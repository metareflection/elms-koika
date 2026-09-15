// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]

#define NUM_REGS 32
#define MEM_SIZE 64
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
  int mem[64];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_143(struct StateT * v5556);
struct StateT * slot_120(struct StateT * v5098);
struct StateT * slot_226(struct StateT * v7501);
struct StateT * slot_167(struct StateT * v6009);
struct StateT * slot_509(struct StateT * v19032);
struct StateT * slot_152(struct StateT * v5734);
struct StateT * slot_429(struct StateT * v17527);
struct StateT * slot_231(struct StateT * v7778);
struct StateT * slot_355(struct StateT * v14549);
struct StateT * slot_92(struct StateT * v4534);
struct StateT * slot_616(struct StateT * v21189);
struct StateT * slot_232(struct StateT * v7883);
struct StateT * slot_466(struct StateT * v18220);
struct StateT * slot_304(struct StateT * v10854);
struct StateT * slot_31(struct StateT * v2620);
struct StateT * slot_236(struct StateT * v8140);
struct StateT * slot_585(struct StateT * v20578);
struct StateT * slot_241(struct StateT * v8424);
struct StateT * slot_611(struct StateT * v21103);
struct StateT * slot_160(struct StateT * v5883);
struct StateT * slot_519(struct StateT * v19234);
struct StateT * slot_150(struct StateT * v5692);
struct StateT * slot_391(struct StateT * v16835);
struct StateT * slot_74(struct StateT * v4172);
struct StateT * slot_580(struct StateT * v20477);
struct StateT * slot_262(struct StateT * v9528);
struct StateT * slot_351(struct StateT * v14218);
struct StateT * slot_372(struct StateT * v15825);
struct StateT * slot_677(struct StateT * v22684);
struct StateT * slot_403(struct StateT * v17024);
struct StateT * slot_107(struct StateT * v4817);
struct StateT * slot_555(struct StateT * v19973);
struct StateT * slot_541(struct StateT * v19675);
struct StateT * slot_325(struct StateT * v12367);
struct StateT * slot_84(struct StateT * v4352);
struct StateT * slot_28(struct StateT * v2577);
struct StateT * slot_155(struct StateT * v5797);
struct StateT * slot_177(struct StateT * v6206);
struct StateT * slot_517(struct StateT * v19201);
struct StateT * slot_229(struct StateT * v7646);
struct StateT * slot_358(struct StateT * v14779);
struct StateT * slot_465(struct StateT * v18199);
struct StateT * slot_181(struct StateT * v6279);
struct StateT * slot_542(struct StateT * v19691);
struct StateT * slot_566(struct StateT * v20192);
struct StateT * slot_679(struct StateT * v22809);
struct StateT * slot_154(struct StateT * v5776);
struct StateT * slot_669(struct StateT * v22368);
struct StateT * slot_260(struct StateT * v9403);
struct StateT * slot_481(struct StateT * v18495);
struct StateT * slot_620(struct StateT * v21262);
struct StateT * slot_305(struct StateT * v10874);
struct StateT * slot_27(struct StateT * v2564);
struct StateT * slot_662(struct StateT * v22047);
struct StateT * slot_454(struct StateT * v17993);
struct StateT * slot_34(struct StateT * v2667);
struct StateT * slot_482(struct StateT * v18515);
struct StateT * slot_21(struct StateT * v1934);
struct StateT * slot_406(struct StateT * v17087);
struct StateT * slot_292(struct StateT * v10228);
struct StateT * slot_118(struct StateT * v5065);
struct StateT * slot_525(struct StateT * v19361);
struct StateT * slot_515(struct StateT * v19165);
struct StateT * slot_666(struct StateT * v22128);
struct StateT * slot_589(struct StateT * v20681);
struct StateT * slot_376(struct StateT * v16161);
struct StateT * slot_373(struct StateT * v15930);
struct StateT * slot_94(struct StateT * v4576);
struct StateT * slot_340(struct StateT * v13435);
struct StateT * slot_146(struct StateT * v5609);
struct StateT * slot_383(struct StateT * v16551);
struct StateT * slot_24(struct StateT * v2249);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v18659);
struct StateT * slot_673(struct StateT * v22526);
struct StateT * slot_286(struct StateT * v10115);
struct StateT * slot_520(struct StateT * v19254);
struct StateT * slot_125(struct StateT * v5188);
struct StateT * slot_254(struct StateT * v9111);
struct StateT * slot_148(struct StateT * v5650);
struct StateT * slot_421(struct StateT * v17362);
struct StateT * slot_126(struct StateT * v5204);
struct StateT * slot_363(struct StateT * v15134);
struct StateT * slot_578(struct StateT * v20441);
struct StateT * slot_661(struct StateT * v22031);
struct StateT * slot_79(struct StateT * v4263);
struct StateT * slot_568(struct StateT * v20234);
struct StateT * slot_571(struct StateT * v20318);
struct StateT * slot_367(struct StateT * v15469);
struct StateT * slot_437(struct StateT * v17666);
struct StateT * slot_341(struct StateT * v13452);
struct StateT * slot_142(struct StateT * v5540);
struct StateT * slot_416(struct StateT * v17273);
struct StateT * slot_624(struct StateT * v21335);
struct StateT * slot_280(struct StateT * v10010);
struct StateT * slot_272(struct StateT * v9877);
struct StateT * slot_47(struct StateT * v3530);
struct StateT * slot_214(struct StateT * v7089);
struct StateT * slot_297(struct StateT * v10402);
struct StateT * slot_29(struct StateT * v2590);
struct StateT * slot_314(struct StateT * v11524);
struct StateT * slot_151(struct StateT * v5713);
struct StateT * slot_7(struct StateT * v605);
struct StateT * slot_124(struct StateT * v5171);
struct StateT * slot_638(struct StateT * v21602);
struct StateT * slot_601(struct StateT * v20899);
struct StateT * slot_128(struct StateT * v5251);
struct StateT * slot_365(struct StateT * v15259);
struct StateT * slot_441(struct StateT * v17740);
struct StateT * slot_19(struct StateT * v1724);
struct StateT * slot_622(struct StateT * v21295);
struct StateT * slot_382(struct StateT * v16534);
struct StateT * slot_523(struct StateT * v19307);
struct StateT * slot_87(struct StateT * v4405);
struct StateT * slot_452(struct StateT * v17960);
struct StateT * slot_67(struct StateT * v4001);
struct StateT * slot_591(struct StateT * v20723);
struct StateT * slot_81(struct StateT * v4299);
struct StateT * slot_546(struct StateT * v19792);
struct StateT * slot_556(struct StateT * v19989);
struct StateT * slot_651(struct StateT * v21855);
struct StateT * slot_337(struct StateT * v13219);
struct StateT * slot_32(struct StateT * v2637);
struct StateT * slot_233(struct StateT * v7910);
struct StateT * slot_595(struct StateT * v20793);
struct StateT * slot_176(struct StateT * v6190);
struct StateT * slot_189(struct StateT * v6425);
struct StateT * slot_394(struct StateT * v16856);
struct StateT * slot_398(struct StateT * v16929);
struct StateT * slot_33(struct StateT * v2654);
struct StateT * slot_371(struct StateT * v15720);
struct StateT * slot_680(struct StateT * v22914);
struct StateT * slot_330(struct StateT * v12697);
struct StateT * slot_450(struct StateT * v17924);
struct StateT * slot_672(struct StateT * v22421);
struct StateT * slot_35(struct StateT * v2683);
struct StateT * slot_484(struct StateT * v18555);
struct StateT * slot_258(struct StateT * v9362);
struct StateT * slot_166(struct StateT * v5989);
struct StateT * slot_615(struct StateT * v21173);
struct StateT * slot_418(struct StateT * v17309);
struct StateT * slot_51(struct StateT * v3670);
struct StateT * slot_25(struct StateT * v2354);
struct StateT * slot_490(struct StateT * v18676);
struct StateT * slot_264(struct StateT * v9650);
struct StateT * slot_339(struct StateT * v13337);
struct StateT * slot_123(struct StateT * v5151);
struct StateT * slot_97(struct StateT * v4630);
struct StateT * slot_594(struct StateT * v20776);
struct StateT * slot_106(struct StateT * v4789);
struct StateT * slot_299(struct StateT * v10520);
struct StateT * slot_539(struct StateT * v19638);
struct StateT * slot_319(struct StateT * v11937);
struct StateT * slot_656(struct StateT * v21941);
struct StateT * slot_671(struct StateT * v22401);
struct StateT * slot_344(struct StateT * v13671);
struct StateT * slot_513(struct StateT * v19128);
struct StateT * slot_130(struct StateT * v5299);
struct StateT * slot_497(struct StateT * v18798);
struct StateT * slot_455(struct StateT * v18013);
struct StateT * slot_141(struct StateT * v5523);
struct StateT * slot_432(struct StateT * v17580);
struct StateT * slot_306(struct StateT * v10972);
struct StateT * slot_312(struct StateT * v11405);
struct StateT * slot_4(struct StateT * v311);
struct StateT * slot_560(struct StateT * v20062);
struct StateT * slot_240(struct StateT * v8397);
struct StateT * slot_247(struct StateT * v8707);
struct StateT * slot_548(struct StateT * v19840);
struct StateT * slot_70(struct StateT * v4082);
struct StateT * slot_168(struct StateT * v6029);
struct StateT * slot_348(struct StateT * v13991);
struct StateT * slot_456(struct StateT * v18030);
struct StateT * slot_225(struct StateT * v7488);
struct StateT * slot_467(struct StateT * v18241);
struct StateT * slot_285(struct StateT * v10095);
struct StateT * slot_659(struct StateT * v21994);
struct StateT * slot_213(struct StateT * v7069);
struct StateT * slot_82(struct StateT * v4316);
struct StateT * slot_632(struct StateT * v21496);
struct StateT * slot_642(struct StateT * v21671);
struct StateT * slot_590(struct StateT * v20702);
struct StateT * slot_263(struct StateT * v9545);
struct StateT * slot_161(struct StateT * v5903);
struct StateT * slot_293(struct StateT * v10244);
struct StateT * slot_185(struct StateT * v6349);
struct StateT * slot_288(struct StateT * v10151);
struct StateT * slot_683(struct StateT * v23059);
struct StateT * slot_89(struct StateT * v4459);
struct StateT * slot_384(struct StateT * v16656);
struct StateT * slot_486(struct StateT * v18596);
struct StateT * slot_347(struct StateT * v13893);
struct StateT * slot_140(struct StateT * v5503);
struct StateT * slot_473(struct StateT * v18353);
struct StateT * slot_49(struct StateT * v3645);
struct StateT * slot_216(struct StateT * v7117);
struct StateT * slot_468(struct StateT * v18262);
struct StateT * slot_50(struct StateT * v3662);
struct StateT * slot_135(struct StateT * v5417);
struct StateT * slot_248(struct StateT * v8727);
struct StateT * slot_59(struct StateT * v3859);
struct StateT * slot_485(struct StateT * v18575);
struct StateT * slot_40(struct StateT * v3087);
struct StateT * slot_586(struct StateT * v20605);
struct StateT * slot_77(struct StateT * v4226);
struct StateT * slot_85(struct StateT * v4369);
struct StateT * slot_350(struct StateT * v14113);
struct StateT * slot_392(struct StateT * v16840);
struct StateT * slot_75(struct StateT * v4193);
struct StateT * slot_581(struct StateT * v20494);
struct StateT * slot_625(struct StateT * v21355);
struct StateT * slot_71(struct StateT * v4109);
struct StateT * slot_378(struct StateT * v16287);
struct StateT * slot_108(struct StateT * v4838);
struct StateT * slot_619(struct StateT * v21242);
struct StateT * slot_116(struct StateT * v5029);
struct StateT * slot_618(struct StateT * v21226);
struct StateT * slot_417(struct StateT * v17289);
struct StateT * slot_405(struct StateT * v17066);
struct StateT * slot_215(struct StateT * v7097);
struct StateT * slot_45(struct StateT * v3496);
struct StateT * slot_579(struct StateT * v20457);
struct StateT * slot_220(struct StateT * v7204);
struct StateT * slot_134(struct StateT * v5396);
struct StateT * slot_463(struct StateT * v18159);
struct StateT * slot_175(struct StateT * v6173);
struct StateT * slot_273(struct StateT * v9897);
struct StateT * slot_69(struct StateT * v4055);
struct StateT * slot_621(struct StateT * v21279);
struct StateT * slot_644(struct StateT * v21711);
struct StateT * slot_565(struct StateT * v20171);
struct StateT * slot_188(struct StateT * v6405);
struct StateT * slot_495(struct StateT * v18765);
struct StateT * slot_186(struct StateT * v6365);
struct StateT * slot_102(struct StateT * v4720);
struct StateT * slot_145(struct StateT * v5593);
struct StateT * slot_110(struct StateT * v4886);
struct StateT * slot_208(struct StateT * v6781);
struct StateT * slot_301(struct StateT * v10638);
struct StateT * slot_502(struct StateT * v18891);
struct StateT * slot_506(struct StateT * v18968);
struct StateT * slot_413(struct StateT * v17220);
struct StateT * slot_320(struct StateT * v11958);
struct StateT * slot_281(struct StateT * v10027);
struct StateT * slot_533(struct StateT * v19532);
struct StateT * slot_203(struct StateT * v6688);
struct StateT * slot_190(struct StateT * v6445);
struct StateT * slot_157(struct StateT * v5830);
struct StateT * slot_447(struct StateT * v17865);
struct StateT * slot_587(struct StateT * v20632);
struct StateT * slot_559(struct StateT * v20042);
struct StateT * slot_243(struct StateT * v8549);
struct StateT * slot_173(struct StateT * v6131);
struct StateT * slot_307(struct StateT * v11070);
struct StateT * slot_453(struct StateT * v17977);
struct StateT * slot_54(struct StateT * v3754);
struct StateT * slot_26(struct StateT * v2459);
struct StateT * slot_370(struct StateT * v15699);
struct StateT * slot_652(struct StateT * v21872);
struct StateT * slot_583(struct StateT * v20530);
struct StateT * slot_206(struct StateT * v6741);
struct StateT * slot_227(struct StateT * v7528);
struct StateT * slot_169(struct StateT * v6049);
struct StateT * slot_442(struct StateT * v17760);
struct StateT * slot_529(struct StateT * v19457);
struct StateT * slot_14(struct StateT * v1291);
struct StateT * slot_357(struct StateT * v14674);
struct StateT * slot_385(struct StateT * v16661);
struct StateT * slot_602(struct StateT * v20915);
struct StateT * slot_444(struct StateT * v17802);
struct StateT * slot_261(struct StateT * v9423);
struct StateT * slot_603(struct StateT * v20936);
struct StateT * slot_287(struct StateT * v10135);
struct StateT * slot_639(struct StateT * v21618);
struct StateT * slot_343(struct StateT * v13655);
struct StateT * slot_36(struct StateT * v2696);
struct StateT * slot_57(struct StateT * v3822);
struct StateT * slot_426(struct StateT * v17464);
struct StateT * slot_536(struct StateT * v19585);
struct StateT * slot_470(struct StateT * v18300);
struct StateT * slot_431(struct StateT * v17560);
struct StateT * slot_62(struct StateT * v3912);
struct StateT * slot_308(struct StateT * v11090);
struct StateT * slot_400(struct StateT * v16962);
struct StateT * slot_323(struct StateT * v12171);
struct StateT * slot_628(struct StateT * v21416);
struct StateT * slot_521(struct StateT * v19271);
struct StateT * slot_530(struct StateT * v19478);
struct StateT * slot_23(struct StateT * v2144);
struct StateT * slot_2(struct StateT * v115);
struct StateT * slot_86(struct StateT * v4385);
struct StateT * slot_670(struct StateT * v22388);
struct StateT * slot_538(struct StateT * v19622);
struct StateT * slot_100(struct StateT * v4683);
struct StateT * slot_127(struct StateT * v5224);
struct StateT * slot_640(struct StateT * v21638);
struct StateT * slot_411(struct StateT * v17183);
struct StateT * slot_13(struct StateT * v1193);
struct StateT * slot_449(struct StateT * v17907);
struct StateT * slot_569(struct StateT * v20262);
struct StateT * slot_460(struct StateT * v18099);
struct StateT * slot_109(struct StateT * v4865);
struct StateT * slot_474(struct StateT * v18369);
struct StateT * slot_174(struct StateT * v6152);
struct StateT * slot_629(struct StateT * v21437);
struct StateT * slot_42(struct StateT * v3283);
struct StateT * slot_609(struct StateT * v21061);
struct StateT * slot_224(struct StateT * v7376);
struct StateT * slot_588(struct StateT * v20653);
struct StateT * slot_184(struct StateT * v6332);
struct StateT * slot_562(struct StateT * v20095);
struct StateT * slot_462(struct StateT * v18139);
struct StateT * slot_165(struct StateT * v5973);
struct StateT * slot_557(struct StateT * v20009);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_584(struct StateT * v20557);
struct StateT * slot_507(struct StateT * v18976);
struct StateT * slot_477(struct StateT * v18422);
struct StateT * slot_278(struct StateT * v9978);
struct StateT * slot_352(struct StateT * v14323);
struct StateT * slot_561(struct StateT * v20079);
struct StateT * slot_577(struct StateT * v20424);
struct StateT * slot_249(struct StateT * v8839);
struct StateT * slot_11(struct StateT * v997);
struct StateT * slot_12(struct StateT * v1095);
struct StateT * slot_228(struct StateT * v7633);
struct StateT * slot_268(struct StateT * v9719);
struct StateT * slot_199(struct StateT * v6619);
struct StateT * slot_252(struct StateT * v9070);
struct StateT * slot_653(struct StateT * v21888);
struct StateT * slot_409(struct StateT * v17150);
struct StateT * slot_374(struct StateT * v15951);
struct StateT * slot_269(struct StateT * v9739);
struct StateT * slot_681(struct StateT * v22934);
struct StateT * slot_501(struct StateT * v18871);
struct StateT * slot_582(struct StateT * v20510);
struct StateT * slot_251(struct StateT * v8965);
struct StateT * slot_65(struct StateT * v3965);
struct StateT * slot_10(struct StateT * v899);
struct StateT * slot_322(struct StateT * v12154);
struct StateT * slot_593(struct StateT * v20756);
struct StateT * slot_277(struct StateT * v9958);
struct StateT * slot_353(struct StateT * v14339);
struct StateT * slot_612(struct StateT * v21120);
struct StateT * slot_572(struct StateT * v20335);
struct StateT * slot_397(struct StateT * v16909);
struct StateT * slot_435(struct StateT * v17633);
struct StateT * slot_476(struct StateT * v18406);
struct StateT * slot_655(struct StateT * v21925);
struct StateT * slot_136(struct StateT * v5434);
struct StateT * slot_658(struct StateT * v21978);
struct StateT * slot_379(struct StateT * v16392);
struct StateT * slot_475(struct StateT * v18389);
struct StateT * slot_310(struct StateT * v11286);
struct StateT * slot_445(struct StateT * v17823);
struct StateT * slot_295(struct StateT * v10362);
struct StateT * slot_315(struct StateT * v11622);
struct StateT * slot_545(struct StateT * v19765);
struct StateT * slot_17(struct StateT * v1514);
struct StateT * slot_197(struct StateT * v6582);
struct StateT * slot_457(struct StateT * v18046);
struct StateT * slot_207(struct StateT * v6761);
struct StateT * slot_663(struct StateT * v22067);
struct StateT * slot_156(struct StateT * v5814);
struct StateT * slot_68(struct StateT * v4028);
struct StateT * slot_493(struct StateT * v18729);
struct StateT * slot_105(struct StateT * v4773);
struct StateT * slot_430(struct StateT * v17544);
struct StateT * slot_369(struct StateT * v15594);
struct StateT * slot_461(struct StateT * v18119);
struct StateT * slot_631(struct StateT * v21479);
struct StateT * slot_164(struct StateT * v5956);
struct StateT * slot_15(struct StateT * v1304);
struct StateT * slot_480(struct StateT * v18475);
struct StateT * slot_133(struct StateT * v5375);
struct StateT * slot_56(struct StateT * v3806);
struct StateT * slot_244(struct StateT * v8562);
struct StateT * slot_222(struct StateT * v7329);
struct StateT * slot_171(struct StateT * v6089);
struct StateT * slot_162(struct StateT * v5920);
struct StateT * slot_634(struct StateT * v21532);
struct StateT * slot_564(struct StateT * v20144);
struct StateT * slot_630(struct StateT * v21458);
struct StateT * slot_377(struct StateT * v16182);
struct StateT * slot_552(struct StateT * v19920);
struct StateT * slot_427(struct StateT * v17485);
struct StateT * slot_399(struct StateT * v16946);
struct StateT * slot_239(struct StateT * v8292);
struct StateT * slot_464(struct StateT * v18179);
struct StateT * slot_500(struct StateT * v18851);
struct StateT * slot_433(struct StateT * v17597);
struct StateT * slot_121(struct StateT * v5118);
struct StateT * slot_610(struct StateT * v21082);
struct StateT * slot_144(struct StateT * v5576);
struct StateT * slot_267(struct StateT * v9706);
struct StateT * slot_492(struct StateT * v18712);
struct StateT * slot_201(struct StateT * v6655);
struct StateT * slot_600(struct StateT * v20882);
struct StateT * slot_63(struct StateT * v3928);
struct StateT * slot_570(struct StateT * v20290);
struct StateT * slot_195(struct StateT * v6549);
struct StateT * slot_326(struct StateT * v12383);
struct StateT * slot_303(struct StateT * v10756);
struct StateT * slot_511(struct StateT * v19088);
struct StateT * slot_335(struct StateT * v13024);
struct StateT * slot_223(struct StateT * v7356);
struct StateT * slot_316(struct StateT * v11720);
struct StateT * slot_424(struct StateT * v17423);
struct StateT * slot_332(struct StateT * v12812);
struct StateT * slot_237(struct StateT * v8167);
struct StateT * slot_41(struct StateT * v3185);
struct StateT * slot_39(struct StateT * v2990);
struct StateT * slot_508(struct StateT * v19004);
struct StateT * slot_668(struct StateT * v22348);
struct StateT * slot_537(struct StateT * v19605);
struct StateT * slot_60(struct StateT * v3875);
struct StateT * slot_289(struct StateT * v10171);
struct StateT * slot_238(struct StateT * v8187);
struct StateT * slot_112(struct StateT * v4928);
struct StateT * slot_256(struct StateT * v9236);
struct StateT * slot_544(struct StateT * v19738);
struct StateT * slot_573(struct StateT * v20351);
struct StateT * slot_567(struct StateT * v20213);
struct StateT * slot_16(struct StateT * v1409);
struct StateT * slot_245(struct StateT * v8589);
struct StateT * slot_113(struct StateT * v4956);
struct StateT * slot_302(struct StateT * v10658);
struct StateT * slot_388(struct StateT * v16782);
struct StateT * slot_191(struct StateT * v6465);
struct StateT * slot_103(struct StateT * v4736);
struct StateT * slot_487(struct StateT * v18617);
struct StateT * slot_324(struct StateT * v12269);
struct StateT * slot_645(struct StateT * v21731);
struct StateT * slot_440(struct StateT * v17719);
struct StateT * slot_633(struct StateT * v21512);
struct StateT * slot_547(struct StateT * v19819);
struct StateT * slot_518(struct StateT * v19218);
struct StateT * slot_95(struct StateT * v4597);
struct StateT * slot_451(struct StateT * v17940);
struct StateT * slot_458(struct StateT * v18066);
struct StateT * slot_415(struct StateT * v17256);
struct StateT * slot_613(struct StateT * v21136);
struct StateT * slot_354(struct StateT * v14444);
struct StateT * slot_531(struct StateT * v19499);
struct StateT * slot_115(struct StateT * v5012);
struct StateT * slot_78(struct StateT * v4246);
struct StateT * slot_321(struct StateT * v12056);
struct StateT * slot_317(struct StateT * v11741);
struct StateT * slot_558(struct StateT * v20026);
struct StateT * slot_205(struct StateT * v6725);
struct StateT * slot_674(struct StateT * v22546);
struct StateT * slot_193(struct StateT * v6507);
struct StateT * slot_554(struct StateT * v19956);
struct StateT * slot_375(struct StateT * v16056);
struct StateT * slot_650(struct StateT * v21834);
struct StateT * slot_637(struct StateT * v21585);
struct StateT * slot_331(struct StateT * v12795);
struct StateT * slot_676(struct StateT * v22664);
struct StateT * slot_380(struct StateT * v16413);
struct StateT * slot_636(struct StateT * v21565);
struct StateT * slot_412(struct StateT * v17203);
struct StateT * slot_381(struct StateT * v16518);
struct StateT * slot_478(struct StateT * v18442);
struct StateT * slot_646(struct StateT * v21751);
struct StateT * slot_627(struct StateT * v21395);
struct StateT * slot_675(struct StateT * v22559);
struct StateT * slot_246(struct StateT * v8694);
struct StateT * slot_210(struct StateT * v6822);
struct StateT * slot_472(struct StateT * v18336);
struct StateT * slot_657(struct StateT * v21961);
struct StateT * slot_284(struct StateT * v10079);
struct StateT * slot_52(struct StateT * v3698);
struct StateT * slot_83(struct StateT * v4332);
struct StateT * slot_209(struct StateT * v6802);
struct StateT * slot_420(struct StateT * v17342);
struct StateT * slot_3(struct StateT * v213);
struct StateT * slot_73(struct StateT * v4151);
struct StateT * slot_270(struct StateT * v9844);
struct StateT * slot_198(struct StateT * v6602);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_187(struct StateT * v6385);
struct StateT * slot_446(struct StateT * v17844);
struct StateT * slot_182(struct StateT * v6296);
struct StateT * slot_361(struct StateT * v15009);
struct StateT * slot_38(struct StateT * v2892);
struct StateT * slot_178(struct StateT * v6226);
struct StateT * slot_98(struct StateT * v4650);
struct StateT * slot_159(struct StateT * v5867);
struct StateT * slot_510(struct StateT * v19060);
struct StateT * slot_459(struct StateT * v18083);
struct StateT * slot_404(struct StateT * v17045);
struct StateT * slot_46(struct StateT * v3513);
struct StateT * slot_212(struct StateT * v6865);
struct StateT * slot_682(struct StateT * v23039);
struct StateT * slot_132(struct StateT * v5347);
struct StateT * slot_313(struct StateT * v11503);
struct StateT * slot_553(struct StateT * v19936);
struct StateT * slot_211(struct StateT * v6842);
struct StateT * slot_20(struct StateT * v1829);
struct StateT * slot_436(struct StateT * v17650);
struct StateT * slot_61(struct StateT * v3895);
struct StateT * slot_499(struct StateT * v18835);
struct StateT * slot_359(struct StateT * v14799);
struct StateT * slot_514(struct StateT * v19148);
struct StateT * slot_296(struct StateT * v10382);
struct StateT * slot_30(struct StateT * v2603);
struct StateT * slot_606(struct StateT * v20998);
struct StateT * slot_18(struct StateT * v1619);
struct StateT * slot_9(struct StateT * v801);
struct StateT * slot_300(struct StateT * v10540);
struct StateT * slot_183(struct StateT * v6312);
struct StateT * slot_282(struct StateT * v10043);
struct StateT * slot_309(struct StateT * v11188);
struct StateT * slot_362(struct StateT * v15029);
struct StateT * slot_43(struct StateT * v3381);
struct StateT * slot_76(struct StateT * v4210);
struct StateT * slot_6(struct StateT * v507);
struct StateT * slot_55(struct StateT * v3782);
struct StateT * slot_283(struct StateT * v10063);
struct StateT * slot_346(struct StateT * v13873);
struct StateT * slot_647(struct StateT * v21771);
struct StateT * slot_516(struct StateT * v19181);
struct StateT * slot_599(struct StateT * v20862);
struct StateT * slot_274(struct StateT * v9913);
struct StateT * slot_535(struct StateT * v19569);
struct StateT * slot_318(struct StateT * v11839);
struct StateT * slot_91(struct StateT * v4513);
struct StateT * slot_58(struct StateT * v3842);
struct StateT * slot_255(struct StateT * v9131);
struct StateT * slot_540(struct StateT * v19658);
struct StateT * slot_617(struct StateT * v21209);
struct StateT * slot_66(struct StateT * v3981);
struct StateT * slot_643(struct StateT * v21691);
struct StateT * slot_550(struct StateT * v19882);
struct StateT * slot_592(struct StateT * v20740);
struct StateT * slot_368(struct StateT * v15489);
struct StateT * slot_265(struct StateT * v9670);
struct StateT * slot_37(struct StateT * v2794);
struct StateT * slot_114(struct StateT * v4984);
struct StateT * slot_257(struct StateT * v9257);
struct StateT * slot_192(struct StateT * v6486);
struct StateT * slot_327(struct StateT * v12481);
struct StateT * slot_48(struct StateT * v3547);
struct StateT * slot_396(struct StateT * v16893);
struct StateT * slot_528(struct StateT * v19436);
struct StateT * slot_72(struct StateT * v4130);
struct StateT * slot_526(struct StateT * v19388);
struct StateT * slot_119(struct StateT * v5082);
struct StateT * slot_101(struct StateT * v4703);
struct StateT * slot_276(struct StateT * v9942);
struct StateT * slot_290(struct StateT * v10188);
struct StateT * slot_93(struct StateT * v4555);
struct StateT * slot_266(struct StateT * v9686);
struct StateT * slot_88(struct StateT * v4432);
struct StateT * slot_96(struct StateT * v4614);
struct StateT * slot_234(struct StateT * v7930);
struct StateT * slot_471(struct StateT * v18316);
struct StateT * slot_419(struct StateT * v17326);
struct StateT * slot_218(struct StateT * v7157);
struct StateT * slot_596(struct StateT * v20809);
struct StateT * slot_576(struct StateT * v20404);
struct StateT * slot_202(struct StateT * v6672);
struct StateT * slot_336(struct StateT * v13122);
struct StateT * slot_230(struct StateT * v7666);
struct StateT * slot_598(struct StateT * v20846);
struct StateT * slot_294(struct StateT * v10264);
struct StateT * slot_408(struct StateT * v17129);
struct StateT * slot_342(struct StateT * v13550);
struct StateT * slot_488(struct StateT * v18638);
struct StateT * slot_439(struct StateT * v17703);
struct StateT * slot_389(struct StateT * v16802);
struct StateT * slot_678(struct StateT * v22789);
struct StateT * slot_479(struct StateT * v18459);
struct StateT * slot_138(struct StateT * v5470);
struct StateT * slot_483(struct StateT * v18535);
struct StateT * slot_649(struct StateT * v21813);
struct StateT * slot_196(struct StateT * v6566);
struct StateT * slot_172(struct StateT * v6110);
struct StateT * slot_425(struct StateT * v17443);
struct StateT * slot_443(struct StateT * v17781);
struct StateT * slot_131(struct StateT * v5326);
struct StateT * slot_8(struct StateT * v703);
struct StateT * slot_534(struct StateT * v19552);
struct StateT * slot_597(struct StateT * v20829);
struct StateT * slot_180(struct StateT * v6259);
struct StateT * slot_504(struct StateT * v18932);
struct StateT * slot_512(struct StateT * v19112);
struct StateT * slot_496(struct StateT * v18782);
struct StateT * slot_494(struct StateT * v18745);
struct StateT * slot_607(struct StateT * v21019);
struct StateT * slot_242(struct StateT * v8444);
struct StateT * slot_605(struct StateT * v20977);
struct StateT * slot_328(struct StateT * v12579);
struct StateT * slot_402(struct StateT * v17004);
struct StateT * slot_200(struct StateT * v6635);
struct StateT * slot_149(struct StateT * v5671);
struct StateT * slot_527(struct StateT * v19415);
struct StateT * slot_5(struct StateT * v409);
struct StateT * slot_334(struct StateT * v13008);
struct StateT * slot_104(struct StateT * v4756);
struct StateT * slot_235(struct StateT * v8035);
struct StateT * slot_275(struct StateT * v9929);
struct StateT * slot_329(struct StateT * v12599);
struct StateT * slot_428(struct StateT * v17506);
struct StateT * slot_395(struct StateT * v16876);
struct StateT * slot_604(struct StateT * v20956);
struct StateT * slot_660(struct StateT * v22014);
struct StateT * slot_614(struct StateT * v21156);
struct StateT * slot_345(struct StateT * v13768);
struct StateT * slot_298(struct StateT * v10500);
struct StateT * slot_414(struct StateT * v17236);
struct StateT * slot_364(struct StateT * v15239);
struct StateT * slot_626(struct StateT * v21375);
struct StateT * slot_356(struct StateT * v14569);
struct StateT * slot_253(struct StateT * v9090);
struct StateT * slot_665(struct StateT * v22108);
struct StateT * slot_434(struct StateT * v17613);
struct StateT * slot_64(struct StateT * v3948);
struct StateT * slot_170(struct StateT * v6069);
struct StateT * slot_53(struct StateT * v3726);
struct StateT * slot_522(struct StateT * v19287);
struct StateT * slot_80(struct StateT * v4279);
struct StateT * slot_503(struct StateT * v18912);
struct StateT * slot_390(struct StateT * v16818);
struct StateT * slot_44(struct StateT * v3479);
struct StateT * slot_635(struct StateT * v21549);
struct StateT * slot_137(struct StateT * v5450);
struct StateT * slot_386(struct StateT * v16677);
struct StateT * slot_122(struct StateT * v5135);
struct StateT * slot_99(struct StateT * v4667);
struct StateT * slot_179(struct StateT * v6243);
struct StateT * slot_219(struct StateT * v7184);
struct StateT * slot_664(struct StateT * v22087);
struct StateT * slot_338(struct StateT * v13239);
struct StateT * slot_22(struct StateT * v2039);
struct StateT * slot_563(struct StateT * v20123);
struct StateT * slot_366(struct StateT * v15364);
struct StateT * slot_574(struct StateT * v20371);
struct StateT * slot_139(struct StateT * v5487);
struct StateT * slot_654(struct StateT * v21908);
struct StateT * slot_608(struct StateT * v21040);
struct StateT * slot_438(struct StateT * v17686);
struct StateT * slot_333(struct StateT * v12910);
struct StateT * slot_221(struct StateT * v7224);
struct StateT * slot_623(struct StateT * v21315);
struct StateT * slot_153(struct StateT * v5755);
struct StateT * slot_129(struct StateT * v5272);
struct StateT * slot_158(struct StateT * v5850);
struct StateT * slot_311(struct StateT * v11307);
struct StateT * slot_498(struct StateT * v18818);
struct StateT * slot_279(struct StateT * v9994);
struct StateT * slot_648(struct StateT * v21792);
struct StateT * slot_575(struct StateT * v20388);
struct StateT * slot_271(struct StateT * v9860);
struct StateT * slot_524(struct StateT * v19334);
struct StateT * slot_505(struct StateT * v18952);
struct StateT * slot_401(struct StateT * v16983);
struct StateT * slot_423(struct StateT * v17403);
struct StateT * slot_532(struct StateT * v19516);
struct StateT * slot_217(struct StateT * v7144);
struct StateT * slot_111(struct StateT * v4907);
struct StateT * slot_549(struct StateT * v19861);
struct StateT * slot_349(struct StateT * v14096);
struct StateT * slot_291(struct StateT * v10208);
struct StateT * slot_147(struct StateT * v5630);
struct StateT * slot_410(struct StateT * v17167);
struct StateT * slot_491(struct StateT * v18692);
struct StateT * slot_163(struct StateT * v5936);
struct StateT * slot_422(struct StateT * v17382);
struct StateT * slot_448(struct StateT * v17886);
struct StateT * slot_204(struct StateT * v6708);
struct StateT * slot_194(struct StateT * v6528);
struct StateT * slot_551(struct StateT * v19903);
struct StateT * slot_641(struct StateT * v21655);
struct StateT * slot_407(struct StateT * v17108);
struct StateT * slot_543(struct StateT * v19711);
struct StateT * slot_250(struct StateT * v8944);
struct StateT * slot_360(struct StateT * v14904);
struct StateT * slot_259(struct StateT * v9382);
struct StateT * slot_469(struct StateT * v18283);
struct StateT * slot_117(struct StateT * v5045);
struct StateT * slot_667(struct StateT * v22148);
struct StateT * slot_90(struct StateT * v4486);
struct StateT * slot_143(struct StateT * v5556) {
  int v5557 = v5556->timer;
  int v5567 = v5557 + 1;
  v5556->timer = v5567;
  int * v5559 = v5556->regs;
  int v5560 = v5559[16];
  int * v5561 = v5556->regs;
  int v5562 = v5561[5];
  int * v5563 = v5556->regs;
  int v5573 = v5560 | v5562;
  v5563[16] = v5573;
  struct StateT * v5565 = slot_144(v5556);
  return v5565;
}

struct StateT * slot_120(struct StateT * v5098) {
  int v5099 = v5098->timer;
  int v5109 = v5099 + 1;
  v5098->timer = v5109;
  int * v5101 = v5098->regs;
  int v5102 = v5101[16];
  int * v5103 = v5098->regs;
  int v5104 = v5103[6];
  int * v5105 = v5098->regs;
  int v5115 = v5102 | v5104;
  v5105[16] = v5115;
  struct StateT * v5107 = slot_121(v5098);
  return v5107;
}

struct StateT * slot_226(struct StateT * v7501) {
  int * v7502 = v7501->saved_regs;
  int * v7503 = v7501->regs;
  int v7504 = v7503[12];
  v7502[12] = v7504;
  int v7506 = v7501->timer;
  int v7520 = v7506 + 1;
  v7501->timer = v7520;
  int * v7508 = v7501->regs;
  int v7509 = v7508[12];
  int * v7510 = v7501->regs;
  int v7511 = v7510[6];
  int * v7512 = v7501->regs;
  int v7525 = v7509 + v7511;
  v7512[12] = v7525;
  struct StateT * v7514 = slot_228(v7501);
  return v7514;
}

struct StateT * slot_167(struct StateT * v6009) {
  int v6010 = v6009->timer;
  int v6020 = v6010 + 1;
  v6009->timer = v6020;
  int * v6012 = v6009->regs;
  int v6013 = v6012[27];
  int * v6014 = v6009->regs;
  int v6015 = v6014[11];
  int * v6016 = v6009->regs;
  int v6026 = v6013 ^ v6015;
  v6016[27] = v6026;
  struct StateT * v6018 = slot_168(v6009);
  return v6018;
}

struct StateT * slot_509(struct StateT * v19032) {
  int * v19033 = v19032->saved_regs;
  int * v19034 = v19032->regs;
  int v19035 = v19034[18];
  v19033[18] = v19035;
  int v19037 = v19032->timer;
  int v19051 = v19037 + 1;
  v19032->timer = v19051;
  int * v19039 = v19032->regs;
  int v19040 = v19039[19];
  int * v19041 = v19032->regs;
  int v19042 = v19041[5];
  int * v19043 = v19032->regs;
  int v19057 = v19040 + v19042;
  v19043[18] = v19057;
  struct StateT * v19045 = slot_510(v19032);
  return v19045;
}

struct StateT * slot_152(struct StateT * v5734) {
  int v5735 = v5734->timer;
  int v5745 = v5735 + 1;
  v5734->timer = v5745;
  int * v5737 = v5734->regs;
  int v5738 = v5737[5];
  int * v5739 = v5734->regs;
  int v5740 = v5739[20];
  int * v5741 = v5734->regs;
  int v5752 = v5738 + v5740;
  v5741[15] = v5752;
  struct StateT * v5743 = slot_153(v5734);
  return v5743;
}

struct StateT * slot_429(struct StateT * v17527) {
  int v17528 = v17527->timer;
  int v17536 = v17528 + 1;
  v17527->timer = v17536;
  int * v17530 = v17527->regs;
  int v17531 = v17530[15];
  int * v17532 = v17527->regs;
  int v17541 = (int)((unsigned int)v17531 >> 25);
  v17532[5] = v17541;
  struct StateT * v17534 = slot_430(v17527);
  return v17534;
}

struct StateT * slot_231(struct StateT * v7778) {
  int v7779 = v7778->timer;
  int v7837 = v7779 + 1;
  v7778->timer = v7837;
  int * v7781 = v7778->regs;
  int v7782 = v7781[2];
  int * v7783 = v7778->cache_keys;
  int v7784 = v7783[0];
  bool v7842 = v7784 == ((int)((unsigned int)(v7782 + 16) >> 2));
  int v7832;
  if (v7842) {
    int * v7785 = v7778->cache_vals;
    int v7786 = v7785[0];
    v7832 = v7786;
  } else {
    int * v7788 = v7778->cache_keys;
    int v7789 = v7788[1];
    bool v7847 = v7789 == ((int)((unsigned int)(v7782 + 16) >> 2));
    int v7830;
    if (v7847) {
      int * v7790 = v7778->cache_vals;
      int v7791 = v7790[1];
      int * v7792 = v7778->cache_keys;
      int * v7793 = v7778->cache_keys;
      int v7794 = v7793[0];
      v7792[1] = v7794;
      int * v7796 = v7778->cache_vals;
      int * v7797 = v7778->cache_vals;
      int v7798 = v7797[0];
      v7796[1] = v7798;
      int * v7800 = v7778->cache_keys;
      int v7856 = (int)((unsigned int)(v7782 + 16) >> 2);
      v7800[0] = v7856;
      int * v7802 = v7778->cache_vals;
      v7802[0] = v7791;
      int v7804 = v7778->timer;
      int v7859 = v7804 + 1;
      v7778->timer = v7859;
      v7830 = v7791;
    } else {
      int * v7807 = v7778->mem;
      int v7861 = (int)((unsigned int)(v7782 + 16) >> 2);
      int v7808 = v7807[v7861];
      int * v7809 = v7778->mem;
      int * v7810 = v7778->cache_keys;
      int v7811 = v7810[1];
      int * v7812 = v7778->cache_vals;
      int v7813 = v7812[1];
      v7809[v7811] = v7813;
      int * v7815 = v7778->cache_keys;
      int * v7816 = v7778->cache_keys;
      int v7817 = v7816[0];
      v7815[1] = v7817;
      int * v7819 = v7778->cache_vals;
      int * v7820 = v7778->cache_vals;
      int v7821 = v7820[0];
      v7819[1] = v7821;
      int * v7823 = v7778->cache_keys;
      v7823[0] = v7861;
      int * v7825 = v7778->cache_vals;
      v7825[0] = v7808;
      int v7827 = v7778->timer;
      int v7876 = v7827 + 100;
      v7778->timer = v7876;
      v7830 = v7808;
    }
    v7832 = v7830;
  }
  int * v7833 = v7778->regs;
  v7833[7] = v7832;
  struct StateT * v7835 = slot_233(v7778);
  return v7835;
}

struct StateT * slot_355(struct StateT * v14549) {
  int v14550 = v14549->timer;
  int v14560 = v14550 + 1;
  v14549->timer = v14560;
  int * v14552 = v14549->regs;
  int v14553 = v14552[18];
  int * v14554 = v14549->regs;
  int v14555 = v14554[20];
  int * v14556 = v14549->regs;
  int v14566 = v14553 | v14555;
  v14556[18] = v14566;
  struct StateT * v14558 = slot_358(v14549);
  return v14558;
}

struct StateT * slot_92(struct StateT * v4534) {
  int v4535 = v4534->timer;
  int v4545 = v4535 + 1;
  v4534->timer = v4545;
  int * v4537 = v4534->regs;
  int v4538 = v4537[24];
  int * v4539 = v4534->regs;
  int v4540 = v4539[13];
  int * v4541 = v4534->regs;
  int v4552 = v4538 + v4540;
  v4541[8] = v4552;
  struct StateT * v4543 = slot_93(v4534);
  return v4543;
}

struct StateT * slot_616(struct StateT * v21189) {
  int v21190 = v21189->timer;
  int v21200 = v21190 + 1;
  v21189->timer = v21200;
  int * v21192 = v21189->regs;
  int v21193 = v21192[15];
  int * v21194 = v21189->regs;
  int v21195 = v21194[9];
  int * v21196 = v21189->regs;
  int v21206 = v21193 | v21195;
  v21196[15] = v21206;
  struct StateT * v21198 = slot_617(v21189);
  return v21198;
}

struct StateT * slot_232(struct StateT * v7883) {
  int * v7884 = v7883->saved_regs;
  int * v7885 = v7883->regs;
  int v7886 = v7885[5];
  v7884[5] = v7886;
  int v7888 = v7883->timer;
  int v7902 = v7888 + 1;
  v7883->timer = v7902;
  int * v7890 = v7883->regs;
  int v7891 = v7890[5];
  int * v7892 = v7883->regs;
  int v7893 = v7892[7];
  int * v7894 = v7883->regs;
  int v7907 = v7891 + v7893;
  v7894[5] = v7907;
  struct StateT * v7896 = slot_234(v7883);
  return v7896;
}

struct StateT * slot_466(struct StateT * v18220) {
  int v18221 = v18220->timer;
  int v18231 = v18221 + 1;
  v18220->timer = v18231;
  int * v18223 = v18220->regs;
  int v18224 = v18223[25];
  int * v18225 = v18220->regs;
  int v18226 = v18225[5];
  int * v18227 = v18220->regs;
  int v18238 = v18224 + v18226;
  v18227[15] = v18238;
  struct StateT * v18229 = slot_467(v18220);
  return v18229;
}

struct StateT * slot_304(struct StateT * v10854) {
  int v10855 = v10854->timer;
  int v10865 = v10855 + 1;
  v10854->timer = v10865;
  int * v10857 = v10854->regs;
  int v10858 = v10857[1];
  int * v10859 = v10854->regs;
  int v10860 = v10859[18];
  int * v10861 = v10854->regs;
  int v10871 = v10858 ^ v10860;
  v10861[1] = v10871;
  struct StateT * v10863 = slot_307(v10854);
  return v10863;
}

struct StateT * slot_31(struct StateT * v2620) {
  int v2621 = v2620->timer;
  int v2629 = v2621 + 1;
  v2620->timer = v2629;
  int * v2623 = v2620->regs;
  int v2624 = v2623[13];
  int * v2625 = v2620->regs;
  int v2634 = v2624 + 1134;
  v2625[11] = v2634;
  struct StateT * v2627 = slot_32(v2620);
  return v2627;
}

struct StateT * slot_236(struct StateT * v8140) {
  int * v8141 = v8140->saved_regs;
  int * v8142 = v8140->regs;
  int v8143 = v8142[25];
  v8141[25] = v8143;
  int v8145 = v8140->timer;
  int v8159 = v8145 + 1;
  v8140->timer = v8159;
  int * v8147 = v8140->regs;
  int v8148 = v8147[25];
  int * v8149 = v8140->regs;
  int v8150 = v8149[7];
  int * v8151 = v8140->regs;
  int v8164 = v8148 + v8150;
  v8151[25] = v8164;
  struct StateT * v8153 = slot_238(v8140);
  return v8153;
}

struct StateT * slot_585(struct StateT * v20578) {
  int * v20579 = v20578->saved_regs;
  int * v20580 = v20578->regs;
  int v20581 = v20580[19];
  v20579[19] = v20581;
  int v20583 = v20578->timer;
  int v20597 = v20583 + 1;
  v20578->timer = v20597;
  int * v20585 = v20578->regs;
  int v20586 = v20585[19];
  int * v20587 = v20578->regs;
  int v20588 = v20587[17];
  int * v20589 = v20578->regs;
  int v20602 = v20586 ^ v20588;
  v20589[19] = v20602;
  struct StateT * v20591 = slot_586(v20578);
  return v20591;
}

struct StateT * slot_241(struct StateT * v8424) {
  int v8425 = v8424->timer;
  int v8435 = v8425 + 1;
  v8424->timer = v8435;
  int * v8427 = v8424->regs;
  int v8428 = v8427[13];
  int * v8429 = v8424->regs;
  int v8430 = v8429[7];
  int * v8431 = v8424->regs;
  int v8441 = v8428 + v8430;
  v8431[13] = v8441;
  struct StateT * v8433 = slot_243(v8424);
  return v8433;
}

struct StateT * slot_611(struct StateT * v21103) {
  int v21104 = v21103->timer;
  int v21112 = v21104 + 1;
  v21103->timer = v21112;
  int * v21106 = v21103->regs;
  int v21107 = v21106[11];
  int * v21108 = v21103->regs;
  int v21117 = (int)((unsigned int)v21107 >> 23);
  v21108[9] = v21117;
  struct StateT * v21110 = slot_612(v21103);
  return v21110;
}

struct StateT * slot_160(struct StateT * v5883) {
  int v5884 = v5883->timer;
  int v5894 = v5884 + 1;
  v5883->timer = v5894;
  int * v5886 = v5883->regs;
  int v5887 = v5886[15];
  int * v5888 = v5883->regs;
  int v5889 = v5888[9];
  int * v5890 = v5883->regs;
  int v5900 = v5887 | v5889;
  v5890[15] = v5900;
  struct StateT * v5892 = slot_161(v5883);
  return v5892;
}

struct StateT * slot_519(struct StateT * v19234) {
  int v19235 = v19234->timer;
  int v19245 = v19235 + 1;
  v19234->timer = v19245;
  int * v19237 = v19234->regs;
  int v19238 = v19237[18];
  int * v19239 = v19234->regs;
  int v19240 = v19239[20];
  int * v19241 = v19234->regs;
  int v19251 = v19238 | v19240;
  v19241[18] = v19251;
  struct StateT * v19243 = slot_520(v19234);
  return v19243;
}

struct StateT * slot_150(struct StateT * v5692) {
  int v5693 = v5692->timer;
  int v5703 = v5693 + 1;
  v5692->timer = v5703;
  int * v5695 = v5692->regs;
  int v5696 = v5695[9];
  int * v5697 = v5692->regs;
  int v5698 = v5697[6];
  int * v5699 = v5692->regs;
  int v5710 = v5696 ^ v5698;
  v5699[16] = v5710;
  struct StateT * v5701 = slot_151(v5692);
  return v5701;
}

struct StateT * slot_391(struct StateT * v16835) {
  int v16836 = v16835->timer;
  int v16839 = v16836 + 1;
  v16835->timer = v16839;
  return v16835;
}

struct StateT * slot_74(struct StateT * v4172) {
  int v4173 = v4172->timer;
  int v4183 = v4173 + 1;
  v4172->timer = v4183;
  int * v4175 = v4172->regs;
  int v4176 = v4175[14];
  int * v4177 = v4172->regs;
  int v4178 = v4177[22];
  int * v4179 = v4172->regs;
  int v4190 = v4176 + v4178;
  v4179[18] = v4190;
  struct StateT * v4181 = slot_75(v4172);
  return v4181;
}

struct StateT * slot_580(struct StateT * v20477) {
  int v20478 = v20477->timer;
  int v20486 = v20478 + 1;
  v20477->timer = v20486;
  int * v20480 = v20477->regs;
  int v20481 = v20480[5];
  int * v20482 = v20477->regs;
  int v20491 = (int)((unsigned int)v20481 >> 14);
  v20482[6] = v20491;
  struct StateT * v20484 = slot_581(v20477);
  return v20484;
}

struct StateT * slot_262(struct StateT * v9528) {
  int v9529 = v9528->timer;
  int v9537 = v9529 + 1;
  v9528->timer = v9537;
  int * v9531 = v9528->regs;
  int v9532 = v9531[15];
  int * v9533 = v9528->regs;
  int v9542 = (int)((unsigned int)v9532 >> 25);
  v9533[9] = v9542;
  struct StateT * v9535 = slot_265(v9528);
  return v9535;
}

struct StateT * slot_351(struct StateT * v14218) {
  int v14219 = v14218->timer;
  int v14277 = v14219 + 1;
  v14218->timer = v14277;
  int * v14221 = v14218->regs;
  int v14222 = v14221[2];
  int * v14223 = v14218->cache_keys;
  int v14224 = v14223[0];
  bool v14282 = v14224 == ((int)((unsigned int)(v14222 + 80) >> 2));
  int v14272;
  if (v14282) {
    int * v14225 = v14218->cache_vals;
    int v14226 = v14225[0];
    v14272 = v14226;
  } else {
    int * v14228 = v14218->cache_keys;
    int v14229 = v14228[1];
    bool v14287 = v14229 == ((int)((unsigned int)(v14222 + 80) >> 2));
    int v14270;
    if (v14287) {
      int * v14230 = v14218->cache_vals;
      int v14231 = v14230[1];
      int * v14232 = v14218->cache_keys;
      int * v14233 = v14218->cache_keys;
      int v14234 = v14233[0];
      v14232[1] = v14234;
      int * v14236 = v14218->cache_vals;
      int * v14237 = v14218->cache_vals;
      int v14238 = v14237[0];
      v14236[1] = v14238;
      int * v14240 = v14218->cache_keys;
      int v14296 = (int)((unsigned int)(v14222 + 80) >> 2);
      v14240[0] = v14296;
      int * v14242 = v14218->cache_vals;
      v14242[0] = v14231;
      int v14244 = v14218->timer;
      int v14299 = v14244 + 1;
      v14218->timer = v14299;
      v14270 = v14231;
    } else {
      int * v14247 = v14218->mem;
      int v14301 = (int)((unsigned int)(v14222 + 80) >> 2);
      int v14248 = v14247[v14301];
      int * v14249 = v14218->mem;
      int * v14250 = v14218->cache_keys;
      int v14251 = v14250[1];
      int * v14252 = v14218->cache_vals;
      int v14253 = v14252[1];
      v14249[v14251] = v14253;
      int * v14255 = v14218->cache_keys;
      int * v14256 = v14218->cache_keys;
      int v14257 = v14256[0];
      v14255[1] = v14257;
      int * v14259 = v14218->cache_vals;
      int * v14260 = v14218->cache_vals;
      int v14261 = v14260[0];
      v14259[1] = v14261;
      int * v14263 = v14218->cache_keys;
      v14263[0] = v14301;
      int * v14265 = v14218->cache_vals;
      v14265[0] = v14248;
      int v14267 = v14218->timer;
      int v14316 = v14267 + 100;
      v14218->timer = v14316;
      v14270 = v14248;
    }
    v14272 = v14270;
  }
  int * v14273 = v14218->regs;
  v14273[18] = v14272;
  struct StateT * v14275 = slot_354(v14218);
  return v14275;
}

struct StateT * slot_372(struct StateT * v15825) {
  int v15826 = v15825->timer;
  int v15884 = v15826 + 1;
  v15825->timer = v15884;
  int * v15828 = v15825->regs;
  int v15829 = v15828[2];
  int * v15830 = v15825->cache_keys;
  int v15831 = v15830[0];
  bool v15889 = v15831 == ((int)((unsigned int)(v15829 + 52) >> 2));
  int v15879;
  if (v15889) {
    int * v15832 = v15825->cache_vals;
    int v15833 = v15832[0];
    v15879 = v15833;
  } else {
    int * v15835 = v15825->cache_keys;
    int v15836 = v15835[1];
    bool v15894 = v15836 == ((int)((unsigned int)(v15829 + 52) >> 2));
    int v15877;
    if (v15894) {
      int * v15837 = v15825->cache_vals;
      int v15838 = v15837[1];
      int * v15839 = v15825->cache_keys;
      int * v15840 = v15825->cache_keys;
      int v15841 = v15840[0];
      v15839[1] = v15841;
      int * v15843 = v15825->cache_vals;
      int * v15844 = v15825->cache_vals;
      int v15845 = v15844[0];
      v15843[1] = v15845;
      int * v15847 = v15825->cache_keys;
      int v15903 = (int)((unsigned int)(v15829 + 52) >> 2);
      v15847[0] = v15903;
      int * v15849 = v15825->cache_vals;
      v15849[0] = v15838;
      int v15851 = v15825->timer;
      int v15906 = v15851 + 1;
      v15825->timer = v15906;
      v15877 = v15838;
    } else {
      int * v15854 = v15825->mem;
      int v15908 = (int)((unsigned int)(v15829 + 52) >> 2);
      int v15855 = v15854[v15908];
      int * v15856 = v15825->mem;
      int * v15857 = v15825->cache_keys;
      int v15858 = v15857[1];
      int * v15859 = v15825->cache_vals;
      int v15860 = v15859[1];
      v15856[v15858] = v15860;
      int * v15862 = v15825->cache_keys;
      int * v15863 = v15825->cache_keys;
      int v15864 = v15863[0];
      v15862[1] = v15864;
      int * v15866 = v15825->cache_vals;
      int * v15867 = v15825->cache_vals;
      int v15868 = v15867[0];
      v15866[1] = v15868;
      int * v15870 = v15825->cache_keys;
      v15870[0] = v15908;
      int * v15872 = v15825->cache_vals;
      v15872[0] = v15855;
      int v15874 = v15825->timer;
      int v15923 = v15874 + 100;
      v15825->timer = v15923;
      v15877 = v15855;
    }
    v15879 = v15877;
  }
  int * v15880 = v15825->regs;
  v15880[25] = v15879;
  struct StateT * v15882 = slot_375(v15825);
  return v15882;
}

struct StateT * slot_677(struct StateT * v22684) {
  int v22685 = v22684->timer;
  int v22743 = v22685 + 1;
  v22684->timer = v22743;
  int * v22687 = v22684->regs;
  int v22688 = v22687[2];
  int * v22689 = v22684->cache_keys;
  int v22690 = v22689[0];
  bool v22748 = v22690 == ((int)((unsigned int)(v22688 + 16) >> 2));
  int v22738;
  if (v22748) {
    int * v22691 = v22684->cache_vals;
    int v22692 = v22691[0];
    v22738 = v22692;
  } else {
    int * v22694 = v22684->cache_keys;
    int v22695 = v22694[1];
    bool v22753 = v22695 == ((int)((unsigned int)(v22688 + 16) >> 2));
    int v22736;
    if (v22753) {
      int * v22696 = v22684->cache_vals;
      int v22697 = v22696[1];
      int * v22698 = v22684->cache_keys;
      int * v22699 = v22684->cache_keys;
      int v22700 = v22699[0];
      v22698[1] = v22700;
      int * v22702 = v22684->cache_vals;
      int * v22703 = v22684->cache_vals;
      int v22704 = v22703[0];
      v22702[1] = v22704;
      int * v22706 = v22684->cache_keys;
      int v22762 = (int)((unsigned int)(v22688 + 16) >> 2);
      v22706[0] = v22762;
      int * v22708 = v22684->cache_vals;
      v22708[0] = v22697;
      int v22710 = v22684->timer;
      int v22765 = v22710 + 1;
      v22684->timer = v22765;
      v22736 = v22697;
    } else {
      int * v22713 = v22684->mem;
      int v22767 = (int)((unsigned int)(v22688 + 16) >> 2);
      int v22714 = v22713[v22767];
      int * v22715 = v22684->mem;
      int * v22716 = v22684->cache_keys;
      int v22717 = v22716[1];
      int * v22718 = v22684->cache_vals;
      int v22719 = v22718[1];
      v22715[v22717] = v22719;
      int * v22721 = v22684->cache_keys;
      int * v22722 = v22684->cache_keys;
      int v22723 = v22722[0];
      v22721[1] = v22723;
      int * v22725 = v22684->cache_vals;
      int * v22726 = v22684->cache_vals;
      int v22727 = v22726[0];
      v22725[1] = v22727;
      int * v22729 = v22684->cache_keys;
      v22729[0] = v22767;
      int * v22731 = v22684->cache_vals;
      v22731[0] = v22714;
      int v22733 = v22684->timer;
      int v22782 = v22733 + 100;
      v22684->timer = v22782;
      v22736 = v22714;
    }
    v22738 = v22736;
  }
  int * v22739 = v22684->regs;
  v22739[7] = v22738;
  struct StateT * v22741 = slot_678(v22684);
  return v22741;
}

struct StateT * slot_403(struct StateT * v17024) {
  int v17025 = v17024->timer;
  int v17035 = v17025 + 1;
  v17024->timer = v17035;
  int * v17027 = v17024->regs;
  int v17028 = v17027[5];
  int * v17029 = v17024->regs;
  int v17030 = v17029[20];
  int * v17031 = v17024->regs;
  int v17042 = v17028 ^ v17030;
  v17031[18] = v17042;
  struct StateT * v17033 = slot_404(v17024);
  return v17033;
}

struct StateT * slot_107(struct StateT * v4817) {
  int v4818 = v4817->timer;
  int v4828 = v4818 + 1;
  v4817->timer = v4828;
  int * v4820 = v4817->regs;
  int v4821 = v4820[16];
  int * v4822 = v4817->regs;
  int v4823 = v4822[15];
  int * v4824 = v4817->regs;
  int v4835 = v4821 ^ v4823;
  v4824[9] = v4835;
  struct StateT * v4826 = slot_108(v4817);
  return v4826;
}

struct StateT * slot_555(struct StateT * v19973) {
  int v19974 = v19973->timer;
  int v19982 = v19974 + 1;
  v19973->timer = v19982;
  int * v19976 = v19973->regs;
  int v19977 = v19976[8];
  int * v19978 = v19973->regs;
  int v19986 = v19977 << 13;
  v19978[8] = v19986;
  struct StateT * v19980 = slot_556(v19973);
  return v19980;
}

struct StateT * slot_541(struct StateT * v19675) {
  int v19676 = v19675->timer;
  int v19684 = v19676 + 1;
  v19675->timer = v19684;
  int * v19678 = v19675->regs;
  int v19679 = v19678[18];
  int * v19680 = v19675->regs;
  int v19688 = v19679 << 9;
  v19680[18] = v19688;
  struct StateT * v19682 = slot_542(v19675);
  return v19682;
}

struct StateT * slot_325(struct StateT * v12367) {
  int v12368 = v12367->timer;
  int v12376 = v12368 + 1;
  v12367->timer = v12376;
  int * v12370 = v12367->regs;
  int v12371 = v12370[15];
  int * v12372 = v12367->regs;
  int v12380 = v12371 << 9;
  v12372[15] = v12380;
  struct StateT * v12374 = slot_328(v12367);
  return v12374;
}

struct StateT * slot_84(struct StateT * v4352) {
  int v4353 = v4352->timer;
  int v4361 = v4353 + 1;
  v4352->timer = v4361;
  int * v4355 = v4352->regs;
  int v4356 = v4355[18];
  int * v4357 = v4352->regs;
  int v4366 = (int)((unsigned int)v4356 >> 23);
  v4357[20] = v4366;
  struct StateT * v4359 = slot_85(v4352);
  return v4359;
}

struct StateT * slot_28(struct StateT * v2577) {
  int v2578 = v2577->timer;
  int v2584 = v2578 + 1;
  v2577->timer = v2584;
  int * v2580 = v2577->regs;
  v2580[13] = 857759744;
  struct StateT * v2582 = slot_29(v2577);
  return v2582;
}

struct StateT * slot_155(struct StateT * v5797) {
  int v5798 = v5797->timer;
  int v5806 = v5798 + 1;
  v5797->timer = v5806;
  int * v5800 = v5797->regs;
  int v5801 = v5800[11];
  int * v5802 = v5797->regs;
  int v5811 = (int)((unsigned int)v5801 >> 23);
  v5802[9] = v5811;
  struct StateT * v5804 = slot_156(v5797);
  return v5804;
}

struct StateT * slot_177(struct StateT * v6206) {
  int v6207 = v6206->timer;
  int v6217 = v6207 + 1;
  v6206->timer = v6217;
  int * v6209 = v6206->regs;
  int v6210 = v6209[11];
  int * v6211 = v6206->regs;
  int v6212 = v6211[9];
  int * v6213 = v6206->regs;
  int v6223 = v6210 | v6212;
  v6213[11] = v6223;
  struct StateT * v6215 = slot_178(v6206);
  return v6215;
}

struct StateT * slot_517(struct StateT * v19201) {
  int v19202 = v19201->timer;
  int v19210 = v19202 + 1;
  v19201->timer = v19210;
  int * v19204 = v19201->regs;
  int v19205 = v19204[18];
  int * v19206 = v19201->regs;
  int v19215 = (int)((unsigned int)v19205 >> 25);
  v19206[20] = v19215;
  struct StateT * v19208 = slot_518(v19201);
  return v19208;
}

struct StateT * slot_229(struct StateT * v7646) {
  int v7647 = v7646->timer;
  int v7657 = v7647 + 1;
  v7646->timer = v7657;
  int * v7649 = v7646->regs;
  int v7650 = v7649[5];
  int * v7651 = v7646->regs;
  int v7652 = v7651[7];
  int * v7653 = v7646->regs;
  int v7663 = v7650 + v7652;
  v7653[5] = v7663;
  struct StateT * v7655 = slot_231(v7646);
  return v7655;
}

struct StateT * slot_358(struct StateT * v14779) {
  int v14780 = v14779->timer;
  int v14790 = v14780 + 1;
  v14779->timer = v14790;
  int * v14782 = v14779->regs;
  int v14783 = v14782[26];
  int * v14784 = v14779->regs;
  int v14785 = v14784[15];
  int * v14786 = v14779->regs;
  int v14796 = v14783 ^ v14785;
  v14786[26] = v14796;
  struct StateT * v14788 = slot_361(v14779);
  return v14788;
}

struct StateT * slot_465(struct StateT * v18199) {
  int v18200 = v18199->timer;
  int v18210 = v18200 + 1;
  v18199->timer = v18210;
  int * v18202 = v18199->regs;
  int v18203 = v18202[27];
  int * v18204 = v18199->regs;
  int v18205 = v18204[23];
  int * v18206 = v18199->regs;
  int v18217 = v18203 + v18205;
  v18206[11] = v18217;
  struct StateT * v18208 = slot_466(v18199);
  return v18208;
}

struct StateT * slot_181(struct StateT * v6279) {
  int v6280 = v6279->timer;
  int v6288 = v6280 + 1;
  v6279->timer = v6288;
  int * v6282 = v6279->regs;
  int v6283 = v6282[6];
  int * v6284 = v6279->regs;
  int v6293 = (int)((unsigned int)v6283 >> 19);
  v6284[9] = v6293;
  struct StateT * v6286 = slot_182(v6279);
  return v6286;
}

struct StateT * slot_542(struct StateT * v19691) {
  int v19692 = v19691->timer;
  int v19702 = v19692 + 1;
  v19691->timer = v19702;
  int * v19694 = v19691->regs;
  int v19695 = v19694[18];
  int * v19696 = v19691->regs;
  int v19697 = v19696[20];
  int * v19698 = v19691->regs;
  int v19708 = v19695 | v19697;
  v19698[18] = v19708;
  struct StateT * v19700 = slot_543(v19691);
  return v19700;
}

struct StateT * slot_566(struct StateT * v20192) {
  int v20193 = v20192->timer;
  int v20203 = v20193 + 1;
  v20192->timer = v20203;
  int * v20195 = v20192->regs;
  int v20196 = v20195[17];
  int * v20197 = v20192->regs;
  int v20198 = v20197[6];
  int * v20199 = v20192->regs;
  int v20210 = v20196 ^ v20198;
  v20199[8] = v20210;
  struct StateT * v20201 = slot_567(v20192);
  return v20201;
}

struct StateT * slot_679(struct StateT * v22809) {
  int v22810 = v22809->timer;
  int v22868 = v22810 + 1;
  v22809->timer = v22868;
  int * v22812 = v22809->regs;
  int v22813 = v22812[2];
  int * v22814 = v22809->cache_keys;
  int v22815 = v22814[0];
  bool v22873 = v22815 == ((int)((unsigned int)(v22813 + 20) >> 2));
  int v22863;
  if (v22873) {
    int * v22816 = v22809->cache_vals;
    int v22817 = v22816[0];
    v22863 = v22817;
  } else {
    int * v22819 = v22809->cache_keys;
    int v22820 = v22819[1];
    bool v22878 = v22820 == ((int)((unsigned int)(v22813 + 20) >> 2));
    int v22861;
    if (v22878) {
      int * v22821 = v22809->cache_vals;
      int v22822 = v22821[1];
      int * v22823 = v22809->cache_keys;
      int * v22824 = v22809->cache_keys;
      int v22825 = v22824[0];
      v22823[1] = v22825;
      int * v22827 = v22809->cache_vals;
      int * v22828 = v22809->cache_vals;
      int v22829 = v22828[0];
      v22827[1] = v22829;
      int * v22831 = v22809->cache_keys;
      int v22887 = (int)((unsigned int)(v22813 + 20) >> 2);
      v22831[0] = v22887;
      int * v22833 = v22809->cache_vals;
      v22833[0] = v22822;
      int v22835 = v22809->timer;
      int v22890 = v22835 + 1;
      v22809->timer = v22890;
      v22861 = v22822;
    } else {
      int * v22838 = v22809->mem;
      int v22892 = (int)((unsigned int)(v22813 + 20) >> 2);
      int v22839 = v22838[v22892];
      int * v22840 = v22809->mem;
      int * v22841 = v22809->cache_keys;
      int v22842 = v22841[1];
      int * v22843 = v22809->cache_vals;
      int v22844 = v22843[1];
      v22840[v22842] = v22844;
      int * v22846 = v22809->cache_keys;
      int * v22847 = v22809->cache_keys;
      int v22848 = v22847[0];
      v22846[1] = v22848;
      int * v22850 = v22809->cache_vals;
      int * v22851 = v22809->cache_vals;
      int v22852 = v22851[0];
      v22850[1] = v22852;
      int * v22854 = v22809->cache_keys;
      v22854[0] = v22892;
      int * v22856 = v22809->cache_vals;
      v22856[0] = v22839;
      int v22858 = v22809->timer;
      int v22907 = v22858 + 100;
      v22809->timer = v22907;
      v22861 = v22839;
    }
    v22863 = v22861;
  }
  int * v22864 = v22809->regs;
  v22864[7] = v22863;
  struct StateT * v22866 = slot_680(v22809);
  return v22866;
}

struct StateT * slot_154(struct StateT * v5776) {
  int v5777 = v5776->timer;
  int v5787 = v5777 + 1;
  v5776->timer = v5787;
  int * v5779 = v5776->regs;
  int v5780 = v5779[16];
  int * v5781 = v5776->regs;
  int v5782 = v5781[22];
  int * v5783 = v5776->regs;
  int v5794 = v5780 + v5782;
  v5783[8] = v5794;
  struct StateT * v5785 = slot_155(v5776);
  return v5785;
}

struct StateT * slot_669(struct StateT * v22368) {
  int v22369 = v22368->timer;
  int v22379 = v22369 + 1;
  v22368->timer = v22379;
  int * v22371 = v22368->regs;
  int v22372 = v22371[27];
  int * v22373 = v22368->regs;
  int v22374 = v22373[28];
  int * v22375 = v22368->regs;
  int v22385 = v22372 + v22374;
  v22375[28] = v22385;
  struct StateT * v22377 = slot_670(v22368);
  return v22377;
}

struct StateT * slot_260(struct StateT * v9403) {
  int v9404 = v9403->timer;
  int v9414 = v9404 + 1;
  v9403->timer = v9414;
  int * v9406 = v9403->regs;
  int v9407 = v9406[16];
  int * v9408 = v9403->regs;
  int v9409 = v9408[30];
  int * v9410 = v9403->regs;
  int v9420 = v9407 + v9409;
  v9410[16] = v9420;
  struct StateT * v9412 = slot_263(v9403);
  return v9412;
}

struct StateT * slot_481(struct StateT * v18495) {
  int v18496 = v18495->timer;
  int v18506 = v18496 + 1;
  v18495->timer = v18506;
  int * v18498 = v18495->regs;
  int v18499 = v18498[14];
  int * v18500 = v18495->regs;
  int v18501 = v18500[11];
  int * v18502 = v18495->regs;
  int v18512 = v18499 ^ v18501;
  v18502[14] = v18512;
  struct StateT * v18504 = slot_482(v18495);
  return v18504;
}

struct StateT * slot_620(struct StateT * v21262) {
  int v21263 = v21262->timer;
  int v21271 = v21263 + 1;
  v21262->timer = v21271;
  int * v21265 = v21262->regs;
  int v21266 = v21265[8];
  int * v21267 = v21262->regs;
  int v21276 = (int)((unsigned int)v21266 >> 23);
  v21267[9] = v21276;
  struct StateT * v21269 = slot_621(v21262);
  return v21269;
}

struct StateT * slot_305(struct StateT * v10874) {
  int v10875 = v10874->timer;
  int v10929 = v10875 + 1;
  v10874->timer = v10929;
  int * v10877 = v10874->regs;
  int v10878 = v10877[10];
  int * v10879 = v10874->regs;
  int v10880 = v10879[29];
  int * v10881 = v10874->cache_keys;
  int v10882 = v10881[0];
  bool v10936 = v10882 == ((int)((unsigned int)(v10878 + 4) >> 2));
  int v10926;
  if (v10936) {
    int * v10883 = v10874->cache_vals;
    v10883[0] = v10880;
    v10926 = v10880;
  } else {
    int * v10886 = v10874->cache_keys;
    int v10887 = v10886[1];
    bool v10941 = v10887 == ((int)((unsigned int)(v10878 + 4) >> 2));
    int v10924;
    if (v10941) {
      int * v10888 = v10874->cache_keys;
      int * v10889 = v10874->cache_keys;
      int v10890 = v10889[0];
      v10888[1] = v10890;
      int * v10892 = v10874->cache_vals;
      int * v10893 = v10874->cache_vals;
      int v10894 = v10893[0];
      v10892[1] = v10894;
      int * v10896 = v10874->cache_keys;
      int v10949 = (int)((unsigned int)(v10878 + 4) >> 2);
      v10896[0] = v10949;
      int * v10898 = v10874->cache_vals;
      v10898[0] = v10880;
      int v10900 = v10874->timer;
      int v10952 = v10900 + 1;
      v10874->timer = v10952;
      v10924 = v10880;
    } else {
      int * v10903 = v10874->mem;
      int * v10904 = v10874->cache_keys;
      int v10905 = v10904[1];
      int * v10906 = v10874->cache_vals;
      int v10907 = v10906[1];
      v10903[v10905] = v10907;
      int * v10909 = v10874->cache_keys;
      int * v10910 = v10874->cache_keys;
      int v10911 = v10910[0];
      v10909[1] = v10911;
      int * v10913 = v10874->cache_vals;
      int * v10914 = v10874->cache_vals;
      int v10915 = v10914[0];
      v10913[1] = v10915;
      int * v10917 = v10874->cache_keys;
      int v10965 = (int)((unsigned int)(v10878 + 4) >> 2);
      v10917[0] = v10965;
      int * v10919 = v10874->cache_vals;
      v10919[0] = v10880;
      int v10921 = v10874->timer;
      int v10968 = v10921 + 100;
      v10874->timer = v10968;
      v10924 = v10880;
    }
    v10926 = v10924;
  }
  struct StateT * v10927 = slot_308(v10874);
  return v10927;
}

struct StateT * slot_27(struct StateT * v2564) {
  int v2565 = v2564->timer;
  int v2571 = v2565 + 1;
  v2564->timer = v2571;
  int * v2567 = v2564->regs;
  v2567[12] = 1634762752;
  struct StateT * v2569 = slot_28(v2564);
  return v2569;
}

struct StateT * slot_662(struct StateT * v22047) {
  int v22048 = v22047->timer;
  int v22058 = v22048 + 1;
  v22047->timer = v22058;
  int * v22050 = v22047->regs;
  int v22051 = v22050[8];
  int * v22052 = v22047->regs;
  int v22053 = v22052[9];
  int * v22054 = v22047->regs;
  int v22064 = v22051 | v22053;
  v22054[8] = v22064;
  struct StateT * v22056 = slot_663(v22047);
  return v22056;
}

struct StateT * slot_454(struct StateT * v17993) {
  int v17994 = v17993->timer;
  int v18004 = v17994 + 1;
  v17993->timer = v18004;
  int * v17996 = v17993->regs;
  int v17997 = v17996[15];
  int * v17998 = v17993->regs;
  int v17999 = v17998[9];
  int * v18000 = v17993->regs;
  int v18010 = v17997 | v17999;
  v18000[15] = v18010;
  struct StateT * v18002 = slot_455(v17993);
  return v18002;
}

struct StateT * slot_34(struct StateT * v2667) {
  int v2668 = v2667->timer;
  int v2676 = v2668 + 1;
  v2667->timer = v2676;
  int * v2670 = v2667->regs;
  int v2671 = v2670[22];
  int * v2672 = v2667->regs;
  int v2680 = v2671 + 1396;
  v2672[22] = v2680;
  struct StateT * v2674 = slot_35(v2667);
  return v2674;
}

struct StateT * slot_482(struct StateT * v18515) {
  int v18516 = v18515->timer;
  int v18526 = v18516 + 1;
  v18515->timer = v18526;
  int * v18518 = v18515->regs;
  int v18519 = v18518[12];
  int * v18520 = v18515->regs;
  int v18521 = v18520[15];
  int * v18522 = v18515->regs;
  int v18532 = v18519 ^ v18521;
  v18522[12] = v18532;
  struct StateT * v18524 = slot_483(v18515);
  return v18524;
}

struct StateT * slot_21(struct StateT * v1934) {
  int v1935 = v1934->timer;
  int v1993 = v1935 + 1;
  v1934->timer = v1993;
  int * v1937 = v1934->regs;
  int v1938 = v1937[12];
  int * v1939 = v1934->cache_keys;
  int v1940 = v1939[0];
  bool v1998 = v1940 == ((int)((unsigned int)(v1938 + 24) >> 2));
  int v1988;
  if (v1998) {
    int * v1941 = v1934->cache_vals;
    int v1942 = v1941[0];
    v1988 = v1942;
  } else {
    int * v1944 = v1934->cache_keys;
    int v1945 = v1944[1];
    bool v2003 = v1945 == ((int)((unsigned int)(v1938 + 24) >> 2));
    int v1986;
    if (v2003) {
      int * v1946 = v1934->cache_vals;
      int v1947 = v1946[1];
      int * v1948 = v1934->cache_keys;
      int * v1949 = v1934->cache_keys;
      int v1950 = v1949[0];
      v1948[1] = v1950;
      int * v1952 = v1934->cache_vals;
      int * v1953 = v1934->cache_vals;
      int v1954 = v1953[0];
      v1952[1] = v1954;
      int * v1956 = v1934->cache_keys;
      int v2012 = (int)((unsigned int)(v1938 + 24) >> 2);
      v1956[0] = v2012;
      int * v1958 = v1934->cache_vals;
      v1958[0] = v1947;
      int v1960 = v1934->timer;
      int v2015 = v1960 + 1;
      v1934->timer = v2015;
      v1986 = v1947;
    } else {
      int * v1963 = v1934->mem;
      int v2017 = (int)((unsigned int)(v1938 + 24) >> 2);
      int v1964 = v1963[v2017];
      int * v1965 = v1934->mem;
      int * v1966 = v1934->cache_keys;
      int v1967 = v1966[1];
      int * v1968 = v1934->cache_vals;
      int v1969 = v1968[1];
      v1965[v1967] = v1969;
      int * v1971 = v1934->cache_keys;
      int * v1972 = v1934->cache_keys;
      int v1973 = v1972[0];
      v1971[1] = v1973;
      int * v1975 = v1934->cache_vals;
      int * v1976 = v1934->cache_vals;
      int v1977 = v1976[0];
      v1975[1] = v1977;
      int * v1979 = v1934->cache_keys;
      v1979[0] = v2017;
      int * v1981 = v1934->cache_vals;
      v1981[0] = v1964;
      int v1983 = v1934->timer;
      int v2032 = v1983 + 100;
      v1934->timer = v2032;
      v1986 = v1964;
    }
    v1988 = v1986;
  }
  int * v1989 = v1934->regs;
  v1989[24] = v1988;
  struct StateT * v1991 = slot_22(v1934);
  return v1991;
}

struct StateT * slot_406(struct StateT * v17087) {
  int v17088 = v17087->timer;
  int v17098 = v17088 + 1;
  v17087->timer = v17098;
  int * v17090 = v17087->regs;
  int v17091 = v17090[23];
  int * v17092 = v17087->regs;
  int v17093 = v17092[24];
  int * v17094 = v17087->regs;
  int v17105 = v17091 + v17093;
  v17094[16] = v17105;
  struct StateT * v17096 = slot_407(v17087);
  return v17096;
}

struct StateT * slot_292(struct StateT * v10228) {
  int v10229 = v10228->timer;
  int v10237 = v10229 + 1;
  v10228->timer = v10237;
  int * v10231 = v10228->regs;
  int v10232 = v10231[8];
  int * v10233 = v10228->regs;
  int v10241 = v10232 << 7;
  v10233[8] = v10241;
  struct StateT * v10235 = slot_295(v10228);
  return v10235;
}

struct StateT * slot_118(struct StateT * v5065) {
  int v5066 = v5065->timer;
  int v5074 = v5066 + 1;
  v5065->timer = v5074;
  int * v5068 = v5065->regs;
  int v5069 = v5068[16];
  int * v5070 = v5065->regs;
  int v5079 = (int)((unsigned int)v5069 >> 14);
  v5070[6] = v5079;
  struct StateT * v5072 = slot_119(v5065);
  return v5072;
}

struct StateT * slot_525(struct StateT * v19361) {
  int * v19362 = v19361->saved_regs;
  int * v19363 = v19361->regs;
  int v19364 = v19363[1];
  v19362[1] = v19364;
  int v19366 = v19361->timer;
  int v19380 = v19366 + 1;
  v19361->timer = v19380;
  int * v19368 = v19361->regs;
  int v19369 = v19368[1];
  int * v19370 = v19361->regs;
  int v19371 = v19370[18];
  int * v19372 = v19361->regs;
  int v19385 = v19369 ^ v19371;
  v19372[1] = v19385;
  struct StateT * v19374 = slot_526(v19361);
  return v19374;
}

struct StateT * slot_515(struct StateT * v19165) {
  int v19166 = v19165->timer;
  int v19174 = v19166 + 1;
  v19165->timer = v19174;
  int * v19168 = v19165->regs;
  int v19169 = v19168[20];
  int * v19170 = v19165->regs;
  int v19178 = v19169 << 7;
  v19170[20] = v19178;
  struct StateT * v19172 = slot_516(v19165);
  return v19172;
}

struct StateT * slot_666(struct StateT * v22128) {
  int v22129 = v22128->timer;
  int v22139 = v22129 + 1;
  v22128->timer = v22139;
  int * v22131 = v22128->regs;
  int v22132 = v22131[22];
  int * v22133 = v22128->regs;
  int v22134 = v22133[8];
  int * v22135 = v22128->regs;
  int v22145 = v22132 ^ v22134;
  v22135[22] = v22145;
  struct StateT * v22137 = slot_667(v22128);
  return v22137;
}

struct StateT * slot_589(struct StateT * v20681) {
  int v20682 = v20681->timer;
  int v20692 = v20682 + 1;
  v20681->timer = v20692;
  int * v20684 = v20681->regs;
  int v20685 = v20684[19];
  int * v20686 = v20681->regs;
  int v20687 = v20686[13];
  int * v20688 = v20681->regs;
  int v20699 = v20685 + v20687;
  v20688[16] = v20699;
  struct StateT * v20690 = slot_590(v20681);
  return v20690;
}

struct StateT * slot_376(struct StateT * v16161) {
  int v16162 = v16161->timer;
  int v16172 = v16162 + 1;
  v16161->timer = v16172;
  int * v16164 = v16161->regs;
  int v16165 = v16164[27];
  int * v16166 = v16161->regs;
  int v16167 = v16166[1];
  int * v16168 = v16161->regs;
  int v16179 = v16165 + v16167;
  v16168[9] = v16179;
  struct StateT * v16170 = slot_379(v16161);
  return v16170;
}

struct StateT * slot_373(struct StateT * v15930) {
  int v15931 = v15930->timer;
  int v15941 = v15931 + 1;
  v15930->timer = v15941;
  int * v15933 = v15930->regs;
  int v15934 = v15933[24];
  int * v15935 = v15930->regs;
  int v15936 = v15935[13];
  int * v15937 = v15930->regs;
  int v15948 = v15934 + v15936;
  v15937[8] = v15948;
  struct StateT * v15939 = slot_376(v15930);
  return v15939;
}

struct StateT * slot_94(struct StateT * v4576) {
  int v4577 = v4576->timer;
  int v4587 = v4577 + 1;
  v4576->timer = v4587;
  int * v4579 = v4576->regs;
  int v4580 = v4579[25];
  int * v4581 = v4576->regs;
  int v4582 = v4581[14];
  int * v4583 = v4576->regs;
  int v4594 = v4580 + v4582;
  v4583[18] = v4594;
  struct StateT * v4585 = slot_95(v4576);
  return v4585;
}

struct StateT * slot_340(struct StateT * v13435) {
  int v13436 = v13435->timer;
  int v13444 = v13436 + 1;
  v13435->timer = v13444;
  int * v13438 = v13435->regs;
  int v13439 = v13438[9];
  int * v13440 = v13435->regs;
  int v13449 = (int)((unsigned int)v13439 >> 23);
  v13440[20] = v13449;
  struct StateT * v13442 = slot_343(v13435);
  return v13442;
}

struct StateT * slot_146(struct StateT * v5609) {
  int v5610 = v5609->timer;
  int v5620 = v5610 + 1;
  v5609->timer = v5620;
  int * v5612 = v5609->regs;
  int v5613 = v5612[17];
  int * v5614 = v5609->regs;
  int v5615 = v5614[5];
  int * v5616 = v5609->regs;
  int v5627 = v5613 | v5615;
  v5616[6] = v5627;
  struct StateT * v5618 = slot_147(v5609);
  return v5618;
}

struct StateT * slot_383(struct StateT * v16551) {
  int v16552 = v16551->timer;
  int v16610 = v16552 + 1;
  v16551->timer = v16610;
  int * v16554 = v16551->regs;
  int v16555 = v16554[2];
  int * v16556 = v16551->cache_keys;
  int v16557 = v16556[0];
  bool v16615 = v16557 == ((int)((unsigned int)(v16555 + 48) >> 2));
  int v16605;
  if (v16615) {
    int * v16558 = v16551->cache_vals;
    int v16559 = v16558[0];
    v16605 = v16559;
  } else {
    int * v16561 = v16551->cache_keys;
    int v16562 = v16561[1];
    bool v16620 = v16562 == ((int)((unsigned int)(v16555 + 48) >> 2));
    int v16603;
    if (v16620) {
      int * v16563 = v16551->cache_vals;
      int v16564 = v16563[1];
      int * v16565 = v16551->cache_keys;
      int * v16566 = v16551->cache_keys;
      int v16567 = v16566[0];
      v16565[1] = v16567;
      int * v16569 = v16551->cache_vals;
      int * v16570 = v16551->cache_vals;
      int v16571 = v16570[0];
      v16569[1] = v16571;
      int * v16573 = v16551->cache_keys;
      int v16629 = (int)((unsigned int)(v16555 + 48) >> 2);
      v16573[0] = v16629;
      int * v16575 = v16551->cache_vals;
      v16575[0] = v16564;
      int v16577 = v16551->timer;
      int v16632 = v16577 + 1;
      v16551->timer = v16632;
      v16603 = v16564;
    } else {
      int * v16580 = v16551->mem;
      int v16634 = (int)((unsigned int)(v16555 + 48) >> 2);
      int v16581 = v16580[v16634];
      int * v16582 = v16551->mem;
      int * v16583 = v16551->cache_keys;
      int v16584 = v16583[1];
      int * v16585 = v16551->cache_vals;
      int v16586 = v16585[1];
      v16582[v16584] = v16586;
      int * v16588 = v16551->cache_keys;
      int * v16589 = v16551->cache_keys;
      int v16590 = v16589[0];
      v16588[1] = v16590;
      int * v16592 = v16551->cache_vals;
      int * v16593 = v16551->cache_vals;
      int v16594 = v16593[0];
      v16592[1] = v16594;
      int * v16596 = v16551->cache_keys;
      v16596[0] = v16634;
      int * v16598 = v16551->cache_vals;
      v16598[0] = v16581;
      int v16600 = v16551->timer;
      int v16649 = v16600 + 100;
      v16551->timer = v16649;
      v16603 = v16581;
    }
    v16605 = v16603;
  }
  int * v16606 = v16551->regs;
  v16606[26] = v16605;
  struct StateT * v16608 = slot_386(v16551);
  return v16608;
}

struct StateT * slot_24(struct StateT * v2249) {
  int v2250 = v2249->timer;
  int v2308 = v2250 + 1;
  v2249->timer = v2308;
  int * v2252 = v2249->regs;
  int v2253 = v2252[11];
  int * v2254 = v2249->cache_keys;
  int v2255 = v2254[0];
  bool v2313 = v2255 == ((int)((unsigned int)(v2253 + 4) >> 2));
  int v2303;
  if (v2313) {
    int * v2256 = v2249->cache_vals;
    int v2257 = v2256[0];
    v2303 = v2257;
  } else {
    int * v2259 = v2249->cache_keys;
    int v2260 = v2259[1];
    bool v2318 = v2260 == ((int)((unsigned int)(v2253 + 4) >> 2));
    int v2301;
    if (v2318) {
      int * v2261 = v2249->cache_vals;
      int v2262 = v2261[1];
      int * v2263 = v2249->cache_keys;
      int * v2264 = v2249->cache_keys;
      int v2265 = v2264[0];
      v2263[1] = v2265;
      int * v2267 = v2249->cache_vals;
      int * v2268 = v2249->cache_vals;
      int v2269 = v2268[0];
      v2267[1] = v2269;
      int * v2271 = v2249->cache_keys;
      int v2327 = (int)((unsigned int)(v2253 + 4) >> 2);
      v2271[0] = v2327;
      int * v2273 = v2249->cache_vals;
      v2273[0] = v2262;
      int v2275 = v2249->timer;
      int v2330 = v2275 + 1;
      v2249->timer = v2330;
      v2301 = v2262;
    } else {
      int * v2278 = v2249->mem;
      int v2332 = (int)((unsigned int)(v2253 + 4) >> 2);
      int v2279 = v2278[v2332];
      int * v2280 = v2249->mem;
      int * v2281 = v2249->cache_keys;
      int v2282 = v2281[1];
      int * v2283 = v2249->cache_vals;
      int v2284 = v2283[1];
      v2280[v2282] = v2284;
      int * v2286 = v2249->cache_keys;
      int * v2287 = v2249->cache_keys;
      int v2288 = v2287[0];
      v2286[1] = v2288;
      int * v2290 = v2249->cache_vals;
      int * v2291 = v2249->cache_vals;
      int v2292 = v2291[0];
      v2290[1] = v2292;
      int * v2294 = v2249->cache_keys;
      v2294[0] = v2332;
      int * v2296 = v2249->cache_vals;
      v2296[0] = v2279;
      int v2298 = v2249->timer;
      int v2347 = v2298 + 100;
      v2249->timer = v2347;
      v2301 = v2279;
    }
    v2303 = v2301;
  }
  int * v2304 = v2249->regs;
  v2304[25] = v2303;
  struct StateT * v2306 = slot_25(v2249);
  return v2306;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v15 = v6 + -96;
  v7[2] = v15;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_489(struct StateT * v18659) {
  int v18660 = v18659->timer;
  int v18668 = v18660 + 1;
  v18659->timer = v18668;
  int * v18662 = v18659->regs;
  int v18663 = v18662[11];
  int * v18664 = v18659->regs;
  int v18673 = (int)((unsigned int)v18663 >> 14);
  v18664[9] = v18673;
  struct StateT * v18666 = slot_490(v18659);
  return v18666;
}

struct StateT * slot_673(struct StateT * v22526) {
  int v22527 = v22526->timer;
  int v22537 = v22527 + 1;
  v22526->timer = v22537;
  int * v22529 = v22526->regs;
  int v22530 = v22529[12];
  int * v22531 = v22526->regs;
  int v22532 = v22531[6];
  int * v22533 = v22526->regs;
  int v22543 = v22530 + v22532;
  v22533[12] = v22543;
  struct StateT * v22535 = slot_674(v22526);
  return v22535;
}

struct StateT * slot_286(struct StateT * v10115) {
  int v10116 = v10115->timer;
  int v10126 = v10116 + 1;
  v10115->timer = v10126;
  int * v10118 = v10115->regs;
  int v10119 = v10118[18];
  int * v10120 = v10115->regs;
  int v10121 = v10120[20];
  int * v10122 = v10115->regs;
  int v10132 = v10119 | v10121;
  v10122[18] = v10132;
  struct StateT * v10124 = slot_289(v10115);
  return v10124;
}

struct StateT * slot_520(struct StateT * v19254) {
  int v19255 = v19254->timer;
  int v19263 = v19255 + 1;
  v19254->timer = v19263;
  int * v19257 = v19254->regs;
  int v19258 = v19257[8];
  int * v19259 = v19254->regs;
  int v19268 = (int)((unsigned int)v19258 >> 25);
  v19259[20] = v19268;
  struct StateT * v19261 = slot_521(v19254);
  return v19261;
}

struct StateT * slot_125(struct StateT * v5188) {
  int v5189 = v5188->timer;
  int v5197 = v5189 + 1;
  v5188->timer = v5197;
  int * v5191 = v5188->regs;
  int v5192 = v5191[5];
  int * v5193 = v5188->regs;
  int v5201 = v5192 << 18;
  v5193[5] = v5201;
  struct StateT * v5195 = slot_126(v5188);
  return v5195;
}

struct StateT * slot_254(struct StateT * v9111) {
  int v9112 = v9111->timer;
  int v9122 = v9112 + 1;
  v9111->timer = v9122;
  int * v9114 = v9111->regs;
  int v9115 = v9114[17];
  int * v9116 = v9111->regs;
  int v9117 = v9116[30];
  int * v9118 = v9111->regs;
  int v9128 = v9115 + v9117;
  v9118[17] = v9128;
  struct StateT * v9120 = slot_257(v9111);
  return v9120;
}

struct StateT * slot_148(struct StateT * v5650) {
  int v5651 = v5650->timer;
  int v5661 = v5651 + 1;
  v5650->timer = v5661;
  int * v5653 = v5650->regs;
  int v5654 = v5653[18];
  int * v5655 = v5650->regs;
  int v5656 = v5655[11];
  int * v5657 = v5650->regs;
  int v5668 = v5654 ^ v5656;
  v5657[5] = v5668;
  struct StateT * v5659 = slot_149(v5650);
  return v5659;
}

struct StateT * slot_421(struct StateT * v17362) {
  int v17363 = v17362->timer;
  int v17373 = v17363 + 1;
  v17362->timer = v17373;
  int * v17365 = v17362->regs;
  int v17366 = v17365[21];
  int * v17367 = v17362->regs;
  int v17368 = v17367[15];
  int * v17369 = v17362->regs;
  int v17379 = v17366 ^ v17368;
  v17369[21] = v17379;
  struct StateT * v17371 = slot_422(v17362);
  return v17371;
}

struct StateT * slot_126(struct StateT * v5204) {
  int v5205 = v5204->timer;
  int v5215 = v5205 + 1;
  v5204->timer = v5215;
  int * v5207 = v5204->regs;
  int v5208 = v5207[5];
  int * v5209 = v5204->regs;
  int v5210 = v5209[6];
  int * v5211 = v5204->regs;
  int v5221 = v5208 | v5210;
  v5211[5] = v5221;
  struct StateT * v5213 = slot_127(v5204);
  return v5213;
}

struct StateT * slot_363(struct StateT * v15134) {
  int v15135 = v15134->timer;
  int v15193 = v15135 + 1;
  v15134->timer = v15193;
  int * v15137 = v15134->regs;
  int v15138 = v15137[2];
  int * v15139 = v15134->cache_keys;
  int v15140 = v15139[0];
  bool v15198 = v15140 == ((int)((unsigned int)(v15138 + 64) >> 2));
  int v15188;
  if (v15198) {
    int * v15141 = v15134->cache_vals;
    int v15142 = v15141[0];
    v15188 = v15142;
  } else {
    int * v15144 = v15134->cache_keys;
    int v15145 = v15144[1];
    bool v15203 = v15145 == ((int)((unsigned int)(v15138 + 64) >> 2));
    int v15186;
    if (v15203) {
      int * v15146 = v15134->cache_vals;
      int v15147 = v15146[1];
      int * v15148 = v15134->cache_keys;
      int * v15149 = v15134->cache_keys;
      int v15150 = v15149[0];
      v15148[1] = v15150;
      int * v15152 = v15134->cache_vals;
      int * v15153 = v15134->cache_vals;
      int v15154 = v15153[0];
      v15152[1] = v15154;
      int * v15156 = v15134->cache_keys;
      int v15212 = (int)((unsigned int)(v15138 + 64) >> 2);
      v15156[0] = v15212;
      int * v15158 = v15134->cache_vals;
      v15158[0] = v15147;
      int v15160 = v15134->timer;
      int v15215 = v15160 + 1;
      v15134->timer = v15215;
      v15186 = v15147;
    } else {
      int * v15163 = v15134->mem;
      int v15217 = (int)((unsigned int)(v15138 + 64) >> 2);
      int v15164 = v15163[v15217];
      int * v15165 = v15134->mem;
      int * v15166 = v15134->cache_keys;
      int v15167 = v15166[1];
      int * v15168 = v15134->cache_vals;
      int v15169 = v15168[1];
      v15165[v15167] = v15169;
      int * v15171 = v15134->cache_keys;
      int * v15172 = v15134->cache_keys;
      int v15173 = v15172[0];
      v15171[1] = v15173;
      int * v15175 = v15134->cache_vals;
      int * v15176 = v15134->cache_vals;
      int v15177 = v15176[0];
      v15175[1] = v15177;
      int * v15179 = v15134->cache_keys;
      v15179[0] = v15217;
      int * v15181 = v15134->cache_vals;
      v15181[0] = v15164;
      int v15183 = v15134->timer;
      int v15232 = v15183 + 100;
      v15134->timer = v15232;
      v15186 = v15164;
    }
    v15188 = v15186;
  }
  int * v15189 = v15134->regs;
  v15189[22] = v15188;
  struct StateT * v15191 = slot_366(v15134);
  return v15191;
}

struct StateT * slot_578(struct StateT * v20441) {
  int v20442 = v20441->timer;
  int v20450 = v20442 + 1;
  v20441->timer = v20450;
  int * v20444 = v20441->regs;
  int v20445 = v20444[17];
  int * v20446 = v20441->regs;
  int v20454 = v20445 << 18;
  v20446[17] = v20454;
  struct StateT * v20448 = slot_579(v20441);
  return v20448;
}

struct StateT * slot_661(struct StateT * v22031) {
  int v22032 = v22031->timer;
  int v22040 = v22032 + 1;
  v22031->timer = v22040;
  int * v22034 = v22031->regs;
  int v22035 = v22034[8];
  int * v22036 = v22031->regs;
  int v22044 = v22035 << 18;
  v22036[8] = v22044;
  struct StateT * v22038 = slot_662(v22031);
  return v22038;
}

struct StateT * slot_79(struct StateT * v4263) {
  int v4264 = v4263->timer;
  int v4272 = v4264 + 1;
  v4263->timer = v4272;
  int * v4266 = v4263->regs;
  int v4267 = v4266[8];
  int * v4268 = v4263->regs;
  int v4276 = v4267 << 9;
  v4268[8] = v4276;
  struct StateT * v4270 = slot_80(v4263);
  return v4270;
}

struct StateT * slot_568(struct StateT * v20234) {
  int * v20235 = v20234->saved_regs;
  int * v20236 = v20234->regs;
  int v20237 = v20236[16];
  v20235[16] = v20237;
  int v20239 = v20234->timer;
  int v20253 = v20239 + 1;
  v20234->timer = v20253;
  int * v20241 = v20234->regs;
  int v20242 = v20241[23];
  int * v20243 = v20234->regs;
  int v20244 = v20243[24];
  int * v20245 = v20234->regs;
  int v20259 = v20242 + v20244;
  v20245[16] = v20259;
  struct StateT * v20247 = slot_569(v20234);
  return v20247;
}

struct StateT * slot_571(struct StateT * v20318) {
  int v20319 = v20318->timer;
  int v20327 = v20319 + 1;
  v20318->timer = v20327;
  int * v20321 = v20318->regs;
  int v20322 = v20321[15];
  int * v20323 = v20318->regs;
  int v20332 = (int)((unsigned int)v20322 >> 14);
  v20323[6] = v20332;
  struct StateT * v20325 = slot_572(v20318);
  return v20325;
}

struct StateT * slot_367(struct StateT * v15469) {
  int v15470 = v15469->timer;
  int v15480 = v15470 + 1;
  v15469->timer = v15480;
  int * v15472 = v15469->regs;
  int v15473 = v15472[25];
  int * v15474 = v15469->regs;
  int v15475 = v15474[18];
  int * v15476 = v15469->regs;
  int v15486 = v15473 ^ v15475;
  v15476[25] = v15486;
  struct StateT * v15478 = slot_370(v15469);
  return v15478;
}

struct StateT * slot_437(struct StateT * v17666) {
  int v17667 = v17666->timer;
  int v17677 = v17667 + 1;
  v17666->timer = v17677;
  int * v17669 = v17666->regs;
  int v17670 = v17669[16];
  int * v17671 = v17666->regs;
  int v17672 = v17671[5];
  int * v17673 = v17666->regs;
  int v17683 = v17670 | v17672;
  v17673[16] = v17683;
  struct StateT * v17675 = slot_438(v17666);
  return v17675;
}

struct StateT * slot_341(struct StateT * v13452) {
  int v13453 = v13452->timer;
  int v13507 = v13453 + 1;
  v13452->timer = v13507;
  int * v13455 = v13452->regs;
  int v13456 = v13455[10];
  int * v13457 = v13452->regs;
  int v13458 = v13457[24];
  int * v13459 = v13452->cache_keys;
  int v13460 = v13459[0];
  bool v13514 = v13460 == ((int)((unsigned int)(v13456 + 52) >> 2));
  int v13504;
  if (v13514) {
    int * v13461 = v13452->cache_vals;
    v13461[0] = v13458;
    v13504 = v13458;
  } else {
    int * v13464 = v13452->cache_keys;
    int v13465 = v13464[1];
    bool v13519 = v13465 == ((int)((unsigned int)(v13456 + 52) >> 2));
    int v13502;
    if (v13519) {
      int * v13466 = v13452->cache_keys;
      int * v13467 = v13452->cache_keys;
      int v13468 = v13467[0];
      v13466[1] = v13468;
      int * v13470 = v13452->cache_vals;
      int * v13471 = v13452->cache_vals;
      int v13472 = v13471[0];
      v13470[1] = v13472;
      int * v13474 = v13452->cache_keys;
      int v13527 = (int)((unsigned int)(v13456 + 52) >> 2);
      v13474[0] = v13527;
      int * v13476 = v13452->cache_vals;
      v13476[0] = v13458;
      int v13478 = v13452->timer;
      int v13530 = v13478 + 1;
      v13452->timer = v13530;
      v13502 = v13458;
    } else {
      int * v13481 = v13452->mem;
      int * v13482 = v13452->cache_keys;
      int v13483 = v13482[1];
      int * v13484 = v13452->cache_vals;
      int v13485 = v13484[1];
      v13481[v13483] = v13485;
      int * v13487 = v13452->cache_keys;
      int * v13488 = v13452->cache_keys;
      int v13489 = v13488[0];
      v13487[1] = v13489;
      int * v13491 = v13452->cache_vals;
      int * v13492 = v13452->cache_vals;
      int v13493 = v13492[0];
      v13491[1] = v13493;
      int * v13495 = v13452->cache_keys;
      int v13543 = (int)((unsigned int)(v13456 + 52) >> 2);
      v13495[0] = v13543;
      int * v13497 = v13452->cache_vals;
      v13497[0] = v13458;
      int v13499 = v13452->timer;
      int v13546 = v13499 + 100;
      v13452->timer = v13546;
      v13502 = v13458;
    }
    v13504 = v13502;
  }
  struct StateT * v13505 = slot_344(v13452);
  return v13505;
}

struct StateT * slot_142(struct StateT * v5540) {
  int v5541 = v5540->timer;
  int v5549 = v5541 + 1;
  v5540->timer = v5549;
  int * v5543 = v5540->regs;
  int v5544 = v5543[16];
  int * v5545 = v5540->regs;
  int v5553 = v5544 << 7;
  v5545[16] = v5553;
  struct StateT * v5547 = slot_143(v5540);
  return v5547;
}

struct StateT * slot_416(struct StateT * v17273) {
  int v17274 = v17273->timer;
  int v17282 = v17274 + 1;
  v17273->timer = v17282;
  int * v17276 = v17273->regs;
  int v17277 = v17276[17];
  int * v17278 = v17273->regs;
  int v17286 = v17277 << 18;
  v17278[17] = v17286;
  struct StateT * v17280 = slot_417(v17273);
  return v17280;
}

struct StateT * slot_624(struct StateT * v21335) {
  int v21336 = v21335->timer;
  int v21346 = v21336 + 1;
  v21335->timer = v21346;
  int * v21338 = v21335->regs;
  int v21339 = v21338[25];
  int * v21340 = v21335->regs;
  int v21341 = v21340[15];
  int * v21342 = v21335->regs;
  int v21352 = v21339 ^ v21341;
  v21342[25] = v21352;
  struct StateT * v21344 = slot_625(v21335);
  return v21344;
}

struct StateT * slot_280(struct StateT * v10010) {
  int v10011 = v10010->timer;
  int v10019 = v10011 + 1;
  v10010->timer = v10019;
  int * v10013 = v10010->regs;
  int v10014 = v10013[18];
  int * v10015 = v10010->regs;
  int v10024 = (int)((unsigned int)v10014 >> 25);
  v10015[20] = v10024;
  struct StateT * v10017 = slot_283(v10010);
  return v10017;
}

struct StateT * slot_272(struct StateT * v9877) {
  int v9878 = v9877->timer;
  int v9888 = v9878 + 1;
  v9877->timer = v9888;
  int * v9880 = v9877->regs;
  int v9881 = v9880[1];
  int * v9882 = v9877->regs;
  int v9883 = v9882[30];
  int * v9884 = v9877->regs;
  int v9894 = v9881 + v9883;
  v9884[1] = v9894;
  struct StateT * v9886 = slot_275(v9877);
  return v9886;
}

struct StateT * slot_47(struct StateT * v3530) {
  int v3531 = v3530->timer;
  int v3539 = v3531 + 1;
  v3530->timer = v3539;
  int * v3533 = v3530->regs;
  int v3534 = v3533[29];
  int * v3535 = v3530->regs;
  v3535[23] = v3534;
  struct StateT * v3537 = slot_48(v3530);
  return v3537;
}

struct StateT * slot_214(struct StateT * v7089) {
  int v7090 = v7089->timer;
  int v7094 = v7090 + 1;
  v7089->timer = v7094;
  struct StateT * v7092 = slot_216(v7089);
  return v7092;
}

struct StateT * slot_297(struct StateT * v10402) {
  int v10403 = v10402->timer;
  int v10457 = v10403 + 1;
  v10402->timer = v10457;
  int * v10405 = v10402->regs;
  int v10406 = v10405[10];
  int * v10407 = v10402->regs;
  int v10408 = v10407[29];
  int * v10409 = v10402->cache_keys;
  int v10410 = v10409[0];
  bool v10464 = v10410 == ((int)((unsigned int)(v10406 + 4) >> 2));
  int v10454;
  if (v10464) {
    int * v10411 = v10402->cache_vals;
    v10411[0] = v10408;
    v10454 = v10408;
  } else {
    int * v10414 = v10402->cache_keys;
    int v10415 = v10414[1];
    bool v10469 = v10415 == ((int)((unsigned int)(v10406 + 4) >> 2));
    int v10452;
    if (v10469) {
      int * v10416 = v10402->cache_keys;
      int * v10417 = v10402->cache_keys;
      int v10418 = v10417[0];
      v10416[1] = v10418;
      int * v10420 = v10402->cache_vals;
      int * v10421 = v10402->cache_vals;
      int v10422 = v10421[0];
      v10420[1] = v10422;
      int * v10424 = v10402->cache_keys;
      int v10477 = (int)((unsigned int)(v10406 + 4) >> 2);
      v10424[0] = v10477;
      int * v10426 = v10402->cache_vals;
      v10426[0] = v10408;
      int v10428 = v10402->timer;
      int v10480 = v10428 + 1;
      v10402->timer = v10480;
      v10452 = v10408;
    } else {
      int * v10431 = v10402->mem;
      int * v10432 = v10402->cache_keys;
      int v10433 = v10432[1];
      int * v10434 = v10402->cache_vals;
      int v10435 = v10434[1];
      v10431[v10433] = v10435;
      int * v10437 = v10402->cache_keys;
      int * v10438 = v10402->cache_keys;
      int v10439 = v10438[0];
      v10437[1] = v10439;
      int * v10441 = v10402->cache_vals;
      int * v10442 = v10402->cache_vals;
      int v10443 = v10442[0];
      v10441[1] = v10443;
      int * v10445 = v10402->cache_keys;
      int v10493 = (int)((unsigned int)(v10406 + 4) >> 2);
      v10445[0] = v10493;
      int * v10447 = v10402->cache_vals;
      v10447[0] = v10408;
      int v10449 = v10402->timer;
      int v10496 = v10449 + 100;
      v10402->timer = v10496;
      v10452 = v10408;
    }
    v10454 = v10452;
  }
  struct StateT * v10455 = slot_300(v10402);
  return v10455;
}

struct StateT * slot_29(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v2597 = v2591 + 1;
  v2590->timer = v2597;
  int * v2593 = v2590->regs;
  v2593[14] = 2036477952;
  struct StateT * v2595 = slot_30(v2590);
  return v2595;
}

struct StateT * slot_314(struct StateT * v11524) {
  int v11525 = v11524->timer;
  int v11579 = v11525 + 1;
  v11524->timer = v11579;
  int * v11527 = v11524->regs;
  int v11528 = v11527[10];
  int * v11529 = v11524->regs;
  int v11530 = v11529[12];
  int * v11531 = v11524->cache_keys;
  int v11532 = v11531[0];
  bool v11586 = v11532 == ((int)((unsigned int)(v11528 + 16) >> 2));
  int v11576;
  if (v11586) {
    int * v11533 = v11524->cache_vals;
    v11533[0] = v11530;
    v11576 = v11530;
  } else {
    int * v11536 = v11524->cache_keys;
    int v11537 = v11536[1];
    bool v11591 = v11537 == ((int)((unsigned int)(v11528 + 16) >> 2));
    int v11574;
    if (v11591) {
      int * v11538 = v11524->cache_keys;
      int * v11539 = v11524->cache_keys;
      int v11540 = v11539[0];
      v11538[1] = v11540;
      int * v11542 = v11524->cache_vals;
      int * v11543 = v11524->cache_vals;
      int v11544 = v11543[0];
      v11542[1] = v11544;
      int * v11546 = v11524->cache_keys;
      int v11599 = (int)((unsigned int)(v11528 + 16) >> 2);
      v11546[0] = v11599;
      int * v11548 = v11524->cache_vals;
      v11548[0] = v11530;
      int v11550 = v11524->timer;
      int v11602 = v11550 + 1;
      v11524->timer = v11602;
      v11574 = v11530;
    } else {
      int * v11553 = v11524->mem;
      int * v11554 = v11524->cache_keys;
      int v11555 = v11554[1];
      int * v11556 = v11524->cache_vals;
      int v11557 = v11556[1];
      v11553[v11555] = v11557;
      int * v11559 = v11524->cache_keys;
      int * v11560 = v11524->cache_keys;
      int v11561 = v11560[0];
      v11559[1] = v11561;
      int * v11563 = v11524->cache_vals;
      int * v11564 = v11524->cache_vals;
      int v11565 = v11564[0];
      v11563[1] = v11565;
      int * v11567 = v11524->cache_keys;
      int v11615 = (int)((unsigned int)(v11528 + 16) >> 2);
      v11567[0] = v11615;
      int * v11569 = v11524->cache_vals;
      v11569[0] = v11530;
      int v11571 = v11524->timer;
      int v11618 = v11571 + 100;
      v11524->timer = v11618;
      v11574 = v11530;
    }
    v11576 = v11574;
  }
  struct StateT * v11577 = slot_317(v11524);
  return v11577;
}

struct StateT * slot_151(struct StateT * v5713) {
  int v5714 = v5713->timer;
  int v5724 = v5714 + 1;
  v5713->timer = v5724;
  int * v5716 = v5713->regs;
  int v5717 = v5716[23];
  int * v5718 = v5713->regs;
  int v5719 = v5718[21];
  int * v5720 = v5713->regs;
  int v5731 = v5717 + v5719;
  v5720[11] = v5731;
  struct StateT * v5722 = slot_152(v5713);
  return v5722;
}

struct StateT * slot_7(struct StateT * v605) {
  int v606 = v605->timer;
  int v660 = v606 + 1;
  v605->timer = v660;
  int * v608 = v605->regs;
  int v609 = v608[2];
  int * v610 = v605->regs;
  int v611 = v610[21];
  int * v612 = v605->cache_keys;
  int v613 = v612[0];
  bool v667 = v613 == ((int)((unsigned int)(v609 + 68) >> 2));
  int v657;
  if (v667) {
    int * v614 = v605->cache_vals;
    v614[0] = v611;
    v657 = v611;
  } else {
    int * v617 = v605->cache_keys;
    int v618 = v617[1];
    bool v672 = v618 == ((int)((unsigned int)(v609 + 68) >> 2));
    int v655;
    if (v672) {
      int * v619 = v605->cache_keys;
      int * v620 = v605->cache_keys;
      int v621 = v620[0];
      v619[1] = v621;
      int * v623 = v605->cache_vals;
      int * v624 = v605->cache_vals;
      int v625 = v624[0];
      v623[1] = v625;
      int * v627 = v605->cache_keys;
      int v680 = (int)((unsigned int)(v609 + 68) >> 2);
      v627[0] = v680;
      int * v629 = v605->cache_vals;
      v629[0] = v611;
      int v631 = v605->timer;
      int v683 = v631 + 1;
      v605->timer = v683;
      v655 = v611;
    } else {
      int * v634 = v605->mem;
      int * v635 = v605->cache_keys;
      int v636 = v635[1];
      int * v637 = v605->cache_vals;
      int v638 = v637[1];
      v634[v636] = v638;
      int * v640 = v605->cache_keys;
      int * v641 = v605->cache_keys;
      int v642 = v641[0];
      v640[1] = v642;
      int * v644 = v605->cache_vals;
      int * v645 = v605->cache_vals;
      int v646 = v645[0];
      v644[1] = v646;
      int * v648 = v605->cache_keys;
      int v696 = (int)((unsigned int)(v609 + 68) >> 2);
      v648[0] = v696;
      int * v650 = v605->cache_vals;
      v650[0] = v611;
      int v652 = v605->timer;
      int v699 = v652 + 100;
      v605->timer = v699;
      v655 = v611;
    }
    v657 = v655;
  }
  struct StateT * v658 = slot_8(v605);
  return v658;
}

struct StateT * slot_124(struct StateT * v5171) {
  int v5172 = v5171->timer;
  int v5180 = v5172 + 1;
  v5171->timer = v5180;
  int * v5174 = v5171->regs;
  int v5175 = v5174[5];
  int * v5176 = v5171->regs;
  int v5185 = (int)((unsigned int)v5175 >> 14);
  v5176[6] = v5185;
  struct StateT * v5178 = slot_125(v5171);
  return v5178;
}

struct StateT * slot_638(struct StateT * v21602) {
  int v21603 = v21602->timer;
  int v21611 = v21603 + 1;
  v21602->timer = v21611;
  int * v21605 = v21602->regs;
  int v21606 = v21605[6];
  int * v21607 = v21602->regs;
  int v21615 = v21606 << 13;
  v21607[6] = v21615;
  struct StateT * v21609 = slot_639(v21602);
  return v21609;
}

struct StateT * slot_601(struct StateT * v20899) {
  int v20900 = v20899->timer;
  int v20908 = v20900 + 1;
  v20899->timer = v20908;
  int * v20902 = v20899->regs;
  int v20903 = v20902[17];
  int * v20904 = v20899->regs;
  int v20912 = v20903 << 7;
  v20904[17] = v20912;
  struct StateT * v20906 = slot_602(v20899);
  return v20906;
}

struct StateT * slot_128(struct StateT * v5251) {
  int v5252 = v5251->timer;
  int v5262 = v5252 + 1;
  v5251->timer = v5262;
  int * v5254 = v5251->regs;
  int v5255 = v5254[11];
  int * v5256 = v5251->regs;
  int v5257 = v5256[16];
  int * v5258 = v5251->regs;
  int v5269 = v5255 ^ v5257;
  v5258[20] = v5269;
  struct StateT * v5260 = slot_129(v5251);
  return v5260;
}

struct StateT * slot_365(struct StateT * v15259) {
  int v15260 = v15259->timer;
  int v15318 = v15260 + 1;
  v15259->timer = v15318;
  int * v15262 = v15259->regs;
  int v15263 = v15262[2];
  int * v15264 = v15259->cache_keys;
  int v15265 = v15264[0];
  bool v15323 = v15265 == ((int)((unsigned int)(v15263 + 72) >> 2));
  int v15313;
  if (v15323) {
    int * v15266 = v15259->cache_vals;
    int v15267 = v15266[0];
    v15313 = v15267;
  } else {
    int * v15269 = v15259->cache_keys;
    int v15270 = v15269[1];
    bool v15328 = v15270 == ((int)((unsigned int)(v15263 + 72) >> 2));
    int v15311;
    if (v15328) {
      int * v15271 = v15259->cache_vals;
      int v15272 = v15271[1];
      int * v15273 = v15259->cache_keys;
      int * v15274 = v15259->cache_keys;
      int v15275 = v15274[0];
      v15273[1] = v15275;
      int * v15277 = v15259->cache_vals;
      int * v15278 = v15259->cache_vals;
      int v15279 = v15278[0];
      v15277[1] = v15279;
      int * v15281 = v15259->cache_keys;
      int v15337 = (int)((unsigned int)(v15263 + 72) >> 2);
      v15281[0] = v15337;
      int * v15283 = v15259->cache_vals;
      v15283[0] = v15272;
      int v15285 = v15259->timer;
      int v15340 = v15285 + 1;
      v15259->timer = v15340;
      v15311 = v15272;
    } else {
      int * v15288 = v15259->mem;
      int v15342 = (int)((unsigned int)(v15263 + 72) >> 2);
      int v15289 = v15288[v15342];
      int * v15290 = v15259->mem;
      int * v15291 = v15259->cache_keys;
      int v15292 = v15291[1];
      int * v15293 = v15259->cache_vals;
      int v15294 = v15293[1];
      v15290[v15292] = v15294;
      int * v15296 = v15259->cache_keys;
      int * v15297 = v15259->cache_keys;
      int v15298 = v15297[0];
      v15296[1] = v15298;
      int * v15300 = v15259->cache_vals;
      int * v15301 = v15259->cache_vals;
      int v15302 = v15301[0];
      v15300[1] = v15302;
      int * v15304 = v15259->cache_keys;
      v15304[0] = v15342;
      int * v15306 = v15259->cache_vals;
      v15306[0] = v15289;
      int v15308 = v15259->timer;
      int v15357 = v15308 + 100;
      v15259->timer = v15357;
      v15311 = v15289;
    }
    v15313 = v15311;
  }
  int * v15314 = v15259->regs;
  v15314[20] = v15313;
  struct StateT * v15316 = slot_368(v15259);
  return v15316;
}

struct StateT * slot_441(struct StateT * v17740) {
  int v17741 = v17740->timer;
  int v17751 = v17741 + 1;
  v17740->timer = v17751;
  int * v17743 = v17740->regs;
  int v17744 = v17743[23];
  int * v17745 = v17740->regs;
  int v17746 = v17745[15];
  int * v17747 = v17740->regs;
  int v17757 = v17744 ^ v17746;
  v17747[23] = v17757;
  struct StateT * v17749 = slot_442(v17740);
  return v17749;
}

struct StateT * slot_19(struct StateT * v1724) {
  int v1725 = v1724->timer;
  int v1783 = v1725 + 1;
  v1724->timer = v1783;
  int * v1727 = v1724->regs;
  int v1728 = v1727[12];
  int * v1729 = v1724->cache_keys;
  int v1730 = v1729[0];
  bool v1788 = v1730 == ((int)((unsigned int)(v1728 + 16) >> 2));
  int v1778;
  if (v1788) {
    int * v1731 = v1724->cache_vals;
    int v1732 = v1731[0];
    v1778 = v1732;
  } else {
    int * v1734 = v1724->cache_keys;
    int v1735 = v1734[1];
    bool v1793 = v1735 == ((int)((unsigned int)(v1728 + 16) >> 2));
    int v1776;
    if (v1793) {
      int * v1736 = v1724->cache_vals;
      int v1737 = v1736[1];
      int * v1738 = v1724->cache_keys;
      int * v1739 = v1724->cache_keys;
      int v1740 = v1739[0];
      v1738[1] = v1740;
      int * v1742 = v1724->cache_vals;
      int * v1743 = v1724->cache_vals;
      int v1744 = v1743[0];
      v1742[1] = v1744;
      int * v1746 = v1724->cache_keys;
      int v1802 = (int)((unsigned int)(v1728 + 16) >> 2);
      v1746[0] = v1802;
      int * v1748 = v1724->cache_vals;
      v1748[0] = v1737;
      int v1750 = v1724->timer;
      int v1805 = v1750 + 1;
      v1724->timer = v1805;
      v1776 = v1737;
    } else {
      int * v1753 = v1724->mem;
      int v1807 = (int)((unsigned int)(v1728 + 16) >> 2);
      int v1754 = v1753[v1807];
      int * v1755 = v1724->mem;
      int * v1756 = v1724->cache_keys;
      int v1757 = v1756[1];
      int * v1758 = v1724->cache_vals;
      int v1759 = v1758[1];
      v1755[v1757] = v1759;
      int * v1761 = v1724->cache_keys;
      int * v1762 = v1724->cache_keys;
      int v1763 = v1762[0];
      v1761[1] = v1763;
      int * v1765 = v1724->cache_vals;
      int * v1766 = v1724->cache_vals;
      int v1767 = v1766[0];
      v1765[1] = v1767;
      int * v1769 = v1724->cache_keys;
      v1769[0] = v1807;
      int * v1771 = v1724->cache_vals;
      v1771[0] = v1754;
      int v1773 = v1724->timer;
      int v1822 = v1773 + 100;
      v1724->timer = v1822;
      v1776 = v1754;
    }
    v1778 = v1776;
  }
  int * v1779 = v1724->regs;
  v1779[17] = v1778;
  struct StateT * v1781 = slot_20(v1724);
  return v1781;
}

struct StateT * slot_622(struct StateT * v21295) {
  int v21296 = v21295->timer;
  int v21306 = v21296 + 1;
  v21295->timer = v21306;
  int * v21298 = v21295->regs;
  int v21299 = v21298[8];
  int * v21300 = v21295->regs;
  int v21301 = v21300[9];
  int * v21302 = v21295->regs;
  int v21312 = v21299 | v21301;
  v21302[8] = v21312;
  struct StateT * v21304 = slot_623(v21295);
  return v21304;
}

struct StateT * slot_382(struct StateT * v16534) {
  int v16535 = v16534->timer;
  int v16543 = v16535 + 1;
  v16534->timer = v16543;
  int * v16537 = v16534->regs;
  int v16538 = v16537[15];
  int * v16539 = v16534->regs;
  int v16548 = (int)((unsigned int)v16538 >> 19);
  v16539[20] = v16548;
  struct StateT * v16541 = slot_385(v16534);
  return v16541;
}

struct StateT * slot_523(struct StateT * v19307) {
  int * v19308 = v19307->saved_regs;
  int * v19309 = v19307->regs;
  int v19310 = v19309[12];
  v19308[12] = v19310;
  int v19312 = v19307->timer;
  int v19326 = v19312 + 1;
  v19307->timer = v19326;
  int * v19314 = v19307->regs;
  int v19315 = v19314[12];
  int * v19316 = v19307->regs;
  int v19317 = v19316[15];
  int * v19318 = v19307->regs;
  int v19331 = v19315 ^ v19317;
  v19318[12] = v19331;
  struct StateT * v19320 = slot_524(v19307);
  return v19320;
}

struct StateT * slot_87(struct StateT * v4405) {
  int * v4406 = v4405->saved_regs;
  int * v4407 = v4405->regs;
  int v4408 = v4407[26];
  v4406[26] = v4408;
  int v4410 = v4405->timer;
  int v4424 = v4410 + 1;
  v4405->timer = v4424;
  int * v4412 = v4405->regs;
  int v4413 = v4412[26];
  int * v4414 = v4405->regs;
  int v4415 = v4414[15];
  int * v4416 = v4405->regs;
  int v4429 = v4413 ^ v4415;
  v4416[26] = v4429;
  struct StateT * v4418 = slot_88(v4405);
  return v4418;
}

struct StateT * slot_452(struct StateT * v17960) {
  int v17961 = v17960->timer;
  int v17969 = v17961 + 1;
  v17960->timer = v17969;
  int * v17963 = v17960->regs;
  int v17964 = v17963[15];
  int * v17965 = v17960->regs;
  int v17974 = (int)((unsigned int)v17964 >> 23);
  v17965[9] = v17974;
  struct StateT * v17967 = slot_453(v17960);
  return v17967;
}

struct StateT * slot_67(struct StateT * v4001) {
  int * v4002 = v4001->saved_regs;
  int * v4003 = v4001->regs;
  int v4004 = v4003[12];
  v4002[12] = v4004;
  int v4006 = v4001->timer;
  int v4020 = v4006 + 1;
  v4001->timer = v4020;
  int * v4008 = v4001->regs;
  int v4009 = v4008[12];
  int * v4010 = v4001->regs;
  int v4011 = v4010[15];
  int * v4012 = v4001->regs;
  int v4025 = v4009 ^ v4011;
  v4012[12] = v4025;
  struct StateT * v4014 = slot_68(v4001);
  return v4014;
}

struct StateT * slot_591(struct StateT * v20723) {
  int v20724 = v20723->timer;
  int v20732 = v20724 + 1;
  v20723->timer = v20732;
  int * v20726 = v20723->regs;
  int v20727 = v20726[15];
  int * v20728 = v20723->regs;
  int v20737 = (int)((unsigned int)v20727 >> 25);
  v20728[5] = v20737;
  struct StateT * v20730 = slot_592(v20723);
  return v20730;
}

struct StateT * slot_81(struct StateT * v4299) {
  int v4300 = v4299->timer;
  int v4308 = v4300 + 1;
  v4299->timer = v4308;
  int * v4302 = v4299->regs;
  int v4303 = v4302[9];
  int * v4304 = v4299->regs;
  int v4313 = (int)((unsigned int)v4303 >> 23);
  v4304[20] = v4313;
  struct StateT * v4306 = slot_82(v4299);
  return v4306;
}

struct StateT * slot_546(struct StateT * v19792) {
  int * v19793 = v19792->saved_regs;
  int * v19794 = v19792->regs;
  int v19795 = v19794[25];
  v19793[25] = v19795;
  int v19797 = v19792->timer;
  int v19811 = v19797 + 1;
  v19792->timer = v19811;
  int * v19799 = v19792->regs;
  int v19800 = v19799[25];
  int * v19801 = v19792->regs;
  int v19802 = v19801[18];
  int * v19803 = v19792->regs;
  int v19816 = v19800 ^ v19802;
  v19803[25] = v19816;
  struct StateT * v19805 = slot_547(v19792);
  return v19805;
}

struct StateT * slot_556(struct StateT * v19989) {
  int v19990 = v19989->timer;
  int v20000 = v19990 + 1;
  v19989->timer = v20000;
  int * v19992 = v19989->regs;
  int v19993 = v19992[8];
  int * v19994 = v19989->regs;
  int v19995 = v19994[20];
  int * v19996 = v19989->regs;
  int v20006 = v19993 | v19995;
  v19996[8] = v20006;
  struct StateT * v19998 = slot_557(v19989);
  return v19998;
}

struct StateT * slot_651(struct StateT * v21855) {
  int v21856 = v21855->timer;
  int v21864 = v21856 + 1;
  v21855->timer = v21864;
  int * v21858 = v21855->regs;
  int v21859 = v21858[11];
  int * v21860 = v21855->regs;
  int v21869 = (int)((unsigned int)v21859 >> 14);
  v21860[9] = v21869;
  struct StateT * v21862 = slot_652(v21855);
  return v21862;
}

struct StateT * slot_337(struct StateT * v13219) {
  int v13220 = v13219->timer;
  int v13230 = v13220 + 1;
  v13219->timer = v13230;
  int * v13222 = v13219->regs;
  int v13223 = v13222[8];
  int * v13224 = v13219->regs;
  int v13225 = v13224[20];
  int * v13226 = v13219->regs;
  int v13236 = v13223 | v13225;
  v13226[8] = v13236;
  struct StateT * v13228 = slot_340(v13219);
  return v13228;
}

struct StateT * slot_32(struct StateT * v2637) {
  int v2638 = v2637->timer;
  int v2646 = v2638 + 1;
  v2637->timer = v2646;
  int * v2640 = v2637->regs;
  int v2641 = v2640[14];
  int * v2642 = v2637->regs;
  int v2651 = v2641 + -718;
  v2642[19] = v2651;
  struct StateT * v2644 = slot_33(v2637);
  return v2644;
}

struct StateT * slot_233(struct StateT * v7910) {
  int v7911 = v7910->timer;
  int v7921 = v7911 + 1;
  v7910->timer = v7921;
  int * v7913 = v7910->regs;
  int v7914 = v7913[25];
  int * v7915 = v7910->regs;
  int v7916 = v7915[7];
  int * v7917 = v7910->regs;
  int v7927 = v7914 + v7916;
  v7917[25] = v7927;
  struct StateT * v7919 = slot_235(v7910);
  return v7919;
}

struct StateT * slot_595(struct StateT * v20793) {
  int v20794 = v20793->timer;
  int v20802 = v20794 + 1;
  v20793->timer = v20802;
  int * v20796 = v20793->regs;
  int v20797 = v20796[11];
  int * v20798 = v20793->regs;
  int v20806 = v20797 << 7;
  v20798[11] = v20806;
  struct StateT * v20800 = slot_596(v20793);
  return v20800;
}

struct StateT * slot_176(struct StateT * v6190) {
  int v6191 = v6190->timer;
  int v6199 = v6191 + 1;
  v6190->timer = v6199;
  int * v6193 = v6190->regs;
  int v6194 = v6193[11];
  int * v6195 = v6190->regs;
  int v6203 = v6194 << 13;
  v6195[11] = v6203;
  struct StateT * v6197 = slot_177(v6190);
  return v6197;
}

struct StateT * slot_189(struct StateT * v6425) {
  int v6426 = v6425->timer;
  int v6436 = v6426 + 1;
  v6425->timer = v6436;
  int * v6428 = v6425->regs;
  int v6429 = v6428[13];
  int * v6430 = v6425->regs;
  int v6431 = v6430[6];
  int * v6432 = v6425->regs;
  int v6442 = v6429 ^ v6431;
  v6432[13] = v6442;
  struct StateT * v6434 = slot_190(v6425);
  return v6434;
}

struct StateT * slot_394(struct StateT * v16856) {
  int v16857 = v16856->timer;
  int v16867 = v16857 + 1;
  v16856->timer = v16867;
  int * v16859 = v16856->regs;
  int v16860 = v16859[8];
  int * v16861 = v16856->regs;
  int v16862 = v16861[20];
  int * v16863 = v16856->regs;
  int v16873 = v16860 | v16862;
  v16863[8] = v16873;
  struct StateT * v16865 = slot_395(v16856);
  return v16865;
}

struct StateT * slot_398(struct StateT * v16929) {
  int v16930 = v16929->timer;
  int v16938 = v16930 + 1;
  v16929->timer = v16938;
  int * v16932 = v16929->regs;
  int v16933 = v16932[18];
  int * v16934 = v16929->regs;
  int v16943 = (int)((unsigned int)v16933 >> 19);
  v16934[9] = v16943;
  struct StateT * v16936 = slot_399(v16929);
  return v16936;
}

struct StateT * slot_33(struct StateT * v2654) {
  int v2655 = v2654->timer;
  int v2661 = v2655 + 1;
  v2654->timer = v2661;
  int * v2657 = v2654->regs;
  v2657[22] = 1797283840;
  struct StateT * v2659 = slot_34(v2654);
  return v2659;
}

struct StateT * slot_371(struct StateT * v15720) {
  int v15721 = v15720->timer;
  int v15779 = v15721 + 1;
  v15720->timer = v15779;
  int * v15723 = v15720->regs;
  int v15724 = v15723[2];
  int * v15725 = v15720->cache_keys;
  int v15726 = v15725[0];
  bool v15784 = v15726 == ((int)((unsigned int)(v15724 + 64) >> 2));
  int v15774;
  if (v15784) {
    int * v15727 = v15720->cache_vals;
    int v15728 = v15727[0];
    v15774 = v15728;
  } else {
    int * v15730 = v15720->cache_keys;
    int v15731 = v15730[1];
    bool v15789 = v15731 == ((int)((unsigned int)(v15724 + 64) >> 2));
    int v15772;
    if (v15789) {
      int * v15732 = v15720->cache_vals;
      int v15733 = v15732[1];
      int * v15734 = v15720->cache_keys;
      int * v15735 = v15720->cache_keys;
      int v15736 = v15735[0];
      v15734[1] = v15736;
      int * v15738 = v15720->cache_vals;
      int * v15739 = v15720->cache_vals;
      int v15740 = v15739[0];
      v15738[1] = v15740;
      int * v15742 = v15720->cache_keys;
      int v15798 = (int)((unsigned int)(v15724 + 64) >> 2);
      v15742[0] = v15798;
      int * v15744 = v15720->cache_vals;
      v15744[0] = v15733;
      int v15746 = v15720->timer;
      int v15801 = v15746 + 1;
      v15720->timer = v15801;
      v15772 = v15733;
    } else {
      int * v15749 = v15720->mem;
      int v15803 = (int)((unsigned int)(v15724 + 64) >> 2);
      int v15750 = v15749[v15803];
      int * v15751 = v15720->mem;
      int * v15752 = v15720->cache_keys;
      int v15753 = v15752[1];
      int * v15754 = v15720->cache_vals;
      int v15755 = v15754[1];
      v15751[v15753] = v15755;
      int * v15757 = v15720->cache_keys;
      int * v15758 = v15720->cache_keys;
      int v15759 = v15758[0];
      v15757[1] = v15759;
      int * v15761 = v15720->cache_vals;
      int * v15762 = v15720->cache_vals;
      int v15763 = v15762[0];
      v15761[1] = v15763;
      int * v15765 = v15720->cache_keys;
      v15765[0] = v15803;
      int * v15767 = v15720->cache_vals;
      v15767[0] = v15750;
      int v15769 = v15720->timer;
      int v15818 = v15769 + 100;
      v15720->timer = v15818;
      v15772 = v15750;
    }
    v15774 = v15772;
  }
  int * v15775 = v15720->regs;
  v15775[22] = v15774;
  struct StateT * v15777 = slot_374(v15720);
  return v15777;
}

struct StateT * slot_680(struct StateT * v22914) {
  int v22915 = v22914->timer;
  int v22925 = v22915 + 1;
  v22914->timer = v22925;
  int * v22917 = v22914->regs;
  int v22918 = v22917[26];
  int * v22919 = v22914->regs;
  int v22920 = v22919[7];
  int * v22921 = v22914->regs;
  int v22931 = v22918 + v22920;
  v22921[26] = v22931;
  struct StateT * v22923 = slot_681(v22914);
  return v22923;
}

struct StateT * slot_330(struct StateT * v12697) {
  int v12698 = v12697->timer;
  int v12752 = v12698 + 1;
  v12697->timer = v12752;
  int * v12700 = v12697->regs;
  int v12701 = v12700[10];
  int * v12702 = v12697->regs;
  int v12703 = v12702[16];
  int * v12704 = v12697->cache_keys;
  int v12705 = v12704[0];
  bool v12759 = v12705 == ((int)((unsigned int)(v12701 + 48) >> 2));
  int v12749;
  if (v12759) {
    int * v12706 = v12697->cache_vals;
    v12706[0] = v12703;
    v12749 = v12703;
  } else {
    int * v12709 = v12697->cache_keys;
    int v12710 = v12709[1];
    bool v12764 = v12710 == ((int)((unsigned int)(v12701 + 48) >> 2));
    int v12747;
    if (v12764) {
      int * v12711 = v12697->cache_keys;
      int * v12712 = v12697->cache_keys;
      int v12713 = v12712[0];
      v12711[1] = v12713;
      int * v12715 = v12697->cache_vals;
      int * v12716 = v12697->cache_vals;
      int v12717 = v12716[0];
      v12715[1] = v12717;
      int * v12719 = v12697->cache_keys;
      int v12772 = (int)((unsigned int)(v12701 + 48) >> 2);
      v12719[0] = v12772;
      int * v12721 = v12697->cache_vals;
      v12721[0] = v12703;
      int v12723 = v12697->timer;
      int v12775 = v12723 + 1;
      v12697->timer = v12775;
      v12747 = v12703;
    } else {
      int * v12726 = v12697->mem;
      int * v12727 = v12697->cache_keys;
      int v12728 = v12727[1];
      int * v12729 = v12697->cache_vals;
      int v12730 = v12729[1];
      v12726[v12728] = v12730;
      int * v12732 = v12697->cache_keys;
      int * v12733 = v12697->cache_keys;
      int v12734 = v12733[0];
      v12732[1] = v12734;
      int * v12736 = v12697->cache_vals;
      int * v12737 = v12697->cache_vals;
      int v12738 = v12737[0];
      v12736[1] = v12738;
      int * v12740 = v12697->cache_keys;
      int v12788 = (int)((unsigned int)(v12701 + 48) >> 2);
      v12740[0] = v12788;
      int * v12742 = v12697->cache_vals;
      v12742[0] = v12703;
      int v12744 = v12697->timer;
      int v12791 = v12744 + 100;
      v12697->timer = v12791;
      v12747 = v12703;
    }
    v12749 = v12747;
  }
  struct StateT * v12750 = slot_333(v12697);
  return v12750;
}

struct StateT * slot_450(struct StateT * v17924) {
  int v17925 = v17924->timer;
  int v17933 = v17925 + 1;
  v17924->timer = v17933;
  int * v17927 = v17924->regs;
  int v17928 = v17927[11];
  int * v17929 = v17924->regs;
  int v17937 = v17928 << 9;
  v17929[11] = v17937;
  struct StateT * v17931 = slot_451(v17924);
  return v17931;
}

struct StateT * slot_672(struct StateT * v22421) {
  int v22422 = v22421->timer;
  int v22480 = v22422 + 1;
  v22421->timer = v22480;
  int * v22424 = v22421->regs;
  int v22425 = v22424[2];
  int * v22426 = v22421->cache_keys;
  int v22427 = v22426[0];
  bool v22485 = v22427 == ((int)((unsigned int)(v22425 + 8) >> 2));
  int v22475;
  if (v22485) {
    int * v22428 = v22421->cache_vals;
    int v22429 = v22428[0];
    v22475 = v22429;
  } else {
    int * v22431 = v22421->cache_keys;
    int v22432 = v22431[1];
    bool v22490 = v22432 == ((int)((unsigned int)(v22425 + 8) >> 2));
    int v22473;
    if (v22490) {
      int * v22433 = v22421->cache_vals;
      int v22434 = v22433[1];
      int * v22435 = v22421->cache_keys;
      int * v22436 = v22421->cache_keys;
      int v22437 = v22436[0];
      v22435[1] = v22437;
      int * v22439 = v22421->cache_vals;
      int * v22440 = v22421->cache_vals;
      int v22441 = v22440[0];
      v22439[1] = v22441;
      int * v22443 = v22421->cache_keys;
      int v22499 = (int)((unsigned int)(v22425 + 8) >> 2);
      v22443[0] = v22499;
      int * v22445 = v22421->cache_vals;
      v22445[0] = v22434;
      int v22447 = v22421->timer;
      int v22502 = v22447 + 1;
      v22421->timer = v22502;
      v22473 = v22434;
    } else {
      int * v22450 = v22421->mem;
      int v22504 = (int)((unsigned int)(v22425 + 8) >> 2);
      int v22451 = v22450[v22504];
      int * v22452 = v22421->mem;
      int * v22453 = v22421->cache_keys;
      int v22454 = v22453[1];
      int * v22455 = v22421->cache_vals;
      int v22456 = v22455[1];
      v22452[v22454] = v22456;
      int * v22458 = v22421->cache_keys;
      int * v22459 = v22421->cache_keys;
      int v22460 = v22459[0];
      v22458[1] = v22460;
      int * v22462 = v22421->cache_vals;
      int * v22463 = v22421->cache_vals;
      int v22464 = v22463[0];
      v22462[1] = v22464;
      int * v22466 = v22421->cache_keys;
      v22466[0] = v22504;
      int * v22468 = v22421->cache_vals;
      v22468[0] = v22451;
      int v22470 = v22421->timer;
      int v22519 = v22470 + 100;
      v22421->timer = v22519;
      v22473 = v22451;
    }
    v22475 = v22473;
  }
  int * v22476 = v22421->regs;
  v22476[6] = v22475;
  struct StateT * v22478 = slot_673(v22421);
  return v22478;
}

struct StateT * slot_35(struct StateT * v2683) {
  int v2684 = v2683->timer;
  int v2690 = v2684 + 1;
  v2683->timer = v2690;
  int * v2686 = v2683->regs;
  v2686[31] = 9;
  struct StateT * v2688 = slot_36(v2683);
  return v2688;
}

struct StateT * slot_484(struct StateT * v18555) {
  int v18556 = v18555->timer;
  int v18566 = v18556 + 1;
  v18555->timer = v18566;
  int * v18558 = v18555->regs;
  int v18559 = v18558[1];
  int * v18560 = v18555->regs;
  int v18561 = v18560[8];
  int * v18562 = v18555->regs;
  int v18572 = v18559 ^ v18561;
  v18562[1] = v18572;
  struct StateT * v18564 = slot_485(v18555);
  return v18564;
}

struct StateT * slot_258(struct StateT * v9362) {
  int v9363 = v9362->timer;
  int v9373 = v9363 + 1;
  v9362->timer = v9373;
  int * v9365 = v9362->regs;
  int v9366 = v9365[24];
  int * v9367 = v9362->regs;
  int v9368 = v9367[30];
  int * v9369 = v9362->regs;
  int v9379 = v9366 + v9368;
  v9369[24] = v9379;
  struct StateT * v9371 = slot_261(v9362);
  return v9371;
}

struct StateT * slot_166(struct StateT * v5989) {
  int v5990 = v5989->timer;
  int v6000 = v5990 + 1;
  v5989->timer = v6000;
  int * v5992 = v5989->regs;
  int v5993 = v5992[8];
  int * v5994 = v5989->regs;
  int v5995 = v5994[9];
  int * v5996 = v5989->regs;
  int v6006 = v5993 | v5995;
  v5996[8] = v6006;
  struct StateT * v5998 = slot_167(v5989);
  return v5998;
}

struct StateT * slot_615(struct StateT * v21173) {
  int v21174 = v21173->timer;
  int v21182 = v21174 + 1;
  v21173->timer = v21182;
  int * v21176 = v21173->regs;
  int v21177 = v21176[15];
  int * v21178 = v21173->regs;
  int v21186 = v21177 << 9;
  v21178[15] = v21186;
  struct StateT * v21180 = slot_616(v21173);
  return v21180;
}

struct StateT * slot_418(struct StateT * v17309) {
  int v17310 = v17309->timer;
  int v17318 = v17310 + 1;
  v17309->timer = v17318;
  int * v17312 = v17309->regs;
  int v17313 = v17312[5];
  int * v17314 = v17309->regs;
  int v17323 = (int)((unsigned int)v17313 >> 14);
  v17314[6] = v17323;
  struct StateT * v17316 = slot_419(v17309);
  return v17316;
}

struct StateT * slot_51(struct StateT * v3670) {
  int * v3671 = v3670->saved_regs;
  int * v3672 = v3670->regs;
  int v3673 = v3672[15];
  v3671[15] = v3673;
  int v3675 = v3670->timer;
  int v3689 = v3675 + 1;
  v3670->timer = v3689;
  int * v3677 = v3670->regs;
  int v3678 = v3677[21];
  int * v3679 = v3670->regs;
  int v3680 = v3679[16];
  int * v3681 = v3670->regs;
  int v3695 = v3678 + v3680;
  v3681[15] = v3695;
  struct StateT * v3683 = slot_52(v3670);
  return v3683;
}

struct StateT * slot_25(struct StateT * v2354) {
  int v2355 = v2354->timer;
  int v2413 = v2355 + 1;
  v2354->timer = v2413;
  int * v2357 = v2354->regs;
  int v2358 = v2357[11];
  int * v2359 = v2354->cache_keys;
  int v2360 = v2359[0];
  bool v2418 = v2360 == ((int)((unsigned int)(v2358 + 8) >> 2));
  int v2408;
  if (v2418) {
    int * v2361 = v2354->cache_vals;
    int v2362 = v2361[0];
    v2408 = v2362;
  } else {
    int * v2364 = v2354->cache_keys;
    int v2365 = v2364[1];
    bool v2423 = v2365 == ((int)((unsigned int)(v2358 + 8) >> 2));
    int v2406;
    if (v2423) {
      int * v2366 = v2354->cache_vals;
      int v2367 = v2366[1];
      int * v2368 = v2354->cache_keys;
      int * v2369 = v2354->cache_keys;
      int v2370 = v2369[0];
      v2368[1] = v2370;
      int * v2372 = v2354->cache_vals;
      int * v2373 = v2354->cache_vals;
      int v2374 = v2373[0];
      v2372[1] = v2374;
      int * v2376 = v2354->cache_keys;
      int v2432 = (int)((unsigned int)(v2358 + 8) >> 2);
      v2376[0] = v2432;
      int * v2378 = v2354->cache_vals;
      v2378[0] = v2367;
      int v2380 = v2354->timer;
      int v2435 = v2380 + 1;
      v2354->timer = v2435;
      v2406 = v2367;
    } else {
      int * v2383 = v2354->mem;
      int v2437 = (int)((unsigned int)(v2358 + 8) >> 2);
      int v2384 = v2383[v2437];
      int * v2385 = v2354->mem;
      int * v2386 = v2354->cache_keys;
      int v2387 = v2386[1];
      int * v2388 = v2354->cache_vals;
      int v2389 = v2388[1];
      v2385[v2387] = v2389;
      int * v2391 = v2354->cache_keys;
      int * v2392 = v2354->cache_keys;
      int v2393 = v2392[0];
      v2391[1] = v2393;
      int * v2395 = v2354->cache_vals;
      int * v2396 = v2354->cache_vals;
      int v2397 = v2396[0];
      v2395[1] = v2397;
      int * v2399 = v2354->cache_keys;
      v2399[0] = v2437;
      int * v2401 = v2354->cache_vals;
      v2401[0] = v2384;
      int v2403 = v2354->timer;
      int v2452 = v2403 + 100;
      v2354->timer = v2452;
      v2406 = v2384;
    }
    v2408 = v2406;
  }
  int * v2409 = v2354->regs;
  v2409[26] = v2408;
  struct StateT * v2411 = slot_26(v2354);
  return v2411;
}

struct StateT * slot_490(struct StateT * v18676) {
  int v18677 = v18676->timer;
  int v18685 = v18677 + 1;
  v18676->timer = v18685;
  int * v18679 = v18676->regs;
  int v18680 = v18679[11];
  int * v18681 = v18676->regs;
  int v18689 = v18680 << 18;
  v18681[11] = v18689;
  struct StateT * v18683 = slot_491(v18676);
  return v18683;
}

struct StateT * slot_264(struct StateT * v9650) {
  int v9651 = v9650->timer;
  int v9661 = v9651 + 1;
  v9650->timer = v9661;
  int * v9653 = v9650->regs;
  int v9654 = v9653[1];
  int * v9655 = v9650->regs;
  int v9656 = v9655[30];
  int * v9657 = v9650->regs;
  int v9667 = v9654 + v9656;
  v9657[1] = v9667;
  struct StateT * v9659 = slot_267(v9650);
  return v9659;
}

struct StateT * slot_339(struct StateT * v13337) {
  int v13338 = v13337->timer;
  int v13392 = v13338 + 1;
  v13337->timer = v13392;
  int * v13340 = v13337->regs;
  int v13341 = v13340[10];
  int * v13342 = v13337->regs;
  int v13343 = v13342[30];
  int * v13344 = v13337->cache_keys;
  int v13345 = v13344[0];
  bool v13399 = v13345 == ((int)((unsigned int)(v13341 + 60) >> 2));
  int v13389;
  if (v13399) {
    int * v13346 = v13337->cache_vals;
    v13346[0] = v13343;
    v13389 = v13343;
  } else {
    int * v13349 = v13337->cache_keys;
    int v13350 = v13349[1];
    bool v13404 = v13350 == ((int)((unsigned int)(v13341 + 60) >> 2));
    int v13387;
    if (v13404) {
      int * v13351 = v13337->cache_keys;
      int * v13352 = v13337->cache_keys;
      int v13353 = v13352[0];
      v13351[1] = v13353;
      int * v13355 = v13337->cache_vals;
      int * v13356 = v13337->cache_vals;
      int v13357 = v13356[0];
      v13355[1] = v13357;
      int * v13359 = v13337->cache_keys;
      int v13412 = (int)((unsigned int)(v13341 + 60) >> 2);
      v13359[0] = v13412;
      int * v13361 = v13337->cache_vals;
      v13361[0] = v13343;
      int v13363 = v13337->timer;
      int v13415 = v13363 + 1;
      v13337->timer = v13415;
      v13387 = v13343;
    } else {
      int * v13366 = v13337->mem;
      int * v13367 = v13337->cache_keys;
      int v13368 = v13367[1];
      int * v13369 = v13337->cache_vals;
      int v13370 = v13369[1];
      v13366[v13368] = v13370;
      int * v13372 = v13337->cache_keys;
      int * v13373 = v13337->cache_keys;
      int v13374 = v13373[0];
      v13372[1] = v13374;
      int * v13376 = v13337->cache_vals;
      int * v13377 = v13337->cache_vals;
      int v13378 = v13377[0];
      v13376[1] = v13378;
      int * v13380 = v13337->cache_keys;
      int v13428 = (int)((unsigned int)(v13341 + 60) >> 2);
      v13380[0] = v13428;
      int * v13382 = v13337->cache_vals;
      v13382[0] = v13343;
      int v13384 = v13337->timer;
      int v13431 = v13384 + 100;
      v13337->timer = v13431;
      v13387 = v13343;
    }
    v13389 = v13387;
  }
  struct StateT * v13390 = slot_342(v13337);
  return v13390;
}

struct StateT * slot_123(struct StateT * v5151) {
  int v5152 = v5151->timer;
  int v5162 = v5152 + 1;
  v5151->timer = v5162;
  int * v5154 = v5151->regs;
  int v5155 = v5154[17];
  int * v5156 = v5151->regs;
  int v5157 = v5156[6];
  int * v5158 = v5151->regs;
  int v5168 = v5155 | v5157;
  v5158[17] = v5168;
  struct StateT * v5160 = slot_124(v5151);
  return v5160;
}

struct StateT * slot_97(struct StateT * v4630) {
  int v4631 = v4630->timer;
  int v4641 = v4631 + 1;
  v4630->timer = v4641;
  int * v4633 = v4630->regs;
  int v4634 = v4633[15];
  int * v4635 = v4630->regs;
  int v4636 = v4635[20];
  int * v4637 = v4630->regs;
  int v4647 = v4634 | v4636;
  v4637[15] = v4647;
  struct StateT * v4639 = slot_98(v4630);
  return v4639;
}

struct StateT * slot_594(struct StateT * v20776) {
  int v20777 = v20776->timer;
  int v20785 = v20777 + 1;
  v20776->timer = v20785;
  int * v20779 = v20776->regs;
  int v20780 = v20779[11];
  int * v20781 = v20776->regs;
  int v20790 = (int)((unsigned int)v20780 >> 25);
  v20781[5] = v20790;
  struct StateT * v20783 = slot_595(v20776);
  return v20783;
}

struct StateT * slot_106(struct StateT * v4789) {
  int * v4790 = v4789->saved_regs;
  int * v4791 = v4789->regs;
  int v4792 = v4791[6];
  v4790[6] = v4792;
  int v4794 = v4789->timer;
  int v4808 = v4794 + 1;
  v4789->timer = v4808;
  int * v4796 = v4789->regs;
  int v4797 = v4796[18];
  int * v4798 = v4789->regs;
  int v4799 = v4798[9];
  int * v4800 = v4789->regs;
  int v4814 = v4797 | v4799;
  v4800[6] = v4814;
  struct StateT * v4802 = slot_107(v4789);
  return v4802;
}

struct StateT * slot_299(struct StateT * v10520) {
  int v10521 = v10520->timer;
  int v10531 = v10521 + 1;
  v10520->timer = v10531;
  int * v10523 = v10520->regs;
  int v10524 = v10523[22];
  int * v10525 = v10520->regs;
  int v10526 = v10525[30];
  int * v10527 = v10520->regs;
  int v10537 = v10524 + v10526;
  v10527[30] = v10537;
  struct StateT * v10529 = slot_302(v10520);
  return v10529;
}

struct StateT * slot_539(struct StateT * v19638) {
  int v19639 = v19638->timer;
  int v19649 = v19639 + 1;
  v19638->timer = v19649;
  int * v19641 = v19638->regs;
  int v19642 = v19641[9];
  int * v19643 = v19638->regs;
  int v19644 = v19643[20];
  int * v19645 = v19638->regs;
  int v19655 = v19642 | v19644;
  v19645[9] = v19655;
  struct StateT * v19647 = slot_540(v19638);
  return v19647;
}

struct StateT * slot_319(struct StateT * v11937) {
  int v11938 = v11937->timer;
  int v11948 = v11938 + 1;
  v11937->timer = v11948;
  int * v11940 = v11937->regs;
  int v11941 = v11940[14];
  int * v11942 = v11937->regs;
  int v11943 = v11942[22];
  int * v11944 = v11937->regs;
  int v11955 = v11941 + v11943;
  v11944[18] = v11955;
  struct StateT * v11946 = slot_322(v11937);
  return v11946;
}

struct StateT * slot_656(struct StateT * v21941) {
  int v21942 = v21941->timer;
  int v21952 = v21942 + 1;
  v21941->timer = v21952;
  int * v21944 = v21941->regs;
  int v21945 = v21944[15];
  int * v21946 = v21941->regs;
  int v21947 = v21946[9];
  int * v21948 = v21941->regs;
  int v21958 = v21945 | v21947;
  v21948[15] = v21958;
  struct StateT * v21950 = slot_657(v21941);
  return v21950;
}

struct StateT * slot_671(struct StateT * v22401) {
  int v22402 = v22401->timer;
  int v22412 = v22402 + 1;
  v22401->timer = v22412;
  int * v22404 = v22401->regs;
  int v22405 = v22404[14];
  int * v22406 = v22401->regs;
  int v22407 = v22406[7];
  int * v22408 = v22401->regs;
  int v22418 = v22405 + v22407;
  v22408[14] = v22418;
  struct StateT * v22410 = slot_672(v22401);
  return v22410;
}

struct StateT * slot_344(struct StateT * v13671) {
  int v13672 = v13671->timer;
  int v13726 = v13672 + 1;
  v13671->timer = v13726;
  int * v13674 = v13671->regs;
  int v13675 = v13674[10];
  int * v13676 = v13671->regs;
  int v13677 = v13676[1];
  int * v13678 = v13671->cache_keys;
  int v13679 = v13678[0];
  bool v13733 = v13679 == ((int)((unsigned int)(v13675 + 56) >> 2));
  int v13723;
  if (v13733) {
    int * v13680 = v13671->cache_vals;
    v13680[0] = v13677;
    v13723 = v13677;
  } else {
    int * v13683 = v13671->cache_keys;
    int v13684 = v13683[1];
    bool v13737 = v13684 == ((int)((unsigned int)(v13675 + 56) >> 2));
    int v13721;
    if (v13737) {
      int * v13685 = v13671->cache_keys;
      int * v13686 = v13671->cache_keys;
      int v13687 = v13686[0];
      v13685[1] = v13687;
      int * v13689 = v13671->cache_vals;
      int * v13690 = v13671->cache_vals;
      int v13691 = v13690[0];
      v13689[1] = v13691;
      int * v13693 = v13671->cache_keys;
      int v13745 = (int)((unsigned int)(v13675 + 56) >> 2);
      v13693[0] = v13745;
      int * v13695 = v13671->cache_vals;
      v13695[0] = v13677;
      int v13697 = v13671->timer;
      int v13748 = v13697 + 1;
      v13671->timer = v13748;
      v13721 = v13677;
    } else {
      int * v13700 = v13671->mem;
      int * v13701 = v13671->cache_keys;
      int v13702 = v13701[1];
      int * v13703 = v13671->cache_vals;
      int v13704 = v13703[1];
      v13700[v13702] = v13704;
      int * v13706 = v13671->cache_keys;
      int * v13707 = v13671->cache_keys;
      int v13708 = v13707[0];
      v13706[1] = v13708;
      int * v13710 = v13671->cache_vals;
      int * v13711 = v13671->cache_vals;
      int v13712 = v13711[0];
      v13710[1] = v13712;
      int * v13714 = v13671->cache_keys;
      int v13761 = (int)((unsigned int)(v13675 + 56) >> 2);
      v13714[0] = v13761;
      int * v13716 = v13671->cache_vals;
      v13716[0] = v13677;
      int v13718 = v13671->timer;
      int v13764 = v13718 + 100;
      v13671->timer = v13764;
      v13721 = v13677;
    }
    v13723 = v13721;
  }
  struct StateT * v13724 = slot_347(v13671);
  return v13724;
}

struct StateT * slot_513(struct StateT * v19128) {
  int v19129 = v19128->timer;
  int v19139 = v19129 + 1;
  v19128->timer = v19139;
  int * v19131 = v19128->regs;
  int v19132 = v19131[15];
  int * v19133 = v19128->regs;
  int v19134 = v19133[9];
  int * v19135 = v19128->regs;
  int v19145 = v19132 | v19134;
  v19135[15] = v19145;
  struct StateT * v19137 = slot_514(v19128);
  return v19137;
}

struct StateT * slot_130(struct StateT * v5299) {
  int * v5300 = v5299->saved_regs;
  int * v5301 = v5299->regs;
  int v5302 = v5301[22];
  v5300[22] = v5302;
  int v5304 = v5299->timer;
  int v5318 = v5304 + 1;
  v5299->timer = v5318;
  int * v5306 = v5299->regs;
  int v5307 = v5306[22];
  int * v5308 = v5299->regs;
  int v5309 = v5308[5];
  int * v5310 = v5299->regs;
  int v5323 = v5307 ^ v5309;
  v5310[22] = v5323;
  struct StateT * v5312 = slot_131(v5299);
  return v5312;
}

struct StateT * slot_497(struct StateT * v18798) {
  int v18799 = v18798->timer;
  int v18809 = v18799 + 1;
  v18798->timer = v18809;
  int * v18801 = v18798->regs;
  int v18802 = v18801[6];
  int * v18803 = v18798->regs;
  int v18804 = v18803[9];
  int * v18805 = v18798->regs;
  int v18815 = v18802 | v18804;
  v18805[6] = v18815;
  struct StateT * v18807 = slot_498(v18798);
  return v18807;
}

struct StateT * slot_455(struct StateT * v18013) {
  int v18014 = v18013->timer;
  int v18022 = v18014 + 1;
  v18013->timer = v18022;
  int * v18016 = v18013->regs;
  int v18017 = v18016[6];
  int * v18018 = v18013->regs;
  int v18027 = (int)((unsigned int)v18017 >> 23);
  v18018[9] = v18027;
  struct StateT * v18020 = slot_456(v18013);
  return v18020;
}

struct StateT * slot_141(struct StateT * v5523) {
  int v5524 = v5523->timer;
  int v5532 = v5524 + 1;
  v5523->timer = v5532;
  int * v5526 = v5523->regs;
  int v5527 = v5526[16];
  int * v5528 = v5523->regs;
  int v5537 = (int)((unsigned int)v5527 >> 25);
  v5528[5] = v5537;
  struct StateT * v5530 = slot_142(v5523);
  return v5530;
}

struct StateT * slot_432(struct StateT * v17580) {
  int v17581 = v17580->timer;
  int v17589 = v17581 + 1;
  v17580->timer = v17589;
  int * v17583 = v17580->regs;
  int v17584 = v17583[11];
  int * v17585 = v17580->regs;
  int v17594 = (int)((unsigned int)v17584 >> 25);
  v17585[5] = v17594;
  struct StateT * v17587 = slot_433(v17580);
  return v17587;
}

struct StateT * slot_306(struct StateT * v10972) {
  int v10973 = v10972->timer;
  int v11027 = v10973 + 1;
  v10972->timer = v11027;
  int * v10975 = v10972->regs;
  int v10976 = v10975[10];
  int * v10977 = v10972->regs;
  int v10978 = v10977[12];
  int * v10979 = v10972->cache_keys;
  int v10980 = v10979[0];
  bool v11034 = v10980 == ((int)((unsigned int)(v10976 + 16) >> 2));
  int v11024;
  if (v11034) {
    int * v10981 = v10972->cache_vals;
    v10981[0] = v10978;
    v11024 = v10978;
  } else {
    int * v10984 = v10972->cache_keys;
    int v10985 = v10984[1];
    bool v11039 = v10985 == ((int)((unsigned int)(v10976 + 16) >> 2));
    int v11022;
    if (v11039) {
      int * v10986 = v10972->cache_keys;
      int * v10987 = v10972->cache_keys;
      int v10988 = v10987[0];
      v10986[1] = v10988;
      int * v10990 = v10972->cache_vals;
      int * v10991 = v10972->cache_vals;
      int v10992 = v10991[0];
      v10990[1] = v10992;
      int * v10994 = v10972->cache_keys;
      int v11047 = (int)((unsigned int)(v10976 + 16) >> 2);
      v10994[0] = v11047;
      int * v10996 = v10972->cache_vals;
      v10996[0] = v10978;
      int v10998 = v10972->timer;
      int v11050 = v10998 + 1;
      v10972->timer = v11050;
      v11022 = v10978;
    } else {
      int * v11001 = v10972->mem;
      int * v11002 = v10972->cache_keys;
      int v11003 = v11002[1];
      int * v11004 = v10972->cache_vals;
      int v11005 = v11004[1];
      v11001[v11003] = v11005;
      int * v11007 = v10972->cache_keys;
      int * v11008 = v10972->cache_keys;
      int v11009 = v11008[0];
      v11007[1] = v11009;
      int * v11011 = v10972->cache_vals;
      int * v11012 = v10972->cache_vals;
      int v11013 = v11012[0];
      v11011[1] = v11013;
      int * v11015 = v10972->cache_keys;
      int v11063 = (int)((unsigned int)(v10976 + 16) >> 2);
      v11015[0] = v11063;
      int * v11017 = v10972->cache_vals;
      v11017[0] = v10978;
      int v11019 = v10972->timer;
      int v11066 = v11019 + 100;
      v10972->timer = v11066;
      v11022 = v10978;
    }
    v11024 = v11022;
  }
  struct StateT * v11025 = slot_309(v10972);
  return v11025;
}

struct StateT * slot_312(struct StateT * v11405) {
  int v11406 = v11405->timer;
  int v11460 = v11406 + 1;
  v11405->timer = v11460;
  int * v11408 = v11405->regs;
  int v11409 = v11408[10];
  int * v11410 = v11405->regs;
  int v11411 = v11410[5];
  int * v11412 = v11405->cache_keys;
  int v11413 = v11412[0];
  bool v11467 = v11413 == ((int)((unsigned int)(v11409 + 24) >> 2));
  int v11457;
  if (v11467) {
    int * v11414 = v11405->cache_vals;
    v11414[0] = v11411;
    v11457 = v11411;
  } else {
    int * v11417 = v11405->cache_keys;
    int v11418 = v11417[1];
    bool v11472 = v11418 == ((int)((unsigned int)(v11409 + 24) >> 2));
    int v11455;
    if (v11472) {
      int * v11419 = v11405->cache_keys;
      int * v11420 = v11405->cache_keys;
      int v11421 = v11420[0];
      v11419[1] = v11421;
      int * v11423 = v11405->cache_vals;
      int * v11424 = v11405->cache_vals;
      int v11425 = v11424[0];
      v11423[1] = v11425;
      int * v11427 = v11405->cache_keys;
      int v11480 = (int)((unsigned int)(v11409 + 24) >> 2);
      v11427[0] = v11480;
      int * v11429 = v11405->cache_vals;
      v11429[0] = v11411;
      int v11431 = v11405->timer;
      int v11483 = v11431 + 1;
      v11405->timer = v11483;
      v11455 = v11411;
    } else {
      int * v11434 = v11405->mem;
      int * v11435 = v11405->cache_keys;
      int v11436 = v11435[1];
      int * v11437 = v11405->cache_vals;
      int v11438 = v11437[1];
      v11434[v11436] = v11438;
      int * v11440 = v11405->cache_keys;
      int * v11441 = v11405->cache_keys;
      int v11442 = v11441[0];
      v11440[1] = v11442;
      int * v11444 = v11405->cache_vals;
      int * v11445 = v11405->cache_vals;
      int v11446 = v11445[0];
      v11444[1] = v11446;
      int * v11448 = v11405->cache_keys;
      int v11496 = (int)((unsigned int)(v11409 + 24) >> 2);
      v11448[0] = v11496;
      int * v11450 = v11405->cache_vals;
      v11450[0] = v11411;
      int v11452 = v11405->timer;
      int v11499 = v11452 + 100;
      v11405->timer = v11499;
      v11455 = v11411;
    }
    v11457 = v11455;
  }
  struct StateT * v11458 = slot_315(v11405);
  return v11458;
}

struct StateT * slot_4(struct StateT * v311) {
  int v312 = v311->timer;
  int v366 = v312 + 1;
  v311->timer = v366;
  int * v314 = v311->regs;
  int v315 = v314[2];
  int * v316 = v311->regs;
  int v317 = v316[18];
  int * v318 = v311->cache_keys;
  int v319 = v318[0];
  bool v373 = v319 == ((int)((unsigned int)(v315 + 80) >> 2));
  int v363;
  if (v373) {
    int * v320 = v311->cache_vals;
    v320[0] = v317;
    v363 = v317;
  } else {
    int * v323 = v311->cache_keys;
    int v324 = v323[1];
    bool v378 = v324 == ((int)((unsigned int)(v315 + 80) >> 2));
    int v361;
    if (v378) {
      int * v325 = v311->cache_keys;
      int * v326 = v311->cache_keys;
      int v327 = v326[0];
      v325[1] = v327;
      int * v329 = v311->cache_vals;
      int * v330 = v311->cache_vals;
      int v331 = v330[0];
      v329[1] = v331;
      int * v333 = v311->cache_keys;
      int v386 = (int)((unsigned int)(v315 + 80) >> 2);
      v333[0] = v386;
      int * v335 = v311->cache_vals;
      v335[0] = v317;
      int v337 = v311->timer;
      int v389 = v337 + 1;
      v311->timer = v389;
      v361 = v317;
    } else {
      int * v340 = v311->mem;
      int * v341 = v311->cache_keys;
      int v342 = v341[1];
      int * v343 = v311->cache_vals;
      int v344 = v343[1];
      v340[v342] = v344;
      int * v346 = v311->cache_keys;
      int * v347 = v311->cache_keys;
      int v348 = v347[0];
      v346[1] = v348;
      int * v350 = v311->cache_vals;
      int * v351 = v311->cache_vals;
      int v352 = v351[0];
      v350[1] = v352;
      int * v354 = v311->cache_keys;
      int v402 = (int)((unsigned int)(v315 + 80) >> 2);
      v354[0] = v402;
      int * v356 = v311->cache_vals;
      v356[0] = v317;
      int v358 = v311->timer;
      int v405 = v358 + 100;
      v311->timer = v405;
      v361 = v317;
    }
    v363 = v361;
  }
  struct StateT * v364 = slot_5(v311);
  return v364;
}

struct StateT * slot_560(struct StateT * v20062) {
  int v20063 = v20062->timer;
  int v20071 = v20063 + 1;
  v20062->timer = v20071;
  int * v20065 = v20062->regs;
  int v20066 = v20065[18];
  int * v20067 = v20062->regs;
  int v20076 = (int)((unsigned int)v20066 >> 19);
  v20067[9] = v20076;
  struct StateT * v20069 = slot_561(v20062);
  return v20069;
}

struct StateT * slot_240(struct StateT * v8397) {
  int * v8398 = v8397->saved_regs;
  int * v8399 = v8397->regs;
  int v8400 = v8399[26];
  v8398[26] = v8400;
  int v8402 = v8397->timer;
  int v8416 = v8402 + 1;
  v8397->timer = v8416;
  int * v8404 = v8397->regs;
  int v8405 = v8404[26];
  int * v8406 = v8397->regs;
  int v8407 = v8406[7];
  int * v8408 = v8397->regs;
  int v8421 = v8405 + v8407;
  v8408[26] = v8421;
  struct StateT * v8410 = slot_242(v8397);
  return v8410;
}

struct StateT * slot_247(struct StateT * v8707) {
  int v8708 = v8707->timer;
  int v8718 = v8708 + 1;
  v8707->timer = v8718;
  int * v8710 = v8707->regs;
  int v8711 = v8710[17];
  int * v8712 = v8707->regs;
  int v8713 = v8712[30];
  int * v8714 = v8707->regs;
  int v8724 = v8711 + v8713;
  v8714[17] = v8724;
  struct StateT * v8716 = slot_249(v8707);
  return v8716;
}

struct StateT * slot_548(struct StateT * v19840) {
  int v19841 = v19840->timer;
  int v19851 = v19841 + 1;
  v19840->timer = v19851;
  int * v19843 = v19840->regs;
  int v19844 = v19843[24];
  int * v19845 = v19840->regs;
  int v19846 = v19845[13];
  int * v19847 = v19840->regs;
  int v19858 = v19844 + v19846;
  v19847[8] = v19858;
  struct StateT * v19849 = slot_549(v19840);
  return v19849;
}

struct StateT * slot_70(struct StateT * v4082) {
  int * v4083 = v4082->saved_regs;
  int * v4084 = v4082->regs;
  int v4085 = v4084[14];
  v4083[14] = v4085;
  int v4087 = v4082->timer;
  int v4101 = v4087 + 1;
  v4082->timer = v4101;
  int * v4089 = v4082->regs;
  int v4090 = v4089[14];
  int * v4091 = v4082->regs;
  int v4092 = v4091[8];
  int * v4093 = v4082->regs;
  int v4106 = v4090 ^ v4092;
  v4093[14] = v4106;
  struct StateT * v4095 = slot_71(v4082);
  return v4095;
}

struct StateT * slot_168(struct StateT * v6029) {
  int v6030 = v6029->timer;
  int v6040 = v6030 + 1;
  v6029->timer = v6040;
  int * v6032 = v6029->regs;
  int v6033 = v6032[25];
  int * v6034 = v6029->regs;
  int v6035 = v6034[15];
  int * v6036 = v6029->regs;
  int v6046 = v6033 ^ v6035;
  v6036[25] = v6046;
  struct StateT * v6038 = slot_169(v6029);
  return v6038;
}

struct StateT * slot_348(struct StateT * v13991) {
  int v13992 = v13991->timer;
  int v14050 = v13992 + 1;
  v13991->timer = v14050;
  int * v13994 = v13991->regs;
  int v13995 = v13994[2];
  int * v13996 = v13991->cache_keys;
  int v13997 = v13996[0];
  bool v14055 = v13997 == ((int)((unsigned int)(v13995 + 84) >> 2));
  int v14045;
  if (v14055) {
    int * v13998 = v13991->cache_vals;
    int v13999 = v13998[0];
    v14045 = v13999;
  } else {
    int * v14001 = v13991->cache_keys;
    int v14002 = v14001[1];
    bool v14060 = v14002 == ((int)((unsigned int)(v13995 + 84) >> 2));
    int v14043;
    if (v14060) {
      int * v14003 = v13991->cache_vals;
      int v14004 = v14003[1];
      int * v14005 = v13991->cache_keys;
      int * v14006 = v13991->cache_keys;
      int v14007 = v14006[0];
      v14005[1] = v14007;
      int * v14009 = v13991->cache_vals;
      int * v14010 = v13991->cache_vals;
      int v14011 = v14010[0];
      v14009[1] = v14011;
      int * v14013 = v13991->cache_keys;
      int v14069 = (int)((unsigned int)(v13995 + 84) >> 2);
      v14013[0] = v14069;
      int * v14015 = v13991->cache_vals;
      v14015[0] = v14004;
      int v14017 = v13991->timer;
      int v14072 = v14017 + 1;
      v13991->timer = v14072;
      v14043 = v14004;
    } else {
      int * v14020 = v13991->mem;
      int v14074 = (int)((unsigned int)(v13995 + 84) >> 2);
      int v14021 = v14020[v14074];
      int * v14022 = v13991->mem;
      int * v14023 = v13991->cache_keys;
      int v14024 = v14023[1];
      int * v14025 = v13991->cache_vals;
      int v14026 = v14025[1];
      v14022[v14024] = v14026;
      int * v14028 = v13991->cache_keys;
      int * v14029 = v13991->cache_keys;
      int v14030 = v14029[0];
      v14028[1] = v14030;
      int * v14032 = v13991->cache_vals;
      int * v14033 = v13991->cache_vals;
      int v14034 = v14033[0];
      v14032[1] = v14034;
      int * v14036 = v13991->cache_keys;
      v14036[0] = v14074;
      int * v14038 = v13991->cache_vals;
      v14038[0] = v14021;
      int v14040 = v13991->timer;
      int v14089 = v14040 + 100;
      v13991->timer = v14089;
      v14043 = v14021;
    }
    v14045 = v14043;
  }
  int * v14046 = v13991->regs;
  v14046[9] = v14045;
  struct StateT * v14048 = slot_351(v13991);
  return v14048;
}

struct StateT * slot_456(struct StateT * v18030) {
  int v18031 = v18030->timer;
  int v18039 = v18031 + 1;
  v18030->timer = v18039;
  int * v18033 = v18030->regs;
  int v18034 = v18033[6];
  int * v18035 = v18030->regs;
  int v18043 = v18034 << 9;
  v18035[6] = v18043;
  struct StateT * v18037 = slot_457(v18030);
  return v18037;
}

struct StateT * slot_225(struct StateT * v7488) {
  int v7489 = v7488->timer;
  int v7495 = v7489 + 1;
  v7488->timer = v7495;
  int * v7491 = v7488->regs;
  v7491[6] = 857759744;
  struct StateT * v7493 = slot_227(v7488);
  return v7493;
}

struct StateT * slot_467(struct StateT * v18241) {
  int v18242 = v18241->timer;
  int v18252 = v18242 + 1;
  v18241->timer = v18252;
  int * v18244 = v18241->regs;
  int v18245 = v18244[26];
  int * v18246 = v18241->regs;
  int v18247 = v18246[17];
  int * v18248 = v18241->regs;
  int v18259 = v18245 + v18247;
  v18248[6] = v18259;
  struct StateT * v18250 = slot_468(v18241);
  return v18250;
}

struct StateT * slot_285(struct StateT * v10095) {
  int v10096 = v10095->timer;
  int v10106 = v10096 + 1;
  v10095->timer = v10106;
  int * v10098 = v10095->regs;
  int v10099 = v10098[11];
  int * v10100 = v10095->regs;
  int v10101 = v10100[6];
  int * v10102 = v10095->regs;
  int v10112 = v10099 + v10101;
  v10102[11] = v10112;
  struct StateT * v10104 = slot_288(v10095);
  return v10104;
}

struct StateT * slot_659(struct StateT * v21994) {
  int v21995 = v21994->timer;
  int v22005 = v21995 + 1;
  v21994->timer = v22005;
  int * v21997 = v21994->regs;
  int v21998 = v21997[6];
  int * v21999 = v21994->regs;
  int v22000 = v21999[9];
  int * v22001 = v21994->regs;
  int v22011 = v21998 | v22000;
  v22001[6] = v22011;
  struct StateT * v22003 = slot_660(v21994);
  return v22003;
}

struct StateT * slot_213(struct StateT * v7069) {
  int v7070 = v7069->timer;
  int v7080 = v7070 + 1;
  v7069->timer = v7080;
  int * v7072 = v7069->regs;
  int v7073 = v7072[23];
  int * v7074 = v7069->regs;
  int v7075 = v7074[29];
  int * v7076 = v7069->regs;
  int v7086 = v7073 + v7075;
  v7076[29] = v7086;
  struct StateT * v7078 = slot_215(v7069);
  return v7078;
}

struct StateT * slot_82(struct StateT * v4316) {
  int v4317 = v4316->timer;
  int v4325 = v4317 + 1;
  v4316->timer = v4325;
  int * v4319 = v4316->regs;
  int v4320 = v4319[9];
  int * v4321 = v4316->regs;
  int v4329 = v4320 << 9;
  v4321[9] = v4329;
  struct StateT * v4323 = slot_83(v4316);
  return v4323;
}

struct StateT * slot_632(struct StateT * v21496) {
  int v21497 = v21496->timer;
  int v21505 = v21497 + 1;
  v21496->timer = v21505;
  int * v21499 = v21496->regs;
  int v21500 = v21499[11];
  int * v21501 = v21496->regs;
  int v21509 = v21500 << 13;
  v21501[11] = v21509;
  struct StateT * v21503 = slot_633(v21496);
  return v21503;
}

struct StateT * slot_642(struct StateT * v21671) {
  int v21672 = v21671->timer;
  int v21682 = v21672 + 1;
  v21671->timer = v21682;
  int * v21674 = v21671->regs;
  int v21675 = v21674[8];
  int * v21676 = v21671->regs;
  int v21677 = v21676[9];
  int * v21678 = v21671->regs;
  int v21688 = v21675 | v21677;
  v21678[8] = v21688;
  struct StateT * v21680 = slot_643(v21671);
  return v21680;
}

struct StateT * slot_590(struct StateT * v20702) {
  int v20703 = v20702->timer;
  int v20713 = v20703 + 1;
  v20702->timer = v20713;
  int * v20705 = v20702->regs;
  int v20706 = v20705[22];
  int * v20707 = v20702->regs;
  int v20708 = v20707[1];
  int * v20709 = v20702->regs;
  int v20720 = v20706 + v20708;
  v20709[17] = v20720;
  struct StateT * v20711 = slot_591(v20702);
  return v20711;
}

struct StateT * slot_263(struct StateT * v9545) {
  int v9546 = v9545->timer;
  int v9604 = v9546 + 1;
  v9545->timer = v9604;
  int * v9548 = v9545->regs;
  int v9549 = v9548[2];
  int * v9550 = v9545->cache_keys;
  int v9551 = v9550[0];
  bool v9609 = v9551 == ((int)((unsigned int)(v9549 + 36) >> 2));
  int v9599;
  if (v9609) {
    int * v9552 = v9545->cache_vals;
    int v9553 = v9552[0];
    v9599 = v9553;
  } else {
    int * v9555 = v9545->cache_keys;
    int v9556 = v9555[1];
    bool v9614 = v9556 == ((int)((unsigned int)(v9549 + 36) >> 2));
    int v9597;
    if (v9614) {
      int * v9557 = v9545->cache_vals;
      int v9558 = v9557[1];
      int * v9559 = v9545->cache_keys;
      int * v9560 = v9545->cache_keys;
      int v9561 = v9560[0];
      v9559[1] = v9561;
      int * v9563 = v9545->cache_vals;
      int * v9564 = v9545->cache_vals;
      int v9565 = v9564[0];
      v9563[1] = v9565;
      int * v9567 = v9545->cache_keys;
      int v9623 = (int)((unsigned int)(v9549 + 36) >> 2);
      v9567[0] = v9623;
      int * v9569 = v9545->cache_vals;
      v9569[0] = v9558;
      int v9571 = v9545->timer;
      int v9626 = v9571 + 1;
      v9545->timer = v9626;
      v9597 = v9558;
    } else {
      int * v9574 = v9545->mem;
      int v9628 = (int)((unsigned int)(v9549 + 36) >> 2);
      int v9575 = v9574[v9628];
      int * v9576 = v9545->mem;
      int * v9577 = v9545->cache_keys;
      int v9578 = v9577[1];
      int * v9579 = v9545->cache_vals;
      int v9580 = v9579[1];
      v9576[v9578] = v9580;
      int * v9582 = v9545->cache_keys;
      int * v9583 = v9545->cache_keys;
      int v9584 = v9583[0];
      v9582[1] = v9584;
      int * v9586 = v9545->cache_vals;
      int * v9587 = v9545->cache_vals;
      int v9588 = v9587[0];
      v9586[1] = v9588;
      int * v9590 = v9545->cache_keys;
      v9590[0] = v9628;
      int * v9592 = v9545->cache_vals;
      v9592[0] = v9575;
      int v9594 = v9545->timer;
      int v9643 = v9594 + 100;
      v9545->timer = v9643;
      v9597 = v9575;
    }
    v9599 = v9597;
  }
  int * v9600 = v9545->regs;
  v9600[30] = v9599;
  struct StateT * v9602 = slot_266(v9545);
  return v9602;
}

struct StateT * slot_161(struct StateT * v5903) {
  int v5904 = v5903->timer;
  int v5912 = v5904 + 1;
  v5903->timer = v5912;
  int * v5906 = v5903->regs;
  int v5907 = v5906[6];
  int * v5908 = v5903->regs;
  int v5917 = (int)((unsigned int)v5907 >> 23);
  v5908[9] = v5917;
  struct StateT * v5910 = slot_162(v5903);
  return v5910;
}

struct StateT * slot_293(struct StateT * v10244) {
  int v10245 = v10244->timer;
  int v10255 = v10245 + 1;
  v10244->timer = v10255;
  int * v10247 = v10244->regs;
  int v10248 = v10247[11];
  int * v10249 = v10244->regs;
  int v10250 = v10249[6];
  int * v10251 = v10244->regs;
  int v10261 = v10248 + v10250;
  v10251[11] = v10261;
  struct StateT * v10253 = slot_296(v10244);
  return v10253;
}

struct StateT * slot_185(struct StateT * v6349) {
  int v6350 = v6349->timer;
  int v6358 = v6350 + 1;
  v6349->timer = v6358;
  int * v6352 = v6349->regs;
  int v6353 = v6352[8];
  int * v6354 = v6349->regs;
  int v6362 = v6353 << 13;
  v6354[8] = v6362;
  struct StateT * v6356 = slot_186(v6349);
  return v6356;
}

struct StateT * slot_288(struct StateT * v10151) {
  int v10152 = v10151->timer;
  int v10162 = v10152 + 1;
  v10151->timer = v10162;
  int * v10154 = v10151->regs;
  int v10155 = v10154[19];
  int * v10156 = v10151->regs;
  int v10157 = v10156[7];
  int * v10158 = v10151->regs;
  int v10168 = v10155 + v10157;
  v10158[7] = v10168;
  struct StateT * v10160 = slot_291(v10151);
  return v10160;
}

struct StateT * slot_683(struct StateT * v23059) {
  int v23060 = v23059->timer;
  int v23066 = v23060 + 1;
  v23059->timer = v23066;
  int * v23062 = v23059->regs;
  v23062[7] = 2036477952;
  struct StateT * v23064 = slot_251(v23059);
  return v23064;
}

struct StateT * slot_89(struct StateT * v4459) {
  int * v4460 = v4459->saved_regs;
  int * v4461 = v4459->regs;
  int v4462 = v4461[27];
  v4460[27] = v4462;
  int v4464 = v4459->timer;
  int v4478 = v4464 + 1;
  v4459->timer = v4478;
  int * v4466 = v4459->regs;
  int v4467 = v4466[27];
  int * v4468 = v4459->regs;
  int v4469 = v4468[9];
  int * v4470 = v4459->regs;
  int v4483 = v4467 ^ v4469;
  v4470[27] = v4483;
  struct StateT * v4472 = slot_90(v4459);
  return v4472;
}

struct StateT * slot_384(struct StateT * v16656) {
  int v16657 = v16656->timer;
  int v16660 = v16657 + 1;
  v16656->timer = v16660;
  return v16656;
}

struct StateT * slot_486(struct StateT * v18596) {
  int v18597 = v18596->timer;
  int v18607 = v18597 + 1;
  v18596->timer = v18607;
  int * v18599 = v18596->regs;
  int v18600 = v18599[12];
  int * v18601 = v18596->regs;
  int v18602 = v18601[25];
  int * v18603 = v18596->regs;
  int v18614 = v18600 + v18602;
  v18603[15] = v18614;
  struct StateT * v18605 = slot_487(v18596);
  return v18605;
}

struct StateT * slot_347(struct StateT * v13893) {
  int v13894 = v13893->timer;
  int v13948 = v13894 + 1;
  v13893->timer = v13948;
  int * v13896 = v13893->regs;
  int v13897 = v13896[10];
  int * v13898 = v13893->regs;
  int v13899 = v13898[30];
  int * v13900 = v13893->cache_keys;
  int v13901 = v13900[0];
  bool v13955 = v13901 == ((int)((unsigned int)(v13897 + 60) >> 2));
  int v13945;
  if (v13955) {
    int * v13902 = v13893->cache_vals;
    v13902[0] = v13899;
    v13945 = v13899;
  } else {
    int * v13905 = v13893->cache_keys;
    int v13906 = v13905[1];
    bool v13960 = v13906 == ((int)((unsigned int)(v13897 + 60) >> 2));
    int v13943;
    if (v13960) {
      int * v13907 = v13893->cache_keys;
      int * v13908 = v13893->cache_keys;
      int v13909 = v13908[0];
      v13907[1] = v13909;
      int * v13911 = v13893->cache_vals;
      int * v13912 = v13893->cache_vals;
      int v13913 = v13912[0];
      v13911[1] = v13913;
      int * v13915 = v13893->cache_keys;
      int v13968 = (int)((unsigned int)(v13897 + 60) >> 2);
      v13915[0] = v13968;
      int * v13917 = v13893->cache_vals;
      v13917[0] = v13899;
      int v13919 = v13893->timer;
      int v13971 = v13919 + 1;
      v13893->timer = v13971;
      v13943 = v13899;
    } else {
      int * v13922 = v13893->mem;
      int * v13923 = v13893->cache_keys;
      int v13924 = v13923[1];
      int * v13925 = v13893->cache_vals;
      int v13926 = v13925[1];
      v13922[v13924] = v13926;
      int * v13928 = v13893->cache_keys;
      int * v13929 = v13893->cache_keys;
      int v13930 = v13929[0];
      v13928[1] = v13930;
      int * v13932 = v13893->cache_vals;
      int * v13933 = v13893->cache_vals;
      int v13934 = v13933[0];
      v13932[1] = v13934;
      int * v13936 = v13893->cache_keys;
      int v13984 = (int)((unsigned int)(v13897 + 60) >> 2);
      v13936[0] = v13984;
      int * v13938 = v13893->cache_vals;
      v13938[0] = v13899;
      int v13940 = v13893->timer;
      int v13987 = v13940 + 100;
      v13893->timer = v13987;
      v13943 = v13899;
    }
    v13945 = v13943;
  }
  struct StateT * v13946 = slot_350(v13893);
  return v13946;
}

struct StateT * slot_140(struct StateT * v5503) {
  int v5504 = v5503->timer;
  int v5514 = v5504 + 1;
  v5503->timer = v5514;
  int * v5506 = v5503->regs;
  int v5507 = v5506[11];
  int * v5508 = v5503->regs;
  int v5509 = v5508[5];
  int * v5510 = v5503->regs;
  int v5520 = v5507 | v5509;
  v5510[11] = v5520;
  struct StateT * v5512 = slot_141(v5503);
  return v5512;
}

struct StateT * slot_473(struct StateT * v18353) {
  int v18354 = v18353->timer;
  int v18362 = v18354 + 1;
  v18353->timer = v18362;
  int * v18356 = v18353->regs;
  int v18357 = v18356[15];
  int * v18358 = v18353->regs;
  int v18366 = v18357 << 13;
  v18358[15] = v18366;
  struct StateT * v18360 = slot_474(v18353);
  return v18360;
}

struct StateT * slot_49(struct StateT * v3645) {
  int v3646 = v3645->timer;
  int v3654 = v3646 + 1;
  v3645->timer = v3654;
  int * v3648 = v3645->regs;
  int v3649 = v3648[15];
  int * v3650 = v3645->regs;
  v3650[13] = v3649;
  struct StateT * v3652 = slot_50(v3645);
  return v3652;
}

struct StateT * slot_216(struct StateT * v7117) {
  int * v7118 = v7117->saved_regs;
  int * v7119 = v7117->regs;
  int v7120 = v7119[29];
  v7118[29] = v7120;
  int v7122 = v7117->timer;
  int v7136 = v7122 + 1;
  v7117->timer = v7136;
  int * v7124 = v7117->regs;
  int v7125 = v7124[23];
  int * v7126 = v7117->regs;
  int v7127 = v7126[29];
  int * v7128 = v7117->regs;
  int v7141 = v7125 + v7127;
  v7128[29] = v7141;
  struct StateT * v7130 = slot_218(v7117);
  return v7130;
}

struct StateT * slot_468(struct StateT * v18262) {
  int v18263 = v18262->timer;
  int v18273 = v18263 + 1;
  v18262->timer = v18273;
  int * v18265 = v18262->regs;
  int v18266 = v18265[24];
  int * v18267 = v18262->regs;
  int v18268 = v18267[16];
  int * v18269 = v18262->regs;
  int v18280 = v18266 + v18268;
  v18269[8] = v18280;
  struct StateT * v18271 = slot_469(v18262);
  return v18271;
}

struct StateT * slot_50(struct StateT * v3662) {
  int v3663 = v3662->timer;
  int v3667 = v3663 + 1;
  v3662->timer = v3667;
  struct StateT * v3665 = slot_51(v3662);
  return v3665;
}

struct StateT * slot_135(struct StateT * v5417) {
  int v5418 = v5417->timer;
  int v5426 = v5418 + 1;
  v5417->timer = v5426;
  int * v5420 = v5417->regs;
  int v5421 = v5420[15];
  int * v5422 = v5417->regs;
  int v5431 = (int)((unsigned int)v5421 >> 25);
  v5422[5] = v5431;
  struct StateT * v5424 = slot_136(v5417);
  return v5424;
}

struct StateT * slot_248(struct StateT * v8727) {
  int * v8728 = v8727->regs;
  int v8729 = v8728[31];
  int * v8730 = v8727->regs;
  int v8731 = v8730[30];
  bool v8788 = (v8729 ^ -2147483648) >= (v8731 ^ -2147483648);
  struct StateT * v8782;
  if (v8788) {
    int v8732 = v8727->timer;
    int v8789 = v8732 + 15;
    v8727->timer = v8789;
    int * v8734 = v8727->saved_regs;
    int v8735 = v8734[29];
    int * v8736 = v8727->regs;
    v8736[29] = v8735;
    int * v8738 = v8727->saved_regs;
    int v8739 = v8738[28];
    int * v8740 = v8727->regs;
    v8740[28] = v8739;
    int * v8742 = v8727->saved_regs;
    int v8743 = v8742[15];
    int * v8744 = v8727->regs;
    v8744[15] = v8743;
    int * v8746 = v8727->saved_regs;
    int v8747 = v8746[14];
    int * v8748 = v8727->regs;
    v8748[14] = v8747;
    int * v8750 = v8727->saved_regs;
    int v8751 = v8750[6];
    int * v8752 = v8727->regs;
    v8752[6] = v8751;
    int * v8754 = v8727->saved_regs;
    int v8755 = v8754[12];
    int * v8756 = v8727->regs;
    v8756[12] = v8755;
    int * v8758 = v8727->saved_regs;
    int v8759 = v8758[7];
    int * v8760 = v8727->regs;
    v8760[7] = v8759;
    int * v8762 = v8727->saved_regs;
    int v8763 = v8762[5];
    int * v8764 = v8727->regs;
    v8764[5] = v8763;
    int * v8766 = v8727->saved_regs;
    int v8767 = v8766[25];
    int * v8768 = v8727->regs;
    v8768[25] = v8767;
    int * v8770 = v8727->saved_regs;
    int v8771 = v8770[26];
    int * v8772 = v8727->regs;
    v8772[26] = v8771;
    int * v8774 = v8727->saved_regs;
    int v8775 = v8774[13];
    int * v8776 = v8727->regs;
    v8776[13] = v8775;
    struct StateT * v8778 = slot_250(v8727);
    v8782 = v8778;
  } else {
    struct StateT * v8780 = slot_251(v8727);
    v8782 = v8780;
  }
  return v8782;
}

struct StateT * slot_59(struct StateT * v3859) {
  int v3860 = v3859->timer;
  int v3868 = v3860 + 1;
  v3859->timer = v3868;
  int * v3862 = v3859->regs;
  int v3863 = v3862[20];
  int * v3864 = v3859->regs;
  int v3872 = v3863 << 7;
  v3864[20] = v3872;
  struct StateT * v3866 = slot_60(v3859);
  return v3866;
}

struct StateT * slot_485(struct StateT * v18575) {
  int v18576 = v18575->timer;
  int v18586 = v18576 + 1;
  v18575->timer = v18586;
  int * v18578 = v18575->regs;
  int v18579 = v18578[14];
  int * v18580 = v18575->regs;
  int v18581 = v18580[27];
  int * v18582 = v18575->regs;
  int v18593 = v18579 + v18581;
  v18582[11] = v18593;
  struct StateT * v18584 = slot_486(v18575);
  return v18584;
}

struct StateT * slot_40(struct StateT * v3087) {
  int v3088 = v3087->timer;
  int v3142 = v3088 + 1;
  v3087->timer = v3142;
  int * v3090 = v3087->regs;
  int v3091 = v3090[2];
  int * v3092 = v3087->regs;
  int v3093 = v3092[24];
  int * v3094 = v3087->cache_keys;
  int v3095 = v3094[0];
  bool v3149 = v3095 == ((int)((unsigned int)(v3091 + 36) >> 2));
  int v3139;
  if (v3149) {
    int * v3096 = v3087->cache_vals;
    v3096[0] = v3093;
    v3139 = v3093;
  } else {
    int * v3099 = v3087->cache_keys;
    int v3100 = v3099[1];
    bool v3154 = v3100 == ((int)((unsigned int)(v3091 + 36) >> 2));
    int v3137;
    if (v3154) {
      int * v3101 = v3087->cache_keys;
      int * v3102 = v3087->cache_keys;
      int v3103 = v3102[0];
      v3101[1] = v3103;
      int * v3105 = v3087->cache_vals;
      int * v3106 = v3087->cache_vals;
      int v3107 = v3106[0];
      v3105[1] = v3107;
      int * v3109 = v3087->cache_keys;
      int v3162 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3109[0] = v3162;
      int * v3111 = v3087->cache_vals;
      v3111[0] = v3093;
      int v3113 = v3087->timer;
      int v3165 = v3113 + 1;
      v3087->timer = v3165;
      v3137 = v3093;
    } else {
      int * v3116 = v3087->mem;
      int * v3117 = v3087->cache_keys;
      int v3118 = v3117[1];
      int * v3119 = v3087->cache_vals;
      int v3120 = v3119[1];
      v3116[v3118] = v3120;
      int * v3122 = v3087->cache_keys;
      int * v3123 = v3087->cache_keys;
      int v3124 = v3123[0];
      v3122[1] = v3124;
      int * v3126 = v3087->cache_vals;
      int * v3127 = v3087->cache_vals;
      int v3128 = v3127[0];
      v3126[1] = v3128;
      int * v3130 = v3087->cache_keys;
      int v3178 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3130[0] = v3178;
      int * v3132 = v3087->cache_vals;
      v3132[0] = v3093;
      int v3134 = v3087->timer;
      int v3181 = v3134 + 100;
      v3087->timer = v3181;
      v3137 = v3093;
    }
    v3139 = v3137;
  }
  struct StateT * v3140 = slot_41(v3087);
  return v3140;
}

struct StateT * slot_586(struct StateT * v20605) {
  int * v20606 = v20605->saved_regs;
  int * v20607 = v20605->regs;
  int v20608 = v20607[22];
  v20606[22] = v20608;
  int v20610 = v20605->timer;
  int v20624 = v20610 + 1;
  v20605->timer = v20624;
  int * v20612 = v20605->regs;
  int v20613 = v20612[22];
  int * v20614 = v20605->regs;
  int v20615 = v20614[5];
  int * v20616 = v20605->regs;
  int v20629 = v20613 ^ v20615;
  v20616[22] = v20629;
  struct StateT * v20618 = slot_587(v20605);
  return v20618;
}

struct StateT * slot_77(struct StateT * v4226) {
  int v4227 = v4226->timer;
  int v4237 = v4227 + 1;
  v4226->timer = v4237;
  int * v4229 = v4226->regs;
  int v4230 = v4229[15];
  int * v4231 = v4226->regs;
  int v4232 = v4231[20];
  int * v4233 = v4226->regs;
  int v4243 = v4230 | v4232;
  v4233[15] = v4243;
  struct StateT * v4235 = slot_78(v4226);
  return v4235;
}

struct StateT * slot_85(struct StateT * v4369) {
  int v4370 = v4369->timer;
  int v4378 = v4370 + 1;
  v4369->timer = v4378;
  int * v4372 = v4369->regs;
  int v4373 = v4372[18];
  int * v4374 = v4369->regs;
  int v4382 = v4373 << 9;
  v4374[18] = v4382;
  struct StateT * v4376 = slot_86(v4369);
  return v4376;
}

struct StateT * slot_350(struct StateT * v14113) {
  int v14114 = v14113->timer;
  int v14172 = v14114 + 1;
  v14113->timer = v14172;
  int * v14116 = v14113->regs;
  int v14117 = v14116[2];
  int * v14118 = v14113->cache_keys;
  int v14119 = v14118[0];
  bool v14177 = v14119 == ((int)((unsigned int)(v14117 + 92) >> 2));
  int v14167;
  if (v14177) {
    int * v14120 = v14113->cache_vals;
    int v14121 = v14120[0];
    v14167 = v14121;
  } else {
    int * v14123 = v14113->cache_keys;
    int v14124 = v14123[1];
    bool v14182 = v14124 == ((int)((unsigned int)(v14117 + 92) >> 2));
    int v14165;
    if (v14182) {
      int * v14125 = v14113->cache_vals;
      int v14126 = v14125[1];
      int * v14127 = v14113->cache_keys;
      int * v14128 = v14113->cache_keys;
      int v14129 = v14128[0];
      v14127[1] = v14129;
      int * v14131 = v14113->cache_vals;
      int * v14132 = v14113->cache_vals;
      int v14133 = v14132[0];
      v14131[1] = v14133;
      int * v14135 = v14113->cache_keys;
      int v14191 = (int)((unsigned int)(v14117 + 92) >> 2);
      v14135[0] = v14191;
      int * v14137 = v14113->cache_vals;
      v14137[0] = v14126;
      int v14139 = v14113->timer;
      int v14194 = v14139 + 1;
      v14113->timer = v14194;
      v14165 = v14126;
    } else {
      int * v14142 = v14113->mem;
      int v14196 = (int)((unsigned int)(v14117 + 92) >> 2);
      int v14143 = v14142[v14196];
      int * v14144 = v14113->mem;
      int * v14145 = v14113->cache_keys;
      int v14146 = v14145[1];
      int * v14147 = v14113->cache_vals;
      int v14148 = v14147[1];
      v14144[v14146] = v14148;
      int * v14150 = v14113->cache_keys;
      int * v14151 = v14113->cache_keys;
      int v14152 = v14151[0];
      v14150[1] = v14152;
      int * v14154 = v14113->cache_vals;
      int * v14155 = v14113->cache_vals;
      int v14156 = v14155[0];
      v14154[1] = v14156;
      int * v14158 = v14113->cache_keys;
      v14158[0] = v14196;
      int * v14160 = v14113->cache_vals;
      v14160[0] = v14143;
      int v14162 = v14113->timer;
      int v14211 = v14162 + 100;
      v14113->timer = v14211;
      v14165 = v14143;
    }
    v14167 = v14165;
  }
  int * v14168 = v14113->regs;
  v14168[1] = v14167;
  struct StateT * v14170 = slot_353(v14113);
  return v14170;
}

struct StateT * slot_392(struct StateT * v16840) {
  int v16841 = v16840->timer;
  int v16849 = v16841 + 1;
  v16840->timer = v16849;
  int * v16843 = v16840->regs;
  int v16844 = v16843[8];
  int * v16845 = v16840->regs;
  int v16853 = v16844 << 13;
  v16845[8] = v16853;
  struct StateT * v16847 = slot_394(v16840);
  return v16847;
}

struct StateT * slot_75(struct StateT * v4193) {
  int v4194 = v4193->timer;
  int v4202 = v4194 + 1;
  v4193->timer = v4202;
  int * v4196 = v4193->regs;
  int v4197 = v4196[15];
  int * v4198 = v4193->regs;
  int v4207 = (int)((unsigned int)v4197 >> 23);
  v4198[20] = v4207;
  struct StateT * v4200 = slot_76(v4193);
  return v4200;
}

struct StateT * slot_581(struct StateT * v20494) {
  int v20495 = v20494->timer;
  int v20503 = v20495 + 1;
  v20494->timer = v20503;
  int * v20497 = v20494->regs;
  int v20498 = v20497[5];
  int * v20499 = v20494->regs;
  int v20507 = v20498 << 18;
  v20499[5] = v20507;
  struct StateT * v20501 = slot_582(v20494);
  return v20501;
}

struct StateT * slot_625(struct StateT * v21355) {
  int v21356 = v21355->timer;
  int v21366 = v21356 + 1;
  v21355->timer = v21366;
  int * v21358 = v21355->regs;
  int v21359 = v21358[26];
  int * v21360 = v21355->regs;
  int v21361 = v21360[6];
  int * v21362 = v21355->regs;
  int v21372 = v21359 ^ v21361;
  v21362[26] = v21372;
  struct StateT * v21364 = slot_626(v21355);
  return v21364;
}

struct StateT * slot_71(struct StateT * v4109) {
  int v4110 = v4109->timer;
  int v4120 = v4110 + 1;
  v4109->timer = v4120;
  int * v4112 = v4109->regs;
  int v4113 = v4112[12];
  int * v4114 = v4109->regs;
  int v4115 = v4114[21];
  int * v4116 = v4109->regs;
  int v4127 = v4113 + v4115;
  v4116[15] = v4127;
  struct StateT * v4118 = slot_72(v4109);
  return v4118;
}

struct StateT * slot_378(struct StateT * v16287) {
  int v16288 = v16287->timer;
  int v16346 = v16288 + 1;
  v16287->timer = v16346;
  int * v16290 = v16287->regs;
  int v16291 = v16290[2];
  int * v16292 = v16287->cache_keys;
  int v16293 = v16292[0];
  bool v16351 = v16293 == ((int)((unsigned int)(v16291 + 44) >> 2));
  int v16341;
  if (v16351) {
    int * v16294 = v16287->cache_vals;
    int v16295 = v16294[0];
    v16341 = v16295;
  } else {
    int * v16297 = v16287->cache_keys;
    int v16298 = v16297[1];
    bool v16356 = v16298 == ((int)((unsigned int)(v16291 + 44) >> 2));
    int v16339;
    if (v16356) {
      int * v16299 = v16287->cache_vals;
      int v16300 = v16299[1];
      int * v16301 = v16287->cache_keys;
      int * v16302 = v16287->cache_keys;
      int v16303 = v16302[0];
      v16301[1] = v16303;
      int * v16305 = v16287->cache_vals;
      int * v16306 = v16287->cache_vals;
      int v16307 = v16306[0];
      v16305[1] = v16307;
      int * v16309 = v16287->cache_keys;
      int v16365 = (int)((unsigned int)(v16291 + 44) >> 2);
      v16309[0] = v16365;
      int * v16311 = v16287->cache_vals;
      v16311[0] = v16300;
      int v16313 = v16287->timer;
      int v16368 = v16313 + 1;
      v16287->timer = v16368;
      v16339 = v16300;
    } else {
      int * v16316 = v16287->mem;
      int v16370 = (int)((unsigned int)(v16291 + 44) >> 2);
      int v16317 = v16316[v16370];
      int * v16318 = v16287->mem;
      int * v16319 = v16287->cache_keys;
      int v16320 = v16319[1];
      int * v16321 = v16287->cache_vals;
      int v16322 = v16321[1];
      v16318[v16320] = v16322;
      int * v16324 = v16287->cache_keys;
      int * v16325 = v16287->cache_keys;
      int v16326 = v16325[0];
      v16324[1] = v16326;
      int * v16328 = v16287->cache_vals;
      int * v16329 = v16287->cache_vals;
      int v16330 = v16329[0];
      v16328[1] = v16330;
      int * v16332 = v16287->cache_keys;
      v16332[0] = v16370;
      int * v16334 = v16287->cache_vals;
      v16334[0] = v16317;
      int v16336 = v16287->timer;
      int v16385 = v16336 + 100;
      v16287->timer = v16385;
      v16339 = v16317;
    }
    v16341 = v16339;
  }
  int * v16342 = v16287->regs;
  v16342[27] = v16341;
  struct StateT * v16344 = slot_381(v16287);
  return v16344;
}

struct StateT * slot_108(struct StateT * v4838) {
  int * v4839 = v4838->saved_regs;
  int * v4840 = v4838->regs;
  int v4841 = v4840[23];
  v4839[23] = v4841;
  int v4843 = v4838->timer;
  int v4857 = v4843 + 1;
  v4838->timer = v4857;
  int * v4845 = v4838->regs;
  int v4846 = v4845[23];
  int * v4847 = v4838->regs;
  int v4848 = v4847[8];
  int * v4849 = v4838->regs;
  int v4862 = v4846 ^ v4848;
  v4849[23] = v4862;
  struct StateT * v4851 = slot_109(v4838);
  return v4851;
}

struct StateT * slot_619(struct StateT * v21242) {
  int v21243 = v21242->timer;
  int v21253 = v21243 + 1;
  v21242->timer = v21253;
  int * v21245 = v21242->regs;
  int v21246 = v21245[6];
  int * v21247 = v21242->regs;
  int v21248 = v21247[9];
  int * v21249 = v21242->regs;
  int v21259 = v21246 | v21248;
  v21249[6] = v21259;
  struct StateT * v21251 = slot_620(v21242);
  return v21251;
}

struct StateT * slot_116(struct StateT * v5029) {
  int v5030 = v5029->timer;
  int v5038 = v5030 + 1;
  v5029->timer = v5038;
  int * v5032 = v5029->regs;
  int v5033 = v5032[15];
  int * v5034 = v5029->regs;
  int v5042 = v5033 << 18;
  v5034[15] = v5042;
  struct StateT * v5036 = slot_117(v5029);
  return v5036;
}

struct StateT * slot_618(struct StateT * v21226) {
  int v21227 = v21226->timer;
  int v21235 = v21227 + 1;
  v21226->timer = v21235;
  int * v21229 = v21226->regs;
  int v21230 = v21229[6];
  int * v21231 = v21226->regs;
  int v21239 = v21230 << 9;
  v21231[6] = v21239;
  struct StateT * v21233 = slot_619(v21226);
  return v21233;
}

struct StateT * slot_417(struct StateT * v17289) {
  int v17290 = v17289->timer;
  int v17300 = v17290 + 1;
  v17289->timer = v17300;
  int * v17292 = v17289->regs;
  int v17293 = v17292[17];
  int * v17294 = v17289->regs;
  int v17295 = v17294[6];
  int * v17296 = v17289->regs;
  int v17306 = v17293 | v17295;
  v17296[17] = v17306;
  struct StateT * v17298 = slot_418(v17289);
  return v17298;
}

struct StateT * slot_405(struct StateT * v17066) {
  int v17067 = v17066->timer;
  int v17077 = v17067 + 1;
  v17066->timer = v17077;
  int * v17069 = v17066->regs;
  int v17070 = v17069[9];
  int * v17071 = v17066->regs;
  int v17072 = v17071[26];
  int * v17073 = v17066->regs;
  int v17084 = v17070 + v17072;
  v17073[15] = v17084;
  struct StateT * v17075 = slot_406(v17066);
  return v17075;
}

struct StateT * slot_215(struct StateT * v7097) {
  int v7098 = v7097->timer;
  int v7108 = v7098 + 1;
  v7097->timer = v7108;
  int * v7100 = v7097->regs;
  int v7101 = v7100[27];
  int * v7102 = v7097->regs;
  int v7103 = v7102[28];
  int * v7104 = v7097->regs;
  int v7114 = v7101 + v7103;
  v7104[28] = v7114;
  struct StateT * v7106 = slot_217(v7097);
  return v7106;
}

struct StateT * slot_45(struct StateT * v3496) {
  int v3497 = v3496->timer;
  int v3505 = v3497 + 1;
  v3496->timer = v3505;
  int * v3499 = v3496->regs;
  int v3500 = v3499[7];
  int * v3501 = v3496->regs;
  v3501[14] = v3500;
  struct StateT * v3503 = slot_46(v3496);
  return v3503;
}

struct StateT * slot_579(struct StateT * v20457) {
  int v20458 = v20457->timer;
  int v20468 = v20458 + 1;
  v20457->timer = v20468;
  int * v20460 = v20457->regs;
  int v20461 = v20460[17];
  int * v20462 = v20457->regs;
  int v20463 = v20462[6];
  int * v20464 = v20457->regs;
  int v20474 = v20461 | v20463;
  v20464[17] = v20474;
  struct StateT * v20466 = slot_580(v20457);
  return v20466;
}

struct StateT * slot_220(struct StateT * v7204) {
  int * v7205 = v7204->saved_regs;
  int * v7206 = v7204->regs;
  int v7207 = v7206[15];
  v7205[15] = v7207;
  int v7209 = v7204->timer;
  int v7219 = v7209 + 1;
  v7204->timer = v7219;
  int * v7211 = v7204->regs;
  v7211[15] = 1634762752;
  struct StateT * v7213 = slot_222(v7204);
  return v7213;
}

struct StateT * slot_134(struct StateT * v5396) {
  int v5397 = v5396->timer;
  int v5407 = v5397 + 1;
  v5396->timer = v5407;
  int * v5399 = v5396->regs;
  int v5400 = v5399[22];
  int * v5401 = v5396->regs;
  int v5402 = v5401[1];
  int * v5403 = v5396->regs;
  int v5414 = v5400 + v5402;
  v5403[17] = v5414;
  struct StateT * v5405 = slot_135(v5396);
  return v5405;
}

struct StateT * slot_463(struct StateT * v18159) {
  int v18160 = v18159->timer;
  int v18170 = v18160 + 1;
  v18159->timer = v18170;
  int * v18162 = v18159->regs;
  int v18163 = v18162[26];
  int * v18164 = v18159->regs;
  int v18165 = v18164[6];
  int * v18166 = v18159->regs;
  int v18176 = v18163 ^ v18165;
  v18166[26] = v18176;
  struct StateT * v18168 = slot_464(v18159);
  return v18168;
}

struct StateT * slot_175(struct StateT * v6173) {
  int v6174 = v6173->timer;
  int v6182 = v6174 + 1;
  v6173->timer = v6182;
  int * v6176 = v6173->regs;
  int v6177 = v6176[11];
  int * v6178 = v6173->regs;
  int v6187 = (int)((unsigned int)v6177 >> 19);
  v6178[9] = v6187;
  struct StateT * v6180 = slot_176(v6173);
  return v6180;
}

struct StateT * slot_273(struct StateT * v9897) {
  int v9898 = v9897->timer;
  int v9906 = v9898 + 1;
  v9897->timer = v9906;
  int * v9900 = v9897->regs;
  int v9901 = v9900[6];
  int * v9902 = v9897->regs;
  int v9910 = v9901 + 1134;
  v9902[6] = v9910;
  struct StateT * v9904 = slot_276(v9897);
  return v9904;
}

struct StateT * slot_69(struct StateT * v4055) {
  int * v4056 = v4055->saved_regs;
  int * v4057 = v4055->regs;
  int v4058 = v4057[1];
  v4056[1] = v4058;
  int v4060 = v4055->timer;
  int v4074 = v4060 + 1;
  v4055->timer = v4074;
  int * v4062 = v4055->regs;
  int v4063 = v4062[1];
  int * v4064 = v4055->regs;
  int v4065 = v4064[18];
  int * v4066 = v4055->regs;
  int v4079 = v4063 ^ v4065;
  v4066[1] = v4079;
  struct StateT * v4068 = slot_70(v4055);
  return v4068;
}

struct StateT * slot_621(struct StateT * v21279) {
  int v21280 = v21279->timer;
  int v21288 = v21280 + 1;
  v21279->timer = v21288;
  int * v21282 = v21279->regs;
  int v21283 = v21282[8];
  int * v21284 = v21279->regs;
  int v21292 = v21283 << 9;
  v21284[8] = v21292;
  struct StateT * v21286 = slot_622(v21279);
  return v21286;
}

struct StateT * slot_644(struct StateT * v21711) {
  int v21712 = v21711->timer;
  int v21722 = v21712 + 1;
  v21711->timer = v21722;
  int * v21714 = v21711->regs;
  int v21715 = v21714[12];
  int * v21716 = v21711->regs;
  int v21717 = v21716[15];
  int * v21718 = v21711->regs;
  int v21728 = v21715 ^ v21717;
  v21718[12] = v21728;
  struct StateT * v21720 = slot_645(v21711);
  return v21720;
}

struct StateT * slot_565(struct StateT * v20171) {
  int v20172 = v20171->timer;
  int v20182 = v20172 + 1;
  v20171->timer = v20182;
  int * v20174 = v20171->regs;
  int v20175 = v20174[5];
  int * v20176 = v20171->regs;
  int v20177 = v20176[20];
  int * v20178 = v20171->regs;
  int v20189 = v20175 ^ v20177;
  v20178[18] = v20189;
  struct StateT * v20180 = slot_566(v20171);
  return v20180;
}

struct StateT * slot_188(struct StateT * v6405) {
  int v6406 = v6405->timer;
  int v6416 = v6406 + 1;
  v6405->timer = v6416;
  int * v6408 = v6405->regs;
  int v6409 = v6408[12];
  int * v6410 = v6405->regs;
  int v6411 = v6410[15];
  int * v6412 = v6405->regs;
  int v6422 = v6409 ^ v6411;
  v6412[12] = v6422;
  struct StateT * v6414 = slot_189(v6405);
  return v6414;
}

struct StateT * slot_495(struct StateT * v18765) {
  int v18766 = v18765->timer;
  int v18774 = v18766 + 1;
  v18765->timer = v18774;
  int * v18768 = v18765->regs;
  int v18769 = v18768[6];
  int * v18770 = v18765->regs;
  int v18779 = (int)((unsigned int)v18769 >> 14);
  v18770[9] = v18779;
  struct StateT * v18772 = slot_496(v18765);
  return v18772;
}

struct StateT * slot_186(struct StateT * v6365) {
  int v6366 = v6365->timer;
  int v6376 = v6366 + 1;
  v6365->timer = v6376;
  int * v6368 = v6365->regs;
  int v6369 = v6368[8];
  int * v6370 = v6365->regs;
  int v6371 = v6370[9];
  int * v6372 = v6365->regs;
  int v6382 = v6369 | v6371;
  v6372[8] = v6382;
  struct StateT * v6374 = slot_187(v6365);
  return v6374;
}

struct StateT * slot_102(struct StateT * v4720) {
  int v4721 = v4720->timer;
  int v4729 = v4721 + 1;
  v4720->timer = v4729;
  int * v4723 = v4720->regs;
  int v4724 = v4723[9];
  int * v4725 = v4720->regs;
  int v4733 = v4724 << 13;
  v4725[9] = v4733;
  struct StateT * v4727 = slot_103(v4720);
  return v4727;
}

struct StateT * slot_145(struct StateT * v5593) {
  int v5594 = v5593->timer;
  int v5602 = v5594 + 1;
  v5593->timer = v5602;
  int * v5596 = v5593->regs;
  int v5597 = v5596[17];
  int * v5598 = v5593->regs;
  int v5606 = v5597 << 7;
  v5598[17] = v5606;
  struct StateT * v5600 = slot_146(v5593);
  return v5600;
}

struct StateT * slot_110(struct StateT * v4886) {
  int v4887 = v4886->timer;
  int v4897 = v4887 + 1;
  v4886->timer = v4897;
  int * v4889 = v4886->regs;
  int v4890 = v4889[17];
  int * v4891 = v4886->regs;
  int v4892 = v4891[6];
  int * v4893 = v4886->regs;
  int v4904 = v4890 ^ v4892;
  v4893[8] = v4904;
  struct StateT * v4895 = slot_111(v4886);
  return v4895;
}

struct StateT * slot_208(struct StateT * v6781) {
  int v6782 = v6781->timer;
  int v6792 = v6782 + 1;
  v6781->timer = v6792;
  int * v6784 = v6781->regs;
  int v6785 = v6784[20];
  int * v6786 = v6781->regs;
  int v6787 = v6786[15];
  int * v6788 = v6781->regs;
  int v6799 = v6785 ^ v6787;
  v6788[11] = v6799;
  struct StateT * v6790 = slot_209(v6781);
  return v6790;
}

struct StateT * slot_301(struct StateT * v10638) {
  int v10639 = v10638->timer;
  int v10649 = v10639 + 1;
  v10638->timer = v10649;
  int * v10641 = v10638->regs;
  int v10642 = v10641[13];
  int * v10643 = v10638->regs;
  int v10644 = v10643[9];
  int * v10645 = v10638->regs;
  int v10655 = v10642 ^ v10644;
  v10645[13] = v10655;
  struct StateT * v10647 = slot_304(v10638);
  return v10647;
}

struct StateT * slot_502(struct StateT * v18891) {
  int v18892 = v18891->timer;
  int v18902 = v18892 + 1;
  v18891->timer = v18902;
  int * v18894 = v18891->regs;
  int v18895 = v18894[20];
  int * v18896 = v18891->regs;
  int v18897 = v18896[15];
  int * v18898 = v18891->regs;
  int v18909 = v18895 ^ v18897;
  v18898[11] = v18909;
  struct StateT * v18900 = slot_503(v18891);
  return v18900;
}

struct StateT * slot_506(struct StateT * v18968) {
  int v18969 = v18968->timer;
  int v18973 = v18969 + 1;
  v18968->timer = v18973;
  struct StateT * v18971 = slot_507(v18968);
  return v18971;
}

struct StateT * slot_413(struct StateT * v17220) {
  int v17221 = v17220->timer;
  int v17229 = v17221 + 1;
  v17220->timer = v17229;
  int * v17223 = v17220->regs;
  int v17224 = v17223[16];
  int * v17225 = v17220->regs;
  int v17233 = v17224 << 18;
  v17225[16] = v17233;
  struct StateT * v17227 = slot_414(v17220);
  return v17227;
}

struct StateT * slot_320(struct StateT * v11958) {
  int v11959 = v11958->timer;
  int v12013 = v11959 + 1;
  v11958->timer = v12013;
  int * v11961 = v11958->regs;
  int v11962 = v11961[10];
  int * v11963 = v11958->regs;
  int v11964 = v11963[5];
  int * v11965 = v11958->cache_keys;
  int v11966 = v11965[0];
  bool v12020 = v11966 == ((int)((unsigned int)(v11962 + 24) >> 2));
  int v12010;
  if (v12020) {
    int * v11967 = v11958->cache_vals;
    v11967[0] = v11964;
    v12010 = v11964;
  } else {
    int * v11970 = v11958->cache_keys;
    int v11971 = v11970[1];
    bool v12025 = v11971 == ((int)((unsigned int)(v11962 + 24) >> 2));
    int v12008;
    if (v12025) {
      int * v11972 = v11958->cache_keys;
      int * v11973 = v11958->cache_keys;
      int v11974 = v11973[0];
      v11972[1] = v11974;
      int * v11976 = v11958->cache_vals;
      int * v11977 = v11958->cache_vals;
      int v11978 = v11977[0];
      v11976[1] = v11978;
      int * v11980 = v11958->cache_keys;
      int v12033 = (int)((unsigned int)(v11962 + 24) >> 2);
      v11980[0] = v12033;
      int * v11982 = v11958->cache_vals;
      v11982[0] = v11964;
      int v11984 = v11958->timer;
      int v12036 = v11984 + 1;
      v11958->timer = v12036;
      v12008 = v11964;
    } else {
      int * v11987 = v11958->mem;
      int * v11988 = v11958->cache_keys;
      int v11989 = v11988[1];
      int * v11990 = v11958->cache_vals;
      int v11991 = v11990[1];
      v11987[v11989] = v11991;
      int * v11993 = v11958->cache_keys;
      int * v11994 = v11958->cache_keys;
      int v11995 = v11994[0];
      v11993[1] = v11995;
      int * v11997 = v11958->cache_vals;
      int * v11998 = v11958->cache_vals;
      int v11999 = v11998[0];
      v11997[1] = v11999;
      int * v12001 = v11958->cache_keys;
      int v12049 = (int)((unsigned int)(v11962 + 24) >> 2);
      v12001[0] = v12049;
      int * v12003 = v11958->cache_vals;
      v12003[0] = v11964;
      int v12005 = v11958->timer;
      int v12052 = v12005 + 100;
      v11958->timer = v12052;
      v12008 = v11964;
    }
    v12010 = v12008;
  }
  struct StateT * v12011 = slot_323(v11958);
  return v12011;
}

struct StateT * slot_281(struct StateT * v10027) {
  int v10028 = v10027->timer;
  int v10036 = v10028 + 1;
  v10027->timer = v10036;
  int * v10030 = v10027->regs;
  int v10031 = v10030[6];
  int * v10032 = v10027->regs;
  int v10040 = v10031 + 1134;
  v10032[6] = v10040;
  struct StateT * v10034 = slot_284(v10027);
  return v10034;
}

struct StateT * slot_533(struct StateT * v19532) {
  int v19533 = v19532->timer;
  int v19543 = v19533 + 1;
  v19532->timer = v19543;
  int * v19535 = v19532->regs;
  int v19536 = v19535[15];
  int * v19537 = v19532->regs;
  int v19538 = v19537[20];
  int * v19539 = v19532->regs;
  int v19549 = v19536 | v19538;
  v19539[15] = v19549;
  struct StateT * v19541 = slot_534(v19532);
  return v19541;
}

struct StateT * slot_203(struct StateT * v6688) {
  int v6689 = v6688->timer;
  int v6699 = v6689 + 1;
  v6688->timer = v6699;
  int * v6691 = v6688->regs;
  int v6692 = v6691[6];
  int * v6693 = v6688->regs;
  int v6694 = v6693[9];
  int * v6695 = v6688->regs;
  int v6705 = v6692 | v6694;
  v6695[6] = v6705;
  struct StateT * v6697 = slot_204(v6688);
  return v6697;
}

struct StateT * slot_190(struct StateT * v6445) {
  int v6446 = v6445->timer;
  int v6456 = v6446 + 1;
  v6445->timer = v6456;
  int * v6448 = v6445->regs;
  int v6449 = v6448[1];
  int * v6450 = v6445->regs;
  int v6451 = v6450[8];
  int * v6452 = v6445->regs;
  int v6462 = v6449 ^ v6451;
  v6452[1] = v6462;
  struct StateT * v6454 = slot_191(v6445);
  return v6454;
}

struct StateT * slot_157(struct StateT * v5830) {
  int v5831 = v5830->timer;
  int v5841 = v5831 + 1;
  v5830->timer = v5841;
  int * v5833 = v5830->regs;
  int v5834 = v5833[11];
  int * v5835 = v5830->regs;
  int v5836 = v5835[9];
  int * v5837 = v5830->regs;
  int v5847 = v5834 | v5836;
  v5837[11] = v5847;
  struct StateT * v5839 = slot_158(v5830);
  return v5839;
}

struct StateT * slot_447(struct StateT * v17865) {
  int v17866 = v17865->timer;
  int v17876 = v17866 + 1;
  v17865->timer = v17876;
  int * v17868 = v17865->regs;
  int v17869 = v17868[17];
  int * v17870 = v17865->regs;
  int v17871 = v17870[19];
  int * v17872 = v17865->regs;
  int v17883 = v17869 + v17871;
  v17872[6] = v17883;
  struct StateT * v17874 = slot_448(v17865);
  return v17874;
}

struct StateT * slot_587(struct StateT * v20632) {
  int v20633 = v20632->timer;
  int v20643 = v20633 + 1;
  v20632->timer = v20643;
  int * v20635 = v20632->regs;
  int v20636 = v20635[21];
  int * v20637 = v20632->regs;
  int v20638 = v20637[14];
  int * v20639 = v20632->regs;
  int v20650 = v20636 + v20638;
  v20639[15] = v20650;
  struct StateT * v20641 = slot_588(v20632);
  return v20641;
}

struct StateT * slot_559(struct StateT * v20042) {
  int v20043 = v20042->timer;
  int v20053 = v20043 + 1;
  v20042->timer = v20053;
  int * v20045 = v20042->regs;
  int v20046 = v20045[9];
  int * v20047 = v20042->regs;
  int v20048 = v20047[20];
  int * v20049 = v20042->regs;
  int v20059 = v20046 | v20048;
  v20049[20] = v20059;
  struct StateT * v20051 = slot_560(v20042);
  return v20051;
}

struct StateT * slot_243(struct StateT * v8549) {
  int v8550 = v8549->timer;
  int v8556 = v8550 + 1;
  v8549->timer = v8556;
  int * v8552 = v8549->regs;
  v8552[7] = 2036477952;
  struct StateT * v8554 = slot_245(v8549);
  return v8554;
}

struct StateT * slot_173(struct StateT * v6131) {
  int v6132 = v6131->timer;
  int v6142 = v6132 + 1;
  v6131->timer = v6142;
  int * v6134 = v6131->regs;
  int v6135 = v6134[26];
  int * v6136 = v6131->regs;
  int v6137 = v6136[17];
  int * v6138 = v6131->regs;
  int v6149 = v6135 + v6137;
  v6138[6] = v6149;
  struct StateT * v6140 = slot_174(v6131);
  return v6140;
}

struct StateT * slot_307(struct StateT * v11070) {
  int v11071 = v11070->timer;
  int v11081 = v11071 + 1;
  v11070->timer = v11081;
  int * v11073 = v11070->regs;
  int v11074 = v11073[14];
  int * v11075 = v11070->regs;
  int v11076 = v11075[8];
  int * v11077 = v11070->regs;
  int v11087 = v11074 ^ v11076;
  v11077[14] = v11087;
  struct StateT * v11079 = slot_310(v11070);
  return v11079;
}

struct StateT * slot_453(struct StateT * v17977) {
  int v17978 = v17977->timer;
  int v17986 = v17978 + 1;
  v17977->timer = v17986;
  int * v17980 = v17977->regs;
  int v17981 = v17980[15];
  int * v17982 = v17977->regs;
  int v17990 = v17981 << 9;
  v17982[15] = v17990;
  struct StateT * v17984 = slot_454(v17977);
  return v17984;
}

struct StateT * slot_54(struct StateT * v3754) {
  int * v3755 = v3754->saved_regs;
  int * v3756 = v3754->regs;
  int v3757 = v3756[8];
  v3755[8] = v3757;
  int v3759 = v3754->timer;
  int v3773 = v3759 + 1;
  v3754->timer = v3773;
  int * v3761 = v3754->regs;
  int v3762 = v3761[22];
  int * v3763 = v3754->regs;
  int v3764 = v3763[17];
  int * v3765 = v3754->regs;
  int v3779 = v3762 + v3764;
  v3765[8] = v3779;
  struct StateT * v3767 = slot_55(v3754);
  return v3767;
}

struct StateT * slot_26(struct StateT * v2459) {
  int v2460 = v2459->timer;
  int v2518 = v2460 + 1;
  v2459->timer = v2518;
  int * v2462 = v2459->regs;
  int v2463 = v2462[11];
  int * v2464 = v2459->cache_keys;
  int v2465 = v2464[0];
  bool v2523 = v2465 == ((int)((unsigned int)(v2463 + 12) >> 2));
  int v2513;
  if (v2523) {
    int * v2466 = v2459->cache_vals;
    int v2467 = v2466[0];
    v2513 = v2467;
  } else {
    int * v2469 = v2459->cache_keys;
    int v2470 = v2469[1];
    bool v2528 = v2470 == ((int)((unsigned int)(v2463 + 12) >> 2));
    int v2511;
    if (v2528) {
      int * v2471 = v2459->cache_vals;
      int v2472 = v2471[1];
      int * v2473 = v2459->cache_keys;
      int * v2474 = v2459->cache_keys;
      int v2475 = v2474[0];
      v2473[1] = v2475;
      int * v2477 = v2459->cache_vals;
      int * v2478 = v2459->cache_vals;
      int v2479 = v2478[0];
      v2477[1] = v2479;
      int * v2481 = v2459->cache_keys;
      int v2537 = (int)((unsigned int)(v2463 + 12) >> 2);
      v2481[0] = v2537;
      int * v2483 = v2459->cache_vals;
      v2483[0] = v2472;
      int v2485 = v2459->timer;
      int v2540 = v2485 + 1;
      v2459->timer = v2540;
      v2511 = v2472;
    } else {
      int * v2488 = v2459->mem;
      int v2542 = (int)((unsigned int)(v2463 + 12) >> 2);
      int v2489 = v2488[v2542];
      int * v2490 = v2459->mem;
      int * v2491 = v2459->cache_keys;
      int v2492 = v2491[1];
      int * v2493 = v2459->cache_vals;
      int v2494 = v2493[1];
      v2490[v2492] = v2494;
      int * v2496 = v2459->cache_keys;
      int * v2497 = v2459->cache_keys;
      int v2498 = v2497[0];
      v2496[1] = v2498;
      int * v2500 = v2459->cache_vals;
      int * v2501 = v2459->cache_vals;
      int v2502 = v2501[0];
      v2500[1] = v2502;
      int * v2504 = v2459->cache_keys;
      v2504[0] = v2542;
      int * v2506 = v2459->cache_vals;
      v2506[0] = v2489;
      int v2508 = v2459->timer;
      int v2557 = v2508 + 100;
      v2459->timer = v2557;
      v2511 = v2489;
    }
    v2513 = v2511;
  }
  int * v2514 = v2459->regs;
  v2514[15] = v2513;
  struct StateT * v2516 = slot_27(v2459);
  return v2516;
}

struct StateT * slot_370(struct StateT * v15699) {
  int v15700 = v15699->timer;
  int v15710 = v15700 + 1;
  v15699->timer = v15710;
  int * v15702 = v15699->regs;
  int v15703 = v15702[26];
  int * v15704 = v15699->regs;
  int v15705 = v15704[12];
  int * v15706 = v15699->regs;
  int v15717 = v15703 + v15705;
  v15706[15] = v15717;
  struct StateT * v15708 = slot_373(v15699);
  return v15708;
}

struct StateT * slot_652(struct StateT * v21872) {
  int v21873 = v21872->timer;
  int v21881 = v21873 + 1;
  v21872->timer = v21881;
  int * v21875 = v21872->regs;
  int v21876 = v21875[11];
  int * v21877 = v21872->regs;
  int v21885 = v21876 << 18;
  v21877[11] = v21885;
  struct StateT * v21879 = slot_653(v21872);
  return v21879;
}

struct StateT * slot_583(struct StateT * v20530) {
  int * v20531 = v20530->saved_regs;
  int * v20532 = v20530->regs;
  int v20533 = v20532[21];
  v20531[21] = v20533;
  int v20535 = v20530->timer;
  int v20549 = v20535 + 1;
  v20530->timer = v20549;
  int * v20537 = v20530->regs;
  int v20538 = v20537[21];
  int * v20539 = v20530->regs;
  int v20540 = v20539[15];
  int * v20541 = v20530->regs;
  int v20554 = v20538 ^ v20540;
  v20541[21] = v20554;
  struct StateT * v20543 = slot_584(v20530);
  return v20543;
}

struct StateT * slot_206(struct StateT * v6741) {
  int v6742 = v6741->timer;
  int v6752 = v6742 + 1;
  v6741->timer = v6752;
  int * v6744 = v6741->regs;
  int v6745 = v6744[8];
  int * v6746 = v6741->regs;
  int v6747 = v6746[9];
  int * v6748 = v6741->regs;
  int v6758 = v6745 | v6747;
  v6748[8] = v6758;
  struct StateT * v6750 = slot_207(v6741);
  return v6750;
}

struct StateT * slot_227(struct StateT * v7528) {
  int v7529 = v7528->timer;
  int v7587 = v7529 + 1;
  v7528->timer = v7587;
  int * v7531 = v7528->regs;
  int v7532 = v7531[2];
  int * v7533 = v7528->cache_keys;
  int v7534 = v7533[0];
  bool v7592 = v7534 == ((int)((unsigned int)(v7532 + 12) >> 2));
  int v7582;
  if (v7592) {
    int * v7535 = v7528->cache_vals;
    int v7536 = v7535[0];
    v7582 = v7536;
  } else {
    int * v7538 = v7528->cache_keys;
    int v7539 = v7538[1];
    bool v7597 = v7539 == ((int)((unsigned int)(v7532 + 12) >> 2));
    int v7580;
    if (v7597) {
      int * v7540 = v7528->cache_vals;
      int v7541 = v7540[1];
      int * v7542 = v7528->cache_keys;
      int * v7543 = v7528->cache_keys;
      int v7544 = v7543[0];
      v7542[1] = v7544;
      int * v7546 = v7528->cache_vals;
      int * v7547 = v7528->cache_vals;
      int v7548 = v7547[0];
      v7546[1] = v7548;
      int * v7550 = v7528->cache_keys;
      int v7606 = (int)((unsigned int)(v7532 + 12) >> 2);
      v7550[0] = v7606;
      int * v7552 = v7528->cache_vals;
      v7552[0] = v7541;
      int v7554 = v7528->timer;
      int v7609 = v7554 + 1;
      v7528->timer = v7609;
      v7580 = v7541;
    } else {
      int * v7557 = v7528->mem;
      int v7611 = (int)((unsigned int)(v7532 + 12) >> 2);
      int v7558 = v7557[v7611];
      int * v7559 = v7528->mem;
      int * v7560 = v7528->cache_keys;
      int v7561 = v7560[1];
      int * v7562 = v7528->cache_vals;
      int v7563 = v7562[1];
      v7559[v7561] = v7563;
      int * v7565 = v7528->cache_keys;
      int * v7566 = v7528->cache_keys;
      int v7567 = v7566[0];
      v7565[1] = v7567;
      int * v7569 = v7528->cache_vals;
      int * v7570 = v7528->cache_vals;
      int v7571 = v7570[0];
      v7569[1] = v7571;
      int * v7573 = v7528->cache_keys;
      v7573[0] = v7611;
      int * v7575 = v7528->cache_vals;
      v7575[0] = v7558;
      int v7577 = v7528->timer;
      int v7626 = v7577 + 100;
      v7528->timer = v7626;
      v7580 = v7558;
    }
    v7582 = v7580;
  }
  int * v7583 = v7528->regs;
  v7583[7] = v7582;
  struct StateT * v7585 = slot_229(v7528);
  return v7585;
}

struct StateT * slot_169(struct StateT * v6049) {
  int v6050 = v6049->timer;
  int v6060 = v6050 + 1;
  v6049->timer = v6060;
  int * v6052 = v6049->regs;
  int v6053 = v6052[26];
  int * v6054 = v6049->regs;
  int v6055 = v6054[6];
  int * v6056 = v6049->regs;
  int v6066 = v6053 ^ v6055;
  v6056[26] = v6066;
  struct StateT * v6058 = slot_170(v6049);
  return v6058;
}

struct StateT * slot_442(struct StateT * v17760) {
  int v17761 = v17760->timer;
  int v17771 = v17761 + 1;
  v17760->timer = v17771;
  int * v17763 = v17760->regs;
  int v17764 = v17763[18];
  int * v17765 = v17760->regs;
  int v17766 = v17765[11];
  int * v17767 = v17760->regs;
  int v17778 = v17764 ^ v17766;
  v17767[5] = v17778;
  struct StateT * v17769 = slot_443(v17760);
  return v17769;
}

struct StateT * slot_529(struct StateT * v19457) {
  int v19458 = v19457->timer;
  int v19468 = v19458 + 1;
  v19457->timer = v19468;
  int * v19460 = v19457->regs;
  int v19461 = v19460[1];
  int * v19462 = v19457->regs;
  int v19463 = v19462[19];
  int * v19464 = v19457->regs;
  int v19475 = v19461 + v19463;
  v19464[9] = v19475;
  struct StateT * v19466 = slot_530(v19457);
  return v19466;
}

struct StateT * slot_14(struct StateT * v1291) {
  int v1292 = v1291->timer;
  int v1298 = v1292 + 1;
  v1291->timer = v1298;
  int * v1294 = v1291->regs;
  v1294[30] = 0;
  struct StateT * v1296 = slot_15(v1291);
  return v1296;
}

struct StateT * slot_357(struct StateT * v14674) {
  int v14675 = v14674->timer;
  int v14733 = v14675 + 1;
  v14674->timer = v14733;
  int * v14677 = v14674->regs;
  int v14678 = v14677[2];
  int * v14679 = v14674->cache_keys;
  int v14680 = v14679[0];
  bool v14738 = v14680 == ((int)((unsigned int)(v14678 + 72) >> 2));
  int v14728;
  if (v14738) {
    int * v14681 = v14674->cache_vals;
    int v14682 = v14681[0];
    v14728 = v14682;
  } else {
    int * v14684 = v14674->cache_keys;
    int v14685 = v14684[1];
    bool v14743 = v14685 == ((int)((unsigned int)(v14678 + 72) >> 2));
    int v14726;
    if (v14743) {
      int * v14686 = v14674->cache_vals;
      int v14687 = v14686[1];
      int * v14688 = v14674->cache_keys;
      int * v14689 = v14674->cache_keys;
      int v14690 = v14689[0];
      v14688[1] = v14690;
      int * v14692 = v14674->cache_vals;
      int * v14693 = v14674->cache_vals;
      int v14694 = v14693[0];
      v14692[1] = v14694;
      int * v14696 = v14674->cache_keys;
      int v14752 = (int)((unsigned int)(v14678 + 72) >> 2);
      v14696[0] = v14752;
      int * v14698 = v14674->cache_vals;
      v14698[0] = v14687;
      int v14700 = v14674->timer;
      int v14755 = v14700 + 1;
      v14674->timer = v14755;
      v14726 = v14687;
    } else {
      int * v14703 = v14674->mem;
      int v14757 = (int)((unsigned int)(v14678 + 72) >> 2);
      int v14704 = v14703[v14757];
      int * v14705 = v14674->mem;
      int * v14706 = v14674->cache_keys;
      int v14707 = v14706[1];
      int * v14708 = v14674->cache_vals;
      int v14709 = v14708[1];
      v14705[v14707] = v14709;
      int * v14711 = v14674->cache_keys;
      int * v14712 = v14674->cache_keys;
      int v14713 = v14712[0];
      v14711[1] = v14713;
      int * v14715 = v14674->cache_vals;
      int * v14716 = v14674->cache_vals;
      int v14717 = v14716[0];
      v14715[1] = v14717;
      int * v14719 = v14674->cache_keys;
      v14719[0] = v14757;
      int * v14721 = v14674->cache_vals;
      v14721[0] = v14704;
      int v14723 = v14674->timer;
      int v14772 = v14723 + 100;
      v14674->timer = v14772;
      v14726 = v14704;
    }
    v14728 = v14726;
  }
  int * v14729 = v14674->regs;
  v14729[20] = v14728;
  struct StateT * v14731 = slot_360(v14674);
  return v14731;
}

struct StateT * slot_385(struct StateT * v16661) {
  int v16662 = v16661->timer;
  int v16670 = v16662 + 1;
  v16661->timer = v16670;
  int * v16664 = v16661->regs;
  int v16665 = v16664[15];
  int * v16666 = v16661->regs;
  int v16674 = v16665 << 13;
  v16666[15] = v16674;
  struct StateT * v16668 = slot_388(v16661);
  return v16668;
}

struct StateT * slot_602(struct StateT * v20915) {
  int v20916 = v20915->timer;
  int v20926 = v20916 + 1;
  v20915->timer = v20926;
  int * v20918 = v20915->regs;
  int v20919 = v20918[17];
  int * v20920 = v20915->regs;
  int v20921 = v20920[5];
  int * v20922 = v20915->regs;
  int v20933 = v20919 | v20921;
  v20922[6] = v20933;
  struct StateT * v20924 = slot_603(v20915);
  return v20924;
}

struct StateT * slot_444(struct StateT * v17802) {
  int v17803 = v17802->timer;
  int v17813 = v17803 + 1;
  v17802->timer = v17813;
  int * v17805 = v17802->regs;
  int v17806 = v17805[9];
  int * v17807 = v17802->regs;
  int v17808 = v17807[6];
  int * v17809 = v17802->regs;
  int v17820 = v17806 ^ v17808;
  v17809[16] = v17820;
  struct StateT * v17811 = slot_445(v17802);
  return v17811;
}

struct StateT * slot_261(struct StateT * v9423) {
  int v9424 = v9423->timer;
  int v9482 = v9424 + 1;
  v9423->timer = v9482;
  int * v9426 = v9423->regs;
  int v9427 = v9426[2];
  int * v9428 = v9423->cache_keys;
  int v9429 = v9428[0];
  bool v9487 = v9429 == ((int)((unsigned int)(v9427 + 40) >> 2));
  int v9477;
  if (v9487) {
    int * v9430 = v9423->cache_vals;
    int v9431 = v9430[0];
    v9477 = v9431;
  } else {
    int * v9433 = v9423->cache_keys;
    int v9434 = v9433[1];
    bool v9492 = v9434 == ((int)((unsigned int)(v9427 + 40) >> 2));
    int v9475;
    if (v9492) {
      int * v9435 = v9423->cache_vals;
      int v9436 = v9435[1];
      int * v9437 = v9423->cache_keys;
      int * v9438 = v9423->cache_keys;
      int v9439 = v9438[0];
      v9437[1] = v9439;
      int * v9441 = v9423->cache_vals;
      int * v9442 = v9423->cache_vals;
      int v9443 = v9442[0];
      v9441[1] = v9443;
      int * v9445 = v9423->cache_keys;
      int v9501 = (int)((unsigned int)(v9427 + 40) >> 2);
      v9445[0] = v9501;
      int * v9447 = v9423->cache_vals;
      v9447[0] = v9436;
      int v9449 = v9423->timer;
      int v9504 = v9449 + 1;
      v9423->timer = v9504;
      v9475 = v9436;
    } else {
      int * v9452 = v9423->mem;
      int v9506 = (int)((unsigned int)(v9427 + 40) >> 2);
      int v9453 = v9452[v9506];
      int * v9454 = v9423->mem;
      int * v9455 = v9423->cache_keys;
      int v9456 = v9455[1];
      int * v9457 = v9423->cache_vals;
      int v9458 = v9457[1];
      v9454[v9456] = v9458;
      int * v9460 = v9423->cache_keys;
      int * v9461 = v9423->cache_keys;
      int v9462 = v9461[0];
      v9460[1] = v9462;
      int * v9464 = v9423->cache_vals;
      int * v9465 = v9423->cache_vals;
      int v9466 = v9465[0];
      v9464[1] = v9466;
      int * v9468 = v9423->cache_keys;
      v9468[0] = v9506;
      int * v9470 = v9423->cache_vals;
      v9470[0] = v9453;
      int v9472 = v9423->timer;
      int v9521 = v9472 + 100;
      v9423->timer = v9521;
      v9475 = v9453;
    }
    v9477 = v9475;
  }
  int * v9478 = v9423->regs;
  v9478[30] = v9477;
  struct StateT * v9480 = slot_264(v9423);
  return v9480;
}

struct StateT * slot_603(struct StateT * v20936) {
  int v20937 = v20936->timer;
  int v20947 = v20937 + 1;
  v20936->timer = v20947;
  int * v20939 = v20936->regs;
  int v20940 = v20939[23];
  int * v20941 = v20936->regs;
  int v20942 = v20941[15];
  int * v20943 = v20936->regs;
  int v20953 = v20940 ^ v20942;
  v20943[23] = v20953;
  struct StateT * v20945 = slot_604(v20936);
  return v20945;
}

struct StateT * slot_287(struct StateT * v10135) {
  int v10136 = v10135->timer;
  int v10144 = v10136 + 1;
  v10135->timer = v10144;
  int * v10138 = v10135->regs;
  int v10139 = v10138[30];
  int * v10140 = v10135->regs;
  int v10148 = v10139 + 1396;
  v10140[30] = v10148;
  struct StateT * v10142 = slot_290(v10135);
  return v10142;
}

struct StateT * slot_639(struct StateT * v21618) {
  int v21619 = v21618->timer;
  int v21629 = v21619 + 1;
  v21618->timer = v21629;
  int * v21621 = v21618->regs;
  int v21622 = v21621[6];
  int * v21623 = v21618->regs;
  int v21624 = v21623[9];
  int * v21625 = v21618->regs;
  int v21635 = v21622 | v21624;
  v21625[6] = v21635;
  struct StateT * v21627 = slot_640(v21618);
  return v21627;
}

struct StateT * slot_343(struct StateT * v13655) {
  int v13656 = v13655->timer;
  int v13664 = v13656 + 1;
  v13655->timer = v13664;
  int * v13658 = v13655->regs;
  int v13659 = v13658[9];
  int * v13660 = v13655->regs;
  int v13668 = v13659 << 9;
  v13660[9] = v13668;
  struct StateT * v13662 = slot_346(v13655);
  return v13662;
}

struct StateT * slot_36(struct StateT * v2696) {
  int v2697 = v2696->timer;
  int v2751 = v2697 + 1;
  v2696->timer = v2751;
  int * v2699 = v2696->regs;
  int v2700 = v2699[2];
  int * v2701 = v2696->regs;
  int v2702 = v2701[26];
  int * v2703 = v2696->cache_keys;
  int v2704 = v2703[0];
  bool v2758 = v2704 == ((int)((unsigned int)(v2700 + 20) >> 2));
  int v2748;
  if (v2758) {
    int * v2705 = v2696->cache_vals;
    v2705[0] = v2702;
    v2748 = v2702;
  } else {
    int * v2708 = v2696->cache_keys;
    int v2709 = v2708[1];
    bool v2763 = v2709 == ((int)((unsigned int)(v2700 + 20) >> 2));
    int v2746;
    if (v2763) {
      int * v2710 = v2696->cache_keys;
      int * v2711 = v2696->cache_keys;
      int v2712 = v2711[0];
      v2710[1] = v2712;
      int * v2714 = v2696->cache_vals;
      int * v2715 = v2696->cache_vals;
      int v2716 = v2715[0];
      v2714[1] = v2716;
      int * v2718 = v2696->cache_keys;
      int v2771 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2718[0] = v2771;
      int * v2720 = v2696->cache_vals;
      v2720[0] = v2702;
      int v2722 = v2696->timer;
      int v2774 = v2722 + 1;
      v2696->timer = v2774;
      v2746 = v2702;
    } else {
      int * v2725 = v2696->mem;
      int * v2726 = v2696->cache_keys;
      int v2727 = v2726[1];
      int * v2728 = v2696->cache_vals;
      int v2729 = v2728[1];
      v2725[v2727] = v2729;
      int * v2731 = v2696->cache_keys;
      int * v2732 = v2696->cache_keys;
      int v2733 = v2732[0];
      v2731[1] = v2733;
      int * v2735 = v2696->cache_vals;
      int * v2736 = v2696->cache_vals;
      int v2737 = v2736[0];
      v2735[1] = v2737;
      int * v2739 = v2696->cache_keys;
      int v2787 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2739[0] = v2787;
      int * v2741 = v2696->cache_vals;
      v2741[0] = v2702;
      int v2743 = v2696->timer;
      int v2790 = v2743 + 100;
      v2696->timer = v2790;
      v2746 = v2702;
    }
    v2748 = v2746;
  }
  struct StateT * v2749 = slot_37(v2696);
  return v2749;
}

struct StateT * slot_57(struct StateT * v3822) {
  int v3823 = v3822->timer;
  int v3833 = v3823 + 1;
  v3822->timer = v3833;
  int * v3825 = v3822->regs;
  int v3826 = v3825[15];
  int * v3827 = v3822->regs;
  int v3828 = v3827[9];
  int * v3829 = v3822->regs;
  int v3839 = v3826 | v3828;
  v3829[15] = v3839;
  struct StateT * v3831 = slot_58(v3822);
  return v3831;
}

struct StateT * slot_426(struct StateT * v17464) {
  int v17465 = v17464->timer;
  int v17475 = v17465 + 1;
  v17464->timer = v17475;
  int * v17467 = v17464->regs;
  int v17468 = v17467[20];
  int * v17469 = v17464->regs;
  int v17470 = v17469[12];
  int * v17471 = v17464->regs;
  int v17482 = v17468 + v17470;
  v17471[11] = v17482;
  struct StateT * v17473 = slot_427(v17464);
  return v17473;
}

struct StateT * slot_536(struct StateT * v19585) {
  int v19586 = v19585->timer;
  int v19596 = v19586 + 1;
  v19585->timer = v19596;
  int * v19588 = v19585->regs;
  int v19589 = v19588[8];
  int * v19590 = v19585->regs;
  int v19591 = v19590[20];
  int * v19592 = v19585->regs;
  int v19602 = v19589 | v19591;
  v19592[8] = v19602;
  struct StateT * v19594 = slot_537(v19585);
  return v19594;
}

struct StateT * slot_470(struct StateT * v18300) {
  int v18301 = v18300->timer;
  int v18309 = v18301 + 1;
  v18300->timer = v18309;
  int * v18303 = v18300->regs;
  int v18304 = v18303[11];
  int * v18305 = v18300->regs;
  int v18313 = v18304 << 13;
  v18305[11] = v18313;
  struct StateT * v18307 = slot_471(v18300);
  return v18307;
}

struct StateT * slot_431(struct StateT * v17560) {
  int v17561 = v17560->timer;
  int v17571 = v17561 + 1;
  v17560->timer = v17571;
  int * v17563 = v17560->regs;
  int v17564 = v17563[15];
  int * v17565 = v17560->regs;
  int v17566 = v17565[5];
  int * v17567 = v17560->regs;
  int v17577 = v17564 | v17566;
  v17567[15] = v17577;
  struct StateT * v17569 = slot_432(v17560);
  return v17569;
}

struct StateT * slot_62(struct StateT * v3912) {
  int v3913 = v3912->timer;
  int v3921 = v3913 + 1;
  v3912->timer = v3921;
  int * v3915 = v3912->regs;
  int v3916 = v3915[18];
  int * v3917 = v3912->regs;
  int v3925 = v3916 << 7;
  v3917[18] = v3925;
  struct StateT * v3919 = slot_63(v3912);
  return v3919;
}

struct StateT * slot_308(struct StateT * v11090) {
  int v11091 = v11090->timer;
  int v11145 = v11091 + 1;
  v11090->timer = v11145;
  int * v11093 = v11090->regs;
  int v11094 = v11093[10];
  int * v11095 = v11090->regs;
  int v11096 = v11095[28];
  int * v11097 = v11090->cache_keys;
  int v11098 = v11097[0];
  bool v11152 = v11098 == ((int)((unsigned int)(v11094 + 8) >> 2));
  int v11142;
  if (v11152) {
    int * v11099 = v11090->cache_vals;
    v11099[0] = v11096;
    v11142 = v11096;
  } else {
    int * v11102 = v11090->cache_keys;
    int v11103 = v11102[1];
    bool v11157 = v11103 == ((int)((unsigned int)(v11094 + 8) >> 2));
    int v11140;
    if (v11157) {
      int * v11104 = v11090->cache_keys;
      int * v11105 = v11090->cache_keys;
      int v11106 = v11105[0];
      v11104[1] = v11106;
      int * v11108 = v11090->cache_vals;
      int * v11109 = v11090->cache_vals;
      int v11110 = v11109[0];
      v11108[1] = v11110;
      int * v11112 = v11090->cache_keys;
      int v11165 = (int)((unsigned int)(v11094 + 8) >> 2);
      v11112[0] = v11165;
      int * v11114 = v11090->cache_vals;
      v11114[0] = v11096;
      int v11116 = v11090->timer;
      int v11168 = v11116 + 1;
      v11090->timer = v11168;
      v11140 = v11096;
    } else {
      int * v11119 = v11090->mem;
      int * v11120 = v11090->cache_keys;
      int v11121 = v11120[1];
      int * v11122 = v11090->cache_vals;
      int v11123 = v11122[1];
      v11119[v11121] = v11123;
      int * v11125 = v11090->cache_keys;
      int * v11126 = v11090->cache_keys;
      int v11127 = v11126[0];
      v11125[1] = v11127;
      int * v11129 = v11090->cache_vals;
      int * v11130 = v11090->cache_vals;
      int v11131 = v11130[0];
      v11129[1] = v11131;
      int * v11133 = v11090->cache_keys;
      int v11181 = (int)((unsigned int)(v11094 + 8) >> 2);
      v11133[0] = v11181;
      int * v11135 = v11090->cache_vals;
      v11135[0] = v11096;
      int v11137 = v11090->timer;
      int v11184 = v11137 + 100;
      v11090->timer = v11184;
      v11140 = v11096;
    }
    v11142 = v11140;
  }
  struct StateT * v11143 = slot_311(v11090);
  return v11143;
}

struct StateT * slot_400(struct StateT * v16962) {
  int v16963 = v16962->timer;
  int v16973 = v16963 + 1;
  v16962->timer = v16973;
  int * v16965 = v16962->regs;
  int v16966 = v16965[18];
  int * v16967 = v16962->regs;
  int v16968 = v16967[9];
  int * v16969 = v16962->regs;
  int v16980 = v16966 | v16968;
  v16969[6] = v16980;
  struct StateT * v16971 = slot_401(v16962);
  return v16971;
}

struct StateT * slot_323(struct StateT * v12171) {
  int v12172 = v12171->timer;
  int v12226 = v12172 + 1;
  v12171->timer = v12226;
  int * v12174 = v12171->regs;
  int v12175 = v12174[10];
  int * v12176 = v12171->regs;
  int v12177 = v12176[25];
  int * v12178 = v12171->cache_keys;
  int v12179 = v12178[0];
  bool v12233 = v12179 == ((int)((unsigned int)(v12175 + 28) >> 2));
  int v12223;
  if (v12233) {
    int * v12180 = v12171->cache_vals;
    v12180[0] = v12177;
    v12223 = v12177;
  } else {
    int * v12183 = v12171->cache_keys;
    int v12184 = v12183[1];
    bool v12238 = v12184 == ((int)((unsigned int)(v12175 + 28) >> 2));
    int v12221;
    if (v12238) {
      int * v12185 = v12171->cache_keys;
      int * v12186 = v12171->cache_keys;
      int v12187 = v12186[0];
      v12185[1] = v12187;
      int * v12189 = v12171->cache_vals;
      int * v12190 = v12171->cache_vals;
      int v12191 = v12190[0];
      v12189[1] = v12191;
      int * v12193 = v12171->cache_keys;
      int v12246 = (int)((unsigned int)(v12175 + 28) >> 2);
      v12193[0] = v12246;
      int * v12195 = v12171->cache_vals;
      v12195[0] = v12177;
      int v12197 = v12171->timer;
      int v12249 = v12197 + 1;
      v12171->timer = v12249;
      v12221 = v12177;
    } else {
      int * v12200 = v12171->mem;
      int * v12201 = v12171->cache_keys;
      int v12202 = v12201[1];
      int * v12203 = v12171->cache_vals;
      int v12204 = v12203[1];
      v12200[v12202] = v12204;
      int * v12206 = v12171->cache_keys;
      int * v12207 = v12171->cache_keys;
      int v12208 = v12207[0];
      v12206[1] = v12208;
      int * v12210 = v12171->cache_vals;
      int * v12211 = v12171->cache_vals;
      int v12212 = v12211[0];
      v12210[1] = v12212;
      int * v12214 = v12171->cache_keys;
      int v12262 = (int)((unsigned int)(v12175 + 28) >> 2);
      v12214[0] = v12262;
      int * v12216 = v12171->cache_vals;
      v12216[0] = v12177;
      int v12218 = v12171->timer;
      int v12265 = v12218 + 100;
      v12171->timer = v12265;
      v12221 = v12177;
    }
    v12223 = v12221;
  }
  struct StateT * v12224 = slot_326(v12171);
  return v12224;
}

struct StateT * slot_628(struct StateT * v21416) {
  int v21417 = v21416->timer;
  int v21427 = v21417 + 1;
  v21416->timer = v21427;
  int * v21419 = v21416->regs;
  int v21420 = v21419[25];
  int * v21421 = v21416->regs;
  int v21422 = v21421[5];
  int * v21423 = v21416->regs;
  int v21434 = v21420 + v21422;
  v21423[15] = v21434;
  struct StateT * v21425 = slot_629(v21416);
  return v21425;
}

struct StateT * slot_521(struct StateT * v19271) {
  int v19272 = v19271->timer;
  int v19280 = v19272 + 1;
  v19271->timer = v19280;
  int * v19274 = v19271->regs;
  int v19275 = v19274[8];
  int * v19276 = v19271->regs;
  int v19284 = v19275 << 7;
  v19276[8] = v19284;
  struct StateT * v19278 = slot_522(v19271);
  return v19278;
}

struct StateT * slot_530(struct StateT * v19478) {
  int v19479 = v19478->timer;
  int v19489 = v19479 + 1;
  v19478->timer = v19489;
  int * v19481 = v19478->regs;
  int v19482 = v19481[14];
  int * v19483 = v19478->regs;
  int v19484 = v19483[22];
  int * v19485 = v19478->regs;
  int v19496 = v19482 + v19484;
  v19485[18] = v19496;
  struct StateT * v19487 = slot_531(v19478);
  return v19487;
}

struct StateT * slot_23(struct StateT * v2144) {
  int v2145 = v2144->timer;
  int v2203 = v2145 + 1;
  v2144->timer = v2203;
  int * v2147 = v2144->regs;
  int v2148 = v2147[11];
  int * v2149 = v2144->cache_keys;
  int v2150 = v2149[0];
  bool v2208 = v2150 == ((int)((unsigned int)v2148 >> 2));
  int v2198;
  if (v2208) {
    int * v2151 = v2144->cache_vals;
    int v2152 = v2151[0];
    v2198 = v2152;
  } else {
    int * v2154 = v2144->cache_keys;
    int v2155 = v2154[1];
    bool v2213 = v2155 == ((int)((unsigned int)v2148 >> 2));
    int v2196;
    if (v2213) {
      int * v2156 = v2144->cache_vals;
      int v2157 = v2156[1];
      int * v2158 = v2144->cache_keys;
      int * v2159 = v2144->cache_keys;
      int v2160 = v2159[0];
      v2158[1] = v2160;
      int * v2162 = v2144->cache_vals;
      int * v2163 = v2144->cache_vals;
      int v2164 = v2163[0];
      v2162[1] = v2164;
      int * v2166 = v2144->cache_keys;
      int v2222 = (int)((unsigned int)v2148 >> 2);
      v2166[0] = v2222;
      int * v2168 = v2144->cache_vals;
      v2168[0] = v2157;
      int v2170 = v2144->timer;
      int v2225 = v2170 + 1;
      v2144->timer = v2225;
      v2196 = v2157;
    } else {
      int * v2173 = v2144->mem;
      int v2227 = (int)((unsigned int)v2148 >> 2);
      int v2174 = v2173[v2227];
      int * v2175 = v2144->mem;
      int * v2176 = v2144->cache_keys;
      int v2177 = v2176[1];
      int * v2178 = v2144->cache_vals;
      int v2179 = v2178[1];
      v2175[v2177] = v2179;
      int * v2181 = v2144->cache_keys;
      int * v2182 = v2144->cache_keys;
      int v2183 = v2182[0];
      v2181[1] = v2183;
      int * v2185 = v2144->cache_vals;
      int * v2186 = v2144->cache_vals;
      int v2187 = v2186[0];
      v2185[1] = v2187;
      int * v2189 = v2144->cache_keys;
      v2189[0] = v2227;
      int * v2191 = v2144->cache_vals;
      v2191[0] = v2174;
      int v2193 = v2144->timer;
      int v2242 = v2193 + 100;
      v2144->timer = v2242;
      v2196 = v2174;
    }
    v2198 = v2196;
  }
  int * v2199 = v2144->regs;
  v2199[5] = v2198;
  struct StateT * v2201 = slot_24(v2144);
  return v2201;
}

struct StateT * slot_2(struct StateT * v115) {
  int v116 = v115->timer;
  int v170 = v116 + 1;
  v115->timer = v170;
  int * v118 = v115->regs;
  int v119 = v118[2];
  int * v120 = v115->regs;
  int v121 = v120[8];
  int * v122 = v115->cache_keys;
  int v123 = v122[0];
  bool v177 = v123 == ((int)((unsigned int)(v119 + 88) >> 2));
  int v167;
  if (v177) {
    int * v124 = v115->cache_vals;
    v124[0] = v121;
    v167 = v121;
  } else {
    int * v127 = v115->cache_keys;
    int v128 = v127[1];
    bool v182 = v128 == ((int)((unsigned int)(v119 + 88) >> 2));
    int v165;
    if (v182) {
      int * v129 = v115->cache_keys;
      int * v130 = v115->cache_keys;
      int v131 = v130[0];
      v129[1] = v131;
      int * v133 = v115->cache_vals;
      int * v134 = v115->cache_vals;
      int v135 = v134[0];
      v133[1] = v135;
      int * v137 = v115->cache_keys;
      int v190 = (int)((unsigned int)(v119 + 88) >> 2);
      v137[0] = v190;
      int * v139 = v115->cache_vals;
      v139[0] = v121;
      int v141 = v115->timer;
      int v193 = v141 + 1;
      v115->timer = v193;
      v165 = v121;
    } else {
      int * v144 = v115->mem;
      int * v145 = v115->cache_keys;
      int v146 = v145[1];
      int * v147 = v115->cache_vals;
      int v148 = v147[1];
      v144[v146] = v148;
      int * v150 = v115->cache_keys;
      int * v151 = v115->cache_keys;
      int v152 = v151[0];
      v150[1] = v152;
      int * v154 = v115->cache_vals;
      int * v155 = v115->cache_vals;
      int v156 = v155[0];
      v154[1] = v156;
      int * v158 = v115->cache_keys;
      int v206 = (int)((unsigned int)(v119 + 88) >> 2);
      v158[0] = v206;
      int * v160 = v115->cache_vals;
      v160[0] = v121;
      int v162 = v115->timer;
      int v209 = v162 + 100;
      v115->timer = v209;
      v165 = v121;
    }
    v167 = v165;
  }
  struct StateT * v168 = slot_3(v115);
  return v168;
}

struct StateT * slot_86(struct StateT * v4385) {
  int v4386 = v4385->timer;
  int v4396 = v4386 + 1;
  v4385->timer = v4396;
  int * v4388 = v4385->regs;
  int v4389 = v4388[18];
  int * v4390 = v4385->regs;
  int v4391 = v4390[20];
  int * v4392 = v4385->regs;
  int v4402 = v4389 | v4391;
  v4392[18] = v4402;
  struct StateT * v4394 = slot_87(v4385);
  return v4394;
}

struct StateT * slot_670(struct StateT * v22388) {
  int v22389 = v22388->timer;
  int v22395 = v22389 + 1;
  v22388->timer = v22395;
  int * v22391 = v22388->regs;
  v22391[15] = 1634762752;
  struct StateT * v22393 = slot_671(v22388);
  return v22393;
}

struct StateT * slot_538(struct StateT * v19622) {
  int v19623 = v19622->timer;
  int v19631 = v19623 + 1;
  v19622->timer = v19631;
  int * v19625 = v19622->regs;
  int v19626 = v19625[9];
  int * v19627 = v19622->regs;
  int v19635 = v19626 << 9;
  v19627[9] = v19635;
  struct StateT * v19629 = slot_539(v19622);
  return v19629;
}

struct StateT * slot_100(struct StateT * v4683) {
  int v4684 = v4683->timer;
  int v4694 = v4684 + 1;
  v4683->timer = v4694;
  int * v4686 = v4683->regs;
  int v4687 = v4686[8];
  int * v4688 = v4683->regs;
  int v4689 = v4688[20];
  int * v4690 = v4683->regs;
  int v4700 = v4687 | v4689;
  v4690[8] = v4700;
  struct StateT * v4692 = slot_101(v4683);
  return v4692;
}

struct StateT * slot_127(struct StateT * v5224) {
  int * v5225 = v5224->saved_regs;
  int * v5226 = v5224->regs;
  int v5227 = v5226[21];
  v5225[21] = v5227;
  int v5229 = v5224->timer;
  int v5243 = v5229 + 1;
  v5224->timer = v5243;
  int * v5231 = v5224->regs;
  int v5232 = v5231[21];
  int * v5233 = v5224->regs;
  int v5234 = v5233[15];
  int * v5235 = v5224->regs;
  int v5248 = v5232 ^ v5234;
  v5235[21] = v5248;
  struct StateT * v5237 = slot_128(v5224);
  return v5237;
}

struct StateT * slot_640(struct StateT * v21638) {
  int v21639 = v21638->timer;
  int v21647 = v21639 + 1;
  v21638->timer = v21647;
  int * v21641 = v21638->regs;
  int v21642 = v21641[8];
  int * v21643 = v21638->regs;
  int v21652 = (int)((unsigned int)v21642 >> 19);
  v21643[9] = v21652;
  struct StateT * v21645 = slot_641(v21638);
  return v21645;
}

struct StateT * slot_411(struct StateT * v17183) {
  int v17184 = v17183->timer;
  int v17194 = v17184 + 1;
  v17183->timer = v17194;
  int * v17186 = v17183->regs;
  int v17187 = v17186[15];
  int * v17188 = v17183->regs;
  int v17189 = v17188[6];
  int * v17190 = v17183->regs;
  int v17200 = v17187 | v17189;
  v17190[15] = v17200;
  struct StateT * v17192 = slot_412(v17183);
  return v17192;
}

struct StateT * slot_13(struct StateT * v1193) {
  int v1194 = v1193->timer;
  int v1248 = v1194 + 1;
  v1193->timer = v1248;
  int * v1196 = v1193->regs;
  int v1197 = v1196[2];
  int * v1198 = v1193->regs;
  int v1199 = v1198[27];
  int * v1200 = v1193->cache_keys;
  int v1201 = v1200[0];
  bool v1255 = v1201 == ((int)((unsigned int)(v1197 + 44) >> 2));
  int v1245;
  if (v1255) {
    int * v1202 = v1193->cache_vals;
    v1202[0] = v1199;
    v1245 = v1199;
  } else {
    int * v1205 = v1193->cache_keys;
    int v1206 = v1205[1];
    bool v1260 = v1206 == ((int)((unsigned int)(v1197 + 44) >> 2));
    int v1243;
    if (v1260) {
      int * v1207 = v1193->cache_keys;
      int * v1208 = v1193->cache_keys;
      int v1209 = v1208[0];
      v1207[1] = v1209;
      int * v1211 = v1193->cache_vals;
      int * v1212 = v1193->cache_vals;
      int v1213 = v1212[0];
      v1211[1] = v1213;
      int * v1215 = v1193->cache_keys;
      int v1268 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1215[0] = v1268;
      int * v1217 = v1193->cache_vals;
      v1217[0] = v1199;
      int v1219 = v1193->timer;
      int v1271 = v1219 + 1;
      v1193->timer = v1271;
      v1243 = v1199;
    } else {
      int * v1222 = v1193->mem;
      int * v1223 = v1193->cache_keys;
      int v1224 = v1223[1];
      int * v1225 = v1193->cache_vals;
      int v1226 = v1225[1];
      v1222[v1224] = v1226;
      int * v1228 = v1193->cache_keys;
      int * v1229 = v1193->cache_keys;
      int v1230 = v1229[0];
      v1228[1] = v1230;
      int * v1232 = v1193->cache_vals;
      int * v1233 = v1193->cache_vals;
      int v1234 = v1233[0];
      v1232[1] = v1234;
      int * v1236 = v1193->cache_keys;
      int v1284 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1236[0] = v1284;
      int * v1238 = v1193->cache_vals;
      v1238[0] = v1199;
      int v1240 = v1193->timer;
      int v1287 = v1240 + 100;
      v1193->timer = v1287;
      v1243 = v1199;
    }
    v1245 = v1243;
  }
  struct StateT * v1246 = slot_14(v1193);
  return v1246;
}

struct StateT * slot_449(struct StateT * v17907) {
  int v17908 = v17907->timer;
  int v17916 = v17908 + 1;
  v17907->timer = v17916;
  int * v17910 = v17907->regs;
  int v17911 = v17910[11];
  int * v17912 = v17907->regs;
  int v17921 = (int)((unsigned int)v17911 >> 23);
  v17912[9] = v17921;
  struct StateT * v17914 = slot_450(v17907);
  return v17914;
}

struct StateT * slot_569(struct StateT * v20262) {
  int * v20263 = v20262->saved_regs;
  int * v20264 = v20262->regs;
  int v20265 = v20264[17];
  v20263[17] = v20265;
  int v20267 = v20262->timer;
  int v20281 = v20267 + 1;
  v20262->timer = v20281;
  int * v20269 = v20262->regs;
  int v20270 = v20269[18];
  int * v20271 = v20262->regs;
  int v20272 = v20271[27];
  int * v20273 = v20262->regs;
  int v20287 = v20270 + v20272;
  v20273[17] = v20287;
  struct StateT * v20275 = slot_570(v20262);
  return v20275;
}

struct StateT * slot_460(struct StateT * v18099) {
  int v18100 = v18099->timer;
  int v18110 = v18100 + 1;
  v18099->timer = v18110;
  int * v18102 = v18099->regs;
  int v18103 = v18102[8];
  int * v18104 = v18099->regs;
  int v18105 = v18104[9];
  int * v18106 = v18099->regs;
  int v18116 = v18103 | v18105;
  v18106[8] = v18116;
  struct StateT * v18108 = slot_461(v18099);
  return v18108;
}

struct StateT * slot_109(struct StateT * v4865) {
  int v4866 = v4865->timer;
  int v4876 = v4866 + 1;
  v4865->timer = v4876;
  int * v4868 = v4865->regs;
  int v4869 = v4868[5];
  int * v4870 = v4865->regs;
  int v4871 = v4870[20];
  int * v4872 = v4865->regs;
  int v4883 = v4869 ^ v4871;
  v4872[18] = v4883;
  struct StateT * v4874 = slot_110(v4865);
  return v4874;
}

struct StateT * slot_474(struct StateT * v18369) {
  int v18370 = v18369->timer;
  int v18380 = v18370 + 1;
  v18369->timer = v18380;
  int * v18372 = v18369->regs;
  int v18373 = v18372[15];
  int * v18374 = v18369->regs;
  int v18375 = v18374[9];
  int * v18376 = v18369->regs;
  int v18386 = v18373 | v18375;
  v18376[15] = v18386;
  struct StateT * v18378 = slot_475(v18369);
  return v18378;
}

struct StateT * slot_174(struct StateT * v6152) {
  int v6153 = v6152->timer;
  int v6163 = v6153 + 1;
  v6152->timer = v6163;
  int * v6155 = v6152->regs;
  int v6156 = v6155[24];
  int * v6157 = v6152->regs;
  int v6158 = v6157[16];
  int * v6159 = v6152->regs;
  int v6170 = v6156 + v6158;
  v6159[8] = v6170;
  struct StateT * v6161 = slot_175(v6152);
  return v6161;
}

struct StateT * slot_629(struct StateT * v21437) {
  int v21438 = v21437->timer;
  int v21448 = v21438 + 1;
  v21437->timer = v21448;
  int * v21440 = v21437->regs;
  int v21441 = v21440[26];
  int * v21442 = v21437->regs;
  int v21443 = v21442[17];
  int * v21444 = v21437->regs;
  int v21455 = v21441 + v21443;
  v21444[6] = v21455;
  struct StateT * v21446 = slot_630(v21437);
  return v21446;
}

struct StateT * slot_42(struct StateT * v3283) {
  int v3284 = v3283->timer;
  int v3338 = v3284 + 1;
  v3283->timer = v3338;
  int * v3286 = v3283->regs;
  int v3287 = v3286[2];
  int * v3288 = v3283->regs;
  int v3289 = v3288[17];
  int * v3290 = v3283->cache_keys;
  int v3291 = v3290[0];
  bool v3345 = v3291 == ((int)((unsigned int)(v3287 + 28) >> 2));
  int v3335;
  if (v3345) {
    int * v3292 = v3283->cache_vals;
    v3292[0] = v3289;
    v3335 = v3289;
  } else {
    int * v3295 = v3283->cache_keys;
    int v3296 = v3295[1];
    bool v3350 = v3296 == ((int)((unsigned int)(v3287 + 28) >> 2));
    int v3333;
    if (v3350) {
      int * v3297 = v3283->cache_keys;
      int * v3298 = v3283->cache_keys;
      int v3299 = v3298[0];
      v3297[1] = v3299;
      int * v3301 = v3283->cache_vals;
      int * v3302 = v3283->cache_vals;
      int v3303 = v3302[0];
      v3301[1] = v3303;
      int * v3305 = v3283->cache_keys;
      int v3358 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3305[0] = v3358;
      int * v3307 = v3283->cache_vals;
      v3307[0] = v3289;
      int v3309 = v3283->timer;
      int v3361 = v3309 + 1;
      v3283->timer = v3361;
      v3333 = v3289;
    } else {
      int * v3312 = v3283->mem;
      int * v3313 = v3283->cache_keys;
      int v3314 = v3313[1];
      int * v3315 = v3283->cache_vals;
      int v3316 = v3315[1];
      v3312[v3314] = v3316;
      int * v3318 = v3283->cache_keys;
      int * v3319 = v3283->cache_keys;
      int v3320 = v3319[0];
      v3318[1] = v3320;
      int * v3322 = v3283->cache_vals;
      int * v3323 = v3283->cache_vals;
      int v3324 = v3323[0];
      v3322[1] = v3324;
      int * v3326 = v3283->cache_keys;
      int v3374 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3326[0] = v3374;
      int * v3328 = v3283->cache_vals;
      v3328[0] = v3289;
      int v3330 = v3283->timer;
      int v3377 = v3330 + 100;
      v3283->timer = v3377;
      v3333 = v3289;
    }
    v3335 = v3333;
  }
  struct StateT * v3336 = slot_43(v3283);
  return v3336;
}

struct StateT * slot_609(struct StateT * v21061) {
  int v21062 = v21061->timer;
  int v21072 = v21062 + 1;
  v21061->timer = v21072;
  int * v21064 = v21061->regs;
  int v21065 = v21064[17];
  int * v21066 = v21061->regs;
  int v21067 = v21066[19];
  int * v21068 = v21061->regs;
  int v21079 = v21065 + v21067;
  v21068[6] = v21079;
  struct StateT * v21070 = slot_610(v21061);
  return v21070;
}

struct StateT * slot_224(struct StateT * v7376) {
  int * v7377 = v7376->saved_regs;
  int * v7378 = v7376->regs;
  int v7379 = v7378[6];
  v7377[6] = v7379;
  int v7381 = v7376->timer;
  int v7443 = v7381 + 1;
  v7376->timer = v7443;
  int * v7383 = v7376->regs;
  int v7384 = v7383[2];
  int * v7385 = v7376->cache_keys;
  int v7386 = v7385[0];
  bool v7448 = v7386 == ((int)((unsigned int)(v7384 + 8) >> 2));
  int v7434;
  if (v7448) {
    int * v7387 = v7376->cache_vals;
    int v7388 = v7387[0];
    v7434 = v7388;
  } else {
    int * v7390 = v7376->cache_keys;
    int v7391 = v7390[1];
    bool v7453 = v7391 == ((int)((unsigned int)(v7384 + 8) >> 2));
    int v7432;
    if (v7453) {
      int * v7392 = v7376->cache_vals;
      int v7393 = v7392[1];
      int * v7394 = v7376->cache_keys;
      int * v7395 = v7376->cache_keys;
      int v7396 = v7395[0];
      v7394[1] = v7396;
      int * v7398 = v7376->cache_vals;
      int * v7399 = v7376->cache_vals;
      int v7400 = v7399[0];
      v7398[1] = v7400;
      int * v7402 = v7376->cache_keys;
      int v7462 = (int)((unsigned int)(v7384 + 8) >> 2);
      v7402[0] = v7462;
      int * v7404 = v7376->cache_vals;
      v7404[0] = v7393;
      int v7406 = v7376->timer;
      int v7465 = v7406 + 1;
      v7376->timer = v7465;
      v7432 = v7393;
    } else {
      int * v7409 = v7376->mem;
      int v7467 = (int)((unsigned int)(v7384 + 8) >> 2);
      int v7410 = v7409[v7467];
      int * v7411 = v7376->mem;
      int * v7412 = v7376->cache_keys;
      int v7413 = v7412[1];
      int * v7414 = v7376->cache_vals;
      int v7415 = v7414[1];
      v7411[v7413] = v7415;
      int * v7417 = v7376->cache_keys;
      int * v7418 = v7376->cache_keys;
      int v7419 = v7418[0];
      v7417[1] = v7419;
      int * v7421 = v7376->cache_vals;
      int * v7422 = v7376->cache_vals;
      int v7423 = v7422[0];
      v7421[1] = v7423;
      int * v7425 = v7376->cache_keys;
      v7425[0] = v7467;
      int * v7427 = v7376->cache_vals;
      v7427[0] = v7410;
      int v7429 = v7376->timer;
      int v7482 = v7429 + 100;
      v7376->timer = v7482;
      v7432 = v7410;
    }
    v7434 = v7432;
  }
  int * v7435 = v7376->regs;
  v7435[6] = v7434;
  struct StateT * v7437 = slot_226(v7376);
  return v7437;
}

struct StateT * slot_588(struct StateT * v20653) {
  int * v20654 = v20653->saved_regs;
  int * v20655 = v20653->regs;
  int v20656 = v20655[11];
  v20654[11] = v20656;
  int v20658 = v20653->timer;
  int v20672 = v20658 + 1;
  v20653->timer = v20672;
  int * v20660 = v20653->regs;
  int v20661 = v20660[20];
  int * v20662 = v20653->regs;
  int v20663 = v20662[12];
  int * v20664 = v20653->regs;
  int v20678 = v20661 + v20663;
  v20664[11] = v20678;
  struct StateT * v20666 = slot_589(v20653);
  return v20666;
}

struct StateT * slot_184(struct StateT * v6332) {
  int v6333 = v6332->timer;
  int v6341 = v6333 + 1;
  v6332->timer = v6341;
  int * v6335 = v6332->regs;
  int v6336 = v6335[8];
  int * v6337 = v6332->regs;
  int v6346 = (int)((unsigned int)v6336 >> 19);
  v6337[9] = v6346;
  struct StateT * v6339 = slot_185(v6332);
  return v6339;
}

struct StateT * slot_562(struct StateT * v20095) {
  int * v20096 = v20095->saved_regs;
  int * v20097 = v20095->regs;
  int v20098 = v20097[6];
  v20096[6] = v20098;
  int v20100 = v20095->timer;
  int v20114 = v20100 + 1;
  v20095->timer = v20114;
  int * v20102 = v20095->regs;
  int v20103 = v20102[18];
  int * v20104 = v20095->regs;
  int v20105 = v20104[9];
  int * v20106 = v20095->regs;
  int v20120 = v20103 | v20105;
  v20106[6] = v20120;
  struct StateT * v20108 = slot_563(v20095);
  return v20108;
}

struct StateT * slot_462(struct StateT * v18139) {
  int v18140 = v18139->timer;
  int v18150 = v18140 + 1;
  v18139->timer = v18150;
  int * v18142 = v18139->regs;
  int v18143 = v18142[25];
  int * v18144 = v18139->regs;
  int v18145 = v18144[15];
  int * v18146 = v18139->regs;
  int v18156 = v18143 ^ v18145;
  v18146[25] = v18156;
  struct StateT * v18148 = slot_463(v18139);
  return v18148;
}

struct StateT * slot_165(struct StateT * v5973) {
  int v5974 = v5973->timer;
  int v5982 = v5974 + 1;
  v5973->timer = v5982;
  int * v5976 = v5973->regs;
  int v5977 = v5976[8];
  int * v5978 = v5973->regs;
  int v5986 = v5977 << 9;
  v5978[8] = v5986;
  struct StateT * v5980 = slot_166(v5973);
  return v5980;
}

struct StateT * slot_557(struct StateT * v20009) {
  int v20010 = v20009->timer;
  int v20018 = v20010 + 1;
  v20009->timer = v20018;
  int * v20012 = v20009->regs;
  int v20013 = v20012[9];
  int * v20014 = v20009->regs;
  int v20023 = (int)((unsigned int)v20013 >> 19);
  v20014[20] = v20023;
  struct StateT * v20016 = slot_558(v20009);
  return v20016;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_584(struct StateT * v20557) {
  int v20558 = v20557->timer;
  int v20568 = v20558 + 1;
  v20557->timer = v20568;
  int * v20560 = v20557->regs;
  int v20561 = v20560[11];
  int * v20562 = v20557->regs;
  int v20563 = v20562[16];
  int * v20564 = v20557->regs;
  int v20575 = v20561 ^ v20563;
  v20564[20] = v20575;
  struct StateT * v20566 = slot_585(v20557);
  return v20566;
}

struct StateT * slot_507(struct StateT * v18976) {
  int * v18977 = v18976->saved_regs;
  int * v18978 = v18976->regs;
  int v18979 = v18978[15];
  v18977[15] = v18979;
  int v18981 = v18976->timer;
  int v18995 = v18981 + 1;
  v18976->timer = v18995;
  int * v18983 = v18976->regs;
  int v18984 = v18983[21];
  int * v18985 = v18976->regs;
  int v18986 = v18985[16];
  int * v18987 = v18976->regs;
  int v19001 = v18984 + v18986;
  v18987[15] = v19001;
  struct StateT * v18989 = slot_508(v18976);
  return v18989;
}

struct StateT * slot_477(struct StateT * v18422) {
  int v18423 = v18422->timer;
  int v18433 = v18423 + 1;
  v18422->timer = v18433;
  int * v18425 = v18422->regs;
  int v18426 = v18425[6];
  int * v18427 = v18422->regs;
  int v18428 = v18427[9];
  int * v18429 = v18422->regs;
  int v18439 = v18426 | v18428;
  v18429[6] = v18439;
  struct StateT * v18431 = slot_478(v18422);
  return v18431;
}

struct StateT * slot_278(struct StateT * v9978) {
  int v9979 = v9978->timer;
  int v9987 = v9979 + 1;
  v9978->timer = v9987;
  int * v9981 = v9978->regs;
  int v9982 = v9981[15];
  int * v9983 = v9978->regs;
  int v9991 = v9982 + -1947;
  v9983[15] = v9991;
  struct StateT * v9985 = slot_281(v9978);
  return v9985;
}

struct StateT * slot_352(struct StateT * v14323) {
  int v14324 = v14323->timer;
  int v14332 = v14324 + 1;
  v14323->timer = v14332;
  int * v14326 = v14323->regs;
  int v14327 = v14326[18];
  int * v14328 = v14323->regs;
  int v14336 = v14327 << 9;
  v14328[18] = v14336;
  struct StateT * v14330 = slot_355(v14323);
  return v14330;
}

struct StateT * slot_561(struct StateT * v20079) {
  int v20080 = v20079->timer;
  int v20088 = v20080 + 1;
  v20079->timer = v20088;
  int * v20082 = v20079->regs;
  int v20083 = v20082[18];
  int * v20084 = v20079->regs;
  int v20092 = v20083 << 13;
  v20084[18] = v20092;
  struct StateT * v20086 = slot_562(v20079);
  return v20086;
}

struct StateT * slot_577(struct StateT * v20424) {
  int v20425 = v20424->timer;
  int v20433 = v20425 + 1;
  v20424->timer = v20433;
  int * v20427 = v20424->regs;
  int v20428 = v20427[17];
  int * v20429 = v20424->regs;
  int v20438 = (int)((unsigned int)v20428 >> 14);
  v20429[6] = v20438;
  struct StateT * v20431 = slot_578(v20424);
  return v20431;
}

struct StateT * slot_249(struct StateT * v8839) {
  int v8840 = v8839->timer;
  int v8898 = v8840 + 1;
  v8839->timer = v8898;
  int * v8842 = v8839->regs;
  int v8843 = v8842[2];
  int * v8844 = v8839->cache_keys;
  int v8845 = v8844[0];
  bool v8903 = v8845 == ((int)((unsigned int)(v8843 + 32) >> 2));
  int v8893;
  if (v8903) {
    int * v8846 = v8839->cache_vals;
    int v8847 = v8846[0];
    v8893 = v8847;
  } else {
    int * v8849 = v8839->cache_keys;
    int v8850 = v8849[1];
    bool v8908 = v8850 == ((int)((unsigned int)(v8843 + 32) >> 2));
    int v8891;
    if (v8908) {
      int * v8851 = v8839->cache_vals;
      int v8852 = v8851[1];
      int * v8853 = v8839->cache_keys;
      int * v8854 = v8839->cache_keys;
      int v8855 = v8854[0];
      v8853[1] = v8855;
      int * v8857 = v8839->cache_vals;
      int * v8858 = v8839->cache_vals;
      int v8859 = v8858[0];
      v8857[1] = v8859;
      int * v8861 = v8839->cache_keys;
      int v8917 = (int)((unsigned int)(v8843 + 32) >> 2);
      v8861[0] = v8917;
      int * v8863 = v8839->cache_vals;
      v8863[0] = v8852;
      int v8865 = v8839->timer;
      int v8920 = v8865 + 1;
      v8839->timer = v8920;
      v8891 = v8852;
    } else {
      int * v8868 = v8839->mem;
      int v8922 = (int)((unsigned int)(v8843 + 32) >> 2);
      int v8869 = v8868[v8922];
      int * v8870 = v8839->mem;
      int * v8871 = v8839->cache_keys;
      int v8872 = v8871[1];
      int * v8873 = v8839->cache_vals;
      int v8874 = v8873[1];
      v8870[v8872] = v8874;
      int * v8876 = v8839->cache_keys;
      int * v8877 = v8839->cache_keys;
      int v8878 = v8877[0];
      v8876[1] = v8878;
      int * v8880 = v8839->cache_vals;
      int * v8881 = v8839->cache_vals;
      int v8882 = v8881[0];
      v8880[1] = v8882;
      int * v8884 = v8839->cache_keys;
      v8884[0] = v8922;
      int * v8886 = v8839->cache_vals;
      v8886[0] = v8869;
      int v8888 = v8839->timer;
      int v8937 = v8888 + 100;
      v8839->timer = v8937;
      v8891 = v8869;
    }
    v8893 = v8891;
  }
  int * v8894 = v8839->regs;
  v8894[30] = v8893;
  struct StateT * v8896 = slot_252(v8839);
  return v8896;
}

struct StateT * slot_11(struct StateT * v997) {
  int v998 = v997->timer;
  int v1052 = v998 + 1;
  v997->timer = v1052;
  int * v1000 = v997->regs;
  int v1001 = v1000[2];
  int * v1002 = v997->regs;
  int v1003 = v1002[25];
  int * v1004 = v997->cache_keys;
  int v1005 = v1004[0];
  bool v1059 = v1005 == ((int)((unsigned int)(v1001 + 52) >> 2));
  int v1049;
  if (v1059) {
    int * v1006 = v997->cache_vals;
    v1006[0] = v1003;
    v1049 = v1003;
  } else {
    int * v1009 = v997->cache_keys;
    int v1010 = v1009[1];
    bool v1064 = v1010 == ((int)((unsigned int)(v1001 + 52) >> 2));
    int v1047;
    if (v1064) {
      int * v1011 = v997->cache_keys;
      int * v1012 = v997->cache_keys;
      int v1013 = v1012[0];
      v1011[1] = v1013;
      int * v1015 = v997->cache_vals;
      int * v1016 = v997->cache_vals;
      int v1017 = v1016[0];
      v1015[1] = v1017;
      int * v1019 = v997->cache_keys;
      int v1072 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1019[0] = v1072;
      int * v1021 = v997->cache_vals;
      v1021[0] = v1003;
      int v1023 = v997->timer;
      int v1075 = v1023 + 1;
      v997->timer = v1075;
      v1047 = v1003;
    } else {
      int * v1026 = v997->mem;
      int * v1027 = v997->cache_keys;
      int v1028 = v1027[1];
      int * v1029 = v997->cache_vals;
      int v1030 = v1029[1];
      v1026[v1028] = v1030;
      int * v1032 = v997->cache_keys;
      int * v1033 = v997->cache_keys;
      int v1034 = v1033[0];
      v1032[1] = v1034;
      int * v1036 = v997->cache_vals;
      int * v1037 = v997->cache_vals;
      int v1038 = v1037[0];
      v1036[1] = v1038;
      int * v1040 = v997->cache_keys;
      int v1088 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1040[0] = v1088;
      int * v1042 = v997->cache_vals;
      v1042[0] = v1003;
      int v1044 = v997->timer;
      int v1091 = v1044 + 100;
      v997->timer = v1091;
      v1047 = v1003;
    }
    v1049 = v1047;
  }
  struct StateT * v1050 = slot_12(v997);
  return v1050;
}

struct StateT * slot_12(struct StateT * v1095) {
  int v1096 = v1095->timer;
  int v1150 = v1096 + 1;
  v1095->timer = v1150;
  int * v1098 = v1095->regs;
  int v1099 = v1098[2];
  int * v1100 = v1095->regs;
  int v1101 = v1100[26];
  int * v1102 = v1095->cache_keys;
  int v1103 = v1102[0];
  bool v1157 = v1103 == ((int)((unsigned int)(v1099 + 48) >> 2));
  int v1147;
  if (v1157) {
    int * v1104 = v1095->cache_vals;
    v1104[0] = v1101;
    v1147 = v1101;
  } else {
    int * v1107 = v1095->cache_keys;
    int v1108 = v1107[1];
    bool v1162 = v1108 == ((int)((unsigned int)(v1099 + 48) >> 2));
    int v1145;
    if (v1162) {
      int * v1109 = v1095->cache_keys;
      int * v1110 = v1095->cache_keys;
      int v1111 = v1110[0];
      v1109[1] = v1111;
      int * v1113 = v1095->cache_vals;
      int * v1114 = v1095->cache_vals;
      int v1115 = v1114[0];
      v1113[1] = v1115;
      int * v1117 = v1095->cache_keys;
      int v1170 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1117[0] = v1170;
      int * v1119 = v1095->cache_vals;
      v1119[0] = v1101;
      int v1121 = v1095->timer;
      int v1173 = v1121 + 1;
      v1095->timer = v1173;
      v1145 = v1101;
    } else {
      int * v1124 = v1095->mem;
      int * v1125 = v1095->cache_keys;
      int v1126 = v1125[1];
      int * v1127 = v1095->cache_vals;
      int v1128 = v1127[1];
      v1124[v1126] = v1128;
      int * v1130 = v1095->cache_keys;
      int * v1131 = v1095->cache_keys;
      int v1132 = v1131[0];
      v1130[1] = v1132;
      int * v1134 = v1095->cache_vals;
      int * v1135 = v1095->cache_vals;
      int v1136 = v1135[0];
      v1134[1] = v1136;
      int * v1138 = v1095->cache_keys;
      int v1186 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1138[0] = v1186;
      int * v1140 = v1095->cache_vals;
      v1140[0] = v1101;
      int v1142 = v1095->timer;
      int v1189 = v1142 + 100;
      v1095->timer = v1189;
      v1145 = v1101;
    }
    v1147 = v1145;
  }
  struct StateT * v1148 = slot_13(v1095);
  return v1148;
}

struct StateT * slot_228(struct StateT * v7633) {
  int v7634 = v7633->timer;
  int v7640 = v7634 + 1;
  v7633->timer = v7640;
  int * v7636 = v7633->regs;
  v7636[6] = 857759744;
  struct StateT * v7638 = slot_230(v7633);
  return v7638;
}

struct StateT * slot_268(struct StateT * v9719) {
  int v9720 = v9719->timer;
  int v9730 = v9720 + 1;
  v9719->timer = v9730;
  int * v9722 = v9719->regs;
  int v9723 = v9722[15];
  int * v9724 = v9719->regs;
  int v9725 = v9724[9];
  int * v9726 = v9719->regs;
  int v9736 = v9723 | v9725;
  v9726[15] = v9736;
  struct StateT * v9728 = slot_271(v9719);
  return v9728;
}

struct StateT * slot_199(struct StateT * v6619) {
  int v6620 = v6619->timer;
  int v6628 = v6620 + 1;
  v6619->timer = v6628;
  int * v6622 = v6619->regs;
  int v6623 = v6622[15];
  int * v6624 = v6619->regs;
  int v6632 = v6623 << 18;
  v6624[15] = v6632;
  struct StateT * v6626 = slot_200(v6619);
  return v6626;
}

struct StateT * slot_252(struct StateT * v9070) {
  int v9071 = v9070->timer;
  int v9081 = v9071 + 1;
  v9070->timer = v9081;
  int * v9073 = v9070->regs;
  int v9074 = v9073[16];
  int * v9075 = v9070->regs;
  int v9076 = v9075[30];
  int * v9077 = v9070->regs;
  int v9087 = v9074 + v9076;
  v9077[16] = v9087;
  struct StateT * v9079 = slot_255(v9070);
  return v9079;
}

struct StateT * slot_653(struct StateT * v21888) {
  int v21889 = v21888->timer;
  int v21899 = v21889 + 1;
  v21888->timer = v21899;
  int * v21891 = v21888->regs;
  int v21892 = v21891[11];
  int * v21893 = v21888->regs;
  int v21894 = v21893[9];
  int * v21895 = v21888->regs;
  int v21905 = v21892 | v21894;
  v21895[11] = v21905;
  struct StateT * v21897 = slot_654(v21888);
  return v21897;
}

struct StateT * slot_409(struct StateT * v17150) {
  int v17151 = v17150->timer;
  int v17159 = v17151 + 1;
  v17150->timer = v17159;
  int * v17153 = v17150->regs;
  int v17154 = v17153[15];
  int * v17155 = v17150->regs;
  int v17164 = (int)((unsigned int)v17154 >> 14);
  v17155[6] = v17164;
  struct StateT * v17157 = slot_410(v17150);
  return v17157;
}

struct StateT * slot_374(struct StateT * v15951) {
  int v15952 = v15951->timer;
  int v16010 = v15952 + 1;
  v15951->timer = v16010;
  int * v15954 = v15951->regs;
  int v15955 = v15954[2];
  int * v15956 = v15951->cache_keys;
  int v15957 = v15956[0];
  bool v16015 = v15957 == ((int)((unsigned int)(v15955 + 60) >> 2));
  int v16005;
  if (v16015) {
    int * v15958 = v15951->cache_vals;
    int v15959 = v15958[0];
    v16005 = v15959;
  } else {
    int * v15961 = v15951->cache_keys;
    int v15962 = v15961[1];
    bool v16020 = v15962 == ((int)((unsigned int)(v15955 + 60) >> 2));
    int v16003;
    if (v16020) {
      int * v15963 = v15951->cache_vals;
      int v15964 = v15963[1];
      int * v15965 = v15951->cache_keys;
      int * v15966 = v15951->cache_keys;
      int v15967 = v15966[0];
      v15965[1] = v15967;
      int * v15969 = v15951->cache_vals;
      int * v15970 = v15951->cache_vals;
      int v15971 = v15970[0];
      v15969[1] = v15971;
      int * v15973 = v15951->cache_keys;
      int v16029 = (int)((unsigned int)(v15955 + 60) >> 2);
      v15973[0] = v16029;
      int * v15975 = v15951->cache_vals;
      v15975[0] = v15964;
      int v15977 = v15951->timer;
      int v16032 = v15977 + 1;
      v15951->timer = v16032;
      v16003 = v15964;
    } else {
      int * v15980 = v15951->mem;
      int v16034 = (int)((unsigned int)(v15955 + 60) >> 2);
      int v15981 = v15980[v16034];
      int * v15982 = v15951->mem;
      int * v15983 = v15951->cache_keys;
      int v15984 = v15983[1];
      int * v15985 = v15951->cache_vals;
      int v15986 = v15985[1];
      v15982[v15984] = v15986;
      int * v15988 = v15951->cache_keys;
      int * v15989 = v15951->cache_keys;
      int v15990 = v15989[0];
      v15988[1] = v15990;
      int * v15992 = v15951->cache_vals;
      int * v15993 = v15951->cache_vals;
      int v15994 = v15993[0];
      v15992[1] = v15994;
      int * v15996 = v15951->cache_keys;
      v15996[0] = v16034;
      int * v15998 = v15951->cache_vals;
      v15998[0] = v15981;
      int v16000 = v15951->timer;
      int v16049 = v16000 + 100;
      v15951->timer = v16049;
      v16003 = v15981;
    }
    v16005 = v16003;
  }
  int * v16006 = v15951->regs;
  v16006[23] = v16005;
  struct StateT * v16008 = slot_377(v15951);
  return v16008;
}

struct StateT * slot_269(struct StateT * v9739) {
  int v9740 = v9739->timer;
  int v9798 = v9740 + 1;
  v9739->timer = v9798;
  int * v9742 = v9739->regs;
  int v9743 = v9742[2];
  int * v9744 = v9739->cache_keys;
  int v9745 = v9744[0];
  bool v9803 = v9745 == ((int)((unsigned int)(v9743 + 40) >> 2));
  int v9793;
  if (v9803) {
    int * v9746 = v9739->cache_vals;
    int v9747 = v9746[0];
    v9793 = v9747;
  } else {
    int * v9749 = v9739->cache_keys;
    int v9750 = v9749[1];
    bool v9808 = v9750 == ((int)((unsigned int)(v9743 + 40) >> 2));
    int v9791;
    if (v9808) {
      int * v9751 = v9739->cache_vals;
      int v9752 = v9751[1];
      int * v9753 = v9739->cache_keys;
      int * v9754 = v9739->cache_keys;
      int v9755 = v9754[0];
      v9753[1] = v9755;
      int * v9757 = v9739->cache_vals;
      int * v9758 = v9739->cache_vals;
      int v9759 = v9758[0];
      v9757[1] = v9759;
      int * v9761 = v9739->cache_keys;
      int v9817 = (int)((unsigned int)(v9743 + 40) >> 2);
      v9761[0] = v9817;
      int * v9763 = v9739->cache_vals;
      v9763[0] = v9752;
      int v9765 = v9739->timer;
      int v9820 = v9765 + 1;
      v9739->timer = v9820;
      v9791 = v9752;
    } else {
      int * v9768 = v9739->mem;
      int v9822 = (int)((unsigned int)(v9743 + 40) >> 2);
      int v9769 = v9768[v9822];
      int * v9770 = v9739->mem;
      int * v9771 = v9739->cache_keys;
      int v9772 = v9771[1];
      int * v9773 = v9739->cache_vals;
      int v9774 = v9773[1];
      v9770[v9772] = v9774;
      int * v9776 = v9739->cache_keys;
      int * v9777 = v9739->cache_keys;
      int v9778 = v9777[0];
      v9776[1] = v9778;
      int * v9780 = v9739->cache_vals;
      int * v9781 = v9739->cache_vals;
      int v9782 = v9781[0];
      v9780[1] = v9782;
      int * v9784 = v9739->cache_keys;
      v9784[0] = v9822;
      int * v9786 = v9739->cache_vals;
      v9786[0] = v9769;
      int v9788 = v9739->timer;
      int v9837 = v9788 + 100;
      v9739->timer = v9837;
      v9791 = v9769;
    }
    v9793 = v9791;
  }
  int * v9794 = v9739->regs;
  v9794[30] = v9793;
  struct StateT * v9796 = slot_272(v9739);
  return v9796;
}

struct StateT * slot_681(struct StateT * v22934) {
  int v22935 = v22934->timer;
  int v22993 = v22935 + 1;
  v22934->timer = v22993;
  int * v22937 = v22934->regs;
  int v22938 = v22937[2];
  int * v22939 = v22934->cache_keys;
  int v22940 = v22939[0];
  bool v22998 = v22940 == ((int)((unsigned int)(v22938 + 24) >> 2));
  int v22988;
  if (v22998) {
    int * v22941 = v22934->cache_vals;
    int v22942 = v22941[0];
    v22988 = v22942;
  } else {
    int * v22944 = v22934->cache_keys;
    int v22945 = v22944[1];
    bool v23003 = v22945 == ((int)((unsigned int)(v22938 + 24) >> 2));
    int v22986;
    if (v23003) {
      int * v22946 = v22934->cache_vals;
      int v22947 = v22946[1];
      int * v22948 = v22934->cache_keys;
      int * v22949 = v22934->cache_keys;
      int v22950 = v22949[0];
      v22948[1] = v22950;
      int * v22952 = v22934->cache_vals;
      int * v22953 = v22934->cache_vals;
      int v22954 = v22953[0];
      v22952[1] = v22954;
      int * v22956 = v22934->cache_keys;
      int v23012 = (int)((unsigned int)(v22938 + 24) >> 2);
      v22956[0] = v23012;
      int * v22958 = v22934->cache_vals;
      v22958[0] = v22947;
      int v22960 = v22934->timer;
      int v23015 = v22960 + 1;
      v22934->timer = v23015;
      v22986 = v22947;
    } else {
      int * v22963 = v22934->mem;
      int v23017 = (int)((unsigned int)(v22938 + 24) >> 2);
      int v22964 = v22963[v23017];
      int * v22965 = v22934->mem;
      int * v22966 = v22934->cache_keys;
      int v22967 = v22966[1];
      int * v22968 = v22934->cache_vals;
      int v22969 = v22968[1];
      v22965[v22967] = v22969;
      int * v22971 = v22934->cache_keys;
      int * v22972 = v22934->cache_keys;
      int v22973 = v22972[0];
      v22971[1] = v22973;
      int * v22975 = v22934->cache_vals;
      int * v22976 = v22934->cache_vals;
      int v22977 = v22976[0];
      v22975[1] = v22977;
      int * v22979 = v22934->cache_keys;
      v22979[0] = v23017;
      int * v22981 = v22934->cache_vals;
      v22981[0] = v22964;
      int v22983 = v22934->timer;
      int v23032 = v22983 + 100;
      v22934->timer = v23032;
      v22986 = v22964;
    }
    v22988 = v22986;
  }
  int * v22989 = v22934->regs;
  v22989[7] = v22988;
  struct StateT * v22991 = slot_682(v22934);
  return v22991;
}

struct StateT * slot_501(struct StateT * v18871) {
  int v18872 = v18871->timer;
  int v18882 = v18872 + 1;
  v18871->timer = v18882;
  int * v18874 = v18871->regs;
  int v18875 = v18874[21];
  int * v18876 = v18871->regs;
  int v18877 = v18876[11];
  int * v18878 = v18871->regs;
  int v18888 = v18875 ^ v18877;
  v18878[21] = v18888;
  struct StateT * v18880 = slot_502(v18871);
  return v18880;
}

struct StateT * slot_582(struct StateT * v20510) {
  int v20511 = v20510->timer;
  int v20521 = v20511 + 1;
  v20510->timer = v20521;
  int * v20513 = v20510->regs;
  int v20514 = v20513[5];
  int * v20515 = v20510->regs;
  int v20516 = v20515[6];
  int * v20517 = v20510->regs;
  int v20527 = v20514 | v20516;
  v20517[5] = v20527;
  struct StateT * v20519 = slot_583(v20510);
  return v20519;
}

struct StateT * slot_251(struct StateT * v8965) {
  int v8966 = v8965->timer;
  int v9024 = v8966 + 1;
  v8965->timer = v9024;
  int * v8968 = v8965->regs;
  int v8969 = v8968[2];
  int * v8970 = v8965->cache_keys;
  int v8971 = v8970[0];
  bool v9029 = v8971 == ((int)((unsigned int)(v8969 + 28) >> 2));
  int v9019;
  if (v9029) {
    int * v8972 = v8965->cache_vals;
    int v8973 = v8972[0];
    v9019 = v8973;
  } else {
    int * v8975 = v8965->cache_keys;
    int v8976 = v8975[1];
    bool v9034 = v8976 == ((int)((unsigned int)(v8969 + 28) >> 2));
    int v9017;
    if (v9034) {
      int * v8977 = v8965->cache_vals;
      int v8978 = v8977[1];
      int * v8979 = v8965->cache_keys;
      int * v8980 = v8965->cache_keys;
      int v8981 = v8980[0];
      v8979[1] = v8981;
      int * v8983 = v8965->cache_vals;
      int * v8984 = v8965->cache_vals;
      int v8985 = v8984[0];
      v8983[1] = v8985;
      int * v8987 = v8965->cache_keys;
      int v9043 = (int)((unsigned int)(v8969 + 28) >> 2);
      v8987[0] = v9043;
      int * v8989 = v8965->cache_vals;
      v8989[0] = v8978;
      int v8991 = v8965->timer;
      int v9046 = v8991 + 1;
      v8965->timer = v9046;
      v9017 = v8978;
    } else {
      int * v8994 = v8965->mem;
      int v9048 = (int)((unsigned int)(v8969 + 28) >> 2);
      int v8995 = v8994[v9048];
      int * v8996 = v8965->mem;
      int * v8997 = v8965->cache_keys;
      int v8998 = v8997[1];
      int * v8999 = v8965->cache_vals;
      int v9000 = v8999[1];
      v8996[v8998] = v9000;
      int * v9002 = v8965->cache_keys;
      int * v9003 = v8965->cache_keys;
      int v9004 = v9003[0];
      v9002[1] = v9004;
      int * v9006 = v8965->cache_vals;
      int * v9007 = v8965->cache_vals;
      int v9008 = v9007[0];
      v9006[1] = v9008;
      int * v9010 = v8965->cache_keys;
      v9010[0] = v9048;
      int * v9012 = v8965->cache_vals;
      v9012[0] = v8995;
      int v9014 = v8965->timer;
      int v9063 = v9014 + 100;
      v8965->timer = v9063;
      v9017 = v8995;
    }
    v9019 = v9017;
  }
  int * v9020 = v8965->regs;
  v9020[30] = v9019;
  struct StateT * v9022 = slot_254(v8965);
  return v9022;
}

struct StateT * slot_65(struct StateT * v3965) {
  int v3966 = v3965->timer;
  int v3974 = v3966 + 1;
  v3965->timer = v3974;
  int * v3968 = v3965->regs;
  int v3969 = v3968[8];
  int * v3970 = v3965->regs;
  int v3978 = v3969 << 7;
  v3970[8] = v3978;
  struct StateT * v3972 = slot_66(v3965);
  return v3972;
}

struct StateT * slot_10(struct StateT * v899) {
  int v900 = v899->timer;
  int v954 = v900 + 1;
  v899->timer = v954;
  int * v902 = v899->regs;
  int v903 = v902[2];
  int * v904 = v899->regs;
  int v905 = v904[24];
  int * v906 = v899->cache_keys;
  int v907 = v906[0];
  bool v961 = v907 == ((int)((unsigned int)(v903 + 56) >> 2));
  int v951;
  if (v961) {
    int * v908 = v899->cache_vals;
    v908[0] = v905;
    v951 = v905;
  } else {
    int * v911 = v899->cache_keys;
    int v912 = v911[1];
    bool v966 = v912 == ((int)((unsigned int)(v903 + 56) >> 2));
    int v949;
    if (v966) {
      int * v913 = v899->cache_keys;
      int * v914 = v899->cache_keys;
      int v915 = v914[0];
      v913[1] = v915;
      int * v917 = v899->cache_vals;
      int * v918 = v899->cache_vals;
      int v919 = v918[0];
      v917[1] = v919;
      int * v921 = v899->cache_keys;
      int v974 = (int)((unsigned int)(v903 + 56) >> 2);
      v921[0] = v974;
      int * v923 = v899->cache_vals;
      v923[0] = v905;
      int v925 = v899->timer;
      int v977 = v925 + 1;
      v899->timer = v977;
      v949 = v905;
    } else {
      int * v928 = v899->mem;
      int * v929 = v899->cache_keys;
      int v930 = v929[1];
      int * v931 = v899->cache_vals;
      int v932 = v931[1];
      v928[v930] = v932;
      int * v934 = v899->cache_keys;
      int * v935 = v899->cache_keys;
      int v936 = v935[0];
      v934[1] = v936;
      int * v938 = v899->cache_vals;
      int * v939 = v899->cache_vals;
      int v940 = v939[0];
      v938[1] = v940;
      int * v942 = v899->cache_keys;
      int v990 = (int)((unsigned int)(v903 + 56) >> 2);
      v942[0] = v990;
      int * v944 = v899->cache_vals;
      v944[0] = v905;
      int v946 = v899->timer;
      int v993 = v946 + 100;
      v899->timer = v993;
      v949 = v905;
    }
    v951 = v949;
  }
  struct StateT * v952 = slot_11(v899);
  return v952;
}

struct StateT * slot_322(struct StateT * v12154) {
  int v12155 = v12154->timer;
  int v12163 = v12155 + 1;
  v12154->timer = v12163;
  int * v12157 = v12154->regs;
  int v12158 = v12157[15];
  int * v12159 = v12154->regs;
  int v12168 = (int)((unsigned int)v12158 >> 23);
  v12159[20] = v12168;
  struct StateT * v12161 = slot_325(v12154);
  return v12161;
}

struct StateT * slot_593(struct StateT * v20756) {
  int v20757 = v20756->timer;
  int v20767 = v20757 + 1;
  v20756->timer = v20767;
  int * v20759 = v20756->regs;
  int v20760 = v20759[15];
  int * v20761 = v20756->regs;
  int v20762 = v20761[5];
  int * v20763 = v20756->regs;
  int v20773 = v20760 | v20762;
  v20763[15] = v20773;
  struct StateT * v20765 = slot_594(v20756);
  return v20765;
}

struct StateT * slot_277(struct StateT * v9958) {
  int v9959 = v9958->timer;
  int v9969 = v9959 + 1;
  v9958->timer = v9969;
  int * v9961 = v9958->regs;
  int v9962 = v9961[20];
  int * v9963 = v9958->regs;
  int v9964 = v9963[9];
  int * v9965 = v9958->regs;
  int v9975 = v9962 | v9964;
  v9965[9] = v9975;
  struct StateT * v9967 = slot_280(v9958);
  return v9967;
}

struct StateT * slot_353(struct StateT * v14339) {
  int v14340 = v14339->timer;
  int v14398 = v14340 + 1;
  v14339->timer = v14398;
  int * v14342 = v14339->regs;
  int v14343 = v14342[2];
  int * v14344 = v14339->cache_keys;
  int v14345 = v14344[0];
  bool v14403 = v14345 == ((int)((unsigned int)(v14343 + 88) >> 2));
  int v14393;
  if (v14403) {
    int * v14346 = v14339->cache_vals;
    int v14347 = v14346[0];
    v14393 = v14347;
  } else {
    int * v14349 = v14339->cache_keys;
    int v14350 = v14349[1];
    bool v14408 = v14350 == ((int)((unsigned int)(v14343 + 88) >> 2));
    int v14391;
    if (v14408) {
      int * v14351 = v14339->cache_vals;
      int v14352 = v14351[1];
      int * v14353 = v14339->cache_keys;
      int * v14354 = v14339->cache_keys;
      int v14355 = v14354[0];
      v14353[1] = v14355;
      int * v14357 = v14339->cache_vals;
      int * v14358 = v14339->cache_vals;
      int v14359 = v14358[0];
      v14357[1] = v14359;
      int * v14361 = v14339->cache_keys;
      int v14417 = (int)((unsigned int)(v14343 + 88) >> 2);
      v14361[0] = v14417;
      int * v14363 = v14339->cache_vals;
      v14363[0] = v14352;
      int v14365 = v14339->timer;
      int v14420 = v14365 + 1;
      v14339->timer = v14420;
      v14391 = v14352;
    } else {
      int * v14368 = v14339->mem;
      int v14422 = (int)((unsigned int)(v14343 + 88) >> 2);
      int v14369 = v14368[v14422];
      int * v14370 = v14339->mem;
      int * v14371 = v14339->cache_keys;
      int v14372 = v14371[1];
      int * v14373 = v14339->cache_vals;
      int v14374 = v14373[1];
      v14370[v14372] = v14374;
      int * v14376 = v14339->cache_keys;
      int * v14377 = v14339->cache_keys;
      int v14378 = v14377[0];
      v14376[1] = v14378;
      int * v14380 = v14339->cache_vals;
      int * v14381 = v14339->cache_vals;
      int v14382 = v14381[0];
      v14380[1] = v14382;
      int * v14384 = v14339->cache_keys;
      v14384[0] = v14422;
      int * v14386 = v14339->cache_vals;
      v14386[0] = v14369;
      int v14388 = v14339->timer;
      int v14437 = v14388 + 100;
      v14339->timer = v14437;
      v14391 = v14369;
    }
    v14393 = v14391;
  }
  int * v14394 = v14339->regs;
  v14394[8] = v14393;
  struct StateT * v14396 = slot_356(v14339);
  return v14396;
}

struct StateT * slot_612(struct StateT * v21120) {
  int v21121 = v21120->timer;
  int v21129 = v21121 + 1;
  v21120->timer = v21129;
  int * v21123 = v21120->regs;
  int v21124 = v21123[11];
  int * v21125 = v21120->regs;
  int v21133 = v21124 << 9;
  v21125[11] = v21133;
  struct StateT * v21127 = slot_613(v21120);
  return v21127;
}

struct StateT * slot_572(struct StateT * v20335) {
  int v20336 = v20335->timer;
  int v20344 = v20336 + 1;
  v20335->timer = v20344;
  int * v20338 = v20335->regs;
  int v20339 = v20338[15];
  int * v20340 = v20335->regs;
  int v20348 = v20339 << 18;
  v20340[15] = v20348;
  struct StateT * v20342 = slot_573(v20335);
  return v20342;
}

struct StateT * slot_397(struct StateT * v16909) {
  int v16910 = v16909->timer;
  int v16920 = v16910 + 1;
  v16909->timer = v16920;
  int * v16912 = v16909->regs;
  int v16913 = v16912[9];
  int * v16914 = v16909->regs;
  int v16915 = v16914[20];
  int * v16916 = v16909->regs;
  int v16926 = v16913 | v16915;
  v16916[20] = v16926;
  struct StateT * v16918 = slot_398(v16909);
  return v16918;
}

struct StateT * slot_435(struct StateT * v17633) {
  int v17634 = v17633->timer;
  int v17642 = v17634 + 1;
  v17633->timer = v17642;
  int * v17636 = v17633->regs;
  int v17637 = v17636[16];
  int * v17638 = v17633->regs;
  int v17647 = (int)((unsigned int)v17637 >> 25);
  v17638[5] = v17647;
  struct StateT * v17640 = slot_436(v17633);
  return v17640;
}

struct StateT * slot_476(struct StateT * v18406) {
  int v18407 = v18406->timer;
  int v18415 = v18407 + 1;
  v18406->timer = v18415;
  int * v18409 = v18406->regs;
  int v18410 = v18409[6];
  int * v18411 = v18406->regs;
  int v18419 = v18410 << 13;
  v18411[6] = v18419;
  struct StateT * v18413 = slot_477(v18406);
  return v18413;
}

struct StateT * slot_655(struct StateT * v21925) {
  int v21926 = v21925->timer;
  int v21934 = v21926 + 1;
  v21925->timer = v21934;
  int * v21928 = v21925->regs;
  int v21929 = v21928[15];
  int * v21930 = v21925->regs;
  int v21938 = v21929 << 18;
  v21930[15] = v21938;
  struct StateT * v21932 = slot_656(v21925);
  return v21932;
}

struct StateT * slot_136(struct StateT * v5434) {
  int v5435 = v5434->timer;
  int v5443 = v5435 + 1;
  v5434->timer = v5443;
  int * v5437 = v5434->regs;
  int v5438 = v5437[15];
  int * v5439 = v5434->regs;
  int v5447 = v5438 << 7;
  v5439[15] = v5447;
  struct StateT * v5441 = slot_137(v5434);
  return v5441;
}

struct StateT * slot_658(struct StateT * v21978) {
  int v21979 = v21978->timer;
  int v21987 = v21979 + 1;
  v21978->timer = v21987;
  int * v21981 = v21978->regs;
  int v21982 = v21981[6];
  int * v21983 = v21978->regs;
  int v21991 = v21982 << 18;
  v21983[6] = v21991;
  struct StateT * v21985 = slot_659(v21978);
  return v21985;
}

struct StateT * slot_379(struct StateT * v16392) {
  int v16393 = v16392->timer;
  int v16403 = v16393 + 1;
  v16392->timer = v16403;
  int * v16395 = v16392->regs;
  int v16396 = v16395[25];
  int * v16397 = v16392->regs;
  int v16398 = v16397[14];
  int * v16399 = v16392->regs;
  int v16410 = v16396 + v16398;
  v16399[18] = v16410;
  struct StateT * v16401 = slot_382(v16392);
  return v16401;
}

struct StateT * slot_475(struct StateT * v18389) {
  int v18390 = v18389->timer;
  int v18398 = v18390 + 1;
  v18389->timer = v18398;
  int * v18392 = v18389->regs;
  int v18393 = v18392[6];
  int * v18394 = v18389->regs;
  int v18403 = (int)((unsigned int)v18393 >> 19);
  v18394[9] = v18403;
  struct StateT * v18396 = slot_476(v18389);
  return v18396;
}

struct StateT * slot_310(struct StateT * v11286) {
  int v11287 = v11286->timer;
  int v11297 = v11287 + 1;
  v11286->timer = v11297;
  int * v11289 = v11286->regs;
  int v11290 = v11289[12];
  int * v11291 = v11286->regs;
  int v11292 = v11291[21];
  int * v11293 = v11286->regs;
  int v11304 = v11290 + v11292;
  v11293[15] = v11304;
  struct StateT * v11295 = slot_313(v11286);
  return v11295;
}

struct StateT * slot_445(struct StateT * v17823) {
  int v17824 = v17823->timer;
  int v17834 = v17824 + 1;
  v17823->timer = v17834;
  int * v17826 = v17823->regs;
  int v17827 = v17826[23];
  int * v17828 = v17823->regs;
  int v17829 = v17828[21];
  int * v17830 = v17823->regs;
  int v17841 = v17827 + v17829;
  v17830[11] = v17841;
  struct StateT * v17832 = slot_446(v17823);
  return v17832;
}

struct StateT * slot_295(struct StateT * v10362) {
  int v10363 = v10362->timer;
  int v10373 = v10363 + 1;
  v10362->timer = v10373;
  int * v10365 = v10362->regs;
  int v10366 = v10365[8];
  int * v10367 = v10362->regs;
  int v10368 = v10367[20];
  int * v10369 = v10362->regs;
  int v10379 = v10366 | v10368;
  v10369[8] = v10379;
  struct StateT * v10371 = slot_298(v10362);
  return v10371;
}

struct StateT * slot_315(struct StateT * v11622) {
  int v11623 = v11622->timer;
  int v11677 = v11623 + 1;
  v11622->timer = v11677;
  int * v11625 = v11622->regs;
  int v11626 = v11625[10];
  int * v11627 = v11622->regs;
  int v11628 = v11627[25];
  int * v11629 = v11622->cache_keys;
  int v11630 = v11629[0];
  bool v11684 = v11630 == ((int)((unsigned int)(v11626 + 28) >> 2));
  int v11674;
  if (v11684) {
    int * v11631 = v11622->cache_vals;
    v11631[0] = v11628;
    v11674 = v11628;
  } else {
    int * v11634 = v11622->cache_keys;
    int v11635 = v11634[1];
    bool v11689 = v11635 == ((int)((unsigned int)(v11626 + 28) >> 2));
    int v11672;
    if (v11689) {
      int * v11636 = v11622->cache_keys;
      int * v11637 = v11622->cache_keys;
      int v11638 = v11637[0];
      v11636[1] = v11638;
      int * v11640 = v11622->cache_vals;
      int * v11641 = v11622->cache_vals;
      int v11642 = v11641[0];
      v11640[1] = v11642;
      int * v11644 = v11622->cache_keys;
      int v11697 = (int)((unsigned int)(v11626 + 28) >> 2);
      v11644[0] = v11697;
      int * v11646 = v11622->cache_vals;
      v11646[0] = v11628;
      int v11648 = v11622->timer;
      int v11700 = v11648 + 1;
      v11622->timer = v11700;
      v11672 = v11628;
    } else {
      int * v11651 = v11622->mem;
      int * v11652 = v11622->cache_keys;
      int v11653 = v11652[1];
      int * v11654 = v11622->cache_vals;
      int v11655 = v11654[1];
      v11651[v11653] = v11655;
      int * v11657 = v11622->cache_keys;
      int * v11658 = v11622->cache_keys;
      int v11659 = v11658[0];
      v11657[1] = v11659;
      int * v11661 = v11622->cache_vals;
      int * v11662 = v11622->cache_vals;
      int v11663 = v11662[0];
      v11661[1] = v11663;
      int * v11665 = v11622->cache_keys;
      int v11713 = (int)((unsigned int)(v11626 + 28) >> 2);
      v11665[0] = v11713;
      int * v11667 = v11622->cache_vals;
      v11667[0] = v11628;
      int v11669 = v11622->timer;
      int v11716 = v11669 + 100;
      v11622->timer = v11716;
      v11672 = v11628;
    }
    v11674 = v11672;
  }
  struct StateT * v11675 = slot_318(v11622);
  return v11675;
}

struct StateT * slot_545(struct StateT * v19765) {
  int * v19766 = v19765->saved_regs;
  int * v19767 = v19765->regs;
  int v19768 = v19767[27];
  v19766[27] = v19768;
  int v19770 = v19765->timer;
  int v19784 = v19770 + 1;
  v19765->timer = v19784;
  int * v19772 = v19765->regs;
  int v19773 = v19772[27];
  int * v19774 = v19765->regs;
  int v19775 = v19774[9];
  int * v19776 = v19765->regs;
  int v19789 = v19773 ^ v19775;
  v19776[27] = v19789;
  struct StateT * v19778 = slot_546(v19765);
  return v19778;
}

struct StateT * slot_17(struct StateT * v1514) {
  int v1515 = v1514->timer;
  int v1573 = v1515 + 1;
  v1514->timer = v1573;
  int * v1517 = v1514->regs;
  int v1518 = v1517[12];
  int * v1519 = v1514->cache_keys;
  int v1520 = v1519[0];
  bool v1578 = v1520 == ((int)((unsigned int)(v1518 + 8) >> 2));
  int v1568;
  if (v1578) {
    int * v1521 = v1514->cache_vals;
    int v1522 = v1521[0];
    v1568 = v1522;
  } else {
    int * v1524 = v1514->cache_keys;
    int v1525 = v1524[1];
    bool v1583 = v1525 == ((int)((unsigned int)(v1518 + 8) >> 2));
    int v1566;
    if (v1583) {
      int * v1526 = v1514->cache_vals;
      int v1527 = v1526[1];
      int * v1528 = v1514->cache_keys;
      int * v1529 = v1514->cache_keys;
      int v1530 = v1529[0];
      v1528[1] = v1530;
      int * v1532 = v1514->cache_vals;
      int * v1533 = v1514->cache_vals;
      int v1534 = v1533[0];
      v1532[1] = v1534;
      int * v1536 = v1514->cache_keys;
      int v1592 = (int)((unsigned int)(v1518 + 8) >> 2);
      v1536[0] = v1592;
      int * v1538 = v1514->cache_vals;
      v1538[0] = v1527;
      int v1540 = v1514->timer;
      int v1595 = v1540 + 1;
      v1514->timer = v1595;
      v1566 = v1527;
    } else {
      int * v1543 = v1514->mem;
      int v1597 = (int)((unsigned int)(v1518 + 8) >> 2);
      int v1544 = v1543[v1597];
      int * v1545 = v1514->mem;
      int * v1546 = v1514->cache_keys;
      int v1547 = v1546[1];
      int * v1548 = v1514->cache_vals;
      int v1549 = v1548[1];
      v1545[v1547] = v1549;
      int * v1551 = v1514->cache_keys;
      int * v1552 = v1514->cache_keys;
      int v1553 = v1552[0];
      v1551[1] = v1553;
      int * v1555 = v1514->cache_vals;
      int * v1556 = v1514->cache_vals;
      int v1557 = v1556[0];
      v1555[1] = v1557;
      int * v1559 = v1514->cache_keys;
      v1559[0] = v1597;
      int * v1561 = v1514->cache_vals;
      v1561[0] = v1544;
      int v1563 = v1514->timer;
      int v1612 = v1563 + 100;
      v1514->timer = v1612;
      v1566 = v1544;
    }
    v1568 = v1566;
  }
  int * v1569 = v1514->regs;
  v1569[7] = v1568;
  struct StateT * v1571 = slot_18(v1514);
  return v1571;
}

struct StateT * slot_197(struct StateT * v6582) {
  int v6583 = v6582->timer;
  int v6593 = v6583 + 1;
  v6582->timer = v6593;
  int * v6585 = v6582->regs;
  int v6586 = v6585[11];
  int * v6587 = v6582->regs;
  int v6588 = v6587[9];
  int * v6589 = v6582->regs;
  int v6599 = v6586 | v6588;
  v6589[11] = v6599;
  struct StateT * v6591 = slot_198(v6582);
  return v6591;
}

struct StateT * slot_457(struct StateT * v18046) {
  int v18047 = v18046->timer;
  int v18057 = v18047 + 1;
  v18046->timer = v18057;
  int * v18049 = v18046->regs;
  int v18050 = v18049[6];
  int * v18051 = v18046->regs;
  int v18052 = v18051[9];
  int * v18053 = v18046->regs;
  int v18063 = v18050 | v18052;
  v18053[6] = v18063;
  struct StateT * v18055 = slot_458(v18046);
  return v18055;
}

struct StateT * slot_207(struct StateT * v6761) {
  int v6762 = v6761->timer;
  int v6772 = v6762 + 1;
  v6761->timer = v6772;
  int * v6764 = v6761->regs;
  int v6765 = v6764[21];
  int * v6766 = v6761->regs;
  int v6767 = v6766[11];
  int * v6768 = v6761->regs;
  int v6778 = v6765 ^ v6767;
  v6768[21] = v6778;
  struct StateT * v6770 = slot_208(v6761);
  return v6770;
}

struct StateT * slot_663(struct StateT * v22067) {
  int v22068 = v22067->timer;
  int v22078 = v22068 + 1;
  v22067->timer = v22078;
  int * v22070 = v22067->regs;
  int v22071 = v22070[21];
  int * v22072 = v22067->regs;
  int v22073 = v22072[11];
  int * v22074 = v22067->regs;
  int v22084 = v22071 ^ v22073;
  v22074[21] = v22084;
  struct StateT * v22076 = slot_664(v22067);
  return v22076;
}

struct StateT * slot_156(struct StateT * v5814) {
  int v5815 = v5814->timer;
  int v5823 = v5815 + 1;
  v5814->timer = v5823;
  int * v5817 = v5814->regs;
  int v5818 = v5817[11];
  int * v5819 = v5814->regs;
  int v5827 = v5818 << 9;
  v5819[11] = v5827;
  struct StateT * v5821 = slot_157(v5814);
  return v5821;
}

struct StateT * slot_68(struct StateT * v4028) {
  int * v4029 = v4028->saved_regs;
  int * v4030 = v4028->regs;
  int v4031 = v4030[13];
  v4029[13] = v4031;
  int v4033 = v4028->timer;
  int v4047 = v4033 + 1;
  v4028->timer = v4047;
  int * v4035 = v4028->regs;
  int v4036 = v4035[13];
  int * v4037 = v4028->regs;
  int v4038 = v4037[9];
  int * v4039 = v4028->regs;
  int v4052 = v4036 ^ v4038;
  v4039[13] = v4052;
  struct StateT * v4041 = slot_69(v4028);
  return v4041;
}

struct StateT * slot_493(struct StateT * v18729) {
  int v18730 = v18729->timer;
  int v18738 = v18730 + 1;
  v18729->timer = v18738;
  int * v18732 = v18729->regs;
  int v18733 = v18732[15];
  int * v18734 = v18729->regs;
  int v18742 = v18733 << 18;
  v18734[15] = v18742;
  struct StateT * v18736 = slot_494(v18729);
  return v18736;
}

struct StateT * slot_105(struct StateT * v4773) {
  int v4774 = v4773->timer;
  int v4782 = v4774 + 1;
  v4773->timer = v4782;
  int * v4776 = v4773->regs;
  int v4777 = v4776[18];
  int * v4778 = v4773->regs;
  int v4786 = v4777 << 13;
  v4778[18] = v4786;
  struct StateT * v4780 = slot_106(v4773);
  return v4780;
}

struct StateT * slot_430(struct StateT * v17544) {
  int v17545 = v17544->timer;
  int v17553 = v17545 + 1;
  v17544->timer = v17553;
  int * v17547 = v17544->regs;
  int v17548 = v17547[15];
  int * v17549 = v17544->regs;
  int v17557 = v17548 << 7;
  v17549[15] = v17557;
  struct StateT * v17551 = slot_431(v17544);
  return v17551;
}

struct StateT * slot_369(struct StateT * v15594) {
  int v15595 = v15594->timer;
  int v15653 = v15595 + 1;
  v15594->timer = v15653;
  int * v15597 = v15594->regs;
  int v15598 = v15597[2];
  int * v15599 = v15594->cache_keys;
  int v15600 = v15599[0];
  bool v15658 = v15600 == ((int)((unsigned int)(v15598 + 56) >> 2));
  int v15648;
  if (v15658) {
    int * v15601 = v15594->cache_vals;
    int v15602 = v15601[0];
    v15648 = v15602;
  } else {
    int * v15604 = v15594->cache_keys;
    int v15605 = v15604[1];
    bool v15663 = v15605 == ((int)((unsigned int)(v15598 + 56) >> 2));
    int v15646;
    if (v15663) {
      int * v15606 = v15594->cache_vals;
      int v15607 = v15606[1];
      int * v15608 = v15594->cache_keys;
      int * v15609 = v15594->cache_keys;
      int v15610 = v15609[0];
      v15608[1] = v15610;
      int * v15612 = v15594->cache_vals;
      int * v15613 = v15594->cache_vals;
      int v15614 = v15613[0];
      v15612[1] = v15614;
      int * v15616 = v15594->cache_keys;
      int v15672 = (int)((unsigned int)(v15598 + 56) >> 2);
      v15616[0] = v15672;
      int * v15618 = v15594->cache_vals;
      v15618[0] = v15607;
      int v15620 = v15594->timer;
      int v15675 = v15620 + 1;
      v15594->timer = v15675;
      v15646 = v15607;
    } else {
      int * v15623 = v15594->mem;
      int v15677 = (int)((unsigned int)(v15598 + 56) >> 2);
      int v15624 = v15623[v15677];
      int * v15625 = v15594->mem;
      int * v15626 = v15594->cache_keys;
      int v15627 = v15626[1];
      int * v15628 = v15594->cache_vals;
      int v15629 = v15628[1];
      v15625[v15627] = v15629;
      int * v15631 = v15594->cache_keys;
      int * v15632 = v15594->cache_keys;
      int v15633 = v15632[0];
      v15631[1] = v15633;
      int * v15635 = v15594->cache_vals;
      int * v15636 = v15594->cache_vals;
      int v15637 = v15636[0];
      v15635[1] = v15637;
      int * v15639 = v15594->cache_keys;
      v15639[0] = v15677;
      int * v15641 = v15594->cache_vals;
      v15641[0] = v15624;
      int v15643 = v15594->timer;
      int v15692 = v15643 + 100;
      v15594->timer = v15692;
      v15646 = v15624;
    }
    v15648 = v15646;
  }
  int * v15649 = v15594->regs;
  v15649[24] = v15648;
  struct StateT * v15651 = slot_372(v15594);
  return v15651;
}

struct StateT * slot_461(struct StateT * v18119) {
  int v18120 = v18119->timer;
  int v18130 = v18120 + 1;
  v18119->timer = v18130;
  int * v18122 = v18119->regs;
  int v18123 = v18122[27];
  int * v18124 = v18119->regs;
  int v18125 = v18124[11];
  int * v18126 = v18119->regs;
  int v18136 = v18123 ^ v18125;
  v18126[27] = v18136;
  struct StateT * v18128 = slot_462(v18119);
  return v18128;
}

struct StateT * slot_631(struct StateT * v21479) {
  int v21480 = v21479->timer;
  int v21488 = v21480 + 1;
  v21479->timer = v21488;
  int * v21482 = v21479->regs;
  int v21483 = v21482[11];
  int * v21484 = v21479->regs;
  int v21493 = (int)((unsigned int)v21483 >> 19);
  v21484[9] = v21493;
  struct StateT * v21486 = slot_632(v21479);
  return v21486;
}

struct StateT * slot_164(struct StateT * v5956) {
  int v5957 = v5956->timer;
  int v5965 = v5957 + 1;
  v5956->timer = v5965;
  int * v5959 = v5956->regs;
  int v5960 = v5959[8];
  int * v5961 = v5956->regs;
  int v5970 = (int)((unsigned int)v5960 >> 23);
  v5961[9] = v5970;
  struct StateT * v5963 = slot_165(v5956);
  return v5963;
}

struct StateT * slot_15(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1363 = v1305 + 1;
  v1304->timer = v1363;
  int * v1307 = v1304->regs;
  int v1308 = v1307[12];
  int * v1309 = v1304->cache_keys;
  int v1310 = v1309[0];
  bool v1368 = v1310 == ((int)((unsigned int)v1308 >> 2));
  int v1358;
  if (v1368) {
    int * v1311 = v1304->cache_vals;
    int v1312 = v1311[0];
    v1358 = v1312;
  } else {
    int * v1314 = v1304->cache_keys;
    int v1315 = v1314[1];
    bool v1373 = v1315 == ((int)((unsigned int)v1308 >> 2));
    int v1356;
    if (v1373) {
      int * v1316 = v1304->cache_vals;
      int v1317 = v1316[1];
      int * v1318 = v1304->cache_keys;
      int * v1319 = v1304->cache_keys;
      int v1320 = v1319[0];
      v1318[1] = v1320;
      int * v1322 = v1304->cache_vals;
      int * v1323 = v1304->cache_vals;
      int v1324 = v1323[0];
      v1322[1] = v1324;
      int * v1326 = v1304->cache_keys;
      int v1382 = (int)((unsigned int)v1308 >> 2);
      v1326[0] = v1382;
      int * v1328 = v1304->cache_vals;
      v1328[0] = v1317;
      int v1330 = v1304->timer;
      int v1385 = v1330 + 1;
      v1304->timer = v1385;
      v1356 = v1317;
    } else {
      int * v1333 = v1304->mem;
      int v1387 = (int)((unsigned int)v1308 >> 2);
      int v1334 = v1333[v1387];
      int * v1335 = v1304->mem;
      int * v1336 = v1304->cache_keys;
      int v1337 = v1336[1];
      int * v1338 = v1304->cache_vals;
      int v1339 = v1338[1];
      v1335[v1337] = v1339;
      int * v1341 = v1304->cache_keys;
      int * v1342 = v1304->cache_keys;
      int v1343 = v1342[0];
      v1341[1] = v1343;
      int * v1345 = v1304->cache_vals;
      int * v1346 = v1304->cache_vals;
      int v1347 = v1346[0];
      v1345[1] = v1347;
      int * v1349 = v1304->cache_keys;
      v1349[0] = v1387;
      int * v1351 = v1304->cache_vals;
      v1351[0] = v1334;
      int v1353 = v1304->timer;
      int v1402 = v1353 + 100;
      v1304->timer = v1402;
      v1356 = v1334;
    }
    v1358 = v1356;
  }
  int * v1359 = v1304->regs;
  v1359[29] = v1358;
  struct StateT * v1361 = slot_16(v1304);
  return v1361;
}

struct StateT * slot_480(struct StateT * v18475) {
  int v18476 = v18475->timer;
  int v18486 = v18476 + 1;
  v18475->timer = v18486;
  int * v18478 = v18475->regs;
  int v18479 = v18478[8];
  int * v18480 = v18475->regs;
  int v18481 = v18480[9];
  int * v18482 = v18475->regs;
  int v18492 = v18479 | v18481;
  v18482[8] = v18492;
  struct StateT * v18484 = slot_481(v18475);
  return v18484;
}

struct StateT * slot_133(struct StateT * v5375) {
  int v5376 = v5375->timer;
  int v5386 = v5376 + 1;
  v5375->timer = v5386;
  int * v5378 = v5375->regs;
  int v5379 = v5378[19];
  int * v5380 = v5375->regs;
  int v5381 = v5380[13];
  int * v5382 = v5375->regs;
  int v5393 = v5379 + v5381;
  v5382[16] = v5393;
  struct StateT * v5384 = slot_134(v5375);
  return v5384;
}

struct StateT * slot_56(struct StateT * v3806) {
  int v3807 = v3806->timer;
  int v3815 = v3807 + 1;
  v3806->timer = v3815;
  int * v3809 = v3806->regs;
  int v3810 = v3809[15];
  int * v3811 = v3806->regs;
  int v3819 = v3810 << 7;
  v3811[15] = v3819;
  struct StateT * v3813 = slot_57(v3806);
  return v3813;
}

struct StateT * slot_244(struct StateT * v8562) {
  int * v8563 = v8562->saved_regs;
  int * v8564 = v8562->regs;
  int v8565 = v8564[13];
  v8563[13] = v8565;
  int v8567 = v8562->timer;
  int v8581 = v8567 + 1;
  v8562->timer = v8581;
  int * v8569 = v8562->regs;
  int v8570 = v8569[13];
  int * v8571 = v8562->regs;
  int v8572 = v8571[7];
  int * v8573 = v8562->regs;
  int v8586 = v8570 + v8572;
  v8573[13] = v8586;
  struct StateT * v8575 = slot_246(v8562);
  return v8575;
}

struct StateT * slot_222(struct StateT * v7329) {
  int * v7330 = v7329->saved_regs;
  int * v7331 = v7329->regs;
  int v7332 = v7331[14];
  v7330[14] = v7332;
  int v7334 = v7329->timer;
  int v7348 = v7334 + 1;
  v7329->timer = v7348;
  int * v7336 = v7329->regs;
  int v7337 = v7336[14];
  int * v7338 = v7329->regs;
  int v7339 = v7338[7];
  int * v7340 = v7329->regs;
  int v7353 = v7337 + v7339;
  v7340[14] = v7353;
  struct StateT * v7342 = slot_224(v7329);
  return v7342;
}

struct StateT * slot_171(struct StateT * v6089) {
  int v6090 = v6089->timer;
  int v6100 = v6090 + 1;
  v6089->timer = v6100;
  int * v6092 = v6089->regs;
  int v6093 = v6092[27];
  int * v6094 = v6089->regs;
  int v6095 = v6094[23];
  int * v6096 = v6089->regs;
  int v6107 = v6093 + v6095;
  v6096[11] = v6107;
  struct StateT * v6098 = slot_172(v6089);
  return v6098;
}

struct StateT * slot_162(struct StateT * v5920) {
  int v5921 = v5920->timer;
  int v5929 = v5921 + 1;
  v5920->timer = v5929;
  int * v5923 = v5920->regs;
  int v5924 = v5923[6];
  int * v5925 = v5920->regs;
  int v5933 = v5924 << 9;
  v5925[6] = v5933;
  struct StateT * v5927 = slot_163(v5920);
  return v5927;
}

struct StateT * slot_634(struct StateT * v21532) {
  int v21533 = v21532->timer;
  int v21541 = v21533 + 1;
  v21532->timer = v21541;
  int * v21535 = v21532->regs;
  int v21536 = v21535[15];
  int * v21537 = v21532->regs;
  int v21546 = (int)((unsigned int)v21536 >> 19);
  v21537[9] = v21546;
  struct StateT * v21539 = slot_635(v21532);
  return v21539;
}

struct StateT * slot_564(struct StateT * v20144) {
  int * v20145 = v20144->saved_regs;
  int * v20146 = v20144->regs;
  int v20147 = v20146[23];
  v20145[23] = v20147;
  int v20149 = v20144->timer;
  int v20163 = v20149 + 1;
  v20144->timer = v20163;
  int * v20151 = v20144->regs;
  int v20152 = v20151[23];
  int * v20153 = v20144->regs;
  int v20154 = v20153[8];
  int * v20155 = v20144->regs;
  int v20168 = v20152 ^ v20154;
  v20155[23] = v20168;
  struct StateT * v20157 = slot_565(v20144);
  return v20157;
}

struct StateT * slot_630(struct StateT * v21458) {
  int v21459 = v21458->timer;
  int v21469 = v21459 + 1;
  v21458->timer = v21469;
  int * v21461 = v21458->regs;
  int v21462 = v21461[24];
  int * v21463 = v21458->regs;
  int v21464 = v21463[16];
  int * v21465 = v21458->regs;
  int v21476 = v21462 + v21464;
  v21465[8] = v21476;
  struct StateT * v21467 = slot_631(v21458);
  return v21467;
}

struct StateT * slot_377(struct StateT * v16182) {
  int v16183 = v16182->timer;
  int v16241 = v16183 + 1;
  v16182->timer = v16241;
  int * v16185 = v16182->regs;
  int v16186 = v16185[2];
  int * v16187 = v16182->cache_keys;
  int v16188 = v16187[0];
  bool v16246 = v16188 == ((int)((unsigned int)(v16186 + 56) >> 2));
  int v16236;
  if (v16246) {
    int * v16189 = v16182->cache_vals;
    int v16190 = v16189[0];
    v16236 = v16190;
  } else {
    int * v16192 = v16182->cache_keys;
    int v16193 = v16192[1];
    bool v16251 = v16193 == ((int)((unsigned int)(v16186 + 56) >> 2));
    int v16234;
    if (v16251) {
      int * v16194 = v16182->cache_vals;
      int v16195 = v16194[1];
      int * v16196 = v16182->cache_keys;
      int * v16197 = v16182->cache_keys;
      int v16198 = v16197[0];
      v16196[1] = v16198;
      int * v16200 = v16182->cache_vals;
      int * v16201 = v16182->cache_vals;
      int v16202 = v16201[0];
      v16200[1] = v16202;
      int * v16204 = v16182->cache_keys;
      int v16260 = (int)((unsigned int)(v16186 + 56) >> 2);
      v16204[0] = v16260;
      int * v16206 = v16182->cache_vals;
      v16206[0] = v16195;
      int v16208 = v16182->timer;
      int v16263 = v16208 + 1;
      v16182->timer = v16263;
      v16234 = v16195;
    } else {
      int * v16211 = v16182->mem;
      int v16265 = (int)((unsigned int)(v16186 + 56) >> 2);
      int v16212 = v16211[v16265];
      int * v16213 = v16182->mem;
      int * v16214 = v16182->cache_keys;
      int v16215 = v16214[1];
      int * v16216 = v16182->cache_vals;
      int v16217 = v16216[1];
      v16213[v16215] = v16217;
      int * v16219 = v16182->cache_keys;
      int * v16220 = v16182->cache_keys;
      int v16221 = v16220[0];
      v16219[1] = v16221;
      int * v16223 = v16182->cache_vals;
      int * v16224 = v16182->cache_vals;
      int v16225 = v16224[0];
      v16223[1] = v16225;
      int * v16227 = v16182->cache_keys;
      v16227[0] = v16265;
      int * v16229 = v16182->cache_vals;
      v16229[0] = v16212;
      int v16231 = v16182->timer;
      int v16280 = v16231 + 100;
      v16182->timer = v16280;
      v16234 = v16212;
    }
    v16236 = v16234;
  }
  int * v16237 = v16182->regs;
  v16237[24] = v16236;
  struct StateT * v16239 = slot_380(v16182);
  return v16239;
}

struct StateT * slot_552(struct StateT * v19920) {
  int v19921 = v19920->timer;
  int v19929 = v19921 + 1;
  v19920->timer = v19929;
  int * v19923 = v19920->regs;
  int v19924 = v19923[15];
  int * v19925 = v19920->regs;
  int v19933 = v19924 << 13;
  v19925[15] = v19933;
  struct StateT * v19927 = slot_553(v19920);
  return v19927;
}

struct StateT * slot_427(struct StateT * v17485) {
  int v17486 = v17485->timer;
  int v17496 = v17486 + 1;
  v17485->timer = v17496;
  int * v17488 = v17485->regs;
  int v17489 = v17488[19];
  int * v17490 = v17485->regs;
  int v17491 = v17490[13];
  int * v17492 = v17485->regs;
  int v17503 = v17489 + v17491;
  v17492[16] = v17503;
  struct StateT * v17494 = slot_428(v17485);
  return v17494;
}

struct StateT * slot_399(struct StateT * v16946) {
  int v16947 = v16946->timer;
  int v16955 = v16947 + 1;
  v16946->timer = v16955;
  int * v16949 = v16946->regs;
  int v16950 = v16949[18];
  int * v16951 = v16946->regs;
  int v16959 = v16950 << 13;
  v16951[18] = v16959;
  struct StateT * v16953 = slot_400(v16946);
  return v16953;
}

struct StateT * slot_239(struct StateT * v8292) {
  int v8293 = v8292->timer;
  int v8351 = v8293 + 1;
  v8292->timer = v8351;
  int * v8295 = v8292->regs;
  int v8296 = v8295[2];
  int * v8297 = v8292->cache_keys;
  int v8298 = v8297[0];
  bool v8356 = v8298 == ((int)((unsigned int)(v8296 + 24) >> 2));
  int v8346;
  if (v8356) {
    int * v8299 = v8292->cache_vals;
    int v8300 = v8299[0];
    v8346 = v8300;
  } else {
    int * v8302 = v8292->cache_keys;
    int v8303 = v8302[1];
    bool v8361 = v8303 == ((int)((unsigned int)(v8296 + 24) >> 2));
    int v8344;
    if (v8361) {
      int * v8304 = v8292->cache_vals;
      int v8305 = v8304[1];
      int * v8306 = v8292->cache_keys;
      int * v8307 = v8292->cache_keys;
      int v8308 = v8307[0];
      v8306[1] = v8308;
      int * v8310 = v8292->cache_vals;
      int * v8311 = v8292->cache_vals;
      int v8312 = v8311[0];
      v8310[1] = v8312;
      int * v8314 = v8292->cache_keys;
      int v8370 = (int)((unsigned int)(v8296 + 24) >> 2);
      v8314[0] = v8370;
      int * v8316 = v8292->cache_vals;
      v8316[0] = v8305;
      int v8318 = v8292->timer;
      int v8373 = v8318 + 1;
      v8292->timer = v8373;
      v8344 = v8305;
    } else {
      int * v8321 = v8292->mem;
      int v8375 = (int)((unsigned int)(v8296 + 24) >> 2);
      int v8322 = v8321[v8375];
      int * v8323 = v8292->mem;
      int * v8324 = v8292->cache_keys;
      int v8325 = v8324[1];
      int * v8326 = v8292->cache_vals;
      int v8327 = v8326[1];
      v8323[v8325] = v8327;
      int * v8329 = v8292->cache_keys;
      int * v8330 = v8292->cache_keys;
      int v8331 = v8330[0];
      v8329[1] = v8331;
      int * v8333 = v8292->cache_vals;
      int * v8334 = v8292->cache_vals;
      int v8335 = v8334[0];
      v8333[1] = v8335;
      int * v8337 = v8292->cache_keys;
      v8337[0] = v8375;
      int * v8339 = v8292->cache_vals;
      v8339[0] = v8322;
      int v8341 = v8292->timer;
      int v8390 = v8341 + 100;
      v8292->timer = v8390;
      v8344 = v8322;
    }
    v8346 = v8344;
  }
  int * v8347 = v8292->regs;
  v8347[7] = v8346;
  struct StateT * v8349 = slot_241(v8292);
  return v8349;
}

struct StateT * slot_464(struct StateT * v18179) {
  int v18180 = v18179->timer;
  int v18190 = v18180 + 1;
  v18179->timer = v18190;
  int * v18182 = v18179->regs;
  int v18183 = v18182[24];
  int * v18184 = v18179->regs;
  int v18185 = v18184[8];
  int * v18186 = v18179->regs;
  int v18196 = v18183 ^ v18185;
  v18186[24] = v18196;
  struct StateT * v18188 = slot_465(v18179);
  return v18188;
}

struct StateT * slot_500(struct StateT * v18851) {
  int v18852 = v18851->timer;
  int v18862 = v18852 + 1;
  v18851->timer = v18862;
  int * v18854 = v18851->regs;
  int v18855 = v18854[8];
  int * v18856 = v18851->regs;
  int v18857 = v18856[9];
  int * v18858 = v18851->regs;
  int v18868 = v18855 | v18857;
  v18858[8] = v18868;
  struct StateT * v18860 = slot_501(v18851);
  return v18860;
}

struct StateT * slot_433(struct StateT * v17597) {
  int v17598 = v17597->timer;
  int v17606 = v17598 + 1;
  v17597->timer = v17606;
  int * v17600 = v17597->regs;
  int v17601 = v17600[11];
  int * v17602 = v17597->regs;
  int v17610 = v17601 << 7;
  v17602[11] = v17610;
  struct StateT * v17604 = slot_434(v17597);
  return v17604;
}

struct StateT * slot_121(struct StateT * v5118) {
  int v5119 = v5118->timer;
  int v5127 = v5119 + 1;
  v5118->timer = v5127;
  int * v5121 = v5118->regs;
  int v5122 = v5121[17];
  int * v5123 = v5118->regs;
  int v5132 = (int)((unsigned int)v5122 >> 14);
  v5123[6] = v5132;
  struct StateT * v5125 = slot_122(v5118);
  return v5125;
}

struct StateT * slot_610(struct StateT * v21082) {
  int v21083 = v21082->timer;
  int v21093 = v21083 + 1;
  v21082->timer = v21093;
  int * v21085 = v21082->regs;
  int v21086 = v21085[16];
  int * v21087 = v21082->regs;
  int v21088 = v21087[22];
  int * v21089 = v21082->regs;
  int v21100 = v21086 + v21088;
  v21089[8] = v21100;
  struct StateT * v21091 = slot_611(v21082);
  return v21091;
}

struct StateT * slot_144(struct StateT * v5576) {
  int v5577 = v5576->timer;
  int v5585 = v5577 + 1;
  v5576->timer = v5585;
  int * v5579 = v5576->regs;
  int v5580 = v5579[17];
  int * v5581 = v5576->regs;
  int v5590 = (int)((unsigned int)v5580 >> 25);
  v5581[5] = v5590;
  struct StateT * v5583 = slot_145(v5576);
  return v5583;
}

struct StateT * slot_267(struct StateT * v9706) {
  int v9707 = v9706->timer;
  int v9713 = v9707 + 1;
  v9706->timer = v9713;
  int * v9709 = v9706->regs;
  v9709[30] = 1797283840;
  struct StateT * v9711 = slot_270(v9706);
  return v9711;
}

struct StateT * slot_492(struct StateT * v18712) {
  int v18713 = v18712->timer;
  int v18721 = v18713 + 1;
  v18712->timer = v18721;
  int * v18715 = v18712->regs;
  int v18716 = v18715[15];
  int * v18717 = v18712->regs;
  int v18726 = (int)((unsigned int)v18716 >> 14);
  v18717[9] = v18726;
  struct StateT * v18719 = slot_493(v18712);
  return v18719;
}

struct StateT * slot_201(struct StateT * v6655) {
  int v6656 = v6655->timer;
  int v6664 = v6656 + 1;
  v6655->timer = v6664;
  int * v6658 = v6655->regs;
  int v6659 = v6658[6];
  int * v6660 = v6655->regs;
  int v6669 = (int)((unsigned int)v6659 >> 14);
  v6660[9] = v6669;
  struct StateT * v6662 = slot_202(v6655);
  return v6662;
}

struct StateT * slot_600(struct StateT * v20882) {
  int v20883 = v20882->timer;
  int v20891 = v20883 + 1;
  v20882->timer = v20891;
  int * v20885 = v20882->regs;
  int v20886 = v20885[17];
  int * v20887 = v20882->regs;
  int v20896 = (int)((unsigned int)v20886 >> 25);
  v20887[5] = v20896;
  struct StateT * v20889 = slot_601(v20882);
  return v20889;
}

struct StateT * slot_63(struct StateT * v3928) {
  int v3929 = v3928->timer;
  int v3939 = v3929 + 1;
  v3928->timer = v3939;
  int * v3931 = v3928->regs;
  int v3932 = v3931[18];
  int * v3933 = v3928->regs;
  int v3934 = v3933[20];
  int * v3935 = v3928->regs;
  int v3945 = v3932 | v3934;
  v3935[18] = v3945;
  struct StateT * v3937 = slot_64(v3928);
  return v3937;
}

struct StateT * slot_570(struct StateT * v20290) {
  int * v20291 = v20290->saved_regs;
  int * v20292 = v20290->regs;
  int v20293 = v20292[5];
  v20291[5] = v20293;
  int v20295 = v20290->timer;
  int v20309 = v20295 + 1;
  v20290->timer = v20309;
  int * v20297 = v20290->regs;
  int v20298 = v20297[8];
  int * v20299 = v20290->regs;
  int v20300 = v20299[25];
  int * v20301 = v20290->regs;
  int v20315 = v20298 + v20300;
  v20301[5] = v20315;
  struct StateT * v20303 = slot_571(v20290);
  return v20303;
}

struct StateT * slot_195(struct StateT * v6549) {
  int v6550 = v6549->timer;
  int v6558 = v6550 + 1;
  v6549->timer = v6558;
  int * v6552 = v6549->regs;
  int v6553 = v6552[11];
  int * v6554 = v6549->regs;
  int v6563 = (int)((unsigned int)v6553 >> 14);
  v6554[9] = v6563;
  struct StateT * v6556 = slot_196(v6549);
  return v6556;
}

struct StateT * slot_326(struct StateT * v12383) {
  int v12384 = v12383->timer;
  int v12438 = v12384 + 1;
  v12383->timer = v12438;
  int * v12386 = v12383->regs;
  int v12387 = v12386[10];
  int * v12388 = v12383->regs;
  int v12389 = v12388[26];
  int * v12390 = v12383->cache_keys;
  int v12391 = v12390[0];
  bool v12445 = v12391 == ((int)((unsigned int)(v12387 + 32) >> 2));
  int v12435;
  if (v12445) {
    int * v12392 = v12383->cache_vals;
    v12392[0] = v12389;
    v12435 = v12389;
  } else {
    int * v12395 = v12383->cache_keys;
    int v12396 = v12395[1];
    bool v12450 = v12396 == ((int)((unsigned int)(v12387 + 32) >> 2));
    int v12433;
    if (v12450) {
      int * v12397 = v12383->cache_keys;
      int * v12398 = v12383->cache_keys;
      int v12399 = v12398[0];
      v12397[1] = v12399;
      int * v12401 = v12383->cache_vals;
      int * v12402 = v12383->cache_vals;
      int v12403 = v12402[0];
      v12401[1] = v12403;
      int * v12405 = v12383->cache_keys;
      int v12458 = (int)((unsigned int)(v12387 + 32) >> 2);
      v12405[0] = v12458;
      int * v12407 = v12383->cache_vals;
      v12407[0] = v12389;
      int v12409 = v12383->timer;
      int v12461 = v12409 + 1;
      v12383->timer = v12461;
      v12433 = v12389;
    } else {
      int * v12412 = v12383->mem;
      int * v12413 = v12383->cache_keys;
      int v12414 = v12413[1];
      int * v12415 = v12383->cache_vals;
      int v12416 = v12415[1];
      v12412[v12414] = v12416;
      int * v12418 = v12383->cache_keys;
      int * v12419 = v12383->cache_keys;
      int v12420 = v12419[0];
      v12418[1] = v12420;
      int * v12422 = v12383->cache_vals;
      int * v12423 = v12383->cache_vals;
      int v12424 = v12423[0];
      v12422[1] = v12424;
      int * v12426 = v12383->cache_keys;
      int v12474 = (int)((unsigned int)(v12387 + 32) >> 2);
      v12426[0] = v12474;
      int * v12428 = v12383->cache_vals;
      v12428[0] = v12389;
      int v12430 = v12383->timer;
      int v12477 = v12430 + 100;
      v12383->timer = v12477;
      v12433 = v12389;
    }
    v12435 = v12433;
  }
  struct StateT * v12436 = slot_329(v12383);
  return v12436;
}

struct StateT * slot_303(struct StateT * v10756) {
  int v10757 = v10756->timer;
  int v10811 = v10757 + 1;
  v10756->timer = v10811;
  int * v10759 = v10756->regs;
  int v10760 = v10759[10];
  int * v10761 = v10756->regs;
  int v10762 = v10761[14];
  int * v10763 = v10756->cache_keys;
  int v10764 = v10763[0];
  bool v10818 = v10764 == ((int)((unsigned int)(v10760 + 12) >> 2));
  int v10808;
  if (v10818) {
    int * v10765 = v10756->cache_vals;
    v10765[0] = v10762;
    v10808 = v10762;
  } else {
    int * v10768 = v10756->cache_keys;
    int v10769 = v10768[1];
    bool v10823 = v10769 == ((int)((unsigned int)(v10760 + 12) >> 2));
    int v10806;
    if (v10823) {
      int * v10770 = v10756->cache_keys;
      int * v10771 = v10756->cache_keys;
      int v10772 = v10771[0];
      v10770[1] = v10772;
      int * v10774 = v10756->cache_vals;
      int * v10775 = v10756->cache_vals;
      int v10776 = v10775[0];
      v10774[1] = v10776;
      int * v10778 = v10756->cache_keys;
      int v10831 = (int)((unsigned int)(v10760 + 12) >> 2);
      v10778[0] = v10831;
      int * v10780 = v10756->cache_vals;
      v10780[0] = v10762;
      int v10782 = v10756->timer;
      int v10834 = v10782 + 1;
      v10756->timer = v10834;
      v10806 = v10762;
    } else {
      int * v10785 = v10756->mem;
      int * v10786 = v10756->cache_keys;
      int v10787 = v10786[1];
      int * v10788 = v10756->cache_vals;
      int v10789 = v10788[1];
      v10785[v10787] = v10789;
      int * v10791 = v10756->cache_keys;
      int * v10792 = v10756->cache_keys;
      int v10793 = v10792[0];
      v10791[1] = v10793;
      int * v10795 = v10756->cache_vals;
      int * v10796 = v10756->cache_vals;
      int v10797 = v10796[0];
      v10795[1] = v10797;
      int * v10799 = v10756->cache_keys;
      int v10847 = (int)((unsigned int)(v10760 + 12) >> 2);
      v10799[0] = v10847;
      int * v10801 = v10756->cache_vals;
      v10801[0] = v10762;
      int v10803 = v10756->timer;
      int v10850 = v10803 + 100;
      v10756->timer = v10850;
      v10806 = v10762;
    }
    v10808 = v10806;
  }
  struct StateT * v10809 = slot_306(v10756);
  return v10809;
}

struct StateT * slot_511(struct StateT * v19088) {
  int * v19089 = v19088->saved_regs;
  int * v19090 = v19088->regs;
  int v19091 = v19090[9];
  v19089[9] = v19091;
  int v19093 = v19088->timer;
  int v19105 = v19093 + 1;
  v19088->timer = v19105;
  int * v19095 = v19088->regs;
  int v19096 = v19095[15];
  int * v19097 = v19088->regs;
  int v19109 = (int)((unsigned int)v19096 >> 25);
  v19097[9] = v19109;
  struct StateT * v19099 = slot_512(v19088);
  return v19099;
}

struct StateT * slot_335(struct StateT * v13024) {
  int v13025 = v13024->timer;
  int v13079 = v13025 + 1;
  v13024->timer = v13079;
  int * v13027 = v13024->regs;
  int v13028 = v13027[10];
  int * v13029 = v13024->regs;
  int v13030 = v13029[17];
  int * v13031 = v13024->cache_keys;
  int v13032 = v13031[0];
  bool v13086 = v13032 == ((int)((unsigned int)(v13028 + 44) >> 2));
  int v13076;
  if (v13086) {
    int * v13033 = v13024->cache_vals;
    v13033[0] = v13030;
    v13076 = v13030;
  } else {
    int * v13036 = v13024->cache_keys;
    int v13037 = v13036[1];
    bool v13091 = v13037 == ((int)((unsigned int)(v13028 + 44) >> 2));
    int v13074;
    if (v13091) {
      int * v13038 = v13024->cache_keys;
      int * v13039 = v13024->cache_keys;
      int v13040 = v13039[0];
      v13038[1] = v13040;
      int * v13042 = v13024->cache_vals;
      int * v13043 = v13024->cache_vals;
      int v13044 = v13043[0];
      v13042[1] = v13044;
      int * v13046 = v13024->cache_keys;
      int v13099 = (int)((unsigned int)(v13028 + 44) >> 2);
      v13046[0] = v13099;
      int * v13048 = v13024->cache_vals;
      v13048[0] = v13030;
      int v13050 = v13024->timer;
      int v13102 = v13050 + 1;
      v13024->timer = v13102;
      v13074 = v13030;
    } else {
      int * v13053 = v13024->mem;
      int * v13054 = v13024->cache_keys;
      int v13055 = v13054[1];
      int * v13056 = v13024->cache_vals;
      int v13057 = v13056[1];
      v13053[v13055] = v13057;
      int * v13059 = v13024->cache_keys;
      int * v13060 = v13024->cache_keys;
      int v13061 = v13060[0];
      v13059[1] = v13061;
      int * v13063 = v13024->cache_vals;
      int * v13064 = v13024->cache_vals;
      int v13065 = v13064[0];
      v13063[1] = v13065;
      int * v13067 = v13024->cache_keys;
      int v13115 = (int)((unsigned int)(v13028 + 44) >> 2);
      v13067[0] = v13115;
      int * v13069 = v13024->cache_vals;
      v13069[0] = v13030;
      int v13071 = v13024->timer;
      int v13118 = v13071 + 100;
      v13024->timer = v13118;
      v13074 = v13030;
    }
    v13076 = v13074;
  }
  struct StateT * v13077 = slot_338(v13024);
  return v13077;
}

struct StateT * slot_223(struct StateT * v7356) {
  int v7357 = v7356->timer;
  int v7367 = v7357 + 1;
  v7356->timer = v7367;
  int * v7359 = v7356->regs;
  int v7360 = v7359[12];
  int * v7361 = v7356->regs;
  int v7362 = v7361[6];
  int * v7363 = v7356->regs;
  int v7373 = v7360 + v7362;
  v7363[12] = v7373;
  struct StateT * v7365 = slot_225(v7356);
  return v7365;
}

struct StateT * slot_316(struct StateT * v11720) {
  int v11721 = v11720->timer;
  int v11731 = v11721 + 1;
  v11720->timer = v11731;
  int * v11723 = v11720->regs;
  int v11724 = v11723[1];
  int * v11725 = v11720->regs;
  int v11726 = v11725[19];
  int * v11727 = v11720->regs;
  int v11738 = v11724 + v11726;
  v11727[9] = v11738;
  struct StateT * v11729 = slot_319(v11720);
  return v11729;
}

struct StateT * slot_424(struct StateT * v17423) {
  int v17424 = v17423->timer;
  int v17434 = v17424 + 1;
  v17423->timer = v17434;
  int * v17426 = v17423->regs;
  int v17427 = v17426[22];
  int * v17428 = v17423->regs;
  int v17429 = v17428[5];
  int * v17430 = v17423->regs;
  int v17440 = v17427 ^ v17429;
  v17430[22] = v17440;
  struct StateT * v17432 = slot_425(v17423);
  return v17432;
}

struct StateT * slot_332(struct StateT * v12812) {
  int v12813 = v12812->timer;
  int v12867 = v12813 + 1;
  v12812->timer = v12867;
  int * v12815 = v12812->regs;
  int v12816 = v12815[10];
  int * v12817 = v12812->regs;
  int v12818 = v12817[7];
  int * v12819 = v12812->cache_keys;
  int v12820 = v12819[0];
  bool v12874 = v12820 == ((int)((unsigned int)(v12816 + 40) >> 2));
  int v12864;
  if (v12874) {
    int * v12821 = v12812->cache_vals;
    v12821[0] = v12818;
    v12864 = v12818;
  } else {
    int * v12824 = v12812->cache_keys;
    int v12825 = v12824[1];
    bool v12879 = v12825 == ((int)((unsigned int)(v12816 + 40) >> 2));
    int v12862;
    if (v12879) {
      int * v12826 = v12812->cache_keys;
      int * v12827 = v12812->cache_keys;
      int v12828 = v12827[0];
      v12826[1] = v12828;
      int * v12830 = v12812->cache_vals;
      int * v12831 = v12812->cache_vals;
      int v12832 = v12831[0];
      v12830[1] = v12832;
      int * v12834 = v12812->cache_keys;
      int v12887 = (int)((unsigned int)(v12816 + 40) >> 2);
      v12834[0] = v12887;
      int * v12836 = v12812->cache_vals;
      v12836[0] = v12818;
      int v12838 = v12812->timer;
      int v12890 = v12838 + 1;
      v12812->timer = v12890;
      v12862 = v12818;
    } else {
      int * v12841 = v12812->mem;
      int * v12842 = v12812->cache_keys;
      int v12843 = v12842[1];
      int * v12844 = v12812->cache_vals;
      int v12845 = v12844[1];
      v12841[v12843] = v12845;
      int * v12847 = v12812->cache_keys;
      int * v12848 = v12812->cache_keys;
      int v12849 = v12848[0];
      v12847[1] = v12849;
      int * v12851 = v12812->cache_vals;
      int * v12852 = v12812->cache_vals;
      int v12853 = v12852[0];
      v12851[1] = v12853;
      int * v12855 = v12812->cache_keys;
      int v12903 = (int)((unsigned int)(v12816 + 40) >> 2);
      v12855[0] = v12903;
      int * v12857 = v12812->cache_vals;
      v12857[0] = v12818;
      int v12859 = v12812->timer;
      int v12906 = v12859 + 100;
      v12812->timer = v12906;
      v12862 = v12818;
    }
    v12864 = v12862;
  }
  struct StateT * v12865 = slot_335(v12812);
  return v12865;
}

struct StateT * slot_237(struct StateT * v8167) {
  int v8168 = v8167->timer;
  int v8178 = v8168 + 1;
  v8167->timer = v8178;
  int * v8170 = v8167->regs;
  int v8171 = v8170[26];
  int * v8172 = v8167->regs;
  int v8173 = v8172[7];
  int * v8174 = v8167->regs;
  int v8184 = v8171 + v8173;
  v8174[26] = v8184;
  struct StateT * v8176 = slot_239(v8167);
  return v8176;
}

struct StateT * slot_41(struct StateT * v3185) {
  int v3186 = v3185->timer;
  int v3240 = v3186 + 1;
  v3185->timer = v3240;
  int * v3188 = v3185->regs;
  int v3189 = v3188[2];
  int * v3190 = v3185->regs;
  int v3191 = v3190[16];
  int * v3192 = v3185->cache_keys;
  int v3193 = v3192[0];
  bool v3247 = v3193 == ((int)((unsigned int)(v3189 + 32) >> 2));
  int v3237;
  if (v3247) {
    int * v3194 = v3185->cache_vals;
    v3194[0] = v3191;
    v3237 = v3191;
  } else {
    int * v3197 = v3185->cache_keys;
    int v3198 = v3197[1];
    bool v3252 = v3198 == ((int)((unsigned int)(v3189 + 32) >> 2));
    int v3235;
    if (v3252) {
      int * v3199 = v3185->cache_keys;
      int * v3200 = v3185->cache_keys;
      int v3201 = v3200[0];
      v3199[1] = v3201;
      int * v3203 = v3185->cache_vals;
      int * v3204 = v3185->cache_vals;
      int v3205 = v3204[0];
      v3203[1] = v3205;
      int * v3207 = v3185->cache_keys;
      int v3260 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3207[0] = v3260;
      int * v3209 = v3185->cache_vals;
      v3209[0] = v3191;
      int v3211 = v3185->timer;
      int v3263 = v3211 + 1;
      v3185->timer = v3263;
      v3235 = v3191;
    } else {
      int * v3214 = v3185->mem;
      int * v3215 = v3185->cache_keys;
      int v3216 = v3215[1];
      int * v3217 = v3185->cache_vals;
      int v3218 = v3217[1];
      v3214[v3216] = v3218;
      int * v3220 = v3185->cache_keys;
      int * v3221 = v3185->cache_keys;
      int v3222 = v3221[0];
      v3220[1] = v3222;
      int * v3224 = v3185->cache_vals;
      int * v3225 = v3185->cache_vals;
      int v3226 = v3225[0];
      v3224[1] = v3226;
      int * v3228 = v3185->cache_keys;
      int v3276 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3228[0] = v3276;
      int * v3230 = v3185->cache_vals;
      v3230[0] = v3191;
      int v3232 = v3185->timer;
      int v3279 = v3232 + 100;
      v3185->timer = v3279;
      v3235 = v3191;
    }
    v3237 = v3235;
  }
  struct StateT * v3238 = slot_42(v3185);
  return v3238;
}

struct StateT * slot_39(struct StateT * v2990) {
  int v2991 = v2990->timer;
  int v3045 = v2991 + 1;
  v2990->timer = v3045;
  int * v2993 = v2990->regs;
  int v2994 = v2993[2];
  int * v2995 = v2990->regs;
  int v2996 = v2995[1];
  int * v2997 = v2990->cache_keys;
  int v2998 = v2997[0];
  bool v3052 = v2998 == ((int)((unsigned int)(v2994 + 40) >> 2));
  int v3042;
  if (v3052) {
    int * v2999 = v2990->cache_vals;
    v2999[0] = v2996;
    v3042 = v2996;
  } else {
    int * v3002 = v2990->cache_keys;
    int v3003 = v3002[1];
    bool v3056 = v3003 == ((int)((unsigned int)(v2994 + 40) >> 2));
    int v3040;
    if (v3056) {
      int * v3004 = v2990->cache_keys;
      int * v3005 = v2990->cache_keys;
      int v3006 = v3005[0];
      v3004[1] = v3006;
      int * v3008 = v2990->cache_vals;
      int * v3009 = v2990->cache_vals;
      int v3010 = v3009[0];
      v3008[1] = v3010;
      int * v3012 = v2990->cache_keys;
      int v3064 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3012[0] = v3064;
      int * v3014 = v2990->cache_vals;
      v3014[0] = v2996;
      int v3016 = v2990->timer;
      int v3067 = v3016 + 1;
      v2990->timer = v3067;
      v3040 = v2996;
    } else {
      int * v3019 = v2990->mem;
      int * v3020 = v2990->cache_keys;
      int v3021 = v3020[1];
      int * v3022 = v2990->cache_vals;
      int v3023 = v3022[1];
      v3019[v3021] = v3023;
      int * v3025 = v2990->cache_keys;
      int * v3026 = v2990->cache_keys;
      int v3027 = v3026[0];
      v3025[1] = v3027;
      int * v3029 = v2990->cache_vals;
      int * v3030 = v2990->cache_vals;
      int v3031 = v3030[0];
      v3029[1] = v3031;
      int * v3033 = v2990->cache_keys;
      int v3080 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3033[0] = v3080;
      int * v3035 = v2990->cache_vals;
      v3035[0] = v2996;
      int v3037 = v2990->timer;
      int v3083 = v3037 + 100;
      v2990->timer = v3083;
      v3040 = v2996;
    }
    v3042 = v3040;
  }
  struct StateT * v3043 = slot_40(v2990);
  return v3043;
}

struct StateT * slot_508(struct StateT * v19004) {
  int * v19005 = v19004->saved_regs;
  int * v19006 = v19004->regs;
  int v19007 = v19006[20];
  v19005[20] = v19007;
  int v19009 = v19004->timer;
  int v19023 = v19009 + 1;
  v19004->timer = v19023;
  int * v19011 = v19004->regs;
  int v19012 = v19011[11];
  int * v19013 = v19004->regs;
  int v19014 = v19013[23];
  int * v19015 = v19004->regs;
  int v19029 = v19012 + v19014;
  v19015[20] = v19029;
  struct StateT * v19017 = slot_509(v19004);
  return v19017;
}

struct StateT * slot_668(struct StateT * v22348) {
  int v22349 = v22348->timer;
  int v22359 = v22349 + 1;
  v22348->timer = v22359;
  int * v22351 = v22348->regs;
  int v22352 = v22351[23];
  int * v22353 = v22348->regs;
  int v22354 = v22353[29];
  int * v22355 = v22348->regs;
  int v22365 = v22352 + v22354;
  v22355[29] = v22365;
  struct StateT * v22357 = slot_669(v22348);
  return v22357;
}

struct StateT * slot_537(struct StateT * v19605) {
  int v19606 = v19605->timer;
  int v19614 = v19606 + 1;
  v19605->timer = v19614;
  int * v19608 = v19605->regs;
  int v19609 = v19608[9];
  int * v19610 = v19605->regs;
  int v19619 = (int)((unsigned int)v19609 >> 23);
  v19610[20] = v19619;
  struct StateT * v19612 = slot_538(v19605);
  return v19612;
}

struct StateT * slot_60(struct StateT * v3875) {
  int v3876 = v3875->timer;
  int v3886 = v3876 + 1;
  v3875->timer = v3886;
  int * v3878 = v3875->regs;
  int v3879 = v3878[20];
  int * v3880 = v3875->regs;
  int v3881 = v3880[9];
  int * v3882 = v3875->regs;
  int v3892 = v3879 | v3881;
  v3882[9] = v3892;
  struct StateT * v3884 = slot_61(v3875);
  return v3884;
}

struct StateT * slot_289(struct StateT * v10171) {
  int v10172 = v10171->timer;
  int v10180 = v10172 + 1;
  v10171->timer = v10180;
  int * v10174 = v10171->regs;
  int v10175 = v10174[8];
  int * v10176 = v10171->regs;
  int v10185 = (int)((unsigned int)v10175 >> 25);
  v10176[20] = v10185;
  struct StateT * v10178 = slot_292(v10171);
  return v10178;
}

struct StateT * slot_238(struct StateT * v8187) {
  int v8188 = v8187->timer;
  int v8246 = v8188 + 1;
  v8187->timer = v8246;
  int * v8190 = v8187->regs;
  int v8191 = v8190[2];
  int * v8192 = v8187->cache_keys;
  int v8193 = v8192[0];
  bool v8251 = v8193 == ((int)((unsigned int)(v8191 + 20) >> 2));
  int v8241;
  if (v8251) {
    int * v8194 = v8187->cache_vals;
    int v8195 = v8194[0];
    v8241 = v8195;
  } else {
    int * v8197 = v8187->cache_keys;
    int v8198 = v8197[1];
    bool v8256 = v8198 == ((int)((unsigned int)(v8191 + 20) >> 2));
    int v8239;
    if (v8256) {
      int * v8199 = v8187->cache_vals;
      int v8200 = v8199[1];
      int * v8201 = v8187->cache_keys;
      int * v8202 = v8187->cache_keys;
      int v8203 = v8202[0];
      v8201[1] = v8203;
      int * v8205 = v8187->cache_vals;
      int * v8206 = v8187->cache_vals;
      int v8207 = v8206[0];
      v8205[1] = v8207;
      int * v8209 = v8187->cache_keys;
      int v8265 = (int)((unsigned int)(v8191 + 20) >> 2);
      v8209[0] = v8265;
      int * v8211 = v8187->cache_vals;
      v8211[0] = v8200;
      int v8213 = v8187->timer;
      int v8268 = v8213 + 1;
      v8187->timer = v8268;
      v8239 = v8200;
    } else {
      int * v8216 = v8187->mem;
      int v8270 = (int)((unsigned int)(v8191 + 20) >> 2);
      int v8217 = v8216[v8270];
      int * v8218 = v8187->mem;
      int * v8219 = v8187->cache_keys;
      int v8220 = v8219[1];
      int * v8221 = v8187->cache_vals;
      int v8222 = v8221[1];
      v8218[v8220] = v8222;
      int * v8224 = v8187->cache_keys;
      int * v8225 = v8187->cache_keys;
      int v8226 = v8225[0];
      v8224[1] = v8226;
      int * v8228 = v8187->cache_vals;
      int * v8229 = v8187->cache_vals;
      int v8230 = v8229[0];
      v8228[1] = v8230;
      int * v8232 = v8187->cache_keys;
      v8232[0] = v8270;
      int * v8234 = v8187->cache_vals;
      v8234[0] = v8217;
      int v8236 = v8187->timer;
      int v8285 = v8236 + 100;
      v8187->timer = v8285;
      v8239 = v8217;
    }
    v8241 = v8239;
  }
  int * v8242 = v8187->regs;
  v8242[7] = v8241;
  struct StateT * v8244 = slot_240(v8187);
  return v8244;
}

struct StateT * slot_112(struct StateT * v4928) {
  int * v4929 = v4928->saved_regs;
  int * v4930 = v4928->regs;
  int v4931 = v4930[16];
  v4929[16] = v4931;
  int v4933 = v4928->timer;
  int v4947 = v4933 + 1;
  v4928->timer = v4947;
  int * v4935 = v4928->regs;
  int v4936 = v4935[23];
  int * v4937 = v4928->regs;
  int v4938 = v4937[24];
  int * v4939 = v4928->regs;
  int v4953 = v4936 + v4938;
  v4939[16] = v4953;
  struct StateT * v4941 = slot_113(v4928);
  return v4941;
}

struct StateT * slot_256(struct StateT * v9236) {
  int v9237 = v9236->timer;
  int v9247 = v9237 + 1;
  v9236->timer = v9247;
  int * v9239 = v9236->regs;
  int v9240 = v9239[19];
  int * v9241 = v9236->regs;
  int v9242 = v9241[5];
  int * v9243 = v9236->regs;
  int v9254 = v9240 + v9242;
  v9243[18] = v9254;
  struct StateT * v9245 = slot_259(v9236);
  return v9245;
}

struct StateT * slot_544(struct StateT * v19738) {
  int * v19739 = v19738->saved_regs;
  int * v19740 = v19738->regs;
  int v19741 = v19740[24];
  v19739[24] = v19741;
  int v19743 = v19738->timer;
  int v19757 = v19743 + 1;
  v19738->timer = v19757;
  int * v19745 = v19738->regs;
  int v19746 = v19745[24];
  int * v19747 = v19738->regs;
  int v19748 = v19747[8];
  int * v19749 = v19738->regs;
  int v19762 = v19746 ^ v19748;
  v19749[24] = v19762;
  struct StateT * v19751 = slot_545(v19738);
  return v19751;
}

struct StateT * slot_573(struct StateT * v20351) {
  int v20352 = v20351->timer;
  int v20362 = v20352 + 1;
  v20351->timer = v20362;
  int * v20354 = v20351->regs;
  int v20355 = v20354[15];
  int * v20356 = v20351->regs;
  int v20357 = v20356[6];
  int * v20358 = v20351->regs;
  int v20368 = v20355 | v20357;
  v20358[15] = v20368;
  struct StateT * v20360 = slot_574(v20351);
  return v20360;
}

struct StateT * slot_567(struct StateT * v20213) {
  int v20214 = v20213->timer;
  int v20224 = v20214 + 1;
  v20213->timer = v20224;
  int * v20216 = v20213->regs;
  int v20217 = v20216[9];
  int * v20218 = v20213->regs;
  int v20219 = v20218[26];
  int * v20220 = v20213->regs;
  int v20231 = v20217 + v20219;
  v20220[15] = v20231;
  struct StateT * v20222 = slot_568(v20213);
  return v20222;
}

struct StateT * slot_16(struct StateT * v1409) {
  int v1410 = v1409->timer;
  int v1468 = v1410 + 1;
  v1409->timer = v1468;
  int * v1412 = v1409->regs;
  int v1413 = v1412[12];
  int * v1414 = v1409->cache_keys;
  int v1415 = v1414[0];
  bool v1473 = v1415 == ((int)((unsigned int)(v1413 + 4) >> 2));
  int v1463;
  if (v1473) {
    int * v1416 = v1409->cache_vals;
    int v1417 = v1416[0];
    v1463 = v1417;
  } else {
    int * v1419 = v1409->cache_keys;
    int v1420 = v1419[1];
    bool v1478 = v1420 == ((int)((unsigned int)(v1413 + 4) >> 2));
    int v1461;
    if (v1478) {
      int * v1421 = v1409->cache_vals;
      int v1422 = v1421[1];
      int * v1423 = v1409->cache_keys;
      int * v1424 = v1409->cache_keys;
      int v1425 = v1424[0];
      v1423[1] = v1425;
      int * v1427 = v1409->cache_vals;
      int * v1428 = v1409->cache_vals;
      int v1429 = v1428[0];
      v1427[1] = v1429;
      int * v1431 = v1409->cache_keys;
      int v1487 = (int)((unsigned int)(v1413 + 4) >> 2);
      v1431[0] = v1487;
      int * v1433 = v1409->cache_vals;
      v1433[0] = v1422;
      int v1435 = v1409->timer;
      int v1490 = v1435 + 1;
      v1409->timer = v1490;
      v1461 = v1422;
    } else {
      int * v1438 = v1409->mem;
      int v1492 = (int)((unsigned int)(v1413 + 4) >> 2);
      int v1439 = v1438[v1492];
      int * v1440 = v1409->mem;
      int * v1441 = v1409->cache_keys;
      int v1442 = v1441[1];
      int * v1443 = v1409->cache_vals;
      int v1444 = v1443[1];
      v1440[v1442] = v1444;
      int * v1446 = v1409->cache_keys;
      int * v1447 = v1409->cache_keys;
      int v1448 = v1447[0];
      v1446[1] = v1448;
      int * v1450 = v1409->cache_vals;
      int * v1451 = v1409->cache_vals;
      int v1452 = v1451[0];
      v1450[1] = v1452;
      int * v1454 = v1409->cache_keys;
      v1454[0] = v1492;
      int * v1456 = v1409->cache_vals;
      v1456[0] = v1439;
      int v1458 = v1409->timer;
      int v1507 = v1458 + 100;
      v1409->timer = v1507;
      v1461 = v1439;
    }
    v1463 = v1461;
  }
  int * v1464 = v1409->regs;
  v1464[28] = v1463;
  struct StateT * v1466 = slot_17(v1409);
  return v1466;
}

struct StateT * slot_245(struct StateT * v8589) {
  int v8590 = v8589->timer;
  int v8648 = v8590 + 1;
  v8589->timer = v8648;
  int * v8592 = v8589->regs;
  int v8593 = v8592[2];
  int * v8594 = v8589->cache_keys;
  int v8595 = v8594[0];
  bool v8653 = v8595 == ((int)((unsigned int)(v8593 + 28) >> 2));
  int v8643;
  if (v8653) {
    int * v8596 = v8589->cache_vals;
    int v8597 = v8596[0];
    v8643 = v8597;
  } else {
    int * v8599 = v8589->cache_keys;
    int v8600 = v8599[1];
    bool v8658 = v8600 == ((int)((unsigned int)(v8593 + 28) >> 2));
    int v8641;
    if (v8658) {
      int * v8601 = v8589->cache_vals;
      int v8602 = v8601[1];
      int * v8603 = v8589->cache_keys;
      int * v8604 = v8589->cache_keys;
      int v8605 = v8604[0];
      v8603[1] = v8605;
      int * v8607 = v8589->cache_vals;
      int * v8608 = v8589->cache_vals;
      int v8609 = v8608[0];
      v8607[1] = v8609;
      int * v8611 = v8589->cache_keys;
      int v8667 = (int)((unsigned int)(v8593 + 28) >> 2);
      v8611[0] = v8667;
      int * v8613 = v8589->cache_vals;
      v8613[0] = v8602;
      int v8615 = v8589->timer;
      int v8670 = v8615 + 1;
      v8589->timer = v8670;
      v8641 = v8602;
    } else {
      int * v8618 = v8589->mem;
      int v8672 = (int)((unsigned int)(v8593 + 28) >> 2);
      int v8619 = v8618[v8672];
      int * v8620 = v8589->mem;
      int * v8621 = v8589->cache_keys;
      int v8622 = v8621[1];
      int * v8623 = v8589->cache_vals;
      int v8624 = v8623[1];
      v8620[v8622] = v8624;
      int * v8626 = v8589->cache_keys;
      int * v8627 = v8589->cache_keys;
      int v8628 = v8627[0];
      v8626[1] = v8628;
      int * v8630 = v8589->cache_vals;
      int * v8631 = v8589->cache_vals;
      int v8632 = v8631[0];
      v8630[1] = v8632;
      int * v8634 = v8589->cache_keys;
      v8634[0] = v8672;
      int * v8636 = v8589->cache_vals;
      v8636[0] = v8619;
      int v8638 = v8589->timer;
      int v8687 = v8638 + 100;
      v8589->timer = v8687;
      v8641 = v8619;
    }
    v8643 = v8641;
  }
  int * v8644 = v8589->regs;
  v8644[30] = v8643;
  struct StateT * v8646 = slot_247(v8589);
  return v8646;
}

struct StateT * slot_113(struct StateT * v4956) {
  int * v4957 = v4956->saved_regs;
  int * v4958 = v4956->regs;
  int v4959 = v4958[17];
  v4957[17] = v4959;
  int v4961 = v4956->timer;
  int v4975 = v4961 + 1;
  v4956->timer = v4975;
  int * v4963 = v4956->regs;
  int v4964 = v4963[18];
  int * v4965 = v4956->regs;
  int v4966 = v4965[27];
  int * v4967 = v4956->regs;
  int v4981 = v4964 + v4966;
  v4967[17] = v4981;
  struct StateT * v4969 = slot_114(v4956);
  return v4969;
}

struct StateT * slot_302(struct StateT * v10658) {
  int v10659 = v10658->timer;
  int v10713 = v10659 + 1;
  v10658->timer = v10713;
  int * v10661 = v10658->regs;
  int v10662 = v10661[10];
  int * v10663 = v10658->regs;
  int v10664 = v10663[15];
  int * v10665 = v10658->cache_keys;
  int v10666 = v10665[0];
  bool v10720 = v10666 == ((int)((unsigned int)v10662 >> 2));
  int v10710;
  if (v10720) {
    int * v10667 = v10658->cache_vals;
    v10667[0] = v10664;
    v10710 = v10664;
  } else {
    int * v10670 = v10658->cache_keys;
    int v10671 = v10670[1];
    bool v10725 = v10671 == ((int)((unsigned int)v10662 >> 2));
    int v10708;
    if (v10725) {
      int * v10672 = v10658->cache_keys;
      int * v10673 = v10658->cache_keys;
      int v10674 = v10673[0];
      v10672[1] = v10674;
      int * v10676 = v10658->cache_vals;
      int * v10677 = v10658->cache_vals;
      int v10678 = v10677[0];
      v10676[1] = v10678;
      int * v10680 = v10658->cache_keys;
      int v10733 = (int)((unsigned int)v10662 >> 2);
      v10680[0] = v10733;
      int * v10682 = v10658->cache_vals;
      v10682[0] = v10664;
      int v10684 = v10658->timer;
      int v10736 = v10684 + 1;
      v10658->timer = v10736;
      v10708 = v10664;
    } else {
      int * v10687 = v10658->mem;
      int * v10688 = v10658->cache_keys;
      int v10689 = v10688[1];
      int * v10690 = v10658->cache_vals;
      int v10691 = v10690[1];
      v10687[v10689] = v10691;
      int * v10693 = v10658->cache_keys;
      int * v10694 = v10658->cache_keys;
      int v10695 = v10694[0];
      v10693[1] = v10695;
      int * v10697 = v10658->cache_vals;
      int * v10698 = v10658->cache_vals;
      int v10699 = v10698[0];
      v10697[1] = v10699;
      int * v10701 = v10658->cache_keys;
      int v10749 = (int)((unsigned int)v10662 >> 2);
      v10701[0] = v10749;
      int * v10703 = v10658->cache_vals;
      v10703[0] = v10664;
      int v10705 = v10658->timer;
      int v10752 = v10705 + 100;
      v10658->timer = v10752;
      v10708 = v10664;
    }
    v10710 = v10708;
  }
  struct StateT * v10711 = slot_305(v10658);
  return v10711;
}

struct StateT * slot_388(struct StateT * v16782) {
  int v16783 = v16782->timer;
  int v16793 = v16783 + 1;
  v16782->timer = v16793;
  int * v16785 = v16782->regs;
  int v16786 = v16785[15];
  int * v16787 = v16782->regs;
  int v16788 = v16787[20];
  int * v16789 = v16782->regs;
  int v16799 = v16786 | v16788;
  v16789[15] = v16799;
  struct StateT * v16791 = slot_390(v16782);
  return v16791;
}

struct StateT * slot_191(struct StateT * v6465) {
  int v6466 = v6465->timer;
  int v6476 = v6466 + 1;
  v6465->timer = v6476;
  int * v6468 = v6465->regs;
  int v6469 = v6468[14];
  int * v6470 = v6465->regs;
  int v6471 = v6470[27];
  int * v6472 = v6465->regs;
  int v6483 = v6469 + v6471;
  v6472[11] = v6483;
  struct StateT * v6474 = slot_192(v6465);
  return v6474;
}

struct StateT * slot_103(struct StateT * v4736) {
  int v4737 = v4736->timer;
  int v4747 = v4737 + 1;
  v4736->timer = v4747;
  int * v4739 = v4736->regs;
  int v4740 = v4739[9];
  int * v4741 = v4736->regs;
  int v4742 = v4741[20];
  int * v4743 = v4736->regs;
  int v4753 = v4740 | v4742;
  v4743[20] = v4753;
  struct StateT * v4745 = slot_104(v4736);
  return v4745;
}

struct StateT * slot_487(struct StateT * v18617) {
  int v18618 = v18617->timer;
  int v18628 = v18618 + 1;
  v18617->timer = v18628;
  int * v18620 = v18617->regs;
  int v18621 = v18620[13];
  int * v18622 = v18617->regs;
  int v18623 = v18622[26];
  int * v18624 = v18617->regs;
  int v18635 = v18621 + v18623;
  v18624[6] = v18635;
  struct StateT * v18626 = slot_488(v18617);
  return v18626;
}

struct StateT * slot_324(struct StateT * v12269) {
  int v12270 = v12269->timer;
  int v12324 = v12270 + 1;
  v12269->timer = v12324;
  int * v12272 = v12269->regs;
  int v12273 = v12272[10];
  int * v12274 = v12269->regs;
  int v12275 = v12274[7];
  int * v12276 = v12269->cache_keys;
  int v12277 = v12276[0];
  bool v12331 = v12277 == ((int)((unsigned int)(v12273 + 40) >> 2));
  int v12321;
  if (v12331) {
    int * v12278 = v12269->cache_vals;
    v12278[0] = v12275;
    v12321 = v12275;
  } else {
    int * v12281 = v12269->cache_keys;
    int v12282 = v12281[1];
    bool v12336 = v12282 == ((int)((unsigned int)(v12273 + 40) >> 2));
    int v12319;
    if (v12336) {
      int * v12283 = v12269->cache_keys;
      int * v12284 = v12269->cache_keys;
      int v12285 = v12284[0];
      v12283[1] = v12285;
      int * v12287 = v12269->cache_vals;
      int * v12288 = v12269->cache_vals;
      int v12289 = v12288[0];
      v12287[1] = v12289;
      int * v12291 = v12269->cache_keys;
      int v12344 = (int)((unsigned int)(v12273 + 40) >> 2);
      v12291[0] = v12344;
      int * v12293 = v12269->cache_vals;
      v12293[0] = v12275;
      int v12295 = v12269->timer;
      int v12347 = v12295 + 1;
      v12269->timer = v12347;
      v12319 = v12275;
    } else {
      int * v12298 = v12269->mem;
      int * v12299 = v12269->cache_keys;
      int v12300 = v12299[1];
      int * v12301 = v12269->cache_vals;
      int v12302 = v12301[1];
      v12298[v12300] = v12302;
      int * v12304 = v12269->cache_keys;
      int * v12305 = v12269->cache_keys;
      int v12306 = v12305[0];
      v12304[1] = v12306;
      int * v12308 = v12269->cache_vals;
      int * v12309 = v12269->cache_vals;
      int v12310 = v12309[0];
      v12308[1] = v12310;
      int * v12312 = v12269->cache_keys;
      int v12360 = (int)((unsigned int)(v12273 + 40) >> 2);
      v12312[0] = v12360;
      int * v12314 = v12269->cache_vals;
      v12314[0] = v12275;
      int v12316 = v12269->timer;
      int v12363 = v12316 + 100;
      v12269->timer = v12363;
      v12319 = v12275;
    }
    v12321 = v12319;
  }
  struct StateT * v12322 = slot_327(v12269);
  return v12322;
}

struct StateT * slot_645(struct StateT * v21731) {
  int v21732 = v21731->timer;
  int v21742 = v21732 + 1;
  v21731->timer = v21742;
  int * v21734 = v21731->regs;
  int v21735 = v21734[13];
  int * v21736 = v21731->regs;
  int v21737 = v21736[6];
  int * v21738 = v21731->regs;
  int v21748 = v21735 ^ v21737;
  v21738[13] = v21748;
  struct StateT * v21740 = slot_646(v21731);
  return v21740;
}

struct StateT * slot_440(struct StateT * v17719) {
  int v17720 = v17719->timer;
  int v17730 = v17720 + 1;
  v17719->timer = v17730;
  int * v17722 = v17719->regs;
  int v17723 = v17722[17];
  int * v17724 = v17719->regs;
  int v17725 = v17724[5];
  int * v17726 = v17719->regs;
  int v17737 = v17723 | v17725;
  v17726[6] = v17737;
  struct StateT * v17728 = slot_441(v17719);
  return v17728;
}

struct StateT * slot_633(struct StateT * v21512) {
  int v21513 = v21512->timer;
  int v21523 = v21513 + 1;
  v21512->timer = v21523;
  int * v21515 = v21512->regs;
  int v21516 = v21515[11];
  int * v21517 = v21512->regs;
  int v21518 = v21517[9];
  int * v21519 = v21512->regs;
  int v21529 = v21516 | v21518;
  v21519[11] = v21529;
  struct StateT * v21521 = slot_634(v21512);
  return v21521;
}

struct StateT * slot_547(struct StateT * v19819) {
  int v19820 = v19819->timer;
  int v19830 = v19820 + 1;
  v19819->timer = v19830;
  int * v19822 = v19819->regs;
  int v19823 = v19822[26];
  int * v19824 = v19819->regs;
  int v19825 = v19824[12];
  int * v19826 = v19819->regs;
  int v19837 = v19823 + v19825;
  v19826[15] = v19837;
  struct StateT * v19828 = slot_548(v19819);
  return v19828;
}

struct StateT * slot_518(struct StateT * v19218) {
  int v19219 = v19218->timer;
  int v19227 = v19219 + 1;
  v19218->timer = v19227;
  int * v19221 = v19218->regs;
  int v19222 = v19221[18];
  int * v19223 = v19218->regs;
  int v19231 = v19222 << 7;
  v19223[18] = v19231;
  struct StateT * v19225 = slot_519(v19218);
  return v19225;
}

struct StateT * slot_95(struct StateT * v4597) {
  int v4598 = v4597->timer;
  int v4606 = v4598 + 1;
  v4597->timer = v4606;
  int * v4600 = v4597->regs;
  int v4601 = v4600[15];
  int * v4602 = v4597->regs;
  int v4611 = (int)((unsigned int)v4601 >> 19);
  v4602[20] = v4611;
  struct StateT * v4604 = slot_96(v4597);
  return v4604;
}

struct StateT * slot_451(struct StateT * v17940) {
  int v17941 = v17940->timer;
  int v17951 = v17941 + 1;
  v17940->timer = v17951;
  int * v17943 = v17940->regs;
  int v17944 = v17943[11];
  int * v17945 = v17940->regs;
  int v17946 = v17945[9];
  int * v17947 = v17940->regs;
  int v17957 = v17944 | v17946;
  v17947[11] = v17957;
  struct StateT * v17949 = slot_452(v17940);
  return v17949;
}

struct StateT * slot_458(struct StateT * v18066) {
  int v18067 = v18066->timer;
  int v18075 = v18067 + 1;
  v18066->timer = v18075;
  int * v18069 = v18066->regs;
  int v18070 = v18069[8];
  int * v18071 = v18066->regs;
  int v18080 = (int)((unsigned int)v18070 >> 23);
  v18071[9] = v18080;
  struct StateT * v18073 = slot_459(v18066);
  return v18073;
}

struct StateT * slot_415(struct StateT * v17256) {
  int v17257 = v17256->timer;
  int v17265 = v17257 + 1;
  v17256->timer = v17265;
  int * v17259 = v17256->regs;
  int v17260 = v17259[17];
  int * v17261 = v17256->regs;
  int v17270 = (int)((unsigned int)v17260 >> 14);
  v17261[6] = v17270;
  struct StateT * v17263 = slot_416(v17256);
  return v17263;
}

struct StateT * slot_613(struct StateT * v21136) {
  int v21137 = v21136->timer;
  int v21147 = v21137 + 1;
  v21136->timer = v21147;
  int * v21139 = v21136->regs;
  int v21140 = v21139[11];
  int * v21141 = v21136->regs;
  int v21142 = v21141[9];
  int * v21143 = v21136->regs;
  int v21153 = v21140 | v21142;
  v21143[11] = v21153;
  struct StateT * v21145 = slot_614(v21136);
  return v21145;
}

struct StateT * slot_354(struct StateT * v14444) {
  int v14445 = v14444->timer;
  int v14503 = v14445 + 1;
  v14444->timer = v14503;
  int * v14447 = v14444->regs;
  int v14448 = v14447[2];
  int * v14449 = v14444->cache_keys;
  int v14450 = v14449[0];
  bool v14508 = v14450 == ((int)((unsigned int)(v14448 + 76) >> 2));
  int v14498;
  if (v14508) {
    int * v14451 = v14444->cache_vals;
    int v14452 = v14451[0];
    v14498 = v14452;
  } else {
    int * v14454 = v14444->cache_keys;
    int v14455 = v14454[1];
    bool v14513 = v14455 == ((int)((unsigned int)(v14448 + 76) >> 2));
    int v14496;
    if (v14513) {
      int * v14456 = v14444->cache_vals;
      int v14457 = v14456[1];
      int * v14458 = v14444->cache_keys;
      int * v14459 = v14444->cache_keys;
      int v14460 = v14459[0];
      v14458[1] = v14460;
      int * v14462 = v14444->cache_vals;
      int * v14463 = v14444->cache_vals;
      int v14464 = v14463[0];
      v14462[1] = v14464;
      int * v14466 = v14444->cache_keys;
      int v14522 = (int)((unsigned int)(v14448 + 76) >> 2);
      v14466[0] = v14522;
      int * v14468 = v14444->cache_vals;
      v14468[0] = v14457;
      int v14470 = v14444->timer;
      int v14525 = v14470 + 1;
      v14444->timer = v14525;
      v14496 = v14457;
    } else {
      int * v14473 = v14444->mem;
      int v14527 = (int)((unsigned int)(v14448 + 76) >> 2);
      int v14474 = v14473[v14527];
      int * v14475 = v14444->mem;
      int * v14476 = v14444->cache_keys;
      int v14477 = v14476[1];
      int * v14478 = v14444->cache_vals;
      int v14479 = v14478[1];
      v14475[v14477] = v14479;
      int * v14481 = v14444->cache_keys;
      int * v14482 = v14444->cache_keys;
      int v14483 = v14482[0];
      v14481[1] = v14483;
      int * v14485 = v14444->cache_vals;
      int * v14486 = v14444->cache_vals;
      int v14487 = v14486[0];
      v14485[1] = v14487;
      int * v14489 = v14444->cache_keys;
      v14489[0] = v14527;
      int * v14491 = v14444->cache_vals;
      v14491[0] = v14474;
      int v14493 = v14444->timer;
      int v14542 = v14493 + 100;
      v14444->timer = v14542;
      v14496 = v14474;
    }
    v14498 = v14496;
  }
  int * v14499 = v14444->regs;
  v14499[19] = v14498;
  struct StateT * v14501 = slot_357(v14444);
  return v14501;
}

struct StateT * slot_531(struct StateT * v19499) {
  int v19500 = v19499->timer;
  int v19508 = v19500 + 1;
  v19499->timer = v19508;
  int * v19502 = v19499->regs;
  int v19503 = v19502[15];
  int * v19504 = v19499->regs;
  int v19513 = (int)((unsigned int)v19503 >> 23);
  v19504[20] = v19513;
  struct StateT * v19506 = slot_532(v19499);
  return v19506;
}

struct StateT * slot_115(struct StateT * v5012) {
  int v5013 = v5012->timer;
  int v5021 = v5013 + 1;
  v5012->timer = v5021;
  int * v5015 = v5012->regs;
  int v5016 = v5015[15];
  int * v5017 = v5012->regs;
  int v5026 = (int)((unsigned int)v5016 >> 14);
  v5017[6] = v5026;
  struct StateT * v5019 = slot_116(v5012);
  return v5019;
}

struct StateT * slot_78(struct StateT * v4246) {
  int v4247 = v4246->timer;
  int v4255 = v4247 + 1;
  v4246->timer = v4255;
  int * v4249 = v4246->regs;
  int v4250 = v4249[8];
  int * v4251 = v4246->regs;
  int v4260 = (int)((unsigned int)v4250 >> 23);
  v4251[20] = v4260;
  struct StateT * v4253 = slot_79(v4246);
  return v4253;
}

struct StateT * slot_321(struct StateT * v12056) {
  int v12057 = v12056->timer;
  int v12111 = v12057 + 1;
  v12056->timer = v12111;
  int * v12059 = v12056->regs;
  int v12060 = v12059[10];
  int * v12061 = v12056->regs;
  int v12062 = v12061[13];
  int * v12063 = v12056->cache_keys;
  int v12064 = v12063[0];
  bool v12118 = v12064 == ((int)((unsigned int)(v12060 + 36) >> 2));
  int v12108;
  if (v12118) {
    int * v12065 = v12056->cache_vals;
    v12065[0] = v12062;
    v12108 = v12062;
  } else {
    int * v12068 = v12056->cache_keys;
    int v12069 = v12068[1];
    bool v12123 = v12069 == ((int)((unsigned int)(v12060 + 36) >> 2));
    int v12106;
    if (v12123) {
      int * v12070 = v12056->cache_keys;
      int * v12071 = v12056->cache_keys;
      int v12072 = v12071[0];
      v12070[1] = v12072;
      int * v12074 = v12056->cache_vals;
      int * v12075 = v12056->cache_vals;
      int v12076 = v12075[0];
      v12074[1] = v12076;
      int * v12078 = v12056->cache_keys;
      int v12131 = (int)((unsigned int)(v12060 + 36) >> 2);
      v12078[0] = v12131;
      int * v12080 = v12056->cache_vals;
      v12080[0] = v12062;
      int v12082 = v12056->timer;
      int v12134 = v12082 + 1;
      v12056->timer = v12134;
      v12106 = v12062;
    } else {
      int * v12085 = v12056->mem;
      int * v12086 = v12056->cache_keys;
      int v12087 = v12086[1];
      int * v12088 = v12056->cache_vals;
      int v12089 = v12088[1];
      v12085[v12087] = v12089;
      int * v12091 = v12056->cache_keys;
      int * v12092 = v12056->cache_keys;
      int v12093 = v12092[0];
      v12091[1] = v12093;
      int * v12095 = v12056->cache_vals;
      int * v12096 = v12056->cache_vals;
      int v12097 = v12096[0];
      v12095[1] = v12097;
      int * v12099 = v12056->cache_keys;
      int v12147 = (int)((unsigned int)(v12060 + 36) >> 2);
      v12099[0] = v12147;
      int * v12101 = v12056->cache_vals;
      v12101[0] = v12062;
      int v12103 = v12056->timer;
      int v12150 = v12103 + 100;
      v12056->timer = v12150;
      v12106 = v12062;
    }
    v12108 = v12106;
  }
  struct StateT * v12109 = slot_324(v12056);
  return v12109;
}

struct StateT * slot_317(struct StateT * v11741) {
  int v11742 = v11741->timer;
  int v11796 = v11742 + 1;
  v11741->timer = v11796;
  int * v11744 = v11741->regs;
  int v11745 = v11744[10];
  int * v11746 = v11741->regs;
  int v11747 = v11746[11];
  int * v11748 = v11741->cache_keys;
  int v11749 = v11748[0];
  bool v11803 = v11749 == ((int)((unsigned int)(v11745 + 20) >> 2));
  int v11793;
  if (v11803) {
    int * v11750 = v11741->cache_vals;
    v11750[0] = v11747;
    v11793 = v11747;
  } else {
    int * v11753 = v11741->cache_keys;
    int v11754 = v11753[1];
    bool v11808 = v11754 == ((int)((unsigned int)(v11745 + 20) >> 2));
    int v11791;
    if (v11808) {
      int * v11755 = v11741->cache_keys;
      int * v11756 = v11741->cache_keys;
      int v11757 = v11756[0];
      v11755[1] = v11757;
      int * v11759 = v11741->cache_vals;
      int * v11760 = v11741->cache_vals;
      int v11761 = v11760[0];
      v11759[1] = v11761;
      int * v11763 = v11741->cache_keys;
      int v11816 = (int)((unsigned int)(v11745 + 20) >> 2);
      v11763[0] = v11816;
      int * v11765 = v11741->cache_vals;
      v11765[0] = v11747;
      int v11767 = v11741->timer;
      int v11819 = v11767 + 1;
      v11741->timer = v11819;
      v11791 = v11747;
    } else {
      int * v11770 = v11741->mem;
      int * v11771 = v11741->cache_keys;
      int v11772 = v11771[1];
      int * v11773 = v11741->cache_vals;
      int v11774 = v11773[1];
      v11770[v11772] = v11774;
      int * v11776 = v11741->cache_keys;
      int * v11777 = v11741->cache_keys;
      int v11778 = v11777[0];
      v11776[1] = v11778;
      int * v11780 = v11741->cache_vals;
      int * v11781 = v11741->cache_vals;
      int v11782 = v11781[0];
      v11780[1] = v11782;
      int * v11784 = v11741->cache_keys;
      int v11832 = (int)((unsigned int)(v11745 + 20) >> 2);
      v11784[0] = v11832;
      int * v11786 = v11741->cache_vals;
      v11786[0] = v11747;
      int v11788 = v11741->timer;
      int v11835 = v11788 + 100;
      v11741->timer = v11835;
      v11791 = v11747;
    }
    v11793 = v11791;
  }
  struct StateT * v11794 = slot_320(v11741);
  return v11794;
}

struct StateT * slot_558(struct StateT * v20026) {
  int v20027 = v20026->timer;
  int v20035 = v20027 + 1;
  v20026->timer = v20035;
  int * v20029 = v20026->regs;
  int v20030 = v20029[9];
  int * v20031 = v20026->regs;
  int v20039 = v20030 << 13;
  v20031[9] = v20039;
  struct StateT * v20033 = slot_559(v20026);
  return v20033;
}

struct StateT * slot_205(struct StateT * v6725) {
  int v6726 = v6725->timer;
  int v6734 = v6726 + 1;
  v6725->timer = v6734;
  int * v6728 = v6725->regs;
  int v6729 = v6728[8];
  int * v6730 = v6725->regs;
  int v6738 = v6729 << 18;
  v6730[8] = v6738;
  struct StateT * v6732 = slot_206(v6725);
  return v6732;
}

struct StateT * slot_674(struct StateT * v22546) {
  int v22547 = v22546->timer;
  int v22553 = v22547 + 1;
  v22546->timer = v22553;
  int * v22549 = v22546->regs;
  v22549[6] = 857759744;
  struct StateT * v22551 = slot_675(v22546);
  return v22551;
}

struct StateT * slot_193(struct StateT * v6507) {
  int v6508 = v6507->timer;
  int v6518 = v6508 + 1;
  v6507->timer = v6518;
  int * v6510 = v6507->regs;
  int v6511 = v6510[13];
  int * v6512 = v6507->regs;
  int v6513 = v6512[26];
  int * v6514 = v6507->regs;
  int v6525 = v6511 + v6513;
  v6514[6] = v6525;
  struct StateT * v6516 = slot_194(v6507);
  return v6516;
}

struct StateT * slot_554(struct StateT * v19956) {
  int v19957 = v19956->timer;
  int v19965 = v19957 + 1;
  v19956->timer = v19965;
  int * v19959 = v19956->regs;
  int v19960 = v19959[8];
  int * v19961 = v19956->regs;
  int v19970 = (int)((unsigned int)v19960 >> 19);
  v19961[20] = v19970;
  struct StateT * v19963 = slot_555(v19956);
  return v19963;
}

struct StateT * slot_375(struct StateT * v16056) {
  int v16057 = v16056->timer;
  int v16115 = v16057 + 1;
  v16056->timer = v16115;
  int * v16059 = v16056->regs;
  int v16060 = v16059[2];
  int * v16061 = v16056->cache_keys;
  int v16062 = v16061[0];
  bool v16120 = v16062 == ((int)((unsigned int)(v16060 + 48) >> 2));
  int v16110;
  if (v16120) {
    int * v16063 = v16056->cache_vals;
    int v16064 = v16063[0];
    v16110 = v16064;
  } else {
    int * v16066 = v16056->cache_keys;
    int v16067 = v16066[1];
    bool v16125 = v16067 == ((int)((unsigned int)(v16060 + 48) >> 2));
    int v16108;
    if (v16125) {
      int * v16068 = v16056->cache_vals;
      int v16069 = v16068[1];
      int * v16070 = v16056->cache_keys;
      int * v16071 = v16056->cache_keys;
      int v16072 = v16071[0];
      v16070[1] = v16072;
      int * v16074 = v16056->cache_vals;
      int * v16075 = v16056->cache_vals;
      int v16076 = v16075[0];
      v16074[1] = v16076;
      int * v16078 = v16056->cache_keys;
      int v16134 = (int)((unsigned int)(v16060 + 48) >> 2);
      v16078[0] = v16134;
      int * v16080 = v16056->cache_vals;
      v16080[0] = v16069;
      int v16082 = v16056->timer;
      int v16137 = v16082 + 1;
      v16056->timer = v16137;
      v16108 = v16069;
    } else {
      int * v16085 = v16056->mem;
      int v16139 = (int)((unsigned int)(v16060 + 48) >> 2);
      int v16086 = v16085[v16139];
      int * v16087 = v16056->mem;
      int * v16088 = v16056->cache_keys;
      int v16089 = v16088[1];
      int * v16090 = v16056->cache_vals;
      int v16091 = v16090[1];
      v16087[v16089] = v16091;
      int * v16093 = v16056->cache_keys;
      int * v16094 = v16056->cache_keys;
      int v16095 = v16094[0];
      v16093[1] = v16095;
      int * v16097 = v16056->cache_vals;
      int * v16098 = v16056->cache_vals;
      int v16099 = v16098[0];
      v16097[1] = v16099;
      int * v16101 = v16056->cache_keys;
      v16101[0] = v16139;
      int * v16103 = v16056->cache_vals;
      v16103[0] = v16086;
      int v16105 = v16056->timer;
      int v16154 = v16105 + 100;
      v16056->timer = v16154;
      v16108 = v16086;
    }
    v16110 = v16108;
  }
  int * v16111 = v16056->regs;
  v16111[26] = v16110;
  struct StateT * v16113 = slot_378(v16056);
  return v16113;
}

struct StateT * slot_650(struct StateT * v21834) {
  int v21835 = v21834->timer;
  int v21845 = v21835 + 1;
  v21834->timer = v21845;
  int * v21837 = v21834->regs;
  int v21838 = v21837[1];
  int * v21839 = v21834->regs;
  int v21840 = v21839[24];
  int * v21841 = v21834->regs;
  int v21852 = v21838 + v21840;
  v21841[8] = v21852;
  struct StateT * v21843 = slot_651(v21834);
  return v21843;
}

struct StateT * slot_637(struct StateT * v21585) {
  int v21586 = v21585->timer;
  int v21594 = v21586 + 1;
  v21585->timer = v21594;
  int * v21588 = v21585->regs;
  int v21589 = v21588[6];
  int * v21590 = v21585->regs;
  int v21599 = (int)((unsigned int)v21589 >> 19);
  v21590[9] = v21599;
  struct StateT * v21592 = slot_638(v21585);
  return v21592;
}

struct StateT * slot_331(struct StateT * v12795) {
  int v12796 = v12795->timer;
  int v12804 = v12796 + 1;
  v12795->timer = v12804;
  int * v12798 = v12795->regs;
  int v12799 = v12798[8];
  int * v12800 = v12795->regs;
  int v12809 = (int)((unsigned int)v12799 >> 23);
  v12800[20] = v12809;
  struct StateT * v12802 = slot_334(v12795);
  return v12802;
}

struct StateT * slot_676(struct StateT * v22664) {
  int v22665 = v22664->timer;
  int v22675 = v22665 + 1;
  v22664->timer = v22675;
  int * v22667 = v22664->regs;
  int v22668 = v22667[5];
  int * v22669 = v22664->regs;
  int v22670 = v22669[7];
  int * v22671 = v22664->regs;
  int v22681 = v22668 + v22670;
  v22671[5] = v22681;
  struct StateT * v22673 = slot_677(v22664);
  return v22673;
}

struct StateT * slot_380(struct StateT * v16413) {
  int v16414 = v16413->timer;
  int v16472 = v16414 + 1;
  v16413->timer = v16472;
  int * v16416 = v16413->regs;
  int v16417 = v16416[2];
  int * v16418 = v16413->cache_keys;
  int v16419 = v16418[0];
  bool v16477 = v16419 == ((int)((unsigned int)(v16417 + 52) >> 2));
  int v16467;
  if (v16477) {
    int * v16420 = v16413->cache_vals;
    int v16421 = v16420[0];
    v16467 = v16421;
  } else {
    int * v16423 = v16413->cache_keys;
    int v16424 = v16423[1];
    bool v16482 = v16424 == ((int)((unsigned int)(v16417 + 52) >> 2));
    int v16465;
    if (v16482) {
      int * v16425 = v16413->cache_vals;
      int v16426 = v16425[1];
      int * v16427 = v16413->cache_keys;
      int * v16428 = v16413->cache_keys;
      int v16429 = v16428[0];
      v16427[1] = v16429;
      int * v16431 = v16413->cache_vals;
      int * v16432 = v16413->cache_vals;
      int v16433 = v16432[0];
      v16431[1] = v16433;
      int * v16435 = v16413->cache_keys;
      int v16491 = (int)((unsigned int)(v16417 + 52) >> 2);
      v16435[0] = v16491;
      int * v16437 = v16413->cache_vals;
      v16437[0] = v16426;
      int v16439 = v16413->timer;
      int v16494 = v16439 + 1;
      v16413->timer = v16494;
      v16465 = v16426;
    } else {
      int * v16442 = v16413->mem;
      int v16496 = (int)((unsigned int)(v16417 + 52) >> 2);
      int v16443 = v16442[v16496];
      int * v16444 = v16413->mem;
      int * v16445 = v16413->cache_keys;
      int v16446 = v16445[1];
      int * v16447 = v16413->cache_vals;
      int v16448 = v16447[1];
      v16444[v16446] = v16448;
      int * v16450 = v16413->cache_keys;
      int * v16451 = v16413->cache_keys;
      int v16452 = v16451[0];
      v16450[1] = v16452;
      int * v16454 = v16413->cache_vals;
      int * v16455 = v16413->cache_vals;
      int v16456 = v16455[0];
      v16454[1] = v16456;
      int * v16458 = v16413->cache_keys;
      v16458[0] = v16496;
      int * v16460 = v16413->cache_vals;
      v16460[0] = v16443;
      int v16462 = v16413->timer;
      int v16511 = v16462 + 100;
      v16413->timer = v16511;
      v16465 = v16443;
    }
    v16467 = v16465;
  }
  int * v16468 = v16413->regs;
  v16468[25] = v16467;
  struct StateT * v16470 = slot_383(v16413);
  return v16470;
}

struct StateT * slot_636(struct StateT * v21565) {
  int v21566 = v21565->timer;
  int v21576 = v21566 + 1;
  v21565->timer = v21576;
  int * v21568 = v21565->regs;
  int v21569 = v21568[15];
  int * v21570 = v21565->regs;
  int v21571 = v21570[9];
  int * v21572 = v21565->regs;
  int v21582 = v21569 | v21571;
  v21572[15] = v21582;
  struct StateT * v21574 = slot_637(v21565);
  return v21574;
}

struct StateT * slot_412(struct StateT * v17203) {
  int v17204 = v17203->timer;
  int v17212 = v17204 + 1;
  v17203->timer = v17212;
  int * v17206 = v17203->regs;
  int v17207 = v17206[16];
  int * v17208 = v17203->regs;
  int v17217 = (int)((unsigned int)v17207 >> 14);
  v17208[6] = v17217;
  struct StateT * v17210 = slot_413(v17203);
  return v17210;
}

struct StateT * slot_381(struct StateT * v16518) {
  int v16519 = v16518->timer;
  int v16527 = v16519 + 1;
  v16518->timer = v16527;
  int * v16521 = v16518->regs;
  int v16522 = v16521[2];
  int * v16523 = v16518->regs;
  int v16531 = v16522 + 96;
  v16523[2] = v16531;
  struct StateT * v16525 = slot_384(v16518);
  return v16525;
}

struct StateT * slot_478(struct StateT * v18442) {
  int v18443 = v18442->timer;
  int v18451 = v18443 + 1;
  v18442->timer = v18451;
  int * v18445 = v18442->regs;
  int v18446 = v18445[8];
  int * v18447 = v18442->regs;
  int v18456 = (int)((unsigned int)v18446 >> 19);
  v18447[9] = v18456;
  struct StateT * v18449 = slot_479(v18442);
  return v18449;
}

struct StateT * slot_646(struct StateT * v21751) {
  int v21752 = v21751->timer;
  int v21762 = v21752 + 1;
  v21751->timer = v21762;
  int * v21754 = v21751->regs;
  int v21755 = v21754[1];
  int * v21756 = v21751->regs;
  int v21757 = v21756[8];
  int * v21758 = v21751->regs;
  int v21768 = v21755 ^ v21757;
  v21758[1] = v21768;
  struct StateT * v21760 = slot_647(v21751);
  return v21760;
}

struct StateT * slot_627(struct StateT * v21395) {
  int v21396 = v21395->timer;
  int v21406 = v21396 + 1;
  v21395->timer = v21406;
  int * v21398 = v21395->regs;
  int v21399 = v21398[27];
  int * v21400 = v21395->regs;
  int v21401 = v21400[23];
  int * v21402 = v21395->regs;
  int v21413 = v21399 + v21401;
  v21402[11] = v21413;
  struct StateT * v21404 = slot_628(v21395);
  return v21404;
}

struct StateT * slot_675(struct StateT * v22559) {
  int v22560 = v22559->timer;
  int v22618 = v22560 + 1;
  v22559->timer = v22618;
  int * v22562 = v22559->regs;
  int v22563 = v22562[2];
  int * v22564 = v22559->cache_keys;
  int v22565 = v22564[0];
  bool v22623 = v22565 == ((int)((unsigned int)(v22563 + 12) >> 2));
  int v22613;
  if (v22623) {
    int * v22566 = v22559->cache_vals;
    int v22567 = v22566[0];
    v22613 = v22567;
  } else {
    int * v22569 = v22559->cache_keys;
    int v22570 = v22569[1];
    bool v22628 = v22570 == ((int)((unsigned int)(v22563 + 12) >> 2));
    int v22611;
    if (v22628) {
      int * v22571 = v22559->cache_vals;
      int v22572 = v22571[1];
      int * v22573 = v22559->cache_keys;
      int * v22574 = v22559->cache_keys;
      int v22575 = v22574[0];
      v22573[1] = v22575;
      int * v22577 = v22559->cache_vals;
      int * v22578 = v22559->cache_vals;
      int v22579 = v22578[0];
      v22577[1] = v22579;
      int * v22581 = v22559->cache_keys;
      int v22637 = (int)((unsigned int)(v22563 + 12) >> 2);
      v22581[0] = v22637;
      int * v22583 = v22559->cache_vals;
      v22583[0] = v22572;
      int v22585 = v22559->timer;
      int v22640 = v22585 + 1;
      v22559->timer = v22640;
      v22611 = v22572;
    } else {
      int * v22588 = v22559->mem;
      int v22642 = (int)((unsigned int)(v22563 + 12) >> 2);
      int v22589 = v22588[v22642];
      int * v22590 = v22559->mem;
      int * v22591 = v22559->cache_keys;
      int v22592 = v22591[1];
      int * v22593 = v22559->cache_vals;
      int v22594 = v22593[1];
      v22590[v22592] = v22594;
      int * v22596 = v22559->cache_keys;
      int * v22597 = v22559->cache_keys;
      int v22598 = v22597[0];
      v22596[1] = v22598;
      int * v22600 = v22559->cache_vals;
      int * v22601 = v22559->cache_vals;
      int v22602 = v22601[0];
      v22600[1] = v22602;
      int * v22604 = v22559->cache_keys;
      v22604[0] = v22642;
      int * v22606 = v22559->cache_vals;
      v22606[0] = v22589;
      int v22608 = v22559->timer;
      int v22657 = v22608 + 100;
      v22559->timer = v22657;
      v22611 = v22589;
    }
    v22613 = v22611;
  }
  int * v22614 = v22559->regs;
  v22614[7] = v22613;
  struct StateT * v22616 = slot_676(v22559);
  return v22616;
}

struct StateT * slot_246(struct StateT * v8694) {
  int v8695 = v8694->timer;
  int v8701 = v8695 + 1;
  v8694->timer = v8701;
  int * v8697 = v8694->regs;
  v8697[7] = 2036477952;
  struct StateT * v8699 = slot_248(v8694);
  return v8699;
}

struct StateT * slot_210(struct StateT * v6822) {
  int v6823 = v6822->timer;
  int v6833 = v6823 + 1;
  v6822->timer = v6833;
  int * v6825 = v6822->regs;
  int v6826 = v6825[22];
  int * v6827 = v6822->regs;
  int v6828 = v6827[8];
  int * v6829 = v6822->regs;
  int v6839 = v6826 ^ v6828;
  v6829[22] = v6839;
  struct StateT * v6831 = slot_211(v6822);
  return v6831;
}

struct StateT * slot_472(struct StateT * v18336) {
  int v18337 = v18336->timer;
  int v18345 = v18337 + 1;
  v18336->timer = v18345;
  int * v18339 = v18336->regs;
  int v18340 = v18339[15];
  int * v18341 = v18336->regs;
  int v18350 = (int)((unsigned int)v18340 >> 19);
  v18341[9] = v18350;
  struct StateT * v18343 = slot_473(v18336);
  return v18343;
}

struct StateT * slot_657(struct StateT * v21961) {
  int v21962 = v21961->timer;
  int v21970 = v21962 + 1;
  v21961->timer = v21970;
  int * v21964 = v21961->regs;
  int v21965 = v21964[6];
  int * v21966 = v21961->regs;
  int v21975 = (int)((unsigned int)v21965 >> 14);
  v21966[9] = v21975;
  struct StateT * v21968 = slot_658(v21961);
  return v21968;
}

struct StateT * slot_284(struct StateT * v10079) {
  int v10080 = v10079->timer;
  int v10088 = v10080 + 1;
  v10079->timer = v10088;
  int * v10082 = v10079->regs;
  int v10083 = v10082[7];
  int * v10084 = v10079->regs;
  int v10092 = v10083 + -718;
  v10084[7] = v10092;
  struct StateT * v10086 = slot_287(v10079);
  return v10086;
}

struct StateT * slot_52(struct StateT * v3698) {
  int * v3699 = v3698->saved_regs;
  int * v3700 = v3698->regs;
  int v3701 = v3700[20];
  v3699[20] = v3701;
  int v3703 = v3698->timer;
  int v3717 = v3703 + 1;
  v3698->timer = v3717;
  int * v3705 = v3698->regs;
  int v3706 = v3705[11];
  int * v3707 = v3698->regs;
  int v3708 = v3707[23];
  int * v3709 = v3698->regs;
  int v3723 = v3706 + v3708;
  v3709[20] = v3723;
  struct StateT * v3711 = slot_53(v3698);
  return v3711;
}

struct StateT * slot_83(struct StateT * v4332) {
  int v4333 = v4332->timer;
  int v4343 = v4333 + 1;
  v4332->timer = v4343;
  int * v4335 = v4332->regs;
  int v4336 = v4335[9];
  int * v4337 = v4332->regs;
  int v4338 = v4337[20];
  int * v4339 = v4332->regs;
  int v4349 = v4336 | v4338;
  v4339[9] = v4349;
  struct StateT * v4341 = slot_84(v4332);
  return v4341;
}

struct StateT * slot_209(struct StateT * v6802) {
  int v6803 = v6802->timer;
  int v6813 = v6803 + 1;
  v6802->timer = v6813;
  int * v6805 = v6802->regs;
  int v6806 = v6805[19];
  int * v6807 = v6802->regs;
  int v6808 = v6807[6];
  int * v6809 = v6802->regs;
  int v6819 = v6806 ^ v6808;
  v6809[19] = v6819;
  struct StateT * v6811 = slot_210(v6802);
  return v6811;
}

struct StateT * slot_420(struct StateT * v17342) {
  int v17343 = v17342->timer;
  int v17353 = v17343 + 1;
  v17342->timer = v17353;
  int * v17345 = v17342->regs;
  int v17346 = v17345[5];
  int * v17347 = v17342->regs;
  int v17348 = v17347[6];
  int * v17349 = v17342->regs;
  int v17359 = v17346 | v17348;
  v17349[5] = v17359;
  struct StateT * v17351 = slot_421(v17342);
  return v17351;
}

struct StateT * slot_3(struct StateT * v213) {
  int v214 = v213->timer;
  int v268 = v214 + 1;
  v213->timer = v268;
  int * v216 = v213->regs;
  int v217 = v216[2];
  int * v218 = v213->regs;
  int v219 = v218[9];
  int * v220 = v213->cache_keys;
  int v221 = v220[0];
  bool v275 = v221 == ((int)((unsigned int)(v217 + 84) >> 2));
  int v265;
  if (v275) {
    int * v222 = v213->cache_vals;
    v222[0] = v219;
    v265 = v219;
  } else {
    int * v225 = v213->cache_keys;
    int v226 = v225[1];
    bool v280 = v226 == ((int)((unsigned int)(v217 + 84) >> 2));
    int v263;
    if (v280) {
      int * v227 = v213->cache_keys;
      int * v228 = v213->cache_keys;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v213->cache_vals;
      int * v232 = v213->cache_vals;
      int v233 = v232[0];
      v231[1] = v233;
      int * v235 = v213->cache_keys;
      int v288 = (int)((unsigned int)(v217 + 84) >> 2);
      v235[0] = v288;
      int * v237 = v213->cache_vals;
      v237[0] = v219;
      int v239 = v213->timer;
      int v291 = v239 + 1;
      v213->timer = v291;
      v263 = v219;
    } else {
      int * v242 = v213->mem;
      int * v243 = v213->cache_keys;
      int v244 = v243[1];
      int * v245 = v213->cache_vals;
      int v246 = v245[1];
      v242[v244] = v246;
      int * v248 = v213->cache_keys;
      int * v249 = v213->cache_keys;
      int v250 = v249[0];
      v248[1] = v250;
      int * v252 = v213->cache_vals;
      int * v253 = v213->cache_vals;
      int v254 = v253[0];
      v252[1] = v254;
      int * v256 = v213->cache_keys;
      int v304 = (int)((unsigned int)(v217 + 84) >> 2);
      v256[0] = v304;
      int * v258 = v213->cache_vals;
      v258[0] = v219;
      int v260 = v213->timer;
      int v307 = v260 + 100;
      v213->timer = v307;
      v263 = v219;
    }
    v265 = v263;
  }
  struct StateT * v266 = slot_4(v213);
  return v266;
}

struct StateT * slot_73(struct StateT * v4151) {
  int v4152 = v4151->timer;
  int v4162 = v4152 + 1;
  v4151->timer = v4162;
  int * v4154 = v4151->regs;
  int v4155 = v4154[1];
  int * v4156 = v4151->regs;
  int v4157 = v4156[19];
  int * v4158 = v4151->regs;
  int v4169 = v4155 + v4157;
  v4158[9] = v4169;
  struct StateT * v4160 = slot_74(v4151);
  return v4160;
}

struct StateT * slot_270(struct StateT * v9844) {
  int v9845 = v9844->timer;
  int v9853 = v9845 + 1;
  v9844->timer = v9853;
  int * v9847 = v9844->regs;
  int v9848 = v9847[15];
  int * v9849 = v9844->regs;
  int v9857 = v9848 + -1947;
  v9849[15] = v9857;
  struct StateT * v9851 = slot_273(v9844);
  return v9851;
}

struct StateT * slot_198(struct StateT * v6602) {
  int v6603 = v6602->timer;
  int v6611 = v6603 + 1;
  v6602->timer = v6611;
  int * v6605 = v6602->regs;
  int v6606 = v6605[15];
  int * v6607 = v6602->regs;
  int v6616 = (int)((unsigned int)v6606 >> 14);
  v6607[9] = v6616;
  struct StateT * v6609 = slot_199(v6602);
  return v6609;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v73 = v19 + 1;
  v18->timer = v73;
  int * v21 = v18->regs;
  int v22 = v21[2];
  int * v23 = v18->regs;
  int v24 = v23[1];
  int * v25 = v18->cache_keys;
  int v26 = v25[0];
  bool v80 = v26 == ((int)((unsigned int)(v22 + 92) >> 2));
  int v70;
  if (v80) {
    int * v27 = v18->cache_vals;
    v27[0] = v24;
    v70 = v24;
  } else {
    int * v30 = v18->cache_keys;
    int v31 = v30[1];
    bool v84 = v31 == ((int)((unsigned int)(v22 + 92) >> 2));
    int v68;
    if (v84) {
      int * v32 = v18->cache_keys;
      int * v33 = v18->cache_keys;
      int v34 = v33[0];
      v32[1] = v34;
      int * v36 = v18->cache_vals;
      int * v37 = v18->cache_vals;
      int v38 = v37[0];
      v36[1] = v38;
      int * v40 = v18->cache_keys;
      int v92 = (int)((unsigned int)(v22 + 92) >> 2);
      v40[0] = v92;
      int * v42 = v18->cache_vals;
      v42[0] = v24;
      int v44 = v18->timer;
      int v95 = v44 + 1;
      v18->timer = v95;
      v68 = v24;
    } else {
      int * v47 = v18->mem;
      int * v48 = v18->cache_keys;
      int v49 = v48[1];
      int * v50 = v18->cache_vals;
      int v51 = v50[1];
      v47[v49] = v51;
      int * v53 = v18->cache_keys;
      int * v54 = v18->cache_keys;
      int v55 = v54[0];
      v53[1] = v55;
      int * v57 = v18->cache_vals;
      int * v58 = v18->cache_vals;
      int v59 = v58[0];
      v57[1] = v59;
      int * v61 = v18->cache_keys;
      int v108 = (int)((unsigned int)(v22 + 92) >> 2);
      v61[0] = v108;
      int * v63 = v18->cache_vals;
      v63[0] = v24;
      int v65 = v18->timer;
      int v111 = v65 + 100;
      v18->timer = v111;
      v68 = v24;
    }
    v70 = v68;
  }
  struct StateT * v71 = slot_2(v18);
  return v71;
}

struct StateT * slot_187(struct StateT * v6385) {
  int v6386 = v6385->timer;
  int v6396 = v6386 + 1;
  v6385->timer = v6396;
  int * v6388 = v6385->regs;
  int v6389 = v6388[14];
  int * v6390 = v6385->regs;
  int v6391 = v6390[11];
  int * v6392 = v6385->regs;
  int v6402 = v6389 ^ v6391;
  v6392[14] = v6402;
  struct StateT * v6394 = slot_188(v6385);
  return v6394;
}

struct StateT * slot_446(struct StateT * v17844) {
  int v17845 = v17844->timer;
  int v17855 = v17845 + 1;
  v17844->timer = v17855;
  int * v17847 = v17844->regs;
  int v17848 = v17847[5];
  int * v17849 = v17844->regs;
  int v17850 = v17849[20];
  int * v17851 = v17844->regs;
  int v17862 = v17848 + v17850;
  v17851[15] = v17862;
  struct StateT * v17853 = slot_447(v17844);
  return v17853;
}

struct StateT * slot_182(struct StateT * v6296) {
  int v6297 = v6296->timer;
  int v6305 = v6297 + 1;
  v6296->timer = v6305;
  int * v6299 = v6296->regs;
  int v6300 = v6299[6];
  int * v6301 = v6296->regs;
  int v6309 = v6300 << 13;
  v6301[6] = v6309;
  struct StateT * v6303 = slot_183(v6296);
  return v6303;
}

struct StateT * slot_361(struct StateT * v15009) {
  int v15010 = v15009->timer;
  int v15020 = v15010 + 1;
  v15009->timer = v15020;
  int * v15012 = v15009->regs;
  int v15013 = v15012[24];
  int * v15014 = v15009->regs;
  int v15015 = v15014[8];
  int * v15016 = v15009->regs;
  int v15026 = v15013 ^ v15015;
  v15016[24] = v15026;
  struct StateT * v15018 = slot_364(v15009);
  return v15018;
}

struct StateT * slot_38(struct StateT * v2892) {
  int v2893 = v2892->timer;
  int v2947 = v2893 + 1;
  v2892->timer = v2947;
  int * v2895 = v2892->regs;
  int v2896 = v2895[2];
  int * v2897 = v2892->regs;
  int v2898 = v2897[5];
  int * v2899 = v2892->cache_keys;
  int v2900 = v2899[0];
  bool v2954 = v2900 == ((int)((unsigned int)(v2896 + 12) >> 2));
  int v2944;
  if (v2954) {
    int * v2901 = v2892->cache_vals;
    v2901[0] = v2898;
    v2944 = v2898;
  } else {
    int * v2904 = v2892->cache_keys;
    int v2905 = v2904[1];
    bool v2959 = v2905 == ((int)((unsigned int)(v2896 + 12) >> 2));
    int v2942;
    if (v2959) {
      int * v2906 = v2892->cache_keys;
      int * v2907 = v2892->cache_keys;
      int v2908 = v2907[0];
      v2906[1] = v2908;
      int * v2910 = v2892->cache_vals;
      int * v2911 = v2892->cache_vals;
      int v2912 = v2911[0];
      v2910[1] = v2912;
      int * v2914 = v2892->cache_keys;
      int v2967 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2914[0] = v2967;
      int * v2916 = v2892->cache_vals;
      v2916[0] = v2898;
      int v2918 = v2892->timer;
      int v2970 = v2918 + 1;
      v2892->timer = v2970;
      v2942 = v2898;
    } else {
      int * v2921 = v2892->mem;
      int * v2922 = v2892->cache_keys;
      int v2923 = v2922[1];
      int * v2924 = v2892->cache_vals;
      int v2925 = v2924[1];
      v2921[v2923] = v2925;
      int * v2927 = v2892->cache_keys;
      int * v2928 = v2892->cache_keys;
      int v2929 = v2928[0];
      v2927[1] = v2929;
      int * v2931 = v2892->cache_vals;
      int * v2932 = v2892->cache_vals;
      int v2933 = v2932[0];
      v2931[1] = v2933;
      int * v2935 = v2892->cache_keys;
      int v2983 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2935[0] = v2983;
      int * v2937 = v2892->cache_vals;
      v2937[0] = v2898;
      int v2939 = v2892->timer;
      int v2986 = v2939 + 100;
      v2892->timer = v2986;
      v2942 = v2898;
    }
    v2944 = v2942;
  }
  struct StateT * v2945 = slot_39(v2892);
  return v2945;
}

struct StateT * slot_178(struct StateT * v6226) {
  int v6227 = v6226->timer;
  int v6235 = v6227 + 1;
  v6226->timer = v6235;
  int * v6229 = v6226->regs;
  int v6230 = v6229[15];
  int * v6231 = v6226->regs;
  int v6240 = (int)((unsigned int)v6230 >> 19);
  v6231[9] = v6240;
  struct StateT * v6233 = slot_179(v6226);
  return v6233;
}

struct StateT * slot_98(struct StateT * v4650) {
  int v4651 = v4650->timer;
  int v4659 = v4651 + 1;
  v4650->timer = v4659;
  int * v4653 = v4650->regs;
  int v4654 = v4653[8];
  int * v4655 = v4650->regs;
  int v4664 = (int)((unsigned int)v4654 >> 19);
  v4655[20] = v4664;
  struct StateT * v4657 = slot_99(v4650);
  return v4657;
}

struct StateT * slot_159(struct StateT * v5867) {
  int v5868 = v5867->timer;
  int v5876 = v5868 + 1;
  v5867->timer = v5876;
  int * v5870 = v5867->regs;
  int v5871 = v5870[15];
  int * v5872 = v5867->regs;
  int v5880 = v5871 << 9;
  v5872[15] = v5880;
  struct StateT * v5874 = slot_160(v5867);
  return v5874;
}

struct StateT * slot_510(struct StateT * v19060) {
  int * v19061 = v19060->saved_regs;
  int * v19062 = v19060->regs;
  int v19063 = v19062[8];
  v19061[8] = v19063;
  int v19065 = v19060->timer;
  int v19079 = v19065 + 1;
  v19060->timer = v19079;
  int * v19067 = v19060->regs;
  int v19068 = v19067[22];
  int * v19069 = v19060->regs;
  int v19070 = v19069[17];
  int * v19071 = v19060->regs;
  int v19085 = v19068 + v19070;
  v19071[8] = v19085;
  struct StateT * v19073 = slot_511(v19060);
  return v19073;
}

struct StateT * slot_459(struct StateT * v18083) {
  int v18084 = v18083->timer;
  int v18092 = v18084 + 1;
  v18083->timer = v18092;
  int * v18086 = v18083->regs;
  int v18087 = v18086[8];
  int * v18088 = v18083->regs;
  int v18096 = v18087 << 9;
  v18088[8] = v18096;
  struct StateT * v18090 = slot_460(v18083);
  return v18090;
}

struct StateT * slot_404(struct StateT * v17045) {
  int v17046 = v17045->timer;
  int v17056 = v17046 + 1;
  v17045->timer = v17056;
  int * v17048 = v17045->regs;
  int v17049 = v17048[17];
  int * v17050 = v17045->regs;
  int v17051 = v17050[6];
  int * v17052 = v17045->regs;
  int v17063 = v17049 ^ v17051;
  v17052[8] = v17063;
  struct StateT * v17054 = slot_405(v17045);
  return v17054;
}

struct StateT * slot_46(struct StateT * v3513) {
  int v3514 = v3513->timer;
  int v3522 = v3514 + 1;
  v3513->timer = v3522;
  int * v3516 = v3513->regs;
  int v3517 = v3516[28];
  int * v3518 = v3513->regs;
  v3518[27] = v3517;
  struct StateT * v3520 = slot_47(v3513);
  return v3520;
}

struct StateT * slot_212(struct StateT * v6865) {
  int * v6866 = v6865->regs;
  int v6867 = v6866[31];
  bool v6970 = (v6867 ^ -2147483648) < -2147483648;
  struct StateT * v6966;
  if (v6970) {
    int v6868 = v6865->timer;
    int v6971 = v6868 + 15;
    v6865->timer = v6971;
    int * v6870 = v6865->saved_regs;
    int v6871 = v6870[15];
    int * v6872 = v6865->regs;
    v6872[15] = v6871;
    int * v6874 = v6865->saved_regs;
    int v6875 = v6874[20];
    int * v6876 = v6865->regs;
    v6876[20] = v6875;
    int * v6878 = v6865->saved_regs;
    int v6879 = v6878[18];
    int * v6880 = v6865->regs;
    v6880[18] = v6879;
    int * v6882 = v6865->saved_regs;
    int v6883 = v6882[8];
    int * v6884 = v6865->regs;
    v6884[8] = v6883;
    int * v6886 = v6865->saved_regs;
    int v6887 = v6886[9];
    int * v6888 = v6865->regs;
    v6888[9] = v6887;
    int * v6890 = v6865->saved_regs;
    int v6891 = v6890[12];
    int * v6892 = v6865->regs;
    v6892[12] = v6891;
    int * v6894 = v6865->saved_regs;
    int v6895 = v6894[13];
    int * v6896 = v6865->regs;
    v6896[13] = v6895;
    int * v6898 = v6865->saved_regs;
    int v6899 = v6898[1];
    int * v6900 = v6865->regs;
    v6900[1] = v6899;
    int * v6902 = v6865->saved_regs;
    int v6903 = v6902[14];
    int * v6904 = v6865->regs;
    v6904[14] = v6903;
    int * v6906 = v6865->saved_regs;
    int v6907 = v6906[26];
    int * v6908 = v6865->regs;
    v6908[26] = v6907;
    int * v6910 = v6865->saved_regs;
    int v6911 = v6910[24];
    int * v6912 = v6865->regs;
    v6912[24] = v6911;
    int * v6914 = v6865->saved_regs;
    int v6915 = v6914[27];
    int * v6916 = v6865->regs;
    v6916[27] = v6915;
    int * v6918 = v6865->saved_regs;
    int v6919 = v6918[25];
    int * v6920 = v6865->regs;
    v6920[25] = v6919;
    int * v6922 = v6865->saved_regs;
    int v6923 = v6922[6];
    int * v6924 = v6865->regs;
    v6924[6] = v6923;
    int * v6926 = v6865->saved_regs;
    int v6927 = v6926[23];
    int * v6928 = v6865->regs;
    v6928[23] = v6927;
    int * v6930 = v6865->saved_regs;
    int v6931 = v6930[16];
    int * v6932 = v6865->regs;
    v6932[16] = v6931;
    int * v6934 = v6865->saved_regs;
    int v6935 = v6934[17];
    int * v6936 = v6865->regs;
    v6936[17] = v6935;
    int * v6938 = v6865->saved_regs;
    int v6939 = v6938[5];
    int * v6940 = v6865->regs;
    v6940[5] = v6939;
    int * v6942 = v6865->saved_regs;
    int v6943 = v6942[21];
    int * v6944 = v6865->regs;
    v6944[21] = v6943;
    int * v6946 = v6865->saved_regs;
    int v6947 = v6946[19];
    int * v6948 = v6865->regs;
    v6948[19] = v6947;
    int * v6950 = v6865->saved_regs;
    int v6951 = v6950[22];
    int * v6952 = v6865->regs;
    v6952[22] = v6951;
    int * v6954 = v6865->saved_regs;
    int v6955 = v6954[11];
    int * v6956 = v6865->regs;
    v6956[11] = v6955;
    int * v6958 = v6865->saved_regs;
    int v6959 = v6958[30];
    int * v6960 = v6865->regs;
    v6960[30] = v6959;
    struct StateT * v6962 = slot_213(v6865);
    v6966 = v6962;
  } else {
    struct StateT * v6964 = slot_214(v6865);
    v6966 = v6964;
  }
  return v6966;
}

struct StateT * slot_682(struct StateT * v23039) {
  int v23040 = v23039->timer;
  int v23050 = v23040 + 1;
  v23039->timer = v23050;
  int * v23042 = v23039->regs;
  int v23043 = v23042[13];
  int * v23044 = v23039->regs;
  int v23045 = v23044[7];
  int * v23046 = v23039->regs;
  int v23056 = v23043 + v23045;
  v23046[13] = v23056;
  struct StateT * v23048 = slot_683(v23039);
  return v23048;
}

struct StateT * slot_132(struct StateT * v5347) {
  int * v5348 = v5347->saved_regs;
  int * v5349 = v5347->regs;
  int v5350 = v5349[11];
  v5348[11] = v5350;
  int v5352 = v5347->timer;
  int v5366 = v5352 + 1;
  v5347->timer = v5366;
  int * v5354 = v5347->regs;
  int v5355 = v5354[20];
  int * v5356 = v5347->regs;
  int v5357 = v5356[12];
  int * v5358 = v5347->regs;
  int v5372 = v5355 + v5357;
  v5358[11] = v5372;
  struct StateT * v5360 = slot_133(v5347);
  return v5360;
}

struct StateT * slot_313(struct StateT * v11503) {
  int v11504 = v11503->timer;
  int v11514 = v11504 + 1;
  v11503->timer = v11514;
  int * v11506 = v11503->regs;
  int v11507 = v11506[13];
  int * v11508 = v11503->regs;
  int v11509 = v11508[11];
  int * v11510 = v11503->regs;
  int v11521 = v11507 + v11509;
  v11510[8] = v11521;
  struct StateT * v11512 = slot_316(v11503);
  return v11512;
}

struct StateT * slot_553(struct StateT * v19936) {
  int v19937 = v19936->timer;
  int v19947 = v19937 + 1;
  v19936->timer = v19947;
  int * v19939 = v19936->regs;
  int v19940 = v19939[15];
  int * v19941 = v19936->regs;
  int v19942 = v19941[20];
  int * v19943 = v19936->regs;
  int v19953 = v19940 | v19942;
  v19943[15] = v19953;
  struct StateT * v19945 = slot_554(v19936);
  return v19945;
}

struct StateT * slot_211(struct StateT * v6842) {
  int * v6843 = v6842->saved_regs;
  int * v6844 = v6842->regs;
  int v6845 = v6844[30];
  v6843[30] = v6845;
  int v6847 = v6842->timer;
  int v6859 = v6847 + 1;
  v6842->timer = v6859;
  int * v6849 = v6842->regs;
  int v6850 = v6849[30];
  int * v6851 = v6842->regs;
  int v6862 = v6850 + 1;
  v6851[30] = v6862;
  struct StateT * v6853 = slot_212(v6842);
  return v6853;
}

struct StateT * slot_20(struct StateT * v1829) {
  int v1830 = v1829->timer;
  int v1888 = v1830 + 1;
  v1829->timer = v1888;
  int * v1832 = v1829->regs;
  int v1833 = v1832[12];
  int * v1834 = v1829->cache_keys;
  int v1835 = v1834[0];
  bool v1893 = v1835 == ((int)((unsigned int)(v1833 + 20) >> 2));
  int v1883;
  if (v1893) {
    int * v1836 = v1829->cache_vals;
    int v1837 = v1836[0];
    v1883 = v1837;
  } else {
    int * v1839 = v1829->cache_keys;
    int v1840 = v1839[1];
    bool v1898 = v1840 == ((int)((unsigned int)(v1833 + 20) >> 2));
    int v1881;
    if (v1898) {
      int * v1841 = v1829->cache_vals;
      int v1842 = v1841[1];
      int * v1843 = v1829->cache_keys;
      int * v1844 = v1829->cache_keys;
      int v1845 = v1844[0];
      v1843[1] = v1845;
      int * v1847 = v1829->cache_vals;
      int * v1848 = v1829->cache_vals;
      int v1849 = v1848[0];
      v1847[1] = v1849;
      int * v1851 = v1829->cache_keys;
      int v1907 = (int)((unsigned int)(v1833 + 20) >> 2);
      v1851[0] = v1907;
      int * v1853 = v1829->cache_vals;
      v1853[0] = v1842;
      int v1855 = v1829->timer;
      int v1910 = v1855 + 1;
      v1829->timer = v1910;
      v1881 = v1842;
    } else {
      int * v1858 = v1829->mem;
      int v1912 = (int)((unsigned int)(v1833 + 20) >> 2);
      int v1859 = v1858[v1912];
      int * v1860 = v1829->mem;
      int * v1861 = v1829->cache_keys;
      int v1862 = v1861[1];
      int * v1863 = v1829->cache_vals;
      int v1864 = v1863[1];
      v1860[v1862] = v1864;
      int * v1866 = v1829->cache_keys;
      int * v1867 = v1829->cache_keys;
      int v1868 = v1867[0];
      v1866[1] = v1868;
      int * v1870 = v1829->cache_vals;
      int * v1871 = v1829->cache_vals;
      int v1872 = v1871[0];
      v1870[1] = v1872;
      int * v1874 = v1829->cache_keys;
      v1874[0] = v1912;
      int * v1876 = v1829->cache_vals;
      v1876[0] = v1859;
      int v1878 = v1829->timer;
      int v1927 = v1878 + 100;
      v1829->timer = v1927;
      v1881 = v1859;
    }
    v1883 = v1881;
  }
  int * v1884 = v1829->regs;
  v1884[16] = v1883;
  struct StateT * v1886 = slot_21(v1829);
  return v1886;
}

struct StateT * slot_436(struct StateT * v17650) {
  int v17651 = v17650->timer;
  int v17659 = v17651 + 1;
  v17650->timer = v17659;
  int * v17653 = v17650->regs;
  int v17654 = v17653[16];
  int * v17655 = v17650->regs;
  int v17663 = v17654 << 7;
  v17655[16] = v17663;
  struct StateT * v17657 = slot_437(v17650);
  return v17657;
}

struct StateT * slot_61(struct StateT * v3895) {
  int v3896 = v3895->timer;
  int v3904 = v3896 + 1;
  v3895->timer = v3904;
  int * v3898 = v3895->regs;
  int v3899 = v3898[18];
  int * v3900 = v3895->regs;
  int v3909 = (int)((unsigned int)v3899 >> 25);
  v3900[20] = v3909;
  struct StateT * v3902 = slot_62(v3895);
  return v3902;
}

struct StateT * slot_499(struct StateT * v18835) {
  int v18836 = v18835->timer;
  int v18844 = v18836 + 1;
  v18835->timer = v18844;
  int * v18838 = v18835->regs;
  int v18839 = v18838[8];
  int * v18840 = v18835->regs;
  int v18848 = v18839 << 18;
  v18840[8] = v18848;
  struct StateT * v18842 = slot_500(v18835);
  return v18842;
}

struct StateT * slot_359(struct StateT * v14799) {
  int v14800 = v14799->timer;
  int v14858 = v14800 + 1;
  v14799->timer = v14858;
  int * v14802 = v14799->regs;
  int v14803 = v14802[2];
  int * v14804 = v14799->cache_keys;
  int v14805 = v14804[0];
  bool v14863 = v14805 == ((int)((unsigned int)(v14803 + 80) >> 2));
  int v14853;
  if (v14863) {
    int * v14806 = v14799->cache_vals;
    int v14807 = v14806[0];
    v14853 = v14807;
  } else {
    int * v14809 = v14799->cache_keys;
    int v14810 = v14809[1];
    bool v14868 = v14810 == ((int)((unsigned int)(v14803 + 80) >> 2));
    int v14851;
    if (v14868) {
      int * v14811 = v14799->cache_vals;
      int v14812 = v14811[1];
      int * v14813 = v14799->cache_keys;
      int * v14814 = v14799->cache_keys;
      int v14815 = v14814[0];
      v14813[1] = v14815;
      int * v14817 = v14799->cache_vals;
      int * v14818 = v14799->cache_vals;
      int v14819 = v14818[0];
      v14817[1] = v14819;
      int * v14821 = v14799->cache_keys;
      int v14877 = (int)((unsigned int)(v14803 + 80) >> 2);
      v14821[0] = v14877;
      int * v14823 = v14799->cache_vals;
      v14823[0] = v14812;
      int v14825 = v14799->timer;
      int v14880 = v14825 + 1;
      v14799->timer = v14880;
      v14851 = v14812;
    } else {
      int * v14828 = v14799->mem;
      int v14882 = (int)((unsigned int)(v14803 + 80) >> 2);
      int v14829 = v14828[v14882];
      int * v14830 = v14799->mem;
      int * v14831 = v14799->cache_keys;
      int v14832 = v14831[1];
      int * v14833 = v14799->cache_vals;
      int v14834 = v14833[1];
      v14830[v14832] = v14834;
      int * v14836 = v14799->cache_keys;
      int * v14837 = v14799->cache_keys;
      int v14838 = v14837[0];
      v14836[1] = v14838;
      int * v14840 = v14799->cache_vals;
      int * v14841 = v14799->cache_vals;
      int v14842 = v14841[0];
      v14840[1] = v14842;
      int * v14844 = v14799->cache_keys;
      v14844[0] = v14882;
      int * v14846 = v14799->cache_vals;
      v14846[0] = v14829;
      int v14848 = v14799->timer;
      int v14897 = v14848 + 100;
      v14799->timer = v14897;
      v14851 = v14829;
    }
    v14853 = v14851;
  }
  int * v14854 = v14799->regs;
  v14854[18] = v14853;
  struct StateT * v14856 = slot_362(v14799);
  return v14856;
}

struct StateT * slot_514(struct StateT * v19148) {
  int v19149 = v19148->timer;
  int v19157 = v19149 + 1;
  v19148->timer = v19157;
  int * v19151 = v19148->regs;
  int v19152 = v19151[20];
  int * v19153 = v19148->regs;
  int v19162 = (int)((unsigned int)v19152 >> 25);
  v19153[9] = v19162;
  struct StateT * v19155 = slot_515(v19148);
  return v19155;
}

struct StateT * slot_296(struct StateT * v10382) {
  int v10383 = v10382->timer;
  int v10393 = v10383 + 1;
  v10382->timer = v10393;
  int * v10385 = v10382->regs;
  int v10386 = v10385[19];
  int * v10387 = v10382->regs;
  int v10388 = v10387[7];
  int * v10389 = v10382->regs;
  int v10399 = v10386 + v10388;
  v10389[7] = v10399;
  struct StateT * v10391 = slot_299(v10382);
  return v10391;
}

struct StateT * slot_30(struct StateT * v2603) {
  int v2604 = v2603->timer;
  int v2612 = v2604 + 1;
  v2603->timer = v2612;
  int * v2606 = v2603->regs;
  int v2607 = v2606[12];
  int * v2608 = v2603->regs;
  int v2617 = v2607 + -1947;
  v2608[21] = v2617;
  struct StateT * v2610 = slot_31(v2603);
  return v2610;
}

struct StateT * slot_606(struct StateT * v20998) {
  int v20999 = v20998->timer;
  int v21009 = v20999 + 1;
  v20998->timer = v21009;
  int * v21001 = v20998->regs;
  int v21002 = v21001[9];
  int * v21003 = v20998->regs;
  int v21004 = v21003[6];
  int * v21005 = v20998->regs;
  int v21016 = v21002 ^ v21004;
  v21005[16] = v21016;
  struct StateT * v21007 = slot_607(v20998);
  return v21007;
}

struct StateT * slot_18(struct StateT * v1619) {
  int v1620 = v1619->timer;
  int v1678 = v1620 + 1;
  v1619->timer = v1678;
  int * v1622 = v1619->regs;
  int v1623 = v1622[12];
  int * v1624 = v1619->cache_keys;
  int v1625 = v1624[0];
  bool v1683 = v1625 == ((int)((unsigned int)(v1623 + 12) >> 2));
  int v1673;
  if (v1683) {
    int * v1626 = v1619->cache_vals;
    int v1627 = v1626[0];
    v1673 = v1627;
  } else {
    int * v1629 = v1619->cache_keys;
    int v1630 = v1629[1];
    bool v1688 = v1630 == ((int)((unsigned int)(v1623 + 12) >> 2));
    int v1671;
    if (v1688) {
      int * v1631 = v1619->cache_vals;
      int v1632 = v1631[1];
      int * v1633 = v1619->cache_keys;
      int * v1634 = v1619->cache_keys;
      int v1635 = v1634[0];
      v1633[1] = v1635;
      int * v1637 = v1619->cache_vals;
      int * v1638 = v1619->cache_vals;
      int v1639 = v1638[0];
      v1637[1] = v1639;
      int * v1641 = v1619->cache_keys;
      int v1697 = (int)((unsigned int)(v1623 + 12) >> 2);
      v1641[0] = v1697;
      int * v1643 = v1619->cache_vals;
      v1643[0] = v1632;
      int v1645 = v1619->timer;
      int v1700 = v1645 + 1;
      v1619->timer = v1700;
      v1671 = v1632;
    } else {
      int * v1648 = v1619->mem;
      int v1702 = (int)((unsigned int)(v1623 + 12) >> 2);
      int v1649 = v1648[v1702];
      int * v1650 = v1619->mem;
      int * v1651 = v1619->cache_keys;
      int v1652 = v1651[1];
      int * v1653 = v1619->cache_vals;
      int v1654 = v1653[1];
      v1650[v1652] = v1654;
      int * v1656 = v1619->cache_keys;
      int * v1657 = v1619->cache_keys;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1619->cache_vals;
      int * v1661 = v1619->cache_vals;
      int v1662 = v1661[0];
      v1660[1] = v1662;
      int * v1664 = v1619->cache_keys;
      v1664[0] = v1702;
      int * v1666 = v1619->cache_vals;
      v1666[0] = v1649;
      int v1668 = v1619->timer;
      int v1717 = v1668 + 100;
      v1619->timer = v1717;
      v1671 = v1649;
    }
    v1673 = v1671;
  }
  int * v1674 = v1619->regs;
  v1674[6] = v1673;
  struct StateT * v1676 = slot_19(v1619);
  return v1676;
}

struct StateT * slot_9(struct StateT * v801) {
  int v802 = v801->timer;
  int v856 = v802 + 1;
  v801->timer = v856;
  int * v804 = v801->regs;
  int v805 = v804[2];
  int * v806 = v801->regs;
  int v807 = v806[23];
  int * v808 = v801->cache_keys;
  int v809 = v808[0];
  bool v863 = v809 == ((int)((unsigned int)(v805 + 60) >> 2));
  int v853;
  if (v863) {
    int * v810 = v801->cache_vals;
    v810[0] = v807;
    v853 = v807;
  } else {
    int * v813 = v801->cache_keys;
    int v814 = v813[1];
    bool v868 = v814 == ((int)((unsigned int)(v805 + 60) >> 2));
    int v851;
    if (v868) {
      int * v815 = v801->cache_keys;
      int * v816 = v801->cache_keys;
      int v817 = v816[0];
      v815[1] = v817;
      int * v819 = v801->cache_vals;
      int * v820 = v801->cache_vals;
      int v821 = v820[0];
      v819[1] = v821;
      int * v823 = v801->cache_keys;
      int v876 = (int)((unsigned int)(v805 + 60) >> 2);
      v823[0] = v876;
      int * v825 = v801->cache_vals;
      v825[0] = v807;
      int v827 = v801->timer;
      int v879 = v827 + 1;
      v801->timer = v879;
      v851 = v807;
    } else {
      int * v830 = v801->mem;
      int * v831 = v801->cache_keys;
      int v832 = v831[1];
      int * v833 = v801->cache_vals;
      int v834 = v833[1];
      v830[v832] = v834;
      int * v836 = v801->cache_keys;
      int * v837 = v801->cache_keys;
      int v838 = v837[0];
      v836[1] = v838;
      int * v840 = v801->cache_vals;
      int * v841 = v801->cache_vals;
      int v842 = v841[0];
      v840[1] = v842;
      int * v844 = v801->cache_keys;
      int v892 = (int)((unsigned int)(v805 + 60) >> 2);
      v844[0] = v892;
      int * v846 = v801->cache_vals;
      v846[0] = v807;
      int v848 = v801->timer;
      int v895 = v848 + 100;
      v801->timer = v895;
      v851 = v807;
    }
    v853 = v851;
  }
  struct StateT * v854 = slot_10(v801);
  return v854;
}

struct StateT * slot_300(struct StateT * v10540) {
  int v10541 = v10540->timer;
  int v10595 = v10541 + 1;
  v10540->timer = v10595;
  int * v10543 = v10540->regs;
  int v10544 = v10543[10];
  int * v10545 = v10540->regs;
  int v10546 = v10545[28];
  int * v10547 = v10540->cache_keys;
  int v10548 = v10547[0];
  bool v10602 = v10548 == ((int)((unsigned int)(v10544 + 8) >> 2));
  int v10592;
  if (v10602) {
    int * v10549 = v10540->cache_vals;
    v10549[0] = v10546;
    v10592 = v10546;
  } else {
    int * v10552 = v10540->cache_keys;
    int v10553 = v10552[1];
    bool v10607 = v10553 == ((int)((unsigned int)(v10544 + 8) >> 2));
    int v10590;
    if (v10607) {
      int * v10554 = v10540->cache_keys;
      int * v10555 = v10540->cache_keys;
      int v10556 = v10555[0];
      v10554[1] = v10556;
      int * v10558 = v10540->cache_vals;
      int * v10559 = v10540->cache_vals;
      int v10560 = v10559[0];
      v10558[1] = v10560;
      int * v10562 = v10540->cache_keys;
      int v10615 = (int)((unsigned int)(v10544 + 8) >> 2);
      v10562[0] = v10615;
      int * v10564 = v10540->cache_vals;
      v10564[0] = v10546;
      int v10566 = v10540->timer;
      int v10618 = v10566 + 1;
      v10540->timer = v10618;
      v10590 = v10546;
    } else {
      int * v10569 = v10540->mem;
      int * v10570 = v10540->cache_keys;
      int v10571 = v10570[1];
      int * v10572 = v10540->cache_vals;
      int v10573 = v10572[1];
      v10569[v10571] = v10573;
      int * v10575 = v10540->cache_keys;
      int * v10576 = v10540->cache_keys;
      int v10577 = v10576[0];
      v10575[1] = v10577;
      int * v10579 = v10540->cache_vals;
      int * v10580 = v10540->cache_vals;
      int v10581 = v10580[0];
      v10579[1] = v10581;
      int * v10583 = v10540->cache_keys;
      int v10631 = (int)((unsigned int)(v10544 + 8) >> 2);
      v10583[0] = v10631;
      int * v10585 = v10540->cache_vals;
      v10585[0] = v10546;
      int v10587 = v10540->timer;
      int v10634 = v10587 + 100;
      v10540->timer = v10634;
      v10590 = v10546;
    }
    v10592 = v10590;
  }
  struct StateT * v10593 = slot_303(v10540);
  return v10593;
}

struct StateT * slot_183(struct StateT * v6312) {
  int v6313 = v6312->timer;
  int v6323 = v6313 + 1;
  v6312->timer = v6323;
  int * v6315 = v6312->regs;
  int v6316 = v6315[6];
  int * v6317 = v6312->regs;
  int v6318 = v6317[9];
  int * v6319 = v6312->regs;
  int v6329 = v6316 | v6318;
  v6319[6] = v6329;
  struct StateT * v6321 = slot_184(v6312);
  return v6321;
}

struct StateT * slot_282(struct StateT * v10043) {
  int v10044 = v10043->timer;
  int v10054 = v10044 + 1;
  v10043->timer = v10054;
  int * v10046 = v10043->regs;
  int v10047 = v10046[21];
  int * v10048 = v10043->regs;
  int v10049 = v10048[15];
  int * v10050 = v10043->regs;
  int v10060 = v10047 + v10049;
  v10050[15] = v10060;
  struct StateT * v10052 = slot_285(v10043);
  return v10052;
}

struct StateT * slot_309(struct StateT * v11188) {
  int v11189 = v11188->timer;
  int v11243 = v11189 + 1;
  v11188->timer = v11243;
  int * v11191 = v11188->regs;
  int v11192 = v11191[10];
  int * v11193 = v11188->regs;
  int v11194 = v11193[11];
  int * v11195 = v11188->cache_keys;
  int v11196 = v11195[0];
  bool v11250 = v11196 == ((int)((unsigned int)(v11192 + 20) >> 2));
  int v11240;
  if (v11250) {
    int * v11197 = v11188->cache_vals;
    v11197[0] = v11194;
    v11240 = v11194;
  } else {
    int * v11200 = v11188->cache_keys;
    int v11201 = v11200[1];
    bool v11255 = v11201 == ((int)((unsigned int)(v11192 + 20) >> 2));
    int v11238;
    if (v11255) {
      int * v11202 = v11188->cache_keys;
      int * v11203 = v11188->cache_keys;
      int v11204 = v11203[0];
      v11202[1] = v11204;
      int * v11206 = v11188->cache_vals;
      int * v11207 = v11188->cache_vals;
      int v11208 = v11207[0];
      v11206[1] = v11208;
      int * v11210 = v11188->cache_keys;
      int v11263 = (int)((unsigned int)(v11192 + 20) >> 2);
      v11210[0] = v11263;
      int * v11212 = v11188->cache_vals;
      v11212[0] = v11194;
      int v11214 = v11188->timer;
      int v11266 = v11214 + 1;
      v11188->timer = v11266;
      v11238 = v11194;
    } else {
      int * v11217 = v11188->mem;
      int * v11218 = v11188->cache_keys;
      int v11219 = v11218[1];
      int * v11220 = v11188->cache_vals;
      int v11221 = v11220[1];
      v11217[v11219] = v11221;
      int * v11223 = v11188->cache_keys;
      int * v11224 = v11188->cache_keys;
      int v11225 = v11224[0];
      v11223[1] = v11225;
      int * v11227 = v11188->cache_vals;
      int * v11228 = v11188->cache_vals;
      int v11229 = v11228[0];
      v11227[1] = v11229;
      int * v11231 = v11188->cache_keys;
      int v11279 = (int)((unsigned int)(v11192 + 20) >> 2);
      v11231[0] = v11279;
      int * v11233 = v11188->cache_vals;
      v11233[0] = v11194;
      int v11235 = v11188->timer;
      int v11282 = v11235 + 100;
      v11188->timer = v11282;
      v11238 = v11194;
    }
    v11240 = v11238;
  }
  struct StateT * v11241 = slot_312(v11188);
  return v11241;
}

struct StateT * slot_362(struct StateT * v15029) {
  int v15030 = v15029->timer;
  int v15088 = v15030 + 1;
  v15029->timer = v15088;
  int * v15032 = v15029->regs;
  int v15033 = v15032[2];
  int * v15034 = v15029->cache_keys;
  int v15035 = v15034[0];
  bool v15093 = v15035 == ((int)((unsigned int)(v15033 + 76) >> 2));
  int v15083;
  if (v15093) {
    int * v15036 = v15029->cache_vals;
    int v15037 = v15036[0];
    v15083 = v15037;
  } else {
    int * v15039 = v15029->cache_keys;
    int v15040 = v15039[1];
    bool v15098 = v15040 == ((int)((unsigned int)(v15033 + 76) >> 2));
    int v15081;
    if (v15098) {
      int * v15041 = v15029->cache_vals;
      int v15042 = v15041[1];
      int * v15043 = v15029->cache_keys;
      int * v15044 = v15029->cache_keys;
      int v15045 = v15044[0];
      v15043[1] = v15045;
      int * v15047 = v15029->cache_vals;
      int * v15048 = v15029->cache_vals;
      int v15049 = v15048[0];
      v15047[1] = v15049;
      int * v15051 = v15029->cache_keys;
      int v15107 = (int)((unsigned int)(v15033 + 76) >> 2);
      v15051[0] = v15107;
      int * v15053 = v15029->cache_vals;
      v15053[0] = v15042;
      int v15055 = v15029->timer;
      int v15110 = v15055 + 1;
      v15029->timer = v15110;
      v15081 = v15042;
    } else {
      int * v15058 = v15029->mem;
      int v15112 = (int)((unsigned int)(v15033 + 76) >> 2);
      int v15059 = v15058[v15112];
      int * v15060 = v15029->mem;
      int * v15061 = v15029->cache_keys;
      int v15062 = v15061[1];
      int * v15063 = v15029->cache_vals;
      int v15064 = v15063[1];
      v15060[v15062] = v15064;
      int * v15066 = v15029->cache_keys;
      int * v15067 = v15029->cache_keys;
      int v15068 = v15067[0];
      v15066[1] = v15068;
      int * v15070 = v15029->cache_vals;
      int * v15071 = v15029->cache_vals;
      int v15072 = v15071[0];
      v15070[1] = v15072;
      int * v15074 = v15029->cache_keys;
      v15074[0] = v15112;
      int * v15076 = v15029->cache_vals;
      v15076[0] = v15059;
      int v15078 = v15029->timer;
      int v15127 = v15078 + 100;
      v15029->timer = v15127;
      v15081 = v15059;
    }
    v15083 = v15081;
  }
  int * v15084 = v15029->regs;
  v15084[19] = v15083;
  struct StateT * v15086 = slot_365(v15029);
  return v15086;
}

struct StateT * slot_43(struct StateT * v3381) {
  int v3382 = v3381->timer;
  int v3436 = v3382 + 1;
  v3381->timer = v3436;
  int * v3384 = v3381->regs;
  int v3385 = v3384[2];
  int * v3386 = v3381->regs;
  int v3387 = v3386[6];
  int * v3388 = v3381->cache_keys;
  int v3389 = v3388[0];
  bool v3443 = v3389 == ((int)((unsigned int)(v3385 + 8) >> 2));
  int v3433;
  if (v3443) {
    int * v3390 = v3381->cache_vals;
    v3390[0] = v3387;
    v3433 = v3387;
  } else {
    int * v3393 = v3381->cache_keys;
    int v3394 = v3393[1];
    bool v3448 = v3394 == ((int)((unsigned int)(v3385 + 8) >> 2));
    int v3431;
    if (v3448) {
      int * v3395 = v3381->cache_keys;
      int * v3396 = v3381->cache_keys;
      int v3397 = v3396[0];
      v3395[1] = v3397;
      int * v3399 = v3381->cache_vals;
      int * v3400 = v3381->cache_vals;
      int v3401 = v3400[0];
      v3399[1] = v3401;
      int * v3403 = v3381->cache_keys;
      int v3456 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3403[0] = v3456;
      int * v3405 = v3381->cache_vals;
      v3405[0] = v3387;
      int v3407 = v3381->timer;
      int v3459 = v3407 + 1;
      v3381->timer = v3459;
      v3431 = v3387;
    } else {
      int * v3410 = v3381->mem;
      int * v3411 = v3381->cache_keys;
      int v3412 = v3411[1];
      int * v3413 = v3381->cache_vals;
      int v3414 = v3413[1];
      v3410[v3412] = v3414;
      int * v3416 = v3381->cache_keys;
      int * v3417 = v3381->cache_keys;
      int v3418 = v3417[0];
      v3416[1] = v3418;
      int * v3420 = v3381->cache_vals;
      int * v3421 = v3381->cache_vals;
      int v3422 = v3421[0];
      v3420[1] = v3422;
      int * v3424 = v3381->cache_keys;
      int v3472 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3424[0] = v3472;
      int * v3426 = v3381->cache_vals;
      v3426[0] = v3387;
      int v3428 = v3381->timer;
      int v3475 = v3428 + 100;
      v3381->timer = v3475;
      v3431 = v3387;
    }
    v3433 = v3431;
  }
  struct StateT * v3434 = slot_44(v3381);
  return v3434;
}

struct StateT * slot_76(struct StateT * v4210) {
  int v4211 = v4210->timer;
  int v4219 = v4211 + 1;
  v4210->timer = v4219;
  int * v4213 = v4210->regs;
  int v4214 = v4213[15];
  int * v4215 = v4210->regs;
  int v4223 = v4214 << 9;
  v4215[15] = v4223;
  struct StateT * v4217 = slot_77(v4210);
  return v4217;
}

struct StateT * slot_6(struct StateT * v507) {
  int v508 = v507->timer;
  int v562 = v508 + 1;
  v507->timer = v562;
  int * v510 = v507->regs;
  int v511 = v510[2];
  int * v512 = v507->regs;
  int v513 = v512[20];
  int * v514 = v507->cache_keys;
  int v515 = v514[0];
  bool v569 = v515 == ((int)((unsigned int)(v511 + 72) >> 2));
  int v559;
  if (v569) {
    int * v516 = v507->cache_vals;
    v516[0] = v513;
    v559 = v513;
  } else {
    int * v519 = v507->cache_keys;
    int v520 = v519[1];
    bool v574 = v520 == ((int)((unsigned int)(v511 + 72) >> 2));
    int v557;
    if (v574) {
      int * v521 = v507->cache_keys;
      int * v522 = v507->cache_keys;
      int v523 = v522[0];
      v521[1] = v523;
      int * v525 = v507->cache_vals;
      int * v526 = v507->cache_vals;
      int v527 = v526[0];
      v525[1] = v527;
      int * v529 = v507->cache_keys;
      int v582 = (int)((unsigned int)(v511 + 72) >> 2);
      v529[0] = v582;
      int * v531 = v507->cache_vals;
      v531[0] = v513;
      int v533 = v507->timer;
      int v585 = v533 + 1;
      v507->timer = v585;
      v557 = v513;
    } else {
      int * v536 = v507->mem;
      int * v537 = v507->cache_keys;
      int v538 = v537[1];
      int * v539 = v507->cache_vals;
      int v540 = v539[1];
      v536[v538] = v540;
      int * v542 = v507->cache_keys;
      int * v543 = v507->cache_keys;
      int v544 = v543[0];
      v542[1] = v544;
      int * v546 = v507->cache_vals;
      int * v547 = v507->cache_vals;
      int v548 = v547[0];
      v546[1] = v548;
      int * v550 = v507->cache_keys;
      int v598 = (int)((unsigned int)(v511 + 72) >> 2);
      v550[0] = v598;
      int * v552 = v507->cache_vals;
      v552[0] = v513;
      int v554 = v507->timer;
      int v601 = v554 + 100;
      v507->timer = v601;
      v557 = v513;
    }
    v559 = v557;
  }
  struct StateT * v560 = slot_7(v507);
  return v560;
}

struct StateT * slot_55(struct StateT * v3782) {
  int * v3783 = v3782->saved_regs;
  int * v3784 = v3782->regs;
  int v3785 = v3784[9];
  v3783[9] = v3785;
  int v3787 = v3782->timer;
  int v3799 = v3787 + 1;
  v3782->timer = v3799;
  int * v3789 = v3782->regs;
  int v3790 = v3789[15];
  int * v3791 = v3782->regs;
  int v3803 = (int)((unsigned int)v3790 >> 25);
  v3791[9] = v3803;
  struct StateT * v3793 = slot_56(v3782);
  return v3793;
}

struct StateT * slot_283(struct StateT * v10063) {
  int v10064 = v10063->timer;
  int v10072 = v10064 + 1;
  v10063->timer = v10072;
  int * v10066 = v10063->regs;
  int v10067 = v10066[18];
  int * v10068 = v10063->regs;
  int v10076 = v10067 << 7;
  v10068[18] = v10076;
  struct StateT * v10070 = slot_286(v10063);
  return v10070;
}

struct StateT * slot_346(struct StateT * v13873) {
  int v13874 = v13873->timer;
  int v13884 = v13874 + 1;
  v13873->timer = v13884;
  int * v13876 = v13873->regs;
  int v13877 = v13876[9];
  int * v13878 = v13873->regs;
  int v13879 = v13878[20];
  int * v13880 = v13873->regs;
  int v13890 = v13877 | v13879;
  v13880[9] = v13890;
  struct StateT * v13882 = slot_349(v13873);
  return v13882;
}

struct StateT * slot_647(struct StateT * v21771) {
  int v21772 = v21771->timer;
  int v21782 = v21772 + 1;
  v21771->timer = v21782;
  int * v21774 = v21771->regs;
  int v21775 = v21774[14];
  int * v21776 = v21771->regs;
  int v21777 = v21776[27];
  int * v21778 = v21771->regs;
  int v21789 = v21775 + v21777;
  v21778[11] = v21789;
  struct StateT * v21780 = slot_648(v21771);
  return v21780;
}

struct StateT * slot_516(struct StateT * v19181) {
  int v19182 = v19181->timer;
  int v19192 = v19182 + 1;
  v19181->timer = v19192;
  int * v19184 = v19181->regs;
  int v19185 = v19184[20];
  int * v19186 = v19181->regs;
  int v19187 = v19186[9];
  int * v19188 = v19181->regs;
  int v19198 = v19185 | v19187;
  v19188[9] = v19198;
  struct StateT * v19190 = slot_517(v19181);
  return v19190;
}

struct StateT * slot_599(struct StateT * v20862) {
  int v20863 = v20862->timer;
  int v20873 = v20863 + 1;
  v20862->timer = v20873;
  int * v20865 = v20862->regs;
  int v20866 = v20865[16];
  int * v20867 = v20862->regs;
  int v20868 = v20867[5];
  int * v20869 = v20862->regs;
  int v20879 = v20866 | v20868;
  v20869[16] = v20879;
  struct StateT * v20871 = slot_600(v20862);
  return v20871;
}

struct StateT * slot_274(struct StateT * v9913) {
  int v9914 = v9913->timer;
  int v9922 = v9914 + 1;
  v9913->timer = v9922;
  int * v9916 = v9913->regs;
  int v9917 = v9916[20];
  int * v9918 = v9913->regs;
  int v9926 = v9917 << 7;
  v9918[20] = v9926;
  struct StateT * v9920 = slot_277(v9913);
  return v9920;
}

struct StateT * slot_535(struct StateT * v19569) {
  int v19570 = v19569->timer;
  int v19578 = v19570 + 1;
  v19569->timer = v19578;
  int * v19572 = v19569->regs;
  int v19573 = v19572[8];
  int * v19574 = v19569->regs;
  int v19582 = v19573 << 9;
  v19574[8] = v19582;
  struct StateT * v19576 = slot_536(v19569);
  return v19576;
}

struct StateT * slot_318(struct StateT * v11839) {
  int v11840 = v11839->timer;
  int v11894 = v11840 + 1;
  v11839->timer = v11894;
  int * v11842 = v11839->regs;
  int v11843 = v11842[10];
  int * v11844 = v11839->regs;
  int v11845 = v11844[26];
  int * v11846 = v11839->cache_keys;
  int v11847 = v11846[0];
  bool v11901 = v11847 == ((int)((unsigned int)(v11843 + 32) >> 2));
  int v11891;
  if (v11901) {
    int * v11848 = v11839->cache_vals;
    v11848[0] = v11845;
    v11891 = v11845;
  } else {
    int * v11851 = v11839->cache_keys;
    int v11852 = v11851[1];
    bool v11906 = v11852 == ((int)((unsigned int)(v11843 + 32) >> 2));
    int v11889;
    if (v11906) {
      int * v11853 = v11839->cache_keys;
      int * v11854 = v11839->cache_keys;
      int v11855 = v11854[0];
      v11853[1] = v11855;
      int * v11857 = v11839->cache_vals;
      int * v11858 = v11839->cache_vals;
      int v11859 = v11858[0];
      v11857[1] = v11859;
      int * v11861 = v11839->cache_keys;
      int v11914 = (int)((unsigned int)(v11843 + 32) >> 2);
      v11861[0] = v11914;
      int * v11863 = v11839->cache_vals;
      v11863[0] = v11845;
      int v11865 = v11839->timer;
      int v11917 = v11865 + 1;
      v11839->timer = v11917;
      v11889 = v11845;
    } else {
      int * v11868 = v11839->mem;
      int * v11869 = v11839->cache_keys;
      int v11870 = v11869[1];
      int * v11871 = v11839->cache_vals;
      int v11872 = v11871[1];
      v11868[v11870] = v11872;
      int * v11874 = v11839->cache_keys;
      int * v11875 = v11839->cache_keys;
      int v11876 = v11875[0];
      v11874[1] = v11876;
      int * v11878 = v11839->cache_vals;
      int * v11879 = v11839->cache_vals;
      int v11880 = v11879[0];
      v11878[1] = v11880;
      int * v11882 = v11839->cache_keys;
      int v11930 = (int)((unsigned int)(v11843 + 32) >> 2);
      v11882[0] = v11930;
      int * v11884 = v11839->cache_vals;
      v11884[0] = v11845;
      int v11886 = v11839->timer;
      int v11933 = v11886 + 100;
      v11839->timer = v11933;
      v11889 = v11845;
    }
    v11891 = v11889;
  }
  struct StateT * v11892 = slot_321(v11839);
  return v11892;
}

struct StateT * slot_91(struct StateT * v4513) {
  int v4514 = v4513->timer;
  int v4524 = v4514 + 1;
  v4513->timer = v4524;
  int * v4516 = v4513->regs;
  int v4517 = v4516[26];
  int * v4518 = v4513->regs;
  int v4519 = v4518[12];
  int * v4520 = v4513->regs;
  int v4531 = v4517 + v4519;
  v4520[15] = v4531;
  struct StateT * v4522 = slot_92(v4513);
  return v4522;
}

struct StateT * slot_58(struct StateT * v3842) {
  int v3843 = v3842->timer;
  int v3851 = v3843 + 1;
  v3842->timer = v3851;
  int * v3845 = v3842->regs;
  int v3846 = v3845[20];
  int * v3847 = v3842->regs;
  int v3856 = (int)((unsigned int)v3846 >> 25);
  v3847[9] = v3856;
  struct StateT * v3849 = slot_59(v3842);
  return v3849;
}

struct StateT * slot_255(struct StateT * v9131) {
  int v9132 = v9131->timer;
  int v9190 = v9132 + 1;
  v9131->timer = v9190;
  int * v9134 = v9131->regs;
  int v9135 = v9134[2];
  int * v9136 = v9131->cache_keys;
  int v9137 = v9136[0];
  bool v9195 = v9137 == ((int)((unsigned int)(v9135 + 36) >> 2));
  int v9185;
  if (v9195) {
    int * v9138 = v9131->cache_vals;
    int v9139 = v9138[0];
    v9185 = v9139;
  } else {
    int * v9141 = v9131->cache_keys;
    int v9142 = v9141[1];
    bool v9200 = v9142 == ((int)((unsigned int)(v9135 + 36) >> 2));
    int v9183;
    if (v9200) {
      int * v9143 = v9131->cache_vals;
      int v9144 = v9143[1];
      int * v9145 = v9131->cache_keys;
      int * v9146 = v9131->cache_keys;
      int v9147 = v9146[0];
      v9145[1] = v9147;
      int * v9149 = v9131->cache_vals;
      int * v9150 = v9131->cache_vals;
      int v9151 = v9150[0];
      v9149[1] = v9151;
      int * v9153 = v9131->cache_keys;
      int v9209 = (int)((unsigned int)(v9135 + 36) >> 2);
      v9153[0] = v9209;
      int * v9155 = v9131->cache_vals;
      v9155[0] = v9144;
      int v9157 = v9131->timer;
      int v9212 = v9157 + 1;
      v9131->timer = v9212;
      v9183 = v9144;
    } else {
      int * v9160 = v9131->mem;
      int v9214 = (int)((unsigned int)(v9135 + 36) >> 2);
      int v9161 = v9160[v9214];
      int * v9162 = v9131->mem;
      int * v9163 = v9131->cache_keys;
      int v9164 = v9163[1];
      int * v9165 = v9131->cache_vals;
      int v9166 = v9165[1];
      v9162[v9164] = v9166;
      int * v9168 = v9131->cache_keys;
      int * v9169 = v9131->cache_keys;
      int v9170 = v9169[0];
      v9168[1] = v9170;
      int * v9172 = v9131->cache_vals;
      int * v9173 = v9131->cache_vals;
      int v9174 = v9173[0];
      v9172[1] = v9174;
      int * v9176 = v9131->cache_keys;
      v9176[0] = v9214;
      int * v9178 = v9131->cache_vals;
      v9178[0] = v9161;
      int v9180 = v9131->timer;
      int v9229 = v9180 + 100;
      v9131->timer = v9229;
      v9183 = v9161;
    }
    v9185 = v9183;
  }
  int * v9186 = v9131->regs;
  v9186[30] = v9185;
  struct StateT * v9188 = slot_258(v9131);
  return v9188;
}

struct StateT * slot_540(struct StateT * v19658) {
  int v19659 = v19658->timer;
  int v19667 = v19659 + 1;
  v19658->timer = v19667;
  int * v19661 = v19658->regs;
  int v19662 = v19661[18];
  int * v19663 = v19658->regs;
  int v19672 = (int)((unsigned int)v19662 >> 23);
  v19663[20] = v19672;
  struct StateT * v19665 = slot_541(v19658);
  return v19665;
}

struct StateT * slot_617(struct StateT * v21209) {
  int v21210 = v21209->timer;
  int v21218 = v21210 + 1;
  v21209->timer = v21218;
  int * v21212 = v21209->regs;
  int v21213 = v21212[6];
  int * v21214 = v21209->regs;
  int v21223 = (int)((unsigned int)v21213 >> 23);
  v21214[9] = v21223;
  struct StateT * v21216 = slot_618(v21209);
  return v21216;
}

struct StateT * slot_66(struct StateT * v3981) {
  int v3982 = v3981->timer;
  int v3992 = v3982 + 1;
  v3981->timer = v3992;
  int * v3984 = v3981->regs;
  int v3985 = v3984[8];
  int * v3986 = v3981->regs;
  int v3987 = v3986[20];
  int * v3988 = v3981->regs;
  int v3998 = v3985 | v3987;
  v3988[8] = v3998;
  struct StateT * v3990 = slot_67(v3981);
  return v3990;
}

struct StateT * slot_643(struct StateT * v21691) {
  int v21692 = v21691->timer;
  int v21702 = v21692 + 1;
  v21691->timer = v21702;
  int * v21694 = v21691->regs;
  int v21695 = v21694[14];
  int * v21696 = v21691->regs;
  int v21697 = v21696[11];
  int * v21698 = v21691->regs;
  int v21708 = v21695 ^ v21697;
  v21698[14] = v21708;
  struct StateT * v21700 = slot_644(v21691);
  return v21700;
}

struct StateT * slot_550(struct StateT * v19882) {
  int v19883 = v19882->timer;
  int v19893 = v19883 + 1;
  v19882->timer = v19893;
  int * v19885 = v19882->regs;
  int v19886 = v19885[25];
  int * v19887 = v19882->regs;
  int v19888 = v19887[14];
  int * v19889 = v19882->regs;
  int v19900 = v19886 + v19888;
  v19889[18] = v19900;
  struct StateT * v19891 = slot_551(v19882);
  return v19891;
}

struct StateT * slot_592(struct StateT * v20740) {
  int v20741 = v20740->timer;
  int v20749 = v20741 + 1;
  v20740->timer = v20749;
  int * v20743 = v20740->regs;
  int v20744 = v20743[15];
  int * v20745 = v20740->regs;
  int v20753 = v20744 << 7;
  v20745[15] = v20753;
  struct StateT * v20747 = slot_593(v20740);
  return v20747;
}

struct StateT * slot_368(struct StateT * v15489) {
  int v15490 = v15489->timer;
  int v15548 = v15490 + 1;
  v15489->timer = v15548;
  int * v15492 = v15489->regs;
  int v15493 = v15492[2];
  int * v15494 = v15489->cache_keys;
  int v15495 = v15494[0];
  bool v15553 = v15495 == ((int)((unsigned int)(v15493 + 68) >> 2));
  int v15543;
  if (v15553) {
    int * v15496 = v15489->cache_vals;
    int v15497 = v15496[0];
    v15543 = v15497;
  } else {
    int * v15499 = v15489->cache_keys;
    int v15500 = v15499[1];
    bool v15558 = v15500 == ((int)((unsigned int)(v15493 + 68) >> 2));
    int v15541;
    if (v15558) {
      int * v15501 = v15489->cache_vals;
      int v15502 = v15501[1];
      int * v15503 = v15489->cache_keys;
      int * v15504 = v15489->cache_keys;
      int v15505 = v15504[0];
      v15503[1] = v15505;
      int * v15507 = v15489->cache_vals;
      int * v15508 = v15489->cache_vals;
      int v15509 = v15508[0];
      v15507[1] = v15509;
      int * v15511 = v15489->cache_keys;
      int v15567 = (int)((unsigned int)(v15493 + 68) >> 2);
      v15511[0] = v15567;
      int * v15513 = v15489->cache_vals;
      v15513[0] = v15502;
      int v15515 = v15489->timer;
      int v15570 = v15515 + 1;
      v15489->timer = v15570;
      v15541 = v15502;
    } else {
      int * v15518 = v15489->mem;
      int v15572 = (int)((unsigned int)(v15493 + 68) >> 2);
      int v15519 = v15518[v15572];
      int * v15520 = v15489->mem;
      int * v15521 = v15489->cache_keys;
      int v15522 = v15521[1];
      int * v15523 = v15489->cache_vals;
      int v15524 = v15523[1];
      v15520[v15522] = v15524;
      int * v15526 = v15489->cache_keys;
      int * v15527 = v15489->cache_keys;
      int v15528 = v15527[0];
      v15526[1] = v15528;
      int * v15530 = v15489->cache_vals;
      int * v15531 = v15489->cache_vals;
      int v15532 = v15531[0];
      v15530[1] = v15532;
      int * v15534 = v15489->cache_keys;
      v15534[0] = v15572;
      int * v15536 = v15489->cache_vals;
      v15536[0] = v15519;
      int v15538 = v15489->timer;
      int v15587 = v15538 + 100;
      v15489->timer = v15587;
      v15541 = v15519;
    }
    v15543 = v15541;
  }
  int * v15544 = v15489->regs;
  v15544[21] = v15543;
  struct StateT * v15546 = slot_371(v15489);
  return v15546;
}

struct StateT * slot_265(struct StateT * v9670) {
  int v9671 = v9670->timer;
  int v9679 = v9671 + 1;
  v9670->timer = v9679;
  int * v9673 = v9670->regs;
  int v9674 = v9673[15];
  int * v9675 = v9670->regs;
  int v9683 = v9674 << 7;
  v9675[15] = v9683;
  struct StateT * v9677 = slot_268(v9670);
  return v9677;
}

struct StateT * slot_37(struct StateT * v2794) {
  int v2795 = v2794->timer;
  int v2849 = v2795 + 1;
  v2794->timer = v2849;
  int * v2797 = v2794->regs;
  int v2798 = v2797[2];
  int * v2799 = v2794->regs;
  int v2800 = v2799[25];
  int * v2801 = v2794->cache_keys;
  int v2802 = v2801[0];
  bool v2856 = v2802 == ((int)((unsigned int)(v2798 + 16) >> 2));
  int v2846;
  if (v2856) {
    int * v2803 = v2794->cache_vals;
    v2803[0] = v2800;
    v2846 = v2800;
  } else {
    int * v2806 = v2794->cache_keys;
    int v2807 = v2806[1];
    bool v2861 = v2807 == ((int)((unsigned int)(v2798 + 16) >> 2));
    int v2844;
    if (v2861) {
      int * v2808 = v2794->cache_keys;
      int * v2809 = v2794->cache_keys;
      int v2810 = v2809[0];
      v2808[1] = v2810;
      int * v2812 = v2794->cache_vals;
      int * v2813 = v2794->cache_vals;
      int v2814 = v2813[0];
      v2812[1] = v2814;
      int * v2816 = v2794->cache_keys;
      int v2869 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2816[0] = v2869;
      int * v2818 = v2794->cache_vals;
      v2818[0] = v2800;
      int v2820 = v2794->timer;
      int v2872 = v2820 + 1;
      v2794->timer = v2872;
      v2844 = v2800;
    } else {
      int * v2823 = v2794->mem;
      int * v2824 = v2794->cache_keys;
      int v2825 = v2824[1];
      int * v2826 = v2794->cache_vals;
      int v2827 = v2826[1];
      v2823[v2825] = v2827;
      int * v2829 = v2794->cache_keys;
      int * v2830 = v2794->cache_keys;
      int v2831 = v2830[0];
      v2829[1] = v2831;
      int * v2833 = v2794->cache_vals;
      int * v2834 = v2794->cache_vals;
      int v2835 = v2834[0];
      v2833[1] = v2835;
      int * v2837 = v2794->cache_keys;
      int v2885 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2837[0] = v2885;
      int * v2839 = v2794->cache_vals;
      v2839[0] = v2800;
      int v2841 = v2794->timer;
      int v2888 = v2841 + 100;
      v2794->timer = v2888;
      v2844 = v2800;
    }
    v2846 = v2844;
  }
  struct StateT * v2847 = slot_38(v2794);
  return v2847;
}

struct StateT * slot_114(struct StateT * v4984) {
  int * v4985 = v4984->saved_regs;
  int * v4986 = v4984->regs;
  int v4987 = v4986[5];
  v4985[5] = v4987;
  int v4989 = v4984->timer;
  int v5003 = v4989 + 1;
  v4984->timer = v5003;
  int * v4991 = v4984->regs;
  int v4992 = v4991[8];
  int * v4993 = v4984->regs;
  int v4994 = v4993[25];
  int * v4995 = v4984->regs;
  int v5009 = v4992 + v4994;
  v4995[5] = v5009;
  struct StateT * v4997 = slot_115(v4984);
  return v4997;
}

struct StateT * slot_257(struct StateT * v9257) {
  int v9258 = v9257->timer;
  int v9316 = v9258 + 1;
  v9257->timer = v9316;
  int * v9260 = v9257->regs;
  int v9261 = v9260[2];
  int * v9262 = v9257->cache_keys;
  int v9263 = v9262[0];
  bool v9321 = v9263 == ((int)((unsigned int)(v9261 + 32) >> 2));
  int v9311;
  if (v9321) {
    int * v9264 = v9257->cache_vals;
    int v9265 = v9264[0];
    v9311 = v9265;
  } else {
    int * v9267 = v9257->cache_keys;
    int v9268 = v9267[1];
    bool v9326 = v9268 == ((int)((unsigned int)(v9261 + 32) >> 2));
    int v9309;
    if (v9326) {
      int * v9269 = v9257->cache_vals;
      int v9270 = v9269[1];
      int * v9271 = v9257->cache_keys;
      int * v9272 = v9257->cache_keys;
      int v9273 = v9272[0];
      v9271[1] = v9273;
      int * v9275 = v9257->cache_vals;
      int * v9276 = v9257->cache_vals;
      int v9277 = v9276[0];
      v9275[1] = v9277;
      int * v9279 = v9257->cache_keys;
      int v9335 = (int)((unsigned int)(v9261 + 32) >> 2);
      v9279[0] = v9335;
      int * v9281 = v9257->cache_vals;
      v9281[0] = v9270;
      int v9283 = v9257->timer;
      int v9338 = v9283 + 1;
      v9257->timer = v9338;
      v9309 = v9270;
    } else {
      int * v9286 = v9257->mem;
      int v9340 = (int)((unsigned int)(v9261 + 32) >> 2);
      int v9287 = v9286[v9340];
      int * v9288 = v9257->mem;
      int * v9289 = v9257->cache_keys;
      int v9290 = v9289[1];
      int * v9291 = v9257->cache_vals;
      int v9292 = v9291[1];
      v9288[v9290] = v9292;
      int * v9294 = v9257->cache_keys;
      int * v9295 = v9257->cache_keys;
      int v9296 = v9295[0];
      v9294[1] = v9296;
      int * v9298 = v9257->cache_vals;
      int * v9299 = v9257->cache_vals;
      int v9300 = v9299[0];
      v9298[1] = v9300;
      int * v9302 = v9257->cache_keys;
      v9302[0] = v9340;
      int * v9304 = v9257->cache_vals;
      v9304[0] = v9287;
      int v9306 = v9257->timer;
      int v9355 = v9306 + 100;
      v9257->timer = v9355;
      v9309 = v9287;
    }
    v9311 = v9309;
  }
  int * v9312 = v9257->regs;
  v9312[30] = v9311;
  struct StateT * v9314 = slot_260(v9257);
  return v9314;
}

struct StateT * slot_192(struct StateT * v6486) {
  int v6487 = v6486->timer;
  int v6497 = v6487 + 1;
  v6486->timer = v6497;
  int * v6489 = v6486->regs;
  int v6490 = v6489[12];
  int * v6491 = v6486->regs;
  int v6492 = v6491[25];
  int * v6493 = v6486->regs;
  int v6504 = v6490 + v6492;
  v6493[15] = v6504;
  struct StateT * v6495 = slot_193(v6486);
  return v6495;
}

struct StateT * slot_327(struct StateT * v12481) {
  int v12482 = v12481->timer;
  int v12536 = v12482 + 1;
  v12481->timer = v12536;
  int * v12484 = v12481->regs;
  int v12485 = v12484[10];
  int * v12486 = v12481->regs;
  int v12487 = v12486[17];
  int * v12488 = v12481->cache_keys;
  int v12489 = v12488[0];
  bool v12543 = v12489 == ((int)((unsigned int)(v12485 + 44) >> 2));
  int v12533;
  if (v12543) {
    int * v12490 = v12481->cache_vals;
    v12490[0] = v12487;
    v12533 = v12487;
  } else {
    int * v12493 = v12481->cache_keys;
    int v12494 = v12493[1];
    bool v12548 = v12494 == ((int)((unsigned int)(v12485 + 44) >> 2));
    int v12531;
    if (v12548) {
      int * v12495 = v12481->cache_keys;
      int * v12496 = v12481->cache_keys;
      int v12497 = v12496[0];
      v12495[1] = v12497;
      int * v12499 = v12481->cache_vals;
      int * v12500 = v12481->cache_vals;
      int v12501 = v12500[0];
      v12499[1] = v12501;
      int * v12503 = v12481->cache_keys;
      int v12556 = (int)((unsigned int)(v12485 + 44) >> 2);
      v12503[0] = v12556;
      int * v12505 = v12481->cache_vals;
      v12505[0] = v12487;
      int v12507 = v12481->timer;
      int v12559 = v12507 + 1;
      v12481->timer = v12559;
      v12531 = v12487;
    } else {
      int * v12510 = v12481->mem;
      int * v12511 = v12481->cache_keys;
      int v12512 = v12511[1];
      int * v12513 = v12481->cache_vals;
      int v12514 = v12513[1];
      v12510[v12512] = v12514;
      int * v12516 = v12481->cache_keys;
      int * v12517 = v12481->cache_keys;
      int v12518 = v12517[0];
      v12516[1] = v12518;
      int * v12520 = v12481->cache_vals;
      int * v12521 = v12481->cache_vals;
      int v12522 = v12521[0];
      v12520[1] = v12522;
      int * v12524 = v12481->cache_keys;
      int v12572 = (int)((unsigned int)(v12485 + 44) >> 2);
      v12524[0] = v12572;
      int * v12526 = v12481->cache_vals;
      v12526[0] = v12487;
      int v12528 = v12481->timer;
      int v12575 = v12528 + 100;
      v12481->timer = v12575;
      v12531 = v12487;
    }
    v12533 = v12531;
  }
  struct StateT * v12534 = slot_330(v12481);
  return v12534;
}

struct StateT * slot_48(struct StateT * v3547) {
  int v3548 = v3547->timer;
  int v3602 = v3548 + 1;
  v3547->timer = v3602;
  int * v3550 = v3547->regs;
  int v3551 = v3550[2];
  int * v3552 = v3547->regs;
  int v3553 = v3552[15];
  int * v3554 = v3547->cache_keys;
  int v3555 = v3554[0];
  bool v3609 = v3555 == ((int)((unsigned int)(v3551 + 24) >> 2));
  int v3599;
  if (v3609) {
    int * v3556 = v3547->cache_vals;
    v3556[0] = v3553;
    v3599 = v3553;
  } else {
    int * v3559 = v3547->cache_keys;
    int v3560 = v3559[1];
    bool v3614 = v3560 == ((int)((unsigned int)(v3551 + 24) >> 2));
    int v3597;
    if (v3614) {
      int * v3561 = v3547->cache_keys;
      int * v3562 = v3547->cache_keys;
      int v3563 = v3562[0];
      v3561[1] = v3563;
      int * v3565 = v3547->cache_vals;
      int * v3566 = v3547->cache_vals;
      int v3567 = v3566[0];
      v3565[1] = v3567;
      int * v3569 = v3547->cache_keys;
      int v3622 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3569[0] = v3622;
      int * v3571 = v3547->cache_vals;
      v3571[0] = v3553;
      int v3573 = v3547->timer;
      int v3625 = v3573 + 1;
      v3547->timer = v3625;
      v3597 = v3553;
    } else {
      int * v3576 = v3547->mem;
      int * v3577 = v3547->cache_keys;
      int v3578 = v3577[1];
      int * v3579 = v3547->cache_vals;
      int v3580 = v3579[1];
      v3576[v3578] = v3580;
      int * v3582 = v3547->cache_keys;
      int * v3583 = v3547->cache_keys;
      int v3584 = v3583[0];
      v3582[1] = v3584;
      int * v3586 = v3547->cache_vals;
      int * v3587 = v3547->cache_vals;
      int v3588 = v3587[0];
      v3586[1] = v3588;
      int * v3590 = v3547->cache_keys;
      int v3638 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3590[0] = v3638;
      int * v3592 = v3547->cache_vals;
      v3592[0] = v3553;
      int v3594 = v3547->timer;
      int v3641 = v3594 + 100;
      v3547->timer = v3641;
      v3597 = v3553;
    }
    v3599 = v3597;
  }
  struct StateT * v3600 = slot_49(v3547);
  return v3600;
}

struct StateT * slot_396(struct StateT * v16893) {
  int v16894 = v16893->timer;
  int v16902 = v16894 + 1;
  v16893->timer = v16902;
  int * v16896 = v16893->regs;
  int v16897 = v16896[9];
  int * v16898 = v16893->regs;
  int v16906 = v16897 << 13;
  v16898[9] = v16906;
  struct StateT * v16900 = slot_397(v16893);
  return v16900;
}

struct StateT * slot_528(struct StateT * v19436) {
  int v19437 = v19436->timer;
  int v19447 = v19437 + 1;
  v19436->timer = v19447;
  int * v19439 = v19436->regs;
  int v19440 = v19439[13];
  int * v19441 = v19436->regs;
  int v19442 = v19441[11];
  int * v19443 = v19436->regs;
  int v19454 = v19440 + v19442;
  v19443[8] = v19454;
  struct StateT * v19445 = slot_529(v19436);
  return v19445;
}

struct StateT * slot_72(struct StateT * v4130) {
  int v4131 = v4130->timer;
  int v4141 = v4131 + 1;
  v4130->timer = v4141;
  int * v4133 = v4130->regs;
  int v4134 = v4133[13];
  int * v4135 = v4130->regs;
  int v4136 = v4135[11];
  int * v4137 = v4130->regs;
  int v4148 = v4134 + v4136;
  v4137[8] = v4148;
  struct StateT * v4139 = slot_73(v4130);
  return v4139;
}

struct StateT * slot_526(struct StateT * v19388) {
  int * v19389 = v19388->saved_regs;
  int * v19390 = v19388->regs;
  int v19391 = v19390[14];
  v19389[14] = v19391;
  int v19393 = v19388->timer;
  int v19407 = v19393 + 1;
  v19388->timer = v19407;
  int * v19395 = v19388->regs;
  int v19396 = v19395[14];
  int * v19397 = v19388->regs;
  int v19398 = v19397[8];
  int * v19399 = v19388->regs;
  int v19412 = v19396 ^ v19398;
  v19399[14] = v19412;
  struct StateT * v19401 = slot_527(v19388);
  return v19401;
}

struct StateT * slot_119(struct StateT * v5082) {
  int v5083 = v5082->timer;
  int v5091 = v5083 + 1;
  v5082->timer = v5091;
  int * v5085 = v5082->regs;
  int v5086 = v5085[16];
  int * v5087 = v5082->regs;
  int v5095 = v5086 << 18;
  v5087[16] = v5095;
  struct StateT * v5089 = slot_120(v5082);
  return v5089;
}

struct StateT * slot_101(struct StateT * v4703) {
  int v4704 = v4703->timer;
  int v4712 = v4704 + 1;
  v4703->timer = v4712;
  int * v4706 = v4703->regs;
  int v4707 = v4706[9];
  int * v4708 = v4703->regs;
  int v4717 = (int)((unsigned int)v4707 >> 19);
  v4708[20] = v4717;
  struct StateT * v4710 = slot_102(v4703);
  return v4710;
}

struct StateT * slot_276(struct StateT * v9942) {
  int v9943 = v9942->timer;
  int v9951 = v9943 + 1;
  v9942->timer = v9951;
  int * v9945 = v9942->regs;
  int v9946 = v9945[7];
  int * v9947 = v9942->regs;
  int v9955 = v9946 + -718;
  v9947[7] = v9955;
  struct StateT * v9949 = slot_279(v9942);
  return v9949;
}

struct StateT * slot_290(struct StateT * v10188) {
  int v10189 = v10188->timer;
  int v10199 = v10189 + 1;
  v10188->timer = v10199;
  int * v10191 = v10188->regs;
  int v10192 = v10191[21];
  int * v10193 = v10188->regs;
  int v10194 = v10193[15];
  int * v10195 = v10188->regs;
  int v10205 = v10192 + v10194;
  v10195[15] = v10205;
  struct StateT * v10197 = slot_293(v10188);
  return v10197;
}

struct StateT * slot_93(struct StateT * v4555) {
  int v4556 = v4555->timer;
  int v4566 = v4556 + 1;
  v4555->timer = v4566;
  int * v4558 = v4555->regs;
  int v4559 = v4558[27];
  int * v4560 = v4555->regs;
  int v4561 = v4560[1];
  int * v4562 = v4555->regs;
  int v4573 = v4559 + v4561;
  v4562[9] = v4573;
  struct StateT * v4564 = slot_94(v4555);
  return v4564;
}

struct StateT * slot_266(struct StateT * v9686) {
  int v9687 = v9686->timer;
  int v9697 = v9687 + 1;
  v9686->timer = v9697;
  int * v9689 = v9686->regs;
  int v9690 = v9689[24];
  int * v9691 = v9686->regs;
  int v9692 = v9691[30];
  int * v9693 = v9686->regs;
  int v9703 = v9690 + v9692;
  v9693[24] = v9703;
  struct StateT * v9695 = slot_269(v9686);
  return v9695;
}

struct StateT * slot_88(struct StateT * v4432) {
  int * v4433 = v4432->saved_regs;
  int * v4434 = v4432->regs;
  int v4435 = v4434[24];
  v4433[24] = v4435;
  int v4437 = v4432->timer;
  int v4451 = v4437 + 1;
  v4432->timer = v4451;
  int * v4439 = v4432->regs;
  int v4440 = v4439[24];
  int * v4441 = v4432->regs;
  int v4442 = v4441[8];
  int * v4443 = v4432->regs;
  int v4456 = v4440 ^ v4442;
  v4443[24] = v4456;
  struct StateT * v4445 = slot_89(v4432);
  return v4445;
}

struct StateT * slot_96(struct StateT * v4614) {
  int v4615 = v4614->timer;
  int v4623 = v4615 + 1;
  v4614->timer = v4623;
  int * v4617 = v4614->regs;
  int v4618 = v4617[15];
  int * v4619 = v4614->regs;
  int v4627 = v4618 << 13;
  v4619[15] = v4627;
  struct StateT * v4621 = slot_97(v4614);
  return v4621;
}

struct StateT * slot_234(struct StateT * v7930) {
  int v7931 = v7930->timer;
  int v7989 = v7931 + 1;
  v7930->timer = v7989;
  int * v7933 = v7930->regs;
  int v7934 = v7933[2];
  int * v7935 = v7930->cache_keys;
  int v7936 = v7935[0];
  bool v7994 = v7936 == ((int)((unsigned int)(v7934 + 16) >> 2));
  int v7984;
  if (v7994) {
    int * v7937 = v7930->cache_vals;
    int v7938 = v7937[0];
    v7984 = v7938;
  } else {
    int * v7940 = v7930->cache_keys;
    int v7941 = v7940[1];
    bool v7999 = v7941 == ((int)((unsigned int)(v7934 + 16) >> 2));
    int v7982;
    if (v7999) {
      int * v7942 = v7930->cache_vals;
      int v7943 = v7942[1];
      int * v7944 = v7930->cache_keys;
      int * v7945 = v7930->cache_keys;
      int v7946 = v7945[0];
      v7944[1] = v7946;
      int * v7948 = v7930->cache_vals;
      int * v7949 = v7930->cache_vals;
      int v7950 = v7949[0];
      v7948[1] = v7950;
      int * v7952 = v7930->cache_keys;
      int v8008 = (int)((unsigned int)(v7934 + 16) >> 2);
      v7952[0] = v8008;
      int * v7954 = v7930->cache_vals;
      v7954[0] = v7943;
      int v7956 = v7930->timer;
      int v8011 = v7956 + 1;
      v7930->timer = v8011;
      v7982 = v7943;
    } else {
      int * v7959 = v7930->mem;
      int v8013 = (int)((unsigned int)(v7934 + 16) >> 2);
      int v7960 = v7959[v8013];
      int * v7961 = v7930->mem;
      int * v7962 = v7930->cache_keys;
      int v7963 = v7962[1];
      int * v7964 = v7930->cache_vals;
      int v7965 = v7964[1];
      v7961[v7963] = v7965;
      int * v7967 = v7930->cache_keys;
      int * v7968 = v7930->cache_keys;
      int v7969 = v7968[0];
      v7967[1] = v7969;
      int * v7971 = v7930->cache_vals;
      int * v7972 = v7930->cache_vals;
      int v7973 = v7972[0];
      v7971[1] = v7973;
      int * v7975 = v7930->cache_keys;
      v7975[0] = v8013;
      int * v7977 = v7930->cache_vals;
      v7977[0] = v7960;
      int v7979 = v7930->timer;
      int v8028 = v7979 + 100;
      v7930->timer = v8028;
      v7982 = v7960;
    }
    v7984 = v7982;
  }
  int * v7985 = v7930->regs;
  v7985[7] = v7984;
  struct StateT * v7987 = slot_236(v7930);
  return v7987;
}

struct StateT * slot_471(struct StateT * v18316) {
  int v18317 = v18316->timer;
  int v18327 = v18317 + 1;
  v18316->timer = v18327;
  int * v18319 = v18316->regs;
  int v18320 = v18319[11];
  int * v18321 = v18316->regs;
  int v18322 = v18321[9];
  int * v18323 = v18316->regs;
  int v18333 = v18320 | v18322;
  v18323[11] = v18333;
  struct StateT * v18325 = slot_472(v18316);
  return v18325;
}

struct StateT * slot_419(struct StateT * v17326) {
  int v17327 = v17326->timer;
  int v17335 = v17327 + 1;
  v17326->timer = v17335;
  int * v17329 = v17326->regs;
  int v17330 = v17329[5];
  int * v17331 = v17326->regs;
  int v17339 = v17330 << 18;
  v17331[5] = v17339;
  struct StateT * v17333 = slot_420(v17326);
  return v17333;
}

struct StateT * slot_218(struct StateT * v7157) {
  int * v7158 = v7157->saved_regs;
  int * v7159 = v7157->regs;
  int v7160 = v7159[28];
  v7158[28] = v7160;
  int v7162 = v7157->timer;
  int v7176 = v7162 + 1;
  v7157->timer = v7176;
  int * v7164 = v7157->regs;
  int v7165 = v7164[27];
  int * v7166 = v7157->regs;
  int v7167 = v7166[28];
  int * v7168 = v7157->regs;
  int v7181 = v7165 + v7167;
  v7168[28] = v7181;
  struct StateT * v7170 = slot_220(v7157);
  return v7170;
}

struct StateT * slot_596(struct StateT * v20809) {
  int v20810 = v20809->timer;
  int v20820 = v20810 + 1;
  v20809->timer = v20820;
  int * v20812 = v20809->regs;
  int v20813 = v20812[11];
  int * v20814 = v20809->regs;
  int v20815 = v20814[5];
  int * v20816 = v20809->regs;
  int v20826 = v20813 | v20815;
  v20816[11] = v20826;
  struct StateT * v20818 = slot_597(v20809);
  return v20818;
}

struct StateT * slot_576(struct StateT * v20404) {
  int v20405 = v20404->timer;
  int v20415 = v20405 + 1;
  v20404->timer = v20415;
  int * v20407 = v20404->regs;
  int v20408 = v20407[16];
  int * v20409 = v20404->regs;
  int v20410 = v20409[6];
  int * v20411 = v20404->regs;
  int v20421 = v20408 | v20410;
  v20411[16] = v20421;
  struct StateT * v20413 = slot_577(v20404);
  return v20413;
}

struct StateT * slot_202(struct StateT * v6672) {
  int v6673 = v6672->timer;
  int v6681 = v6673 + 1;
  v6672->timer = v6681;
  int * v6675 = v6672->regs;
  int v6676 = v6675[6];
  int * v6677 = v6672->regs;
  int v6685 = v6676 << 18;
  v6677[6] = v6685;
  struct StateT * v6679 = slot_203(v6672);
  return v6679;
}

struct StateT * slot_336(struct StateT * v13122) {
  int v13123 = v13122->timer;
  int v13177 = v13123 + 1;
  v13122->timer = v13177;
  int * v13125 = v13122->regs;
  int v13126 = v13125[10];
  int * v13127 = v13122->regs;
  int v13128 = v13127[1];
  int * v13129 = v13122->cache_keys;
  int v13130 = v13129[0];
  bool v13184 = v13130 == ((int)((unsigned int)(v13126 + 56) >> 2));
  int v13174;
  if (v13184) {
    int * v13131 = v13122->cache_vals;
    v13131[0] = v13128;
    v13174 = v13128;
  } else {
    int * v13134 = v13122->cache_keys;
    int v13135 = v13134[1];
    bool v13188 = v13135 == ((int)((unsigned int)(v13126 + 56) >> 2));
    int v13172;
    if (v13188) {
      int * v13136 = v13122->cache_keys;
      int * v13137 = v13122->cache_keys;
      int v13138 = v13137[0];
      v13136[1] = v13138;
      int * v13140 = v13122->cache_vals;
      int * v13141 = v13122->cache_vals;
      int v13142 = v13141[0];
      v13140[1] = v13142;
      int * v13144 = v13122->cache_keys;
      int v13196 = (int)((unsigned int)(v13126 + 56) >> 2);
      v13144[0] = v13196;
      int * v13146 = v13122->cache_vals;
      v13146[0] = v13128;
      int v13148 = v13122->timer;
      int v13199 = v13148 + 1;
      v13122->timer = v13199;
      v13172 = v13128;
    } else {
      int * v13151 = v13122->mem;
      int * v13152 = v13122->cache_keys;
      int v13153 = v13152[1];
      int * v13154 = v13122->cache_vals;
      int v13155 = v13154[1];
      v13151[v13153] = v13155;
      int * v13157 = v13122->cache_keys;
      int * v13158 = v13122->cache_keys;
      int v13159 = v13158[0];
      v13157[1] = v13159;
      int * v13161 = v13122->cache_vals;
      int * v13162 = v13122->cache_vals;
      int v13163 = v13162[0];
      v13161[1] = v13163;
      int * v13165 = v13122->cache_keys;
      int v13212 = (int)((unsigned int)(v13126 + 56) >> 2);
      v13165[0] = v13212;
      int * v13167 = v13122->cache_vals;
      v13167[0] = v13128;
      int v13169 = v13122->timer;
      int v13215 = v13169 + 100;
      v13122->timer = v13215;
      v13172 = v13128;
    }
    v13174 = v13172;
  }
  struct StateT * v13175 = slot_339(v13122);
  return v13175;
}

struct StateT * slot_230(struct StateT * v7666) {
  int * v7667 = v7666->saved_regs;
  int * v7668 = v7666->regs;
  int v7669 = v7668[7];
  v7667[7] = v7669;
  int v7671 = v7666->timer;
  int v7733 = v7671 + 1;
  v7666->timer = v7733;
  int * v7673 = v7666->regs;
  int v7674 = v7673[2];
  int * v7675 = v7666->cache_keys;
  int v7676 = v7675[0];
  bool v7738 = v7676 == ((int)((unsigned int)(v7674 + 12) >> 2));
  int v7724;
  if (v7738) {
    int * v7677 = v7666->cache_vals;
    int v7678 = v7677[0];
    v7724 = v7678;
  } else {
    int * v7680 = v7666->cache_keys;
    int v7681 = v7680[1];
    bool v7743 = v7681 == ((int)((unsigned int)(v7674 + 12) >> 2));
    int v7722;
    if (v7743) {
      int * v7682 = v7666->cache_vals;
      int v7683 = v7682[1];
      int * v7684 = v7666->cache_keys;
      int * v7685 = v7666->cache_keys;
      int v7686 = v7685[0];
      v7684[1] = v7686;
      int * v7688 = v7666->cache_vals;
      int * v7689 = v7666->cache_vals;
      int v7690 = v7689[0];
      v7688[1] = v7690;
      int * v7692 = v7666->cache_keys;
      int v7752 = (int)((unsigned int)(v7674 + 12) >> 2);
      v7692[0] = v7752;
      int * v7694 = v7666->cache_vals;
      v7694[0] = v7683;
      int v7696 = v7666->timer;
      int v7755 = v7696 + 1;
      v7666->timer = v7755;
      v7722 = v7683;
    } else {
      int * v7699 = v7666->mem;
      int v7757 = (int)((unsigned int)(v7674 + 12) >> 2);
      int v7700 = v7699[v7757];
      int * v7701 = v7666->mem;
      int * v7702 = v7666->cache_keys;
      int v7703 = v7702[1];
      int * v7704 = v7666->cache_vals;
      int v7705 = v7704[1];
      v7701[v7703] = v7705;
      int * v7707 = v7666->cache_keys;
      int * v7708 = v7666->cache_keys;
      int v7709 = v7708[0];
      v7707[1] = v7709;
      int * v7711 = v7666->cache_vals;
      int * v7712 = v7666->cache_vals;
      int v7713 = v7712[0];
      v7711[1] = v7713;
      int * v7715 = v7666->cache_keys;
      v7715[0] = v7757;
      int * v7717 = v7666->cache_vals;
      v7717[0] = v7700;
      int v7719 = v7666->timer;
      int v7772 = v7719 + 100;
      v7666->timer = v7772;
      v7722 = v7700;
    }
    v7724 = v7722;
  }
  int * v7725 = v7666->regs;
  v7725[7] = v7724;
  struct StateT * v7727 = slot_232(v7666);
  return v7727;
}

struct StateT * slot_598(struct StateT * v20846) {
  int v20847 = v20846->timer;
  int v20855 = v20847 + 1;
  v20846->timer = v20855;
  int * v20849 = v20846->regs;
  int v20850 = v20849[16];
  int * v20851 = v20846->regs;
  int v20859 = v20850 << 7;
  v20851[16] = v20859;
  struct StateT * v20853 = slot_599(v20846);
  return v20853;
}

struct StateT * slot_294(struct StateT * v10264) {
  int v10265 = v10264->timer;
  int v10319 = v10265 + 1;
  v10264->timer = v10319;
  int * v10267 = v10264->regs;
  int v10268 = v10267[10];
  int * v10269 = v10264->regs;
  int v10270 = v10269[15];
  int * v10271 = v10264->cache_keys;
  int v10272 = v10271[0];
  bool v10326 = v10272 == ((int)((unsigned int)v10268 >> 2));
  int v10316;
  if (v10326) {
    int * v10273 = v10264->cache_vals;
    v10273[0] = v10270;
    v10316 = v10270;
  } else {
    int * v10276 = v10264->cache_keys;
    int v10277 = v10276[1];
    bool v10331 = v10277 == ((int)((unsigned int)v10268 >> 2));
    int v10314;
    if (v10331) {
      int * v10278 = v10264->cache_keys;
      int * v10279 = v10264->cache_keys;
      int v10280 = v10279[0];
      v10278[1] = v10280;
      int * v10282 = v10264->cache_vals;
      int * v10283 = v10264->cache_vals;
      int v10284 = v10283[0];
      v10282[1] = v10284;
      int * v10286 = v10264->cache_keys;
      int v10339 = (int)((unsigned int)v10268 >> 2);
      v10286[0] = v10339;
      int * v10288 = v10264->cache_vals;
      v10288[0] = v10270;
      int v10290 = v10264->timer;
      int v10342 = v10290 + 1;
      v10264->timer = v10342;
      v10314 = v10270;
    } else {
      int * v10293 = v10264->mem;
      int * v10294 = v10264->cache_keys;
      int v10295 = v10294[1];
      int * v10296 = v10264->cache_vals;
      int v10297 = v10296[1];
      v10293[v10295] = v10297;
      int * v10299 = v10264->cache_keys;
      int * v10300 = v10264->cache_keys;
      int v10301 = v10300[0];
      v10299[1] = v10301;
      int * v10303 = v10264->cache_vals;
      int * v10304 = v10264->cache_vals;
      int v10305 = v10304[0];
      v10303[1] = v10305;
      int * v10307 = v10264->cache_keys;
      int v10355 = (int)((unsigned int)v10268 >> 2);
      v10307[0] = v10355;
      int * v10309 = v10264->cache_vals;
      v10309[0] = v10270;
      int v10311 = v10264->timer;
      int v10358 = v10311 + 100;
      v10264->timer = v10358;
      v10314 = v10270;
    }
    v10316 = v10314;
  }
  struct StateT * v10317 = slot_297(v10264);
  return v10317;
}

struct StateT * slot_408(struct StateT * v17129) {
  int v17130 = v17129->timer;
  int v17140 = v17130 + 1;
  v17129->timer = v17140;
  int * v17132 = v17129->regs;
  int v17133 = v17132[8];
  int * v17134 = v17129->regs;
  int v17135 = v17134[25];
  int * v17136 = v17129->regs;
  int v17147 = v17133 + v17135;
  v17136[5] = v17147;
  struct StateT * v17138 = slot_409(v17129);
  return v17138;
}

struct StateT * slot_342(struct StateT * v13550) {
  int v13551 = v13550->timer;
  int v13609 = v13551 + 1;
  v13550->timer = v13609;
  int * v13553 = v13550->regs;
  int v13554 = v13553[2];
  int * v13555 = v13550->cache_keys;
  int v13556 = v13555[0];
  bool v13614 = v13556 == ((int)((unsigned int)(v13554 + 92) >> 2));
  int v13604;
  if (v13614) {
    int * v13557 = v13550->cache_vals;
    int v13558 = v13557[0];
    v13604 = v13558;
  } else {
    int * v13560 = v13550->cache_keys;
    int v13561 = v13560[1];
    bool v13619 = v13561 == ((int)((unsigned int)(v13554 + 92) >> 2));
    int v13602;
    if (v13619) {
      int * v13562 = v13550->cache_vals;
      int v13563 = v13562[1];
      int * v13564 = v13550->cache_keys;
      int * v13565 = v13550->cache_keys;
      int v13566 = v13565[0];
      v13564[1] = v13566;
      int * v13568 = v13550->cache_vals;
      int * v13569 = v13550->cache_vals;
      int v13570 = v13569[0];
      v13568[1] = v13570;
      int * v13572 = v13550->cache_keys;
      int v13628 = (int)((unsigned int)(v13554 + 92) >> 2);
      v13572[0] = v13628;
      int * v13574 = v13550->cache_vals;
      v13574[0] = v13563;
      int v13576 = v13550->timer;
      int v13631 = v13576 + 1;
      v13550->timer = v13631;
      v13602 = v13563;
    } else {
      int * v13579 = v13550->mem;
      int v13633 = (int)((unsigned int)(v13554 + 92) >> 2);
      int v13580 = v13579[v13633];
      int * v13581 = v13550->mem;
      int * v13582 = v13550->cache_keys;
      int v13583 = v13582[1];
      int * v13584 = v13550->cache_vals;
      int v13585 = v13584[1];
      v13581[v13583] = v13585;
      int * v13587 = v13550->cache_keys;
      int * v13588 = v13550->cache_keys;
      int v13589 = v13588[0];
      v13587[1] = v13589;
      int * v13591 = v13550->cache_vals;
      int * v13592 = v13550->cache_vals;
      int v13593 = v13592[0];
      v13591[1] = v13593;
      int * v13595 = v13550->cache_keys;
      v13595[0] = v13633;
      int * v13597 = v13550->cache_vals;
      v13597[0] = v13580;
      int v13599 = v13550->timer;
      int v13648 = v13599 + 100;
      v13550->timer = v13648;
      v13602 = v13580;
    }
    v13604 = v13602;
  }
  int * v13605 = v13550->regs;
  v13605[1] = v13604;
  struct StateT * v13607 = slot_345(v13550);
  return v13607;
}

struct StateT * slot_488(struct StateT * v18638) {
  int v18639 = v18638->timer;
  int v18649 = v18639 + 1;
  v18638->timer = v18649;
  int * v18641 = v18638->regs;
  int v18642 = v18641[1];
  int * v18643 = v18638->regs;
  int v18644 = v18643[24];
  int * v18645 = v18638->regs;
  int v18656 = v18642 + v18644;
  v18645[8] = v18656;
  struct StateT * v18647 = slot_489(v18638);
  return v18647;
}

struct StateT * slot_439(struct StateT * v17703) {
  int v17704 = v17703->timer;
  int v17712 = v17704 + 1;
  v17703->timer = v17712;
  int * v17706 = v17703->regs;
  int v17707 = v17706[17];
  int * v17708 = v17703->regs;
  int v17716 = v17707 << 7;
  v17708[17] = v17716;
  struct StateT * v17710 = slot_440(v17703);
  return v17710;
}

struct StateT * slot_389(struct StateT * v16802) {
  int v16803 = v16802->timer;
  int v16811 = v16803 + 1;
  v16802->timer = v16811;
  int * v16805 = v16802->regs;
  int v16806 = v16805[2];
  int * v16807 = v16802->regs;
  int v16815 = v16806 + 96;
  v16807[2] = v16815;
  struct StateT * v16809 = slot_391(v16802);
  return v16809;
}

struct StateT * slot_678(struct StateT * v22789) {
  int v22790 = v22789->timer;
  int v22800 = v22790 + 1;
  v22789->timer = v22800;
  int * v22792 = v22789->regs;
  int v22793 = v22792[25];
  int * v22794 = v22789->regs;
  int v22795 = v22794[7];
  int * v22796 = v22789->regs;
  int v22806 = v22793 + v22795;
  v22796[25] = v22806;
  struct StateT * v22798 = slot_679(v22789);
  return v22798;
}

struct StateT * slot_479(struct StateT * v18459) {
  int v18460 = v18459->timer;
  int v18468 = v18460 + 1;
  v18459->timer = v18468;
  int * v18462 = v18459->regs;
  int v18463 = v18462[8];
  int * v18464 = v18459->regs;
  int v18472 = v18463 << 13;
  v18464[8] = v18472;
  struct StateT * v18466 = slot_480(v18459);
  return v18466;
}

struct StateT * slot_138(struct StateT * v5470) {
  int v5471 = v5470->timer;
  int v5479 = v5471 + 1;
  v5470->timer = v5479;
  int * v5473 = v5470->regs;
  int v5474 = v5473[11];
  int * v5475 = v5470->regs;
  int v5484 = (int)((unsigned int)v5474 >> 25);
  v5475[5] = v5484;
  struct StateT * v5477 = slot_139(v5470);
  return v5477;
}

struct StateT * slot_483(struct StateT * v18535) {
  int v18536 = v18535->timer;
  int v18546 = v18536 + 1;
  v18535->timer = v18546;
  int * v18538 = v18535->regs;
  int v18539 = v18538[13];
  int * v18540 = v18535->regs;
  int v18541 = v18540[6];
  int * v18542 = v18535->regs;
  int v18552 = v18539 ^ v18541;
  v18542[13] = v18552;
  struct StateT * v18544 = slot_484(v18535);
  return v18544;
}

struct StateT * slot_649(struct StateT * v21813) {
  int v21814 = v21813->timer;
  int v21824 = v21814 + 1;
  v21813->timer = v21824;
  int * v21816 = v21813->regs;
  int v21817 = v21816[13];
  int * v21818 = v21813->regs;
  int v21819 = v21818[26];
  int * v21820 = v21813->regs;
  int v21831 = v21817 + v21819;
  v21820[6] = v21831;
  struct StateT * v21822 = slot_650(v21813);
  return v21822;
}

struct StateT * slot_196(struct StateT * v6566) {
  int v6567 = v6566->timer;
  int v6575 = v6567 + 1;
  v6566->timer = v6575;
  int * v6569 = v6566->regs;
  int v6570 = v6569[11];
  int * v6571 = v6566->regs;
  int v6579 = v6570 << 18;
  v6571[11] = v6579;
  struct StateT * v6573 = slot_197(v6566);
  return v6573;
}

struct StateT * slot_172(struct StateT * v6110) {
  int v6111 = v6110->timer;
  int v6121 = v6111 + 1;
  v6110->timer = v6121;
  int * v6113 = v6110->regs;
  int v6114 = v6113[25];
  int * v6115 = v6110->regs;
  int v6116 = v6115[5];
  int * v6117 = v6110->regs;
  int v6128 = v6114 + v6116;
  v6117[15] = v6128;
  struct StateT * v6119 = slot_173(v6110);
  return v6119;
}

struct StateT * slot_425(struct StateT * v17443) {
  int v17444 = v17443->timer;
  int v17454 = v17444 + 1;
  v17443->timer = v17454;
  int * v17446 = v17443->regs;
  int v17447 = v17446[21];
  int * v17448 = v17443->regs;
  int v17449 = v17448[14];
  int * v17450 = v17443->regs;
  int v17461 = v17447 + v17449;
  v17450[15] = v17461;
  struct StateT * v17452 = slot_426(v17443);
  return v17452;
}

struct StateT * slot_443(struct StateT * v17781) {
  int v17782 = v17781->timer;
  int v17792 = v17782 + 1;
  v17781->timer = v17792;
  int * v17784 = v17781->regs;
  int v17785 = v17784[8];
  int * v17786 = v17781->regs;
  int v17787 = v17786[16];
  int * v17788 = v17781->regs;
  int v17799 = v17785 ^ v17787;
  v17788[17] = v17799;
  struct StateT * v17790 = slot_444(v17781);
  return v17790;
}

struct StateT * slot_131(struct StateT * v5326) {
  int v5327 = v5326->timer;
  int v5337 = v5327 + 1;
  v5326->timer = v5337;
  int * v5329 = v5326->regs;
  int v5330 = v5329[21];
  int * v5331 = v5326->regs;
  int v5332 = v5331[14];
  int * v5333 = v5326->regs;
  int v5344 = v5330 + v5332;
  v5333[15] = v5344;
  struct StateT * v5335 = slot_132(v5326);
  return v5335;
}

struct StateT * slot_8(struct StateT * v703) {
  int v704 = v703->timer;
  int v758 = v704 + 1;
  v703->timer = v758;
  int * v706 = v703->regs;
  int v707 = v706[2];
  int * v708 = v703->regs;
  int v709 = v708[22];
  int * v710 = v703->cache_keys;
  int v711 = v710[0];
  bool v765 = v711 == ((int)((unsigned int)(v707 + 64) >> 2));
  int v755;
  if (v765) {
    int * v712 = v703->cache_vals;
    v712[0] = v709;
    v755 = v709;
  } else {
    int * v715 = v703->cache_keys;
    int v716 = v715[1];
    bool v770 = v716 == ((int)((unsigned int)(v707 + 64) >> 2));
    int v753;
    if (v770) {
      int * v717 = v703->cache_keys;
      int * v718 = v703->cache_keys;
      int v719 = v718[0];
      v717[1] = v719;
      int * v721 = v703->cache_vals;
      int * v722 = v703->cache_vals;
      int v723 = v722[0];
      v721[1] = v723;
      int * v725 = v703->cache_keys;
      int v778 = (int)((unsigned int)(v707 + 64) >> 2);
      v725[0] = v778;
      int * v727 = v703->cache_vals;
      v727[0] = v709;
      int v729 = v703->timer;
      int v781 = v729 + 1;
      v703->timer = v781;
      v753 = v709;
    } else {
      int * v732 = v703->mem;
      int * v733 = v703->cache_keys;
      int v734 = v733[1];
      int * v735 = v703->cache_vals;
      int v736 = v735[1];
      v732[v734] = v736;
      int * v738 = v703->cache_keys;
      int * v739 = v703->cache_keys;
      int v740 = v739[0];
      v738[1] = v740;
      int * v742 = v703->cache_vals;
      int * v743 = v703->cache_vals;
      int v744 = v743[0];
      v742[1] = v744;
      int * v746 = v703->cache_keys;
      int v794 = (int)((unsigned int)(v707 + 64) >> 2);
      v746[0] = v794;
      int * v748 = v703->cache_vals;
      v748[0] = v709;
      int v750 = v703->timer;
      int v797 = v750 + 100;
      v703->timer = v797;
      v753 = v709;
    }
    v755 = v753;
  }
  struct StateT * v756 = slot_9(v703);
  return v756;
}

struct StateT * slot_534(struct StateT * v19552) {
  int v19553 = v19552->timer;
  int v19561 = v19553 + 1;
  v19552->timer = v19561;
  int * v19555 = v19552->regs;
  int v19556 = v19555[8];
  int * v19557 = v19552->regs;
  int v19566 = (int)((unsigned int)v19556 >> 23);
  v19557[20] = v19566;
  struct StateT * v19559 = slot_535(v19552);
  return v19559;
}

struct StateT * slot_597(struct StateT * v20829) {
  int v20830 = v20829->timer;
  int v20838 = v20830 + 1;
  v20829->timer = v20838;
  int * v20832 = v20829->regs;
  int v20833 = v20832[16];
  int * v20834 = v20829->regs;
  int v20843 = (int)((unsigned int)v20833 >> 25);
  v20834[5] = v20843;
  struct StateT * v20836 = slot_598(v20829);
  return v20836;
}

struct StateT * slot_180(struct StateT * v6259) {
  int v6260 = v6259->timer;
  int v6270 = v6260 + 1;
  v6259->timer = v6270;
  int * v6262 = v6259->regs;
  int v6263 = v6262[15];
  int * v6264 = v6259->regs;
  int v6265 = v6264[9];
  int * v6266 = v6259->regs;
  int v6276 = v6263 | v6265;
  v6266[15] = v6276;
  struct StateT * v6268 = slot_181(v6259);
  return v6268;
}

struct StateT * slot_504(struct StateT * v18932) {
  int v18933 = v18932->timer;
  int v18943 = v18933 + 1;
  v18932->timer = v18943;
  int * v18935 = v18932->regs;
  int v18936 = v18935[22];
  int * v18937 = v18932->regs;
  int v18938 = v18937[8];
  int * v18939 = v18932->regs;
  int v18949 = v18936 ^ v18938;
  v18939[22] = v18949;
  struct StateT * v18941 = slot_505(v18932);
  return v18941;
}

struct StateT * slot_512(struct StateT * v19112) {
  int v19113 = v19112->timer;
  int v19121 = v19113 + 1;
  v19112->timer = v19121;
  int * v19115 = v19112->regs;
  int v19116 = v19115[15];
  int * v19117 = v19112->regs;
  int v19125 = v19116 << 7;
  v19117[15] = v19125;
  struct StateT * v19119 = slot_513(v19112);
  return v19119;
}

struct StateT * slot_496(struct StateT * v18782) {
  int v18783 = v18782->timer;
  int v18791 = v18783 + 1;
  v18782->timer = v18791;
  int * v18785 = v18782->regs;
  int v18786 = v18785[6];
  int * v18787 = v18782->regs;
  int v18795 = v18786 << 18;
  v18787[6] = v18795;
  struct StateT * v18789 = slot_497(v18782);
  return v18789;
}

struct StateT * slot_494(struct StateT * v18745) {
  int v18746 = v18745->timer;
  int v18756 = v18746 + 1;
  v18745->timer = v18756;
  int * v18748 = v18745->regs;
  int v18749 = v18748[15];
  int * v18750 = v18745->regs;
  int v18751 = v18750[9];
  int * v18752 = v18745->regs;
  int v18762 = v18749 | v18751;
  v18752[15] = v18762;
  struct StateT * v18754 = slot_495(v18745);
  return v18754;
}

struct StateT * slot_607(struct StateT * v21019) {
  int v21020 = v21019->timer;
  int v21030 = v21020 + 1;
  v21019->timer = v21030;
  int * v21022 = v21019->regs;
  int v21023 = v21022[23];
  int * v21024 = v21019->regs;
  int v21025 = v21024[21];
  int * v21026 = v21019->regs;
  int v21037 = v21023 + v21025;
  v21026[11] = v21037;
  struct StateT * v21028 = slot_608(v21019);
  return v21028;
}

struct StateT * slot_242(struct StateT * v8444) {
  int v8445 = v8444->timer;
  int v8503 = v8445 + 1;
  v8444->timer = v8503;
  int * v8447 = v8444->regs;
  int v8448 = v8447[2];
  int * v8449 = v8444->cache_keys;
  int v8450 = v8449[0];
  bool v8508 = v8450 == ((int)((unsigned int)(v8448 + 24) >> 2));
  int v8498;
  if (v8508) {
    int * v8451 = v8444->cache_vals;
    int v8452 = v8451[0];
    v8498 = v8452;
  } else {
    int * v8454 = v8444->cache_keys;
    int v8455 = v8454[1];
    bool v8513 = v8455 == ((int)((unsigned int)(v8448 + 24) >> 2));
    int v8496;
    if (v8513) {
      int * v8456 = v8444->cache_vals;
      int v8457 = v8456[1];
      int * v8458 = v8444->cache_keys;
      int * v8459 = v8444->cache_keys;
      int v8460 = v8459[0];
      v8458[1] = v8460;
      int * v8462 = v8444->cache_vals;
      int * v8463 = v8444->cache_vals;
      int v8464 = v8463[0];
      v8462[1] = v8464;
      int * v8466 = v8444->cache_keys;
      int v8522 = (int)((unsigned int)(v8448 + 24) >> 2);
      v8466[0] = v8522;
      int * v8468 = v8444->cache_vals;
      v8468[0] = v8457;
      int v8470 = v8444->timer;
      int v8525 = v8470 + 1;
      v8444->timer = v8525;
      v8496 = v8457;
    } else {
      int * v8473 = v8444->mem;
      int v8527 = (int)((unsigned int)(v8448 + 24) >> 2);
      int v8474 = v8473[v8527];
      int * v8475 = v8444->mem;
      int * v8476 = v8444->cache_keys;
      int v8477 = v8476[1];
      int * v8478 = v8444->cache_vals;
      int v8479 = v8478[1];
      v8475[v8477] = v8479;
      int * v8481 = v8444->cache_keys;
      int * v8482 = v8444->cache_keys;
      int v8483 = v8482[0];
      v8481[1] = v8483;
      int * v8485 = v8444->cache_vals;
      int * v8486 = v8444->cache_vals;
      int v8487 = v8486[0];
      v8485[1] = v8487;
      int * v8489 = v8444->cache_keys;
      v8489[0] = v8527;
      int * v8491 = v8444->cache_vals;
      v8491[0] = v8474;
      int v8493 = v8444->timer;
      int v8542 = v8493 + 100;
      v8444->timer = v8542;
      v8496 = v8474;
    }
    v8498 = v8496;
  }
  int * v8499 = v8444->regs;
  v8499[7] = v8498;
  struct StateT * v8501 = slot_244(v8444);
  return v8501;
}

struct StateT * slot_605(struct StateT * v20977) {
  int v20978 = v20977->timer;
  int v20988 = v20978 + 1;
  v20977->timer = v20988;
  int * v20980 = v20977->regs;
  int v20981 = v20980[8];
  int * v20982 = v20977->regs;
  int v20983 = v20982[16];
  int * v20984 = v20977->regs;
  int v20995 = v20981 ^ v20983;
  v20984[17] = v20995;
  struct StateT * v20986 = slot_606(v20977);
  return v20986;
}

struct StateT * slot_328(struct StateT * v12579) {
  int v12580 = v12579->timer;
  int v12590 = v12580 + 1;
  v12579->timer = v12590;
  int * v12582 = v12579->regs;
  int v12583 = v12582[15];
  int * v12584 = v12579->regs;
  int v12585 = v12584[20];
  int * v12586 = v12579->regs;
  int v12596 = v12583 | v12585;
  v12586[15] = v12596;
  struct StateT * v12588 = slot_331(v12579);
  return v12588;
}

struct StateT * slot_402(struct StateT * v17004) {
  int v17005 = v17004->timer;
  int v17015 = v17005 + 1;
  v17004->timer = v17015;
  int * v17007 = v17004->regs;
  int v17008 = v17007[23];
  int * v17009 = v17004->regs;
  int v17010 = v17009[8];
  int * v17011 = v17004->regs;
  int v17021 = v17008 ^ v17010;
  v17011[23] = v17021;
  struct StateT * v17013 = slot_403(v17004);
  return v17013;
}

struct StateT * slot_200(struct StateT * v6635) {
  int v6636 = v6635->timer;
  int v6646 = v6636 + 1;
  v6635->timer = v6646;
  int * v6638 = v6635->regs;
  int v6639 = v6638[15];
  int * v6640 = v6635->regs;
  int v6641 = v6640[9];
  int * v6642 = v6635->regs;
  int v6652 = v6639 | v6641;
  v6642[15] = v6652;
  struct StateT * v6644 = slot_201(v6635);
  return v6644;
}

struct StateT * slot_149(struct StateT * v5671) {
  int v5672 = v5671->timer;
  int v5682 = v5672 + 1;
  v5671->timer = v5682;
  int * v5674 = v5671->regs;
  int v5675 = v5674[8];
  int * v5676 = v5671->regs;
  int v5677 = v5676[16];
  int * v5678 = v5671->regs;
  int v5689 = v5675 ^ v5677;
  v5678[17] = v5689;
  struct StateT * v5680 = slot_150(v5671);
  return v5680;
}

struct StateT * slot_527(struct StateT * v19415) {
  int v19416 = v19415->timer;
  int v19426 = v19416 + 1;
  v19415->timer = v19426;
  int * v19418 = v19415->regs;
  int v19419 = v19418[12];
  int * v19420 = v19415->regs;
  int v19421 = v19420[21];
  int * v19422 = v19415->regs;
  int v19433 = v19419 + v19421;
  v19422[15] = v19433;
  struct StateT * v19424 = slot_528(v19415);
  return v19424;
}

struct StateT * slot_5(struct StateT * v409) {
  int v410 = v409->timer;
  int v464 = v410 + 1;
  v409->timer = v464;
  int * v412 = v409->regs;
  int v413 = v412[2];
  int * v414 = v409->regs;
  int v415 = v414[19];
  int * v416 = v409->cache_keys;
  int v417 = v416[0];
  bool v471 = v417 == ((int)((unsigned int)(v413 + 76) >> 2));
  int v461;
  if (v471) {
    int * v418 = v409->cache_vals;
    v418[0] = v415;
    v461 = v415;
  } else {
    int * v421 = v409->cache_keys;
    int v422 = v421[1];
    bool v476 = v422 == ((int)((unsigned int)(v413 + 76) >> 2));
    int v459;
    if (v476) {
      int * v423 = v409->cache_keys;
      int * v424 = v409->cache_keys;
      int v425 = v424[0];
      v423[1] = v425;
      int * v427 = v409->cache_vals;
      int * v428 = v409->cache_vals;
      int v429 = v428[0];
      v427[1] = v429;
      int * v431 = v409->cache_keys;
      int v484 = (int)((unsigned int)(v413 + 76) >> 2);
      v431[0] = v484;
      int * v433 = v409->cache_vals;
      v433[0] = v415;
      int v435 = v409->timer;
      int v487 = v435 + 1;
      v409->timer = v487;
      v459 = v415;
    } else {
      int * v438 = v409->mem;
      int * v439 = v409->cache_keys;
      int v440 = v439[1];
      int * v441 = v409->cache_vals;
      int v442 = v441[1];
      v438[v440] = v442;
      int * v444 = v409->cache_keys;
      int * v445 = v409->cache_keys;
      int v446 = v445[0];
      v444[1] = v446;
      int * v448 = v409->cache_vals;
      int * v449 = v409->cache_vals;
      int v450 = v449[0];
      v448[1] = v450;
      int * v452 = v409->cache_keys;
      int v500 = (int)((unsigned int)(v413 + 76) >> 2);
      v452[0] = v500;
      int * v454 = v409->cache_vals;
      v454[0] = v415;
      int v456 = v409->timer;
      int v503 = v456 + 100;
      v409->timer = v503;
      v459 = v415;
    }
    v461 = v459;
  }
  struct StateT * v462 = slot_6(v409);
  return v462;
}

struct StateT * slot_334(struct StateT * v13008) {
  int v13009 = v13008->timer;
  int v13017 = v13009 + 1;
  v13008->timer = v13017;
  int * v13011 = v13008->regs;
  int v13012 = v13011[8];
  int * v13013 = v13008->regs;
  int v13021 = v13012 << 9;
  v13013[8] = v13021;
  struct StateT * v13015 = slot_337(v13008);
  return v13015;
}

struct StateT * slot_104(struct StateT * v4756) {
  int v4757 = v4756->timer;
  int v4765 = v4757 + 1;
  v4756->timer = v4765;
  int * v4759 = v4756->regs;
  int v4760 = v4759[18];
  int * v4761 = v4756->regs;
  int v4770 = (int)((unsigned int)v4760 >> 19);
  v4761[9] = v4770;
  struct StateT * v4763 = slot_105(v4756);
  return v4763;
}

struct StateT * slot_235(struct StateT * v8035) {
  int v8036 = v8035->timer;
  int v8094 = v8036 + 1;
  v8035->timer = v8094;
  int * v8038 = v8035->regs;
  int v8039 = v8038[2];
  int * v8040 = v8035->cache_keys;
  int v8041 = v8040[0];
  bool v8099 = v8041 == ((int)((unsigned int)(v8039 + 20) >> 2));
  int v8089;
  if (v8099) {
    int * v8042 = v8035->cache_vals;
    int v8043 = v8042[0];
    v8089 = v8043;
  } else {
    int * v8045 = v8035->cache_keys;
    int v8046 = v8045[1];
    bool v8104 = v8046 == ((int)((unsigned int)(v8039 + 20) >> 2));
    int v8087;
    if (v8104) {
      int * v8047 = v8035->cache_vals;
      int v8048 = v8047[1];
      int * v8049 = v8035->cache_keys;
      int * v8050 = v8035->cache_keys;
      int v8051 = v8050[0];
      v8049[1] = v8051;
      int * v8053 = v8035->cache_vals;
      int * v8054 = v8035->cache_vals;
      int v8055 = v8054[0];
      v8053[1] = v8055;
      int * v8057 = v8035->cache_keys;
      int v8113 = (int)((unsigned int)(v8039 + 20) >> 2);
      v8057[0] = v8113;
      int * v8059 = v8035->cache_vals;
      v8059[0] = v8048;
      int v8061 = v8035->timer;
      int v8116 = v8061 + 1;
      v8035->timer = v8116;
      v8087 = v8048;
    } else {
      int * v8064 = v8035->mem;
      int v8118 = (int)((unsigned int)(v8039 + 20) >> 2);
      int v8065 = v8064[v8118];
      int * v8066 = v8035->mem;
      int * v8067 = v8035->cache_keys;
      int v8068 = v8067[1];
      int * v8069 = v8035->cache_vals;
      int v8070 = v8069[1];
      v8066[v8068] = v8070;
      int * v8072 = v8035->cache_keys;
      int * v8073 = v8035->cache_keys;
      int v8074 = v8073[0];
      v8072[1] = v8074;
      int * v8076 = v8035->cache_vals;
      int * v8077 = v8035->cache_vals;
      int v8078 = v8077[0];
      v8076[1] = v8078;
      int * v8080 = v8035->cache_keys;
      v8080[0] = v8118;
      int * v8082 = v8035->cache_vals;
      v8082[0] = v8065;
      int v8084 = v8035->timer;
      int v8133 = v8084 + 100;
      v8035->timer = v8133;
      v8087 = v8065;
    }
    v8089 = v8087;
  }
  int * v8090 = v8035->regs;
  v8090[7] = v8089;
  struct StateT * v8092 = slot_237(v8035);
  return v8092;
}

struct StateT * slot_275(struct StateT * v9929) {
  int v9930 = v9929->timer;
  int v9936 = v9930 + 1;
  v9929->timer = v9936;
  int * v9932 = v9929->regs;
  v9932[30] = 1797283840;
  struct StateT * v9934 = slot_278(v9929);
  return v9934;
}

struct StateT * slot_329(struct StateT * v12599) {
  int v12600 = v12599->timer;
  int v12654 = v12600 + 1;
  v12599->timer = v12654;
  int * v12602 = v12599->regs;
  int v12603 = v12602[10];
  int * v12604 = v12599->regs;
  int v12605 = v12604[13];
  int * v12606 = v12599->cache_keys;
  int v12607 = v12606[0];
  bool v12661 = v12607 == ((int)((unsigned int)(v12603 + 36) >> 2));
  int v12651;
  if (v12661) {
    int * v12608 = v12599->cache_vals;
    v12608[0] = v12605;
    v12651 = v12605;
  } else {
    int * v12611 = v12599->cache_keys;
    int v12612 = v12611[1];
    bool v12666 = v12612 == ((int)((unsigned int)(v12603 + 36) >> 2));
    int v12649;
    if (v12666) {
      int * v12613 = v12599->cache_keys;
      int * v12614 = v12599->cache_keys;
      int v12615 = v12614[0];
      v12613[1] = v12615;
      int * v12617 = v12599->cache_vals;
      int * v12618 = v12599->cache_vals;
      int v12619 = v12618[0];
      v12617[1] = v12619;
      int * v12621 = v12599->cache_keys;
      int v12674 = (int)((unsigned int)(v12603 + 36) >> 2);
      v12621[0] = v12674;
      int * v12623 = v12599->cache_vals;
      v12623[0] = v12605;
      int v12625 = v12599->timer;
      int v12677 = v12625 + 1;
      v12599->timer = v12677;
      v12649 = v12605;
    } else {
      int * v12628 = v12599->mem;
      int * v12629 = v12599->cache_keys;
      int v12630 = v12629[1];
      int * v12631 = v12599->cache_vals;
      int v12632 = v12631[1];
      v12628[v12630] = v12632;
      int * v12634 = v12599->cache_keys;
      int * v12635 = v12599->cache_keys;
      int v12636 = v12635[0];
      v12634[1] = v12636;
      int * v12638 = v12599->cache_vals;
      int * v12639 = v12599->cache_vals;
      int v12640 = v12639[0];
      v12638[1] = v12640;
      int * v12642 = v12599->cache_keys;
      int v12690 = (int)((unsigned int)(v12603 + 36) >> 2);
      v12642[0] = v12690;
      int * v12644 = v12599->cache_vals;
      v12644[0] = v12605;
      int v12646 = v12599->timer;
      int v12693 = v12646 + 100;
      v12599->timer = v12693;
      v12649 = v12605;
    }
    v12651 = v12649;
  }
  struct StateT * v12652 = slot_332(v12599);
  return v12652;
}

struct StateT * slot_428(struct StateT * v17506) {
  int v17507 = v17506->timer;
  int v17517 = v17507 + 1;
  v17506->timer = v17517;
  int * v17509 = v17506->regs;
  int v17510 = v17509[22];
  int * v17511 = v17506->regs;
  int v17512 = v17511[1];
  int * v17513 = v17506->regs;
  int v17524 = v17510 + v17512;
  v17513[17] = v17524;
  struct StateT * v17515 = slot_429(v17506);
  return v17515;
}

struct StateT * slot_395(struct StateT * v16876) {
  int v16877 = v16876->timer;
  int v16885 = v16877 + 1;
  v16876->timer = v16885;
  int * v16879 = v16876->regs;
  int v16880 = v16879[9];
  int * v16881 = v16876->regs;
  int v16890 = (int)((unsigned int)v16880 >> 19);
  v16881[20] = v16890;
  struct StateT * v16883 = slot_396(v16876);
  return v16883;
}

struct StateT * slot_604(struct StateT * v20956) {
  int v20957 = v20956->timer;
  int v20967 = v20957 + 1;
  v20956->timer = v20967;
  int * v20959 = v20956->regs;
  int v20960 = v20959[18];
  int * v20961 = v20956->regs;
  int v20962 = v20961[11];
  int * v20963 = v20956->regs;
  int v20974 = v20960 ^ v20962;
  v20963[5] = v20974;
  struct StateT * v20965 = slot_605(v20956);
  return v20965;
}

struct StateT * slot_660(struct StateT * v22014) {
  int v22015 = v22014->timer;
  int v22023 = v22015 + 1;
  v22014->timer = v22023;
  int * v22017 = v22014->regs;
  int v22018 = v22017[8];
  int * v22019 = v22014->regs;
  int v22028 = (int)((unsigned int)v22018 >> 14);
  v22019[9] = v22028;
  struct StateT * v22021 = slot_661(v22014);
  return v22021;
}

struct StateT * slot_614(struct StateT * v21156) {
  int v21157 = v21156->timer;
  int v21165 = v21157 + 1;
  v21156->timer = v21165;
  int * v21159 = v21156->regs;
  int v21160 = v21159[15];
  int * v21161 = v21156->regs;
  int v21170 = (int)((unsigned int)v21160 >> 23);
  v21161[9] = v21170;
  struct StateT * v21163 = slot_615(v21156);
  return v21163;
}

struct StateT * slot_345(struct StateT * v13768) {
  int v13769 = v13768->timer;
  int v13827 = v13769 + 1;
  v13768->timer = v13827;
  int * v13771 = v13768->regs;
  int v13772 = v13771[2];
  int * v13773 = v13768->cache_keys;
  int v13774 = v13773[0];
  bool v13832 = v13774 == ((int)((unsigned int)(v13772 + 88) >> 2));
  int v13822;
  if (v13832) {
    int * v13775 = v13768->cache_vals;
    int v13776 = v13775[0];
    v13822 = v13776;
  } else {
    int * v13778 = v13768->cache_keys;
    int v13779 = v13778[1];
    bool v13837 = v13779 == ((int)((unsigned int)(v13772 + 88) >> 2));
    int v13820;
    if (v13837) {
      int * v13780 = v13768->cache_vals;
      int v13781 = v13780[1];
      int * v13782 = v13768->cache_keys;
      int * v13783 = v13768->cache_keys;
      int v13784 = v13783[0];
      v13782[1] = v13784;
      int * v13786 = v13768->cache_vals;
      int * v13787 = v13768->cache_vals;
      int v13788 = v13787[0];
      v13786[1] = v13788;
      int * v13790 = v13768->cache_keys;
      int v13846 = (int)((unsigned int)(v13772 + 88) >> 2);
      v13790[0] = v13846;
      int * v13792 = v13768->cache_vals;
      v13792[0] = v13781;
      int v13794 = v13768->timer;
      int v13849 = v13794 + 1;
      v13768->timer = v13849;
      v13820 = v13781;
    } else {
      int * v13797 = v13768->mem;
      int v13851 = (int)((unsigned int)(v13772 + 88) >> 2);
      int v13798 = v13797[v13851];
      int * v13799 = v13768->mem;
      int * v13800 = v13768->cache_keys;
      int v13801 = v13800[1];
      int * v13802 = v13768->cache_vals;
      int v13803 = v13802[1];
      v13799[v13801] = v13803;
      int * v13805 = v13768->cache_keys;
      int * v13806 = v13768->cache_keys;
      int v13807 = v13806[0];
      v13805[1] = v13807;
      int * v13809 = v13768->cache_vals;
      int * v13810 = v13768->cache_vals;
      int v13811 = v13810[0];
      v13809[1] = v13811;
      int * v13813 = v13768->cache_keys;
      v13813[0] = v13851;
      int * v13815 = v13768->cache_vals;
      v13815[0] = v13798;
      int v13817 = v13768->timer;
      int v13866 = v13817 + 100;
      v13768->timer = v13866;
      v13820 = v13798;
    }
    v13822 = v13820;
  }
  int * v13823 = v13768->regs;
  v13823[8] = v13822;
  struct StateT * v13825 = slot_348(v13768);
  return v13825;
}

struct StateT * slot_298(struct StateT * v10500) {
  int v10501 = v10500->timer;
  int v10511 = v10501 + 1;
  v10500->timer = v10511;
  int * v10503 = v10500->regs;
  int v10504 = v10503[12];
  int * v10505 = v10500->regs;
  int v10506 = v10505[15];
  int * v10507 = v10500->regs;
  int v10517 = v10504 ^ v10506;
  v10507[12] = v10517;
  struct StateT * v10509 = slot_301(v10500);
  return v10509;
}

struct StateT * slot_414(struct StateT * v17236) {
  int v17237 = v17236->timer;
  int v17247 = v17237 + 1;
  v17236->timer = v17247;
  int * v17239 = v17236->regs;
  int v17240 = v17239[16];
  int * v17241 = v17236->regs;
  int v17242 = v17241[6];
  int * v17243 = v17236->regs;
  int v17253 = v17240 | v17242;
  v17243[16] = v17253;
  struct StateT * v17245 = slot_415(v17236);
  return v17245;
}

struct StateT * slot_364(struct StateT * v15239) {
  int v15240 = v15239->timer;
  int v15250 = v15240 + 1;
  v15239->timer = v15250;
  int * v15242 = v15239->regs;
  int v15243 = v15242[27];
  int * v15244 = v15239->regs;
  int v15245 = v15244[9];
  int * v15246 = v15239->regs;
  int v15256 = v15243 ^ v15245;
  v15246[27] = v15256;
  struct StateT * v15248 = slot_367(v15239);
  return v15248;
}

struct StateT * slot_626(struct StateT * v21375) {
  int v21376 = v21375->timer;
  int v21386 = v21376 + 1;
  v21375->timer = v21386;
  int * v21378 = v21375->regs;
  int v21379 = v21378[24];
  int * v21380 = v21375->regs;
  int v21381 = v21380[8];
  int * v21382 = v21375->regs;
  int v21392 = v21379 ^ v21381;
  v21382[24] = v21392;
  struct StateT * v21384 = slot_627(v21375);
  return v21384;
}

struct StateT * slot_356(struct StateT * v14569) {
  int v14570 = v14569->timer;
  int v14628 = v14570 + 1;
  v14569->timer = v14628;
  int * v14572 = v14569->regs;
  int v14573 = v14572[2];
  int * v14574 = v14569->cache_keys;
  int v14575 = v14574[0];
  bool v14633 = v14575 == ((int)((unsigned int)(v14573 + 84) >> 2));
  int v14623;
  if (v14633) {
    int * v14576 = v14569->cache_vals;
    int v14577 = v14576[0];
    v14623 = v14577;
  } else {
    int * v14579 = v14569->cache_keys;
    int v14580 = v14579[1];
    bool v14638 = v14580 == ((int)((unsigned int)(v14573 + 84) >> 2));
    int v14621;
    if (v14638) {
      int * v14581 = v14569->cache_vals;
      int v14582 = v14581[1];
      int * v14583 = v14569->cache_keys;
      int * v14584 = v14569->cache_keys;
      int v14585 = v14584[0];
      v14583[1] = v14585;
      int * v14587 = v14569->cache_vals;
      int * v14588 = v14569->cache_vals;
      int v14589 = v14588[0];
      v14587[1] = v14589;
      int * v14591 = v14569->cache_keys;
      int v14647 = (int)((unsigned int)(v14573 + 84) >> 2);
      v14591[0] = v14647;
      int * v14593 = v14569->cache_vals;
      v14593[0] = v14582;
      int v14595 = v14569->timer;
      int v14650 = v14595 + 1;
      v14569->timer = v14650;
      v14621 = v14582;
    } else {
      int * v14598 = v14569->mem;
      int v14652 = (int)((unsigned int)(v14573 + 84) >> 2);
      int v14599 = v14598[v14652];
      int * v14600 = v14569->mem;
      int * v14601 = v14569->cache_keys;
      int v14602 = v14601[1];
      int * v14603 = v14569->cache_vals;
      int v14604 = v14603[1];
      v14600[v14602] = v14604;
      int * v14606 = v14569->cache_keys;
      int * v14607 = v14569->cache_keys;
      int v14608 = v14607[0];
      v14606[1] = v14608;
      int * v14610 = v14569->cache_vals;
      int * v14611 = v14569->cache_vals;
      int v14612 = v14611[0];
      v14610[1] = v14612;
      int * v14614 = v14569->cache_keys;
      v14614[0] = v14652;
      int * v14616 = v14569->cache_vals;
      v14616[0] = v14599;
      int v14618 = v14569->timer;
      int v14667 = v14618 + 100;
      v14569->timer = v14667;
      v14621 = v14599;
    }
    v14623 = v14621;
  }
  int * v14624 = v14569->regs;
  v14624[9] = v14623;
  struct StateT * v14626 = slot_359(v14569);
  return v14626;
}

struct StateT * slot_253(struct StateT * v9090) {
  int v9091 = v9090->timer;
  int v9101 = v9091 + 1;
  v9090->timer = v9101;
  int * v9093 = v9090->regs;
  int v9094 = v9093[11];
  int * v9095 = v9090->regs;
  int v9096 = v9095[23];
  int * v9097 = v9090->regs;
  int v9108 = v9094 + v9096;
  v9097[20] = v9108;
  struct StateT * v9099 = slot_256(v9090);
  return v9099;
}

struct StateT * slot_665(struct StateT * v22108) {
  int v22109 = v22108->timer;
  int v22119 = v22109 + 1;
  v22108->timer = v22119;
  int * v22111 = v22108->regs;
  int v22112 = v22111[19];
  int * v22113 = v22108->regs;
  int v22114 = v22113[6];
  int * v22115 = v22108->regs;
  int v22125 = v22112 ^ v22114;
  v22115[19] = v22125;
  struct StateT * v22117 = slot_666(v22108);
  return v22117;
}

struct StateT * slot_434(struct StateT * v17613) {
  int v17614 = v17613->timer;
  int v17624 = v17614 + 1;
  v17613->timer = v17624;
  int * v17616 = v17613->regs;
  int v17617 = v17616[11];
  int * v17618 = v17613->regs;
  int v17619 = v17618[5];
  int * v17620 = v17613->regs;
  int v17630 = v17617 | v17619;
  v17620[11] = v17630;
  struct StateT * v17622 = slot_435(v17613);
  return v17622;
}

struct StateT * slot_64(struct StateT * v3948) {
  int v3949 = v3948->timer;
  int v3957 = v3949 + 1;
  v3948->timer = v3957;
  int * v3951 = v3948->regs;
  int v3952 = v3951[8];
  int * v3953 = v3948->regs;
  int v3962 = (int)((unsigned int)v3952 >> 25);
  v3953[20] = v3962;
  struct StateT * v3955 = slot_65(v3948);
  return v3955;
}

struct StateT * slot_170(struct StateT * v6069) {
  int v6070 = v6069->timer;
  int v6080 = v6070 + 1;
  v6069->timer = v6080;
  int * v6072 = v6069->regs;
  int v6073 = v6072[24];
  int * v6074 = v6069->regs;
  int v6075 = v6074[8];
  int * v6076 = v6069->regs;
  int v6086 = v6073 ^ v6075;
  v6076[24] = v6086;
  struct StateT * v6078 = slot_171(v6069);
  return v6078;
}

struct StateT * slot_53(struct StateT * v3726) {
  int * v3727 = v3726->saved_regs;
  int * v3728 = v3726->regs;
  int v3729 = v3728[18];
  v3727[18] = v3729;
  int v3731 = v3726->timer;
  int v3745 = v3731 + 1;
  v3726->timer = v3745;
  int * v3733 = v3726->regs;
  int v3734 = v3733[19];
  int * v3735 = v3726->regs;
  int v3736 = v3735[5];
  int * v3737 = v3726->regs;
  int v3751 = v3734 + v3736;
  v3737[18] = v3751;
  struct StateT * v3739 = slot_54(v3726);
  return v3739;
}

struct StateT * slot_522(struct StateT * v19287) {
  int v19288 = v19287->timer;
  int v19298 = v19288 + 1;
  v19287->timer = v19298;
  int * v19290 = v19287->regs;
  int v19291 = v19290[8];
  int * v19292 = v19287->regs;
  int v19293 = v19292[20];
  int * v19294 = v19287->regs;
  int v19304 = v19291 | v19293;
  v19294[8] = v19304;
  struct StateT * v19296 = slot_523(v19287);
  return v19296;
}

struct StateT * slot_80(struct StateT * v4279) {
  int v4280 = v4279->timer;
  int v4290 = v4280 + 1;
  v4279->timer = v4290;
  int * v4282 = v4279->regs;
  int v4283 = v4282[8];
  int * v4284 = v4279->regs;
  int v4285 = v4284[20];
  int * v4286 = v4279->regs;
  int v4296 = v4283 | v4285;
  v4286[8] = v4296;
  struct StateT * v4288 = slot_81(v4279);
  return v4288;
}

struct StateT * slot_503(struct StateT * v18912) {
  int v18913 = v18912->timer;
  int v18923 = v18913 + 1;
  v18912->timer = v18923;
  int * v18915 = v18912->regs;
  int v18916 = v18915[19];
  int * v18917 = v18912->regs;
  int v18918 = v18917[6];
  int * v18919 = v18912->regs;
  int v18929 = v18916 ^ v18918;
  v18919[19] = v18929;
  struct StateT * v18921 = slot_504(v18912);
  return v18921;
}

struct StateT * slot_390(struct StateT * v16818) {
  int v16819 = v16818->timer;
  int v16827 = v16819 + 1;
  v16818->timer = v16827;
  int * v16821 = v16818->regs;
  int v16822 = v16821[8];
  int * v16823 = v16818->regs;
  int v16832 = (int)((unsigned int)v16822 >> 19);
  v16823[20] = v16832;
  struct StateT * v16825 = slot_392(v16818);
  return v16825;
}

struct StateT * slot_44(struct StateT * v3479) {
  int v3480 = v3479->timer;
  int v3488 = v3480 + 1;
  v3479->timer = v3488;
  int * v3482 = v3479->regs;
  int v3483 = v3482[6];
  int * v3484 = v3479->regs;
  v3484[12] = v3483;
  struct StateT * v3486 = slot_45(v3479);
  return v3486;
}

struct StateT * slot_635(struct StateT * v21549) {
  int v21550 = v21549->timer;
  int v21558 = v21550 + 1;
  v21549->timer = v21558;
  int * v21552 = v21549->regs;
  int v21553 = v21552[15];
  int * v21554 = v21549->regs;
  int v21562 = v21553 << 13;
  v21554[15] = v21562;
  struct StateT * v21556 = slot_636(v21549);
  return v21556;
}

struct StateT * slot_137(struct StateT * v5450) {
  int v5451 = v5450->timer;
  int v5461 = v5451 + 1;
  v5450->timer = v5461;
  int * v5453 = v5450->regs;
  int v5454 = v5453[15];
  int * v5455 = v5450->regs;
  int v5456 = v5455[5];
  int * v5457 = v5450->regs;
  int v5467 = v5454 | v5456;
  v5457[15] = v5467;
  struct StateT * v5459 = slot_138(v5450);
  return v5459;
}

struct StateT * slot_386(struct StateT * v16677) {
  int v16678 = v16677->timer;
  int v16736 = v16678 + 1;
  v16677->timer = v16736;
  int * v16680 = v16677->regs;
  int v16681 = v16680[2];
  int * v16682 = v16677->cache_keys;
  int v16683 = v16682[0];
  bool v16741 = v16683 == ((int)((unsigned int)(v16681 + 44) >> 2));
  int v16731;
  if (v16741) {
    int * v16684 = v16677->cache_vals;
    int v16685 = v16684[0];
    v16731 = v16685;
  } else {
    int * v16687 = v16677->cache_keys;
    int v16688 = v16687[1];
    bool v16746 = v16688 == ((int)((unsigned int)(v16681 + 44) >> 2));
    int v16729;
    if (v16746) {
      int * v16689 = v16677->cache_vals;
      int v16690 = v16689[1];
      int * v16691 = v16677->cache_keys;
      int * v16692 = v16677->cache_keys;
      int v16693 = v16692[0];
      v16691[1] = v16693;
      int * v16695 = v16677->cache_vals;
      int * v16696 = v16677->cache_vals;
      int v16697 = v16696[0];
      v16695[1] = v16697;
      int * v16699 = v16677->cache_keys;
      int v16755 = (int)((unsigned int)(v16681 + 44) >> 2);
      v16699[0] = v16755;
      int * v16701 = v16677->cache_vals;
      v16701[0] = v16690;
      int v16703 = v16677->timer;
      int v16758 = v16703 + 1;
      v16677->timer = v16758;
      v16729 = v16690;
    } else {
      int * v16706 = v16677->mem;
      int v16760 = (int)((unsigned int)(v16681 + 44) >> 2);
      int v16707 = v16706[v16760];
      int * v16708 = v16677->mem;
      int * v16709 = v16677->cache_keys;
      int v16710 = v16709[1];
      int * v16711 = v16677->cache_vals;
      int v16712 = v16711[1];
      v16708[v16710] = v16712;
      int * v16714 = v16677->cache_keys;
      int * v16715 = v16677->cache_keys;
      int v16716 = v16715[0];
      v16714[1] = v16716;
      int * v16718 = v16677->cache_vals;
      int * v16719 = v16677->cache_vals;
      int v16720 = v16719[0];
      v16718[1] = v16720;
      int * v16722 = v16677->cache_keys;
      v16722[0] = v16760;
      int * v16724 = v16677->cache_vals;
      v16724[0] = v16707;
      int v16726 = v16677->timer;
      int v16775 = v16726 + 100;
      v16677->timer = v16775;
      v16729 = v16707;
    }
    v16731 = v16729;
  }
  int * v16732 = v16677->regs;
  v16732[27] = v16731;
  struct StateT * v16734 = slot_389(v16677);
  return v16734;
}

struct StateT * slot_122(struct StateT * v5135) {
  int v5136 = v5135->timer;
  int v5144 = v5136 + 1;
  v5135->timer = v5144;
  int * v5138 = v5135->regs;
  int v5139 = v5138[17];
  int * v5140 = v5135->regs;
  int v5148 = v5139 << 18;
  v5140[17] = v5148;
  struct StateT * v5142 = slot_123(v5135);
  return v5142;
}

struct StateT * slot_99(struct StateT * v4667) {
  int v4668 = v4667->timer;
  int v4676 = v4668 + 1;
  v4667->timer = v4676;
  int * v4670 = v4667->regs;
  int v4671 = v4670[8];
  int * v4672 = v4667->regs;
  int v4680 = v4671 << 13;
  v4672[8] = v4680;
  struct StateT * v4674 = slot_100(v4667);
  return v4674;
}

struct StateT * slot_179(struct StateT * v6243) {
  int v6244 = v6243->timer;
  int v6252 = v6244 + 1;
  v6243->timer = v6252;
  int * v6246 = v6243->regs;
  int v6247 = v6246[15];
  int * v6248 = v6243->regs;
  int v6256 = v6247 << 13;
  v6248[15] = v6256;
  struct StateT * v6250 = slot_180(v6243);
  return v6250;
}

struct StateT * slot_219(struct StateT * v7184) {
  int v7185 = v7184->timer;
  int v7195 = v7185 + 1;
  v7184->timer = v7195;
  int * v7187 = v7184->regs;
  int v7188 = v7187[14];
  int * v7189 = v7184->regs;
  int v7190 = v7189[7];
  int * v7191 = v7184->regs;
  int v7201 = v7188 + v7190;
  v7191[14] = v7201;
  struct StateT * v7193 = slot_221(v7184);
  return v7193;
}

struct StateT * slot_664(struct StateT * v22087) {
  int v22088 = v22087->timer;
  int v22098 = v22088 + 1;
  v22087->timer = v22098;
  int * v22090 = v22087->regs;
  int v22091 = v22090[20];
  int * v22092 = v22087->regs;
  int v22093 = v22092[15];
  int * v22094 = v22087->regs;
  int v22105 = v22091 ^ v22093;
  v22094[11] = v22105;
  struct StateT * v22096 = slot_665(v22087);
  return v22096;
}

struct StateT * slot_338(struct StateT * v13239) {
  int v13240 = v13239->timer;
  int v13294 = v13240 + 1;
  v13239->timer = v13294;
  int * v13242 = v13239->regs;
  int v13243 = v13242[10];
  int * v13244 = v13239->regs;
  int v13245 = v13244[16];
  int * v13246 = v13239->cache_keys;
  int v13247 = v13246[0];
  bool v13301 = v13247 == ((int)((unsigned int)(v13243 + 48) >> 2));
  int v13291;
  if (v13301) {
    int * v13248 = v13239->cache_vals;
    v13248[0] = v13245;
    v13291 = v13245;
  } else {
    int * v13251 = v13239->cache_keys;
    int v13252 = v13251[1];
    bool v13306 = v13252 == ((int)((unsigned int)(v13243 + 48) >> 2));
    int v13289;
    if (v13306) {
      int * v13253 = v13239->cache_keys;
      int * v13254 = v13239->cache_keys;
      int v13255 = v13254[0];
      v13253[1] = v13255;
      int * v13257 = v13239->cache_vals;
      int * v13258 = v13239->cache_vals;
      int v13259 = v13258[0];
      v13257[1] = v13259;
      int * v13261 = v13239->cache_keys;
      int v13314 = (int)((unsigned int)(v13243 + 48) >> 2);
      v13261[0] = v13314;
      int * v13263 = v13239->cache_vals;
      v13263[0] = v13245;
      int v13265 = v13239->timer;
      int v13317 = v13265 + 1;
      v13239->timer = v13317;
      v13289 = v13245;
    } else {
      int * v13268 = v13239->mem;
      int * v13269 = v13239->cache_keys;
      int v13270 = v13269[1];
      int * v13271 = v13239->cache_vals;
      int v13272 = v13271[1];
      v13268[v13270] = v13272;
      int * v13274 = v13239->cache_keys;
      int * v13275 = v13239->cache_keys;
      int v13276 = v13275[0];
      v13274[1] = v13276;
      int * v13278 = v13239->cache_vals;
      int * v13279 = v13239->cache_vals;
      int v13280 = v13279[0];
      v13278[1] = v13280;
      int * v13282 = v13239->cache_keys;
      int v13330 = (int)((unsigned int)(v13243 + 48) >> 2);
      v13282[0] = v13330;
      int * v13284 = v13239->cache_vals;
      v13284[0] = v13245;
      int v13286 = v13239->timer;
      int v13333 = v13286 + 100;
      v13239->timer = v13333;
      v13289 = v13245;
    }
    v13291 = v13289;
  }
  struct StateT * v13292 = slot_341(v13239);
  return v13292;
}

struct StateT * slot_22(struct StateT * v2039) {
  int v2040 = v2039->timer;
  int v2098 = v2040 + 1;
  v2039->timer = v2098;
  int * v2042 = v2039->regs;
  int v2043 = v2042[12];
  int * v2044 = v2039->cache_keys;
  int v2045 = v2044[0];
  bool v2103 = v2045 == ((int)((unsigned int)(v2043 + 28) >> 2));
  int v2093;
  if (v2103) {
    int * v2046 = v2039->cache_vals;
    int v2047 = v2046[0];
    v2093 = v2047;
  } else {
    int * v2049 = v2039->cache_keys;
    int v2050 = v2049[1];
    bool v2108 = v2050 == ((int)((unsigned int)(v2043 + 28) >> 2));
    int v2091;
    if (v2108) {
      int * v2051 = v2039->cache_vals;
      int v2052 = v2051[1];
      int * v2053 = v2039->cache_keys;
      int * v2054 = v2039->cache_keys;
      int v2055 = v2054[0];
      v2053[1] = v2055;
      int * v2057 = v2039->cache_vals;
      int * v2058 = v2039->cache_vals;
      int v2059 = v2058[0];
      v2057[1] = v2059;
      int * v2061 = v2039->cache_keys;
      int v2117 = (int)((unsigned int)(v2043 + 28) >> 2);
      v2061[0] = v2117;
      int * v2063 = v2039->cache_vals;
      v2063[0] = v2052;
      int v2065 = v2039->timer;
      int v2120 = v2065 + 1;
      v2039->timer = v2120;
      v2091 = v2052;
    } else {
      int * v2068 = v2039->mem;
      int v2122 = (int)((unsigned int)(v2043 + 28) >> 2);
      int v2069 = v2068[v2122];
      int * v2070 = v2039->mem;
      int * v2071 = v2039->cache_keys;
      int v2072 = v2071[1];
      int * v2073 = v2039->cache_vals;
      int v2074 = v2073[1];
      v2070[v2072] = v2074;
      int * v2076 = v2039->cache_keys;
      int * v2077 = v2039->cache_keys;
      int v2078 = v2077[0];
      v2076[1] = v2078;
      int * v2080 = v2039->cache_vals;
      int * v2081 = v2039->cache_vals;
      int v2082 = v2081[0];
      v2080[1] = v2082;
      int * v2084 = v2039->cache_keys;
      v2084[0] = v2122;
      int * v2086 = v2039->cache_vals;
      v2086[0] = v2069;
      int v2088 = v2039->timer;
      int v2137 = v2088 + 100;
      v2039->timer = v2137;
      v2091 = v2069;
    }
    v2093 = v2091;
  }
  int * v2094 = v2039->regs;
  v2094[1] = v2093;
  struct StateT * v2096 = slot_23(v2039);
  return v2096;
}

struct StateT * slot_563(struct StateT * v20123) {
  int v20124 = v20123->timer;
  int v20134 = v20124 + 1;
  v20123->timer = v20134;
  int * v20126 = v20123->regs;
  int v20127 = v20126[16];
  int * v20128 = v20123->regs;
  int v20129 = v20128[15];
  int * v20130 = v20123->regs;
  int v20141 = v20127 ^ v20129;
  v20130[9] = v20141;
  struct StateT * v20132 = slot_564(v20123);
  return v20132;
}

struct StateT * slot_366(struct StateT * v15364) {
  int v15365 = v15364->timer;
  int v15423 = v15365 + 1;
  v15364->timer = v15423;
  int * v15367 = v15364->regs;
  int v15368 = v15367[2];
  int * v15369 = v15364->cache_keys;
  int v15370 = v15369[0];
  bool v15428 = v15370 == ((int)((unsigned int)(v15368 + 60) >> 2));
  int v15418;
  if (v15428) {
    int * v15371 = v15364->cache_vals;
    int v15372 = v15371[0];
    v15418 = v15372;
  } else {
    int * v15374 = v15364->cache_keys;
    int v15375 = v15374[1];
    bool v15433 = v15375 == ((int)((unsigned int)(v15368 + 60) >> 2));
    int v15416;
    if (v15433) {
      int * v15376 = v15364->cache_vals;
      int v15377 = v15376[1];
      int * v15378 = v15364->cache_keys;
      int * v15379 = v15364->cache_keys;
      int v15380 = v15379[0];
      v15378[1] = v15380;
      int * v15382 = v15364->cache_vals;
      int * v15383 = v15364->cache_vals;
      int v15384 = v15383[0];
      v15382[1] = v15384;
      int * v15386 = v15364->cache_keys;
      int v15442 = (int)((unsigned int)(v15368 + 60) >> 2);
      v15386[0] = v15442;
      int * v15388 = v15364->cache_vals;
      v15388[0] = v15377;
      int v15390 = v15364->timer;
      int v15445 = v15390 + 1;
      v15364->timer = v15445;
      v15416 = v15377;
    } else {
      int * v15393 = v15364->mem;
      int v15447 = (int)((unsigned int)(v15368 + 60) >> 2);
      int v15394 = v15393[v15447];
      int * v15395 = v15364->mem;
      int * v15396 = v15364->cache_keys;
      int v15397 = v15396[1];
      int * v15398 = v15364->cache_vals;
      int v15399 = v15398[1];
      v15395[v15397] = v15399;
      int * v15401 = v15364->cache_keys;
      int * v15402 = v15364->cache_keys;
      int v15403 = v15402[0];
      v15401[1] = v15403;
      int * v15405 = v15364->cache_vals;
      int * v15406 = v15364->cache_vals;
      int v15407 = v15406[0];
      v15405[1] = v15407;
      int * v15409 = v15364->cache_keys;
      v15409[0] = v15447;
      int * v15411 = v15364->cache_vals;
      v15411[0] = v15394;
      int v15413 = v15364->timer;
      int v15462 = v15413 + 100;
      v15364->timer = v15462;
      v15416 = v15394;
    }
    v15418 = v15416;
  }
  int * v15419 = v15364->regs;
  v15419[23] = v15418;
  struct StateT * v15421 = slot_369(v15364);
  return v15421;
}

struct StateT * slot_574(struct StateT * v20371) {
  int v20372 = v20371->timer;
  int v20380 = v20372 + 1;
  v20371->timer = v20380;
  int * v20374 = v20371->regs;
  int v20375 = v20374[16];
  int * v20376 = v20371->regs;
  int v20385 = (int)((unsigned int)v20375 >> 14);
  v20376[6] = v20385;
  struct StateT * v20378 = slot_575(v20371);
  return v20378;
}

struct StateT * slot_139(struct StateT * v5487) {
  int v5488 = v5487->timer;
  int v5496 = v5488 + 1;
  v5487->timer = v5496;
  int * v5490 = v5487->regs;
  int v5491 = v5490[11];
  int * v5492 = v5487->regs;
  int v5500 = v5491 << 7;
  v5492[11] = v5500;
  struct StateT * v5494 = slot_140(v5487);
  return v5494;
}

struct StateT * slot_654(struct StateT * v21908) {
  int v21909 = v21908->timer;
  int v21917 = v21909 + 1;
  v21908->timer = v21917;
  int * v21911 = v21908->regs;
  int v21912 = v21911[15];
  int * v21913 = v21908->regs;
  int v21922 = (int)((unsigned int)v21912 >> 14);
  v21913[9] = v21922;
  struct StateT * v21915 = slot_655(v21908);
  return v21915;
}

struct StateT * slot_608(struct StateT * v21040) {
  int v21041 = v21040->timer;
  int v21051 = v21041 + 1;
  v21040->timer = v21051;
  int * v21043 = v21040->regs;
  int v21044 = v21043[5];
  int * v21045 = v21040->regs;
  int v21046 = v21045[20];
  int * v21047 = v21040->regs;
  int v21058 = v21044 + v21046;
  v21047[15] = v21058;
  struct StateT * v21049 = slot_609(v21040);
  return v21049;
}

struct StateT * slot_438(struct StateT * v17686) {
  int v17687 = v17686->timer;
  int v17695 = v17687 + 1;
  v17686->timer = v17695;
  int * v17689 = v17686->regs;
  int v17690 = v17689[17];
  int * v17691 = v17686->regs;
  int v17700 = (int)((unsigned int)v17690 >> 25);
  v17691[5] = v17700;
  struct StateT * v17693 = slot_439(v17686);
  return v17693;
}

struct StateT * slot_333(struct StateT * v12910) {
  int v12911 = v12910->timer;
  int v12965 = v12911 + 1;
  v12910->timer = v12965;
  int * v12913 = v12910->regs;
  int v12914 = v12913[10];
  int * v12915 = v12910->regs;
  int v12916 = v12915[24];
  int * v12917 = v12910->cache_keys;
  int v12918 = v12917[0];
  bool v12972 = v12918 == ((int)((unsigned int)(v12914 + 52) >> 2));
  int v12962;
  if (v12972) {
    int * v12919 = v12910->cache_vals;
    v12919[0] = v12916;
    v12962 = v12916;
  } else {
    int * v12922 = v12910->cache_keys;
    int v12923 = v12922[1];
    bool v12977 = v12923 == ((int)((unsigned int)(v12914 + 52) >> 2));
    int v12960;
    if (v12977) {
      int * v12924 = v12910->cache_keys;
      int * v12925 = v12910->cache_keys;
      int v12926 = v12925[0];
      v12924[1] = v12926;
      int * v12928 = v12910->cache_vals;
      int * v12929 = v12910->cache_vals;
      int v12930 = v12929[0];
      v12928[1] = v12930;
      int * v12932 = v12910->cache_keys;
      int v12985 = (int)((unsigned int)(v12914 + 52) >> 2);
      v12932[0] = v12985;
      int * v12934 = v12910->cache_vals;
      v12934[0] = v12916;
      int v12936 = v12910->timer;
      int v12988 = v12936 + 1;
      v12910->timer = v12988;
      v12960 = v12916;
    } else {
      int * v12939 = v12910->mem;
      int * v12940 = v12910->cache_keys;
      int v12941 = v12940[1];
      int * v12942 = v12910->cache_vals;
      int v12943 = v12942[1];
      v12939[v12941] = v12943;
      int * v12945 = v12910->cache_keys;
      int * v12946 = v12910->cache_keys;
      int v12947 = v12946[0];
      v12945[1] = v12947;
      int * v12949 = v12910->cache_vals;
      int * v12950 = v12910->cache_vals;
      int v12951 = v12950[0];
      v12949[1] = v12951;
      int * v12953 = v12910->cache_keys;
      int v13001 = (int)((unsigned int)(v12914 + 52) >> 2);
      v12953[0] = v13001;
      int * v12955 = v12910->cache_vals;
      v12955[0] = v12916;
      int v12957 = v12910->timer;
      int v13004 = v12957 + 100;
      v12910->timer = v13004;
      v12960 = v12916;
    }
    v12962 = v12960;
  }
  struct StateT * v12963 = slot_336(v12910);
  return v12963;
}

struct StateT * slot_221(struct StateT * v7224) {
  int v7225 = v7224->timer;
  int v7283 = v7225 + 1;
  v7224->timer = v7283;
  int * v7227 = v7224->regs;
  int v7228 = v7227[2];
  int * v7229 = v7224->cache_keys;
  int v7230 = v7229[0];
  bool v7288 = v7230 == ((int)((unsigned int)(v7228 + 8) >> 2));
  int v7278;
  if (v7288) {
    int * v7231 = v7224->cache_vals;
    int v7232 = v7231[0];
    v7278 = v7232;
  } else {
    int * v7234 = v7224->cache_keys;
    int v7235 = v7234[1];
    bool v7293 = v7235 == ((int)((unsigned int)(v7228 + 8) >> 2));
    int v7276;
    if (v7293) {
      int * v7236 = v7224->cache_vals;
      int v7237 = v7236[1];
      int * v7238 = v7224->cache_keys;
      int * v7239 = v7224->cache_keys;
      int v7240 = v7239[0];
      v7238[1] = v7240;
      int * v7242 = v7224->cache_vals;
      int * v7243 = v7224->cache_vals;
      int v7244 = v7243[0];
      v7242[1] = v7244;
      int * v7246 = v7224->cache_keys;
      int v7302 = (int)((unsigned int)(v7228 + 8) >> 2);
      v7246[0] = v7302;
      int * v7248 = v7224->cache_vals;
      v7248[0] = v7237;
      int v7250 = v7224->timer;
      int v7305 = v7250 + 1;
      v7224->timer = v7305;
      v7276 = v7237;
    } else {
      int * v7253 = v7224->mem;
      int v7307 = (int)((unsigned int)(v7228 + 8) >> 2);
      int v7254 = v7253[v7307];
      int * v7255 = v7224->mem;
      int * v7256 = v7224->cache_keys;
      int v7257 = v7256[1];
      int * v7258 = v7224->cache_vals;
      int v7259 = v7258[1];
      v7255[v7257] = v7259;
      int * v7261 = v7224->cache_keys;
      int * v7262 = v7224->cache_keys;
      int v7263 = v7262[0];
      v7261[1] = v7263;
      int * v7265 = v7224->cache_vals;
      int * v7266 = v7224->cache_vals;
      int v7267 = v7266[0];
      v7265[1] = v7267;
      int * v7269 = v7224->cache_keys;
      v7269[0] = v7307;
      int * v7271 = v7224->cache_vals;
      v7271[0] = v7254;
      int v7273 = v7224->timer;
      int v7322 = v7273 + 100;
      v7224->timer = v7322;
      v7276 = v7254;
    }
    v7278 = v7276;
  }
  int * v7279 = v7224->regs;
  v7279[6] = v7278;
  struct StateT * v7281 = slot_223(v7224);
  return v7281;
}

struct StateT * slot_623(struct StateT * v21315) {
  int v21316 = v21315->timer;
  int v21326 = v21316 + 1;
  v21315->timer = v21326;
  int * v21318 = v21315->regs;
  int v21319 = v21318[27];
  int * v21320 = v21315->regs;
  int v21321 = v21320[11];
  int * v21322 = v21315->regs;
  int v21332 = v21319 ^ v21321;
  v21322[27] = v21332;
  struct StateT * v21324 = slot_624(v21315);
  return v21324;
}

struct StateT * slot_153(struct StateT * v5755) {
  int v5756 = v5755->timer;
  int v5766 = v5756 + 1;
  v5755->timer = v5766;
  int * v5758 = v5755->regs;
  int v5759 = v5758[17];
  int * v5760 = v5755->regs;
  int v5761 = v5760[19];
  int * v5762 = v5755->regs;
  int v5773 = v5759 + v5761;
  v5762[6] = v5773;
  struct StateT * v5764 = slot_154(v5755);
  return v5764;
}

struct StateT * slot_129(struct StateT * v5272) {
  int * v5273 = v5272->saved_regs;
  int * v5274 = v5272->regs;
  int v5275 = v5274[19];
  v5273[19] = v5275;
  int v5277 = v5272->timer;
  int v5291 = v5277 + 1;
  v5272->timer = v5291;
  int * v5279 = v5272->regs;
  int v5280 = v5279[19];
  int * v5281 = v5272->regs;
  int v5282 = v5281[17];
  int * v5283 = v5272->regs;
  int v5296 = v5280 ^ v5282;
  v5283[19] = v5296;
  struct StateT * v5285 = slot_130(v5272);
  return v5285;
}

struct StateT * slot_158(struct StateT * v5850) {
  int v5851 = v5850->timer;
  int v5859 = v5851 + 1;
  v5850->timer = v5859;
  int * v5853 = v5850->regs;
  int v5854 = v5853[15];
  int * v5855 = v5850->regs;
  int v5864 = (int)((unsigned int)v5854 >> 23);
  v5855[9] = v5864;
  struct StateT * v5857 = slot_159(v5850);
  return v5857;
}

struct StateT * slot_311(struct StateT * v11307) {
  int v11308 = v11307->timer;
  int v11362 = v11308 + 1;
  v11307->timer = v11362;
  int * v11310 = v11307->regs;
  int v11311 = v11310[10];
  int * v11312 = v11307->regs;
  int v11313 = v11312[14];
  int * v11314 = v11307->cache_keys;
  int v11315 = v11314[0];
  bool v11369 = v11315 == ((int)((unsigned int)(v11311 + 12) >> 2));
  int v11359;
  if (v11369) {
    int * v11316 = v11307->cache_vals;
    v11316[0] = v11313;
    v11359 = v11313;
  } else {
    int * v11319 = v11307->cache_keys;
    int v11320 = v11319[1];
    bool v11374 = v11320 == ((int)((unsigned int)(v11311 + 12) >> 2));
    int v11357;
    if (v11374) {
      int * v11321 = v11307->cache_keys;
      int * v11322 = v11307->cache_keys;
      int v11323 = v11322[0];
      v11321[1] = v11323;
      int * v11325 = v11307->cache_vals;
      int * v11326 = v11307->cache_vals;
      int v11327 = v11326[0];
      v11325[1] = v11327;
      int * v11329 = v11307->cache_keys;
      int v11382 = (int)((unsigned int)(v11311 + 12) >> 2);
      v11329[0] = v11382;
      int * v11331 = v11307->cache_vals;
      v11331[0] = v11313;
      int v11333 = v11307->timer;
      int v11385 = v11333 + 1;
      v11307->timer = v11385;
      v11357 = v11313;
    } else {
      int * v11336 = v11307->mem;
      int * v11337 = v11307->cache_keys;
      int v11338 = v11337[1];
      int * v11339 = v11307->cache_vals;
      int v11340 = v11339[1];
      v11336[v11338] = v11340;
      int * v11342 = v11307->cache_keys;
      int * v11343 = v11307->cache_keys;
      int v11344 = v11343[0];
      v11342[1] = v11344;
      int * v11346 = v11307->cache_vals;
      int * v11347 = v11307->cache_vals;
      int v11348 = v11347[0];
      v11346[1] = v11348;
      int * v11350 = v11307->cache_keys;
      int v11398 = (int)((unsigned int)(v11311 + 12) >> 2);
      v11350[0] = v11398;
      int * v11352 = v11307->cache_vals;
      v11352[0] = v11313;
      int v11354 = v11307->timer;
      int v11401 = v11354 + 100;
      v11307->timer = v11401;
      v11357 = v11313;
    }
    v11359 = v11357;
  }
  struct StateT * v11360 = slot_314(v11307);
  return v11360;
}

struct StateT * slot_498(struct StateT * v18818) {
  int v18819 = v18818->timer;
  int v18827 = v18819 + 1;
  v18818->timer = v18827;
  int * v18821 = v18818->regs;
  int v18822 = v18821[8];
  int * v18823 = v18818->regs;
  int v18832 = (int)((unsigned int)v18822 >> 14);
  v18823[9] = v18832;
  struct StateT * v18825 = slot_499(v18818);
  return v18825;
}

struct StateT * slot_279(struct StateT * v9994) {
  int v9995 = v9994->timer;
  int v10003 = v9995 + 1;
  v9994->timer = v10003;
  int * v9997 = v9994->regs;
  int v9998 = v9997[30];
  int * v9999 = v9994->regs;
  int v10007 = v9998 + 1396;
  v9999[30] = v10007;
  struct StateT * v10001 = slot_282(v9994);
  return v10001;
}

struct StateT * slot_648(struct StateT * v21792) {
  int v21793 = v21792->timer;
  int v21803 = v21793 + 1;
  v21792->timer = v21803;
  int * v21795 = v21792->regs;
  int v21796 = v21795[12];
  int * v21797 = v21792->regs;
  int v21798 = v21797[25];
  int * v21799 = v21792->regs;
  int v21810 = v21796 + v21798;
  v21799[15] = v21810;
  struct StateT * v21801 = slot_649(v21792);
  return v21801;
}

struct StateT * slot_575(struct StateT * v20388) {
  int v20389 = v20388->timer;
  int v20397 = v20389 + 1;
  v20388->timer = v20397;
  int * v20391 = v20388->regs;
  int v20392 = v20391[16];
  int * v20393 = v20388->regs;
  int v20401 = v20392 << 18;
  v20393[16] = v20401;
  struct StateT * v20395 = slot_576(v20388);
  return v20395;
}

struct StateT * slot_271(struct StateT * v9860) {
  int v9861 = v9860->timer;
  int v9869 = v9861 + 1;
  v9860->timer = v9869;
  int * v9863 = v9860->regs;
  int v9864 = v9863[20];
  int * v9865 = v9860->regs;
  int v9874 = (int)((unsigned int)v9864 >> 25);
  v9865[9] = v9874;
  struct StateT * v9867 = slot_274(v9860);
  return v9867;
}

struct StateT * slot_524(struct StateT * v19334) {
  int * v19335 = v19334->saved_regs;
  int * v19336 = v19334->regs;
  int v19337 = v19336[13];
  v19335[13] = v19337;
  int v19339 = v19334->timer;
  int v19353 = v19339 + 1;
  v19334->timer = v19353;
  int * v19341 = v19334->regs;
  int v19342 = v19341[13];
  int * v19343 = v19334->regs;
  int v19344 = v19343[9];
  int * v19345 = v19334->regs;
  int v19358 = v19342 ^ v19344;
  v19345[13] = v19358;
  struct StateT * v19347 = slot_525(v19334);
  return v19347;
}

struct StateT * slot_505(struct StateT * v18952) {
  int v18953 = v18952->timer;
  int v18961 = v18953 + 1;
  v18952->timer = v18961;
  int * v18955 = v18952->regs;
  int v18956 = v18955[30];
  int * v18957 = v18952->regs;
  int v18965 = v18956 + 1;
  v18957[30] = v18965;
  struct StateT * v18959 = slot_506(v18952);
  return v18959;
}

struct StateT * slot_401(struct StateT * v16983) {
  int v16984 = v16983->timer;
  int v16994 = v16984 + 1;
  v16983->timer = v16994;
  int * v16986 = v16983->regs;
  int v16987 = v16986[16];
  int * v16988 = v16983->regs;
  int v16989 = v16988[15];
  int * v16990 = v16983->regs;
  int v17001 = v16987 ^ v16989;
  v16990[9] = v17001;
  struct StateT * v16992 = slot_402(v16983);
  return v16992;
}

struct StateT * slot_423(struct StateT * v17403) {
  int v17404 = v17403->timer;
  int v17414 = v17404 + 1;
  v17403->timer = v17414;
  int * v17406 = v17403->regs;
  int v17407 = v17406[19];
  int * v17408 = v17403->regs;
  int v17409 = v17408[17];
  int * v17410 = v17403->regs;
  int v17420 = v17407 ^ v17409;
  v17410[19] = v17420;
  struct StateT * v17412 = slot_424(v17403);
  return v17412;
}

struct StateT * slot_532(struct StateT * v19516) {
  int v19517 = v19516->timer;
  int v19525 = v19517 + 1;
  v19516->timer = v19525;
  int * v19519 = v19516->regs;
  int v19520 = v19519[15];
  int * v19521 = v19516->regs;
  int v19529 = v19520 << 9;
  v19521[15] = v19529;
  struct StateT * v19523 = slot_533(v19516);
  return v19523;
}

struct StateT * slot_217(struct StateT * v7144) {
  int v7145 = v7144->timer;
  int v7151 = v7145 + 1;
  v7144->timer = v7151;
  int * v7147 = v7144->regs;
  v7147[15] = 1634762752;
  struct StateT * v7149 = slot_219(v7144);
  return v7149;
}

struct StateT * slot_111(struct StateT * v4907) {
  int v4908 = v4907->timer;
  int v4918 = v4908 + 1;
  v4907->timer = v4918;
  int * v4910 = v4907->regs;
  int v4911 = v4910[9];
  int * v4912 = v4907->regs;
  int v4913 = v4912[26];
  int * v4914 = v4907->regs;
  int v4925 = v4911 + v4913;
  v4914[15] = v4925;
  struct StateT * v4916 = slot_112(v4907);
  return v4916;
}

struct StateT * slot_549(struct StateT * v19861) {
  int v19862 = v19861->timer;
  int v19872 = v19862 + 1;
  v19861->timer = v19872;
  int * v19864 = v19861->regs;
  int v19865 = v19864[27];
  int * v19866 = v19861->regs;
  int v19867 = v19866[1];
  int * v19868 = v19861->regs;
  int v19879 = v19865 + v19867;
  v19868[9] = v19879;
  struct StateT * v19870 = slot_550(v19861);
  return v19870;
}

struct StateT * slot_349(struct StateT * v14096) {
  int v14097 = v14096->timer;
  int v14105 = v14097 + 1;
  v14096->timer = v14105;
  int * v14099 = v14096->regs;
  int v14100 = v14099[18];
  int * v14101 = v14096->regs;
  int v14110 = (int)((unsigned int)v14100 >> 23);
  v14101[20] = v14110;
  struct StateT * v14103 = slot_352(v14096);
  return v14103;
}

struct StateT * slot_291(struct StateT * v10208) {
  int v10209 = v10208->timer;
  int v10219 = v10209 + 1;
  v10208->timer = v10219;
  int * v10211 = v10208->regs;
  int v10212 = v10211[22];
  int * v10213 = v10208->regs;
  int v10214 = v10213[30];
  int * v10215 = v10208->regs;
  int v10225 = v10212 + v10214;
  v10215[30] = v10225;
  struct StateT * v10217 = slot_294(v10208);
  return v10217;
}

struct StateT * slot_147(struct StateT * v5630) {
  int v5631 = v5630->timer;
  int v5641 = v5631 + 1;
  v5630->timer = v5641;
  int * v5633 = v5630->regs;
  int v5634 = v5633[23];
  int * v5635 = v5630->regs;
  int v5636 = v5635[15];
  int * v5637 = v5630->regs;
  int v5647 = v5634 ^ v5636;
  v5637[23] = v5647;
  struct StateT * v5639 = slot_148(v5630);
  return v5639;
}

struct StateT * slot_410(struct StateT * v17167) {
  int v17168 = v17167->timer;
  int v17176 = v17168 + 1;
  v17167->timer = v17176;
  int * v17170 = v17167->regs;
  int v17171 = v17170[15];
  int * v17172 = v17167->regs;
  int v17180 = v17171 << 18;
  v17172[15] = v17180;
  struct StateT * v17174 = slot_411(v17167);
  return v17174;
}

struct StateT * slot_491(struct StateT * v18692) {
  int v18693 = v18692->timer;
  int v18703 = v18693 + 1;
  v18692->timer = v18703;
  int * v18695 = v18692->regs;
  int v18696 = v18695[11];
  int * v18697 = v18692->regs;
  int v18698 = v18697[9];
  int * v18699 = v18692->regs;
  int v18709 = v18696 | v18698;
  v18699[11] = v18709;
  struct StateT * v18701 = slot_492(v18692);
  return v18701;
}

struct StateT * slot_163(struct StateT * v5936) {
  int v5937 = v5936->timer;
  int v5947 = v5937 + 1;
  v5936->timer = v5947;
  int * v5939 = v5936->regs;
  int v5940 = v5939[6];
  int * v5941 = v5936->regs;
  int v5942 = v5941[9];
  int * v5943 = v5936->regs;
  int v5953 = v5940 | v5942;
  v5943[6] = v5953;
  struct StateT * v5945 = slot_164(v5936);
  return v5945;
}

struct StateT * slot_422(struct StateT * v17382) {
  int v17383 = v17382->timer;
  int v17393 = v17383 + 1;
  v17382->timer = v17393;
  int * v17385 = v17382->regs;
  int v17386 = v17385[11];
  int * v17387 = v17382->regs;
  int v17388 = v17387[16];
  int * v17389 = v17382->regs;
  int v17400 = v17386 ^ v17388;
  v17389[20] = v17400;
  struct StateT * v17391 = slot_423(v17382);
  return v17391;
}

struct StateT * slot_448(struct StateT * v17886) {
  int v17887 = v17886->timer;
  int v17897 = v17887 + 1;
  v17886->timer = v17897;
  int * v17889 = v17886->regs;
  int v17890 = v17889[16];
  int * v17891 = v17886->regs;
  int v17892 = v17891[22];
  int * v17893 = v17886->regs;
  int v17904 = v17890 + v17892;
  v17893[8] = v17904;
  struct StateT * v17895 = slot_449(v17886);
  return v17895;
}

struct StateT * slot_204(struct StateT * v6708) {
  int v6709 = v6708->timer;
  int v6717 = v6709 + 1;
  v6708->timer = v6717;
  int * v6711 = v6708->regs;
  int v6712 = v6711[8];
  int * v6713 = v6708->regs;
  int v6722 = (int)((unsigned int)v6712 >> 14);
  v6713[9] = v6722;
  struct StateT * v6715 = slot_205(v6708);
  return v6715;
}

struct StateT * slot_194(struct StateT * v6528) {
  int v6529 = v6528->timer;
  int v6539 = v6529 + 1;
  v6528->timer = v6539;
  int * v6531 = v6528->regs;
  int v6532 = v6531[1];
  int * v6533 = v6528->regs;
  int v6534 = v6533[24];
  int * v6535 = v6528->regs;
  int v6546 = v6532 + v6534;
  v6535[8] = v6546;
  struct StateT * v6537 = slot_195(v6528);
  return v6537;
}

struct StateT * slot_551(struct StateT * v19903) {
  int v19904 = v19903->timer;
  int v19912 = v19904 + 1;
  v19903->timer = v19912;
  int * v19906 = v19903->regs;
  int v19907 = v19906[15];
  int * v19908 = v19903->regs;
  int v19917 = (int)((unsigned int)v19907 >> 19);
  v19908[20] = v19917;
  struct StateT * v19910 = slot_552(v19903);
  return v19910;
}

struct StateT * slot_641(struct StateT * v21655) {
  int v21656 = v21655->timer;
  int v21664 = v21656 + 1;
  v21655->timer = v21664;
  int * v21658 = v21655->regs;
  int v21659 = v21658[8];
  int * v21660 = v21655->regs;
  int v21668 = v21659 << 13;
  v21660[8] = v21668;
  struct StateT * v21662 = slot_642(v21655);
  return v21662;
}

struct StateT * slot_407(struct StateT * v17108) {
  int v17109 = v17108->timer;
  int v17119 = v17109 + 1;
  v17108->timer = v17119;
  int * v17111 = v17108->regs;
  int v17112 = v17111[18];
  int * v17113 = v17108->regs;
  int v17114 = v17113[27];
  int * v17115 = v17108->regs;
  int v17126 = v17112 + v17114;
  v17115[17] = v17126;
  struct StateT * v17117 = slot_408(v17108);
  return v17117;
}

struct StateT * slot_543(struct StateT * v19711) {
  int * v19712 = v19711->saved_regs;
  int * v19713 = v19711->regs;
  int v19714 = v19713[26];
  v19712[26] = v19714;
  int v19716 = v19711->timer;
  int v19730 = v19716 + 1;
  v19711->timer = v19730;
  int * v19718 = v19711->regs;
  int v19719 = v19718[26];
  int * v19720 = v19711->regs;
  int v19721 = v19720[15];
  int * v19722 = v19711->regs;
  int v19735 = v19719 ^ v19721;
  v19722[26] = v19735;
  struct StateT * v19724 = slot_544(v19711);
  return v19724;
}

struct StateT * slot_250(struct StateT * v8944) {
  int v8945 = v8944->timer;
  int v8955 = v8945 + 1;
  v8944->timer = v8955;
  int * v8947 = v8944->regs;
  int v8948 = v8947[21];
  int * v8949 = v8944->regs;
  int v8950 = v8949[16];
  int * v8951 = v8944->regs;
  int v8962 = v8948 + v8950;
  v8951[15] = v8962;
  struct StateT * v8953 = slot_253(v8944);
  return v8953;
}

struct StateT * slot_360(struct StateT * v14904) {
  int v14905 = v14904->timer;
  int v14963 = v14905 + 1;
  v14904->timer = v14963;
  int * v14907 = v14904->regs;
  int v14908 = v14907[2];
  int * v14909 = v14904->cache_keys;
  int v14910 = v14909[0];
  bool v14968 = v14910 == ((int)((unsigned int)(v14908 + 68) >> 2));
  int v14958;
  if (v14968) {
    int * v14911 = v14904->cache_vals;
    int v14912 = v14911[0];
    v14958 = v14912;
  } else {
    int * v14914 = v14904->cache_keys;
    int v14915 = v14914[1];
    bool v14973 = v14915 == ((int)((unsigned int)(v14908 + 68) >> 2));
    int v14956;
    if (v14973) {
      int * v14916 = v14904->cache_vals;
      int v14917 = v14916[1];
      int * v14918 = v14904->cache_keys;
      int * v14919 = v14904->cache_keys;
      int v14920 = v14919[0];
      v14918[1] = v14920;
      int * v14922 = v14904->cache_vals;
      int * v14923 = v14904->cache_vals;
      int v14924 = v14923[0];
      v14922[1] = v14924;
      int * v14926 = v14904->cache_keys;
      int v14982 = (int)((unsigned int)(v14908 + 68) >> 2);
      v14926[0] = v14982;
      int * v14928 = v14904->cache_vals;
      v14928[0] = v14917;
      int v14930 = v14904->timer;
      int v14985 = v14930 + 1;
      v14904->timer = v14985;
      v14956 = v14917;
    } else {
      int * v14933 = v14904->mem;
      int v14987 = (int)((unsigned int)(v14908 + 68) >> 2);
      int v14934 = v14933[v14987];
      int * v14935 = v14904->mem;
      int * v14936 = v14904->cache_keys;
      int v14937 = v14936[1];
      int * v14938 = v14904->cache_vals;
      int v14939 = v14938[1];
      v14935[v14937] = v14939;
      int * v14941 = v14904->cache_keys;
      int * v14942 = v14904->cache_keys;
      int v14943 = v14942[0];
      v14941[1] = v14943;
      int * v14945 = v14904->cache_vals;
      int * v14946 = v14904->cache_vals;
      int v14947 = v14946[0];
      v14945[1] = v14947;
      int * v14949 = v14904->cache_keys;
      v14949[0] = v14987;
      int * v14951 = v14904->cache_vals;
      v14951[0] = v14934;
      int v14953 = v14904->timer;
      int v15002 = v14953 + 100;
      v14904->timer = v15002;
      v14956 = v14934;
    }
    v14958 = v14956;
  }
  int * v14959 = v14904->regs;
  v14959[21] = v14958;
  struct StateT * v14961 = slot_363(v14904);
  return v14961;
}

struct StateT * slot_259(struct StateT * v9382) {
  int v9383 = v9382->timer;
  int v9393 = v9383 + 1;
  v9382->timer = v9393;
  int * v9385 = v9382->regs;
  int v9386 = v9385[22];
  int * v9387 = v9382->regs;
  int v9388 = v9387[17];
  int * v9389 = v9382->regs;
  int v9400 = v9386 + v9388;
  v9389[8] = v9400;
  struct StateT * v9391 = slot_262(v9382);
  return v9391;
}

struct StateT * slot_469(struct StateT * v18283) {
  int v18284 = v18283->timer;
  int v18292 = v18284 + 1;
  v18283->timer = v18292;
  int * v18286 = v18283->regs;
  int v18287 = v18286[11];
  int * v18288 = v18283->regs;
  int v18297 = (int)((unsigned int)v18287 >> 19);
  v18288[9] = v18297;
  struct StateT * v18290 = slot_470(v18283);
  return v18290;
}

struct StateT * slot_117(struct StateT * v5045) {
  int v5046 = v5045->timer;
  int v5056 = v5046 + 1;
  v5045->timer = v5056;
  int * v5048 = v5045->regs;
  int v5049 = v5048[15];
  int * v5050 = v5045->regs;
  int v5051 = v5050[6];
  int * v5052 = v5045->regs;
  int v5062 = v5049 | v5051;
  v5052[15] = v5062;
  struct StateT * v5054 = slot_118(v5045);
  return v5054;
}

struct StateT * slot_667(struct StateT * v22148) {
  int * v22149 = v22148->regs;
  int v22150 = v22149[31];
  int * v22151 = v22148->regs;
  int v22152 = v22151[30];
  bool v22253 = (v22150 ^ -2147483648) >= (v22152 ^ -2147483648);
  struct StateT * v22247;
  if (v22253) {
    struct StateT * v22153 = slot_505(v22148);
    v22247 = v22153;
  } else {
    int v22155 = v22148->timer;
    int v22256 = v22155 + 15;
    v22148->timer = v22256;
    int * v22157 = v22148->saved_regs;
    int v22158 = v22157[15];
    int * v22159 = v22148->regs;
    v22159[15] = v22158;
    int * v22161 = v22148->saved_regs;
    int v22162 = v22161[20];
    int * v22163 = v22148->regs;
    v22163[20] = v22162;
    int * v22165 = v22148->saved_regs;
    int v22166 = v22165[18];
    int * v22167 = v22148->regs;
    v22167[18] = v22166;
    int * v22169 = v22148->saved_regs;
    int v22170 = v22169[8];
    int * v22171 = v22148->regs;
    v22171[8] = v22170;
    int * v22173 = v22148->saved_regs;
    int v22174 = v22173[9];
    int * v22175 = v22148->regs;
    v22175[9] = v22174;
    int * v22177 = v22148->saved_regs;
    int v22178 = v22177[12];
    int * v22179 = v22148->regs;
    v22179[12] = v22178;
    int * v22181 = v22148->saved_regs;
    int v22182 = v22181[13];
    int * v22183 = v22148->regs;
    v22183[13] = v22182;
    int * v22185 = v22148->saved_regs;
    int v22186 = v22185[1];
    int * v22187 = v22148->regs;
    v22187[1] = v22186;
    int * v22189 = v22148->saved_regs;
    int v22190 = v22189[14];
    int * v22191 = v22148->regs;
    v22191[14] = v22190;
    int * v22193 = v22148->saved_regs;
    int v22194 = v22193[26];
    int * v22195 = v22148->regs;
    v22195[26] = v22194;
    int * v22197 = v22148->saved_regs;
    int v22198 = v22197[24];
    int * v22199 = v22148->regs;
    v22199[24] = v22198;
    int * v22201 = v22148->saved_regs;
    int v22202 = v22201[27];
    int * v22203 = v22148->regs;
    v22203[27] = v22202;
    int * v22205 = v22148->saved_regs;
    int v22206 = v22205[25];
    int * v22207 = v22148->regs;
    v22207[25] = v22206;
    int * v22209 = v22148->saved_regs;
    int v22210 = v22209[6];
    int * v22211 = v22148->regs;
    v22211[6] = v22210;
    int * v22213 = v22148->saved_regs;
    int v22214 = v22213[23];
    int * v22215 = v22148->regs;
    v22215[23] = v22214;
    int * v22217 = v22148->saved_regs;
    int v22218 = v22217[16];
    int * v22219 = v22148->regs;
    v22219[16] = v22218;
    int * v22221 = v22148->saved_regs;
    int v22222 = v22221[17];
    int * v22223 = v22148->regs;
    v22223[17] = v22222;
    int * v22225 = v22148->saved_regs;
    int v22226 = v22225[5];
    int * v22227 = v22148->regs;
    v22227[5] = v22226;
    int * v22229 = v22148->saved_regs;
    int v22230 = v22229[21];
    int * v22231 = v22148->regs;
    v22231[21] = v22230;
    int * v22233 = v22148->saved_regs;
    int v22234 = v22233[19];
    int * v22235 = v22148->regs;
    v22235[19] = v22234;
    int * v22237 = v22148->saved_regs;
    int v22238 = v22237[22];
    int * v22239 = v22148->regs;
    v22239[22] = v22238;
    int * v22241 = v22148->saved_regs;
    int v22242 = v22241[11];
    int * v22243 = v22148->regs;
    v22243[11] = v22242;
    struct StateT * v22245 = slot_668(v22148);
    v22247 = v22245;
  }
  return v22247;
}

struct StateT * slot_90(struct StateT * v4486) {
  int * v4487 = v4486->saved_regs;
  int * v4488 = v4486->regs;
  int v4489 = v4488[25];
  v4487[25] = v4489;
  int v4491 = v4486->timer;
  int v4505 = v4491 + 1;
  v4486->timer = v4505;
  int * v4493 = v4486->regs;
  int v4494 = v4493[25];
  int * v4495 = v4486->regs;
  int v4496 = v4495[18];
  int * v4497 = v4486->regs;
  int v4510 = v4494 ^ v4496;
  v4497[25] = v4510;
  struct StateT * v4499 = slot_91(v4486);
  return v4499;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
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
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = bounded(0, 20);
    s2.mem[20 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}