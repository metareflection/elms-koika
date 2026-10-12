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
struct StateT * slot_226(struct StateT * v12689);
struct StateT * slot_167(struct StateT * v7681);
struct StateT * slot_509(struct StateT * v17404);
struct StateT * slot_152(struct StateT * v7447);
struct StateT * slot_429(struct StateT * v16100);
struct StateT * slot_231(struct StateT * v12952);
struct StateT * slot_355(struct StateT * v14861);
struct StateT * slot_92(struct StateT * v6476);
struct StateT * slot_232(struct StateT * v12957);
struct StateT * slot_466(struct StateT * v16735);
struct StateT * slot_304(struct StateT * v14070);
struct StateT * slot_31(struct StateT * v5423);
struct StateT * slot_236(struct StateT * v13005);
struct StateT * slot_241(struct StateT * v13089);
struct StateT * slot_160(struct StateT * v7576);
struct StateT * slot_519(struct StateT * v17558);
struct StateT * slot_150(struct StateT * v7415);
struct StateT * slot_391(struct StateT * v15449);
struct StateT * slot_74(struct StateT * v6176);
struct StateT * slot_262(struct StateT * v13416);
struct StateT * slot_351(struct StateT * v14799);
struct StateT * slot_372(struct StateT * v15125);
struct StateT * slot_403(struct StateT * v15670);
struct StateT * slot_107(struct StateT * v6717);
struct StateT * slot_325(struct StateT * v14397);
struct StateT * slot_84(struct StateT * v6332);
struct StateT * slot_28(struct StateT * v5381);
struct StateT * slot_155(struct StateT * v7497);
struct StateT * slot_177(struct StateT * v7843);
struct StateT * slot_517(struct StateT * v17526);
struct StateT * slot_229(struct StateT * v12922);
struct StateT * slot_358(struct StateT * v14910);
struct StateT * slot_465(struct StateT * v16719);
struct StateT * slot_181(struct StateT * v7903);
struct StateT * slot_154(struct StateT * v7480);
struct StateT * slot_260(struct StateT * v13384);
struct StateT * slot_481(struct StateT * v16968);
struct StateT * slot_305(struct StateT * v14085);
struct StateT * slot_27(struct StateT * v5366);
struct StateT * slot_454(struct StateT * v16514);
struct StateT * slot_34(struct StateT * v5468);
struct StateT * slot_482(struct StateT * v16985);
struct StateT * slot_21(struct StateT * v4904);
struct StateT * slot_406(struct StateT * v15715);
struct StateT * slot_292(struct StateT * v13877);
struct StateT * slot_118(struct StateT * v6922);
struct StateT * slot_525(struct StateT * v17655);
struct StateT * slot_515(struct StateT * v17494);
struct StateT * slot_376(struct StateT * v15189);
struct StateT * slot_373(struct StateT * v15141);
struct StateT * slot_94(struct StateT * v6516);
struct StateT * slot_340(struct StateT * v14632);
struct StateT * slot_146(struct StateT * v7354);
struct StateT * slot_383(struct StateT * v15323);
struct StateT * slot_24(struct StateT * v5325);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v17092);
struct StateT * slot_286(struct StateT * v13787);
struct StateT * slot_520(struct StateT * v17575);
struct StateT * slot_125(struct StateT * v7026);
struct StateT * slot_254(struct StateT * v13285);
struct StateT * slot_148(struct StateT * v7383);
struct StateT * slot_421(struct StateT * v15976);
struct StateT * slot_126(struct StateT * v7042);
struct StateT * slot_363(struct StateT * v14990);
struct StateT * slot_79(struct StateT * v6256);
struct StateT * slot_367(struct StateT * v15051);
struct StateT * slot_437(struct StateT * v16236);
struct StateT * slot_341(struct StateT * v14649);
struct StateT * slot_142(struct StateT * v7293);
struct StateT * slot_416(struct StateT * v15873);
struct StateT * slot_280(struct StateT * v13696);
struct StateT * slot_272(struct StateT * v13565);
struct StateT * slot_47(struct StateT * v5697);
struct StateT * slot_214(struct StateT * v11375);
struct StateT * slot_297(struct StateT * v13957);
struct StateT * slot_29(struct StateT * v5396);
struct StateT * slot_314(struct StateT * v14221);
struct StateT * slot_151(struct StateT * v7431);
struct StateT * slot_7(struct StateT * v1906);
struct StateT * slot_124(struct StateT * v7012);
struct StateT * slot_128(struct StateT * v7071);
struct StateT * slot_365(struct StateT * v15021);
struct StateT * slot_441(struct StateT * v16316);
struct StateT * slot_19(struct StateT * v4496);
struct StateT * slot_382(struct StateT * v15299);
struct StateT * slot_523(struct StateT * v17626);
struct StateT * slot_87(struct StateT * v6377);
struct StateT * slot_452(struct StateT * v16485);
struct StateT * slot_67(struct StateT * v6037);
struct StateT * slot_81(struct StateT * v6287);
struct StateT * slot_337(struct StateT * v14581);
struct StateT * slot_32(struct StateT * v5436);
struct StateT * slot_176(struct StateT * v7826);
struct StateT * slot_189(struct StateT * v8023);
struct StateT * slot_394(struct StateT * v15494);
struct StateT * slot_398(struct StateT * v15579);
struct StateT * slot_33(struct StateT * v5444);
struct StateT * slot_371(struct StateT * v15111);
struct StateT * slot_330(struct StateT * v14472);
struct StateT * slot_450(struct StateT * v16455);
struct StateT * slot_35(struct StateT * v5492);
struct StateT * slot_484(struct StateT * v17017);
struct StateT * slot_258(struct StateT * v13350);
struct StateT * slot_166(struct StateT * v7666);
struct StateT * slot_418(struct StateT * v15919);
struct StateT * slot_51(struct StateT * v5773);
struct StateT * slot_25(struct StateT * v5338);
struct StateT * slot_490(struct StateT * v17107);
struct StateT * slot_264(struct StateT * v13446);
struct StateT * slot_339(struct StateT * v14615);
struct StateT * slot_123(struct StateT * v6997);
struct StateT * slot_97(struct StateT * v6567);
struct StateT * slot_106(struct StateT * v6702);
struct StateT * slot_299(struct StateT * v13991);
struct StateT * slot_539(struct StateT * v17870);
struct StateT * slot_319(struct StateT * v14303);
struct StateT * slot_344(struct StateT * v14694);
struct StateT * slot_513(struct StateT * v17464);
struct StateT * slot_130(struct StateT * v7103);
struct StateT * slot_497(struct StateT * v17214);
struct StateT * slot_455(struct StateT * v16530);
struct StateT * slot_141(struct StateT * v7279);
struct StateT * slot_432(struct StateT * v16145);
struct StateT * slot_306(struct StateT * v14099);
struct StateT * slot_312(struct StateT * v14189);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_240(struct StateT * v13072);
struct StateT * slot_247(struct StateT * v13179);
struct StateT * slot_70(struct StateT * v6090);
struct StateT * slot_168(struct StateT * v7695);
struct StateT * slot_348(struct StateT * v14754);
struct StateT * slot_456(struct StateT * v16553);
struct StateT * slot_225(struct StateT * v12485);
struct StateT * slot_467(struct StateT * v16750);
struct StateT * slot_285(struct StateT * v13773);
struct StateT * slot_213(struct StateT * v11171);
struct StateT * slot_82(struct StateT * v6301);
struct StateT * slot_263(struct StateT * v13430);
struct StateT * slot_161(struct StateT * v7591);
struct StateT * slot_293(struct StateT * v13893);
struct StateT * slot_185(struct StateT * v7962);
struct StateT * slot_288(struct StateT * v13818);
struct StateT * slot_89(struct StateT * v6407);
struct StateT * slot_384(struct StateT * v15345);
struct StateT * slot_486(struct StateT * v17047);
struct StateT * slot_347(struct StateT * v14739);
struct StateT * slot_140(struct StateT * v7264);
struct StateT * slot_473(struct StateT * v16840);
struct StateT * slot_49(struct StateT * v5727);
struct StateT * slot_216(struct StateT * v11594);
struct StateT * slot_468(struct StateT * v16764);
struct StateT * slot_50(struct StateT * v5750);
struct StateT * slot_135(struct StateT * v7185);
struct StateT * slot_248(struct StateT * v13194);
struct StateT * slot_59(struct StateT * v5916);
struct StateT * slot_485(struct StateT * v17031);
struct StateT * slot_40(struct StateT * v5592);
struct StateT * slot_77(struct StateT * v6227);
struct StateT * slot_85(struct StateT * v6346);
struct StateT * slot_350(struct StateT * v14784);
struct StateT * slot_392(struct StateT * v15465);
struct StateT * slot_75(struct StateT * v6193);
struct StateT * slot_71(struct StateT * v6113);
struct StateT * slot_378(struct StateT * v15219);
struct StateT * slot_108(struct StateT * v6731);
struct StateT * slot_116(struct StateT * v6890);
struct StateT * slot_417(struct StateT * v15896);
struct StateT * slot_405(struct StateT * v15699);
struct StateT * slot_215(struct StateT * v11390);
struct StateT * slot_45(struct StateT * v5666);
struct StateT * slot_220(struct StateT * v12032);
struct StateT * slot_134(struct StateT * v7168);
struct StateT * slot_463(struct StateT * v16690);
struct StateT * slot_175(struct StateT * v7809);
struct StateT * slot_387(struct StateT * v15390);
struct StateT * slot_273(struct StateT * v13581);
struct StateT * slot_69(struct StateT * v6067);
struct StateT * slot_188(struct StateT * v8007);
struct StateT * slot_495(struct StateT * v17182);
struct StateT * slot_186(struct StateT * v7978);
struct StateT * slot_102(struct StateT * v6641);
struct StateT * slot_145(struct StateT * v7338);
struct StateT * slot_110(struct StateT * v6770);
struct StateT * slot_208(struct StateT * v10607);
struct StateT * slot_301(struct StateT * v14025);
struct StateT * slot_502(struct StateT * v17297);
struct StateT * slot_506(struct StateT * v17359);
struct StateT * slot_413(struct StateT * v15820);
struct StateT * slot_320(struct StateT * v14320);
struct StateT * slot_281(struct StateT * v13713);
struct StateT * slot_533(struct StateT * v17776);
struct StateT * slot_203(struct StateT * v9628);
struct StateT * slot_190(struct StateT * v8039);
struct StateT * slot_157(struct StateT * v7531);
struct StateT * slot_447(struct StateT * v16410);
struct StateT * slot_243(struct StateT * v13118);
struct StateT * slot_173(struct StateT * v7775);
struct StateT * slot_307(struct StateT * v14115);
struct StateT * slot_453(struct StateT * v16500);
struct StateT * slot_54(struct StateT * v5836);
struct StateT * slot_26(struct StateT * v5351);
struct StateT * slot_370(struct StateT * v15096);
struct StateT * slot_206(struct StateT * v10275);
struct StateT * slot_227(struct StateT * v12704);
struct StateT * slot_169(struct StateT * v7711);
struct StateT * slot_442(struct StateT * v16333);
struct StateT * slot_529(struct StateT * v17716);
struct StateT * slot_14(struct StateT * v3476);
struct StateT * slot_357(struct StateT * v14893);
struct StateT * slot_385(struct StateT * v15359);
struct StateT * slot_444(struct StateT * v16365);
struct StateT * slot_261(struct StateT * v13401);
struct StateT * slot_287(struct StateT * v13803);
struct StateT * slot_343(struct StateT * v14678);
struct StateT * slot_36(struct StateT * v5516);
struct StateT * slot_57(struct StateT * v5887);
struct StateT * slot_426(struct StateT * v16055);
struct StateT * slot_536(struct StateT * v17822);
struct StateT * slot_470(struct StateT * v16795);
struct StateT * slot_431(struct StateT * v16129);
struct StateT * slot_62(struct StateT * v5961);
struct StateT * slot_308(struct StateT * v14130);
struct StateT * slot_400(struct StateT * v15619);
struct StateT * slot_323(struct StateT * v14366);
struct StateT * slot_521(struct StateT * v17592);
struct StateT * slot_530(struct StateT * v17731);
struct StateT * slot_23(struct StateT * v5312);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v6362);
struct StateT * slot_538(struct StateT * v17854);
struct StateT * slot_100(struct StateT * v6612);
struct StateT * slot_127(struct StateT * v7057);
struct StateT * slot_411(struct StateT * v15789);
struct StateT * slot_13(struct StateT * v3272);
struct StateT * slot_449(struct StateT * v16440);
struct StateT * slot_460(struct StateT * v16639);
struct StateT * slot_109(struct StateT * v6747);
struct StateT * slot_474(struct StateT * v16854);
struct StateT * slot_174(struct StateT * v7792);
struct StateT * slot_42(struct StateT * v5621);
struct StateT * slot_224(struct StateT * v12469);
struct StateT * slot_184(struct StateT * v7948);
struct StateT * slot_462(struct StateT * v16673);
struct StateT * slot_165(struct StateT * v7650);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_393(struct StateT * v15480);
struct StateT * slot_507(struct StateT * v17374);
struct StateT * slot_477(struct StateT * v16902);
struct StateT * slot_278(struct StateT * v13662);
struct StateT * slot_352(struct StateT * v14813);
struct StateT * slot_249(struct StateT * v13208);
struct StateT * slot_11(struct StateT * v2864);
struct StateT * slot_12(struct StateT * v3068);
struct StateT * slot_228(struct StateT * v12908);
struct StateT * slot_268(struct StateT * v13506);
struct StateT * slot_199(struct StateT * v8964);
struct StateT * slot_252(struct StateT * v13253);
struct StateT * slot_409(struct StateT * v15760);
struct StateT * slot_374(struct StateT * v15157);
struct StateT * slot_269(struct StateT * v13520);
struct StateT * slot_501(struct StateT * v17280);
struct StateT * slot_251(struct StateT * v13239);
struct StateT * slot_65(struct StateT * v6006);
struct StateT * slot_10(struct StateT * v2851);
struct StateT * slot_322(struct StateT * v14352);
struct StateT * slot_277(struct StateT * v13645);
struct StateT * slot_353(struct StateT * v14829);
struct StateT * slot_397(struct StateT * v15556);
struct StateT * slot_435(struct StateT * v16190);
struct StateT * slot_476(struct StateT * v16886);
struct StateT * slot_136(struct StateT * v7202);
struct StateT * slot_379(struct StateT * v15227);
struct StateT * slot_475(struct StateT * v16870);
struct StateT * slot_310(struct StateT * v14160);
struct StateT * slot_445(struct StateT * v16379);
struct StateT * slot_295(struct StateT * v13925);
struct StateT * slot_315(struct StateT * v14237);
struct StateT * slot_17(struct StateT * v4088);
struct StateT * slot_197(struct StateT * v8627);
struct StateT * slot_457(struct StateT * v16576);
struct StateT * slot_207(struct StateT * v10292);
struct StateT * slot_156(struct StateT * v7514);
struct StateT * slot_68(struct StateT * v6051);
struct StateT * slot_493(struct StateT * v17152);
struct StateT * slot_105(struct StateT * v6686);
struct StateT * slot_430(struct StateT * v16115);
struct StateT * slot_369(struct StateT * v15080);
struct StateT * slot_461(struct StateT * v16656);
struct StateT * slot_164(struct StateT * v7636);
struct StateT * slot_15(struct StateT * v3680);
struct StateT * slot_480(struct StateT * v16951);
struct StateT * slot_133(struct StateT * v7151);
struct StateT * slot_56(struct StateT * v5870);
struct StateT * slot_244(struct StateT * v13134);
struct StateT * slot_222(struct StateT * v12251);
struct StateT * slot_171(struct StateT * v7743);
struct StateT * slot_162(struct StateT * v7605);
struct StateT * slot_377(struct StateT * v15205);
struct StateT * slot_427(struct StateT * v16070);
struct StateT * slot_399(struct StateT * v15602);
struct StateT * slot_239(struct StateT * v13055);
struct StateT * slot_464(struct StateT * v16705);
struct StateT * slot_500(struct StateT * v17263);
struct StateT * slot_433(struct StateT * v16160);
struct StateT * slot_121(struct StateT * v6967);
struct StateT * slot_144(struct StateT * v7324);
struct StateT * slot_267(struct StateT * v13491);
struct StateT * slot_492(struct StateT * v17137);
struct StateT * slot_201(struct StateT * v9296);
struct StateT * slot_63(struct StateT * v5977);
struct StateT * slot_195(struct StateT * v8304);
struct StateT * slot_326(struct StateT * v14411);
struct StateT * slot_303(struct StateT * v14054);
struct StateT * slot_511(struct StateT * v17433);
struct StateT * slot_335(struct StateT * v14549);
struct StateT * slot_223(struct StateT * v12265);
struct StateT * slot_316(struct StateT * v14253);
struct StateT * slot_424(struct StateT * v16025);
struct StateT * slot_332(struct StateT * v14501);
struct StateT * slot_237(struct StateT * v13021);
struct StateT * slot_41(struct StateT * v5607);
struct StateT * slot_39(struct StateT * v5576);
struct StateT * slot_508(struct StateT * v17388);
struct StateT * slot_537(struct StateT * v17838);
struct StateT * slot_60(struct StateT * v5932);
struct StateT * slot_289(struct StateT * v13832);
struct StateT * slot_238(struct StateT * v13038);
struct StateT * slot_112(struct StateT * v6816);
struct StateT * slot_256(struct StateT * v13317);
struct StateT * slot_16(struct StateT * v3884);
struct StateT * slot_245(struct StateT * v13149);
struct StateT * slot_113(struct StateT * v6839);
struct StateT * slot_302(struct StateT * v14040);
struct StateT * slot_388(struct StateT * v15404);
struct StateT * slot_191(struct StateT * v8055);
struct StateT * slot_103(struct StateT * v6657);
struct StateT * slot_487(struct StateT * v17062);
struct StateT * slot_324(struct StateT * v14382);
struct StateT * slot_440(struct StateT * v16299);
struct StateT * slot_518(struct StateT * v17542);
struct StateT * slot_95(struct StateT * v6533);
struct StateT * slot_451(struct StateT * v16469);
struct StateT * slot_458(struct StateT * v16599);
struct StateT * slot_415(struct StateT * v15850);
struct StateT * slot_354(struct StateT * v14845);
struct StateT * slot_531(struct StateT * v17745);
struct StateT * slot_115(struct StateT * v6873);
struct StateT * slot_78(struct StateT * v6242);
struct StateT * slot_321(struct StateT * v14337);
struct StateT * slot_317(struct StateT * v14269);
struct StateT * slot_205(struct StateT * v9960);
struct StateT * slot_193(struct StateT * v8087);
struct StateT * slot_375(struct StateT * v15173);
struct StateT * slot_331(struct StateT * v14487);
struct StateT * slot_380(struct StateT * v15251);
struct StateT * slot_412(struct StateT * v15805);
struct StateT * slot_381(struct StateT * v15275);
struct StateT * slot_478(struct StateT * v16918);
struct StateT * slot_246(struct StateT * v13163);
struct StateT * slot_210(struct StateT * v10937);
struct StateT * slot_472(struct StateT * v16825);
struct StateT * slot_284(struct StateT * v13758);
struct StateT * slot_52(struct StateT * v5796);
struct StateT * slot_83(struct StateT * v6317);
struct StateT * slot_209(struct StateT * v10622);
struct StateT * slot_420(struct StateT * v15959);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_73(struct StateT * v6159);
struct StateT * slot_270(struct StateT * v13536);
struct StateT * slot_198(struct StateT * v8942);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v7993);
struct StateT * slot_446(struct StateT * v16395);
struct StateT * slot_182(struct StateT * v7917);
struct StateT * slot_361(struct StateT * v14961);
struct StateT * slot_38(struct StateT * v5562);
struct StateT * slot_178(struct StateT * v7858);
struct StateT * slot_98(struct StateT * v6582);
struct StateT * slot_159(struct StateT * v7560);
struct StateT * slot_510(struct StateT * v17419);
struct StateT * slot_459(struct StateT * v16622);
struct StateT * slot_404(struct StateT * v15685);
struct StateT * slot_46(struct StateT * v5682);
struct StateT * slot_212(struct StateT * v11155);
struct StateT * slot_132(struct StateT * v7135);
struct StateT * slot_313(struct StateT * v14205);
struct StateT * slot_211(struct StateT * v10951);
struct StateT * slot_20(struct StateT * v4700);
struct StateT * slot_436(struct StateT * v16213);
struct StateT * slot_61(struct StateT * v5947);
struct StateT * slot_499(struct StateT * v17246);
struct StateT * slot_359(struct StateT * v14927);
struct StateT * slot_514(struct StateT * v17478);
struct StateT * slot_296(struct StateT * v13941);
struct StateT * slot_30(struct StateT * v5409);
struct StateT * slot_18(struct StateT * v4292);
struct StateT * slot_9(struct StateT * v2536);
struct StateT * slot_300(struct StateT * v14008);
struct StateT * slot_183(struct StateT * v7933);
struct StateT * slot_282(struct StateT * v13728);
struct StateT * slot_309(struct StateT * v14144);
struct StateT * slot_362(struct StateT * v14976);
struct StateT * slot_43(struct StateT * v5637);
struct StateT * slot_76(struct StateT * v6210);
struct StateT * slot_6(struct StateT * v1591);
struct StateT * slot_55(struct StateT * v5853);
struct StateT * slot_283(struct StateT * v13742);
struct StateT * slot_346(struct StateT * v14723);
struct StateT * slot_516(struct StateT * v17510);
struct StateT * slot_274(struct StateT * v13597);
struct StateT * slot_535(struct StateT * v17806);
struct StateT * slot_318(struct StateT * v14286);
struct StateT * slot_91(struct StateT * v6453);
struct StateT * slot_58(struct StateT * v5902);
struct StateT * slot_255(struct StateT * v13301);
struct StateT * slot_540(struct StateT * v17891);
struct StateT * slot_66(struct StateT * v6022);
struct StateT * slot_368(struct StateT * v15066);
struct StateT * slot_265(struct StateT * v13461);
struct StateT * slot_37(struct StateT * v5540);
struct StateT * slot_114(struct StateT * v6856);
struct StateT * slot_257(struct StateT * v13333);
struct StateT * slot_192(struct StateT * v8071);
struct StateT * slot_327(struct StateT * v14427);
struct StateT * slot_48(struct StateT * v5711);
struct StateT * slot_396(struct StateT * v15533);
struct StateT * slot_528(struct StateT * v17700);
struct StateT * slot_72(struct StateT * v6136);
struct StateT * slot_526(struct StateT * v17671);
struct StateT * slot_119(struct StateT * v6936);
struct StateT * slot_101(struct StateT * v6627);
struct StateT * slot_276(struct StateT * v13629);
struct StateT * slot_290(struct StateT * v13848);
struct StateT * slot_93(struct StateT * v6499);
struct StateT * slot_266(struct StateT * v13475);
struct StateT * slot_88(struct StateT * v6391);
struct StateT * slot_96(struct StateT * v6550);
struct StateT * slot_234(struct StateT * v12973);
struct StateT * slot_471(struct StateT * v16809);
struct StateT * slot_419(struct StateT * v15942);
struct StateT * slot_218(struct StateT * v11812);
struct StateT * slot_202(struct StateT * v9611);
struct StateT * slot_336(struct StateT * v14565);
struct StateT * slot_230(struct StateT * v12936);
struct StateT * slot_294(struct StateT * v13909);
struct StateT * slot_408(struct StateT * v15744);
struct StateT * slot_342(struct StateT * v14664);
struct StateT * slot_488(struct StateT * v17076);
struct StateT * slot_439(struct StateT * v16282);
struct StateT * slot_389(struct StateT * v15420);
struct StateT * slot_479(struct StateT * v16934);
struct StateT * slot_138(struct StateT * v7234);
struct StateT * slot_483(struct StateT * v17002);
struct StateT * slot_196(struct StateT * v8619);
struct StateT * slot_172(struct StateT * v7759);
struct StateT * slot_425(struct StateT * v16039);
struct StateT * slot_443(struct StateT * v16350);
struct StateT * slot_131(struct StateT * v7119);
struct StateT * slot_8(struct StateT * v2221);
struct StateT * slot_534(struct StateT * v17790);
struct StateT * slot_180(struct StateT * v7888);
struct StateT * slot_504(struct StateT * v17329);
struct StateT * slot_512(struct StateT * v17449);
struct StateT * slot_496(struct StateT * v17198);
struct StateT * slot_494(struct StateT * v17166);
struct StateT * slot_242(struct StateT * v13104);
struct StateT * slot_328(struct StateT * v14442);
struct StateT * slot_402(struct StateT * v15653);
struct StateT * slot_200(struct StateT * v9279);
struct StateT * slot_149(struct StateT * v7399);
struct StateT * slot_527(struct StateT * v17686);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_334(struct StateT * v14533);
struct StateT * slot_104(struct StateT * v6672);
struct StateT * slot_235(struct StateT * v12989);
struct StateT * slot_275(struct StateT * v13613);
struct StateT * slot_329(struct StateT * v14456);
struct StateT * slot_428(struct StateT * v16084);
struct StateT * slot_395(struct StateT * v15510);
struct StateT * slot_345(struct StateT * v14709);
struct StateT * slot_298(struct StateT * v13974);
struct StateT * slot_414(struct StateT * v15834);
struct StateT * slot_364(struct StateT * v15006);
struct StateT * slot_356(struct StateT * v14877);
struct StateT * slot_253(struct StateT * v13269);
struct StateT * slot_434(struct StateT * v16174);
struct StateT * slot_64(struct StateT * v5992);
struct StateT * slot_170(struct StateT * v7727);
struct StateT * slot_53(struct StateT * v5819);
struct StateT * slot_522(struct StateT * v17609);
struct StateT * slot_80(struct StateT * v6272);
struct StateT * slot_503(struct StateT * v17314);
struct StateT * slot_390(struct StateT * v15435);
struct StateT * slot_44(struct StateT * v5652);
struct StateT * slot_137(struct StateT * v7219);
struct StateT * slot_386(struct StateT * v15375);
struct StateT * slot_122(struct StateT * v6981);
struct StateT * slot_99(struct StateT * v6596);
struct StateT * slot_179(struct StateT * v7872);
struct StateT * slot_219(struct StateT * v11828);
struct StateT * slot_338(struct StateT * v14598);
struct StateT * slot_22(struct StateT * v5108);
struct StateT * slot_366(struct StateT * v15035);
struct StateT * slot_139(struct StateT * v7248);
struct StateT * slot_438(struct StateT * v16259);
struct StateT * slot_333(struct StateT * v14517);
struct StateT * slot_221(struct StateT * v12047);
struct StateT * slot_153(struct StateT * v7463);
struct StateT * slot_129(struct StateT * v7087);
struct StateT * slot_158(struct StateT * v7546);
struct StateT * slot_311(struct StateT * v14175);
struct StateT * slot_498(struct StateT * v17230);
struct StateT * slot_279(struct StateT * v13679);
struct StateT * slot_271(struct StateT * v13551);
struct StateT * slot_524(struct StateT * v17641);
struct StateT * slot_505(struct StateT * v17343);
struct StateT * slot_401(struct StateT * v15636);
struct StateT * slot_423(struct StateT * v16010);
struct StateT * slot_532(struct StateT * v17761);
struct StateT * slot_217(struct StateT * v11608);
struct StateT * slot_111(struct StateT * v6793);
struct StateT * slot_349(struct StateT * v14768);
struct StateT * slot_291(struct StateT * v13863);
struct StateT * slot_147(struct StateT * v7369);
struct StateT * slot_410(struct StateT * v15775);
struct StateT * slot_491(struct StateT * v17121);
struct StateT * slot_163(struct StateT * v7621);
struct StateT * slot_422(struct StateT * v15993);
struct StateT * slot_448(struct StateT * v16424);
struct StateT * slot_204(struct StateT * v9943);
struct StateT * slot_194(struct StateT * v8108);
struct StateT * slot_407(struct StateT * v15730);
struct StateT * slot_250(struct StateT * v13224);
struct StateT * slot_360(struct StateT * v14944);
struct StateT * slot_259(struct StateT * v13367);
struct StateT * slot_469(struct StateT * v16780);
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

struct StateT * slot_226(struct StateT * v12689) {
  int v12690 = v12689->timer;
  int v12697 = v12690 + 1;
  v12689->timer = v12697;
  int * v12692 = v12689->regs;
  int v12693 = v12692[23];
  int v12701 = (int)((unsigned int)v12693 >> 25);
  v12692[24] = v12701;
  struct StateT * v12695 = slot_228(v12689);
  return v12695;
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

struct StateT * slot_509(struct StateT * v17404) {
  int v17405 = v17404->timer;
  int v17412 = v17405 + 1;
  v17404->timer = v17412;
  int * v17407 = v17404->regs;
  int v17408 = v17407[22];
  int v17416 = (int)((unsigned int)v17408 >> 19);
  v17407[24] = v17416;
  struct StateT * v17410 = slot_510(v17404);
  return v17410;
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

struct StateT * slot_429(struct StateT * v16100) {
  int v16101 = v16100->timer;
  int v16108 = v16101 + 1;
  v16100->timer = v16108;
  int * v16103 = v16100->regs;
  int v16104 = v16103[22];
  int v16112 = (int)((unsigned int)v16104 >> 19);
  v16103[24] = v16112;
  struct StateT * v16106 = slot_430(v16100);
  return v16106;
}

struct StateT * slot_231(struct StateT * v12952) {
  int v12953 = v12952->timer;
  int v12956 = v12953 + 1;
  v12952->timer = v12956;
  return v12952;
}

struct StateT * slot_355(struct StateT * v14861) {
  int v14862 = v14861->timer;
  int v14870 = v14862 + 1;
  v14861->timer = v14870;
  int * v14864 = v14861->regs;
  int v14865 = v14864[18];
  int v14866 = v14864[22];
  int v14874 = v14865 ^ v14866;
  v14864[18] = v14874;
  struct StateT * v14868 = slot_356(v14861);
  return v14868;
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

struct StateT * slot_232(struct StateT * v12957) {
  int v12958 = v12957->timer;
  int v12966 = v12958 + 1;
  v12957->timer = v12966;
  int * v12960 = v12957->regs;
  int v12961 = v12960[9];
  int v12962 = v12960[20];
  int v12970 = v12961 ^ v12962;
  v12960[9] = v12970;
  struct StateT * v12964 = slot_234(v12957);
  return v12964;
}

struct StateT * slot_466(struct StateT * v16735) {
  int v16736 = v16735->timer;
  int v16743 = v16736 + 1;
  v16735->timer = v16743;
  int * v16738 = v16735->regs;
  int v16739 = v16738[21];
  int v16747 = (int)((unsigned int)v16739 >> 25);
  v16738[24] = v16747;
  struct StateT * v16741 = slot_467(v16735);
  return v16741;
}

struct StateT * slot_304(struct StateT * v14070) {
  int v14071 = v14070->timer;
  int v14078 = v14071 + 1;
  v14070->timer = v14078;
  int * v14073 = v14070->regs;
  int v14074 = v14073[21];
  int v14082 = (int)((unsigned int)v14074 >> 25);
  v14073[24] = v14082;
  struct StateT * v14076 = slot_305(v14070);
  return v14076;
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

struct StateT * slot_236(struct StateT * v13005) {
  int v13006 = v13005->timer;
  int v13014 = v13006 + 1;
  v13005->timer = v13014;
  int * v13008 = v13005->regs;
  int v13009 = v13008[8];
  int v13010 = v13008[23];
  int v13018 = v13009 ^ v13010;
  v13008[8] = v13018;
  struct StateT * v13012 = slot_237(v13005);
  return v13012;
}

struct StateT * slot_241(struct StateT * v13089) {
  int v13090 = v13089->timer;
  int v13097 = v13090 + 1;
  v13089->timer = v13097;
  int * v13092 = v13089->regs;
  int v13093 = v13092[20];
  int v13101 = (int)((unsigned int)v13093 >> 23);
  v13092[24] = v13101;
  struct StateT * v13095 = slot_242(v13089);
  return v13095;
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

struct StateT * slot_519(struct StateT * v17558) {
  int v17559 = v17558->timer;
  int v17567 = v17559 + 1;
  v17558->timer = v17567;
  int * v17561 = v17558->regs;
  int v17562 = v17561[8];
  int v17563 = v17561[17];
  int v17572 = v17562 + v17563;
  v17561[20] = v17572;
  struct StateT * v17565 = slot_520(v17558);
  return v17565;
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

struct StateT * slot_391(struct StateT * v15449) {
  int v15450 = v15449->timer;
  int v15458 = v15450 + 1;
  v15449->timer = v15458;
  int * v15452 = v15449->regs;
  int v15453 = v15452[22];
  int v15454 = v15452[24];
  int v15462 = v15453 | v15454;
  v15452[22] = v15462;
  struct StateT * v15456 = slot_392(v15449);
  return v15456;
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

struct StateT * slot_262(struct StateT * v13416) {
  int v13417 = v13416->timer;
  int v13424 = v13417 + 1;
  v13416->timer = v13424;
  int * v13419 = v13416->regs;
  int v13420 = v13419[20];
  int v13427 = v13420 << 13;
  v13419[20] = v13427;
  struct StateT * v13422 = slot_263(v13416);
  return v13422;
}

struct StateT * slot_351(struct StateT * v14799) {
  int v14800 = v14799->timer;
  int v14807 = v14800 + 1;
  v14799->timer = v14807;
  int * v14802 = v14799->regs;
  int v14803 = v14802[23];
  int v14810 = v14803 << 13;
  v14802[23] = v14810;
  struct StateT * v14805 = slot_352(v14799);
  return v14805;
}

struct StateT * slot_372(struct StateT * v15125) {
  int v15126 = v15125->timer;
  int v15134 = v15126 + 1;
  v15125->timer = v15134;
  int * v15128 = v15125->regs;
  int v15129 = v15128[23];
  int v15130 = v15128[24];
  int v15138 = v15129 | v15130;
  v15128[23] = v15138;
  struct StateT * v15132 = slot_373(v15125);
  return v15132;
}

struct StateT * slot_403(struct StateT * v15670) {
  int v15671 = v15670->timer;
  int v15678 = v15671 + 1;
  v15670->timer = v15678;
  int * v15673 = v15670->regs;
  int v15674 = v15673[20];
  int v15682 = (int)((unsigned int)v15674 >> 23);
  v15673[24] = v15682;
  struct StateT * v15676 = slot_404(v15670);
  return v15676;
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

struct StateT * slot_325(struct StateT * v14397) {
  int v14398 = v14397->timer;
  int v14405 = v14398 + 1;
  v14397->timer = v14405;
  int * v14400 = v14397->regs;
  int v14401 = v14400[21];
  int v14408 = v14401 << 9;
  v14400[21] = v14408;
  struct StateT * v14403 = slot_326(v14397);
  return v14403;
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

struct StateT * slot_517(struct StateT * v17526) {
  int v17527 = v17526->timer;
  int v17535 = v17527 + 1;
  v17526->timer = v17535;
  int * v17529 = v17526->regs;
  int v17530 = v17529[18];
  int v17531 = v17529[22];
  int v17539 = v17530 ^ v17531;
  v17529[18] = v17539;
  struct StateT * v17533 = slot_518(v17526);
  return v17533;
}

struct StateT * slot_229(struct StateT * v12922) {
  int v12923 = v12922->timer;
  int v12930 = v12923 + 1;
  v12922->timer = v12930;
  int * v12925 = v12922->regs;
  int v12926 = v12925[2];
  int v12933 = v12926 + 48;
  v12925[2] = v12933;
  struct StateT * v12928 = slot_231(v12922);
  return v12928;
}

struct StateT * slot_358(struct StateT * v14910) {
  int v14911 = v14910->timer;
  int v14919 = v14911 + 1;
  v14910->timer = v14919;
  int * v14913 = v14910->regs;
  int v14914 = v14913[9];
  int v14915 = v14913[5];
  int v14924 = v14914 + v14915;
  v14913[21] = v14924;
  struct StateT * v14917 = slot_359(v14910);
  return v14917;
}

struct StateT * slot_465(struct StateT * v16719) {
  int v16720 = v16719->timer;
  int v16728 = v16720 + 1;
  v16719->timer = v16728;
  int * v16722 = v16719->regs;
  int v16723 = v16722[20];
  int v16724 = v16722[24];
  int v16732 = v16723 | v16724;
  v16722[20] = v16732;
  struct StateT * v16726 = slot_466(v16719);
  return v16726;
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

struct StateT * slot_260(struct StateT * v13384) {
  int v13385 = v13384->timer;
  int v13393 = v13385 + 1;
  v13384->timer = v13393;
  int * v13387 = v13384->regs;
  int v13388 = v13387[5];
  int v13389 = v13387[8];
  int v13398 = v13388 + v13389;
  v13387[23] = v13398;
  struct StateT * v13391 = slot_261(v13384);
  return v13391;
}

struct StateT * slot_481(struct StateT * v16968) {
  int v16969 = v16968->timer;
  int v16977 = v16969 + 1;
  v16968->timer = v16977;
  int * v16971 = v16968->regs;
  int v16972 = v16971[15];
  int v16973 = v16971[28];
  int v16982 = v16972 + v16973;
  v16971[22] = v16982;
  struct StateT * v16975 = slot_482(v16968);
  return v16975;
}

struct StateT * slot_305(struct StateT * v14085) {
  int v14086 = v14085->timer;
  int v14093 = v14086 + 1;
  v14085->timer = v14093;
  int * v14088 = v14085->regs;
  int v14089 = v14088[21];
  int v14096 = v14089 << 7;
  v14088[21] = v14096;
  struct StateT * v14091 = slot_306(v14085);
  return v14091;
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

struct StateT * slot_454(struct StateT * v16514) {
  int v16515 = v16514->timer;
  int v16523 = v16515 + 1;
  v16514->timer = v16523;
  int * v16517 = v16514->regs;
  int v16518 = v16517[23];
  int v16519 = v16517[24];
  int v16527 = v16518 | v16519;
  v16517[23] = v16527;
  struct StateT * v16521 = slot_455(v16514);
  return v16521;
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

struct StateT * slot_482(struct StateT * v16985) {
  int v16986 = v16985->timer;
  int v16994 = v16986 + 1;
  v16985->timer = v16994;
  int * v16988 = v16985->regs;
  int v16989 = v16988[16];
  int v16990 = v16988[31];
  int v16999 = v16989 + v16990;
  v16988[23] = v16999;
  struct StateT * v16992 = slot_483(v16985);
  return v16992;
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

struct StateT * slot_406(struct StateT * v15715) {
  int v15716 = v15715->timer;
  int v15723 = v15716 + 1;
  v15715->timer = v15723;
  int * v15718 = v15715->regs;
  int v15719 = v15718[21];
  int v15727 = (int)((unsigned int)v15719 >> 23);
  v15718[24] = v15727;
  struct StateT * v15721 = slot_407(v15715);
  return v15721;
}

struct StateT * slot_292(struct StateT * v13877) {
  int v13878 = v13877->timer;
  int v13886 = v13878 + 1;
  v13877->timer = v13886;
  int * v13880 = v13877->regs;
  int v13881 = v13880[23];
  int v13882 = v13880[24];
  int v13890 = v13881 | v13882;
  v13880[23] = v13890;
  struct StateT * v13884 = slot_293(v13877);
  return v13884;
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

struct StateT * slot_525(struct StateT * v17655) {
  int v17656 = v17655->timer;
  int v17664 = v17656 + 1;
  v17655->timer = v17664;
  int * v17658 = v17655->regs;
  int v17659 = v17658[20];
  int v17660 = v17658[24];
  int v17668 = v17659 | v17660;
  v17658[20] = v17668;
  struct StateT * v17662 = slot_526(v17655);
  return v17662;
}

struct StateT * slot_515(struct StateT * v17494) {
  int v17495 = v17494->timer;
  int v17503 = v17495 + 1;
  v17494->timer = v17503;
  int * v17497 = v17494->regs;
  int v17498 = v17497[8];
  int v17499 = v17497[20];
  int v17507 = v17498 ^ v17499;
  v17497[8] = v17507;
  struct StateT * v17501 = slot_516(v17494);
  return v17501;
}

struct StateT * slot_376(struct StateT * v15189) {
  int v15190 = v15189->timer;
  int v15198 = v15190 + 1;
  v15189->timer = v15198;
  int * v15192 = v15189->regs;
  int v15193 = v15192[31];
  int v15194 = v15192[23];
  int v15202 = v15193 ^ v15194;
  v15192[31] = v15202;
  struct StateT * v15196 = slot_377(v15189);
  return v15196;
}

struct StateT * slot_373(struct StateT * v15141) {
  int v15142 = v15141->timer;
  int v15150 = v15142 + 1;
  v15141->timer = v15150;
  int * v15144 = v15141->regs;
  int v15145 = v15144[30];
  int v15146 = v15144[20];
  int v15154 = v15145 ^ v15146;
  v15144[30] = v15154;
  struct StateT * v15148 = slot_374(v15141);
  return v15148;
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

struct StateT * slot_340(struct StateT * v14632) {
  int v14633 = v14632->timer;
  int v14641 = v14633 + 1;
  v14632->timer = v14641;
  int * v14635 = v14632->regs;
  int v14636 = v14635[7];
  int v14637 = v14635[16];
  int v14646 = v14636 + v14637;
  v14635[23] = v14646;
  struct StateT * v14639 = slot_341(v14632);
  return v14639;
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

struct StateT * slot_383(struct StateT * v15323) {
  int * v15324 = v15323->saved_regs;
  int * v15325 = v15323->regs;
  int v15326 = v15325[24];
  v15324[24] = v15326;
  int v15328 = v15323->timer;
  int v15339 = v15328 + 1;
  v15323->timer = v15339;
  int * v15330 = v15323->regs;
  int v15331 = v15330[20];
  int v15342 = (int)((unsigned int)v15331 >> 25);
  v15330[24] = v15342;
  struct StateT * v15333 = slot_384(v15323);
  return v15333;
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

struct StateT * slot_489(struct StateT * v17092) {
  int v17093 = v17092->timer;
  int v17100 = v17093 + 1;
  v17092->timer = v17100;
  int * v17095 = v17092->regs;
  int v17096 = v17095[22];
  int v17104 = (int)((unsigned int)v17096 >> 23);
  v17095[24] = v17104;
  struct StateT * v17098 = slot_490(v17092);
  return v17098;
}

struct StateT * slot_286(struct StateT * v13787) {
  int v13788 = v13787->timer;
  int v13796 = v13788 + 1;
  v13787->timer = v13796;
  int * v13790 = v13787->regs;
  int v13791 = v13790[21];
  int v13792 = v13790[24];
  int v13800 = v13791 | v13792;
  v13790[21] = v13800;
  struct StateT * v13794 = slot_287(v13787);
  return v13794;
}

struct StateT * slot_520(struct StateT * v17575) {
  int v17576 = v17575->timer;
  int v17584 = v17576 + 1;
  v17575->timer = v17584;
  int * v17578 = v17575->regs;
  int v17579 = v17578[9];
  int v17580 = v17578[5];
  int v17589 = v17579 + v17580;
  v17578[21] = v17589;
  struct StateT * v17582 = slot_521(v17575);
  return v17582;
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

struct StateT * slot_254(struct StateT * v13285) {
  int v13286 = v13285->timer;
  int v13294 = v13286 + 1;
  v13285->timer = v13294;
  int * v13288 = v13285->regs;
  int v13289 = v13288[7];
  int v13290 = v13288[21];
  int v13298 = v13289 ^ v13290;
  v13288[7] = v13298;
  struct StateT * v13292 = slot_255(v13285);
  return v13292;
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

struct StateT * slot_421(struct StateT * v15976) {
  int v15977 = v15976->timer;
  int v15985 = v15977 + 1;
  v15976->timer = v15985;
  int * v15979 = v15976->regs;
  int v15980 = v15979[17];
  int v15981 = v15979[19];
  int v15990 = v15980 + v15981;
  v15979[22] = v15990;
  struct StateT * v15983 = slot_422(v15976);
  return v15983;
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

struct StateT * slot_363(struct StateT * v14990) {
  int v14991 = v14990->timer;
  int v14999 = v14991 + 1;
  v14990->timer = v14999;
  int * v14993 = v14990->regs;
  int v14994 = v14993[20];
  int v14995 = v14993[24];
  int v15003 = v14994 | v14995;
  v14993[20] = v15003;
  struct StateT * v14997 = slot_364(v14990);
  return v14997;
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

struct StateT * slot_367(struct StateT * v15051) {
  int v15052 = v15051->timer;
  int v15059 = v15052 + 1;
  v15051->timer = v15059;
  int * v15054 = v15051->regs;
  int v15055 = v15054[22];
  int v15063 = (int)((unsigned int)v15055 >> 14);
  v15054[24] = v15063;
  struct StateT * v15057 = slot_368(v15051);
  return v15057;
}

struct StateT * slot_437(struct StateT * v16236) {
  int * v16237 = v16236->saved_regs;
  int * v16238 = v16236->regs;
  int v16239 = v16238[12];
  v16237[12] = v16239;
  int v16241 = v16236->timer;
  int v16253 = v16241 + 1;
  v16236->timer = v16253;
  int * v16243 = v16236->regs;
  int v16244 = v16243[12];
  int v16245 = v16243[22];
  int v16256 = v16244 ^ v16245;
  v16243[12] = v16256;
  struct StateT * v16247 = slot_438(v16236);
  return v16247;
}

struct StateT * slot_341(struct StateT * v14649) {
  int v14650 = v14649->timer;
  int v14657 = v14650 + 1;
  v14649->timer = v14657;
  int * v14652 = v14649->regs;
  int v14653 = v14652[20];
  int v14661 = (int)((unsigned int)v14653 >> 19);
  v14652[24] = v14661;
  struct StateT * v14655 = slot_342(v14649);
  return v14655;
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

struct StateT * slot_416(struct StateT * v15873) {
  int * v15874 = v15873->saved_regs;
  int * v15875 = v15873->regs;
  int v15876 = v15875[7];
  v15874[7] = v15876;
  int v15878 = v15873->timer;
  int v15890 = v15878 + 1;
  v15873->timer = v15890;
  int * v15880 = v15873->regs;
  int v15881 = v15880[7];
  int v15882 = v15880[21];
  int v15893 = v15881 ^ v15882;
  v15880[7] = v15893;
  struct StateT * v15884 = slot_417(v15873);
  return v15884;
}

struct StateT * slot_280(struct StateT * v13696) {
  int v13697 = v13696->timer;
  int v13705 = v13697 + 1;
  v13696->timer = v13705;
  int * v13699 = v13696->regs;
  int v13700 = v13699[15];
  int v13701 = v13699[5];
  int v13710 = v13700 + v13701;
  v13699[23] = v13710;
  struct StateT * v13703 = slot_281(v13696);
  return v13703;
}

struct StateT * slot_272(struct StateT * v13565) {
  int v13566 = v13565->timer;
  int v13574 = v13566 + 1;
  v13565->timer = v13574;
  int * v13568 = v13565->regs;
  int v13569 = v13568[23];
  int v13570 = v13568[24];
  int v13578 = v13569 | v13570;
  v13568[23] = v13578;
  struct StateT * v13572 = slot_273(v13565);
  return v13572;
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

struct StateT * slot_214(struct StateT * v11375) {
  int v11376 = v11375->timer;
  int v11383 = v11376 + 1;
  v11375->timer = v11383;
  int * v11378 = v11375->regs;
  int v11379 = v11378[21];
  int v11387 = (int)((unsigned int)v11379 >> 25);
  v11378[24] = v11387;
  struct StateT * v11381 = slot_216(v11375);
  return v11381;
}

struct StateT * slot_297(struct StateT * v13957) {
  int v13958 = v13957->timer;
  int v13966 = v13958 + 1;
  v13957->timer = v13966;
  int * v13960 = v13957->regs;
  int v13961 = v13960[30];
  int v13962 = v13960[8];
  int v13971 = v13961 + v13962;
  v13960[20] = v13971;
  struct StateT * v13964 = slot_298(v13957);
  return v13964;
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

struct StateT * slot_314(struct StateT * v14221) {
  int v14222 = v14221->timer;
  int v14230 = v14222 + 1;
  v14221->timer = v14230;
  int * v14224 = v14221->regs;
  int v14225 = v14224[12];
  int v14226 = v14224[21];
  int v14234 = v14225 ^ v14226;
  v14224[12] = v14234;
  struct StateT * v14228 = slot_315(v14221);
  return v14228;
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

struct StateT * slot_365(struct StateT * v15021) {
  int v15022 = v15021->timer;
  int v15029 = v15022 + 1;
  v15021->timer = v15029;
  int * v15024 = v15021->regs;
  int v15025 = v15024[21];
  int v15032 = v15025 << 18;
  v15024[21] = v15032;
  struct StateT * v15027 = slot_366(v15021);
  return v15027;
}

struct StateT * slot_441(struct StateT * v16316) {
  int v16317 = v16316->timer;
  int v16325 = v16317 + 1;
  v16316->timer = v16325;
  int * v16319 = v16316->regs;
  int v16320 = v16319[12];
  int v16321 = v16319[17];
  int v16330 = v16320 + v16321;
  v16319[22] = v16330;
  struct StateT * v16323 = slot_442(v16316);
  return v16323;
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

struct StateT * slot_382(struct StateT * v15299) {
  int * v15300 = v15299->saved_regs;
  int * v15301 = v15299->regs;
  int v15302 = v15301[23];
  v15300[23] = v15302;
  int v15304 = v15299->timer;
  int v15316 = v15304 + 1;
  v15299->timer = v15316;
  int * v15306 = v15299->regs;
  int v15307 = v15306[31];
  int v15308 = v15306[15];
  int v15320 = v15307 + v15308;
  v15306[23] = v15320;
  struct StateT * v15310 = slot_383(v15299);
  return v15310;
}

struct StateT * slot_523(struct StateT * v17626) {
  int v17627 = v17626->timer;
  int v17634 = v17627 + 1;
  v17626->timer = v17634;
  int * v17629 = v17626->regs;
  int v17630 = v17629[20];
  int v17638 = (int)((unsigned int)v17630 >> 14);
  v17629[24] = v17638;
  struct StateT * v17632 = slot_524(v17626);
  return v17632;
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

struct StateT * slot_452(struct StateT * v16485) {
  int v16486 = v16485->timer;
  int v16493 = v16486 + 1;
  v16485->timer = v16493;
  int * v16488 = v16485->regs;
  int v16489 = v16488[23];
  int v16497 = (int)((unsigned int)v16489 >> 14);
  v16488[24] = v16497;
  struct StateT * v16491 = slot_453(v16485);
  return v16491;
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

struct StateT * slot_337(struct StateT * v14581) {
  int v14582 = v14581->timer;
  int v14590 = v14582 + 1;
  v14581->timer = v14590;
  int * v14584 = v14581->regs;
  int v14585 = v14584[17];
  int v14586 = v14584[14];
  int v14595 = v14585 + v14586;
  v14584[20] = v14595;
  struct StateT * v14588 = slot_338(v14581);
  return v14588;
}

struct StateT * slot_32(struct StateT * v5436) {
  int v5437 = v5436->timer;
  int v5441 = v5437 + 1;
  v5436->timer = v5441;
  struct StateT * v5439 = slot_33(v5436);
  return v5439;
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

struct StateT * slot_394(struct StateT * v15494) {
  int v15495 = v15494->timer;
  int v15503 = v15495 + 1;
  v15494->timer = v15503;
  int * v15497 = v15494->regs;
  int v15498 = v15497[23];
  int v15499 = v15497[24];
  int v15507 = v15498 | v15499;
  v15497[23] = v15507;
  struct StateT * v15501 = slot_395(v15494);
  return v15501;
}

struct StateT * slot_398(struct StateT * v15579) {
  int * v15580 = v15579->saved_regs;
  int * v15581 = v15579->regs;
  int v15582 = v15581[8];
  v15580[8] = v15582;
  int v15584 = v15579->timer;
  int v15596 = v15584 + 1;
  v15579->timer = v15596;
  int * v15586 = v15579->regs;
  int v15587 = v15586[8];
  int v15588 = v15586[23];
  int v15599 = v15587 ^ v15588;
  v15586[8] = v15599;
  struct StateT * v15590 = slot_399(v15579);
  return v15590;
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

struct StateT * slot_371(struct StateT * v15111) {
  int v15112 = v15111->timer;
  int v15119 = v15112 + 1;
  v15111->timer = v15119;
  int * v15114 = v15111->regs;
  int v15115 = v15114[23];
  int v15122 = v15115 << 18;
  v15114[23] = v15122;
  struct StateT * v15117 = slot_372(v15111);
  return v15117;
}

struct StateT * slot_330(struct StateT * v14472) {
  int v14473 = v14472->timer;
  int v14480 = v14473 + 1;
  v14472->timer = v14480;
  int * v14475 = v14472->regs;
  int v14476 = v14475[23];
  int v14484 = (int)((unsigned int)v14476 >> 23);
  v14475[24] = v14484;
  struct StateT * v14478 = slot_331(v14472);
  return v14478;
}

struct StateT * slot_450(struct StateT * v16455) {
  int v16456 = v16455->timer;
  int v16463 = v16456 + 1;
  v16455->timer = v16463;
  int * v16458 = v16455->regs;
  int v16459 = v16458[22];
  int v16466 = v16459 << 18;
  v16458[22] = v16466;
  struct StateT * v16461 = slot_451(v16455);
  return v16461;
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

struct StateT * slot_484(struct StateT * v17017) {
  int v17018 = v17017->timer;
  int v17025 = v17018 + 1;
  v17017->timer = v17025;
  int * v17020 = v17017->regs;
  int v17021 = v17020[20];
  int v17028 = v17021 << 9;
  v17020[20] = v17028;
  struct StateT * v17023 = slot_485(v17017);
  return v17023;
}

struct StateT * slot_258(struct StateT * v13350) {
  int v13351 = v13350->timer;
  int v13359 = v13351 + 1;
  v13350->timer = v13359;
  int * v13353 = v13350->regs;
  int v13354 = v13353[7];
  int v13355 = v13353[18];
  int v13364 = v13354 + v13355;
  v13353[21] = v13364;
  struct StateT * v13357 = slot_259(v13350);
  return v13357;
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

struct StateT * slot_418(struct StateT * v15919) {
  int * v15920 = v15919->saved_regs;
  int * v15921 = v15919->regs;
  int v15922 = v15921[5];
  v15920[5] = v15922;
  int v15924 = v15919->timer;
  int v15936 = v15924 + 1;
  v15919->timer = v15936;
  int * v15926 = v15919->regs;
  int v15927 = v15926[5];
  int v15928 = v15926[23];
  int v15939 = v15927 ^ v15928;
  v15926[5] = v15939;
  struct StateT * v15930 = slot_419(v15919);
  return v15930;
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

struct StateT * slot_490(struct StateT * v17107) {
  int v17108 = v17107->timer;
  int v17115 = v17108 + 1;
  v17107->timer = v17115;
  int * v17110 = v17107->regs;
  int v17111 = v17110[22];
  int v17118 = v17111 << 9;
  v17110[22] = v17118;
  struct StateT * v17113 = slot_491(v17107);
  return v17113;
}

struct StateT * slot_264(struct StateT * v13446) {
  int v13447 = v13446->timer;
  int v13454 = v13447 + 1;
  v13446->timer = v13454;
  int * v13449 = v13446->regs;
  int v13450 = v13449[21];
  int v13458 = (int)((unsigned int)v13450 >> 19);
  v13449[24] = v13458;
  struct StateT * v13452 = slot_265(v13446);
  return v13452;
}

struct StateT * slot_339(struct StateT * v14615) {
  int v14616 = v14615->timer;
  int v14624 = v14616 + 1;
  v14615->timer = v14624;
  int * v14618 = v14615->regs;
  int v14619 = v14618[6];
  int v14620 = v14618[15];
  int v14629 = v14619 + v14620;
  v14618[22] = v14629;
  struct StateT * v14622 = slot_340(v14615);
  return v14622;
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

struct StateT * slot_299(struct StateT * v13991) {
  int v13992 = v13991->timer;
  int v14000 = v13992 + 1;
  v13991->timer = v14000;
  int * v13994 = v13991->regs;
  int v13995 = v13994[28];
  int v13996 = v13994[18];
  int v14005 = v13995 + v13996;
  v13994[22] = v14005;
  struct StateT * v13998 = slot_300(v13991);
  return v13998;
}

struct StateT * slot_539(struct StateT * v17870) {
  int * v17871 = v17870->saved_regs;
  int * v17872 = v17870->regs;
  int v17873 = v17872[13];
  v17871[13] = v17873;
  int v17875 = v17870->timer;
  int v17886 = v17875 + 1;
  v17870->timer = v17886;
  int * v17877 = v17870->regs;
  int v17878 = v17877[13];
  int v17888 = v17878 + 1;
  v17877[13] = v17888;
  struct StateT * v17880 = slot_540(v17870);
  return v17880;
}

struct StateT * slot_319(struct StateT * v14303) {
  int v14304 = v14303->timer;
  int v14312 = v14304 + 1;
  v14303->timer = v14312;
  int * v14306 = v14303->regs;
  int v14307 = v14306[15];
  int v14308 = v14306[28];
  int v14317 = v14307 + v14308;
  v14306[22] = v14317;
  struct StateT * v14310 = slot_320(v14303);
  return v14310;
}

struct StateT * slot_344(struct StateT * v14694) {
  int v14695 = v14694->timer;
  int v14702 = v14695 + 1;
  v14694->timer = v14702;
  int * v14697 = v14694->regs;
  int v14698 = v14697[21];
  int v14706 = (int)((unsigned int)v14698 >> 19);
  v14697[24] = v14706;
  struct StateT * v14700 = slot_345(v14694);
  return v14700;
}

struct StateT * slot_513(struct StateT * v17464) {
  int v17465 = v17464->timer;
  int v17472 = v17465 + 1;
  v17464->timer = v17472;
  int * v17467 = v17464->regs;
  int v17468 = v17467[23];
  int v17475 = v17468 << 13;
  v17467[23] = v17475;
  struct StateT * v17470 = slot_514(v17464);
  return v17470;
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

struct StateT * slot_497(struct StateT * v17214) {
  int v17215 = v17214->timer;
  int v17223 = v17215 + 1;
  v17214->timer = v17223;
  int * v17217 = v17214->regs;
  int v17218 = v17217[6];
  int v17219 = v17217[22];
  int v17227 = v17218 ^ v17219;
  v17217[6] = v17227;
  struct StateT * v17221 = slot_498(v17214);
  return v17221;
}

struct StateT * slot_455(struct StateT * v16530) {
  int * v16531 = v16530->saved_regs;
  int * v16532 = v16530->regs;
  int v16533 = v16532[30];
  v16531[30] = v16533;
  int v16535 = v16530->timer;
  int v16547 = v16535 + 1;
  v16530->timer = v16547;
  int * v16537 = v16530->regs;
  int v16538 = v16537[30];
  int v16539 = v16537[20];
  int v16550 = v16538 ^ v16539;
  v16537[30] = v16550;
  struct StateT * v16541 = slot_456(v16530);
  return v16541;
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

struct StateT * slot_432(struct StateT * v16145) {
  int v16146 = v16145->timer;
  int v16153 = v16146 + 1;
  v16145->timer = v16153;
  int * v16148 = v16145->regs;
  int v16149 = v16148[23];
  int v16157 = (int)((unsigned int)v16149 >> 19);
  v16148[24] = v16157;
  struct StateT * v16151 = slot_433(v16145);
  return v16151;
}

struct StateT * slot_306(struct StateT * v14099) {
  int v14100 = v14099->timer;
  int v14108 = v14100 + 1;
  v14099->timer = v14108;
  int * v14102 = v14099->regs;
  int v14103 = v14102[21];
  int v14104 = v14102[24];
  int v14112 = v14103 | v14104;
  v14102[21] = v14112;
  struct StateT * v14106 = slot_307(v14099);
  return v14106;
}

struct StateT * slot_312(struct StateT * v14189) {
  int v14190 = v14189->timer;
  int v14198 = v14190 + 1;
  v14189->timer = v14198;
  int * v14192 = v14189->regs;
  int v14193 = v14192[23];
  int v14194 = v14192[24];
  int v14202 = v14193 | v14194;
  v14192[23] = v14202;
  struct StateT * v14196 = slot_313(v14189);
  return v14196;
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

struct StateT * slot_240(struct StateT * v13072) {
  int v13073 = v13072->timer;
  int v13081 = v13073 + 1;
  v13072->timer = v13081;
  int * v13075 = v13072->regs;
  int v13076 = v13075[8];
  int v13077 = v13075[31];
  int v13086 = v13076 + v13077;
  v13075[23] = v13086;
  struct StateT * v13079 = slot_241(v13072);
  return v13079;
}

struct StateT * slot_247(struct StateT * v13179) {
  int v13180 = v13179->timer;
  int v13187 = v13180 + 1;
  v13179->timer = v13187;
  int * v13182 = v13179->regs;
  int v13183 = v13182[22];
  int v13191 = (int)((unsigned int)v13183 >> 23);
  v13182[24] = v13191;
  struct StateT * v13185 = slot_248(v13179);
  return v13185;
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

struct StateT * slot_348(struct StateT * v14754) {
  int v14755 = v14754->timer;
  int v14762 = v14755 + 1;
  v14754->timer = v14762;
  int * v14757 = v14754->regs;
  int v14758 = v14757[22];
  int v14765 = v14758 << 13;
  v14757[22] = v14765;
  struct StateT * v14760 = slot_349(v14754);
  return v14760;
}

struct StateT * slot_456(struct StateT * v16553) {
  int * v16554 = v16553->saved_regs;
  int * v16555 = v16553->regs;
  int v16556 = v16555[29];
  v16554[29] = v16556;
  int v16558 = v16553->timer;
  int v16570 = v16558 + 1;
  v16553->timer = v16570;
  int * v16560 = v16553->regs;
  int v16561 = v16560[29];
  int v16562 = v16560[21];
  int v16573 = v16561 ^ v16562;
  v16560[29] = v16573;
  struct StateT * v16564 = slot_457(v16553);
  return v16564;
}

struct StateT * slot_225(struct StateT * v12485) {
  int v12486 = v12485->timer;
  int v12596 = v12486 + 1;
  v12485->timer = v12596;
  int * v12488 = v12485->regs;
  int v12489 = v12488[2];
  int * v12490 = v12485->cache_tags;
  int v12600 = (((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2;
  int v12491 = v12490[v12600];
  int v12601 = ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12492 = v12490[v12601];
  int v12602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2);
  int v12493 = v12490[v12602];
  int v12603 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12494 = v12490[v12603];
  int v12495 = v12485->timer;
  int v12604 = v12495 + ((100 ^ (((~(((v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12491 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12491 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12485->timer = v12604;
  int * v12497 = v12485->cache_vals;
  bool v12605 = !(((~(((v12491 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12491 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v12590;
  if (v12605) {
    int * v12498 = v12485->cache_age;
    int v12607 = ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12492 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v12499 = v12498[v12607];
    int v12500 = v12498[v12600];
    int v12608 = v12500 + ((int)((unsigned int)(v12500 - v12499) >> 31));
    v12498[v12600] = v12608;
    int * v12502 = v12485->cache_age;
    int v12503 = v12502[v12601];
    int v12610 = v12503 + ((int)((unsigned int)(v12503 - v12499) >> 31));
    v12502[v12601] = v12610;
    int * v12505 = v12485->cache_age;
    v12505[v12607] = 0;
    v12590 = v12607;
  } else {
    int * v12508 = v12485->cache_age;
    int v12614 = (((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2;
    int v12509 = v12508[v12614];
    int * v12510 = v12485->cache_tags;
    int v12511 = v12510[v12614];
    int v12512 = v12508[v12601];
    int v12513 = v12510[v12601];
    bool v12616 = !(((~(((v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12493 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v12567;
    if (v12616) {
      int * v12514 = v12485->cache_age;
      int v12618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))) | (-(v12494 ^ ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v12515 = v12514[v12618];
      int v12516 = v12514[v12602];
      int v12619 = v12516 + ((int)((unsigned int)(v12516 - v12515) >> 31));
      v12514[v12602] = v12619;
      int * v12518 = v12485->cache_age;
      int v12519 = v12518[v12603];
      int v12621 = v12519 + ((int)((unsigned int)(v12519 - v12515) >> 31));
      v12518[v12603] = v12621;
      int * v12521 = v12485->cache_age;
      v12521[v12618] = 0;
      v12567 = v12618;
    } else {
      int * v12524 = v12485->cache_age;
      int v12625 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2);
      int v12525 = v12524[v12625];
      int * v12526 = v12485->cache_tags;
      int v12527 = v12526[v12625];
      int v12528 = v12524[v12603];
      int v12529 = v12526[v12603];
      int * v12530 = v12485->cache_dirty;
      int v12628 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12525 + ((~(((v12527 ^ -1) | (-(v12527 ^ -1))) >> 31)) & 2)) - (v12528 + ((~(((v12529 ^ -1) | (-(v12529 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12531 = v12530[v12628];
      bool v12629 = !(v12531 == 0);
      if (v12629) {
        int * v12532 = v12485->cache_tags;
        int v12533 = v12532[v12628];
        int * v12534 = v12485->cache_vals;
        int v12632 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12525 + ((~(((v12527 ^ -1) | (-(v12527 ^ -1))) >> 31)) & 2)) - (v12528 + ((~(((v12529 ^ -1) | (-(v12529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12535 = v12534[v12632];
        int v12633 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12525 + ((~(((v12527 ^ -1) | (-(v12527 ^ -1))) >> 31)) & 2)) - (v12528 + ((~(((v12529 ^ -1) | (-(v12529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12536 = v12534[v12633];
        int * v12537 = v12485->mem;
        int v12635 = v12533 * 2;
        v12537[v12635] = v12535;
        int * v12539 = v12485->mem;
        int v12638 = (v12533 * 2) + 1;
        v12539[v12638] = v12536;
        ;
      } else {
        ;
      }
      int * v12544 = v12485->mem;
      int v12643 = ((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) * 2;
      int v12545 = v12544[v12643];
      int v12644 = (((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) * 2) + 1;
      int v12546 = v12544[v12644];
      int * v12547 = v12485->cache_vals;
      int v12646 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12525 + ((~(((v12527 ^ -1) | (-(v12527 ^ -1))) >> 31)) & 2)) - (v12528 + ((~(((v12529 ^ -1) | (-(v12529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12547[v12646] = v12545;
      int * v12549 = v12485->cache_vals;
      int v12649 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12525 + ((~(((v12527 ^ -1) | (-(v12527 ^ -1))) >> 31)) & 2)) - (v12528 + ((~(((v12529 ^ -1) | (-(v12529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12549[v12649] = v12546;
      int * v12551 = v12485->cache_tags;
      int v12652 = (int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1);
      v12551[v12628] = v12652;
      int * v12553 = v12485->cache_dirty;
      v12553[v12628] = 0;
      int * v12555 = v12485->cache_age;
      v12555[v12628] = 1;
      int * v12557 = v12485->cache_age;
      int v12558 = v12557[v12628];
      int v12559 = v12557[v12602];
      int v12658 = v12559 + ((int)((unsigned int)(v12559 - v12558) >> 31));
      v12557[v12602] = v12658;
      int * v12561 = v12485->cache_age;
      int v12562 = v12561[v12603];
      int v12660 = v12562 + ((int)((unsigned int)(v12562 - v12558) >> 31));
      v12561[v12603] = v12660;
      int * v12564 = v12485->cache_age;
      v12564[v12628] = 0;
      v12567 = v12628;
    }
    int * v12568 = v12485->cache_vals;
    int v12663 = v12567 * 2;
    int v12569 = v12568[v12663];
    int v12664 = (v12567 * 2) + 1;
    int v12570 = v12568[v12664];
    int v12665 = (((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12509 + ((~(((v12511 ^ -1) | (-(v12511 ^ -1))) >> 31)) & 2)) - (v12512 + ((~(((v12513 ^ -1) | (-(v12513 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12568[v12665] = v12569;
    int * v12572 = v12485->cache_vals;
    int v12668 = ((((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12509 + ((~(((v12511 ^ -1) | (-(v12511 ^ -1))) >> 31)) & 2)) - (v12512 + ((~(((v12513 ^ -1) | (-(v12513 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12572[v12668] = v12570;
    int * v12574 = v12485->cache_tags;
    int v12671 = ((((int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12509 + ((~(((v12511 ^ -1) | (-(v12511 ^ -1))) >> 31)) & 2)) - (v12512 + ((~(((v12513 ^ -1) | (-(v12513 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12672 = (int)((unsigned int)((int)((unsigned int)(v12489 + 16) >> 2)) >> 1);
    v12574[v12671] = v12672;
    int * v12576 = v12485->cache_dirty;
    v12576[v12671] = 0;
    int * v12578 = v12485->cache_age;
    v12578[v12671] = 1;
    int * v12580 = v12485->cache_age;
    int v12581 = v12580[v12671];
    int v12582 = v12580[v12600];
    int v12678 = v12582 + ((int)((unsigned int)(v12582 - v12581) >> 31));
    v12580[v12600] = v12678;
    int * v12584 = v12485->cache_age;
    int v12585 = v12584[v12601];
    int v12680 = v12585 + ((int)((unsigned int)(v12585 - v12581) >> 31));
    v12584[v12601] = v12680;
    int * v12587 = v12485->cache_age;
    v12587[v12671] = 0;
    v12590 = v12671;
  }
  int v12683 = (v12590 * 2) + (((int)((unsigned int)(v12489 + 16) >> 2)) & 1);
  int v12591 = v12497[v12683];
  int * v12592 = v12485->regs;
  v12592[23] = v12591;
  struct StateT * v12594 = slot_227(v12485);
  return v12594;
}

struct StateT * slot_467(struct StateT * v16750) {
  int v16751 = v16750->timer;
  int v16758 = v16751 + 1;
  v16750->timer = v16758;
  int * v16753 = v16750->regs;
  int v16754 = v16753[21];
  int v16761 = v16754 << 7;
  v16753[21] = v16761;
  struct StateT * v16756 = slot_468(v16750);
  return v16756;
}

struct StateT * slot_285(struct StateT * v13773) {
  int v13774 = v13773->timer;
  int v13781 = v13774 + 1;
  v13773->timer = v13781;
  int * v13776 = v13773->regs;
  int v13777 = v13776[21];
  int v13784 = v13777 << 18;
  v13776[21] = v13784;
  struct StateT * v13779 = slot_286(v13773);
  return v13779;
}

struct StateT * slot_213(struct StateT * v11171) {
  int v11172 = v11171->timer;
  int v11282 = v11172 + 1;
  v11171->timer = v11282;
  int * v11174 = v11171->regs;
  int v11175 = v11174[2];
  int * v11176 = v11171->cache_tags;
  int v11286 = (((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2;
  int v11177 = v11176[v11286];
  int v11287 = ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11178 = v11176[v11287];
  int v11288 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2);
  int v11179 = v11176[v11288];
  int v11289 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11180 = v11176[v11289];
  int v11181 = v11171->timer;
  int v11290 = v11181 + ((100 ^ (((~(((v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11177 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11177 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11171->timer = v11290;
  int * v11183 = v11171->cache_vals;
  bool v11291 = !(((~(((v11177 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11177 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v11276;
  if (v11291) {
    int * v11184 = v11171->cache_age;
    int v11293 = ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11178 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v11185 = v11184[v11293];
    int v11186 = v11184[v11286];
    int v11294 = v11186 + ((int)((unsigned int)(v11186 - v11185) >> 31));
    v11184[v11286] = v11294;
    int * v11188 = v11171->cache_age;
    int v11189 = v11188[v11287];
    int v11296 = v11189 + ((int)((unsigned int)(v11189 - v11185) >> 31));
    v11188[v11287] = v11296;
    int * v11191 = v11171->cache_age;
    v11191[v11293] = 0;
    v11276 = v11293;
  } else {
    int * v11194 = v11171->cache_age;
    int v11300 = (((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2;
    int v11195 = v11194[v11300];
    int * v11196 = v11171->cache_tags;
    int v11197 = v11196[v11300];
    int v11198 = v11194[v11287];
    int v11199 = v11196[v11287];
    bool v11302 = !(((~(((v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11179 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v11253;
    if (v11302) {
      int * v11200 = v11171->cache_age;
      int v11304 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))) | (-(v11180 ^ ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v11201 = v11200[v11304];
      int v11202 = v11200[v11288];
      int v11305 = v11202 + ((int)((unsigned int)(v11202 - v11201) >> 31));
      v11200[v11288] = v11305;
      int * v11204 = v11171->cache_age;
      int v11205 = v11204[v11289];
      int v11307 = v11205 + ((int)((unsigned int)(v11205 - v11201) >> 31));
      v11204[v11289] = v11307;
      int * v11207 = v11171->cache_age;
      v11207[v11304] = 0;
      v11253 = v11304;
    } else {
      int * v11210 = v11171->cache_age;
      int v11311 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2);
      int v11211 = v11210[v11311];
      int * v11212 = v11171->cache_tags;
      int v11213 = v11212[v11311];
      int v11214 = v11210[v11289];
      int v11215 = v11212[v11289];
      int * v11216 = v11171->cache_dirty;
      int v11314 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11211 + ((~(((v11213 ^ -1) | (-(v11213 ^ -1))) >> 31)) & 2)) - (v11214 + ((~(((v11215 ^ -1) | (-(v11215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11217 = v11216[v11314];
      bool v11315 = !(v11217 == 0);
      if (v11315) {
        int * v11218 = v11171->cache_tags;
        int v11219 = v11218[v11314];
        int * v11220 = v11171->cache_vals;
        int v11318 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11211 + ((~(((v11213 ^ -1) | (-(v11213 ^ -1))) >> 31)) & 2)) - (v11214 + ((~(((v11215 ^ -1) | (-(v11215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11221 = v11220[v11318];
        int v11319 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11211 + ((~(((v11213 ^ -1) | (-(v11213 ^ -1))) >> 31)) & 2)) - (v11214 + ((~(((v11215 ^ -1) | (-(v11215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11222 = v11220[v11319];
        int * v11223 = v11171->mem;
        int v11321 = v11219 * 2;
        v11223[v11321] = v11221;
        int * v11225 = v11171->mem;
        int v11324 = (v11219 * 2) + 1;
        v11225[v11324] = v11222;
        ;
      } else {
        ;
      }
      int * v11230 = v11171->mem;
      int v11329 = ((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) * 2;
      int v11231 = v11230[v11329];
      int v11330 = (((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) * 2) + 1;
      int v11232 = v11230[v11330];
      int * v11233 = v11171->cache_vals;
      int v11332 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11211 + ((~(((v11213 ^ -1) | (-(v11213 ^ -1))) >> 31)) & 2)) - (v11214 + ((~(((v11215 ^ -1) | (-(v11215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11233[v11332] = v11231;
      int * v11235 = v11171->cache_vals;
      int v11335 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11211 + ((~(((v11213 ^ -1) | (-(v11213 ^ -1))) >> 31)) & 2)) - (v11214 + ((~(((v11215 ^ -1) | (-(v11215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11235[v11335] = v11232;
      int * v11237 = v11171->cache_tags;
      int v11338 = (int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1);
      v11237[v11314] = v11338;
      int * v11239 = v11171->cache_dirty;
      v11239[v11314] = 0;
      int * v11241 = v11171->cache_age;
      v11241[v11314] = 1;
      int * v11243 = v11171->cache_age;
      int v11244 = v11243[v11314];
      int v11245 = v11243[v11288];
      int v11344 = v11245 + ((int)((unsigned int)(v11245 - v11244) >> 31));
      v11243[v11288] = v11344;
      int * v11247 = v11171->cache_age;
      int v11248 = v11247[v11289];
      int v11346 = v11248 + ((int)((unsigned int)(v11248 - v11244) >> 31));
      v11247[v11289] = v11346;
      int * v11250 = v11171->cache_age;
      v11250[v11314] = 0;
      v11253 = v11314;
    }
    int * v11254 = v11171->cache_vals;
    int v11349 = v11253 * 2;
    int v11255 = v11254[v11349];
    int v11350 = (v11253 * 2) + 1;
    int v11256 = v11254[v11350];
    int v11351 = (((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11195 + ((~(((v11197 ^ -1) | (-(v11197 ^ -1))) >> 31)) & 2)) - (v11198 + ((~(((v11199 ^ -1) | (-(v11199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11254[v11351] = v11255;
    int * v11258 = v11171->cache_vals;
    int v11354 = ((((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11195 + ((~(((v11197 ^ -1) | (-(v11197 ^ -1))) >> 31)) & 2)) - (v11198 + ((~(((v11199 ^ -1) | (-(v11199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11258[v11354] = v11256;
    int * v11260 = v11171->cache_tags;
    int v11357 = ((((int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11195 + ((~(((v11197 ^ -1) | (-(v11197 ^ -1))) >> 31)) & 2)) - (v11198 + ((~(((v11199 ^ -1) | (-(v11199 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11358 = (int)((unsigned int)((int)((unsigned int)(v11175 + 40) >> 2)) >> 1);
    v11260[v11357] = v11358;
    int * v11262 = v11171->cache_dirty;
    v11262[v11357] = 0;
    int * v11264 = v11171->cache_age;
    v11264[v11357] = 1;
    int * v11266 = v11171->cache_age;
    int v11267 = v11266[v11357];
    int v11268 = v11266[v11286];
    int v11364 = v11268 + ((int)((unsigned int)(v11268 - v11267) >> 31));
    v11266[v11286] = v11364;
    int * v11270 = v11171->cache_age;
    int v11271 = v11270[v11287];
    int v11366 = v11271 + ((int)((unsigned int)(v11271 - v11267) >> 31));
    v11270[v11287] = v11366;
    int * v11273 = v11171->cache_age;
    v11273[v11357] = 0;
    v11276 = v11357;
  }
  int v11369 = (v11276 * 2) + (((int)((unsigned int)(v11175 + 40) >> 2)) & 1);
  int v11277 = v11183[v11369];
  int * v11278 = v11171->regs;
  v11278[9] = v11277;
  struct StateT * v11280 = slot_215(v11171);
  return v11280;
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

struct StateT * slot_263(struct StateT * v13430) {
  int v13431 = v13430->timer;
  int v13439 = v13431 + 1;
  v13430->timer = v13439;
  int * v13433 = v13430->regs;
  int v13434 = v13433[20];
  int v13435 = v13433[24];
  int v13443 = v13434 | v13435;
  v13433[20] = v13443;
  struct StateT * v13437 = slot_264(v13430);
  return v13437;
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

struct StateT * slot_293(struct StateT * v13893) {
  int v13894 = v13893->timer;
  int v13902 = v13894 + 1;
  v13893->timer = v13902;
  int * v13896 = v13893->regs;
  int v13897 = v13896[30];
  int v13898 = v13896[20];
  int v13906 = v13897 ^ v13898;
  v13896[30] = v13906;
  struct StateT * v13900 = slot_294(v13893);
  return v13900;
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

struct StateT * slot_288(struct StateT * v13818) {
  int v13819 = v13818->timer;
  int v13826 = v13819 + 1;
  v13818->timer = v13826;
  int * v13821 = v13818->regs;
  int v13822 = v13821[22];
  int v13829 = v13822 << 18;
  v13821[22] = v13829;
  struct StateT * v13824 = slot_289(v13818);
  return v13824;
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

struct StateT * slot_384(struct StateT * v15345) {
  int v15346 = v15345->timer;
  int v15353 = v15346 + 1;
  v15345->timer = v15353;
  int * v15348 = v15345->regs;
  int v15349 = v15348[20];
  int v15356 = v15349 << 7;
  v15348[20] = v15356;
  struct StateT * v15351 = slot_385(v15345);
  return v15351;
}

struct StateT * slot_486(struct StateT * v17047) {
  int v17048 = v17047->timer;
  int v17055 = v17048 + 1;
  v17047->timer = v17055;
  int * v17050 = v17047->regs;
  int v17051 = v17050[21];
  int v17059 = (int)((unsigned int)v17051 >> 23);
  v17050[24] = v17059;
  struct StateT * v17053 = slot_487(v17047);
  return v17053;
}

struct StateT * slot_347(struct StateT * v14739) {
  int v14740 = v14739->timer;
  int v14747 = v14740 + 1;
  v14739->timer = v14747;
  int * v14742 = v14739->regs;
  int v14743 = v14742[22];
  int v14751 = (int)((unsigned int)v14743 >> 19);
  v14742[24] = v14751;
  struct StateT * v14745 = slot_348(v14739);
  return v14745;
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

struct StateT * slot_473(struct StateT * v16840) {
  int v16841 = v16840->timer;
  int v16848 = v16841 + 1;
  v16840->timer = v16848;
  int * v16843 = v16840->regs;
  int v16844 = v16843[23];
  int v16851 = v16844 << 7;
  v16843[23] = v16851;
  struct StateT * v16846 = slot_474(v16840);
  return v16846;
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

struct StateT * slot_216(struct StateT * v11594) {
  int v11595 = v11594->timer;
  int v11602 = v11595 + 1;
  v11594->timer = v11602;
  int * v11597 = v11594->regs;
  int v11598 = v11597[21];
  int v11605 = v11598 << 7;
  v11597[21] = v11605;
  struct StateT * v11600 = slot_218(v11594);
  return v11600;
}

struct StateT * slot_468(struct StateT * v16764) {
  int v16765 = v16764->timer;
  int v16773 = v16765 + 1;
  v16764->timer = v16773;
  int * v16767 = v16764->regs;
  int v16768 = v16767[21];
  int v16769 = v16767[24];
  int v16777 = v16768 | v16769;
  v16767[21] = v16777;
  struct StateT * v16771 = slot_469(v16764);
  return v16771;
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

struct StateT * slot_248(struct StateT * v13194) {
  int v13195 = v13194->timer;
  int v13202 = v13195 + 1;
  v13194->timer = v13202;
  int * v13197 = v13194->regs;
  int v13198 = v13197[22];
  int v13205 = v13198 << 9;
  v13197[22] = v13205;
  struct StateT * v13200 = slot_249(v13194);
  return v13200;
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

struct StateT * slot_485(struct StateT * v17031) {
  int v17032 = v17031->timer;
  int v17040 = v17032 + 1;
  v17031->timer = v17040;
  int * v17034 = v17031->regs;
  int v17035 = v17034[20];
  int v17036 = v17034[24];
  int v17044 = v17035 | v17036;
  v17034[20] = v17044;
  struct StateT * v17038 = slot_486(v17031);
  return v17038;
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

struct StateT * slot_350(struct StateT * v14784) {
  int v14785 = v14784->timer;
  int v14792 = v14785 + 1;
  v14784->timer = v14792;
  int * v14787 = v14784->regs;
  int v14788 = v14787[23];
  int v14796 = (int)((unsigned int)v14788 >> 19);
  v14787[24] = v14796;
  struct StateT * v14790 = slot_351(v14784);
  return v14790;
}

struct StateT * slot_392(struct StateT * v15465) {
  int v15466 = v15465->timer;
  int v15473 = v15466 + 1;
  v15465->timer = v15473;
  int * v15468 = v15465->regs;
  int v15469 = v15468[23];
  int v15477 = (int)((unsigned int)v15469 >> 25);
  v15468[24] = v15477;
  struct StateT * v15471 = slot_393(v15465);
  return v15471;
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

struct StateT * slot_378(struct StateT * v15219) {
  int v15220 = v15219->timer;
  int v15224 = v15220 + 1;
  v15219->timer = v15224;
  struct StateT * v15222 = slot_379(v15219);
  return v15222;
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

struct StateT * slot_417(struct StateT * v15896) {
  int * v15897 = v15896->saved_regs;
  int * v15898 = v15896->regs;
  int v15899 = v15898[17];
  v15897[17] = v15899;
  int v15901 = v15896->timer;
  int v15913 = v15901 + 1;
  v15896->timer = v15913;
  int * v15903 = v15896->regs;
  int v15904 = v15903[17];
  int v15905 = v15903[22];
  int v15916 = v15904 ^ v15905;
  v15903[17] = v15916;
  struct StateT * v15907 = slot_418(v15896);
  return v15907;
}

struct StateT * slot_405(struct StateT * v15699) {
  int v15700 = v15699->timer;
  int v15708 = v15700 + 1;
  v15699->timer = v15708;
  int * v15702 = v15699->regs;
  int v15703 = v15702[20];
  int v15704 = v15702[24];
  int v15712 = v15703 | v15704;
  v15702[20] = v15712;
  struct StateT * v15706 = slot_406(v15699);
  return v15706;
}

struct StateT * slot_215(struct StateT * v11390) {
  int v11391 = v11390->timer;
  int v11501 = v11391 + 1;
  v11390->timer = v11501;
  int * v11393 = v11390->regs;
  int v11394 = v11393[2];
  int * v11395 = v11390->cache_tags;
  int v11505 = (((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2;
  int v11396 = v11395[v11505];
  int v11506 = ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11397 = v11395[v11506];
  int v11507 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2);
  int v11398 = v11395[v11507];
  int v11508 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11399 = v11395[v11508];
  int v11400 = v11390->timer;
  int v11509 = v11400 + ((100 ^ (((~(((v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11396 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11396 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11390->timer = v11509;
  int * v11402 = v11390->cache_vals;
  bool v11510 = !(((~(((v11396 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11396 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v11495;
  if (v11510) {
    int * v11403 = v11390->cache_age;
    int v11512 = ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11397 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v11404 = v11403[v11512];
    int v11405 = v11403[v11505];
    int v11513 = v11405 + ((int)((unsigned int)(v11405 - v11404) >> 31));
    v11403[v11505] = v11513;
    int * v11407 = v11390->cache_age;
    int v11408 = v11407[v11506];
    int v11515 = v11408 + ((int)((unsigned int)(v11408 - v11404) >> 31));
    v11407[v11506] = v11515;
    int * v11410 = v11390->cache_age;
    v11410[v11512] = 0;
    v11495 = v11512;
  } else {
    int * v11413 = v11390->cache_age;
    int v11519 = (((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2;
    int v11414 = v11413[v11519];
    int * v11415 = v11390->cache_tags;
    int v11416 = v11415[v11519];
    int v11417 = v11413[v11506];
    int v11418 = v11415[v11506];
    bool v11521 = !(((~(((v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11398 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v11472;
    if (v11521) {
      int * v11419 = v11390->cache_age;
      int v11523 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))) | (-(v11399 ^ ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v11420 = v11419[v11523];
      int v11421 = v11419[v11507];
      int v11524 = v11421 + ((int)((unsigned int)(v11421 - v11420) >> 31));
      v11419[v11507] = v11524;
      int * v11423 = v11390->cache_age;
      int v11424 = v11423[v11508];
      int v11526 = v11424 + ((int)((unsigned int)(v11424 - v11420) >> 31));
      v11423[v11508] = v11526;
      int * v11426 = v11390->cache_age;
      v11426[v11523] = 0;
      v11472 = v11523;
    } else {
      int * v11429 = v11390->cache_age;
      int v11530 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2);
      int v11430 = v11429[v11530];
      int * v11431 = v11390->cache_tags;
      int v11432 = v11431[v11530];
      int v11433 = v11429[v11508];
      int v11434 = v11431[v11508];
      int * v11435 = v11390->cache_dirty;
      int v11533 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11430 + ((~(((v11432 ^ -1) | (-(v11432 ^ -1))) >> 31)) & 2)) - (v11433 + ((~(((v11434 ^ -1) | (-(v11434 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11436 = v11435[v11533];
      bool v11534 = !(v11436 == 0);
      if (v11534) {
        int * v11437 = v11390->cache_tags;
        int v11438 = v11437[v11533];
        int * v11439 = v11390->cache_vals;
        int v11537 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11430 + ((~(((v11432 ^ -1) | (-(v11432 ^ -1))) >> 31)) & 2)) - (v11433 + ((~(((v11434 ^ -1) | (-(v11434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11440 = v11439[v11537];
        int v11538 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11430 + ((~(((v11432 ^ -1) | (-(v11432 ^ -1))) >> 31)) & 2)) - (v11433 + ((~(((v11434 ^ -1) | (-(v11434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11441 = v11439[v11538];
        int * v11442 = v11390->mem;
        int v11540 = v11438 * 2;
        v11442[v11540] = v11440;
        int * v11444 = v11390->mem;
        int v11543 = (v11438 * 2) + 1;
        v11444[v11543] = v11441;
        ;
      } else {
        ;
      }
      int * v11449 = v11390->mem;
      int v11548 = ((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) * 2;
      int v11450 = v11449[v11548];
      int v11549 = (((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) * 2) + 1;
      int v11451 = v11449[v11549];
      int * v11452 = v11390->cache_vals;
      int v11551 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11430 + ((~(((v11432 ^ -1) | (-(v11432 ^ -1))) >> 31)) & 2)) - (v11433 + ((~(((v11434 ^ -1) | (-(v11434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11452[v11551] = v11450;
      int * v11454 = v11390->cache_vals;
      int v11554 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11430 + ((~(((v11432 ^ -1) | (-(v11432 ^ -1))) >> 31)) & 2)) - (v11433 + ((~(((v11434 ^ -1) | (-(v11434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11454[v11554] = v11451;
      int * v11456 = v11390->cache_tags;
      int v11557 = (int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1);
      v11456[v11533] = v11557;
      int * v11458 = v11390->cache_dirty;
      v11458[v11533] = 0;
      int * v11460 = v11390->cache_age;
      v11460[v11533] = 1;
      int * v11462 = v11390->cache_age;
      int v11463 = v11462[v11533];
      int v11464 = v11462[v11507];
      int v11563 = v11464 + ((int)((unsigned int)(v11464 - v11463) >> 31));
      v11462[v11507] = v11563;
      int * v11466 = v11390->cache_age;
      int v11467 = v11466[v11508];
      int v11565 = v11467 + ((int)((unsigned int)(v11467 - v11463) >> 31));
      v11466[v11508] = v11565;
      int * v11469 = v11390->cache_age;
      v11469[v11533] = 0;
      v11472 = v11533;
    }
    int * v11473 = v11390->cache_vals;
    int v11568 = v11472 * 2;
    int v11474 = v11473[v11568];
    int v11569 = (v11472 * 2) + 1;
    int v11475 = v11473[v11569];
    int v11570 = (((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11414 + ((~(((v11416 ^ -1) | (-(v11416 ^ -1))) >> 31)) & 2)) - (v11417 + ((~(((v11418 ^ -1) | (-(v11418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11473[v11570] = v11474;
    int * v11477 = v11390->cache_vals;
    int v11573 = ((((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11414 + ((~(((v11416 ^ -1) | (-(v11416 ^ -1))) >> 31)) & 2)) - (v11417 + ((~(((v11418 ^ -1) | (-(v11418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11477[v11573] = v11475;
    int * v11479 = v11390->cache_tags;
    int v11576 = ((((int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11414 + ((~(((v11416 ^ -1) | (-(v11416 ^ -1))) >> 31)) & 2)) - (v11417 + ((~(((v11418 ^ -1) | (-(v11418 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11577 = (int)((unsigned int)((int)((unsigned int)(v11394 + 36) >> 2)) >> 1);
    v11479[v11576] = v11577;
    int * v11481 = v11390->cache_dirty;
    v11481[v11576] = 0;
    int * v11483 = v11390->cache_age;
    v11483[v11576] = 1;
    int * v11485 = v11390->cache_age;
    int v11486 = v11485[v11576];
    int v11487 = v11485[v11505];
    int v11583 = v11487 + ((int)((unsigned int)(v11487 - v11486) >> 31));
    v11485[v11505] = v11583;
    int * v11489 = v11390->cache_age;
    int v11490 = v11489[v11506];
    int v11585 = v11490 + ((int)((unsigned int)(v11490 - v11486) >> 31));
    v11489[v11506] = v11585;
    int * v11492 = v11390->cache_age;
    v11492[v11576] = 0;
    v11495 = v11576;
  }
  int v11588 = (v11495 * 2) + (((int)((unsigned int)(v11394 + 36) >> 2)) & 1);
  int v11496 = v11402[v11588];
  int * v11497 = v11390->regs;
  v11497[18] = v11496;
  struct StateT * v11499 = slot_217(v11390);
  return v11499;
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

struct StateT * slot_220(struct StateT * v12032) {
  int v12033 = v12032->timer;
  int v12040 = v12033 + 1;
  v12032->timer = v12040;
  int * v12035 = v12032->regs;
  int v12036 = v12035[22];
  int v12044 = (int)((unsigned int)v12036 >> 25);
  v12035[24] = v12044;
  struct StateT * v12038 = slot_222(v12032);
  return v12038;
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

struct StateT * slot_463(struct StateT * v16690) {
  int v16691 = v16690->timer;
  int v16698 = v16691 + 1;
  v16690->timer = v16698;
  int * v16693 = v16690->regs;
  int v16694 = v16693[20];
  int v16702 = (int)((unsigned int)v16694 >> 25);
  v16693[24] = v16702;
  struct StateT * v16696 = slot_464(v16690);
  return v16696;
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

struct StateT * slot_387(struct StateT * v15390) {
  int v15391 = v15390->timer;
  int v15398 = v15391 + 1;
  v15390->timer = v15398;
  int * v15393 = v15390->regs;
  int v15394 = v15393[21];
  int v15401 = v15394 << 7;
  v15393[21] = v15401;
  struct StateT * v15396 = slot_388(v15390);
  return v15396;
}

struct StateT * slot_273(struct StateT * v13581) {
  int v13582 = v13581->timer;
  int v13590 = v13582 + 1;
  v13581->timer = v13590;
  int * v13584 = v13581->regs;
  int v13585 = v13584[16];
  int v13586 = v13584[20];
  int v13594 = v13585 ^ v13586;
  v13584[16] = v13594;
  struct StateT * v13588 = slot_274(v13581);
  return v13588;
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

struct StateT * slot_495(struct StateT * v17182) {
  int v17183 = v17182->timer;
  int v17191 = v17183 + 1;
  v17182->timer = v17191;
  int * v17185 = v17182->regs;
  int v17186 = v17185[17];
  int v17187 = v17185[20];
  int v17195 = v17186 ^ v17187;
  v17185[17] = v17195;
  struct StateT * v17189 = slot_496(v17182);
  return v17189;
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

struct StateT * slot_208(struct StateT * v10607) {
  int v10608 = v10607->timer;
  int v10615 = v10608 + 1;
  v10607->timer = v10615;
  int * v10610 = v10607->regs;
  int v10611 = v10610[20];
  int v10619 = (int)((unsigned int)v10611 >> 25);
  v10610[24] = v10619;
  struct StateT * v10613 = slot_210(v10607);
  return v10613;
}

struct StateT * slot_301(struct StateT * v14025) {
  int v14026 = v14025->timer;
  int v14033 = v14026 + 1;
  v14025->timer = v14033;
  int * v14028 = v14025->regs;
  int v14029 = v14028[20];
  int v14037 = (int)((unsigned int)v14029 >> 25);
  v14028[24] = v14037;
  struct StateT * v14031 = slot_302(v14025);
  return v14031;
}

struct StateT * slot_502(struct StateT * v17297) {
  int v17298 = v17297->timer;
  int v17306 = v17298 + 1;
  v17297->timer = v17306;
  int * v17300 = v17297->regs;
  int v17301 = v17300[7];
  int v17302 = v17300[16];
  int v17311 = v17301 + v17302;
  v17300[23] = v17311;
  struct StateT * v17304 = slot_503(v17297);
  return v17304;
}

struct StateT * slot_506(struct StateT * v17359) {
  int v17360 = v17359->timer;
  int v17367 = v17360 + 1;
  v17359->timer = v17367;
  int * v17362 = v17359->regs;
  int v17363 = v17362[21];
  int v17371 = (int)((unsigned int)v17363 >> 19);
  v17362[24] = v17371;
  struct StateT * v17365 = slot_507(v17359);
  return v17365;
}

struct StateT * slot_413(struct StateT * v15820) {
  int v15821 = v15820->timer;
  int v15828 = v15821 + 1;
  v15820->timer = v15828;
  int * v15823 = v15820->regs;
  int v15824 = v15823[23];
  int v15831 = v15824 << 9;
  v15823[23] = v15831;
  struct StateT * v15826 = slot_414(v15820);
  return v15826;
}

struct StateT * slot_320(struct StateT * v14320) {
  int v14321 = v14320->timer;
  int v14329 = v14321 + 1;
  v14320->timer = v14329;
  int * v14323 = v14320->regs;
  int v14324 = v14323[16];
  int v14325 = v14323[31];
  int v14334 = v14324 + v14325;
  v14323[23] = v14334;
  struct StateT * v14327 = slot_321(v14320);
  return v14327;
}

struct StateT * slot_281(struct StateT * v13713) {
  int v13714 = v13713->timer;
  int v13721 = v13714 + 1;
  v13713->timer = v13721;
  int * v13716 = v13713->regs;
  int v13717 = v13716[20];
  int v13725 = (int)((unsigned int)v13717 >> 14);
  v13716[24] = v13725;
  struct StateT * v13719 = slot_282(v13713);
  return v13719;
}

struct StateT * slot_533(struct StateT * v17776) {
  int v17777 = v17776->timer;
  int v17784 = v17777 + 1;
  v17776->timer = v17784;
  int * v17779 = v17776->regs;
  int v17780 = v17779[23];
  int v17787 = v17780 << 18;
  v17779[23] = v17787;
  struct StateT * v17782 = slot_534(v17776);
  return v17782;
}

struct StateT * slot_203(struct StateT * v9628) {
  int v9629 = v9628->timer;
  int v9799 = v9629 + 1;
  v9628->timer = v9799;
  int * v9631 = v9628->regs;
  int v9632 = v9631[10];
  int v9633 = v9631[12];
  int * v9634 = v9628->cache_tags;
  int v9804 = (((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2;
  int v9635 = v9634[v9804];
  int v9805 = ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9636 = v9634[v9805];
  int v9806 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2);
  int v9637 = v9634[v9806];
  int v9807 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9638 = v9634[v9807];
  int v9639 = v9628->timer;
  int v9808 = v9639 + ((100 ^ (((~(((v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9635 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9635 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9628->timer = v9808;
  bool v9809 = !(((~(((v9635 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9635 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v9733;
  if (v9809) {
    int * v9641 = v9628->cache_age;
    int v9811 = ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9636 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v9642 = v9641[v9811];
    int v9643 = v9641[v9804];
    int v9812 = v9643 + ((int)((unsigned int)(v9643 - v9642) >> 31));
    v9641[v9804] = v9812;
    int * v9645 = v9628->cache_age;
    int v9646 = v9645[v9805];
    int v9814 = v9646 + ((int)((unsigned int)(v9646 - v9642) >> 31));
    v9645[v9805] = v9814;
    int * v9648 = v9628->cache_age;
    v9648[v9811] = 0;
    v9733 = v9811;
  } else {
    int * v9651 = v9628->cache_age;
    int v9818 = (((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2;
    int v9652 = v9651[v9818];
    int * v9653 = v9628->cache_tags;
    int v9654 = v9653[v9818];
    int v9655 = v9651[v9805];
    int v9656 = v9653[v9805];
    bool v9820 = !(((~(((v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9637 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v9710;
    if (v9820) {
      int * v9657 = v9628->cache_age;
      int v9822 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9638 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v9658 = v9657[v9822];
      int v9659 = v9657[v9806];
      int v9823 = v9659 + ((int)((unsigned int)(v9659 - v9658) >> 31));
      v9657[v9806] = v9823;
      int * v9661 = v9628->cache_age;
      int v9662 = v9661[v9807];
      int v9825 = v9662 + ((int)((unsigned int)(v9662 - v9658) >> 31));
      v9661[v9807] = v9825;
      int * v9664 = v9628->cache_age;
      v9664[v9822] = 0;
      v9710 = v9822;
    } else {
      int * v9667 = v9628->cache_age;
      int v9829 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2);
      int v9668 = v9667[v9829];
      int * v9669 = v9628->cache_tags;
      int v9670 = v9669[v9829];
      int v9671 = v9667[v9807];
      int v9672 = v9669[v9807];
      int * v9673 = v9628->cache_dirty;
      int v9832 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9668 + ((~(((v9670 ^ -1) | (-(v9670 ^ -1))) >> 31)) & 2)) - (v9671 + ((~(((v9672 ^ -1) | (-(v9672 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9674 = v9673[v9832];
      bool v9833 = !(v9674 == 0);
      if (v9833) {
        int * v9675 = v9628->cache_tags;
        int v9676 = v9675[v9832];
        int * v9677 = v9628->cache_vals;
        int v9836 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9668 + ((~(((v9670 ^ -1) | (-(v9670 ^ -1))) >> 31)) & 2)) - (v9671 + ((~(((v9672 ^ -1) | (-(v9672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9678 = v9677[v9836];
        int v9837 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9668 + ((~(((v9670 ^ -1) | (-(v9670 ^ -1))) >> 31)) & 2)) - (v9671 + ((~(((v9672 ^ -1) | (-(v9672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9679 = v9677[v9837];
        int * v9680 = v9628->mem;
        int v9839 = v9676 * 2;
        v9680[v9839] = v9678;
        int * v9682 = v9628->mem;
        int v9842 = (v9676 * 2) + 1;
        v9682[v9842] = v9679;
        ;
      } else {
        ;
      }
      int * v9687 = v9628->mem;
      int v9847 = ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) * 2;
      int v9688 = v9687[v9847];
      int v9848 = (((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) * 2) + 1;
      int v9689 = v9687[v9848];
      int * v9690 = v9628->cache_vals;
      int v9850 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9668 + ((~(((v9670 ^ -1) | (-(v9670 ^ -1))) >> 31)) & 2)) - (v9671 + ((~(((v9672 ^ -1) | (-(v9672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9690[v9850] = v9688;
      int * v9692 = v9628->cache_vals;
      int v9853 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9668 + ((~(((v9670 ^ -1) | (-(v9670 ^ -1))) >> 31)) & 2)) - (v9671 + ((~(((v9672 ^ -1) | (-(v9672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9692[v9853] = v9689;
      int * v9694 = v9628->cache_tags;
      int v9856 = (int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1);
      v9694[v9832] = v9856;
      int * v9696 = v9628->cache_dirty;
      v9696[v9832] = 0;
      int * v9698 = v9628->cache_age;
      v9698[v9832] = 1;
      int * v9700 = v9628->cache_age;
      int v9701 = v9700[v9832];
      int v9702 = v9700[v9806];
      int v9862 = v9702 + ((int)((unsigned int)(v9702 - v9701) >> 31));
      v9700[v9806] = v9862;
      int * v9704 = v9628->cache_age;
      int v9705 = v9704[v9807];
      int v9864 = v9705 + ((int)((unsigned int)(v9705 - v9701) >> 31));
      v9704[v9807] = v9864;
      int * v9707 = v9628->cache_age;
      v9707[v9832] = 0;
      v9710 = v9832;
    }
    int * v9711 = v9628->cache_vals;
    int v9867 = v9710 * 2;
    int v9712 = v9711[v9867];
    int v9868 = (v9710 * 2) + 1;
    int v9713 = v9711[v9868];
    int v9869 = (((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9711[v9869] = v9712;
    int * v9715 = v9628->cache_vals;
    int v9872 = ((((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9715[v9872] = v9713;
    int * v9717 = v9628->cache_tags;
    int v9875 = ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9876 = (int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1);
    v9717[v9875] = v9876;
    int * v9719 = v9628->cache_dirty;
    v9719[v9875] = 0;
    int * v9721 = v9628->cache_age;
    v9721[v9875] = 1;
    int * v9723 = v9628->cache_age;
    int v9724 = v9723[v9875];
    int v9725 = v9723[v9804];
    int v9882 = v9725 + ((int)((unsigned int)(v9725 - v9724) >> 31));
    v9723[v9804] = v9882;
    int * v9727 = v9628->cache_age;
    int v9728 = v9727[v9805];
    int v9884 = v9728 + ((int)((unsigned int)(v9728 - v9724) >> 31));
    v9727[v9805] = v9884;
    int * v9730 = v9628->cache_age;
    v9730[v9875] = 0;
    v9733 = v9875;
  }
  int * v9734 = v9628->cache_vals;
  int v9887 = (v9733 * 2) + (((int)((unsigned int)(v9632 + 16) >> 2)) & 1);
  v9734[v9887] = v9633;
  int * v9736 = v9628->cache_tags;
  int v9737 = v9736[v9806];
  int v9738 = v9736[v9807];
  bool v9890 = !(((~(((v9737 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9737 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9738 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9738 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v9792;
  if (v9890) {
    int * v9739 = v9628->cache_age;
    int v9892 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9738 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))) | (-(v9738 ^ ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v9740 = v9739[v9892];
    int v9741 = v9739[v9806];
    int v9893 = v9741 + ((int)((unsigned int)(v9741 - v9740) >> 31));
    v9739[v9806] = v9893;
    int * v9743 = v9628->cache_age;
    int v9744 = v9743[v9807];
    int v9895 = v9744 + ((int)((unsigned int)(v9744 - v9740) >> 31));
    v9743[v9807] = v9895;
    int * v9746 = v9628->cache_age;
    v9746[v9892] = 0;
    v9792 = v9892;
  } else {
    int * v9749 = v9628->cache_age;
    int v9899 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2);
    int v9750 = v9749[v9899];
    int * v9751 = v9628->cache_tags;
    int v9752 = v9751[v9899];
    int v9753 = v9749[v9807];
    int v9754 = v9751[v9807];
    int * v9755 = v9628->cache_dirty;
    int v9902 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9750 + ((~(((v9752 ^ -1) | (-(v9752 ^ -1))) >> 31)) & 2)) - (v9753 + ((~(((v9754 ^ -1) | (-(v9754 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9756 = v9755[v9902];
    bool v9903 = !(v9756 == 0);
    if (v9903) {
      int * v9757 = v9628->cache_tags;
      int v9758 = v9757[v9902];
      int * v9759 = v9628->cache_vals;
      int v9906 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9750 + ((~(((v9752 ^ -1) | (-(v9752 ^ -1))) >> 31)) & 2)) - (v9753 + ((~(((v9754 ^ -1) | (-(v9754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9760 = v9759[v9906];
      int v9907 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9750 + ((~(((v9752 ^ -1) | (-(v9752 ^ -1))) >> 31)) & 2)) - (v9753 + ((~(((v9754 ^ -1) | (-(v9754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9761 = v9759[v9907];
      int * v9762 = v9628->mem;
      int v9909 = v9758 * 2;
      v9762[v9909] = v9760;
      int * v9764 = v9628->mem;
      int v9912 = (v9758 * 2) + 1;
      v9764[v9912] = v9761;
      ;
    } else {
      ;
    }
    int * v9769 = v9628->mem;
    int v9917 = ((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) * 2;
    int v9770 = v9769[v9917];
    int v9918 = (((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) * 2) + 1;
    int v9771 = v9769[v9918];
    int * v9772 = v9628->cache_vals;
    int v9920 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9750 + ((~(((v9752 ^ -1) | (-(v9752 ^ -1))) >> 31)) & 2)) - (v9753 + ((~(((v9754 ^ -1) | (-(v9754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9772[v9920] = v9770;
    int * v9774 = v9628->cache_vals;
    int v9923 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9750 + ((~(((v9752 ^ -1) | (-(v9752 ^ -1))) >> 31)) & 2)) - (v9753 + ((~(((v9754 ^ -1) | (-(v9754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9774[v9923] = v9771;
    int * v9776 = v9628->cache_tags;
    int v9926 = (int)((unsigned int)((int)((unsigned int)(v9632 + 16) >> 2)) >> 1);
    v9776[v9902] = v9926;
    int * v9778 = v9628->cache_dirty;
    v9778[v9902] = 0;
    int * v9780 = v9628->cache_age;
    v9780[v9902] = 1;
    int * v9782 = v9628->cache_age;
    int v9783 = v9782[v9902];
    int v9784 = v9782[v9806];
    int v9932 = v9784 + ((int)((unsigned int)(v9784 - v9783) >> 31));
    v9782[v9806] = v9932;
    int * v9786 = v9628->cache_age;
    int v9787 = v9786[v9807];
    int v9934 = v9787 + ((int)((unsigned int)(v9787 - v9783) >> 31));
    v9786[v9807] = v9934;
    int * v9789 = v9628->cache_age;
    v9789[v9902] = 0;
    v9792 = v9902;
  }
  int * v9793 = v9628->cache_vals;
  int v9937 = (v9792 * 2) + (((int)((unsigned int)(v9632 + 16) >> 2)) & 1);
  v9793[v9937] = v9633;
  int * v9795 = v9628->cache_dirty;
  v9795[v9792] = 1;
  struct StateT * v9797 = slot_205(v9628);
  return v9797;
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

struct StateT * slot_447(struct StateT * v16410) {
  int v16411 = v16410->timer;
  int v16418 = v16411 + 1;
  v16410->timer = v16418;
  int * v16413 = v16410->regs;
  int v16414 = v16413[21];
  int v16421 = v16414 << 18;
  v16413[21] = v16421;
  struct StateT * v16416 = slot_448(v16410);
  return v16416;
}

struct StateT * slot_243(struct StateT * v13118) {
  int v13119 = v13118->timer;
  int v13127 = v13119 + 1;
  v13118->timer = v13127;
  int * v13121 = v13118->regs;
  int v13122 = v13121[20];
  int v13123 = v13121[24];
  int v13131 = v13122 | v13123;
  v13121[20] = v13131;
  struct StateT * v13125 = slot_244(v13118);
  return v13125;
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

struct StateT * slot_307(struct StateT * v14115) {
  int v14116 = v14115->timer;
  int v14123 = v14116 + 1;
  v14115->timer = v14123;
  int * v14118 = v14115->regs;
  int v14119 = v14118[22];
  int v14127 = (int)((unsigned int)v14119 >> 25);
  v14118[24] = v14127;
  struct StateT * v14121 = slot_308(v14115);
  return v14121;
}

struct StateT * slot_453(struct StateT * v16500) {
  int v16501 = v16500->timer;
  int v16508 = v16501 + 1;
  v16500->timer = v16508;
  int * v16503 = v16500->regs;
  int v16504 = v16503[23];
  int v16511 = v16504 << 18;
  v16503[23] = v16511;
  struct StateT * v16506 = slot_454(v16500);
  return v16506;
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

struct StateT * slot_370(struct StateT * v15096) {
  int v15097 = v15096->timer;
  int v15104 = v15097 + 1;
  v15096->timer = v15104;
  int * v15099 = v15096->regs;
  int v15100 = v15099[23];
  int v15108 = (int)((unsigned int)v15100 >> 14);
  v15099[24] = v15108;
  struct StateT * v15102 = slot_371(v15096);
  return v15102;
}

struct StateT * slot_206(struct StateT * v10275) {
  int v10276 = v10275->timer;
  int v10284 = v10276 + 1;
  v10275->timer = v10284;
  int * v10278 = v10275->regs;
  int v10279 = v10278[31];
  int v10280 = v10278[15];
  int v10289 = v10279 + v10280;
  v10278[23] = v10289;
  struct StateT * v10282 = slot_208(v10275);
  return v10282;
}

struct StateT * slot_227(struct StateT * v12704) {
  int v12705 = v12704->timer;
  int v12815 = v12705 + 1;
  v12704->timer = v12815;
  int * v12707 = v12704->regs;
  int v12708 = v12707[2];
  int * v12709 = v12704->cache_tags;
  int v12819 = (((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2;
  int v12710 = v12709[v12819];
  int v12820 = ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12711 = v12709[v12820];
  int v12821 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2);
  int v12712 = v12709[v12821];
  int v12822 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12713 = v12709[v12822];
  int v12714 = v12704->timer;
  int v12823 = v12714 + ((100 ^ (((~(((v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12710 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12710 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12704->timer = v12823;
  int * v12716 = v12704->cache_vals;
  bool v12824 = !(((~(((v12710 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12710 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v12809;
  if (v12824) {
    int * v12717 = v12704->cache_age;
    int v12826 = ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12711 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v12718 = v12717[v12826];
    int v12719 = v12717[v12819];
    int v12827 = v12719 + ((int)((unsigned int)(v12719 - v12718) >> 31));
    v12717[v12819] = v12827;
    int * v12721 = v12704->cache_age;
    int v12722 = v12721[v12820];
    int v12829 = v12722 + ((int)((unsigned int)(v12722 - v12718) >> 31));
    v12721[v12820] = v12829;
    int * v12724 = v12704->cache_age;
    v12724[v12826] = 0;
    v12809 = v12826;
  } else {
    int * v12727 = v12704->cache_age;
    int v12833 = (((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2;
    int v12728 = v12727[v12833];
    int * v12729 = v12704->cache_tags;
    int v12730 = v12729[v12833];
    int v12731 = v12727[v12820];
    int v12732 = v12729[v12820];
    bool v12835 = !(((~(((v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v12786;
    if (v12835) {
      int * v12733 = v12704->cache_age;
      int v12837 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v12734 = v12733[v12837];
      int v12735 = v12733[v12821];
      int v12838 = v12735 + ((int)((unsigned int)(v12735 - v12734) >> 31));
      v12733[v12821] = v12838;
      int * v12737 = v12704->cache_age;
      int v12738 = v12737[v12822];
      int v12840 = v12738 + ((int)((unsigned int)(v12738 - v12734) >> 31));
      v12737[v12822] = v12840;
      int * v12740 = v12704->cache_age;
      v12740[v12837] = 0;
      v12786 = v12837;
    } else {
      int * v12743 = v12704->cache_age;
      int v12844 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2);
      int v12744 = v12743[v12844];
      int * v12745 = v12704->cache_tags;
      int v12746 = v12745[v12844];
      int v12747 = v12743[v12822];
      int v12748 = v12745[v12822];
      int * v12749 = v12704->cache_dirty;
      int v12847 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12744 + ((~(((v12746 ^ -1) | (-(v12746 ^ -1))) >> 31)) & 2)) - (v12747 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12750 = v12749[v12847];
      bool v12848 = !(v12750 == 0);
      if (v12848) {
        int * v12751 = v12704->cache_tags;
        int v12752 = v12751[v12847];
        int * v12753 = v12704->cache_vals;
        int v12851 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12744 + ((~(((v12746 ^ -1) | (-(v12746 ^ -1))) >> 31)) & 2)) - (v12747 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12754 = v12753[v12851];
        int v12852 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12744 + ((~(((v12746 ^ -1) | (-(v12746 ^ -1))) >> 31)) & 2)) - (v12747 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12755 = v12753[v12852];
        int * v12756 = v12704->mem;
        int v12854 = v12752 * 2;
        v12756[v12854] = v12754;
        int * v12758 = v12704->mem;
        int v12857 = (v12752 * 2) + 1;
        v12758[v12857] = v12755;
        ;
      } else {
        ;
      }
      int * v12763 = v12704->mem;
      int v12862 = ((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) * 2;
      int v12764 = v12763[v12862];
      int v12863 = (((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) * 2) + 1;
      int v12765 = v12763[v12863];
      int * v12766 = v12704->cache_vals;
      int v12865 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12744 + ((~(((v12746 ^ -1) | (-(v12746 ^ -1))) >> 31)) & 2)) - (v12747 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12766[v12865] = v12764;
      int * v12768 = v12704->cache_vals;
      int v12868 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12744 + ((~(((v12746 ^ -1) | (-(v12746 ^ -1))) >> 31)) & 2)) - (v12747 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12768[v12868] = v12765;
      int * v12770 = v12704->cache_tags;
      int v12871 = (int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1);
      v12770[v12847] = v12871;
      int * v12772 = v12704->cache_dirty;
      v12772[v12847] = 0;
      int * v12774 = v12704->cache_age;
      v12774[v12847] = 1;
      int * v12776 = v12704->cache_age;
      int v12777 = v12776[v12847];
      int v12778 = v12776[v12821];
      int v12877 = v12778 + ((int)((unsigned int)(v12778 - v12777) >> 31));
      v12776[v12821] = v12877;
      int * v12780 = v12704->cache_age;
      int v12781 = v12780[v12822];
      int v12879 = v12781 + ((int)((unsigned int)(v12781 - v12777) >> 31));
      v12780[v12822] = v12879;
      int * v12783 = v12704->cache_age;
      v12783[v12847] = 0;
      v12786 = v12847;
    }
    int * v12787 = v12704->cache_vals;
    int v12882 = v12786 * 2;
    int v12788 = v12787[v12882];
    int v12883 = (v12786 * 2) + 1;
    int v12789 = v12787[v12883];
    int v12884 = (((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12728 + ((~(((v12730 ^ -1) | (-(v12730 ^ -1))) >> 31)) & 2)) - (v12731 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12787[v12884] = v12788;
    int * v12791 = v12704->cache_vals;
    int v12887 = ((((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12728 + ((~(((v12730 ^ -1) | (-(v12730 ^ -1))) >> 31)) & 2)) - (v12731 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12791[v12887] = v12789;
    int * v12793 = v12704->cache_tags;
    int v12890 = ((((int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12728 + ((~(((v12730 ^ -1) | (-(v12730 ^ -1))) >> 31)) & 2)) - (v12731 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12891 = (int)((unsigned int)((int)((unsigned int)(v12708 + 12) >> 2)) >> 1);
    v12793[v12890] = v12891;
    int * v12795 = v12704->cache_dirty;
    v12795[v12890] = 0;
    int * v12797 = v12704->cache_age;
    v12797[v12890] = 1;
    int * v12799 = v12704->cache_age;
    int v12800 = v12799[v12890];
    int v12801 = v12799[v12819];
    int v12897 = v12801 + ((int)((unsigned int)(v12801 - v12800) >> 31));
    v12799[v12819] = v12897;
    int * v12803 = v12704->cache_age;
    int v12804 = v12803[v12820];
    int v12899 = v12804 + ((int)((unsigned int)(v12804 - v12800) >> 31));
    v12803[v12820] = v12899;
    int * v12806 = v12704->cache_age;
    v12806[v12890] = 0;
    v12809 = v12890;
  }
  int v12902 = (v12809 * 2) + (((int)((unsigned int)(v12708 + 12) >> 2)) & 1);
  int v12810 = v12716[v12902];
  int * v12811 = v12704->regs;
  v12811[24] = v12810;
  struct StateT * v12813 = slot_229(v12704);
  return v12813;
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

struct StateT * slot_442(struct StateT * v16333) {
  int v16334 = v16333->timer;
  int v16342 = v16334 + 1;
  v16333->timer = v16342;
  int * v16336 = v16333->regs;
  int v16337 = v16336[15];
  int v16338 = v16336[5];
  int v16347 = v16337 + v16338;
  v16336[23] = v16347;
  struct StateT * v16340 = slot_443(v16333);
  return v16340;
}

struct StateT * slot_529(struct StateT * v17716) {
  int v17717 = v17716->timer;
  int v17724 = v17717 + 1;
  v17716->timer = v17724;
  int * v17719 = v17716->regs;
  int v17720 = v17719[22];
  int v17728 = (int)((unsigned int)v17720 >> 14);
  v17719[24] = v17728;
  struct StateT * v17722 = slot_530(v17716);
  return v17722;
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

struct StateT * slot_357(struct StateT * v14893) {
  int v14894 = v14893->timer;
  int v14902 = v14894 + 1;
  v14893->timer = v14902;
  int * v14896 = v14893->regs;
  int v14897 = v14896[8];
  int v14898 = v14896[17];
  int v14907 = v14897 + v14898;
  v14896[20] = v14907;
  struct StateT * v14900 = slot_358(v14893);
  return v14900;
}

struct StateT * slot_385(struct StateT * v15359) {
  int v15360 = v15359->timer;
  int v15368 = v15360 + 1;
  v15359->timer = v15368;
  int * v15362 = v15359->regs;
  int v15363 = v15362[20];
  int v15364 = v15362[24];
  int v15372 = v15363 | v15364;
  v15362[20] = v15372;
  struct StateT * v15366 = slot_386(v15359);
  return v15366;
}

struct StateT * slot_444(struct StateT * v16365) {
  int v16366 = v16365->timer;
  int v16373 = v16366 + 1;
  v16365->timer = v16373;
  int * v16368 = v16365->regs;
  int v16369 = v16368[20];
  int v16376 = v16369 << 18;
  v16368[20] = v16376;
  struct StateT * v16371 = slot_445(v16365);
  return v16371;
}

struct StateT * slot_261(struct StateT * v13401) {
  int v13402 = v13401->timer;
  int v13409 = v13402 + 1;
  v13401->timer = v13409;
  int * v13404 = v13401->regs;
  int v13405 = v13404[20];
  int v13413 = (int)((unsigned int)v13405 >> 19);
  v13404[24] = v13413;
  struct StateT * v13407 = slot_262(v13401);
  return v13407;
}

struct StateT * slot_287(struct StateT * v13803) {
  int v13804 = v13803->timer;
  int v13811 = v13804 + 1;
  v13803->timer = v13811;
  int * v13806 = v13803->regs;
  int v13807 = v13806[22];
  int v13815 = (int)((unsigned int)v13807 >> 14);
  v13806[24] = v13815;
  struct StateT * v13809 = slot_288(v13803);
  return v13809;
}

struct StateT * slot_343(struct StateT * v14678) {
  int v14679 = v14678->timer;
  int v14687 = v14679 + 1;
  v14678->timer = v14687;
  int * v14681 = v14678->regs;
  int v14682 = v14681[20];
  int v14683 = v14681[24];
  int v14691 = v14682 | v14683;
  v14681[20] = v14691;
  struct StateT * v14685 = slot_344(v14678);
  return v14685;
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

struct StateT * slot_426(struct StateT * v16055) {
  int v16056 = v16055->timer;
  int v16063 = v16056 + 1;
  v16055->timer = v16063;
  int * v16058 = v16055->regs;
  int v16059 = v16058[21];
  int v16067 = (int)((unsigned int)v16059 >> 19);
  v16058[24] = v16067;
  struct StateT * v16061 = slot_427(v16055);
  return v16061;
}

struct StateT * slot_536(struct StateT * v17822) {
  int v17823 = v17822->timer;
  int v17831 = v17823 + 1;
  v17822->timer = v17831;
  int * v17825 = v17822->regs;
  int v17826 = v17825[29];
  int v17827 = v17825[21];
  int v17835 = v17826 ^ v17827;
  v17825[29] = v17835;
  struct StateT * v17829 = slot_537(v17822);
  return v17829;
}

struct StateT * slot_470(struct StateT * v16795) {
  int v16796 = v16795->timer;
  int v16803 = v16796 + 1;
  v16795->timer = v16803;
  int * v16798 = v16795->regs;
  int v16799 = v16798[22];
  int v16806 = v16799 << 7;
  v16798[22] = v16806;
  struct StateT * v16801 = slot_471(v16795);
  return v16801;
}

struct StateT * slot_431(struct StateT * v16129) {
  int v16130 = v16129->timer;
  int v16138 = v16130 + 1;
  v16129->timer = v16138;
  int * v16132 = v16129->regs;
  int v16133 = v16132[22];
  int v16134 = v16132[24];
  int v16142 = v16133 | v16134;
  v16132[22] = v16142;
  struct StateT * v16136 = slot_432(v16129);
  return v16136;
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

struct StateT * slot_308(struct StateT * v14130) {
  int v14131 = v14130->timer;
  int v14138 = v14131 + 1;
  v14130->timer = v14138;
  int * v14133 = v14130->regs;
  int v14134 = v14133[22];
  int v14141 = v14134 << 7;
  v14133[22] = v14141;
  struct StateT * v14136 = slot_309(v14130);
  return v14136;
}

struct StateT * slot_400(struct StateT * v15619) {
  int v15620 = v15619->timer;
  int v15628 = v15620 + 1;
  v15619->timer = v15628;
  int * v15622 = v15619->regs;
  int v15623 = v15622[18];
  int v15624 = v15622[29];
  int v15633 = v15623 + v15624;
  v15622[21] = v15633;
  struct StateT * v15626 = slot_401(v15619);
  return v15626;
}

struct StateT * slot_323(struct StateT * v14366) {
  int v14367 = v14366->timer;
  int v14375 = v14367 + 1;
  v14366->timer = v14375;
  int * v14369 = v14366->regs;
  int v14370 = v14369[20];
  int v14371 = v14369[24];
  int v14379 = v14370 | v14371;
  v14369[20] = v14379;
  struct StateT * v14373 = slot_324(v14366);
  return v14373;
}

struct StateT * slot_521(struct StateT * v17592) {
  int v17593 = v17592->timer;
  int v17601 = v17593 + 1;
  v17592->timer = v17601;
  int * v17595 = v17592->regs;
  int v17596 = v17595[18];
  int v17597 = v17595[6];
  int v17606 = v17596 + v17597;
  v17595[22] = v17606;
  struct StateT * v17599 = slot_522(v17592);
  return v17599;
}

struct StateT * slot_530(struct StateT * v17731) {
  int v17732 = v17731->timer;
  int v17739 = v17732 + 1;
  v17731->timer = v17739;
  int * v17734 = v17731->regs;
  int v17735 = v17734[22];
  int v17742 = v17735 << 18;
  v17734[22] = v17742;
  struct StateT * v17737 = slot_531(v17731);
  return v17737;
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

struct StateT * slot_538(struct StateT * v17854) {
  int v17855 = v17854->timer;
  int v17863 = v17855 + 1;
  v17854->timer = v17863;
  int * v17857 = v17854->regs;
  int v17858 = v17857[31];
  int v17859 = v17857[23];
  int v17867 = v17858 ^ v17859;
  v17857[31] = v17867;
  struct StateT * v17861 = slot_539(v17854);
  return v17861;
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

struct StateT * slot_411(struct StateT * v15789) {
  int v15790 = v15789->timer;
  int v15798 = v15790 + 1;
  v15789->timer = v15798;
  int * v15792 = v15789->regs;
  int v15793 = v15792[22];
  int v15794 = v15792[24];
  int v15802 = v15793 | v15794;
  v15792[22] = v15802;
  struct StateT * v15796 = slot_412(v15789);
  return v15796;
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

struct StateT * slot_449(struct StateT * v16440) {
  int v16441 = v16440->timer;
  int v16448 = v16441 + 1;
  v16440->timer = v16448;
  int * v16443 = v16440->regs;
  int v16444 = v16443[22];
  int v16452 = (int)((unsigned int)v16444 >> 14);
  v16443[24] = v16452;
  struct StateT * v16446 = slot_450(v16440);
  return v16446;
}

struct StateT * slot_460(struct StateT * v16639) {
  int v16640 = v16639->timer;
  int v16648 = v16640 + 1;
  v16639->timer = v16648;
  int * v16642 = v16639->regs;
  int v16643 = v16642[29];
  int v16644 = v16642[9];
  int v16653 = v16643 + v16644;
  v16642[21] = v16653;
  struct StateT * v16646 = slot_461(v16639);
  return v16646;
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

struct StateT * slot_474(struct StateT * v16854) {
  int v16855 = v16854->timer;
  int v16863 = v16855 + 1;
  v16854->timer = v16863;
  int * v16857 = v16854->regs;
  int v16858 = v16857[23];
  int v16859 = v16857[24];
  int v16867 = v16858 | v16859;
  v16857[23] = v16867;
  struct StateT * v16861 = slot_475(v16854);
  return v16861;
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

struct StateT * slot_224(struct StateT * v12469) {
  int v12470 = v12469->timer;
  int v12478 = v12470 + 1;
  v12469->timer = v12478;
  int * v12472 = v12469->regs;
  int v12473 = v12472[22];
  int v12474 = v12472[24];
  int v12482 = v12473 | v12474;
  v12472[22] = v12482;
  struct StateT * v12476 = slot_226(v12469);
  return v12476;
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

struct StateT * slot_462(struct StateT * v16673) {
  int v16674 = v16673->timer;
  int v16682 = v16674 + 1;
  v16673->timer = v16682;
  int * v16676 = v16673->regs;
  int v16677 = v16676[31];
  int v16678 = v16676[19];
  int v16687 = v16677 + v16678;
  v16676[23] = v16687;
  struct StateT * v16680 = slot_463(v16673);
  return v16680;
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_393(struct StateT * v15480) {
  int v15481 = v15480->timer;
  int v15488 = v15481 + 1;
  v15480->timer = v15488;
  int * v15483 = v15480->regs;
  int v15484 = v15483[23];
  int v15491 = v15484 << 7;
  v15483[23] = v15491;
  struct StateT * v15486 = slot_394(v15480);
  return v15486;
}

struct StateT * slot_507(struct StateT * v17374) {
  int v17375 = v17374->timer;
  int v17382 = v17375 + 1;
  v17374->timer = v17382;
  int * v17377 = v17374->regs;
  int v17378 = v17377[21];
  int v17385 = v17378 << 13;
  v17377[21] = v17385;
  struct StateT * v17380 = slot_508(v17374);
  return v17380;
}

struct StateT * slot_477(struct StateT * v16902) {
  int v16903 = v16902->timer;
  int v16911 = v16903 + 1;
  v16902->timer = v16911;
  int * v16905 = v16902->regs;
  int v16906 = v16905[15];
  int v16907 = v16905[22];
  int v16915 = v16906 ^ v16907;
  v16905[15] = v16915;
  struct StateT * v16909 = slot_478(v16902);
  return v16909;
}

struct StateT * slot_278(struct StateT * v13662) {
  int v13663 = v13662->timer;
  int v13671 = v13663 + 1;
  v13662->timer = v13671;
  int * v13665 = v13662->regs;
  int v13666 = v13665[14];
  int v13667 = v13665[7];
  int v13676 = v13666 + v13667;
  v13665[21] = v13676;
  struct StateT * v13669 = slot_279(v13662);
  return v13669;
}

struct StateT * slot_352(struct StateT * v14813) {
  int v14814 = v14813->timer;
  int v14822 = v14814 + 1;
  v14813->timer = v14822;
  int * v14816 = v14813->regs;
  int v14817 = v14816[23];
  int v14818 = v14816[24];
  int v14826 = v14817 | v14818;
  v14816[23] = v14826;
  struct StateT * v14820 = slot_353(v14813);
  return v14820;
}

struct StateT * slot_249(struct StateT * v13208) {
  int v13209 = v13208->timer;
  int v13217 = v13209 + 1;
  v13208->timer = v13217;
  int * v13211 = v13208->regs;
  int v13212 = v13211[22];
  int v13213 = v13211[24];
  int v13221 = v13212 | v13213;
  v13211[22] = v13221;
  struct StateT * v13215 = slot_250(v13208);
  return v13215;
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

struct StateT * slot_228(struct StateT * v12908) {
  int v12909 = v12908->timer;
  int v12916 = v12909 + 1;
  v12908->timer = v12916;
  int * v12911 = v12908->regs;
  int v12912 = v12911[23];
  int v12919 = v12912 << 7;
  v12911[23] = v12919;
  struct StateT * v12914 = slot_230(v12908);
  return v12914;
}

struct StateT * slot_268(struct StateT * v13506) {
  int v13507 = v13506->timer;
  int v13514 = v13507 + 1;
  v13506->timer = v13514;
  int * v13509 = v13506->regs;
  int v13510 = v13509[22];
  int v13517 = v13510 << 13;
  v13509[22] = v13517;
  struct StateT * v13512 = slot_269(v13506);
  return v13512;
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
  struct StateT * v9133 = slot_201(v8964);
  return v9133;
}

struct StateT * slot_252(struct StateT * v13253) {
  int v13254 = v13253->timer;
  int v13262 = v13254 + 1;
  v13253->timer = v13262;
  int * v13256 = v13253->regs;
  int v13257 = v13256[23];
  int v13258 = v13256[24];
  int v13266 = v13257 | v13258;
  v13256[23] = v13266;
  struct StateT * v13260 = slot_253(v13253);
  return v13260;
}

struct StateT * slot_409(struct StateT * v15760) {
  int v15761 = v15760->timer;
  int v15768 = v15761 + 1;
  v15760->timer = v15768;
  int * v15763 = v15760->regs;
  int v15764 = v15763[22];
  int v15772 = (int)((unsigned int)v15764 >> 23);
  v15763[24] = v15772;
  struct StateT * v15766 = slot_410(v15760);
  return v15766;
}

struct StateT * slot_374(struct StateT * v15157) {
  int v15158 = v15157->timer;
  int v15166 = v15158 + 1;
  v15157->timer = v15166;
  int * v15160 = v15157->regs;
  int v15161 = v15160[29];
  int v15162 = v15160[21];
  int v15170 = v15161 ^ v15162;
  v15160[29] = v15170;
  struct StateT * v15164 = slot_375(v15157);
  return v15164;
}

struct StateT * slot_269(struct StateT * v13520) {
  int v13521 = v13520->timer;
  int v13529 = v13521 + 1;
  v13520->timer = v13529;
  int * v13523 = v13520->regs;
  int v13524 = v13523[22];
  int v13525 = v13523[24];
  int v13533 = v13524 | v13525;
  v13523[22] = v13533;
  struct StateT * v13527 = slot_270(v13520);
  return v13527;
}

struct StateT * slot_501(struct StateT * v17280) {
  int v17281 = v17280->timer;
  int v17289 = v17281 + 1;
  v17280->timer = v17289;
  int * v17283 = v17280->regs;
  int v17284 = v17283[6];
  int v17285 = v17283[15];
  int v17294 = v17284 + v17285;
  v17283[22] = v17294;
  struct StateT * v17287 = slot_502(v17280);
  return v17287;
}

struct StateT * slot_251(struct StateT * v13239) {
  int v13240 = v13239->timer;
  int v13247 = v13240 + 1;
  v13239->timer = v13247;
  int * v13242 = v13239->regs;
  int v13243 = v13242[23];
  int v13250 = v13243 << 9;
  v13242[23] = v13250;
  struct StateT * v13245 = slot_252(v13239);
  return v13245;
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

struct StateT * slot_322(struct StateT * v14352) {
  int v14353 = v14352->timer;
  int v14360 = v14353 + 1;
  v14352->timer = v14360;
  int * v14355 = v14352->regs;
  int v14356 = v14355[20];
  int v14363 = v14356 << 9;
  v14355[20] = v14363;
  struct StateT * v14358 = slot_323(v14352);
  return v14358;
}

struct StateT * slot_277(struct StateT * v13645) {
  int v13646 = v13645->timer;
  int v13654 = v13646 + 1;
  v13645->timer = v13654;
  int * v13648 = v13645->regs;
  int v13649 = v13648[16];
  int v13650 = v13648[6];
  int v13659 = v13649 + v13650;
  v13648[20] = v13659;
  struct StateT * v13652 = slot_278(v13645);
  return v13652;
}

struct StateT * slot_353(struct StateT * v14829) {
  int v14830 = v14829->timer;
  int v14838 = v14830 + 1;
  v14829->timer = v14838;
  int * v14832 = v14829->regs;
  int v14833 = v14832[8];
  int v14834 = v14832[20];
  int v14842 = v14833 ^ v14834;
  v14832[8] = v14842;
  struct StateT * v14836 = slot_354(v14829);
  return v14836;
}

struct StateT * slot_397(struct StateT * v15556) {
  int * v15557 = v15556->saved_regs;
  int * v15558 = v15556->regs;
  int v15559 = v15558[19];
  v15557[19] = v15559;
  int v15561 = v15556->timer;
  int v15573 = v15561 + 1;
  v15556->timer = v15573;
  int * v15563 = v15556->regs;
  int v15564 = v15563[19];
  int v15565 = v15563[22];
  int v15576 = v15564 ^ v15565;
  v15563[19] = v15576;
  struct StateT * v15567 = slot_398(v15556);
  return v15567;
}

struct StateT * slot_435(struct StateT * v16190) {
  int * v16191 = v16190->saved_regs;
  int * v16192 = v16190->regs;
  int v16193 = v16192[16];
  v16191[16] = v16193;
  int v16195 = v16190->timer;
  int v16207 = v16195 + 1;
  v16190->timer = v16207;
  int * v16197 = v16190->regs;
  int v16198 = v16197[16];
  int v16199 = v16197[20];
  int v16210 = v16198 ^ v16199;
  v16197[16] = v16210;
  struct StateT * v16201 = slot_436(v16190);
  return v16201;
}

struct StateT * slot_476(struct StateT * v16886) {
  int v16887 = v16886->timer;
  int v16895 = v16887 + 1;
  v16886->timer = v16895;
  int * v16889 = v16886->regs;
  int v16890 = v16889[12];
  int v16891 = v16889[21];
  int v16899 = v16890 ^ v16891;
  v16889[12] = v16899;
  struct StateT * v16893 = slot_477(v16886);
  return v16893;
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

struct StateT * slot_379(struct StateT * v15227) {
  int * v15228 = v15227->saved_regs;
  int * v15229 = v15227->regs;
  int v15230 = v15229[20];
  v15228[20] = v15230;
  int v15232 = v15227->timer;
  int v15244 = v15232 + 1;
  v15227->timer = v15244;
  int * v15234 = v15227->regs;
  int v15235 = v15234[30];
  int v15236 = v15234[16];
  int v15248 = v15235 + v15236;
  v15234[20] = v15248;
  struct StateT * v15238 = slot_380(v15227);
  return v15238;
}

struct StateT * slot_475(struct StateT * v16870) {
  int v16871 = v16870->timer;
  int v16879 = v16871 + 1;
  v16870->timer = v16879;
  int * v16873 = v16870->regs;
  int v16874 = v16873[14];
  int v16875 = v16873[20];
  int v16883 = v16874 ^ v16875;
  v16873[14] = v16883;
  struct StateT * v16877 = slot_476(v16870);
  return v16877;
}

struct StateT * slot_310(struct StateT * v14160) {
  int v14161 = v14160->timer;
  int v14168 = v14161 + 1;
  v14160->timer = v14168;
  int * v14163 = v14160->regs;
  int v14164 = v14163[23];
  int v14172 = (int)((unsigned int)v14164 >> 25);
  v14163[24] = v14172;
  struct StateT * v14166 = slot_311(v14160);
  return v14166;
}

struct StateT * slot_445(struct StateT * v16379) {
  int v16380 = v16379->timer;
  int v16388 = v16380 + 1;
  v16379->timer = v16388;
  int * v16382 = v16379->regs;
  int v16383 = v16382[20];
  int v16384 = v16382[24];
  int v16392 = v16383 | v16384;
  v16382[20] = v16392;
  struct StateT * v16386 = slot_446(v16379);
  return v16386;
}

struct StateT * slot_295(struct StateT * v13925) {
  int v13926 = v13925->timer;
  int v13934 = v13926 + 1;
  v13925->timer = v13934;
  int * v13928 = v13925->regs;
  int v13929 = v13928[28];
  int v13930 = v13928[22];
  int v13938 = v13929 ^ v13930;
  v13928[28] = v13938;
  struct StateT * v13932 = slot_296(v13925);
  return v13932;
}

struct StateT * slot_315(struct StateT * v14237) {
  int v14238 = v14237->timer;
  int v14246 = v14238 + 1;
  v14237->timer = v14246;
  int * v14240 = v14237->regs;
  int v14241 = v14240[15];
  int v14242 = v14240[22];
  int v14250 = v14241 ^ v14242;
  v14240[15] = v14250;
  struct StateT * v14244 = slot_316(v14237);
  return v14244;
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

struct StateT * slot_457(struct StateT * v16576) {
  int * v16577 = v16576->saved_regs;
  int * v16578 = v16576->regs;
  int v16579 = v16578[28];
  v16577[28] = v16579;
  int v16581 = v16576->timer;
  int v16593 = v16581 + 1;
  v16576->timer = v16593;
  int * v16583 = v16576->regs;
  int v16584 = v16583[28];
  int v16585 = v16583[22];
  int v16596 = v16584 ^ v16585;
  v16583[28] = v16596;
  struct StateT * v16587 = slot_458(v16576);
  return v16587;
}

struct StateT * slot_207(struct StateT * v10292) {
  int v10293 = v10292->timer;
  int v10463 = v10293 + 1;
  v10292->timer = v10463;
  int * v10295 = v10292->regs;
  int v10296 = v10295[10];
  int v10297 = v10295[6];
  int * v10298 = v10292->cache_tags;
  int v10468 = (((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2;
  int v10299 = v10298[v10468];
  int v10469 = ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10300 = v10298[v10469];
  int v10470 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2);
  int v10301 = v10298[v10470];
  int v10471 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10302 = v10298[v10471];
  int v10303 = v10292->timer;
  int v10472 = v10303 + ((100 ^ (((~(((v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10299 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10299 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10292->timer = v10472;
  bool v10473 = !(((~(((v10299 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10299 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v10397;
  if (v10473) {
    int * v10305 = v10292->cache_age;
    int v10475 = ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10300 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v10306 = v10305[v10475];
    int v10307 = v10305[v10468];
    int v10476 = v10307 + ((int)((unsigned int)(v10307 - v10306) >> 31));
    v10305[v10468] = v10476;
    int * v10309 = v10292->cache_age;
    int v10310 = v10309[v10469];
    int v10478 = v10310 + ((int)((unsigned int)(v10310 - v10306) >> 31));
    v10309[v10469] = v10478;
    int * v10312 = v10292->cache_age;
    v10312[v10475] = 0;
    v10397 = v10475;
  } else {
    int * v10315 = v10292->cache_age;
    int v10482 = (((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2;
    int v10316 = v10315[v10482];
    int * v10317 = v10292->cache_tags;
    int v10318 = v10317[v10482];
    int v10319 = v10315[v10469];
    int v10320 = v10317[v10469];
    bool v10484 = !(((~(((v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10301 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v10374;
    if (v10484) {
      int * v10321 = v10292->cache_age;
      int v10486 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10302 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v10322 = v10321[v10486];
      int v10323 = v10321[v10470];
      int v10487 = v10323 + ((int)((unsigned int)(v10323 - v10322) >> 31));
      v10321[v10470] = v10487;
      int * v10325 = v10292->cache_age;
      int v10326 = v10325[v10471];
      int v10489 = v10326 + ((int)((unsigned int)(v10326 - v10322) >> 31));
      v10325[v10471] = v10489;
      int * v10328 = v10292->cache_age;
      v10328[v10486] = 0;
      v10374 = v10486;
    } else {
      int * v10331 = v10292->cache_age;
      int v10493 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2);
      int v10332 = v10331[v10493];
      int * v10333 = v10292->cache_tags;
      int v10334 = v10333[v10493];
      int v10335 = v10331[v10471];
      int v10336 = v10333[v10471];
      int * v10337 = v10292->cache_dirty;
      int v10496 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10332 + ((~(((v10334 ^ -1) | (-(v10334 ^ -1))) >> 31)) & 2)) - (v10335 + ((~(((v10336 ^ -1) | (-(v10336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10338 = v10337[v10496];
      bool v10497 = !(v10338 == 0);
      if (v10497) {
        int * v10339 = v10292->cache_tags;
        int v10340 = v10339[v10496];
        int * v10341 = v10292->cache_vals;
        int v10500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10332 + ((~(((v10334 ^ -1) | (-(v10334 ^ -1))) >> 31)) & 2)) - (v10335 + ((~(((v10336 ^ -1) | (-(v10336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10342 = v10341[v10500];
        int v10501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10332 + ((~(((v10334 ^ -1) | (-(v10334 ^ -1))) >> 31)) & 2)) - (v10335 + ((~(((v10336 ^ -1) | (-(v10336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10343 = v10341[v10501];
        int * v10344 = v10292->mem;
        int v10503 = v10340 * 2;
        v10344[v10503] = v10342;
        int * v10346 = v10292->mem;
        int v10506 = (v10340 * 2) + 1;
        v10346[v10506] = v10343;
        ;
      } else {
        ;
      }
      int * v10351 = v10292->mem;
      int v10511 = ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) * 2;
      int v10352 = v10351[v10511];
      int v10512 = (((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) * 2) + 1;
      int v10353 = v10351[v10512];
      int * v10354 = v10292->cache_vals;
      int v10514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10332 + ((~(((v10334 ^ -1) | (-(v10334 ^ -1))) >> 31)) & 2)) - (v10335 + ((~(((v10336 ^ -1) | (-(v10336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10354[v10514] = v10352;
      int * v10356 = v10292->cache_vals;
      int v10517 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10332 + ((~(((v10334 ^ -1) | (-(v10334 ^ -1))) >> 31)) & 2)) - (v10335 + ((~(((v10336 ^ -1) | (-(v10336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10356[v10517] = v10353;
      int * v10358 = v10292->cache_tags;
      int v10520 = (int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1);
      v10358[v10496] = v10520;
      int * v10360 = v10292->cache_dirty;
      v10360[v10496] = 0;
      int * v10362 = v10292->cache_age;
      v10362[v10496] = 1;
      int * v10364 = v10292->cache_age;
      int v10365 = v10364[v10496];
      int v10366 = v10364[v10470];
      int v10526 = v10366 + ((int)((unsigned int)(v10366 - v10365) >> 31));
      v10364[v10470] = v10526;
      int * v10368 = v10292->cache_age;
      int v10369 = v10368[v10471];
      int v10528 = v10369 + ((int)((unsigned int)(v10369 - v10365) >> 31));
      v10368[v10471] = v10528;
      int * v10371 = v10292->cache_age;
      v10371[v10496] = 0;
      v10374 = v10496;
    }
    int * v10375 = v10292->cache_vals;
    int v10531 = v10374 * 2;
    int v10376 = v10375[v10531];
    int v10532 = (v10374 * 2) + 1;
    int v10377 = v10375[v10532];
    int v10533 = (((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10316 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2)) - (v10319 + ((~(((v10320 ^ -1) | (-(v10320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10375[v10533] = v10376;
    int * v10379 = v10292->cache_vals;
    int v10536 = ((((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10316 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2)) - (v10319 + ((~(((v10320 ^ -1) | (-(v10320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10379[v10536] = v10377;
    int * v10381 = v10292->cache_tags;
    int v10539 = ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10316 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2)) - (v10319 + ((~(((v10320 ^ -1) | (-(v10320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10540 = (int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1);
    v10381[v10539] = v10540;
    int * v10383 = v10292->cache_dirty;
    v10383[v10539] = 0;
    int * v10385 = v10292->cache_age;
    v10385[v10539] = 1;
    int * v10387 = v10292->cache_age;
    int v10388 = v10387[v10539];
    int v10389 = v10387[v10468];
    int v10546 = v10389 + ((int)((unsigned int)(v10389 - v10388) >> 31));
    v10387[v10468] = v10546;
    int * v10391 = v10292->cache_age;
    int v10392 = v10391[v10469];
    int v10548 = v10392 + ((int)((unsigned int)(v10392 - v10388) >> 31));
    v10391[v10469] = v10548;
    int * v10394 = v10292->cache_age;
    v10394[v10539] = 0;
    v10397 = v10539;
  }
  int * v10398 = v10292->cache_vals;
  int v10551 = (v10397 * 2) + (((int)((unsigned int)(v10296 + 24) >> 2)) & 1);
  v10398[v10551] = v10297;
  int * v10400 = v10292->cache_tags;
  int v10401 = v10400[v10470];
  int v10402 = v10400[v10471];
  bool v10554 = !(((~(((v10401 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10401 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10402 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10402 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v10456;
  if (v10554) {
    int * v10403 = v10292->cache_age;
    int v10556 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10402 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))) | (-(v10402 ^ ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v10404 = v10403[v10556];
    int v10405 = v10403[v10470];
    int v10557 = v10405 + ((int)((unsigned int)(v10405 - v10404) >> 31));
    v10403[v10470] = v10557;
    int * v10407 = v10292->cache_age;
    int v10408 = v10407[v10471];
    int v10559 = v10408 + ((int)((unsigned int)(v10408 - v10404) >> 31));
    v10407[v10471] = v10559;
    int * v10410 = v10292->cache_age;
    v10410[v10556] = 0;
    v10456 = v10556;
  } else {
    int * v10413 = v10292->cache_age;
    int v10563 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2);
    int v10414 = v10413[v10563];
    int * v10415 = v10292->cache_tags;
    int v10416 = v10415[v10563];
    int v10417 = v10413[v10471];
    int v10418 = v10415[v10471];
    int * v10419 = v10292->cache_dirty;
    int v10566 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10414 + ((~(((v10416 ^ -1) | (-(v10416 ^ -1))) >> 31)) & 2)) - (v10417 + ((~(((v10418 ^ -1) | (-(v10418 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10420 = v10419[v10566];
    bool v10567 = !(v10420 == 0);
    if (v10567) {
      int * v10421 = v10292->cache_tags;
      int v10422 = v10421[v10566];
      int * v10423 = v10292->cache_vals;
      int v10570 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10414 + ((~(((v10416 ^ -1) | (-(v10416 ^ -1))) >> 31)) & 2)) - (v10417 + ((~(((v10418 ^ -1) | (-(v10418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10424 = v10423[v10570];
      int v10571 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10414 + ((~(((v10416 ^ -1) | (-(v10416 ^ -1))) >> 31)) & 2)) - (v10417 + ((~(((v10418 ^ -1) | (-(v10418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10425 = v10423[v10571];
      int * v10426 = v10292->mem;
      int v10573 = v10422 * 2;
      v10426[v10573] = v10424;
      int * v10428 = v10292->mem;
      int v10576 = (v10422 * 2) + 1;
      v10428[v10576] = v10425;
      ;
    } else {
      ;
    }
    int * v10433 = v10292->mem;
    int v10581 = ((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) * 2;
    int v10434 = v10433[v10581];
    int v10582 = (((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) * 2) + 1;
    int v10435 = v10433[v10582];
    int * v10436 = v10292->cache_vals;
    int v10584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10414 + ((~(((v10416 ^ -1) | (-(v10416 ^ -1))) >> 31)) & 2)) - (v10417 + ((~(((v10418 ^ -1) | (-(v10418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10436[v10584] = v10434;
    int * v10438 = v10292->cache_vals;
    int v10587 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10414 + ((~(((v10416 ^ -1) | (-(v10416 ^ -1))) >> 31)) & 2)) - (v10417 + ((~(((v10418 ^ -1) | (-(v10418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10438[v10587] = v10435;
    int * v10440 = v10292->cache_tags;
    int v10590 = (int)((unsigned int)((int)((unsigned int)(v10296 + 24) >> 2)) >> 1);
    v10440[v10566] = v10590;
    int * v10442 = v10292->cache_dirty;
    v10442[v10566] = 0;
    int * v10444 = v10292->cache_age;
    v10444[v10566] = 1;
    int * v10446 = v10292->cache_age;
    int v10447 = v10446[v10566];
    int v10448 = v10446[v10470];
    int v10596 = v10448 + ((int)((unsigned int)(v10448 - v10447) >> 31));
    v10446[v10470] = v10596;
    int * v10450 = v10292->cache_age;
    int v10451 = v10450[v10471];
    int v10598 = v10451 + ((int)((unsigned int)(v10451 - v10447) >> 31));
    v10450[v10471] = v10598;
    int * v10453 = v10292->cache_age;
    v10453[v10566] = 0;
    v10456 = v10566;
  }
  int * v10457 = v10292->cache_vals;
  int v10601 = (v10456 * 2) + (((int)((unsigned int)(v10296 + 24) >> 2)) & 1);
  v10457[v10601] = v10297;
  int * v10459 = v10292->cache_dirty;
  v10459[v10456] = 1;
  struct StateT * v10461 = slot_209(v10292);
  return v10461;
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

struct StateT * slot_493(struct StateT * v17152) {
  int v17153 = v17152->timer;
  int v17160 = v17153 + 1;
  v17152->timer = v17160;
  int * v17155 = v17152->regs;
  int v17156 = v17155[23];
  int v17163 = v17156 << 9;
  v17155[23] = v17163;
  struct StateT * v17158 = slot_494(v17152);
  return v17158;
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

struct StateT * slot_430(struct StateT * v16115) {
  int v16116 = v16115->timer;
  int v16123 = v16116 + 1;
  v16115->timer = v16123;
  int * v16118 = v16115->regs;
  int v16119 = v16118[22];
  int v16126 = v16119 << 13;
  v16118[22] = v16126;
  struct StateT * v16121 = slot_431(v16115);
  return v16121;
}

struct StateT * slot_369(struct StateT * v15080) {
  int v15081 = v15080->timer;
  int v15089 = v15081 + 1;
  v15080->timer = v15089;
  int * v15083 = v15080->regs;
  int v15084 = v15083[22];
  int v15085 = v15083[24];
  int v15093 = v15084 | v15085;
  v15083[22] = v15093;
  struct StateT * v15087 = slot_370(v15080);
  return v15087;
}

struct StateT * slot_461(struct StateT * v16656) {
  int v16657 = v16656->timer;
  int v16665 = v16657 + 1;
  v16656->timer = v16665;
  int * v16659 = v16656->regs;
  int v16660 = v16659[28];
  int v16661 = v16659[18];
  int v16670 = v16660 + v16661;
  v16659[22] = v16670;
  struct StateT * v16663 = slot_462(v16656);
  return v16663;
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

struct StateT * slot_480(struct StateT * v16951) {
  int v16952 = v16951->timer;
  int v16960 = v16952 + 1;
  v16951->timer = v16960;
  int * v16954 = v16951->regs;
  int v16955 = v16954[12];
  int v16956 = v16954[29];
  int v16965 = v16955 + v16956;
  v16954[21] = v16965;
  struct StateT * v16958 = slot_481(v16951);
  return v16958;
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

struct StateT * slot_244(struct StateT * v13134) {
  int v13135 = v13134->timer;
  int v13142 = v13135 + 1;
  v13134->timer = v13142;
  int * v13137 = v13134->regs;
  int v13138 = v13137[21];
  int v13146 = (int)((unsigned int)v13138 >> 23);
  v13137[24] = v13146;
  struct StateT * v13140 = slot_245(v13134);
  return v13140;
}

struct StateT * slot_222(struct StateT * v12251) {
  int v12252 = v12251->timer;
  int v12259 = v12252 + 1;
  v12251->timer = v12259;
  int * v12254 = v12251->regs;
  int v12255 = v12254[22];
  int v12262 = v12255 << 7;
  v12254[22] = v12262;
  struct StateT * v12257 = slot_224(v12251);
  return v12257;
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

struct StateT * slot_377(struct StateT * v15205) {
  int v15206 = v15205->timer;
  int v15213 = v15206 + 1;
  v15205->timer = v15213;
  int * v15208 = v15205->regs;
  int v15209 = v15208[13];
  int v15216 = v15209 + 1;
  v15208[13] = v15216;
  struct StateT * v15211 = slot_378(v15205);
  return v15211;
}

struct StateT * slot_427(struct StateT * v16070) {
  int v16071 = v16070->timer;
  int v16078 = v16071 + 1;
  v16070->timer = v16078;
  int * v16073 = v16070->regs;
  int v16074 = v16073[21];
  int v16081 = v16074 << 13;
  v16073[21] = v16081;
  struct StateT * v16076 = slot_428(v16070);
  return v16076;
}

struct StateT * slot_399(struct StateT * v15602) {
  int v15603 = v15602->timer;
  int v15611 = v15603 + 1;
  v15602->timer = v15611;
  int * v15605 = v15602->regs;
  int v15606 = v15605[9];
  int v15607 = v15605[30];
  int v15616 = v15606 + v15607;
  v15605[20] = v15616;
  struct StateT * v15609 = slot_400(v15602);
  return v15609;
}

struct StateT * slot_239(struct StateT * v13055) {
  int v13056 = v13055->timer;
  int v13064 = v13056 + 1;
  v13055->timer = v13064;
  int * v13058 = v13055->regs;
  int v13059 = v13058[19];
  int v13060 = v13058[28];
  int v13069 = v13059 + v13060;
  v13058[22] = v13069;
  struct StateT * v13062 = slot_240(v13055);
  return v13062;
}

struct StateT * slot_464(struct StateT * v16705) {
  int v16706 = v16705->timer;
  int v16713 = v16706 + 1;
  v16705->timer = v16713;
  int * v16708 = v16705->regs;
  int v16709 = v16708[20];
  int v16716 = v16709 << 7;
  v16708[20] = v16716;
  struct StateT * v16711 = slot_465(v16705);
  return v16711;
}

struct StateT * slot_500(struct StateT * v17263) {
  int v17264 = v17263->timer;
  int v17272 = v17264 + 1;
  v17263->timer = v17272;
  int * v17266 = v17263->regs;
  int v17267 = v17266[5];
  int v17268 = v17266[12];
  int v17277 = v17267 + v17268;
  v17266[21] = v17277;
  struct StateT * v17270 = slot_501(v17263);
  return v17270;
}

struct StateT * slot_433(struct StateT * v16160) {
  int v16161 = v16160->timer;
  int v16168 = v16161 + 1;
  v16160->timer = v16168;
  int * v16163 = v16160->regs;
  int v16164 = v16163[23];
  int v16171 = v16164 << 13;
  v16163[23] = v16171;
  struct StateT * v16166 = slot_434(v16160);
  return v16166;
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

struct StateT * slot_267(struct StateT * v13491) {
  int v13492 = v13491->timer;
  int v13499 = v13492 + 1;
  v13491->timer = v13499;
  int * v13494 = v13491->regs;
  int v13495 = v13494[22];
  int v13503 = (int)((unsigned int)v13495 >> 19);
  v13494[24] = v13503;
  struct StateT * v13497 = slot_268(v13491);
  return v13497;
}

struct StateT * slot_492(struct StateT * v17137) {
  int v17138 = v17137->timer;
  int v17145 = v17138 + 1;
  v17137->timer = v17145;
  int * v17140 = v17137->regs;
  int v17141 = v17140[23];
  int v17149 = (int)((unsigned int)v17141 >> 23);
  v17140[24] = v17149;
  struct StateT * v17143 = slot_493(v17137);
  return v17143;
}

struct StateT * slot_201(struct StateT * v9296) {
  int v9297 = v9296->timer;
  int v9467 = v9297 + 1;
  v9296->timer = v9467;
  int * v9299 = v9296->regs;
  int v9300 = v9299[10];
  int v9301 = v9299[31];
  int * v9302 = v9296->cache_tags;
  int v9472 = (((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2;
  int v9303 = v9302[v9472];
  int v9473 = ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9304 = v9302[v9473];
  int v9474 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2);
  int v9305 = v9302[v9474];
  int v9475 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9306 = v9302[v9475];
  int v9307 = v9296->timer;
  int v9476 = v9307 + ((100 ^ (((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9296->timer = v9476;
  bool v9477 = !(((~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v9401;
  if (v9477) {
    int * v9309 = v9296->cache_age;
    int v9479 = ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v9486 = (((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2;
    int v9320 = v9319[v9486];
    int * v9321 = v9296->cache_tags;
    int v9322 = v9321[v9486];
    int v9323 = v9319[v9473];
    int v9324 = v9321[v9473];
    bool v9488 = !(((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v9378;
    if (v9488) {
      int * v9325 = v9296->cache_age;
      int v9490 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v9497 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2);
      int v9336 = v9335[v9497];
      int * v9337 = v9296->cache_tags;
      int v9338 = v9337[v9497];
      int v9339 = v9335[v9475];
      int v9340 = v9337[v9475];
      int * v9341 = v9296->cache_dirty;
      int v9500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9342 = v9341[v9500];
      bool v9501 = !(v9342 == 0);
      if (v9501) {
        int * v9343 = v9296->cache_tags;
        int v9344 = v9343[v9500];
        int * v9345 = v9296->cache_vals;
        int v9504 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9346 = v9345[v9504];
        int v9505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v9515 = ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) * 2;
      int v9356 = v9355[v9515];
      int v9516 = (((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) * 2) + 1;
      int v9357 = v9355[v9516];
      int * v9358 = v9296->cache_vals;
      int v9518 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9358[v9518] = v9356;
      int * v9360 = v9296->cache_vals;
      int v9521 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9360[v9521] = v9357;
      int * v9362 = v9296->cache_tags;
      int v9524 = (int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1);
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
    int v9537 = (((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9379[v9537] = v9380;
    int * v9383 = v9296->cache_vals;
    int v9540 = ((((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9383[v9540] = v9381;
    int * v9385 = v9296->cache_tags;
    int v9543 = ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9544 = (int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1);
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
  int v9555 = (v9401 * 2) + (((int)((unsigned int)(v9300 + 12) >> 2)) & 1);
  v9402[v9555] = v9301;
  int * v9404 = v9296->cache_tags;
  int v9405 = v9404[v9474];
  int v9406 = v9404[v9475];
  bool v9558 = !(((~(((v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9406 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9406 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v9460;
  if (v9558) {
    int * v9407 = v9296->cache_age;
    int v9560 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9406 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))) | (-(v9406 ^ ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v9567 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2);
    int v9418 = v9417[v9567];
    int * v9419 = v9296->cache_tags;
    int v9420 = v9419[v9567];
    int v9421 = v9417[v9475];
    int v9422 = v9419[v9475];
    int * v9423 = v9296->cache_dirty;
    int v9570 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9424 = v9423[v9570];
    bool v9571 = !(v9424 == 0);
    if (v9571) {
      int * v9425 = v9296->cache_tags;
      int v9426 = v9425[v9570];
      int * v9427 = v9296->cache_vals;
      int v9574 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9428 = v9427[v9574];
      int v9575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v9585 = ((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) * 2;
    int v9438 = v9437[v9585];
    int v9586 = (((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) * 2) + 1;
    int v9439 = v9437[v9586];
    int * v9440 = v9296->cache_vals;
    int v9588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9440[v9588] = v9438;
    int * v9442 = v9296->cache_vals;
    int v9591 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9442[v9591] = v9439;
    int * v9444 = v9296->cache_tags;
    int v9594 = (int)((unsigned int)((int)((unsigned int)(v9300 + 12) >> 2)) >> 1);
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
  int v9605 = (v9460 * 2) + (((int)((unsigned int)(v9300 + 12) >> 2)) & 1);
  v9461[v9605] = v9301;
  int * v9463 = v9296->cache_dirty;
  v9463[v9460] = 1;
  struct StateT * v9465 = slot_203(v9296);
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

struct StateT * slot_195(struct StateT * v8304) {
  int v8305 = v8304->timer;
  int v8475 = v8305 + 1;
  v8304->timer = v8475;
  int * v8307 = v8304->regs;
  int v8308 = v8307[10];
  int v8309 = v8307[30];
  int * v8310 = v8304->cache_tags;
  int v8480 = (((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2;
  int v8311 = v8310[v8480];
  int v8481 = ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2) + 1;
  int v8312 = v8310[v8481];
  int v8482 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2);
  int v8313 = v8310[v8482];
  int v8483 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8314 = v8310[v8483];
  int v8315 = v8304->timer;
  int v8484 = v8315 + ((100 ^ (((~(((v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8311 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8311 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) & 104)))));
  v8304->timer = v8484;
  bool v8485 = !(((~(((v8311 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8311 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) == 0);
  int v8409;
  if (v8485) {
    int * v8317 = v8304->cache_age;
    int v8487 = ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2) + ((~(((v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8312 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) & 1);
    int v8318 = v8317[v8487];
    int v8319 = v8317[v8480];
    int v8488 = v8319 + ((int)((unsigned int)(v8319 - v8318) >> 31));
    v8317[v8480] = v8488;
    int * v8321 = v8304->cache_age;
    int v8322 = v8321[v8481];
    int v8490 = v8322 + ((int)((unsigned int)(v8322 - v8318) >> 31));
    v8321[v8481] = v8490;
    int * v8324 = v8304->cache_age;
    v8324[v8487] = 0;
    v8409 = v8487;
  } else {
    int * v8327 = v8304->cache_age;
    int v8494 = (((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2;
    int v8328 = v8327[v8494];
    int * v8329 = v8304->cache_tags;
    int v8330 = v8329[v8494];
    int v8331 = v8327[v8481];
    int v8332 = v8329[v8481];
    bool v8496 = !(((~(((v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8313 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) == 0);
    int v8386;
    if (v8496) {
      int * v8333 = v8304->cache_age;
      int v8498 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((~(((v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8314 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) & 1);
      int v8334 = v8333[v8498];
      int v8335 = v8333[v8482];
      int v8499 = v8335 + ((int)((unsigned int)(v8335 - v8334) >> 31));
      v8333[v8482] = v8499;
      int * v8337 = v8304->cache_age;
      int v8338 = v8337[v8483];
      int v8501 = v8338 + ((int)((unsigned int)(v8338 - v8334) >> 31));
      v8337[v8483] = v8501;
      int * v8340 = v8304->cache_age;
      v8340[v8498] = 0;
      v8386 = v8498;
    } else {
      int * v8343 = v8304->cache_age;
      int v8505 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2);
      int v8344 = v8343[v8505];
      int * v8345 = v8304->cache_tags;
      int v8346 = v8345[v8505];
      int v8347 = v8343[v8483];
      int v8348 = v8345[v8483];
      int * v8349 = v8304->cache_dirty;
      int v8508 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8344 + ((~(((v8346 ^ -1) | (-(v8346 ^ -1))) >> 31)) & 2)) - (v8347 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8350 = v8349[v8508];
      bool v8509 = !(v8350 == 0);
      if (v8509) {
        int * v8351 = v8304->cache_tags;
        int v8352 = v8351[v8508];
        int * v8353 = v8304->cache_vals;
        int v8512 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8344 + ((~(((v8346 ^ -1) | (-(v8346 ^ -1))) >> 31)) & 2)) - (v8347 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8354 = v8353[v8512];
        int v8513 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8344 + ((~(((v8346 ^ -1) | (-(v8346 ^ -1))) >> 31)) & 2)) - (v8347 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8355 = v8353[v8513];
        int * v8356 = v8304->mem;
        int v8515 = v8352 * 2;
        v8356[v8515] = v8354;
        int * v8358 = v8304->mem;
        int v8518 = (v8352 * 2) + 1;
        v8358[v8518] = v8355;
        ;
      } else {
        ;
      }
      int * v8363 = v8304->mem;
      int v8523 = ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) * 2;
      int v8364 = v8363[v8523];
      int v8524 = (((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) * 2) + 1;
      int v8365 = v8363[v8524];
      int * v8366 = v8304->cache_vals;
      int v8526 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8344 + ((~(((v8346 ^ -1) | (-(v8346 ^ -1))) >> 31)) & 2)) - (v8347 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8366[v8526] = v8364;
      int * v8368 = v8304->cache_vals;
      int v8529 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8344 + ((~(((v8346 ^ -1) | (-(v8346 ^ -1))) >> 31)) & 2)) - (v8347 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8368[v8529] = v8365;
      int * v8370 = v8304->cache_tags;
      int v8532 = (int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1);
      v8370[v8508] = v8532;
      int * v8372 = v8304->cache_dirty;
      v8372[v8508] = 0;
      int * v8374 = v8304->cache_age;
      v8374[v8508] = 1;
      int * v8376 = v8304->cache_age;
      int v8377 = v8376[v8508];
      int v8378 = v8376[v8482];
      int v8538 = v8378 + ((int)((unsigned int)(v8378 - v8377) >> 31));
      v8376[v8482] = v8538;
      int * v8380 = v8304->cache_age;
      int v8381 = v8380[v8483];
      int v8540 = v8381 + ((int)((unsigned int)(v8381 - v8377) >> 31));
      v8380[v8483] = v8540;
      int * v8383 = v8304->cache_age;
      v8383[v8508] = 0;
      v8386 = v8508;
    }
    int * v8387 = v8304->cache_vals;
    int v8543 = v8386 * 2;
    int v8388 = v8387[v8543];
    int v8544 = (v8386 * 2) + 1;
    int v8389 = v8387[v8544];
    int v8545 = (((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2) + ((((v8328 + ((~(((v8330 ^ -1) | (-(v8330 ^ -1))) >> 31)) & 2)) - (v8331 + ((~(((v8332 ^ -1) | (-(v8332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8387[v8545] = v8388;
    int * v8391 = v8304->cache_vals;
    int v8548 = ((((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2) + ((((v8328 + ((~(((v8330 ^ -1) | (-(v8330 ^ -1))) >> 31)) & 2)) - (v8331 + ((~(((v8332 ^ -1) | (-(v8332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8391[v8548] = v8389;
    int * v8393 = v8304->cache_tags;
    int v8551 = ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 1) * 2) + ((((v8328 + ((~(((v8330 ^ -1) | (-(v8330 ^ -1))) >> 31)) & 2)) - (v8331 + ((~(((v8332 ^ -1) | (-(v8332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8552 = (int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1);
    v8393[v8551] = v8552;
    int * v8395 = v8304->cache_dirty;
    v8395[v8551] = 0;
    int * v8397 = v8304->cache_age;
    v8397[v8551] = 1;
    int * v8399 = v8304->cache_age;
    int v8400 = v8399[v8551];
    int v8401 = v8399[v8480];
    int v8558 = v8401 + ((int)((unsigned int)(v8401 - v8400) >> 31));
    v8399[v8480] = v8558;
    int * v8403 = v8304->cache_age;
    int v8404 = v8403[v8481];
    int v8560 = v8404 + ((int)((unsigned int)(v8404 - v8400) >> 31));
    v8403[v8481] = v8560;
    int * v8406 = v8304->cache_age;
    v8406[v8551] = 0;
    v8409 = v8551;
  }
  int * v8410 = v8304->cache_vals;
  int v8563 = (v8409 * 2) + (((int)((unsigned int)v8308 >> 2)) & 1);
  v8410[v8563] = v8309;
  int * v8412 = v8304->cache_tags;
  int v8413 = v8412[v8482];
  int v8414 = v8412[v8483];
  bool v8566 = !(((~(((v8413 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8413 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) | (~(((v8414 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8414 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31))) == 0);
  int v8468;
  if (v8566) {
    int * v8415 = v8304->cache_age;
    int v8568 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((~(((v8414 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))) | (-(v8414 ^ ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1))))) >> 31)) & 1);
    int v8416 = v8415[v8568];
    int v8417 = v8415[v8482];
    int v8569 = v8417 + ((int)((unsigned int)(v8417 - v8416) >> 31));
    v8415[v8482] = v8569;
    int * v8419 = v8304->cache_age;
    int v8420 = v8419[v8483];
    int v8571 = v8420 + ((int)((unsigned int)(v8420 - v8416) >> 31));
    v8419[v8483] = v8571;
    int * v8422 = v8304->cache_age;
    v8422[v8568] = 0;
    v8468 = v8568;
  } else {
    int * v8425 = v8304->cache_age;
    int v8575 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2);
    int v8426 = v8425[v8575];
    int * v8427 = v8304->cache_tags;
    int v8428 = v8427[v8575];
    int v8429 = v8425[v8483];
    int v8430 = v8427[v8483];
    int * v8431 = v8304->cache_dirty;
    int v8578 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8426 + ((~(((v8428 ^ -1) | (-(v8428 ^ -1))) >> 31)) & 2)) - (v8429 + ((~(((v8430 ^ -1) | (-(v8430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8432 = v8431[v8578];
    bool v8579 = !(v8432 == 0);
    if (v8579) {
      int * v8433 = v8304->cache_tags;
      int v8434 = v8433[v8578];
      int * v8435 = v8304->cache_vals;
      int v8582 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8426 + ((~(((v8428 ^ -1) | (-(v8428 ^ -1))) >> 31)) & 2)) - (v8429 + ((~(((v8430 ^ -1) | (-(v8430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8436 = v8435[v8582];
      int v8583 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8426 + ((~(((v8428 ^ -1) | (-(v8428 ^ -1))) >> 31)) & 2)) - (v8429 + ((~(((v8430 ^ -1) | (-(v8430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8437 = v8435[v8583];
      int * v8438 = v8304->mem;
      int v8585 = v8434 * 2;
      v8438[v8585] = v8436;
      int * v8440 = v8304->mem;
      int v8588 = (v8434 * 2) + 1;
      v8440[v8588] = v8437;
      ;
    } else {
      ;
    }
    int * v8445 = v8304->mem;
    int v8593 = ((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) * 2;
    int v8446 = v8445[v8593];
    int v8594 = (((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) * 2) + 1;
    int v8447 = v8445[v8594];
    int * v8448 = v8304->cache_vals;
    int v8596 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8426 + ((~(((v8428 ^ -1) | (-(v8428 ^ -1))) >> 31)) & 2)) - (v8429 + ((~(((v8430 ^ -1) | (-(v8430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8448[v8596] = v8446;
    int * v8450 = v8304->cache_vals;
    int v8599 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1)) & 3) * 2)) + ((((v8426 + ((~(((v8428 ^ -1) | (-(v8428 ^ -1))) >> 31)) & 2)) - (v8429 + ((~(((v8430 ^ -1) | (-(v8430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8450[v8599] = v8447;
    int * v8452 = v8304->cache_tags;
    int v8602 = (int)((unsigned int)((int)((unsigned int)v8308 >> 2)) >> 1);
    v8452[v8578] = v8602;
    int * v8454 = v8304->cache_dirty;
    v8454[v8578] = 0;
    int * v8456 = v8304->cache_age;
    v8456[v8578] = 1;
    int * v8458 = v8304->cache_age;
    int v8459 = v8458[v8578];
    int v8460 = v8458[v8482];
    int v8608 = v8460 + ((int)((unsigned int)(v8460 - v8459) >> 31));
    v8458[v8482] = v8608;
    int * v8462 = v8304->cache_age;
    int v8463 = v8462[v8483];
    int v8610 = v8463 + ((int)((unsigned int)(v8463 - v8459) >> 31));
    v8462[v8483] = v8610;
    int * v8465 = v8304->cache_age;
    v8465[v8578] = 0;
    v8468 = v8578;
  }
  int * v8469 = v8304->cache_vals;
  int v8613 = (v8468 * 2) + (((int)((unsigned int)v8308 >> 2)) & 1);
  v8469[v8613] = v8309;
  int * v8471 = v8304->cache_dirty;
  v8471[v8468] = 1;
  struct StateT * v8473 = slot_197(v8304);
  return v8473;
}

struct StateT * slot_326(struct StateT * v14411) {
  int v14412 = v14411->timer;
  int v14420 = v14412 + 1;
  v14411->timer = v14420;
  int * v14414 = v14411->regs;
  int v14415 = v14414[21];
  int v14416 = v14414[24];
  int v14424 = v14415 | v14416;
  v14414[21] = v14424;
  struct StateT * v14418 = slot_327(v14411);
  return v14418;
}

struct StateT * slot_303(struct StateT * v14054) {
  int v14055 = v14054->timer;
  int v14063 = v14055 + 1;
  v14054->timer = v14063;
  int * v14057 = v14054->regs;
  int v14058 = v14057[20];
  int v14059 = v14057[24];
  int v14067 = v14058 | v14059;
  v14057[20] = v14067;
  struct StateT * v14061 = slot_304(v14054);
  return v14061;
}

struct StateT * slot_511(struct StateT * v17433) {
  int v17434 = v17433->timer;
  int v17442 = v17434 + 1;
  v17433->timer = v17442;
  int * v17436 = v17433->regs;
  int v17437 = v17436[22];
  int v17438 = v17436[24];
  int v17446 = v17437 | v17438;
  v17436[22] = v17446;
  struct StateT * v17440 = slot_512(v17433);
  return v17440;
}

struct StateT * slot_335(struct StateT * v14549) {
  int v14550 = v14549->timer;
  int v14558 = v14550 + 1;
  v14549->timer = v14558;
  int * v14552 = v14549->regs;
  int v14553 = v14552[6];
  int v14554 = v14552[22];
  int v14562 = v14553 ^ v14554;
  v14552[6] = v14562;
  struct StateT * v14556 = slot_336(v14549);
  return v14556;
}

struct StateT * slot_223(struct StateT * v12265) {
  int v12266 = v12265->timer;
  int v12376 = v12266 + 1;
  v12265->timer = v12376;
  int * v12268 = v12265->regs;
  int v12269 = v12268[2];
  int * v12270 = v12265->cache_tags;
  int v12380 = (((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2;
  int v12271 = v12270[v12380];
  int v12381 = ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12272 = v12270[v12381];
  int v12382 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2);
  int v12273 = v12270[v12382];
  int v12383 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12274 = v12270[v12383];
  int v12275 = v12265->timer;
  int v12384 = v12275 + ((100 ^ (((~(((v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12271 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12271 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12265->timer = v12384;
  int * v12277 = v12265->cache_vals;
  bool v12385 = !(((~(((v12271 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12271 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v12370;
  if (v12385) {
    int * v12278 = v12265->cache_age;
    int v12387 = ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12272 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v12279 = v12278[v12387];
    int v12280 = v12278[v12380];
    int v12388 = v12280 + ((int)((unsigned int)(v12280 - v12279) >> 31));
    v12278[v12380] = v12388;
    int * v12282 = v12265->cache_age;
    int v12283 = v12282[v12381];
    int v12390 = v12283 + ((int)((unsigned int)(v12283 - v12279) >> 31));
    v12282[v12381] = v12390;
    int * v12285 = v12265->cache_age;
    v12285[v12387] = 0;
    v12370 = v12387;
  } else {
    int * v12288 = v12265->cache_age;
    int v12394 = (((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2;
    int v12289 = v12288[v12394];
    int * v12290 = v12265->cache_tags;
    int v12291 = v12290[v12394];
    int v12292 = v12288[v12381];
    int v12293 = v12290[v12381];
    bool v12396 = !(((~(((v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12273 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v12347;
    if (v12396) {
      int * v12294 = v12265->cache_age;
      int v12398 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))) | (-(v12274 ^ ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v12295 = v12294[v12398];
      int v12296 = v12294[v12382];
      int v12399 = v12296 + ((int)((unsigned int)(v12296 - v12295) >> 31));
      v12294[v12382] = v12399;
      int * v12298 = v12265->cache_age;
      int v12299 = v12298[v12383];
      int v12401 = v12299 + ((int)((unsigned int)(v12299 - v12295) >> 31));
      v12298[v12383] = v12401;
      int * v12301 = v12265->cache_age;
      v12301[v12398] = 0;
      v12347 = v12398;
    } else {
      int * v12304 = v12265->cache_age;
      int v12405 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2);
      int v12305 = v12304[v12405];
      int * v12306 = v12265->cache_tags;
      int v12307 = v12306[v12405];
      int v12308 = v12304[v12383];
      int v12309 = v12306[v12383];
      int * v12310 = v12265->cache_dirty;
      int v12408 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12305 + ((~(((v12307 ^ -1) | (-(v12307 ^ -1))) >> 31)) & 2)) - (v12308 + ((~(((v12309 ^ -1) | (-(v12309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12311 = v12310[v12408];
      bool v12409 = !(v12311 == 0);
      if (v12409) {
        int * v12312 = v12265->cache_tags;
        int v12313 = v12312[v12408];
        int * v12314 = v12265->cache_vals;
        int v12412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12305 + ((~(((v12307 ^ -1) | (-(v12307 ^ -1))) >> 31)) & 2)) - (v12308 + ((~(((v12309 ^ -1) | (-(v12309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12315 = v12314[v12412];
        int v12413 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12305 + ((~(((v12307 ^ -1) | (-(v12307 ^ -1))) >> 31)) & 2)) - (v12308 + ((~(((v12309 ^ -1) | (-(v12309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12316 = v12314[v12413];
        int * v12317 = v12265->mem;
        int v12415 = v12313 * 2;
        v12317[v12415] = v12315;
        int * v12319 = v12265->mem;
        int v12418 = (v12313 * 2) + 1;
        v12319[v12418] = v12316;
        ;
      } else {
        ;
      }
      int * v12324 = v12265->mem;
      int v12423 = ((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) * 2;
      int v12325 = v12324[v12423];
      int v12424 = (((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) * 2) + 1;
      int v12326 = v12324[v12424];
      int * v12327 = v12265->cache_vals;
      int v12426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12305 + ((~(((v12307 ^ -1) | (-(v12307 ^ -1))) >> 31)) & 2)) - (v12308 + ((~(((v12309 ^ -1) | (-(v12309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12327[v12426] = v12325;
      int * v12329 = v12265->cache_vals;
      int v12429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12305 + ((~(((v12307 ^ -1) | (-(v12307 ^ -1))) >> 31)) & 2)) - (v12308 + ((~(((v12309 ^ -1) | (-(v12309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12329[v12429] = v12326;
      int * v12331 = v12265->cache_tags;
      int v12432 = (int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1);
      v12331[v12408] = v12432;
      int * v12333 = v12265->cache_dirty;
      v12333[v12408] = 0;
      int * v12335 = v12265->cache_age;
      v12335[v12408] = 1;
      int * v12337 = v12265->cache_age;
      int v12338 = v12337[v12408];
      int v12339 = v12337[v12382];
      int v12438 = v12339 + ((int)((unsigned int)(v12339 - v12338) >> 31));
      v12337[v12382] = v12438;
      int * v12341 = v12265->cache_age;
      int v12342 = v12341[v12383];
      int v12440 = v12342 + ((int)((unsigned int)(v12342 - v12338) >> 31));
      v12341[v12383] = v12440;
      int * v12344 = v12265->cache_age;
      v12344[v12408] = 0;
      v12347 = v12408;
    }
    int * v12348 = v12265->cache_vals;
    int v12443 = v12347 * 2;
    int v12349 = v12348[v12443];
    int v12444 = (v12347 * 2) + 1;
    int v12350 = v12348[v12444];
    int v12445 = (((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12289 + ((~(((v12291 ^ -1) | (-(v12291 ^ -1))) >> 31)) & 2)) - (v12292 + ((~(((v12293 ^ -1) | (-(v12293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12348[v12445] = v12349;
    int * v12352 = v12265->cache_vals;
    int v12448 = ((((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12289 + ((~(((v12291 ^ -1) | (-(v12291 ^ -1))) >> 31)) & 2)) - (v12292 + ((~(((v12293 ^ -1) | (-(v12293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12352[v12448] = v12350;
    int * v12354 = v12265->cache_tags;
    int v12451 = ((((int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12289 + ((~(((v12291 ^ -1) | (-(v12291 ^ -1))) >> 31)) & 2)) - (v12292 + ((~(((v12293 ^ -1) | (-(v12293 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12452 = (int)((unsigned int)((int)((unsigned int)(v12269 + 20) >> 2)) >> 1);
    v12354[v12451] = v12452;
    int * v12356 = v12265->cache_dirty;
    v12356[v12451] = 0;
    int * v12358 = v12265->cache_age;
    v12358[v12451] = 1;
    int * v12360 = v12265->cache_age;
    int v12361 = v12360[v12451];
    int v12362 = v12360[v12380];
    int v12458 = v12362 + ((int)((unsigned int)(v12362 - v12361) >> 31));
    v12360[v12380] = v12458;
    int * v12364 = v12265->cache_age;
    int v12365 = v12364[v12381];
    int v12460 = v12365 + ((int)((unsigned int)(v12365 - v12361) >> 31));
    v12364[v12381] = v12460;
    int * v12367 = v12265->cache_age;
    v12367[v12451] = 0;
    v12370 = v12451;
  }
  int v12463 = (v12370 * 2) + (((int)((unsigned int)(v12269 + 20) >> 2)) & 1);
  int v12371 = v12277[v12463];
  int * v12372 = v12265->regs;
  v12372[22] = v12371;
  struct StateT * v12374 = slot_225(v12265);
  return v12374;
}

struct StateT * slot_316(struct StateT * v14253) {
  int v14254 = v14253->timer;
  int v14262 = v14254 + 1;
  v14253->timer = v14262;
  int * v14256 = v14253->regs;
  int v14257 = v14256[16];
  int v14258 = v14256[23];
  int v14266 = v14257 ^ v14258;
  v14256[16] = v14266;
  struct StateT * v14260 = slot_317(v14253);
  return v14260;
}

struct StateT * slot_424(struct StateT * v16025) {
  int v16026 = v16025->timer;
  int v16033 = v16026 + 1;
  v16025->timer = v16033;
  int * v16028 = v16025->regs;
  int v16029 = v16028[20];
  int v16036 = v16029 << 13;
  v16028[20] = v16036;
  struct StateT * v16031 = slot_425(v16025);
  return v16031;
}

struct StateT * slot_332(struct StateT * v14501) {
  int v14502 = v14501->timer;
  int v14510 = v14502 + 1;
  v14501->timer = v14510;
  int * v14504 = v14501->regs;
  int v14505 = v14504[23];
  int v14506 = v14504[24];
  int v14514 = v14505 | v14506;
  v14504[23] = v14514;
  struct StateT * v14508 = slot_333(v14501);
  return v14508;
}

struct StateT * slot_237(struct StateT * v13021) {
  int v13022 = v13021->timer;
  int v13030 = v13022 + 1;
  v13021->timer = v13030;
  int * v13024 = v13021->regs;
  int v13025 = v13024[9];
  int v13026 = v13024[30];
  int v13035 = v13025 + v13026;
  v13024[20] = v13035;
  struct StateT * v13028 = slot_238(v13021);
  return v13028;
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

struct StateT * slot_508(struct StateT * v17388) {
  int v17389 = v17388->timer;
  int v17397 = v17389 + 1;
  v17388->timer = v17397;
  int * v17391 = v17388->regs;
  int v17392 = v17391[21];
  int v17393 = v17391[24];
  int v17401 = v17392 | v17393;
  v17391[21] = v17401;
  struct StateT * v17395 = slot_509(v17388);
  return v17395;
}

struct StateT * slot_537(struct StateT * v17838) {
  int v17839 = v17838->timer;
  int v17847 = v17839 + 1;
  v17838->timer = v17847;
  int * v17841 = v17838->regs;
  int v17842 = v17841[28];
  int v17843 = v17841[22];
  int v17851 = v17842 ^ v17843;
  v17841[28] = v17851;
  struct StateT * v17845 = slot_538(v17838);
  return v17845;
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

struct StateT * slot_289(struct StateT * v13832) {
  int v13833 = v13832->timer;
  int v13841 = v13833 + 1;
  v13832->timer = v13841;
  int * v13835 = v13832->regs;
  int v13836 = v13835[22];
  int v13837 = v13835[24];
  int v13845 = v13836 | v13837;
  v13835[22] = v13845;
  struct StateT * v13839 = slot_290(v13832);
  return v13839;
}

struct StateT * slot_238(struct StateT * v13038) {
  int v13039 = v13038->timer;
  int v13047 = v13039 + 1;
  v13038->timer = v13047;
  int * v13041 = v13038->regs;
  int v13042 = v13041[18];
  int v13043 = v13041[29];
  int v13052 = v13042 + v13043;
  v13041[21] = v13052;
  struct StateT * v13045 = slot_239(v13038);
  return v13045;
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

struct StateT * slot_256(struct StateT * v13317) {
  int v13318 = v13317->timer;
  int v13326 = v13318 + 1;
  v13317->timer = v13326;
  int * v13320 = v13317->regs;
  int v13321 = v13320[5];
  int v13322 = v13320[23];
  int v13330 = v13321 ^ v13322;
  v13320[5] = v13330;
  struct StateT * v13324 = slot_257(v13317);
  return v13324;
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

struct StateT * slot_245(struct StateT * v13149) {
  int v13150 = v13149->timer;
  int v13157 = v13150 + 1;
  v13149->timer = v13157;
  int * v13152 = v13149->regs;
  int v13153 = v13152[21];
  int v13160 = v13153 << 9;
  v13152[21] = v13160;
  struct StateT * v13155 = slot_246(v13149);
  return v13155;
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

struct StateT * slot_302(struct StateT * v14040) {
  int v14041 = v14040->timer;
  int v14048 = v14041 + 1;
  v14040->timer = v14048;
  int * v14043 = v14040->regs;
  int v14044 = v14043[20];
  int v14051 = v14044 << 7;
  v14043[20] = v14051;
  struct StateT * v14046 = slot_303(v14040);
  return v14046;
}

struct StateT * slot_388(struct StateT * v15404) {
  int v15405 = v15404->timer;
  int v15413 = v15405 + 1;
  v15404->timer = v15413;
  int * v15407 = v15404->regs;
  int v15408 = v15407[21];
  int v15409 = v15407[24];
  int v15417 = v15408 | v15409;
  v15407[21] = v15417;
  struct StateT * v15411 = slot_389(v15404);
  return v15411;
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

struct StateT * slot_487(struct StateT * v17062) {
  int v17063 = v17062->timer;
  int v17070 = v17063 + 1;
  v17062->timer = v17070;
  int * v17065 = v17062->regs;
  int v17066 = v17065[21];
  int v17073 = v17066 << 9;
  v17065[21] = v17073;
  struct StateT * v17068 = slot_488(v17062);
  return v17068;
}

struct StateT * slot_324(struct StateT * v14382) {
  int v14383 = v14382->timer;
  int v14390 = v14383 + 1;
  v14382->timer = v14390;
  int * v14385 = v14382->regs;
  int v14386 = v14385[21];
  int v14394 = (int)((unsigned int)v14386 >> 23);
  v14385[24] = v14394;
  struct StateT * v14388 = slot_325(v14382);
  return v14388;
}

struct StateT * slot_440(struct StateT * v16299) {
  int v16300 = v16299->timer;
  int v16308 = v16300 + 1;
  v16299->timer = v16308;
  int * v16302 = v16299->regs;
  int v16303 = v16302[14];
  int v16304 = v16302[7];
  int v16313 = v16303 + v16304;
  v16302[21] = v16313;
  struct StateT * v16306 = slot_441(v16299);
  return v16306;
}

struct StateT * slot_518(struct StateT * v17542) {
  int v17543 = v17542->timer;
  int v17551 = v17543 + 1;
  v17542->timer = v17551;
  int * v17545 = v17542->regs;
  int v17546 = v17545[19];
  int v17547 = v17545[23];
  int v17555 = v17546 ^ v17547;
  v17545[19] = v17555;
  struct StateT * v17549 = slot_519(v17542);
  return v17549;
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

struct StateT * slot_451(struct StateT * v16469) {
  int v16470 = v16469->timer;
  int v16478 = v16470 + 1;
  v16469->timer = v16478;
  int * v16472 = v16469->regs;
  int v16473 = v16472[22];
  int v16474 = v16472[24];
  int v16482 = v16473 | v16474;
  v16472[22] = v16482;
  struct StateT * v16476 = slot_452(v16469);
  return v16476;
}

struct StateT * slot_458(struct StateT * v16599) {
  int * v16600 = v16599->saved_regs;
  int * v16601 = v16599->regs;
  int v16602 = v16601[31];
  v16600[31] = v16602;
  int v16604 = v16599->timer;
  int v16616 = v16604 + 1;
  v16599->timer = v16616;
  int * v16606 = v16599->regs;
  int v16607 = v16606[31];
  int v16608 = v16606[23];
  int v16619 = v16607 ^ v16608;
  v16606[31] = v16619;
  struct StateT * v16610 = slot_459(v16599);
  return v16610;
}

struct StateT * slot_415(struct StateT * v15850) {
  int * v15851 = v15850->saved_regs;
  int * v15852 = v15850->regs;
  int v15853 = v15852[6];
  v15851[6] = v15853;
  int v15855 = v15850->timer;
  int v15867 = v15855 + 1;
  v15850->timer = v15867;
  int * v15857 = v15850->regs;
  int v15858 = v15857[6];
  int v15859 = v15857[20];
  int v15870 = v15858 ^ v15859;
  v15857[6] = v15870;
  struct StateT * v15861 = slot_416(v15850);
  return v15861;
}

struct StateT * slot_354(struct StateT * v14845) {
  int v14846 = v14845->timer;
  int v14854 = v14846 + 1;
  v14845->timer = v14854;
  int * v14848 = v14845->regs;
  int v14849 = v14848[9];
  int v14850 = v14848[21];
  int v14858 = v14849 ^ v14850;
  v14848[9] = v14858;
  struct StateT * v14852 = slot_355(v14845);
  return v14852;
}

struct StateT * slot_531(struct StateT * v17745) {
  int v17746 = v17745->timer;
  int v17754 = v17746 + 1;
  v17745->timer = v17754;
  int * v17748 = v17745->regs;
  int v17749 = v17748[22];
  int v17750 = v17748[24];
  int v17758 = v17749 | v17750;
  v17748[22] = v17758;
  struct StateT * v17752 = slot_532(v17745);
  return v17752;
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

struct StateT * slot_321(struct StateT * v14337) {
  int v14338 = v14337->timer;
  int v14345 = v14338 + 1;
  v14337->timer = v14345;
  int * v14340 = v14337->regs;
  int v14341 = v14340[20];
  int v14349 = (int)((unsigned int)v14341 >> 23);
  v14340[24] = v14349;
  struct StateT * v14343 = slot_322(v14337);
  return v14343;
}

struct StateT * slot_317(struct StateT * v14269) {
  int v14270 = v14269->timer;
  int v14278 = v14270 + 1;
  v14269->timer = v14278;
  int * v14272 = v14269->regs;
  int v14273 = v14272[14];
  int v14274 = v14272[30];
  int v14283 = v14273 + v14274;
  v14272[20] = v14283;
  struct StateT * v14276 = slot_318(v14269);
  return v14276;
}

struct StateT * slot_205(struct StateT * v9960) {
  int v9961 = v9960->timer;
  int v10131 = v9961 + 1;
  v9960->timer = v10131;
  int * v9963 = v9960->regs;
  int v9964 = v9963[10];
  int v9965 = v9963[5];
  int * v9966 = v9960->cache_tags;
  int v10136 = (((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2;
  int v9967 = v9966[v10136];
  int v10137 = ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9968 = v9966[v10137];
  int v10138 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2);
  int v9969 = v9966[v10138];
  int v10139 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9970 = v9966[v10139];
  int v9971 = v9960->timer;
  int v10140 = v9971 + ((100 ^ (((~(((v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9967 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9967 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9960->timer = v10140;
  bool v10141 = !(((~(((v9967 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9967 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v10065;
  if (v10141) {
    int * v9973 = v9960->cache_age;
    int v10143 = ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9968 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v9974 = v9973[v10143];
    int v9975 = v9973[v10136];
    int v10144 = v9975 + ((int)((unsigned int)(v9975 - v9974) >> 31));
    v9973[v10136] = v10144;
    int * v9977 = v9960->cache_age;
    int v9978 = v9977[v10137];
    int v10146 = v9978 + ((int)((unsigned int)(v9978 - v9974) >> 31));
    v9977[v10137] = v10146;
    int * v9980 = v9960->cache_age;
    v9980[v10143] = 0;
    v10065 = v10143;
  } else {
    int * v9983 = v9960->cache_age;
    int v10150 = (((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2;
    int v9984 = v9983[v10150];
    int * v9985 = v9960->cache_tags;
    int v9986 = v9985[v10150];
    int v9987 = v9983[v10137];
    int v9988 = v9985[v10137];
    bool v10152 = !(((~(((v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9969 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v10042;
    if (v10152) {
      int * v9989 = v9960->cache_age;
      int v10154 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v9970 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v9990 = v9989[v10154];
      int v9991 = v9989[v10138];
      int v10155 = v9991 + ((int)((unsigned int)(v9991 - v9990) >> 31));
      v9989[v10138] = v10155;
      int * v9993 = v9960->cache_age;
      int v9994 = v9993[v10139];
      int v10157 = v9994 + ((int)((unsigned int)(v9994 - v9990) >> 31));
      v9993[v10139] = v10157;
      int * v9996 = v9960->cache_age;
      v9996[v10154] = 0;
      v10042 = v10154;
    } else {
      int * v9999 = v9960->cache_age;
      int v10161 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2);
      int v10000 = v9999[v10161];
      int * v10001 = v9960->cache_tags;
      int v10002 = v10001[v10161];
      int v10003 = v9999[v10139];
      int v10004 = v10001[v10139];
      int * v10005 = v9960->cache_dirty;
      int v10164 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10000 + ((~(((v10002 ^ -1) | (-(v10002 ^ -1))) >> 31)) & 2)) - (v10003 + ((~(((v10004 ^ -1) | (-(v10004 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10006 = v10005[v10164];
      bool v10165 = !(v10006 == 0);
      if (v10165) {
        int * v10007 = v9960->cache_tags;
        int v10008 = v10007[v10164];
        int * v10009 = v9960->cache_vals;
        int v10168 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10000 + ((~(((v10002 ^ -1) | (-(v10002 ^ -1))) >> 31)) & 2)) - (v10003 + ((~(((v10004 ^ -1) | (-(v10004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10010 = v10009[v10168];
        int v10169 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10000 + ((~(((v10002 ^ -1) | (-(v10002 ^ -1))) >> 31)) & 2)) - (v10003 + ((~(((v10004 ^ -1) | (-(v10004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10011 = v10009[v10169];
        int * v10012 = v9960->mem;
        int v10171 = v10008 * 2;
        v10012[v10171] = v10010;
        int * v10014 = v9960->mem;
        int v10174 = (v10008 * 2) + 1;
        v10014[v10174] = v10011;
        ;
      } else {
        ;
      }
      int * v10019 = v9960->mem;
      int v10179 = ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) * 2;
      int v10020 = v10019[v10179];
      int v10180 = (((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) * 2) + 1;
      int v10021 = v10019[v10180];
      int * v10022 = v9960->cache_vals;
      int v10182 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10000 + ((~(((v10002 ^ -1) | (-(v10002 ^ -1))) >> 31)) & 2)) - (v10003 + ((~(((v10004 ^ -1) | (-(v10004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10022[v10182] = v10020;
      int * v10024 = v9960->cache_vals;
      int v10185 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10000 + ((~(((v10002 ^ -1) | (-(v10002 ^ -1))) >> 31)) & 2)) - (v10003 + ((~(((v10004 ^ -1) | (-(v10004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10024[v10185] = v10021;
      int * v10026 = v9960->cache_tags;
      int v10188 = (int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1);
      v10026[v10164] = v10188;
      int * v10028 = v9960->cache_dirty;
      v10028[v10164] = 0;
      int * v10030 = v9960->cache_age;
      v10030[v10164] = 1;
      int * v10032 = v9960->cache_age;
      int v10033 = v10032[v10164];
      int v10034 = v10032[v10138];
      int v10194 = v10034 + ((int)((unsigned int)(v10034 - v10033) >> 31));
      v10032[v10138] = v10194;
      int * v10036 = v9960->cache_age;
      int v10037 = v10036[v10139];
      int v10196 = v10037 + ((int)((unsigned int)(v10037 - v10033) >> 31));
      v10036[v10139] = v10196;
      int * v10039 = v9960->cache_age;
      v10039[v10164] = 0;
      v10042 = v10164;
    }
    int * v10043 = v9960->cache_vals;
    int v10199 = v10042 * 2;
    int v10044 = v10043[v10199];
    int v10200 = (v10042 * 2) + 1;
    int v10045 = v10043[v10200];
    int v10201 = (((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9984 + ((~(((v9986 ^ -1) | (-(v9986 ^ -1))) >> 31)) & 2)) - (v9987 + ((~(((v9988 ^ -1) | (-(v9988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10043[v10201] = v10044;
    int * v10047 = v9960->cache_vals;
    int v10204 = ((((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9984 + ((~(((v9986 ^ -1) | (-(v9986 ^ -1))) >> 31)) & 2)) - (v9987 + ((~(((v9988 ^ -1) | (-(v9988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10047[v10204] = v10045;
    int * v10049 = v9960->cache_tags;
    int v10207 = ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9984 + ((~(((v9986 ^ -1) | (-(v9986 ^ -1))) >> 31)) & 2)) - (v9987 + ((~(((v9988 ^ -1) | (-(v9988 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10208 = (int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1);
    v10049[v10207] = v10208;
    int * v10051 = v9960->cache_dirty;
    v10051[v10207] = 0;
    int * v10053 = v9960->cache_age;
    v10053[v10207] = 1;
    int * v10055 = v9960->cache_age;
    int v10056 = v10055[v10207];
    int v10057 = v10055[v10136];
    int v10214 = v10057 + ((int)((unsigned int)(v10057 - v10056) >> 31));
    v10055[v10136] = v10214;
    int * v10059 = v9960->cache_age;
    int v10060 = v10059[v10137];
    int v10216 = v10060 + ((int)((unsigned int)(v10060 - v10056) >> 31));
    v10059[v10137] = v10216;
    int * v10062 = v9960->cache_age;
    v10062[v10207] = 0;
    v10065 = v10207;
  }
  int * v10066 = v9960->cache_vals;
  int v10219 = (v10065 * 2) + (((int)((unsigned int)(v9964 + 20) >> 2)) & 1);
  v10066[v10219] = v9965;
  int * v10068 = v9960->cache_tags;
  int v10069 = v10068[v10138];
  int v10070 = v10068[v10139];
  bool v10222 = !(((~(((v10069 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v10069 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10070 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v10070 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v10124;
  if (v10222) {
    int * v10071 = v9960->cache_age;
    int v10224 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10070 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))) | (-(v10070 ^ ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v10072 = v10071[v10224];
    int v10073 = v10071[v10138];
    int v10225 = v10073 + ((int)((unsigned int)(v10073 - v10072) >> 31));
    v10071[v10138] = v10225;
    int * v10075 = v9960->cache_age;
    int v10076 = v10075[v10139];
    int v10227 = v10076 + ((int)((unsigned int)(v10076 - v10072) >> 31));
    v10075[v10139] = v10227;
    int * v10078 = v9960->cache_age;
    v10078[v10224] = 0;
    v10124 = v10224;
  } else {
    int * v10081 = v9960->cache_age;
    int v10231 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2);
    int v10082 = v10081[v10231];
    int * v10083 = v9960->cache_tags;
    int v10084 = v10083[v10231];
    int v10085 = v10081[v10139];
    int v10086 = v10083[v10139];
    int * v10087 = v9960->cache_dirty;
    int v10234 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10082 + ((~(((v10084 ^ -1) | (-(v10084 ^ -1))) >> 31)) & 2)) - (v10085 + ((~(((v10086 ^ -1) | (-(v10086 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10088 = v10087[v10234];
    bool v10235 = !(v10088 == 0);
    if (v10235) {
      int * v10089 = v9960->cache_tags;
      int v10090 = v10089[v10234];
      int * v10091 = v9960->cache_vals;
      int v10238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10082 + ((~(((v10084 ^ -1) | (-(v10084 ^ -1))) >> 31)) & 2)) - (v10085 + ((~(((v10086 ^ -1) | (-(v10086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10092 = v10091[v10238];
      int v10239 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10082 + ((~(((v10084 ^ -1) | (-(v10084 ^ -1))) >> 31)) & 2)) - (v10085 + ((~(((v10086 ^ -1) | (-(v10086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10093 = v10091[v10239];
      int * v10094 = v9960->mem;
      int v10241 = v10090 * 2;
      v10094[v10241] = v10092;
      int * v10096 = v9960->mem;
      int v10244 = (v10090 * 2) + 1;
      v10096[v10244] = v10093;
      ;
    } else {
      ;
    }
    int * v10101 = v9960->mem;
    int v10249 = ((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) * 2;
    int v10102 = v10101[v10249];
    int v10250 = (((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) * 2) + 1;
    int v10103 = v10101[v10250];
    int * v10104 = v9960->cache_vals;
    int v10252 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10082 + ((~(((v10084 ^ -1) | (-(v10084 ^ -1))) >> 31)) & 2)) - (v10085 + ((~(((v10086 ^ -1) | (-(v10086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10104[v10252] = v10102;
    int * v10106 = v9960->cache_vals;
    int v10255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10082 + ((~(((v10084 ^ -1) | (-(v10084 ^ -1))) >> 31)) & 2)) - (v10085 + ((~(((v10086 ^ -1) | (-(v10086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10106[v10255] = v10103;
    int * v10108 = v9960->cache_tags;
    int v10258 = (int)((unsigned int)((int)((unsigned int)(v9964 + 20) >> 2)) >> 1);
    v10108[v10234] = v10258;
    int * v10110 = v9960->cache_dirty;
    v10110[v10234] = 0;
    int * v10112 = v9960->cache_age;
    v10112[v10234] = 1;
    int * v10114 = v9960->cache_age;
    int v10115 = v10114[v10234];
    int v10116 = v10114[v10138];
    int v10264 = v10116 + ((int)((unsigned int)(v10116 - v10115) >> 31));
    v10114[v10138] = v10264;
    int * v10118 = v9960->cache_age;
    int v10119 = v10118[v10139];
    int v10266 = v10119 + ((int)((unsigned int)(v10119 - v10115) >> 31));
    v10118[v10139] = v10266;
    int * v10121 = v9960->cache_age;
    v10121[v10234] = 0;
    v10124 = v10234;
  }
  int * v10125 = v9960->cache_vals;
  int v10269 = (v10124 * 2) + (((int)((unsigned int)(v9964 + 20) >> 2)) & 1);
  v10125[v10269] = v9965;
  int * v10127 = v9960->cache_dirty;
  v10127[v10124] = 1;
  struct StateT * v10129 = slot_207(v9960);
  return v10129;
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

struct StateT * slot_375(struct StateT * v15173) {
  int v15174 = v15173->timer;
  int v15182 = v15174 + 1;
  v15173->timer = v15182;
  int * v15176 = v15173->regs;
  int v15177 = v15176[28];
  int v15178 = v15176[22];
  int v15186 = v15177 ^ v15178;
  v15176[28] = v15186;
  struct StateT * v15180 = slot_376(v15173);
  return v15180;
}

struct StateT * slot_331(struct StateT * v14487) {
  int v14488 = v14487->timer;
  int v14495 = v14488 + 1;
  v14487->timer = v14495;
  int * v14490 = v14487->regs;
  int v14491 = v14490[23];
  int v14498 = v14491 << 9;
  v14490[23] = v14498;
  struct StateT * v14493 = slot_332(v14487);
  return v14493;
}

struct StateT * slot_380(struct StateT * v15251) {
  int * v15252 = v15251->saved_regs;
  int * v15253 = v15251->regs;
  int v15254 = v15253[21];
  v15252[21] = v15254;
  int v15256 = v15251->timer;
  int v15268 = v15256 + 1;
  v15251->timer = v15268;
  int * v15258 = v15251->regs;
  int v15259 = v15258[29];
  int v15260 = v15258[14];
  int v15272 = v15259 + v15260;
  v15258[21] = v15272;
  struct StateT * v15262 = slot_381(v15251);
  return v15262;
}

struct StateT * slot_412(struct StateT * v15805) {
  int v15806 = v15805->timer;
  int v15813 = v15806 + 1;
  v15805->timer = v15813;
  int * v15808 = v15805->regs;
  int v15809 = v15808[23];
  int v15817 = (int)((unsigned int)v15809 >> 23);
  v15808[24] = v15817;
  struct StateT * v15811 = slot_413(v15805);
  return v15811;
}

struct StateT * slot_381(struct StateT * v15275) {
  int * v15276 = v15275->saved_regs;
  int * v15277 = v15275->regs;
  int v15278 = v15277[22];
  v15276[22] = v15278;
  int v15280 = v15275->timer;
  int v15292 = v15280 + 1;
  v15275->timer = v15292;
  int * v15282 = v15275->regs;
  int v15283 = v15282[28];
  int v15284 = v15282[12];
  int v15296 = v15283 + v15284;
  v15282[22] = v15296;
  struct StateT * v15286 = slot_382(v15275);
  return v15286;
}

struct StateT * slot_478(struct StateT * v16918) {
  int v16919 = v16918->timer;
  int v16927 = v16919 + 1;
  v16918->timer = v16927;
  int * v16921 = v16918->regs;
  int v16922 = v16921[16];
  int v16923 = v16921[23];
  int v16931 = v16922 ^ v16923;
  v16921[16] = v16931;
  struct StateT * v16925 = slot_479(v16918);
  return v16925;
}

struct StateT * slot_246(struct StateT * v13163) {
  int v13164 = v13163->timer;
  int v13172 = v13164 + 1;
  v13163->timer = v13172;
  int * v13166 = v13163->regs;
  int v13167 = v13166[21];
  int v13168 = v13166[24];
  int v13176 = v13167 | v13168;
  v13166[21] = v13176;
  struct StateT * v13170 = slot_247(v13163);
  return v13170;
}

struct StateT * slot_210(struct StateT * v10937) {
  int v10938 = v10937->timer;
  int v10945 = v10938 + 1;
  v10937->timer = v10945;
  int * v10940 = v10937->regs;
  int v10941 = v10940[20];
  int v10948 = v10941 << 7;
  v10940[20] = v10948;
  struct StateT * v10943 = slot_212(v10937);
  return v10943;
}

struct StateT * slot_472(struct StateT * v16825) {
  int v16826 = v16825->timer;
  int v16833 = v16826 + 1;
  v16825->timer = v16833;
  int * v16828 = v16825->regs;
  int v16829 = v16828[23];
  int v16837 = (int)((unsigned int)v16829 >> 25);
  v16828[24] = v16837;
  struct StateT * v16831 = slot_473(v16825);
  return v16831;
}

struct StateT * slot_284(struct StateT * v13758) {
  int v13759 = v13758->timer;
  int v13766 = v13759 + 1;
  v13758->timer = v13766;
  int * v13761 = v13758->regs;
  int v13762 = v13761[21];
  int v13770 = (int)((unsigned int)v13762 >> 14);
  v13761[24] = v13770;
  struct StateT * v13764 = slot_285(v13758);
  return v13764;
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

struct StateT * slot_209(struct StateT * v10622) {
  int v10623 = v10622->timer;
  int v10793 = v10623 + 1;
  v10622->timer = v10793;
  int * v10625 = v10622->regs;
  int v10626 = v10625[10];
  int v10627 = v10625[18];
  int * v10628 = v10622->cache_tags;
  int v10798 = (((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2;
  int v10629 = v10628[v10798];
  int v10799 = ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10630 = v10628[v10799];
  int v10800 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2);
  int v10631 = v10628[v10800];
  int v10801 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10632 = v10628[v10801];
  int v10633 = v10622->timer;
  int v10802 = v10633 + ((100 ^ (((~(((v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10629 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10629 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10622->timer = v10802;
  bool v10803 = !(((~(((v10629 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10629 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v10727;
  if (v10803) {
    int * v10635 = v10622->cache_age;
    int v10805 = ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10630 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v10636 = v10635[v10805];
    int v10637 = v10635[v10798];
    int v10806 = v10637 + ((int)((unsigned int)(v10637 - v10636) >> 31));
    v10635[v10798] = v10806;
    int * v10639 = v10622->cache_age;
    int v10640 = v10639[v10799];
    int v10808 = v10640 + ((int)((unsigned int)(v10640 - v10636) >> 31));
    v10639[v10799] = v10808;
    int * v10642 = v10622->cache_age;
    v10642[v10805] = 0;
    v10727 = v10805;
  } else {
    int * v10645 = v10622->cache_age;
    int v10812 = (((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2;
    int v10646 = v10645[v10812];
    int * v10647 = v10622->cache_tags;
    int v10648 = v10647[v10812];
    int v10649 = v10645[v10799];
    int v10650 = v10647[v10799];
    bool v10814 = !(((~(((v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10631 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v10704;
    if (v10814) {
      int * v10651 = v10622->cache_age;
      int v10816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10632 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v10652 = v10651[v10816];
      int v10653 = v10651[v10800];
      int v10817 = v10653 + ((int)((unsigned int)(v10653 - v10652) >> 31));
      v10651[v10800] = v10817;
      int * v10655 = v10622->cache_age;
      int v10656 = v10655[v10801];
      int v10819 = v10656 + ((int)((unsigned int)(v10656 - v10652) >> 31));
      v10655[v10801] = v10819;
      int * v10658 = v10622->cache_age;
      v10658[v10816] = 0;
      v10704 = v10816;
    } else {
      int * v10661 = v10622->cache_age;
      int v10823 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2);
      int v10662 = v10661[v10823];
      int * v10663 = v10622->cache_tags;
      int v10664 = v10663[v10823];
      int v10665 = v10661[v10801];
      int v10666 = v10663[v10801];
      int * v10667 = v10622->cache_dirty;
      int v10826 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10662 + ((~(((v10664 ^ -1) | (-(v10664 ^ -1))) >> 31)) & 2)) - (v10665 + ((~(((v10666 ^ -1) | (-(v10666 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10668 = v10667[v10826];
      bool v10827 = !(v10668 == 0);
      if (v10827) {
        int * v10669 = v10622->cache_tags;
        int v10670 = v10669[v10826];
        int * v10671 = v10622->cache_vals;
        int v10830 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10662 + ((~(((v10664 ^ -1) | (-(v10664 ^ -1))) >> 31)) & 2)) - (v10665 + ((~(((v10666 ^ -1) | (-(v10666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10672 = v10671[v10830];
        int v10831 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10662 + ((~(((v10664 ^ -1) | (-(v10664 ^ -1))) >> 31)) & 2)) - (v10665 + ((~(((v10666 ^ -1) | (-(v10666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10673 = v10671[v10831];
        int * v10674 = v10622->mem;
        int v10833 = v10670 * 2;
        v10674[v10833] = v10672;
        int * v10676 = v10622->mem;
        int v10836 = (v10670 * 2) + 1;
        v10676[v10836] = v10673;
        ;
      } else {
        ;
      }
      int * v10681 = v10622->mem;
      int v10841 = ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) * 2;
      int v10682 = v10681[v10841];
      int v10842 = (((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) * 2) + 1;
      int v10683 = v10681[v10842];
      int * v10684 = v10622->cache_vals;
      int v10844 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10662 + ((~(((v10664 ^ -1) | (-(v10664 ^ -1))) >> 31)) & 2)) - (v10665 + ((~(((v10666 ^ -1) | (-(v10666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10684[v10844] = v10682;
      int * v10686 = v10622->cache_vals;
      int v10847 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10662 + ((~(((v10664 ^ -1) | (-(v10664 ^ -1))) >> 31)) & 2)) - (v10665 + ((~(((v10666 ^ -1) | (-(v10666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10686[v10847] = v10683;
      int * v10688 = v10622->cache_tags;
      int v10850 = (int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1);
      v10688[v10826] = v10850;
      int * v10690 = v10622->cache_dirty;
      v10690[v10826] = 0;
      int * v10692 = v10622->cache_age;
      v10692[v10826] = 1;
      int * v10694 = v10622->cache_age;
      int v10695 = v10694[v10826];
      int v10696 = v10694[v10800];
      int v10856 = v10696 + ((int)((unsigned int)(v10696 - v10695) >> 31));
      v10694[v10800] = v10856;
      int * v10698 = v10622->cache_age;
      int v10699 = v10698[v10801];
      int v10858 = v10699 + ((int)((unsigned int)(v10699 - v10695) >> 31));
      v10698[v10801] = v10858;
      int * v10701 = v10622->cache_age;
      v10701[v10826] = 0;
      v10704 = v10826;
    }
    int * v10705 = v10622->cache_vals;
    int v10861 = v10704 * 2;
    int v10706 = v10705[v10861];
    int v10862 = (v10704 * 2) + 1;
    int v10707 = v10705[v10862];
    int v10863 = (((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v10646 + ((~(((v10648 ^ -1) | (-(v10648 ^ -1))) >> 31)) & 2)) - (v10649 + ((~(((v10650 ^ -1) | (-(v10650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10705[v10863] = v10706;
    int * v10709 = v10622->cache_vals;
    int v10866 = ((((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v10646 + ((~(((v10648 ^ -1) | (-(v10648 ^ -1))) >> 31)) & 2)) - (v10649 + ((~(((v10650 ^ -1) | (-(v10650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10709[v10866] = v10707;
    int * v10711 = v10622->cache_tags;
    int v10869 = ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v10646 + ((~(((v10648 ^ -1) | (-(v10648 ^ -1))) >> 31)) & 2)) - (v10649 + ((~(((v10650 ^ -1) | (-(v10650 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10870 = (int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1);
    v10711[v10869] = v10870;
    int * v10713 = v10622->cache_dirty;
    v10713[v10869] = 0;
    int * v10715 = v10622->cache_age;
    v10715[v10869] = 1;
    int * v10717 = v10622->cache_age;
    int v10718 = v10717[v10869];
    int v10719 = v10717[v10798];
    int v10876 = v10719 + ((int)((unsigned int)(v10719 - v10718) >> 31));
    v10717[v10798] = v10876;
    int * v10721 = v10622->cache_age;
    int v10722 = v10721[v10799];
    int v10878 = v10722 + ((int)((unsigned int)(v10722 - v10718) >> 31));
    v10721[v10799] = v10878;
    int * v10724 = v10622->cache_age;
    v10724[v10869] = 0;
    v10727 = v10869;
  }
  int * v10728 = v10622->cache_vals;
  int v10881 = (v10727 * 2) + (((int)((unsigned int)(v10626 + 28) >> 2)) & 1);
  v10728[v10881] = v10627;
  int * v10730 = v10622->cache_tags;
  int v10731 = v10730[v10800];
  int v10732 = v10730[v10801];
  bool v10884 = !(((~(((v10731 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10731 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v10732 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10732 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v10786;
  if (v10884) {
    int * v10733 = v10622->cache_age;
    int v10886 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10732 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))) | (-(v10732 ^ ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v10734 = v10733[v10886];
    int v10735 = v10733[v10800];
    int v10887 = v10735 + ((int)((unsigned int)(v10735 - v10734) >> 31));
    v10733[v10800] = v10887;
    int * v10737 = v10622->cache_age;
    int v10738 = v10737[v10801];
    int v10889 = v10738 + ((int)((unsigned int)(v10738 - v10734) >> 31));
    v10737[v10801] = v10889;
    int * v10740 = v10622->cache_age;
    v10740[v10886] = 0;
    v10786 = v10886;
  } else {
    int * v10743 = v10622->cache_age;
    int v10893 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2);
    int v10744 = v10743[v10893];
    int * v10745 = v10622->cache_tags;
    int v10746 = v10745[v10893];
    int v10747 = v10743[v10801];
    int v10748 = v10745[v10801];
    int * v10749 = v10622->cache_dirty;
    int v10896 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10744 + ((~(((v10746 ^ -1) | (-(v10746 ^ -1))) >> 31)) & 2)) - (v10747 + ((~(((v10748 ^ -1) | (-(v10748 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10750 = v10749[v10896];
    bool v10897 = !(v10750 == 0);
    if (v10897) {
      int * v10751 = v10622->cache_tags;
      int v10752 = v10751[v10896];
      int * v10753 = v10622->cache_vals;
      int v10900 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10744 + ((~(((v10746 ^ -1) | (-(v10746 ^ -1))) >> 31)) & 2)) - (v10747 + ((~(((v10748 ^ -1) | (-(v10748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10754 = v10753[v10900];
      int v10901 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10744 + ((~(((v10746 ^ -1) | (-(v10746 ^ -1))) >> 31)) & 2)) - (v10747 + ((~(((v10748 ^ -1) | (-(v10748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10755 = v10753[v10901];
      int * v10756 = v10622->mem;
      int v10903 = v10752 * 2;
      v10756[v10903] = v10754;
      int * v10758 = v10622->mem;
      int v10906 = (v10752 * 2) + 1;
      v10758[v10906] = v10755;
      ;
    } else {
      ;
    }
    int * v10763 = v10622->mem;
    int v10911 = ((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) * 2;
    int v10764 = v10763[v10911];
    int v10912 = (((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) * 2) + 1;
    int v10765 = v10763[v10912];
    int * v10766 = v10622->cache_vals;
    int v10914 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10744 + ((~(((v10746 ^ -1) | (-(v10746 ^ -1))) >> 31)) & 2)) - (v10747 + ((~(((v10748 ^ -1) | (-(v10748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10766[v10914] = v10764;
    int * v10768 = v10622->cache_vals;
    int v10917 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v10744 + ((~(((v10746 ^ -1) | (-(v10746 ^ -1))) >> 31)) & 2)) - (v10747 + ((~(((v10748 ^ -1) | (-(v10748 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10768[v10917] = v10765;
    int * v10770 = v10622->cache_tags;
    int v10920 = (int)((unsigned int)((int)((unsigned int)(v10626 + 28) >> 2)) >> 1);
    v10770[v10896] = v10920;
    int * v10772 = v10622->cache_dirty;
    v10772[v10896] = 0;
    int * v10774 = v10622->cache_age;
    v10774[v10896] = 1;
    int * v10776 = v10622->cache_age;
    int v10777 = v10776[v10896];
    int v10778 = v10776[v10800];
    int v10926 = v10778 + ((int)((unsigned int)(v10778 - v10777) >> 31));
    v10776[v10800] = v10926;
    int * v10780 = v10622->cache_age;
    int v10781 = v10780[v10801];
    int v10928 = v10781 + ((int)((unsigned int)(v10781 - v10777) >> 31));
    v10780[v10801] = v10928;
    int * v10783 = v10622->cache_age;
    v10783[v10896] = 0;
    v10786 = v10896;
  }
  int * v10787 = v10622->cache_vals;
  int v10931 = (v10786 * 2) + (((int)((unsigned int)(v10626 + 28) >> 2)) & 1);
  v10787[v10931] = v10627;
  int * v10789 = v10622->cache_dirty;
  v10789[v10786] = 1;
  struct StateT * v10791 = slot_211(v10622);
  return v10791;
}

struct StateT * slot_420(struct StateT * v15959) {
  int v15960 = v15959->timer;
  int v15968 = v15960 + 1;
  v15959->timer = v15968;
  int * v15962 = v15959->regs;
  int v15963 = v15962[7];
  int v15964 = v15962[18];
  int v15973 = v15963 + v15964;
  v15962[21] = v15973;
  struct StateT * v15966 = slot_421(v15959);
  return v15966;
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

struct StateT * slot_270(struct StateT * v13536) {
  int v13537 = v13536->timer;
  int v13544 = v13537 + 1;
  v13536->timer = v13544;
  int * v13539 = v13536->regs;
  int v13540 = v13539[23];
  int v13548 = (int)((unsigned int)v13540 >> 19);
  v13539[24] = v13548;
  struct StateT * v13542 = slot_271(v13536);
  return v13542;
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
    struct StateT * v8950 = slot_195(v8942);
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

struct StateT * slot_446(struct StateT * v16395) {
  int v16396 = v16395->timer;
  int v16403 = v16396 + 1;
  v16395->timer = v16403;
  int * v16398 = v16395->regs;
  int v16399 = v16398[21];
  int v16407 = (int)((unsigned int)v16399 >> 14);
  v16398[24] = v16407;
  struct StateT * v16401 = slot_447(v16395);
  return v16401;
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

struct StateT * slot_361(struct StateT * v14961) {
  int v14962 = v14961->timer;
  int v14969 = v14962 + 1;
  v14961->timer = v14969;
  int * v14964 = v14961->regs;
  int v14965 = v14964[20];
  int v14973 = (int)((unsigned int)v14965 >> 14);
  v14964[24] = v14973;
  struct StateT * v14967 = slot_362(v14961);
  return v14967;
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

struct StateT * slot_510(struct StateT * v17419) {
  int v17420 = v17419->timer;
  int v17427 = v17420 + 1;
  v17419->timer = v17427;
  int * v17422 = v17419->regs;
  int v17423 = v17422[22];
  int v17430 = v17423 << 13;
  v17422[22] = v17430;
  struct StateT * v17425 = slot_511(v17419);
  return v17425;
}

struct StateT * slot_459(struct StateT * v16622) {
  int v16623 = v16622->timer;
  int v16631 = v16623 + 1;
  v16622->timer = v16631;
  int * v16625 = v16622->regs;
  int v16626 = v16625[30];
  int v16627 = v16625[8];
  int v16636 = v16626 + v16627;
  v16625[20] = v16636;
  struct StateT * v16629 = slot_460(v16622);
  return v16629;
}

struct StateT * slot_404(struct StateT * v15685) {
  int v15686 = v15685->timer;
  int v15693 = v15686 + 1;
  v15685->timer = v15693;
  int * v15688 = v15685->regs;
  int v15689 = v15688[20];
  int v15696 = v15689 << 9;
  v15688[20] = v15696;
  struct StateT * v15691 = slot_405(v15685);
  return v15691;
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

struct StateT * slot_212(struct StateT * v11155) {
  int v11156 = v11155->timer;
  int v11164 = v11156 + 1;
  v11155->timer = v11164;
  int * v11158 = v11155->regs;
  int v11159 = v11158[20];
  int v11160 = v11158[24];
  int v11168 = v11159 | v11160;
  v11158[20] = v11168;
  struct StateT * v11162 = slot_214(v11155);
  return v11162;
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

struct StateT * slot_313(struct StateT * v14205) {
  int v14206 = v14205->timer;
  int v14214 = v14206 + 1;
  v14205->timer = v14214;
  int * v14208 = v14205->regs;
  int v14209 = v14208[14];
  int v14210 = v14208[20];
  int v14218 = v14209 ^ v14210;
  v14208[14] = v14218;
  struct StateT * v14212 = slot_314(v14205);
  return v14212;
}

struct StateT * slot_211(struct StateT * v10951) {
  int v10952 = v10951->timer;
  int v11062 = v10952 + 1;
  v10951->timer = v11062;
  int * v10954 = v10951->regs;
  int v10955 = v10954[2];
  int * v10956 = v10951->cache_tags;
  int v11066 = (((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2;
  int v10957 = v10956[v11066];
  int v11067 = ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10958 = v10956[v11067];
  int v11068 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2);
  int v10959 = v10956[v11068];
  int v11069 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10960 = v10956[v11069];
  int v10961 = v10951->timer;
  int v11070 = v10961 + ((100 ^ (((~(((v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10957 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10957 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10951->timer = v11070;
  int * v10963 = v10951->cache_vals;
  bool v11071 = !(((~(((v10957 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10957 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v11056;
  if (v11071) {
    int * v10964 = v10951->cache_age;
    int v11073 = ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10958 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v10965 = v10964[v11073];
    int v10966 = v10964[v11066];
    int v11074 = v10966 + ((int)((unsigned int)(v10966 - v10965) >> 31));
    v10964[v11066] = v11074;
    int * v10968 = v10951->cache_age;
    int v10969 = v10968[v11067];
    int v11076 = v10969 + ((int)((unsigned int)(v10969 - v10965) >> 31));
    v10968[v11067] = v11076;
    int * v10971 = v10951->cache_age;
    v10971[v11073] = 0;
    v11056 = v11073;
  } else {
    int * v10974 = v10951->cache_age;
    int v11080 = (((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2;
    int v10975 = v10974[v11080];
    int * v10976 = v10951->cache_tags;
    int v10977 = v10976[v11080];
    int v10978 = v10974[v11067];
    int v10979 = v10976[v11067];
    bool v11082 = !(((~(((v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10959 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v11033;
    if (v11082) {
      int * v10980 = v10951->cache_age;
      int v11084 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))) | (-(v10960 ^ ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v10981 = v10980[v11084];
      int v10982 = v10980[v11068];
      int v11085 = v10982 + ((int)((unsigned int)(v10982 - v10981) >> 31));
      v10980[v11068] = v11085;
      int * v10984 = v10951->cache_age;
      int v10985 = v10984[v11069];
      int v11087 = v10985 + ((int)((unsigned int)(v10985 - v10981) >> 31));
      v10984[v11069] = v11087;
      int * v10987 = v10951->cache_age;
      v10987[v11084] = 0;
      v11033 = v11084;
    } else {
      int * v10990 = v10951->cache_age;
      int v11091 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2);
      int v10991 = v10990[v11091];
      int * v10992 = v10951->cache_tags;
      int v10993 = v10992[v11091];
      int v10994 = v10990[v11069];
      int v10995 = v10992[v11069];
      int * v10996 = v10951->cache_dirty;
      int v11094 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v10991 + ((~(((v10993 ^ -1) | (-(v10993 ^ -1))) >> 31)) & 2)) - (v10994 + ((~(((v10995 ^ -1) | (-(v10995 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10997 = v10996[v11094];
      bool v11095 = !(v10997 == 0);
      if (v11095) {
        int * v10998 = v10951->cache_tags;
        int v10999 = v10998[v11094];
        int * v11000 = v10951->cache_vals;
        int v11098 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v10991 + ((~(((v10993 ^ -1) | (-(v10993 ^ -1))) >> 31)) & 2)) - (v10994 + ((~(((v10995 ^ -1) | (-(v10995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11001 = v11000[v11098];
        int v11099 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v10991 + ((~(((v10993 ^ -1) | (-(v10993 ^ -1))) >> 31)) & 2)) - (v10994 + ((~(((v10995 ^ -1) | (-(v10995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11002 = v11000[v11099];
        int * v11003 = v10951->mem;
        int v11101 = v10999 * 2;
        v11003[v11101] = v11001;
        int * v11005 = v10951->mem;
        int v11104 = (v10999 * 2) + 1;
        v11005[v11104] = v11002;
        ;
      } else {
        ;
      }
      int * v11010 = v10951->mem;
      int v11109 = ((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) * 2;
      int v11011 = v11010[v11109];
      int v11110 = (((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) * 2) + 1;
      int v11012 = v11010[v11110];
      int * v11013 = v10951->cache_vals;
      int v11112 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v10991 + ((~(((v10993 ^ -1) | (-(v10993 ^ -1))) >> 31)) & 2)) - (v10994 + ((~(((v10995 ^ -1) | (-(v10995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11013[v11112] = v11011;
      int * v11015 = v10951->cache_vals;
      int v11115 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v10991 + ((~(((v10993 ^ -1) | (-(v10993 ^ -1))) >> 31)) & 2)) - (v10994 + ((~(((v10995 ^ -1) | (-(v10995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11015[v11115] = v11012;
      int * v11017 = v10951->cache_tags;
      int v11118 = (int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1);
      v11017[v11094] = v11118;
      int * v11019 = v10951->cache_dirty;
      v11019[v11094] = 0;
      int * v11021 = v10951->cache_age;
      v11021[v11094] = 1;
      int * v11023 = v10951->cache_age;
      int v11024 = v11023[v11094];
      int v11025 = v11023[v11068];
      int v11124 = v11025 + ((int)((unsigned int)(v11025 - v11024) >> 31));
      v11023[v11068] = v11124;
      int * v11027 = v10951->cache_age;
      int v11028 = v11027[v11069];
      int v11126 = v11028 + ((int)((unsigned int)(v11028 - v11024) >> 31));
      v11027[v11069] = v11126;
      int * v11030 = v10951->cache_age;
      v11030[v11094] = 0;
      v11033 = v11094;
    }
    int * v11034 = v10951->cache_vals;
    int v11129 = v11033 * 2;
    int v11035 = v11034[v11129];
    int v11130 = (v11033 * 2) + 1;
    int v11036 = v11034[v11130];
    int v11131 = (((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v10975 + ((~(((v10977 ^ -1) | (-(v10977 ^ -1))) >> 31)) & 2)) - (v10978 + ((~(((v10979 ^ -1) | (-(v10979 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11034[v11131] = v11035;
    int * v11038 = v10951->cache_vals;
    int v11134 = ((((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v10975 + ((~(((v10977 ^ -1) | (-(v10977 ^ -1))) >> 31)) & 2)) - (v10978 + ((~(((v10979 ^ -1) | (-(v10979 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11038[v11134] = v11036;
    int * v11040 = v10951->cache_tags;
    int v11137 = ((((int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v10975 + ((~(((v10977 ^ -1) | (-(v10977 ^ -1))) >> 31)) & 2)) - (v10978 + ((~(((v10979 ^ -1) | (-(v10979 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11138 = (int)((unsigned int)((int)((unsigned int)(v10955 + 44) >> 2)) >> 1);
    v11040[v11137] = v11138;
    int * v11042 = v10951->cache_dirty;
    v11042[v11137] = 0;
    int * v11044 = v10951->cache_age;
    v11044[v11137] = 1;
    int * v11046 = v10951->cache_age;
    int v11047 = v11046[v11137];
    int v11048 = v11046[v11066];
    int v11144 = v11048 + ((int)((unsigned int)(v11048 - v11047) >> 31));
    v11046[v11066] = v11144;
    int * v11050 = v10951->cache_age;
    int v11051 = v11050[v11067];
    int v11146 = v11051 + ((int)((unsigned int)(v11051 - v11047) >> 31));
    v11050[v11067] = v11146;
    int * v11053 = v10951->cache_age;
    v11053[v11137] = 0;
    v11056 = v11137;
  }
  int v11149 = (v11056 * 2) + (((int)((unsigned int)(v10955 + 44) >> 2)) & 1);
  int v11057 = v10963[v11149];
  int * v11058 = v10951->regs;
  v11058[8] = v11057;
  struct StateT * v11060 = slot_213(v10951);
  return v11060;
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

struct StateT * slot_436(struct StateT * v16213) {
  int * v16214 = v16213->saved_regs;
  int * v16215 = v16213->regs;
  int v16216 = v16215[14];
  v16214[14] = v16216;
  int v16218 = v16213->timer;
  int v16230 = v16218 + 1;
  v16213->timer = v16230;
  int * v16220 = v16213->regs;
  int v16221 = v16220[14];
  int v16222 = v16220[21];
  int v16233 = v16221 ^ v16222;
  v16220[14] = v16233;
  struct StateT * v16224 = slot_437(v16213);
  return v16224;
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

struct StateT * slot_499(struct StateT * v17246) {
  int v17247 = v17246->timer;
  int v17255 = v17247 + 1;
  v17246->timer = v17255;
  int * v17249 = v17246->regs;
  int v17250 = v17249[17];
  int v17251 = v17249[14];
  int v17260 = v17250 + v17251;
  v17249[20] = v17260;
  struct StateT * v17253 = slot_500(v17246);
  return v17253;
}

struct StateT * slot_359(struct StateT * v14927) {
  int v14928 = v14927->timer;
  int v14936 = v14928 + 1;
  v14927->timer = v14936;
  int * v14930 = v14927->regs;
  int v14931 = v14930[18];
  int v14932 = v14930[6];
  int v14941 = v14931 + v14932;
  v14930[22] = v14941;
  struct StateT * v14934 = slot_360(v14927);
  return v14934;
}

struct StateT * slot_514(struct StateT * v17478) {
  int v17479 = v17478->timer;
  int v17487 = v17479 + 1;
  v17478->timer = v17487;
  int * v17481 = v17478->regs;
  int v17482 = v17481[23];
  int v17483 = v17481[24];
  int v17491 = v17482 | v17483;
  v17481[23] = v17491;
  struct StateT * v17485 = slot_515(v17478);
  return v17485;
}

struct StateT * slot_296(struct StateT * v13941) {
  int v13942 = v13941->timer;
  int v13950 = v13942 + 1;
  v13941->timer = v13950;
  int * v13944 = v13941->regs;
  int v13945 = v13944[31];
  int v13946 = v13944[23];
  int v13954 = v13945 ^ v13946;
  v13944[31] = v13954;
  struct StateT * v13948 = slot_297(v13941);
  return v13948;
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

struct StateT * slot_300(struct StateT * v14008) {
  int v14009 = v14008->timer;
  int v14017 = v14009 + 1;
  v14008->timer = v14017;
  int * v14011 = v14008->regs;
  int v14012 = v14011[31];
  int v14013 = v14011[19];
  int v14022 = v14012 + v14013;
  v14011[23] = v14022;
  struct StateT * v14015 = slot_301(v14008);
  return v14015;
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

struct StateT * slot_282(struct StateT * v13728) {
  int v13729 = v13728->timer;
  int v13736 = v13729 + 1;
  v13728->timer = v13736;
  int * v13731 = v13728->regs;
  int v13732 = v13731[20];
  int v13739 = v13732 << 18;
  v13731[20] = v13739;
  struct StateT * v13734 = slot_283(v13728);
  return v13734;
}

struct StateT * slot_309(struct StateT * v14144) {
  int v14145 = v14144->timer;
  int v14153 = v14145 + 1;
  v14144->timer = v14153;
  int * v14147 = v14144->regs;
  int v14148 = v14147[22];
  int v14149 = v14147[24];
  int v14157 = v14148 | v14149;
  v14147[22] = v14157;
  struct StateT * v14151 = slot_310(v14144);
  return v14151;
}

struct StateT * slot_362(struct StateT * v14976) {
  int v14977 = v14976->timer;
  int v14984 = v14977 + 1;
  v14976->timer = v14984;
  int * v14979 = v14976->regs;
  int v14980 = v14979[20];
  int v14987 = v14980 << 18;
  v14979[20] = v14987;
  struct StateT * v14982 = slot_363(v14976);
  return v14982;
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

struct StateT * slot_283(struct StateT * v13742) {
  int v13743 = v13742->timer;
  int v13751 = v13743 + 1;
  v13742->timer = v13751;
  int * v13745 = v13742->regs;
  int v13746 = v13745[20];
  int v13747 = v13745[24];
  int v13755 = v13746 | v13747;
  v13745[20] = v13755;
  struct StateT * v13749 = slot_284(v13742);
  return v13749;
}

struct StateT * slot_346(struct StateT * v14723) {
  int v14724 = v14723->timer;
  int v14732 = v14724 + 1;
  v14723->timer = v14732;
  int * v14726 = v14723->regs;
  int v14727 = v14726[21];
  int v14728 = v14726[24];
  int v14736 = v14727 | v14728;
  v14726[21] = v14736;
  struct StateT * v14730 = slot_347(v14723);
  return v14730;
}

struct StateT * slot_516(struct StateT * v17510) {
  int v17511 = v17510->timer;
  int v17519 = v17511 + 1;
  v17510->timer = v17519;
  int * v17513 = v17510->regs;
  int v17514 = v17513[9];
  int v17515 = v17513[21];
  int v17523 = v17514 ^ v17515;
  v17513[9] = v17523;
  struct StateT * v17517 = slot_517(v17510);
  return v17517;
}

struct StateT * slot_274(struct StateT * v13597) {
  int v13598 = v13597->timer;
  int v13606 = v13598 + 1;
  v13597->timer = v13606;
  int * v13600 = v13597->regs;
  int v13601 = v13600[14];
  int v13602 = v13600[21];
  int v13610 = v13601 ^ v13602;
  v13600[14] = v13610;
  struct StateT * v13604 = slot_275(v13597);
  return v13604;
}

struct StateT * slot_535(struct StateT * v17806) {
  int v17807 = v17806->timer;
  int v17815 = v17807 + 1;
  v17806->timer = v17815;
  int * v17809 = v17806->regs;
  int v17810 = v17809[30];
  int v17811 = v17809[20];
  int v17819 = v17810 ^ v17811;
  v17809[30] = v17819;
  struct StateT * v17813 = slot_536(v17806);
  return v17813;
}

struct StateT * slot_318(struct StateT * v14286) {
  int v14287 = v14286->timer;
  int v14295 = v14287 + 1;
  v14286->timer = v14295;
  int * v14289 = v14286->regs;
  int v14290 = v14289[12];
  int v14291 = v14289[29];
  int v14300 = v14290 + v14291;
  v14289[21] = v14300;
  struct StateT * v14293 = slot_319(v14286);
  return v14293;
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

struct StateT * slot_255(struct StateT * v13301) {
  int v13302 = v13301->timer;
  int v13310 = v13302 + 1;
  v13301->timer = v13310;
  int * v13304 = v13301->regs;
  int v13305 = v13304[17];
  int v13306 = v13304[22];
  int v13314 = v13305 ^ v13306;
  v13304[17] = v13314;
  struct StateT * v13308 = slot_256(v13301);
  return v13308;
}

struct StateT * slot_540(struct StateT * v17891) {
  int * v17892 = v17891->regs;
  int v17893 = v17892[11];
  int * v17894 = v17891->saved_regs;
  int v17895 = v17894[13];
  bool v17996 = (v17893 ^ -2147483648) >= (v17895 ^ -2147483648);
  struct StateT * v17990;
  if (v17996) {
    struct StateT * v17896 = slot_378(v17891);
    v17990 = v17896;
  } else {
    int v17898 = v17891->timer;
    int v17999 = v17898 + 15;
    v17891->timer = v17999;
    int * v17900 = v17891->saved_regs;
    int v17901 = v17900[20];
    int * v17902 = v17891->regs;
    v17902[20] = v17901;
    int * v17904 = v17891->saved_regs;
    int v17905 = v17904[21];
    int * v17906 = v17891->regs;
    v17906[21] = v17905;
    int * v17908 = v17891->saved_regs;
    int v17909 = v17908[22];
    int * v17910 = v17891->regs;
    v17910[22] = v17909;
    int * v17912 = v17891->saved_regs;
    int v17913 = v17912[23];
    int * v17914 = v17891->regs;
    v17914[23] = v17913;
    int * v17916 = v17891->saved_regs;
    int v17917 = v17916[24];
    int * v17918 = v17891->regs;
    v17918[24] = v17917;
    int * v17920 = v17891->saved_regs;
    int v17921 = v17920[9];
    int * v17922 = v17891->regs;
    v17922[9] = v17921;
    int * v17924 = v17891->saved_regs;
    int v17925 = v17924[18];
    int * v17926 = v17891->regs;
    v17926[18] = v17925;
    int * v17928 = v17891->saved_regs;
    int v17929 = v17928[19];
    int * v17930 = v17891->regs;
    v17930[19] = v17929;
    int * v17932 = v17891->saved_regs;
    int v17933 = v17932[8];
    int * v17934 = v17891->regs;
    v17934[8] = v17933;
    int * v17936 = v17891->saved_regs;
    int v17937 = v17936[6];
    int * v17938 = v17891->regs;
    v17938[6] = v17937;
    int * v17940 = v17891->saved_regs;
    int v17941 = v17940[7];
    int * v17942 = v17891->regs;
    v17942[7] = v17941;
    int * v17944 = v17891->saved_regs;
    int v17945 = v17944[17];
    int * v17946 = v17891->regs;
    v17946[17] = v17945;
    int * v17948 = v17891->saved_regs;
    int v17949 = v17948[5];
    int * v17950 = v17891->regs;
    v17950[5] = v17949;
    int * v17952 = v17891->saved_regs;
    int v17953 = v17952[16];
    int * v17954 = v17891->regs;
    v17954[16] = v17953;
    int * v17956 = v17891->saved_regs;
    int v17957 = v17956[14];
    int * v17958 = v17891->regs;
    v17958[14] = v17957;
    int * v17960 = v17891->saved_regs;
    int v17961 = v17960[12];
    int * v17962 = v17891->regs;
    v17962[12] = v17961;
    int * v17964 = v17891->saved_regs;
    int v17965 = v17964[15];
    int * v17966 = v17891->regs;
    v17966[15] = v17965;
    int * v17968 = v17891->saved_regs;
    int v17969 = v17968[30];
    int * v17970 = v17891->regs;
    v17970[30] = v17969;
    int * v17972 = v17891->saved_regs;
    int v17973 = v17972[29];
    int * v17974 = v17891->regs;
    v17974[29] = v17973;
    int * v17976 = v17891->saved_regs;
    int v17977 = v17976[28];
    int * v17978 = v17891->regs;
    v17978[28] = v17977;
    int * v17980 = v17891->saved_regs;
    int v17981 = v17980[31];
    int * v17982 = v17891->regs;
    v17982[31] = v17981;
    int * v17984 = v17891->saved_regs;
    int v17985 = v17984[13];
    int * v17986 = v17891->regs;
    v17986[13] = v17985;
    struct StateT * v17988 = slot_195(v17891);
    v17990 = v17988;
  }
  return v17990;
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

struct StateT * slot_368(struct StateT * v15066) {
  int v15067 = v15066->timer;
  int v15074 = v15067 + 1;
  v15066->timer = v15074;
  int * v15069 = v15066->regs;
  int v15070 = v15069[22];
  int v15077 = v15070 << 18;
  v15069[22] = v15077;
  struct StateT * v15072 = slot_369(v15066);
  return v15072;
}

struct StateT * slot_265(struct StateT * v13461) {
  int v13462 = v13461->timer;
  int v13469 = v13462 + 1;
  v13461->timer = v13469;
  int * v13464 = v13461->regs;
  int v13465 = v13464[21];
  int v13472 = v13465 << 13;
  v13464[21] = v13472;
  struct StateT * v13467 = slot_266(v13461);
  return v13467;
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

struct StateT * slot_257(struct StateT * v13333) {
  int v13334 = v13333->timer;
  int v13342 = v13334 + 1;
  v13333->timer = v13342;
  int * v13336 = v13333->regs;
  int v13337 = v13336[6];
  int v13338 = v13336[9];
  int v13347 = v13337 + v13338;
  v13336[20] = v13347;
  struct StateT * v13340 = slot_258(v13333);
  return v13340;
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

struct StateT * slot_327(struct StateT * v14427) {
  int v14428 = v14427->timer;
  int v14435 = v14428 + 1;
  v14427->timer = v14435;
  int * v14430 = v14427->regs;
  int v14431 = v14430[22];
  int v14439 = (int)((unsigned int)v14431 >> 23);
  v14430[24] = v14439;
  struct StateT * v14433 = slot_328(v14427);
  return v14433;
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

struct StateT * slot_396(struct StateT * v15533) {
  int * v15534 = v15533->saved_regs;
  int * v15535 = v15533->regs;
  int v15536 = v15535[18];
  v15534[18] = v15536;
  int v15538 = v15533->timer;
  int v15550 = v15538 + 1;
  v15533->timer = v15550;
  int * v15540 = v15533->regs;
  int v15541 = v15540[18];
  int v15542 = v15540[21];
  int v15553 = v15541 ^ v15542;
  v15540[18] = v15553;
  struct StateT * v15544 = slot_397(v15533);
  return v15544;
}

struct StateT * slot_528(struct StateT * v17700) {
  int v17701 = v17700->timer;
  int v17709 = v17701 + 1;
  v17700->timer = v17709;
  int * v17703 = v17700->regs;
  int v17704 = v17703[21];
  int v17705 = v17703[24];
  int v17713 = v17704 | v17705;
  v17703[21] = v17713;
  struct StateT * v17707 = slot_529(v17700);
  return v17707;
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

struct StateT * slot_526(struct StateT * v17671) {
  int v17672 = v17671->timer;
  int v17679 = v17672 + 1;
  v17671->timer = v17679;
  int * v17674 = v17671->regs;
  int v17675 = v17674[21];
  int v17683 = (int)((unsigned int)v17675 >> 14);
  v17674[24] = v17683;
  struct StateT * v17677 = slot_527(v17671);
  return v17677;
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

struct StateT * slot_276(struct StateT * v13629) {
  int v13630 = v13629->timer;
  int v13638 = v13630 + 1;
  v13629->timer = v13638;
  int * v13632 = v13629->regs;
  int v13633 = v13632[15];
  int v13634 = v13632[23];
  int v13642 = v13633 ^ v13634;
  v13632[15] = v13642;
  struct StateT * v13636 = slot_277(v13629);
  return v13636;
}

struct StateT * slot_290(struct StateT * v13848) {
  int v13849 = v13848->timer;
  int v13856 = v13849 + 1;
  v13848->timer = v13856;
  int * v13851 = v13848->regs;
  int v13852 = v13851[23];
  int v13860 = (int)((unsigned int)v13852 >> 14);
  v13851[24] = v13860;
  struct StateT * v13854 = slot_291(v13848);
  return v13854;
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

struct StateT * slot_266(struct StateT * v13475) {
  int v13476 = v13475->timer;
  int v13484 = v13476 + 1;
  v13475->timer = v13484;
  int * v13478 = v13475->regs;
  int v13479 = v13478[21];
  int v13480 = v13478[24];
  int v13488 = v13479 | v13480;
  v13478[21] = v13488;
  struct StateT * v13482 = slot_267(v13475);
  return v13482;
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

struct StateT * slot_234(struct StateT * v12973) {
  int v12974 = v12973->timer;
  int v12982 = v12974 + 1;
  v12973->timer = v12982;
  int * v12976 = v12973->regs;
  int v12977 = v12976[18];
  int v12978 = v12976[21];
  int v12986 = v12977 ^ v12978;
  v12976[18] = v12986;
  struct StateT * v12980 = slot_235(v12973);
  return v12980;
}

struct StateT * slot_471(struct StateT * v16809) {
  int v16810 = v16809->timer;
  int v16818 = v16810 + 1;
  v16809->timer = v16818;
  int * v16812 = v16809->regs;
  int v16813 = v16812[22];
  int v16814 = v16812[24];
  int v16822 = v16813 | v16814;
  v16812[22] = v16822;
  struct StateT * v16816 = slot_472(v16809);
  return v16816;
}

struct StateT * slot_419(struct StateT * v15942) {
  int v15943 = v15942->timer;
  int v15951 = v15943 + 1;
  v15942->timer = v15951;
  int * v15945 = v15942->regs;
  int v15946 = v15945[6];
  int v15947 = v15945[9];
  int v15956 = v15946 + v15947;
  v15945[20] = v15956;
  struct StateT * v15949 = slot_420(v15942);
  return v15949;
}

struct StateT * slot_218(struct StateT * v11812) {
  int v11813 = v11812->timer;
  int v11821 = v11813 + 1;
  v11812->timer = v11821;
  int * v11815 = v11812->regs;
  int v11816 = v11815[21];
  int v11817 = v11815[24];
  int v11825 = v11816 | v11817;
  v11815[21] = v11825;
  struct StateT * v11819 = slot_220(v11812);
  return v11819;
}

struct StateT * slot_202(struct StateT * v9611) {
  int v9612 = v9611->timer;
  int v9620 = v9612 + 1;
  v9611->timer = v9620;
  int * v9614 = v9611->regs;
  int v9615 = v9614[29];
  int v9616 = v9614[14];
  int v9625 = v9615 + v9616;
  v9614[21] = v9625;
  struct StateT * v9618 = slot_204(v9611);
  return v9618;
}

struct StateT * slot_336(struct StateT * v14565) {
  int v14566 = v14565->timer;
  int v14574 = v14566 + 1;
  v14565->timer = v14574;
  int * v14568 = v14565->regs;
  int v14569 = v14568[7];
  int v14570 = v14568[23];
  int v14578 = v14569 ^ v14570;
  v14568[7] = v14578;
  struct StateT * v14572 = slot_337(v14565);
  return v14572;
}

struct StateT * slot_230(struct StateT * v12936) {
  int v12937 = v12936->timer;
  int v12945 = v12937 + 1;
  v12936->timer = v12945;
  int * v12939 = v12936->regs;
  int v12940 = v12939[23];
  int v12941 = v12939[24];
  int v12949 = v12940 | v12941;
  v12939[23] = v12949;
  struct StateT * v12943 = slot_232(v12936);
  return v12943;
}

struct StateT * slot_294(struct StateT * v13909) {
  int v13910 = v13909->timer;
  int v13918 = v13910 + 1;
  v13909->timer = v13918;
  int * v13912 = v13909->regs;
  int v13913 = v13912[29];
  int v13914 = v13912[21];
  int v13922 = v13913 ^ v13914;
  v13912[29] = v13922;
  struct StateT * v13916 = slot_295(v13909);
  return v13916;
}

struct StateT * slot_408(struct StateT * v15744) {
  int v15745 = v15744->timer;
  int v15753 = v15745 + 1;
  v15744->timer = v15753;
  int * v15747 = v15744->regs;
  int v15748 = v15747[21];
  int v15749 = v15747[24];
  int v15757 = v15748 | v15749;
  v15747[21] = v15757;
  struct StateT * v15751 = slot_409(v15744);
  return v15751;
}

struct StateT * slot_342(struct StateT * v14664) {
  int v14665 = v14664->timer;
  int v14672 = v14665 + 1;
  v14664->timer = v14672;
  int * v14667 = v14664->regs;
  int v14668 = v14667[20];
  int v14675 = v14668 << 13;
  v14667[20] = v14675;
  struct StateT * v14670 = slot_343(v14664);
  return v14670;
}

struct StateT * slot_488(struct StateT * v17076) {
  int v17077 = v17076->timer;
  int v17085 = v17077 + 1;
  v17076->timer = v17085;
  int * v17079 = v17076->regs;
  int v17080 = v17079[21];
  int v17081 = v17079[24];
  int v17089 = v17080 | v17081;
  v17079[21] = v17089;
  struct StateT * v17083 = slot_489(v17076);
  return v17083;
}

struct StateT * slot_439(struct StateT * v16282) {
  int v16283 = v16282->timer;
  int v16291 = v16283 + 1;
  v16282->timer = v16291;
  int * v16285 = v16282->regs;
  int v16286 = v16285[16];
  int v16287 = v16285[6];
  int v16296 = v16286 + v16287;
  v16285[20] = v16296;
  struct StateT * v16289 = slot_440(v16282);
  return v16289;
}

struct StateT * slot_389(struct StateT * v15420) {
  int v15421 = v15420->timer;
  int v15428 = v15421 + 1;
  v15420->timer = v15428;
  int * v15423 = v15420->regs;
  int v15424 = v15423[22];
  int v15432 = (int)((unsigned int)v15424 >> 25);
  v15423[24] = v15432;
  struct StateT * v15426 = slot_390(v15420);
  return v15426;
}

struct StateT * slot_479(struct StateT * v16934) {
  int v16935 = v16934->timer;
  int v16943 = v16935 + 1;
  v16934->timer = v16943;
  int * v16937 = v16934->regs;
  int v16938 = v16937[14];
  int v16939 = v16937[30];
  int v16948 = v16938 + v16939;
  v16937[20] = v16948;
  struct StateT * v16941 = slot_480(v16934);
  return v16941;
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

struct StateT * slot_483(struct StateT * v17002) {
  int v17003 = v17002->timer;
  int v17010 = v17003 + 1;
  v17002->timer = v17010;
  int * v17005 = v17002->regs;
  int v17006 = v17005[20];
  int v17014 = (int)((unsigned int)v17006 >> 23);
  v17005[24] = v17014;
  struct StateT * v17008 = slot_484(v17002);
  return v17008;
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

struct StateT * slot_425(struct StateT * v16039) {
  int v16040 = v16039->timer;
  int v16048 = v16040 + 1;
  v16039->timer = v16048;
  int * v16042 = v16039->regs;
  int v16043 = v16042[20];
  int v16044 = v16042[24];
  int v16052 = v16043 | v16044;
  v16042[20] = v16052;
  struct StateT * v16046 = slot_426(v16039);
  return v16046;
}

struct StateT * slot_443(struct StateT * v16350) {
  int v16351 = v16350->timer;
  int v16358 = v16351 + 1;
  v16350->timer = v16358;
  int * v16353 = v16350->regs;
  int v16354 = v16353[20];
  int v16362 = (int)((unsigned int)v16354 >> 14);
  v16353[24] = v16362;
  struct StateT * v16356 = slot_444(v16350);
  return v16356;
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

struct StateT * slot_534(struct StateT * v17790) {
  int v17791 = v17790->timer;
  int v17799 = v17791 + 1;
  v17790->timer = v17799;
  int * v17793 = v17790->regs;
  int v17794 = v17793[23];
  int v17795 = v17793[24];
  int v17803 = v17794 | v17795;
  v17793[23] = v17803;
  struct StateT * v17797 = slot_535(v17790);
  return v17797;
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

struct StateT * slot_504(struct StateT * v17329) {
  int v17330 = v17329->timer;
  int v17337 = v17330 + 1;
  v17329->timer = v17337;
  int * v17332 = v17329->regs;
  int v17333 = v17332[20];
  int v17340 = v17333 << 13;
  v17332[20] = v17340;
  struct StateT * v17335 = slot_505(v17329);
  return v17335;
}

struct StateT * slot_512(struct StateT * v17449) {
  int v17450 = v17449->timer;
  int v17457 = v17450 + 1;
  v17449->timer = v17457;
  int * v17452 = v17449->regs;
  int v17453 = v17452[23];
  int v17461 = (int)((unsigned int)v17453 >> 19);
  v17452[24] = v17461;
  struct StateT * v17455 = slot_513(v17449);
  return v17455;
}

struct StateT * slot_496(struct StateT * v17198) {
  int v17199 = v17198->timer;
  int v17207 = v17199 + 1;
  v17198->timer = v17207;
  int * v17201 = v17198->regs;
  int v17202 = v17201[5];
  int v17203 = v17201[21];
  int v17211 = v17202 ^ v17203;
  v17201[5] = v17211;
  struct StateT * v17205 = slot_497(v17198);
  return v17205;
}

struct StateT * slot_494(struct StateT * v17166) {
  int v17167 = v17166->timer;
  int v17175 = v17167 + 1;
  v17166->timer = v17175;
  int * v17169 = v17166->regs;
  int v17170 = v17169[23];
  int v17171 = v17169[24];
  int v17179 = v17170 | v17171;
  v17169[23] = v17179;
  struct StateT * v17173 = slot_495(v17166);
  return v17173;
}

struct StateT * slot_242(struct StateT * v13104) {
  int v13105 = v13104->timer;
  int v13112 = v13105 + 1;
  v13104->timer = v13112;
  int * v13107 = v13104->regs;
  int v13108 = v13107[20];
  int v13115 = v13108 << 9;
  v13107[20] = v13115;
  struct StateT * v13110 = slot_243(v13104);
  return v13110;
}

struct StateT * slot_328(struct StateT * v14442) {
  int v14443 = v14442->timer;
  int v14450 = v14443 + 1;
  v14442->timer = v14450;
  int * v14445 = v14442->regs;
  int v14446 = v14445[22];
  int v14453 = v14446 << 9;
  v14445[22] = v14453;
  struct StateT * v14448 = slot_329(v14442);
  return v14448;
}

struct StateT * slot_402(struct StateT * v15653) {
  int v15654 = v15653->timer;
  int v15662 = v15654 + 1;
  v15653->timer = v15662;
  int * v15656 = v15653->regs;
  int v15657 = v15656[8];
  int v15658 = v15656[31];
  int v15667 = v15657 + v15658;
  v15656[23] = v15667;
  struct StateT * v15660 = slot_403(v15653);
  return v15660;
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
  struct StateT * v9286 = slot_202(v9279);
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

struct StateT * slot_527(struct StateT * v17686) {
  int v17687 = v17686->timer;
  int v17694 = v17687 + 1;
  v17686->timer = v17694;
  int * v17689 = v17686->regs;
  int v17690 = v17689[21];
  int v17697 = v17690 << 18;
  v17689[21] = v17697;
  struct StateT * v17692 = slot_528(v17686);
  return v17692;
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

struct StateT * slot_334(struct StateT * v14533) {
  int v14534 = v14533->timer;
  int v14542 = v14534 + 1;
  v14533->timer = v14542;
  int * v14536 = v14533->regs;
  int v14537 = v14536[5];
  int v14538 = v14536[21];
  int v14546 = v14537 ^ v14538;
  v14536[5] = v14546;
  struct StateT * v14540 = slot_335(v14533);
  return v14540;
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

struct StateT * slot_235(struct StateT * v12989) {
  int v12990 = v12989->timer;
  int v12998 = v12990 + 1;
  v12989->timer = v12998;
  int * v12992 = v12989->regs;
  int v12993 = v12992[19];
  int v12994 = v12992[22];
  int v13002 = v12993 ^ v12994;
  v12992[19] = v13002;
  struct StateT * v12996 = slot_236(v12989);
  return v12996;
}

struct StateT * slot_275(struct StateT * v13613) {
  int v13614 = v13613->timer;
  int v13622 = v13614 + 1;
  v13613->timer = v13622;
  int * v13616 = v13613->regs;
  int v13617 = v13616[12];
  int v13618 = v13616[22];
  int v13626 = v13617 ^ v13618;
  v13616[12] = v13626;
  struct StateT * v13620 = slot_276(v13613);
  return v13620;
}

struct StateT * slot_329(struct StateT * v14456) {
  int v14457 = v14456->timer;
  int v14465 = v14457 + 1;
  v14456->timer = v14465;
  int * v14459 = v14456->regs;
  int v14460 = v14459[22];
  int v14461 = v14459[24];
  int v14469 = v14460 | v14461;
  v14459[22] = v14469;
  struct StateT * v14463 = slot_330(v14456);
  return v14463;
}

struct StateT * slot_428(struct StateT * v16084) {
  int v16085 = v16084->timer;
  int v16093 = v16085 + 1;
  v16084->timer = v16093;
  int * v16087 = v16084->regs;
  int v16088 = v16087[21];
  int v16089 = v16087[24];
  int v16097 = v16088 | v16089;
  v16087[21] = v16097;
  struct StateT * v16091 = slot_429(v16084);
  return v16091;
}

struct StateT * slot_395(struct StateT * v15510) {
  int * v15511 = v15510->saved_regs;
  int * v15512 = v15510->regs;
  int v15513 = v15512[9];
  v15511[9] = v15513;
  int v15515 = v15510->timer;
  int v15527 = v15515 + 1;
  v15510->timer = v15527;
  int * v15517 = v15510->regs;
  int v15518 = v15517[9];
  int v15519 = v15517[20];
  int v15530 = v15518 ^ v15519;
  v15517[9] = v15530;
  struct StateT * v15521 = slot_396(v15510);
  return v15521;
}

struct StateT * slot_345(struct StateT * v14709) {
  int v14710 = v14709->timer;
  int v14717 = v14710 + 1;
  v14709->timer = v14717;
  int * v14712 = v14709->regs;
  int v14713 = v14712[21];
  int v14720 = v14713 << 13;
  v14712[21] = v14720;
  struct StateT * v14715 = slot_346(v14709);
  return v14715;
}

struct StateT * slot_298(struct StateT * v13974) {
  int v13975 = v13974->timer;
  int v13983 = v13975 + 1;
  v13974->timer = v13983;
  int * v13977 = v13974->regs;
  int v13978 = v13977[29];
  int v13979 = v13977[9];
  int v13988 = v13978 + v13979;
  v13977[21] = v13988;
  struct StateT * v13981 = slot_299(v13974);
  return v13981;
}

struct StateT * slot_414(struct StateT * v15834) {
  int v15835 = v15834->timer;
  int v15843 = v15835 + 1;
  v15834->timer = v15843;
  int * v15837 = v15834->regs;
  int v15838 = v15837[23];
  int v15839 = v15837[24];
  int v15847 = v15838 | v15839;
  v15837[23] = v15847;
  struct StateT * v15841 = slot_415(v15834);
  return v15841;
}

struct StateT * slot_364(struct StateT * v15006) {
  int v15007 = v15006->timer;
  int v15014 = v15007 + 1;
  v15006->timer = v15014;
  int * v15009 = v15006->regs;
  int v15010 = v15009[21];
  int v15018 = (int)((unsigned int)v15010 >> 14);
  v15009[24] = v15018;
  struct StateT * v15012 = slot_365(v15006);
  return v15012;
}

struct StateT * slot_356(struct StateT * v14877) {
  int v14878 = v14877->timer;
  int v14886 = v14878 + 1;
  v14877->timer = v14886;
  int * v14880 = v14877->regs;
  int v14881 = v14880[19];
  int v14882 = v14880[23];
  int v14890 = v14881 ^ v14882;
  v14880[19] = v14890;
  struct StateT * v14884 = slot_357(v14877);
  return v14884;
}

struct StateT * slot_253(struct StateT * v13269) {
  int v13270 = v13269->timer;
  int v13278 = v13270 + 1;
  v13269->timer = v13278;
  int * v13272 = v13269->regs;
  int v13273 = v13272[6];
  int v13274 = v13272[20];
  int v13282 = v13273 ^ v13274;
  v13272[6] = v13282;
  struct StateT * v13276 = slot_254(v13269);
  return v13276;
}

struct StateT * slot_434(struct StateT * v16174) {
  int v16175 = v16174->timer;
  int v16183 = v16175 + 1;
  v16174->timer = v16183;
  int * v16177 = v16174->regs;
  int v16178 = v16177[23];
  int v16179 = v16177[24];
  int v16187 = v16178 | v16179;
  v16177[23] = v16187;
  struct StateT * v16181 = slot_435(v16174);
  return v16181;
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

struct StateT * slot_522(struct StateT * v17609) {
  int v17610 = v17609->timer;
  int v17618 = v17610 + 1;
  v17609->timer = v17618;
  int * v17612 = v17609->regs;
  int v17613 = v17612[19];
  int v17614 = v17612[7];
  int v17623 = v17613 + v17614;
  v17612[23] = v17623;
  struct StateT * v17616 = slot_523(v17609);
  return v17616;
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

struct StateT * slot_503(struct StateT * v17314) {
  int v17315 = v17314->timer;
  int v17322 = v17315 + 1;
  v17314->timer = v17322;
  int * v17317 = v17314->regs;
  int v17318 = v17317[20];
  int v17326 = (int)((unsigned int)v17318 >> 19);
  v17317[24] = v17326;
  struct StateT * v17320 = slot_504(v17314);
  return v17320;
}

struct StateT * slot_390(struct StateT * v15435) {
  int v15436 = v15435->timer;
  int v15443 = v15436 + 1;
  v15435->timer = v15443;
  int * v15438 = v15435->regs;
  int v15439 = v15438[22];
  int v15446 = v15439 << 7;
  v15438[22] = v15446;
  struct StateT * v15441 = slot_391(v15435);
  return v15441;
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

struct StateT * slot_386(struct StateT * v15375) {
  int v15376 = v15375->timer;
  int v15383 = v15376 + 1;
  v15375->timer = v15383;
  int * v15378 = v15375->regs;
  int v15379 = v15378[21];
  int v15387 = (int)((unsigned int)v15379 >> 25);
  v15378[24] = v15387;
  struct StateT * v15381 = slot_387(v15375);
  return v15381;
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

struct StateT * slot_219(struct StateT * v11828) {
  int v11829 = v11828->timer;
  int v11939 = v11829 + 1;
  v11828->timer = v11939;
  int * v11831 = v11828->regs;
  int v11832 = v11831[2];
  int * v11833 = v11828->cache_tags;
  int v11943 = (((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2;
  int v11834 = v11833[v11943];
  int v11944 = ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11835 = v11833[v11944];
  int v11945 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2);
  int v11836 = v11833[v11945];
  int v11946 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11837 = v11833[v11946];
  int v11838 = v11828->timer;
  int v11947 = v11838 + ((100 ^ (((~(((v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11834 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11834 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11828->timer = v11947;
  int * v11840 = v11828->cache_vals;
  bool v11948 = !(((~(((v11834 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11834 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v11933;
  if (v11948) {
    int * v11841 = v11828->cache_age;
    int v11950 = ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11835 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v11842 = v11841[v11950];
    int v11843 = v11841[v11943];
    int v11951 = v11843 + ((int)((unsigned int)(v11843 - v11842) >> 31));
    v11841[v11943] = v11951;
    int * v11845 = v11828->cache_age;
    int v11846 = v11845[v11944];
    int v11953 = v11846 + ((int)((unsigned int)(v11846 - v11842) >> 31));
    v11845[v11944] = v11953;
    int * v11848 = v11828->cache_age;
    v11848[v11950] = 0;
    v11933 = v11950;
  } else {
    int * v11851 = v11828->cache_age;
    int v11957 = (((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2;
    int v11852 = v11851[v11957];
    int * v11853 = v11828->cache_tags;
    int v11854 = v11853[v11957];
    int v11855 = v11851[v11944];
    int v11856 = v11853[v11944];
    bool v11959 = !(((~(((v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11836 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v11910;
    if (v11959) {
      int * v11857 = v11828->cache_age;
      int v11961 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))) | (-(v11837 ^ ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v11858 = v11857[v11961];
      int v11859 = v11857[v11945];
      int v11962 = v11859 + ((int)((unsigned int)(v11859 - v11858) >> 31));
      v11857[v11945] = v11962;
      int * v11861 = v11828->cache_age;
      int v11862 = v11861[v11946];
      int v11964 = v11862 + ((int)((unsigned int)(v11862 - v11858) >> 31));
      v11861[v11946] = v11964;
      int * v11864 = v11828->cache_age;
      v11864[v11961] = 0;
      v11910 = v11961;
    } else {
      int * v11867 = v11828->cache_age;
      int v11968 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2);
      int v11868 = v11867[v11968];
      int * v11869 = v11828->cache_tags;
      int v11870 = v11869[v11968];
      int v11871 = v11867[v11946];
      int v11872 = v11869[v11946];
      int * v11873 = v11828->cache_dirty;
      int v11971 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11868 + ((~(((v11870 ^ -1) | (-(v11870 ^ -1))) >> 31)) & 2)) - (v11871 + ((~(((v11872 ^ -1) | (-(v11872 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11874 = v11873[v11971];
      bool v11972 = !(v11874 == 0);
      if (v11972) {
        int * v11875 = v11828->cache_tags;
        int v11876 = v11875[v11971];
        int * v11877 = v11828->cache_vals;
        int v11975 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11868 + ((~(((v11870 ^ -1) | (-(v11870 ^ -1))) >> 31)) & 2)) - (v11871 + ((~(((v11872 ^ -1) | (-(v11872 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11878 = v11877[v11975];
        int v11976 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11868 + ((~(((v11870 ^ -1) | (-(v11870 ^ -1))) >> 31)) & 2)) - (v11871 + ((~(((v11872 ^ -1) | (-(v11872 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11879 = v11877[v11976];
        int * v11880 = v11828->mem;
        int v11978 = v11876 * 2;
        v11880[v11978] = v11878;
        int * v11882 = v11828->mem;
        int v11981 = (v11876 * 2) + 1;
        v11882[v11981] = v11879;
        ;
      } else {
        ;
      }
      int * v11887 = v11828->mem;
      int v11986 = ((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) * 2;
      int v11888 = v11887[v11986];
      int v11987 = (((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) * 2) + 1;
      int v11889 = v11887[v11987];
      int * v11890 = v11828->cache_vals;
      int v11989 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11868 + ((~(((v11870 ^ -1) | (-(v11870 ^ -1))) >> 31)) & 2)) - (v11871 + ((~(((v11872 ^ -1) | (-(v11872 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11890[v11989] = v11888;
      int * v11892 = v11828->cache_vals;
      int v11992 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11868 + ((~(((v11870 ^ -1) | (-(v11870 ^ -1))) >> 31)) & 2)) - (v11871 + ((~(((v11872 ^ -1) | (-(v11872 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11892[v11992] = v11889;
      int * v11894 = v11828->cache_tags;
      int v11995 = (int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1);
      v11894[v11971] = v11995;
      int * v11896 = v11828->cache_dirty;
      v11896[v11971] = 0;
      int * v11898 = v11828->cache_age;
      v11898[v11971] = 1;
      int * v11900 = v11828->cache_age;
      int v11901 = v11900[v11971];
      int v11902 = v11900[v11945];
      int v12001 = v11902 + ((int)((unsigned int)(v11902 - v11901) >> 31));
      v11900[v11945] = v12001;
      int * v11904 = v11828->cache_age;
      int v11905 = v11904[v11946];
      int v12003 = v11905 + ((int)((unsigned int)(v11905 - v11901) >> 31));
      v11904[v11946] = v12003;
      int * v11907 = v11828->cache_age;
      v11907[v11971] = 0;
      v11910 = v11971;
    }
    int * v11911 = v11828->cache_vals;
    int v12006 = v11910 * 2;
    int v11912 = v11911[v12006];
    int v12007 = (v11910 * 2) + 1;
    int v11913 = v11911[v12007];
    int v12008 = (((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11852 + ((~(((v11854 ^ -1) | (-(v11854 ^ -1))) >> 31)) & 2)) - (v11855 + ((~(((v11856 ^ -1) | (-(v11856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11911[v12008] = v11912;
    int * v11915 = v11828->cache_vals;
    int v12011 = ((((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11852 + ((~(((v11854 ^ -1) | (-(v11854 ^ -1))) >> 31)) & 2)) - (v11855 + ((~(((v11856 ^ -1) | (-(v11856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11915[v12011] = v11913;
    int * v11917 = v11828->cache_tags;
    int v12014 = ((((int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11852 + ((~(((v11854 ^ -1) | (-(v11854 ^ -1))) >> 31)) & 2)) - (v11855 + ((~(((v11856 ^ -1) | (-(v11856 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12015 = (int)((unsigned int)((int)((unsigned int)(v11832 + 28) >> 2)) >> 1);
    v11917[v12014] = v12015;
    int * v11919 = v11828->cache_dirty;
    v11919[v12014] = 0;
    int * v11921 = v11828->cache_age;
    v11921[v12014] = 1;
    int * v11923 = v11828->cache_age;
    int v11924 = v11923[v12014];
    int v11925 = v11923[v11943];
    int v12021 = v11925 + ((int)((unsigned int)(v11925 - v11924) >> 31));
    v11923[v11943] = v12021;
    int * v11927 = v11828->cache_age;
    int v11928 = v11927[v11944];
    int v12023 = v11928 + ((int)((unsigned int)(v11928 - v11924) >> 31));
    v11927[v11944] = v12023;
    int * v11930 = v11828->cache_age;
    v11930[v12014] = 0;
    v11933 = v12014;
  }
  int v12026 = (v11933 * 2) + (((int)((unsigned int)(v11832 + 28) >> 2)) & 1);
  int v11934 = v11840[v12026];
  int * v11935 = v11828->regs;
  v11935[20] = v11934;
  struct StateT * v11937 = slot_221(v11828);
  return v11937;
}

struct StateT * slot_338(struct StateT * v14598) {
  int v14599 = v14598->timer;
  int v14607 = v14599 + 1;
  v14598->timer = v14607;
  int * v14601 = v14598->regs;
  int v14602 = v14601[5];
  int v14603 = v14601[12];
  int v14612 = v14602 + v14603;
  v14601[21] = v14612;
  struct StateT * v14605 = slot_339(v14598);
  return v14605;
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

struct StateT * slot_366(struct StateT * v15035) {
  int v15036 = v15035->timer;
  int v15044 = v15036 + 1;
  v15035->timer = v15044;
  int * v15038 = v15035->regs;
  int v15039 = v15038[21];
  int v15040 = v15038[24];
  int v15048 = v15039 | v15040;
  v15038[21] = v15048;
  struct StateT * v15042 = slot_367(v15035);
  return v15042;
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

struct StateT * slot_438(struct StateT * v16259) {
  int * v16260 = v16259->saved_regs;
  int * v16261 = v16259->regs;
  int v16262 = v16261[15];
  v16260[15] = v16262;
  int v16264 = v16259->timer;
  int v16276 = v16264 + 1;
  v16259->timer = v16276;
  int * v16266 = v16259->regs;
  int v16267 = v16266[15];
  int v16268 = v16266[23];
  int v16279 = v16267 ^ v16268;
  v16266[15] = v16279;
  struct StateT * v16270 = slot_439(v16259);
  return v16270;
}

struct StateT * slot_333(struct StateT * v14517) {
  int v14518 = v14517->timer;
  int v14526 = v14518 + 1;
  v14517->timer = v14526;
  int * v14520 = v14517->regs;
  int v14521 = v14520[17];
  int v14522 = v14520[20];
  int v14530 = v14521 ^ v14522;
  v14520[17] = v14530;
  struct StateT * v14524 = slot_334(v14517);
  return v14524;
}

struct StateT * slot_221(struct StateT * v12047) {
  int v12048 = v12047->timer;
  int v12158 = v12048 + 1;
  v12047->timer = v12158;
  int * v12050 = v12047->regs;
  int v12051 = v12050[2];
  int * v12052 = v12047->cache_tags;
  int v12162 = (((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2;
  int v12053 = v12052[v12162];
  int v12163 = ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12054 = v12052[v12163];
  int v12164 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2);
  int v12055 = v12052[v12164];
  int v12165 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12056 = v12052[v12165];
  int v12057 = v12047->timer;
  int v12166 = v12057 + ((100 ^ (((~(((v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12053 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12053 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12047->timer = v12166;
  int * v12059 = v12047->cache_vals;
  bool v12167 = !(((~(((v12053 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12053 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v12152;
  if (v12167) {
    int * v12060 = v12047->cache_age;
    int v12169 = ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12054 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v12061 = v12060[v12169];
    int v12062 = v12060[v12162];
    int v12170 = v12062 + ((int)((unsigned int)(v12062 - v12061) >> 31));
    v12060[v12162] = v12170;
    int * v12064 = v12047->cache_age;
    int v12065 = v12064[v12163];
    int v12172 = v12065 + ((int)((unsigned int)(v12065 - v12061) >> 31));
    v12064[v12163] = v12172;
    int * v12067 = v12047->cache_age;
    v12067[v12169] = 0;
    v12152 = v12169;
  } else {
    int * v12070 = v12047->cache_age;
    int v12176 = (((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2;
    int v12071 = v12070[v12176];
    int * v12072 = v12047->cache_tags;
    int v12073 = v12072[v12176];
    int v12074 = v12070[v12163];
    int v12075 = v12072[v12163];
    bool v12178 = !(((~(((v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12055 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v12129;
    if (v12178) {
      int * v12076 = v12047->cache_age;
      int v12180 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))) | (-(v12056 ^ ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v12077 = v12076[v12180];
      int v12078 = v12076[v12164];
      int v12181 = v12078 + ((int)((unsigned int)(v12078 - v12077) >> 31));
      v12076[v12164] = v12181;
      int * v12080 = v12047->cache_age;
      int v12081 = v12080[v12165];
      int v12183 = v12081 + ((int)((unsigned int)(v12081 - v12077) >> 31));
      v12080[v12165] = v12183;
      int * v12083 = v12047->cache_age;
      v12083[v12180] = 0;
      v12129 = v12180;
    } else {
      int * v12086 = v12047->cache_age;
      int v12187 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2);
      int v12087 = v12086[v12187];
      int * v12088 = v12047->cache_tags;
      int v12089 = v12088[v12187];
      int v12090 = v12086[v12165];
      int v12091 = v12088[v12165];
      int * v12092 = v12047->cache_dirty;
      int v12190 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v12087 + ((~(((v12089 ^ -1) | (-(v12089 ^ -1))) >> 31)) & 2)) - (v12090 + ((~(((v12091 ^ -1) | (-(v12091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12093 = v12092[v12190];
      bool v12191 = !(v12093 == 0);
      if (v12191) {
        int * v12094 = v12047->cache_tags;
        int v12095 = v12094[v12190];
        int * v12096 = v12047->cache_vals;
        int v12194 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v12087 + ((~(((v12089 ^ -1) | (-(v12089 ^ -1))) >> 31)) & 2)) - (v12090 + ((~(((v12091 ^ -1) | (-(v12091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12097 = v12096[v12194];
        int v12195 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v12087 + ((~(((v12089 ^ -1) | (-(v12089 ^ -1))) >> 31)) & 2)) - (v12090 + ((~(((v12091 ^ -1) | (-(v12091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12098 = v12096[v12195];
        int * v12099 = v12047->mem;
        int v12197 = v12095 * 2;
        v12099[v12197] = v12097;
        int * v12101 = v12047->mem;
        int v12200 = (v12095 * 2) + 1;
        v12101[v12200] = v12098;
        ;
      } else {
        ;
      }
      int * v12106 = v12047->mem;
      int v12205 = ((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) * 2;
      int v12107 = v12106[v12205];
      int v12206 = (((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) * 2) + 1;
      int v12108 = v12106[v12206];
      int * v12109 = v12047->cache_vals;
      int v12208 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v12087 + ((~(((v12089 ^ -1) | (-(v12089 ^ -1))) >> 31)) & 2)) - (v12090 + ((~(((v12091 ^ -1) | (-(v12091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12109[v12208] = v12107;
      int * v12111 = v12047->cache_vals;
      int v12211 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v12087 + ((~(((v12089 ^ -1) | (-(v12089 ^ -1))) >> 31)) & 2)) - (v12090 + ((~(((v12091 ^ -1) | (-(v12091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12111[v12211] = v12108;
      int * v12113 = v12047->cache_tags;
      int v12214 = (int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1);
      v12113[v12190] = v12214;
      int * v12115 = v12047->cache_dirty;
      v12115[v12190] = 0;
      int * v12117 = v12047->cache_age;
      v12117[v12190] = 1;
      int * v12119 = v12047->cache_age;
      int v12120 = v12119[v12190];
      int v12121 = v12119[v12164];
      int v12220 = v12121 + ((int)((unsigned int)(v12121 - v12120) >> 31));
      v12119[v12164] = v12220;
      int * v12123 = v12047->cache_age;
      int v12124 = v12123[v12165];
      int v12222 = v12124 + ((int)((unsigned int)(v12124 - v12120) >> 31));
      v12123[v12165] = v12222;
      int * v12126 = v12047->cache_age;
      v12126[v12190] = 0;
      v12129 = v12190;
    }
    int * v12130 = v12047->cache_vals;
    int v12225 = v12129 * 2;
    int v12131 = v12130[v12225];
    int v12226 = (v12129 * 2) + 1;
    int v12132 = v12130[v12226];
    int v12227 = (((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v12071 + ((~(((v12073 ^ -1) | (-(v12073 ^ -1))) >> 31)) & 2)) - (v12074 + ((~(((v12075 ^ -1) | (-(v12075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12130[v12227] = v12131;
    int * v12134 = v12047->cache_vals;
    int v12230 = ((((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v12071 + ((~(((v12073 ^ -1) | (-(v12073 ^ -1))) >> 31)) & 2)) - (v12074 + ((~(((v12075 ^ -1) | (-(v12075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12134[v12230] = v12132;
    int * v12136 = v12047->cache_tags;
    int v12233 = ((((int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v12071 + ((~(((v12073 ^ -1) | (-(v12073 ^ -1))) >> 31)) & 2)) - (v12074 + ((~(((v12075 ^ -1) | (-(v12075 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12234 = (int)((unsigned int)((int)((unsigned int)(v12051 + 24) >> 2)) >> 1);
    v12136[v12233] = v12234;
    int * v12138 = v12047->cache_dirty;
    v12138[v12233] = 0;
    int * v12140 = v12047->cache_age;
    v12140[v12233] = 1;
    int * v12142 = v12047->cache_age;
    int v12143 = v12142[v12233];
    int v12144 = v12142[v12162];
    int v12240 = v12144 + ((int)((unsigned int)(v12144 - v12143) >> 31));
    v12142[v12162] = v12240;
    int * v12146 = v12047->cache_age;
    int v12147 = v12146[v12163];
    int v12242 = v12147 + ((int)((unsigned int)(v12147 - v12143) >> 31));
    v12146[v12163] = v12242;
    int * v12149 = v12047->cache_age;
    v12149[v12233] = 0;
    v12152 = v12233;
  }
  int v12245 = (v12152 * 2) + (((int)((unsigned int)(v12051 + 24) >> 2)) & 1);
  int v12153 = v12059[v12245];
  int * v12154 = v12047->regs;
  v12154[21] = v12153;
  struct StateT * v12156 = slot_223(v12047);
  return v12156;
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

struct StateT * slot_311(struct StateT * v14175) {
  int v14176 = v14175->timer;
  int v14183 = v14176 + 1;
  v14175->timer = v14183;
  int * v14178 = v14175->regs;
  int v14179 = v14178[23];
  int v14186 = v14179 << 7;
  v14178[23] = v14186;
  struct StateT * v14181 = slot_312(v14175);
  return v14181;
}

struct StateT * slot_498(struct StateT * v17230) {
  int v17231 = v17230->timer;
  int v17239 = v17231 + 1;
  v17230->timer = v17239;
  int * v17233 = v17230->regs;
  int v17234 = v17233[7];
  int v17235 = v17233[23];
  int v17243 = v17234 ^ v17235;
  v17233[7] = v17243;
  struct StateT * v17237 = slot_499(v17230);
  return v17237;
}

struct StateT * slot_279(struct StateT * v13679) {
  int v13680 = v13679->timer;
  int v13688 = v13680 + 1;
  v13679->timer = v13688;
  int * v13682 = v13679->regs;
  int v13683 = v13682[12];
  int v13684 = v13682[17];
  int v13693 = v13683 + v13684;
  v13682[22] = v13693;
  struct StateT * v13686 = slot_280(v13679);
  return v13686;
}

struct StateT * slot_271(struct StateT * v13551) {
  int v13552 = v13551->timer;
  int v13559 = v13552 + 1;
  v13551->timer = v13559;
  int * v13554 = v13551->regs;
  int v13555 = v13554[23];
  int v13562 = v13555 << 13;
  v13554[23] = v13562;
  struct StateT * v13557 = slot_272(v13551);
  return v13557;
}

struct StateT * slot_524(struct StateT * v17641) {
  int v17642 = v17641->timer;
  int v17649 = v17642 + 1;
  v17641->timer = v17649;
  int * v17644 = v17641->regs;
  int v17645 = v17644[20];
  int v17652 = v17645 << 18;
  v17644[20] = v17652;
  struct StateT * v17647 = slot_525(v17641);
  return v17647;
}

struct StateT * slot_505(struct StateT * v17343) {
  int v17344 = v17343->timer;
  int v17352 = v17344 + 1;
  v17343->timer = v17352;
  int * v17346 = v17343->regs;
  int v17347 = v17346[20];
  int v17348 = v17346[24];
  int v17356 = v17347 | v17348;
  v17346[20] = v17356;
  struct StateT * v17350 = slot_506(v17343);
  return v17350;
}

struct StateT * slot_401(struct StateT * v15636) {
  int v15637 = v15636->timer;
  int v15645 = v15637 + 1;
  v15636->timer = v15645;
  int * v15639 = v15636->regs;
  int v15640 = v15639[19];
  int v15641 = v15639[28];
  int v15650 = v15640 + v15641;
  v15639[22] = v15650;
  struct StateT * v15643 = slot_402(v15636);
  return v15643;
}

struct StateT * slot_423(struct StateT * v16010) {
  int v16011 = v16010->timer;
  int v16018 = v16011 + 1;
  v16010->timer = v16018;
  int * v16013 = v16010->regs;
  int v16014 = v16013[20];
  int v16022 = (int)((unsigned int)v16014 >> 19);
  v16013[24] = v16022;
  struct StateT * v16016 = slot_424(v16010);
  return v16016;
}

struct StateT * slot_532(struct StateT * v17761) {
  int v17762 = v17761->timer;
  int v17769 = v17762 + 1;
  v17761->timer = v17769;
  int * v17764 = v17761->regs;
  int v17765 = v17764[23];
  int v17773 = (int)((unsigned int)v17765 >> 14);
  v17764[24] = v17773;
  struct StateT * v17767 = slot_533(v17761);
  return v17767;
}

struct StateT * slot_217(struct StateT * v11608) {
  int v11609 = v11608->timer;
  int v11719 = v11609 + 1;
  v11608->timer = v11719;
  int * v11611 = v11608->regs;
  int v11612 = v11611[2];
  int * v11613 = v11608->cache_tags;
  int v11723 = (((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2;
  int v11614 = v11613[v11723];
  int v11724 = ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11615 = v11613[v11724];
  int v11725 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2);
  int v11616 = v11613[v11725];
  int v11726 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11617 = v11613[v11726];
  int v11618 = v11608->timer;
  int v11727 = v11618 + ((100 ^ (((~(((v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11614 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11614 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11608->timer = v11727;
  int * v11620 = v11608->cache_vals;
  bool v11728 = !(((~(((v11614 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11614 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v11713;
  if (v11728) {
    int * v11621 = v11608->cache_age;
    int v11730 = ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11615 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v11622 = v11621[v11730];
    int v11623 = v11621[v11723];
    int v11731 = v11623 + ((int)((unsigned int)(v11623 - v11622) >> 31));
    v11621[v11723] = v11731;
    int * v11625 = v11608->cache_age;
    int v11626 = v11625[v11724];
    int v11733 = v11626 + ((int)((unsigned int)(v11626 - v11622) >> 31));
    v11625[v11724] = v11733;
    int * v11628 = v11608->cache_age;
    v11628[v11730] = 0;
    v11713 = v11730;
  } else {
    int * v11631 = v11608->cache_age;
    int v11737 = (((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2;
    int v11632 = v11631[v11737];
    int * v11633 = v11608->cache_tags;
    int v11634 = v11633[v11737];
    int v11635 = v11631[v11724];
    int v11636 = v11633[v11724];
    bool v11739 = !(((~(((v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11616 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v11690;
    if (v11739) {
      int * v11637 = v11608->cache_age;
      int v11741 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))) | (-(v11617 ^ ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v11638 = v11637[v11741];
      int v11639 = v11637[v11725];
      int v11742 = v11639 + ((int)((unsigned int)(v11639 - v11638) >> 31));
      v11637[v11725] = v11742;
      int * v11641 = v11608->cache_age;
      int v11642 = v11641[v11726];
      int v11744 = v11642 + ((int)((unsigned int)(v11642 - v11638) >> 31));
      v11641[v11726] = v11744;
      int * v11644 = v11608->cache_age;
      v11644[v11741] = 0;
      v11690 = v11741;
    } else {
      int * v11647 = v11608->cache_age;
      int v11748 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2);
      int v11648 = v11647[v11748];
      int * v11649 = v11608->cache_tags;
      int v11650 = v11649[v11748];
      int v11651 = v11647[v11726];
      int v11652 = v11649[v11726];
      int * v11653 = v11608->cache_dirty;
      int v11751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11648 + ((~(((v11650 ^ -1) | (-(v11650 ^ -1))) >> 31)) & 2)) - (v11651 + ((~(((v11652 ^ -1) | (-(v11652 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11654 = v11653[v11751];
      bool v11752 = !(v11654 == 0);
      if (v11752) {
        int * v11655 = v11608->cache_tags;
        int v11656 = v11655[v11751];
        int * v11657 = v11608->cache_vals;
        int v11755 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11648 + ((~(((v11650 ^ -1) | (-(v11650 ^ -1))) >> 31)) & 2)) - (v11651 + ((~(((v11652 ^ -1) | (-(v11652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11658 = v11657[v11755];
        int v11756 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11648 + ((~(((v11650 ^ -1) | (-(v11650 ^ -1))) >> 31)) & 2)) - (v11651 + ((~(((v11652 ^ -1) | (-(v11652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11659 = v11657[v11756];
        int * v11660 = v11608->mem;
        int v11758 = v11656 * 2;
        v11660[v11758] = v11658;
        int * v11662 = v11608->mem;
        int v11761 = (v11656 * 2) + 1;
        v11662[v11761] = v11659;
        ;
      } else {
        ;
      }
      int * v11667 = v11608->mem;
      int v11766 = ((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) * 2;
      int v11668 = v11667[v11766];
      int v11767 = (((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) * 2) + 1;
      int v11669 = v11667[v11767];
      int * v11670 = v11608->cache_vals;
      int v11769 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11648 + ((~(((v11650 ^ -1) | (-(v11650 ^ -1))) >> 31)) & 2)) - (v11651 + ((~(((v11652 ^ -1) | (-(v11652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11670[v11769] = v11668;
      int * v11672 = v11608->cache_vals;
      int v11772 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11648 + ((~(((v11650 ^ -1) | (-(v11650 ^ -1))) >> 31)) & 2)) - (v11651 + ((~(((v11652 ^ -1) | (-(v11652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11672[v11772] = v11669;
      int * v11674 = v11608->cache_tags;
      int v11775 = (int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1);
      v11674[v11751] = v11775;
      int * v11676 = v11608->cache_dirty;
      v11676[v11751] = 0;
      int * v11678 = v11608->cache_age;
      v11678[v11751] = 1;
      int * v11680 = v11608->cache_age;
      int v11681 = v11680[v11751];
      int v11682 = v11680[v11725];
      int v11781 = v11682 + ((int)((unsigned int)(v11682 - v11681) >> 31));
      v11680[v11725] = v11781;
      int * v11684 = v11608->cache_age;
      int v11685 = v11684[v11726];
      int v11783 = v11685 + ((int)((unsigned int)(v11685 - v11681) >> 31));
      v11684[v11726] = v11783;
      int * v11687 = v11608->cache_age;
      v11687[v11751] = 0;
      v11690 = v11751;
    }
    int * v11691 = v11608->cache_vals;
    int v11786 = v11690 * 2;
    int v11692 = v11691[v11786];
    int v11787 = (v11690 * 2) + 1;
    int v11693 = v11691[v11787];
    int v11788 = (((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11632 + ((~(((v11634 ^ -1) | (-(v11634 ^ -1))) >> 31)) & 2)) - (v11635 + ((~(((v11636 ^ -1) | (-(v11636 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11691[v11788] = v11692;
    int * v11695 = v11608->cache_vals;
    int v11791 = ((((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11632 + ((~(((v11634 ^ -1) | (-(v11634 ^ -1))) >> 31)) & 2)) - (v11635 + ((~(((v11636 ^ -1) | (-(v11636 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11695[v11791] = v11693;
    int * v11697 = v11608->cache_tags;
    int v11794 = ((((int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11632 + ((~(((v11634 ^ -1) | (-(v11634 ^ -1))) >> 31)) & 2)) - (v11635 + ((~(((v11636 ^ -1) | (-(v11636 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11795 = (int)((unsigned int)((int)((unsigned int)(v11612 + 32) >> 2)) >> 1);
    v11697[v11794] = v11795;
    int * v11699 = v11608->cache_dirty;
    v11699[v11794] = 0;
    int * v11701 = v11608->cache_age;
    v11701[v11794] = 1;
    int * v11703 = v11608->cache_age;
    int v11704 = v11703[v11794];
    int v11705 = v11703[v11723];
    int v11801 = v11705 + ((int)((unsigned int)(v11705 - v11704) >> 31));
    v11703[v11723] = v11801;
    int * v11707 = v11608->cache_age;
    int v11708 = v11707[v11724];
    int v11803 = v11708 + ((int)((unsigned int)(v11708 - v11704) >> 31));
    v11707[v11724] = v11803;
    int * v11710 = v11608->cache_age;
    v11710[v11794] = 0;
    v11713 = v11794;
  }
  int v11806 = (v11713 * 2) + (((int)((unsigned int)(v11612 + 32) >> 2)) & 1);
  int v11714 = v11620[v11806];
  int * v11715 = v11608->regs;
  v11715[19] = v11714;
  struct StateT * v11717 = slot_219(v11608);
  return v11717;
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

struct StateT * slot_349(struct StateT * v14768) {
  int v14769 = v14768->timer;
  int v14777 = v14769 + 1;
  v14768->timer = v14777;
  int * v14771 = v14768->regs;
  int v14772 = v14771[22];
  int v14773 = v14771[24];
  int v14781 = v14772 | v14773;
  v14771[22] = v14781;
  struct StateT * v14775 = slot_350(v14768);
  return v14775;
}

struct StateT * slot_291(struct StateT * v13863) {
  int v13864 = v13863->timer;
  int v13871 = v13864 + 1;
  v13863->timer = v13871;
  int * v13866 = v13863->regs;
  int v13867 = v13866[23];
  int v13874 = v13867 << 18;
  v13866[23] = v13874;
  struct StateT * v13869 = slot_292(v13863);
  return v13869;
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

struct StateT * slot_410(struct StateT * v15775) {
  int v15776 = v15775->timer;
  int v15783 = v15776 + 1;
  v15775->timer = v15783;
  int * v15778 = v15775->regs;
  int v15779 = v15778[22];
  int v15786 = v15779 << 9;
  v15778[22] = v15786;
  struct StateT * v15781 = slot_411(v15775);
  return v15781;
}

struct StateT * slot_491(struct StateT * v17121) {
  int v17122 = v17121->timer;
  int v17130 = v17122 + 1;
  v17121->timer = v17130;
  int * v17124 = v17121->regs;
  int v17125 = v17124[22];
  int v17126 = v17124[24];
  int v17134 = v17125 | v17126;
  v17124[22] = v17134;
  struct StateT * v17128 = slot_492(v17121);
  return v17128;
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

struct StateT * slot_422(struct StateT * v15993) {
  int v15994 = v15993->timer;
  int v16002 = v15994 + 1;
  v15993->timer = v16002;
  int * v15996 = v15993->regs;
  int v15997 = v15996[5];
  int v15998 = v15996[8];
  int v16007 = v15997 + v15998;
  v15996[23] = v16007;
  struct StateT * v16000 = slot_423(v15993);
  return v16000;
}

struct StateT * slot_448(struct StateT * v16424) {
  int v16425 = v16424->timer;
  int v16433 = v16425 + 1;
  v16424->timer = v16433;
  int * v16427 = v16424->regs;
  int v16428 = v16427[21];
  int v16429 = v16427[24];
  int v16437 = v16428 | v16429;
  v16427[21] = v16437;
  struct StateT * v16431 = slot_449(v16424);
  return v16431;
}

struct StateT * slot_204(struct StateT * v9943) {
  int v9944 = v9943->timer;
  int v9952 = v9944 + 1;
  v9943->timer = v9952;
  int * v9946 = v9943->regs;
  int v9947 = v9946[28];
  int v9948 = v9946[12];
  int v9957 = v9947 + v9948;
  v9946[22] = v9957;
  struct StateT * v9950 = slot_206(v9943);
  return v9950;
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
    struct StateT * v8201 = slot_195(v8108);
    v8205 = v8201;
  } else {
    struct StateT * v8203 = slot_196(v8108);
    v8205 = v8203;
  }
  return v8205;
}

struct StateT * slot_407(struct StateT * v15730) {
  int v15731 = v15730->timer;
  int v15738 = v15731 + 1;
  v15730->timer = v15738;
  int * v15733 = v15730->regs;
  int v15734 = v15733[21];
  int v15741 = v15734 << 9;
  v15733[21] = v15741;
  struct StateT * v15736 = slot_408(v15730);
  return v15736;
}

struct StateT * slot_250(struct StateT * v13224) {
  int v13225 = v13224->timer;
  int v13232 = v13225 + 1;
  v13224->timer = v13232;
  int * v13227 = v13224->regs;
  int v13228 = v13227[23];
  int v13236 = (int)((unsigned int)v13228 >> 23);
  v13227[24] = v13236;
  struct StateT * v13230 = slot_251(v13224);
  return v13230;
}

struct StateT * slot_360(struct StateT * v14944) {
  int v14945 = v14944->timer;
  int v14953 = v14945 + 1;
  v14944->timer = v14953;
  int * v14947 = v14944->regs;
  int v14948 = v14947[19];
  int v14949 = v14947[7];
  int v14958 = v14948 + v14949;
  v14947[23] = v14958;
  struct StateT * v14951 = slot_361(v14944);
  return v14951;
}

struct StateT * slot_259(struct StateT * v13367) {
  int v13368 = v13367->timer;
  int v13376 = v13368 + 1;
  v13367->timer = v13376;
  int * v13370 = v13367->regs;
  int v13371 = v13370[17];
  int v13372 = v13370[19];
  int v13381 = v13371 + v13372;
  v13370[22] = v13381;
  struct StateT * v13374 = slot_260(v13367);
  return v13374;
}

struct StateT * slot_469(struct StateT * v16780) {
  int v16781 = v16780->timer;
  int v16788 = v16781 + 1;
  v16780->timer = v16788;
  int * v16783 = v16780->regs;
  int v16784 = v16783[22];
  int v16792 = (int)((unsigned int)v16784 >> 25);
  v16783[24] = v16792;
  struct StateT * v16786 = slot_470(v16780);
  return v16786;
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