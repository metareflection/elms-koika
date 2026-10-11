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
struct StateT * slot_226(struct StateT * v15546);
struct StateT * slot_167(struct StateT * v8349);
struct StateT * slot_509(struct StateT * v23885);
struct StateT * slot_152(struct StateT * v8115);
struct StateT * slot_429(struct StateT * v22553);
struct StateT * slot_231(struct StateT * v18617);
struct StateT * slot_355(struct StateT * v21342);
struct StateT * slot_92(struct StateT * v7144);
struct StateT * slot_232(struct StateT * v19053);
struct StateT * slot_466(struct StateT * v23188);
struct StateT * slot_304(struct StateT * v20551);
struct StateT * slot_31(struct StateT * v6091);
struct StateT * slot_236(struct StateT * v18194);
struct StateT * slot_241(struct StateT * v19039);
struct StateT * slot_160(struct StateT * v8244);
struct StateT * slot_519(struct StateT * v24039);
struct StateT * slot_150(struct StateT * v8083);
struct StateT * slot_391(struct StateT * v21904);
struct StateT * slot_74(struct StateT * v6844);
struct StateT * slot_262(struct StateT * v19897);
struct StateT * slot_351(struct StateT * v21280);
struct StateT * slot_372(struct StateT * v21606);
struct StateT * slot_403(struct StateT * v22116);
struct StateT * slot_107(struct StateT * v7385);
struct StateT * slot_555(struct StateT * v24599);
struct StateT * slot_541(struct StateT * v24385);
struct StateT * slot_325(struct StateT * v20878);
struct StateT * slot_84(struct StateT * v7000);
struct StateT * slot_28(struct StateT * v6049);
struct StateT * slot_155(struct StateT * v8165);
struct StateT * slot_177(struct StateT * v8511);
struct StateT * slot_517(struct StateT * v24007);
struct StateT * slot_229(struct StateT * v17158);
struct StateT * slot_358(struct StateT * v21391);
struct StateT * slot_465(struct StateT * v23172);
struct StateT * slot_181(struct StateT * v8571);
struct StateT * slot_542(struct StateT * v24402);
struct StateT * slot_154(struct StateT * v8148);
struct StateT * slot_260(struct StateT * v19865);
struct StateT * slot_481(struct StateT * v23449);
struct StateT * slot_305(struct StateT * v20566);
struct StateT * slot_27(struct StateT * v6034);
struct StateT * slot_454(struct StateT * v22967);
struct StateT * slot_34(struct StateT * v6136);
struct StateT * slot_482(struct StateT * v23466);
struct StateT * slot_21(struct StateT * v5572);
struct StateT * slot_406(struct StateT * v22168);
struct StateT * slot_292(struct StateT * v20358);
struct StateT * slot_118(struct StateT * v7590);
struct StateT * slot_525(struct StateT * v24136);
struct StateT * slot_515(struct StateT * v23975);
struct StateT * slot_376(struct StateT * v21670);
struct StateT * slot_373(struct StateT * v21622);
struct StateT * slot_94(struct StateT * v7184);
struct StateT * slot_340(struct StateT * v21113);
struct StateT * slot_146(struct StateT * v8022);
struct StateT * slot_383(struct StateT * v21783);
struct StateT * slot_24(struct StateT * v5993);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v23573);
struct StateT * slot_286(struct StateT * v20268);
struct StateT * slot_520(struct StateT * v24056);
struct StateT * slot_125(struct StateT * v7694);
struct StateT * slot_254(struct StateT * v19766);
struct StateT * slot_148(struct StateT * v8051);
struct StateT * slot_421(struct StateT * v22429);
struct StateT * slot_126(struct StateT * v7710);
struct StateT * slot_363(struct StateT * v21471);
struct StateT * slot_79(struct StateT * v6924);
struct StateT * slot_367(struct StateT * v21532);
struct StateT * slot_437(struct StateT * v22689);
struct StateT * slot_341(struct StateT * v21130);
struct StateT * slot_142(struct StateT * v7961);
struct StateT * slot_416(struct StateT * v22326);
struct StateT * slot_280(struct StateT * v20177);
struct StateT * slot_272(struct StateT * v20046);
struct StateT * slot_47(struct StateT * v6365);
struct StateT * slot_297(struct StateT * v20438);
struct StateT * slot_29(struct StateT * v6064);
struct StateT * slot_314(struct StateT * v20702);
struct StateT * slot_151(struct StateT * v8099);
struct StateT * slot_7(struct StateT * v1906);
struct StateT * slot_124(struct StateT * v7680);
struct StateT * slot_128(struct StateT * v7739);
struct StateT * slot_365(struct StateT * v21502);
struct StateT * slot_441(struct StateT * v22769);
struct StateT * slot_19(struct StateT * v5164);
struct StateT * slot_382(struct StateT * v21769);
struct StateT * slot_523(struct StateT * v24107);
struct StateT * slot_87(struct StateT * v7045);
struct StateT * slot_452(struct StateT * v22938);
struct StateT * slot_67(struct StateT * v6705);
struct StateT * slot_81(struct StateT * v6955);
struct StateT * slot_546(struct StateT * v24464);
struct StateT * slot_556(struct StateT * v24615);
struct StateT * slot_337(struct StateT * v21062);
struct StateT * slot_32(struct StateT * v6104);
struct StateT * slot_233(struct StateT * v17362);
struct StateT * slot_176(struct StateT * v8494);
struct StateT * slot_189(struct StateT * v8691);
struct StateT * slot_394(struct StateT * v21950);
struct StateT * slot_398(struct StateT * v22012);
struct StateT * slot_33(struct StateT * v6112);
struct StateT * slot_371(struct StateT * v21592);
struct StateT * slot_330(struct StateT * v20953);
struct StateT * slot_450(struct StateT * v22908);
struct StateT * slot_35(struct StateT * v6160);
struct StateT * slot_484(struct StateT * v23498);
struct StateT * slot_258(struct StateT * v19831);
struct StateT * slot_166(struct StateT * v8334);
struct StateT * slot_418(struct StateT * v22372);
struct StateT * slot_51(struct StateT * v6441);
struct StateT * slot_25(struct StateT * v6006);
struct StateT * slot_490(struct StateT * v23588);
struct StateT * slot_264(struct StateT * v19927);
struct StateT * slot_339(struct StateT * v21096);
struct StateT * slot_123(struct StateT * v7665);
struct StateT * slot_97(struct StateT * v7235);
struct StateT * slot_106(struct StateT * v7370);
struct StateT * slot_299(struct StateT * v20472);
struct StateT * slot_539(struct StateT * v24351);
struct StateT * slot_319(struct StateT * v20784);
struct StateT * slot_344(struct StateT * v21175);
struct StateT * slot_513(struct StateT * v23945);
struct StateT * slot_130(struct StateT * v7771);
struct StateT * slot_497(struct StateT * v23695);
struct StateT * slot_455(struct StateT * v22983);
struct StateT * slot_141(struct StateT * v7947);
struct StateT * slot_432(struct StateT * v22598);
struct StateT * slot_306(struct StateT * v20580);
struct StateT * slot_312(struct StateT * v20670);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_560(struct StateT * v24684);
struct StateT * slot_240(struct StateT * v19025);
struct StateT * slot_247(struct StateT * v19686);
struct StateT * slot_548(struct StateT * v24493);
struct StateT * slot_70(struct StateT * v6758);
struct StateT * slot_168(struct StateT * v8363);
struct StateT * slot_348(struct StateT * v21235);
struct StateT * slot_456(struct StateT * v23006);
struct StateT * slot_225(struct StateT * v15531);
struct StateT * slot_467(struct StateT * v23203);
struct StateT * slot_285(struct StateT * v20254);
struct StateT * slot_213(struct StateT * v12550);
struct StateT * slot_82(struct StateT * v6969);
struct StateT * slot_263(struct StateT * v19911);
struct StateT * slot_161(struct StateT * v8259);
struct StateT * slot_293(struct StateT * v20374);
struct StateT * slot_185(struct StateT * v8630);
struct StateT * slot_288(struct StateT * v20299);
struct StateT * slot_89(struct StateT * v7075);
struct StateT * slot_384(struct StateT * v21799);
struct StateT * slot_486(struct StateT * v23528);
struct StateT * slot_347(struct StateT * v21220);
struct StateT * slot_140(struct StateT * v7932);
struct StateT * slot_473(struct StateT * v23293);
struct StateT * slot_49(struct StateT * v6395);
struct StateT * slot_216(struct StateT * v14069);
struct StateT * slot_468(struct StateT * v23217);
struct StateT * slot_50(struct StateT * v6418);
struct StateT * slot_135(struct StateT * v7853);
struct StateT * slot_59(struct StateT * v6584);
struct StateT * slot_485(struct StateT * v23512);
struct StateT * slot_40(struct StateT * v6260);
struct StateT * slot_77(struct StateT * v6895);
struct StateT * slot_85(struct StateT * v7014);
struct StateT * slot_350(struct StateT * v21265);
struct StateT * slot_392(struct StateT * v21918);
struct StateT * slot_75(struct StateT * v6861);
struct StateT * slot_71(struct StateT * v6781);
struct StateT * slot_378(struct StateT * v21703);
struct StateT * slot_108(struct StateT * v7399);
struct StateT * slot_116(struct StateT * v7558);
struct StateT * slot_417(struct StateT * v22349);
struct StateT * slot_405(struct StateT * v22152);
struct StateT * slot_215(struct StateT * v14055);
struct StateT * slot_45(struct StateT * v6334);
struct StateT * slot_134(struct StateT * v7836);
struct StateT * slot_463(struct StateT * v23143);
struct StateT * slot_175(struct StateT * v8477);
struct StateT * slot_387(struct StateT * v21844);
struct StateT * slot_273(struct StateT * v20062);
struct StateT * slot_69(struct StateT * v6735);
struct StateT * slot_188(struct StateT * v8675);
struct StateT * slot_495(struct StateT * v23663);
struct StateT * slot_186(struct StateT * v8646);
struct StateT * slot_102(struct StateT * v7309);
struct StateT * slot_145(struct StateT * v8006);
struct StateT * slot_110(struct StateT * v7438);
struct StateT * slot_301(struct StateT * v20506);
struct StateT * slot_502(struct StateT * v23778);
struct StateT * slot_506(struct StateT * v23840);
struct StateT * slot_413(struct StateT * v22273);
struct StateT * slot_320(struct StateT * v20801);
struct StateT * slot_281(struct StateT * v20194);
struct StateT * slot_533(struct StateT * v24257);
struct StateT * slot_203(struct StateT * v10594);
struct StateT * slot_190(struct StateT * v8707);
struct StateT * slot_157(struct StateT * v8199);
struct StateT * slot_447(struct StateT * v22863);
struct StateT * slot_559(struct StateT * v24663);
struct StateT * slot_243(struct StateT * v19461);
struct StateT * slot_173(struct StateT * v8443);
struct StateT * slot_307(struct StateT * v20596);
struct StateT * slot_453(struct StateT * v22953);
struct StateT * slot_54(struct StateT * v6504);
struct StateT * slot_26(struct StateT * v6019);
struct StateT * slot_370(struct StateT * v21577);
struct StateT * slot_206(struct StateT * v11241);
struct StateT * slot_227(struct StateT * v16940);
struct StateT * slot_169(struct StateT * v8379);
struct StateT * slot_442(struct StateT * v22786);
struct StateT * slot_529(struct StateT * v24197);
struct StateT * slot_14(struct StateT * v3532);
struct StateT * slot_357(struct StateT * v21374);
struct StateT * slot_385(struct StateT * v21814);
struct StateT * slot_444(struct StateT * v22818);
struct StateT * slot_261(struct StateT * v19882);
struct StateT * slot_287(struct StateT * v20284);
struct StateT * slot_343(struct StateT * v21159);
struct StateT * slot_36(struct StateT * v6184);
struct StateT * slot_57(struct StateT * v6555);
struct StateT * slot_426(struct StateT * v22508);
struct StateT * slot_536(struct StateT * v24303);
struct StateT * slot_470(struct StateT * v23248);
struct StateT * slot_431(struct StateT * v22582);
struct StateT * slot_62(struct StateT * v6629);
struct StateT * slot_308(struct StateT * v20611);
struct StateT * slot_400(struct StateT * v22044);
struct StateT * slot_323(struct StateT * v20847);
struct StateT * slot_521(struct StateT * v24073);
struct StateT * slot_530(struct StateT * v24212);
struct StateT * slot_23(struct StateT * v5980);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v7030);
struct StateT * slot_538(struct StateT * v24335);
struct StateT * slot_100(struct StateT * v7280);
struct StateT * slot_127(struct StateT * v7725);
struct StateT * slot_411(struct StateT * v22242);
struct StateT * slot_13(struct StateT * v4552);
struct StateT * slot_449(struct StateT * v22893);
struct StateT * slot_460(struct StateT * v23092);
struct StateT * slot_109(struct StateT * v7415);
struct StateT * slot_474(struct StateT * v23307);
struct StateT * slot_174(struct StateT * v8460);
struct StateT * slot_42(struct StateT * v6289);
struct StateT * slot_184(struct StateT * v8616);
struct StateT * slot_462(struct StateT * v23126);
struct StateT * slot_165(struct StateT * v8318);
struct StateT * slot_557(struct StateT * v24631);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_393(struct StateT * v21934);
struct StateT * slot_507(struct StateT * v23855);
struct StateT * slot_477(struct StateT * v23369);
struct StateT * slot_278(struct StateT * v20143);
struct StateT * slot_352(struct StateT * v21294);
struct StateT * slot_249(struct StateT * v19715);
struct StateT * slot_11(struct StateT * v3736);
struct StateT * slot_12(struct StateT * v4144);
struct StateT * slot_228(struct StateT * v17144);
struct StateT * slot_268(struct StateT * v19987);
struct StateT * slot_199(struct StateT * v9632);
struct StateT * slot_409(struct StateT * v22213);
struct StateT * slot_374(struct StateT * v21638);
struct StateT * slot_269(struct StateT * v20001);
struct StateT * slot_501(struct StateT * v23761);
struct StateT * slot_251(struct StateT * v19734);
struct StateT * slot_65(struct StateT * v6674);
struct StateT * slot_10(struct StateT * v3519);
struct StateT * slot_322(struct StateT * v20833);
struct StateT * slot_277(struct StateT * v20126);
struct StateT * slot_353(struct StateT * v21310);
struct StateT * slot_397(struct StateT * v21998);
struct StateT * slot_435(struct StateT * v22643);
struct StateT * slot_476(struct StateT * v23346);
struct StateT * slot_136(struct StateT * v7870);
struct StateT * slot_379(struct StateT * v21720);
struct StateT * slot_475(struct StateT * v23323);
struct StateT * slot_310(struct StateT * v20641);
struct StateT * slot_445(struct StateT * v22832);
struct StateT * slot_295(struct StateT * v20406);
struct StateT * slot_315(struct StateT * v20718);
struct StateT * slot_545(struct StateT * v24448);
struct StateT * slot_17(struct StateT * v4756);
struct StateT * slot_197(struct StateT * v9295);
struct StateT * slot_457(struct StateT * v23029);
struct StateT * slot_156(struct StateT * v8182);
struct StateT * slot_68(struct StateT * v6719);
struct StateT * slot_493(struct StateT * v23633);
struct StateT * slot_105(struct StateT * v7354);
struct StateT * slot_430(struct StateT * v22568);
struct StateT * slot_369(struct StateT * v21561);
struct StateT * slot_461(struct StateT * v23109);
struct StateT * slot_164(struct StateT * v8304);
struct StateT * slot_15(struct StateT * v3940);
struct StateT * slot_480(struct StateT * v23432);
struct StateT * slot_133(struct StateT * v7819);
struct StateT * slot_56(struct StateT * v6538);
struct StateT * slot_244(struct StateT * v19466);
struct StateT * slot_222(struct StateT * v14792);
struct StateT * slot_171(struct StateT * v8411);
struct StateT * slot_162(struct StateT * v8273);
struct StateT * slot_377(struct StateT * v21686);
struct StateT * slot_552(struct StateT * v24554);
struct StateT * slot_427(struct StateT * v22523);
struct StateT * slot_399(struct StateT * v22020);
struct StateT * slot_464(struct StateT * v23158);
struct StateT * slot_500(struct StateT * v23744);
struct StateT * slot_433(struct StateT * v22613);
struct StateT * slot_121(struct StateT * v7635);
struct StateT * slot_144(struct StateT * v7992);
struct StateT * slot_267(struct StateT * v19972);
struct StateT * slot_492(struct StateT * v23618);
struct StateT * slot_201(struct StateT * v9964);
struct StateT * slot_63(struct StateT * v6645);
struct StateT * slot_326(struct StateT * v20892);
struct StateT * slot_303(struct StateT * v20535);
struct StateT * slot_511(struct StateT * v23914);
struct StateT * slot_335(struct StateT * v21030);
struct StateT * slot_223(struct StateT * v14808);
struct StateT * slot_316(struct StateT * v20734);
struct StateT * slot_424(struct StateT * v22478);
struct StateT * slot_332(struct StateT * v20982);
struct StateT * slot_237(struct StateT * v18398);
struct StateT * slot_41(struct StateT * v6275);
struct StateT * slot_39(struct StateT * v6244);
struct StateT * slot_508(struct StateT * v23869);
struct StateT * slot_537(struct StateT * v24319);
struct StateT * slot_60(struct StateT * v6600);
struct StateT * slot_289(struct StateT * v20313);
struct StateT * slot_238(struct StateT * v18602);
struct StateT * slot_112(struct StateT * v7484);
struct StateT * slot_256(struct StateT * v19798);
struct StateT * slot_544(struct StateT * v24434);
struct StateT * slot_16(struct StateT * v4348);
struct StateT * slot_113(struct StateT * v7507);
struct StateT * slot_302(struct StateT * v20521);
struct StateT * slot_388(struct StateT * v21859);
struct StateT * slot_191(struct StateT * v8723);
struct StateT * slot_103(struct StateT * v7325);
struct StateT * slot_487(struct StateT * v23543);
struct StateT * slot_324(struct StateT * v20863);
struct StateT * slot_440(struct StateT * v22752);
struct StateT * slot_547(struct StateT * v24479);
struct StateT * slot_518(struct StateT * v24023);
struct StateT * slot_95(struct StateT * v7201);
struct StateT * slot_451(struct StateT * v22922);
struct StateT * slot_458(struct StateT * v23052);
struct StateT * slot_415(struct StateT * v22303);
struct StateT * slot_354(struct StateT * v21326);
struct StateT * slot_531(struct StateT * v24226);
struct StateT * slot_115(struct StateT * v7541);
struct StateT * slot_78(struct StateT * v6910);
struct StateT * slot_321(struct StateT * v20818);
struct StateT * slot_317(struct StateT * v20750);
struct StateT * slot_558(struct StateT * v24647);
struct StateT * slot_193(struct StateT * v8755);
struct StateT * slot_554(struct StateT * v24583);
struct StateT * slot_375(struct StateT * v21654);
struct StateT * slot_331(struct StateT * v20968);
struct StateT * slot_380(struct StateT * v21737);
struct StateT * slot_412(struct StateT * v22258);
struct StateT * slot_381(struct StateT * v21754);
struct StateT * slot_478(struct StateT * v23392);
struct StateT * slot_210(struct StateT * v11905);
struct StateT * slot_472(struct StateT * v23278);
struct StateT * slot_284(struct StateT * v20239);
struct StateT * slot_52(struct StateT * v6464);
struct StateT * slot_83(struct StateT * v6985);
struct StateT * slot_209(struct StateT * v11888);
struct StateT * slot_420(struct StateT * v22412);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_73(struct StateT * v6827);
struct StateT * slot_270(struct StateT * v20017);
struct StateT * slot_198(struct StateT * v9610);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v8661);
struct StateT * slot_446(struct StateT * v22848);
struct StateT * slot_182(struct StateT * v8585);
struct StateT * slot_361(struct StateT * v21442);
struct StateT * slot_38(struct StateT * v6230);
struct StateT * slot_178(struct StateT * v8526);
struct StateT * slot_98(struct StateT * v7250);
struct StateT * slot_159(struct StateT * v8228);
struct StateT * slot_510(struct StateT * v23900);
struct StateT * slot_459(struct StateT * v23075);
struct StateT * slot_404(struct StateT * v22138);
struct StateT * slot_46(struct StateT * v6350);
struct StateT * slot_212(struct StateT * v12535);
struct StateT * slot_132(struct StateT * v7803);
struct StateT * slot_313(struct StateT * v20686);
struct StateT * slot_553(struct StateT * v24569);
struct StateT * slot_20(struct StateT * v5368);
struct StateT * slot_436(struct StateT * v22666);
struct StateT * slot_61(struct StateT * v6615);
struct StateT * slot_499(struct StateT * v23727);
struct StateT * slot_359(struct StateT * v21408);
struct StateT * slot_514(struct StateT * v23959);
struct StateT * slot_296(struct StateT * v20422);
struct StateT * slot_30(struct StateT * v6077);
struct StateT * slot_18(struct StateT * v4960);
struct StateT * slot_9(struct StateT * v2536);
struct StateT * slot_300(struct StateT * v20489);
struct StateT * slot_183(struct StateT * v8601);
struct StateT * slot_282(struct StateT * v20209);
struct StateT * slot_309(struct StateT * v20625);
struct StateT * slot_362(struct StateT * v21457);
struct StateT * slot_43(struct StateT * v6305);
struct StateT * slot_76(struct StateT * v6878);
struct StateT * slot_6(struct StateT * v1591);
struct StateT * slot_55(struct StateT * v6521);
struct StateT * slot_283(struct StateT * v20223);
struct StateT * slot_346(struct StateT * v21204);
struct StateT * slot_516(struct StateT * v23991);
struct StateT * slot_274(struct StateT * v20078);
struct StateT * slot_535(struct StateT * v24287);
struct StateT * slot_318(struct StateT * v20767);
struct StateT * slot_91(struct StateT * v7121);
struct StateT * slot_58(struct StateT * v6570);
struct StateT * slot_255(struct StateT * v19782);
struct StateT * slot_540(struct StateT * v24368);
struct StateT * slot_66(struct StateT * v6690);
struct StateT * slot_550(struct StateT * v24524);
struct StateT * slot_368(struct StateT * v21547);
struct StateT * slot_265(struct StateT * v19942);
struct StateT * slot_37(struct StateT * v6208);
struct StateT * slot_114(struct StateT * v7524);
struct StateT * slot_257(struct StateT * v19814);
struct StateT * slot_192(struct StateT * v8739);
struct StateT * slot_327(struct StateT * v20908);
struct StateT * slot_48(struct StateT * v6379);
struct StateT * slot_396(struct StateT * v21982);
struct StateT * slot_528(struct StateT * v24181);
struct StateT * slot_72(struct StateT * v6804);
struct StateT * slot_526(struct StateT * v24152);
struct StateT * slot_119(struct StateT * v7604);
struct StateT * slot_101(struct StateT * v7295);
struct StateT * slot_276(struct StateT * v20110);
struct StateT * slot_290(struct StateT * v20329);
struct StateT * slot_93(struct StateT * v7167);
struct StateT * slot_266(struct StateT * v19956);
struct StateT * slot_88(struct StateT * v7059);
struct StateT * slot_96(struct StateT * v7218);
struct StateT * slot_234(struct StateT * v17770);
struct StateT * slot_471(struct StateT * v23262);
struct StateT * slot_419(struct StateT * v22395);
struct StateT * slot_218(struct StateT * v15123);
struct StateT * slot_336(struct StateT * v21046);
struct StateT * slot_294(struct StateT * v20390);
struct StateT * slot_408(struct StateT * v22197);
struct StateT * slot_342(struct StateT * v21145);
struct StateT * slot_488(struct StateT * v23557);
struct StateT * slot_439(struct StateT * v22735);
struct StateT * slot_389(struct StateT * v21873);
struct StateT * slot_479(struct StateT * v23415);
struct StateT * slot_138(struct StateT * v7902);
struct StateT * slot_483(struct StateT * v23483);
struct StateT * slot_196(struct StateT * v9287);
struct StateT * slot_172(struct StateT * v8427);
struct StateT * slot_425(struct StateT * v22492);
struct StateT * slot_443(struct StateT * v22803);
struct StateT * slot_131(struct StateT * v7787);
struct StateT * slot_8(struct StateT * v2221);
struct StateT * slot_534(struct StateT * v24271);
struct StateT * slot_180(struct StateT * v8556);
struct StateT * slot_504(struct StateT * v23810);
struct StateT * slot_512(struct StateT * v23930);
struct StateT * slot_496(struct StateT * v23679);
struct StateT * slot_494(struct StateT * v23647);
struct StateT * slot_328(struct StateT * v20923);
struct StateT * slot_402(struct StateT * v22092);
struct StateT * slot_200(struct StateT * v9947);
struct StateT * slot_149(struct StateT * v8067);
struct StateT * slot_527(struct StateT * v24167);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_334(struct StateT * v21014);
struct StateT * slot_104(struct StateT * v7340);
struct StateT * slot_235(struct StateT * v17974);
struct StateT * slot_275(struct StateT * v20094);
struct StateT * slot_329(struct StateT * v20937);
struct StateT * slot_428(struct StateT * v22537);
struct StateT * slot_395(struct StateT * v21966);
struct StateT * slot_345(struct StateT * v21190);
struct StateT * slot_298(struct StateT * v20455);
struct StateT * slot_414(struct StateT * v22287);
struct StateT * slot_364(struct StateT * v21487);
struct StateT * slot_356(struct StateT * v21358);
struct StateT * slot_253(struct StateT * v19750);
struct StateT * slot_434(struct StateT * v22627);
struct StateT * slot_64(struct StateT * v6660);
struct StateT * slot_170(struct StateT * v8395);
struct StateT * slot_53(struct StateT * v6487);
struct StateT * slot_522(struct StateT * v24090);
struct StateT * slot_80(struct StateT * v6940);
struct StateT * slot_503(struct StateT * v23795);
struct StateT * slot_390(struct StateT * v21889);
struct StateT * slot_44(struct StateT * v6320);
struct StateT * slot_137(struct StateT * v7887);
struct StateT * slot_386(struct StateT * v21828);
struct StateT * slot_122(struct StateT * v7649);
struct StateT * slot_99(struct StateT * v7264);
struct StateT * slot_179(struct StateT * v8540);
struct StateT * slot_338(struct StateT * v21079);
struct StateT * slot_22(struct StateT * v5776);
struct StateT * slot_366(struct StateT * v21516);
struct StateT * slot_139(struct StateT * v7916);
struct StateT * slot_438(struct StateT * v22712);
struct StateT * slot_333(struct StateT * v20998);
struct StateT * slot_153(struct StateT * v8131);
struct StateT * slot_129(struct StateT * v7755);
struct StateT * slot_158(struct StateT * v8214);
struct StateT * slot_311(struct StateT * v20656);
struct StateT * slot_498(struct StateT * v23711);
struct StateT * slot_279(struct StateT * v20160);
struct StateT * slot_271(struct StateT * v20032);
struct StateT * slot_524(struct StateT * v24122);
struct StateT * slot_505(struct StateT * v23824);
struct StateT * slot_401(struct StateT * v22068);
struct StateT * slot_423(struct StateT * v22463);
struct StateT * slot_532(struct StateT * v24242);
struct StateT * slot_111(struct StateT * v7461);
struct StateT * slot_549(struct StateT * v24509);
struct StateT * slot_349(struct StateT * v21249);
struct StateT * slot_291(struct StateT * v20344);
struct StateT * slot_147(struct StateT * v8037);
struct StateT * slot_410(struct StateT * v22228);
struct StateT * slot_491(struct StateT * v23602);
struct StateT * slot_163(struct StateT * v8289);
struct StateT * slot_422(struct StateT * v22446);
struct StateT * slot_448(struct StateT * v22877);
struct StateT * slot_194(struct StateT * v8776);
struct StateT * slot_551(struct StateT * v24538);
struct StateT * slot_407(struct StateT * v22183);
struct StateT * slot_543(struct StateT * v24419);
struct StateT * slot_360(struct StateT * v21425);
struct StateT * slot_259(struct StateT * v19848);
struct StateT * slot_469(struct StateT * v23233);
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

struct StateT * slot_226(struct StateT * v15546) {
  int v15547 = v15546->timer;
  int v16196 = v15547 + 1;
  v15546->timer = v16196;
  int * v15549 = v15546->regs;
  int v15550 = v15549[10];
  int v15551 = v15549[18];
  int * v15552 = v15546->saved_regs;
  int v15553 = v15549[8];
  v15552[8] = v15553;
  int v15555 = v15546->timer;
  int v16203 = v15555 + 1;
  v15546->timer = v16203;
  int * v15557 = v15546->regs;
  int v15558 = v15557[2];
  int * v15559 = v15546->cache_tags;
  int v16207 = (((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2;
  int v15560 = v15559[v16207];
  int v16208 = ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15561 = v15559[v16208];
  int v16209 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2);
  int v15562 = v15559[v16209];
  int v16210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15563 = v15559[v16210];
  int v15564 = v15546->timer;
  int v16211 = v15564 + ((100 ^ (((~(((v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15560 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15560 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15546->timer = v16211;
  int * v15566 = v15546->cache_vals;
  bool v16212 = !(((~(((v15560 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15560 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v15659;
  if (v16212) {
    int * v15567 = v15546->cache_age;
    int v16214 = ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15561 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v15568 = v15567[v16214];
    int v15569 = v15567[v16207];
    int v16215 = v15569 + ((int)((unsigned int)(v15569 - v15568) >> 31));
    v15567[v16207] = v16215;
    int * v15571 = v15546->cache_age;
    int v15572 = v15571[v16208];
    int v16217 = v15572 + ((int)((unsigned int)(v15572 - v15568) >> 31));
    v15571[v16208] = v16217;
    int * v15574 = v15546->cache_age;
    v15574[v16214] = 0;
    v15659 = v16214;
  } else {
    int * v15577 = v15546->cache_age;
    int v16221 = (((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2;
    int v15578 = v15577[v16221];
    int * v15579 = v15546->cache_tags;
    int v15580 = v15579[v16221];
    int v15581 = v15577[v16208];
    int v15582 = v15579[v16208];
    bool v16223 = !(((~(((v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15562 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v15636;
    if (v16223) {
      int * v15583 = v15546->cache_age;
      int v16225 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))) | (-(v15563 ^ ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v15584 = v15583[v16225];
      int v15585 = v15583[v16209];
      int v16226 = v15585 + ((int)((unsigned int)(v15585 - v15584) >> 31));
      v15583[v16209] = v16226;
      int * v15587 = v15546->cache_age;
      int v15588 = v15587[v16210];
      int v16228 = v15588 + ((int)((unsigned int)(v15588 - v15584) >> 31));
      v15587[v16210] = v16228;
      int * v15590 = v15546->cache_age;
      v15590[v16225] = 0;
      v15636 = v16225;
    } else {
      int * v15593 = v15546->cache_age;
      int v16232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2);
      int v15594 = v15593[v16232];
      int * v15595 = v15546->cache_tags;
      int v15596 = v15595[v16232];
      int v15597 = v15593[v16210];
      int v15598 = v15595[v16210];
      int * v15599 = v15546->cache_dirty;
      int v16235 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v15594 + ((~(((v15596 ^ -1) | (-(v15596 ^ -1))) >> 31)) & 2)) - (v15597 + ((~(((v15598 ^ -1) | (-(v15598 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15600 = v15599[v16235];
      bool v16236 = !(v15600 == 0);
      if (v16236) {
        int * v15601 = v15546->cache_tags;
        int v15602 = v15601[v16235];
        int * v15603 = v15546->cache_vals;
        int v16239 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v15594 + ((~(((v15596 ^ -1) | (-(v15596 ^ -1))) >> 31)) & 2)) - (v15597 + ((~(((v15598 ^ -1) | (-(v15598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15604 = v15603[v16239];
        int v16240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v15594 + ((~(((v15596 ^ -1) | (-(v15596 ^ -1))) >> 31)) & 2)) - (v15597 + ((~(((v15598 ^ -1) | (-(v15598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15605 = v15603[v16240];
        int * v15606 = v15546->mem;
        int v16242 = v15602 * 2;
        v15606[v16242] = v15604;
        int * v15608 = v15546->mem;
        int v16245 = (v15602 * 2) + 1;
        v15608[v16245] = v15605;
        ;
      } else {
        ;
      }
      int * v15613 = v15546->mem;
      int v16250 = ((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) * 2;
      int v15614 = v15613[v16250];
      int v16251 = (((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) * 2) + 1;
      int v15615 = v15613[v16251];
      int * v15616 = v15546->cache_vals;
      int v16253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v15594 + ((~(((v15596 ^ -1) | (-(v15596 ^ -1))) >> 31)) & 2)) - (v15597 + ((~(((v15598 ^ -1) | (-(v15598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15616[v16253] = v15614;
      int * v15618 = v15546->cache_vals;
      int v16256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v15594 + ((~(((v15596 ^ -1) | (-(v15596 ^ -1))) >> 31)) & 2)) - (v15597 + ((~(((v15598 ^ -1) | (-(v15598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15618[v16256] = v15615;
      int * v15620 = v15546->cache_tags;
      int v16259 = (int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1);
      v15620[v16235] = v16259;
      int * v15622 = v15546->cache_dirty;
      v15622[v16235] = 0;
      int * v15624 = v15546->cache_age;
      v15624[v16235] = 1;
      int * v15626 = v15546->cache_age;
      int v15627 = v15626[v16235];
      int v15628 = v15626[v16209];
      int v16265 = v15628 + ((int)((unsigned int)(v15628 - v15627) >> 31));
      v15626[v16209] = v16265;
      int * v15630 = v15546->cache_age;
      int v15631 = v15630[v16210];
      int v16267 = v15631 + ((int)((unsigned int)(v15631 - v15627) >> 31));
      v15630[v16210] = v16267;
      int * v15633 = v15546->cache_age;
      v15633[v16235] = 0;
      v15636 = v16235;
    }
    int * v15637 = v15546->cache_vals;
    int v16270 = v15636 * 2;
    int v15638 = v15637[v16270];
    int v16271 = (v15636 * 2) + 1;
    int v15639 = v15637[v16271];
    int v16272 = (((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15578 + ((~(((v15580 ^ -1) | (-(v15580 ^ -1))) >> 31)) & 2)) - (v15581 + ((~(((v15582 ^ -1) | (-(v15582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15637[v16272] = v15638;
    int * v15641 = v15546->cache_vals;
    int v16275 = ((((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15578 + ((~(((v15580 ^ -1) | (-(v15580 ^ -1))) >> 31)) & 2)) - (v15581 + ((~(((v15582 ^ -1) | (-(v15582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15641[v16275] = v15639;
    int * v15643 = v15546->cache_tags;
    int v16278 = ((((int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15578 + ((~(((v15580 ^ -1) | (-(v15580 ^ -1))) >> 31)) & 2)) - (v15581 + ((~(((v15582 ^ -1) | (-(v15582 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16279 = (int)((unsigned int)((int)((unsigned int)(v15558 + 44) >> 2)) >> 1);
    v15643[v16278] = v16279;
    int * v15645 = v15546->cache_dirty;
    v15645[v16278] = 0;
    int * v15647 = v15546->cache_age;
    v15647[v16278] = 1;
    int * v15649 = v15546->cache_age;
    int v15650 = v15649[v16278];
    int v15651 = v15649[v16207];
    int v16285 = v15651 + ((int)((unsigned int)(v15651 - v15650) >> 31));
    v15649[v16207] = v16285;
    int * v15653 = v15546->cache_age;
    int v15654 = v15653[v16208];
    int v16287 = v15654 + ((int)((unsigned int)(v15654 - v15650) >> 31));
    v15653[v16208] = v16287;
    int * v15656 = v15546->cache_age;
    v15656[v16278] = 0;
    v15659 = v16278;
  }
  int v16290 = (v15659 * 2) + (((int)((unsigned int)(v15558 + 44) >> 2)) & 1);
  int v15660 = v15566[v16290];
  int * v15661 = v15546->regs;
  v15661[8] = v15660;
  int * v15663 = v15546->saved_regs;
  int * v15664 = v15546->regs;
  int v15665 = v15664[9];
  v15663[9] = v15665;
  int v15667 = v15546->timer;
  int v16297 = v15667 + 1;
  v15546->timer = v16297;
  int * v15669 = v15546->regs;
  int v15670 = v15669[2];
  int * v15671 = v15546->cache_tags;
  int v16300 = (((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2;
  int v15672 = v15671[v16300];
  int v16301 = ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15673 = v15671[v16301];
  int v16302 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2);
  int v15674 = v15671[v16302];
  int v16303 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15675 = v15671[v16303];
  int v15676 = v15546->timer;
  int v16304 = v15676 + ((100 ^ (((~(((v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15672 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15672 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15546->timer = v16304;
  int * v15678 = v15546->cache_vals;
  bool v16305 = !(((~(((v15672 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15672 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v15771;
  if (v16305) {
    int * v15679 = v15546->cache_age;
    int v16307 = ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15673 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v15680 = v15679[v16307];
    int v15681 = v15679[v16300];
    int v16308 = v15681 + ((int)((unsigned int)(v15681 - v15680) >> 31));
    v15679[v16300] = v16308;
    int * v15683 = v15546->cache_age;
    int v15684 = v15683[v16301];
    int v16310 = v15684 + ((int)((unsigned int)(v15684 - v15680) >> 31));
    v15683[v16301] = v16310;
    int * v15686 = v15546->cache_age;
    v15686[v16307] = 0;
    v15771 = v16307;
  } else {
    int * v15689 = v15546->cache_age;
    int v16314 = (((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2;
    int v15690 = v15689[v16314];
    int * v15691 = v15546->cache_tags;
    int v15692 = v15691[v16314];
    int v15693 = v15689[v16301];
    int v15694 = v15691[v16301];
    bool v16316 = !(((~(((v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15674 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v15748;
    if (v16316) {
      int * v15695 = v15546->cache_age;
      int v16318 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))) | (-(v15675 ^ ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v15696 = v15695[v16318];
      int v15697 = v15695[v16302];
      int v16319 = v15697 + ((int)((unsigned int)(v15697 - v15696) >> 31));
      v15695[v16302] = v16319;
      int * v15699 = v15546->cache_age;
      int v15700 = v15699[v16303];
      int v16321 = v15700 + ((int)((unsigned int)(v15700 - v15696) >> 31));
      v15699[v16303] = v16321;
      int * v15702 = v15546->cache_age;
      v15702[v16318] = 0;
      v15748 = v16318;
    } else {
      int * v15705 = v15546->cache_age;
      int v16325 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2);
      int v15706 = v15705[v16325];
      int * v15707 = v15546->cache_tags;
      int v15708 = v15707[v16325];
      int v15709 = v15705[v16303];
      int v15710 = v15707[v16303];
      int * v15711 = v15546->cache_dirty;
      int v16328 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15706 + ((~(((v15708 ^ -1) | (-(v15708 ^ -1))) >> 31)) & 2)) - (v15709 + ((~(((v15710 ^ -1) | (-(v15710 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15712 = v15711[v16328];
      bool v16329 = !(v15712 == 0);
      if (v16329) {
        int * v15713 = v15546->cache_tags;
        int v15714 = v15713[v16328];
        int * v15715 = v15546->cache_vals;
        int v16332 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15706 + ((~(((v15708 ^ -1) | (-(v15708 ^ -1))) >> 31)) & 2)) - (v15709 + ((~(((v15710 ^ -1) | (-(v15710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15716 = v15715[v16332];
        int v16333 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15706 + ((~(((v15708 ^ -1) | (-(v15708 ^ -1))) >> 31)) & 2)) - (v15709 + ((~(((v15710 ^ -1) | (-(v15710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15717 = v15715[v16333];
        int * v15718 = v15546->mem;
        int v16335 = v15714 * 2;
        v15718[v16335] = v15716;
        int * v15720 = v15546->mem;
        int v16338 = (v15714 * 2) + 1;
        v15720[v16338] = v15717;
        ;
      } else {
        ;
      }
      int * v15725 = v15546->mem;
      int v16343 = ((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) * 2;
      int v15726 = v15725[v16343];
      int v16344 = (((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) * 2) + 1;
      int v15727 = v15725[v16344];
      int * v15728 = v15546->cache_vals;
      int v16346 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15706 + ((~(((v15708 ^ -1) | (-(v15708 ^ -1))) >> 31)) & 2)) - (v15709 + ((~(((v15710 ^ -1) | (-(v15710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15728[v16346] = v15726;
      int * v15730 = v15546->cache_vals;
      int v16349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15706 + ((~(((v15708 ^ -1) | (-(v15708 ^ -1))) >> 31)) & 2)) - (v15709 + ((~(((v15710 ^ -1) | (-(v15710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15730[v16349] = v15727;
      int * v15732 = v15546->cache_tags;
      int v16352 = (int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1);
      v15732[v16328] = v16352;
      int * v15734 = v15546->cache_dirty;
      v15734[v16328] = 0;
      int * v15736 = v15546->cache_age;
      v15736[v16328] = 1;
      int * v15738 = v15546->cache_age;
      int v15739 = v15738[v16328];
      int v15740 = v15738[v16302];
      int v16358 = v15740 + ((int)((unsigned int)(v15740 - v15739) >> 31));
      v15738[v16302] = v16358;
      int * v15742 = v15546->cache_age;
      int v15743 = v15742[v16303];
      int v16360 = v15743 + ((int)((unsigned int)(v15743 - v15739) >> 31));
      v15742[v16303] = v16360;
      int * v15745 = v15546->cache_age;
      v15745[v16328] = 0;
      v15748 = v16328;
    }
    int * v15749 = v15546->cache_vals;
    int v16363 = v15748 * 2;
    int v15750 = v15749[v16363];
    int v16364 = (v15748 * 2) + 1;
    int v15751 = v15749[v16364];
    int v16365 = (((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15690 + ((~(((v15692 ^ -1) | (-(v15692 ^ -1))) >> 31)) & 2)) - (v15693 + ((~(((v15694 ^ -1) | (-(v15694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15749[v16365] = v15750;
    int * v15753 = v15546->cache_vals;
    int v16368 = ((((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15690 + ((~(((v15692 ^ -1) | (-(v15692 ^ -1))) >> 31)) & 2)) - (v15693 + ((~(((v15694 ^ -1) | (-(v15694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15753[v16368] = v15751;
    int * v15755 = v15546->cache_tags;
    int v16371 = ((((int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15690 + ((~(((v15692 ^ -1) | (-(v15692 ^ -1))) >> 31)) & 2)) - (v15693 + ((~(((v15694 ^ -1) | (-(v15694 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16372 = (int)((unsigned int)((int)((unsigned int)(v15670 + 40) >> 2)) >> 1);
    v15755[v16371] = v16372;
    int * v15757 = v15546->cache_dirty;
    v15757[v16371] = 0;
    int * v15759 = v15546->cache_age;
    v15759[v16371] = 1;
    int * v15761 = v15546->cache_age;
    int v15762 = v15761[v16371];
    int v15763 = v15761[v16300];
    int v16378 = v15763 + ((int)((unsigned int)(v15763 - v15762) >> 31));
    v15761[v16300] = v16378;
    int * v15765 = v15546->cache_age;
    int v15766 = v15765[v16301];
    int v16380 = v15766 + ((int)((unsigned int)(v15766 - v15762) >> 31));
    v15765[v16301] = v16380;
    int * v15768 = v15546->cache_age;
    v15768[v16371] = 0;
    v15771 = v16371;
  }
  int v16383 = (v15771 * 2) + (((int)((unsigned int)(v15670 + 40) >> 2)) & 1);
  int v15772 = v15678[v16383];
  int * v15773 = v15546->regs;
  v15773[9] = v15772;
  int * v15775 = v15546->saved_regs;
  int * v15776 = v15546->regs;
  int v15777 = v15776[18];
  v15775[18] = v15777;
  int v15779 = v15546->timer;
  int v16389 = v15779 + 1;
  v15546->timer = v16389;
  int * v15781 = v15546->regs;
  int v15782 = v15781[2];
  bool v16391 = (((int)((unsigned int)(v15550 + 28) >> 2)) & 3) == (((int)((unsigned int)(v15782 + 36) >> 2)) & 3);
  int v15889;
  if (v16391) {
    int v15783 = v15546->timer;
    int v16392 = v15783 + 1;
    v15546->timer = v16392;
    v15889 = v15551;
  } else {
    int * v15786 = v15546->cache_tags;
    int v16395 = (((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2;
    int v15787 = v15786[v16395];
    int v16396 = ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
    int v15788 = v15786[v16396];
    int v16397 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2);
    int v15789 = v15786[v16397];
    int v16398 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v15790 = v15786[v16398];
    int v15791 = v15546->timer;
    int v16399 = v15791 + ((100 ^ (((~(((v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15787 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15787 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
    v15546->timer = v16399;
    int * v15793 = v15546->cache_vals;
    bool v16400 = !(((~(((v15787 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15787 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v15886;
    if (v16400) {
      int * v15794 = v15546->cache_age;
      int v16402 = ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15788 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v15795 = v15794[v16402];
      int v15796 = v15794[v16395];
      int v16403 = v15796 + ((int)((unsigned int)(v15796 - v15795) >> 31));
      v15794[v16395] = v16403;
      int * v15798 = v15546->cache_age;
      int v15799 = v15798[v16396];
      int v16405 = v15799 + ((int)((unsigned int)(v15799 - v15795) >> 31));
      v15798[v16396] = v16405;
      int * v15801 = v15546->cache_age;
      v15801[v16402] = 0;
      v15886 = v16402;
    } else {
      int * v15804 = v15546->cache_age;
      int v16409 = (((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2;
      int v15805 = v15804[v16409];
      int * v15806 = v15546->cache_tags;
      int v15807 = v15806[v16409];
      int v15808 = v15804[v16396];
      int v15809 = v15806[v16396];
      bool v16411 = !(((~(((v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15789 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31))) == 0);
      int v15863;
      if (v16411) {
        int * v15810 = v15546->cache_age;
        int v16413 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))) | (-(v15790 ^ ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1))))) >> 31)) & 1);
        int v15811 = v15810[v16413];
        int v15812 = v15810[v16397];
        int v16414 = v15812 + ((int)((unsigned int)(v15812 - v15811) >> 31));
        v15810[v16397] = v16414;
        int * v15814 = v15546->cache_age;
        int v15815 = v15814[v16398];
        int v16416 = v15815 + ((int)((unsigned int)(v15815 - v15811) >> 31));
        v15814[v16398] = v16416;
        int * v15817 = v15546->cache_age;
        v15817[v16413] = 0;
        v15863 = v16413;
      } else {
        int * v15820 = v15546->cache_age;
        int v16420 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2);
        int v15821 = v15820[v16420];
        int * v15822 = v15546->cache_tags;
        int v15823 = v15822[v16420];
        int v15824 = v15820[v16398];
        int v15825 = v15822[v16398];
        int * v15826 = v15546->cache_dirty;
        int v16423 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15821 + ((~(((v15823 ^ -1) | (-(v15823 ^ -1))) >> 31)) & 2)) - (v15824 + ((~(((v15825 ^ -1) | (-(v15825 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v15827 = v15826[v16423];
        bool v16424 = !(v15827 == 0);
        if (v16424) {
          int * v15828 = v15546->cache_tags;
          int v15829 = v15828[v16423];
          int * v15830 = v15546->cache_vals;
          int v16427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15821 + ((~(((v15823 ^ -1) | (-(v15823 ^ -1))) >> 31)) & 2)) - (v15824 + ((~(((v15825 ^ -1) | (-(v15825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v15831 = v15830[v16427];
          int v16428 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15821 + ((~(((v15823 ^ -1) | (-(v15823 ^ -1))) >> 31)) & 2)) - (v15824 + ((~(((v15825 ^ -1) | (-(v15825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v15832 = v15830[v16428];
          int * v15833 = v15546->mem;
          int v16430 = v15829 * 2;
          v15833[v16430] = v15831;
          int * v15835 = v15546->mem;
          int v16433 = (v15829 * 2) + 1;
          v15835[v16433] = v15832;
          ;
        } else {
          ;
        }
        int * v15840 = v15546->mem;
        int v16438 = ((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) * 2;
        int v15841 = v15840[v16438];
        int v16439 = (((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) * 2) + 1;
        int v15842 = v15840[v16439];
        int * v15843 = v15546->cache_vals;
        int v16441 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15821 + ((~(((v15823 ^ -1) | (-(v15823 ^ -1))) >> 31)) & 2)) - (v15824 + ((~(((v15825 ^ -1) | (-(v15825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v15843[v16441] = v15841;
        int * v15845 = v15546->cache_vals;
        int v16444 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15821 + ((~(((v15823 ^ -1) | (-(v15823 ^ -1))) >> 31)) & 2)) - (v15824 + ((~(((v15825 ^ -1) | (-(v15825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v15845[v16444] = v15842;
        int * v15847 = v15546->cache_tags;
        int v16447 = (int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1);
        v15847[v16423] = v16447;
        int * v15849 = v15546->cache_dirty;
        v15849[v16423] = 0;
        int * v15851 = v15546->cache_age;
        v15851[v16423] = 1;
        int * v15853 = v15546->cache_age;
        int v15854 = v15853[v16423];
        int v15855 = v15853[v16397];
        int v16453 = v15855 + ((int)((unsigned int)(v15855 - v15854) >> 31));
        v15853[v16397] = v16453;
        int * v15857 = v15546->cache_age;
        int v15858 = v15857[v16398];
        int v16455 = v15858 + ((int)((unsigned int)(v15858 - v15854) >> 31));
        v15857[v16398] = v16455;
        int * v15860 = v15546->cache_age;
        v15860[v16423] = 0;
        v15863 = v16423;
      }
      int * v15864 = v15546->cache_vals;
      int v16458 = v15863 * 2;
      int v15865 = v15864[v16458];
      int v16459 = (v15863 * 2) + 1;
      int v15866 = v15864[v16459];
      int v16460 = (((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15805 + ((~(((v15807 ^ -1) | (-(v15807 ^ -1))) >> 31)) & 2)) - (v15808 + ((~(((v15809 ^ -1) | (-(v15809 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15864[v16460] = v15865;
      int * v15868 = v15546->cache_vals;
      int v16463 = ((((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15805 + ((~(((v15807 ^ -1) | (-(v15807 ^ -1))) >> 31)) & 2)) - (v15808 + ((~(((v15809 ^ -1) | (-(v15809 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15868[v16463] = v15866;
      int * v15870 = v15546->cache_tags;
      int v16466 = ((((int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15805 + ((~(((v15807 ^ -1) | (-(v15807 ^ -1))) >> 31)) & 2)) - (v15808 + ((~(((v15809 ^ -1) | (-(v15809 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16467 = (int)((unsigned int)((int)((unsigned int)(v15782 + 36) >> 2)) >> 1);
      v15870[v16466] = v16467;
      int * v15872 = v15546->cache_dirty;
      v15872[v16466] = 0;
      int * v15874 = v15546->cache_age;
      v15874[v16466] = 1;
      int * v15876 = v15546->cache_age;
      int v15877 = v15876[v16466];
      int v15878 = v15876[v16395];
      int v16473 = v15878 + ((int)((unsigned int)(v15878 - v15877) >> 31));
      v15876[v16395] = v16473;
      int * v15880 = v15546->cache_age;
      int v15881 = v15880[v16396];
      int v16475 = v15881 + ((int)((unsigned int)(v15881 - v15877) >> 31));
      v15880[v16396] = v16475;
      int * v15883 = v15546->cache_age;
      v15883[v16466] = 0;
      v15886 = v16466;
    }
    int v16478 = (v15886 * 2) + (((int)((unsigned int)(v15782 + 36) >> 2)) & 1);
    int v15887 = v15793[v16478];
    v15889 = v15887;
  }
  int * v15890 = v15546->regs;
  v15890[18] = v15889;
  int * v15892 = v15546->saved_regs;
  int * v15893 = v15546->regs;
  int v15894 = v15893[19];
  v15892[19] = v15894;
  int v15896 = v15546->timer;
  int v16486 = v15896 + 1;
  v15546->timer = v16486;
  int * v15898 = v15546->regs;
  int v15899 = v15898[2];
  bool v16488 = (((int)((unsigned int)(v15550 + 28) >> 2)) & 3) == (((int)((unsigned int)(v15899 + 32) >> 2)) & 3);
  int v16006;
  if (v16488) {
    int v15900 = v15546->timer;
    int v16489 = v15900 + 1;
    v15546->timer = v16489;
    v16006 = v15551;
  } else {
    int * v15903 = v15546->cache_tags;
    int v16492 = (((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2;
    int v15904 = v15903[v16492];
    int v16493 = ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
    int v15905 = v15903[v16493];
    int v16494 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2);
    int v15906 = v15903[v16494];
    int v16495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v15907 = v15903[v16495];
    int v15908 = v15546->timer;
    int v16496 = v15908 + ((100 ^ (((~(((v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15904 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15904 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
    v15546->timer = v16496;
    int * v15910 = v15546->cache_vals;
    bool v16497 = !(((~(((v15904 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15904 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v16003;
    if (v16497) {
      int * v15911 = v15546->cache_age;
      int v16499 = ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15905 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v15912 = v15911[v16499];
      int v15913 = v15911[v16492];
      int v16500 = v15913 + ((int)((unsigned int)(v15913 - v15912) >> 31));
      v15911[v16492] = v16500;
      int * v15915 = v15546->cache_age;
      int v15916 = v15915[v16493];
      int v16502 = v15916 + ((int)((unsigned int)(v15916 - v15912) >> 31));
      v15915[v16493] = v16502;
      int * v15918 = v15546->cache_age;
      v15918[v16499] = 0;
      v16003 = v16499;
    } else {
      int * v15921 = v15546->cache_age;
      int v16506 = (((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2;
      int v15922 = v15921[v16506];
      int * v15923 = v15546->cache_tags;
      int v15924 = v15923[v16506];
      int v15925 = v15921[v16493];
      int v15926 = v15923[v16493];
      bool v16508 = !(((~(((v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15906 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31))) == 0);
      int v15980;
      if (v16508) {
        int * v15927 = v15546->cache_age;
        int v16510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))) | (-(v15907 ^ ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1))))) >> 31)) & 1);
        int v15928 = v15927[v16510];
        int v15929 = v15927[v16494];
        int v16511 = v15929 + ((int)((unsigned int)(v15929 - v15928) >> 31));
        v15927[v16494] = v16511;
        int * v15931 = v15546->cache_age;
        int v15932 = v15931[v16495];
        int v16513 = v15932 + ((int)((unsigned int)(v15932 - v15928) >> 31));
        v15931[v16495] = v16513;
        int * v15934 = v15546->cache_age;
        v15934[v16510] = 0;
        v15980 = v16510;
      } else {
        int * v15937 = v15546->cache_age;
        int v16517 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2);
        int v15938 = v15937[v16517];
        int * v15939 = v15546->cache_tags;
        int v15940 = v15939[v16517];
        int v15941 = v15937[v16495];
        int v15942 = v15939[v16495];
        int * v15943 = v15546->cache_dirty;
        int v16520 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15938 + ((~(((v15940 ^ -1) | (-(v15940 ^ -1))) >> 31)) & 2)) - (v15941 + ((~(((v15942 ^ -1) | (-(v15942 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v15944 = v15943[v16520];
        bool v16521 = !(v15944 == 0);
        if (v16521) {
          int * v15945 = v15546->cache_tags;
          int v15946 = v15945[v16520];
          int * v15947 = v15546->cache_vals;
          int v16524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15938 + ((~(((v15940 ^ -1) | (-(v15940 ^ -1))) >> 31)) & 2)) - (v15941 + ((~(((v15942 ^ -1) | (-(v15942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v15948 = v15947[v16524];
          int v16525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15938 + ((~(((v15940 ^ -1) | (-(v15940 ^ -1))) >> 31)) & 2)) - (v15941 + ((~(((v15942 ^ -1) | (-(v15942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v15949 = v15947[v16525];
          int * v15950 = v15546->mem;
          int v16527 = v15946 * 2;
          v15950[v16527] = v15948;
          int * v15952 = v15546->mem;
          int v16530 = (v15946 * 2) + 1;
          v15952[v16530] = v15949;
          ;
        } else {
          ;
        }
        int * v15957 = v15546->mem;
        int v16535 = ((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) * 2;
        int v15958 = v15957[v16535];
        int v16536 = (((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) * 2) + 1;
        int v15959 = v15957[v16536];
        int * v15960 = v15546->cache_vals;
        int v16538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15938 + ((~(((v15940 ^ -1) | (-(v15940 ^ -1))) >> 31)) & 2)) - (v15941 + ((~(((v15942 ^ -1) | (-(v15942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v15960[v16538] = v15958;
        int * v15962 = v15546->cache_vals;
        int v16541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15938 + ((~(((v15940 ^ -1) | (-(v15940 ^ -1))) >> 31)) & 2)) - (v15941 + ((~(((v15942 ^ -1) | (-(v15942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v15962[v16541] = v15959;
        int * v15964 = v15546->cache_tags;
        int v16544 = (int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1);
        v15964[v16520] = v16544;
        int * v15966 = v15546->cache_dirty;
        v15966[v16520] = 0;
        int * v15968 = v15546->cache_age;
        v15968[v16520] = 1;
        int * v15970 = v15546->cache_age;
        int v15971 = v15970[v16520];
        int v15972 = v15970[v16494];
        int v16550 = v15972 + ((int)((unsigned int)(v15972 - v15971) >> 31));
        v15970[v16494] = v16550;
        int * v15974 = v15546->cache_age;
        int v15975 = v15974[v16495];
        int v16552 = v15975 + ((int)((unsigned int)(v15975 - v15971) >> 31));
        v15974[v16495] = v16552;
        int * v15977 = v15546->cache_age;
        v15977[v16520] = 0;
        v15980 = v16520;
      }
      int * v15981 = v15546->cache_vals;
      int v16555 = v15980 * 2;
      int v15982 = v15981[v16555];
      int v16556 = (v15980 * 2) + 1;
      int v15983 = v15981[v16556];
      int v16557 = (((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15922 + ((~(((v15924 ^ -1) | (-(v15924 ^ -1))) >> 31)) & 2)) - (v15925 + ((~(((v15926 ^ -1) | (-(v15926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15981[v16557] = v15982;
      int * v15985 = v15546->cache_vals;
      int v16560 = ((((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15922 + ((~(((v15924 ^ -1) | (-(v15924 ^ -1))) >> 31)) & 2)) - (v15925 + ((~(((v15926 ^ -1) | (-(v15926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15985[v16560] = v15983;
      int * v15987 = v15546->cache_tags;
      int v16563 = ((((int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15922 + ((~(((v15924 ^ -1) | (-(v15924 ^ -1))) >> 31)) & 2)) - (v15925 + ((~(((v15926 ^ -1) | (-(v15926 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16564 = (int)((unsigned int)((int)((unsigned int)(v15899 + 32) >> 2)) >> 1);
      v15987[v16563] = v16564;
      int * v15989 = v15546->cache_dirty;
      v15989[v16563] = 0;
      int * v15991 = v15546->cache_age;
      v15991[v16563] = 1;
      int * v15993 = v15546->cache_age;
      int v15994 = v15993[v16563];
      int v15995 = v15993[v16492];
      int v16570 = v15995 + ((int)((unsigned int)(v15995 - v15994) >> 31));
      v15993[v16492] = v16570;
      int * v15997 = v15546->cache_age;
      int v15998 = v15997[v16493];
      int v16572 = v15998 + ((int)((unsigned int)(v15998 - v15994) >> 31));
      v15997[v16493] = v16572;
      int * v16000 = v15546->cache_age;
      v16000[v16563] = 0;
      v16003 = v16563;
    }
    int v16575 = (v16003 * 2) + (((int)((unsigned int)(v15899 + 32) >> 2)) & 1);
    int v16004 = v15910[v16575];
    v16006 = v16004;
  }
  int * v16007 = v15546->regs;
  v16007[19] = v16006;
  int * v16009 = v15546->cache_tags;
  int v16580 = (((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2;
  int v16010 = v16009[v16580];
  int v16581 = ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16011 = v16009[v16581];
  int v16582 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2);
  int v16012 = v16009[v16582];
  int v16583 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16013 = v16009[v16583];
  int v16014 = v15546->timer;
  int v16584 = v16014 + ((100 ^ (((~(((v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16010 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16010 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15546->timer = v16584;
  bool v16585 = !(((~(((v16010 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16010 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v16108;
  if (v16585) {
    int * v16016 = v15546->cache_age;
    int v16587 = ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16011 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v16017 = v16016[v16587];
    int v16018 = v16016[v16580];
    int v16588 = v16018 + ((int)((unsigned int)(v16018 - v16017) >> 31));
    v16016[v16580] = v16588;
    int * v16020 = v15546->cache_age;
    int v16021 = v16020[v16581];
    int v16590 = v16021 + ((int)((unsigned int)(v16021 - v16017) >> 31));
    v16020[v16581] = v16590;
    int * v16023 = v15546->cache_age;
    v16023[v16587] = 0;
    v16108 = v16587;
  } else {
    int * v16026 = v15546->cache_age;
    int v16594 = (((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2;
    int v16027 = v16026[v16594];
    int * v16028 = v15546->cache_tags;
    int v16029 = v16028[v16594];
    int v16030 = v16026[v16581];
    int v16031 = v16028[v16581];
    bool v16596 = !(((~(((v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16012 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v16085;
    if (v16596) {
      int * v16032 = v15546->cache_age;
      int v16598 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16013 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v16033 = v16032[v16598];
      int v16034 = v16032[v16582];
      int v16599 = v16034 + ((int)((unsigned int)(v16034 - v16033) >> 31));
      v16032[v16582] = v16599;
      int * v16036 = v15546->cache_age;
      int v16037 = v16036[v16583];
      int v16601 = v16037 + ((int)((unsigned int)(v16037 - v16033) >> 31));
      v16036[v16583] = v16601;
      int * v16039 = v15546->cache_age;
      v16039[v16598] = 0;
      v16085 = v16598;
    } else {
      int * v16042 = v15546->cache_age;
      int v16605 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2);
      int v16043 = v16042[v16605];
      int * v16044 = v15546->cache_tags;
      int v16045 = v16044[v16605];
      int v16046 = v16042[v16583];
      int v16047 = v16044[v16583];
      int * v16048 = v15546->cache_dirty;
      int v16608 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16043 + ((~(((v16045 ^ -1) | (-(v16045 ^ -1))) >> 31)) & 2)) - (v16046 + ((~(((v16047 ^ -1) | (-(v16047 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16049 = v16048[v16608];
      bool v16609 = !(v16049 == 0);
      if (v16609) {
        int * v16050 = v15546->cache_tags;
        int v16051 = v16050[v16608];
        int * v16052 = v15546->cache_vals;
        int v16612 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16043 + ((~(((v16045 ^ -1) | (-(v16045 ^ -1))) >> 31)) & 2)) - (v16046 + ((~(((v16047 ^ -1) | (-(v16047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16053 = v16052[v16612];
        int v16613 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16043 + ((~(((v16045 ^ -1) | (-(v16045 ^ -1))) >> 31)) & 2)) - (v16046 + ((~(((v16047 ^ -1) | (-(v16047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16054 = v16052[v16613];
        int * v16055 = v15546->mem;
        int v16615 = v16051 * 2;
        v16055[v16615] = v16053;
        int * v16057 = v15546->mem;
        int v16618 = (v16051 * 2) + 1;
        v16057[v16618] = v16054;
        ;
      } else {
        ;
      }
      int * v16062 = v15546->mem;
      int v16623 = ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) * 2;
      int v16063 = v16062[v16623];
      int v16624 = (((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) * 2) + 1;
      int v16064 = v16062[v16624];
      int * v16065 = v15546->cache_vals;
      int v16626 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16043 + ((~(((v16045 ^ -1) | (-(v16045 ^ -1))) >> 31)) & 2)) - (v16046 + ((~(((v16047 ^ -1) | (-(v16047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16065[v16626] = v16063;
      int * v16067 = v15546->cache_vals;
      int v16629 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16043 + ((~(((v16045 ^ -1) | (-(v16045 ^ -1))) >> 31)) & 2)) - (v16046 + ((~(((v16047 ^ -1) | (-(v16047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16067[v16629] = v16064;
      int * v16069 = v15546->cache_tags;
      int v16632 = (int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1);
      v16069[v16608] = v16632;
      int * v16071 = v15546->cache_dirty;
      v16071[v16608] = 0;
      int * v16073 = v15546->cache_age;
      v16073[v16608] = 1;
      int * v16075 = v15546->cache_age;
      int v16076 = v16075[v16608];
      int v16077 = v16075[v16582];
      int v16638 = v16077 + ((int)((unsigned int)(v16077 - v16076) >> 31));
      v16075[v16582] = v16638;
      int * v16079 = v15546->cache_age;
      int v16080 = v16079[v16583];
      int v16640 = v16080 + ((int)((unsigned int)(v16080 - v16076) >> 31));
      v16079[v16583] = v16640;
      int * v16082 = v15546->cache_age;
      v16082[v16608] = 0;
      v16085 = v16608;
    }
    int * v16086 = v15546->cache_vals;
    int v16643 = v16085 * 2;
    int v16087 = v16086[v16643];
    int v16644 = (v16085 * 2) + 1;
    int v16088 = v16086[v16644];
    int v16645 = (((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v16027 + ((~(((v16029 ^ -1) | (-(v16029 ^ -1))) >> 31)) & 2)) - (v16030 + ((~(((v16031 ^ -1) | (-(v16031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16086[v16645] = v16087;
    int * v16090 = v15546->cache_vals;
    int v16648 = ((((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v16027 + ((~(((v16029 ^ -1) | (-(v16029 ^ -1))) >> 31)) & 2)) - (v16030 + ((~(((v16031 ^ -1) | (-(v16031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16090[v16648] = v16088;
    int * v16092 = v15546->cache_tags;
    int v16651 = ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v16027 + ((~(((v16029 ^ -1) | (-(v16029 ^ -1))) >> 31)) & 2)) - (v16030 + ((~(((v16031 ^ -1) | (-(v16031 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16652 = (int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1);
    v16092[v16651] = v16652;
    int * v16094 = v15546->cache_dirty;
    v16094[v16651] = 0;
    int * v16096 = v15546->cache_age;
    v16096[v16651] = 1;
    int * v16098 = v15546->cache_age;
    int v16099 = v16098[v16651];
    int v16100 = v16098[v16580];
    int v16658 = v16100 + ((int)((unsigned int)(v16100 - v16099) >> 31));
    v16098[v16580] = v16658;
    int * v16102 = v15546->cache_age;
    int v16103 = v16102[v16581];
    int v16660 = v16103 + ((int)((unsigned int)(v16103 - v16099) >> 31));
    v16102[v16581] = v16660;
    int * v16105 = v15546->cache_age;
    v16105[v16651] = 0;
    v16108 = v16651;
  }
  int * v16109 = v15546->cache_vals;
  int v16663 = (v16108 * 2) + (((int)((unsigned int)(v15550 + 28) >> 2)) & 1);
  v16109[v16663] = v15551;
  int * v16111 = v15546->cache_tags;
  int v16112 = v16111[v16582];
  int v16113 = v16111[v16583];
  bool v16666 = !(((~(((v16112 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16112 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v16113 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16113 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v16167;
  if (v16666) {
    int * v16114 = v15546->cache_age;
    int v16668 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16113 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))) | (-(v16113 ^ ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v16115 = v16114[v16668];
    int v16116 = v16114[v16582];
    int v16669 = v16116 + ((int)((unsigned int)(v16116 - v16115) >> 31));
    v16114[v16582] = v16669;
    int * v16118 = v15546->cache_age;
    int v16119 = v16118[v16583];
    int v16671 = v16119 + ((int)((unsigned int)(v16119 - v16115) >> 31));
    v16118[v16583] = v16671;
    int * v16121 = v15546->cache_age;
    v16121[v16668] = 0;
    v16167 = v16668;
  } else {
    int * v16124 = v15546->cache_age;
    int v16675 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2);
    int v16125 = v16124[v16675];
    int * v16126 = v15546->cache_tags;
    int v16127 = v16126[v16675];
    int v16128 = v16124[v16583];
    int v16129 = v16126[v16583];
    int * v16130 = v15546->cache_dirty;
    int v16678 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16125 + ((~(((v16127 ^ -1) | (-(v16127 ^ -1))) >> 31)) & 2)) - (v16128 + ((~(((v16129 ^ -1) | (-(v16129 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16131 = v16130[v16678];
    bool v16679 = !(v16131 == 0);
    if (v16679) {
      int * v16132 = v15546->cache_tags;
      int v16133 = v16132[v16678];
      int * v16134 = v15546->cache_vals;
      int v16682 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16125 + ((~(((v16127 ^ -1) | (-(v16127 ^ -1))) >> 31)) & 2)) - (v16128 + ((~(((v16129 ^ -1) | (-(v16129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v16135 = v16134[v16682];
      int v16683 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16125 + ((~(((v16127 ^ -1) | (-(v16127 ^ -1))) >> 31)) & 2)) - (v16128 + ((~(((v16129 ^ -1) | (-(v16129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v16136 = v16134[v16683];
      int * v16137 = v15546->mem;
      int v16685 = v16133 * 2;
      v16137[v16685] = v16135;
      int * v16139 = v15546->mem;
      int v16688 = (v16133 * 2) + 1;
      v16139[v16688] = v16136;
      ;
    } else {
      ;
    }
    int * v16144 = v15546->mem;
    int v16693 = ((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) * 2;
    int v16145 = v16144[v16693];
    int v16694 = (((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) * 2) + 1;
    int v16146 = v16144[v16694];
    int * v16147 = v15546->cache_vals;
    int v16696 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16125 + ((~(((v16127 ^ -1) | (-(v16127 ^ -1))) >> 31)) & 2)) - (v16128 + ((~(((v16129 ^ -1) | (-(v16129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16147[v16696] = v16145;
    int * v16149 = v15546->cache_vals;
    int v16699 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v16125 + ((~(((v16127 ^ -1) | (-(v16127 ^ -1))) >> 31)) & 2)) - (v16128 + ((~(((v16129 ^ -1) | (-(v16129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16149[v16699] = v16146;
    int * v16151 = v15546->cache_tags;
    int v16702 = (int)((unsigned int)((int)((unsigned int)(v15550 + 28) >> 2)) >> 1);
    v16151[v16678] = v16702;
    int * v16153 = v15546->cache_dirty;
    v16153[v16678] = 0;
    int * v16155 = v15546->cache_age;
    v16155[v16678] = 1;
    int * v16157 = v15546->cache_age;
    int v16158 = v16157[v16678];
    int v16159 = v16157[v16582];
    int v16708 = v16159 + ((int)((unsigned int)(v16159 - v16158) >> 31));
    v16157[v16582] = v16708;
    int * v16161 = v15546->cache_age;
    int v16162 = v16161[v16583];
    int v16710 = v16162 + ((int)((unsigned int)(v16162 - v16158) >> 31));
    v16161[v16583] = v16710;
    int * v16164 = v15546->cache_age;
    v16164[v16678] = 0;
    v16167 = v16678;
  }
  int * v16168 = v15546->cache_vals;
  int v16713 = (v16167 * 2) + (((int)((unsigned int)(v15550 + 28) >> 2)) & 1);
  v16168[v16713] = v15551;
  int * v16170 = v15546->cache_dirty;
  v16170[v16167] = 1;
  bool v16717 = (((((int)((unsigned int)(v15558 + 44) >> 2)) == ((int)((unsigned int)(v15550 + 28) >> 2))) | (((int)((unsigned int)(v15670 + 40) >> 2)) == ((int)((unsigned int)(v15550 + 28) >> 2)))) | (((((int)((unsigned int)(v15782 + 36) >> 2)) & 3) == (((int)((unsigned int)(v15550 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v15782 + 36) >> 2)) == ((int)((unsigned int)(v15550 + 28) >> 2)))))) | (((((int)((unsigned int)(v15899 + 32) >> 2)) & 3) == (((int)((unsigned int)(v15550 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v15899 + 32) >> 2)) == ((int)((unsigned int)(v15550 + 28) >> 2)))));
  struct StateT * v16194;
  if (v16717) {
    int v16172 = v15546->timer;
    int v16718 = v16172 + 15;
    v15546->timer = v16718;
    int * v16174 = v15546->saved_regs;
    int v16175 = v16174[8];
    int * v16176 = v15546->regs;
    v16176[8] = v16175;
    int * v16178 = v15546->saved_regs;
    int v16179 = v16178[9];
    int * v16180 = v15546->regs;
    v16180[9] = v16179;
    int * v16182 = v15546->saved_regs;
    int v16183 = v16182[18];
    int * v16184 = v15546->regs;
    v16184[18] = v16183;
    int * v16186 = v15546->saved_regs;
    int v16187 = v16186[19];
    int * v16188 = v15546->regs;
    v16188[19] = v16187;
    struct StateT * v16190 = slot_229(v15546);
    v16194 = v16190;
  } else {
    struct StateT * v16192 = slot_233(v15546);
    v16194 = v16192;
  }
  return v16194;
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

struct StateT * slot_509(struct StateT * v23885) {
  int v23886 = v23885->timer;
  int v23893 = v23886 + 1;
  v23885->timer = v23893;
  int * v23888 = v23885->regs;
  int v23889 = v23888[22];
  int v23897 = (int)((unsigned int)v23889 >> 23);
  v23888[24] = v23897;
  struct StateT * v23891 = slot_510(v23885);
  return v23891;
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

struct StateT * slot_429(struct StateT * v22553) {
  int v22554 = v22553->timer;
  int v22561 = v22554 + 1;
  v22553->timer = v22561;
  int * v22556 = v22553->regs;
  int v22557 = v22556[22];
  int v22565 = (int)((unsigned int)v22557 >> 23);
  v22556[24] = v22565;
  struct StateT * v22559 = slot_430(v22553);
  return v22559;
}

struct StateT * slot_231(struct StateT * v18617) {
  int v18618 = v18617->timer;
  int v18728 = v18618 + 1;
  v18617->timer = v18728;
  int * v18620 = v18617->regs;
  int v18621 = v18620[2];
  int * v18622 = v18617->cache_tags;
  int v18732 = (((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2;
  int v18623 = v18622[v18732];
  int v18733 = ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18624 = v18622[v18733];
  int v18734 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2);
  int v18625 = v18622[v18734];
  int v18735 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18626 = v18622[v18735];
  int v18627 = v18617->timer;
  int v18736 = v18627 + ((100 ^ (((~(((v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18623 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18623 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18617->timer = v18736;
  int * v18629 = v18617->cache_vals;
  bool v18737 = !(((~(((v18623 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18623 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v18722;
  if (v18737) {
    int * v18630 = v18617->cache_age;
    int v18739 = ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18624 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v18631 = v18630[v18739];
    int v18632 = v18630[v18732];
    int v18740 = v18632 + ((int)((unsigned int)(v18632 - v18631) >> 31));
    v18630[v18732] = v18740;
    int * v18634 = v18617->cache_age;
    int v18635 = v18634[v18733];
    int v18742 = v18635 + ((int)((unsigned int)(v18635 - v18631) >> 31));
    v18634[v18733] = v18742;
    int * v18637 = v18617->cache_age;
    v18637[v18739] = 0;
    v18722 = v18739;
  } else {
    int * v18640 = v18617->cache_age;
    int v18746 = (((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2;
    int v18641 = v18640[v18746];
    int * v18642 = v18617->cache_tags;
    int v18643 = v18642[v18746];
    int v18644 = v18640[v18733];
    int v18645 = v18642[v18733];
    bool v18748 = !(((~(((v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18625 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v18699;
    if (v18748) {
      int * v18646 = v18617->cache_age;
      int v18750 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))) | (-(v18626 ^ ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v18647 = v18646[v18750];
      int v18648 = v18646[v18734];
      int v18751 = v18648 + ((int)((unsigned int)(v18648 - v18647) >> 31));
      v18646[v18734] = v18751;
      int * v18650 = v18617->cache_age;
      int v18651 = v18650[v18735];
      int v18753 = v18651 + ((int)((unsigned int)(v18651 - v18647) >> 31));
      v18650[v18735] = v18753;
      int * v18653 = v18617->cache_age;
      v18653[v18750] = 0;
      v18699 = v18750;
    } else {
      int * v18656 = v18617->cache_age;
      int v18757 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2);
      int v18657 = v18656[v18757];
      int * v18658 = v18617->cache_tags;
      int v18659 = v18658[v18757];
      int v18660 = v18656[v18735];
      int v18661 = v18658[v18735];
      int * v18662 = v18617->cache_dirty;
      int v18760 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v18657 + ((~(((v18659 ^ -1) | (-(v18659 ^ -1))) >> 31)) & 2)) - (v18660 + ((~(((v18661 ^ -1) | (-(v18661 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18663 = v18662[v18760];
      bool v18761 = !(v18663 == 0);
      if (v18761) {
        int * v18664 = v18617->cache_tags;
        int v18665 = v18664[v18760];
        int * v18666 = v18617->cache_vals;
        int v18764 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v18657 + ((~(((v18659 ^ -1) | (-(v18659 ^ -1))) >> 31)) & 2)) - (v18660 + ((~(((v18661 ^ -1) | (-(v18661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18667 = v18666[v18764];
        int v18765 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v18657 + ((~(((v18659 ^ -1) | (-(v18659 ^ -1))) >> 31)) & 2)) - (v18660 + ((~(((v18661 ^ -1) | (-(v18661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18668 = v18666[v18765];
        int * v18669 = v18617->mem;
        int v18767 = v18665 * 2;
        v18669[v18767] = v18667;
        int * v18671 = v18617->mem;
        int v18770 = (v18665 * 2) + 1;
        v18671[v18770] = v18668;
        ;
      } else {
        ;
      }
      int * v18676 = v18617->mem;
      int v18775 = ((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) * 2;
      int v18677 = v18676[v18775];
      int v18776 = (((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) * 2) + 1;
      int v18678 = v18676[v18776];
      int * v18679 = v18617->cache_vals;
      int v18778 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v18657 + ((~(((v18659 ^ -1) | (-(v18659 ^ -1))) >> 31)) & 2)) - (v18660 + ((~(((v18661 ^ -1) | (-(v18661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18679[v18778] = v18677;
      int * v18681 = v18617->cache_vals;
      int v18781 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v18657 + ((~(((v18659 ^ -1) | (-(v18659 ^ -1))) >> 31)) & 2)) - (v18660 + ((~(((v18661 ^ -1) | (-(v18661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18681[v18781] = v18678;
      int * v18683 = v18617->cache_tags;
      int v18784 = (int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1);
      v18683[v18760] = v18784;
      int * v18685 = v18617->cache_dirty;
      v18685[v18760] = 0;
      int * v18687 = v18617->cache_age;
      v18687[v18760] = 1;
      int * v18689 = v18617->cache_age;
      int v18690 = v18689[v18760];
      int v18691 = v18689[v18734];
      int v18790 = v18691 + ((int)((unsigned int)(v18691 - v18690) >> 31));
      v18689[v18734] = v18790;
      int * v18693 = v18617->cache_age;
      int v18694 = v18693[v18735];
      int v18792 = v18694 + ((int)((unsigned int)(v18694 - v18690) >> 31));
      v18693[v18735] = v18792;
      int * v18696 = v18617->cache_age;
      v18696[v18760] = 0;
      v18699 = v18760;
    }
    int * v18700 = v18617->cache_vals;
    int v18795 = v18699 * 2;
    int v18701 = v18700[v18795];
    int v18796 = (v18699 * 2) + 1;
    int v18702 = v18700[v18796];
    int v18797 = (((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v18641 + ((~(((v18643 ^ -1) | (-(v18643 ^ -1))) >> 31)) & 2)) - (v18644 + ((~(((v18645 ^ -1) | (-(v18645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18700[v18797] = v18701;
    int * v18704 = v18617->cache_vals;
    int v18800 = ((((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v18641 + ((~(((v18643 ^ -1) | (-(v18643 ^ -1))) >> 31)) & 2)) - (v18644 + ((~(((v18645 ^ -1) | (-(v18645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18704[v18800] = v18702;
    int * v18706 = v18617->cache_tags;
    int v18803 = ((((int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v18641 + ((~(((v18643 ^ -1) | (-(v18643 ^ -1))) >> 31)) & 2)) - (v18644 + ((~(((v18645 ^ -1) | (-(v18645 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18804 = (int)((unsigned int)((int)((unsigned int)(v18621 + 36) >> 2)) >> 1);
    v18706[v18803] = v18804;
    int * v18708 = v18617->cache_dirty;
    v18708[v18803] = 0;
    int * v18710 = v18617->cache_age;
    v18710[v18803] = 1;
    int * v18712 = v18617->cache_age;
    int v18713 = v18712[v18803];
    int v18714 = v18712[v18732];
    int v18810 = v18714 + ((int)((unsigned int)(v18714 - v18713) >> 31));
    v18712[v18732] = v18810;
    int * v18716 = v18617->cache_age;
    int v18717 = v18716[v18733];
    int v18812 = v18717 + ((int)((unsigned int)(v18717 - v18713) >> 31));
    v18716[v18733] = v18812;
    int * v18719 = v18617->cache_age;
    v18719[v18803] = 0;
    v18722 = v18803;
  }
  int v18815 = (v18722 * 2) + (((int)((unsigned int)(v18621 + 36) >> 2)) & 1);
  int v18723 = v18629[v18815];
  int * v18724 = v18617->regs;
  v18724[18] = v18723;
  struct StateT * v18726 = slot_232(v18617);
  return v18726;
}

struct StateT * slot_355(struct StateT * v21342) {
  int v21343 = v21342->timer;
  int v21351 = v21343 + 1;
  v21342->timer = v21351;
  int * v21345 = v21342->regs;
  int v21346 = v21345[6];
  int v21347 = v21345[22];
  int v21355 = v21346 ^ v21347;
  v21345[6] = v21355;
  struct StateT * v21349 = slot_356(v21342);
  return v21349;
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

struct StateT * slot_232(struct StateT * v19053) {
  int v19054 = v19053->timer;
  int v19164 = v19054 + 1;
  v19053->timer = v19164;
  int * v19056 = v19053->regs;
  int v19057 = v19056[2];
  int * v19058 = v19053->cache_tags;
  int v19168 = (((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2;
  int v19059 = v19058[v19168];
  int v19169 = ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19060 = v19058[v19169];
  int v19170 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2);
  int v19061 = v19058[v19170];
  int v19171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19062 = v19058[v19171];
  int v19063 = v19053->timer;
  int v19172 = v19063 + ((100 ^ (((~(((v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19059 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19059 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19053->timer = v19172;
  int * v19065 = v19053->cache_vals;
  bool v19173 = !(((~(((v19059 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19059 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v19158;
  if (v19173) {
    int * v19066 = v19053->cache_age;
    int v19175 = ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19060 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v19067 = v19066[v19175];
    int v19068 = v19066[v19168];
    int v19176 = v19068 + ((int)((unsigned int)(v19068 - v19067) >> 31));
    v19066[v19168] = v19176;
    int * v19070 = v19053->cache_age;
    int v19071 = v19070[v19169];
    int v19178 = v19071 + ((int)((unsigned int)(v19071 - v19067) >> 31));
    v19070[v19169] = v19178;
    int * v19073 = v19053->cache_age;
    v19073[v19175] = 0;
    v19158 = v19175;
  } else {
    int * v19076 = v19053->cache_age;
    int v19182 = (((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2;
    int v19077 = v19076[v19182];
    int * v19078 = v19053->cache_tags;
    int v19079 = v19078[v19182];
    int v19080 = v19076[v19169];
    int v19081 = v19078[v19169];
    bool v19184 = !(((~(((v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19061 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v19135;
    if (v19184) {
      int * v19082 = v19053->cache_age;
      int v19186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))) | (-(v19062 ^ ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v19083 = v19082[v19186];
      int v19084 = v19082[v19170];
      int v19187 = v19084 + ((int)((unsigned int)(v19084 - v19083) >> 31));
      v19082[v19170] = v19187;
      int * v19086 = v19053->cache_age;
      int v19087 = v19086[v19171];
      int v19189 = v19087 + ((int)((unsigned int)(v19087 - v19083) >> 31));
      v19086[v19171] = v19189;
      int * v19089 = v19053->cache_age;
      v19089[v19186] = 0;
      v19135 = v19186;
    } else {
      int * v19092 = v19053->cache_age;
      int v19193 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2);
      int v19093 = v19092[v19193];
      int * v19094 = v19053->cache_tags;
      int v19095 = v19094[v19193];
      int v19096 = v19092[v19171];
      int v19097 = v19094[v19171];
      int * v19098 = v19053->cache_dirty;
      int v19196 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19093 + ((~(((v19095 ^ -1) | (-(v19095 ^ -1))) >> 31)) & 2)) - (v19096 + ((~(((v19097 ^ -1) | (-(v19097 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19099 = v19098[v19196];
      bool v19197 = !(v19099 == 0);
      if (v19197) {
        int * v19100 = v19053->cache_tags;
        int v19101 = v19100[v19196];
        int * v19102 = v19053->cache_vals;
        int v19200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19093 + ((~(((v19095 ^ -1) | (-(v19095 ^ -1))) >> 31)) & 2)) - (v19096 + ((~(((v19097 ^ -1) | (-(v19097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19103 = v19102[v19200];
        int v19201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19093 + ((~(((v19095 ^ -1) | (-(v19095 ^ -1))) >> 31)) & 2)) - (v19096 + ((~(((v19097 ^ -1) | (-(v19097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19104 = v19102[v19201];
        int * v19105 = v19053->mem;
        int v19203 = v19101 * 2;
        v19105[v19203] = v19103;
        int * v19107 = v19053->mem;
        int v19206 = (v19101 * 2) + 1;
        v19107[v19206] = v19104;
        ;
      } else {
        ;
      }
      int * v19112 = v19053->mem;
      int v19211 = ((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) * 2;
      int v19113 = v19112[v19211];
      int v19212 = (((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) * 2) + 1;
      int v19114 = v19112[v19212];
      int * v19115 = v19053->cache_vals;
      int v19214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19093 + ((~(((v19095 ^ -1) | (-(v19095 ^ -1))) >> 31)) & 2)) - (v19096 + ((~(((v19097 ^ -1) | (-(v19097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19115[v19214] = v19113;
      int * v19117 = v19053->cache_vals;
      int v19217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19093 + ((~(((v19095 ^ -1) | (-(v19095 ^ -1))) >> 31)) & 2)) - (v19096 + ((~(((v19097 ^ -1) | (-(v19097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19117[v19217] = v19114;
      int * v19119 = v19053->cache_tags;
      int v19220 = (int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1);
      v19119[v19196] = v19220;
      int * v19121 = v19053->cache_dirty;
      v19121[v19196] = 0;
      int * v19123 = v19053->cache_age;
      v19123[v19196] = 1;
      int * v19125 = v19053->cache_age;
      int v19126 = v19125[v19196];
      int v19127 = v19125[v19170];
      int v19226 = v19127 + ((int)((unsigned int)(v19127 - v19126) >> 31));
      v19125[v19170] = v19226;
      int * v19129 = v19053->cache_age;
      int v19130 = v19129[v19171];
      int v19228 = v19130 + ((int)((unsigned int)(v19130 - v19126) >> 31));
      v19129[v19171] = v19228;
      int * v19132 = v19053->cache_age;
      v19132[v19196] = 0;
      v19135 = v19196;
    }
    int * v19136 = v19053->cache_vals;
    int v19231 = v19135 * 2;
    int v19137 = v19136[v19231];
    int v19232 = (v19135 * 2) + 1;
    int v19138 = v19136[v19232];
    int v19233 = (((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19077 + ((~(((v19079 ^ -1) | (-(v19079 ^ -1))) >> 31)) & 2)) - (v19080 + ((~(((v19081 ^ -1) | (-(v19081 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19136[v19233] = v19137;
    int * v19140 = v19053->cache_vals;
    int v19236 = ((((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19077 + ((~(((v19079 ^ -1) | (-(v19079 ^ -1))) >> 31)) & 2)) - (v19080 + ((~(((v19081 ^ -1) | (-(v19081 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19140[v19236] = v19138;
    int * v19142 = v19053->cache_tags;
    int v19239 = ((((int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19077 + ((~(((v19079 ^ -1) | (-(v19079 ^ -1))) >> 31)) & 2)) - (v19080 + ((~(((v19081 ^ -1) | (-(v19081 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19240 = (int)((unsigned int)((int)((unsigned int)(v19057 + 32) >> 2)) >> 1);
    v19142[v19239] = v19240;
    int * v19144 = v19053->cache_dirty;
    v19144[v19239] = 0;
    int * v19146 = v19053->cache_age;
    v19146[v19239] = 1;
    int * v19148 = v19053->cache_age;
    int v19149 = v19148[v19239];
    int v19150 = v19148[v19168];
    int v19246 = v19150 + ((int)((unsigned int)(v19150 - v19149) >> 31));
    v19148[v19168] = v19246;
    int * v19152 = v19053->cache_age;
    int v19153 = v19152[v19169];
    int v19248 = v19153 + ((int)((unsigned int)(v19153 - v19149) >> 31));
    v19152[v19169] = v19248;
    int * v19155 = v19053->cache_age;
    v19155[v19239] = 0;
    v19158 = v19239;
  }
  int v19251 = (v19158 * 2) + (((int)((unsigned int)(v19057 + 32) >> 2)) & 1);
  int v19159 = v19065[v19251];
  int * v19160 = v19053->regs;
  v19160[19] = v19159;
  struct StateT * v19162 = slot_233(v19053);
  return v19162;
}

struct StateT * slot_466(struct StateT * v23188) {
  int v23189 = v23188->timer;
  int v23196 = v23189 + 1;
  v23188->timer = v23196;
  int * v23191 = v23188->regs;
  int v23192 = v23191[21];
  int v23200 = (int)((unsigned int)v23192 >> 14);
  v23191[24] = v23200;
  struct StateT * v23194 = slot_467(v23188);
  return v23194;
}

struct StateT * slot_304(struct StateT * v20551) {
  int v20552 = v20551->timer;
  int v20559 = v20552 + 1;
  v20551->timer = v20559;
  int * v20554 = v20551->regs;
  int v20555 = v20554[21];
  int v20563 = (int)((unsigned int)v20555 >> 14);
  v20554[24] = v20563;
  struct StateT * v20557 = slot_305(v20551);
  return v20557;
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

struct StateT * slot_236(struct StateT * v18194) {
  int v18195 = v18194->timer;
  int v18305 = v18195 + 1;
  v18194->timer = v18305;
  int * v18197 = v18194->regs;
  int v18198 = v18197[2];
  int * v18199 = v18194->cache_tags;
  int v18309 = (((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2;
  int v18200 = v18199[v18309];
  int v18310 = ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18201 = v18199[v18310];
  int v18311 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2);
  int v18202 = v18199[v18311];
  int v18312 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18203 = v18199[v18312];
  int v18204 = v18194->timer;
  int v18313 = v18204 + ((100 ^ (((~(((v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18200 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18200 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18194->timer = v18313;
  int * v18206 = v18194->cache_vals;
  bool v18314 = !(((~(((v18200 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18200 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v18299;
  if (v18314) {
    int * v18207 = v18194->cache_age;
    int v18316 = ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18201 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v18208 = v18207[v18316];
    int v18209 = v18207[v18309];
    int v18317 = v18209 + ((int)((unsigned int)(v18209 - v18208) >> 31));
    v18207[v18309] = v18317;
    int * v18211 = v18194->cache_age;
    int v18212 = v18211[v18310];
    int v18319 = v18212 + ((int)((unsigned int)(v18212 - v18208) >> 31));
    v18211[v18310] = v18319;
    int * v18214 = v18194->cache_age;
    v18214[v18316] = 0;
    v18299 = v18316;
  } else {
    int * v18217 = v18194->cache_age;
    int v18323 = (((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2;
    int v18218 = v18217[v18323];
    int * v18219 = v18194->cache_tags;
    int v18220 = v18219[v18323];
    int v18221 = v18217[v18310];
    int v18222 = v18219[v18310];
    bool v18325 = !(((~(((v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18202 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v18276;
    if (v18325) {
      int * v18223 = v18194->cache_age;
      int v18327 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))) | (-(v18203 ^ ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v18224 = v18223[v18327];
      int v18225 = v18223[v18311];
      int v18328 = v18225 + ((int)((unsigned int)(v18225 - v18224) >> 31));
      v18223[v18311] = v18328;
      int * v18227 = v18194->cache_age;
      int v18228 = v18227[v18312];
      int v18330 = v18228 + ((int)((unsigned int)(v18228 - v18224) >> 31));
      v18227[v18312] = v18330;
      int * v18230 = v18194->cache_age;
      v18230[v18327] = 0;
      v18276 = v18327;
    } else {
      int * v18233 = v18194->cache_age;
      int v18334 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2);
      int v18234 = v18233[v18334];
      int * v18235 = v18194->cache_tags;
      int v18236 = v18235[v18334];
      int v18237 = v18233[v18312];
      int v18238 = v18235[v18312];
      int * v18239 = v18194->cache_dirty;
      int v18337 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18234 + ((~(((v18236 ^ -1) | (-(v18236 ^ -1))) >> 31)) & 2)) - (v18237 + ((~(((v18238 ^ -1) | (-(v18238 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18240 = v18239[v18337];
      bool v18338 = !(v18240 == 0);
      if (v18338) {
        int * v18241 = v18194->cache_tags;
        int v18242 = v18241[v18337];
        int * v18243 = v18194->cache_vals;
        int v18341 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18234 + ((~(((v18236 ^ -1) | (-(v18236 ^ -1))) >> 31)) & 2)) - (v18237 + ((~(((v18238 ^ -1) | (-(v18238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18244 = v18243[v18341];
        int v18342 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18234 + ((~(((v18236 ^ -1) | (-(v18236 ^ -1))) >> 31)) & 2)) - (v18237 + ((~(((v18238 ^ -1) | (-(v18238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18245 = v18243[v18342];
        int * v18246 = v18194->mem;
        int v18344 = v18242 * 2;
        v18246[v18344] = v18244;
        int * v18248 = v18194->mem;
        int v18347 = (v18242 * 2) + 1;
        v18248[v18347] = v18245;
        ;
      } else {
        ;
      }
      int * v18253 = v18194->mem;
      int v18352 = ((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) * 2;
      int v18254 = v18253[v18352];
      int v18353 = (((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) * 2) + 1;
      int v18255 = v18253[v18353];
      int * v18256 = v18194->cache_vals;
      int v18355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18234 + ((~(((v18236 ^ -1) | (-(v18236 ^ -1))) >> 31)) & 2)) - (v18237 + ((~(((v18238 ^ -1) | (-(v18238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18256[v18355] = v18254;
      int * v18258 = v18194->cache_vals;
      int v18358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18234 + ((~(((v18236 ^ -1) | (-(v18236 ^ -1))) >> 31)) & 2)) - (v18237 + ((~(((v18238 ^ -1) | (-(v18238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18258[v18358] = v18255;
      int * v18260 = v18194->cache_tags;
      int v18361 = (int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1);
      v18260[v18337] = v18361;
      int * v18262 = v18194->cache_dirty;
      v18262[v18337] = 0;
      int * v18264 = v18194->cache_age;
      v18264[v18337] = 1;
      int * v18266 = v18194->cache_age;
      int v18267 = v18266[v18337];
      int v18268 = v18266[v18311];
      int v18367 = v18268 + ((int)((unsigned int)(v18268 - v18267) >> 31));
      v18266[v18311] = v18367;
      int * v18270 = v18194->cache_age;
      int v18271 = v18270[v18312];
      int v18369 = v18271 + ((int)((unsigned int)(v18271 - v18267) >> 31));
      v18270[v18312] = v18369;
      int * v18273 = v18194->cache_age;
      v18273[v18337] = 0;
      v18276 = v18337;
    }
    int * v18277 = v18194->cache_vals;
    int v18372 = v18276 * 2;
    int v18278 = v18277[v18372];
    int v18373 = (v18276 * 2) + 1;
    int v18279 = v18277[v18373];
    int v18374 = (((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18218 + ((~(((v18220 ^ -1) | (-(v18220 ^ -1))) >> 31)) & 2)) - (v18221 + ((~(((v18222 ^ -1) | (-(v18222 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18277[v18374] = v18278;
    int * v18281 = v18194->cache_vals;
    int v18377 = ((((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18218 + ((~(((v18220 ^ -1) | (-(v18220 ^ -1))) >> 31)) & 2)) - (v18221 + ((~(((v18222 ^ -1) | (-(v18222 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18281[v18377] = v18279;
    int * v18283 = v18194->cache_tags;
    int v18380 = ((((int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18218 + ((~(((v18220 ^ -1) | (-(v18220 ^ -1))) >> 31)) & 2)) - (v18221 + ((~(((v18222 ^ -1) | (-(v18222 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18381 = (int)((unsigned int)((int)((unsigned int)(v18198 + 24) >> 2)) >> 1);
    v18283[v18380] = v18381;
    int * v18285 = v18194->cache_dirty;
    v18285[v18380] = 0;
    int * v18287 = v18194->cache_age;
    v18287[v18380] = 1;
    int * v18289 = v18194->cache_age;
    int v18290 = v18289[v18380];
    int v18291 = v18289[v18309];
    int v18387 = v18291 + ((int)((unsigned int)(v18291 - v18290) >> 31));
    v18289[v18309] = v18387;
    int * v18293 = v18194->cache_age;
    int v18294 = v18293[v18310];
    int v18389 = v18294 + ((int)((unsigned int)(v18294 - v18290) >> 31));
    v18293[v18310] = v18389;
    int * v18296 = v18194->cache_age;
    v18296[v18380] = 0;
    v18299 = v18380;
  }
  int v18392 = (v18299 * 2) + (((int)((unsigned int)(v18198 + 24) >> 2)) & 1);
  int v18300 = v18206[v18392];
  int * v18301 = v18194->regs;
  v18301[21] = v18300;
  struct StateT * v18303 = slot_227(v18194);
  return v18303;
}

struct StateT * slot_241(struct StateT * v19039) {
  int v19040 = v19039->timer;
  int v19047 = v19040 + 1;
  v19039->timer = v19047;
  int * v19042 = v19039->regs;
  int v19043 = v19042[22];
  int v19050 = v19043 << 7;
  v19042[22] = v19050;
  struct StateT * v19045 = slot_244(v19039);
  return v19045;
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

struct StateT * slot_519(struct StateT * v24039) {
  int v24040 = v24039->timer;
  int v24048 = v24040 + 1;
  v24039->timer = v24048;
  int * v24042 = v24039->regs;
  int v24043 = v24042[17];
  int v24044 = v24042[14];
  int v24053 = v24043 + v24044;
  v24042[20] = v24053;
  struct StateT * v24046 = slot_520(v24039);
  return v24046;
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

struct StateT * slot_391(struct StateT * v21904) {
  int v21905 = v21904->timer;
  int v21912 = v21905 + 1;
  v21904->timer = v21912;
  int * v21907 = v21904->regs;
  int v21908 = v21907[23];
  int v21915 = v21908 << 18;
  v21907[23] = v21915;
  struct StateT * v21910 = slot_392(v21904);
  return v21910;
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

struct StateT * slot_262(struct StateT * v19897) {
  int v19898 = v19897->timer;
  int v19905 = v19898 + 1;
  v19897->timer = v19905;
  int * v19900 = v19897->regs;
  int v19901 = v19900[20];
  int v19908 = v19901 << 9;
  v19900[20] = v19908;
  struct StateT * v19903 = slot_263(v19897);
  return v19903;
}

struct StateT * slot_351(struct StateT * v21280) {
  int v21281 = v21280->timer;
  int v21288 = v21281 + 1;
  v21280->timer = v21288;
  int * v21283 = v21280->regs;
  int v21284 = v21283[23];
  int v21291 = v21284 << 9;
  v21283[23] = v21291;
  struct StateT * v21286 = slot_352(v21280);
  return v21286;
}

struct StateT * slot_372(struct StateT * v21606) {
  int v21607 = v21606->timer;
  int v21615 = v21607 + 1;
  v21606->timer = v21615;
  int * v21609 = v21606->regs;
  int v21610 = v21609[23];
  int v21611 = v21609[24];
  int v21619 = v21610 | v21611;
  v21609[23] = v21619;
  struct StateT * v21613 = slot_373(v21606);
  return v21613;
}

struct StateT * slot_403(struct StateT * v22116) {
  int * v22117 = v22116->saved_regs;
  int * v22118 = v22116->regs;
  int v22119 = v22118[24];
  v22117[24] = v22119;
  int v22121 = v22116->timer;
  int v22132 = v22121 + 1;
  v22116->timer = v22132;
  int * v22123 = v22116->regs;
  int v22124 = v22123[20];
  int v22135 = (int)((unsigned int)v22124 >> 25);
  v22123[24] = v22135;
  struct StateT * v22126 = slot_404(v22116);
  return v22126;
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

struct StateT * slot_555(struct StateT * v24599) {
  int v24600 = v24599->timer;
  int v24608 = v24600 + 1;
  v24599->timer = v24608;
  int * v24602 = v24599->regs;
  int v24603 = v24602[30];
  int v24604 = v24602[20];
  int v24612 = v24603 ^ v24604;
  v24602[30] = v24612;
  struct StateT * v24606 = slot_556(v24599);
  return v24606;
}

struct StateT * slot_541(struct StateT * v24385) {
  int v24386 = v24385->timer;
  int v24394 = v24386 + 1;
  v24385->timer = v24394;
  int * v24388 = v24385->regs;
  int v24389 = v24388[18];
  int v24390 = v24388[6];
  int v24399 = v24389 + v24390;
  v24388[22] = v24399;
  struct StateT * v24392 = slot_542(v24385);
  return v24392;
}

struct StateT * slot_325(struct StateT * v20878) {
  int v20879 = v20878->timer;
  int v20886 = v20879 + 1;
  v20878->timer = v20886;
  int * v20881 = v20878->regs;
  int v20882 = v20881[21];
  int v20889 = v20882 << 7;
  v20881[21] = v20889;
  struct StateT * v20884 = slot_326(v20878);
  return v20884;
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

struct StateT * slot_517(struct StateT * v24007) {
  int v24008 = v24007->timer;
  int v24016 = v24008 + 1;
  v24007->timer = v24016;
  int * v24010 = v24007->regs;
  int v24011 = v24010[6];
  int v24012 = v24010[22];
  int v24020 = v24011 ^ v24012;
  v24010[6] = v24020;
  struct StateT * v24014 = slot_518(v24007);
  return v24014;
}

struct StateT * slot_229(struct StateT * v17158) {
  int v17159 = v17158->timer;
  int v17269 = v17159 + 1;
  v17158->timer = v17269;
  int * v17161 = v17158->regs;
  int v17162 = v17161[2];
  int * v17163 = v17158->cache_tags;
  int v17273 = (((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2;
  int v17164 = v17163[v17273];
  int v17274 = ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17165 = v17163[v17274];
  int v17275 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2);
  int v17166 = v17163[v17275];
  int v17276 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17167 = v17163[v17276];
  int v17168 = v17158->timer;
  int v17277 = v17168 + ((100 ^ (((~(((v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17164 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17164 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17158->timer = v17277;
  int * v17170 = v17158->cache_vals;
  bool v17278 = !(((~(((v17164 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17164 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v17263;
  if (v17278) {
    int * v17171 = v17158->cache_age;
    int v17280 = ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17165 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v17172 = v17171[v17280];
    int v17173 = v17171[v17273];
    int v17281 = v17173 + ((int)((unsigned int)(v17173 - v17172) >> 31));
    v17171[v17273] = v17281;
    int * v17175 = v17158->cache_age;
    int v17176 = v17175[v17274];
    int v17283 = v17176 + ((int)((unsigned int)(v17176 - v17172) >> 31));
    v17175[v17274] = v17283;
    int * v17178 = v17158->cache_age;
    v17178[v17280] = 0;
    v17263 = v17280;
  } else {
    int * v17181 = v17158->cache_age;
    int v17287 = (((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2;
    int v17182 = v17181[v17287];
    int * v17183 = v17158->cache_tags;
    int v17184 = v17183[v17287];
    int v17185 = v17181[v17274];
    int v17186 = v17183[v17274];
    bool v17289 = !(((~(((v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17166 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v17240;
    if (v17289) {
      int * v17187 = v17158->cache_age;
      int v17291 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))) | (-(v17167 ^ ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v17188 = v17187[v17291];
      int v17189 = v17187[v17275];
      int v17292 = v17189 + ((int)((unsigned int)(v17189 - v17188) >> 31));
      v17187[v17275] = v17292;
      int * v17191 = v17158->cache_age;
      int v17192 = v17191[v17276];
      int v17294 = v17192 + ((int)((unsigned int)(v17192 - v17188) >> 31));
      v17191[v17276] = v17294;
      int * v17194 = v17158->cache_age;
      v17194[v17291] = 0;
      v17240 = v17291;
    } else {
      int * v17197 = v17158->cache_age;
      int v17298 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2);
      int v17198 = v17197[v17298];
      int * v17199 = v17158->cache_tags;
      int v17200 = v17199[v17298];
      int v17201 = v17197[v17276];
      int v17202 = v17199[v17276];
      int * v17203 = v17158->cache_dirty;
      int v17301 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v17198 + ((~(((v17200 ^ -1) | (-(v17200 ^ -1))) >> 31)) & 2)) - (v17201 + ((~(((v17202 ^ -1) | (-(v17202 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17204 = v17203[v17301];
      bool v17302 = !(v17204 == 0);
      if (v17302) {
        int * v17205 = v17158->cache_tags;
        int v17206 = v17205[v17301];
        int * v17207 = v17158->cache_vals;
        int v17305 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v17198 + ((~(((v17200 ^ -1) | (-(v17200 ^ -1))) >> 31)) & 2)) - (v17201 + ((~(((v17202 ^ -1) | (-(v17202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17208 = v17207[v17305];
        int v17306 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v17198 + ((~(((v17200 ^ -1) | (-(v17200 ^ -1))) >> 31)) & 2)) - (v17201 + ((~(((v17202 ^ -1) | (-(v17202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17209 = v17207[v17306];
        int * v17210 = v17158->mem;
        int v17308 = v17206 * 2;
        v17210[v17308] = v17208;
        int * v17212 = v17158->mem;
        int v17311 = (v17206 * 2) + 1;
        v17212[v17311] = v17209;
        ;
      } else {
        ;
      }
      int * v17217 = v17158->mem;
      int v17316 = ((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) * 2;
      int v17218 = v17217[v17316];
      int v17317 = (((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) * 2) + 1;
      int v17219 = v17217[v17317];
      int * v17220 = v17158->cache_vals;
      int v17319 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v17198 + ((~(((v17200 ^ -1) | (-(v17200 ^ -1))) >> 31)) & 2)) - (v17201 + ((~(((v17202 ^ -1) | (-(v17202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17220[v17319] = v17218;
      int * v17222 = v17158->cache_vals;
      int v17322 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v17198 + ((~(((v17200 ^ -1) | (-(v17200 ^ -1))) >> 31)) & 2)) - (v17201 + ((~(((v17202 ^ -1) | (-(v17202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17222[v17322] = v17219;
      int * v17224 = v17158->cache_tags;
      int v17325 = (int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1);
      v17224[v17301] = v17325;
      int * v17226 = v17158->cache_dirty;
      v17226[v17301] = 0;
      int * v17228 = v17158->cache_age;
      v17228[v17301] = 1;
      int * v17230 = v17158->cache_age;
      int v17231 = v17230[v17301];
      int v17232 = v17230[v17275];
      int v17331 = v17232 + ((int)((unsigned int)(v17232 - v17231) >> 31));
      v17230[v17275] = v17331;
      int * v17234 = v17158->cache_age;
      int v17235 = v17234[v17276];
      int v17333 = v17235 + ((int)((unsigned int)(v17235 - v17231) >> 31));
      v17234[v17276] = v17333;
      int * v17237 = v17158->cache_age;
      v17237[v17301] = 0;
      v17240 = v17301;
    }
    int * v17241 = v17158->cache_vals;
    int v17336 = v17240 * 2;
    int v17242 = v17241[v17336];
    int v17337 = (v17240 * 2) + 1;
    int v17243 = v17241[v17337];
    int v17338 = (((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v17182 + ((~(((v17184 ^ -1) | (-(v17184 ^ -1))) >> 31)) & 2)) - (v17185 + ((~(((v17186 ^ -1) | (-(v17186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17241[v17338] = v17242;
    int * v17245 = v17158->cache_vals;
    int v17341 = ((((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v17182 + ((~(((v17184 ^ -1) | (-(v17184 ^ -1))) >> 31)) & 2)) - (v17185 + ((~(((v17186 ^ -1) | (-(v17186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17245[v17341] = v17243;
    int * v17247 = v17158->cache_tags;
    int v17344 = ((((int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v17182 + ((~(((v17184 ^ -1) | (-(v17184 ^ -1))) >> 31)) & 2)) - (v17185 + ((~(((v17186 ^ -1) | (-(v17186 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17345 = (int)((unsigned int)((int)((unsigned int)(v17162 + 44) >> 2)) >> 1);
    v17247[v17344] = v17345;
    int * v17249 = v17158->cache_dirty;
    v17249[v17344] = 0;
    int * v17251 = v17158->cache_age;
    v17251[v17344] = 1;
    int * v17253 = v17158->cache_age;
    int v17254 = v17253[v17344];
    int v17255 = v17253[v17273];
    int v17351 = v17255 + ((int)((unsigned int)(v17255 - v17254) >> 31));
    v17253[v17273] = v17351;
    int * v17257 = v17158->cache_age;
    int v17258 = v17257[v17274];
    int v17353 = v17258 + ((int)((unsigned int)(v17258 - v17254) >> 31));
    v17257[v17274] = v17353;
    int * v17260 = v17158->cache_age;
    v17260[v17344] = 0;
    v17263 = v17344;
  }
  int v17356 = (v17263 * 2) + (((int)((unsigned int)(v17162 + 44) >> 2)) & 1);
  int v17264 = v17170[v17356];
  int * v17265 = v17158->regs;
  v17265[8] = v17264;
  struct StateT * v17267 = slot_218(v17158);
  return v17267;
}

struct StateT * slot_358(struct StateT * v21391) {
  int v21392 = v21391->timer;
  int v21400 = v21392 + 1;
  v21391->timer = v21400;
  int * v21394 = v21391->regs;
  int v21395 = v21394[5];
  int v21396 = v21394[12];
  int v21405 = v21395 + v21396;
  v21394[21] = v21405;
  struct StateT * v21398 = slot_359(v21391);
  return v21398;
}

struct StateT * slot_465(struct StateT * v23172) {
  int v23173 = v23172->timer;
  int v23181 = v23173 + 1;
  v23172->timer = v23181;
  int * v23175 = v23172->regs;
  int v23176 = v23175[20];
  int v23177 = v23175[24];
  int v23185 = v23176 | v23177;
  v23175[20] = v23185;
  struct StateT * v23179 = slot_466(v23172);
  return v23179;
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

struct StateT * slot_542(struct StateT * v24402) {
  int v24403 = v24402->timer;
  int v24411 = v24403 + 1;
  v24402->timer = v24411;
  int * v24405 = v24402->regs;
  int v24406 = v24405[19];
  int v24407 = v24405[7];
  int v24416 = v24406 + v24407;
  v24405[23] = v24416;
  struct StateT * v24409 = slot_543(v24402);
  return v24409;
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

struct StateT * slot_260(struct StateT * v19865) {
  int v19866 = v19865->timer;
  int v19874 = v19866 + 1;
  v19865->timer = v19874;
  int * v19868 = v19865->regs;
  int v19869 = v19868[8];
  int v19870 = v19868[31];
  int v19879 = v19869 + v19870;
  v19868[23] = v19879;
  struct StateT * v19872 = slot_261(v19865);
  return v19872;
}

struct StateT * slot_481(struct StateT * v23449) {
  int v23450 = v23449->timer;
  int v23458 = v23450 + 1;
  v23449->timer = v23458;
  int * v23452 = v23449->regs;
  int v23453 = v23452[28];
  int v23454 = v23452[18];
  int v23463 = v23453 + v23454;
  v23452[22] = v23463;
  struct StateT * v23456 = slot_482(v23449);
  return v23456;
}

struct StateT * slot_305(struct StateT * v20566) {
  int v20567 = v20566->timer;
  int v20574 = v20567 + 1;
  v20566->timer = v20574;
  int * v20569 = v20566->regs;
  int v20570 = v20569[21];
  int v20577 = v20570 << 18;
  v20569[21] = v20577;
  struct StateT * v20572 = slot_306(v20566);
  return v20572;
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

struct StateT * slot_454(struct StateT * v22967) {
  int v22968 = v22967->timer;
  int v22976 = v22968 + 1;
  v22967->timer = v22976;
  int * v22970 = v22967->regs;
  int v22971 = v22970[23];
  int v22972 = v22970[24];
  int v22980 = v22971 | v22972;
  v22970[23] = v22980;
  struct StateT * v22974 = slot_455(v22967);
  return v22974;
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

struct StateT * slot_482(struct StateT * v23466) {
  int v23467 = v23466->timer;
  int v23475 = v23467 + 1;
  v23466->timer = v23475;
  int * v23469 = v23466->regs;
  int v23470 = v23469[31];
  int v23471 = v23469[19];
  int v23480 = v23470 + v23471;
  v23469[23] = v23480;
  struct StateT * v23473 = slot_483(v23466);
  return v23473;
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

struct StateT * slot_406(struct StateT * v22168) {
  int v22169 = v22168->timer;
  int v22176 = v22169 + 1;
  v22168->timer = v22176;
  int * v22171 = v22168->regs;
  int v22172 = v22171[21];
  int v22180 = (int)((unsigned int)v22172 >> 25);
  v22171[24] = v22180;
  struct StateT * v22174 = slot_407(v22168);
  return v22174;
}

struct StateT * slot_292(struct StateT * v20358) {
  int v20359 = v20358->timer;
  int v20367 = v20359 + 1;
  v20358->timer = v20367;
  int * v20361 = v20358->regs;
  int v20362 = v20361[23];
  int v20363 = v20361[24];
  int v20371 = v20362 | v20363;
  v20361[23] = v20371;
  struct StateT * v20365 = slot_293(v20358);
  return v20365;
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

struct StateT * slot_525(struct StateT * v24136) {
  int v24137 = v24136->timer;
  int v24145 = v24137 + 1;
  v24136->timer = v24145;
  int * v24139 = v24136->regs;
  int v24140 = v24139[20];
  int v24141 = v24139[24];
  int v24149 = v24140 | v24141;
  v24139[20] = v24149;
  struct StateT * v24143 = slot_526(v24136);
  return v24143;
}

struct StateT * slot_515(struct StateT * v23975) {
  int v23976 = v23975->timer;
  int v23984 = v23976 + 1;
  v23975->timer = v23984;
  int * v23978 = v23975->regs;
  int v23979 = v23978[17];
  int v23980 = v23978[20];
  int v23988 = v23979 ^ v23980;
  v23978[17] = v23988;
  struct StateT * v23982 = slot_516(v23975);
  return v23982;
}

struct StateT * slot_376(struct StateT * v21670) {
  int v21671 = v21670->timer;
  int v21679 = v21671 + 1;
  v21670->timer = v21679;
  int * v21673 = v21670->regs;
  int v21674 = v21673[19];
  int v21675 = v21673[23];
  int v21683 = v21674 ^ v21675;
  v21673[19] = v21683;
  struct StateT * v21677 = slot_377(v21670);
  return v21677;
}

struct StateT * slot_373(struct StateT * v21622) {
  int v21623 = v21622->timer;
  int v21631 = v21623 + 1;
  v21622->timer = v21631;
  int * v21625 = v21622->regs;
  int v21626 = v21625[8];
  int v21627 = v21625[20];
  int v21635 = v21626 ^ v21627;
  v21625[8] = v21635;
  struct StateT * v21629 = slot_374(v21622);
  return v21629;
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

struct StateT * slot_340(struct StateT * v21113) {
  int v21114 = v21113->timer;
  int v21122 = v21114 + 1;
  v21113->timer = v21122;
  int * v21116 = v21113->regs;
  int v21117 = v21116[16];
  int v21118 = v21116[31];
  int v21127 = v21117 + v21118;
  v21116[23] = v21127;
  struct StateT * v21120 = slot_341(v21113);
  return v21120;
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

struct StateT * slot_383(struct StateT * v21783) {
  int v21784 = v21783->timer;
  int v21792 = v21784 + 1;
  v21783->timer = v21792;
  int * v21786 = v21783->regs;
  int v21787 = v21786[20];
  int v21788 = v21786[24];
  int v21796 = v21787 | v21788;
  v21786[20] = v21796;
  struct StateT * v21790 = slot_384(v21783);
  return v21790;
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

struct StateT * slot_489(struct StateT * v23573) {
  int v23574 = v23573->timer;
  int v23581 = v23574 + 1;
  v23573->timer = v23581;
  int * v23576 = v23573->regs;
  int v23577 = v23576[22];
  int v23585 = (int)((unsigned int)v23577 >> 25);
  v23576[24] = v23585;
  struct StateT * v23579 = slot_490(v23573);
  return v23579;
}

struct StateT * slot_286(struct StateT * v20268) {
  int v20269 = v20268->timer;
  int v20277 = v20269 + 1;
  v20268->timer = v20277;
  int * v20271 = v20268->regs;
  int v20272 = v20271[21];
  int v20273 = v20271[24];
  int v20281 = v20272 | v20273;
  v20271[21] = v20281;
  struct StateT * v20275 = slot_287(v20268);
  return v20275;
}

struct StateT * slot_520(struct StateT * v24056) {
  int v24057 = v24056->timer;
  int v24065 = v24057 + 1;
  v24056->timer = v24065;
  int * v24059 = v24056->regs;
  int v24060 = v24059[5];
  int v24061 = v24059[12];
  int v24070 = v24060 + v24061;
  v24059[21] = v24070;
  struct StateT * v24063 = slot_521(v24056);
  return v24063;
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

struct StateT * slot_254(struct StateT * v19766) {
  int v19767 = v19766->timer;
  int v19775 = v19767 + 1;
  v19766->timer = v19775;
  int * v19769 = v19766->regs;
  int v19770 = v19769[18];
  int v19771 = v19769[21];
  int v19779 = v19770 ^ v19771;
  v19769[18] = v19779;
  struct StateT * v19773 = slot_255(v19766);
  return v19773;
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

struct StateT * slot_421(struct StateT * v22429) {
  int v22430 = v22429->timer;
  int v22438 = v22430 + 1;
  v22429->timer = v22438;
  int * v22432 = v22429->regs;
  int v22433 = v22432[19];
  int v22434 = v22432[28];
  int v22443 = v22433 + v22434;
  v22432[22] = v22443;
  struct StateT * v22436 = slot_422(v22429);
  return v22436;
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

struct StateT * slot_363(struct StateT * v21471) {
  int v21472 = v21471->timer;
  int v21480 = v21472 + 1;
  v21471->timer = v21480;
  int * v21474 = v21471->regs;
  int v21475 = v21474[20];
  int v21476 = v21474[24];
  int v21484 = v21475 | v21476;
  v21474[20] = v21484;
  struct StateT * v21478 = slot_364(v21471);
  return v21478;
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

struct StateT * slot_367(struct StateT * v21532) {
  int v21533 = v21532->timer;
  int v21540 = v21533 + 1;
  v21532->timer = v21540;
  int * v21535 = v21532->regs;
  int v21536 = v21535[22];
  int v21544 = (int)((unsigned int)v21536 >> 19);
  v21535[24] = v21544;
  struct StateT * v21538 = slot_368(v21532);
  return v21538;
}

struct StateT * slot_437(struct StateT * v22689) {
  int * v22690 = v22689->saved_regs;
  int * v22691 = v22689->regs;
  int v22692 = v22691[17];
  v22690[17] = v22692;
  int v22694 = v22689->timer;
  int v22706 = v22694 + 1;
  v22689->timer = v22706;
  int * v22696 = v22689->regs;
  int v22697 = v22696[17];
  int v22698 = v22696[22];
  int v22709 = v22697 ^ v22698;
  v22696[17] = v22709;
  struct StateT * v22700 = slot_438(v22689);
  return v22700;
}

struct StateT * slot_341(struct StateT * v21130) {
  int v21131 = v21130->timer;
  int v21138 = v21131 + 1;
  v21130->timer = v21138;
  int * v21133 = v21130->regs;
  int v21134 = v21133[20];
  int v21142 = (int)((unsigned int)v21134 >> 23);
  v21133[24] = v21142;
  struct StateT * v21136 = slot_342(v21130);
  return v21136;
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

struct StateT * slot_416(struct StateT * v22326) {
  int * v22327 = v22326->saved_regs;
  int * v22328 = v22326->regs;
  int v22329 = v22328[18];
  v22327[18] = v22329;
  int v22331 = v22326->timer;
  int v22343 = v22331 + 1;
  v22326->timer = v22343;
  int * v22333 = v22326->regs;
  int v22334 = v22333[18];
  int v22335 = v22333[21];
  int v22346 = v22334 ^ v22335;
  v22333[18] = v22346;
  struct StateT * v22337 = slot_417(v22326);
  return v22337;
}

struct StateT * slot_280(struct StateT * v20177) {
  int v20178 = v20177->timer;
  int v20186 = v20178 + 1;
  v20177->timer = v20186;
  int * v20180 = v20177->regs;
  int v20181 = v20180[5];
  int v20182 = v20180[8];
  int v20191 = v20181 + v20182;
  v20180[23] = v20191;
  struct StateT * v20184 = slot_281(v20177);
  return v20184;
}

struct StateT * slot_272(struct StateT * v20046) {
  int v20047 = v20046->timer;
  int v20055 = v20047 + 1;
  v20046->timer = v20055;
  int * v20049 = v20046->regs;
  int v20050 = v20049[23];
  int v20051 = v20049[24];
  int v20059 = v20050 | v20051;
  v20049[23] = v20059;
  struct StateT * v20053 = slot_273(v20046);
  return v20053;
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

struct StateT * slot_297(struct StateT * v20438) {
  int v20439 = v20438->timer;
  int v20447 = v20439 + 1;
  v20438->timer = v20447;
  int * v20441 = v20438->regs;
  int v20442 = v20441[16];
  int v20443 = v20441[6];
  int v20452 = v20442 + v20443;
  v20441[20] = v20452;
  struct StateT * v20445 = slot_298(v20438);
  return v20445;
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

struct StateT * slot_314(struct StateT * v20702) {
  int v20703 = v20702->timer;
  int v20711 = v20703 + 1;
  v20702->timer = v20711;
  int * v20705 = v20702->regs;
  int v20706 = v20705[29];
  int v20707 = v20705[21];
  int v20715 = v20706 ^ v20707;
  v20705[29] = v20715;
  struct StateT * v20709 = slot_315(v20702);
  return v20709;
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

struct StateT * slot_365(struct StateT * v21502) {
  int v21503 = v21502->timer;
  int v21510 = v21503 + 1;
  v21502->timer = v21510;
  int * v21505 = v21502->regs;
  int v21506 = v21505[21];
  int v21513 = v21506 << 13;
  v21505[21] = v21513;
  struct StateT * v21508 = slot_366(v21502);
  return v21508;
}

struct StateT * slot_441(struct StateT * v22769) {
  int v22770 = v22769->timer;
  int v22778 = v22770 + 1;
  v22769->timer = v22778;
  int * v22772 = v22769->regs;
  int v22773 = v22772[17];
  int v22774 = v22772[19];
  int v22783 = v22773 + v22774;
  v22772[22] = v22783;
  struct StateT * v22776 = slot_442(v22769);
  return v22776;
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

struct StateT * slot_382(struct StateT * v21769) {
  int v21770 = v21769->timer;
  int v21777 = v21770 + 1;
  v21769->timer = v21777;
  int * v21772 = v21769->regs;
  int v21773 = v21772[20];
  int v21780 = v21773 << 18;
  v21772[20] = v21780;
  struct StateT * v21775 = slot_383(v21769);
  return v21775;
}

struct StateT * slot_523(struct StateT * v24107) {
  int v24108 = v24107->timer;
  int v24115 = v24108 + 1;
  v24107->timer = v24115;
  int * v24110 = v24107->regs;
  int v24111 = v24110[20];
  int v24119 = (int)((unsigned int)v24111 >> 19);
  v24110[24] = v24119;
  struct StateT * v24113 = slot_524(v24107);
  return v24113;
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

struct StateT * slot_452(struct StateT * v22938) {
  int v22939 = v22938->timer;
  int v22946 = v22939 + 1;
  v22938->timer = v22946;
  int * v22941 = v22938->regs;
  int v22942 = v22941[23];
  int v22950 = (int)((unsigned int)v22942 >> 19);
  v22941[24] = v22950;
  struct StateT * v22944 = slot_453(v22938);
  return v22944;
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

struct StateT * slot_546(struct StateT * v24464) {
  int v24465 = v24464->timer;
  int v24472 = v24465 + 1;
  v24464->timer = v24472;
  int * v24467 = v24464->regs;
  int v24468 = v24467[21];
  int v24476 = (int)((unsigned int)v24468 >> 14);
  v24467[24] = v24476;
  struct StateT * v24470 = slot_547(v24464);
  return v24470;
}

struct StateT * slot_556(struct StateT * v24615) {
  int v24616 = v24615->timer;
  int v24624 = v24616 + 1;
  v24615->timer = v24624;
  int * v24618 = v24615->regs;
  int v24619 = v24618[29];
  int v24620 = v24618[21];
  int v24628 = v24619 ^ v24620;
  v24618[29] = v24628;
  struct StateT * v24622 = slot_557(v24615);
  return v24622;
}

struct StateT * slot_337(struct StateT * v21062) {
  int v21063 = v21062->timer;
  int v21071 = v21063 + 1;
  v21062->timer = v21071;
  int * v21065 = v21062->regs;
  int v21066 = v21065[14];
  int v21067 = v21065[30];
  int v21076 = v21066 + v21067;
  v21065[20] = v21076;
  struct StateT * v21069 = slot_338(v21062);
  return v21069;
}

struct StateT * slot_32(struct StateT * v6104) {
  int v6105 = v6104->timer;
  int v6109 = v6105 + 1;
  v6104->timer = v6109;
  struct StateT * v6107 = slot_33(v6104);
  return v6107;
}

struct StateT * slot_233(struct StateT * v17362) {
  int v17363 = v17362->timer;
  int v17473 = v17363 + 1;
  v17362->timer = v17473;
  int * v17365 = v17362->regs;
  int v17366 = v17365[2];
  int * v17367 = v17362->cache_tags;
  int v17477 = (((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2;
  int v17368 = v17367[v17477];
  int v17478 = ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17369 = v17367[v17478];
  int v17479 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2);
  int v17370 = v17367[v17479];
  int v17480 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17371 = v17367[v17480];
  int v17372 = v17362->timer;
  int v17481 = v17372 + ((100 ^ (((~(((v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17368 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17368 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17362->timer = v17481;
  int * v17374 = v17362->cache_vals;
  bool v17482 = !(((~(((v17368 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17368 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v17467;
  if (v17482) {
    int * v17375 = v17362->cache_age;
    int v17484 = ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17369 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v17376 = v17375[v17484];
    int v17377 = v17375[v17477];
    int v17485 = v17377 + ((int)((unsigned int)(v17377 - v17376) >> 31));
    v17375[v17477] = v17485;
    int * v17379 = v17362->cache_age;
    int v17380 = v17379[v17478];
    int v17487 = v17380 + ((int)((unsigned int)(v17380 - v17376) >> 31));
    v17379[v17478] = v17487;
    int * v17382 = v17362->cache_age;
    v17382[v17484] = 0;
    v17467 = v17484;
  } else {
    int * v17385 = v17362->cache_age;
    int v17491 = (((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2;
    int v17386 = v17385[v17491];
    int * v17387 = v17362->cache_tags;
    int v17388 = v17387[v17491];
    int v17389 = v17385[v17478];
    int v17390 = v17387[v17478];
    bool v17493 = !(((~(((v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17370 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v17444;
    if (v17493) {
      int * v17391 = v17362->cache_age;
      int v17495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))) | (-(v17371 ^ ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v17392 = v17391[v17495];
      int v17393 = v17391[v17479];
      int v17496 = v17393 + ((int)((unsigned int)(v17393 - v17392) >> 31));
      v17391[v17479] = v17496;
      int * v17395 = v17362->cache_age;
      int v17396 = v17395[v17480];
      int v17498 = v17396 + ((int)((unsigned int)(v17396 - v17392) >> 31));
      v17395[v17480] = v17498;
      int * v17398 = v17362->cache_age;
      v17398[v17495] = 0;
      v17444 = v17495;
    } else {
      int * v17401 = v17362->cache_age;
      int v17502 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2);
      int v17402 = v17401[v17502];
      int * v17403 = v17362->cache_tags;
      int v17404 = v17403[v17502];
      int v17405 = v17401[v17480];
      int v17406 = v17403[v17480];
      int * v17407 = v17362->cache_dirty;
      int v17505 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v17402 + ((~(((v17404 ^ -1) | (-(v17404 ^ -1))) >> 31)) & 2)) - (v17405 + ((~(((v17406 ^ -1) | (-(v17406 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17408 = v17407[v17505];
      bool v17506 = !(v17408 == 0);
      if (v17506) {
        int * v17409 = v17362->cache_tags;
        int v17410 = v17409[v17505];
        int * v17411 = v17362->cache_vals;
        int v17509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v17402 + ((~(((v17404 ^ -1) | (-(v17404 ^ -1))) >> 31)) & 2)) - (v17405 + ((~(((v17406 ^ -1) | (-(v17406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17412 = v17411[v17509];
        int v17510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v17402 + ((~(((v17404 ^ -1) | (-(v17404 ^ -1))) >> 31)) & 2)) - (v17405 + ((~(((v17406 ^ -1) | (-(v17406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17413 = v17411[v17510];
        int * v17414 = v17362->mem;
        int v17512 = v17410 * 2;
        v17414[v17512] = v17412;
        int * v17416 = v17362->mem;
        int v17515 = (v17410 * 2) + 1;
        v17416[v17515] = v17413;
        ;
      } else {
        ;
      }
      int * v17421 = v17362->mem;
      int v17520 = ((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) * 2;
      int v17422 = v17421[v17520];
      int v17521 = (((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) * 2) + 1;
      int v17423 = v17421[v17521];
      int * v17424 = v17362->cache_vals;
      int v17523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v17402 + ((~(((v17404 ^ -1) | (-(v17404 ^ -1))) >> 31)) & 2)) - (v17405 + ((~(((v17406 ^ -1) | (-(v17406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17424[v17523] = v17422;
      int * v17426 = v17362->cache_vals;
      int v17526 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v17402 + ((~(((v17404 ^ -1) | (-(v17404 ^ -1))) >> 31)) & 2)) - (v17405 + ((~(((v17406 ^ -1) | (-(v17406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17426[v17526] = v17423;
      int * v17428 = v17362->cache_tags;
      int v17529 = (int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1);
      v17428[v17505] = v17529;
      int * v17430 = v17362->cache_dirty;
      v17430[v17505] = 0;
      int * v17432 = v17362->cache_age;
      v17432[v17505] = 1;
      int * v17434 = v17362->cache_age;
      int v17435 = v17434[v17505];
      int v17436 = v17434[v17479];
      int v17535 = v17436 + ((int)((unsigned int)(v17436 - v17435) >> 31));
      v17434[v17479] = v17535;
      int * v17438 = v17362->cache_age;
      int v17439 = v17438[v17480];
      int v17537 = v17439 + ((int)((unsigned int)(v17439 - v17435) >> 31));
      v17438[v17480] = v17537;
      int * v17441 = v17362->cache_age;
      v17441[v17505] = 0;
      v17444 = v17505;
    }
    int * v17445 = v17362->cache_vals;
    int v17540 = v17444 * 2;
    int v17446 = v17445[v17540];
    int v17541 = (v17444 * 2) + 1;
    int v17447 = v17445[v17541];
    int v17542 = (((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v17386 + ((~(((v17388 ^ -1) | (-(v17388 ^ -1))) >> 31)) & 2)) - (v17389 + ((~(((v17390 ^ -1) | (-(v17390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17445[v17542] = v17446;
    int * v17449 = v17362->cache_vals;
    int v17545 = ((((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v17386 + ((~(((v17388 ^ -1) | (-(v17388 ^ -1))) >> 31)) & 2)) - (v17389 + ((~(((v17390 ^ -1) | (-(v17390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17449[v17545] = v17447;
    int * v17451 = v17362->cache_tags;
    int v17548 = ((((int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v17386 + ((~(((v17388 ^ -1) | (-(v17388 ^ -1))) >> 31)) & 2)) - (v17389 + ((~(((v17390 ^ -1) | (-(v17390 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17549 = (int)((unsigned int)((int)((unsigned int)(v17366 + 28) >> 2)) >> 1);
    v17451[v17548] = v17549;
    int * v17453 = v17362->cache_dirty;
    v17453[v17548] = 0;
    int * v17455 = v17362->cache_age;
    v17455[v17548] = 1;
    int * v17457 = v17362->cache_age;
    int v17458 = v17457[v17548];
    int v17459 = v17457[v17477];
    int v17555 = v17459 + ((int)((unsigned int)(v17459 - v17458) >> 31));
    v17457[v17477] = v17555;
    int * v17461 = v17362->cache_age;
    int v17462 = v17461[v17478];
    int v17557 = v17462 + ((int)((unsigned int)(v17462 - v17458) >> 31));
    v17461[v17478] = v17557;
    int * v17464 = v17362->cache_age;
    v17464[v17548] = 0;
    v17467 = v17548;
  }
  int v17560 = (v17467 * 2) + (((int)((unsigned int)(v17366 + 28) >> 2)) & 1);
  int v17468 = v17374[v17560];
  int * v17469 = v17362->regs;
  v17469[20] = v17468;
  struct StateT * v17471 = slot_236(v17362);
  return v17471;
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

struct StateT * slot_394(struct StateT * v21950) {
  int v21951 = v21950->timer;
  int v21959 = v21951 + 1;
  v21950->timer = v21959;
  int * v21953 = v21950->regs;
  int v21954 = v21953[29];
  int v21955 = v21953[21];
  int v21963 = v21954 ^ v21955;
  v21953[29] = v21963;
  struct StateT * v21957 = slot_395(v21950);
  return v21957;
}

struct StateT * slot_398(struct StateT * v22012) {
  int v22013 = v22012->timer;
  int v22017 = v22013 + 1;
  v22012->timer = v22017;
  struct StateT * v22015 = slot_399(v22012);
  return v22015;
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

struct StateT * slot_371(struct StateT * v21592) {
  int v21593 = v21592->timer;
  int v21600 = v21593 + 1;
  v21592->timer = v21600;
  int * v21595 = v21592->regs;
  int v21596 = v21595[23];
  int v21603 = v21596 << 13;
  v21595[23] = v21603;
  struct StateT * v21598 = slot_372(v21592);
  return v21598;
}

struct StateT * slot_330(struct StateT * v20953) {
  int v20954 = v20953->timer;
  int v20961 = v20954 + 1;
  v20953->timer = v20961;
  int * v20956 = v20953->regs;
  int v20957 = v20956[23];
  int v20965 = (int)((unsigned int)v20957 >> 25);
  v20956[24] = v20965;
  struct StateT * v20959 = slot_331(v20953);
  return v20959;
}

struct StateT * slot_450(struct StateT * v22908) {
  int v22909 = v22908->timer;
  int v22916 = v22909 + 1;
  v22908->timer = v22916;
  int * v22911 = v22908->regs;
  int v22912 = v22911[22];
  int v22919 = v22912 << 13;
  v22911[22] = v22919;
  struct StateT * v22914 = slot_451(v22908);
  return v22914;
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

struct StateT * slot_484(struct StateT * v23498) {
  int v23499 = v23498->timer;
  int v23506 = v23499 + 1;
  v23498->timer = v23506;
  int * v23501 = v23498->regs;
  int v23502 = v23501[20];
  int v23509 = v23502 << 7;
  v23501[20] = v23509;
  struct StateT * v23504 = slot_485(v23498);
  return v23504;
}

struct StateT * slot_258(struct StateT * v19831) {
  int v19832 = v19831->timer;
  int v19840 = v19832 + 1;
  v19831->timer = v19840;
  int * v19834 = v19831->regs;
  int v19835 = v19834[18];
  int v19836 = v19834[29];
  int v19845 = v19835 + v19836;
  v19834[21] = v19845;
  struct StateT * v19838 = slot_259(v19831);
  return v19838;
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

struct StateT * slot_418(struct StateT * v22372) {
  int * v22373 = v22372->saved_regs;
  int * v22374 = v22372->regs;
  int v22375 = v22374[8];
  v22373[8] = v22375;
  int v22377 = v22372->timer;
  int v22389 = v22377 + 1;
  v22372->timer = v22389;
  int * v22379 = v22372->regs;
  int v22380 = v22379[8];
  int v22381 = v22379[23];
  int v22392 = v22380 ^ v22381;
  v22379[8] = v22392;
  struct StateT * v22383 = slot_419(v22372);
  return v22383;
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

struct StateT * slot_490(struct StateT * v23588) {
  int v23589 = v23588->timer;
  int v23596 = v23589 + 1;
  v23588->timer = v23596;
  int * v23591 = v23588->regs;
  int v23592 = v23591[22];
  int v23599 = v23592 << 7;
  v23591[22] = v23599;
  struct StateT * v23594 = slot_491(v23588);
  return v23594;
}

struct StateT * slot_264(struct StateT * v19927) {
  int v19928 = v19927->timer;
  int v19935 = v19928 + 1;
  v19927->timer = v19935;
  int * v19930 = v19927->regs;
  int v19931 = v19930[21];
  int v19939 = (int)((unsigned int)v19931 >> 23);
  v19930[24] = v19939;
  struct StateT * v19933 = slot_265(v19927);
  return v19933;
}

struct StateT * slot_339(struct StateT * v21096) {
  int v21097 = v21096->timer;
  int v21105 = v21097 + 1;
  v21096->timer = v21105;
  int * v21099 = v21096->regs;
  int v21100 = v21099[15];
  int v21101 = v21099[28];
  int v21110 = v21100 + v21101;
  v21099[22] = v21110;
  struct StateT * v21103 = slot_340(v21096);
  return v21103;
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

struct StateT * slot_299(struct StateT * v20472) {
  int v20473 = v20472->timer;
  int v20481 = v20473 + 1;
  v20472->timer = v20481;
  int * v20475 = v20472->regs;
  int v20476 = v20475[12];
  int v20477 = v20475[17];
  int v20486 = v20476 + v20477;
  v20475[22] = v20486;
  struct StateT * v20479 = slot_300(v20472);
  return v20479;
}

struct StateT * slot_539(struct StateT * v24351) {
  int v24352 = v24351->timer;
  int v24360 = v24352 + 1;
  v24351->timer = v24360;
  int * v24354 = v24351->regs;
  int v24355 = v24354[8];
  int v24356 = v24354[17];
  int v24365 = v24355 + v24356;
  v24354[20] = v24365;
  struct StateT * v24358 = slot_540(v24351);
  return v24358;
}

struct StateT * slot_319(struct StateT * v20784) {
  int v20785 = v20784->timer;
  int v20793 = v20785 + 1;
  v20784->timer = v20793;
  int * v20787 = v20784->regs;
  int v20788 = v20787[28];
  int v20789 = v20787[18];
  int v20798 = v20788 + v20789;
  v20787[22] = v20798;
  struct StateT * v20791 = slot_320(v20784);
  return v20791;
}

struct StateT * slot_344(struct StateT * v21175) {
  int v21176 = v21175->timer;
  int v21183 = v21176 + 1;
  v21175->timer = v21183;
  int * v21178 = v21175->regs;
  int v21179 = v21178[21];
  int v21187 = (int)((unsigned int)v21179 >> 23);
  v21178[24] = v21187;
  struct StateT * v21181 = slot_345(v21175);
  return v21181;
}

struct StateT * slot_513(struct StateT * v23945) {
  int v23946 = v23945->timer;
  int v23953 = v23946 + 1;
  v23945->timer = v23953;
  int * v23948 = v23945->regs;
  int v23949 = v23948[23];
  int v23956 = v23949 << 9;
  v23948[23] = v23956;
  struct StateT * v23951 = slot_514(v23945);
  return v23951;
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

struct StateT * slot_497(struct StateT * v23695) {
  int v23696 = v23695->timer;
  int v23704 = v23696 + 1;
  v23695->timer = v23704;
  int * v23698 = v23695->regs;
  int v23699 = v23698[15];
  int v23700 = v23698[22];
  int v23708 = v23699 ^ v23700;
  v23698[15] = v23708;
  struct StateT * v23702 = slot_498(v23695);
  return v23702;
}

struct StateT * slot_455(struct StateT * v22983) {
  int * v22984 = v22983->saved_regs;
  int * v22985 = v22983->regs;
  int v22986 = v22985[16];
  v22984[16] = v22986;
  int v22988 = v22983->timer;
  int v23000 = v22988 + 1;
  v22983->timer = v23000;
  int * v22990 = v22983->regs;
  int v22991 = v22990[16];
  int v22992 = v22990[20];
  int v23003 = v22991 ^ v22992;
  v22990[16] = v23003;
  struct StateT * v22994 = slot_456(v22983);
  return v22994;
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

struct StateT * slot_432(struct StateT * v22598) {
  int v22599 = v22598->timer;
  int v22606 = v22599 + 1;
  v22598->timer = v22606;
  int * v22601 = v22598->regs;
  int v22602 = v22601[23];
  int v22610 = (int)((unsigned int)v22602 >> 23);
  v22601[24] = v22610;
  struct StateT * v22604 = slot_433(v22598);
  return v22604;
}

struct StateT * slot_306(struct StateT * v20580) {
  int v20581 = v20580->timer;
  int v20589 = v20581 + 1;
  v20580->timer = v20589;
  int * v20583 = v20580->regs;
  int v20584 = v20583[21];
  int v20585 = v20583[24];
  int v20593 = v20584 | v20585;
  v20583[21] = v20593;
  struct StateT * v20587 = slot_307(v20580);
  return v20587;
}

struct StateT * slot_312(struct StateT * v20670) {
  int v20671 = v20670->timer;
  int v20679 = v20671 + 1;
  v20670->timer = v20679;
  int * v20673 = v20670->regs;
  int v20674 = v20673[23];
  int v20675 = v20673[24];
  int v20683 = v20674 | v20675;
  v20673[23] = v20683;
  struct StateT * v20677 = slot_313(v20670);
  return v20677;
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

struct StateT * slot_560(struct StateT * v24684) {
  int * v24685 = v24684->regs;
  int v24686 = v24685[11];
  int * v24687 = v24684->saved_regs;
  int v24688 = v24687[13];
  bool v24789 = (v24686 ^ -2147483648) >= (v24688 ^ -2147483648);
  struct StateT * v24783;
  if (v24789) {
    struct StateT * v24689 = slot_398(v24684);
    v24783 = v24689;
  } else {
    int v24691 = v24684->timer;
    int v24792 = v24691 + 15;
    v24684->timer = v24792;
    int * v24693 = v24684->saved_regs;
    int v24694 = v24693[20];
    int * v24695 = v24684->regs;
    v24695[20] = v24694;
    int * v24697 = v24684->saved_regs;
    int v24698 = v24697[21];
    int * v24699 = v24684->regs;
    v24699[21] = v24698;
    int * v24701 = v24684->saved_regs;
    int v24702 = v24701[22];
    int * v24703 = v24684->regs;
    v24703[22] = v24702;
    int * v24705 = v24684->saved_regs;
    int v24706 = v24705[23];
    int * v24707 = v24684->regs;
    v24707[23] = v24706;
    int * v24709 = v24684->saved_regs;
    int v24710 = v24709[24];
    int * v24711 = v24684->regs;
    v24711[24] = v24710;
    int * v24713 = v24684->saved_regs;
    int v24714 = v24713[9];
    int * v24715 = v24684->regs;
    v24715[9] = v24714;
    int * v24717 = v24684->saved_regs;
    int v24718 = v24717[18];
    int * v24719 = v24684->regs;
    v24719[18] = v24718;
    int * v24721 = v24684->saved_regs;
    int v24722 = v24721[19];
    int * v24723 = v24684->regs;
    v24723[19] = v24722;
    int * v24725 = v24684->saved_regs;
    int v24726 = v24725[8];
    int * v24727 = v24684->regs;
    v24727[8] = v24726;
    int * v24729 = v24684->saved_regs;
    int v24730 = v24729[6];
    int * v24731 = v24684->regs;
    v24731[6] = v24730;
    int * v24733 = v24684->saved_regs;
    int v24734 = v24733[7];
    int * v24735 = v24684->regs;
    v24735[7] = v24734;
    int * v24737 = v24684->saved_regs;
    int v24738 = v24737[17];
    int * v24739 = v24684->regs;
    v24739[17] = v24738;
    int * v24741 = v24684->saved_regs;
    int v24742 = v24741[5];
    int * v24743 = v24684->regs;
    v24743[5] = v24742;
    int * v24745 = v24684->saved_regs;
    int v24746 = v24745[16];
    int * v24747 = v24684->regs;
    v24747[16] = v24746;
    int * v24749 = v24684->saved_regs;
    int v24750 = v24749[14];
    int * v24751 = v24684->regs;
    v24751[14] = v24750;
    int * v24753 = v24684->saved_regs;
    int v24754 = v24753[12];
    int * v24755 = v24684->regs;
    v24755[12] = v24754;
    int * v24757 = v24684->saved_regs;
    int v24758 = v24757[15];
    int * v24759 = v24684->regs;
    v24759[15] = v24758;
    int * v24761 = v24684->saved_regs;
    int v24762 = v24761[30];
    int * v24763 = v24684->regs;
    v24763[30] = v24762;
    int * v24765 = v24684->saved_regs;
    int v24766 = v24765[29];
    int * v24767 = v24684->regs;
    v24767[29] = v24766;
    int * v24769 = v24684->saved_regs;
    int v24770 = v24769[28];
    int * v24771 = v24684->regs;
    v24771[28] = v24770;
    int * v24773 = v24684->saved_regs;
    int v24774 = v24773[31];
    int * v24775 = v24684->regs;
    v24775[31] = v24774;
    int * v24777 = v24684->saved_regs;
    int v24778 = v24777[13];
    int * v24779 = v24684->regs;
    v24779[13] = v24778;
    struct StateT * v24781 = slot_201(v24684);
    v24783 = v24781;
  }
  return v24783;
}

struct StateT * slot_240(struct StateT * v19025) {
  int v19026 = v19025->timer;
  int v19033 = v19026 + 1;
  v19025->timer = v19033;
  int * v19028 = v19025->regs;
  int v19029 = v19028[2];
  int v19036 = v19029 + 48;
  v19028[2] = v19036;
  struct StateT * v19031 = slot_243(v19025);
  return v19031;
}

struct StateT * slot_247(struct StateT * v19686) {
  int v19687 = v19686->timer;
  int v19694 = v19687 + 1;
  v19686->timer = v19694;
  int * v19689 = v19686->regs;
  int v19690 = v19689[23];
  int v19698 = (int)((unsigned int)v19690 >> 25);
  v19689[24] = v19698;
  struct StateT * v19692 = slot_249(v19686);
  return v19692;
}

struct StateT * slot_548(struct StateT * v24493) {
  int v24494 = v24493->timer;
  int v24502 = v24494 + 1;
  v24493->timer = v24502;
  int * v24496 = v24493->regs;
  int v24497 = v24496[21];
  int v24498 = v24496[24];
  int v24506 = v24497 | v24498;
  v24496[21] = v24506;
  struct StateT * v24500 = slot_549(v24493);
  return v24500;
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

struct StateT * slot_348(struct StateT * v21235) {
  int v21236 = v21235->timer;
  int v21243 = v21236 + 1;
  v21235->timer = v21243;
  int * v21238 = v21235->regs;
  int v21239 = v21238[22];
  int v21246 = v21239 << 9;
  v21238[22] = v21246;
  struct StateT * v21241 = slot_349(v21235);
  return v21241;
}

struct StateT * slot_456(struct StateT * v23006) {
  int * v23007 = v23006->saved_regs;
  int * v23008 = v23006->regs;
  int v23009 = v23008[14];
  v23007[14] = v23009;
  int v23011 = v23006->timer;
  int v23023 = v23011 + 1;
  v23006->timer = v23023;
  int * v23013 = v23006->regs;
  int v23014 = v23013[14];
  int v23015 = v23013[21];
  int v23026 = v23014 ^ v23015;
  v23013[14] = v23026;
  struct StateT * v23017 = slot_457(v23006);
  return v23017;
}

struct StateT * slot_225(struct StateT * v15531) {
  int v15532 = v15531->timer;
  int v15539 = v15532 + 1;
  v15531->timer = v15539;
  int * v15534 = v15531->regs;
  int v15535 = v15534[21];
  int v15543 = (int)((unsigned int)v15535 >> 25);
  v15534[24] = v15543;
  struct StateT * v15537 = slot_228(v15531);
  return v15537;
}

struct StateT * slot_467(struct StateT * v23203) {
  int v23204 = v23203->timer;
  int v23211 = v23204 + 1;
  v23203->timer = v23211;
  int * v23206 = v23203->regs;
  int v23207 = v23206[21];
  int v23214 = v23207 << 18;
  v23206[21] = v23214;
  struct StateT * v23209 = slot_468(v23203);
  return v23209;
}

struct StateT * slot_285(struct StateT * v20254) {
  int v20255 = v20254->timer;
  int v20262 = v20255 + 1;
  v20254->timer = v20262;
  int * v20257 = v20254->regs;
  int v20258 = v20257[21];
  int v20265 = v20258 << 13;
  v20257[21] = v20265;
  struct StateT * v20260 = slot_286(v20254);
  return v20260;
}

struct StateT * slot_213(struct StateT * v12550) {
  int v12551 = v12550->timer;
  int v12721 = v12551 + 1;
  v12550->timer = v12721;
  int * v12553 = v12550->regs;
  int v12554 = v12553[10];
  int v12555 = v12553[12];
  int * v12556 = v12550->cache_tags;
  int v12726 = (((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2;
  int v12557 = v12556[v12726];
  int v12727 = ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12558 = v12556[v12727];
  int v12728 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2);
  int v12559 = v12556[v12728];
  int v12729 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12560 = v12556[v12729];
  int v12561 = v12550->timer;
  int v12730 = v12561 + ((100 ^ (((~(((v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12557 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12557 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12550->timer = v12730;
  bool v12731 = !(((~(((v12557 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12557 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v12655;
  if (v12731) {
    int * v12563 = v12550->cache_age;
    int v12733 = ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12558 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v12564 = v12563[v12733];
    int v12565 = v12563[v12726];
    int v12734 = v12565 + ((int)((unsigned int)(v12565 - v12564) >> 31));
    v12563[v12726] = v12734;
    int * v12567 = v12550->cache_age;
    int v12568 = v12567[v12727];
    int v12736 = v12568 + ((int)((unsigned int)(v12568 - v12564) >> 31));
    v12567[v12727] = v12736;
    int * v12570 = v12550->cache_age;
    v12570[v12733] = 0;
    v12655 = v12733;
  } else {
    int * v12573 = v12550->cache_age;
    int v12740 = (((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2;
    int v12574 = v12573[v12740];
    int * v12575 = v12550->cache_tags;
    int v12576 = v12575[v12740];
    int v12577 = v12573[v12727];
    int v12578 = v12575[v12727];
    bool v12742 = !(((~(((v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12559 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v12632;
    if (v12742) {
      int * v12579 = v12550->cache_age;
      int v12744 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12560 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v12580 = v12579[v12744];
      int v12581 = v12579[v12728];
      int v12745 = v12581 + ((int)((unsigned int)(v12581 - v12580) >> 31));
      v12579[v12728] = v12745;
      int * v12583 = v12550->cache_age;
      int v12584 = v12583[v12729];
      int v12747 = v12584 + ((int)((unsigned int)(v12584 - v12580) >> 31));
      v12583[v12729] = v12747;
      int * v12586 = v12550->cache_age;
      v12586[v12744] = 0;
      v12632 = v12744;
    } else {
      int * v12589 = v12550->cache_age;
      int v12751 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2);
      int v12590 = v12589[v12751];
      int * v12591 = v12550->cache_tags;
      int v12592 = v12591[v12751];
      int v12593 = v12589[v12729];
      int v12594 = v12591[v12729];
      int * v12595 = v12550->cache_dirty;
      int v12754 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12590 + ((~(((v12592 ^ -1) | (-(v12592 ^ -1))) >> 31)) & 2)) - (v12593 + ((~(((v12594 ^ -1) | (-(v12594 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12596 = v12595[v12754];
      bool v12755 = !(v12596 == 0);
      if (v12755) {
        int * v12597 = v12550->cache_tags;
        int v12598 = v12597[v12754];
        int * v12599 = v12550->cache_vals;
        int v12758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12590 + ((~(((v12592 ^ -1) | (-(v12592 ^ -1))) >> 31)) & 2)) - (v12593 + ((~(((v12594 ^ -1) | (-(v12594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12600 = v12599[v12758];
        int v12759 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12590 + ((~(((v12592 ^ -1) | (-(v12592 ^ -1))) >> 31)) & 2)) - (v12593 + ((~(((v12594 ^ -1) | (-(v12594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12601 = v12599[v12759];
        int * v12602 = v12550->mem;
        int v12761 = v12598 * 2;
        v12602[v12761] = v12600;
        int * v12604 = v12550->mem;
        int v12764 = (v12598 * 2) + 1;
        v12604[v12764] = v12601;
        ;
      } else {
        ;
      }
      int * v12609 = v12550->mem;
      int v12769 = ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) * 2;
      int v12610 = v12609[v12769];
      int v12770 = (((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) * 2) + 1;
      int v12611 = v12609[v12770];
      int * v12612 = v12550->cache_vals;
      int v12772 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12590 + ((~(((v12592 ^ -1) | (-(v12592 ^ -1))) >> 31)) & 2)) - (v12593 + ((~(((v12594 ^ -1) | (-(v12594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12612[v12772] = v12610;
      int * v12614 = v12550->cache_vals;
      int v12775 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12590 + ((~(((v12592 ^ -1) | (-(v12592 ^ -1))) >> 31)) & 2)) - (v12593 + ((~(((v12594 ^ -1) | (-(v12594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12614[v12775] = v12611;
      int * v12616 = v12550->cache_tags;
      int v12778 = (int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1);
      v12616[v12754] = v12778;
      int * v12618 = v12550->cache_dirty;
      v12618[v12754] = 0;
      int * v12620 = v12550->cache_age;
      v12620[v12754] = 1;
      int * v12622 = v12550->cache_age;
      int v12623 = v12622[v12754];
      int v12624 = v12622[v12728];
      int v12784 = v12624 + ((int)((unsigned int)(v12624 - v12623) >> 31));
      v12622[v12728] = v12784;
      int * v12626 = v12550->cache_age;
      int v12627 = v12626[v12729];
      int v12786 = v12627 + ((int)((unsigned int)(v12627 - v12623) >> 31));
      v12626[v12729] = v12786;
      int * v12629 = v12550->cache_age;
      v12629[v12754] = 0;
      v12632 = v12754;
    }
    int * v12633 = v12550->cache_vals;
    int v12789 = v12632 * 2;
    int v12634 = v12633[v12789];
    int v12790 = (v12632 * 2) + 1;
    int v12635 = v12633[v12790];
    int v12791 = (((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12574 + ((~(((v12576 ^ -1) | (-(v12576 ^ -1))) >> 31)) & 2)) - (v12577 + ((~(((v12578 ^ -1) | (-(v12578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12633[v12791] = v12634;
    int * v12637 = v12550->cache_vals;
    int v12794 = ((((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12574 + ((~(((v12576 ^ -1) | (-(v12576 ^ -1))) >> 31)) & 2)) - (v12577 + ((~(((v12578 ^ -1) | (-(v12578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12637[v12794] = v12635;
    int * v12639 = v12550->cache_tags;
    int v12797 = ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v12574 + ((~(((v12576 ^ -1) | (-(v12576 ^ -1))) >> 31)) & 2)) - (v12577 + ((~(((v12578 ^ -1) | (-(v12578 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12798 = (int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1);
    v12639[v12797] = v12798;
    int * v12641 = v12550->cache_dirty;
    v12641[v12797] = 0;
    int * v12643 = v12550->cache_age;
    v12643[v12797] = 1;
    int * v12645 = v12550->cache_age;
    int v12646 = v12645[v12797];
    int v12647 = v12645[v12726];
    int v12804 = v12647 + ((int)((unsigned int)(v12647 - v12646) >> 31));
    v12645[v12726] = v12804;
    int * v12649 = v12550->cache_age;
    int v12650 = v12649[v12727];
    int v12806 = v12650 + ((int)((unsigned int)(v12650 - v12646) >> 31));
    v12649[v12727] = v12806;
    int * v12652 = v12550->cache_age;
    v12652[v12797] = 0;
    v12655 = v12797;
  }
  int * v12656 = v12550->cache_vals;
  int v12809 = (v12655 * 2) + (((int)((unsigned int)(v12554 + 16) >> 2)) & 1);
  v12656[v12809] = v12555;
  int * v12658 = v12550->cache_tags;
  int v12659 = v12658[v12728];
  int v12660 = v12658[v12729];
  bool v12812 = !(((~(((v12659 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12659 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v12660 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12660 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v12714;
  if (v12812) {
    int * v12661 = v12550->cache_age;
    int v12814 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12660 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))) | (-(v12660 ^ ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v12662 = v12661[v12814];
    int v12663 = v12661[v12728];
    int v12815 = v12663 + ((int)((unsigned int)(v12663 - v12662) >> 31));
    v12661[v12728] = v12815;
    int * v12665 = v12550->cache_age;
    int v12666 = v12665[v12729];
    int v12817 = v12666 + ((int)((unsigned int)(v12666 - v12662) >> 31));
    v12665[v12729] = v12817;
    int * v12668 = v12550->cache_age;
    v12668[v12814] = 0;
    v12714 = v12814;
  } else {
    int * v12671 = v12550->cache_age;
    int v12821 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2);
    int v12672 = v12671[v12821];
    int * v12673 = v12550->cache_tags;
    int v12674 = v12673[v12821];
    int v12675 = v12671[v12729];
    int v12676 = v12673[v12729];
    int * v12677 = v12550->cache_dirty;
    int v12824 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12672 + ((~(((v12674 ^ -1) | (-(v12674 ^ -1))) >> 31)) & 2)) - (v12675 + ((~(((v12676 ^ -1) | (-(v12676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12678 = v12677[v12824];
    bool v12825 = !(v12678 == 0);
    if (v12825) {
      int * v12679 = v12550->cache_tags;
      int v12680 = v12679[v12824];
      int * v12681 = v12550->cache_vals;
      int v12828 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12672 + ((~(((v12674 ^ -1) | (-(v12674 ^ -1))) >> 31)) & 2)) - (v12675 + ((~(((v12676 ^ -1) | (-(v12676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12682 = v12681[v12828];
      int v12829 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12672 + ((~(((v12674 ^ -1) | (-(v12674 ^ -1))) >> 31)) & 2)) - (v12675 + ((~(((v12676 ^ -1) | (-(v12676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12683 = v12681[v12829];
      int * v12684 = v12550->mem;
      int v12831 = v12680 * 2;
      v12684[v12831] = v12682;
      int * v12686 = v12550->mem;
      int v12834 = (v12680 * 2) + 1;
      v12686[v12834] = v12683;
      ;
    } else {
      ;
    }
    int * v12691 = v12550->mem;
    int v12839 = ((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) * 2;
    int v12692 = v12691[v12839];
    int v12840 = (((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) * 2) + 1;
    int v12693 = v12691[v12840];
    int * v12694 = v12550->cache_vals;
    int v12842 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12672 + ((~(((v12674 ^ -1) | (-(v12674 ^ -1))) >> 31)) & 2)) - (v12675 + ((~(((v12676 ^ -1) | (-(v12676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12694[v12842] = v12692;
    int * v12696 = v12550->cache_vals;
    int v12845 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12672 + ((~(((v12674 ^ -1) | (-(v12674 ^ -1))) >> 31)) & 2)) - (v12675 + ((~(((v12676 ^ -1) | (-(v12676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12696[v12845] = v12693;
    int * v12698 = v12550->cache_tags;
    int v12848 = (int)((unsigned int)((int)((unsigned int)(v12554 + 16) >> 2)) >> 1);
    v12698[v12824] = v12848;
    int * v12700 = v12550->cache_dirty;
    v12700[v12824] = 0;
    int * v12702 = v12550->cache_age;
    v12702[v12824] = 1;
    int * v12704 = v12550->cache_age;
    int v12705 = v12704[v12824];
    int v12706 = v12704[v12728];
    int v12854 = v12706 + ((int)((unsigned int)(v12706 - v12705) >> 31));
    v12704[v12728] = v12854;
    int * v12708 = v12550->cache_age;
    int v12709 = v12708[v12729];
    int v12856 = v12709 + ((int)((unsigned int)(v12709 - v12705) >> 31));
    v12708[v12729] = v12856;
    int * v12711 = v12550->cache_age;
    v12711[v12824] = 0;
    v12714 = v12824;
  }
  int * v12715 = v12550->cache_vals;
  int v12859 = (v12714 * 2) + (((int)((unsigned int)(v12554 + 16) >> 2)) & 1);
  v12715[v12859] = v12555;
  int * v12717 = v12550->cache_dirty;
  v12717[v12714] = 1;
  struct StateT * v12719 = slot_216(v12550);
  return v12719;
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

struct StateT * slot_263(struct StateT * v19911) {
  int v19912 = v19911->timer;
  int v19920 = v19912 + 1;
  v19911->timer = v19920;
  int * v19914 = v19911->regs;
  int v19915 = v19914[20];
  int v19916 = v19914[24];
  int v19924 = v19915 | v19916;
  v19914[20] = v19924;
  struct StateT * v19918 = slot_264(v19911);
  return v19918;
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

struct StateT * slot_293(struct StateT * v20374) {
  int v20375 = v20374->timer;
  int v20383 = v20375 + 1;
  v20374->timer = v20383;
  int * v20377 = v20374->regs;
  int v20378 = v20377[16];
  int v20379 = v20377[20];
  int v20387 = v20378 ^ v20379;
  v20377[16] = v20387;
  struct StateT * v20381 = slot_294(v20374);
  return v20381;
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

struct StateT * slot_288(struct StateT * v20299) {
  int v20300 = v20299->timer;
  int v20307 = v20300 + 1;
  v20299->timer = v20307;
  int * v20302 = v20299->regs;
  int v20303 = v20302[22];
  int v20310 = v20303 << 13;
  v20302[22] = v20310;
  struct StateT * v20305 = slot_289(v20299);
  return v20305;
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

struct StateT * slot_384(struct StateT * v21799) {
  int v21800 = v21799->timer;
  int v21807 = v21800 + 1;
  v21799->timer = v21807;
  int * v21802 = v21799->regs;
  int v21803 = v21802[21];
  int v21811 = (int)((unsigned int)v21803 >> 14);
  v21802[24] = v21811;
  struct StateT * v21805 = slot_385(v21799);
  return v21805;
}

struct StateT * slot_486(struct StateT * v23528) {
  int v23529 = v23528->timer;
  int v23536 = v23529 + 1;
  v23528->timer = v23536;
  int * v23531 = v23528->regs;
  int v23532 = v23531[21];
  int v23540 = (int)((unsigned int)v23532 >> 25);
  v23531[24] = v23540;
  struct StateT * v23534 = slot_487(v23528);
  return v23534;
}

struct StateT * slot_347(struct StateT * v21220) {
  int v21221 = v21220->timer;
  int v21228 = v21221 + 1;
  v21220->timer = v21228;
  int * v21223 = v21220->regs;
  int v21224 = v21223[22];
  int v21232 = (int)((unsigned int)v21224 >> 23);
  v21223[24] = v21232;
  struct StateT * v21226 = slot_348(v21220);
  return v21226;
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

struct StateT * slot_473(struct StateT * v23293) {
  int v23294 = v23293->timer;
  int v23301 = v23294 + 1;
  v23293->timer = v23301;
  int * v23296 = v23293->regs;
  int v23297 = v23296[23];
  int v23304 = v23297 << 18;
  v23296[23] = v23304;
  struct StateT * v23299 = slot_474(v23293);
  return v23299;
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

struct StateT * slot_216(struct StateT * v14069) {
  int v14070 = v14069->timer;
  int v14240 = v14070 + 1;
  v14069->timer = v14240;
  int * v14072 = v14069->regs;
  int v14073 = v14072[10];
  int v14074 = v14072[5];
  int * v14075 = v14069->cache_tags;
  int v14245 = (((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2;
  int v14076 = v14075[v14245];
  int v14246 = ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14077 = v14075[v14246];
  int v14247 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2);
  int v14078 = v14075[v14247];
  int v14248 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14079 = v14075[v14248];
  int v14080 = v14069->timer;
  int v14249 = v14080 + ((100 ^ (((~(((v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14076 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14076 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14069->timer = v14249;
  bool v14250 = !(((~(((v14076 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14076 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v14174;
  if (v14250) {
    int * v14082 = v14069->cache_age;
    int v14252 = ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14077 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v14083 = v14082[v14252];
    int v14084 = v14082[v14245];
    int v14253 = v14084 + ((int)((unsigned int)(v14084 - v14083) >> 31));
    v14082[v14245] = v14253;
    int * v14086 = v14069->cache_age;
    int v14087 = v14086[v14246];
    int v14255 = v14087 + ((int)((unsigned int)(v14087 - v14083) >> 31));
    v14086[v14246] = v14255;
    int * v14089 = v14069->cache_age;
    v14089[v14252] = 0;
    v14174 = v14252;
  } else {
    int * v14092 = v14069->cache_age;
    int v14259 = (((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2;
    int v14093 = v14092[v14259];
    int * v14094 = v14069->cache_tags;
    int v14095 = v14094[v14259];
    int v14096 = v14092[v14246];
    int v14097 = v14094[v14246];
    bool v14261 = !(((~(((v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14078 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v14151;
    if (v14261) {
      int * v14098 = v14069->cache_age;
      int v14263 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14079 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v14099 = v14098[v14263];
      int v14100 = v14098[v14247];
      int v14264 = v14100 + ((int)((unsigned int)(v14100 - v14099) >> 31));
      v14098[v14247] = v14264;
      int * v14102 = v14069->cache_age;
      int v14103 = v14102[v14248];
      int v14266 = v14103 + ((int)((unsigned int)(v14103 - v14099) >> 31));
      v14102[v14248] = v14266;
      int * v14105 = v14069->cache_age;
      v14105[v14263] = 0;
      v14151 = v14263;
    } else {
      int * v14108 = v14069->cache_age;
      int v14270 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2);
      int v14109 = v14108[v14270];
      int * v14110 = v14069->cache_tags;
      int v14111 = v14110[v14270];
      int v14112 = v14108[v14248];
      int v14113 = v14110[v14248];
      int * v14114 = v14069->cache_dirty;
      int v14273 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14109 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2)) - (v14112 + ((~(((v14113 ^ -1) | (-(v14113 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14115 = v14114[v14273];
      bool v14274 = !(v14115 == 0);
      if (v14274) {
        int * v14116 = v14069->cache_tags;
        int v14117 = v14116[v14273];
        int * v14118 = v14069->cache_vals;
        int v14277 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14109 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2)) - (v14112 + ((~(((v14113 ^ -1) | (-(v14113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14119 = v14118[v14277];
        int v14278 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14109 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2)) - (v14112 + ((~(((v14113 ^ -1) | (-(v14113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14120 = v14118[v14278];
        int * v14121 = v14069->mem;
        int v14280 = v14117 * 2;
        v14121[v14280] = v14119;
        int * v14123 = v14069->mem;
        int v14283 = (v14117 * 2) + 1;
        v14123[v14283] = v14120;
        ;
      } else {
        ;
      }
      int * v14128 = v14069->mem;
      int v14288 = ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) * 2;
      int v14129 = v14128[v14288];
      int v14289 = (((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) * 2) + 1;
      int v14130 = v14128[v14289];
      int * v14131 = v14069->cache_vals;
      int v14291 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14109 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2)) - (v14112 + ((~(((v14113 ^ -1) | (-(v14113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14131[v14291] = v14129;
      int * v14133 = v14069->cache_vals;
      int v14294 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14109 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2)) - (v14112 + ((~(((v14113 ^ -1) | (-(v14113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14133[v14294] = v14130;
      int * v14135 = v14069->cache_tags;
      int v14297 = (int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1);
      v14135[v14273] = v14297;
      int * v14137 = v14069->cache_dirty;
      v14137[v14273] = 0;
      int * v14139 = v14069->cache_age;
      v14139[v14273] = 1;
      int * v14141 = v14069->cache_age;
      int v14142 = v14141[v14273];
      int v14143 = v14141[v14247];
      int v14303 = v14143 + ((int)((unsigned int)(v14143 - v14142) >> 31));
      v14141[v14247] = v14303;
      int * v14145 = v14069->cache_age;
      int v14146 = v14145[v14248];
      int v14305 = v14146 + ((int)((unsigned int)(v14146 - v14142) >> 31));
      v14145[v14248] = v14305;
      int * v14148 = v14069->cache_age;
      v14148[v14273] = 0;
      v14151 = v14273;
    }
    int * v14152 = v14069->cache_vals;
    int v14308 = v14151 * 2;
    int v14153 = v14152[v14308];
    int v14309 = (v14151 * 2) + 1;
    int v14154 = v14152[v14309];
    int v14310 = (((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14093 + ((~(((v14095 ^ -1) | (-(v14095 ^ -1))) >> 31)) & 2)) - (v14096 + ((~(((v14097 ^ -1) | (-(v14097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14152[v14310] = v14153;
    int * v14156 = v14069->cache_vals;
    int v14313 = ((((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14093 + ((~(((v14095 ^ -1) | (-(v14095 ^ -1))) >> 31)) & 2)) - (v14096 + ((~(((v14097 ^ -1) | (-(v14097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14156[v14313] = v14154;
    int * v14158 = v14069->cache_tags;
    int v14316 = ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14093 + ((~(((v14095 ^ -1) | (-(v14095 ^ -1))) >> 31)) & 2)) - (v14096 + ((~(((v14097 ^ -1) | (-(v14097 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14317 = (int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1);
    v14158[v14316] = v14317;
    int * v14160 = v14069->cache_dirty;
    v14160[v14316] = 0;
    int * v14162 = v14069->cache_age;
    v14162[v14316] = 1;
    int * v14164 = v14069->cache_age;
    int v14165 = v14164[v14316];
    int v14166 = v14164[v14245];
    int v14323 = v14166 + ((int)((unsigned int)(v14166 - v14165) >> 31));
    v14164[v14245] = v14323;
    int * v14168 = v14069->cache_age;
    int v14169 = v14168[v14246];
    int v14325 = v14169 + ((int)((unsigned int)(v14169 - v14165) >> 31));
    v14168[v14246] = v14325;
    int * v14171 = v14069->cache_age;
    v14171[v14316] = 0;
    v14174 = v14316;
  }
  int * v14175 = v14069->cache_vals;
  int v14328 = (v14174 * 2) + (((int)((unsigned int)(v14073 + 20) >> 2)) & 1);
  v14175[v14328] = v14074;
  int * v14177 = v14069->cache_tags;
  int v14178 = v14177[v14247];
  int v14179 = v14177[v14248];
  bool v14331 = !(((~(((v14178 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14178 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14179 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14179 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v14233;
  if (v14331) {
    int * v14180 = v14069->cache_age;
    int v14333 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14179 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))) | (-(v14179 ^ ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v14181 = v14180[v14333];
    int v14182 = v14180[v14247];
    int v14334 = v14182 + ((int)((unsigned int)(v14182 - v14181) >> 31));
    v14180[v14247] = v14334;
    int * v14184 = v14069->cache_age;
    int v14185 = v14184[v14248];
    int v14336 = v14185 + ((int)((unsigned int)(v14185 - v14181) >> 31));
    v14184[v14248] = v14336;
    int * v14187 = v14069->cache_age;
    v14187[v14333] = 0;
    v14233 = v14333;
  } else {
    int * v14190 = v14069->cache_age;
    int v14340 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2);
    int v14191 = v14190[v14340];
    int * v14192 = v14069->cache_tags;
    int v14193 = v14192[v14340];
    int v14194 = v14190[v14248];
    int v14195 = v14192[v14248];
    int * v14196 = v14069->cache_dirty;
    int v14343 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14191 + ((~(((v14193 ^ -1) | (-(v14193 ^ -1))) >> 31)) & 2)) - (v14194 + ((~(((v14195 ^ -1) | (-(v14195 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14197 = v14196[v14343];
    bool v14344 = !(v14197 == 0);
    if (v14344) {
      int * v14198 = v14069->cache_tags;
      int v14199 = v14198[v14343];
      int * v14200 = v14069->cache_vals;
      int v14347 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14191 + ((~(((v14193 ^ -1) | (-(v14193 ^ -1))) >> 31)) & 2)) - (v14194 + ((~(((v14195 ^ -1) | (-(v14195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v14201 = v14200[v14347];
      int v14348 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14191 + ((~(((v14193 ^ -1) | (-(v14193 ^ -1))) >> 31)) & 2)) - (v14194 + ((~(((v14195 ^ -1) | (-(v14195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v14202 = v14200[v14348];
      int * v14203 = v14069->mem;
      int v14350 = v14199 * 2;
      v14203[v14350] = v14201;
      int * v14205 = v14069->mem;
      int v14353 = (v14199 * 2) + 1;
      v14205[v14353] = v14202;
      ;
    } else {
      ;
    }
    int * v14210 = v14069->mem;
    int v14358 = ((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) * 2;
    int v14211 = v14210[v14358];
    int v14359 = (((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) * 2) + 1;
    int v14212 = v14210[v14359];
    int * v14213 = v14069->cache_vals;
    int v14361 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14191 + ((~(((v14193 ^ -1) | (-(v14193 ^ -1))) >> 31)) & 2)) - (v14194 + ((~(((v14195 ^ -1) | (-(v14195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14213[v14361] = v14211;
    int * v14215 = v14069->cache_vals;
    int v14364 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14191 + ((~(((v14193 ^ -1) | (-(v14193 ^ -1))) >> 31)) & 2)) - (v14194 + ((~(((v14195 ^ -1) | (-(v14195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14215[v14364] = v14212;
    int * v14217 = v14069->cache_tags;
    int v14367 = (int)((unsigned int)((int)((unsigned int)(v14073 + 20) >> 2)) >> 1);
    v14217[v14343] = v14367;
    int * v14219 = v14069->cache_dirty;
    v14219[v14343] = 0;
    int * v14221 = v14069->cache_age;
    v14221[v14343] = 1;
    int * v14223 = v14069->cache_age;
    int v14224 = v14223[v14343];
    int v14225 = v14223[v14247];
    int v14373 = v14225 + ((int)((unsigned int)(v14225 - v14224) >> 31));
    v14223[v14247] = v14373;
    int * v14227 = v14069->cache_age;
    int v14228 = v14227[v14248];
    int v14375 = v14228 + ((int)((unsigned int)(v14228 - v14224) >> 31));
    v14227[v14248] = v14375;
    int * v14230 = v14069->cache_age;
    v14230[v14343] = 0;
    v14233 = v14343;
  }
  int * v14234 = v14069->cache_vals;
  int v14378 = (v14233 * 2) + (((int)((unsigned int)(v14073 + 20) >> 2)) & 1);
  v14234[v14378] = v14074;
  int * v14236 = v14069->cache_dirty;
  v14236[v14233] = 1;
  struct StateT * v14238 = slot_223(v14069);
  return v14238;
}

struct StateT * slot_468(struct StateT * v23217) {
  int v23218 = v23217->timer;
  int v23226 = v23218 + 1;
  v23217->timer = v23226;
  int * v23220 = v23217->regs;
  int v23221 = v23220[21];
  int v23222 = v23220[24];
  int v23230 = v23221 | v23222;
  v23220[21] = v23230;
  struct StateT * v23224 = slot_469(v23217);
  return v23224;
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

struct StateT * slot_485(struct StateT * v23512) {
  int v23513 = v23512->timer;
  int v23521 = v23513 + 1;
  v23512->timer = v23521;
  int * v23515 = v23512->regs;
  int v23516 = v23515[20];
  int v23517 = v23515[24];
  int v23525 = v23516 | v23517;
  v23515[20] = v23525;
  struct StateT * v23519 = slot_486(v23512);
  return v23519;
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

struct StateT * slot_350(struct StateT * v21265) {
  int v21266 = v21265->timer;
  int v21273 = v21266 + 1;
  v21265->timer = v21273;
  int * v21268 = v21265->regs;
  int v21269 = v21268[23];
  int v21277 = (int)((unsigned int)v21269 >> 23);
  v21268[24] = v21277;
  struct StateT * v21271 = slot_351(v21265);
  return v21271;
}

struct StateT * slot_392(struct StateT * v21918) {
  int v21919 = v21918->timer;
  int v21927 = v21919 + 1;
  v21918->timer = v21927;
  int * v21921 = v21918->regs;
  int v21922 = v21921[23];
  int v21923 = v21921[24];
  int v21931 = v21922 | v21923;
  v21921[23] = v21931;
  struct StateT * v21925 = slot_393(v21918);
  return v21925;
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

struct StateT * slot_378(struct StateT * v21703) {
  int v21704 = v21703->timer;
  int v21712 = v21704 + 1;
  v21703->timer = v21712;
  int * v21706 = v21703->regs;
  int v21707 = v21706[9];
  int v21708 = v21706[5];
  int v21717 = v21707 + v21708;
  v21706[21] = v21717;
  struct StateT * v21710 = slot_379(v21703);
  return v21710;
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

struct StateT * slot_417(struct StateT * v22349) {
  int * v22350 = v22349->saved_regs;
  int * v22351 = v22349->regs;
  int v22352 = v22351[19];
  v22350[19] = v22352;
  int v22354 = v22349->timer;
  int v22366 = v22354 + 1;
  v22349->timer = v22366;
  int * v22356 = v22349->regs;
  int v22357 = v22356[19];
  int v22358 = v22356[22];
  int v22369 = v22357 ^ v22358;
  v22356[19] = v22369;
  struct StateT * v22360 = slot_418(v22349);
  return v22360;
}

struct StateT * slot_405(struct StateT * v22152) {
  int v22153 = v22152->timer;
  int v22161 = v22153 + 1;
  v22152->timer = v22161;
  int * v22155 = v22152->regs;
  int v22156 = v22155[20];
  int v22157 = v22155[24];
  int v22165 = v22156 | v22157;
  v22155[20] = v22165;
  struct StateT * v22159 = slot_406(v22152);
  return v22159;
}

struct StateT * slot_215(struct StateT * v14055) {
  int v14056 = v14055->timer;
  int v14063 = v14056 + 1;
  v14055->timer = v14063;
  int * v14058 = v14055->regs;
  int v14059 = v14058[20];
  int v14066 = v14059 << 7;
  v14058[20] = v14066;
  struct StateT * v14061 = slot_222(v14055);
  return v14061;
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

struct StateT * slot_463(struct StateT * v23143) {
  int v23144 = v23143->timer;
  int v23151 = v23144 + 1;
  v23143->timer = v23151;
  int * v23146 = v23143->regs;
  int v23147 = v23146[20];
  int v23155 = (int)((unsigned int)v23147 >> 14);
  v23146[24] = v23155;
  struct StateT * v23149 = slot_464(v23143);
  return v23149;
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

struct StateT * slot_387(struct StateT * v21844) {
  int v21845 = v21844->timer;
  int v21852 = v21845 + 1;
  v21844->timer = v21852;
  int * v21847 = v21844->regs;
  int v21848 = v21847[22];
  int v21856 = (int)((unsigned int)v21848 >> 14);
  v21847[24] = v21856;
  struct StateT * v21850 = slot_388(v21844);
  return v21850;
}

struct StateT * slot_273(struct StateT * v20062) {
  int v20063 = v20062->timer;
  int v20071 = v20063 + 1;
  v20062->timer = v20071;
  int * v20065 = v20062->regs;
  int v20066 = v20065[6];
  int v20067 = v20065[20];
  int v20075 = v20066 ^ v20067;
  v20065[6] = v20075;
  struct StateT * v20069 = slot_274(v20062);
  return v20069;
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

struct StateT * slot_495(struct StateT * v23663) {
  int v23664 = v23663->timer;
  int v23672 = v23664 + 1;
  v23663->timer = v23672;
  int * v23666 = v23663->regs;
  int v23667 = v23666[14];
  int v23668 = v23666[20];
  int v23676 = v23667 ^ v23668;
  v23666[14] = v23676;
  struct StateT * v23670 = slot_496(v23663);
  return v23670;
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

struct StateT * slot_301(struct StateT * v20506) {
  int v20507 = v20506->timer;
  int v20514 = v20507 + 1;
  v20506->timer = v20514;
  int * v20509 = v20506->regs;
  int v20510 = v20509[20];
  int v20518 = (int)((unsigned int)v20510 >> 14);
  v20509[24] = v20518;
  struct StateT * v20512 = slot_302(v20506);
  return v20512;
}

struct StateT * slot_502(struct StateT * v23778) {
  int v23779 = v23778->timer;
  int v23787 = v23779 + 1;
  v23778->timer = v23787;
  int * v23781 = v23778->regs;
  int v23782 = v23781[16];
  int v23783 = v23781[31];
  int v23792 = v23782 + v23783;
  v23781[23] = v23792;
  struct StateT * v23785 = slot_503(v23778);
  return v23785;
}

struct StateT * slot_506(struct StateT * v23840) {
  int v23841 = v23840->timer;
  int v23848 = v23841 + 1;
  v23840->timer = v23848;
  int * v23843 = v23840->regs;
  int v23844 = v23843[21];
  int v23852 = (int)((unsigned int)v23844 >> 23);
  v23843[24] = v23852;
  struct StateT * v23846 = slot_507(v23840);
  return v23846;
}

struct StateT * slot_413(struct StateT * v22273) {
  int v22274 = v22273->timer;
  int v22281 = v22274 + 1;
  v22273->timer = v22281;
  int * v22276 = v22273->regs;
  int v22277 = v22276[23];
  int v22284 = v22277 << 7;
  v22276[23] = v22284;
  struct StateT * v22279 = slot_414(v22273);
  return v22279;
}

struct StateT * slot_320(struct StateT * v20801) {
  int v20802 = v20801->timer;
  int v20810 = v20802 + 1;
  v20801->timer = v20810;
  int * v20804 = v20801->regs;
  int v20805 = v20804[31];
  int v20806 = v20804[19];
  int v20815 = v20805 + v20806;
  v20804[23] = v20815;
  struct StateT * v20808 = slot_321(v20801);
  return v20808;
}

struct StateT * slot_281(struct StateT * v20194) {
  int v20195 = v20194->timer;
  int v20202 = v20195 + 1;
  v20194->timer = v20202;
  int * v20197 = v20194->regs;
  int v20198 = v20197[20];
  int v20206 = (int)((unsigned int)v20198 >> 19);
  v20197[24] = v20206;
  struct StateT * v20200 = slot_282(v20194);
  return v20200;
}

struct StateT * slot_533(struct StateT * v24257) {
  int v24258 = v24257->timer;
  int v24265 = v24258 + 1;
  v24257->timer = v24265;
  int * v24260 = v24257->regs;
  int v24261 = v24260[23];
  int v24268 = v24261 << 13;
  v24260[23] = v24268;
  struct StateT * v24263 = slot_534(v24257);
  return v24263;
}

struct StateT * slot_203(struct StateT * v10594) {
  int v10595 = v10594->timer;
  int v10603 = v10595 + 1;
  v10594->timer = v10603;
  int * v10597 = v10594->regs;
  int v10598 = v10597[29];
  int v10599 = v10597[14];
  int v10608 = v10598 + v10599;
  v10597[21] = v10608;
  struct StateT * v10601 = slot_206(v10594);
  return v10601;
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

struct StateT * slot_447(struct StateT * v22863) {
  int v22864 = v22863->timer;
  int v22871 = v22864 + 1;
  v22863->timer = v22871;
  int * v22866 = v22863->regs;
  int v22867 = v22866[21];
  int v22874 = v22867 << 13;
  v22866[21] = v22874;
  struct StateT * v22869 = slot_448(v22863);
  return v22869;
}

struct StateT * slot_559(struct StateT * v24663) {
  int * v24664 = v24663->saved_regs;
  int * v24665 = v24663->regs;
  int v24666 = v24665[13];
  v24664[13] = v24666;
  int v24668 = v24663->timer;
  int v24679 = v24668 + 1;
  v24663->timer = v24679;
  int * v24670 = v24663->regs;
  int v24671 = v24670[13];
  int v24681 = v24671 + 1;
  v24670[13] = v24681;
  struct StateT * v24673 = slot_560(v24663);
  return v24673;
}

struct StateT * slot_243(struct StateT * v19461) {
  int v19462 = v19461->timer;
  int v19465 = v19462 + 1;
  v19461->timer = v19465;
  return v19461;
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

struct StateT * slot_307(struct StateT * v20596) {
  int v20597 = v20596->timer;
  int v20604 = v20597 + 1;
  v20596->timer = v20604;
  int * v20599 = v20596->regs;
  int v20600 = v20599[22];
  int v20608 = (int)((unsigned int)v20600 >> 14);
  v20599[24] = v20608;
  struct StateT * v20602 = slot_308(v20596);
  return v20602;
}

struct StateT * slot_453(struct StateT * v22953) {
  int v22954 = v22953->timer;
  int v22961 = v22954 + 1;
  v22953->timer = v22961;
  int * v22956 = v22953->regs;
  int v22957 = v22956[23];
  int v22964 = v22957 << 13;
  v22956[23] = v22964;
  struct StateT * v22959 = slot_454(v22953);
  return v22959;
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

struct StateT * slot_370(struct StateT * v21577) {
  int v21578 = v21577->timer;
  int v21585 = v21578 + 1;
  v21577->timer = v21585;
  int * v21580 = v21577->regs;
  int v21581 = v21580[23];
  int v21589 = (int)((unsigned int)v21581 >> 19);
  v21580[24] = v21589;
  struct StateT * v21583 = slot_371(v21577);
  return v21583;
}

struct StateT * slot_206(struct StateT * v11241) {
  int v11242 = v11241->timer;
  int v11250 = v11242 + 1;
  v11241->timer = v11250;
  int * v11244 = v11241->regs;
  int v11245 = v11244[28];
  int v11246 = v11244[12];
  int v11255 = v11245 + v11246;
  v11244[22] = v11255;
  struct StateT * v11248 = slot_209(v11241);
  return v11248;
}

struct StateT * slot_227(struct StateT * v16940) {
  int v16941 = v16940->timer;
  int v17051 = v16941 + 1;
  v16940->timer = v17051;
  int * v16943 = v16940->regs;
  int v16944 = v16943[2];
  int * v16945 = v16940->cache_tags;
  int v17055 = (((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2;
  int v16946 = v16945[v17055];
  int v17056 = ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16947 = v16945[v17056];
  int v17057 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2);
  int v16948 = v16945[v17057];
  int v17058 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16949 = v16945[v17058];
  int v16950 = v16940->timer;
  int v17059 = v16950 + ((100 ^ (((~(((v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16946 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16946 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16940->timer = v17059;
  int * v16952 = v16940->cache_vals;
  bool v17060 = !(((~(((v16946 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16946 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v17045;
  if (v17060) {
    int * v16953 = v16940->cache_age;
    int v17062 = ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16947 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v16954 = v16953[v17062];
    int v16955 = v16953[v17055];
    int v17063 = v16955 + ((int)((unsigned int)(v16955 - v16954) >> 31));
    v16953[v17055] = v17063;
    int * v16957 = v16940->cache_age;
    int v16958 = v16957[v17056];
    int v17065 = v16958 + ((int)((unsigned int)(v16958 - v16954) >> 31));
    v16957[v17056] = v17065;
    int * v16960 = v16940->cache_age;
    v16960[v17062] = 0;
    v17045 = v17062;
  } else {
    int * v16963 = v16940->cache_age;
    int v17069 = (((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2;
    int v16964 = v16963[v17069];
    int * v16965 = v16940->cache_tags;
    int v16966 = v16965[v17069];
    int v16967 = v16963[v17056];
    int v16968 = v16965[v17056];
    bool v17071 = !(((~(((v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16948 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v17022;
    if (v17071) {
      int * v16969 = v16940->cache_age;
      int v17073 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))) | (-(v16949 ^ ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v16970 = v16969[v17073];
      int v16971 = v16969[v17057];
      int v17074 = v16971 + ((int)((unsigned int)(v16971 - v16970) >> 31));
      v16969[v17057] = v17074;
      int * v16973 = v16940->cache_age;
      int v16974 = v16973[v17058];
      int v17076 = v16974 + ((int)((unsigned int)(v16974 - v16970) >> 31));
      v16973[v17058] = v17076;
      int * v16976 = v16940->cache_age;
      v16976[v17073] = 0;
      v17022 = v17073;
    } else {
      int * v16979 = v16940->cache_age;
      int v17080 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2);
      int v16980 = v16979[v17080];
      int * v16981 = v16940->cache_tags;
      int v16982 = v16981[v17080];
      int v16983 = v16979[v17058];
      int v16984 = v16981[v17058];
      int * v16985 = v16940->cache_dirty;
      int v17083 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16980 + ((~(((v16982 ^ -1) | (-(v16982 ^ -1))) >> 31)) & 2)) - (v16983 + ((~(((v16984 ^ -1) | (-(v16984 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16986 = v16985[v17083];
      bool v17084 = !(v16986 == 0);
      if (v17084) {
        int * v16987 = v16940->cache_tags;
        int v16988 = v16987[v17083];
        int * v16989 = v16940->cache_vals;
        int v17087 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16980 + ((~(((v16982 ^ -1) | (-(v16982 ^ -1))) >> 31)) & 2)) - (v16983 + ((~(((v16984 ^ -1) | (-(v16984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16990 = v16989[v17087];
        int v17088 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16980 + ((~(((v16982 ^ -1) | (-(v16982 ^ -1))) >> 31)) & 2)) - (v16983 + ((~(((v16984 ^ -1) | (-(v16984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16991 = v16989[v17088];
        int * v16992 = v16940->mem;
        int v17090 = v16988 * 2;
        v16992[v17090] = v16990;
        int * v16994 = v16940->mem;
        int v17093 = (v16988 * 2) + 1;
        v16994[v17093] = v16991;
        ;
      } else {
        ;
      }
      int * v16999 = v16940->mem;
      int v17098 = ((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) * 2;
      int v17000 = v16999[v17098];
      int v17099 = (((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) * 2) + 1;
      int v17001 = v16999[v17099];
      int * v17002 = v16940->cache_vals;
      int v17101 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16980 + ((~(((v16982 ^ -1) | (-(v16982 ^ -1))) >> 31)) & 2)) - (v16983 + ((~(((v16984 ^ -1) | (-(v16984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17002[v17101] = v17000;
      int * v17004 = v16940->cache_vals;
      int v17104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16980 + ((~(((v16982 ^ -1) | (-(v16982 ^ -1))) >> 31)) & 2)) - (v16983 + ((~(((v16984 ^ -1) | (-(v16984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17004[v17104] = v17001;
      int * v17006 = v16940->cache_tags;
      int v17107 = (int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1);
      v17006[v17083] = v17107;
      int * v17008 = v16940->cache_dirty;
      v17008[v17083] = 0;
      int * v17010 = v16940->cache_age;
      v17010[v17083] = 1;
      int * v17012 = v16940->cache_age;
      int v17013 = v17012[v17083];
      int v17014 = v17012[v17057];
      int v17113 = v17014 + ((int)((unsigned int)(v17014 - v17013) >> 31));
      v17012[v17057] = v17113;
      int * v17016 = v16940->cache_age;
      int v17017 = v17016[v17058];
      int v17115 = v17017 + ((int)((unsigned int)(v17017 - v17013) >> 31));
      v17016[v17058] = v17115;
      int * v17019 = v16940->cache_age;
      v17019[v17083] = 0;
      v17022 = v17083;
    }
    int * v17023 = v16940->cache_vals;
    int v17118 = v17022 * 2;
    int v17024 = v17023[v17118];
    int v17119 = (v17022 * 2) + 1;
    int v17025 = v17023[v17119];
    int v17120 = (((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16964 + ((~(((v16966 ^ -1) | (-(v16966 ^ -1))) >> 31)) & 2)) - (v16967 + ((~(((v16968 ^ -1) | (-(v16968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17023[v17120] = v17024;
    int * v17027 = v16940->cache_vals;
    int v17123 = ((((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16964 + ((~(((v16966 ^ -1) | (-(v16966 ^ -1))) >> 31)) & 2)) - (v16967 + ((~(((v16968 ^ -1) | (-(v16968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17027[v17123] = v17025;
    int * v17029 = v16940->cache_tags;
    int v17126 = ((((int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16964 + ((~(((v16966 ^ -1) | (-(v16966 ^ -1))) >> 31)) & 2)) - (v16967 + ((~(((v16968 ^ -1) | (-(v16968 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17127 = (int)((unsigned int)((int)((unsigned int)(v16944 + 20) >> 2)) >> 1);
    v17029[v17126] = v17127;
    int * v17031 = v16940->cache_dirty;
    v17031[v17126] = 0;
    int * v17033 = v16940->cache_age;
    v17033[v17126] = 1;
    int * v17035 = v16940->cache_age;
    int v17036 = v17035[v17126];
    int v17037 = v17035[v17055];
    int v17133 = v17037 + ((int)((unsigned int)(v17037 - v17036) >> 31));
    v17035[v17055] = v17133;
    int * v17039 = v16940->cache_age;
    int v17040 = v17039[v17056];
    int v17135 = v17040 + ((int)((unsigned int)(v17040 - v17036) >> 31));
    v17039[v17056] = v17135;
    int * v17042 = v16940->cache_age;
    v17042[v17126] = 0;
    v17045 = v17126;
  }
  int v17138 = (v17045 * 2) + (((int)((unsigned int)(v16944 + 20) >> 2)) & 1);
  int v17046 = v16952[v17138];
  int * v17047 = v16940->regs;
  v17047[22] = v17046;
  struct StateT * v17049 = slot_234(v16940);
  return v17049;
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

struct StateT * slot_442(struct StateT * v22786) {
  int v22787 = v22786->timer;
  int v22795 = v22787 + 1;
  v22786->timer = v22795;
  int * v22789 = v22786->regs;
  int v22790 = v22789[5];
  int v22791 = v22789[8];
  int v22800 = v22790 + v22791;
  v22789[23] = v22800;
  struct StateT * v22793 = slot_443(v22786);
  return v22793;
}

struct StateT * slot_529(struct StateT * v24197) {
  int v24198 = v24197->timer;
  int v24205 = v24198 + 1;
  v24197->timer = v24205;
  int * v24200 = v24197->regs;
  int v24201 = v24200[22];
  int v24209 = (int)((unsigned int)v24201 >> 19);
  v24200[24] = v24209;
  struct StateT * v24203 = slot_530(v24197);
  return v24203;
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

struct StateT * slot_357(struct StateT * v21374) {
  int v21375 = v21374->timer;
  int v21383 = v21375 + 1;
  v21374->timer = v21383;
  int * v21377 = v21374->regs;
  int v21378 = v21377[17];
  int v21379 = v21377[14];
  int v21388 = v21378 + v21379;
  v21377[20] = v21388;
  struct StateT * v21381 = slot_358(v21374);
  return v21381;
}

struct StateT * slot_385(struct StateT * v21814) {
  int v21815 = v21814->timer;
  int v21822 = v21815 + 1;
  v21814->timer = v21822;
  int * v21817 = v21814->regs;
  int v21818 = v21817[21];
  int v21825 = v21818 << 18;
  v21817[21] = v21825;
  struct StateT * v21820 = slot_386(v21814);
  return v21820;
}

struct StateT * slot_444(struct StateT * v22818) {
  int v22819 = v22818->timer;
  int v22826 = v22819 + 1;
  v22818->timer = v22826;
  int * v22821 = v22818->regs;
  int v22822 = v22821[20];
  int v22829 = v22822 << 13;
  v22821[20] = v22829;
  struct StateT * v22824 = slot_445(v22818);
  return v22824;
}

struct StateT * slot_261(struct StateT * v19882) {
  int v19883 = v19882->timer;
  int v19890 = v19883 + 1;
  v19882->timer = v19890;
  int * v19885 = v19882->regs;
  int v19886 = v19885[20];
  int v19894 = (int)((unsigned int)v19886 >> 23);
  v19885[24] = v19894;
  struct StateT * v19888 = slot_262(v19882);
  return v19888;
}

struct StateT * slot_287(struct StateT * v20284) {
  int v20285 = v20284->timer;
  int v20292 = v20285 + 1;
  v20284->timer = v20292;
  int * v20287 = v20284->regs;
  int v20288 = v20287[22];
  int v20296 = (int)((unsigned int)v20288 >> 19);
  v20287[24] = v20296;
  struct StateT * v20290 = slot_288(v20284);
  return v20290;
}

struct StateT * slot_343(struct StateT * v21159) {
  int v21160 = v21159->timer;
  int v21168 = v21160 + 1;
  v21159->timer = v21168;
  int * v21162 = v21159->regs;
  int v21163 = v21162[20];
  int v21164 = v21162[24];
  int v21172 = v21163 | v21164;
  v21162[20] = v21172;
  struct StateT * v21166 = slot_344(v21159);
  return v21166;
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

struct StateT * slot_426(struct StateT * v22508) {
  int v22509 = v22508->timer;
  int v22516 = v22509 + 1;
  v22508->timer = v22516;
  int * v22511 = v22508->regs;
  int v22512 = v22511[21];
  int v22520 = (int)((unsigned int)v22512 >> 23);
  v22511[24] = v22520;
  struct StateT * v22514 = slot_427(v22508);
  return v22514;
}

struct StateT * slot_536(struct StateT * v24303) {
  int v24304 = v24303->timer;
  int v24312 = v24304 + 1;
  v24303->timer = v24312;
  int * v24306 = v24303->regs;
  int v24307 = v24306[9];
  int v24308 = v24306[21];
  int v24316 = v24307 ^ v24308;
  v24306[9] = v24316;
  struct StateT * v24310 = slot_537(v24303);
  return v24310;
}

struct StateT * slot_470(struct StateT * v23248) {
  int v23249 = v23248->timer;
  int v23256 = v23249 + 1;
  v23248->timer = v23256;
  int * v23251 = v23248->regs;
  int v23252 = v23251[22];
  int v23259 = v23252 << 18;
  v23251[22] = v23259;
  struct StateT * v23254 = slot_471(v23248);
  return v23254;
}

struct StateT * slot_431(struct StateT * v22582) {
  int v22583 = v22582->timer;
  int v22591 = v22583 + 1;
  v22582->timer = v22591;
  int * v22585 = v22582->regs;
  int v22586 = v22585[22];
  int v22587 = v22585[24];
  int v22595 = v22586 | v22587;
  v22585[22] = v22595;
  struct StateT * v22589 = slot_432(v22582);
  return v22589;
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

struct StateT * slot_308(struct StateT * v20611) {
  int v20612 = v20611->timer;
  int v20619 = v20612 + 1;
  v20611->timer = v20619;
  int * v20614 = v20611->regs;
  int v20615 = v20614[22];
  int v20622 = v20615 << 18;
  v20614[22] = v20622;
  struct StateT * v20617 = slot_309(v20611);
  return v20617;
}

struct StateT * slot_400(struct StateT * v22044) {
  int * v22045 = v22044->saved_regs;
  int * v22046 = v22044->regs;
  int v22047 = v22046[21];
  v22045[21] = v22047;
  int v22049 = v22044->timer;
  int v22061 = v22049 + 1;
  v22044->timer = v22061;
  int * v22051 = v22044->regs;
  int v22052 = v22051[29];
  int v22053 = v22051[14];
  int v22065 = v22052 + v22053;
  v22051[21] = v22065;
  struct StateT * v22055 = slot_401(v22044);
  return v22055;
}

struct StateT * slot_323(struct StateT * v20847) {
  int v20848 = v20847->timer;
  int v20856 = v20848 + 1;
  v20847->timer = v20856;
  int * v20850 = v20847->regs;
  int v20851 = v20850[20];
  int v20852 = v20850[24];
  int v20860 = v20851 | v20852;
  v20850[20] = v20860;
  struct StateT * v20854 = slot_324(v20847);
  return v20854;
}

struct StateT * slot_521(struct StateT * v24073) {
  int v24074 = v24073->timer;
  int v24082 = v24074 + 1;
  v24073->timer = v24082;
  int * v24076 = v24073->regs;
  int v24077 = v24076[6];
  int v24078 = v24076[15];
  int v24087 = v24077 + v24078;
  v24076[22] = v24087;
  struct StateT * v24080 = slot_522(v24073);
  return v24080;
}

struct StateT * slot_530(struct StateT * v24212) {
  int v24213 = v24212->timer;
  int v24220 = v24213 + 1;
  v24212->timer = v24220;
  int * v24215 = v24212->regs;
  int v24216 = v24215[22];
  int v24223 = v24216 << 13;
  v24215[22] = v24223;
  struct StateT * v24218 = slot_531(v24212);
  return v24218;
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

struct StateT * slot_538(struct StateT * v24335) {
  int v24336 = v24335->timer;
  int v24344 = v24336 + 1;
  v24335->timer = v24344;
  int * v24338 = v24335->regs;
  int v24339 = v24338[19];
  int v24340 = v24338[23];
  int v24348 = v24339 ^ v24340;
  v24338[19] = v24348;
  struct StateT * v24342 = slot_539(v24335);
  return v24342;
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

struct StateT * slot_411(struct StateT * v22242) {
  int v22243 = v22242->timer;
  int v22251 = v22243 + 1;
  v22242->timer = v22251;
  int * v22245 = v22242->regs;
  int v22246 = v22245[22];
  int v22247 = v22245[24];
  int v22255 = v22246 | v22247;
  v22245[22] = v22255;
  struct StateT * v22249 = slot_412(v22242);
  return v22249;
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

struct StateT * slot_449(struct StateT * v22893) {
  int v22894 = v22893->timer;
  int v22901 = v22894 + 1;
  v22893->timer = v22901;
  int * v22896 = v22893->regs;
  int v22897 = v22896[22];
  int v22905 = (int)((unsigned int)v22897 >> 19);
  v22896[24] = v22905;
  struct StateT * v22899 = slot_450(v22893);
  return v22899;
}

struct StateT * slot_460(struct StateT * v23092) {
  int v23093 = v23092->timer;
  int v23101 = v23093 + 1;
  v23092->timer = v23101;
  int * v23095 = v23092->regs;
  int v23096 = v23095[14];
  int v23097 = v23095[7];
  int v23106 = v23096 + v23097;
  v23095[21] = v23106;
  struct StateT * v23099 = slot_461(v23092);
  return v23099;
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

struct StateT * slot_474(struct StateT * v23307) {
  int v23308 = v23307->timer;
  int v23316 = v23308 + 1;
  v23307->timer = v23316;
  int * v23310 = v23307->regs;
  int v23311 = v23310[23];
  int v23312 = v23310[24];
  int v23320 = v23311 | v23312;
  v23310[23] = v23320;
  struct StateT * v23314 = slot_475(v23307);
  return v23314;
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

struct StateT * slot_462(struct StateT * v23126) {
  int v23127 = v23126->timer;
  int v23135 = v23127 + 1;
  v23126->timer = v23135;
  int * v23129 = v23126->regs;
  int v23130 = v23129[15];
  int v23131 = v23129[5];
  int v23140 = v23130 + v23131;
  v23129[23] = v23140;
  struct StateT * v23133 = slot_463(v23126);
  return v23133;
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

struct StateT * slot_557(struct StateT * v24631) {
  int v24632 = v24631->timer;
  int v24640 = v24632 + 1;
  v24631->timer = v24640;
  int * v24634 = v24631->regs;
  int v24635 = v24634[28];
  int v24636 = v24634[22];
  int v24644 = v24635 ^ v24636;
  v24634[28] = v24644;
  struct StateT * v24638 = slot_558(v24631);
  return v24638;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_393(struct StateT * v21934) {
  int v21935 = v21934->timer;
  int v21943 = v21935 + 1;
  v21934->timer = v21943;
  int * v21937 = v21934->regs;
  int v21938 = v21937[30];
  int v21939 = v21937[20];
  int v21947 = v21938 ^ v21939;
  v21937[30] = v21947;
  struct StateT * v21941 = slot_394(v21934);
  return v21941;
}

struct StateT * slot_507(struct StateT * v23855) {
  int v23856 = v23855->timer;
  int v23863 = v23856 + 1;
  v23855->timer = v23863;
  int * v23858 = v23855->regs;
  int v23859 = v23858[21];
  int v23866 = v23859 << 9;
  v23858[21] = v23866;
  struct StateT * v23861 = slot_508(v23855);
  return v23861;
}

struct StateT * slot_477(struct StateT * v23369) {
  int * v23370 = v23369->saved_regs;
  int * v23371 = v23369->regs;
  int v23372 = v23371[28];
  v23370[28] = v23372;
  int v23374 = v23369->timer;
  int v23386 = v23374 + 1;
  v23369->timer = v23386;
  int * v23376 = v23369->regs;
  int v23377 = v23376[28];
  int v23378 = v23376[22];
  int v23389 = v23377 ^ v23378;
  v23376[28] = v23389;
  struct StateT * v23380 = slot_478(v23369);
  return v23380;
}

struct StateT * slot_278(struct StateT * v20143) {
  int v20144 = v20143->timer;
  int v20152 = v20144 + 1;
  v20143->timer = v20152;
  int * v20146 = v20143->regs;
  int v20147 = v20146[7];
  int v20148 = v20146[18];
  int v20157 = v20147 + v20148;
  v20146[21] = v20157;
  struct StateT * v20150 = slot_279(v20143);
  return v20150;
}

struct StateT * slot_352(struct StateT * v21294) {
  int v21295 = v21294->timer;
  int v21303 = v21295 + 1;
  v21294->timer = v21303;
  int * v21297 = v21294->regs;
  int v21298 = v21297[23];
  int v21299 = v21297[24];
  int v21307 = v21298 | v21299;
  v21297[23] = v21307;
  struct StateT * v21301 = slot_353(v21294);
  return v21301;
}

struct StateT * slot_249(struct StateT * v19715) {
  int v19716 = v19715->timer;
  int v19723 = v19716 + 1;
  v19715->timer = v19723;
  int * v19718 = v19715->regs;
  int v19719 = v19718[23];
  int v19726 = v19719 << 7;
  v19718[23] = v19726;
  struct StateT * v19721 = slot_251(v19715);
  return v19721;
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

struct StateT * slot_228(struct StateT * v17144) {
  int v17145 = v17144->timer;
  int v17152 = v17145 + 1;
  v17144->timer = v17152;
  int * v17147 = v17144->regs;
  int v17148 = v17147[21];
  int v17155 = v17148 << 7;
  v17147[21] = v17155;
  struct StateT * v17150 = slot_235(v17144);
  return v17150;
}

struct StateT * slot_268(struct StateT * v19987) {
  int v19988 = v19987->timer;
  int v19995 = v19988 + 1;
  v19987->timer = v19995;
  int * v19990 = v19987->regs;
  int v19991 = v19990[22];
  int v19998 = v19991 << 9;
  v19990[22] = v19998;
  struct StateT * v19993 = slot_269(v19987);
  return v19993;
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
  struct StateT * v9801 = slot_210(v9632);
  return v9801;
}

struct StateT * slot_409(struct StateT * v22213) {
  int v22214 = v22213->timer;
  int v22221 = v22214 + 1;
  v22213->timer = v22221;
  int * v22216 = v22213->regs;
  int v22217 = v22216[22];
  int v22225 = (int)((unsigned int)v22217 >> 25);
  v22216[24] = v22225;
  struct StateT * v22219 = slot_410(v22213);
  return v22219;
}

struct StateT * slot_374(struct StateT * v21638) {
  int v21639 = v21638->timer;
  int v21647 = v21639 + 1;
  v21638->timer = v21647;
  int * v21641 = v21638->regs;
  int v21642 = v21641[9];
  int v21643 = v21641[21];
  int v21651 = v21642 ^ v21643;
  v21641[9] = v21651;
  struct StateT * v21645 = slot_375(v21638);
  return v21645;
}

struct StateT * slot_269(struct StateT * v20001) {
  int v20002 = v20001->timer;
  int v20010 = v20002 + 1;
  v20001->timer = v20010;
  int * v20004 = v20001->regs;
  int v20005 = v20004[22];
  int v20006 = v20004[24];
  int v20014 = v20005 | v20006;
  v20004[22] = v20014;
  struct StateT * v20008 = slot_270(v20001);
  return v20008;
}

struct StateT * slot_501(struct StateT * v23761) {
  int v23762 = v23761->timer;
  int v23770 = v23762 + 1;
  v23761->timer = v23770;
  int * v23764 = v23761->regs;
  int v23765 = v23764[15];
  int v23766 = v23764[28];
  int v23775 = v23765 + v23766;
  v23764[22] = v23775;
  struct StateT * v23768 = slot_502(v23761);
  return v23768;
}

struct StateT * slot_251(struct StateT * v19734) {
  int v19735 = v19734->timer;
  int v19743 = v19735 + 1;
  v19734->timer = v19743;
  int * v19737 = v19734->regs;
  int v19738 = v19737[23];
  int v19739 = v19737[24];
  int v19747 = v19738 | v19739;
  v19737[23] = v19747;
  struct StateT * v19741 = slot_253(v19734);
  return v19741;
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

struct StateT * slot_322(struct StateT * v20833) {
  int v20834 = v20833->timer;
  int v20841 = v20834 + 1;
  v20833->timer = v20841;
  int * v20836 = v20833->regs;
  int v20837 = v20836[20];
  int v20844 = v20837 << 7;
  v20836[20] = v20844;
  struct StateT * v20839 = slot_323(v20833);
  return v20839;
}

struct StateT * slot_277(struct StateT * v20126) {
  int v20127 = v20126->timer;
  int v20135 = v20127 + 1;
  v20126->timer = v20135;
  int * v20129 = v20126->regs;
  int v20130 = v20129[6];
  int v20131 = v20129[9];
  int v20140 = v20130 + v20131;
  v20129[20] = v20140;
  struct StateT * v20133 = slot_278(v20126);
  return v20133;
}

struct StateT * slot_353(struct StateT * v21310) {
  int v21311 = v21310->timer;
  int v21319 = v21311 + 1;
  v21310->timer = v21319;
  int * v21313 = v21310->regs;
  int v21314 = v21313[17];
  int v21315 = v21313[20];
  int v21323 = v21314 ^ v21315;
  v21313[17] = v21323;
  struct StateT * v21317 = slot_354(v21310);
  return v21317;
}

struct StateT * slot_397(struct StateT * v21998) {
  int v21999 = v21998->timer;
  int v22006 = v21999 + 1;
  v21998->timer = v22006;
  int * v22001 = v21998->regs;
  int v22002 = v22001[13];
  int v22009 = v22002 + 1;
  v22001[13] = v22009;
  struct StateT * v22004 = slot_398(v21998);
  return v22004;
}

struct StateT * slot_435(struct StateT * v22643) {
  int * v22644 = v22643->saved_regs;
  int * v22645 = v22643->regs;
  int v22646 = v22645[6];
  v22644[6] = v22646;
  int v22648 = v22643->timer;
  int v22660 = v22648 + 1;
  v22643->timer = v22660;
  int * v22650 = v22643->regs;
  int v22651 = v22650[6];
  int v22652 = v22650[20];
  int v22663 = v22651 ^ v22652;
  v22650[6] = v22663;
  struct StateT * v22654 = slot_436(v22643);
  return v22654;
}

struct StateT * slot_476(struct StateT * v23346) {
  int * v23347 = v23346->saved_regs;
  int * v23348 = v23346->regs;
  int v23349 = v23348[29];
  v23347[29] = v23349;
  int v23351 = v23346->timer;
  int v23363 = v23351 + 1;
  v23346->timer = v23363;
  int * v23353 = v23346->regs;
  int v23354 = v23353[29];
  int v23355 = v23353[21];
  int v23366 = v23354 ^ v23355;
  v23353[29] = v23366;
  struct StateT * v23357 = slot_477(v23346);
  return v23357;
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

struct StateT * slot_379(struct StateT * v21720) {
  int v21721 = v21720->timer;
  int v21729 = v21721 + 1;
  v21720->timer = v21729;
  int * v21723 = v21720->regs;
  int v21724 = v21723[18];
  int v21725 = v21723[6];
  int v21734 = v21724 + v21725;
  v21723[22] = v21734;
  struct StateT * v21727 = slot_380(v21720);
  return v21727;
}

struct StateT * slot_475(struct StateT * v23323) {
  int * v23324 = v23323->saved_regs;
  int * v23325 = v23323->regs;
  int v23326 = v23325[30];
  v23324[30] = v23326;
  int v23328 = v23323->timer;
  int v23340 = v23328 + 1;
  v23323->timer = v23340;
  int * v23330 = v23323->regs;
  int v23331 = v23330[30];
  int v23332 = v23330[20];
  int v23343 = v23331 ^ v23332;
  v23330[30] = v23343;
  struct StateT * v23334 = slot_476(v23323);
  return v23334;
}

struct StateT * slot_310(struct StateT * v20641) {
  int v20642 = v20641->timer;
  int v20649 = v20642 + 1;
  v20641->timer = v20649;
  int * v20644 = v20641->regs;
  int v20645 = v20644[23];
  int v20653 = (int)((unsigned int)v20645 >> 14);
  v20644[24] = v20653;
  struct StateT * v20647 = slot_311(v20641);
  return v20647;
}

struct StateT * slot_445(struct StateT * v22832) {
  int v22833 = v22832->timer;
  int v22841 = v22833 + 1;
  v22832->timer = v22841;
  int * v22835 = v22832->regs;
  int v22836 = v22835[20];
  int v22837 = v22835[24];
  int v22845 = v22836 | v22837;
  v22835[20] = v22845;
  struct StateT * v22839 = slot_446(v22832);
  return v22839;
}

struct StateT * slot_295(struct StateT * v20406) {
  int v20407 = v20406->timer;
  int v20415 = v20407 + 1;
  v20406->timer = v20415;
  int * v20409 = v20406->regs;
  int v20410 = v20409[12];
  int v20411 = v20409[22];
  int v20419 = v20410 ^ v20411;
  v20409[12] = v20419;
  struct StateT * v20413 = slot_296(v20406);
  return v20413;
}

struct StateT * slot_315(struct StateT * v20718) {
  int v20719 = v20718->timer;
  int v20727 = v20719 + 1;
  v20718->timer = v20727;
  int * v20721 = v20718->regs;
  int v20722 = v20721[28];
  int v20723 = v20721[22];
  int v20731 = v20722 ^ v20723;
  v20721[28] = v20731;
  struct StateT * v20725 = slot_316(v20718);
  return v20725;
}

struct StateT * slot_545(struct StateT * v24448) {
  int v24449 = v24448->timer;
  int v24457 = v24449 + 1;
  v24448->timer = v24457;
  int * v24451 = v24448->regs;
  int v24452 = v24451[20];
  int v24453 = v24451[24];
  int v24461 = v24452 | v24453;
  v24451[20] = v24461;
  struct StateT * v24455 = slot_546(v24448);
  return v24455;
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

struct StateT * slot_457(struct StateT * v23029) {
  int * v23030 = v23029->saved_regs;
  int * v23031 = v23029->regs;
  int v23032 = v23031[12];
  v23030[12] = v23032;
  int v23034 = v23029->timer;
  int v23046 = v23034 + 1;
  v23029->timer = v23046;
  int * v23036 = v23029->regs;
  int v23037 = v23036[12];
  int v23038 = v23036[22];
  int v23049 = v23037 ^ v23038;
  v23036[12] = v23049;
  struct StateT * v23040 = slot_458(v23029);
  return v23040;
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

struct StateT * slot_493(struct StateT * v23633) {
  int v23634 = v23633->timer;
  int v23641 = v23634 + 1;
  v23633->timer = v23641;
  int * v23636 = v23633->regs;
  int v23637 = v23636[23];
  int v23644 = v23637 << 7;
  v23636[23] = v23644;
  struct StateT * v23639 = slot_494(v23633);
  return v23639;
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

struct StateT * slot_430(struct StateT * v22568) {
  int v22569 = v22568->timer;
  int v22576 = v22569 + 1;
  v22568->timer = v22576;
  int * v22571 = v22568->regs;
  int v22572 = v22571[22];
  int v22579 = v22572 << 9;
  v22571[22] = v22579;
  struct StateT * v22574 = slot_431(v22568);
  return v22574;
}

struct StateT * slot_369(struct StateT * v21561) {
  int v21562 = v21561->timer;
  int v21570 = v21562 + 1;
  v21561->timer = v21570;
  int * v21564 = v21561->regs;
  int v21565 = v21564[22];
  int v21566 = v21564[24];
  int v21574 = v21565 | v21566;
  v21564[22] = v21574;
  struct StateT * v21568 = slot_370(v21561);
  return v21568;
}

struct StateT * slot_461(struct StateT * v23109) {
  int v23110 = v23109->timer;
  int v23118 = v23110 + 1;
  v23109->timer = v23118;
  int * v23112 = v23109->regs;
  int v23113 = v23112[12];
  int v23114 = v23112[17];
  int v23123 = v23113 + v23114;
  v23112[22] = v23123;
  struct StateT * v23116 = slot_462(v23109);
  return v23116;
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

struct StateT * slot_480(struct StateT * v23432) {
  int v23433 = v23432->timer;
  int v23441 = v23433 + 1;
  v23432->timer = v23441;
  int * v23435 = v23432->regs;
  int v23436 = v23435[29];
  int v23437 = v23435[9];
  int v23446 = v23436 + v23437;
  v23435[21] = v23446;
  struct StateT * v23439 = slot_481(v23432);
  return v23439;
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

struct StateT * slot_244(struct StateT * v19466) {
  int v19467 = v19466->timer;
  int v19475 = v19467 + 1;
  v19466->timer = v19475;
  int * v19469 = v19466->regs;
  int v19470 = v19469[22];
  int v19471 = v19469[24];
  int v19479 = v19470 | v19471;
  v19469[22] = v19479;
  struct StateT * v19473 = slot_247(v19466);
  return v19473;
}

struct StateT * slot_222(struct StateT * v14792) {
  int v14793 = v14792->timer;
  int v14801 = v14793 + 1;
  v14792->timer = v14801;
  int * v14795 = v14792->regs;
  int v14796 = v14795[20];
  int v14797 = v14795[24];
  int v14805 = v14796 | v14797;
  v14795[20] = v14805;
  struct StateT * v14799 = slot_225(v14792);
  return v14799;
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

struct StateT * slot_377(struct StateT * v21686) {
  int v21687 = v21686->timer;
  int v21695 = v21687 + 1;
  v21686->timer = v21695;
  int * v21689 = v21686->regs;
  int v21690 = v21689[8];
  int v21691 = v21689[17];
  int v21700 = v21690 + v21691;
  v21689[20] = v21700;
  struct StateT * v21693 = slot_378(v21686);
  return v21693;
}

struct StateT * slot_552(struct StateT * v24554) {
  int v24555 = v24554->timer;
  int v24562 = v24555 + 1;
  v24554->timer = v24562;
  int * v24557 = v24554->regs;
  int v24558 = v24557[23];
  int v24566 = (int)((unsigned int)v24558 >> 14);
  v24557[24] = v24566;
  struct StateT * v24560 = slot_553(v24554);
  return v24560;
}

struct StateT * slot_427(struct StateT * v22523) {
  int v22524 = v22523->timer;
  int v22531 = v22524 + 1;
  v22523->timer = v22531;
  int * v22526 = v22523->regs;
  int v22527 = v22526[21];
  int v22534 = v22527 << 9;
  v22526[21] = v22534;
  struct StateT * v22529 = slot_428(v22523);
  return v22529;
}

struct StateT * slot_399(struct StateT * v22020) {
  int * v22021 = v22020->saved_regs;
  int * v22022 = v22020->regs;
  int v22023 = v22022[20];
  v22021[20] = v22023;
  int v22025 = v22020->timer;
  int v22037 = v22025 + 1;
  v22020->timer = v22037;
  int * v22027 = v22020->regs;
  int v22028 = v22027[30];
  int v22029 = v22027[16];
  int v22041 = v22028 + v22029;
  v22027[20] = v22041;
  struct StateT * v22031 = slot_400(v22020);
  return v22031;
}

struct StateT * slot_464(struct StateT * v23158) {
  int v23159 = v23158->timer;
  int v23166 = v23159 + 1;
  v23158->timer = v23166;
  int * v23161 = v23158->regs;
  int v23162 = v23161[20];
  int v23169 = v23162 << 18;
  v23161[20] = v23169;
  struct StateT * v23164 = slot_465(v23158);
  return v23164;
}

struct StateT * slot_500(struct StateT * v23744) {
  int v23745 = v23744->timer;
  int v23753 = v23745 + 1;
  v23744->timer = v23753;
  int * v23747 = v23744->regs;
  int v23748 = v23747[12];
  int v23749 = v23747[29];
  int v23758 = v23748 + v23749;
  v23747[21] = v23758;
  struct StateT * v23751 = slot_501(v23744);
  return v23751;
}

struct StateT * slot_433(struct StateT * v22613) {
  int v22614 = v22613->timer;
  int v22621 = v22614 + 1;
  v22613->timer = v22621;
  int * v22616 = v22613->regs;
  int v22617 = v22616[23];
  int v22624 = v22617 << 9;
  v22616[23] = v22624;
  struct StateT * v22619 = slot_434(v22613);
  return v22619;
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

struct StateT * slot_267(struct StateT * v19972) {
  int v19973 = v19972->timer;
  int v19980 = v19973 + 1;
  v19972->timer = v19980;
  int * v19975 = v19972->regs;
  int v19976 = v19975[22];
  int v19984 = (int)((unsigned int)v19976 >> 23);
  v19975[24] = v19984;
  struct StateT * v19978 = slot_268(v19972);
  return v19978;
}

struct StateT * slot_492(struct StateT * v23618) {
  int v23619 = v23618->timer;
  int v23626 = v23619 + 1;
  v23618->timer = v23626;
  int * v23621 = v23618->regs;
  int v23622 = v23621[23];
  int v23630 = (int)((unsigned int)v23622 >> 25);
  v23621[24] = v23630;
  struct StateT * v23624 = slot_493(v23618);
  return v23624;
}

struct StateT * slot_201(struct StateT * v9964) {
  int v9965 = v9964->timer;
  int v10135 = v9965 + 1;
  v9964->timer = v10135;
  int * v9967 = v9964->regs;
  int v9968 = v9967[10];
  int v9969 = v9967[30];
  int * v9970 = v9964->cache_tags;
  int v10140 = (((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2;
  int v9971 = v9970[v10140];
  int v10141 = ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9972 = v9970[v10141];
  int v10142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2);
  int v9973 = v9970[v10142];
  int v10143 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9974 = v9970[v10143];
  int v9975 = v9964->timer;
  int v10144 = v9975 + ((100 ^ (((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9971 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9971 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) & 104)))));
  v9964->timer = v10144;
  bool v10145 = !(((~(((v9971 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9971 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) == 0);
  int v10069;
  if (v10145) {
    int * v9977 = v9964->cache_age;
    int v10147 = ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2) + ((~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) & 1);
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
    int v10154 = (((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2;
    int v9988 = v9987[v10154];
    int * v9989 = v9964->cache_tags;
    int v9990 = v9989[v10154];
    int v9991 = v9987[v10141];
    int v9992 = v9989[v10141];
    bool v10156 = !(((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) == 0);
    int v10046;
    if (v10156) {
      int * v9993 = v9964->cache_age;
      int v10158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) & 1);
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
      int v10165 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2);
      int v10004 = v10003[v10165];
      int * v10005 = v9964->cache_tags;
      int v10006 = v10005[v10165];
      int v10007 = v10003[v10143];
      int v10008 = v10005[v10143];
      int * v10009 = v9964->cache_dirty;
      int v10168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10010 = v10009[v10168];
      bool v10169 = !(v10010 == 0);
      if (v10169) {
        int * v10011 = v9964->cache_tags;
        int v10012 = v10011[v10168];
        int * v10013 = v9964->cache_vals;
        int v10172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10014 = v10013[v10172];
        int v10173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v10183 = ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) * 2;
      int v10024 = v10023[v10183];
      int v10184 = (((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) * 2) + 1;
      int v10025 = v10023[v10184];
      int * v10026 = v9964->cache_vals;
      int v10186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10026[v10186] = v10024;
      int * v10028 = v9964->cache_vals;
      int v10189 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10028[v10189] = v10025;
      int * v10030 = v9964->cache_tags;
      int v10192 = (int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1);
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
    int v10205 = (((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10047[v10205] = v10048;
    int * v10051 = v9964->cache_vals;
    int v10208 = ((((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10051[v10208] = v10049;
    int * v10053 = v9964->cache_tags;
    int v10211 = ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10212 = (int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1);
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
  int v10223 = (v10069 * 2) + (((int)((unsigned int)v9968 >> 2)) & 1);
  v10070[v10223] = v9969;
  int * v10072 = v9964->cache_tags;
  int v10073 = v10072[v10142];
  int v10074 = v10072[v10143];
  bool v10226 = !(((~(((v10073 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v10073 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) | (~(((v10074 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v10074 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31))) == 0);
  int v10128;
  if (v10226) {
    int * v10075 = v9964->cache_age;
    int v10228 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((~(((v10074 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))) | (-(v10074 ^ ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1))))) >> 31)) & 1);
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
    int v10235 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2);
    int v10086 = v10085[v10235];
    int * v10087 = v9964->cache_tags;
    int v10088 = v10087[v10235];
    int v10089 = v10085[v10143];
    int v10090 = v10087[v10143];
    int * v10091 = v9964->cache_dirty;
    int v10238 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10092 = v10091[v10238];
    bool v10239 = !(v10092 == 0);
    if (v10239) {
      int * v10093 = v9964->cache_tags;
      int v10094 = v10093[v10238];
      int * v10095 = v9964->cache_vals;
      int v10242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10096 = v10095[v10242];
      int v10243 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v10253 = ((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) * 2;
    int v10106 = v10105[v10253];
    int v10254 = (((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) * 2) + 1;
    int v10107 = v10105[v10254];
    int * v10108 = v9964->cache_vals;
    int v10256 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10108[v10256] = v10106;
    int * v10110 = v9964->cache_vals;
    int v10259 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10110[v10259] = v10107;
    int * v10112 = v9964->cache_tags;
    int v10262 = (int)((unsigned int)((int)((unsigned int)v9968 >> 2)) >> 1);
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
  int v10273 = (v10128 * 2) + (((int)((unsigned int)v9968 >> 2)) & 1);
  v10129[v10273] = v9969;
  int * v10131 = v9964->cache_dirty;
  v10131[v10128] = 1;
  struct StateT * v10133 = slot_197(v9964);
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

struct StateT * slot_326(struct StateT * v20892) {
  int v20893 = v20892->timer;
  int v20901 = v20893 + 1;
  v20892->timer = v20901;
  int * v20895 = v20892->regs;
  int v20896 = v20895[21];
  int v20897 = v20895[24];
  int v20905 = v20896 | v20897;
  v20895[21] = v20905;
  struct StateT * v20899 = slot_327(v20892);
  return v20899;
}

struct StateT * slot_303(struct StateT * v20535) {
  int v20536 = v20535->timer;
  int v20544 = v20536 + 1;
  v20535->timer = v20544;
  int * v20538 = v20535->regs;
  int v20539 = v20538[20];
  int v20540 = v20538[24];
  int v20548 = v20539 | v20540;
  v20538[20] = v20548;
  struct StateT * v20542 = slot_304(v20535);
  return v20542;
}

struct StateT * slot_511(struct StateT * v23914) {
  int v23915 = v23914->timer;
  int v23923 = v23915 + 1;
  v23914->timer = v23923;
  int * v23917 = v23914->regs;
  int v23918 = v23917[22];
  int v23919 = v23917[24];
  int v23927 = v23918 | v23919;
  v23917[22] = v23927;
  struct StateT * v23921 = slot_512(v23914);
  return v23921;
}

struct StateT * slot_335(struct StateT * v21030) {
  int v21031 = v21030->timer;
  int v21039 = v21031 + 1;
  v21030->timer = v21039;
  int * v21033 = v21030->regs;
  int v21034 = v21033[15];
  int v21035 = v21033[22];
  int v21043 = v21034 ^ v21035;
  v21033[15] = v21043;
  struct StateT * v21037 = slot_336(v21030);
  return v21037;
}

struct StateT * slot_223(struct StateT * v14808) {
  int v14809 = v14808->timer;
  int v14979 = v14809 + 1;
  v14808->timer = v14979;
  int * v14811 = v14808->regs;
  int v14812 = v14811[10];
  int v14813 = v14811[6];
  int * v14814 = v14808->cache_tags;
  int v14984 = (((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2;
  int v14815 = v14814[v14984];
  int v14985 = ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14816 = v14814[v14985];
  int v14986 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2);
  int v14817 = v14814[v14986];
  int v14987 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14818 = v14814[v14987];
  int v14819 = v14808->timer;
  int v14988 = v14819 + ((100 ^ (((~(((v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14815 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14815 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14808->timer = v14988;
  bool v14989 = !(((~(((v14815 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14815 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v14913;
  if (v14989) {
    int * v14821 = v14808->cache_age;
    int v14991 = ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14816 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v14822 = v14821[v14991];
    int v14823 = v14821[v14984];
    int v14992 = v14823 + ((int)((unsigned int)(v14823 - v14822) >> 31));
    v14821[v14984] = v14992;
    int * v14825 = v14808->cache_age;
    int v14826 = v14825[v14985];
    int v14994 = v14826 + ((int)((unsigned int)(v14826 - v14822) >> 31));
    v14825[v14985] = v14994;
    int * v14828 = v14808->cache_age;
    v14828[v14991] = 0;
    v14913 = v14991;
  } else {
    int * v14831 = v14808->cache_age;
    int v14998 = (((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2;
    int v14832 = v14831[v14998];
    int * v14833 = v14808->cache_tags;
    int v14834 = v14833[v14998];
    int v14835 = v14831[v14985];
    int v14836 = v14833[v14985];
    bool v15000 = !(((~(((v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14817 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v14890;
    if (v15000) {
      int * v14837 = v14808->cache_age;
      int v15002 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14818 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v14838 = v14837[v15002];
      int v14839 = v14837[v14986];
      int v15003 = v14839 + ((int)((unsigned int)(v14839 - v14838) >> 31));
      v14837[v14986] = v15003;
      int * v14841 = v14808->cache_age;
      int v14842 = v14841[v14987];
      int v15005 = v14842 + ((int)((unsigned int)(v14842 - v14838) >> 31));
      v14841[v14987] = v15005;
      int * v14844 = v14808->cache_age;
      v14844[v15002] = 0;
      v14890 = v15002;
    } else {
      int * v14847 = v14808->cache_age;
      int v15009 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2);
      int v14848 = v14847[v15009];
      int * v14849 = v14808->cache_tags;
      int v14850 = v14849[v15009];
      int v14851 = v14847[v14987];
      int v14852 = v14849[v14987];
      int * v14853 = v14808->cache_dirty;
      int v15012 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14848 + ((~(((v14850 ^ -1) | (-(v14850 ^ -1))) >> 31)) & 2)) - (v14851 + ((~(((v14852 ^ -1) | (-(v14852 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14854 = v14853[v15012];
      bool v15013 = !(v14854 == 0);
      if (v15013) {
        int * v14855 = v14808->cache_tags;
        int v14856 = v14855[v15012];
        int * v14857 = v14808->cache_vals;
        int v15016 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14848 + ((~(((v14850 ^ -1) | (-(v14850 ^ -1))) >> 31)) & 2)) - (v14851 + ((~(((v14852 ^ -1) | (-(v14852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14858 = v14857[v15016];
        int v15017 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14848 + ((~(((v14850 ^ -1) | (-(v14850 ^ -1))) >> 31)) & 2)) - (v14851 + ((~(((v14852 ^ -1) | (-(v14852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14859 = v14857[v15017];
        int * v14860 = v14808->mem;
        int v15019 = v14856 * 2;
        v14860[v15019] = v14858;
        int * v14862 = v14808->mem;
        int v15022 = (v14856 * 2) + 1;
        v14862[v15022] = v14859;
        ;
      } else {
        ;
      }
      int * v14867 = v14808->mem;
      int v15027 = ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) * 2;
      int v14868 = v14867[v15027];
      int v15028 = (((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) * 2) + 1;
      int v14869 = v14867[v15028];
      int * v14870 = v14808->cache_vals;
      int v15030 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14848 + ((~(((v14850 ^ -1) | (-(v14850 ^ -1))) >> 31)) & 2)) - (v14851 + ((~(((v14852 ^ -1) | (-(v14852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14870[v15030] = v14868;
      int * v14872 = v14808->cache_vals;
      int v15033 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14848 + ((~(((v14850 ^ -1) | (-(v14850 ^ -1))) >> 31)) & 2)) - (v14851 + ((~(((v14852 ^ -1) | (-(v14852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14872[v15033] = v14869;
      int * v14874 = v14808->cache_tags;
      int v15036 = (int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1);
      v14874[v15012] = v15036;
      int * v14876 = v14808->cache_dirty;
      v14876[v15012] = 0;
      int * v14878 = v14808->cache_age;
      v14878[v15012] = 1;
      int * v14880 = v14808->cache_age;
      int v14881 = v14880[v15012];
      int v14882 = v14880[v14986];
      int v15042 = v14882 + ((int)((unsigned int)(v14882 - v14881) >> 31));
      v14880[v14986] = v15042;
      int * v14884 = v14808->cache_age;
      int v14885 = v14884[v14987];
      int v15044 = v14885 + ((int)((unsigned int)(v14885 - v14881) >> 31));
      v14884[v14987] = v15044;
      int * v14887 = v14808->cache_age;
      v14887[v15012] = 0;
      v14890 = v15012;
    }
    int * v14891 = v14808->cache_vals;
    int v15047 = v14890 * 2;
    int v14892 = v14891[v15047];
    int v15048 = (v14890 * 2) + 1;
    int v14893 = v14891[v15048];
    int v15049 = (((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14832 + ((~(((v14834 ^ -1) | (-(v14834 ^ -1))) >> 31)) & 2)) - (v14835 + ((~(((v14836 ^ -1) | (-(v14836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14891[v15049] = v14892;
    int * v14895 = v14808->cache_vals;
    int v15052 = ((((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14832 + ((~(((v14834 ^ -1) | (-(v14834 ^ -1))) >> 31)) & 2)) - (v14835 + ((~(((v14836 ^ -1) | (-(v14836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14895[v15052] = v14893;
    int * v14897 = v14808->cache_tags;
    int v15055 = ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14832 + ((~(((v14834 ^ -1) | (-(v14834 ^ -1))) >> 31)) & 2)) - (v14835 + ((~(((v14836 ^ -1) | (-(v14836 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15056 = (int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1);
    v14897[v15055] = v15056;
    int * v14899 = v14808->cache_dirty;
    v14899[v15055] = 0;
    int * v14901 = v14808->cache_age;
    v14901[v15055] = 1;
    int * v14903 = v14808->cache_age;
    int v14904 = v14903[v15055];
    int v14905 = v14903[v14984];
    int v15062 = v14905 + ((int)((unsigned int)(v14905 - v14904) >> 31));
    v14903[v14984] = v15062;
    int * v14907 = v14808->cache_age;
    int v14908 = v14907[v14985];
    int v15064 = v14908 + ((int)((unsigned int)(v14908 - v14904) >> 31));
    v14907[v14985] = v15064;
    int * v14910 = v14808->cache_age;
    v14910[v15055] = 0;
    v14913 = v15055;
  }
  int * v14914 = v14808->cache_vals;
  int v15067 = (v14913 * 2) + (((int)((unsigned int)(v14812 + 24) >> 2)) & 1);
  v14914[v15067] = v14813;
  int * v14916 = v14808->cache_tags;
  int v14917 = v14916[v14986];
  int v14918 = v14916[v14987];
  bool v15070 = !(((~(((v14917 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14917 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14918 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14918 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v14972;
  if (v15070) {
    int * v14919 = v14808->cache_age;
    int v15072 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14918 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))) | (-(v14918 ^ ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v14920 = v14919[v15072];
    int v14921 = v14919[v14986];
    int v15073 = v14921 + ((int)((unsigned int)(v14921 - v14920) >> 31));
    v14919[v14986] = v15073;
    int * v14923 = v14808->cache_age;
    int v14924 = v14923[v14987];
    int v15075 = v14924 + ((int)((unsigned int)(v14924 - v14920) >> 31));
    v14923[v14987] = v15075;
    int * v14926 = v14808->cache_age;
    v14926[v15072] = 0;
    v14972 = v15072;
  } else {
    int * v14929 = v14808->cache_age;
    int v15079 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2);
    int v14930 = v14929[v15079];
    int * v14931 = v14808->cache_tags;
    int v14932 = v14931[v15079];
    int v14933 = v14929[v14987];
    int v14934 = v14931[v14987];
    int * v14935 = v14808->cache_dirty;
    int v15082 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14930 + ((~(((v14932 ^ -1) | (-(v14932 ^ -1))) >> 31)) & 2)) - (v14933 + ((~(((v14934 ^ -1) | (-(v14934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14936 = v14935[v15082];
    bool v15083 = !(v14936 == 0);
    if (v15083) {
      int * v14937 = v14808->cache_tags;
      int v14938 = v14937[v15082];
      int * v14939 = v14808->cache_vals;
      int v15086 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14930 + ((~(((v14932 ^ -1) | (-(v14932 ^ -1))) >> 31)) & 2)) - (v14933 + ((~(((v14934 ^ -1) | (-(v14934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v14940 = v14939[v15086];
      int v15087 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14930 + ((~(((v14932 ^ -1) | (-(v14932 ^ -1))) >> 31)) & 2)) - (v14933 + ((~(((v14934 ^ -1) | (-(v14934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v14941 = v14939[v15087];
      int * v14942 = v14808->mem;
      int v15089 = v14938 * 2;
      v14942[v15089] = v14940;
      int * v14944 = v14808->mem;
      int v15092 = (v14938 * 2) + 1;
      v14944[v15092] = v14941;
      ;
    } else {
      ;
    }
    int * v14949 = v14808->mem;
    int v15097 = ((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) * 2;
    int v14950 = v14949[v15097];
    int v15098 = (((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) * 2) + 1;
    int v14951 = v14949[v15098];
    int * v14952 = v14808->cache_vals;
    int v15100 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14930 + ((~(((v14932 ^ -1) | (-(v14932 ^ -1))) >> 31)) & 2)) - (v14933 + ((~(((v14934 ^ -1) | (-(v14934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14952[v15100] = v14950;
    int * v14954 = v14808->cache_vals;
    int v15103 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14930 + ((~(((v14932 ^ -1) | (-(v14932 ^ -1))) >> 31)) & 2)) - (v14933 + ((~(((v14934 ^ -1) | (-(v14934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14954[v15103] = v14951;
    int * v14956 = v14808->cache_tags;
    int v15106 = (int)((unsigned int)((int)((unsigned int)(v14812 + 24) >> 2)) >> 1);
    v14956[v15082] = v15106;
    int * v14958 = v14808->cache_dirty;
    v14958[v15082] = 0;
    int * v14960 = v14808->cache_age;
    v14960[v15082] = 1;
    int * v14962 = v14808->cache_age;
    int v14963 = v14962[v15082];
    int v14964 = v14962[v14986];
    int v15112 = v14964 + ((int)((unsigned int)(v14964 - v14963) >> 31));
    v14962[v14986] = v15112;
    int * v14966 = v14808->cache_age;
    int v14967 = v14966[v14987];
    int v15114 = v14967 + ((int)((unsigned int)(v14967 - v14963) >> 31));
    v14966[v14987] = v15114;
    int * v14969 = v14808->cache_age;
    v14969[v15082] = 0;
    v14972 = v15082;
  }
  int * v14973 = v14808->cache_vals;
  int v15117 = (v14972 * 2) + (((int)((unsigned int)(v14812 + 24) >> 2)) & 1);
  v14973[v15117] = v14813;
  int * v14975 = v14808->cache_dirty;
  v14975[v14972] = 1;
  struct StateT * v14977 = slot_226(v14808);
  return v14977;
}

struct StateT * slot_316(struct StateT * v20734) {
  int v20735 = v20734->timer;
  int v20743 = v20735 + 1;
  v20734->timer = v20743;
  int * v20737 = v20734->regs;
  int v20738 = v20737[31];
  int v20739 = v20737[23];
  int v20747 = v20738 ^ v20739;
  v20737[31] = v20747;
  struct StateT * v20741 = slot_317(v20734);
  return v20741;
}

struct StateT * slot_424(struct StateT * v22478) {
  int v22479 = v22478->timer;
  int v22486 = v22479 + 1;
  v22478->timer = v22486;
  int * v22481 = v22478->regs;
  int v22482 = v22481[20];
  int v22489 = v22482 << 9;
  v22481[20] = v22489;
  struct StateT * v22484 = slot_425(v22478);
  return v22484;
}

struct StateT * slot_332(struct StateT * v20982) {
  int v20983 = v20982->timer;
  int v20991 = v20983 + 1;
  v20982->timer = v20991;
  int * v20985 = v20982->regs;
  int v20986 = v20985[23];
  int v20987 = v20985[24];
  int v20995 = v20986 | v20987;
  v20985[23] = v20995;
  struct StateT * v20989 = slot_333(v20982);
  return v20989;
}

struct StateT * slot_237(struct StateT * v18398) {
  int v18399 = v18398->timer;
  int v18509 = v18399 + 1;
  v18398->timer = v18509;
  int * v18401 = v18398->regs;
  int v18402 = v18401[2];
  int * v18403 = v18398->cache_tags;
  int v18513 = (((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2;
  int v18404 = v18403[v18513];
  int v18514 = ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18405 = v18403[v18514];
  int v18515 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2);
  int v18406 = v18403[v18515];
  int v18516 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18407 = v18403[v18516];
  int v18408 = v18398->timer;
  int v18517 = v18408 + ((100 ^ (((~(((v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18404 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18404 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18398->timer = v18517;
  int * v18410 = v18398->cache_vals;
  bool v18518 = !(((~(((v18404 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18404 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v18503;
  if (v18518) {
    int * v18411 = v18398->cache_age;
    int v18520 = ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18405 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v18412 = v18411[v18520];
    int v18413 = v18411[v18513];
    int v18521 = v18413 + ((int)((unsigned int)(v18413 - v18412) >> 31));
    v18411[v18513] = v18521;
    int * v18415 = v18398->cache_age;
    int v18416 = v18415[v18514];
    int v18523 = v18416 + ((int)((unsigned int)(v18416 - v18412) >> 31));
    v18415[v18514] = v18523;
    int * v18418 = v18398->cache_age;
    v18418[v18520] = 0;
    v18503 = v18520;
  } else {
    int * v18421 = v18398->cache_age;
    int v18527 = (((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2;
    int v18422 = v18421[v18527];
    int * v18423 = v18398->cache_tags;
    int v18424 = v18423[v18527];
    int v18425 = v18421[v18514];
    int v18426 = v18423[v18514];
    bool v18529 = !(((~(((v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18406 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v18480;
    if (v18529) {
      int * v18427 = v18398->cache_age;
      int v18531 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))) | (-(v18407 ^ ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v18428 = v18427[v18531];
      int v18429 = v18427[v18515];
      int v18532 = v18429 + ((int)((unsigned int)(v18429 - v18428) >> 31));
      v18427[v18515] = v18532;
      int * v18431 = v18398->cache_age;
      int v18432 = v18431[v18516];
      int v18534 = v18432 + ((int)((unsigned int)(v18432 - v18428) >> 31));
      v18431[v18516] = v18534;
      int * v18434 = v18398->cache_age;
      v18434[v18531] = 0;
      v18480 = v18531;
    } else {
      int * v18437 = v18398->cache_age;
      int v18538 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2);
      int v18438 = v18437[v18538];
      int * v18439 = v18398->cache_tags;
      int v18440 = v18439[v18538];
      int v18441 = v18437[v18516];
      int v18442 = v18439[v18516];
      int * v18443 = v18398->cache_dirty;
      int v18541 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v18438 + ((~(((v18440 ^ -1) | (-(v18440 ^ -1))) >> 31)) & 2)) - (v18441 + ((~(((v18442 ^ -1) | (-(v18442 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18444 = v18443[v18541];
      bool v18542 = !(v18444 == 0);
      if (v18542) {
        int * v18445 = v18398->cache_tags;
        int v18446 = v18445[v18541];
        int * v18447 = v18398->cache_vals;
        int v18545 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v18438 + ((~(((v18440 ^ -1) | (-(v18440 ^ -1))) >> 31)) & 2)) - (v18441 + ((~(((v18442 ^ -1) | (-(v18442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18448 = v18447[v18545];
        int v18546 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v18438 + ((~(((v18440 ^ -1) | (-(v18440 ^ -1))) >> 31)) & 2)) - (v18441 + ((~(((v18442 ^ -1) | (-(v18442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18449 = v18447[v18546];
        int * v18450 = v18398->mem;
        int v18548 = v18446 * 2;
        v18450[v18548] = v18448;
        int * v18452 = v18398->mem;
        int v18551 = (v18446 * 2) + 1;
        v18452[v18551] = v18449;
        ;
      } else {
        ;
      }
      int * v18457 = v18398->mem;
      int v18556 = ((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) * 2;
      int v18458 = v18457[v18556];
      int v18557 = (((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) * 2) + 1;
      int v18459 = v18457[v18557];
      int * v18460 = v18398->cache_vals;
      int v18559 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v18438 + ((~(((v18440 ^ -1) | (-(v18440 ^ -1))) >> 31)) & 2)) - (v18441 + ((~(((v18442 ^ -1) | (-(v18442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18460[v18559] = v18458;
      int * v18462 = v18398->cache_vals;
      int v18562 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v18438 + ((~(((v18440 ^ -1) | (-(v18440 ^ -1))) >> 31)) & 2)) - (v18441 + ((~(((v18442 ^ -1) | (-(v18442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18462[v18562] = v18459;
      int * v18464 = v18398->cache_tags;
      int v18565 = (int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1);
      v18464[v18541] = v18565;
      int * v18466 = v18398->cache_dirty;
      v18466[v18541] = 0;
      int * v18468 = v18398->cache_age;
      v18468[v18541] = 1;
      int * v18470 = v18398->cache_age;
      int v18471 = v18470[v18541];
      int v18472 = v18470[v18515];
      int v18571 = v18472 + ((int)((unsigned int)(v18472 - v18471) >> 31));
      v18470[v18515] = v18571;
      int * v18474 = v18398->cache_age;
      int v18475 = v18474[v18516];
      int v18573 = v18475 + ((int)((unsigned int)(v18475 - v18471) >> 31));
      v18474[v18516] = v18573;
      int * v18477 = v18398->cache_age;
      v18477[v18541] = 0;
      v18480 = v18541;
    }
    int * v18481 = v18398->cache_vals;
    int v18576 = v18480 * 2;
    int v18482 = v18481[v18576];
    int v18577 = (v18480 * 2) + 1;
    int v18483 = v18481[v18577];
    int v18578 = (((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v18422 + ((~(((v18424 ^ -1) | (-(v18424 ^ -1))) >> 31)) & 2)) - (v18425 + ((~(((v18426 ^ -1) | (-(v18426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18481[v18578] = v18482;
    int * v18485 = v18398->cache_vals;
    int v18581 = ((((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v18422 + ((~(((v18424 ^ -1) | (-(v18424 ^ -1))) >> 31)) & 2)) - (v18425 + ((~(((v18426 ^ -1) | (-(v18426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18485[v18581] = v18483;
    int * v18487 = v18398->cache_tags;
    int v18584 = ((((int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v18422 + ((~(((v18424 ^ -1) | (-(v18424 ^ -1))) >> 31)) & 2)) - (v18425 + ((~(((v18426 ^ -1) | (-(v18426 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18585 = (int)((unsigned int)((int)((unsigned int)(v18402 + 12) >> 2)) >> 1);
    v18487[v18584] = v18585;
    int * v18489 = v18398->cache_dirty;
    v18489[v18584] = 0;
    int * v18491 = v18398->cache_age;
    v18491[v18584] = 1;
    int * v18493 = v18398->cache_age;
    int v18494 = v18493[v18584];
    int v18495 = v18493[v18513];
    int v18591 = v18495 + ((int)((unsigned int)(v18495 - v18494) >> 31));
    v18493[v18513] = v18591;
    int * v18497 = v18398->cache_age;
    int v18498 = v18497[v18514];
    int v18593 = v18498 + ((int)((unsigned int)(v18498 - v18494) >> 31));
    v18497[v18514] = v18593;
    int * v18500 = v18398->cache_age;
    v18500[v18584] = 0;
    v18503 = v18584;
  }
  int v18596 = (v18503 * 2) + (((int)((unsigned int)(v18402 + 12) >> 2)) & 1);
  int v18504 = v18410[v18596];
  int * v18505 = v18398->regs;
  v18505[24] = v18504;
  struct StateT * v18507 = slot_240(v18398);
  return v18507;
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

struct StateT * slot_508(struct StateT * v23869) {
  int v23870 = v23869->timer;
  int v23878 = v23870 + 1;
  v23869->timer = v23878;
  int * v23872 = v23869->regs;
  int v23873 = v23872[21];
  int v23874 = v23872[24];
  int v23882 = v23873 | v23874;
  v23872[21] = v23882;
  struct StateT * v23876 = slot_509(v23869);
  return v23876;
}

struct StateT * slot_537(struct StateT * v24319) {
  int v24320 = v24319->timer;
  int v24328 = v24320 + 1;
  v24319->timer = v24328;
  int * v24322 = v24319->regs;
  int v24323 = v24322[18];
  int v24324 = v24322[22];
  int v24332 = v24323 ^ v24324;
  v24322[18] = v24332;
  struct StateT * v24326 = slot_538(v24319);
  return v24326;
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

struct StateT * slot_289(struct StateT * v20313) {
  int v20314 = v20313->timer;
  int v20322 = v20314 + 1;
  v20313->timer = v20322;
  int * v20316 = v20313->regs;
  int v20317 = v20316[22];
  int v20318 = v20316[24];
  int v20326 = v20317 | v20318;
  v20316[22] = v20326;
  struct StateT * v20320 = slot_290(v20313);
  return v20320;
}

struct StateT * slot_238(struct StateT * v18602) {
  int v18603 = v18602->timer;
  int v18610 = v18603 + 1;
  v18602->timer = v18610;
  int * v18605 = v18602->regs;
  int v18606 = v18605[22];
  int v18614 = (int)((unsigned int)v18606 >> 25);
  v18605[24] = v18614;
  struct StateT * v18608 = slot_241(v18602);
  return v18608;
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

struct StateT * slot_256(struct StateT * v19798) {
  int v19799 = v19798->timer;
  int v19807 = v19799 + 1;
  v19798->timer = v19807;
  int * v19801 = v19798->regs;
  int v19802 = v19801[8];
  int v19803 = v19801[23];
  int v19811 = v19802 ^ v19803;
  v19801[8] = v19811;
  struct StateT * v19805 = slot_257(v19798);
  return v19805;
}

struct StateT * slot_544(struct StateT * v24434) {
  int v24435 = v24434->timer;
  int v24442 = v24435 + 1;
  v24434->timer = v24442;
  int * v24437 = v24434->regs;
  int v24438 = v24437[20];
  int v24445 = v24438 << 18;
  v24437[20] = v24445;
  struct StateT * v24440 = slot_545(v24434);
  return v24440;
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

struct StateT * slot_302(struct StateT * v20521) {
  int v20522 = v20521->timer;
  int v20529 = v20522 + 1;
  v20521->timer = v20529;
  int * v20524 = v20521->regs;
  int v20525 = v20524[20];
  int v20532 = v20525 << 18;
  v20524[20] = v20532;
  struct StateT * v20527 = slot_303(v20521);
  return v20527;
}

struct StateT * slot_388(struct StateT * v21859) {
  int v21860 = v21859->timer;
  int v21867 = v21860 + 1;
  v21859->timer = v21867;
  int * v21862 = v21859->regs;
  int v21863 = v21862[22];
  int v21870 = v21863 << 18;
  v21862[22] = v21870;
  struct StateT * v21865 = slot_389(v21859);
  return v21865;
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

struct StateT * slot_487(struct StateT * v23543) {
  int v23544 = v23543->timer;
  int v23551 = v23544 + 1;
  v23543->timer = v23551;
  int * v23546 = v23543->regs;
  int v23547 = v23546[21];
  int v23554 = v23547 << 7;
  v23546[21] = v23554;
  struct StateT * v23549 = slot_488(v23543);
  return v23549;
}

struct StateT * slot_324(struct StateT * v20863) {
  int v20864 = v20863->timer;
  int v20871 = v20864 + 1;
  v20863->timer = v20871;
  int * v20866 = v20863->regs;
  int v20867 = v20866[21];
  int v20875 = (int)((unsigned int)v20867 >> 25);
  v20866[24] = v20875;
  struct StateT * v20869 = slot_325(v20863);
  return v20869;
}

struct StateT * slot_440(struct StateT * v22752) {
  int v22753 = v22752->timer;
  int v22761 = v22753 + 1;
  v22752->timer = v22761;
  int * v22755 = v22752->regs;
  int v22756 = v22755[7];
  int v22757 = v22755[18];
  int v22766 = v22756 + v22757;
  v22755[21] = v22766;
  struct StateT * v22759 = slot_441(v22752);
  return v22759;
}

struct StateT * slot_547(struct StateT * v24479) {
  int v24480 = v24479->timer;
  int v24487 = v24480 + 1;
  v24479->timer = v24487;
  int * v24482 = v24479->regs;
  int v24483 = v24482[21];
  int v24490 = v24483 << 18;
  v24482[21] = v24490;
  struct StateT * v24485 = slot_548(v24479);
  return v24485;
}

struct StateT * slot_518(struct StateT * v24023) {
  int v24024 = v24023->timer;
  int v24032 = v24024 + 1;
  v24023->timer = v24032;
  int * v24026 = v24023->regs;
  int v24027 = v24026[7];
  int v24028 = v24026[23];
  int v24036 = v24027 ^ v24028;
  v24026[7] = v24036;
  struct StateT * v24030 = slot_519(v24023);
  return v24030;
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

struct StateT * slot_451(struct StateT * v22922) {
  int v22923 = v22922->timer;
  int v22931 = v22923 + 1;
  v22922->timer = v22931;
  int * v22925 = v22922->regs;
  int v22926 = v22925[22];
  int v22927 = v22925[24];
  int v22935 = v22926 | v22927;
  v22925[22] = v22935;
  struct StateT * v22929 = slot_452(v22922);
  return v22929;
}

struct StateT * slot_458(struct StateT * v23052) {
  int * v23053 = v23052->saved_regs;
  int * v23054 = v23052->regs;
  int v23055 = v23054[15];
  v23053[15] = v23055;
  int v23057 = v23052->timer;
  int v23069 = v23057 + 1;
  v23052->timer = v23069;
  int * v23059 = v23052->regs;
  int v23060 = v23059[15];
  int v23061 = v23059[23];
  int v23072 = v23060 ^ v23061;
  v23059[15] = v23072;
  struct StateT * v23063 = slot_459(v23052);
  return v23063;
}

struct StateT * slot_415(struct StateT * v22303) {
  int * v22304 = v22303->saved_regs;
  int * v22305 = v22303->regs;
  int v22306 = v22305[9];
  v22304[9] = v22306;
  int v22308 = v22303->timer;
  int v22320 = v22308 + 1;
  v22303->timer = v22320;
  int * v22310 = v22303->regs;
  int v22311 = v22310[9];
  int v22312 = v22310[20];
  int v22323 = v22311 ^ v22312;
  v22310[9] = v22323;
  struct StateT * v22314 = slot_416(v22303);
  return v22314;
}

struct StateT * slot_354(struct StateT * v21326) {
  int v21327 = v21326->timer;
  int v21335 = v21327 + 1;
  v21326->timer = v21335;
  int * v21329 = v21326->regs;
  int v21330 = v21329[5];
  int v21331 = v21329[21];
  int v21339 = v21330 ^ v21331;
  v21329[5] = v21339;
  struct StateT * v21333 = slot_355(v21326);
  return v21333;
}

struct StateT * slot_531(struct StateT * v24226) {
  int v24227 = v24226->timer;
  int v24235 = v24227 + 1;
  v24226->timer = v24235;
  int * v24229 = v24226->regs;
  int v24230 = v24229[22];
  int v24231 = v24229[24];
  int v24239 = v24230 | v24231;
  v24229[22] = v24239;
  struct StateT * v24233 = slot_532(v24226);
  return v24233;
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

struct StateT * slot_321(struct StateT * v20818) {
  int v20819 = v20818->timer;
  int v20826 = v20819 + 1;
  v20818->timer = v20826;
  int * v20821 = v20818->regs;
  int v20822 = v20821[20];
  int v20830 = (int)((unsigned int)v20822 >> 25);
  v20821[24] = v20830;
  struct StateT * v20824 = slot_322(v20818);
  return v20824;
}

struct StateT * slot_317(struct StateT * v20750) {
  int v20751 = v20750->timer;
  int v20759 = v20751 + 1;
  v20750->timer = v20759;
  int * v20753 = v20750->regs;
  int v20754 = v20753[30];
  int v20755 = v20753[8];
  int v20764 = v20754 + v20755;
  v20753[20] = v20764;
  struct StateT * v20757 = slot_318(v20750);
  return v20757;
}

struct StateT * slot_558(struct StateT * v24647) {
  int v24648 = v24647->timer;
  int v24656 = v24648 + 1;
  v24647->timer = v24656;
  int * v24650 = v24647->regs;
  int v24651 = v24650[31];
  int v24652 = v24650[23];
  int v24660 = v24651 ^ v24652;
  v24650[31] = v24660;
  struct StateT * v24654 = slot_559(v24647);
  return v24654;
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

struct StateT * slot_554(struct StateT * v24583) {
  int v24584 = v24583->timer;
  int v24592 = v24584 + 1;
  v24583->timer = v24592;
  int * v24586 = v24583->regs;
  int v24587 = v24586[23];
  int v24588 = v24586[24];
  int v24596 = v24587 | v24588;
  v24586[23] = v24596;
  struct StateT * v24590 = slot_555(v24583);
  return v24590;
}

struct StateT * slot_375(struct StateT * v21654) {
  int v21655 = v21654->timer;
  int v21663 = v21655 + 1;
  v21654->timer = v21663;
  int * v21657 = v21654->regs;
  int v21658 = v21657[18];
  int v21659 = v21657[22];
  int v21667 = v21658 ^ v21659;
  v21657[18] = v21667;
  struct StateT * v21661 = slot_376(v21654);
  return v21661;
}

struct StateT * slot_331(struct StateT * v20968) {
  int v20969 = v20968->timer;
  int v20976 = v20969 + 1;
  v20968->timer = v20976;
  int * v20971 = v20968->regs;
  int v20972 = v20971[23];
  int v20979 = v20972 << 7;
  v20971[23] = v20979;
  struct StateT * v20974 = slot_332(v20968);
  return v20974;
}

struct StateT * slot_380(struct StateT * v21737) {
  int v21738 = v21737->timer;
  int v21746 = v21738 + 1;
  v21737->timer = v21746;
  int * v21740 = v21737->regs;
  int v21741 = v21740[19];
  int v21742 = v21740[7];
  int v21751 = v21741 + v21742;
  v21740[23] = v21751;
  struct StateT * v21744 = slot_381(v21737);
  return v21744;
}

struct StateT * slot_412(struct StateT * v22258) {
  int v22259 = v22258->timer;
  int v22266 = v22259 + 1;
  v22258->timer = v22266;
  int * v22261 = v22258->regs;
  int v22262 = v22261[23];
  int v22270 = (int)((unsigned int)v22262 >> 25);
  v22261[24] = v22270;
  struct StateT * v22264 = slot_413(v22258);
  return v22264;
}

struct StateT * slot_381(struct StateT * v21754) {
  int v21755 = v21754->timer;
  int v21762 = v21755 + 1;
  v21754->timer = v21762;
  int * v21757 = v21754->regs;
  int v21758 = v21757[20];
  int v21766 = (int)((unsigned int)v21758 >> 14);
  v21757[24] = v21766;
  struct StateT * v21760 = slot_382(v21754);
  return v21760;
}

struct StateT * slot_478(struct StateT * v23392) {
  int * v23393 = v23392->saved_regs;
  int * v23394 = v23392->regs;
  int v23395 = v23394[31];
  v23393[31] = v23395;
  int v23397 = v23392->timer;
  int v23409 = v23397 + 1;
  v23392->timer = v23409;
  int * v23399 = v23392->regs;
  int v23400 = v23399[31];
  int v23401 = v23399[23];
  int v23412 = v23400 ^ v23401;
  v23399[31] = v23412;
  struct StateT * v23403 = slot_479(v23392);
  return v23403;
}

struct StateT * slot_210(struct StateT * v11905) {
  int v11906 = v11905->timer;
  int v12076 = v11906 + 1;
  v11905->timer = v12076;
  int * v11908 = v11905->regs;
  int v11909 = v11908[10];
  int v11910 = v11908[31];
  int * v11911 = v11905->cache_tags;
  int v12081 = (((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2;
  int v11912 = v11911[v12081];
  int v12082 = ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11913 = v11911[v12082];
  int v12083 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2);
  int v11914 = v11911[v12083];
  int v12084 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11915 = v11911[v12084];
  int v11916 = v11905->timer;
  int v12085 = v11916 + ((100 ^ (((~(((v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11905->timer = v12085;
  bool v12086 = !(((~(((v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v12010;
  if (v12086) {
    int * v11918 = v11905->cache_age;
    int v12088 = ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v11919 = v11918[v12088];
    int v11920 = v11918[v12081];
    int v12089 = v11920 + ((int)((unsigned int)(v11920 - v11919) >> 31));
    v11918[v12081] = v12089;
    int * v11922 = v11905->cache_age;
    int v11923 = v11922[v12082];
    int v12091 = v11923 + ((int)((unsigned int)(v11923 - v11919) >> 31));
    v11922[v12082] = v12091;
    int * v11925 = v11905->cache_age;
    v11925[v12088] = 0;
    v12010 = v12088;
  } else {
    int * v11928 = v11905->cache_age;
    int v12095 = (((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2;
    int v11929 = v11928[v12095];
    int * v11930 = v11905->cache_tags;
    int v11931 = v11930[v12095];
    int v11932 = v11928[v12082];
    int v11933 = v11930[v12082];
    bool v12097 = !(((~(((v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11914 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v11987;
    if (v12097) {
      int * v11934 = v11905->cache_age;
      int v12099 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v11915 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v11935 = v11934[v12099];
      int v11936 = v11934[v12083];
      int v12100 = v11936 + ((int)((unsigned int)(v11936 - v11935) >> 31));
      v11934[v12083] = v12100;
      int * v11938 = v11905->cache_age;
      int v11939 = v11938[v12084];
      int v12102 = v11939 + ((int)((unsigned int)(v11939 - v11935) >> 31));
      v11938[v12084] = v12102;
      int * v11941 = v11905->cache_age;
      v11941[v12099] = 0;
      v11987 = v12099;
    } else {
      int * v11944 = v11905->cache_age;
      int v12106 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2);
      int v11945 = v11944[v12106];
      int * v11946 = v11905->cache_tags;
      int v11947 = v11946[v12106];
      int v11948 = v11944[v12084];
      int v11949 = v11946[v12084];
      int * v11950 = v11905->cache_dirty;
      int v12109 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11945 + ((~(((v11947 ^ -1) | (-(v11947 ^ -1))) >> 31)) & 2)) - (v11948 + ((~(((v11949 ^ -1) | (-(v11949 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11951 = v11950[v12109];
      bool v12110 = !(v11951 == 0);
      if (v12110) {
        int * v11952 = v11905->cache_tags;
        int v11953 = v11952[v12109];
        int * v11954 = v11905->cache_vals;
        int v12113 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11945 + ((~(((v11947 ^ -1) | (-(v11947 ^ -1))) >> 31)) & 2)) - (v11948 + ((~(((v11949 ^ -1) | (-(v11949 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11955 = v11954[v12113];
        int v12114 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11945 + ((~(((v11947 ^ -1) | (-(v11947 ^ -1))) >> 31)) & 2)) - (v11948 + ((~(((v11949 ^ -1) | (-(v11949 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11956 = v11954[v12114];
        int * v11957 = v11905->mem;
        int v12116 = v11953 * 2;
        v11957[v12116] = v11955;
        int * v11959 = v11905->mem;
        int v12119 = (v11953 * 2) + 1;
        v11959[v12119] = v11956;
        ;
      } else {
        ;
      }
      int * v11964 = v11905->mem;
      int v12124 = ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) * 2;
      int v11965 = v11964[v12124];
      int v12125 = (((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) * 2) + 1;
      int v11966 = v11964[v12125];
      int * v11967 = v11905->cache_vals;
      int v12127 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11945 + ((~(((v11947 ^ -1) | (-(v11947 ^ -1))) >> 31)) & 2)) - (v11948 + ((~(((v11949 ^ -1) | (-(v11949 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11967[v12127] = v11965;
      int * v11969 = v11905->cache_vals;
      int v12130 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11945 + ((~(((v11947 ^ -1) | (-(v11947 ^ -1))) >> 31)) & 2)) - (v11948 + ((~(((v11949 ^ -1) | (-(v11949 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11969[v12130] = v11966;
      int * v11971 = v11905->cache_tags;
      int v12133 = (int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1);
      v11971[v12109] = v12133;
      int * v11973 = v11905->cache_dirty;
      v11973[v12109] = 0;
      int * v11975 = v11905->cache_age;
      v11975[v12109] = 1;
      int * v11977 = v11905->cache_age;
      int v11978 = v11977[v12109];
      int v11979 = v11977[v12083];
      int v12139 = v11979 + ((int)((unsigned int)(v11979 - v11978) >> 31));
      v11977[v12083] = v12139;
      int * v11981 = v11905->cache_age;
      int v11982 = v11981[v12084];
      int v12141 = v11982 + ((int)((unsigned int)(v11982 - v11978) >> 31));
      v11981[v12084] = v12141;
      int * v11984 = v11905->cache_age;
      v11984[v12109] = 0;
      v11987 = v12109;
    }
    int * v11988 = v11905->cache_vals;
    int v12144 = v11987 * 2;
    int v11989 = v11988[v12144];
    int v12145 = (v11987 * 2) + 1;
    int v11990 = v11988[v12145];
    int v12146 = (((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11929 + ((~(((v11931 ^ -1) | (-(v11931 ^ -1))) >> 31)) & 2)) - (v11932 + ((~(((v11933 ^ -1) | (-(v11933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11988[v12146] = v11989;
    int * v11992 = v11905->cache_vals;
    int v12149 = ((((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11929 + ((~(((v11931 ^ -1) | (-(v11931 ^ -1))) >> 31)) & 2)) - (v11932 + ((~(((v11933 ^ -1) | (-(v11933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11992[v12149] = v11990;
    int * v11994 = v11905->cache_tags;
    int v12152 = ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11929 + ((~(((v11931 ^ -1) | (-(v11931 ^ -1))) >> 31)) & 2)) - (v11932 + ((~(((v11933 ^ -1) | (-(v11933 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12153 = (int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1);
    v11994[v12152] = v12153;
    int * v11996 = v11905->cache_dirty;
    v11996[v12152] = 0;
    int * v11998 = v11905->cache_age;
    v11998[v12152] = 1;
    int * v12000 = v11905->cache_age;
    int v12001 = v12000[v12152];
    int v12002 = v12000[v12081];
    int v12159 = v12002 + ((int)((unsigned int)(v12002 - v12001) >> 31));
    v12000[v12081] = v12159;
    int * v12004 = v11905->cache_age;
    int v12005 = v12004[v12082];
    int v12161 = v12005 + ((int)((unsigned int)(v12005 - v12001) >> 31));
    v12004[v12082] = v12161;
    int * v12007 = v11905->cache_age;
    v12007[v12152] = 0;
    v12010 = v12152;
  }
  int * v12011 = v11905->cache_vals;
  int v12164 = (v12010 * 2) + (((int)((unsigned int)(v11909 + 12) >> 2)) & 1);
  v12011[v12164] = v11910;
  int * v12013 = v11905->cache_tags;
  int v12014 = v12013[v12083];
  int v12015 = v12013[v12084];
  bool v12167 = !(((~(((v12014 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v12014 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12015 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v12015 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v12069;
  if (v12167) {
    int * v12016 = v11905->cache_age;
    int v12169 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12015 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))) | (-(v12015 ^ ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v12017 = v12016[v12169];
    int v12018 = v12016[v12083];
    int v12170 = v12018 + ((int)((unsigned int)(v12018 - v12017) >> 31));
    v12016[v12083] = v12170;
    int * v12020 = v11905->cache_age;
    int v12021 = v12020[v12084];
    int v12172 = v12021 + ((int)((unsigned int)(v12021 - v12017) >> 31));
    v12020[v12084] = v12172;
    int * v12023 = v11905->cache_age;
    v12023[v12169] = 0;
    v12069 = v12169;
  } else {
    int * v12026 = v11905->cache_age;
    int v12176 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2);
    int v12027 = v12026[v12176];
    int * v12028 = v11905->cache_tags;
    int v12029 = v12028[v12176];
    int v12030 = v12026[v12084];
    int v12031 = v12028[v12084];
    int * v12032 = v11905->cache_dirty;
    int v12179 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12027 + ((~(((v12029 ^ -1) | (-(v12029 ^ -1))) >> 31)) & 2)) - (v12030 + ((~(((v12031 ^ -1) | (-(v12031 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12033 = v12032[v12179];
    bool v12180 = !(v12033 == 0);
    if (v12180) {
      int * v12034 = v11905->cache_tags;
      int v12035 = v12034[v12179];
      int * v12036 = v11905->cache_vals;
      int v12183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12027 + ((~(((v12029 ^ -1) | (-(v12029 ^ -1))) >> 31)) & 2)) - (v12030 + ((~(((v12031 ^ -1) | (-(v12031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12037 = v12036[v12183];
      int v12184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12027 + ((~(((v12029 ^ -1) | (-(v12029 ^ -1))) >> 31)) & 2)) - (v12030 + ((~(((v12031 ^ -1) | (-(v12031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12038 = v12036[v12184];
      int * v12039 = v11905->mem;
      int v12186 = v12035 * 2;
      v12039[v12186] = v12037;
      int * v12041 = v11905->mem;
      int v12189 = (v12035 * 2) + 1;
      v12041[v12189] = v12038;
      ;
    } else {
      ;
    }
    int * v12046 = v11905->mem;
    int v12194 = ((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) * 2;
    int v12047 = v12046[v12194];
    int v12195 = (((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) * 2) + 1;
    int v12048 = v12046[v12195];
    int * v12049 = v11905->cache_vals;
    int v12197 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12027 + ((~(((v12029 ^ -1) | (-(v12029 ^ -1))) >> 31)) & 2)) - (v12030 + ((~(((v12031 ^ -1) | (-(v12031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12049[v12197] = v12047;
    int * v12051 = v11905->cache_vals;
    int v12200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12027 + ((~(((v12029 ^ -1) | (-(v12029 ^ -1))) >> 31)) & 2)) - (v12030 + ((~(((v12031 ^ -1) | (-(v12031 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12051[v12200] = v12048;
    int * v12053 = v11905->cache_tags;
    int v12203 = (int)((unsigned int)((int)((unsigned int)(v11909 + 12) >> 2)) >> 1);
    v12053[v12179] = v12203;
    int * v12055 = v11905->cache_dirty;
    v12055[v12179] = 0;
    int * v12057 = v11905->cache_age;
    v12057[v12179] = 1;
    int * v12059 = v11905->cache_age;
    int v12060 = v12059[v12179];
    int v12061 = v12059[v12083];
    int v12209 = v12061 + ((int)((unsigned int)(v12061 - v12060) >> 31));
    v12059[v12083] = v12209;
    int * v12063 = v11905->cache_age;
    int v12064 = v12063[v12084];
    int v12211 = v12064 + ((int)((unsigned int)(v12064 - v12060) >> 31));
    v12063[v12084] = v12211;
    int * v12066 = v11905->cache_age;
    v12066[v12179] = 0;
    v12069 = v12179;
  }
  int * v12070 = v11905->cache_vals;
  int v12214 = (v12069 * 2) + (((int)((unsigned int)(v11909 + 12) >> 2)) & 1);
  v12070[v12214] = v11910;
  int * v12072 = v11905->cache_dirty;
  v12072[v12069] = 1;
  struct StateT * v12074 = slot_213(v11905);
  return v12074;
}

struct StateT * slot_472(struct StateT * v23278) {
  int v23279 = v23278->timer;
  int v23286 = v23279 + 1;
  v23278->timer = v23286;
  int * v23281 = v23278->regs;
  int v23282 = v23281[23];
  int v23290 = (int)((unsigned int)v23282 >> 14);
  v23281[24] = v23290;
  struct StateT * v23284 = slot_473(v23278);
  return v23284;
}

struct StateT * slot_284(struct StateT * v20239) {
  int v20240 = v20239->timer;
  int v20247 = v20240 + 1;
  v20239->timer = v20247;
  int * v20242 = v20239->regs;
  int v20243 = v20242[21];
  int v20251 = (int)((unsigned int)v20243 >> 19);
  v20242[24] = v20251;
  struct StateT * v20245 = slot_285(v20239);
  return v20245;
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

struct StateT * slot_209(struct StateT * v11888) {
  int v11889 = v11888->timer;
  int v11897 = v11889 + 1;
  v11888->timer = v11897;
  int * v11891 = v11888->regs;
  int v11892 = v11891[31];
  int v11893 = v11891[15];
  int v11902 = v11892 + v11893;
  v11891[23] = v11902;
  struct StateT * v11895 = slot_212(v11888);
  return v11895;
}

struct StateT * slot_420(struct StateT * v22412) {
  int v22413 = v22412->timer;
  int v22421 = v22413 + 1;
  v22412->timer = v22421;
  int * v22415 = v22412->regs;
  int v22416 = v22415[18];
  int v22417 = v22415[29];
  int v22426 = v22416 + v22417;
  v22415[21] = v22426;
  struct StateT * v22419 = slot_421(v22412);
  return v22419;
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

struct StateT * slot_270(struct StateT * v20017) {
  int v20018 = v20017->timer;
  int v20025 = v20018 + 1;
  v20017->timer = v20025;
  int * v20020 = v20017->regs;
  int v20021 = v20020[23];
  int v20029 = (int)((unsigned int)v20021 >> 23);
  v20020[24] = v20029;
  struct StateT * v20023 = slot_271(v20017);
  return v20023;
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
    struct StateT * v9618 = slot_201(v9610);
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

struct StateT * slot_446(struct StateT * v22848) {
  int v22849 = v22848->timer;
  int v22856 = v22849 + 1;
  v22848->timer = v22856;
  int * v22851 = v22848->regs;
  int v22852 = v22851[21];
  int v22860 = (int)((unsigned int)v22852 >> 19);
  v22851[24] = v22860;
  struct StateT * v22854 = slot_447(v22848);
  return v22854;
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

struct StateT * slot_361(struct StateT * v21442) {
  int v21443 = v21442->timer;
  int v21450 = v21443 + 1;
  v21442->timer = v21450;
  int * v21445 = v21442->regs;
  int v21446 = v21445[20];
  int v21454 = (int)((unsigned int)v21446 >> 19);
  v21445[24] = v21454;
  struct StateT * v21448 = slot_362(v21442);
  return v21448;
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

struct StateT * slot_510(struct StateT * v23900) {
  int v23901 = v23900->timer;
  int v23908 = v23901 + 1;
  v23900->timer = v23908;
  int * v23903 = v23900->regs;
  int v23904 = v23903[22];
  int v23911 = v23904 << 9;
  v23903[22] = v23911;
  struct StateT * v23906 = slot_511(v23900);
  return v23906;
}

struct StateT * slot_459(struct StateT * v23075) {
  int v23076 = v23075->timer;
  int v23084 = v23076 + 1;
  v23075->timer = v23084;
  int * v23078 = v23075->regs;
  int v23079 = v23078[16];
  int v23080 = v23078[6];
  int v23089 = v23079 + v23080;
  v23078[20] = v23089;
  struct StateT * v23082 = slot_460(v23075);
  return v23082;
}

struct StateT * slot_404(struct StateT * v22138) {
  int v22139 = v22138->timer;
  int v22146 = v22139 + 1;
  v22138->timer = v22146;
  int * v22141 = v22138->regs;
  int v22142 = v22141[20];
  int v22149 = v22142 << 7;
  v22141[20] = v22149;
  struct StateT * v22144 = slot_405(v22138);
  return v22144;
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

struct StateT * slot_212(struct StateT * v12535) {
  int v12536 = v12535->timer;
  int v12543 = v12536 + 1;
  v12535->timer = v12543;
  int * v12538 = v12535->regs;
  int v12539 = v12538[20];
  int v12547 = (int)((unsigned int)v12539 >> 25);
  v12538[24] = v12547;
  struct StateT * v12541 = slot_215(v12535);
  return v12541;
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

struct StateT * slot_313(struct StateT * v20686) {
  int v20687 = v20686->timer;
  int v20695 = v20687 + 1;
  v20686->timer = v20695;
  int * v20689 = v20686->regs;
  int v20690 = v20689[30];
  int v20691 = v20689[20];
  int v20699 = v20690 ^ v20691;
  v20689[30] = v20699;
  struct StateT * v20693 = slot_314(v20686);
  return v20693;
}

struct StateT * slot_553(struct StateT * v24569) {
  int v24570 = v24569->timer;
  int v24577 = v24570 + 1;
  v24569->timer = v24577;
  int * v24572 = v24569->regs;
  int v24573 = v24572[23];
  int v24580 = v24573 << 18;
  v24572[23] = v24580;
  struct StateT * v24575 = slot_554(v24569);
  return v24575;
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

struct StateT * slot_436(struct StateT * v22666) {
  int * v22667 = v22666->saved_regs;
  int * v22668 = v22666->regs;
  int v22669 = v22668[7];
  v22667[7] = v22669;
  int v22671 = v22666->timer;
  int v22683 = v22671 + 1;
  v22666->timer = v22683;
  int * v22673 = v22666->regs;
  int v22674 = v22673[7];
  int v22675 = v22673[21];
  int v22686 = v22674 ^ v22675;
  v22673[7] = v22686;
  struct StateT * v22677 = slot_437(v22666);
  return v22677;
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

struct StateT * slot_499(struct StateT * v23727) {
  int v23728 = v23727->timer;
  int v23736 = v23728 + 1;
  v23727->timer = v23736;
  int * v23730 = v23727->regs;
  int v23731 = v23730[14];
  int v23732 = v23730[30];
  int v23741 = v23731 + v23732;
  v23730[20] = v23741;
  struct StateT * v23734 = slot_500(v23727);
  return v23734;
}

struct StateT * slot_359(struct StateT * v21408) {
  int v21409 = v21408->timer;
  int v21417 = v21409 + 1;
  v21408->timer = v21417;
  int * v21411 = v21408->regs;
  int v21412 = v21411[6];
  int v21413 = v21411[15];
  int v21422 = v21412 + v21413;
  v21411[22] = v21422;
  struct StateT * v21415 = slot_360(v21408);
  return v21415;
}

struct StateT * slot_514(struct StateT * v23959) {
  int v23960 = v23959->timer;
  int v23968 = v23960 + 1;
  v23959->timer = v23968;
  int * v23962 = v23959->regs;
  int v23963 = v23962[23];
  int v23964 = v23962[24];
  int v23972 = v23963 | v23964;
  v23962[23] = v23972;
  struct StateT * v23966 = slot_515(v23959);
  return v23966;
}

struct StateT * slot_296(struct StateT * v20422) {
  int v20423 = v20422->timer;
  int v20431 = v20423 + 1;
  v20422->timer = v20431;
  int * v20425 = v20422->regs;
  int v20426 = v20425[15];
  int v20427 = v20425[23];
  int v20435 = v20426 ^ v20427;
  v20425[15] = v20435;
  struct StateT * v20429 = slot_297(v20422);
  return v20429;
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

struct StateT * slot_300(struct StateT * v20489) {
  int v20490 = v20489->timer;
  int v20498 = v20490 + 1;
  v20489->timer = v20498;
  int * v20492 = v20489->regs;
  int v20493 = v20492[15];
  int v20494 = v20492[5];
  int v20503 = v20493 + v20494;
  v20492[23] = v20503;
  struct StateT * v20496 = slot_301(v20489);
  return v20496;
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

struct StateT * slot_282(struct StateT * v20209) {
  int v20210 = v20209->timer;
  int v20217 = v20210 + 1;
  v20209->timer = v20217;
  int * v20212 = v20209->regs;
  int v20213 = v20212[20];
  int v20220 = v20213 << 13;
  v20212[20] = v20220;
  struct StateT * v20215 = slot_283(v20209);
  return v20215;
}

struct StateT * slot_309(struct StateT * v20625) {
  int v20626 = v20625->timer;
  int v20634 = v20626 + 1;
  v20625->timer = v20634;
  int * v20628 = v20625->regs;
  int v20629 = v20628[22];
  int v20630 = v20628[24];
  int v20638 = v20629 | v20630;
  v20628[22] = v20638;
  struct StateT * v20632 = slot_310(v20625);
  return v20632;
}

struct StateT * slot_362(struct StateT * v21457) {
  int v21458 = v21457->timer;
  int v21465 = v21458 + 1;
  v21457->timer = v21465;
  int * v21460 = v21457->regs;
  int v21461 = v21460[20];
  int v21468 = v21461 << 13;
  v21460[20] = v21468;
  struct StateT * v21463 = slot_363(v21457);
  return v21463;
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

struct StateT * slot_283(struct StateT * v20223) {
  int v20224 = v20223->timer;
  int v20232 = v20224 + 1;
  v20223->timer = v20232;
  int * v20226 = v20223->regs;
  int v20227 = v20226[20];
  int v20228 = v20226[24];
  int v20236 = v20227 | v20228;
  v20226[20] = v20236;
  struct StateT * v20230 = slot_284(v20223);
  return v20230;
}

struct StateT * slot_346(struct StateT * v21204) {
  int v21205 = v21204->timer;
  int v21213 = v21205 + 1;
  v21204->timer = v21213;
  int * v21207 = v21204->regs;
  int v21208 = v21207[21];
  int v21209 = v21207[24];
  int v21217 = v21208 | v21209;
  v21207[21] = v21217;
  struct StateT * v21211 = slot_347(v21204);
  return v21211;
}

struct StateT * slot_516(struct StateT * v23991) {
  int v23992 = v23991->timer;
  int v24000 = v23992 + 1;
  v23991->timer = v24000;
  int * v23994 = v23991->regs;
  int v23995 = v23994[5];
  int v23996 = v23994[21];
  int v24004 = v23995 ^ v23996;
  v23994[5] = v24004;
  struct StateT * v23998 = slot_517(v23991);
  return v23998;
}

struct StateT * slot_274(struct StateT * v20078) {
  int v20079 = v20078->timer;
  int v20087 = v20079 + 1;
  v20078->timer = v20087;
  int * v20081 = v20078->regs;
  int v20082 = v20081[7];
  int v20083 = v20081[21];
  int v20091 = v20082 ^ v20083;
  v20081[7] = v20091;
  struct StateT * v20085 = slot_275(v20078);
  return v20085;
}

struct StateT * slot_535(struct StateT * v24287) {
  int v24288 = v24287->timer;
  int v24296 = v24288 + 1;
  v24287->timer = v24296;
  int * v24290 = v24287->regs;
  int v24291 = v24290[8];
  int v24292 = v24290[20];
  int v24300 = v24291 ^ v24292;
  v24290[8] = v24300;
  struct StateT * v24294 = slot_536(v24287);
  return v24294;
}

struct StateT * slot_318(struct StateT * v20767) {
  int v20768 = v20767->timer;
  int v20776 = v20768 + 1;
  v20767->timer = v20776;
  int * v20770 = v20767->regs;
  int v20771 = v20770[29];
  int v20772 = v20770[9];
  int v20781 = v20771 + v20772;
  v20770[21] = v20781;
  struct StateT * v20774 = slot_319(v20767);
  return v20774;
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

struct StateT * slot_255(struct StateT * v19782) {
  int v19783 = v19782->timer;
  int v19791 = v19783 + 1;
  v19782->timer = v19791;
  int * v19785 = v19782->regs;
  int v19786 = v19785[19];
  int v19787 = v19785[22];
  int v19795 = v19786 ^ v19787;
  v19785[19] = v19795;
  struct StateT * v19789 = slot_256(v19782);
  return v19789;
}

struct StateT * slot_540(struct StateT * v24368) {
  int v24369 = v24368->timer;
  int v24377 = v24369 + 1;
  v24368->timer = v24377;
  int * v24371 = v24368->regs;
  int v24372 = v24371[9];
  int v24373 = v24371[5];
  int v24382 = v24372 + v24373;
  v24371[21] = v24382;
  struct StateT * v24375 = slot_541(v24368);
  return v24375;
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

struct StateT * slot_550(struct StateT * v24524) {
  int v24525 = v24524->timer;
  int v24532 = v24525 + 1;
  v24524->timer = v24532;
  int * v24527 = v24524->regs;
  int v24528 = v24527[22];
  int v24535 = v24528 << 18;
  v24527[22] = v24535;
  struct StateT * v24530 = slot_551(v24524);
  return v24530;
}

struct StateT * slot_368(struct StateT * v21547) {
  int v21548 = v21547->timer;
  int v21555 = v21548 + 1;
  v21547->timer = v21555;
  int * v21550 = v21547->regs;
  int v21551 = v21550[22];
  int v21558 = v21551 << 13;
  v21550[22] = v21558;
  struct StateT * v21553 = slot_369(v21547);
  return v21553;
}

struct StateT * slot_265(struct StateT * v19942) {
  int v19943 = v19942->timer;
  int v19950 = v19943 + 1;
  v19942->timer = v19950;
  int * v19945 = v19942->regs;
  int v19946 = v19945[21];
  int v19953 = v19946 << 9;
  v19945[21] = v19953;
  struct StateT * v19948 = slot_266(v19942);
  return v19948;
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

struct StateT * slot_257(struct StateT * v19814) {
  int v19815 = v19814->timer;
  int v19823 = v19815 + 1;
  v19814->timer = v19823;
  int * v19817 = v19814->regs;
  int v19818 = v19817[9];
  int v19819 = v19817[30];
  int v19828 = v19818 + v19819;
  v19817[20] = v19828;
  struct StateT * v19821 = slot_258(v19814);
  return v19821;
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

struct StateT * slot_327(struct StateT * v20908) {
  int v20909 = v20908->timer;
  int v20916 = v20909 + 1;
  v20908->timer = v20916;
  int * v20911 = v20908->regs;
  int v20912 = v20911[22];
  int v20920 = (int)((unsigned int)v20912 >> 25);
  v20911[24] = v20920;
  struct StateT * v20914 = slot_328(v20908);
  return v20914;
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

struct StateT * slot_396(struct StateT * v21982) {
  int v21983 = v21982->timer;
  int v21991 = v21983 + 1;
  v21982->timer = v21991;
  int * v21985 = v21982->regs;
  int v21986 = v21985[31];
  int v21987 = v21985[23];
  int v21995 = v21986 ^ v21987;
  v21985[31] = v21995;
  struct StateT * v21989 = slot_397(v21982);
  return v21989;
}

struct StateT * slot_528(struct StateT * v24181) {
  int v24182 = v24181->timer;
  int v24190 = v24182 + 1;
  v24181->timer = v24190;
  int * v24184 = v24181->regs;
  int v24185 = v24184[21];
  int v24186 = v24184[24];
  int v24194 = v24185 | v24186;
  v24184[21] = v24194;
  struct StateT * v24188 = slot_529(v24181);
  return v24188;
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

struct StateT * slot_526(struct StateT * v24152) {
  int v24153 = v24152->timer;
  int v24160 = v24153 + 1;
  v24152->timer = v24160;
  int * v24155 = v24152->regs;
  int v24156 = v24155[21];
  int v24164 = (int)((unsigned int)v24156 >> 19);
  v24155[24] = v24164;
  struct StateT * v24158 = slot_527(v24152);
  return v24158;
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

struct StateT * slot_276(struct StateT * v20110) {
  int v20111 = v20110->timer;
  int v20119 = v20111 + 1;
  v20110->timer = v20119;
  int * v20113 = v20110->regs;
  int v20114 = v20113[5];
  int v20115 = v20113[23];
  int v20123 = v20114 ^ v20115;
  v20113[5] = v20123;
  struct StateT * v20117 = slot_277(v20110);
  return v20117;
}

struct StateT * slot_290(struct StateT * v20329) {
  int v20330 = v20329->timer;
  int v20337 = v20330 + 1;
  v20329->timer = v20337;
  int * v20332 = v20329->regs;
  int v20333 = v20332[23];
  int v20341 = (int)((unsigned int)v20333 >> 19);
  v20332[24] = v20341;
  struct StateT * v20335 = slot_291(v20329);
  return v20335;
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

struct StateT * slot_266(struct StateT * v19956) {
  int v19957 = v19956->timer;
  int v19965 = v19957 + 1;
  v19956->timer = v19965;
  int * v19959 = v19956->regs;
  int v19960 = v19959[21];
  int v19961 = v19959[24];
  int v19969 = v19960 | v19961;
  v19959[21] = v19969;
  struct StateT * v19963 = slot_267(v19956);
  return v19963;
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

struct StateT * slot_234(struct StateT * v17770) {
  int v17771 = v17770->timer;
  int v17881 = v17771 + 1;
  v17770->timer = v17881;
  int * v17773 = v17770->regs;
  int v17774 = v17773[2];
  int * v17775 = v17770->cache_tags;
  int v17885 = (((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2;
  int v17776 = v17775[v17885];
  int v17886 = ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17777 = v17775[v17886];
  int v17887 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2);
  int v17778 = v17775[v17887];
  int v17888 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17779 = v17775[v17888];
  int v17780 = v17770->timer;
  int v17889 = v17780 + ((100 ^ (((~(((v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17776 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17776 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17770->timer = v17889;
  int * v17782 = v17770->cache_vals;
  bool v17890 = !(((~(((v17776 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17776 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v17875;
  if (v17890) {
    int * v17783 = v17770->cache_age;
    int v17892 = ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17777 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v17784 = v17783[v17892];
    int v17785 = v17783[v17885];
    int v17893 = v17785 + ((int)((unsigned int)(v17785 - v17784) >> 31));
    v17783[v17885] = v17893;
    int * v17787 = v17770->cache_age;
    int v17788 = v17787[v17886];
    int v17895 = v17788 + ((int)((unsigned int)(v17788 - v17784) >> 31));
    v17787[v17886] = v17895;
    int * v17790 = v17770->cache_age;
    v17790[v17892] = 0;
    v17875 = v17892;
  } else {
    int * v17793 = v17770->cache_age;
    int v17899 = (((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2;
    int v17794 = v17793[v17899];
    int * v17795 = v17770->cache_tags;
    int v17796 = v17795[v17899];
    int v17797 = v17793[v17886];
    int v17798 = v17795[v17886];
    bool v17901 = !(((~(((v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17778 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v17852;
    if (v17901) {
      int * v17799 = v17770->cache_age;
      int v17903 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))) | (-(v17779 ^ ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v17800 = v17799[v17903];
      int v17801 = v17799[v17887];
      int v17904 = v17801 + ((int)((unsigned int)(v17801 - v17800) >> 31));
      v17799[v17887] = v17904;
      int * v17803 = v17770->cache_age;
      int v17804 = v17803[v17888];
      int v17906 = v17804 + ((int)((unsigned int)(v17804 - v17800) >> 31));
      v17803[v17888] = v17906;
      int * v17806 = v17770->cache_age;
      v17806[v17903] = 0;
      v17852 = v17903;
    } else {
      int * v17809 = v17770->cache_age;
      int v17910 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2);
      int v17810 = v17809[v17910];
      int * v17811 = v17770->cache_tags;
      int v17812 = v17811[v17910];
      int v17813 = v17809[v17888];
      int v17814 = v17811[v17888];
      int * v17815 = v17770->cache_dirty;
      int v17913 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v17810 + ((~(((v17812 ^ -1) | (-(v17812 ^ -1))) >> 31)) & 2)) - (v17813 + ((~(((v17814 ^ -1) | (-(v17814 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17816 = v17815[v17913];
      bool v17914 = !(v17816 == 0);
      if (v17914) {
        int * v17817 = v17770->cache_tags;
        int v17818 = v17817[v17913];
        int * v17819 = v17770->cache_vals;
        int v17917 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v17810 + ((~(((v17812 ^ -1) | (-(v17812 ^ -1))) >> 31)) & 2)) - (v17813 + ((~(((v17814 ^ -1) | (-(v17814 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17820 = v17819[v17917];
        int v17918 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v17810 + ((~(((v17812 ^ -1) | (-(v17812 ^ -1))) >> 31)) & 2)) - (v17813 + ((~(((v17814 ^ -1) | (-(v17814 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17821 = v17819[v17918];
        int * v17822 = v17770->mem;
        int v17920 = v17818 * 2;
        v17822[v17920] = v17820;
        int * v17824 = v17770->mem;
        int v17923 = (v17818 * 2) + 1;
        v17824[v17923] = v17821;
        ;
      } else {
        ;
      }
      int * v17829 = v17770->mem;
      int v17928 = ((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) * 2;
      int v17830 = v17829[v17928];
      int v17929 = (((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) * 2) + 1;
      int v17831 = v17829[v17929];
      int * v17832 = v17770->cache_vals;
      int v17931 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v17810 + ((~(((v17812 ^ -1) | (-(v17812 ^ -1))) >> 31)) & 2)) - (v17813 + ((~(((v17814 ^ -1) | (-(v17814 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17832[v17931] = v17830;
      int * v17834 = v17770->cache_vals;
      int v17934 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v17810 + ((~(((v17812 ^ -1) | (-(v17812 ^ -1))) >> 31)) & 2)) - (v17813 + ((~(((v17814 ^ -1) | (-(v17814 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17834[v17934] = v17831;
      int * v17836 = v17770->cache_tags;
      int v17937 = (int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1);
      v17836[v17913] = v17937;
      int * v17838 = v17770->cache_dirty;
      v17838[v17913] = 0;
      int * v17840 = v17770->cache_age;
      v17840[v17913] = 1;
      int * v17842 = v17770->cache_age;
      int v17843 = v17842[v17913];
      int v17844 = v17842[v17887];
      int v17943 = v17844 + ((int)((unsigned int)(v17844 - v17843) >> 31));
      v17842[v17887] = v17943;
      int * v17846 = v17770->cache_age;
      int v17847 = v17846[v17888];
      int v17945 = v17847 + ((int)((unsigned int)(v17847 - v17843) >> 31));
      v17846[v17888] = v17945;
      int * v17849 = v17770->cache_age;
      v17849[v17913] = 0;
      v17852 = v17913;
    }
    int * v17853 = v17770->cache_vals;
    int v17948 = v17852 * 2;
    int v17854 = v17853[v17948];
    int v17949 = (v17852 * 2) + 1;
    int v17855 = v17853[v17949];
    int v17950 = (((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v17794 + ((~(((v17796 ^ -1) | (-(v17796 ^ -1))) >> 31)) & 2)) - (v17797 + ((~(((v17798 ^ -1) | (-(v17798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17853[v17950] = v17854;
    int * v17857 = v17770->cache_vals;
    int v17953 = ((((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v17794 + ((~(((v17796 ^ -1) | (-(v17796 ^ -1))) >> 31)) & 2)) - (v17797 + ((~(((v17798 ^ -1) | (-(v17798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17857[v17953] = v17855;
    int * v17859 = v17770->cache_tags;
    int v17956 = ((((int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v17794 + ((~(((v17796 ^ -1) | (-(v17796 ^ -1))) >> 31)) & 2)) - (v17797 + ((~(((v17798 ^ -1) | (-(v17798 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17957 = (int)((unsigned int)((int)((unsigned int)(v17774 + 16) >> 2)) >> 1);
    v17859[v17956] = v17957;
    int * v17861 = v17770->cache_dirty;
    v17861[v17956] = 0;
    int * v17863 = v17770->cache_age;
    v17863[v17956] = 1;
    int * v17865 = v17770->cache_age;
    int v17866 = v17865[v17956];
    int v17867 = v17865[v17885];
    int v17963 = v17867 + ((int)((unsigned int)(v17867 - v17866) >> 31));
    v17865[v17885] = v17963;
    int * v17869 = v17770->cache_age;
    int v17870 = v17869[v17886];
    int v17965 = v17870 + ((int)((unsigned int)(v17870 - v17866) >> 31));
    v17869[v17886] = v17965;
    int * v17872 = v17770->cache_age;
    v17872[v17956] = 0;
    v17875 = v17956;
  }
  int v17968 = (v17875 * 2) + (((int)((unsigned int)(v17774 + 16) >> 2)) & 1);
  int v17876 = v17782[v17968];
  int * v17877 = v17770->regs;
  v17877[23] = v17876;
  struct StateT * v17879 = slot_237(v17770);
  return v17879;
}

struct StateT * slot_471(struct StateT * v23262) {
  int v23263 = v23262->timer;
  int v23271 = v23263 + 1;
  v23262->timer = v23271;
  int * v23265 = v23262->regs;
  int v23266 = v23265[22];
  int v23267 = v23265[24];
  int v23275 = v23266 | v23267;
  v23265[22] = v23275;
  struct StateT * v23269 = slot_472(v23262);
  return v23269;
}

struct StateT * slot_419(struct StateT * v22395) {
  int v22396 = v22395->timer;
  int v22404 = v22396 + 1;
  v22395->timer = v22404;
  int * v22398 = v22395->regs;
  int v22399 = v22398[9];
  int v22400 = v22398[30];
  int v22409 = v22399 + v22400;
  v22398[20] = v22409;
  struct StateT * v22402 = slot_420(v22395);
  return v22402;
}

struct StateT * slot_218(struct StateT * v15123) {
  int v15124 = v15123->timer;
  int v15234 = v15124 + 1;
  v15123->timer = v15234;
  int * v15126 = v15123->regs;
  int v15127 = v15126[2];
  int * v15128 = v15123->cache_tags;
  int v15238 = (((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2;
  int v15129 = v15128[v15238];
  int v15239 = ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15130 = v15128[v15239];
  int v15240 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2);
  int v15131 = v15128[v15240];
  int v15241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15132 = v15128[v15241];
  int v15133 = v15123->timer;
  int v15242 = v15133 + ((100 ^ (((~(((v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15129 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15129 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15123->timer = v15242;
  int * v15135 = v15123->cache_vals;
  bool v15243 = !(((~(((v15129 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15129 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v15228;
  if (v15243) {
    int * v15136 = v15123->cache_age;
    int v15245 = ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15130 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v15137 = v15136[v15245];
    int v15138 = v15136[v15238];
    int v15246 = v15138 + ((int)((unsigned int)(v15138 - v15137) >> 31));
    v15136[v15238] = v15246;
    int * v15140 = v15123->cache_age;
    int v15141 = v15140[v15239];
    int v15248 = v15141 + ((int)((unsigned int)(v15141 - v15137) >> 31));
    v15140[v15239] = v15248;
    int * v15143 = v15123->cache_age;
    v15143[v15245] = 0;
    v15228 = v15245;
  } else {
    int * v15146 = v15123->cache_age;
    int v15252 = (((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2;
    int v15147 = v15146[v15252];
    int * v15148 = v15123->cache_tags;
    int v15149 = v15148[v15252];
    int v15150 = v15146[v15239];
    int v15151 = v15148[v15239];
    bool v15254 = !(((~(((v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15131 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v15205;
    if (v15254) {
      int * v15152 = v15123->cache_age;
      int v15256 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))) | (-(v15132 ^ ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v15153 = v15152[v15256];
      int v15154 = v15152[v15240];
      int v15257 = v15154 + ((int)((unsigned int)(v15154 - v15153) >> 31));
      v15152[v15240] = v15257;
      int * v15156 = v15123->cache_age;
      int v15157 = v15156[v15241];
      int v15259 = v15157 + ((int)((unsigned int)(v15157 - v15153) >> 31));
      v15156[v15241] = v15259;
      int * v15159 = v15123->cache_age;
      v15159[v15256] = 0;
      v15205 = v15256;
    } else {
      int * v15162 = v15123->cache_age;
      int v15263 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2);
      int v15163 = v15162[v15263];
      int * v15164 = v15123->cache_tags;
      int v15165 = v15164[v15263];
      int v15166 = v15162[v15241];
      int v15167 = v15164[v15241];
      int * v15168 = v15123->cache_dirty;
      int v15266 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15163 + ((~(((v15165 ^ -1) | (-(v15165 ^ -1))) >> 31)) & 2)) - (v15166 + ((~(((v15167 ^ -1) | (-(v15167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15169 = v15168[v15266];
      bool v15267 = !(v15169 == 0);
      if (v15267) {
        int * v15170 = v15123->cache_tags;
        int v15171 = v15170[v15266];
        int * v15172 = v15123->cache_vals;
        int v15270 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15163 + ((~(((v15165 ^ -1) | (-(v15165 ^ -1))) >> 31)) & 2)) - (v15166 + ((~(((v15167 ^ -1) | (-(v15167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15173 = v15172[v15270];
        int v15271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15163 + ((~(((v15165 ^ -1) | (-(v15165 ^ -1))) >> 31)) & 2)) - (v15166 + ((~(((v15167 ^ -1) | (-(v15167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15174 = v15172[v15271];
        int * v15175 = v15123->mem;
        int v15273 = v15171 * 2;
        v15175[v15273] = v15173;
        int * v15177 = v15123->mem;
        int v15276 = (v15171 * 2) + 1;
        v15177[v15276] = v15174;
        ;
      } else {
        ;
      }
      int * v15182 = v15123->mem;
      int v15281 = ((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) * 2;
      int v15183 = v15182[v15281];
      int v15282 = (((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) * 2) + 1;
      int v15184 = v15182[v15282];
      int * v15185 = v15123->cache_vals;
      int v15284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15163 + ((~(((v15165 ^ -1) | (-(v15165 ^ -1))) >> 31)) & 2)) - (v15166 + ((~(((v15167 ^ -1) | (-(v15167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15185[v15284] = v15183;
      int * v15187 = v15123->cache_vals;
      int v15287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15163 + ((~(((v15165 ^ -1) | (-(v15165 ^ -1))) >> 31)) & 2)) - (v15166 + ((~(((v15167 ^ -1) | (-(v15167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15187[v15287] = v15184;
      int * v15189 = v15123->cache_tags;
      int v15290 = (int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1);
      v15189[v15266] = v15290;
      int * v15191 = v15123->cache_dirty;
      v15191[v15266] = 0;
      int * v15193 = v15123->cache_age;
      v15193[v15266] = 1;
      int * v15195 = v15123->cache_age;
      int v15196 = v15195[v15266];
      int v15197 = v15195[v15240];
      int v15296 = v15197 + ((int)((unsigned int)(v15197 - v15196) >> 31));
      v15195[v15240] = v15296;
      int * v15199 = v15123->cache_age;
      int v15200 = v15199[v15241];
      int v15298 = v15200 + ((int)((unsigned int)(v15200 - v15196) >> 31));
      v15199[v15241] = v15298;
      int * v15202 = v15123->cache_age;
      v15202[v15266] = 0;
      v15205 = v15266;
    }
    int * v15206 = v15123->cache_vals;
    int v15301 = v15205 * 2;
    int v15207 = v15206[v15301];
    int v15302 = (v15205 * 2) + 1;
    int v15208 = v15206[v15302];
    int v15303 = (((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15147 + ((~(((v15149 ^ -1) | (-(v15149 ^ -1))) >> 31)) & 2)) - (v15150 + ((~(((v15151 ^ -1) | (-(v15151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15206[v15303] = v15207;
    int * v15210 = v15123->cache_vals;
    int v15306 = ((((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15147 + ((~(((v15149 ^ -1) | (-(v15149 ^ -1))) >> 31)) & 2)) - (v15150 + ((~(((v15151 ^ -1) | (-(v15151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15210[v15306] = v15208;
    int * v15212 = v15123->cache_tags;
    int v15309 = ((((int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15147 + ((~(((v15149 ^ -1) | (-(v15149 ^ -1))) >> 31)) & 2)) - (v15150 + ((~(((v15151 ^ -1) | (-(v15151 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15310 = (int)((unsigned int)((int)((unsigned int)(v15127 + 40) >> 2)) >> 1);
    v15212[v15309] = v15310;
    int * v15214 = v15123->cache_dirty;
    v15214[v15309] = 0;
    int * v15216 = v15123->cache_age;
    v15216[v15309] = 1;
    int * v15218 = v15123->cache_age;
    int v15219 = v15218[v15309];
    int v15220 = v15218[v15238];
    int v15316 = v15220 + ((int)((unsigned int)(v15220 - v15219) >> 31));
    v15218[v15238] = v15316;
    int * v15222 = v15123->cache_age;
    int v15223 = v15222[v15239];
    int v15318 = v15223 + ((int)((unsigned int)(v15223 - v15219) >> 31));
    v15222[v15239] = v15318;
    int * v15225 = v15123->cache_age;
    v15225[v15309] = 0;
    v15228 = v15309;
  }
  int v15321 = (v15228 * 2) + (((int)((unsigned int)(v15127 + 40) >> 2)) & 1);
  int v15229 = v15135[v15321];
  int * v15230 = v15123->regs;
  v15230[9] = v15229;
  struct StateT * v15232 = slot_231(v15123);
  return v15232;
}

struct StateT * slot_336(struct StateT * v21046) {
  int v21047 = v21046->timer;
  int v21055 = v21047 + 1;
  v21046->timer = v21055;
  int * v21049 = v21046->regs;
  int v21050 = v21049[16];
  int v21051 = v21049[23];
  int v21059 = v21050 ^ v21051;
  v21049[16] = v21059;
  struct StateT * v21053 = slot_337(v21046);
  return v21053;
}

struct StateT * slot_294(struct StateT * v20390) {
  int v20391 = v20390->timer;
  int v20399 = v20391 + 1;
  v20390->timer = v20399;
  int * v20393 = v20390->regs;
  int v20394 = v20393[14];
  int v20395 = v20393[21];
  int v20403 = v20394 ^ v20395;
  v20393[14] = v20403;
  struct StateT * v20397 = slot_295(v20390);
  return v20397;
}

struct StateT * slot_408(struct StateT * v22197) {
  int v22198 = v22197->timer;
  int v22206 = v22198 + 1;
  v22197->timer = v22206;
  int * v22200 = v22197->regs;
  int v22201 = v22200[21];
  int v22202 = v22200[24];
  int v22210 = v22201 | v22202;
  v22200[21] = v22210;
  struct StateT * v22204 = slot_409(v22197);
  return v22204;
}

struct StateT * slot_342(struct StateT * v21145) {
  int v21146 = v21145->timer;
  int v21153 = v21146 + 1;
  v21145->timer = v21153;
  int * v21148 = v21145->regs;
  int v21149 = v21148[20];
  int v21156 = v21149 << 9;
  v21148[20] = v21156;
  struct StateT * v21151 = slot_343(v21145);
  return v21151;
}

struct StateT * slot_488(struct StateT * v23557) {
  int v23558 = v23557->timer;
  int v23566 = v23558 + 1;
  v23557->timer = v23566;
  int * v23560 = v23557->regs;
  int v23561 = v23560[21];
  int v23562 = v23560[24];
  int v23570 = v23561 | v23562;
  v23560[21] = v23570;
  struct StateT * v23564 = slot_489(v23557);
  return v23564;
}

struct StateT * slot_439(struct StateT * v22735) {
  int v22736 = v22735->timer;
  int v22744 = v22736 + 1;
  v22735->timer = v22744;
  int * v22738 = v22735->regs;
  int v22739 = v22738[6];
  int v22740 = v22738[9];
  int v22749 = v22739 + v22740;
  v22738[20] = v22749;
  struct StateT * v22742 = slot_440(v22735);
  return v22742;
}

struct StateT * slot_389(struct StateT * v21873) {
  int v21874 = v21873->timer;
  int v21882 = v21874 + 1;
  v21873->timer = v21882;
  int * v21876 = v21873->regs;
  int v21877 = v21876[22];
  int v21878 = v21876[24];
  int v21886 = v21877 | v21878;
  v21876[22] = v21886;
  struct StateT * v21880 = slot_390(v21873);
  return v21880;
}

struct StateT * slot_479(struct StateT * v23415) {
  int v23416 = v23415->timer;
  int v23424 = v23416 + 1;
  v23415->timer = v23424;
  int * v23418 = v23415->regs;
  int v23419 = v23418[30];
  int v23420 = v23418[8];
  int v23429 = v23419 + v23420;
  v23418[20] = v23429;
  struct StateT * v23422 = slot_480(v23415);
  return v23422;
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

struct StateT * slot_483(struct StateT * v23483) {
  int v23484 = v23483->timer;
  int v23491 = v23484 + 1;
  v23483->timer = v23491;
  int * v23486 = v23483->regs;
  int v23487 = v23486[20];
  int v23495 = (int)((unsigned int)v23487 >> 25);
  v23486[24] = v23495;
  struct StateT * v23489 = slot_484(v23483);
  return v23489;
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

struct StateT * slot_425(struct StateT * v22492) {
  int v22493 = v22492->timer;
  int v22501 = v22493 + 1;
  v22492->timer = v22501;
  int * v22495 = v22492->regs;
  int v22496 = v22495[20];
  int v22497 = v22495[24];
  int v22505 = v22496 | v22497;
  v22495[20] = v22505;
  struct StateT * v22499 = slot_426(v22492);
  return v22499;
}

struct StateT * slot_443(struct StateT * v22803) {
  int v22804 = v22803->timer;
  int v22811 = v22804 + 1;
  v22803->timer = v22811;
  int * v22806 = v22803->regs;
  int v22807 = v22806[20];
  int v22815 = (int)((unsigned int)v22807 >> 19);
  v22806[24] = v22815;
  struct StateT * v22809 = slot_444(v22803);
  return v22809;
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

struct StateT * slot_534(struct StateT * v24271) {
  int v24272 = v24271->timer;
  int v24280 = v24272 + 1;
  v24271->timer = v24280;
  int * v24274 = v24271->regs;
  int v24275 = v24274[23];
  int v24276 = v24274[24];
  int v24284 = v24275 | v24276;
  v24274[23] = v24284;
  struct StateT * v24278 = slot_535(v24271);
  return v24278;
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

struct StateT * slot_504(struct StateT * v23810) {
  int v23811 = v23810->timer;
  int v23818 = v23811 + 1;
  v23810->timer = v23818;
  int * v23813 = v23810->regs;
  int v23814 = v23813[20];
  int v23821 = v23814 << 9;
  v23813[20] = v23821;
  struct StateT * v23816 = slot_505(v23810);
  return v23816;
}

struct StateT * slot_512(struct StateT * v23930) {
  int v23931 = v23930->timer;
  int v23938 = v23931 + 1;
  v23930->timer = v23938;
  int * v23933 = v23930->regs;
  int v23934 = v23933[23];
  int v23942 = (int)((unsigned int)v23934 >> 23);
  v23933[24] = v23942;
  struct StateT * v23936 = slot_513(v23930);
  return v23936;
}

struct StateT * slot_496(struct StateT * v23679) {
  int v23680 = v23679->timer;
  int v23688 = v23680 + 1;
  v23679->timer = v23688;
  int * v23682 = v23679->regs;
  int v23683 = v23682[12];
  int v23684 = v23682[21];
  int v23692 = v23683 ^ v23684;
  v23682[12] = v23692;
  struct StateT * v23686 = slot_497(v23679);
  return v23686;
}

struct StateT * slot_494(struct StateT * v23647) {
  int v23648 = v23647->timer;
  int v23656 = v23648 + 1;
  v23647->timer = v23656;
  int * v23650 = v23647->regs;
  int v23651 = v23650[23];
  int v23652 = v23650[24];
  int v23660 = v23651 | v23652;
  v23650[23] = v23660;
  struct StateT * v23654 = slot_495(v23647);
  return v23654;
}

struct StateT * slot_328(struct StateT * v20923) {
  int v20924 = v20923->timer;
  int v20931 = v20924 + 1;
  v20923->timer = v20931;
  int * v20926 = v20923->regs;
  int v20927 = v20926[22];
  int v20934 = v20927 << 7;
  v20926[22] = v20934;
  struct StateT * v20929 = slot_329(v20923);
  return v20929;
}

struct StateT * slot_402(struct StateT * v22092) {
  int * v22093 = v22092->saved_regs;
  int * v22094 = v22092->regs;
  int v22095 = v22094[23];
  v22093[23] = v22095;
  int v22097 = v22092->timer;
  int v22109 = v22097 + 1;
  v22092->timer = v22109;
  int * v22099 = v22092->regs;
  int v22100 = v22099[31];
  int v22101 = v22099[15];
  int v22113 = v22100 + v22101;
  v22099[23] = v22113;
  struct StateT * v22103 = slot_403(v22092);
  return v22103;
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
  struct StateT * v9954 = slot_203(v9947);
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

struct StateT * slot_527(struct StateT * v24167) {
  int v24168 = v24167->timer;
  int v24175 = v24168 + 1;
  v24167->timer = v24175;
  int * v24170 = v24167->regs;
  int v24171 = v24170[21];
  int v24178 = v24171 << 13;
  v24170[21] = v24178;
  struct StateT * v24173 = slot_528(v24167);
  return v24173;
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

struct StateT * slot_334(struct StateT * v21014) {
  int v21015 = v21014->timer;
  int v21023 = v21015 + 1;
  v21014->timer = v21023;
  int * v21017 = v21014->regs;
  int v21018 = v21017[12];
  int v21019 = v21017[21];
  int v21027 = v21018 ^ v21019;
  v21017[12] = v21027;
  struct StateT * v21021 = slot_335(v21014);
  return v21021;
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

struct StateT * slot_235(struct StateT * v17974) {
  int v17975 = v17974->timer;
  int v17983 = v17975 + 1;
  v17974->timer = v17983;
  int * v17977 = v17974->regs;
  int v17978 = v17977[21];
  int v17979 = v17977[24];
  int v17987 = v17978 | v17979;
  v17977[21] = v17987;
  struct StateT * v17981 = slot_238(v17974);
  return v17981;
}

struct StateT * slot_275(struct StateT * v20094) {
  int v20095 = v20094->timer;
  int v20103 = v20095 + 1;
  v20094->timer = v20103;
  int * v20097 = v20094->regs;
  int v20098 = v20097[17];
  int v20099 = v20097[22];
  int v20107 = v20098 ^ v20099;
  v20097[17] = v20107;
  struct StateT * v20101 = slot_276(v20094);
  return v20101;
}

struct StateT * slot_329(struct StateT * v20937) {
  int v20938 = v20937->timer;
  int v20946 = v20938 + 1;
  v20937->timer = v20946;
  int * v20940 = v20937->regs;
  int v20941 = v20940[22];
  int v20942 = v20940[24];
  int v20950 = v20941 | v20942;
  v20940[22] = v20950;
  struct StateT * v20944 = slot_330(v20937);
  return v20944;
}

struct StateT * slot_428(struct StateT * v22537) {
  int v22538 = v22537->timer;
  int v22546 = v22538 + 1;
  v22537->timer = v22546;
  int * v22540 = v22537->regs;
  int v22541 = v22540[21];
  int v22542 = v22540[24];
  int v22550 = v22541 | v22542;
  v22540[21] = v22550;
  struct StateT * v22544 = slot_429(v22537);
  return v22544;
}

struct StateT * slot_395(struct StateT * v21966) {
  int v21967 = v21966->timer;
  int v21975 = v21967 + 1;
  v21966->timer = v21975;
  int * v21969 = v21966->regs;
  int v21970 = v21969[28];
  int v21971 = v21969[22];
  int v21979 = v21970 ^ v21971;
  v21969[28] = v21979;
  struct StateT * v21973 = slot_396(v21966);
  return v21973;
}

struct StateT * slot_345(struct StateT * v21190) {
  int v21191 = v21190->timer;
  int v21198 = v21191 + 1;
  v21190->timer = v21198;
  int * v21193 = v21190->regs;
  int v21194 = v21193[21];
  int v21201 = v21194 << 9;
  v21193[21] = v21201;
  struct StateT * v21196 = slot_346(v21190);
  return v21196;
}

struct StateT * slot_298(struct StateT * v20455) {
  int v20456 = v20455->timer;
  int v20464 = v20456 + 1;
  v20455->timer = v20464;
  int * v20458 = v20455->regs;
  int v20459 = v20458[14];
  int v20460 = v20458[7];
  int v20469 = v20459 + v20460;
  v20458[21] = v20469;
  struct StateT * v20462 = slot_299(v20455);
  return v20462;
}

struct StateT * slot_414(struct StateT * v22287) {
  int v22288 = v22287->timer;
  int v22296 = v22288 + 1;
  v22287->timer = v22296;
  int * v22290 = v22287->regs;
  int v22291 = v22290[23];
  int v22292 = v22290[24];
  int v22300 = v22291 | v22292;
  v22290[23] = v22300;
  struct StateT * v22294 = slot_415(v22287);
  return v22294;
}

struct StateT * slot_364(struct StateT * v21487) {
  int v21488 = v21487->timer;
  int v21495 = v21488 + 1;
  v21487->timer = v21495;
  int * v21490 = v21487->regs;
  int v21491 = v21490[21];
  int v21499 = (int)((unsigned int)v21491 >> 19);
  v21490[24] = v21499;
  struct StateT * v21493 = slot_365(v21487);
  return v21493;
}

struct StateT * slot_356(struct StateT * v21358) {
  int v21359 = v21358->timer;
  int v21367 = v21359 + 1;
  v21358->timer = v21367;
  int * v21361 = v21358->regs;
  int v21362 = v21361[7];
  int v21363 = v21361[23];
  int v21371 = v21362 ^ v21363;
  v21361[7] = v21371;
  struct StateT * v21365 = slot_357(v21358);
  return v21365;
}

struct StateT * slot_253(struct StateT * v19750) {
  int v19751 = v19750->timer;
  int v19759 = v19751 + 1;
  v19750->timer = v19759;
  int * v19753 = v19750->regs;
  int v19754 = v19753[9];
  int v19755 = v19753[20];
  int v19763 = v19754 ^ v19755;
  v19753[9] = v19763;
  struct StateT * v19757 = slot_254(v19750);
  return v19757;
}

struct StateT * slot_434(struct StateT * v22627) {
  int v22628 = v22627->timer;
  int v22636 = v22628 + 1;
  v22627->timer = v22636;
  int * v22630 = v22627->regs;
  int v22631 = v22630[23];
  int v22632 = v22630[24];
  int v22640 = v22631 | v22632;
  v22630[23] = v22640;
  struct StateT * v22634 = slot_435(v22627);
  return v22634;
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

struct StateT * slot_522(struct StateT * v24090) {
  int v24091 = v24090->timer;
  int v24099 = v24091 + 1;
  v24090->timer = v24099;
  int * v24093 = v24090->regs;
  int v24094 = v24093[7];
  int v24095 = v24093[16];
  int v24104 = v24094 + v24095;
  v24093[23] = v24104;
  struct StateT * v24097 = slot_523(v24090);
  return v24097;
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

struct StateT * slot_503(struct StateT * v23795) {
  int v23796 = v23795->timer;
  int v23803 = v23796 + 1;
  v23795->timer = v23803;
  int * v23798 = v23795->regs;
  int v23799 = v23798[20];
  int v23807 = (int)((unsigned int)v23799 >> 23);
  v23798[24] = v23807;
  struct StateT * v23801 = slot_504(v23795);
  return v23801;
}

struct StateT * slot_390(struct StateT * v21889) {
  int v21890 = v21889->timer;
  int v21897 = v21890 + 1;
  v21889->timer = v21897;
  int * v21892 = v21889->regs;
  int v21893 = v21892[23];
  int v21901 = (int)((unsigned int)v21893 >> 14);
  v21892[24] = v21901;
  struct StateT * v21895 = slot_391(v21889);
  return v21895;
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

struct StateT * slot_386(struct StateT * v21828) {
  int v21829 = v21828->timer;
  int v21837 = v21829 + 1;
  v21828->timer = v21837;
  int * v21831 = v21828->regs;
  int v21832 = v21831[21];
  int v21833 = v21831[24];
  int v21841 = v21832 | v21833;
  v21831[21] = v21841;
  struct StateT * v21835 = slot_387(v21828);
  return v21835;
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

struct StateT * slot_338(struct StateT * v21079) {
  int v21080 = v21079->timer;
  int v21088 = v21080 + 1;
  v21079->timer = v21088;
  int * v21082 = v21079->regs;
  int v21083 = v21082[12];
  int v21084 = v21082[29];
  int v21093 = v21083 + v21084;
  v21082[21] = v21093;
  struct StateT * v21086 = slot_339(v21079);
  return v21086;
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

struct StateT * slot_366(struct StateT * v21516) {
  int v21517 = v21516->timer;
  int v21525 = v21517 + 1;
  v21516->timer = v21525;
  int * v21519 = v21516->regs;
  int v21520 = v21519[21];
  int v21521 = v21519[24];
  int v21529 = v21520 | v21521;
  v21519[21] = v21529;
  struct StateT * v21523 = slot_367(v21516);
  return v21523;
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

struct StateT * slot_438(struct StateT * v22712) {
  int * v22713 = v22712->saved_regs;
  int * v22714 = v22712->regs;
  int v22715 = v22714[5];
  v22713[5] = v22715;
  int v22717 = v22712->timer;
  int v22729 = v22717 + 1;
  v22712->timer = v22729;
  int * v22719 = v22712->regs;
  int v22720 = v22719[5];
  int v22721 = v22719[23];
  int v22732 = v22720 ^ v22721;
  v22719[5] = v22732;
  struct StateT * v22723 = slot_439(v22712);
  return v22723;
}

struct StateT * slot_333(struct StateT * v20998) {
  int v20999 = v20998->timer;
  int v21007 = v20999 + 1;
  v20998->timer = v21007;
  int * v21001 = v20998->regs;
  int v21002 = v21001[14];
  int v21003 = v21001[20];
  int v21011 = v21002 ^ v21003;
  v21001[14] = v21011;
  struct StateT * v21005 = slot_334(v20998);
  return v21005;
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

struct StateT * slot_311(struct StateT * v20656) {
  int v20657 = v20656->timer;
  int v20664 = v20657 + 1;
  v20656->timer = v20664;
  int * v20659 = v20656->regs;
  int v20660 = v20659[23];
  int v20667 = v20660 << 18;
  v20659[23] = v20667;
  struct StateT * v20662 = slot_312(v20656);
  return v20662;
}

struct StateT * slot_498(struct StateT * v23711) {
  int v23712 = v23711->timer;
  int v23720 = v23712 + 1;
  v23711->timer = v23720;
  int * v23714 = v23711->regs;
  int v23715 = v23714[16];
  int v23716 = v23714[23];
  int v23724 = v23715 ^ v23716;
  v23714[16] = v23724;
  struct StateT * v23718 = slot_499(v23711);
  return v23718;
}

struct StateT * slot_279(struct StateT * v20160) {
  int v20161 = v20160->timer;
  int v20169 = v20161 + 1;
  v20160->timer = v20169;
  int * v20163 = v20160->regs;
  int v20164 = v20163[17];
  int v20165 = v20163[19];
  int v20174 = v20164 + v20165;
  v20163[22] = v20174;
  struct StateT * v20167 = slot_280(v20160);
  return v20167;
}

struct StateT * slot_271(struct StateT * v20032) {
  int v20033 = v20032->timer;
  int v20040 = v20033 + 1;
  v20032->timer = v20040;
  int * v20035 = v20032->regs;
  int v20036 = v20035[23];
  int v20043 = v20036 << 9;
  v20035[23] = v20043;
  struct StateT * v20038 = slot_272(v20032);
  return v20038;
}

struct StateT * slot_524(struct StateT * v24122) {
  int v24123 = v24122->timer;
  int v24130 = v24123 + 1;
  v24122->timer = v24130;
  int * v24125 = v24122->regs;
  int v24126 = v24125[20];
  int v24133 = v24126 << 13;
  v24125[20] = v24133;
  struct StateT * v24128 = slot_525(v24122);
  return v24128;
}

struct StateT * slot_505(struct StateT * v23824) {
  int v23825 = v23824->timer;
  int v23833 = v23825 + 1;
  v23824->timer = v23833;
  int * v23827 = v23824->regs;
  int v23828 = v23827[20];
  int v23829 = v23827[24];
  int v23837 = v23828 | v23829;
  v23827[20] = v23837;
  struct StateT * v23831 = slot_506(v23824);
  return v23831;
}

struct StateT * slot_401(struct StateT * v22068) {
  int * v22069 = v22068->saved_regs;
  int * v22070 = v22068->regs;
  int v22071 = v22070[22];
  v22069[22] = v22071;
  int v22073 = v22068->timer;
  int v22085 = v22073 + 1;
  v22068->timer = v22085;
  int * v22075 = v22068->regs;
  int v22076 = v22075[28];
  int v22077 = v22075[12];
  int v22089 = v22076 + v22077;
  v22075[22] = v22089;
  struct StateT * v22079 = slot_402(v22068);
  return v22079;
}

struct StateT * slot_423(struct StateT * v22463) {
  int v22464 = v22463->timer;
  int v22471 = v22464 + 1;
  v22463->timer = v22471;
  int * v22466 = v22463->regs;
  int v22467 = v22466[20];
  int v22475 = (int)((unsigned int)v22467 >> 23);
  v22466[24] = v22475;
  struct StateT * v22469 = slot_424(v22463);
  return v22469;
}

struct StateT * slot_532(struct StateT * v24242) {
  int v24243 = v24242->timer;
  int v24250 = v24243 + 1;
  v24242->timer = v24250;
  int * v24245 = v24242->regs;
  int v24246 = v24245[23];
  int v24254 = (int)((unsigned int)v24246 >> 19);
  v24245[24] = v24254;
  struct StateT * v24248 = slot_533(v24242);
  return v24248;
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

struct StateT * slot_549(struct StateT * v24509) {
  int v24510 = v24509->timer;
  int v24517 = v24510 + 1;
  v24509->timer = v24517;
  int * v24512 = v24509->regs;
  int v24513 = v24512[22];
  int v24521 = (int)((unsigned int)v24513 >> 14);
  v24512[24] = v24521;
  struct StateT * v24515 = slot_550(v24509);
  return v24515;
}

struct StateT * slot_349(struct StateT * v21249) {
  int v21250 = v21249->timer;
  int v21258 = v21250 + 1;
  v21249->timer = v21258;
  int * v21252 = v21249->regs;
  int v21253 = v21252[22];
  int v21254 = v21252[24];
  int v21262 = v21253 | v21254;
  v21252[22] = v21262;
  struct StateT * v21256 = slot_350(v21249);
  return v21256;
}

struct StateT * slot_291(struct StateT * v20344) {
  int v20345 = v20344->timer;
  int v20352 = v20345 + 1;
  v20344->timer = v20352;
  int * v20347 = v20344->regs;
  int v20348 = v20347[23];
  int v20355 = v20348 << 13;
  v20347[23] = v20355;
  struct StateT * v20350 = slot_292(v20344);
  return v20350;
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

struct StateT * slot_410(struct StateT * v22228) {
  int v22229 = v22228->timer;
  int v22236 = v22229 + 1;
  v22228->timer = v22236;
  int * v22231 = v22228->regs;
  int v22232 = v22231[22];
  int v22239 = v22232 << 7;
  v22231[22] = v22239;
  struct StateT * v22234 = slot_411(v22228);
  return v22234;
}

struct StateT * slot_491(struct StateT * v23602) {
  int v23603 = v23602->timer;
  int v23611 = v23603 + 1;
  v23602->timer = v23611;
  int * v23605 = v23602->regs;
  int v23606 = v23605[22];
  int v23607 = v23605[24];
  int v23615 = v23606 | v23607;
  v23605[22] = v23615;
  struct StateT * v23609 = slot_492(v23602);
  return v23609;
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

struct StateT * slot_422(struct StateT * v22446) {
  int v22447 = v22446->timer;
  int v22455 = v22447 + 1;
  v22446->timer = v22455;
  int * v22449 = v22446->regs;
  int v22450 = v22449[8];
  int v22451 = v22449[31];
  int v22460 = v22450 + v22451;
  v22449[23] = v22460;
  struct StateT * v22453 = slot_423(v22446);
  return v22453;
}

struct StateT * slot_448(struct StateT * v22877) {
  int v22878 = v22877->timer;
  int v22886 = v22878 + 1;
  v22877->timer = v22886;
  int * v22880 = v22877->regs;
  int v22881 = v22880[21];
  int v22882 = v22880[24];
  int v22890 = v22881 | v22882;
  v22880[21] = v22890;
  struct StateT * v22884 = slot_449(v22877);
  return v22884;
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
    struct StateT * v8869 = slot_201(v8776);
    v8873 = v8869;
  } else {
    struct StateT * v8871 = slot_196(v8776);
    v8873 = v8871;
  }
  return v8873;
}

struct StateT * slot_551(struct StateT * v24538) {
  int v24539 = v24538->timer;
  int v24547 = v24539 + 1;
  v24538->timer = v24547;
  int * v24541 = v24538->regs;
  int v24542 = v24541[22];
  int v24543 = v24541[24];
  int v24551 = v24542 | v24543;
  v24541[22] = v24551;
  struct StateT * v24545 = slot_552(v24538);
  return v24545;
}

struct StateT * slot_407(struct StateT * v22183) {
  int v22184 = v22183->timer;
  int v22191 = v22184 + 1;
  v22183->timer = v22191;
  int * v22186 = v22183->regs;
  int v22187 = v22186[21];
  int v22194 = v22187 << 7;
  v22186[21] = v22194;
  struct StateT * v22189 = slot_408(v22183);
  return v22189;
}

struct StateT * slot_543(struct StateT * v24419) {
  int v24420 = v24419->timer;
  int v24427 = v24420 + 1;
  v24419->timer = v24427;
  int * v24422 = v24419->regs;
  int v24423 = v24422[20];
  int v24431 = (int)((unsigned int)v24423 >> 14);
  v24422[24] = v24431;
  struct StateT * v24425 = slot_544(v24419);
  return v24425;
}

struct StateT * slot_360(struct StateT * v21425) {
  int v21426 = v21425->timer;
  int v21434 = v21426 + 1;
  v21425->timer = v21434;
  int * v21428 = v21425->regs;
  int v21429 = v21428[7];
  int v21430 = v21428[16];
  int v21439 = v21429 + v21430;
  v21428[23] = v21439;
  struct StateT * v21432 = slot_361(v21425);
  return v21432;
}

struct StateT * slot_259(struct StateT * v19848) {
  int v19849 = v19848->timer;
  int v19857 = v19849 + 1;
  v19848->timer = v19857;
  int * v19851 = v19848->regs;
  int v19852 = v19851[19];
  int v19853 = v19851[28];
  int v19862 = v19852 + v19853;
  v19851[22] = v19862;
  struct StateT * v19855 = slot_260(v19848);
  return v19855;
}

struct StateT * slot_469(struct StateT * v23233) {
  int v23234 = v23233->timer;
  int v23241 = v23234 + 1;
  v23233->timer = v23241;
  int * v23236 = v23233->regs;
  int v23237 = v23236[22];
  int v23245 = (int)((unsigned int)v23237 >> 14);
  v23236[24] = v23245;
  struct StateT * v23239 = slot_470(v23233);
  return v23239;
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