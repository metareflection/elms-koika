// verify: leak (Eva should report untainted_timer: unknown) [unroll 513]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 512
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[512];
  int timer;
};

void ret_assert(bool);

struct StateG * slot_120(struct StateG * v2372);
struct StateG * slot_167(struct StateG * v3340);
struct StateG * slot_509(struct StateG * v10924);
struct StateG * slot_152(struct StateG * v3180);
struct StateG * slot_231(struct StateG * v4496);
struct StateG * slot_355(struct StateG * v7200);
struct StateG * slot_616(struct StateG * v12644);
struct StateG * slot_232(struct StateG * v4516);
struct StateG * slot_466(struct StateG * v9644);
struct StateG * slot_764(struct StateG * v15588);
struct StateG * slot_304(struct StateG * v6236);
struct StateG * slot_31(struct StateG * v778);
struct StateG * slot_730(struct StateG * v15146);
struct StateG * slot_585(struct StateG * v12129);
struct StateG * slot_241(struct StateG * v4876);
struct StateG * slot_611(struct StateG * v12544);
struct StateG * slot_160(struct StateG * v3264);
struct StateG * slot_745(struct StateG * v15341);
struct StateG * slot_150(struct StateG * v3159);
struct StateG * slot_391(struct StateG * v8540);
struct StateG * slot_74(struct StateG * v1641);
struct StateG * slot_372(struct StateG * v7780);
struct StateG * slot_403(struct StateG * v8698);
struct StateG * slot_325(struct StateG * v6600);
struct StateG * slot_686(struct StateG * v14623);
struct StateG * slot_895(struct StateG * v18408);
struct StateG * slot_28(struct StateG * v664);
struct StateG * slot_517(struct StateG * v11244);
struct StateG * slot_566(struct StateG * v11882);
struct StateG * slot_154(struct StateG * v3201);
struct StateG * slot_260(struct StateG * v5636);
struct StateG * slot_305(struct StateG * v6249);
struct StateG * slot_662(struct StateG * v13844);
struct StateG * slot_34(struct StateG * v837);
struct StateG * slot_850(struct StateG * v17742);
struct StateG * slot_21(struct StateG * v531);
struct StateG * slot_118(struct StateG * v2332);
struct StateG * slot_515(struct StateG * v11164);
struct StateG * slot_833(struct StateG * v17064);
struct StateG * slot_376(struct StateG * v7940);
struct StateG * slot_373(struct StateG * v7820);
struct StateG * slot_146(struct StateG * v3117);
struct StateG * slot_383(struct StateG * v8220);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_489(struct StateG * v10124);
struct StateG * slot_148(struct StateG * v3138);
struct StateG * slot_421(struct StateG * v8882);
struct StateG * slot_725(struct StateG * v15078);
struct StateG * slot_918(struct StateG * v18604);
struct StateG * slot_79(struct StateG * v1696);
struct StateG * slot_568(struct StateG * v11908);
struct StateG * slot_810(struct StateG * v16424);
struct StateG * slot_571(struct StateG * v11947);
struct StateG * slot_142(struct StateG * v3075);
struct StateG * slot_416(struct StateG * v8832);
struct StateG * slot_624(struct StateG * v12804);
struct StateG * slot_738(struct StateG * v15250);
struct StateG * slot_214(struct StateG * v4156);
struct StateG * slot_29(struct StateG * v702);
struct StateG * slot_151(struct StateG * v3172);
struct StateG * slot_7(struct StateG * v298);
struct StateG * slot_124(struct StateG * v2532);
struct StateG * slot_601(struct StateG * v12344);
struct StateG * slot_128(struct StateG * v2692);
struct StateG * slot_365(struct StateG * v7500);
struct StateG * slot_622(struct StateG * v12764);
struct StateG * slot_523(struct StateG * v11398);
struct StateG * slot_782(struct StateG * v15864);
struct StateG * slot_87(struct StateG * v1780);
struct StateG * slot_452(struct StateG * v9364);
struct StateG * slot_67(struct StateG * v1420);
struct StateG * slot_591(struct StateG * v12207);
struct StateG * slot_81(struct StateG * v1712);
struct StateG * slot_546(struct StateG * v11637);
struct StateG * slot_32(struct StateG * v816);
struct StateG * slot_861(struct StateG * v18024);
struct StateG * slot_189(struct StateG * v3656);
struct StateG * slot_394(struct StateG * v8601);
struct StateG * slot_33(struct StateG * v824);
struct StateG * slot_743(struct StateG * v15315);
struct StateG * slot_371(struct StateG * v7740);
struct StateG * slot_680(struct StateG * v14560);
struct StateG * slot_672(struct StateG * v14244);
struct StateG * slot_709(struct StateG * v14862);
struct StateG * slot_35(struct StateG * v850);
struct StateG * slot_484(struct StateG * v10004);
struct StateG * slot_258(struct StateG * v5556);
struct StateG * slot_744(struct StateG * v15328);
struct StateG * slot_615(struct StateG * v12624);
struct StateG * slot_51(struct StateG * v1047);
struct StateG * slot_25(struct StateG * v604);
struct StateG * slot_731(struct StateG * v15159);
struct StateG * slot_490(struct StateG * v10164);
struct StateG * slot_123(struct StateG * v2492);
struct StateG * slot_733(struct StateG * v15185);
struct StateG * slot_702(struct StateG * v14791);
struct StateG * slot_799(struct StateG * v16204);
struct StateG * slot_299(struct StateG * v6171);
struct StateG * slot_539(struct StateG * v11566);
struct StateG * slot_319(struct StateG * v6480);
struct StateG * slot_656(struct StateG * v13604);
struct StateG * slot_671(struct StateG * v14204);
struct StateG * slot_344(struct StateG * v6980);
struct StateG * slot_794(struct StateG * v16104);
struct StateG * slot_687(struct StateG * v14636);
struct StateG * slot_497(struct StateG * v10444);
struct StateG * slot_455(struct StateG * v9424);
struct StateG * slot_843(struct StateG * v17464);
struct StateG * slot_742(struct StateG * v15302);
struct StateG * slot_560(struct StateG * v11804);
struct StateG * slot_240(struct StateG * v4836);
struct StateG * slot_754(struct StateG * v15458);
struct StateG * slot_548(struct StateG * v11658);
struct StateG * slot_70(struct StateG * v1540);
struct StateG * slot_348(struct StateG * v7060);
struct StateG * slot_734(struct StateG * v15198);
struct StateG * slot_467(struct StateG * v9664);
struct StateG * slot_749(struct StateG * v15393);
struct StateG * slot_883(struct StateG * v18260);
struct StateG * slot_293(struct StateG * v6098);
struct StateG * slot_288(struct StateG * v6048);
struct StateG * slot_683(struct StateG * v14594);
struct StateG * slot_89(struct StateG * v1801);
struct StateG * slot_347(struct StateG * v7040);
struct StateG * slot_741(struct StateG * v15289);
struct StateG * slot_140(struct StateG * v3054);
struct StateG * slot_778(struct StateG * v15784);
struct StateG * slot_473(struct StateG * v9784);
struct StateG * slot_706(struct StateG * v14833);
struct StateG * slot_135(struct StateG * v2972);
struct StateG * slot_767(struct StateG * v15627);
struct StateG * slot_485(struct StateG * v10024);
struct StateG * slot_40(struct StateG * v900);
struct StateG * slot_586(struct StateG * v12142);
struct StateG * slot_784(struct StateG * v15904);
struct StateG * slot_85(struct StateG * v1754);
struct StateG * slot_707(struct StateG * v14846);
struct StateG * slot_75(struct StateG * v1654);
struct StateG * slot_581(struct StateG * v12077);
struct StateG * slot_772(struct StateG * v15692);
struct StateG * slot_619(struct StateG * v12704);
struct StateG * slot_405(struct StateG * v8714);
struct StateG * slot_828(struct StateG * v16864);
struct StateG * slot_579(struct StateG * v12051);
struct StateG * slot_463(struct StateG * v9584);
struct StateG * slot_175(struct StateG * v3439);
struct StateG * slot_387(struct StateG * v8380);
struct StateG * slot_621(struct StateG * v12744);
struct StateG * slot_777(struct StateG * v15764);
struct StateG * slot_565(struct StateG * v11869);
struct StateG * slot_188(struct StateG * v3636);
struct StateG * slot_758(struct StateG * v15510);
struct StateG * slot_495(struct StateG * v10364);
struct StateG * slot_110(struct StateG * v2172);
struct StateG * slot_301(struct StateG * v6197);
struct StateG * slot_502(struct StateG * v10644);
struct StateG * slot_320(struct StateG * v6500);
struct StateG * slot_756(struct StateG * v15484);
struct StateG * slot_727(struct StateG * v15106);
struct StateG * slot_203(struct StateG * v3936);
struct StateG * slot_157(struct StateG * v3230);
struct StateG * slot_587(struct StateG * v12155);
struct StateG * slot_453(struct StateG * v9384);
struct StateG * slot_712(struct StateG * v14896);
struct StateG * slot_26(struct StateG * v624);
struct StateG * slot_370(struct StateG * v7700);
struct StateG * slot_652(struct StateG * v13444);
struct StateG * slot_583(struct StateG * v12103);
struct StateG * slot_817(struct StateG * v16564);
struct StateG * slot_206(struct StateG * v3996);
struct StateG * slot_169(struct StateG * v3361);
struct StateG * slot_858(struct StateG * v17995);
struct StateG * slot_14(struct StateG * v438);
struct StateG * slot_357(struct StateG * v7240);
struct StateG * slot_385(struct StateG * v8300);
struct StateG * slot_602(struct StateG * v12364);
struct StateG * slot_261(struct StateG * v5676);
struct StateG * slot_838(struct StateG * v17264);
struct StateG * slot_603(struct StateG * v12384);
struct StateG * slot_740(struct StateG * v15276);
struct StateG * slot_831(struct StateG * v16984);
struct StateG * slot_639(struct StateG * v13104);
struct StateG * slot_36(struct StateG * v858);
struct StateG * slot_57(struct StateG * v1160);
struct StateG * slot_426(struct StateG * v8942);
struct StateG * slot_431(struct StateG * v9007);
struct StateG * slot_729(struct StateG * v15133);
struct StateG * slot_62(struct StateG * v1260);
struct StateG * slot_308(struct StateG * v6288);
struct StateG * slot_400(struct StateG * v8664);
struct StateG * slot_323(struct StateG * v6560);
struct StateG * slot_628(struct StateG * v12884);
struct StateG * slot_521(struct StateG * v11372);
struct StateG * slot_530(struct StateG * v11469);
struct StateG * slot_23(struct StateG * v564);
struct StateG * slot_2(struct StateG * v219);
struct StateG * slot_86(struct StateG * v1767);
struct StateG * slot_836(struct StateG * v17184);
struct StateG * slot_538(struct StateG * v11553);
struct StateG * slot_693(struct StateG * v14694);
struct StateG * slot_100(struct StateG * v1972);
struct StateG * slot_747(struct StateG * v15367);
struct StateG * slot_13(struct StateG * v430);
struct StateG * slot_449(struct StateG * v9304);
struct StateG * slot_569(struct StateG * v11921);
struct StateG * slot_460(struct StateG * v9524);
struct StateG * slot_109(struct StateG * v2152);
struct StateG * slot_629(struct StateG * v12904);
struct StateG * slot_609(struct StateG * v12504);
struct StateG * slot_224(struct StateG * v4356);
struct StateG * slot_796(struct StateG * v16144);
struct StateG * slot_184(struct StateG * v3556);
struct StateG * slot_562(struct StateG * v11830);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_584(struct StateG * v12116);
struct StateG * slot_393(struct StateG * v8588);
struct StateG * slot_477(struct StateG * v9864);
struct StateG * slot_761(struct StateG * v15549);
struct StateG * slot_690(struct StateG * v14665);
struct StateG * slot_352(struct StateG * v7140);
struct StateG * slot_561(struct StateG * v11817);
struct StateG * slot_249(struct StateG * v5196);
struct StateG * slot_11(struct StateG * v404);
struct StateG * slot_228(struct StateG * v4436);
struct StateG * slot_268(struct StateG * v5838);
struct StateG * slot_199(struct StateG * v3856);
struct StateG * slot_653(struct StateG * v13484);
struct StateG * slot_409(struct StateG * v8756);
struct StateG * slot_822(struct StateG * v16664);
struct StateG * slot_269(struct StateG * v5846);
struct StateG * slot_827(struct StateG * v16824);
struct StateG * slot_681(struct StateG * v14568);
struct StateG * slot_501(struct StateG * v10604);
struct StateG * slot_854(struct StateG * v17898);
struct StateG * slot_612(struct StateG * v12564);
struct StateG * slot_572(struct StateG * v11960);
struct StateG * slot_435(struct StateG * v9059);
struct StateG * slot_136(struct StateG * v3012);
struct StateG * slot_379(struct StateG * v8060);
struct StateG * slot_746(struct StateG * v15354);
struct StateG * slot_475(struct StateG * v9824);
struct StateG * slot_310(struct StateG * v6314);
struct StateG * slot_445(struct StateG * v9224);
struct StateG * slot_197(struct StateG * v3816);
struct StateG * slot_457(struct StateG * v9464);
struct StateG * slot_663(struct StateG * v13884);
struct StateG * slot_68(struct StateG * v1460);
struct StateG * slot_493(struct StateG * v10284);
struct StateG * slot_105(struct StateG * v2072);
struct StateG * slot_15(struct StateG * v452);
struct StateG * slot_699(struct StateG * v14762);
struct StateG * slot_480(struct StateG * v9924);
struct StateG * slot_769(struct StateG * v15653);
struct StateG * slot_244(struct StateG * v4996);
struct StateG * slot_222(struct StateG * v4316);
struct StateG * slot_171(struct StateG * v3387);
struct StateG * slot_162(struct StateG * v3285);
struct StateG * slot_634(struct StateG * v13004);
struct StateG * slot_552(struct StateG * v11700);
struct StateG * slot_399(struct StateG * v8656);
struct StateG * slot_239(struct StateG * v4796);
struct StateG * slot_500(struct StateG * v10564);
struct StateG * slot_267(struct StateG * v5830);
struct StateG * slot_570(struct StateG * v11934);
struct StateG * slot_511(struct StateG * v11004);
struct StateG * slot_848(struct StateG * v17664);
struct StateG * slot_316(struct StateG * v6420);
struct StateG * slot_424(struct StateG * v8916);
struct StateG * slot_332(struct StateG * v6740);
struct StateG * slot_39(struct StateG * v892);
struct StateG * slot_508(struct StateG * v10884);
struct StateG * slot_736(struct StateG * v15224);
struct StateG * slot_60(struct StateG * v1220);
struct StateG * slot_765(struct StateG * v15601);
struct StateG * slot_112(struct StateG * v2212);
struct StateG * slot_256(struct StateG * v5476);
struct StateG * slot_798(struct StateG * v16184);
struct StateG * slot_801(struct StateG * v16244);
struct StateG * slot_567(struct StateG * v11895);
struct StateG * slot_16(struct StateG * v466);
struct StateG * slot_113(struct StateG * v2232);
struct StateG * slot_302(struct StateG * v6210);
struct StateG * slot_191(struct StateG * v3696);
struct StateG * slot_487(struct StateG * v10064);
struct StateG * slot_645(struct StateG * v13224);
struct StateG * slot_633(struct StateG * v12984);
struct StateG * slot_95(struct StateG * v1879);
struct StateG * slot_354(struct StateG * v7180);
struct StateG * slot_115(struct StateG * v2272);
struct StateG * slot_78(struct StateG * v1683);
struct StateG * slot_674(struct StateG * v14324);
struct StateG * slot_554(struct StateG * v11726);
struct StateG * slot_650(struct StateG * v13364);
struct StateG * slot_752(struct StateG * v15432);
struct StateG * slot_331(struct StateG * v6720);
struct StateG * slot_676(struct StateG * v14404);
struct StateG * slot_412(struct StateG * v8790);
struct StateG * slot_381(struct StateG * v8140);
struct StateG * slot_646(struct StateG * v13244);
struct StateG * slot_627(struct StateG * v12864);
struct StateG * slot_675(struct StateG * v14364);
struct StateG * slot_845(struct StateG * v17544);
struct StateG * slot_837(struct StateG * v17224);
struct StateG * slot_210(struct StateG * v4076);
struct StateG * slot_472(struct StateG * v9764);
struct StateG * slot_657(struct StateG * v13644);
struct StateG * slot_739(struct StateG * v15263);
struct StateG * slot_52(struct StateG * v1060);
struct StateG * slot_83(struct StateG * v1738);
struct StateG * slot_209(struct StateG * v4056);
struct StateG * slot_420(struct StateG * v8874);
struct StateG * slot_853(struct StateG * v17860);
struct StateG * slot_73(struct StateG * v1628);
struct StateG * slot_270(struct StateG * v5859);
struct StateG * slot_198(struct StateG * v3836);
struct StateG * slot_187(struct StateG * v3616);
struct StateG * slot_182(struct StateG * v3530);
struct StateG * slot_361(struct StateG * v7340);
struct StateG * slot_178(struct StateG * v3478);
struct StateG * slot_98(struct StateG * v1932);
struct StateG * slot_510(struct StateG * v10964);
struct StateG * slot_404(struct StateG * v8706);
struct StateG * slot_46(struct StateG * v982);
struct StateG * slot_212(struct StateG * v4116);
struct StateG * slot_682(struct StateG * v14581);
struct StateG * slot_20(struct StateG * v518);
struct StateG * slot_61(struct StateG * v1240);
struct StateG * slot_499(struct StateG * v10524);
struct StateG * slot_359(struct StateG * v7280);
struct StateG * slot_514(struct StateG * v11124);
struct StateG * slot_30(struct StateG * v740);
struct StateG * slot_606(struct StateG * v12444);
struct StateG * slot_300(struct StateG * v6184);
struct StateG * slot_183(struct StateG * v3543);
struct StateG * slot_309(struct StateG * v6301);
struct StateG * slot_6(struct StateG * v278);
struct StateG * slot_283(struct StateG * v5998);
struct StateG * slot_516(struct StateG * v11204);
struct StateG * slot_599(struct StateG * v12311);
struct StateG * slot_694(struct StateG * v14707);
struct StateG * slot_785(struct StateG * v15924);
struct StateG * slot_540(struct StateG * v11574);
struct StateG * slot_697(struct StateG * v14736);
struct StateG * slot_617(struct StateG * v12664);
struct StateG * slot_37(struct StateG * v866);
struct StateG * slot_114(struct StateG * v2252);
struct StateG * slot_257(struct StateG * v5516);
struct StateG * slot_327(struct StateG * v6640);
struct StateG * slot_396(struct StateG * v8622);
struct StateG * slot_528(struct StateG * v11448);
struct StateG * slot_813(struct StateG * v16484);
struct StateG * slot_72(struct StateG * v1620);
struct StateG * slot_526(struct StateG * v11427);
struct StateG * slot_101(struct StateG * v1992);
struct StateG * slot_795(struct StateG * v16124);
struct StateG * slot_93(struct StateG * v1853);
struct StateG * slot_803(struct StateG * v16284);
struct StateG * slot_266(struct StateG * v5817);
struct StateG * slot_88(struct StateG * v1788);
struct StateG * slot_96(struct StateG * v1892);
struct StateG * slot_471(struct StateG * v9744);
struct StateG * slot_419(struct StateG * v8866);
struct StateG * slot_336(struct StateG * v6820);
struct StateG * slot_685(struct StateG * v14610);
struct StateG * slot_598(struct StateG * v12298);
struct StateG * slot_408(struct StateG * v8748);
struct StateG * slot_342(struct StateG * v6940);
struct StateG * slot_389(struct StateG * v8460);
struct StateG * slot_678(struct StateG * v14482);
struct StateG * slot_138(struct StateG * v3033);
struct StateG * slot_483(struct StateG * v9984);
struct StateG * slot_791(struct StateG * v16044);
struct StateG * slot_649(struct StateG * v13324);
struct StateG * slot_425(struct StateG * v8929);
struct StateG * slot_131(struct StateG * v2812);
struct StateG * slot_504(struct StateG * v10724);
struct StateG * slot_496(struct StateG * v10404);
struct StateG * slot_242(struct StateG * v4916);
struct StateG * slot_605(struct StateG * v12424);
struct StateG * slot_757(struct StateG * v15497);
struct StateG * slot_200(struct StateG * v3876);
struct StateG * slot_334(struct StateG * v6780);
struct StateG * slot_104(struct StateG * v2052);
struct StateG * slot_329(struct StateG * v6680);
struct StateG * slot_395(struct StateG * v8614);
struct StateG * slot_604(struct StateG * v12404);
struct StateG * slot_298(struct StateG * v6158);
struct StateG * slot_626(struct StateG * v12844);
struct StateG * slot_839(struct StateG * v17304);
struct StateG * slot_253(struct StateG * v5356);
struct StateG * slot_64(struct StateG * v1300);
struct StateG * slot_170(struct StateG * v3374);
struct StateG * slot_53(struct StateG * v1080);
struct StateG * slot_503(struct StateG * v10684);
struct StateG * slot_829(struct StateG * v16904);
struct StateG * slot_635(struct StateG * v13024);
struct StateG * slot_386(struct StateG * v8340);
struct StateG * slot_840(struct StateG * v17344);
struct StateG * slot_99(struct StateG * v1952);
struct StateG * slot_219(struct StateG * v4256);
struct StateG * slot_664(struct StateG * v13924);
struct StateG * slot_855(struct StateG * v17936);
struct StateG * slot_22(struct StateG * v544);
struct StateG * slot_139(struct StateG * v3046);
struct StateG * slot_654(struct StateG * v13524);
struct StateG * slot_790(struct StateG * v16024);
struct StateG * slot_786(struct StateG * v15944);
struct StateG * slot_608(struct StateG * v12484);
struct StateG * slot_333(struct StateG * v6760);
struct StateG * slot_221(struct StateG * v4296);
struct StateG * slot_797(struct StateG * v16164);
struct StateG * slot_623(struct StateG * v12784);
struct StateG * slot_153(struct StateG * v3188);
struct StateG * slot_129(struct StateG * v2732);
struct StateG * slot_158(struct StateG * v3243);
struct StateG * slot_498(struct StateG * v10484);
struct StateG * slot_648(struct StateG * v13284);
struct StateG * slot_575(struct StateG * v11999);
struct StateG * slot_271(struct StateG * v5872);
struct StateG * slot_524(struct StateG * v11406);
struct StateG * slot_808(struct StateG * v16384);
struct StateG * slot_505(struct StateG * v10764);
struct StateG * slot_532(struct StateG * v11490);
struct StateG * slot_410(struct StateG * v8769);
struct StateG * slot_844(struct StateG * v17504);
struct StateG * slot_204(struct StateG * v3956);
struct StateG * slot_194(struct StateG * v3756);
struct StateG * slot_551(struct StateG * v11692);
struct StateG * slot_641(struct StateG * v13144);
struct StateG * slot_821(struct StateG * v16644);
struct StateG * slot_543(struct StateG * v11608);
struct StateG * slot_826(struct StateG * v16784);
struct StateG * slot_117(struct StateG * v2312);
struct StateG * slot_667(struct StateG * v14044);
struct StateG * slot_90(struct StateG * v1814);
struct StateG * slot_748(struct StateG * v15380);
struct StateG * slot_143(struct StateG * v3088);
struct StateG * slot_226(struct StateG * v4396);
struct StateG * slot_429(struct StateG * v8981);
struct StateG * slot_92(struct StateG * v1840);
struct StateG * slot_787(struct StateG * v15964);
struct StateG * slot_236(struct StateG * v4676);
struct StateG * slot_703(struct StateG * v14804);
struct StateG * slot_849(struct StateG * v17703);
struct StateG * slot_519(struct StateG * v11324);
struct StateG * slot_580(struct StateG * v12064);
struct StateG * slot_262(struct StateG * v5716);
struct StateG * slot_351(struct StateG * v7120);
struct StateG * slot_677(struct StateG * v14443);
struct StateG * slot_774(struct StateG * v15718);
struct StateG * slot_107(struct StateG * v2112);
struct StateG * slot_555(struct StateG * v11739);
struct StateG * slot_541(struct StateG * v11582);
struct StateG * slot_711(struct StateG * v14888);
struct StateG * slot_84(struct StateG * v1746);
struct StateG * slot_155(struct StateG * v3214);
struct StateG * slot_177(struct StateG * v3465);
struct StateG * slot_229(struct StateG * v4456);
struct StateG * slot_358(struct StateG * v7260);
struct StateG * slot_465(struct StateG * v9624);
struct StateG * slot_780(struct StateG * v15824);
struct StateG * slot_181(struct StateG * v3517);
struct StateG * slot_542(struct StateG * v11595);
struct StateG * slot_679(struct StateG * v14521);
struct StateG * slot_669(struct StateG * v14124);
struct StateG * slot_805(struct StateG * v16324);
struct StateG * slot_481(struct StateG * v9944);
struct StateG * slot_620(struct StateG * v12724);
struct StateG * slot_27(struct StateG * v644);
struct StateG * slot_818(struct StateG * v16584);
struct StateG * slot_454(struct StateG * v9404);
struct StateG * slot_830(struct StateG * v16944);
struct StateG * slot_482(struct StateG * v9964);
struct StateG * slot_689(struct StateG * v14652);
struct StateG * slot_406(struct StateG * v8727);
struct StateG * slot_292(struct StateG * v6090);
struct StateG * slot_776(struct StateG * v15744);
struct StateG * slot_525(struct StateG * v11414);
struct StateG * slot_666(struct StateG * v14004);
struct StateG * slot_589(struct StateG * v12181);
struct StateG * slot_94(struct StateG * v1866);
struct StateG * slot_340(struct StateG * v6900);
struct StateG * slot_846(struct StateG * v17584);
struct StateG * slot_24(struct StateG * v584);
struct StateG * slot_673(struct StateG * v14284);
struct StateG * slot_286(struct StateG * v6027);
struct StateG * slot_520(struct StateG * v11364);
struct StateG * slot_125(struct StateG * v2572);
struct StateG * slot_726(struct StateG * v15092);
struct StateG * slot_254(struct StateG * v5396);
struct StateG * slot_126(struct StateG * v2612);
struct StateG * slot_363(struct StateG * v7420);
struct StateG * slot_816(struct StateG * v16544);
struct StateG * slot_578(struct StateG * v12038);
struct StateG * slot_661(struct StateG * v13804);
struct StateG * slot_842(struct StateG * v17424);
struct StateG * slot_732(struct StateG * v15172);
struct StateG * slot_367(struct StateG * v7580);
struct StateG * slot_437(struct StateG * v9085);
struct StateG * slot_724(struct StateG * v15064);
struct StateG * slot_341(struct StateG * v6920);
struct StateG * slot_280(struct StateG * v5964);
struct StateG * slot_779(struct StateG * v15804);
struct StateG * slot_272(struct StateG * v5880);
struct StateG * slot_47(struct StateG * v995);
struct StateG * slot_297(struct StateG * v6145);
struct StateG * slot_715(struct StateG * v14938);
struct StateG * slot_314(struct StateG * v6380);
struct StateG * slot_638(struct StateG * v13084);
struct StateG * slot_441(struct StateG * v9144);
struct StateG * slot_19(struct StateG * v505);
struct StateG * slot_382(struct StateG * v8180);
struct StateG * slot_556(struct StateG * v11752);
struct StateG * slot_651(struct StateG * v13404);
struct StateG * slot_337(struct StateG * v6840);
struct StateG * slot_233(struct StateG * v4556);
struct StateG * slot_595(struct StateG * v12259);
struct StateG * slot_176(struct StateG * v3452);
struct StateG * slot_398(struct StateG * v8643);
struct StateG * slot_330(struct StateG * v6700);
struct StateG * slot_450(struct StateG * v9324);
struct StateG * slot_713(struct StateG * v14910);
struct StateG * slot_819(struct StateG * v16604);
struct StateG * slot_166(struct StateG * v3327);
struct StateG * slot_418(struct StateG * v8853);
struct StateG * slot_264(struct StateG * v5796);
struct StateG * slot_339(struct StateG * v6880);
struct StateG * slot_811(struct StateG * v16444);
struct StateG * slot_97(struct StateG * v1912);
struct StateG * slot_594(struct StateG * v12246);
struct StateG * slot_106(struct StateG * v2092);
struct StateG * slot_809(struct StateG * v16404);
struct StateG * slot_513(struct StateG * v11084);
struct StateG * slot_130(struct StateG * v2772);
struct StateG * slot_141(struct StateG * v3062);
struct StateG * slot_701(struct StateG * v14778);
struct StateG * slot_432(struct StateG * v9020);
struct StateG * slot_306(struct StateG * v6262);
struct StateG * slot_312(struct StateG * v6340);
struct StateG * slot_4(struct StateG * v245);
struct StateG * slot_705(struct StateG * v14820);
struct StateG * slot_247(struct StateG * v5116);
struct StateG * slot_168(struct StateG * v3348);
struct StateG * slot_456(struct StateG * v9444);
struct StateG * slot_225(struct StateG * v4376);
struct StateG * slot_285(struct StateG * v6014);
struct StateG * slot_659(struct StateG * v13724);
struct StateG * slot_213(struct StateG * v4136);
struct StateG * slot_82(struct StateG * v1725);
struct StateG * slot_632(struct StateG * v12964);
struct StateG * slot_642(struct StateG * v13164);
struct StateG * slot_691(struct StateG * v14678);
struct StateG * slot_590(struct StateG * v12194);
struct StateG * slot_263(struct StateG * v5756);
struct StateG * slot_161(struct StateG * v3272);
struct StateG * slot_185(struct StateG * v3576);
struct StateG * slot_804(struct StateG * v16304);
struct StateG * slot_384(struct StateG * v8260);
struct StateG * slot_486(struct StateG * v10044);
struct StateG * slot_49(struct StateG * v1021);
struct StateG * slot_216(struct StateG * v4196);
struct StateG * slot_468(struct StateG * v9684);
struct StateG * slot_50(struct StateG * v1034);
struct StateG * slot_248(struct StateG * v5156);
struct StateG * slot_59(struct StateG * v1200);
struct StateG * slot_721(struct StateG * v15022);
struct StateG * slot_77(struct StateG * v1670);
struct StateG * slot_350(struct StateG * v7100);
struct StateG * slot_392(struct StateG * v8580);
struct StateG * slot_771(struct StateG * v15679);
struct StateG * slot_625(struct StateG * v12824);
struct StateG * slot_71(struct StateG * v1580);
struct StateG * slot_378(struct StateG * v8020);
struct StateG * slot_800(struct StateG * v16224);
struct StateG * slot_108(struct StateG * v2132);
struct StateG * slot_116(struct StateG * v2292);
struct StateG * slot_618(struct StateG * v12684);
struct StateG * slot_417(struct StateG * v8840);
struct StateG * slot_762(struct StateG * v15562);
struct StateG * slot_766(struct StateG * v15614);
struct StateG * slot_215(struct StateG * v4176);
struct StateG * slot_45(struct StateG * v969);
struct StateG * slot_220(struct StateG * v4276);
struct StateG * slot_134(struct StateG * v2932);
struct StateG * slot_273(struct StateG * v5888);
struct StateG * slot_69(struct StateG * v1500);
struct StateG * slot_644(struct StateG * v13204);
struct StateG * slot_723(struct StateG * v15050);
struct StateG * slot_751(struct StateG * v15419);
struct StateG * slot_186(struct StateG * v3596);
struct StateG * slot_102(struct StateG * v2012);
struct StateG * slot_145(struct StateG * v3104);
struct StateG * slot_208(struct StateG * v4036);
struct StateG * slot_506(struct StateG * v10804);
struct StateG * slot_413(struct StateG * v8798);
struct StateG * slot_281(struct StateG * v5972);
struct StateG * slot_533(struct StateG * v11498);
struct StateG * slot_190(struct StateG * v3676);
struct StateG * slot_447(struct StateG * v9264);
struct StateG * slot_719(struct StateG * v14994);
struct StateG * slot_559(struct StateG * v11791);
struct StateG * slot_243(struct StateG * v4956);
struct StateG * slot_173(struct StateG * v3413);
struct StateG * slot_750(struct StateG * v15406);
struct StateG * slot_814(struct StateG * v16504);
struct StateG * slot_307(struct StateG * v6275);
struct StateG * slot_54(struct StateG * v1100);
struct StateG * slot_735(struct StateG * v15211);
struct StateG * slot_227(struct StateG * v4416);
struct StateG * slot_442(struct StateG * v9164);
struct StateG * slot_529(struct StateG * v11456);
struct StateG * slot_807(struct StateG * v16364);
struct StateG * slot_710(struct StateG * v14875);
struct StateG * slot_444(struct StateG * v9204);
struct StateG * slot_824(struct StateG * v16704);
struct StateG * slot_287(struct StateG * v6040);
struct StateG * slot_343(struct StateG * v6960);
struct StateG * slot_755(struct StateG * v15471);
struct StateG * slot_728(struct StateG * v15120);
struct StateG * slot_536(struct StateG * v11532);
struct StateG * slot_470(struct StateG * v9724);
struct StateG * slot_670(struct StateG * v14164);
struct StateG * slot_127(struct StateG * v2652);
struct StateG * slot_640(struct StateG * v13124);
struct StateG * slot_411(struct StateG * v8782);
struct StateG * slot_783(struct StateG * v15884);
struct StateG * slot_834(struct StateG * v17104);
struct StateG * slot_688(struct StateG * v14644);
struct StateG * slot_474(struct StateG * v9804);
struct StateG * slot_174(struct StateG * v3426);
struct StateG * slot_42(struct StateG * v928);
struct StateG * slot_720(struct StateG * v15008);
struct StateG * slot_588(struct StateG * v12168);
struct StateG * slot_825(struct StateG * v16744);
struct StateG * slot_462(struct StateG * v9564);
struct StateG * slot_165(struct StateG * v3314);
struct StateG * slot_557(struct StateG * v11765);
struct StateG * slot_507(struct StateG * v10844);
struct StateG * slot_278(struct StateG * v5943);
struct StateG * slot_577(struct StateG * v12025);
struct StateG * slot_806(struct StateG * v16344);
struct StateG * slot_12(struct StateG * v417);
struct StateG * slot_716(struct StateG * v14952);
struct StateG * slot_252(struct StateG * v5316);
struct StateG * slot_374(struct StateG * v7860);
struct StateG * slot_582(struct StateG * v12090);
struct StateG * slot_251(struct StateG * v5276);
struct StateG * slot_65(struct StateG * v1340);
struct StateG * slot_10(struct StateG * v396);
struct StateG * slot_322(struct StateG * v6540);
struct StateG * slot_714(struct StateG * v14924);
struct StateG * slot_593(struct StateG * v12233);
struct StateG * slot_277(struct StateG * v5930);
struct StateG * slot_692(struct StateG * v14686);
struct StateG * slot_353(struct StateG * v7160);
struct StateG * slot_397(struct StateG * v8630);
struct StateG * slot_476(struct StateG * v9844);
struct StateG * slot_655(struct StateG * v13564);
struct StateG * slot_658(struct StateG * v13684);
struct StateG * slot_851(struct StateG * v17782);
struct StateG * slot_835(struct StateG * v17144);
struct StateG * slot_295(struct StateG * v6124);
struct StateG * slot_315(struct StateG * v6400);
struct StateG * slot_802(struct StateG * v16264);
struct StateG * slot_545(struct StateG * v11624);
struct StateG * slot_17(struct StateG * v479);
struct StateG * slot_207(struct StateG * v4016);
struct StateG * slot_156(struct StateG * v3222);
struct StateG * slot_430(struct StateG * v8994);
struct StateG * slot_369(struct StateG * v7660);
struct StateG * slot_461(struct StateG * v9544);
struct StateG * slot_631(struct StateG * v12944);
struct StateG * slot_164(struct StateG * v3306);
struct StateG * slot_847(struct StateG * v17624);
struct StateG * slot_133(struct StateG * v2892);
struct StateG * slot_56(struct StateG * v1140);
struct StateG * slot_564(struct StateG * v11856);
struct StateG * slot_823(struct StateG * v16684);
struct StateG * slot_630(struct StateG * v12924);
struct StateG * slot_377(struct StateG * v7980);
struct StateG * slot_768(struct StateG * v15640);
struct StateG * slot_427(struct StateG * v8955);
struct StateG * slot_464(struct StateG * v9604);
struct StateG * slot_433(struct StateG * v9033);
struct StateG * slot_121(struct StateG * v2412);
struct StateG * slot_610(struct StateG * v12524);
struct StateG * slot_144(struct StateG * v3096);
struct StateG * slot_492(struct StateG * v10244);
struct StateG * slot_201(struct StateG * v3896);
struct StateG * slot_600(struct StateG * v12324);
struct StateG * slot_63(struct StateG * v1280);
struct StateG * slot_195(struct StateG * v3776);
struct StateG * slot_326(struct StateG * v6620);
struct StateG * slot_303(struct StateG * v6223);
struct StateG * slot_335(struct StateG * v6800);
struct StateG * slot_223(struct StateG * v4336);
struct StateG * slot_773(struct StateG * v15705);
struct StateG * slot_237(struct StateG * v4716);
struct StateG * slot_41(struct StateG * v914);
struct StateG * slot_668(struct StateG * v14084);
struct StateG * slot_537(struct StateG * v11540);
struct StateG * slot_737(struct StateG * v15237);
struct StateG * slot_289(struct StateG * v6056);
struct StateG * slot_238(struct StateG * v4756);
struct StateG * slot_544(struct StateG * v11616);
struct StateG * slot_573(struct StateG * v11973);
struct StateG * slot_245(struct StateG * v5036);
struct StateG * slot_388(struct StateG * v8420);
struct StateG * slot_103(struct StateG * v2032);
struct StateG * slot_324(struct StateG * v6580);
struct StateG * slot_440(struct StateG * v9124);
struct StateG * slot_781(struct StateG * v15844);
struct StateG * slot_788(struct StateG * v15984);
struct StateG * slot_547(struct StateG * v11650);
struct StateG * slot_518(struct StateG * v11284);
struct StateG * slot_451(struct StateG * v9344);
struct StateG * slot_458(struct StateG * v9484);
struct StateG * slot_415(struct StateG * v8824);
struct StateG * slot_613(struct StateG * v12584);
struct StateG * slot_832(struct StateG * v17024);
struct StateG * slot_531(struct StateG * v11482);
struct StateG * slot_321(struct StateG * v6520);
struct StateG * slot_317(struct StateG * v6440);
struct StateG * slot_558(struct StateG * v11778);
struct StateG * slot_205(struct StateG * v3976);
struct StateG * slot_193(struct StateG * v3736);
struct StateG * slot_375(struct StateG * v7900);
struct StateG * slot_759(struct StateG * v15523);
struct StateG * slot_637(struct StateG * v13064);
struct StateG * slot_793(struct StateG * v16084);
struct StateG * slot_380(struct StateG * v8100);
struct StateG * slot_636(struct StateG * v13044);
struct StateG * slot_478(struct StateG * v9884);
struct StateG * slot_775(struct StateG * v15731);
struct StateG * slot_695(struct StateG * v14720);
struct StateG * slot_246(struct StateG * v5076);
struct StateG * slot_284(struct StateG * v6006);
struct StateG * slot_3(struct StateG * v232);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_446(struct StateG * v9244);
struct StateG * slot_38(struct StateG * v879);
struct StateG * slot_159(struct StateG * v3256);
struct StateG * slot_684(struct StateG * v14602);
struct StateG * slot_459(struct StateG * v9504);
struct StateG * slot_812(struct StateG * v16464);
struct StateG * slot_132(struct StateG * v2852);
struct StateG * slot_313(struct StateG * v6360);
struct StateG * slot_553(struct StateG * v11713);
struct StateG * slot_211(struct StateG * v4096);
struct StateG * slot_717(struct StateG * v14966);
struct StateG * slot_436(struct StateG * v9072);
struct StateG * slot_704(struct StateG * v14812);
struct StateG * slot_708(struct StateG * v14854);
struct StateG * slot_296(struct StateG * v6132);
struct StateG * slot_18(struct StateG * v492);
struct StateG * slot_9(struct StateG * v357);
struct StateG * slot_282(struct StateG * v5985);
struct StateG * slot_362(struct StateG * v7380);
struct StateG * slot_43(struct StateG * v942);
struct StateG * slot_76(struct StateG * v1662);
struct StateG * slot_55(struct StateG * v1120);
struct StateG * slot_346(struct StateG * v7020);
struct StateG * slot_647(struct StateG * v13264);
struct StateG * slot_274(struct StateG * v5901);
struct StateG * slot_535(struct StateG * v11524);
struct StateG * slot_318(struct StateG * v6460);
struct StateG * slot_91(struct StateG * v1827);
struct StateG * slot_700(struct StateG * v14770);
struct StateG * slot_58(struct StateG * v1180);
struct StateG * slot_255(struct StateG * v5436);
struct StateG * slot_66(struct StateG * v1380);
struct StateG * slot_643(struct StateG * v13184);
struct StateG * slot_550(struct StateG * v11679);
struct StateG * slot_592(struct StateG * v12220);
struct StateG * slot_368(struct StateG * v7620);
struct StateG * slot_718(struct StateG * v14980);
struct StateG * slot_265(struct StateG * v5804);
struct StateG * slot_192(struct StateG * v3716);
struct StateG * slot_48(struct StateG * v1008);
struct StateG * slot_770(struct StateG * v15666);
struct StateG * slot_119(struct StateG * v2352);
struct StateG * slot_276(struct StateG * v5922);
struct StateG * slot_763(struct StateG * v15575);
struct StateG * slot_290(struct StateG * v6069);
struct StateG * slot_234(struct StateG * v4596);
struct StateG * slot_218(struct StateG * v4236);
struct StateG * slot_841(struct StateG * v17384);
struct StateG * slot_596(struct StateG * v12272);
struct StateG * slot_576(struct StateG * v12012);
struct StateG * slot_202(struct StateG * v3916);
struct StateG * slot_230(struct StateG * v4476);
struct StateG * slot_852(struct StateG * v17822);
struct StateG * slot_294(struct StateG * v6111);
struct StateG * slot_488(struct StateG * v10084);
struct StateG * slot_439(struct StateG * v9111);
struct StateG * slot_479(struct StateG * v9904);
struct StateG * slot_196(struct StateG * v3796);
struct StateG * slot_172(struct StateG * v3400);
struct StateG * slot_443(struct StateG * v9184);
struct StateG * slot_8(struct StateG * v318);
struct StateG * slot_534(struct StateG * v11511);
struct StateG * slot_597(struct StateG * v12285);
struct StateG * slot_180(struct StateG * v3504);
struct StateG * slot_512(struct StateG * v11044);
struct StateG * slot_494(struct StateG * v10324);
struct StateG * slot_607(struct StateG * v12464);
struct StateG * slot_789(struct StateG * v16004);
struct StateG * slot_328(struct StateG * v6660);
struct StateG * slot_402(struct StateG * v8685);
struct StateG * slot_149(struct StateG * v3146);
struct StateG * slot_527(struct StateG * v11440);
struct StateG * slot_5(struct StateG * v258);
struct StateG * slot_235(struct StateG * v4636);
struct StateG * slot_275(struct StateG * v5914);
struct StateG * slot_428(struct StateG * v8968);
struct StateG * slot_815(struct StateG * v16524);
struct StateG * slot_660(struct StateG * v13764);
struct StateG * slot_614(struct StateG * v12604);
struct StateG * slot_345(struct StateG * v7000);
struct StateG * slot_753(struct StateG * v15445);
struct StateG * slot_414(struct StateG * v8811);
struct StateG * slot_364(struct StateG * v7460);
struct StateG * slot_356(struct StateG * v7220);
struct StateG * slot_665(struct StateG * v13964);
struct StateG * slot_434(struct StateG * v9046);
struct StateG * slot_760(struct StateG * v15536);
struct StateG * slot_522(struct StateG * v11385);
struct StateG * slot_80(struct StateG * v1704);
struct StateG * slot_390(struct StateG * v8500);
struct StateG * slot_44(struct StateG * v956);
struct StateG * slot_137(struct StateG * v3020);
struct StateG * slot_122(struct StateG * v2452);
struct StateG * slot_722(struct StateG * v15036);
struct StateG * slot_179(struct StateG * v3491);
struct StateG * slot_338(struct StateG * v6860);
struct StateG * slot_563(struct StateG * v11843);
struct StateG * slot_366(struct StateG * v7540);
struct StateG * slot_574(struct StateG * v11986);
struct StateG * slot_438(struct StateG * v9098);
struct StateG * slot_311(struct StateG * v6327);
struct StateG * slot_279(struct StateG * v5956);
struct StateG * slot_401(struct StateG * v8672);
struct StateG * slot_423(struct StateG * v8908);
struct StateG * slot_217(struct StateG * v4216);
struct StateG * slot_696(struct StateG * v14728);
struct StateG * slot_111(struct StateG * v2192);
struct StateG * slot_549(struct StateG * v11666);
struct StateG * slot_349(struct StateG * v7080);
struct StateG * slot_291(struct StateG * v6082);
struct StateG * slot_820(struct StateG * v16624);
struct StateG * slot_147(struct StateG * v3130);
struct StateG * slot_491(struct StateG * v10204);
struct StateG * slot_163(struct StateG * v3298);
struct StateG * slot_422(struct StateG * v8895);
struct StateG * slot_448(struct StateG * v9284);
struct StateG * slot_792(struct StateG * v16064);
struct StateG * slot_698(struct StateG * v14749);
struct StateG * slot_407(struct StateG * v8740);
struct StateG * slot_250(struct StateG * v5236);
struct StateG * slot_360(struct StateG * v7300);
struct StateG * slot_259(struct StateG * v5596);
struct StateG * slot_469(struct StateG * v9704);
struct StateG * slot_120(struct StateG * v2372) {
  int * v2373 = v2372->regs;
  int v2374 = v2373[16];
  int v2375 = v2373[17];
  bool v2395 = v2374 < v2375;
  struct StateG * v2390;
  if (v2395) {
    int * v2376 = v2372->pht;
    v2376[55] = 1;
    struct StateG * v2378 = slot_136(v2372);
    v2390 = v2378;
  } else {
    int * v2380 = v2372->pht;
    v2380[55] = 0;
    int v2382 = v2372->timer;
    int v2404 = v2382 + 15;
    v2372->timer = v2404;
    int * v2384 = v2372->saved_regs;
    int v2385 = v2384[18];
    int * v2386 = v2372->regs;
    v2386[18] = v2385;
    struct StateG * v2388 = slot_137(v2372);
    v2390 = v2388;
  }
  return v2390;
}

struct StateG * slot_167(struct StateG * v3340) {
  int v3341 = v3340->timer;
  int v3345 = v3341 + 1;
  v3340->timer = v3345;
  struct StateG * v3343 = slot_183(v3340);
  return v3343;
}

struct StateG * slot_509(struct StateG * v10924) {
  int * v10925 = v10924->regs;
  int v10926 = v10925[16];
  int v10927 = v10925[17];
  bool v10947 = v10926 < v10927;
  struct StateG * v10942;
  if (v10947) {
    int * v10928 = v10924->pht;
    v10928[101] = 1;
    int v10930 = v10924->timer;
    int v10951 = v10930 + 15;
    v10924->timer = v10951;
    int * v10932 = v10924->saved_regs;
    int v10933 = v10932[18];
    int * v10934 = v10924->regs;
    v10934[18] = v10933;
    struct StateG * v10936 = slot_530(v10924);
    v10942 = v10936;
  } else {
    int * v10938 = v10924->pht;
    v10938[101] = 0;
    struct StateG * v10940 = slot_531(v10924);
    v10942 = v10940;
  }
  return v10942;
}

struct StateG * slot_152(struct StateG * v3180) {
  int v3181 = v3180->timer;
  int v3185 = v3181 + 1;
  v3180->timer = v3185;
  struct StateG * v3183 = slot_176(v3180);
  return v3183;
}

struct StateG * slot_231(struct StateG * v4496) {
  int * v4497 = v4496->saved_regs;
  int * v4498 = v4496->regs;
  int v4499 = v4498[18];
  v4497[18] = v4499;
  int v4501 = v4496->timer;
  int v4511 = v4501 + 1;
  v4496->timer = v4511;
  int * v4503 = v4496->regs;
  v4503[18] = 1;
  struct StateG * v4505 = slot_263(v4496);
  return v4505;
}

struct StateG * slot_355(struct StateG * v7200) {
  int * v7201 = v7200->saved_regs;
  int * v7202 = v7200->regs;
  int v7203 = v7202[18];
  v7201[18] = v7203;
  int v7205 = v7200->timer;
  int v7215 = v7205 + 1;
  v7200->timer = v7215;
  int * v7207 = v7200->regs;
  v7207[18] = 1;
  struct StateG * v7209 = slot_387(v7200);
  return v7209;
}

struct StateG * slot_616(struct StateG * v12644) {
  int * v12645 = v12644->saved_regs;
  int * v12646 = v12644->regs;
  int v12647 = v12646[18];
  v12645[18] = v12647;
  int v12649 = v12644->timer;
  int v12659 = v12649 + 1;
  v12644->timer = v12659;
  int * v12651 = v12644->regs;
  v12651[18] = 2;
  struct StateG * v12653 = slot_648(v12644);
  return v12653;
}

struct StateG * slot_232(struct StateG * v4516) {
  int * v4517 = v4516->regs;
  int v4518 = v4517[16];
  int v4519 = v4517[17];
  bool v4539 = v4518 < v4519;
  struct StateG * v4534;
  if (v4539) {
    int * v4520 = v4516->pht;
    v4520[79] = 1;
    struct StateG * v4522 = slot_264(v4516);
    v4534 = v4522;
  } else {
    int * v4524 = v4516->pht;
    v4524[79] = 0;
    int v4526 = v4516->timer;
    int v4548 = v4526 + 15;
    v4516->timer = v4548;
    int * v4528 = v4516->saved_regs;
    int v4529 = v4528[18];
    int * v4530 = v4516->regs;
    v4530[18] = v4529;
    struct StateG * v4532 = slot_265(v4516);
    v4534 = v4532;
  }
  return v4534;
}

struct StateG * slot_466(struct StateG * v9644) {
  int * v9645 = v9644->saved_regs;
  int * v9646 = v9644->regs;
  int v9647 = v9646[18];
  v9645[18] = v9647;
  int v9649 = v9644->timer;
  int v9659 = v9649 + 1;
  v9644->timer = v9659;
  int * v9651 = v9644->regs;
  v9651[18] = 2;
  struct StateG * v9653 = slot_498(v9644);
  return v9653;
}

struct StateG * slot_764(struct StateG * v15588) {
  int v15589 = v15588->timer;
  int v15595 = v15589 + 1;
  v15588->timer = v15595;
  int * v15591 = v15588->regs;
  v15591[17] = 10;
  struct StateG * v15593 = slot_780(v15588);
  return v15593;
}

struct StateG * slot_304(struct StateG * v6236) {
  int v6237 = v6236->timer;
  int v6243 = v6237 + 1;
  v6236->timer = v6243;
  int * v6239 = v6236->regs;
  v6239[17] = 10;
  struct StateG * v6241 = slot_320(v6236);
  return v6241;
}

struct StateG * slot_31(struct StateG * v778) {
  int * v779 = v778->regs;
  int v780 = v779[16];
  int v781 = v779[17];
  bool v801 = v780 >= v781;
  struct StateG * v796;
  if (v801) {
    int * v782 = v778->pht;
    v782[16] = 1;
    int v784 = v778->timer;
    int v804 = v784 + 15;
    v778->timer = v804;
    int * v786 = v778->saved_regs;
    int v787 = v786[19];
    int * v788 = v778->regs;
    v788[19] = v787;
    struct StateG * v790 = slot_38(v778);
    v796 = v790;
  } else {
    int * v792 = v778->pht;
    v792[16] = 0;
    struct StateG * v794 = slot_39(v778);
    v796 = v794;
  }
  return v796;
}

struct StateG * slot_730(struct StateG * v15146) {
  int v15147 = v15146->timer;
  int v15153 = v15147 + 1;
  v15146->timer = v15153;
  int * v15149 = v15146->regs;
  v15149[1] = 156;
  struct StateG * v15151 = slot_746(v15146);
  return v15151;
}

struct StateG * slot_585(struct StateG * v12129) {
  int v12130 = v12129->timer;
  int v12136 = v12130 + 1;
  v12129->timer = v12136;
  int * v12132 = v12129->regs;
  v12132[17] = 10;
  struct StateG * v12134 = slot_601(v12129);
  return v12134;
}

struct StateG * slot_241(struct StateG * v4876) {
  int * v4877 = v4876->regs;
  int v4878 = v4877[16];
  int v4879 = v4877[17];
  bool v4899 = v4878 < v4879;
  struct StateG * v4894;
  if (v4899) {
    int * v4880 = v4876->pht;
    v4880[75] = 1;
    int v4882 = v4876->timer;
    int v4903 = v4882 + 15;
    v4876->timer = v4903;
    int * v4884 = v4876->saved_regs;
    int v4885 = v4884[18];
    int * v4886 = v4876->regs;
    v4886[18] = v4885;
    struct StateG * v4888 = slot_282(v4876);
    v4894 = v4888;
  } else {
    int * v4890 = v4876->pht;
    v4890[75] = 0;
    struct StateG * v4892 = slot_283(v4876);
    v4894 = v4892;
  }
  return v4894;
}

struct StateG * slot_611(struct StateG * v12544) {
  int v12545 = v12544->timer;
  int v12555 = v12545 + 1;
  v12544->timer = v12555;
  int * v12547 = v12544->pht;
  int v12548 = v12547[4];
  bool v12558 = !(v12548 == 0);
  struct StateG * v12553;
  if (v12558) {
    struct StateG * v12549 = slot_638(v12544);
    v12553 = v12549;
  } else {
    struct StateG * v12551 = slot_639(v12544);
    v12553 = v12551;
  }
  return v12553;
}

struct StateG * slot_160(struct StateG * v3264) {
  int v3265 = v3264->timer;
  int v3269 = v3265 + 1;
  v3264->timer = v3269;
  struct StateG * v3267 = slot_180(v3264);
  return v3267;
}

struct StateG * slot_745(struct StateG * v15341) {
  int v15342 = v15341->timer;
  int v15348 = v15342 + 1;
  v15341->timer = v15348;
  int * v15344 = v15341->regs;
  v15344[1] = 164;
  struct StateG * v15346 = slot_761(v15341);
  return v15346;
}

struct StateG * slot_150(struct StateG * v3159) {
  int v3160 = v3159->timer;
  int v3166 = v3160 + 1;
  v3159->timer = v3166;
  int * v3162 = v3159->regs;
  v3162[18] = 2;
  struct StateG * v3164 = slot_148(v3159);
  return v3164;
}

struct StateG * slot_391(struct StateG * v8540) {
  int * v8541 = v8540->regs;
  int v8542 = v8541[16];
  int v8543 = v8541[17];
  bool v8563 = v8542 < v8543;
  struct StateG * v8558;
  if (v8563) {
    int * v8544 = v8540->pht;
    v8544[80] = 1;
    int v8546 = v8540->timer;
    int v8567 = v8546 + 15;
    v8540->timer = v8567;
    int * v8548 = v8540->saved_regs;
    int v8549 = v8548[18];
    int * v8550 = v8540->regs;
    v8550[18] = v8549;
    struct StateG * v8552 = slot_422(v8540);
    v8558 = v8552;
  } else {
    int * v8554 = v8540->pht;
    v8554[80] = 0;
    struct StateG * v8556 = slot_423(v8540);
    v8558 = v8556;
  }
  return v8558;
}

struct StateG * slot_74(struct StateG * v1641) {
  int v1642 = v1641->timer;
  int v1648 = v1642 + 1;
  v1641->timer = v1648;
  int * v1644 = v1641->regs;
  v1644[18] = 2;
  struct StateG * v1646 = slot_72(v1641);
  return v1646;
}

struct StateG * slot_372(struct StateG * v7780) {
  int * v7781 = v7780->regs;
  int v7782 = v7781[16];
  int v7783 = v7781[17];
  bool v7803 = v7782 < v7783;
  struct StateG * v7798;
  if (v7803) {
    int * v7784 = v7780->pht;
    v7784[89] = 1;
    struct StateG * v7786 = slot_416(v7780);
    v7798 = v7786;
  } else {
    int * v7788 = v7780->pht;
    v7788[89] = 0;
    int v7790 = v7780->timer;
    int v7812 = v7790 + 15;
    v7780->timer = v7812;
    int * v7792 = v7780->saved_regs;
    int v7793 = v7792[18];
    int * v7794 = v7780->regs;
    v7794[18] = v7793;
    struct StateG * v7796 = slot_417(v7780);
    v7798 = v7796;
  }
  return v7798;
}

struct StateG * slot_403(struct StateG * v8698) {
  int v8699 = v8698->timer;
  int v8703 = v8699 + 1;
  v8698->timer = v8703;
  struct StateG * v8701 = slot_429(v8698);
  return v8701;
}

struct StateG * slot_325(struct StateG * v6600) {
  int v6601 = v6600->timer;
  int v6611 = v6601 + 1;
  v6600->timer = v6611;
  int * v6603 = v6600->pht;
  int v6604 = v6603[82];
  bool v6614 = !(v6604 == 0);
  struct StateG * v6609;
  if (v6614) {
    struct StateG * v6605 = slot_354(v6600);
    v6609 = v6605;
  } else {
    struct StateG * v6607 = slot_355(v6600);
    v6609 = v6607;
  }
  return v6609;
}

struct StateG * slot_686(struct StateG * v14623) {
  int v14624 = v14623->timer;
  int v14630 = v14624 + 1;
  v14623->timer = v14630;
  int * v14626 = v14623->regs;
  v14626[18] = 2;
  struct StateG * v14628 = slot_684(v14623);
  return v14628;
}

struct StateG * slot_895(struct StateG * v18408) {
  int v18409 = v18408->timer;
  int v18416 = v18409 + 1;
  v18408->timer = v18416;
  int * v18411 = v18408->regs;
  int v18412 = v18411[1];
  bool v18419 = v18412 == 164;
  ret_assert(v18419);
  struct StateG * v18414 = slot_918(v18408);
  return v18414;
}

struct StateG * slot_28(struct StateG * v664) {
  int * v665 = v664->regs;
  int v666 = v665[16];
  int v667 = v665[17];
  bool v687 = v666 >= v667;
  struct StateG * v682;
  if (v687) {
    int * v668 = v664->pht;
    v668[17] = 1;
    struct StateG * v670 = slot_32(v664);
    v682 = v670;
  } else {
    int * v672 = v664->pht;
    v672[17] = 0;
    int v674 = v664->timer;
    int v694 = v674 + 15;
    v664->timer = v694;
    int * v676 = v664->saved_regs;
    int v677 = v676[19];
    int * v678 = v664->regs;
    v678[19] = v677;
    struct StateG * v680 = slot_33(v664);
    v682 = v680;
  }
  return v682;
}

struct StateG * slot_517(struct StateG * v11244) {
  int * v11245 = v11244->regs;
  int v11246 = v11245[16];
  int v11247 = v11245[17];
  bool v11267 = v11246 < v11247;
  struct StateG * v11262;
  if (v11267) {
    int * v11248 = v11244->pht;
    v11248[97] = 1;
    int v11250 = v11244->timer;
    int v11271 = v11250 + 15;
    v11244->timer = v11271;
    int * v11252 = v11244->saved_regs;
    int v11253 = v11252[18];
    int * v11254 = v11244->regs;
    v11254[18] = v11253;
    struct StateG * v11256 = slot_546(v11244);
    v11262 = v11256;
  } else {
    int * v11258 = v11244->pht;
    v11258[97] = 0;
    struct StateG * v11260 = slot_547(v11244);
    v11262 = v11260;
  }
  return v11262;
}

struct StateG * slot_566(struct StateG * v11882) {
  int v11883 = v11882->timer;
  int v11889 = v11883 + 1;
  v11882->timer = v11889;
  int * v11885 = v11882->regs;
  v11885[1] = 148;
  struct StateG * v11887 = slot_582(v11882);
  return v11887;
}

struct StateG * slot_154(struct StateG * v3201) {
  int v3202 = v3201->timer;
  int v3208 = v3202 + 1;
  v3201->timer = v3208;
  int * v3204 = v3201->regs;
  v3204[18] = 2;
  struct StateG * v3206 = slot_152(v3201);
  return v3206;
}

struct StateG * slot_260(struct StateG * v5636) {
  int * v5637 = v5636->regs;
  int v5638 = v5637[16];
  int v5639 = v5637[17];
  bool v5659 = v5638 < v5639;
  struct StateG * v5654;
  if (v5659) {
    int * v5640 = v5636->pht;
    v5640[65] = 1;
    struct StateG * v5642 = slot_288(v5636);
    v5654 = v5642;
  } else {
    int * v5644 = v5636->pht;
    v5644[65] = 0;
    int v5646 = v5636->timer;
    int v5668 = v5646 + 15;
    v5636->timer = v5668;
    int * v5648 = v5636->saved_regs;
    int v5649 = v5648[18];
    int * v5650 = v5636->regs;
    v5650[18] = v5649;
    struct StateG * v5652 = slot_289(v5636);
    v5654 = v5652;
  }
  return v5654;
}

struct StateG * slot_305(struct StateG * v6249) {
  int v6250 = v6249->timer;
  int v6256 = v6250 + 1;
  v6249->timer = v6256;
  int * v6252 = v6249->regs;
  v6252[17] = 10;
  struct StateG * v6254 = slot_321(v6249);
  return v6254;
}

struct StateG * slot_662(struct StateG * v13844) {
  int * v13845 = v13844->regs;
  int v13846 = v13845[16];
  int v13847 = v13845[17];
  bool v13867 = v13846 < v13847;
  struct StateG * v13862;
  if (v13867) {
    int * v13848 = v13844->pht;
    v13848[8] = 1;
    struct StateG * v13850 = slot_708(v13844);
    v13862 = v13850;
  } else {
    int * v13852 = v13844->pht;
    v13852[8] = 0;
    int v13854 = v13844->timer;
    int v13876 = v13854 + 15;
    v13844->timer = v13876;
    int * v13856 = v13844->saved_regs;
    int v13857 = v13856[18];
    int * v13858 = v13844->regs;
    v13858[18] = v13857;
    struct StateG * v13860 = slot_709(v13844);
    v13862 = v13860;
  }
  return v13862;
}

struct StateG * slot_34(struct StateG * v837) {
  int v838 = v837->timer;
  int v844 = v838 + 1;
  v837->timer = v844;
  int * v840 = v837->regs;
  v840[19] = 2;
  struct StateG * v842 = slot_32(v837);
  return v842;
}

struct StateG * slot_850(struct StateG * v17742) {
  int * v17743 = v17742->regs;
  int v17744 = v17743[16];
  int v17745 = v17743[17];
  bool v17765 = v17744 >= v17745;
  struct StateG * v17760;
  if (v17765) {
    int * v17746 = v17742->pht;
    v17746[18] = 1;
    struct StateG * v17748 = slot_883(v17742);
    v17760 = v17748;
  } else {
    int * v17750 = v17742->pht;
    v17750[18] = 0;
    int v17752 = v17742->timer;
    int v17774 = v17752 + 15;
    v17742->timer = v17774;
    int * v17754 = v17742->saved_regs;
    int v17755 = v17754[19];
    int * v17756 = v17742->regs;
    v17756[19] = v17755;
    struct StateG * v17758 = slot_861(v17742);
    v17760 = v17758;
  }
  return v17760;
}

struct StateG * slot_21(struct StateG * v531) {
  int v532 = v531->timer;
  int v538 = v532 + 1;
  v531->timer = v538;
  int * v534 = v531->regs;
  v534[17] = 10;
  struct StateG * v536 = slot_23(v531);
  return v536;
}

struct StateG * slot_118(struct StateG * v2332) {
  int * v2333 = v2332->saved_regs;
  int * v2334 = v2332->regs;
  int v2335 = v2334[18];
  v2333[18] = v2335;
  int v2337 = v2332->timer;
  int v2347 = v2337 + 1;
  v2332->timer = v2347;
  int * v2339 = v2332->regs;
  v2339[18] = 2;
  struct StateG * v2341 = slot_134(v2332);
  return v2341;
}

struct StateG * slot_515(struct StateG * v11164) {
  int * v11165 = v11164->regs;
  int v11166 = v11165[16];
  int v11167 = v11165[17];
  bool v11187 = v11166 < v11167;
  struct StateG * v11182;
  if (v11187) {
    int * v11168 = v11164->pht;
    v11168[98] = 1;
    int v11170 = v11164->timer;
    int v11191 = v11170 + 15;
    v11164->timer = v11191;
    int * v11172 = v11164->saved_regs;
    int v11173 = v11172[18];
    int * v11174 = v11164->regs;
    v11174[18] = v11173;
    struct StateG * v11176 = slot_542(v11164);
    v11182 = v11176;
  } else {
    int * v11178 = v11164->pht;
    v11178[98] = 0;
    struct StateG * v11180 = slot_543(v11164);
    v11182 = v11180;
  }
  return v11182;
}

struct StateG * slot_833(struct StateG * v17064) {
  int * v17065 = v17064->regs;
  int v17066 = v17065[16];
  int v17067 = v17065[17];
  bool v17087 = v17066 >= v17067;
  struct StateG * v17082;
  if (v17087) {
    int * v17068 = v17064->pht;
    v17068[27] = 1;
    int v17070 = v17064->timer;
    int v17091 = v17070 + 15;
    v17064->timer = v17091;
    int * v17072 = v17064->saved_regs;
    int v17073 = v17072[19];
    int * v17074 = v17064->regs;
    v17074[19] = v17073;
    struct StateG * v17076 = slot_858(v17064);
    v17082 = v17076;
  } else {
    int * v17078 = v17064->pht;
    v17078[27] = 0;
    struct StateG * v17080 = slot_883(v17064);
    v17082 = v17080;
  }
  return v17082;
}

struct StateG * slot_376(struct StateG * v7940) {
  int * v7941 = v7940->regs;
  int v7942 = v7941[16];
  int v7943 = v7941[17];
  bool v7963 = v7942 < v7943;
  struct StateG * v7958;
  if (v7963) {
    int * v7944 = v7940->pht;
    v7944[87] = 1;
    struct StateG * v7946 = slot_392(v7940);
    v7958 = v7946;
  } else {
    int * v7948 = v7940->pht;
    v7948[87] = 0;
    int v7950 = v7940->timer;
    int v7972 = v7950 + 15;
    v7940->timer = v7972;
    int * v7952 = v7940->saved_regs;
    int v7953 = v7952[18];
    int * v7954 = v7940->regs;
    v7954[18] = v7953;
    struct StateG * v7956 = slot_393(v7940);
    v7958 = v7956;
  }
  return v7958;
}

struct StateG * slot_373(struct StateG * v7820) {
  int * v7821 = v7820->regs;
  int v7822 = v7821[16];
  int v7823 = v7821[17];
  bool v7843 = v7822 < v7823;
  struct StateG * v7838;
  if (v7843) {
    int * v7824 = v7820->pht;
    v7824[89] = 1;
    int v7826 = v7820->timer;
    int v7847 = v7826 + 15;
    v7820->timer = v7847;
    int * v7828 = v7820->saved_regs;
    int v7829 = v7828[18];
    int * v7830 = v7820->regs;
    v7830[18] = v7829;
    struct StateG * v7832 = slot_418(v7820);
    v7838 = v7832;
  } else {
    int * v7834 = v7820->pht;
    v7834[89] = 0;
    struct StateG * v7836 = slot_419(v7820);
    v7838 = v7836;
  }
  return v7838;
}

struct StateG * slot_146(struct StateG * v3117) {
  int v3118 = v3117->timer;
  int v3124 = v3118 + 1;
  v3117->timer = v3124;
  int * v3120 = v3117->regs;
  v3120[18] = 2;
  struct StateG * v3122 = slot_144(v3117);
  return v3122;
}

struct StateG * slot_383(struct StateG * v8220) {
  int * v8221 = v8220->regs;
  int v8222 = v8221[16];
  int v8223 = v8221[17];
  bool v8243 = v8222 < v8223;
  struct StateG * v8238;
  if (v8243) {
    int * v8224 = v8220->pht;
    v8224[84] = 1;
    int v8226 = v8220->timer;
    int v8247 = v8226 + 15;
    v8220->timer = v8247;
    int * v8228 = v8220->saved_regs;
    int v8229 = v8228[18];
    int * v8230 = v8220->regs;
    v8230[18] = v8229;
    struct StateG * v8232 = slot_406(v8220);
    v8238 = v8232;
  } else {
    int * v8234 = v8220->pht;
    v8234[84] = 0;
    struct StateG * v8236 = slot_407(v8220);
    v8238 = v8236;
  }
  return v8238;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_489(struct StateG * v10124) {
  int * v10125 = v10124->regs;
  int v10126 = v10125[16];
  int v10127 = v10125[17];
  bool v10147 = v10126 < v10127;
  struct StateG * v10142;
  if (v10147) {
    int * v10128 = v10124->pht;
    v10128[111] = 1;
    int v10130 = v10124->timer;
    int v10151 = v10130 + 15;
    v10124->timer = v10151;
    int * v10132 = v10124->saved_regs;
    int v10133 = v10132[18];
    int * v10134 = v10124->regs;
    v10134[18] = v10133;
    struct StateG * v10136 = slot_522(v10124);
    v10142 = v10136;
  } else {
    int * v10138 = v10124->pht;
    v10138[111] = 0;
    struct StateG * v10140 = slot_523(v10124);
    v10142 = v10140;
  }
  return v10142;
}

struct StateG * slot_148(struct StateG * v3138) {
  int v3139 = v3138->timer;
  int v3143 = v3139 + 1;
  v3138->timer = v3143;
  struct StateG * v3141 = slot_174(v3138);
  return v3141;
}

struct StateG * slot_421(struct StateG * v8882) {
  int v8883 = v8882->timer;
  int v8889 = v8883 + 1;
  v8882->timer = v8889;
  int * v8885 = v8882->regs;
  v8885[18] = 1;
  struct StateG * v8887 = slot_423(v8882);
  return v8887;
}

struct StateG * slot_725(struct StateG * v15078) {
  int v15079 = v15078->timer;
  int v15086 = v15079 + 1;
  v15078->timer = v15086;
  int * v15081 = v15078->regs;
  int v15082 = v15081[1];
  bool v15089 = v15082 == 156;
  ret_assert(v15089);
  struct StateG * v15084 = slot_741(v15078);
  return v15084;
}

struct StateG * slot_918(struct StateG * v18604) {
  int v18605 = v18604->timer;
  int v18608 = v18605 + 1;
  v18604->timer = v18608;
  return v18604;
}

struct StateG * slot_79(struct StateG * v1696) {
  int v1697 = v1696->timer;
  int v1701 = v1697 + 1;
  v1696->timer = v1701;
  struct StateG * v1699 = slot_91(v1696);
  return v1699;
}

struct StateG * slot_568(struct StateG * v11908) {
  int v11909 = v11908->timer;
  int v11915 = v11909 + 1;
  v11908->timer = v11915;
  int * v11911 = v11908->regs;
  v11911[1] = 156;
  struct StateG * v11913 = slot_584(v11908);
  return v11913;
}

struct StateG * slot_810(struct StateG * v16424) {
  int * v16425 = v16424->saved_regs;
  int * v16426 = v16424->regs;
  int v16427 = v16426[19];
  v16425[19] = v16427;
  int v16429 = v16424->timer;
  int v16439 = v16429 + 1;
  v16424->timer = v16439;
  int * v16431 = v16424->regs;
  v16431[19] = 2;
  struct StateG * v16433 = slot_842(v16424);
  return v16433;
}

struct StateG * slot_571(struct StateG * v11947) {
  int v11948 = v11947->timer;
  int v11954 = v11948 + 1;
  v11947->timer = v11954;
  int * v11950 = v11947->regs;
  v11950[1] = 156;
  struct StateG * v11952 = slot_587(v11947);
  return v11952;
}

struct StateG * slot_142(struct StateG * v3075) {
  int v3076 = v3075->timer;
  int v3082 = v3076 + 1;
  v3075->timer = v3082;
  int * v3078 = v3075->regs;
  v3078[18] = 2;
  struct StateG * v3080 = slot_140(v3075);
  return v3080;
}

struct StateG * slot_416(struct StateG * v8832) {
  int v8833 = v8832->timer;
  int v8837 = v8833 + 1;
  v8832->timer = v8837;
  struct StateG * v8835 = slot_436(v8832);
  return v8835;
}

struct StateG * slot_624(struct StateG * v12804) {
  int * v12805 = v12804->saved_regs;
  int * v12806 = v12804->regs;
  int v12807 = v12806[18];
  v12805[18] = v12807;
  int v12809 = v12804->timer;
  int v12819 = v12809 + 1;
  v12804->timer = v12819;
  int * v12811 = v12804->regs;
  v12811[18] = 2;
  struct StateG * v12813 = slot_656(v12804);
  return v12813;
}

struct StateG * slot_738(struct StateG * v15250) {
  int v15251 = v15250->timer;
  int v15257 = v15251 + 1;
  v15250->timer = v15257;
  int * v15253 = v15250->regs;
  v15253[1] = 156;
  struct StateG * v15255 = slot_754(v15250);
  return v15255;
}

struct StateG * slot_214(struct StateG * v4156) {
  int * v4157 = v4156->saved_regs;
  int * v4158 = v4156->regs;
  int v4159 = v4158[18];
  v4157[18] = v4159;
  int v4161 = v4156->timer;
  int v4171 = v4161 + 1;
  v4156->timer = v4171;
  int * v4163 = v4156->regs;
  v4163[18] = 2;
  struct StateG * v4165 = slot_246(v4156);
  return v4165;
}

struct StateG * slot_29(struct StateG * v702) {
  int * v703 = v702->regs;
  int v704 = v703[16];
  int v705 = v703[17];
  bool v725 = v704 >= v705;
  struct StateG * v720;
  if (v725) {
    int * v706 = v702->pht;
    v706[17] = 1;
    int v708 = v702->timer;
    int v728 = v708 + 15;
    v702->timer = v728;
    int * v710 = v702->saved_regs;
    int v711 = v710[19];
    int * v712 = v702->regs;
    v712[19] = v711;
    struct StateG * v714 = slot_34(v702);
    v720 = v714;
  } else {
    int * v716 = v702->pht;
    v716[17] = 0;
    struct StateG * v718 = slot_35(v702);
    v720 = v718;
  }
  return v720;
}

struct StateG * slot_151(struct StateG * v3172) {
  int v3173 = v3172->timer;
  int v3177 = v3173 + 1;
  v3172->timer = v3177;
  struct StateG * v3175 = slot_175(v3172);
  return v3175;
}

struct StateG * slot_7(struct StateG * v298) {
  int * v299 = v298->saved_regs;
  int * v300 = v298->regs;
  int v301 = v300[18];
  v299[18] = v301;
  int v303 = v298->timer;
  int v313 = v303 + 1;
  v298->timer = v313;
  int * v305 = v298->regs;
  v305[18] = 1;
  struct StateG * v307 = slot_9(v298);
  return v307;
}

struct StateG * slot_124(struct StateG * v2532) {
  int * v2533 = v2532->regs;
  int v2534 = v2533[16];
  int v2535 = v2533[17];
  bool v2555 = v2534 < v2535;
  struct StateG * v2550;
  if (v2555) {
    int * v2536 = v2532->pht;
    v2536[53] = 1;
    struct StateG * v2538 = slot_144(v2532);
    v2550 = v2538;
  } else {
    int * v2540 = v2532->pht;
    v2540[53] = 0;
    int v2542 = v2532->timer;
    int v2564 = v2542 + 15;
    v2532->timer = v2564;
    int * v2544 = v2532->saved_regs;
    int v2545 = v2544[18];
    int * v2546 = v2532->regs;
    v2546[18] = v2545;
    struct StateG * v2548 = slot_145(v2532);
    v2550 = v2548;
  }
  return v2550;
}

struct StateG * slot_601(struct StateG * v12344) {
  int v12345 = v12344->timer;
  int v12355 = v12345 + 1;
  v12344->timer = v12355;
  int * v12347 = v12344->pht;
  int v12348 = v12347[14];
  bool v12358 = !(v12348 == 0);
  struct StateG * v12353;
  if (v12358) {
    struct StateG * v12349 = slot_618(v12344);
    v12353 = v12349;
  } else {
    struct StateG * v12351 = slot_619(v12344);
    v12353 = v12351;
  }
  return v12353;
}

struct StateG * slot_128(struct StateG * v2692) {
  int * v2693 = v2692->regs;
  int v2694 = v2693[16];
  int v2695 = v2693[17];
  bool v2715 = v2694 < v2695;
  struct StateG * v2710;
  if (v2715) {
    int * v2696 = v2692->pht;
    v2696[51] = 1;
    struct StateG * v2698 = slot_152(v2692);
    v2710 = v2698;
  } else {
    int * v2700 = v2692->pht;
    v2700[51] = 0;
    int v2702 = v2692->timer;
    int v2724 = v2702 + 15;
    v2692->timer = v2724;
    int * v2704 = v2692->saved_regs;
    int v2705 = v2704[18];
    int * v2706 = v2692->regs;
    v2706[18] = v2705;
    struct StateG * v2708 = slot_153(v2692);
    v2710 = v2708;
  }
  return v2710;
}

struct StateG * slot_365(struct StateG * v7500) {
  int * v7501 = v7500->regs;
  int v7502 = v7501[16];
  int v7503 = v7501[17];
  bool v7523 = v7502 < v7503;
  struct StateG * v7518;
  if (v7523) {
    int * v7504 = v7500->pht;
    v7504[93] = 1;
    int v7506 = v7500->timer;
    int v7527 = v7506 + 15;
    v7500->timer = v7527;
    int * v7508 = v7500->saved_regs;
    int v7509 = v7508[18];
    int * v7510 = v7500->regs;
    v7510[18] = v7509;
    struct StateG * v7512 = slot_402(v7500);
    v7518 = v7512;
  } else {
    int * v7514 = v7500->pht;
    v7514[93] = 0;
    struct StateG * v7516 = slot_403(v7500);
    v7518 = v7516;
  }
  return v7518;
}

struct StateG * slot_622(struct StateG * v12764) {
  int * v12765 = v12764->saved_regs;
  int * v12766 = v12764->regs;
  int v12767 = v12766[18];
  v12765[18] = v12767;
  int v12769 = v12764->timer;
  int v12779 = v12769 + 1;
  v12764->timer = v12779;
  int * v12771 = v12764->regs;
  v12771[18] = 2;
  struct StateG * v12773 = slot_654(v12764);
  return v12773;
}

struct StateG * slot_523(struct StateG * v11398) {
  int v11399 = v11398->timer;
  int v11403 = v11399 + 1;
  v11398->timer = v11403;
  struct StateG * v11401 = slot_553(v11398);
  return v11401;
}

struct StateG * slot_782(struct StateG * v15864) {
  int v15865 = v15864->timer;
  int v15875 = v15865 + 1;
  v15864->timer = v15875;
  int * v15867 = v15864->pht;
  int v15868 = v15867[25];
  bool v15878 = !(v15868 == 0);
  struct StateG * v15873;
  if (v15878) {
    struct StateG * v15869 = slot_804(v15864);
    v15873 = v15869;
  } else {
    struct StateG * v15871 = slot_805(v15864);
    v15873 = v15871;
  }
  return v15873;
}

struct StateG * slot_87(struct StateG * v1780) {
  int v1781 = v1780->timer;
  int v1785 = v1781 + 1;
  v1780->timer = v1785;
  struct StateG * v1783 = slot_95(v1780);
  return v1783;
}

struct StateG * slot_452(struct StateG * v9364) {
  int v9365 = v9364->timer;
  int v9375 = v9365 + 1;
  v9364->timer = v9375;
  int * v9367 = v9364->pht;
  int v9368 = v9367[99];
  bool v9378 = !(v9368 == 0);
  struct StateG * v9373;
  if (v9378) {
    struct StateG * v9369 = slot_480(v9364);
    v9373 = v9369;
  } else {
    struct StateG * v9371 = slot_481(v9364);
    v9373 = v9371;
  }
  return v9373;
}

struct StateG * slot_67(struct StateG * v1420) {
  int * v1421 = v1420->regs;
  int v1422 = v1421[16];
  int v1423 = v1421[17];
  bool v1443 = v1422 < v1423;
  struct StateG * v1438;
  if (v1443) {
    int * v1424 = v1420->pht;
    v1424[34] = 1;
    int v1426 = v1420->timer;
    int v1447 = v1426 + 15;
    v1420->timer = v1447;
    int * v1428 = v1420->saved_regs;
    int v1429 = v1428[18];
    int * v1430 = v1420->regs;
    v1430[18] = v1429;
    struct StateG * v1432 = slot_78(v1420);
    v1438 = v1432;
  } else {
    int * v1434 = v1420->pht;
    v1434[34] = 0;
    struct StateG * v1436 = slot_79(v1420);
    v1438 = v1436;
  }
  return v1438;
}

struct StateG * slot_591(struct StateG * v12207) {
  int v12208 = v12207->timer;
  int v12214 = v12208 + 1;
  v12207->timer = v12214;
  int * v12210 = v12207->regs;
  v12210[17] = 10;
  struct StateG * v12212 = slot_607(v12207);
  return v12212;
}

struct StateG * slot_81(struct StateG * v1712) {
  int v1713 = v1712->timer;
  int v1719 = v1713 + 1;
  v1712->timer = v1719;
  int * v1715 = v1712->regs;
  v1715[18] = 1;
  struct StateG * v1717 = slot_83(v1712);
  return v1717;
}

struct StateG * slot_546(struct StateG * v11637) {
  int v11638 = v11637->timer;
  int v11644 = v11638 + 1;
  v11637->timer = v11644;
  int * v11640 = v11637->regs;
  v11640[18] = 2;
  struct StateG * v11642 = slot_544(v11637);
  return v11642;
}

struct StateG * slot_32(struct StateG * v816) {
  int v817 = v816->timer;
  int v821 = v817 + 1;
  v816->timer = v821;
  struct StateG * v819 = slot_40(v816);
  return v819;
}

struct StateG * slot_861(struct StateG * v18024) {
  int v18025 = v18024->timer;
  int v18031 = v18025 + 1;
  v18024->timer = v18031;
  int * v18027 = v18024->regs;
  v18027[19] = 1;
  struct StateG * v18029 = slot_883(v18024);
  return v18029;
}

struct StateG * slot_189(struct StateG * v3656) {
  int v3657 = v3656->timer;
  int v3667 = v3657 + 1;
  v3656->timer = v3667;
  int * v3659 = v3656->pht;
  int v3660 = v3659[74];
  bool v3670 = !(v3660 == 0);
  struct StateG * v3665;
  if (v3670) {
    struct StateG * v3661 = slot_210(v3656);
    v3665 = v3661;
  } else {
    struct StateG * v3663 = slot_211(v3656);
    v3665 = v3663;
  }
  return v3665;
}

struct StateG * slot_394(struct StateG * v8601) {
  int v8602 = v8601->timer;
  int v8608 = v8602 + 1;
  v8601->timer = v8608;
  int * v8604 = v8601->regs;
  v8604[18] = 2;
  struct StateG * v8606 = slot_392(v8601);
  return v8606;
}

struct StateG * slot_33(struct StateG * v824) {
  int v825 = v824->timer;
  int v831 = v825 + 1;
  v824->timer = v831;
  int * v827 = v824->regs;
  v827[19] = 1;
  struct StateG * v829 = slot_35(v824);
  return v829;
}

struct StateG * slot_743(struct StateG * v15315) {
  int v15316 = v15315->timer;
  int v15322 = v15316 + 1;
  v15315->timer = v15322;
  int * v15318 = v15315->regs;
  v15318[1] = 156;
  struct StateG * v15320 = slot_759(v15315);
  return v15320;
}

struct StateG * slot_371(struct StateG * v7740) {
  int * v7741 = v7740->regs;
  int v7742 = v7741[16];
  int v7743 = v7741[17];
  bool v7763 = v7742 < v7743;
  struct StateG * v7758;
  if (v7763) {
    int * v7744 = v7740->pht;
    v7744[90] = 1;
    int v7746 = v7740->timer;
    int v7767 = v7746 + 15;
    v7740->timer = v7767;
    int * v7748 = v7740->saved_regs;
    int v7749 = v7748[18];
    int * v7750 = v7740->regs;
    v7750[18] = v7749;
    struct StateG * v7752 = slot_414(v7740);
    v7758 = v7752;
  } else {
    int * v7754 = v7740->pht;
    v7754[90] = 0;
    struct StateG * v7756 = slot_415(v7740);
    v7758 = v7756;
  }
  return v7758;
}

struct StateG * slot_680(struct StateG * v14560) {
  int v14561 = v14560->timer;
  int v14565 = v14561 + 1;
  v14560->timer = v14565;
  struct StateG * v14563 = slot_712(v14560);
  return v14563;
}

struct StateG * slot_672(struct StateG * v14244) {
  int * v14245 = v14244->regs;
  int v14246 = v14245[16];
  int v14247 = v14245[17];
  bool v14267 = v14246 < v14247;
  struct StateG * v14262;
  if (v14267) {
    int * v14248 = v14244->pht;
    v14248[3] = 1;
    struct StateG * v14250 = slot_696(v14244);
    v14262 = v14250;
  } else {
    int * v14252 = v14244->pht;
    v14252[3] = 0;
    int v14254 = v14244->timer;
    int v14276 = v14254 + 15;
    v14244->timer = v14276;
    int * v14256 = v14244->saved_regs;
    int v14257 = v14256[18];
    int * v14258 = v14244->regs;
    v14258[18] = v14257;
    struct StateG * v14260 = slot_697(v14244);
    v14262 = v14260;
  }
  return v14262;
}

struct StateG * slot_709(struct StateG * v14862) {
  int v14863 = v14862->timer;
  int v14869 = v14863 + 1;
  v14862->timer = v14869;
  int * v14865 = v14862->regs;
  v14865[18] = 1;
  struct StateG * v14867 = slot_711(v14862);
  return v14867;
}

struct StateG * slot_35(struct StateG * v850) {
  int v851 = v850->timer;
  int v855 = v851 + 1;
  v850->timer = v855;
  struct StateG * v853 = slot_41(v850);
  return v853;
}

struct StateG * slot_484(struct StateG * v10004) {
  int * v10005 = v10004->saved_regs;
  int * v10006 = v10004->regs;
  int v10007 = v10006[18];
  v10005[18] = v10007;
  int v10009 = v10004->timer;
  int v10019 = v10009 + 1;
  v10004->timer = v10019;
  int * v10011 = v10004->regs;
  v10011[18] = 2;
  struct StateG * v10013 = slot_516(v10004);
  return v10013;
}

struct StateG * slot_258(struct StateG * v5556) {
  int * v5557 = v5556->regs;
  int v5558 = v5557[16];
  int v5559 = v5557[17];
  bool v5579 = v5558 < v5559;
  struct StateG * v5574;
  if (v5579) {
    int * v5560 = v5556->pht;
    v5560[66] = 1;
    struct StateG * v5562 = slot_284(v5556);
    v5574 = v5562;
  } else {
    int * v5564 = v5556->pht;
    v5564[66] = 0;
    int v5566 = v5556->timer;
    int v5588 = v5566 + 15;
    v5556->timer = v5588;
    int * v5568 = v5556->saved_regs;
    int v5569 = v5568[18];
    int * v5570 = v5556->regs;
    v5570[18] = v5569;
    struct StateG * v5572 = slot_285(v5556);
    v5574 = v5572;
  }
  return v5574;
}

struct StateG * slot_744(struct StateG * v15328) {
  int v15329 = v15328->timer;
  int v15335 = v15329 + 1;
  v15328->timer = v15335;
  int * v15331 = v15328->regs;
  v15331[1] = 164;
  struct StateG * v15333 = slot_760(v15328);
  return v15333;
}

struct StateG * slot_615(struct StateG * v12624) {
  int v12625 = v12624->timer;
  int v12635 = v12625 + 1;
  v12624->timer = v12635;
  int * v12627 = v12624->pht;
  int v12628 = v12627[0];
  bool v12638 = !(v12628 == 0);
  struct StateG * v12633;
  if (v12638) {
    struct StateG * v12629 = slot_646(v12624);
    v12633 = v12629;
  } else {
    struct StateG * v12631 = slot_647(v12624);
    v12633 = v12631;
  }
  return v12633;
}

struct StateG * slot_51(struct StateG * v1047) {
  int v1048 = v1047->timer;
  int v1054 = v1048 + 1;
  v1047->timer = v1054;
  int * v1050 = v1047->regs;
  v1050[17] = 10;
  struct StateG * v1052 = slot_55(v1047);
  return v1052;
}

struct StateG * slot_25(struct StateG * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[19];
  v605[19] = v607;
  int v609 = v604->timer;
  int v619 = v609 + 1;
  v604->timer = v619;
  int * v611 = v604->regs;
  v611[19] = 1;
  struct StateG * v613 = slot_29(v604);
  return v613;
}

struct StateG * slot_731(struct StateG * v15159) {
  int v15160 = v15159->timer;
  int v15166 = v15160 + 1;
  v15159->timer = v15166;
  int * v15162 = v15159->regs;
  v15162[1] = 156;
  struct StateG * v15164 = slot_747(v15159);
  return v15164;
}

struct StateG * slot_490(struct StateG * v10164) {
  int * v10165 = v10164->regs;
  int v10166 = v10165[16];
  int v10167 = v10165[17];
  bool v10187 = v10166 < v10167;
  struct StateG * v10182;
  if (v10187) {
    int * v10168 = v10164->pht;
    v10168[110] = 1;
    struct StateG * v10170 = slot_524(v10164);
    v10182 = v10170;
  } else {
    int * v10172 = v10164->pht;
    v10172[110] = 0;
    int v10174 = v10164->timer;
    int v10196 = v10174 + 15;
    v10164->timer = v10196;
    int * v10176 = v10164->saved_regs;
    int v10177 = v10176[18];
    int * v10178 = v10164->regs;
    v10178[18] = v10177;
    struct StateG * v10180 = slot_525(v10164);
    v10182 = v10180;
  }
  return v10182;
}

struct StateG * slot_123(struct StateG * v2492) {
  int * v2493 = v2492->regs;
  int v2494 = v2493[16];
  int v2495 = v2493[17];
  bool v2515 = v2494 < v2495;
  struct StateG * v2510;
  if (v2515) {
    int * v2496 = v2492->pht;
    v2496[54] = 1;
    int v2498 = v2492->timer;
    int v2519 = v2498 + 15;
    v2492->timer = v2519;
    int * v2500 = v2492->saved_regs;
    int v2501 = v2500[18];
    int * v2502 = v2492->regs;
    v2502[18] = v2501;
    struct StateG * v2504 = slot_142(v2492);
    v2510 = v2504;
  } else {
    int * v2506 = v2492->pht;
    v2506[54] = 0;
    struct StateG * v2508 = slot_143(v2492);
    v2510 = v2508;
  }
  return v2510;
}

struct StateG * slot_733(struct StateG * v15185) {
  int v15186 = v15185->timer;
  int v15192 = v15186 + 1;
  v15185->timer = v15192;
  int * v15188 = v15185->regs;
  v15188[1] = 156;
  struct StateG * v15190 = slot_749(v15185);
  return v15190;
}

struct StateG * slot_702(struct StateG * v14791) {
  int v14792 = v14791->timer;
  int v14798 = v14792 + 1;
  v14791->timer = v14798;
  int * v14794 = v14791->regs;
  v14794[18] = 2;
  struct StateG * v14796 = slot_700(v14791);
  return v14796;
}

struct StateG * slot_799(struct StateG * v16204) {
  int * v16205 = v16204->saved_regs;
  int * v16206 = v16204->regs;
  int v16207 = v16206[19];
  v16205[19] = v16207;
  int v16209 = v16204->timer;
  int v16219 = v16209 + 1;
  v16204->timer = v16219;
  int * v16211 = v16204->regs;
  v16211[19] = 1;
  struct StateG * v16213 = slot_831(v16204);
  return v16213;
}

struct StateG * slot_299(struct StateG * v6171) {
  int v6172 = v6171->timer;
  int v6178 = v6172 + 1;
  v6171->timer = v6178;
  int * v6174 = v6171->regs;
  v6174[17] = 10;
  struct StateG * v6176 = slot_315(v6171);
  return v6176;
}

struct StateG * slot_539(struct StateG * v11566) {
  int v11567 = v11566->timer;
  int v11571 = v11567 + 1;
  v11566->timer = v11571;
  struct StateG * v11569 = slot_561(v11566);
  return v11569;
}

struct StateG * slot_319(struct StateG * v6480) {
  int v6481 = v6480->timer;
  int v6491 = v6481 + 1;
  v6480->timer = v6491;
  int * v6483 = v6480->pht;
  int v6484 = v6483[88];
  bool v6494 = !(v6484 == 0);
  struct StateG * v6489;
  if (v6494) {
    struct StateG * v6485 = slot_342(v6480);
    v6489 = v6485;
  } else {
    struct StateG * v6487 = slot_343(v6480);
    v6489 = v6487;
  }
  return v6489;
}

struct StateG * slot_656(struct StateG * v13604) {
  int * v13605 = v13604->regs;
  int v13606 = v13605[16];
  int v13607 = v13605[17];
  bool v13627 = v13606 < v13607;
  struct StateG * v13622;
  if (v13627) {
    int * v13608 = v13604->pht;
    v13608[11] = 1;
    struct StateG * v13610 = slot_696(v13604);
    v13622 = v13610;
  } else {
    int * v13612 = v13604->pht;
    v13612[11] = 0;
    int v13614 = v13604->timer;
    int v13636 = v13614 + 15;
    v13604->timer = v13636;
    int * v13616 = v13604->saved_regs;
    int v13617 = v13616[18];
    int * v13618 = v13604->regs;
    v13618[18] = v13617;
    struct StateG * v13620 = slot_697(v13604);
    v13622 = v13620;
  }
  return v13622;
}

struct StateG * slot_671(struct StateG * v14204) {
  int * v14205 = v14204->regs;
  int v14206 = v14205[16];
  int v14207 = v14205[17];
  bool v14227 = v14206 < v14207;
  struct StateG * v14222;
  if (v14227) {
    int * v14208 = v14204->pht;
    v14208[4] = 1;
    int v14210 = v14204->timer;
    int v14231 = v14210 + 15;
    v14204->timer = v14231;
    int * v14212 = v14204->saved_regs;
    int v14213 = v14212[18];
    int * v14214 = v14204->regs;
    v14214[18] = v14213;
    struct StateG * v14216 = slot_694(v14204);
    v14222 = v14216;
  } else {
    int * v14218 = v14204->pht;
    v14218[4] = 0;
    struct StateG * v14220 = slot_695(v14204);
    v14222 = v14220;
  }
  return v14222;
}

struct StateG * slot_344(struct StateG * v6980) {
  int * v6981 = v6980->saved_regs;
  int * v6982 = v6980->regs;
  int v6983 = v6982[18];
  v6981[18] = v6983;
  int v6985 = v6980->timer;
  int v6995 = v6985 + 1;
  v6980->timer = v6995;
  int * v6987 = v6980->regs;
  v6987[18] = 2;
  struct StateG * v6989 = slot_376(v6980);
  return v6989;
}

struct StateG * slot_794(struct StateG * v16104) {
  int * v16105 = v16104->saved_regs;
  int * v16106 = v16104->regs;
  int v16107 = v16106[19];
  v16105[19] = v16107;
  int v16109 = v16104->timer;
  int v16119 = v16109 + 1;
  v16104->timer = v16119;
  int * v16111 = v16104->regs;
  v16111[19] = 2;
  struct StateG * v16113 = slot_826(v16104);
  return v16113;
}

struct StateG * slot_687(struct StateG * v14636) {
  int v14637 = v14636->timer;
  int v14641 = v14637 + 1;
  v14636->timer = v14641;
  struct StateG * v14639 = slot_715(v14636);
  return v14639;
}

struct StateG * slot_497(struct StateG * v10444) {
  int * v10445 = v10444->regs;
  int v10446 = v10445[16];
  int v10447 = v10445[17];
  bool v10467 = v10446 < v10447;
  struct StateG * v10462;
  if (v10467) {
    int * v10448 = v10444->pht;
    v10448[107] = 1;
    int v10450 = v10444->timer;
    int v10471 = v10450 + 15;
    v10444->timer = v10471;
    int * v10452 = v10444->saved_regs;
    int v10453 = v10452[18];
    int * v10454 = v10444->regs;
    v10454[18] = v10453;
    struct StateG * v10456 = slot_538(v10444);
    v10462 = v10456;
  } else {
    int * v10458 = v10444->pht;
    v10458[107] = 0;
    struct StateG * v10460 = slot_539(v10444);
    v10462 = v10460;
  }
  return v10462;
}

struct StateG * slot_455(struct StateG * v9424) {
  int v9425 = v9424->timer;
  int v9435 = v9425 + 1;
  v9424->timer = v9435;
  int * v9427 = v9424->pht;
  int v9428 = v9427[96];
  bool v9438 = !(v9428 == 0);
  struct StateG * v9433;
  if (v9438) {
    struct StateG * v9429 = slot_486(v9424);
    v9433 = v9429;
  } else {
    struct StateG * v9431 = slot_487(v9424);
    v9433 = v9431;
  }
  return v9433;
}

struct StateG * slot_843(struct StateG * v17464) {
  int * v17465 = v17464->regs;
  int v17466 = v17465[16];
  int v17467 = v17465[17];
  bool v17487 = v17466 >= v17467;
  struct StateG * v17482;
  if (v17487) {
    int * v17468 = v17464->pht;
    v17468[22] = 1;
    int v17470 = v17464->timer;
    int v17491 = v17470 + 15;
    v17464->timer = v17491;
    int * v17472 = v17464->saved_regs;
    int v17473 = v17472[19];
    int * v17474 = v17464->regs;
    v17474[19] = v17473;
    struct StateG * v17476 = slot_858(v17464);
    v17482 = v17476;
  } else {
    int * v17478 = v17464->pht;
    v17478[22] = 0;
    struct StateG * v17480 = slot_883(v17464);
    v17482 = v17480;
  }
  return v17482;
}

struct StateG * slot_742(struct StateG * v15302) {
  int v15303 = v15302->timer;
  int v15309 = v15303 + 1;
  v15302->timer = v15309;
  int * v15305 = v15302->regs;
  v15305[1] = 156;
  struct StateG * v15307 = slot_758(v15302);
  return v15307;
}

struct StateG * slot_560(struct StateG * v11804) {
  int v11805 = v11804->timer;
  int v11811 = v11805 + 1;
  v11804->timer = v11811;
  int * v11807 = v11804->regs;
  v11807[1] = 148;
  struct StateG * v11809 = slot_576(v11804);
  return v11809;
}

struct StateG * slot_240(struct StateG * v4836) {
  int * v4837 = v4836->regs;
  int v4838 = v4837[16];
  int v4839 = v4837[17];
  bool v4859 = v4838 < v4839;
  struct StateG * v4854;
  if (v4859) {
    int * v4840 = v4836->pht;
    v4840[75] = 1;
    struct StateG * v4842 = slot_280(v4836);
    v4854 = v4842;
  } else {
    int * v4844 = v4836->pht;
    v4844[75] = 0;
    int v4846 = v4836->timer;
    int v4868 = v4846 + 15;
    v4836->timer = v4868;
    int * v4848 = v4836->saved_regs;
    int v4849 = v4848[18];
    int * v4850 = v4836->regs;
    v4850[18] = v4849;
    struct StateG * v4852 = slot_281(v4836);
    v4854 = v4852;
  }
  return v4854;
}

struct StateG * slot_754(struct StateG * v15458) {
  int v15459 = v15458->timer;
  int v15465 = v15459 + 1;
  v15458->timer = v15465;
  int * v15461 = v15458->regs;
  v15461[1] = 164;
  struct StateG * v15463 = slot_770(v15458);
  return v15463;
}

struct StateG * slot_548(struct StateG * v11658) {
  int v11659 = v11658->timer;
  int v11663 = v11659 + 1;
  v11658->timer = v11663;
  struct StateG * v11661 = slot_566(v11658);
  return v11661;
}

struct StateG * slot_70(struct StateG * v1540) {
  int * v1541 = v1540->regs;
  int v1542 = v1541[16];
  int v1543 = v1541[17];
  bool v1563 = v1542 < v1543;
  struct StateG * v1558;
  if (v1563) {
    int * v1544 = v1540->pht;
    v1544[32] = 1;
    struct StateG * v1546 = slot_84(v1540);
    v1558 = v1546;
  } else {
    int * v1548 = v1540->pht;
    v1548[32] = 0;
    int v1550 = v1540->timer;
    int v1572 = v1550 + 15;
    v1540->timer = v1572;
    int * v1552 = v1540->saved_regs;
    int v1553 = v1552[18];
    int * v1554 = v1540->regs;
    v1554[18] = v1553;
    struct StateG * v1556 = slot_85(v1540);
    v1558 = v1556;
  }
  return v1558;
}

struct StateG * slot_348(struct StateG * v7060) {
  int * v7061 = v7060->saved_regs;
  int * v7062 = v7060->regs;
  int v7063 = v7062[18];
  v7061[18] = v7063;
  int v7065 = v7060->timer;
  int v7075 = v7065 + 1;
  v7060->timer = v7075;
  int * v7067 = v7060->regs;
  v7067[18] = 2;
  struct StateG * v7069 = slot_380(v7060);
  return v7069;
}

struct StateG * slot_734(struct StateG * v15198) {
  int v15199 = v15198->timer;
  int v15205 = v15199 + 1;
  v15198->timer = v15205;
  int * v15201 = v15198->regs;
  v15201[1] = 156;
  struct StateG * v15203 = slot_750(v15198);
  return v15203;
}

struct StateG * slot_467(struct StateG * v9664) {
  int * v9665 = v9664->saved_regs;
  int * v9666 = v9664->regs;
  int v9667 = v9666[18];
  v9665[18] = v9667;
  int v9669 = v9664->timer;
  int v9679 = v9669 + 1;
  v9664->timer = v9679;
  int * v9671 = v9664->regs;
  v9671[18] = 1;
  struct StateG * v9673 = slot_499(v9664);
  return v9673;
}

struct StateG * slot_749(struct StateG * v15393) {
  int v15394 = v15393->timer;
  int v15400 = v15394 + 1;
  v15393->timer = v15400;
  int * v15396 = v15393->regs;
  v15396[1] = 164;
  struct StateG * v15398 = slot_765(v15393);
  return v15398;
}

struct StateG * slot_883(struct StateG * v18260) {
  int v18261 = v18260->timer;
  int v18265 = v18261 + 1;
  v18260->timer = v18265;
  struct StateG * v18263 = slot_895(v18260);
  return v18263;
}

struct StateG * slot_293(struct StateG * v6098) {
  int v6099 = v6098->timer;
  int v6105 = v6099 + 1;
  v6098->timer = v6105;
  int * v6101 = v6098->regs;
  v6101[18] = 1;
  struct StateG * v6103 = slot_295(v6098);
  return v6103;
}

struct StateG * slot_288(struct StateG * v6048) {
  int v6049 = v6048->timer;
  int v6053 = v6049 + 1;
  v6048->timer = v6053;
  struct StateG * v6051 = slot_308(v6048);
  return v6051;
}

struct StateG * slot_683(struct StateG * v14594) {
  int v14595 = v14594->timer;
  int v14599 = v14595 + 1;
  v14594->timer = v14599;
  struct StateG * v14597 = slot_713(v14594);
  return v14597;
}

struct StateG * slot_89(struct StateG * v1801) {
  int v1802 = v1801->timer;
  int v1808 = v1802 + 1;
  v1801->timer = v1808;
  int * v1804 = v1801->regs;
  v1804[17] = 10;
  struct StateG * v1806 = slot_97(v1801);
  return v1806;
}

struct StateG * slot_347(struct StateG * v7040) {
  int * v7041 = v7040->saved_regs;
  int * v7042 = v7040->regs;
  int v7043 = v7042[18];
  v7041[18] = v7043;
  int v7045 = v7040->timer;
  int v7055 = v7045 + 1;
  v7040->timer = v7055;
  int * v7047 = v7040->regs;
  v7047[18] = 1;
  struct StateG * v7049 = slot_379(v7040);
  return v7049;
}

struct StateG * slot_741(struct StateG * v15289) {
  int v15290 = v15289->timer;
  int v15296 = v15290 + 1;
  v15289->timer = v15296;
  int * v15292 = v15289->regs;
  v15292[1] = 156;
  struct StateG * v15294 = slot_757(v15289);
  return v15294;
}

struct StateG * slot_140(struct StateG * v3054) {
  int v3055 = v3054->timer;
  int v3059 = v3055 + 1;
  v3054->timer = v3059;
  struct StateG * v3057 = slot_170(v3054);
  return v3057;
}

struct StateG * slot_778(struct StateG * v15784) {
  int v15785 = v15784->timer;
  int v15795 = v15785 + 1;
  v15784->timer = v15795;
  int * v15787 = v15784->pht;
  int v15788 = v15787[29];
  bool v15798 = !(v15788 == 0);
  struct StateG * v15793;
  if (v15798) {
    struct StateG * v15789 = slot_796(v15784);
    v15793 = v15789;
  } else {
    struct StateG * v15791 = slot_797(v15784);
    v15793 = v15791;
  }
  return v15793;
}

struct StateG * slot_473(struct StateG * v9784) {
  int * v9785 = v9784->saved_regs;
  int * v9786 = v9784->regs;
  int v9787 = v9786[18];
  v9785[18] = v9787;
  int v9789 = v9784->timer;
  int v9799 = v9789 + 1;
  v9784->timer = v9799;
  int * v9791 = v9784->regs;
  v9791[18] = 1;
  struct StateG * v9793 = slot_505(v9784);
  return v9793;
}

struct StateG * slot_706(struct StateG * v14833) {
  int v14834 = v14833->timer;
  int v14840 = v14834 + 1;
  v14833->timer = v14840;
  int * v14836 = v14833->regs;
  v14836[18] = 2;
  struct StateG * v14838 = slot_704(v14833);
  return v14838;
}

struct StateG * slot_135(struct StateG * v2972) {
  int * v2973 = v2972->regs;
  int v2974 = v2973[16];
  int v2975 = v2973[17];
  bool v2995 = v2974 < v2975;
  struct StateG * v2990;
  if (v2995) {
    int * v2976 = v2972->pht;
    v2976[48] = 1;
    int v2978 = v2972->timer;
    int v2999 = v2978 + 15;
    v2972->timer = v2999;
    int * v2980 = v2972->saved_regs;
    int v2981 = v2980[18];
    int * v2982 = v2972->regs;
    v2982[18] = v2981;
    struct StateG * v2984 = slot_166(v2972);
    v2990 = v2984;
  } else {
    int * v2986 = v2972->pht;
    v2986[48] = 0;
    struct StateG * v2988 = slot_167(v2972);
    v2990 = v2988;
  }
  return v2990;
}

struct StateG * slot_767(struct StateG * v15627) {
  int v15628 = v15627->timer;
  int v15634 = v15628 + 1;
  v15627->timer = v15634;
  int * v15630 = v15627->regs;
  v15630[17] = 10;
  struct StateG * v15632 = slot_783(v15627);
  return v15632;
}

struct StateG * slot_485(struct StateG * v10024) {
  int * v10025 = v10024->saved_regs;
  int * v10026 = v10024->regs;
  int v10027 = v10026[18];
  v10025[18] = v10027;
  int v10029 = v10024->timer;
  int v10039 = v10029 + 1;
  v10024->timer = v10039;
  int * v10031 = v10024->regs;
  v10031[18] = 1;
  struct StateG * v10033 = slot_517(v10024);
  return v10033;
}

struct StateG * slot_40(struct StateG * v900) {
  int v901 = v900->timer;
  int v908 = v901 + 1;
  v900->timer = v908;
  int * v903 = v900->regs;
  int v904 = v903[1];
  bool v911 = v904 == 24;
  ret_assert(v911);
  struct StateG * v906 = slot_44(v900);
  return v906;
}

struct StateG * slot_586(struct StateG * v12142) {
  int v12143 = v12142->timer;
  int v12149 = v12143 + 1;
  v12142->timer = v12149;
  int * v12145 = v12142->regs;
  v12145[17] = 10;
  struct StateG * v12147 = slot_602(v12142);
  return v12147;
}

struct StateG * slot_784(struct StateG * v15904) {
  int v15905 = v15904->timer;
  int v15915 = v15905 + 1;
  v15904->timer = v15915;
  int * v15907 = v15904->pht;
  int v15908 = v15907[23];
  bool v15918 = !(v15908 == 0);
  struct StateG * v15913;
  if (v15918) {
    struct StateG * v15909 = slot_808(v15904);
    v15913 = v15909;
  } else {
    struct StateG * v15911 = slot_809(v15904);
    v15913 = v15911;
  }
  return v15913;
}

struct StateG * slot_85(struct StateG * v1754) {
  int v1755 = v1754->timer;
  int v1761 = v1755 + 1;
  v1754->timer = v1761;
  int * v1757 = v1754->regs;
  v1757[18] = 1;
  struct StateG * v1759 = slot_87(v1754);
  return v1759;
}

struct StateG * slot_707(struct StateG * v14846) {
  int v14847 = v14846->timer;
  int v14851 = v14847 + 1;
  v14846->timer = v14851;
  struct StateG * v14849 = slot_725(v14846);
  return v14849;
}

struct StateG * slot_75(struct StateG * v1654) {
  int v1655 = v1654->timer;
  int v1659 = v1655 + 1;
  v1654->timer = v1659;
  struct StateG * v1657 = slot_89(v1654);
  return v1657;
}

struct StateG * slot_581(struct StateG * v12077) {
  int v12078 = v12077->timer;
  int v12084 = v12078 + 1;
  v12077->timer = v12084;
  int * v12080 = v12077->regs;
  v12080[1] = 156;
  struct StateG * v12082 = slot_597(v12077);
  return v12082;
}

struct StateG * slot_772(struct StateG * v15692) {
  int v15693 = v15692->timer;
  int v15699 = v15693 + 1;
  v15692->timer = v15699;
  int * v15695 = v15692->regs;
  v15695[17] = 10;
  struct StateG * v15697 = slot_788(v15692);
  return v15697;
}

struct StateG * slot_619(struct StateG * v12704) {
  int * v12705 = v12704->saved_regs;
  int * v12706 = v12704->regs;
  int v12707 = v12706[18];
  v12705[18] = v12707;
  int v12709 = v12704->timer;
  int v12719 = v12709 + 1;
  v12704->timer = v12719;
  int * v12711 = v12704->regs;
  v12711[18] = 1;
  struct StateG * v12713 = slot_651(v12704);
  return v12713;
}

struct StateG * slot_405(struct StateG * v8714) {
  int v8715 = v8714->timer;
  int v8721 = v8715 + 1;
  v8714->timer = v8721;
  int * v8717 = v8714->regs;
  v8717[18] = 1;
  struct StateG * v8719 = slot_407(v8714);
  return v8719;
}

struct StateG * slot_828(struct StateG * v16864) {
  int * v16865 = v16864->regs;
  int v16866 = v16865[16];
  int v16867 = v16865[17];
  bool v16887 = v16866 >= v16867;
  struct StateG * v16882;
  if (v16887) {
    int * v16868 = v16864->pht;
    v16868[29] = 1;
    struct StateG * v16870 = slot_883(v16864);
    v16882 = v16870;
  } else {
    int * v16872 = v16864->pht;
    v16872[29] = 0;
    int v16874 = v16864->timer;
    int v16896 = v16874 + 15;
    v16864->timer = v16896;
    int * v16876 = v16864->saved_regs;
    int v16877 = v16876[19];
    int * v16878 = v16864->regs;
    v16878[19] = v16877;
    struct StateG * v16880 = slot_861(v16864);
    v16882 = v16880;
  }
  return v16882;
}

struct StateG * slot_579(struct StateG * v12051) {
  int v12052 = v12051->timer;
  int v12058 = v12052 + 1;
  v12051->timer = v12058;
  int * v12054 = v12051->regs;
  v12054[1] = 156;
  struct StateG * v12056 = slot_595(v12051);
  return v12056;
}

struct StateG * slot_463(struct StateG * v9584) {
  int * v9585 = v9584->saved_regs;
  int * v9586 = v9584->regs;
  int v9587 = v9586[18];
  v9585[18] = v9587;
  int v9589 = v9584->timer;
  int v9599 = v9589 + 1;
  v9584->timer = v9599;
  int * v9591 = v9584->regs;
  v9591[18] = 1;
  struct StateG * v9593 = slot_495(v9584);
  return v9593;
}

struct StateG * slot_175(struct StateG * v3439) {
  int v3440 = v3439->timer;
  int v3446 = v3440 + 1;
  v3439->timer = v3446;
  int * v3442 = v3439->regs;
  v3442[17] = 10;
  struct StateG * v3444 = slot_191(v3439);
  return v3444;
}

struct StateG * slot_387(struct StateG * v8380) {
  int * v8381 = v8380->regs;
  int v8382 = v8381[16];
  int v8383 = v8381[17];
  bool v8403 = v8382 < v8383;
  struct StateG * v8398;
  if (v8403) {
    int * v8384 = v8380->pht;
    v8384[82] = 1;
    int v8386 = v8380->timer;
    int v8407 = v8386 + 15;
    v8380->timer = v8407;
    int * v8388 = v8380->saved_regs;
    int v8389 = v8388[18];
    int * v8390 = v8380->regs;
    v8390[18] = v8389;
    struct StateG * v8392 = slot_414(v8380);
    v8398 = v8392;
  } else {
    int * v8394 = v8380->pht;
    v8394[82] = 0;
    struct StateG * v8396 = slot_415(v8380);
    v8398 = v8396;
  }
  return v8398;
}

struct StateG * slot_621(struct StateG * v12744) {
  int * v12745 = v12744->saved_regs;
  int * v12746 = v12744->regs;
  int v12747 = v12746[18];
  v12745[18] = v12747;
  int v12749 = v12744->timer;
  int v12759 = v12749 + 1;
  v12744->timer = v12759;
  int * v12751 = v12744->regs;
  v12751[18] = 1;
  struct StateG * v12753 = slot_653(v12744);
  return v12753;
}

struct StateG * slot_777(struct StateG * v15764) {
  int v15765 = v15764->timer;
  int v15775 = v15765 + 1;
  v15764->timer = v15775;
  int * v15767 = v15764->pht;
  int v15768 = v15767[30];
  bool v15778 = !(v15768 == 0);
  struct StateG * v15773;
  if (v15778) {
    struct StateG * v15769 = slot_794(v15764);
    v15773 = v15769;
  } else {
    struct StateG * v15771 = slot_795(v15764);
    v15773 = v15771;
  }
  return v15773;
}

struct StateG * slot_565(struct StateG * v11869) {
  int v11870 = v11869->timer;
  int v11876 = v11870 + 1;
  v11869->timer = v11876;
  int * v11872 = v11869->regs;
  v11872[1] = 148;
  struct StateG * v11874 = slot_581(v11869);
  return v11874;
}

struct StateG * slot_188(struct StateG * v3636) {
  int v3637 = v3636->timer;
  int v3647 = v3637 + 1;
  v3636->timer = v3647;
  int * v3639 = v3636->pht;
  int v3640 = v3639[75];
  bool v3650 = !(v3640 == 0);
  struct StateG * v3645;
  if (v3650) {
    struct StateG * v3641 = slot_208(v3636);
    v3645 = v3641;
  } else {
    struct StateG * v3643 = slot_209(v3636);
    v3645 = v3643;
  }
  return v3645;
}

struct StateG * slot_758(struct StateG * v15510) {
  int v15511 = v15510->timer;
  int v15517 = v15511 + 1;
  v15510->timer = v15517;
  int * v15513 = v15510->regs;
  v15513[1] = 164;
  struct StateG * v15515 = slot_774(v15510);
  return v15515;
}

struct StateG * slot_495(struct StateG * v10364) {
  int * v10365 = v10364->regs;
  int v10366 = v10365[16];
  int v10367 = v10365[17];
  bool v10387 = v10366 < v10367;
  struct StateG * v10382;
  if (v10387) {
    int * v10368 = v10364->pht;
    v10368[108] = 1;
    int v10370 = v10364->timer;
    int v10391 = v10370 + 15;
    v10364->timer = v10391;
    int * v10372 = v10364->saved_regs;
    int v10373 = v10372[18];
    int * v10374 = v10364->regs;
    v10374[18] = v10373;
    struct StateG * v10376 = slot_534(v10364);
    v10382 = v10376;
  } else {
    int * v10378 = v10364->pht;
    v10378[108] = 0;
    struct StateG * v10380 = slot_535(v10364);
    v10382 = v10380;
  }
  return v10382;
}

struct StateG * slot_110(struct StateG * v2172) {
  int * v2173 = v2172->saved_regs;
  int * v2174 = v2172->regs;
  int v2175 = v2174[18];
  v2173[18] = v2175;
  int v2177 = v2172->timer;
  int v2187 = v2177 + 1;
  v2172->timer = v2187;
  int * v2179 = v2172->regs;
  v2179[18] = 2;
  struct StateG * v2181 = slot_126(v2172);
  return v2181;
}

struct StateG * slot_301(struct StateG * v6197) {
  int v6198 = v6197->timer;
  int v6204 = v6198 + 1;
  v6197->timer = v6204;
  int * v6200 = v6197->regs;
  v6200[17] = 10;
  struct StateG * v6202 = slot_317(v6197);
  return v6202;
}

struct StateG * slot_502(struct StateG * v10644) {
  int * v10645 = v10644->regs;
  int v10646 = v10645[16];
  int v10647 = v10645[17];
  bool v10667 = v10646 < v10647;
  struct StateG * v10662;
  if (v10667) {
    int * v10648 = v10644->pht;
    v10648[104] = 1;
    struct StateG * v10650 = slot_548(v10644);
    v10662 = v10650;
  } else {
    int * v10652 = v10644->pht;
    v10652[104] = 0;
    int v10654 = v10644->timer;
    int v10676 = v10654 + 15;
    v10644->timer = v10676;
    int * v10656 = v10644->saved_regs;
    int v10657 = v10656[18];
    int * v10658 = v10644->regs;
    v10658[18] = v10657;
    struct StateG * v10660 = slot_549(v10644);
    v10662 = v10660;
  }
  return v10662;
}

struct StateG * slot_320(struct StateG * v6500) {
  int v6501 = v6500->timer;
  int v6511 = v6501 + 1;
  v6500->timer = v6511;
  int * v6503 = v6500->pht;
  int v6504 = v6503[87];
  bool v6514 = !(v6504 == 0);
  struct StateG * v6509;
  if (v6514) {
    struct StateG * v6505 = slot_344(v6500);
    v6509 = v6505;
  } else {
    struct StateG * v6507 = slot_345(v6500);
    v6509 = v6507;
  }
  return v6509;
}

struct StateG * slot_756(struct StateG * v15484) {
  int v15485 = v15484->timer;
  int v15491 = v15485 + 1;
  v15484->timer = v15491;
  int * v15487 = v15484->regs;
  v15487[1] = 164;
  struct StateG * v15489 = slot_772(v15484);
  return v15489;
}

struct StateG * slot_727(struct StateG * v15106) {
  int v15107 = v15106->timer;
  int v15114 = v15107 + 1;
  v15106->timer = v15114;
  int * v15109 = v15106->regs;
  int v15110 = v15109[1];
  bool v15117 = v15110 == 156;
  ret_assert(v15117);
  struct StateG * v15112 = slot_743(v15106);
  return v15112;
}

struct StateG * slot_203(struct StateG * v3936) {
  int * v3937 = v3936->saved_regs;
  int * v3938 = v3936->regs;
  int v3939 = v3938[18];
  v3937[18] = v3939;
  int v3941 = v3936->timer;
  int v3951 = v3941 + 1;
  v3936->timer = v3951;
  int * v3943 = v3936->regs;
  v3943[18] = 1;
  struct StateG * v3945 = slot_235(v3936);
  return v3945;
}

struct StateG * slot_157(struct StateG * v3230) {
  int v3231 = v3230->timer;
  int v3237 = v3231 + 1;
  v3230->timer = v3237;
  int * v3233 = v3230->regs;
  v3233[18] = 1;
  struct StateG * v3235 = slot_159(v3230);
  return v3235;
}

struct StateG * slot_587(struct StateG * v12155) {
  int v12156 = v12155->timer;
  int v12162 = v12156 + 1;
  v12155->timer = v12162;
  int * v12158 = v12155->regs;
  v12158[17] = 10;
  struct StateG * v12160 = slot_603(v12155);
  return v12160;
}

struct StateG * slot_453(struct StateG * v9384) {
  int v9385 = v9384->timer;
  int v9395 = v9385 + 1;
  v9384->timer = v9395;
  int * v9387 = v9384->pht;
  int v9388 = v9387[98];
  bool v9398 = !(v9388 == 0);
  struct StateG * v9393;
  if (v9398) {
    struct StateG * v9389 = slot_482(v9384);
    v9393 = v9389;
  } else {
    struct StateG * v9391 = slot_483(v9384);
    v9393 = v9391;
  }
  return v9393;
}

struct StateG * slot_712(struct StateG * v14896) {
  int v14897 = v14896->timer;
  int v14904 = v14897 + 1;
  v14896->timer = v14904;
  int * v14899 = v14896->regs;
  int v14900 = v14899[1];
  bool v14907 = v14900 == 156;
  ret_assert(v14907);
  struct StateG * v14902 = slot_728(v14896);
  return v14902;
}

struct StateG * slot_26(struct StateG * v624) {
  int * v625 = v624->saved_regs;
  int * v626 = v624->regs;
  int v627 = v626[19];
  v625[19] = v627;
  int v629 = v624->timer;
  int v639 = v629 + 1;
  v624->timer = v639;
  int * v631 = v624->regs;
  v631[19] = 2;
  struct StateG * v633 = slot_30(v624);
  return v633;
}

struct StateG * slot_370(struct StateG * v7700) {
  int * v7701 = v7700->regs;
  int v7702 = v7701[16];
  int v7703 = v7701[17];
  bool v7723 = v7702 < v7703;
  struct StateG * v7718;
  if (v7723) {
    int * v7704 = v7700->pht;
    v7704[90] = 1;
    struct StateG * v7706 = slot_412(v7700);
    v7718 = v7706;
  } else {
    int * v7708 = v7700->pht;
    v7708[90] = 0;
    int v7710 = v7700->timer;
    int v7732 = v7710 + 15;
    v7700->timer = v7732;
    int * v7712 = v7700->saved_regs;
    int v7713 = v7712[18];
    int * v7714 = v7700->regs;
    v7714[18] = v7713;
    struct StateG * v7716 = slot_413(v7700);
    v7718 = v7716;
  }
  return v7718;
}

struct StateG * slot_652(struct StateG * v13444) {
  int * v13445 = v13444->regs;
  int v13446 = v13445[16];
  int v13447 = v13445[17];
  bool v13467 = v13446 < v13447;
  struct StateG * v13462;
  if (v13467) {
    int * v13448 = v13444->pht;
    v13448[13] = 1;
    struct StateG * v13450 = slot_688(v13444);
    v13462 = v13450;
  } else {
    int * v13452 = v13444->pht;
    v13452[13] = 0;
    int v13454 = v13444->timer;
    int v13476 = v13454 + 15;
    v13444->timer = v13476;
    int * v13456 = v13444->saved_regs;
    int v13457 = v13456[18];
    int * v13458 = v13444->regs;
    v13458[18] = v13457;
    struct StateG * v13460 = slot_689(v13444);
    v13462 = v13460;
  }
  return v13462;
}

struct StateG * slot_583(struct StateG * v12103) {
  int v12104 = v12103->timer;
  int v12110 = v12104 + 1;
  v12103->timer = v12110;
  int * v12106 = v12103->regs;
  v12106[1] = 156;
  struct StateG * v12108 = slot_599(v12103);
  return v12108;
}

struct StateG * slot_817(struct StateG * v16564) {
  int * v16565 = v16564->saved_regs;
  int * v16566 = v16564->regs;
  int v16567 = v16566[19];
  v16565[19] = v16567;
  int v16569 = v16564->timer;
  int v16579 = v16569 + 1;
  v16564->timer = v16579;
  int * v16571 = v16564->regs;
  v16571[19] = 1;
  struct StateG * v16573 = slot_849(v16564);
  return v16573;
}

struct StateG * slot_206(struct StateG * v3996) {
  int * v3997 = v3996->saved_regs;
  int * v3998 = v3996->regs;
  int v3999 = v3998[18];
  v3997[18] = v3999;
  int v4001 = v3996->timer;
  int v4011 = v4001 + 1;
  v3996->timer = v4011;
  int * v4003 = v3996->regs;
  v4003[18] = 2;
  struct StateG * v4005 = slot_238(v3996);
  return v4005;
}

struct StateG * slot_169(struct StateG * v3361) {
  int v3362 = v3361->timer;
  int v3368 = v3362 + 1;
  v3361->timer = v3368;
  int * v3364 = v3361->regs;
  v3364[17] = 10;
  struct StateG * v3366 = slot_185(v3361);
  return v3366;
}

struct StateG * slot_858(struct StateG * v17995) {
  int v17996 = v17995->timer;
  int v18002 = v17996 + 1;
  v17995->timer = v18002;
  int * v17998 = v17995->regs;
  v17998[19] = 2;
  struct StateG * v18000 = slot_883(v17995);
  return v18000;
}

struct StateG * slot_14(struct StateG * v438) {
  int v439 = v438->timer;
  int v446 = v439 + 1;
  v438->timer = v446;
  int * v441 = v438->regs;
  int v442 = v441[1];
  bool v449 = v442 == 16;
  ret_assert(v449);
  struct StateG * v444 = slot_16(v438);
  return v444;
}

struct StateG * slot_357(struct StateG * v7240) {
  int * v7241 = v7240->saved_regs;
  int * v7242 = v7240->regs;
  int v7243 = v7242[18];
  v7241[18] = v7243;
  int v7245 = v7240->timer;
  int v7255 = v7245 + 1;
  v7240->timer = v7255;
  int * v7247 = v7240->regs;
  v7247[18] = 1;
  struct StateG * v7249 = slot_389(v7240);
  return v7249;
}

struct StateG * slot_385(struct StateG * v8300) {
  int * v8301 = v8300->regs;
  int v8302 = v8301[16];
  int v8303 = v8301[17];
  bool v8323 = v8302 < v8303;
  struct StateG * v8318;
  if (v8323) {
    int * v8304 = v8300->pht;
    v8304[83] = 1;
    int v8306 = v8300->timer;
    int v8327 = v8306 + 15;
    v8300->timer = v8327;
    int * v8308 = v8300->saved_regs;
    int v8309 = v8308[18];
    int * v8310 = v8300->regs;
    v8310[18] = v8309;
    struct StateG * v8312 = slot_410(v8300);
    v8318 = v8312;
  } else {
    int * v8314 = v8300->pht;
    v8314[83] = 0;
    struct StateG * v8316 = slot_411(v8300);
    v8318 = v8316;
  }
  return v8318;
}

struct StateG * slot_602(struct StateG * v12364) {
  int v12365 = v12364->timer;
  int v12375 = v12365 + 1;
  v12364->timer = v12375;
  int * v12367 = v12364->pht;
  int v12368 = v12367[13];
  bool v12378 = !(v12368 == 0);
  struct StateG * v12373;
  if (v12378) {
    struct StateG * v12369 = slot_620(v12364);
    v12373 = v12369;
  } else {
    struct StateG * v12371 = slot_621(v12364);
    v12373 = v12371;
  }
  return v12373;
}

struct StateG * slot_261(struct StateG * v5676) {
  int * v5677 = v5676->regs;
  int v5678 = v5677[16];
  int v5679 = v5677[17];
  bool v5699 = v5678 < v5679;
  struct StateG * v5694;
  if (v5699) {
    int * v5680 = v5676->pht;
    v5680[65] = 1;
    int v5682 = v5676->timer;
    int v5703 = v5682 + 15;
    v5676->timer = v5703;
    int * v5684 = v5676->saved_regs;
    int v5685 = v5684[18];
    int * v5686 = v5676->regs;
    v5686[18] = v5685;
    struct StateG * v5688 = slot_290(v5676);
    v5694 = v5688;
  } else {
    int * v5690 = v5676->pht;
    v5690[65] = 0;
    struct StateG * v5692 = slot_291(v5676);
    v5694 = v5692;
  }
  return v5694;
}

struct StateG * slot_838(struct StateG * v17264) {
  int * v17265 = v17264->regs;
  int v17266 = v17265[16];
  int v17267 = v17265[17];
  bool v17287 = v17266 >= v17267;
  struct StateG * v17282;
  if (v17287) {
    int * v17268 = v17264->pht;
    v17268[24] = 1;
    struct StateG * v17270 = slot_883(v17264);
    v17282 = v17270;
  } else {
    int * v17272 = v17264->pht;
    v17272[24] = 0;
    int v17274 = v17264->timer;
    int v17296 = v17274 + 15;
    v17264->timer = v17296;
    int * v17276 = v17264->saved_regs;
    int v17277 = v17276[19];
    int * v17278 = v17264->regs;
    v17278[19] = v17277;
    struct StateG * v17280 = slot_861(v17264);
    v17282 = v17280;
  }
  return v17282;
}

struct StateG * slot_603(struct StateG * v12384) {
  int v12385 = v12384->timer;
  int v12395 = v12385 + 1;
  v12384->timer = v12395;
  int * v12387 = v12384->pht;
  int v12388 = v12387[12];
  bool v12398 = !(v12388 == 0);
  struct StateG * v12393;
  if (v12398) {
    struct StateG * v12389 = slot_622(v12384);
    v12393 = v12389;
  } else {
    struct StateG * v12391 = slot_623(v12384);
    v12393 = v12391;
  }
  return v12393;
}

struct StateG * slot_740(struct StateG * v15276) {
  int v15277 = v15276->timer;
  int v15283 = v15277 + 1;
  v15276->timer = v15283;
  int * v15279 = v15276->regs;
  v15279[1] = 156;
  struct StateG * v15281 = slot_756(v15276);
  return v15281;
}

struct StateG * slot_831(struct StateG * v16984) {
  int * v16985 = v16984->regs;
  int v16986 = v16985[16];
  int v16987 = v16985[17];
  bool v17007 = v16986 >= v16987;
  struct StateG * v17002;
  if (v17007) {
    int * v16988 = v16984->pht;
    v16988[28] = 1;
    int v16990 = v16984->timer;
    int v17011 = v16990 + 15;
    v16984->timer = v17011;
    int * v16992 = v16984->saved_regs;
    int v16993 = v16992[19];
    int * v16994 = v16984->regs;
    v16994[19] = v16993;
    struct StateG * v16996 = slot_858(v16984);
    v17002 = v16996;
  } else {
    int * v16998 = v16984->pht;
    v16998[28] = 0;
    struct StateG * v17000 = slot_883(v16984);
    v17002 = v17000;
  }
  return v17002;
}

struct StateG * slot_639(struct StateG * v13104) {
  int * v13105 = v13104->saved_regs;
  int * v13106 = v13104->regs;
  int v13107 = v13106[18];
  v13105[18] = v13107;
  int v13109 = v13104->timer;
  int v13119 = v13109 + 1;
  v13104->timer = v13119;
  int * v13111 = v13104->regs;
  v13111[18] = 1;
  struct StateG * v13113 = slot_671(v13104);
  return v13113;
}

struct StateG * slot_36(struct StateG * v858) {
  int v859 = v858->timer;
  int v863 = v859 + 1;
  v858->timer = v863;
  struct StateG * v861 = slot_42(v858);
  return v861;
}

struct StateG * slot_57(struct StateG * v1160) {
  int * v1161 = v1160->saved_regs;
  int * v1162 = v1160->regs;
  int v1163 = v1162[18];
  v1161[18] = v1163;
  int v1165 = v1160->timer;
  int v1175 = v1165 + 1;
  v1160->timer = v1175;
  int * v1167 = v1160->regs;
  v1167[18] = 1;
  struct StateG * v1169 = slot_65(v1160);
  return v1169;
}

struct StateG * slot_426(struct StateG * v8942) {
  int v8943 = v8942->timer;
  int v8949 = v8943 + 1;
  v8942->timer = v8949;
  int * v8945 = v8942->regs;
  v8945[17] = 10;
  struct StateG * v8947 = slot_442(v8942);
  return v8947;
}

struct StateG * slot_431(struct StateG * v9007) {
  int v9008 = v9007->timer;
  int v9014 = v9008 + 1;
  v9007->timer = v9014;
  int * v9010 = v9007->regs;
  v9010[17] = 10;
  struct StateG * v9012 = slot_447(v9007);
  return v9012;
}

struct StateG * slot_729(struct StateG * v15133) {
  int v15134 = v15133->timer;
  int v15140 = v15134 + 1;
  v15133->timer = v15140;
  int * v15136 = v15133->regs;
  v15136[1] = 156;
  struct StateG * v15138 = slot_745(v15133);
  return v15138;
}

struct StateG * slot_62(struct StateG * v1260) {
  int * v1261 = v1260->saved_regs;
  int * v1262 = v1260->regs;
  int v1263 = v1262[18];
  v1261[18] = v1263;
  int v1265 = v1260->timer;
  int v1275 = v1265 + 1;
  v1260->timer = v1275;
  int * v1267 = v1260->regs;
  v1267[18] = 2;
  struct StateG * v1269 = slot_70(v1260);
  return v1269;
}

struct StateG * slot_308(struct StateG * v6288) {
  int v6289 = v6288->timer;
  int v6295 = v6289 + 1;
  v6288->timer = v6295;
  int * v6291 = v6288->regs;
  v6291[17] = 10;
  struct StateG * v6293 = slot_324(v6288);
  return v6293;
}

struct StateG * slot_400(struct StateG * v8664) {
  int v8665 = v8664->timer;
  int v8669 = v8665 + 1;
  v8664->timer = v8669;
  struct StateG * v8667 = slot_428(v8664);
  return v8667;
}

struct StateG * slot_323(struct StateG * v6560) {
  int v6561 = v6560->timer;
  int v6571 = v6561 + 1;
  v6560->timer = v6571;
  int * v6563 = v6560->pht;
  int v6564 = v6563[84];
  bool v6574 = !(v6564 == 0);
  struct StateG * v6569;
  if (v6574) {
    struct StateG * v6565 = slot_350(v6560);
    v6569 = v6565;
  } else {
    struct StateG * v6567 = slot_351(v6560);
    v6569 = v6567;
  }
  return v6569;
}

struct StateG * slot_628(struct StateG * v12884) {
  int * v12885 = v12884->saved_regs;
  int * v12886 = v12884->regs;
  int v12887 = v12886[18];
  v12885[18] = v12887;
  int v12889 = v12884->timer;
  int v12899 = v12889 + 1;
  v12884->timer = v12899;
  int * v12891 = v12884->regs;
  v12891[18] = 2;
  struct StateG * v12893 = slot_660(v12884);
  return v12893;
}

struct StateG * slot_521(struct StateG * v11372) {
  int v11373 = v11372->timer;
  int v11379 = v11373 + 1;
  v11372->timer = v11379;
  int * v11375 = v11372->regs;
  v11375[18] = 1;
  struct StateG * v11377 = slot_523(v11372);
  return v11377;
}

struct StateG * slot_530(struct StateG * v11469) {
  int v11470 = v11469->timer;
  int v11476 = v11470 + 1;
  v11469->timer = v11476;
  int * v11472 = v11469->regs;
  v11472[18] = 2;
  struct StateG * v11474 = slot_528(v11469);
  return v11474;
}

struct StateG * slot_23(struct StateG * v564) {
  int v565 = v564->timer;
  int v575 = v565 + 1;
  v564->timer = v575;
  int * v567 = v564->pht;
  int v568 = v567[16];
  bool v578 = !(v568 == 0);
  struct StateG * v573;
  if (v578) {
    struct StateG * v569 = slot_26(v564);
    v573 = v569;
  } else {
    struct StateG * v571 = slot_27(v564);
    v573 = v571;
  }
  return v573;
}

struct StateG * slot_2(struct StateG * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[1] = 8;
  struct StateG * v224 = slot_3(v219);
  return v224;
}

struct StateG * slot_86(struct StateG * v1767) {
  int v1768 = v1767->timer;
  int v1774 = v1768 + 1;
  v1767->timer = v1774;
  int * v1770 = v1767->regs;
  v1770[18] = 2;
  struct StateG * v1772 = slot_84(v1767);
  return v1772;
}

struct StateG * slot_836(struct StateG * v17184) {
  int * v17185 = v17184->regs;
  int v17186 = v17185[16];
  int v17187 = v17185[17];
  bool v17207 = v17186 >= v17187;
  struct StateG * v17202;
  if (v17207) {
    int * v17188 = v17184->pht;
    v17188[25] = 1;
    struct StateG * v17190 = slot_883(v17184);
    v17202 = v17190;
  } else {
    int * v17192 = v17184->pht;
    v17192[25] = 0;
    int v17194 = v17184->timer;
    int v17216 = v17194 + 15;
    v17184->timer = v17216;
    int * v17196 = v17184->saved_regs;
    int v17197 = v17196[19];
    int * v17198 = v17184->regs;
    v17198[19] = v17197;
    struct StateG * v17200 = slot_861(v17184);
    v17202 = v17200;
  }
  return v17202;
}

struct StateG * slot_538(struct StateG * v11553) {
  int v11554 = v11553->timer;
  int v11560 = v11554 + 1;
  v11553->timer = v11560;
  int * v11556 = v11553->regs;
  v11556[18] = 2;
  struct StateG * v11558 = slot_536(v11553);
  return v11558;
}

struct StateG * slot_693(struct StateG * v14694) {
  int v14695 = v14694->timer;
  int v14701 = v14695 + 1;
  v14694->timer = v14701;
  int * v14697 = v14694->regs;
  v14697[18] = 1;
  struct StateG * v14699 = slot_695(v14694);
  return v14699;
}

struct StateG * slot_100(struct StateG * v1972) {
  int v1973 = v1972->timer;
  int v1983 = v1973 + 1;
  v1972->timer = v1983;
  int * v1975 = v1972->pht;
  int v1976 = v1975[51];
  bool v1986 = !(v1976 == 0);
  struct StateG * v1981;
  if (v1986) {
    struct StateG * v1977 = slot_112(v1972);
    v1981 = v1977;
  } else {
    struct StateG * v1979 = slot_113(v1972);
    v1981 = v1979;
  }
  return v1981;
}

struct StateG * slot_747(struct StateG * v15367) {
  int v15368 = v15367->timer;
  int v15374 = v15368 + 1;
  v15367->timer = v15374;
  int * v15370 = v15367->regs;
  v15370[1] = 164;
  struct StateG * v15372 = slot_763(v15367);
  return v15372;
}

struct StateG * slot_13(struct StateG * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateG * v433 = slot_15(v430);
  return v433;
}

struct StateG * slot_449(struct StateG * v9304) {
  int v9305 = v9304->timer;
  int v9315 = v9305 + 1;
  v9304->timer = v9315;
  int * v9307 = v9304->pht;
  int v9308 = v9307[102];
  bool v9318 = !(v9308 == 0);
  struct StateG * v9313;
  if (v9318) {
    struct StateG * v9309 = slot_474(v9304);
    v9313 = v9309;
  } else {
    struct StateG * v9311 = slot_475(v9304);
    v9313 = v9311;
  }
  return v9313;
}

struct StateG * slot_569(struct StateG * v11921) {
  int v11922 = v11921->timer;
  int v11928 = v11922 + 1;
  v11921->timer = v11928;
  int * v11924 = v11921->regs;
  v11924[1] = 156;
  struct StateG * v11926 = slot_585(v11921);
  return v11926;
}

struct StateG * slot_460(struct StateG * v9524) {
  int * v9525 = v9524->saved_regs;
  int * v9526 = v9524->regs;
  int v9527 = v9526[18];
  v9525[18] = v9527;
  int v9529 = v9524->timer;
  int v9539 = v9529 + 1;
  v9524->timer = v9539;
  int * v9531 = v9524->regs;
  v9531[18] = 2;
  struct StateG * v9533 = slot_492(v9524);
  return v9533;
}

struct StateG * slot_109(struct StateG * v2152) {
  int * v2153 = v2152->saved_regs;
  int * v2154 = v2152->regs;
  int v2155 = v2154[18];
  v2153[18] = v2155;
  int v2157 = v2152->timer;
  int v2167 = v2157 + 1;
  v2152->timer = v2167;
  int * v2159 = v2152->regs;
  v2159[18] = 1;
  struct StateG * v2161 = slot_125(v2152);
  return v2161;
}

struct StateG * slot_629(struct StateG * v12904) {
  int * v12905 = v12904->saved_regs;
  int * v12906 = v12904->regs;
  int v12907 = v12906[18];
  v12905[18] = v12907;
  int v12909 = v12904->timer;
  int v12919 = v12909 + 1;
  v12904->timer = v12919;
  int * v12911 = v12904->regs;
  v12911[18] = 1;
  struct StateG * v12913 = slot_661(v12904);
  return v12913;
}

struct StateG * slot_609(struct StateG * v12504) {
  int v12505 = v12504->timer;
  int v12515 = v12505 + 1;
  v12504->timer = v12515;
  int * v12507 = v12504->pht;
  int v12508 = v12507[6];
  bool v12518 = !(v12508 == 0);
  struct StateG * v12513;
  if (v12518) {
    struct StateG * v12509 = slot_634(v12504);
    v12513 = v12509;
  } else {
    struct StateG * v12511 = slot_635(v12504);
    v12513 = v12511;
  }
  return v12513;
}

struct StateG * slot_224(struct StateG * v4356) {
  int * v4357 = v4356->saved_regs;
  int * v4358 = v4356->regs;
  int v4359 = v4358[18];
  v4357[18] = v4359;
  int v4361 = v4356->timer;
  int v4371 = v4361 + 1;
  v4356->timer = v4371;
  int * v4363 = v4356->regs;
  v4363[18] = 2;
  struct StateG * v4365 = slot_256(v4356);
  return v4365;
}

struct StateG * slot_796(struct StateG * v16144) {
  int * v16145 = v16144->saved_regs;
  int * v16146 = v16144->regs;
  int v16147 = v16146[19];
  v16145[19] = v16147;
  int v16149 = v16144->timer;
  int v16159 = v16149 + 1;
  v16144->timer = v16159;
  int * v16151 = v16144->regs;
  v16151[19] = 2;
  struct StateG * v16153 = slot_828(v16144);
  return v16153;
}

struct StateG * slot_184(struct StateG * v3556) {
  int v3557 = v3556->timer;
  int v3567 = v3557 + 1;
  v3556->timer = v3567;
  int * v3559 = v3556->pht;
  int v3560 = v3559[79];
  bool v3570 = !(v3560 == 0);
  struct StateG * v3565;
  if (v3570) {
    struct StateG * v3561 = slot_200(v3556);
    v3565 = v3561;
  } else {
    struct StateG * v3563 = slot_201(v3556);
    v3565 = v3563;
  }
  return v3565;
}

struct StateG * slot_562(struct StateG * v11830) {
  int v11831 = v11830->timer;
  int v11837 = v11831 + 1;
  v11830->timer = v11837;
  int * v11833 = v11830->regs;
  v11833[1] = 148;
  struct StateG * v11835 = slot_578(v11830);
  return v11835;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_584(struct StateG * v12116) {
  int v12117 = v12116->timer;
  int v12123 = v12117 + 1;
  v12116->timer = v12123;
  int * v12119 = v12116->regs;
  v12119[17] = 10;
  struct StateG * v12121 = slot_600(v12116);
  return v12121;
}

struct StateG * slot_393(struct StateG * v8588) {
  int v8589 = v8588->timer;
  int v8595 = v8589 + 1;
  v8588->timer = v8595;
  int * v8591 = v8588->regs;
  v8591[18] = 1;
  struct StateG * v8593 = slot_395(v8588);
  return v8593;
}

struct StateG * slot_477(struct StateG * v9864) {
  int * v9865 = v9864->saved_regs;
  int * v9866 = v9864->regs;
  int v9867 = v9866[18];
  v9865[18] = v9867;
  int v9869 = v9864->timer;
  int v9879 = v9869 + 1;
  v9864->timer = v9879;
  int * v9871 = v9864->regs;
  v9871[18] = 1;
  struct StateG * v9873 = slot_509(v9864);
  return v9873;
}

struct StateG * slot_761(struct StateG * v15549) {
  int v15550 = v15549->timer;
  int v15556 = v15550 + 1;
  v15549->timer = v15556;
  int * v15552 = v15549->regs;
  v15552[17] = 10;
  struct StateG * v15554 = slot_777(v15549);
  return v15554;
}

struct StateG * slot_690(struct StateG * v14665) {
  int v14666 = v14665->timer;
  int v14672 = v14666 + 1;
  v14665->timer = v14672;
  int * v14668 = v14665->regs;
  v14668[18] = 2;
  struct StateG * v14670 = slot_688(v14665);
  return v14670;
}

struct StateG * slot_352(struct StateG * v7140) {
  int * v7141 = v7140->saved_regs;
  int * v7142 = v7140->regs;
  int v7143 = v7142[18];
  v7141[18] = v7143;
  int v7145 = v7140->timer;
  int v7155 = v7145 + 1;
  v7140->timer = v7155;
  int * v7147 = v7140->regs;
  v7147[18] = 2;
  struct StateG * v7149 = slot_384(v7140);
  return v7149;
}

struct StateG * slot_561(struct StateG * v11817) {
  int v11818 = v11817->timer;
  int v11824 = v11818 + 1;
  v11817->timer = v11824;
  int * v11820 = v11817->regs;
  v11820[1] = 148;
  struct StateG * v11822 = slot_577(v11817);
  return v11822;
}

struct StateG * slot_249(struct StateG * v5196) {
  int * v5197 = v5196->regs;
  int v5198 = v5197[16];
  int v5199 = v5197[17];
  bool v5219 = v5198 < v5199;
  struct StateG * v5214;
  if (v5219) {
    int * v5200 = v5196->pht;
    v5200[71] = 1;
    int v5202 = v5196->timer;
    int v5223 = v5202 + 15;
    v5196->timer = v5223;
    int * v5204 = v5196->saved_regs;
    int v5205 = v5204[18];
    int * v5206 = v5196->regs;
    v5206[18] = v5205;
    struct StateG * v5208 = slot_266(v5196);
    v5214 = v5208;
  } else {
    int * v5210 = v5196->pht;
    v5210[71] = 0;
    struct StateG * v5212 = slot_267(v5196);
    v5214 = v5212;
  }
  return v5214;
}

struct StateG * slot_11(struct StateG * v404) {
  int v405 = v404->timer;
  int v411 = v405 + 1;
  v404->timer = v411;
  int * v407 = v404->regs;
  v407[18] = 1;
  struct StateG * v409 = slot_13(v404);
  return v409;
}

struct StateG * slot_228(struct StateG * v4436) {
  int * v4437 = v4436->saved_regs;
  int * v4438 = v4436->regs;
  int v4439 = v4438[18];
  v4437[18] = v4439;
  int v4441 = v4436->timer;
  int v4451 = v4441 + 1;
  v4436->timer = v4451;
  int * v4443 = v4436->regs;
  v4443[18] = 2;
  struct StateG * v4445 = slot_260(v4436);
  return v4445;
}

struct StateG * slot_268(struct StateG * v5838) {
  int v5839 = v5838->timer;
  int v5843 = v5839 + 1;
  v5838->timer = v5843;
  struct StateG * v5841 = slot_298(v5838);
  return v5841;
}

struct StateG * slot_199(struct StateG * v3856) {
  int v3857 = v3856->timer;
  int v3867 = v3857 + 1;
  v3856->timer = v3867;
  int * v3859 = v3856->pht;
  int v3860 = v3859[64];
  bool v3870 = !(v3860 == 0);
  struct StateG * v3865;
  if (v3870) {
    struct StateG * v3861 = slot_230(v3856);
    v3865 = v3861;
  } else {
    struct StateG * v3863 = slot_231(v3856);
    v3865 = v3863;
  }
  return v3865;
}

struct StateG * slot_653(struct StateG * v13484) {
  int * v13485 = v13484->regs;
  int v13486 = v13485[16];
  int v13487 = v13485[17];
  bool v13507 = v13486 < v13487;
  struct StateG * v13502;
  if (v13507) {
    int * v13488 = v13484->pht;
    v13488[13] = 1;
    int v13490 = v13484->timer;
    int v13511 = v13490 + 15;
    v13484->timer = v13511;
    int * v13492 = v13484->saved_regs;
    int v13493 = v13492[18];
    int * v13494 = v13484->regs;
    v13494[18] = v13493;
    struct StateG * v13496 = slot_690(v13484);
    v13502 = v13496;
  } else {
    int * v13498 = v13484->pht;
    v13498[13] = 0;
    struct StateG * v13500 = slot_691(v13484);
    v13502 = v13500;
  }
  return v13502;
}

struct StateG * slot_409(struct StateG * v8756) {
  int v8757 = v8756->timer;
  int v8763 = v8757 + 1;
  v8756->timer = v8763;
  int * v8759 = v8756->regs;
  v8759[18] = 1;
  struct StateG * v8761 = slot_411(v8756);
  return v8761;
}

struct StateG * slot_822(struct StateG * v16664) {
  int * v16665 = v16664->saved_regs;
  int * v16666 = v16664->regs;
  int v16667 = v16666[19];
  v16665[19] = v16667;
  int v16669 = v16664->timer;
  int v16679 = v16669 + 1;
  v16664->timer = v16679;
  int * v16671 = v16664->regs;
  v16671[19] = 2;
  struct StateG * v16673 = slot_854(v16664);
  return v16673;
}

struct StateG * slot_269(struct StateG * v5846) {
  int v5847 = v5846->timer;
  int v5853 = v5847 + 1;
  v5846->timer = v5853;
  int * v5849 = v5846->regs;
  v5849[18] = 1;
  struct StateG * v5851 = slot_271(v5846);
  return v5851;
}

struct StateG * slot_827(struct StateG * v16824) {
  int * v16825 = v16824->regs;
  int v16826 = v16825[16];
  int v16827 = v16825[17];
  bool v16847 = v16826 >= v16827;
  struct StateG * v16842;
  if (v16847) {
    int * v16828 = v16824->pht;
    v16828[30] = 1;
    int v16830 = v16824->timer;
    int v16851 = v16830 + 15;
    v16824->timer = v16851;
    int * v16832 = v16824->saved_regs;
    int v16833 = v16832[19];
    int * v16834 = v16824->regs;
    v16834[19] = v16833;
    struct StateG * v16836 = slot_858(v16824);
    v16842 = v16836;
  } else {
    int * v16838 = v16824->pht;
    v16838[30] = 0;
    struct StateG * v16840 = slot_883(v16824);
    v16842 = v16840;
  }
  return v16842;
}

struct StateG * slot_681(struct StateG * v14568) {
  int v14569 = v14568->timer;
  int v14575 = v14569 + 1;
  v14568->timer = v14575;
  int * v14571 = v14568->regs;
  v14571[18] = 1;
  struct StateG * v14573 = slot_683(v14568);
  return v14573;
}

struct StateG * slot_501(struct StateG * v10604) {
  int * v10605 = v10604->regs;
  int v10606 = v10605[16];
  int v10607 = v10605[17];
  bool v10627 = v10606 < v10607;
  struct StateG * v10622;
  if (v10627) {
    int * v10608 = v10604->pht;
    v10608[105] = 1;
    int v10610 = v10604->timer;
    int v10631 = v10610 + 15;
    v10604->timer = v10631;
    int * v10612 = v10604->saved_regs;
    int v10613 = v10612[18];
    int * v10614 = v10604->regs;
    v10614[18] = v10613;
    struct StateG * v10616 = slot_546(v10604);
    v10622 = v10616;
  } else {
    int * v10618 = v10604->pht;
    v10618[105] = 0;
    struct StateG * v10620 = slot_547(v10604);
    v10622 = v10620;
  }
  return v10622;
}

struct StateG * slot_854(struct StateG * v17898) {
  int * v17899 = v17898->regs;
  int v17900 = v17899[16];
  int v17901 = v17899[17];
  bool v17921 = v17900 >= v17901;
  struct StateG * v17916;
  if (v17921) {
    int * v17902 = v17898->pht;
    v17902[16] = 1;
    struct StateG * v17904 = slot_883(v17898);
    v17916 = v17904;
  } else {
    int * v17906 = v17898->pht;
    v17906[16] = 0;
    int v17908 = v17898->timer;
    int v17928 = v17908 + 15;
    v17898->timer = v17928;
    int * v17910 = v17898->saved_regs;
    int v17911 = v17910[19];
    int * v17912 = v17898->regs;
    v17912[19] = v17911;
    struct StateG * v17914 = slot_861(v17898);
    v17916 = v17914;
  }
  return v17916;
}

struct StateG * slot_612(struct StateG * v12564) {
  int v12565 = v12564->timer;
  int v12575 = v12565 + 1;
  v12564->timer = v12575;
  int * v12567 = v12564->pht;
  int v12568 = v12567[3];
  bool v12578 = !(v12568 == 0);
  struct StateG * v12573;
  if (v12578) {
    struct StateG * v12569 = slot_640(v12564);
    v12573 = v12569;
  } else {
    struct StateG * v12571 = slot_641(v12564);
    v12573 = v12571;
  }
  return v12573;
}

struct StateG * slot_572(struct StateG * v11960) {
  int v11961 = v11960->timer;
  int v11967 = v11961 + 1;
  v11960->timer = v11967;
  int * v11963 = v11960->regs;
  v11963[1] = 156;
  struct StateG * v11965 = slot_588(v11960);
  return v11965;
}

struct StateG * slot_435(struct StateG * v9059) {
  int v9060 = v9059->timer;
  int v9066 = v9060 + 1;
  v9059->timer = v9066;
  int * v9062 = v9059->regs;
  v9062[17] = 10;
  struct StateG * v9064 = slot_451(v9059);
  return v9064;
}

struct StateG * slot_136(struct StateG * v3012) {
  int v3013 = v3012->timer;
  int v3017 = v3013 + 1;
  v3012->timer = v3017;
  struct StateG * v3015 = slot_168(v3012);
  return v3015;
}

struct StateG * slot_379(struct StateG * v8060) {
  int * v8061 = v8060->regs;
  int v8062 = v8061[16];
  int v8063 = v8061[17];
  bool v8083 = v8062 < v8063;
  struct StateG * v8078;
  if (v8083) {
    int * v8064 = v8060->pht;
    v8064[86] = 1;
    int v8066 = v8060->timer;
    int v8087 = v8066 + 15;
    v8060->timer = v8087;
    int * v8068 = v8060->saved_regs;
    int v8069 = v8068[18];
    int * v8070 = v8060->regs;
    v8070[18] = v8069;
    struct StateG * v8072 = slot_398(v8060);
    v8078 = v8072;
  } else {
    int * v8074 = v8060->pht;
    v8074[86] = 0;
    struct StateG * v8076 = slot_399(v8060);
    v8078 = v8076;
  }
  return v8078;
}

struct StateG * slot_746(struct StateG * v15354) {
  int v15355 = v15354->timer;
  int v15361 = v15355 + 1;
  v15354->timer = v15361;
  int * v15357 = v15354->regs;
  v15357[1] = 164;
  struct StateG * v15359 = slot_762(v15354);
  return v15359;
}

struct StateG * slot_475(struct StateG * v9824) {
  int * v9825 = v9824->saved_regs;
  int * v9826 = v9824->regs;
  int v9827 = v9826[18];
  v9825[18] = v9827;
  int v9829 = v9824->timer;
  int v9839 = v9829 + 1;
  v9824->timer = v9839;
  int * v9831 = v9824->regs;
  v9831[18] = 1;
  struct StateG * v9833 = slot_507(v9824);
  return v9833;
}

struct StateG * slot_310(struct StateG * v6314) {
  int v6315 = v6314->timer;
  int v6321 = v6315 + 1;
  v6314->timer = v6321;
  int * v6317 = v6314->regs;
  v6317[17] = 10;
  struct StateG * v6319 = slot_326(v6314);
  return v6319;
}

struct StateG * slot_445(struct StateG * v9224) {
  int v9225 = v9224->timer;
  int v9235 = v9225 + 1;
  v9224->timer = v9235;
  int * v9227 = v9224->pht;
  int v9228 = v9227[106];
  bool v9238 = !(v9228 == 0);
  struct StateG * v9233;
  if (v9238) {
    struct StateG * v9229 = slot_466(v9224);
    v9233 = v9229;
  } else {
    struct StateG * v9231 = slot_467(v9224);
    v9233 = v9231;
  }
  return v9233;
}

struct StateG * slot_197(struct StateG * v3816) {
  int v3817 = v3816->timer;
  int v3827 = v3817 + 1;
  v3816->timer = v3827;
  int * v3819 = v3816->pht;
  int v3820 = v3819[66];
  bool v3830 = !(v3820 == 0);
  struct StateG * v3825;
  if (v3830) {
    struct StateG * v3821 = slot_226(v3816);
    v3825 = v3821;
  } else {
    struct StateG * v3823 = slot_227(v3816);
    v3825 = v3823;
  }
  return v3825;
}

struct StateG * slot_457(struct StateG * v9464) {
  int * v9465 = v9464->saved_regs;
  int * v9466 = v9464->regs;
  int v9467 = v9466[18];
  v9465[18] = v9467;
  int v9469 = v9464->timer;
  int v9479 = v9469 + 1;
  v9464->timer = v9479;
  int * v9471 = v9464->regs;
  v9471[18] = 1;
  struct StateG * v9473 = slot_489(v9464);
  return v9473;
}

struct StateG * slot_663(struct StateG * v13884) {
  int * v13885 = v13884->regs;
  int v13886 = v13885[16];
  int v13887 = v13885[17];
  bool v13907 = v13886 < v13887;
  struct StateG * v13902;
  if (v13907) {
    int * v13888 = v13884->pht;
    v13888[8] = 1;
    int v13890 = v13884->timer;
    int v13911 = v13890 + 15;
    v13884->timer = v13911;
    int * v13892 = v13884->saved_regs;
    int v13893 = v13892[18];
    int * v13894 = v13884->regs;
    v13894[18] = v13893;
    struct StateG * v13896 = slot_710(v13884);
    v13902 = v13896;
  } else {
    int * v13898 = v13884->pht;
    v13898[8] = 0;
    struct StateG * v13900 = slot_711(v13884);
    v13902 = v13900;
  }
  return v13902;
}

struct StateG * slot_68(struct StateG * v1460) {
  int * v1461 = v1460->regs;
  int v1462 = v1461[16];
  int v1463 = v1461[17];
  bool v1483 = v1462 < v1463;
  struct StateG * v1478;
  if (v1483) {
    int * v1464 = v1460->pht;
    v1464[33] = 1;
    struct StateG * v1466 = slot_80(v1460);
    v1478 = v1466;
  } else {
    int * v1468 = v1460->pht;
    v1468[33] = 0;
    int v1470 = v1460->timer;
    int v1492 = v1470 + 15;
    v1460->timer = v1492;
    int * v1472 = v1460->saved_regs;
    int v1473 = v1472[18];
    int * v1474 = v1460->regs;
    v1474[18] = v1473;
    struct StateG * v1476 = slot_81(v1460);
    v1478 = v1476;
  }
  return v1478;
}

struct StateG * slot_493(struct StateG * v10284) {
  int * v10285 = v10284->regs;
  int v10286 = v10285[16];
  int v10287 = v10285[17];
  bool v10307 = v10286 < v10287;
  struct StateG * v10302;
  if (v10307) {
    int * v10288 = v10284->pht;
    v10288[109] = 1;
    int v10290 = v10284->timer;
    int v10311 = v10290 + 15;
    v10284->timer = v10311;
    int * v10292 = v10284->saved_regs;
    int v10293 = v10292[18];
    int * v10294 = v10284->regs;
    v10294[18] = v10293;
    struct StateG * v10296 = slot_530(v10284);
    v10302 = v10296;
  } else {
    int * v10298 = v10284->pht;
    v10298[109] = 0;
    struct StateG * v10300 = slot_531(v10284);
    v10302 = v10300;
  }
  return v10302;
}

struct StateG * slot_105(struct StateG * v2072) {
  int * v2073 = v2072->saved_regs;
  int * v2074 = v2072->regs;
  int v2075 = v2074[18];
  v2073[18] = v2075;
  int v2077 = v2072->timer;
  int v2087 = v2077 + 1;
  v2072->timer = v2087;
  int * v2079 = v2072->regs;
  v2079[18] = 1;
  struct StateG * v2081 = slot_121(v2072);
  return v2081;
}

struct StateG * slot_15(struct StateG * v452) {
  int v453 = v452->timer;
  int v460 = v453 + 1;
  v452->timer = v460;
  int * v455 = v452->regs;
  int v456 = v455[1];
  bool v463 = v456 == 16;
  ret_assert(v463);
  struct StateG * v458 = slot_17(v452);
  return v458;
}

struct StateG * slot_699(struct StateG * v14762) {
  int v14763 = v14762->timer;
  int v14767 = v14763 + 1;
  v14762->timer = v14767;
  struct StateG * v14765 = slot_721(v14762);
  return v14765;
}

struct StateG * slot_480(struct StateG * v9924) {
  int * v9925 = v9924->saved_regs;
  int * v9926 = v9924->regs;
  int v9927 = v9926[18];
  v9925[18] = v9927;
  int v9929 = v9924->timer;
  int v9939 = v9929 + 1;
  v9924->timer = v9939;
  int * v9931 = v9924->regs;
  v9931[18] = 2;
  struct StateG * v9933 = slot_512(v9924);
  return v9933;
}

struct StateG * slot_769(struct StateG * v15653) {
  int v15654 = v15653->timer;
  int v15660 = v15654 + 1;
  v15653->timer = v15660;
  int * v15656 = v15653->regs;
  v15656[17] = 10;
  struct StateG * v15658 = slot_785(v15653);
  return v15658;
}

struct StateG * slot_244(struct StateG * v4996) {
  int * v4997 = v4996->regs;
  int v4998 = v4997[16];
  int v4999 = v4997[17];
  bool v5019 = v4998 < v4999;
  struct StateG * v5014;
  if (v5019) {
    int * v5000 = v4996->pht;
    v5000[73] = 1;
    struct StateG * v5002 = slot_288(v4996);
    v5014 = v5002;
  } else {
    int * v5004 = v4996->pht;
    v5004[73] = 0;
    int v5006 = v4996->timer;
    int v5028 = v5006 + 15;
    v4996->timer = v5028;
    int * v5008 = v4996->saved_regs;
    int v5009 = v5008[18];
    int * v5010 = v4996->regs;
    v5010[18] = v5009;
    struct StateG * v5012 = slot_289(v4996);
    v5014 = v5012;
  }
  return v5014;
}

struct StateG * slot_222(struct StateG * v4316) {
  int * v4317 = v4316->saved_regs;
  int * v4318 = v4316->regs;
  int v4319 = v4318[18];
  v4317[18] = v4319;
  int v4321 = v4316->timer;
  int v4331 = v4321 + 1;
  v4316->timer = v4331;
  int * v4323 = v4316->regs;
  v4323[18] = 2;
  struct StateG * v4325 = slot_254(v4316);
  return v4325;
}

struct StateG * slot_171(struct StateG * v3387) {
  int v3388 = v3387->timer;
  int v3394 = v3388 + 1;
  v3387->timer = v3394;
  int * v3390 = v3387->regs;
  v3390[17] = 10;
  struct StateG * v3392 = slot_187(v3387);
  return v3392;
}

struct StateG * slot_162(struct StateG * v3285) {
  int v3286 = v3285->timer;
  int v3292 = v3286 + 1;
  v3285->timer = v3292;
  int * v3288 = v3285->regs;
  v3288[18] = 2;
  struct StateG * v3290 = slot_160(v3285);
  return v3290;
}

struct StateG * slot_634(struct StateG * v13004) {
  int * v13005 = v13004->saved_regs;
  int * v13006 = v13004->regs;
  int v13007 = v13006[18];
  v13005[18] = v13007;
  int v13009 = v13004->timer;
  int v13019 = v13009 + 1;
  v13004->timer = v13019;
  int * v13011 = v13004->regs;
  v13011[18] = 2;
  struct StateG * v13013 = slot_666(v13004);
  return v13013;
}

struct StateG * slot_552(struct StateG * v11700) {
  int v11701 = v11700->timer;
  int v11707 = v11701 + 1;
  v11700->timer = v11707;
  int * v11703 = v11700->regs;
  v11703[1] = 148;
  struct StateG * v11705 = slot_568(v11700);
  return v11705;
}

struct StateG * slot_399(struct StateG * v8656) {
  int v8657 = v8656->timer;
  int v8661 = v8657 + 1;
  v8656->timer = v8661;
  struct StateG * v8659 = slot_427(v8656);
  return v8659;
}

struct StateG * slot_239(struct StateG * v4796) {
  int * v4797 = v4796->regs;
  int v4798 = v4797[16];
  int v4799 = v4797[17];
  bool v4819 = v4798 < v4799;
  struct StateG * v4814;
  if (v4819) {
    int * v4800 = v4796->pht;
    v4800[76] = 1;
    int v4802 = v4796->timer;
    int v4823 = v4802 + 15;
    v4796->timer = v4823;
    int * v4804 = v4796->saved_regs;
    int v4805 = v4804[18];
    int * v4806 = v4796->regs;
    v4806[18] = v4805;
    struct StateG * v4808 = slot_278(v4796);
    v4814 = v4808;
  } else {
    int * v4810 = v4796->pht;
    v4810[76] = 0;
    struct StateG * v4812 = slot_279(v4796);
    v4814 = v4812;
  }
  return v4814;
}

struct StateG * slot_500(struct StateG * v10564) {
  int * v10565 = v10564->regs;
  int v10566 = v10565[16];
  int v10567 = v10565[17];
  bool v10587 = v10566 < v10567;
  struct StateG * v10582;
  if (v10587) {
    int * v10568 = v10564->pht;
    v10568[105] = 1;
    struct StateG * v10570 = slot_544(v10564);
    v10582 = v10570;
  } else {
    int * v10572 = v10564->pht;
    v10572[105] = 0;
    int v10574 = v10564->timer;
    int v10596 = v10574 + 15;
    v10564->timer = v10596;
    int * v10576 = v10564->saved_regs;
    int v10577 = v10576[18];
    int * v10578 = v10564->regs;
    v10578[18] = v10577;
    struct StateG * v10580 = slot_545(v10564);
    v10582 = v10580;
  }
  return v10582;
}

struct StateG * slot_267(struct StateG * v5830) {
  int v5831 = v5830->timer;
  int v5835 = v5831 + 1;
  v5830->timer = v5835;
  struct StateG * v5833 = slot_297(v5830);
  return v5833;
}

struct StateG * slot_570(struct StateG * v11934) {
  int v11935 = v11934->timer;
  int v11941 = v11935 + 1;
  v11934->timer = v11941;
  int * v11937 = v11934->regs;
  v11937[1] = 156;
  struct StateG * v11939 = slot_586(v11934);
  return v11939;
}

struct StateG * slot_511(struct StateG * v11004) {
  int * v11005 = v11004->regs;
  int v11006 = v11005[16];
  int v11007 = v11005[17];
  bool v11027 = v11006 < v11007;
  struct StateG * v11022;
  if (v11027) {
    int * v11008 = v11004->pht;
    v11008[100] = 1;
    int v11010 = v11004->timer;
    int v11031 = v11010 + 15;
    v11004->timer = v11031;
    int * v11012 = v11004->saved_regs;
    int v11013 = v11012[18];
    int * v11014 = v11004->regs;
    v11014[18] = v11013;
    struct StateG * v11016 = slot_534(v11004);
    v11022 = v11016;
  } else {
    int * v11018 = v11004->pht;
    v11018[100] = 0;
    struct StateG * v11020 = slot_535(v11004);
    v11022 = v11020;
  }
  return v11022;
}

struct StateG * slot_848(struct StateG * v17664) {
  int * v17665 = v17664->regs;
  int v17666 = v17665[16];
  int v17667 = v17665[17];
  bool v17687 = v17666 >= v17667;
  struct StateG * v17682;
  if (v17687) {
    int * v17668 = v17664->pht;
    v17668[19] = 1;
    struct StateG * v17670 = slot_883(v17664);
    v17682 = v17670;
  } else {
    int * v17672 = v17664->pht;
    v17672[19] = 0;
    int v17674 = v17664->timer;
    int v17696 = v17674 + 15;
    v17664->timer = v17696;
    int * v17676 = v17664->saved_regs;
    int v17677 = v17676[19];
    int * v17678 = v17664->regs;
    v17678[19] = v17677;
    struct StateG * v17680 = slot_861(v17664);
    v17682 = v17680;
  }
  return v17682;
}

struct StateG * slot_316(struct StateG * v6420) {
  int v6421 = v6420->timer;
  int v6431 = v6421 + 1;
  v6420->timer = v6431;
  int * v6423 = v6420->pht;
  int v6424 = v6423[91];
  bool v6434 = !(v6424 == 0);
  struct StateG * v6429;
  if (v6434) {
    struct StateG * v6425 = slot_336(v6420);
    v6429 = v6425;
  } else {
    struct StateG * v6427 = slot_337(v6420);
    v6429 = v6427;
  }
  return v6429;
}

struct StateG * slot_424(struct StateG * v8916) {
  int v8917 = v8916->timer;
  int v8923 = v8917 + 1;
  v8916->timer = v8923;
  int * v8919 = v8916->regs;
  v8919[17] = 10;
  struct StateG * v8921 = slot_440(v8916);
  return v8921;
}

struct StateG * slot_332(struct StateG * v6740) {
  int * v6741 = v6740->saved_regs;
  int * v6742 = v6740->regs;
  int v6743 = v6742[18];
  v6741[18] = v6743;
  int v6745 = v6740->timer;
  int v6755 = v6745 + 1;
  v6740->timer = v6755;
  int * v6747 = v6740->regs;
  v6747[18] = 2;
  struct StateG * v6749 = slot_364(v6740);
  return v6749;
}

struct StateG * slot_39(struct StateG * v892) {
  int v893 = v892->timer;
  int v897 = v893 + 1;
  v892->timer = v897;
  struct StateG * v895 = slot_43(v892);
  return v895;
}

struct StateG * slot_508(struct StateG * v10884) {
  int * v10885 = v10884->regs;
  int v10886 = v10885[16];
  int v10887 = v10885[17];
  bool v10907 = v10886 < v10887;
  struct StateG * v10902;
  if (v10907) {
    int * v10888 = v10884->pht;
    v10888[101] = 1;
    struct StateG * v10890 = slot_528(v10884);
    v10902 = v10890;
  } else {
    int * v10892 = v10884->pht;
    v10892[101] = 0;
    int v10894 = v10884->timer;
    int v10916 = v10894 + 15;
    v10884->timer = v10916;
    int * v10896 = v10884->saved_regs;
    int v10897 = v10896[18];
    int * v10898 = v10884->regs;
    v10898[18] = v10897;
    struct StateG * v10900 = slot_529(v10884);
    v10902 = v10900;
  }
  return v10902;
}

struct StateG * slot_736(struct StateG * v15224) {
  int v15225 = v15224->timer;
  int v15231 = v15225 + 1;
  v15224->timer = v15231;
  int * v15227 = v15224->regs;
  v15227[1] = 156;
  struct StateG * v15229 = slot_752(v15224);
  return v15229;
}

struct StateG * slot_60(struct StateG * v1220) {
  int * v1221 = v1220->saved_regs;
  int * v1222 = v1220->regs;
  int v1223 = v1222[18];
  v1221[18] = v1223;
  int v1225 = v1220->timer;
  int v1235 = v1225 + 1;
  v1220->timer = v1235;
  int * v1227 = v1220->regs;
  v1227[18] = 2;
  struct StateG * v1229 = slot_68(v1220);
  return v1229;
}

struct StateG * slot_765(struct StateG * v15601) {
  int v15602 = v15601->timer;
  int v15608 = v15602 + 1;
  v15601->timer = v15608;
  int * v15604 = v15601->regs;
  v15604[17] = 10;
  struct StateG * v15606 = slot_781(v15601);
  return v15606;
}

struct StateG * slot_112(struct StateG * v2212) {
  int * v2213 = v2212->saved_regs;
  int * v2214 = v2212->regs;
  int v2215 = v2214[18];
  v2213[18] = v2215;
  int v2217 = v2212->timer;
  int v2227 = v2217 + 1;
  v2212->timer = v2227;
  int * v2219 = v2212->regs;
  v2219[18] = 2;
  struct StateG * v2221 = slot_128(v2212);
  return v2221;
}

struct StateG * slot_256(struct StateG * v5476) {
  int * v5477 = v5476->regs;
  int v5478 = v5477[16];
  int v5479 = v5477[17];
  bool v5499 = v5478 < v5479;
  struct StateG * v5494;
  if (v5499) {
    int * v5480 = v5476->pht;
    v5480[67] = 1;
    struct StateG * v5482 = slot_280(v5476);
    v5494 = v5482;
  } else {
    int * v5484 = v5476->pht;
    v5484[67] = 0;
    int v5486 = v5476->timer;
    int v5508 = v5486 + 15;
    v5476->timer = v5508;
    int * v5488 = v5476->saved_regs;
    int v5489 = v5488[18];
    int * v5490 = v5476->regs;
    v5490[18] = v5489;
    struct StateG * v5492 = slot_281(v5476);
    v5494 = v5492;
  }
  return v5494;
}

struct StateG * slot_798(struct StateG * v16184) {
  int * v16185 = v16184->saved_regs;
  int * v16186 = v16184->regs;
  int v16187 = v16186[19];
  v16185[19] = v16187;
  int v16189 = v16184->timer;
  int v16199 = v16189 + 1;
  v16184->timer = v16199;
  int * v16191 = v16184->regs;
  v16191[19] = 2;
  struct StateG * v16193 = slot_830(v16184);
  return v16193;
}

struct StateG * slot_801(struct StateG * v16244) {
  int * v16245 = v16244->saved_regs;
  int * v16246 = v16244->regs;
  int v16247 = v16246[19];
  v16245[19] = v16247;
  int v16249 = v16244->timer;
  int v16259 = v16249 + 1;
  v16244->timer = v16259;
  int * v16251 = v16244->regs;
  v16251[19] = 1;
  struct StateG * v16253 = slot_833(v16244);
  return v16253;
}

struct StateG * slot_567(struct StateG * v11895) {
  int v11896 = v11895->timer;
  int v11902 = v11896 + 1;
  v11895->timer = v11902;
  int * v11898 = v11895->regs;
  v11898[1] = 148;
  struct StateG * v11900 = slot_583(v11895);
  return v11900;
}

struct StateG * slot_16(struct StateG * v466) {
  int v467 = v466->timer;
  int v473 = v467 + 1;
  v466->timer = v473;
  int * v469 = v466->regs;
  v469[1] = 16;
  struct StateG * v471 = slot_18(v466);
  return v471;
}

struct StateG * slot_113(struct StateG * v2232) {
  int * v2233 = v2232->saved_regs;
  int * v2234 = v2232->regs;
  int v2235 = v2234[18];
  v2233[18] = v2235;
  int v2237 = v2232->timer;
  int v2247 = v2237 + 1;
  v2232->timer = v2247;
  int * v2239 = v2232->regs;
  v2239[18] = 1;
  struct StateG * v2241 = slot_129(v2232);
  return v2241;
}

struct StateG * slot_302(struct StateG * v6210) {
  int v6211 = v6210->timer;
  int v6217 = v6211 + 1;
  v6210->timer = v6217;
  int * v6213 = v6210->regs;
  v6213[17] = 10;
  struct StateG * v6215 = slot_318(v6210);
  return v6215;
}

struct StateG * slot_191(struct StateG * v3696) {
  int v3697 = v3696->timer;
  int v3707 = v3697 + 1;
  v3696->timer = v3707;
  int * v3699 = v3696->pht;
  int v3700 = v3699[72];
  bool v3710 = !(v3700 == 0);
  struct StateG * v3705;
  if (v3710) {
    struct StateG * v3701 = slot_214(v3696);
    v3705 = v3701;
  } else {
    struct StateG * v3703 = slot_215(v3696);
    v3705 = v3703;
  }
  return v3705;
}

struct StateG * slot_487(struct StateG * v10064) {
  int * v10065 = v10064->saved_regs;
  int * v10066 = v10064->regs;
  int v10067 = v10066[18];
  v10065[18] = v10067;
  int v10069 = v10064->timer;
  int v10079 = v10069 + 1;
  v10064->timer = v10079;
  int * v10071 = v10064->regs;
  v10071[18] = 1;
  struct StateG * v10073 = slot_519(v10064);
  return v10073;
}

struct StateG * slot_645(struct StateG * v13224) {
  int * v13225 = v13224->saved_regs;
  int * v13226 = v13224->regs;
  int v13227 = v13226[18];
  v13225[18] = v13227;
  int v13229 = v13224->timer;
  int v13239 = v13229 + 1;
  v13224->timer = v13239;
  int * v13231 = v13224->regs;
  v13231[18] = 1;
  struct StateG * v13233 = slot_677(v13224);
  return v13233;
}

struct StateG * slot_633(struct StateG * v12984) {
  int * v12985 = v12984->saved_regs;
  int * v12986 = v12984->regs;
  int v12987 = v12986[18];
  v12985[18] = v12987;
  int v12989 = v12984->timer;
  int v12999 = v12989 + 1;
  v12984->timer = v12999;
  int * v12991 = v12984->regs;
  v12991[18] = 1;
  struct StateG * v12993 = slot_665(v12984);
  return v12993;
}

struct StateG * slot_95(struct StateG * v1879) {
  int v1880 = v1879->timer;
  int v1886 = v1880 + 1;
  v1879->timer = v1886;
  int * v1882 = v1879->regs;
  v1882[17] = 10;
  struct StateG * v1884 = slot_103(v1879);
  return v1884;
}

struct StateG * slot_354(struct StateG * v7180) {
  int * v7181 = v7180->saved_regs;
  int * v7182 = v7180->regs;
  int v7183 = v7182[18];
  v7181[18] = v7183;
  int v7185 = v7180->timer;
  int v7195 = v7185 + 1;
  v7180->timer = v7195;
  int * v7187 = v7180->regs;
  v7187[18] = 2;
  struct StateG * v7189 = slot_386(v7180);
  return v7189;
}

struct StateG * slot_115(struct StateG * v2272) {
  int * v2273 = v2272->saved_regs;
  int * v2274 = v2272->regs;
  int v2275 = v2274[18];
  v2273[18] = v2275;
  int v2277 = v2272->timer;
  int v2287 = v2277 + 1;
  v2272->timer = v2287;
  int * v2279 = v2272->regs;
  v2279[18] = 1;
  struct StateG * v2281 = slot_131(v2272);
  return v2281;
}

struct StateG * slot_78(struct StateG * v1683) {
  int v1684 = v1683->timer;
  int v1690 = v1684 + 1;
  v1683->timer = v1690;
  int * v1686 = v1683->regs;
  v1686[18] = 2;
  struct StateG * v1688 = slot_76(v1683);
  return v1688;
}

struct StateG * slot_674(struct StateG * v14324) {
  int * v14325 = v14324->regs;
  int v14326 = v14325[16];
  int v14327 = v14325[17];
  bool v14347 = v14326 < v14327;
  struct StateG * v14342;
  if (v14347) {
    int * v14328 = v14324->pht;
    v14328[2] = 1;
    struct StateG * v14330 = slot_700(v14324);
    v14342 = v14330;
  } else {
    int * v14332 = v14324->pht;
    v14332[2] = 0;
    int v14334 = v14324->timer;
    int v14356 = v14334 + 15;
    v14324->timer = v14356;
    int * v14336 = v14324->saved_regs;
    int v14337 = v14336[18];
    int * v14338 = v14324->regs;
    v14338[18] = v14337;
    struct StateG * v14340 = slot_701(v14324);
    v14342 = v14340;
  }
  return v14342;
}

struct StateG * slot_554(struct StateG * v11726) {
  int v11727 = v11726->timer;
  int v11733 = v11727 + 1;
  v11726->timer = v11733;
  int * v11729 = v11726->regs;
  v11729[1] = 148;
  struct StateG * v11731 = slot_570(v11726);
  return v11731;
}

struct StateG * slot_650(struct StateG * v13364) {
  int * v13365 = v13364->regs;
  int v13366 = v13365[16];
  int v13367 = v13365[17];
  bool v13387 = v13366 < v13367;
  struct StateG * v13382;
  if (v13387) {
    int * v13368 = v13364->pht;
    v13368[14] = 1;
    struct StateG * v13370 = slot_684(v13364);
    v13382 = v13370;
  } else {
    int * v13372 = v13364->pht;
    v13372[14] = 0;
    int v13374 = v13364->timer;
    int v13396 = v13374 + 15;
    v13364->timer = v13396;
    int * v13376 = v13364->saved_regs;
    int v13377 = v13376[18];
    int * v13378 = v13364->regs;
    v13378[18] = v13377;
    struct StateG * v13380 = slot_685(v13364);
    v13382 = v13380;
  }
  return v13382;
}

struct StateG * slot_752(struct StateG * v15432) {
  int v15433 = v15432->timer;
  int v15439 = v15433 + 1;
  v15432->timer = v15439;
  int * v15435 = v15432->regs;
  v15435[1] = 164;
  struct StateG * v15437 = slot_768(v15432);
  return v15437;
}

struct StateG * slot_331(struct StateG * v6720) {
  int * v6721 = v6720->saved_regs;
  int * v6722 = v6720->regs;
  int v6723 = v6722[18];
  v6721[18] = v6723;
  int v6725 = v6720->timer;
  int v6735 = v6725 + 1;
  v6720->timer = v6735;
  int * v6727 = v6720->regs;
  v6727[18] = 1;
  struct StateG * v6729 = slot_363(v6720);
  return v6729;
}

struct StateG * slot_676(struct StateG * v14404) {
  int * v14405 = v14404->regs;
  int v14406 = v14405[16];
  int v14407 = v14405[17];
  bool v14427 = v14406 < v14407;
  struct StateG * v14422;
  if (v14427) {
    int * v14408 = v14404->pht;
    v14408[1] = 1;
    struct StateG * v14410 = slot_704(v14404);
    v14422 = v14410;
  } else {
    int * v14412 = v14404->pht;
    v14412[1] = 0;
    int v14414 = v14404->timer;
    int v14435 = v14414 + 15;
    v14404->timer = v14435;
    int * v14416 = v14404->saved_regs;
    int v14417 = v14416[18];
    int * v14418 = v14404->regs;
    v14418[18] = v14417;
    struct StateG * v14420 = slot_705(v14404);
    v14422 = v14420;
  }
  return v14422;
}

struct StateG * slot_412(struct StateG * v8790) {
  int v8791 = v8790->timer;
  int v8795 = v8791 + 1;
  v8790->timer = v8795;
  struct StateG * v8793 = slot_434(v8790);
  return v8793;
}

struct StateG * slot_381(struct StateG * v8140) {
  int * v8141 = v8140->regs;
  int v8142 = v8141[16];
  int v8143 = v8141[17];
  bool v8163 = v8142 < v8143;
  struct StateG * v8158;
  if (v8163) {
    int * v8144 = v8140->pht;
    v8144[85] = 1;
    int v8146 = v8140->timer;
    int v8167 = v8146 + 15;
    v8140->timer = v8167;
    int * v8148 = v8140->saved_regs;
    int v8149 = v8148[18];
    int * v8150 = v8140->regs;
    v8150[18] = v8149;
    struct StateG * v8152 = slot_402(v8140);
    v8158 = v8152;
  } else {
    int * v8154 = v8140->pht;
    v8154[85] = 0;
    struct StateG * v8156 = slot_403(v8140);
    v8158 = v8156;
  }
  return v8158;
}

struct StateG * slot_646(struct StateG * v13244) {
  int * v13245 = v13244->saved_regs;
  int * v13246 = v13244->regs;
  int v13247 = v13246[18];
  v13245[18] = v13247;
  int v13249 = v13244->timer;
  int v13259 = v13249 + 1;
  v13244->timer = v13259;
  int * v13251 = v13244->regs;
  v13251[18] = 2;
  struct StateG * v13253 = slot_678(v13244);
  return v13253;
}

struct StateG * slot_627(struct StateG * v12864) {
  int * v12865 = v12864->saved_regs;
  int * v12866 = v12864->regs;
  int v12867 = v12866[18];
  v12865[18] = v12867;
  int v12869 = v12864->timer;
  int v12879 = v12869 + 1;
  v12864->timer = v12879;
  int * v12871 = v12864->regs;
  v12871[18] = 1;
  struct StateG * v12873 = slot_659(v12864);
  return v12873;
}

struct StateG * slot_675(struct StateG * v14364) {
  int * v14365 = v14364->regs;
  int v14366 = v14365[16];
  int v14367 = v14365[17];
  bool v14387 = v14366 < v14367;
  struct StateG * v14382;
  if (v14387) {
    int * v14368 = v14364->pht;
    v14368[2] = 1;
    int v14370 = v14364->timer;
    int v14391 = v14370 + 15;
    v14364->timer = v14391;
    int * v14372 = v14364->saved_regs;
    int v14373 = v14372[18];
    int * v14374 = v14364->regs;
    v14374[18] = v14373;
    struct StateG * v14376 = slot_702(v14364);
    v14382 = v14376;
  } else {
    int * v14378 = v14364->pht;
    v14378[2] = 0;
    struct StateG * v14380 = slot_703(v14364);
    v14382 = v14380;
  }
  return v14382;
}

struct StateG * slot_845(struct StateG * v17544) {
  int * v17545 = v17544->regs;
  int v17546 = v17545[16];
  int v17547 = v17545[17];
  bool v17567 = v17546 >= v17547;
  struct StateG * v17562;
  if (v17567) {
    int * v17548 = v17544->pht;
    v17548[21] = 1;
    int v17550 = v17544->timer;
    int v17571 = v17550 + 15;
    v17544->timer = v17571;
    int * v17552 = v17544->saved_regs;
    int v17553 = v17552[19];
    int * v17554 = v17544->regs;
    v17554[19] = v17553;
    struct StateG * v17556 = slot_858(v17544);
    v17562 = v17556;
  } else {
    int * v17558 = v17544->pht;
    v17558[21] = 0;
    struct StateG * v17560 = slot_883(v17544);
    v17562 = v17560;
  }
  return v17562;
}

struct StateG * slot_837(struct StateG * v17224) {
  int * v17225 = v17224->regs;
  int v17226 = v17225[16];
  int v17227 = v17225[17];
  bool v17247 = v17226 >= v17227;
  struct StateG * v17242;
  if (v17247) {
    int * v17228 = v17224->pht;
    v17228[25] = 1;
    int v17230 = v17224->timer;
    int v17251 = v17230 + 15;
    v17224->timer = v17251;
    int * v17232 = v17224->saved_regs;
    int v17233 = v17232[19];
    int * v17234 = v17224->regs;
    v17234[19] = v17233;
    struct StateG * v17236 = slot_858(v17224);
    v17242 = v17236;
  } else {
    int * v17238 = v17224->pht;
    v17238[25] = 0;
    struct StateG * v17240 = slot_883(v17224);
    v17242 = v17240;
  }
  return v17242;
}

struct StateG * slot_210(struct StateG * v4076) {
  int * v4077 = v4076->saved_regs;
  int * v4078 = v4076->regs;
  int v4079 = v4078[18];
  v4077[18] = v4079;
  int v4081 = v4076->timer;
  int v4091 = v4081 + 1;
  v4076->timer = v4091;
  int * v4083 = v4076->regs;
  v4083[18] = 2;
  struct StateG * v4085 = slot_242(v4076);
  return v4085;
}

struct StateG * slot_472(struct StateG * v9764) {
  int * v9765 = v9764->saved_regs;
  int * v9766 = v9764->regs;
  int v9767 = v9766[18];
  v9765[18] = v9767;
  int v9769 = v9764->timer;
  int v9779 = v9769 + 1;
  v9764->timer = v9779;
  int * v9771 = v9764->regs;
  v9771[18] = 2;
  struct StateG * v9773 = slot_504(v9764);
  return v9773;
}

struct StateG * slot_657(struct StateG * v13644) {
  int * v13645 = v13644->regs;
  int v13646 = v13645[16];
  int v13647 = v13645[17];
  bool v13667 = v13646 < v13647;
  struct StateG * v13662;
  if (v13667) {
    int * v13648 = v13644->pht;
    v13648[11] = 1;
    int v13650 = v13644->timer;
    int v13671 = v13650 + 15;
    v13644->timer = v13671;
    int * v13652 = v13644->saved_regs;
    int v13653 = v13652[18];
    int * v13654 = v13644->regs;
    v13654[18] = v13653;
    struct StateG * v13656 = slot_698(v13644);
    v13662 = v13656;
  } else {
    int * v13658 = v13644->pht;
    v13658[11] = 0;
    struct StateG * v13660 = slot_699(v13644);
    v13662 = v13660;
  }
  return v13662;
}

struct StateG * slot_739(struct StateG * v15263) {
  int v15264 = v15263->timer;
  int v15270 = v15264 + 1;
  v15263->timer = v15270;
  int * v15266 = v15263->regs;
  v15266[1] = 156;
  struct StateG * v15268 = slot_755(v15263);
  return v15268;
}

struct StateG * slot_52(struct StateG * v1060) {
  int v1061 = v1060->timer;
  int v1071 = v1061 + 1;
  v1060->timer = v1071;
  int * v1063 = v1060->pht;
  int v1064 = v1063[35];
  bool v1074 = !(v1064 == 0);
  struct StateG * v1069;
  if (v1074) {
    struct StateG * v1065 = slot_56(v1060);
    v1069 = v1065;
  } else {
    struct StateG * v1067 = slot_57(v1060);
    v1069 = v1067;
  }
  return v1069;
}

struct StateG * slot_83(struct StateG * v1738) {
  int v1739 = v1738->timer;
  int v1743 = v1739 + 1;
  v1738->timer = v1743;
  struct StateG * v1741 = slot_93(v1738);
  return v1741;
}

struct StateG * slot_209(struct StateG * v4056) {
  int * v4057 = v4056->saved_regs;
  int * v4058 = v4056->regs;
  int v4059 = v4058[18];
  v4057[18] = v4059;
  int v4061 = v4056->timer;
  int v4071 = v4061 + 1;
  v4056->timer = v4071;
  int * v4063 = v4056->regs;
  v4063[18] = 1;
  struct StateG * v4065 = slot_241(v4056);
  return v4065;
}

struct StateG * slot_420(struct StateG * v8874) {
  int v8875 = v8874->timer;
  int v8879 = v8875 + 1;
  v8874->timer = v8879;
  struct StateG * v8877 = slot_438(v8874);
  return v8877;
}

struct StateG * slot_853(struct StateG * v17860) {
  int * v17861 = v17860->regs;
  int v17862 = v17861[16];
  int v17863 = v17861[17];
  bool v17883 = v17862 >= v17863;
  struct StateG * v17878;
  if (v17883) {
    int * v17864 = v17860->pht;
    v17864[17] = 1;
    int v17866 = v17860->timer;
    int v17886 = v17866 + 15;
    v17860->timer = v17886;
    int * v17868 = v17860->saved_regs;
    int v17869 = v17868[19];
    int * v17870 = v17860->regs;
    v17870[19] = v17869;
    struct StateG * v17872 = slot_858(v17860);
    v17878 = v17872;
  } else {
    int * v17874 = v17860->pht;
    v17874[17] = 0;
    struct StateG * v17876 = slot_883(v17860);
    v17878 = v17876;
  }
  return v17878;
}

struct StateG * slot_73(struct StateG * v1628) {
  int v1629 = v1628->timer;
  int v1635 = v1629 + 1;
  v1628->timer = v1635;
  int * v1631 = v1628->regs;
  v1631[18] = 1;
  struct StateG * v1633 = slot_75(v1628);
  return v1633;
}

struct StateG * slot_270(struct StateG * v5859) {
  int v5860 = v5859->timer;
  int v5866 = v5860 + 1;
  v5859->timer = v5866;
  int * v5862 = v5859->regs;
  v5862[18] = 2;
  struct StateG * v5864 = slot_268(v5859);
  return v5864;
}

struct StateG * slot_198(struct StateG * v3836) {
  int v3837 = v3836->timer;
  int v3847 = v3837 + 1;
  v3836->timer = v3847;
  int * v3839 = v3836->pht;
  int v3840 = v3839[65];
  bool v3850 = !(v3840 == 0);
  struct StateG * v3845;
  if (v3850) {
    struct StateG * v3841 = slot_228(v3836);
    v3845 = v3841;
  } else {
    struct StateG * v3843 = slot_229(v3836);
    v3845 = v3843;
  }
  return v3845;
}

struct StateG * slot_187(struct StateG * v3616) {
  int v3617 = v3616->timer;
  int v3627 = v3617 + 1;
  v3616->timer = v3627;
  int * v3619 = v3616->pht;
  int v3620 = v3619[76];
  bool v3630 = !(v3620 == 0);
  struct StateG * v3625;
  if (v3630) {
    struct StateG * v3621 = slot_206(v3616);
    v3625 = v3621;
  } else {
    struct StateG * v3623 = slot_207(v3616);
    v3625 = v3623;
  }
  return v3625;
}

struct StateG * slot_182(struct StateG * v3530) {
  int v3531 = v3530->timer;
  int v3537 = v3531 + 1;
  v3530->timer = v3537;
  int * v3533 = v3530->regs;
  v3533[17] = 10;
  struct StateG * v3535 = slot_198(v3530);
  return v3535;
}

struct StateG * slot_361(struct StateG * v7340) {
  int * v7341 = v7340->regs;
  int v7342 = v7341[16];
  int v7343 = v7341[17];
  bool v7363 = v7342 < v7343;
  struct StateG * v7358;
  if (v7363) {
    int * v7344 = v7340->pht;
    v7344[95] = 1;
    int v7346 = v7340->timer;
    int v7367 = v7346 + 15;
    v7340->timer = v7367;
    int * v7348 = v7340->saved_regs;
    int v7349 = v7348[18];
    int * v7350 = v7340->regs;
    v7350[18] = v7349;
    struct StateG * v7352 = slot_394(v7340);
    v7358 = v7352;
  } else {
    int * v7354 = v7340->pht;
    v7354[95] = 0;
    struct StateG * v7356 = slot_395(v7340);
    v7358 = v7356;
  }
  return v7358;
}

struct StateG * slot_178(struct StateG * v3478) {
  int v3479 = v3478->timer;
  int v3485 = v3479 + 1;
  v3478->timer = v3485;
  int * v3481 = v3478->regs;
  v3481[17] = 10;
  struct StateG * v3483 = slot_194(v3478);
  return v3483;
}

struct StateG * slot_98(struct StateG * v1932) {
  int v1933 = v1932->timer;
  int v1943 = v1933 + 1;
  v1932->timer = v1943;
  int * v1935 = v1932->pht;
  int v1936 = v1935[53];
  bool v1946 = !(v1936 == 0);
  struct StateG * v1941;
  if (v1946) {
    struct StateG * v1937 = slot_108(v1932);
    v1941 = v1937;
  } else {
    struct StateG * v1939 = slot_109(v1932);
    v1941 = v1939;
  }
  return v1941;
}

struct StateG * slot_510(struct StateG * v10964) {
  int * v10965 = v10964->regs;
  int v10966 = v10965[16];
  int v10967 = v10965[17];
  bool v10987 = v10966 < v10967;
  struct StateG * v10982;
  if (v10987) {
    int * v10968 = v10964->pht;
    v10968[100] = 1;
    struct StateG * v10970 = slot_532(v10964);
    v10982 = v10970;
  } else {
    int * v10972 = v10964->pht;
    v10972[100] = 0;
    int v10974 = v10964->timer;
    int v10996 = v10974 + 15;
    v10964->timer = v10996;
    int * v10976 = v10964->saved_regs;
    int v10977 = v10976[18];
    int * v10978 = v10964->regs;
    v10978[18] = v10977;
    struct StateG * v10980 = slot_533(v10964);
    v10982 = v10980;
  }
  return v10982;
}

struct StateG * slot_404(struct StateG * v8706) {
  int v8707 = v8706->timer;
  int v8711 = v8707 + 1;
  v8706->timer = v8711;
  struct StateG * v8709 = slot_430(v8706);
  return v8709;
}

struct StateG * slot_46(struct StateG * v982) {
  int v983 = v982->timer;
  int v989 = v983 + 1;
  v982->timer = v989;
  int * v985 = v982->regs;
  v985[16] = 20;
  struct StateG * v987 = slot_50(v982);
  return v987;
}

struct StateG * slot_212(struct StateG * v4116) {
  int * v4117 = v4116->saved_regs;
  int * v4118 = v4116->regs;
  int v4119 = v4118[18];
  v4117[18] = v4119;
  int v4121 = v4116->timer;
  int v4131 = v4121 + 1;
  v4116->timer = v4131;
  int * v4123 = v4116->regs;
  v4123[18] = 2;
  struct StateG * v4125 = slot_244(v4116);
  return v4125;
}

struct StateG * slot_682(struct StateG * v14581) {
  int v14582 = v14581->timer;
  int v14588 = v14582 + 1;
  v14581->timer = v14588;
  int * v14584 = v14581->regs;
  v14584[18] = 2;
  struct StateG * v14586 = slot_680(v14581);
  return v14586;
}

struct StateG * slot_20(struct StateG * v518) {
  int v519 = v518->timer;
  int v525 = v519 + 1;
  v518->timer = v525;
  int * v521 = v518->regs;
  v521[17] = 10;
  struct StateG * v523 = slot_22(v518);
  return v523;
}

struct StateG * slot_61(struct StateG * v1240) {
  int * v1241 = v1240->saved_regs;
  int * v1242 = v1240->regs;
  int v1243 = v1242[18];
  v1241[18] = v1243;
  int v1245 = v1240->timer;
  int v1255 = v1245 + 1;
  v1240->timer = v1255;
  int * v1247 = v1240->regs;
  v1247[18] = 1;
  struct StateG * v1249 = slot_69(v1240);
  return v1249;
}

struct StateG * slot_499(struct StateG * v10524) {
  int * v10525 = v10524->regs;
  int v10526 = v10525[16];
  int v10527 = v10525[17];
  bool v10547 = v10526 < v10527;
  struct StateG * v10542;
  if (v10547) {
    int * v10528 = v10524->pht;
    v10528[106] = 1;
    int v10530 = v10524->timer;
    int v10551 = v10530 + 15;
    v10524->timer = v10551;
    int * v10532 = v10524->saved_regs;
    int v10533 = v10532[18];
    int * v10534 = v10524->regs;
    v10534[18] = v10533;
    struct StateG * v10536 = slot_542(v10524);
    v10542 = v10536;
  } else {
    int * v10538 = v10524->pht;
    v10538[106] = 0;
    struct StateG * v10540 = slot_543(v10524);
    v10542 = v10540;
  }
  return v10542;
}

struct StateG * slot_359(struct StateG * v7280) {
  int * v7281 = v7280->saved_regs;
  int * v7282 = v7280->regs;
  int v7283 = v7282[18];
  v7281[18] = v7283;
  int v7285 = v7280->timer;
  int v7295 = v7285 + 1;
  v7280->timer = v7295;
  int * v7287 = v7280->regs;
  v7287[18] = 1;
  struct StateG * v7289 = slot_391(v7280);
  return v7289;
}

struct StateG * slot_514(struct StateG * v11124) {
  int * v11125 = v11124->regs;
  int v11126 = v11125[16];
  int v11127 = v11125[17];
  bool v11147 = v11126 < v11127;
  struct StateG * v11142;
  if (v11147) {
    int * v11128 = v11124->pht;
    v11128[98] = 1;
    struct StateG * v11130 = slot_540(v11124);
    v11142 = v11130;
  } else {
    int * v11132 = v11124->pht;
    v11132[98] = 0;
    int v11134 = v11124->timer;
    int v11156 = v11134 + 15;
    v11124->timer = v11156;
    int * v11136 = v11124->saved_regs;
    int v11137 = v11136[18];
    int * v11138 = v11124->regs;
    v11138[18] = v11137;
    struct StateG * v11140 = slot_541(v11124);
    v11142 = v11140;
  }
  return v11142;
}

struct StateG * slot_30(struct StateG * v740) {
  int * v741 = v740->regs;
  int v742 = v741[16];
  int v743 = v741[17];
  bool v763 = v742 >= v743;
  struct StateG * v758;
  if (v763) {
    int * v744 = v740->pht;
    v744[16] = 1;
    struct StateG * v746 = slot_36(v740);
    v758 = v746;
  } else {
    int * v748 = v740->pht;
    v748[16] = 0;
    int v750 = v740->timer;
    int v770 = v750 + 15;
    v740->timer = v770;
    int * v752 = v740->saved_regs;
    int v753 = v752[19];
    int * v754 = v740->regs;
    v754[19] = v753;
    struct StateG * v756 = slot_37(v740);
    v758 = v756;
  }
  return v758;
}

struct StateG * slot_606(struct StateG * v12444) {
  int v12445 = v12444->timer;
  int v12455 = v12445 + 1;
  v12444->timer = v12455;
  int * v12447 = v12444->pht;
  int v12448 = v12447[9];
  bool v12458 = !(v12448 == 0);
  struct StateG * v12453;
  if (v12458) {
    struct StateG * v12449 = slot_628(v12444);
    v12453 = v12449;
  } else {
    struct StateG * v12451 = slot_629(v12444);
    v12453 = v12451;
  }
  return v12453;
}

struct StateG * slot_300(struct StateG * v6184) {
  int v6185 = v6184->timer;
  int v6191 = v6185 + 1;
  v6184->timer = v6191;
  int * v6187 = v6184->regs;
  v6187[17] = 10;
  struct StateG * v6189 = slot_316(v6184);
  return v6189;
}

struct StateG * slot_183(struct StateG * v3543) {
  int v3544 = v3543->timer;
  int v3550 = v3544 + 1;
  v3543->timer = v3550;
  int * v3546 = v3543->regs;
  v3546[17] = 10;
  struct StateG * v3548 = slot_199(v3543);
  return v3548;
}

struct StateG * slot_309(struct StateG * v6301) {
  int v6302 = v6301->timer;
  int v6308 = v6302 + 1;
  v6301->timer = v6308;
  int * v6304 = v6301->regs;
  v6304[17] = 10;
  struct StateG * v6306 = slot_325(v6301);
  return v6306;
}

struct StateG * slot_6(struct StateG * v278) {
  int * v279 = v278->saved_regs;
  int * v280 = v278->regs;
  int v281 = v280[18];
  v279[18] = v281;
  int v283 = v278->timer;
  int v293 = v283 + 1;
  v278->timer = v293;
  int * v285 = v278->regs;
  v285[18] = 2;
  struct StateG * v287 = slot_8(v278);
  return v287;
}

struct StateG * slot_283(struct StateG * v5998) {
  int v5999 = v5998->timer;
  int v6003 = v5999 + 1;
  v5998->timer = v6003;
  struct StateG * v6001 = slot_305(v5998);
  return v6001;
}

struct StateG * slot_516(struct StateG * v11204) {
  int * v11205 = v11204->regs;
  int v11206 = v11205[16];
  int v11207 = v11205[17];
  bool v11227 = v11206 < v11207;
  struct StateG * v11222;
  if (v11227) {
    int * v11208 = v11204->pht;
    v11208[97] = 1;
    struct StateG * v11210 = slot_544(v11204);
    v11222 = v11210;
  } else {
    int * v11212 = v11204->pht;
    v11212[97] = 0;
    int v11214 = v11204->timer;
    int v11236 = v11214 + 15;
    v11204->timer = v11236;
    int * v11216 = v11204->saved_regs;
    int v11217 = v11216[18];
    int * v11218 = v11204->regs;
    v11218[18] = v11217;
    struct StateG * v11220 = slot_545(v11204);
    v11222 = v11220;
  }
  return v11222;
}

struct StateG * slot_599(struct StateG * v12311) {
  int v12312 = v12311->timer;
  int v12318 = v12312 + 1;
  v12311->timer = v12318;
  int * v12314 = v12311->regs;
  v12314[17] = 10;
  struct StateG * v12316 = slot_615(v12311);
  return v12316;
}

struct StateG * slot_694(struct StateG * v14707) {
  int v14708 = v14707->timer;
  int v14714 = v14708 + 1;
  v14707->timer = v14714;
  int * v14710 = v14707->regs;
  v14710[18] = 2;
  struct StateG * v14712 = slot_692(v14707);
  return v14712;
}

struct StateG * slot_785(struct StateG * v15924) {
  int v15925 = v15924->timer;
  int v15935 = v15925 + 1;
  v15924->timer = v15935;
  int * v15927 = v15924->pht;
  int v15928 = v15927[22];
  bool v15938 = !(v15928 == 0);
  struct StateG * v15933;
  if (v15938) {
    struct StateG * v15929 = slot_810(v15924);
    v15933 = v15929;
  } else {
    struct StateG * v15931 = slot_811(v15924);
    v15933 = v15931;
  }
  return v15933;
}

struct StateG * slot_540(struct StateG * v11574) {
  int v11575 = v11574->timer;
  int v11579 = v11575 + 1;
  v11574->timer = v11579;
  struct StateG * v11577 = slot_562(v11574);
  return v11577;
}

struct StateG * slot_697(struct StateG * v14736) {
  int v14737 = v14736->timer;
  int v14743 = v14737 + 1;
  v14736->timer = v14743;
  int * v14739 = v14736->regs;
  v14739[18] = 1;
  struct StateG * v14741 = slot_699(v14736);
  return v14741;
}

struct StateG * slot_617(struct StateG * v12664) {
  int * v12665 = v12664->saved_regs;
  int * v12666 = v12664->regs;
  int v12667 = v12666[18];
  v12665[18] = v12667;
  int v12669 = v12664->timer;
  int v12679 = v12669 + 1;
  v12664->timer = v12679;
  int * v12671 = v12664->regs;
  v12671[18] = 1;
  struct StateG * v12673 = slot_649(v12664);
  return v12673;
}

struct StateG * slot_37(struct StateG * v866) {
  int v867 = v866->timer;
  int v873 = v867 + 1;
  v866->timer = v873;
  int * v869 = v866->regs;
  v869[19] = 1;
  struct StateG * v871 = slot_39(v866);
  return v871;
}

struct StateG * slot_114(struct StateG * v2252) {
  int * v2253 = v2252->saved_regs;
  int * v2254 = v2252->regs;
  int v2255 = v2254[18];
  v2253[18] = v2255;
  int v2257 = v2252->timer;
  int v2267 = v2257 + 1;
  v2252->timer = v2267;
  int * v2259 = v2252->regs;
  v2259[18] = 2;
  struct StateG * v2261 = slot_130(v2252);
  return v2261;
}

struct StateG * slot_257(struct StateG * v5516) {
  int * v5517 = v5516->regs;
  int v5518 = v5517[16];
  int v5519 = v5517[17];
  bool v5539 = v5518 < v5519;
  struct StateG * v5534;
  if (v5539) {
    int * v5520 = v5516->pht;
    v5520[67] = 1;
    int v5522 = v5516->timer;
    int v5543 = v5522 + 15;
    v5516->timer = v5543;
    int * v5524 = v5516->saved_regs;
    int v5525 = v5524[18];
    int * v5526 = v5516->regs;
    v5526[18] = v5525;
    struct StateG * v5528 = slot_282(v5516);
    v5534 = v5528;
  } else {
    int * v5530 = v5516->pht;
    v5530[67] = 0;
    struct StateG * v5532 = slot_283(v5516);
    v5534 = v5532;
  }
  return v5534;
}

struct StateG * slot_327(struct StateG * v6640) {
  int v6641 = v6640->timer;
  int v6651 = v6641 + 1;
  v6640->timer = v6651;
  int * v6643 = v6640->pht;
  int v6644 = v6643[80];
  bool v6654 = !(v6644 == 0);
  struct StateG * v6649;
  if (v6654) {
    struct StateG * v6645 = slot_358(v6640);
    v6649 = v6645;
  } else {
    struct StateG * v6647 = slot_359(v6640);
    v6649 = v6647;
  }
  return v6649;
}

struct StateG * slot_396(struct StateG * v8622) {
  int v8623 = v8622->timer;
  int v8627 = v8623 + 1;
  v8622->timer = v8627;
  struct StateG * v8625 = slot_426(v8622);
  return v8625;
}

struct StateG * slot_528(struct StateG * v11448) {
  int v11449 = v11448->timer;
  int v11453 = v11449 + 1;
  v11448->timer = v11453;
  struct StateG * v11451 = slot_556(v11448);
  return v11451;
}

struct StateG * slot_813(struct StateG * v16484) {
  int * v16485 = v16484->saved_regs;
  int * v16486 = v16484->regs;
  int v16487 = v16486[19];
  v16485[19] = v16487;
  int v16489 = v16484->timer;
  int v16499 = v16489 + 1;
  v16484->timer = v16499;
  int * v16491 = v16484->regs;
  v16491[19] = 1;
  struct StateG * v16493 = slot_845(v16484);
  return v16493;
}

struct StateG * slot_72(struct StateG * v1620) {
  int v1621 = v1620->timer;
  int v1625 = v1621 + 1;
  v1620->timer = v1625;
  struct StateG * v1623 = slot_88(v1620);
  return v1623;
}

struct StateG * slot_526(struct StateG * v11427) {
  int v11428 = v11427->timer;
  int v11434 = v11428 + 1;
  v11427->timer = v11434;
  int * v11430 = v11427->regs;
  v11430[18] = 2;
  struct StateG * v11432 = slot_524(v11427);
  return v11432;
}

struct StateG * slot_101(struct StateG * v1992) {
  int v1993 = v1992->timer;
  int v2003 = v1993 + 1;
  v1992->timer = v2003;
  int * v1995 = v1992->pht;
  int v1996 = v1995[50];
  bool v2006 = !(v1996 == 0);
  struct StateG * v2001;
  if (v2006) {
    struct StateG * v1997 = slot_114(v1992);
    v2001 = v1997;
  } else {
    struct StateG * v1999 = slot_115(v1992);
    v2001 = v1999;
  }
  return v2001;
}

struct StateG * slot_795(struct StateG * v16124) {
  int * v16125 = v16124->saved_regs;
  int * v16126 = v16124->regs;
  int v16127 = v16126[19];
  v16125[19] = v16127;
  int v16129 = v16124->timer;
  int v16139 = v16129 + 1;
  v16124->timer = v16139;
  int * v16131 = v16124->regs;
  v16131[19] = 1;
  struct StateG * v16133 = slot_827(v16124);
  return v16133;
}

struct StateG * slot_93(struct StateG * v1853) {
  int v1854 = v1853->timer;
  int v1860 = v1854 + 1;
  v1853->timer = v1860;
  int * v1856 = v1853->regs;
  v1856[17] = 10;
  struct StateG * v1858 = slot_101(v1853);
  return v1858;
}

struct StateG * slot_803(struct StateG * v16284) {
  int * v16285 = v16284->saved_regs;
  int * v16286 = v16284->regs;
  int v16287 = v16286[19];
  v16285[19] = v16287;
  int v16289 = v16284->timer;
  int v16299 = v16289 + 1;
  v16284->timer = v16299;
  int * v16291 = v16284->regs;
  v16291[19] = 1;
  struct StateG * v16293 = slot_835(v16284);
  return v16293;
}

struct StateG * slot_266(struct StateG * v5817) {
  int v5818 = v5817->timer;
  int v5824 = v5818 + 1;
  v5817->timer = v5824;
  int * v5820 = v5817->regs;
  v5820[18] = 2;
  struct StateG * v5822 = slot_264(v5817);
  return v5822;
}

struct StateG * slot_88(struct StateG * v1788) {
  int v1789 = v1788->timer;
  int v1795 = v1789 + 1;
  v1788->timer = v1795;
  int * v1791 = v1788->regs;
  v1791[17] = 10;
  struct StateG * v1793 = slot_96(v1788);
  return v1793;
}

struct StateG * slot_96(struct StateG * v1892) {
  int v1893 = v1892->timer;
  int v1903 = v1893 + 1;
  v1892->timer = v1903;
  int * v1895 = v1892->pht;
  int v1896 = v1895[55];
  bool v1906 = !(v1896 == 0);
  struct StateG * v1901;
  if (v1906) {
    struct StateG * v1897 = slot_104(v1892);
    v1901 = v1897;
  } else {
    struct StateG * v1899 = slot_105(v1892);
    v1901 = v1899;
  }
  return v1901;
}

struct StateG * slot_471(struct StateG * v9744) {
  int * v9745 = v9744->saved_regs;
  int * v9746 = v9744->regs;
  int v9747 = v9746[18];
  v9745[18] = v9747;
  int v9749 = v9744->timer;
  int v9759 = v9749 + 1;
  v9744->timer = v9759;
  int * v9751 = v9744->regs;
  v9751[18] = 1;
  struct StateG * v9753 = slot_503(v9744);
  return v9753;
}

struct StateG * slot_419(struct StateG * v8866) {
  int v8867 = v8866->timer;
  int v8871 = v8867 + 1;
  v8866->timer = v8871;
  struct StateG * v8869 = slot_437(v8866);
  return v8869;
}

struct StateG * slot_336(struct StateG * v6820) {
  int * v6821 = v6820->saved_regs;
  int * v6822 = v6820->regs;
  int v6823 = v6822[18];
  v6821[18] = v6823;
  int v6825 = v6820->timer;
  int v6835 = v6825 + 1;
  v6820->timer = v6835;
  int * v6827 = v6820->regs;
  v6827[18] = 2;
  struct StateG * v6829 = slot_368(v6820);
  return v6829;
}

struct StateG * slot_685(struct StateG * v14610) {
  int v14611 = v14610->timer;
  int v14617 = v14611 + 1;
  v14610->timer = v14617;
  int * v14613 = v14610->regs;
  v14613[18] = 1;
  struct StateG * v14615 = slot_687(v14610);
  return v14615;
}

struct StateG * slot_598(struct StateG * v12298) {
  int v12299 = v12298->timer;
  int v12305 = v12299 + 1;
  v12298->timer = v12305;
  int * v12301 = v12298->regs;
  v12301[17] = 10;
  struct StateG * v12303 = slot_614(v12298);
  return v12303;
}

struct StateG * slot_408(struct StateG * v8748) {
  int v8749 = v8748->timer;
  int v8753 = v8749 + 1;
  v8748->timer = v8753;
  struct StateG * v8751 = slot_432(v8748);
  return v8751;
}

struct StateG * slot_342(struct StateG * v6940) {
  int * v6941 = v6940->saved_regs;
  int * v6942 = v6940->regs;
  int v6943 = v6942[18];
  v6941[18] = v6943;
  int v6945 = v6940->timer;
  int v6955 = v6945 + 1;
  v6940->timer = v6955;
  int * v6947 = v6940->regs;
  v6947[18] = 2;
  struct StateG * v6949 = slot_374(v6940);
  return v6949;
}

struct StateG * slot_389(struct StateG * v8460) {
  int * v8461 = v8460->regs;
  int v8462 = v8461[16];
  int v8463 = v8461[17];
  bool v8483 = v8462 < v8463;
  struct StateG * v8478;
  if (v8483) {
    int * v8464 = v8460->pht;
    v8464[81] = 1;
    int v8466 = v8460->timer;
    int v8487 = v8466 + 15;
    v8460->timer = v8487;
    int * v8468 = v8460->saved_regs;
    int v8469 = v8468[18];
    int * v8470 = v8460->regs;
    v8470[18] = v8469;
    struct StateG * v8472 = slot_418(v8460);
    v8478 = v8472;
  } else {
    int * v8474 = v8460->pht;
    v8474[81] = 0;
    struct StateG * v8476 = slot_419(v8460);
    v8478 = v8476;
  }
  return v8478;
}

struct StateG * slot_678(struct StateG * v14482) {
  int * v14483 = v14482->regs;
  int v14484 = v14483[16];
  int v14485 = v14483[17];
  bool v14505 = v14484 < v14485;
  struct StateG * v14500;
  if (v14505) {
    int * v14486 = v14482->pht;
    v14486[0] = 1;
    struct StateG * v14488 = slot_708(v14482);
    v14500 = v14488;
  } else {
    int * v14490 = v14482->pht;
    v14490[0] = 0;
    int v14492 = v14482->timer;
    int v14513 = v14492 + 15;
    v14482->timer = v14513;
    int * v14494 = v14482->saved_regs;
    int v14495 = v14494[18];
    int * v14496 = v14482->regs;
    v14496[18] = v14495;
    struct StateG * v14498 = slot_709(v14482);
    v14500 = v14498;
  }
  return v14500;
}

struct StateG * slot_138(struct StateG * v3033) {
  int v3034 = v3033->timer;
  int v3040 = v3034 + 1;
  v3033->timer = v3040;
  int * v3036 = v3033->regs;
  v3036[18] = 2;
  struct StateG * v3038 = slot_136(v3033);
  return v3038;
}

struct StateG * slot_483(struct StateG * v9984) {
  int * v9985 = v9984->saved_regs;
  int * v9986 = v9984->regs;
  int v9987 = v9986[18];
  v9985[18] = v9987;
  int v9989 = v9984->timer;
  int v9999 = v9989 + 1;
  v9984->timer = v9999;
  int * v9991 = v9984->regs;
  v9991[18] = 1;
  struct StateG * v9993 = slot_515(v9984);
  return v9993;
}

struct StateG * slot_791(struct StateG * v16044) {
  int v16045 = v16044->timer;
  int v16055 = v16045 + 1;
  v16044->timer = v16055;
  int * v16047 = v16044->pht;
  int v16048 = v16047[16];
  bool v16058 = !(v16048 == 0);
  struct StateG * v16053;
  if (v16058) {
    struct StateG * v16049 = slot_822(v16044);
    v16053 = v16049;
  } else {
    struct StateG * v16051 = slot_823(v16044);
    v16053 = v16051;
  }
  return v16053;
}

struct StateG * slot_649(struct StateG * v13324) {
  int * v13325 = v13324->regs;
  int v13326 = v13325[16];
  int v13327 = v13325[17];
  bool v13347 = v13326 < v13327;
  struct StateG * v13342;
  if (v13347) {
    int * v13328 = v13324->pht;
    v13328[15] = 1;
    int v13330 = v13324->timer;
    int v13351 = v13330 + 15;
    v13324->timer = v13351;
    int * v13332 = v13324->saved_regs;
    int v13333 = v13332[18];
    int * v13334 = v13324->regs;
    v13334[18] = v13333;
    struct StateG * v13336 = slot_682(v13324);
    v13342 = v13336;
  } else {
    int * v13338 = v13324->pht;
    v13338[15] = 0;
    struct StateG * v13340 = slot_683(v13324);
    v13342 = v13340;
  }
  return v13342;
}

struct StateG * slot_425(struct StateG * v8929) {
  int v8930 = v8929->timer;
  int v8936 = v8930 + 1;
  v8929->timer = v8936;
  int * v8932 = v8929->regs;
  v8932[17] = 10;
  struct StateG * v8934 = slot_441(v8929);
  return v8934;
}

struct StateG * slot_131(struct StateG * v2812) {
  int * v2813 = v2812->regs;
  int v2814 = v2813[16];
  int v2815 = v2813[17];
  bool v2835 = v2814 < v2815;
  struct StateG * v2830;
  if (v2835) {
    int * v2816 = v2812->pht;
    v2816[50] = 1;
    int v2818 = v2812->timer;
    int v2839 = v2818 + 15;
    v2812->timer = v2839;
    int * v2820 = v2812->saved_regs;
    int v2821 = v2820[18];
    int * v2822 = v2812->regs;
    v2822[18] = v2821;
    struct StateG * v2824 = slot_158(v2812);
    v2830 = v2824;
  } else {
    int * v2826 = v2812->pht;
    v2826[50] = 0;
    struct StateG * v2828 = slot_159(v2812);
    v2830 = v2828;
  }
  return v2830;
}

struct StateG * slot_504(struct StateG * v10724) {
  int * v10725 = v10724->regs;
  int v10726 = v10725[16];
  int v10727 = v10725[17];
  bool v10747 = v10726 < v10727;
  struct StateG * v10742;
  if (v10747) {
    int * v10728 = v10724->pht;
    v10728[103] = 1;
    struct StateG * v10730 = slot_520(v10724);
    v10742 = v10730;
  } else {
    int * v10732 = v10724->pht;
    v10732[103] = 0;
    int v10734 = v10724->timer;
    int v10756 = v10734 + 15;
    v10724->timer = v10756;
    int * v10736 = v10724->saved_regs;
    int v10737 = v10736[18];
    int * v10738 = v10724->regs;
    v10738[18] = v10737;
    struct StateG * v10740 = slot_521(v10724);
    v10742 = v10740;
  }
  return v10742;
}

struct StateG * slot_496(struct StateG * v10404) {
  int * v10405 = v10404->regs;
  int v10406 = v10405[16];
  int v10407 = v10405[17];
  bool v10427 = v10406 < v10407;
  struct StateG * v10422;
  if (v10427) {
    int * v10408 = v10404->pht;
    v10408[107] = 1;
    struct StateG * v10410 = slot_536(v10404);
    v10422 = v10410;
  } else {
    int * v10412 = v10404->pht;
    v10412[107] = 0;
    int v10414 = v10404->timer;
    int v10436 = v10414 + 15;
    v10404->timer = v10436;
    int * v10416 = v10404->saved_regs;
    int v10417 = v10416[18];
    int * v10418 = v10404->regs;
    v10418[18] = v10417;
    struct StateG * v10420 = slot_537(v10404);
    v10422 = v10420;
  }
  return v10422;
}

struct StateG * slot_242(struct StateG * v4916) {
  int * v4917 = v4916->regs;
  int v4918 = v4917[16];
  int v4919 = v4917[17];
  bool v4939 = v4918 < v4919;
  struct StateG * v4934;
  if (v4939) {
    int * v4920 = v4916->pht;
    v4920[74] = 1;
    struct StateG * v4922 = slot_284(v4916);
    v4934 = v4922;
  } else {
    int * v4924 = v4916->pht;
    v4924[74] = 0;
    int v4926 = v4916->timer;
    int v4948 = v4926 + 15;
    v4916->timer = v4948;
    int * v4928 = v4916->saved_regs;
    int v4929 = v4928[18];
    int * v4930 = v4916->regs;
    v4930[18] = v4929;
    struct StateG * v4932 = slot_285(v4916);
    v4934 = v4932;
  }
  return v4934;
}

struct StateG * slot_605(struct StateG * v12424) {
  int v12425 = v12424->timer;
  int v12435 = v12425 + 1;
  v12424->timer = v12435;
  int * v12427 = v12424->pht;
  int v12428 = v12427[10];
  bool v12438 = !(v12428 == 0);
  struct StateG * v12433;
  if (v12438) {
    struct StateG * v12429 = slot_626(v12424);
    v12433 = v12429;
  } else {
    struct StateG * v12431 = slot_627(v12424);
    v12433 = v12431;
  }
  return v12433;
}

struct StateG * slot_757(struct StateG * v15497) {
  int v15498 = v15497->timer;
  int v15504 = v15498 + 1;
  v15497->timer = v15504;
  int * v15500 = v15497->regs;
  v15500[1] = 164;
  struct StateG * v15502 = slot_773(v15497);
  return v15502;
}

struct StateG * slot_200(struct StateG * v3876) {
  int * v3877 = v3876->saved_regs;
  int * v3878 = v3876->regs;
  int v3879 = v3878[18];
  v3877[18] = v3879;
  int v3881 = v3876->timer;
  int v3891 = v3881 + 1;
  v3876->timer = v3891;
  int * v3883 = v3876->regs;
  v3883[18] = 2;
  struct StateG * v3885 = slot_232(v3876);
  return v3885;
}

struct StateG * slot_334(struct StateG * v6780) {
  int * v6781 = v6780->saved_regs;
  int * v6782 = v6780->regs;
  int v6783 = v6782[18];
  v6781[18] = v6783;
  int v6785 = v6780->timer;
  int v6795 = v6785 + 1;
  v6780->timer = v6795;
  int * v6787 = v6780->regs;
  v6787[18] = 2;
  struct StateG * v6789 = slot_366(v6780);
  return v6789;
}

struct StateG * slot_104(struct StateG * v2052) {
  int * v2053 = v2052->saved_regs;
  int * v2054 = v2052->regs;
  int v2055 = v2054[18];
  v2053[18] = v2055;
  int v2057 = v2052->timer;
  int v2067 = v2057 + 1;
  v2052->timer = v2067;
  int * v2059 = v2052->regs;
  v2059[18] = 2;
  struct StateG * v2061 = slot_120(v2052);
  return v2061;
}

struct StateG * slot_329(struct StateG * v6680) {
  int * v6681 = v6680->saved_regs;
  int * v6682 = v6680->regs;
  int v6683 = v6682[18];
  v6681[18] = v6683;
  int v6685 = v6680->timer;
  int v6695 = v6685 + 1;
  v6680->timer = v6695;
  int * v6687 = v6680->regs;
  v6687[18] = 1;
  struct StateG * v6689 = slot_361(v6680);
  return v6689;
}

struct StateG * slot_395(struct StateG * v8614) {
  int v8615 = v8614->timer;
  int v8619 = v8615 + 1;
  v8614->timer = v8619;
  struct StateG * v8617 = slot_425(v8614);
  return v8617;
}

struct StateG * slot_604(struct StateG * v12404) {
  int v12405 = v12404->timer;
  int v12415 = v12405 + 1;
  v12404->timer = v12415;
  int * v12407 = v12404->pht;
  int v12408 = v12407[11];
  bool v12418 = !(v12408 == 0);
  struct StateG * v12413;
  if (v12418) {
    struct StateG * v12409 = slot_624(v12404);
    v12413 = v12409;
  } else {
    struct StateG * v12411 = slot_625(v12404);
    v12413 = v12411;
  }
  return v12413;
}

struct StateG * slot_298(struct StateG * v6158) {
  int v6159 = v6158->timer;
  int v6165 = v6159 + 1;
  v6158->timer = v6165;
  int * v6161 = v6158->regs;
  v6161[17] = 10;
  struct StateG * v6163 = slot_314(v6158);
  return v6163;
}

struct StateG * slot_626(struct StateG * v12844) {
  int * v12845 = v12844->saved_regs;
  int * v12846 = v12844->regs;
  int v12847 = v12846[18];
  v12845[18] = v12847;
  int v12849 = v12844->timer;
  int v12859 = v12849 + 1;
  v12844->timer = v12859;
  int * v12851 = v12844->regs;
  v12851[18] = 2;
  struct StateG * v12853 = slot_658(v12844);
  return v12853;
}

struct StateG * slot_839(struct StateG * v17304) {
  int * v17305 = v17304->regs;
  int v17306 = v17305[16];
  int v17307 = v17305[17];
  bool v17327 = v17306 >= v17307;
  struct StateG * v17322;
  if (v17327) {
    int * v17308 = v17304->pht;
    v17308[24] = 1;
    int v17310 = v17304->timer;
    int v17331 = v17310 + 15;
    v17304->timer = v17331;
    int * v17312 = v17304->saved_regs;
    int v17313 = v17312[19];
    int * v17314 = v17304->regs;
    v17314[19] = v17313;
    struct StateG * v17316 = slot_858(v17304);
    v17322 = v17316;
  } else {
    int * v17318 = v17304->pht;
    v17318[24] = 0;
    struct StateG * v17320 = slot_883(v17304);
    v17322 = v17320;
  }
  return v17322;
}

struct StateG * slot_253(struct StateG * v5356) {
  int * v5357 = v5356->regs;
  int v5358 = v5357[16];
  int v5359 = v5357[17];
  bool v5379 = v5358 < v5359;
  struct StateG * v5374;
  if (v5379) {
    int * v5360 = v5356->pht;
    v5360[69] = 1;
    int v5362 = v5356->timer;
    int v5383 = v5362 + 15;
    v5356->timer = v5383;
    int * v5364 = v5356->saved_regs;
    int v5365 = v5364[18];
    int * v5366 = v5356->regs;
    v5366[18] = v5365;
    struct StateG * v5368 = slot_274(v5356);
    v5374 = v5368;
  } else {
    int * v5370 = v5356->pht;
    v5370[69] = 0;
    struct StateG * v5372 = slot_275(v5356);
    v5374 = v5372;
  }
  return v5374;
}

struct StateG * slot_64(struct StateG * v1300) {
  int * v1301 = v1300->regs;
  int v1302 = v1301[16];
  int v1303 = v1301[17];
  bool v1323 = v1302 < v1303;
  struct StateG * v1318;
  if (v1323) {
    int * v1304 = v1300->pht;
    v1304[35] = 1;
    struct StateG * v1306 = slot_72(v1300);
    v1318 = v1306;
  } else {
    int * v1308 = v1300->pht;
    v1308[35] = 0;
    int v1310 = v1300->timer;
    int v1332 = v1310 + 15;
    v1300->timer = v1332;
    int * v1312 = v1300->saved_regs;
    int v1313 = v1312[18];
    int * v1314 = v1300->regs;
    v1314[18] = v1313;
    struct StateG * v1316 = slot_73(v1300);
    v1318 = v1316;
  }
  return v1318;
}

struct StateG * slot_170(struct StateG * v3374) {
  int v3375 = v3374->timer;
  int v3381 = v3375 + 1;
  v3374->timer = v3381;
  int * v3377 = v3374->regs;
  v3377[17] = 10;
  struct StateG * v3379 = slot_186(v3374);
  return v3379;
}

struct StateG * slot_53(struct StateG * v1080) {
  int v1081 = v1080->timer;
  int v1091 = v1081 + 1;
  v1080->timer = v1091;
  int * v1083 = v1080->pht;
  int v1084 = v1083[34];
  bool v1094 = !(v1084 == 0);
  struct StateG * v1089;
  if (v1094) {
    struct StateG * v1085 = slot_58(v1080);
    v1089 = v1085;
  } else {
    struct StateG * v1087 = slot_59(v1080);
    v1089 = v1087;
  }
  return v1089;
}

struct StateG * slot_503(struct StateG * v10684) {
  int * v10685 = v10684->regs;
  int v10686 = v10685[16];
  int v10687 = v10685[17];
  bool v10707 = v10686 < v10687;
  struct StateG * v10702;
  if (v10707) {
    int * v10688 = v10684->pht;
    v10688[104] = 1;
    int v10690 = v10684->timer;
    int v10711 = v10690 + 15;
    v10684->timer = v10711;
    int * v10692 = v10684->saved_regs;
    int v10693 = v10692[18];
    int * v10694 = v10684->regs;
    v10694[18] = v10693;
    struct StateG * v10696 = slot_550(v10684);
    v10702 = v10696;
  } else {
    int * v10698 = v10684->pht;
    v10698[104] = 0;
    struct StateG * v10700 = slot_551(v10684);
    v10702 = v10700;
  }
  return v10702;
}

struct StateG * slot_829(struct StateG * v16904) {
  int * v16905 = v16904->regs;
  int v16906 = v16905[16];
  int v16907 = v16905[17];
  bool v16927 = v16906 >= v16907;
  struct StateG * v16922;
  if (v16927) {
    int * v16908 = v16904->pht;
    v16908[29] = 1;
    int v16910 = v16904->timer;
    int v16931 = v16910 + 15;
    v16904->timer = v16931;
    int * v16912 = v16904->saved_regs;
    int v16913 = v16912[19];
    int * v16914 = v16904->regs;
    v16914[19] = v16913;
    struct StateG * v16916 = slot_858(v16904);
    v16922 = v16916;
  } else {
    int * v16918 = v16904->pht;
    v16918[29] = 0;
    struct StateG * v16920 = slot_883(v16904);
    v16922 = v16920;
  }
  return v16922;
}

struct StateG * slot_635(struct StateG * v13024) {
  int * v13025 = v13024->saved_regs;
  int * v13026 = v13024->regs;
  int v13027 = v13026[18];
  v13025[18] = v13027;
  int v13029 = v13024->timer;
  int v13039 = v13029 + 1;
  v13024->timer = v13039;
  int * v13031 = v13024->regs;
  v13031[18] = 1;
  struct StateG * v13033 = slot_667(v13024);
  return v13033;
}

struct StateG * slot_386(struct StateG * v8340) {
  int * v8341 = v8340->regs;
  int v8342 = v8341[16];
  int v8343 = v8341[17];
  bool v8363 = v8342 < v8343;
  struct StateG * v8358;
  if (v8363) {
    int * v8344 = v8340->pht;
    v8344[82] = 1;
    struct StateG * v8346 = slot_412(v8340);
    v8358 = v8346;
  } else {
    int * v8348 = v8340->pht;
    v8348[82] = 0;
    int v8350 = v8340->timer;
    int v8372 = v8350 + 15;
    v8340->timer = v8372;
    int * v8352 = v8340->saved_regs;
    int v8353 = v8352[18];
    int * v8354 = v8340->regs;
    v8354[18] = v8353;
    struct StateG * v8356 = slot_413(v8340);
    v8358 = v8356;
  }
  return v8358;
}

struct StateG * slot_840(struct StateG * v17344) {
  int * v17345 = v17344->regs;
  int v17346 = v17345[16];
  int v17347 = v17345[17];
  bool v17367 = v17346 >= v17347;
  struct StateG * v17362;
  if (v17367) {
    int * v17348 = v17344->pht;
    v17348[23] = 1;
    struct StateG * v17350 = slot_883(v17344);
    v17362 = v17350;
  } else {
    int * v17352 = v17344->pht;
    v17352[23] = 0;
    int v17354 = v17344->timer;
    int v17376 = v17354 + 15;
    v17344->timer = v17376;
    int * v17356 = v17344->saved_regs;
    int v17357 = v17356[19];
    int * v17358 = v17344->regs;
    v17358[19] = v17357;
    struct StateG * v17360 = slot_861(v17344);
    v17362 = v17360;
  }
  return v17362;
}

struct StateG * slot_99(struct StateG * v1952) {
  int v1953 = v1952->timer;
  int v1963 = v1953 + 1;
  v1952->timer = v1963;
  int * v1955 = v1952->pht;
  int v1956 = v1955[52];
  bool v1966 = !(v1956 == 0);
  struct StateG * v1961;
  if (v1966) {
    struct StateG * v1957 = slot_110(v1952);
    v1961 = v1957;
  } else {
    struct StateG * v1959 = slot_111(v1952);
    v1961 = v1959;
  }
  return v1961;
}

struct StateG * slot_219(struct StateG * v4256) {
  int * v4257 = v4256->saved_regs;
  int * v4258 = v4256->regs;
  int v4259 = v4258[18];
  v4257[18] = v4259;
  int v4261 = v4256->timer;
  int v4271 = v4261 + 1;
  v4256->timer = v4271;
  int * v4263 = v4256->regs;
  v4263[18] = 1;
  struct StateG * v4265 = slot_251(v4256);
  return v4265;
}

struct StateG * slot_664(struct StateG * v13924) {
  int * v13925 = v13924->regs;
  int v13926 = v13925[16];
  int v13927 = v13925[17];
  bool v13947 = v13926 < v13927;
  struct StateG * v13942;
  if (v13947) {
    int * v13928 = v13924->pht;
    v13928[7] = 1;
    struct StateG * v13930 = slot_680(v13924);
    v13942 = v13930;
  } else {
    int * v13932 = v13924->pht;
    v13932[7] = 0;
    int v13934 = v13924->timer;
    int v13956 = v13934 + 15;
    v13924->timer = v13956;
    int * v13936 = v13924->saved_regs;
    int v13937 = v13936[18];
    int * v13938 = v13924->regs;
    v13938[18] = v13937;
    struct StateG * v13940 = slot_681(v13924);
    v13942 = v13940;
  }
  return v13942;
}

struct StateG * slot_855(struct StateG * v17936) {
  int * v17937 = v17936->regs;
  int v17938 = v17937[16];
  int v17939 = v17937[17];
  bool v17959 = v17938 >= v17939;
  struct StateG * v17954;
  if (v17959) {
    int * v17940 = v17936->pht;
    v17940[16] = 1;
    int v17942 = v17936->timer;
    int v17962 = v17942 + 15;
    v17936->timer = v17962;
    int * v17944 = v17936->saved_regs;
    int v17945 = v17944[19];
    int * v17946 = v17936->regs;
    v17946[19] = v17945;
    struct StateG * v17948 = slot_858(v17936);
    v17954 = v17948;
  } else {
    int * v17950 = v17936->pht;
    v17950[16] = 0;
    struct StateG * v17952 = slot_883(v17936);
    v17954 = v17952;
  }
  return v17954;
}

struct StateG * slot_22(struct StateG * v544) {
  int v545 = v544->timer;
  int v555 = v545 + 1;
  v544->timer = v555;
  int * v547 = v544->pht;
  int v548 = v547[17];
  bool v558 = !(v548 == 0);
  struct StateG * v553;
  if (v558) {
    struct StateG * v549 = slot_24(v544);
    v553 = v549;
  } else {
    struct StateG * v551 = slot_25(v544);
    v553 = v551;
  }
  return v553;
}

struct StateG * slot_139(struct StateG * v3046) {
  int v3047 = v3046->timer;
  int v3051 = v3047 + 1;
  v3046->timer = v3051;
  struct StateG * v3049 = slot_169(v3046);
  return v3049;
}

struct StateG * slot_654(struct StateG * v13524) {
  int * v13525 = v13524->regs;
  int v13526 = v13525[16];
  int v13527 = v13525[17];
  bool v13547 = v13526 < v13527;
  struct StateG * v13542;
  if (v13547) {
    int * v13528 = v13524->pht;
    v13528[12] = 1;
    struct StateG * v13530 = slot_692(v13524);
    v13542 = v13530;
  } else {
    int * v13532 = v13524->pht;
    v13532[12] = 0;
    int v13534 = v13524->timer;
    int v13556 = v13534 + 15;
    v13524->timer = v13556;
    int * v13536 = v13524->saved_regs;
    int v13537 = v13536[18];
    int * v13538 = v13524->regs;
    v13538[18] = v13537;
    struct StateG * v13540 = slot_693(v13524);
    v13542 = v13540;
  }
  return v13542;
}

struct StateG * slot_790(struct StateG * v16024) {
  int v16025 = v16024->timer;
  int v16035 = v16025 + 1;
  v16024->timer = v16035;
  int * v16027 = v16024->pht;
  int v16028 = v16027[17];
  bool v16038 = !(v16028 == 0);
  struct StateG * v16033;
  if (v16038) {
    struct StateG * v16029 = slot_820(v16024);
    v16033 = v16029;
  } else {
    struct StateG * v16031 = slot_821(v16024);
    v16033 = v16031;
  }
  return v16033;
}

struct StateG * slot_786(struct StateG * v15944) {
  int v15945 = v15944->timer;
  int v15955 = v15945 + 1;
  v15944->timer = v15955;
  int * v15947 = v15944->pht;
  int v15948 = v15947[21];
  bool v15958 = !(v15948 == 0);
  struct StateG * v15953;
  if (v15958) {
    struct StateG * v15949 = slot_812(v15944);
    v15953 = v15949;
  } else {
    struct StateG * v15951 = slot_813(v15944);
    v15953 = v15951;
  }
  return v15953;
}

struct StateG * slot_608(struct StateG * v12484) {
  int v12485 = v12484->timer;
  int v12495 = v12485 + 1;
  v12484->timer = v12495;
  int * v12487 = v12484->pht;
  int v12488 = v12487[7];
  bool v12498 = !(v12488 == 0);
  struct StateG * v12493;
  if (v12498) {
    struct StateG * v12489 = slot_632(v12484);
    v12493 = v12489;
  } else {
    struct StateG * v12491 = slot_633(v12484);
    v12493 = v12491;
  }
  return v12493;
}

struct StateG * slot_333(struct StateG * v6760) {
  int * v6761 = v6760->saved_regs;
  int * v6762 = v6760->regs;
  int v6763 = v6762[18];
  v6761[18] = v6763;
  int v6765 = v6760->timer;
  int v6775 = v6765 + 1;
  v6760->timer = v6775;
  int * v6767 = v6760->regs;
  v6767[18] = 1;
  struct StateG * v6769 = slot_365(v6760);
  return v6769;
}

struct StateG * slot_221(struct StateG * v4296) {
  int * v4297 = v4296->saved_regs;
  int * v4298 = v4296->regs;
  int v4299 = v4298[18];
  v4297[18] = v4299;
  int v4301 = v4296->timer;
  int v4311 = v4301 + 1;
  v4296->timer = v4311;
  int * v4303 = v4296->regs;
  v4303[18] = 1;
  struct StateG * v4305 = slot_253(v4296);
  return v4305;
}

struct StateG * slot_797(struct StateG * v16164) {
  int * v16165 = v16164->saved_regs;
  int * v16166 = v16164->regs;
  int v16167 = v16166[19];
  v16165[19] = v16167;
  int v16169 = v16164->timer;
  int v16179 = v16169 + 1;
  v16164->timer = v16179;
  int * v16171 = v16164->regs;
  v16171[19] = 1;
  struct StateG * v16173 = slot_829(v16164);
  return v16173;
}

struct StateG * slot_623(struct StateG * v12784) {
  int * v12785 = v12784->saved_regs;
  int * v12786 = v12784->regs;
  int v12787 = v12786[18];
  v12785[18] = v12787;
  int v12789 = v12784->timer;
  int v12799 = v12789 + 1;
  v12784->timer = v12799;
  int * v12791 = v12784->regs;
  v12791[18] = 1;
  struct StateG * v12793 = slot_655(v12784);
  return v12793;
}

struct StateG * slot_153(struct StateG * v3188) {
  int v3189 = v3188->timer;
  int v3195 = v3189 + 1;
  v3188->timer = v3195;
  int * v3191 = v3188->regs;
  v3191[18] = 1;
  struct StateG * v3193 = slot_155(v3188);
  return v3193;
}

struct StateG * slot_129(struct StateG * v2732) {
  int * v2733 = v2732->regs;
  int v2734 = v2733[16];
  int v2735 = v2733[17];
  bool v2755 = v2734 < v2735;
  struct StateG * v2750;
  if (v2755) {
    int * v2736 = v2732->pht;
    v2736[51] = 1;
    int v2738 = v2732->timer;
    int v2759 = v2738 + 15;
    v2732->timer = v2759;
    int * v2740 = v2732->saved_regs;
    int v2741 = v2740[18];
    int * v2742 = v2732->regs;
    v2742[18] = v2741;
    struct StateG * v2744 = slot_154(v2732);
    v2750 = v2744;
  } else {
    int * v2746 = v2732->pht;
    v2746[51] = 0;
    struct StateG * v2748 = slot_155(v2732);
    v2750 = v2748;
  }
  return v2750;
}

struct StateG * slot_158(struct StateG * v3243) {
  int v3244 = v3243->timer;
  int v3250 = v3244 + 1;
  v3243->timer = v3250;
  int * v3246 = v3243->regs;
  v3246[18] = 2;
  struct StateG * v3248 = slot_156(v3243);
  return v3248;
}

struct StateG * slot_498(struct StateG * v10484) {
  int * v10485 = v10484->regs;
  int v10486 = v10485[16];
  int v10487 = v10485[17];
  bool v10507 = v10486 < v10487;
  struct StateG * v10502;
  if (v10507) {
    int * v10488 = v10484->pht;
    v10488[106] = 1;
    struct StateG * v10490 = slot_540(v10484);
    v10502 = v10490;
  } else {
    int * v10492 = v10484->pht;
    v10492[106] = 0;
    int v10494 = v10484->timer;
    int v10516 = v10494 + 15;
    v10484->timer = v10516;
    int * v10496 = v10484->saved_regs;
    int v10497 = v10496[18];
    int * v10498 = v10484->regs;
    v10498[18] = v10497;
    struct StateG * v10500 = slot_541(v10484);
    v10502 = v10500;
  }
  return v10502;
}

struct StateG * slot_648(struct StateG * v13284) {
  int * v13285 = v13284->regs;
  int v13286 = v13285[16];
  int v13287 = v13285[17];
  bool v13307 = v13286 < v13287;
  struct StateG * v13302;
  if (v13307) {
    int * v13288 = v13284->pht;
    v13288[15] = 1;
    struct StateG * v13290 = slot_680(v13284);
    v13302 = v13290;
  } else {
    int * v13292 = v13284->pht;
    v13292[15] = 0;
    int v13294 = v13284->timer;
    int v13316 = v13294 + 15;
    v13284->timer = v13316;
    int * v13296 = v13284->saved_regs;
    int v13297 = v13296[18];
    int * v13298 = v13284->regs;
    v13298[18] = v13297;
    struct StateG * v13300 = slot_681(v13284);
    v13302 = v13300;
  }
  return v13302;
}

struct StateG * slot_575(struct StateG * v11999) {
  int v12000 = v11999->timer;
  int v12006 = v12000 + 1;
  v11999->timer = v12006;
  int * v12002 = v11999->regs;
  v12002[1] = 156;
  struct StateG * v12004 = slot_591(v11999);
  return v12004;
}

struct StateG * slot_271(struct StateG * v5872) {
  int v5873 = v5872->timer;
  int v5877 = v5873 + 1;
  v5872->timer = v5877;
  struct StateG * v5875 = slot_299(v5872);
  return v5875;
}

struct StateG * slot_524(struct StateG * v11406) {
  int v11407 = v11406->timer;
  int v11411 = v11407 + 1;
  v11406->timer = v11411;
  struct StateG * v11409 = slot_554(v11406);
  return v11409;
}

struct StateG * slot_808(struct StateG * v16384) {
  int * v16385 = v16384->saved_regs;
  int * v16386 = v16384->regs;
  int v16387 = v16386[19];
  v16385[19] = v16387;
  int v16389 = v16384->timer;
  int v16399 = v16389 + 1;
  v16384->timer = v16399;
  int * v16391 = v16384->regs;
  v16391[19] = 2;
  struct StateG * v16393 = slot_840(v16384);
  return v16393;
}

struct StateG * slot_505(struct StateG * v10764) {
  int * v10765 = v10764->regs;
  int v10766 = v10765[16];
  int v10767 = v10765[17];
  bool v10787 = v10766 < v10767;
  struct StateG * v10782;
  if (v10787) {
    int * v10768 = v10764->pht;
    v10768[103] = 1;
    int v10770 = v10764->timer;
    int v10791 = v10770 + 15;
    v10764->timer = v10791;
    int * v10772 = v10764->saved_regs;
    int v10773 = v10772[18];
    int * v10774 = v10764->regs;
    v10774[18] = v10773;
    struct StateG * v10776 = slot_522(v10764);
    v10782 = v10776;
  } else {
    int * v10778 = v10764->pht;
    v10778[103] = 0;
    struct StateG * v10780 = slot_523(v10764);
    v10782 = v10780;
  }
  return v10782;
}

struct StateG * slot_532(struct StateG * v11490) {
  int v11491 = v11490->timer;
  int v11495 = v11491 + 1;
  v11490->timer = v11495;
  struct StateG * v11493 = slot_558(v11490);
  return v11493;
}

struct StateG * slot_410(struct StateG * v8769) {
  int v8770 = v8769->timer;
  int v8776 = v8770 + 1;
  v8769->timer = v8776;
  int * v8772 = v8769->regs;
  v8772[18] = 2;
  struct StateG * v8774 = slot_408(v8769);
  return v8774;
}

struct StateG * slot_844(struct StateG * v17504) {
  int * v17505 = v17504->regs;
  int v17506 = v17505[16];
  int v17507 = v17505[17];
  bool v17527 = v17506 >= v17507;
  struct StateG * v17522;
  if (v17527) {
    int * v17508 = v17504->pht;
    v17508[21] = 1;
    struct StateG * v17510 = slot_883(v17504);
    v17522 = v17510;
  } else {
    int * v17512 = v17504->pht;
    v17512[21] = 0;
    int v17514 = v17504->timer;
    int v17536 = v17514 + 15;
    v17504->timer = v17536;
    int * v17516 = v17504->saved_regs;
    int v17517 = v17516[19];
    int * v17518 = v17504->regs;
    v17518[19] = v17517;
    struct StateG * v17520 = slot_861(v17504);
    v17522 = v17520;
  }
  return v17522;
}

struct StateG * slot_204(struct StateG * v3956) {
  int * v3957 = v3956->saved_regs;
  int * v3958 = v3956->regs;
  int v3959 = v3958[18];
  v3957[18] = v3959;
  int v3961 = v3956->timer;
  int v3971 = v3961 + 1;
  v3956->timer = v3971;
  int * v3963 = v3956->regs;
  v3963[18] = 2;
  struct StateG * v3965 = slot_236(v3956);
  return v3965;
}

struct StateG * slot_194(struct StateG * v3756) {
  int v3757 = v3756->timer;
  int v3767 = v3757 + 1;
  v3756->timer = v3767;
  int * v3759 = v3756->pht;
  int v3760 = v3759[69];
  bool v3770 = !(v3760 == 0);
  struct StateG * v3765;
  if (v3770) {
    struct StateG * v3761 = slot_220(v3756);
    v3765 = v3761;
  } else {
    struct StateG * v3763 = slot_221(v3756);
    v3765 = v3763;
  }
  return v3765;
}

struct StateG * slot_551(struct StateG * v11692) {
  int v11693 = v11692->timer;
  int v11697 = v11693 + 1;
  v11692->timer = v11697;
  struct StateG * v11695 = slot_567(v11692);
  return v11695;
}

struct StateG * slot_641(struct StateG * v13144) {
  int * v13145 = v13144->saved_regs;
  int * v13146 = v13144->regs;
  int v13147 = v13146[18];
  v13145[18] = v13147;
  int v13149 = v13144->timer;
  int v13159 = v13149 + 1;
  v13144->timer = v13159;
  int * v13151 = v13144->regs;
  v13151[18] = 1;
  struct StateG * v13153 = slot_673(v13144);
  return v13153;
}

struct StateG * slot_821(struct StateG * v16644) {
  int * v16645 = v16644->saved_regs;
  int * v16646 = v16644->regs;
  int v16647 = v16646[19];
  v16645[19] = v16647;
  int v16649 = v16644->timer;
  int v16659 = v16649 + 1;
  v16644->timer = v16659;
  int * v16651 = v16644->regs;
  v16651[19] = 1;
  struct StateG * v16653 = slot_853(v16644);
  return v16653;
}

struct StateG * slot_543(struct StateG * v11608) {
  int v11609 = v11608->timer;
  int v11613 = v11609 + 1;
  v11608->timer = v11613;
  struct StateG * v11611 = slot_563(v11608);
  return v11611;
}

struct StateG * slot_826(struct StateG * v16784) {
  int * v16785 = v16784->regs;
  int v16786 = v16785[16];
  int v16787 = v16785[17];
  bool v16807 = v16786 >= v16787;
  struct StateG * v16802;
  if (v16807) {
    int * v16788 = v16784->pht;
    v16788[30] = 1;
    struct StateG * v16790 = slot_883(v16784);
    v16802 = v16790;
  } else {
    int * v16792 = v16784->pht;
    v16792[30] = 0;
    int v16794 = v16784->timer;
    int v16816 = v16794 + 15;
    v16784->timer = v16816;
    int * v16796 = v16784->saved_regs;
    int v16797 = v16796[19];
    int * v16798 = v16784->regs;
    v16798[19] = v16797;
    struct StateG * v16800 = slot_861(v16784);
    v16802 = v16800;
  }
  return v16802;
}

struct StateG * slot_117(struct StateG * v2312) {
  int * v2313 = v2312->saved_regs;
  int * v2314 = v2312->regs;
  int v2315 = v2314[18];
  v2313[18] = v2315;
  int v2317 = v2312->timer;
  int v2327 = v2317 + 1;
  v2312->timer = v2327;
  int * v2319 = v2312->regs;
  v2319[18] = 1;
  struct StateG * v2321 = slot_133(v2312);
  return v2321;
}

struct StateG * slot_667(struct StateG * v14044) {
  int * v14045 = v14044->regs;
  int v14046 = v14045[16];
  int v14047 = v14045[17];
  bool v14067 = v14046 < v14047;
  struct StateG * v14062;
  if (v14067) {
    int * v14048 = v14044->pht;
    v14048[6] = 1;
    int v14050 = v14044->timer;
    int v14071 = v14050 + 15;
    v14044->timer = v14071;
    int * v14052 = v14044->saved_regs;
    int v14053 = v14052[18];
    int * v14054 = v14044->regs;
    v14054[18] = v14053;
    struct StateG * v14056 = slot_686(v14044);
    v14062 = v14056;
  } else {
    int * v14058 = v14044->pht;
    v14058[6] = 0;
    struct StateG * v14060 = slot_687(v14044);
    v14062 = v14060;
  }
  return v14062;
}

struct StateG * slot_90(struct StateG * v1814) {
  int v1815 = v1814->timer;
  int v1821 = v1815 + 1;
  v1814->timer = v1821;
  int * v1817 = v1814->regs;
  v1817[17] = 10;
  struct StateG * v1819 = slot_98(v1814);
  return v1819;
}

struct StateG * slot_748(struct StateG * v15380) {
  int v15381 = v15380->timer;
  int v15387 = v15381 + 1;
  v15380->timer = v15387;
  int * v15383 = v15380->regs;
  v15383[1] = 164;
  struct StateG * v15385 = slot_764(v15380);
  return v15385;
}

struct StateG * slot_143(struct StateG * v3088) {
  int v3089 = v3088->timer;
  int v3093 = v3089 + 1;
  v3088->timer = v3093;
  struct StateG * v3091 = slot_171(v3088);
  return v3091;
}

struct StateG * slot_226(struct StateG * v4396) {
  int * v4397 = v4396->saved_regs;
  int * v4398 = v4396->regs;
  int v4399 = v4398[18];
  v4397[18] = v4399;
  int v4401 = v4396->timer;
  int v4411 = v4401 + 1;
  v4396->timer = v4411;
  int * v4403 = v4396->regs;
  v4403[18] = 2;
  struct StateG * v4405 = slot_258(v4396);
  return v4405;
}

struct StateG * slot_429(struct StateG * v8981) {
  int v8982 = v8981->timer;
  int v8988 = v8982 + 1;
  v8981->timer = v8988;
  int * v8984 = v8981->regs;
  v8984[17] = 10;
  struct StateG * v8986 = slot_445(v8981);
  return v8986;
}

struct StateG * slot_92(struct StateG * v1840) {
  int v1841 = v1840->timer;
  int v1847 = v1841 + 1;
  v1840->timer = v1847;
  int * v1843 = v1840->regs;
  v1843[17] = 10;
  struct StateG * v1845 = slot_100(v1840);
  return v1845;
}

struct StateG * slot_787(struct StateG * v15964) {
  int v15965 = v15964->timer;
  int v15975 = v15965 + 1;
  v15964->timer = v15975;
  int * v15967 = v15964->pht;
  int v15968 = v15967[20];
  bool v15978 = !(v15968 == 0);
  struct StateG * v15973;
  if (v15978) {
    struct StateG * v15969 = slot_814(v15964);
    v15973 = v15969;
  } else {
    struct StateG * v15971 = slot_815(v15964);
    v15973 = v15971;
  }
  return v15973;
}

struct StateG * slot_236(struct StateG * v4676) {
  int * v4677 = v4676->regs;
  int v4678 = v4677[16];
  int v4679 = v4677[17];
  bool v4699 = v4678 < v4679;
  struct StateG * v4694;
  if (v4699) {
    int * v4680 = v4676->pht;
    v4680[77] = 1;
    struct StateG * v4682 = slot_272(v4676);
    v4694 = v4682;
  } else {
    int * v4684 = v4676->pht;
    v4684[77] = 0;
    int v4686 = v4676->timer;
    int v4708 = v4686 + 15;
    v4676->timer = v4708;
    int * v4688 = v4676->saved_regs;
    int v4689 = v4688[18];
    int * v4690 = v4676->regs;
    v4690[18] = v4689;
    struct StateG * v4692 = slot_273(v4676);
    v4694 = v4692;
  }
  return v4694;
}

struct StateG * slot_703(struct StateG * v14804) {
  int v14805 = v14804->timer;
  int v14809 = v14805 + 1;
  v14804->timer = v14809;
  struct StateG * v14807 = slot_723(v14804);
  return v14807;
}

struct StateG * slot_849(struct StateG * v17703) {
  int * v17704 = v17703->regs;
  int v17705 = v17704[16];
  int v17706 = v17704[17];
  bool v17726 = v17705 >= v17706;
  struct StateG * v17721;
  if (v17726) {
    int * v17707 = v17703->pht;
    v17707[19] = 1;
    int v17709 = v17703->timer;
    int v17730 = v17709 + 15;
    v17703->timer = v17730;
    int * v17711 = v17703->saved_regs;
    int v17712 = v17711[19];
    int * v17713 = v17703->regs;
    v17713[19] = v17712;
    struct StateG * v17715 = slot_858(v17703);
    v17721 = v17715;
  } else {
    int * v17717 = v17703->pht;
    v17717[19] = 0;
    struct StateG * v17719 = slot_883(v17703);
    v17721 = v17719;
  }
  return v17721;
}

struct StateG * slot_519(struct StateG * v11324) {
  int * v11325 = v11324->regs;
  int v11326 = v11325[16];
  int v11327 = v11325[17];
  bool v11347 = v11326 < v11327;
  struct StateG * v11342;
  if (v11347) {
    int * v11328 = v11324->pht;
    v11328[96] = 1;
    int v11330 = v11324->timer;
    int v11351 = v11330 + 15;
    v11324->timer = v11351;
    int * v11332 = v11324->saved_regs;
    int v11333 = v11332[18];
    int * v11334 = v11324->regs;
    v11334[18] = v11333;
    struct StateG * v11336 = slot_550(v11324);
    v11342 = v11336;
  } else {
    int * v11338 = v11324->pht;
    v11338[96] = 0;
    struct StateG * v11340 = slot_551(v11324);
    v11342 = v11340;
  }
  return v11342;
}

struct StateG * slot_580(struct StateG * v12064) {
  int v12065 = v12064->timer;
  int v12071 = v12065 + 1;
  v12064->timer = v12071;
  int * v12067 = v12064->regs;
  v12067[1] = 156;
  struct StateG * v12069 = slot_596(v12064);
  return v12069;
}

struct StateG * slot_262(struct StateG * v5716) {
  int * v5717 = v5716->regs;
  int v5718 = v5717[16];
  int v5719 = v5717[17];
  bool v5739 = v5718 < v5719;
  struct StateG * v5734;
  if (v5739) {
    int * v5720 = v5716->pht;
    v5720[64] = 1;
    struct StateG * v5722 = slot_292(v5716);
    v5734 = v5722;
  } else {
    int * v5724 = v5716->pht;
    v5724[64] = 0;
    int v5726 = v5716->timer;
    int v5748 = v5726 + 15;
    v5716->timer = v5748;
    int * v5728 = v5716->saved_regs;
    int v5729 = v5728[18];
    int * v5730 = v5716->regs;
    v5730[18] = v5729;
    struct StateG * v5732 = slot_293(v5716);
    v5734 = v5732;
  }
  return v5734;
}

struct StateG * slot_351(struct StateG * v7120) {
  int * v7121 = v7120->saved_regs;
  int * v7122 = v7120->regs;
  int v7123 = v7122[18];
  v7121[18] = v7123;
  int v7125 = v7120->timer;
  int v7135 = v7125 + 1;
  v7120->timer = v7135;
  int * v7127 = v7120->regs;
  v7127[18] = 1;
  struct StateG * v7129 = slot_383(v7120);
  return v7129;
}

struct StateG * slot_677(struct StateG * v14443) {
  int * v14444 = v14443->regs;
  int v14445 = v14444[16];
  int v14446 = v14444[17];
  bool v14466 = v14445 < v14446;
  struct StateG * v14461;
  if (v14466) {
    int * v14447 = v14443->pht;
    v14447[1] = 1;
    int v14449 = v14443->timer;
    int v14469 = v14449 + 15;
    v14443->timer = v14469;
    int * v14451 = v14443->saved_regs;
    int v14452 = v14451[18];
    int * v14453 = v14443->regs;
    v14453[18] = v14452;
    struct StateG * v14455 = slot_706(v14443);
    v14461 = v14455;
  } else {
    int * v14457 = v14443->pht;
    v14457[1] = 0;
    struct StateG * v14459 = slot_707(v14443);
    v14461 = v14459;
  }
  return v14461;
}

struct StateG * slot_774(struct StateG * v15718) {
  int v15719 = v15718->timer;
  int v15725 = v15719 + 1;
  v15718->timer = v15725;
  int * v15721 = v15718->regs;
  v15721[17] = 10;
  struct StateG * v15723 = slot_790(v15718);
  return v15723;
}

struct StateG * slot_107(struct StateG * v2112) {
  int * v2113 = v2112->saved_regs;
  int * v2114 = v2112->regs;
  int v2115 = v2114[18];
  v2113[18] = v2115;
  int v2117 = v2112->timer;
  int v2127 = v2117 + 1;
  v2112->timer = v2127;
  int * v2119 = v2112->regs;
  v2119[18] = 1;
  struct StateG * v2121 = slot_123(v2112);
  return v2121;
}

struct StateG * slot_555(struct StateG * v11739) {
  int v11740 = v11739->timer;
  int v11746 = v11740 + 1;
  v11739->timer = v11746;
  int * v11742 = v11739->regs;
  v11742[1] = 148;
  struct StateG * v11744 = slot_571(v11739);
  return v11744;
}

struct StateG * slot_541(struct StateG * v11582) {
  int v11583 = v11582->timer;
  int v11589 = v11583 + 1;
  v11582->timer = v11589;
  int * v11585 = v11582->regs;
  v11585[18] = 1;
  struct StateG * v11587 = slot_543(v11582);
  return v11587;
}

struct StateG * slot_711(struct StateG * v14888) {
  int v14889 = v14888->timer;
  int v14893 = v14889 + 1;
  v14888->timer = v14893;
  struct StateG * v14891 = slot_727(v14888);
  return v14891;
}

struct StateG * slot_84(struct StateG * v1746) {
  int v1747 = v1746->timer;
  int v1751 = v1747 + 1;
  v1746->timer = v1751;
  struct StateG * v1749 = slot_94(v1746);
  return v1749;
}

struct StateG * slot_155(struct StateG * v3214) {
  int v3215 = v3214->timer;
  int v3219 = v3215 + 1;
  v3214->timer = v3219;
  struct StateG * v3217 = slot_177(v3214);
  return v3217;
}

struct StateG * slot_177(struct StateG * v3465) {
  int v3466 = v3465->timer;
  int v3472 = v3466 + 1;
  v3465->timer = v3472;
  int * v3468 = v3465->regs;
  v3468[17] = 10;
  struct StateG * v3470 = slot_193(v3465);
  return v3470;
}

struct StateG * slot_229(struct StateG * v4456) {
  int * v4457 = v4456->saved_regs;
  int * v4458 = v4456->regs;
  int v4459 = v4458[18];
  v4457[18] = v4459;
  int v4461 = v4456->timer;
  int v4471 = v4461 + 1;
  v4456->timer = v4471;
  int * v4463 = v4456->regs;
  v4463[18] = 1;
  struct StateG * v4465 = slot_261(v4456);
  return v4465;
}

struct StateG * slot_358(struct StateG * v7260) {
  int * v7261 = v7260->saved_regs;
  int * v7262 = v7260->regs;
  int v7263 = v7262[18];
  v7261[18] = v7263;
  int v7265 = v7260->timer;
  int v7275 = v7265 + 1;
  v7260->timer = v7275;
  int * v7267 = v7260->regs;
  v7267[18] = 2;
  struct StateG * v7269 = slot_390(v7260);
  return v7269;
}

struct StateG * slot_465(struct StateG * v9624) {
  int * v9625 = v9624->saved_regs;
  int * v9626 = v9624->regs;
  int v9627 = v9626[18];
  v9625[18] = v9627;
  int v9629 = v9624->timer;
  int v9639 = v9629 + 1;
  v9624->timer = v9639;
  int * v9631 = v9624->regs;
  v9631[18] = 1;
  struct StateG * v9633 = slot_497(v9624);
  return v9633;
}

struct StateG * slot_780(struct StateG * v15824) {
  int v15825 = v15824->timer;
  int v15835 = v15825 + 1;
  v15824->timer = v15835;
  int * v15827 = v15824->pht;
  int v15828 = v15827[27];
  bool v15838 = !(v15828 == 0);
  struct StateG * v15833;
  if (v15838) {
    struct StateG * v15829 = slot_800(v15824);
    v15833 = v15829;
  } else {
    struct StateG * v15831 = slot_801(v15824);
    v15833 = v15831;
  }
  return v15833;
}

struct StateG * slot_181(struct StateG * v3517) {
  int v3518 = v3517->timer;
  int v3524 = v3518 + 1;
  v3517->timer = v3524;
  int * v3520 = v3517->regs;
  v3520[17] = 10;
  struct StateG * v3522 = slot_197(v3517);
  return v3522;
}

struct StateG * slot_542(struct StateG * v11595) {
  int v11596 = v11595->timer;
  int v11602 = v11596 + 1;
  v11595->timer = v11602;
  int * v11598 = v11595->regs;
  v11598[18] = 2;
  struct StateG * v11600 = slot_540(v11595);
  return v11600;
}

struct StateG * slot_679(struct StateG * v14521) {
  int * v14522 = v14521->regs;
  int v14523 = v14522[16];
  int v14524 = v14522[17];
  bool v14544 = v14523 < v14524;
  struct StateG * v14539;
  if (v14544) {
    int * v14525 = v14521->pht;
    v14525[0] = 1;
    int v14527 = v14521->timer;
    int v14548 = v14527 + 15;
    v14521->timer = v14548;
    int * v14529 = v14521->saved_regs;
    int v14530 = v14529[18];
    int * v14531 = v14521->regs;
    v14531[18] = v14530;
    struct StateG * v14533 = slot_710(v14521);
    v14539 = v14533;
  } else {
    int * v14535 = v14521->pht;
    v14535[0] = 0;
    struct StateG * v14537 = slot_711(v14521);
    v14539 = v14537;
  }
  return v14539;
}

struct StateG * slot_669(struct StateG * v14124) {
  int * v14125 = v14124->regs;
  int v14126 = v14125[16];
  int v14127 = v14125[17];
  bool v14147 = v14126 < v14127;
  struct StateG * v14142;
  if (v14147) {
    int * v14128 = v14124->pht;
    v14128[5] = 1;
    int v14130 = v14124->timer;
    int v14151 = v14130 + 15;
    v14124->timer = v14151;
    int * v14132 = v14124->saved_regs;
    int v14133 = v14132[18];
    int * v14134 = v14124->regs;
    v14134[18] = v14133;
    struct StateG * v14136 = slot_690(v14124);
    v14142 = v14136;
  } else {
    int * v14138 = v14124->pht;
    v14138[5] = 0;
    struct StateG * v14140 = slot_691(v14124);
    v14142 = v14140;
  }
  return v14142;
}

struct StateG * slot_805(struct StateG * v16324) {
  int * v16325 = v16324->saved_regs;
  int * v16326 = v16324->regs;
  int v16327 = v16326[19];
  v16325[19] = v16327;
  int v16329 = v16324->timer;
  int v16339 = v16329 + 1;
  v16324->timer = v16339;
  int * v16331 = v16324->regs;
  v16331[19] = 1;
  struct StateG * v16333 = slot_837(v16324);
  return v16333;
}

struct StateG * slot_481(struct StateG * v9944) {
  int * v9945 = v9944->saved_regs;
  int * v9946 = v9944->regs;
  int v9947 = v9946[18];
  v9945[18] = v9947;
  int v9949 = v9944->timer;
  int v9959 = v9949 + 1;
  v9944->timer = v9959;
  int * v9951 = v9944->regs;
  v9951[18] = 1;
  struct StateG * v9953 = slot_513(v9944);
  return v9953;
}

struct StateG * slot_620(struct StateG * v12724) {
  int * v12725 = v12724->saved_regs;
  int * v12726 = v12724->regs;
  int v12727 = v12726[18];
  v12725[18] = v12727;
  int v12729 = v12724->timer;
  int v12739 = v12729 + 1;
  v12724->timer = v12739;
  int * v12731 = v12724->regs;
  v12731[18] = 2;
  struct StateG * v12733 = slot_652(v12724);
  return v12733;
}

struct StateG * slot_27(struct StateG * v644) {
  int * v645 = v644->saved_regs;
  int * v646 = v644->regs;
  int v647 = v646[19];
  v645[19] = v647;
  int v649 = v644->timer;
  int v659 = v649 + 1;
  v644->timer = v659;
  int * v651 = v644->regs;
  v651[19] = 1;
  struct StateG * v653 = slot_31(v644);
  return v653;
}

struct StateG * slot_818(struct StateG * v16584) {
  int * v16585 = v16584->saved_regs;
  int * v16586 = v16584->regs;
  int v16587 = v16586[19];
  v16585[19] = v16587;
  int v16589 = v16584->timer;
  int v16599 = v16589 + 1;
  v16584->timer = v16599;
  int * v16591 = v16584->regs;
  v16591[19] = 2;
  struct StateG * v16593 = slot_850(v16584);
  return v16593;
}

struct StateG * slot_454(struct StateG * v9404) {
  int v9405 = v9404->timer;
  int v9415 = v9405 + 1;
  v9404->timer = v9415;
  int * v9407 = v9404->pht;
  int v9408 = v9407[97];
  bool v9418 = !(v9408 == 0);
  struct StateG * v9413;
  if (v9418) {
    struct StateG * v9409 = slot_484(v9404);
    v9413 = v9409;
  } else {
    struct StateG * v9411 = slot_485(v9404);
    v9413 = v9411;
  }
  return v9413;
}

struct StateG * slot_830(struct StateG * v16944) {
  int * v16945 = v16944->regs;
  int v16946 = v16945[16];
  int v16947 = v16945[17];
  bool v16967 = v16946 >= v16947;
  struct StateG * v16962;
  if (v16967) {
    int * v16948 = v16944->pht;
    v16948[28] = 1;
    struct StateG * v16950 = slot_883(v16944);
    v16962 = v16950;
  } else {
    int * v16952 = v16944->pht;
    v16952[28] = 0;
    int v16954 = v16944->timer;
    int v16976 = v16954 + 15;
    v16944->timer = v16976;
    int * v16956 = v16944->saved_regs;
    int v16957 = v16956[19];
    int * v16958 = v16944->regs;
    v16958[19] = v16957;
    struct StateG * v16960 = slot_861(v16944);
    v16962 = v16960;
  }
  return v16962;
}

struct StateG * slot_482(struct StateG * v9964) {
  int * v9965 = v9964->saved_regs;
  int * v9966 = v9964->regs;
  int v9967 = v9966[18];
  v9965[18] = v9967;
  int v9969 = v9964->timer;
  int v9979 = v9969 + 1;
  v9964->timer = v9979;
  int * v9971 = v9964->regs;
  v9971[18] = 2;
  struct StateG * v9973 = slot_514(v9964);
  return v9973;
}

struct StateG * slot_689(struct StateG * v14652) {
  int v14653 = v14652->timer;
  int v14659 = v14653 + 1;
  v14652->timer = v14659;
  int * v14655 = v14652->regs;
  v14655[18] = 1;
  struct StateG * v14657 = slot_691(v14652);
  return v14657;
}

struct StateG * slot_406(struct StateG * v8727) {
  int v8728 = v8727->timer;
  int v8734 = v8728 + 1;
  v8727->timer = v8734;
  int * v8730 = v8727->regs;
  v8730[18] = 2;
  struct StateG * v8732 = slot_404(v8727);
  return v8732;
}

struct StateG * slot_292(struct StateG * v6090) {
  int v6091 = v6090->timer;
  int v6095 = v6091 + 1;
  v6090->timer = v6095;
  struct StateG * v6093 = slot_310(v6090);
  return v6093;
}

struct StateG * slot_776(struct StateG * v15744) {
  int v15745 = v15744->timer;
  int v15755 = v15745 + 1;
  v15744->timer = v15755;
  int * v15747 = v15744->pht;
  int v15748 = v15747[31];
  bool v15758 = !(v15748 == 0);
  struct StateG * v15753;
  if (v15758) {
    struct StateG * v15749 = slot_792(v15744);
    v15753 = v15749;
  } else {
    struct StateG * v15751 = slot_793(v15744);
    v15753 = v15751;
  }
  return v15753;
}

struct StateG * slot_525(struct StateG * v11414) {
  int v11415 = v11414->timer;
  int v11421 = v11415 + 1;
  v11414->timer = v11421;
  int * v11417 = v11414->regs;
  v11417[18] = 1;
  struct StateG * v11419 = slot_527(v11414);
  return v11419;
}

struct StateG * slot_666(struct StateG * v14004) {
  int * v14005 = v14004->regs;
  int v14006 = v14005[16];
  int v14007 = v14005[17];
  bool v14027 = v14006 < v14007;
  struct StateG * v14022;
  if (v14027) {
    int * v14008 = v14004->pht;
    v14008[6] = 1;
    struct StateG * v14010 = slot_684(v14004);
    v14022 = v14010;
  } else {
    int * v14012 = v14004->pht;
    v14012[6] = 0;
    int v14014 = v14004->timer;
    int v14036 = v14014 + 15;
    v14004->timer = v14036;
    int * v14016 = v14004->saved_regs;
    int v14017 = v14016[18];
    int * v14018 = v14004->regs;
    v14018[18] = v14017;
    struct StateG * v14020 = slot_685(v14004);
    v14022 = v14020;
  }
  return v14022;
}

struct StateG * slot_589(struct StateG * v12181) {
  int v12182 = v12181->timer;
  int v12188 = v12182 + 1;
  v12181->timer = v12188;
  int * v12184 = v12181->regs;
  v12184[17] = 10;
  struct StateG * v12186 = slot_605(v12181);
  return v12186;
}

struct StateG * slot_94(struct StateG * v1866) {
  int v1867 = v1866->timer;
  int v1873 = v1867 + 1;
  v1866->timer = v1873;
  int * v1869 = v1866->regs;
  v1869[17] = 10;
  struct StateG * v1871 = slot_102(v1866);
  return v1871;
}

struct StateG * slot_340(struct StateG * v6900) {
  int * v6901 = v6900->saved_regs;
  int * v6902 = v6900->regs;
  int v6903 = v6902[18];
  v6901[18] = v6903;
  int v6905 = v6900->timer;
  int v6915 = v6905 + 1;
  v6900->timer = v6915;
  int * v6907 = v6900->regs;
  v6907[18] = 2;
  struct StateG * v6909 = slot_372(v6900);
  return v6909;
}

struct StateG * slot_846(struct StateG * v17584) {
  int * v17585 = v17584->regs;
  int v17586 = v17585[16];
  int v17587 = v17585[17];
  bool v17607 = v17586 >= v17587;
  struct StateG * v17602;
  if (v17607) {
    int * v17588 = v17584->pht;
    v17588[20] = 1;
    struct StateG * v17590 = slot_883(v17584);
    v17602 = v17590;
  } else {
    int * v17592 = v17584->pht;
    v17592[20] = 0;
    int v17594 = v17584->timer;
    int v17616 = v17594 + 15;
    v17584->timer = v17616;
    int * v17596 = v17584->saved_regs;
    int v17597 = v17596[19];
    int * v17598 = v17584->regs;
    v17598[19] = v17597;
    struct StateG * v17600 = slot_861(v17584);
    v17602 = v17600;
  }
  return v17602;
}

struct StateG * slot_24(struct StateG * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[19];
  v585[19] = v587;
  int v589 = v584->timer;
  int v599 = v589 + 1;
  v584->timer = v599;
  int * v591 = v584->regs;
  v591[19] = 2;
  struct StateG * v593 = slot_28(v584);
  return v593;
}

struct StateG * slot_673(struct StateG * v14284) {
  int * v14285 = v14284->regs;
  int v14286 = v14285[16];
  int v14287 = v14285[17];
  bool v14307 = v14286 < v14287;
  struct StateG * v14302;
  if (v14307) {
    int * v14288 = v14284->pht;
    v14288[3] = 1;
    int v14290 = v14284->timer;
    int v14311 = v14290 + 15;
    v14284->timer = v14311;
    int * v14292 = v14284->saved_regs;
    int v14293 = v14292[18];
    int * v14294 = v14284->regs;
    v14294[18] = v14293;
    struct StateG * v14296 = slot_698(v14284);
    v14302 = v14296;
  } else {
    int * v14298 = v14284->pht;
    v14298[3] = 0;
    struct StateG * v14300 = slot_699(v14284);
    v14302 = v14300;
  }
  return v14302;
}

struct StateG * slot_286(struct StateG * v6027) {
  int v6028 = v6027->timer;
  int v6034 = v6028 + 1;
  v6027->timer = v6034;
  int * v6030 = v6027->regs;
  v6030[18] = 2;
  struct StateG * v6032 = slot_284(v6027);
  return v6032;
}

struct StateG * slot_520(struct StateG * v11364) {
  int v11365 = v11364->timer;
  int v11369 = v11365 + 1;
  v11364->timer = v11369;
  struct StateG * v11367 = slot_552(v11364);
  return v11367;
}

struct StateG * slot_125(struct StateG * v2572) {
  int * v2573 = v2572->regs;
  int v2574 = v2573[16];
  int v2575 = v2573[17];
  bool v2595 = v2574 < v2575;
  struct StateG * v2590;
  if (v2595) {
    int * v2576 = v2572->pht;
    v2576[53] = 1;
    int v2578 = v2572->timer;
    int v2599 = v2578 + 15;
    v2572->timer = v2599;
    int * v2580 = v2572->saved_regs;
    int v2581 = v2580[18];
    int * v2582 = v2572->regs;
    v2582[18] = v2581;
    struct StateG * v2584 = slot_146(v2572);
    v2590 = v2584;
  } else {
    int * v2586 = v2572->pht;
    v2586[53] = 0;
    struct StateG * v2588 = slot_147(v2572);
    v2590 = v2588;
  }
  return v2590;
}

struct StateG * slot_726(struct StateG * v15092) {
  int v15093 = v15092->timer;
  int v15100 = v15093 + 1;
  v15092->timer = v15100;
  int * v15095 = v15092->regs;
  int v15096 = v15095[1];
  bool v15103 = v15096 == 156;
  ret_assert(v15103);
  struct StateG * v15098 = slot_742(v15092);
  return v15098;
}

struct StateG * slot_254(struct StateG * v5396) {
  int * v5397 = v5396->regs;
  int v5398 = v5397[16];
  int v5399 = v5397[17];
  bool v5419 = v5398 < v5399;
  struct StateG * v5414;
  if (v5419) {
    int * v5400 = v5396->pht;
    v5400[68] = 1;
    struct StateG * v5402 = slot_276(v5396);
    v5414 = v5402;
  } else {
    int * v5404 = v5396->pht;
    v5404[68] = 0;
    int v5406 = v5396->timer;
    int v5428 = v5406 + 15;
    v5396->timer = v5428;
    int * v5408 = v5396->saved_regs;
    int v5409 = v5408[18];
    int * v5410 = v5396->regs;
    v5410[18] = v5409;
    struct StateG * v5412 = slot_277(v5396);
    v5414 = v5412;
  }
  return v5414;
}

struct StateG * slot_126(struct StateG * v2612) {
  int * v2613 = v2612->regs;
  int v2614 = v2613[16];
  int v2615 = v2613[17];
  bool v2635 = v2614 < v2615;
  struct StateG * v2630;
  if (v2635) {
    int * v2616 = v2612->pht;
    v2616[52] = 1;
    struct StateG * v2618 = slot_148(v2612);
    v2630 = v2618;
  } else {
    int * v2620 = v2612->pht;
    v2620[52] = 0;
    int v2622 = v2612->timer;
    int v2644 = v2622 + 15;
    v2612->timer = v2644;
    int * v2624 = v2612->saved_regs;
    int v2625 = v2624[18];
    int * v2626 = v2612->regs;
    v2626[18] = v2625;
    struct StateG * v2628 = slot_149(v2612);
    v2630 = v2628;
  }
  return v2630;
}

struct StateG * slot_363(struct StateG * v7420) {
  int * v7421 = v7420->regs;
  int v7422 = v7421[16];
  int v7423 = v7421[17];
  bool v7443 = v7422 < v7423;
  struct StateG * v7438;
  if (v7443) {
    int * v7424 = v7420->pht;
    v7424[94] = 1;
    int v7426 = v7420->timer;
    int v7447 = v7426 + 15;
    v7420->timer = v7447;
    int * v7428 = v7420->saved_regs;
    int v7429 = v7428[18];
    int * v7430 = v7420->regs;
    v7430[18] = v7429;
    struct StateG * v7432 = slot_398(v7420);
    v7438 = v7432;
  } else {
    int * v7434 = v7420->pht;
    v7434[94] = 0;
    struct StateG * v7436 = slot_399(v7420);
    v7438 = v7436;
  }
  return v7438;
}

struct StateG * slot_816(struct StateG * v16544) {
  int * v16545 = v16544->saved_regs;
  int * v16546 = v16544->regs;
  int v16547 = v16546[19];
  v16545[19] = v16547;
  int v16549 = v16544->timer;
  int v16559 = v16549 + 1;
  v16544->timer = v16559;
  int * v16551 = v16544->regs;
  v16551[19] = 2;
  struct StateG * v16553 = slot_848(v16544);
  return v16553;
}

struct StateG * slot_578(struct StateG * v12038) {
  int v12039 = v12038->timer;
  int v12045 = v12039 + 1;
  v12038->timer = v12045;
  int * v12041 = v12038->regs;
  v12041[1] = 156;
  struct StateG * v12043 = slot_594(v12038);
  return v12043;
}

struct StateG * slot_661(struct StateG * v13804) {
  int * v13805 = v13804->regs;
  int v13806 = v13805[16];
  int v13807 = v13805[17];
  bool v13827 = v13806 < v13807;
  struct StateG * v13822;
  if (v13827) {
    int * v13808 = v13804->pht;
    v13808[9] = 1;
    int v13810 = v13804->timer;
    int v13831 = v13810 + 15;
    v13804->timer = v13831;
    int * v13812 = v13804->saved_regs;
    int v13813 = v13812[18];
    int * v13814 = v13804->regs;
    v13814[18] = v13813;
    struct StateG * v13816 = slot_706(v13804);
    v13822 = v13816;
  } else {
    int * v13818 = v13804->pht;
    v13818[9] = 0;
    struct StateG * v13820 = slot_707(v13804);
    v13822 = v13820;
  }
  return v13822;
}

struct StateG * slot_842(struct StateG * v17424) {
  int * v17425 = v17424->regs;
  int v17426 = v17425[16];
  int v17427 = v17425[17];
  bool v17447 = v17426 >= v17427;
  struct StateG * v17442;
  if (v17447) {
    int * v17428 = v17424->pht;
    v17428[22] = 1;
    struct StateG * v17430 = slot_883(v17424);
    v17442 = v17430;
  } else {
    int * v17432 = v17424->pht;
    v17432[22] = 0;
    int v17434 = v17424->timer;
    int v17456 = v17434 + 15;
    v17424->timer = v17456;
    int * v17436 = v17424->saved_regs;
    int v17437 = v17436[19];
    int * v17438 = v17424->regs;
    v17438[19] = v17437;
    struct StateG * v17440 = slot_861(v17424);
    v17442 = v17440;
  }
  return v17442;
}

struct StateG * slot_732(struct StateG * v15172) {
  int v15173 = v15172->timer;
  int v15179 = v15173 + 1;
  v15172->timer = v15179;
  int * v15175 = v15172->regs;
  v15175[1] = 156;
  struct StateG * v15177 = slot_748(v15172);
  return v15177;
}

struct StateG * slot_367(struct StateG * v7580) {
  int * v7581 = v7580->regs;
  int v7582 = v7581[16];
  int v7583 = v7581[17];
  bool v7603 = v7582 < v7583;
  struct StateG * v7598;
  if (v7603) {
    int * v7584 = v7580->pht;
    v7584[92] = 1;
    int v7586 = v7580->timer;
    int v7607 = v7586 + 15;
    v7580->timer = v7607;
    int * v7588 = v7580->saved_regs;
    int v7589 = v7588[18];
    int * v7590 = v7580->regs;
    v7590[18] = v7589;
    struct StateG * v7592 = slot_406(v7580);
    v7598 = v7592;
  } else {
    int * v7594 = v7580->pht;
    v7594[92] = 0;
    struct StateG * v7596 = slot_407(v7580);
    v7598 = v7596;
  }
  return v7598;
}

struct StateG * slot_437(struct StateG * v9085) {
  int v9086 = v9085->timer;
  int v9092 = v9086 + 1;
  v9085->timer = v9092;
  int * v9088 = v9085->regs;
  v9088[17] = 10;
  struct StateG * v9090 = slot_453(v9085);
  return v9090;
}

struct StateG * slot_724(struct StateG * v15064) {
  int v15065 = v15064->timer;
  int v15072 = v15065 + 1;
  v15064->timer = v15072;
  int * v15067 = v15064->regs;
  int v15068 = v15067[1];
  bool v15075 = v15068 == 156;
  ret_assert(v15075);
  struct StateG * v15070 = slot_740(v15064);
  return v15070;
}

struct StateG * slot_341(struct StateG * v6920) {
  int * v6921 = v6920->saved_regs;
  int * v6922 = v6920->regs;
  int v6923 = v6922[18];
  v6921[18] = v6923;
  int v6925 = v6920->timer;
  int v6935 = v6925 + 1;
  v6920->timer = v6935;
  int * v6927 = v6920->regs;
  v6927[18] = 1;
  struct StateG * v6929 = slot_373(v6920);
  return v6929;
}

struct StateG * slot_280(struct StateG * v5964) {
  int v5965 = v5964->timer;
  int v5969 = v5965 + 1;
  v5964->timer = v5969;
  struct StateG * v5967 = slot_304(v5964);
  return v5967;
}

struct StateG * slot_779(struct StateG * v15804) {
  int v15805 = v15804->timer;
  int v15815 = v15805 + 1;
  v15804->timer = v15815;
  int * v15807 = v15804->pht;
  int v15808 = v15807[28];
  bool v15818 = !(v15808 == 0);
  struct StateG * v15813;
  if (v15818) {
    struct StateG * v15809 = slot_798(v15804);
    v15813 = v15809;
  } else {
    struct StateG * v15811 = slot_799(v15804);
    v15813 = v15811;
  }
  return v15813;
}

struct StateG * slot_272(struct StateG * v5880) {
  int v5881 = v5880->timer;
  int v5885 = v5881 + 1;
  v5880->timer = v5885;
  struct StateG * v5883 = slot_300(v5880);
  return v5883;
}

struct StateG * slot_47(struct StateG * v995) {
  int v996 = v995->timer;
  int v1002 = v996 + 1;
  v995->timer = v1002;
  int * v998 = v995->regs;
  v998[16] = 20;
  struct StateG * v1000 = slot_51(v995);
  return v1000;
}

struct StateG * slot_297(struct StateG * v6145) {
  int v6146 = v6145->timer;
  int v6152 = v6146 + 1;
  v6145->timer = v6152;
  int * v6148 = v6145->regs;
  v6148[17] = 10;
  struct StateG * v6150 = slot_313(v6145);
  return v6150;
}

struct StateG * slot_715(struct StateG * v14938) {
  int v14939 = v14938->timer;
  int v14946 = v14939 + 1;
  v14938->timer = v14946;
  int * v14941 = v14938->regs;
  int v14942 = v14941[1];
  bool v14949 = v14942 == 156;
  ret_assert(v14949);
  struct StateG * v14944 = slot_731(v14938);
  return v14944;
}

struct StateG * slot_314(struct StateG * v6380) {
  int v6381 = v6380->timer;
  int v6391 = v6381 + 1;
  v6380->timer = v6391;
  int * v6383 = v6380->pht;
  int v6384 = v6383[93];
  bool v6394 = !(v6384 == 0);
  struct StateG * v6389;
  if (v6394) {
    struct StateG * v6385 = slot_332(v6380);
    v6389 = v6385;
  } else {
    struct StateG * v6387 = slot_333(v6380);
    v6389 = v6387;
  }
  return v6389;
}

struct StateG * slot_638(struct StateG * v13084) {
  int * v13085 = v13084->saved_regs;
  int * v13086 = v13084->regs;
  int v13087 = v13086[18];
  v13085[18] = v13087;
  int v13089 = v13084->timer;
  int v13099 = v13089 + 1;
  v13084->timer = v13099;
  int * v13091 = v13084->regs;
  v13091[18] = 2;
  struct StateG * v13093 = slot_670(v13084);
  return v13093;
}

struct StateG * slot_441(struct StateG * v9144) {
  int v9145 = v9144->timer;
  int v9155 = v9145 + 1;
  v9144->timer = v9155;
  int * v9147 = v9144->pht;
  int v9148 = v9147[110];
  bool v9158 = !(v9148 == 0);
  struct StateG * v9153;
  if (v9158) {
    struct StateG * v9149 = slot_458(v9144);
    v9153 = v9149;
  } else {
    struct StateG * v9151 = slot_459(v9144);
    v9153 = v9151;
  }
  return v9153;
}

struct StateG * slot_19(struct StateG * v505) {
  int v506 = v505->timer;
  int v512 = v506 + 1;
  v505->timer = v512;
  int * v508 = v505->regs;
  v508[1] = 24;
  struct StateG * v510 = slot_21(v505);
  return v510;
}

struct StateG * slot_382(struct StateG * v8180) {
  int * v8181 = v8180->regs;
  int v8182 = v8181[16];
  int v8183 = v8181[17];
  bool v8203 = v8182 < v8183;
  struct StateG * v8198;
  if (v8203) {
    int * v8184 = v8180->pht;
    v8184[84] = 1;
    struct StateG * v8186 = slot_404(v8180);
    v8198 = v8186;
  } else {
    int * v8188 = v8180->pht;
    v8188[84] = 0;
    int v8190 = v8180->timer;
    int v8212 = v8190 + 15;
    v8180->timer = v8212;
    int * v8192 = v8180->saved_regs;
    int v8193 = v8192[18];
    int * v8194 = v8180->regs;
    v8194[18] = v8193;
    struct StateG * v8196 = slot_405(v8180);
    v8198 = v8196;
  }
  return v8198;
}

struct StateG * slot_556(struct StateG * v11752) {
  int v11753 = v11752->timer;
  int v11759 = v11753 + 1;
  v11752->timer = v11759;
  int * v11755 = v11752->regs;
  v11755[1] = 148;
  struct StateG * v11757 = slot_572(v11752);
  return v11757;
}

struct StateG * slot_651(struct StateG * v13404) {
  int * v13405 = v13404->regs;
  int v13406 = v13405[16];
  int v13407 = v13405[17];
  bool v13427 = v13406 < v13407;
  struct StateG * v13422;
  if (v13427) {
    int * v13408 = v13404->pht;
    v13408[14] = 1;
    int v13410 = v13404->timer;
    int v13431 = v13410 + 15;
    v13404->timer = v13431;
    int * v13412 = v13404->saved_regs;
    int v13413 = v13412[18];
    int * v13414 = v13404->regs;
    v13414[18] = v13413;
    struct StateG * v13416 = slot_686(v13404);
    v13422 = v13416;
  } else {
    int * v13418 = v13404->pht;
    v13418[14] = 0;
    struct StateG * v13420 = slot_687(v13404);
    v13422 = v13420;
  }
  return v13422;
}

struct StateG * slot_337(struct StateG * v6840) {
  int * v6841 = v6840->saved_regs;
  int * v6842 = v6840->regs;
  int v6843 = v6842[18];
  v6841[18] = v6843;
  int v6845 = v6840->timer;
  int v6855 = v6845 + 1;
  v6840->timer = v6855;
  int * v6847 = v6840->regs;
  v6847[18] = 1;
  struct StateG * v6849 = slot_369(v6840);
  return v6849;
}

struct StateG * slot_233(struct StateG * v4556) {
  int * v4557 = v4556->regs;
  int v4558 = v4557[16];
  int v4559 = v4557[17];
  bool v4579 = v4558 < v4559;
  struct StateG * v4574;
  if (v4579) {
    int * v4560 = v4556->pht;
    v4560[79] = 1;
    int v4562 = v4556->timer;
    int v4583 = v4562 + 15;
    v4556->timer = v4583;
    int * v4564 = v4556->saved_regs;
    int v4565 = v4564[18];
    int * v4566 = v4556->regs;
    v4566[18] = v4565;
    struct StateG * v4568 = slot_266(v4556);
    v4574 = v4568;
  } else {
    int * v4570 = v4556->pht;
    v4570[79] = 0;
    struct StateG * v4572 = slot_267(v4556);
    v4574 = v4572;
  }
  return v4574;
}

struct StateG * slot_595(struct StateG * v12259) {
  int v12260 = v12259->timer;
  int v12266 = v12260 + 1;
  v12259->timer = v12266;
  int * v12262 = v12259->regs;
  v12262[17] = 10;
  struct StateG * v12264 = slot_611(v12259);
  return v12264;
}

struct StateG * slot_176(struct StateG * v3452) {
  int v3453 = v3452->timer;
  int v3459 = v3453 + 1;
  v3452->timer = v3459;
  int * v3455 = v3452->regs;
  v3455[17] = 10;
  struct StateG * v3457 = slot_192(v3452);
  return v3457;
}

struct StateG * slot_398(struct StateG * v8643) {
  int v8644 = v8643->timer;
  int v8650 = v8644 + 1;
  v8643->timer = v8650;
  int * v8646 = v8643->regs;
  v8646[18] = 2;
  struct StateG * v8648 = slot_396(v8643);
  return v8648;
}

struct StateG * slot_330(struct StateG * v6700) {
  int * v6701 = v6700->saved_regs;
  int * v6702 = v6700->regs;
  int v6703 = v6702[18];
  v6701[18] = v6703;
  int v6705 = v6700->timer;
  int v6715 = v6705 + 1;
  v6700->timer = v6715;
  int * v6707 = v6700->regs;
  v6707[18] = 2;
  struct StateG * v6709 = slot_362(v6700);
  return v6709;
}

struct StateG * slot_450(struct StateG * v9324) {
  int v9325 = v9324->timer;
  int v9335 = v9325 + 1;
  v9324->timer = v9335;
  int * v9327 = v9324->pht;
  int v9328 = v9327[101];
  bool v9338 = !(v9328 == 0);
  struct StateG * v9333;
  if (v9338) {
    struct StateG * v9329 = slot_476(v9324);
    v9333 = v9329;
  } else {
    struct StateG * v9331 = slot_477(v9324);
    v9333 = v9331;
  }
  return v9333;
}

struct StateG * slot_713(struct StateG * v14910) {
  int v14911 = v14910->timer;
  int v14918 = v14911 + 1;
  v14910->timer = v14918;
  int * v14913 = v14910->regs;
  int v14914 = v14913[1];
  bool v14921 = v14914 == 156;
  ret_assert(v14921);
  struct StateG * v14916 = slot_729(v14910);
  return v14916;
}

struct StateG * slot_819(struct StateG * v16604) {
  int * v16605 = v16604->saved_regs;
  int * v16606 = v16604->regs;
  int v16607 = v16606[19];
  v16605[19] = v16607;
  int v16609 = v16604->timer;
  int v16619 = v16609 + 1;
  v16604->timer = v16619;
  int * v16611 = v16604->regs;
  v16611[19] = 1;
  struct StateG * v16613 = slot_851(v16604);
  return v16613;
}

struct StateG * slot_166(struct StateG * v3327) {
  int v3328 = v3327->timer;
  int v3334 = v3328 + 1;
  v3327->timer = v3334;
  int * v3330 = v3327->regs;
  v3330[18] = 2;
  struct StateG * v3332 = slot_164(v3327);
  return v3332;
}

struct StateG * slot_418(struct StateG * v8853) {
  int v8854 = v8853->timer;
  int v8860 = v8854 + 1;
  v8853->timer = v8860;
  int * v8856 = v8853->regs;
  v8856[18] = 2;
  struct StateG * v8858 = slot_416(v8853);
  return v8858;
}

struct StateG * slot_264(struct StateG * v5796) {
  int v5797 = v5796->timer;
  int v5801 = v5797 + 1;
  v5796->timer = v5801;
  struct StateG * v5799 = slot_296(v5796);
  return v5799;
}

struct StateG * slot_339(struct StateG * v6880) {
  int * v6881 = v6880->saved_regs;
  int * v6882 = v6880->regs;
  int v6883 = v6882[18];
  v6881[18] = v6883;
  int v6885 = v6880->timer;
  int v6895 = v6885 + 1;
  v6880->timer = v6895;
  int * v6887 = v6880->regs;
  v6887[18] = 1;
  struct StateG * v6889 = slot_371(v6880);
  return v6889;
}

struct StateG * slot_811(struct StateG * v16444) {
  int * v16445 = v16444->saved_regs;
  int * v16446 = v16444->regs;
  int v16447 = v16446[19];
  v16445[19] = v16447;
  int v16449 = v16444->timer;
  int v16459 = v16449 + 1;
  v16444->timer = v16459;
  int * v16451 = v16444->regs;
  v16451[19] = 1;
  struct StateG * v16453 = slot_843(v16444);
  return v16453;
}

struct StateG * slot_97(struct StateG * v1912) {
  int v1913 = v1912->timer;
  int v1923 = v1913 + 1;
  v1912->timer = v1923;
  int * v1915 = v1912->pht;
  int v1916 = v1915[54];
  bool v1926 = !(v1916 == 0);
  struct StateG * v1921;
  if (v1926) {
    struct StateG * v1917 = slot_106(v1912);
    v1921 = v1917;
  } else {
    struct StateG * v1919 = slot_107(v1912);
    v1921 = v1919;
  }
  return v1921;
}

struct StateG * slot_594(struct StateG * v12246) {
  int v12247 = v12246->timer;
  int v12253 = v12247 + 1;
  v12246->timer = v12253;
  int * v12249 = v12246->regs;
  v12249[17] = 10;
  struct StateG * v12251 = slot_610(v12246);
  return v12251;
}

struct StateG * slot_106(struct StateG * v2092) {
  int * v2093 = v2092->saved_regs;
  int * v2094 = v2092->regs;
  int v2095 = v2094[18];
  v2093[18] = v2095;
  int v2097 = v2092->timer;
  int v2107 = v2097 + 1;
  v2092->timer = v2107;
  int * v2099 = v2092->regs;
  v2099[18] = 2;
  struct StateG * v2101 = slot_122(v2092);
  return v2101;
}

struct StateG * slot_809(struct StateG * v16404) {
  int * v16405 = v16404->saved_regs;
  int * v16406 = v16404->regs;
  int v16407 = v16406[19];
  v16405[19] = v16407;
  int v16409 = v16404->timer;
  int v16419 = v16409 + 1;
  v16404->timer = v16419;
  int * v16411 = v16404->regs;
  v16411[19] = 1;
  struct StateG * v16413 = slot_841(v16404);
  return v16413;
}

struct StateG * slot_513(struct StateG * v11084) {
  int * v11085 = v11084->regs;
  int v11086 = v11085[16];
  int v11087 = v11085[17];
  bool v11107 = v11086 < v11087;
  struct StateG * v11102;
  if (v11107) {
    int * v11088 = v11084->pht;
    v11088[99] = 1;
    int v11090 = v11084->timer;
    int v11111 = v11090 + 15;
    v11084->timer = v11111;
    int * v11092 = v11084->saved_regs;
    int v11093 = v11092[18];
    int * v11094 = v11084->regs;
    v11094[18] = v11093;
    struct StateG * v11096 = slot_538(v11084);
    v11102 = v11096;
  } else {
    int * v11098 = v11084->pht;
    v11098[99] = 0;
    struct StateG * v11100 = slot_539(v11084);
    v11102 = v11100;
  }
  return v11102;
}

struct StateG * slot_130(struct StateG * v2772) {
  int * v2773 = v2772->regs;
  int v2774 = v2773[16];
  int v2775 = v2773[17];
  bool v2795 = v2774 < v2775;
  struct StateG * v2790;
  if (v2795) {
    int * v2776 = v2772->pht;
    v2776[50] = 1;
    struct StateG * v2778 = slot_156(v2772);
    v2790 = v2778;
  } else {
    int * v2780 = v2772->pht;
    v2780[50] = 0;
    int v2782 = v2772->timer;
    int v2804 = v2782 + 15;
    v2772->timer = v2804;
    int * v2784 = v2772->saved_regs;
    int v2785 = v2784[18];
    int * v2786 = v2772->regs;
    v2786[18] = v2785;
    struct StateG * v2788 = slot_157(v2772);
    v2790 = v2788;
  }
  return v2790;
}

struct StateG * slot_141(struct StateG * v3062) {
  int v3063 = v3062->timer;
  int v3069 = v3063 + 1;
  v3062->timer = v3069;
  int * v3065 = v3062->regs;
  v3065[18] = 1;
  struct StateG * v3067 = slot_143(v3062);
  return v3067;
}

struct StateG * slot_701(struct StateG * v14778) {
  int v14779 = v14778->timer;
  int v14785 = v14779 + 1;
  v14778->timer = v14785;
  int * v14781 = v14778->regs;
  v14781[18] = 1;
  struct StateG * v14783 = slot_703(v14778);
  return v14783;
}

struct StateG * slot_432(struct StateG * v9020) {
  int v9021 = v9020->timer;
  int v9027 = v9021 + 1;
  v9020->timer = v9027;
  int * v9023 = v9020->regs;
  v9023[17] = 10;
  struct StateG * v9025 = slot_448(v9020);
  return v9025;
}

struct StateG * slot_306(struct StateG * v6262) {
  int v6263 = v6262->timer;
  int v6269 = v6263 + 1;
  v6262->timer = v6269;
  int * v6265 = v6262->regs;
  v6265[17] = 10;
  struct StateG * v6267 = slot_322(v6262);
  return v6267;
}

struct StateG * slot_312(struct StateG * v6340) {
  int v6341 = v6340->timer;
  int v6351 = v6341 + 1;
  v6340->timer = v6351;
  int * v6343 = v6340->pht;
  int v6344 = v6343[95];
  bool v6354 = !(v6344 == 0);
  struct StateG * v6349;
  if (v6354) {
    struct StateG * v6345 = slot_328(v6340);
    v6349 = v6345;
  } else {
    struct StateG * v6347 = slot_329(v6340);
    v6349 = v6347;
  }
  return v6349;
}

struct StateG * slot_4(struct StateG * v245) {
  int v246 = v245->timer;
  int v252 = v246 + 1;
  v245->timer = v252;
  int * v248 = v245->regs;
  v248[17] = 10;
  struct StateG * v250 = slot_5(v245);
  return v250;
}

struct StateG * slot_705(struct StateG * v14820) {
  int v14821 = v14820->timer;
  int v14827 = v14821 + 1;
  v14820->timer = v14827;
  int * v14823 = v14820->regs;
  v14823[18] = 1;
  struct StateG * v14825 = slot_707(v14820);
  return v14825;
}

struct StateG * slot_247(struct StateG * v5116) {
  int * v5117 = v5116->regs;
  int v5118 = v5117[16];
  int v5119 = v5117[17];
  bool v5139 = v5118 < v5119;
  struct StateG * v5134;
  if (v5139) {
    int * v5120 = v5116->pht;
    v5120[72] = 1;
    int v5122 = v5116->timer;
    int v5143 = v5122 + 15;
    v5116->timer = v5143;
    int * v5124 = v5116->saved_regs;
    int v5125 = v5124[18];
    int * v5126 = v5116->regs;
    v5126[18] = v5125;
    struct StateG * v5128 = slot_294(v5116);
    v5134 = v5128;
  } else {
    int * v5130 = v5116->pht;
    v5130[72] = 0;
    struct StateG * v5132 = slot_295(v5116);
    v5134 = v5132;
  }
  return v5134;
}

struct StateG * slot_168(struct StateG * v3348) {
  int v3349 = v3348->timer;
  int v3355 = v3349 + 1;
  v3348->timer = v3355;
  int * v3351 = v3348->regs;
  v3351[17] = 10;
  struct StateG * v3353 = slot_184(v3348);
  return v3353;
}

struct StateG * slot_456(struct StateG * v9444) {
  int * v9445 = v9444->saved_regs;
  int * v9446 = v9444->regs;
  int v9447 = v9446[18];
  v9445[18] = v9447;
  int v9449 = v9444->timer;
  int v9459 = v9449 + 1;
  v9444->timer = v9459;
  int * v9451 = v9444->regs;
  v9451[18] = 2;
  struct StateG * v9453 = slot_488(v9444);
  return v9453;
}

struct StateG * slot_225(struct StateG * v4376) {
  int * v4377 = v4376->saved_regs;
  int * v4378 = v4376->regs;
  int v4379 = v4378[18];
  v4377[18] = v4379;
  int v4381 = v4376->timer;
  int v4391 = v4381 + 1;
  v4376->timer = v4391;
  int * v4383 = v4376->regs;
  v4383[18] = 1;
  struct StateG * v4385 = slot_257(v4376);
  return v4385;
}

struct StateG * slot_285(struct StateG * v6014) {
  int v6015 = v6014->timer;
  int v6021 = v6015 + 1;
  v6014->timer = v6021;
  int * v6017 = v6014->regs;
  v6017[18] = 1;
  struct StateG * v6019 = slot_287(v6014);
  return v6019;
}

struct StateG * slot_659(struct StateG * v13724) {
  int * v13725 = v13724->regs;
  int v13726 = v13725[16];
  int v13727 = v13725[17];
  bool v13747 = v13726 < v13727;
  struct StateG * v13742;
  if (v13747) {
    int * v13728 = v13724->pht;
    v13728[10] = 1;
    int v13730 = v13724->timer;
    int v13751 = v13730 + 15;
    v13724->timer = v13751;
    int * v13732 = v13724->saved_regs;
    int v13733 = v13732[18];
    int * v13734 = v13724->regs;
    v13734[18] = v13733;
    struct StateG * v13736 = slot_702(v13724);
    v13742 = v13736;
  } else {
    int * v13738 = v13724->pht;
    v13738[10] = 0;
    struct StateG * v13740 = slot_703(v13724);
    v13742 = v13740;
  }
  return v13742;
}

struct StateG * slot_213(struct StateG * v4136) {
  int * v4137 = v4136->saved_regs;
  int * v4138 = v4136->regs;
  int v4139 = v4138[18];
  v4137[18] = v4139;
  int v4141 = v4136->timer;
  int v4151 = v4141 + 1;
  v4136->timer = v4151;
  int * v4143 = v4136->regs;
  v4143[18] = 1;
  struct StateG * v4145 = slot_245(v4136);
  return v4145;
}

struct StateG * slot_82(struct StateG * v1725) {
  int v1726 = v1725->timer;
  int v1732 = v1726 + 1;
  v1725->timer = v1732;
  int * v1728 = v1725->regs;
  v1728[18] = 2;
  struct StateG * v1730 = slot_80(v1725);
  return v1730;
}

struct StateG * slot_632(struct StateG * v12964) {
  int * v12965 = v12964->saved_regs;
  int * v12966 = v12964->regs;
  int v12967 = v12966[18];
  v12965[18] = v12967;
  int v12969 = v12964->timer;
  int v12979 = v12969 + 1;
  v12964->timer = v12979;
  int * v12971 = v12964->regs;
  v12971[18] = 2;
  struct StateG * v12973 = slot_664(v12964);
  return v12973;
}

struct StateG * slot_642(struct StateG * v13164) {
  int * v13165 = v13164->saved_regs;
  int * v13166 = v13164->regs;
  int v13167 = v13166[18];
  v13165[18] = v13167;
  int v13169 = v13164->timer;
  int v13179 = v13169 + 1;
  v13164->timer = v13179;
  int * v13171 = v13164->regs;
  v13171[18] = 2;
  struct StateG * v13173 = slot_674(v13164);
  return v13173;
}

struct StateG * slot_691(struct StateG * v14678) {
  int v14679 = v14678->timer;
  int v14683 = v14679 + 1;
  v14678->timer = v14683;
  struct StateG * v14681 = slot_717(v14678);
  return v14681;
}

struct StateG * slot_590(struct StateG * v12194) {
  int v12195 = v12194->timer;
  int v12201 = v12195 + 1;
  v12194->timer = v12201;
  int * v12197 = v12194->regs;
  v12197[17] = 10;
  struct StateG * v12199 = slot_606(v12194);
  return v12199;
}

struct StateG * slot_263(struct StateG * v5756) {
  int * v5757 = v5756->regs;
  int v5758 = v5757[16];
  int v5759 = v5757[17];
  bool v5779 = v5758 < v5759;
  struct StateG * v5774;
  if (v5779) {
    int * v5760 = v5756->pht;
    v5760[64] = 1;
    int v5762 = v5756->timer;
    int v5783 = v5762 + 15;
    v5756->timer = v5783;
    int * v5764 = v5756->saved_regs;
    int v5765 = v5764[18];
    int * v5766 = v5756->regs;
    v5766[18] = v5765;
    struct StateG * v5768 = slot_294(v5756);
    v5774 = v5768;
  } else {
    int * v5770 = v5756->pht;
    v5770[64] = 0;
    struct StateG * v5772 = slot_295(v5756);
    v5774 = v5772;
  }
  return v5774;
}

struct StateG * slot_161(struct StateG * v3272) {
  int v3273 = v3272->timer;
  int v3279 = v3273 + 1;
  v3272->timer = v3279;
  int * v3275 = v3272->regs;
  v3275[18] = 1;
  struct StateG * v3277 = slot_163(v3272);
  return v3277;
}

struct StateG * slot_185(struct StateG * v3576) {
  int v3577 = v3576->timer;
  int v3587 = v3577 + 1;
  v3576->timer = v3587;
  int * v3579 = v3576->pht;
  int v3580 = v3579[78];
  bool v3590 = !(v3580 == 0);
  struct StateG * v3585;
  if (v3590) {
    struct StateG * v3581 = slot_202(v3576);
    v3585 = v3581;
  } else {
    struct StateG * v3583 = slot_203(v3576);
    v3585 = v3583;
  }
  return v3585;
}

struct StateG * slot_804(struct StateG * v16304) {
  int * v16305 = v16304->saved_regs;
  int * v16306 = v16304->regs;
  int v16307 = v16306[19];
  v16305[19] = v16307;
  int v16309 = v16304->timer;
  int v16319 = v16309 + 1;
  v16304->timer = v16319;
  int * v16311 = v16304->regs;
  v16311[19] = 2;
  struct StateG * v16313 = slot_836(v16304);
  return v16313;
}

struct StateG * slot_384(struct StateG * v8260) {
  int * v8261 = v8260->regs;
  int v8262 = v8261[16];
  int v8263 = v8261[17];
  bool v8283 = v8262 < v8263;
  struct StateG * v8278;
  if (v8283) {
    int * v8264 = v8260->pht;
    v8264[83] = 1;
    struct StateG * v8266 = slot_408(v8260);
    v8278 = v8266;
  } else {
    int * v8268 = v8260->pht;
    v8268[83] = 0;
    int v8270 = v8260->timer;
    int v8292 = v8270 + 15;
    v8260->timer = v8292;
    int * v8272 = v8260->saved_regs;
    int v8273 = v8272[18];
    int * v8274 = v8260->regs;
    v8274[18] = v8273;
    struct StateG * v8276 = slot_409(v8260);
    v8278 = v8276;
  }
  return v8278;
}

struct StateG * slot_486(struct StateG * v10044) {
  int * v10045 = v10044->saved_regs;
  int * v10046 = v10044->regs;
  int v10047 = v10046[18];
  v10045[18] = v10047;
  int v10049 = v10044->timer;
  int v10059 = v10049 + 1;
  v10044->timer = v10059;
  int * v10051 = v10044->regs;
  v10051[18] = 2;
  struct StateG * v10053 = slot_518(v10044);
  return v10053;
}

struct StateG * slot_49(struct StateG * v1021) {
  int v1022 = v1021->timer;
  int v1028 = v1022 + 1;
  v1021->timer = v1028;
  int * v1024 = v1021->regs;
  v1024[17] = 10;
  struct StateG * v1026 = slot_53(v1021);
  return v1026;
}

struct StateG * slot_216(struct StateG * v4196) {
  int * v4197 = v4196->saved_regs;
  int * v4198 = v4196->regs;
  int v4199 = v4198[18];
  v4197[18] = v4199;
  int v4201 = v4196->timer;
  int v4211 = v4201 + 1;
  v4196->timer = v4211;
  int * v4203 = v4196->regs;
  v4203[18] = 2;
  struct StateG * v4205 = slot_248(v4196);
  return v4205;
}

struct StateG * slot_468(struct StateG * v9684) {
  int * v9685 = v9684->saved_regs;
  int * v9686 = v9684->regs;
  int v9687 = v9686[18];
  v9685[18] = v9687;
  int v9689 = v9684->timer;
  int v9699 = v9689 + 1;
  v9684->timer = v9699;
  int * v9691 = v9684->regs;
  v9691[18] = 2;
  struct StateG * v9693 = slot_500(v9684);
  return v9693;
}

struct StateG * slot_50(struct StateG * v1034) {
  int v1035 = v1034->timer;
  int v1041 = v1035 + 1;
  v1034->timer = v1041;
  int * v1037 = v1034->regs;
  v1037[17] = 10;
  struct StateG * v1039 = slot_54(v1034);
  return v1039;
}

struct StateG * slot_248(struct StateG * v5156) {
  int * v5157 = v5156->regs;
  int v5158 = v5157[16];
  int v5159 = v5157[17];
  bool v5179 = v5158 < v5159;
  struct StateG * v5174;
  if (v5179) {
    int * v5160 = v5156->pht;
    v5160[71] = 1;
    struct StateG * v5162 = slot_264(v5156);
    v5174 = v5162;
  } else {
    int * v5164 = v5156->pht;
    v5164[71] = 0;
    int v5166 = v5156->timer;
    int v5188 = v5166 + 15;
    v5156->timer = v5188;
    int * v5168 = v5156->saved_regs;
    int v5169 = v5168[18];
    int * v5170 = v5156->regs;
    v5170[18] = v5169;
    struct StateG * v5172 = slot_265(v5156);
    v5174 = v5172;
  }
  return v5174;
}

struct StateG * slot_59(struct StateG * v1200) {
  int * v1201 = v1200->saved_regs;
  int * v1202 = v1200->regs;
  int v1203 = v1202[18];
  v1201[18] = v1203;
  int v1205 = v1200->timer;
  int v1215 = v1205 + 1;
  v1200->timer = v1215;
  int * v1207 = v1200->regs;
  v1207[18] = 1;
  struct StateG * v1209 = slot_67(v1200);
  return v1209;
}

struct StateG * slot_721(struct StateG * v15022) {
  int v15023 = v15022->timer;
  int v15030 = v15023 + 1;
  v15022->timer = v15030;
  int * v15025 = v15022->regs;
  int v15026 = v15025[1];
  bool v15033 = v15026 == 156;
  ret_assert(v15033);
  struct StateG * v15028 = slot_737(v15022);
  return v15028;
}

struct StateG * slot_77(struct StateG * v1670) {
  int v1671 = v1670->timer;
  int v1677 = v1671 + 1;
  v1670->timer = v1677;
  int * v1673 = v1670->regs;
  v1673[18] = 1;
  struct StateG * v1675 = slot_79(v1670);
  return v1675;
}

struct StateG * slot_350(struct StateG * v7100) {
  int * v7101 = v7100->saved_regs;
  int * v7102 = v7100->regs;
  int v7103 = v7102[18];
  v7101[18] = v7103;
  int v7105 = v7100->timer;
  int v7115 = v7105 + 1;
  v7100->timer = v7115;
  int * v7107 = v7100->regs;
  v7107[18] = 2;
  struct StateG * v7109 = slot_382(v7100);
  return v7109;
}

struct StateG * slot_392(struct StateG * v8580) {
  int v8581 = v8580->timer;
  int v8585 = v8581 + 1;
  v8580->timer = v8585;
  struct StateG * v8583 = slot_424(v8580);
  return v8583;
}

struct StateG * slot_771(struct StateG * v15679) {
  int v15680 = v15679->timer;
  int v15686 = v15680 + 1;
  v15679->timer = v15686;
  int * v15682 = v15679->regs;
  v15682[17] = 10;
  struct StateG * v15684 = slot_787(v15679);
  return v15684;
}

struct StateG * slot_625(struct StateG * v12824) {
  int * v12825 = v12824->saved_regs;
  int * v12826 = v12824->regs;
  int v12827 = v12826[18];
  v12825[18] = v12827;
  int v12829 = v12824->timer;
  int v12839 = v12829 + 1;
  v12824->timer = v12839;
  int * v12831 = v12824->regs;
  v12831[18] = 1;
  struct StateG * v12833 = slot_657(v12824);
  return v12833;
}

struct StateG * slot_71(struct StateG * v1580) {
  int * v1581 = v1580->regs;
  int v1582 = v1581[16];
  int v1583 = v1581[17];
  bool v1603 = v1582 < v1583;
  struct StateG * v1598;
  if (v1603) {
    int * v1584 = v1580->pht;
    v1584[32] = 1;
    int v1586 = v1580->timer;
    int v1607 = v1586 + 15;
    v1580->timer = v1607;
    int * v1588 = v1580->saved_regs;
    int v1589 = v1588[18];
    int * v1590 = v1580->regs;
    v1590[18] = v1589;
    struct StateG * v1592 = slot_86(v1580);
    v1598 = v1592;
  } else {
    int * v1594 = v1580->pht;
    v1594[32] = 0;
    struct StateG * v1596 = slot_87(v1580);
    v1598 = v1596;
  }
  return v1598;
}

struct StateG * slot_378(struct StateG * v8020) {
  int * v8021 = v8020->regs;
  int v8022 = v8021[16];
  int v8023 = v8021[17];
  bool v8043 = v8022 < v8023;
  struct StateG * v8038;
  if (v8043) {
    int * v8024 = v8020->pht;
    v8024[86] = 1;
    struct StateG * v8026 = slot_396(v8020);
    v8038 = v8026;
  } else {
    int * v8028 = v8020->pht;
    v8028[86] = 0;
    int v8030 = v8020->timer;
    int v8052 = v8030 + 15;
    v8020->timer = v8052;
    int * v8032 = v8020->saved_regs;
    int v8033 = v8032[18];
    int * v8034 = v8020->regs;
    v8034[18] = v8033;
    struct StateG * v8036 = slot_397(v8020);
    v8038 = v8036;
  }
  return v8038;
}

struct StateG * slot_800(struct StateG * v16224) {
  int * v16225 = v16224->saved_regs;
  int * v16226 = v16224->regs;
  int v16227 = v16226[19];
  v16225[19] = v16227;
  int v16229 = v16224->timer;
  int v16239 = v16229 + 1;
  v16224->timer = v16239;
  int * v16231 = v16224->regs;
  v16231[19] = 2;
  struct StateG * v16233 = slot_832(v16224);
  return v16233;
}

struct StateG * slot_108(struct StateG * v2132) {
  int * v2133 = v2132->saved_regs;
  int * v2134 = v2132->regs;
  int v2135 = v2134[18];
  v2133[18] = v2135;
  int v2137 = v2132->timer;
  int v2147 = v2137 + 1;
  v2132->timer = v2147;
  int * v2139 = v2132->regs;
  v2139[18] = 2;
  struct StateG * v2141 = slot_124(v2132);
  return v2141;
}

struct StateG * slot_116(struct StateG * v2292) {
  int * v2293 = v2292->saved_regs;
  int * v2294 = v2292->regs;
  int v2295 = v2294[18];
  v2293[18] = v2295;
  int v2297 = v2292->timer;
  int v2307 = v2297 + 1;
  v2292->timer = v2307;
  int * v2299 = v2292->regs;
  v2299[18] = 2;
  struct StateG * v2301 = slot_132(v2292);
  return v2301;
}

struct StateG * slot_618(struct StateG * v12684) {
  int * v12685 = v12684->saved_regs;
  int * v12686 = v12684->regs;
  int v12687 = v12686[18];
  v12685[18] = v12687;
  int v12689 = v12684->timer;
  int v12699 = v12689 + 1;
  v12684->timer = v12699;
  int * v12691 = v12684->regs;
  v12691[18] = 2;
  struct StateG * v12693 = slot_650(v12684);
  return v12693;
}

struct StateG * slot_417(struct StateG * v8840) {
  int v8841 = v8840->timer;
  int v8847 = v8841 + 1;
  v8840->timer = v8847;
  int * v8843 = v8840->regs;
  v8843[18] = 1;
  struct StateG * v8845 = slot_419(v8840);
  return v8845;
}

struct StateG * slot_762(struct StateG * v15562) {
  int v15563 = v15562->timer;
  int v15569 = v15563 + 1;
  v15562->timer = v15569;
  int * v15565 = v15562->regs;
  v15565[17] = 10;
  struct StateG * v15567 = slot_778(v15562);
  return v15567;
}

struct StateG * slot_766(struct StateG * v15614) {
  int v15615 = v15614->timer;
  int v15621 = v15615 + 1;
  v15614->timer = v15621;
  int * v15617 = v15614->regs;
  v15617[17] = 10;
  struct StateG * v15619 = slot_782(v15614);
  return v15619;
}

struct StateG * slot_215(struct StateG * v4176) {
  int * v4177 = v4176->saved_regs;
  int * v4178 = v4176->regs;
  int v4179 = v4178[18];
  v4177[18] = v4179;
  int v4181 = v4176->timer;
  int v4191 = v4181 + 1;
  v4176->timer = v4191;
  int * v4183 = v4176->regs;
  v4183[18] = 1;
  struct StateG * v4185 = slot_247(v4176);
  return v4185;
}

struct StateG * slot_45(struct StateG * v969) {
  int v970 = v969->timer;
  int v976 = v970 + 1;
  v969->timer = v976;
  int * v972 = v969->regs;
  v972[16] = 20;
  struct StateG * v974 = slot_49(v969);
  return v974;
}

struct StateG * slot_220(struct StateG * v4276) {
  int * v4277 = v4276->saved_regs;
  int * v4278 = v4276->regs;
  int v4279 = v4278[18];
  v4277[18] = v4279;
  int v4281 = v4276->timer;
  int v4291 = v4281 + 1;
  v4276->timer = v4291;
  int * v4283 = v4276->regs;
  v4283[18] = 2;
  struct StateG * v4285 = slot_252(v4276);
  return v4285;
}

struct StateG * slot_134(struct StateG * v2932) {
  int * v2933 = v2932->regs;
  int v2934 = v2933[16];
  int v2935 = v2933[17];
  bool v2955 = v2934 < v2935;
  struct StateG * v2950;
  if (v2955) {
    int * v2936 = v2932->pht;
    v2936[48] = 1;
    struct StateG * v2938 = slot_164(v2932);
    v2950 = v2938;
  } else {
    int * v2940 = v2932->pht;
    v2940[48] = 0;
    int v2942 = v2932->timer;
    int v2964 = v2942 + 15;
    v2932->timer = v2964;
    int * v2944 = v2932->saved_regs;
    int v2945 = v2944[18];
    int * v2946 = v2932->regs;
    v2946[18] = v2945;
    struct StateG * v2948 = slot_165(v2932);
    v2950 = v2948;
  }
  return v2950;
}

struct StateG * slot_273(struct StateG * v5888) {
  int v5889 = v5888->timer;
  int v5895 = v5889 + 1;
  v5888->timer = v5895;
  int * v5891 = v5888->regs;
  v5891[18] = 1;
  struct StateG * v5893 = slot_275(v5888);
  return v5893;
}

struct StateG * slot_69(struct StateG * v1500) {
  int * v1501 = v1500->regs;
  int v1502 = v1501[16];
  int v1503 = v1501[17];
  bool v1523 = v1502 < v1503;
  struct StateG * v1518;
  if (v1523) {
    int * v1504 = v1500->pht;
    v1504[33] = 1;
    int v1506 = v1500->timer;
    int v1527 = v1506 + 15;
    v1500->timer = v1527;
    int * v1508 = v1500->saved_regs;
    int v1509 = v1508[18];
    int * v1510 = v1500->regs;
    v1510[18] = v1509;
    struct StateG * v1512 = slot_82(v1500);
    v1518 = v1512;
  } else {
    int * v1514 = v1500->pht;
    v1514[33] = 0;
    struct StateG * v1516 = slot_83(v1500);
    v1518 = v1516;
  }
  return v1518;
}

struct StateG * slot_644(struct StateG * v13204) {
  int * v13205 = v13204->saved_regs;
  int * v13206 = v13204->regs;
  int v13207 = v13206[18];
  v13205[18] = v13207;
  int v13209 = v13204->timer;
  int v13219 = v13209 + 1;
  v13204->timer = v13219;
  int * v13211 = v13204->regs;
  v13211[18] = 2;
  struct StateG * v13213 = slot_676(v13204);
  return v13213;
}

struct StateG * slot_723(struct StateG * v15050) {
  int v15051 = v15050->timer;
  int v15058 = v15051 + 1;
  v15050->timer = v15058;
  int * v15053 = v15050->regs;
  int v15054 = v15053[1];
  bool v15061 = v15054 == 156;
  ret_assert(v15061);
  struct StateG * v15056 = slot_739(v15050);
  return v15056;
}

struct StateG * slot_751(struct StateG * v15419) {
  int v15420 = v15419->timer;
  int v15426 = v15420 + 1;
  v15419->timer = v15426;
  int * v15422 = v15419->regs;
  v15422[1] = 164;
  struct StateG * v15424 = slot_767(v15419);
  return v15424;
}

struct StateG * slot_186(struct StateG * v3596) {
  int v3597 = v3596->timer;
  int v3607 = v3597 + 1;
  v3596->timer = v3607;
  int * v3599 = v3596->pht;
  int v3600 = v3599[77];
  bool v3610 = !(v3600 == 0);
  struct StateG * v3605;
  if (v3610) {
    struct StateG * v3601 = slot_204(v3596);
    v3605 = v3601;
  } else {
    struct StateG * v3603 = slot_205(v3596);
    v3605 = v3603;
  }
  return v3605;
}

struct StateG * slot_102(struct StateG * v2012) {
  int v2013 = v2012->timer;
  int v2023 = v2013 + 1;
  v2012->timer = v2023;
  int * v2015 = v2012->pht;
  int v2016 = v2015[49];
  bool v2026 = !(v2016 == 0);
  struct StateG * v2021;
  if (v2026) {
    struct StateG * v2017 = slot_116(v2012);
    v2021 = v2017;
  } else {
    struct StateG * v2019 = slot_117(v2012);
    v2021 = v2019;
  }
  return v2021;
}

struct StateG * slot_145(struct StateG * v3104) {
  int v3105 = v3104->timer;
  int v3111 = v3105 + 1;
  v3104->timer = v3111;
  int * v3107 = v3104->regs;
  v3107[18] = 1;
  struct StateG * v3109 = slot_147(v3104);
  return v3109;
}

struct StateG * slot_208(struct StateG * v4036) {
  int * v4037 = v4036->saved_regs;
  int * v4038 = v4036->regs;
  int v4039 = v4038[18];
  v4037[18] = v4039;
  int v4041 = v4036->timer;
  int v4051 = v4041 + 1;
  v4036->timer = v4051;
  int * v4043 = v4036->regs;
  v4043[18] = 2;
  struct StateG * v4045 = slot_240(v4036);
  return v4045;
}

struct StateG * slot_506(struct StateG * v10804) {
  int * v10805 = v10804->regs;
  int v10806 = v10805[16];
  int v10807 = v10805[17];
  bool v10827 = v10806 < v10807;
  struct StateG * v10822;
  if (v10827) {
    int * v10808 = v10804->pht;
    v10808[102] = 1;
    struct StateG * v10810 = slot_524(v10804);
    v10822 = v10810;
  } else {
    int * v10812 = v10804->pht;
    v10812[102] = 0;
    int v10814 = v10804->timer;
    int v10836 = v10814 + 15;
    v10804->timer = v10836;
    int * v10816 = v10804->saved_regs;
    int v10817 = v10816[18];
    int * v10818 = v10804->regs;
    v10818[18] = v10817;
    struct StateG * v10820 = slot_525(v10804);
    v10822 = v10820;
  }
  return v10822;
}

struct StateG * slot_413(struct StateG * v8798) {
  int v8799 = v8798->timer;
  int v8805 = v8799 + 1;
  v8798->timer = v8805;
  int * v8801 = v8798->regs;
  v8801[18] = 1;
  struct StateG * v8803 = slot_415(v8798);
  return v8803;
}

struct StateG * slot_281(struct StateG * v5972) {
  int v5973 = v5972->timer;
  int v5979 = v5973 + 1;
  v5972->timer = v5979;
  int * v5975 = v5972->regs;
  v5975[18] = 1;
  struct StateG * v5977 = slot_283(v5972);
  return v5977;
}

struct StateG * slot_533(struct StateG * v11498) {
  int v11499 = v11498->timer;
  int v11505 = v11499 + 1;
  v11498->timer = v11505;
  int * v11501 = v11498->regs;
  v11501[18] = 1;
  struct StateG * v11503 = slot_535(v11498);
  return v11503;
}

struct StateG * slot_190(struct StateG * v3676) {
  int v3677 = v3676->timer;
  int v3687 = v3677 + 1;
  v3676->timer = v3687;
  int * v3679 = v3676->pht;
  int v3680 = v3679[73];
  bool v3690 = !(v3680 == 0);
  struct StateG * v3685;
  if (v3690) {
    struct StateG * v3681 = slot_212(v3676);
    v3685 = v3681;
  } else {
    struct StateG * v3683 = slot_213(v3676);
    v3685 = v3683;
  }
  return v3685;
}

struct StateG * slot_447(struct StateG * v9264) {
  int v9265 = v9264->timer;
  int v9275 = v9265 + 1;
  v9264->timer = v9275;
  int * v9267 = v9264->pht;
  int v9268 = v9267[104];
  bool v9278 = !(v9268 == 0);
  struct StateG * v9273;
  if (v9278) {
    struct StateG * v9269 = slot_470(v9264);
    v9273 = v9269;
  } else {
    struct StateG * v9271 = slot_471(v9264);
    v9273 = v9271;
  }
  return v9273;
}

struct StateG * slot_719(struct StateG * v14994) {
  int v14995 = v14994->timer;
  int v15002 = v14995 + 1;
  v14994->timer = v15002;
  int * v14997 = v14994->regs;
  int v14998 = v14997[1];
  bool v15005 = v14998 == 156;
  ret_assert(v15005);
  struct StateG * v15000 = slot_735(v14994);
  return v15000;
}

struct StateG * slot_559(struct StateG * v11791) {
  int v11792 = v11791->timer;
  int v11798 = v11792 + 1;
  v11791->timer = v11798;
  int * v11794 = v11791->regs;
  v11794[1] = 148;
  struct StateG * v11796 = slot_575(v11791);
  return v11796;
}

struct StateG * slot_243(struct StateG * v4956) {
  int * v4957 = v4956->regs;
  int v4958 = v4957[16];
  int v4959 = v4957[17];
  bool v4979 = v4958 < v4959;
  struct StateG * v4974;
  if (v4979) {
    int * v4960 = v4956->pht;
    v4960[74] = 1;
    int v4962 = v4956->timer;
    int v4983 = v4962 + 15;
    v4956->timer = v4983;
    int * v4964 = v4956->saved_regs;
    int v4965 = v4964[18];
    int * v4966 = v4956->regs;
    v4966[18] = v4965;
    struct StateG * v4968 = slot_286(v4956);
    v4974 = v4968;
  } else {
    int * v4970 = v4956->pht;
    v4970[74] = 0;
    struct StateG * v4972 = slot_287(v4956);
    v4974 = v4972;
  }
  return v4974;
}

struct StateG * slot_173(struct StateG * v3413) {
  int v3414 = v3413->timer;
  int v3420 = v3414 + 1;
  v3413->timer = v3420;
  int * v3416 = v3413->regs;
  v3416[17] = 10;
  struct StateG * v3418 = slot_189(v3413);
  return v3418;
}

struct StateG * slot_750(struct StateG * v15406) {
  int v15407 = v15406->timer;
  int v15413 = v15407 + 1;
  v15406->timer = v15413;
  int * v15409 = v15406->regs;
  v15409[1] = 164;
  struct StateG * v15411 = slot_766(v15406);
  return v15411;
}

struct StateG * slot_814(struct StateG * v16504) {
  int * v16505 = v16504->saved_regs;
  int * v16506 = v16504->regs;
  int v16507 = v16506[19];
  v16505[19] = v16507;
  int v16509 = v16504->timer;
  int v16519 = v16509 + 1;
  v16504->timer = v16519;
  int * v16511 = v16504->regs;
  v16511[19] = 2;
  struct StateG * v16513 = slot_846(v16504);
  return v16513;
}

struct StateG * slot_307(struct StateG * v6275) {
  int v6276 = v6275->timer;
  int v6282 = v6276 + 1;
  v6275->timer = v6282;
  int * v6278 = v6275->regs;
  v6278[17] = 10;
  struct StateG * v6280 = slot_323(v6275);
  return v6280;
}

struct StateG * slot_54(struct StateG * v1100) {
  int v1101 = v1100->timer;
  int v1111 = v1101 + 1;
  v1100->timer = v1111;
  int * v1103 = v1100->pht;
  int v1104 = v1103[33];
  bool v1114 = !(v1104 == 0);
  struct StateG * v1109;
  if (v1114) {
    struct StateG * v1105 = slot_60(v1100);
    v1109 = v1105;
  } else {
    struct StateG * v1107 = slot_61(v1100);
    v1109 = v1107;
  }
  return v1109;
}

struct StateG * slot_735(struct StateG * v15211) {
  int v15212 = v15211->timer;
  int v15218 = v15212 + 1;
  v15211->timer = v15218;
  int * v15214 = v15211->regs;
  v15214[1] = 156;
  struct StateG * v15216 = slot_751(v15211);
  return v15216;
}

struct StateG * slot_227(struct StateG * v4416) {
  int * v4417 = v4416->saved_regs;
  int * v4418 = v4416->regs;
  int v4419 = v4418[18];
  v4417[18] = v4419;
  int v4421 = v4416->timer;
  int v4431 = v4421 + 1;
  v4416->timer = v4431;
  int * v4423 = v4416->regs;
  v4423[18] = 1;
  struct StateG * v4425 = slot_259(v4416);
  return v4425;
}

struct StateG * slot_442(struct StateG * v9164) {
  int v9165 = v9164->timer;
  int v9175 = v9165 + 1;
  v9164->timer = v9175;
  int * v9167 = v9164->pht;
  int v9168 = v9167[109];
  bool v9178 = !(v9168 == 0);
  struct StateG * v9173;
  if (v9178) {
    struct StateG * v9169 = slot_460(v9164);
    v9173 = v9169;
  } else {
    struct StateG * v9171 = slot_461(v9164);
    v9173 = v9171;
  }
  return v9173;
}

struct StateG * slot_529(struct StateG * v11456) {
  int v11457 = v11456->timer;
  int v11463 = v11457 + 1;
  v11456->timer = v11463;
  int * v11459 = v11456->regs;
  v11459[18] = 1;
  struct StateG * v11461 = slot_531(v11456);
  return v11461;
}

struct StateG * slot_807(struct StateG * v16364) {
  int * v16365 = v16364->saved_regs;
  int * v16366 = v16364->regs;
  int v16367 = v16366[19];
  v16365[19] = v16367;
  int v16369 = v16364->timer;
  int v16379 = v16369 + 1;
  v16364->timer = v16379;
  int * v16371 = v16364->regs;
  v16371[19] = 1;
  struct StateG * v16373 = slot_839(v16364);
  return v16373;
}

struct StateG * slot_710(struct StateG * v14875) {
  int v14876 = v14875->timer;
  int v14882 = v14876 + 1;
  v14875->timer = v14882;
  int * v14878 = v14875->regs;
  v14878[18] = 2;
  struct StateG * v14880 = slot_708(v14875);
  return v14880;
}

struct StateG * slot_444(struct StateG * v9204) {
  int v9205 = v9204->timer;
  int v9215 = v9205 + 1;
  v9204->timer = v9215;
  int * v9207 = v9204->pht;
  int v9208 = v9207[107];
  bool v9218 = !(v9208 == 0);
  struct StateG * v9213;
  if (v9218) {
    struct StateG * v9209 = slot_464(v9204);
    v9213 = v9209;
  } else {
    struct StateG * v9211 = slot_465(v9204);
    v9213 = v9211;
  }
  return v9213;
}

struct StateG * slot_824(struct StateG * v16704) {
  int * v16705 = v16704->regs;
  int v16706 = v16705[16];
  int v16707 = v16705[17];
  bool v16727 = v16706 >= v16707;
  struct StateG * v16722;
  if (v16727) {
    int * v16708 = v16704->pht;
    v16708[31] = 1;
    struct StateG * v16710 = slot_883(v16704);
    v16722 = v16710;
  } else {
    int * v16712 = v16704->pht;
    v16712[31] = 0;
    int v16714 = v16704->timer;
    int v16736 = v16714 + 15;
    v16704->timer = v16736;
    int * v16716 = v16704->saved_regs;
    int v16717 = v16716[19];
    int * v16718 = v16704->regs;
    v16718[19] = v16717;
    struct StateG * v16720 = slot_861(v16704);
    v16722 = v16720;
  }
  return v16722;
}

struct StateG * slot_287(struct StateG * v6040) {
  int v6041 = v6040->timer;
  int v6045 = v6041 + 1;
  v6040->timer = v6045;
  struct StateG * v6043 = slot_307(v6040);
  return v6043;
}

struct StateG * slot_343(struct StateG * v6960) {
  int * v6961 = v6960->saved_regs;
  int * v6962 = v6960->regs;
  int v6963 = v6962[18];
  v6961[18] = v6963;
  int v6965 = v6960->timer;
  int v6975 = v6965 + 1;
  v6960->timer = v6975;
  int * v6967 = v6960->regs;
  v6967[18] = 1;
  struct StateG * v6969 = slot_375(v6960);
  return v6969;
}

struct StateG * slot_755(struct StateG * v15471) {
  int v15472 = v15471->timer;
  int v15478 = v15472 + 1;
  v15471->timer = v15478;
  int * v15474 = v15471->regs;
  v15474[1] = 164;
  struct StateG * v15476 = slot_771(v15471);
  return v15476;
}

struct StateG * slot_728(struct StateG * v15120) {
  int v15121 = v15120->timer;
  int v15127 = v15121 + 1;
  v15120->timer = v15127;
  int * v15123 = v15120->regs;
  v15123[1] = 156;
  struct StateG * v15125 = slot_744(v15120);
  return v15125;
}

struct StateG * slot_536(struct StateG * v11532) {
  int v11533 = v11532->timer;
  int v11537 = v11533 + 1;
  v11532->timer = v11537;
  struct StateG * v11535 = slot_560(v11532);
  return v11535;
}

struct StateG * slot_470(struct StateG * v9724) {
  int * v9725 = v9724->saved_regs;
  int * v9726 = v9724->regs;
  int v9727 = v9726[18];
  v9725[18] = v9727;
  int v9729 = v9724->timer;
  int v9739 = v9729 + 1;
  v9724->timer = v9739;
  int * v9731 = v9724->regs;
  v9731[18] = 2;
  struct StateG * v9733 = slot_502(v9724);
  return v9733;
}

struct StateG * slot_670(struct StateG * v14164) {
  int * v14165 = v14164->regs;
  int v14166 = v14165[16];
  int v14167 = v14165[17];
  bool v14187 = v14166 < v14167;
  struct StateG * v14182;
  if (v14187) {
    int * v14168 = v14164->pht;
    v14168[4] = 1;
    struct StateG * v14170 = slot_692(v14164);
    v14182 = v14170;
  } else {
    int * v14172 = v14164->pht;
    v14172[4] = 0;
    int v14174 = v14164->timer;
    int v14196 = v14174 + 15;
    v14164->timer = v14196;
    int * v14176 = v14164->saved_regs;
    int v14177 = v14176[18];
    int * v14178 = v14164->regs;
    v14178[18] = v14177;
    struct StateG * v14180 = slot_693(v14164);
    v14182 = v14180;
  }
  return v14182;
}

struct StateG * slot_127(struct StateG * v2652) {
  int * v2653 = v2652->regs;
  int v2654 = v2653[16];
  int v2655 = v2653[17];
  bool v2675 = v2654 < v2655;
  struct StateG * v2670;
  if (v2675) {
    int * v2656 = v2652->pht;
    v2656[52] = 1;
    int v2658 = v2652->timer;
    int v2679 = v2658 + 15;
    v2652->timer = v2679;
    int * v2660 = v2652->saved_regs;
    int v2661 = v2660[18];
    int * v2662 = v2652->regs;
    v2662[18] = v2661;
    struct StateG * v2664 = slot_150(v2652);
    v2670 = v2664;
  } else {
    int * v2666 = v2652->pht;
    v2666[52] = 0;
    struct StateG * v2668 = slot_151(v2652);
    v2670 = v2668;
  }
  return v2670;
}

struct StateG * slot_640(struct StateG * v13124) {
  int * v13125 = v13124->saved_regs;
  int * v13126 = v13124->regs;
  int v13127 = v13126[18];
  v13125[18] = v13127;
  int v13129 = v13124->timer;
  int v13139 = v13129 + 1;
  v13124->timer = v13139;
  int * v13131 = v13124->regs;
  v13131[18] = 2;
  struct StateG * v13133 = slot_672(v13124);
  return v13133;
}

struct StateG * slot_411(struct StateG * v8782) {
  int v8783 = v8782->timer;
  int v8787 = v8783 + 1;
  v8782->timer = v8787;
  struct StateG * v8785 = slot_433(v8782);
  return v8785;
}

struct StateG * slot_783(struct StateG * v15884) {
  int v15885 = v15884->timer;
  int v15895 = v15885 + 1;
  v15884->timer = v15895;
  int * v15887 = v15884->pht;
  int v15888 = v15887[24];
  bool v15898 = !(v15888 == 0);
  struct StateG * v15893;
  if (v15898) {
    struct StateG * v15889 = slot_806(v15884);
    v15893 = v15889;
  } else {
    struct StateG * v15891 = slot_807(v15884);
    v15893 = v15891;
  }
  return v15893;
}

struct StateG * slot_834(struct StateG * v17104) {
  int * v17105 = v17104->regs;
  int v17106 = v17105[16];
  int v17107 = v17105[17];
  bool v17127 = v17106 >= v17107;
  struct StateG * v17122;
  if (v17127) {
    int * v17108 = v17104->pht;
    v17108[26] = 1;
    struct StateG * v17110 = slot_883(v17104);
    v17122 = v17110;
  } else {
    int * v17112 = v17104->pht;
    v17112[26] = 0;
    int v17114 = v17104->timer;
    int v17136 = v17114 + 15;
    v17104->timer = v17136;
    int * v17116 = v17104->saved_regs;
    int v17117 = v17116[19];
    int * v17118 = v17104->regs;
    v17118[19] = v17117;
    struct StateG * v17120 = slot_861(v17104);
    v17122 = v17120;
  }
  return v17122;
}

struct StateG * slot_688(struct StateG * v14644) {
  int v14645 = v14644->timer;
  int v14649 = v14645 + 1;
  v14644->timer = v14649;
  struct StateG * v14647 = slot_716(v14644);
  return v14647;
}

struct StateG * slot_474(struct StateG * v9804) {
  int * v9805 = v9804->saved_regs;
  int * v9806 = v9804->regs;
  int v9807 = v9806[18];
  v9805[18] = v9807;
  int v9809 = v9804->timer;
  int v9819 = v9809 + 1;
  v9804->timer = v9819;
  int * v9811 = v9804->regs;
  v9811[18] = 2;
  struct StateG * v9813 = slot_506(v9804);
  return v9813;
}

struct StateG * slot_174(struct StateG * v3426) {
  int v3427 = v3426->timer;
  int v3433 = v3427 + 1;
  v3426->timer = v3433;
  int * v3429 = v3426->regs;
  v3429[17] = 10;
  struct StateG * v3431 = slot_190(v3426);
  return v3431;
}

struct StateG * slot_42(struct StateG * v928) {
  int v929 = v928->timer;
  int v936 = v929 + 1;
  v928->timer = v936;
  int * v931 = v928->regs;
  int v932 = v931[1];
  bool v939 = v932 == 24;
  ret_assert(v939);
  struct StateG * v934 = slot_46(v928);
  return v934;
}

struct StateG * slot_720(struct StateG * v15008) {
  int v15009 = v15008->timer;
  int v15016 = v15009 + 1;
  v15008->timer = v15016;
  int * v15011 = v15008->regs;
  int v15012 = v15011[1];
  bool v15019 = v15012 == 156;
  ret_assert(v15019);
  struct StateG * v15014 = slot_736(v15008);
  return v15014;
}

struct StateG * slot_588(struct StateG * v12168) {
  int v12169 = v12168->timer;
  int v12175 = v12169 + 1;
  v12168->timer = v12175;
  int * v12171 = v12168->regs;
  v12171[17] = 10;
  struct StateG * v12173 = slot_604(v12168);
  return v12173;
}

struct StateG * slot_825(struct StateG * v16744) {
  int * v16745 = v16744->regs;
  int v16746 = v16745[16];
  int v16747 = v16745[17];
  bool v16767 = v16746 >= v16747;
  struct StateG * v16762;
  if (v16767) {
    int * v16748 = v16744->pht;
    v16748[31] = 1;
    int v16750 = v16744->timer;
    int v16771 = v16750 + 15;
    v16744->timer = v16771;
    int * v16752 = v16744->saved_regs;
    int v16753 = v16752[19];
    int * v16754 = v16744->regs;
    v16754[19] = v16753;
    struct StateG * v16756 = slot_858(v16744);
    v16762 = v16756;
  } else {
    int * v16758 = v16744->pht;
    v16758[31] = 0;
    struct StateG * v16760 = slot_883(v16744);
    v16762 = v16760;
  }
  return v16762;
}

struct StateG * slot_462(struct StateG * v9564) {
  int * v9565 = v9564->saved_regs;
  int * v9566 = v9564->regs;
  int v9567 = v9566[18];
  v9565[18] = v9567;
  int v9569 = v9564->timer;
  int v9579 = v9569 + 1;
  v9564->timer = v9579;
  int * v9571 = v9564->regs;
  v9571[18] = 2;
  struct StateG * v9573 = slot_494(v9564);
  return v9573;
}

struct StateG * slot_165(struct StateG * v3314) {
  int v3315 = v3314->timer;
  int v3321 = v3315 + 1;
  v3314->timer = v3321;
  int * v3317 = v3314->regs;
  v3317[18] = 1;
  struct StateG * v3319 = slot_167(v3314);
  return v3319;
}

struct StateG * slot_557(struct StateG * v11765) {
  int v11766 = v11765->timer;
  int v11772 = v11766 + 1;
  v11765->timer = v11772;
  int * v11768 = v11765->regs;
  v11768[1] = 148;
  struct StateG * v11770 = slot_573(v11765);
  return v11770;
}

struct StateG * slot_507(struct StateG * v10844) {
  int * v10845 = v10844->regs;
  int v10846 = v10845[16];
  int v10847 = v10845[17];
  bool v10867 = v10846 < v10847;
  struct StateG * v10862;
  if (v10867) {
    int * v10848 = v10844->pht;
    v10848[102] = 1;
    int v10850 = v10844->timer;
    int v10871 = v10850 + 15;
    v10844->timer = v10871;
    int * v10852 = v10844->saved_regs;
    int v10853 = v10852[18];
    int * v10854 = v10844->regs;
    v10854[18] = v10853;
    struct StateG * v10856 = slot_526(v10844);
    v10862 = v10856;
  } else {
    int * v10858 = v10844->pht;
    v10858[102] = 0;
    struct StateG * v10860 = slot_527(v10844);
    v10862 = v10860;
  }
  return v10862;
}

struct StateG * slot_278(struct StateG * v5943) {
  int v5944 = v5943->timer;
  int v5950 = v5944 + 1;
  v5943->timer = v5950;
  int * v5946 = v5943->regs;
  v5946[18] = 2;
  struct StateG * v5948 = slot_276(v5943);
  return v5948;
}

struct StateG * slot_577(struct StateG * v12025) {
  int v12026 = v12025->timer;
  int v12032 = v12026 + 1;
  v12025->timer = v12032;
  int * v12028 = v12025->regs;
  v12028[1] = 156;
  struct StateG * v12030 = slot_593(v12025);
  return v12030;
}

struct StateG * slot_806(struct StateG * v16344) {
  int * v16345 = v16344->saved_regs;
  int * v16346 = v16344->regs;
  int v16347 = v16346[19];
  v16345[19] = v16347;
  int v16349 = v16344->timer;
  int v16359 = v16349 + 1;
  v16344->timer = v16359;
  int * v16351 = v16344->regs;
  v16351[19] = 2;
  struct StateG * v16353 = slot_838(v16344);
  return v16353;
}

struct StateG * slot_12(struct StateG * v417) {
  int v418 = v417->timer;
  int v424 = v418 + 1;
  v417->timer = v424;
  int * v420 = v417->regs;
  v420[18] = 2;
  struct StateG * v422 = slot_10(v417);
  return v422;
}

struct StateG * slot_716(struct StateG * v14952) {
  int v14953 = v14952->timer;
  int v14960 = v14953 + 1;
  v14952->timer = v14960;
  int * v14955 = v14952->regs;
  int v14956 = v14955[1];
  bool v14963 = v14956 == 156;
  ret_assert(v14963);
  struct StateG * v14958 = slot_732(v14952);
  return v14958;
}

struct StateG * slot_252(struct StateG * v5316) {
  int * v5317 = v5316->regs;
  int v5318 = v5317[16];
  int v5319 = v5317[17];
  bool v5339 = v5318 < v5319;
  struct StateG * v5334;
  if (v5339) {
    int * v5320 = v5316->pht;
    v5320[69] = 1;
    struct StateG * v5322 = slot_272(v5316);
    v5334 = v5322;
  } else {
    int * v5324 = v5316->pht;
    v5324[69] = 0;
    int v5326 = v5316->timer;
    int v5348 = v5326 + 15;
    v5316->timer = v5348;
    int * v5328 = v5316->saved_regs;
    int v5329 = v5328[18];
    int * v5330 = v5316->regs;
    v5330[18] = v5329;
    struct StateG * v5332 = slot_273(v5316);
    v5334 = v5332;
  }
  return v5334;
}

struct StateG * slot_374(struct StateG * v7860) {
  int * v7861 = v7860->regs;
  int v7862 = v7861[16];
  int v7863 = v7861[17];
  bool v7883 = v7862 < v7863;
  struct StateG * v7878;
  if (v7883) {
    int * v7864 = v7860->pht;
    v7864[88] = 1;
    struct StateG * v7866 = slot_420(v7860);
    v7878 = v7866;
  } else {
    int * v7868 = v7860->pht;
    v7868[88] = 0;
    int v7870 = v7860->timer;
    int v7892 = v7870 + 15;
    v7860->timer = v7892;
    int * v7872 = v7860->saved_regs;
    int v7873 = v7872[18];
    int * v7874 = v7860->regs;
    v7874[18] = v7873;
    struct StateG * v7876 = slot_421(v7860);
    v7878 = v7876;
  }
  return v7878;
}

struct StateG * slot_582(struct StateG * v12090) {
  int v12091 = v12090->timer;
  int v12097 = v12091 + 1;
  v12090->timer = v12097;
  int * v12093 = v12090->regs;
  v12093[1] = 156;
  struct StateG * v12095 = slot_598(v12090);
  return v12095;
}

struct StateG * slot_251(struct StateG * v5276) {
  int * v5277 = v5276->regs;
  int v5278 = v5277[16];
  int v5279 = v5277[17];
  bool v5299 = v5278 < v5279;
  struct StateG * v5294;
  if (v5299) {
    int * v5280 = v5276->pht;
    v5280[70] = 1;
    int v5282 = v5276->timer;
    int v5303 = v5282 + 15;
    v5276->timer = v5303;
    int * v5284 = v5276->saved_regs;
    int v5285 = v5284[18];
    int * v5286 = v5276->regs;
    v5286[18] = v5285;
    struct StateG * v5288 = slot_270(v5276);
    v5294 = v5288;
  } else {
    int * v5290 = v5276->pht;
    v5290[70] = 0;
    struct StateG * v5292 = slot_271(v5276);
    v5294 = v5292;
  }
  return v5294;
}

struct StateG * slot_65(struct StateG * v1340) {
  int * v1341 = v1340->regs;
  int v1342 = v1341[16];
  int v1343 = v1341[17];
  bool v1363 = v1342 < v1343;
  struct StateG * v1358;
  if (v1363) {
    int * v1344 = v1340->pht;
    v1344[35] = 1;
    int v1346 = v1340->timer;
    int v1367 = v1346 + 15;
    v1340->timer = v1367;
    int * v1348 = v1340->saved_regs;
    int v1349 = v1348[18];
    int * v1350 = v1340->regs;
    v1350[18] = v1349;
    struct StateG * v1352 = slot_74(v1340);
    v1358 = v1352;
  } else {
    int * v1354 = v1340->pht;
    v1354[35] = 0;
    struct StateG * v1356 = slot_75(v1340);
    v1358 = v1356;
  }
  return v1358;
}

struct StateG * slot_10(struct StateG * v396) {
  int v397 = v396->timer;
  int v401 = v397 + 1;
  v396->timer = v401;
  struct StateG * v399 = slot_14(v396);
  return v399;
}

struct StateG * slot_322(struct StateG * v6540) {
  int v6541 = v6540->timer;
  int v6551 = v6541 + 1;
  v6540->timer = v6551;
  int * v6543 = v6540->pht;
  int v6544 = v6543[85];
  bool v6554 = !(v6544 == 0);
  struct StateG * v6549;
  if (v6554) {
    struct StateG * v6545 = slot_348(v6540);
    v6549 = v6545;
  } else {
    struct StateG * v6547 = slot_349(v6540);
    v6549 = v6547;
  }
  return v6549;
}

struct StateG * slot_714(struct StateG * v14924) {
  int v14925 = v14924->timer;
  int v14932 = v14925 + 1;
  v14924->timer = v14932;
  int * v14927 = v14924->regs;
  int v14928 = v14927[1];
  bool v14935 = v14928 == 156;
  ret_assert(v14935);
  struct StateG * v14930 = slot_730(v14924);
  return v14930;
}

struct StateG * slot_593(struct StateG * v12233) {
  int v12234 = v12233->timer;
  int v12240 = v12234 + 1;
  v12233->timer = v12240;
  int * v12236 = v12233->regs;
  v12236[17] = 10;
  struct StateG * v12238 = slot_609(v12233);
  return v12238;
}

struct StateG * slot_277(struct StateG * v5930) {
  int v5931 = v5930->timer;
  int v5937 = v5931 + 1;
  v5930->timer = v5937;
  int * v5933 = v5930->regs;
  v5933[18] = 1;
  struct StateG * v5935 = slot_279(v5930);
  return v5935;
}

struct StateG * slot_692(struct StateG * v14686) {
  int v14687 = v14686->timer;
  int v14691 = v14687 + 1;
  v14686->timer = v14691;
  struct StateG * v14689 = slot_718(v14686);
  return v14689;
}

struct StateG * slot_353(struct StateG * v7160) {
  int * v7161 = v7160->saved_regs;
  int * v7162 = v7160->regs;
  int v7163 = v7162[18];
  v7161[18] = v7163;
  int v7165 = v7160->timer;
  int v7175 = v7165 + 1;
  v7160->timer = v7175;
  int * v7167 = v7160->regs;
  v7167[18] = 1;
  struct StateG * v7169 = slot_385(v7160);
  return v7169;
}

struct StateG * slot_397(struct StateG * v8630) {
  int v8631 = v8630->timer;
  int v8637 = v8631 + 1;
  v8630->timer = v8637;
  int * v8633 = v8630->regs;
  v8633[18] = 1;
  struct StateG * v8635 = slot_399(v8630);
  return v8635;
}

struct StateG * slot_476(struct StateG * v9844) {
  int * v9845 = v9844->saved_regs;
  int * v9846 = v9844->regs;
  int v9847 = v9846[18];
  v9845[18] = v9847;
  int v9849 = v9844->timer;
  int v9859 = v9849 + 1;
  v9844->timer = v9859;
  int * v9851 = v9844->regs;
  v9851[18] = 2;
  struct StateG * v9853 = slot_508(v9844);
  return v9853;
}

struct StateG * slot_655(struct StateG * v13564) {
  int * v13565 = v13564->regs;
  int v13566 = v13565[16];
  int v13567 = v13565[17];
  bool v13587 = v13566 < v13567;
  struct StateG * v13582;
  if (v13587) {
    int * v13568 = v13564->pht;
    v13568[12] = 1;
    int v13570 = v13564->timer;
    int v13591 = v13570 + 15;
    v13564->timer = v13591;
    int * v13572 = v13564->saved_regs;
    int v13573 = v13572[18];
    int * v13574 = v13564->regs;
    v13574[18] = v13573;
    struct StateG * v13576 = slot_694(v13564);
    v13582 = v13576;
  } else {
    int * v13578 = v13564->pht;
    v13578[12] = 0;
    struct StateG * v13580 = slot_695(v13564);
    v13582 = v13580;
  }
  return v13582;
}

struct StateG * slot_658(struct StateG * v13684) {
  int * v13685 = v13684->regs;
  int v13686 = v13685[16];
  int v13687 = v13685[17];
  bool v13707 = v13686 < v13687;
  struct StateG * v13702;
  if (v13707) {
    int * v13688 = v13684->pht;
    v13688[10] = 1;
    struct StateG * v13690 = slot_700(v13684);
    v13702 = v13690;
  } else {
    int * v13692 = v13684->pht;
    v13692[10] = 0;
    int v13694 = v13684->timer;
    int v13716 = v13694 + 15;
    v13684->timer = v13716;
    int * v13696 = v13684->saved_regs;
    int v13697 = v13696[18];
    int * v13698 = v13684->regs;
    v13698[18] = v13697;
    struct StateG * v13700 = slot_701(v13684);
    v13702 = v13700;
  }
  return v13702;
}

struct StateG * slot_851(struct StateG * v17782) {
  int * v17783 = v17782->regs;
  int v17784 = v17783[16];
  int v17785 = v17783[17];
  bool v17805 = v17784 >= v17785;
  struct StateG * v17800;
  if (v17805) {
    int * v17786 = v17782->pht;
    v17786[18] = 1;
    int v17788 = v17782->timer;
    int v17809 = v17788 + 15;
    v17782->timer = v17809;
    int * v17790 = v17782->saved_regs;
    int v17791 = v17790[19];
    int * v17792 = v17782->regs;
    v17792[19] = v17791;
    struct StateG * v17794 = slot_858(v17782);
    v17800 = v17794;
  } else {
    int * v17796 = v17782->pht;
    v17796[18] = 0;
    struct StateG * v17798 = slot_883(v17782);
    v17800 = v17798;
  }
  return v17800;
}

struct StateG * slot_835(struct StateG * v17144) {
  int * v17145 = v17144->regs;
  int v17146 = v17145[16];
  int v17147 = v17145[17];
  bool v17167 = v17146 >= v17147;
  struct StateG * v17162;
  if (v17167) {
    int * v17148 = v17144->pht;
    v17148[26] = 1;
    int v17150 = v17144->timer;
    int v17171 = v17150 + 15;
    v17144->timer = v17171;
    int * v17152 = v17144->saved_regs;
    int v17153 = v17152[19];
    int * v17154 = v17144->regs;
    v17154[19] = v17153;
    struct StateG * v17156 = slot_858(v17144);
    v17162 = v17156;
  } else {
    int * v17158 = v17144->pht;
    v17158[26] = 0;
    struct StateG * v17160 = slot_883(v17144);
    v17162 = v17160;
  }
  return v17162;
}

struct StateG * slot_295(struct StateG * v6124) {
  int v6125 = v6124->timer;
  int v6129 = v6125 + 1;
  v6124->timer = v6129;
  struct StateG * v6127 = slot_311(v6124);
  return v6127;
}

struct StateG * slot_315(struct StateG * v6400) {
  int v6401 = v6400->timer;
  int v6411 = v6401 + 1;
  v6400->timer = v6411;
  int * v6403 = v6400->pht;
  int v6404 = v6403[92];
  bool v6414 = !(v6404 == 0);
  struct StateG * v6409;
  if (v6414) {
    struct StateG * v6405 = slot_334(v6400);
    v6409 = v6405;
  } else {
    struct StateG * v6407 = slot_335(v6400);
    v6409 = v6407;
  }
  return v6409;
}

struct StateG * slot_802(struct StateG * v16264) {
  int * v16265 = v16264->saved_regs;
  int * v16266 = v16264->regs;
  int v16267 = v16266[19];
  v16265[19] = v16267;
  int v16269 = v16264->timer;
  int v16279 = v16269 + 1;
  v16264->timer = v16279;
  int * v16271 = v16264->regs;
  v16271[19] = 2;
  struct StateG * v16273 = slot_834(v16264);
  return v16273;
}

struct StateG * slot_545(struct StateG * v11624) {
  int v11625 = v11624->timer;
  int v11631 = v11625 + 1;
  v11624->timer = v11631;
  int * v11627 = v11624->regs;
  v11627[18] = 1;
  struct StateG * v11629 = slot_547(v11624);
  return v11629;
}

struct StateG * slot_17(struct StateG * v479) {
  int v480 = v479->timer;
  int v486 = v480 + 1;
  v479->timer = v486;
  int * v482 = v479->regs;
  v482[1] = 16;
  struct StateG * v484 = slot_19(v479);
  return v484;
}

struct StateG * slot_207(struct StateG * v4016) {
  int * v4017 = v4016->saved_regs;
  int * v4018 = v4016->regs;
  int v4019 = v4018[18];
  v4017[18] = v4019;
  int v4021 = v4016->timer;
  int v4031 = v4021 + 1;
  v4016->timer = v4031;
  int * v4023 = v4016->regs;
  v4023[18] = 1;
  struct StateG * v4025 = slot_239(v4016);
  return v4025;
}

struct StateG * slot_156(struct StateG * v3222) {
  int v3223 = v3222->timer;
  int v3227 = v3223 + 1;
  v3222->timer = v3227;
  struct StateG * v3225 = slot_178(v3222);
  return v3225;
}

struct StateG * slot_430(struct StateG * v8994) {
  int v8995 = v8994->timer;
  int v9001 = v8995 + 1;
  v8994->timer = v9001;
  int * v8997 = v8994->regs;
  v8997[17] = 10;
  struct StateG * v8999 = slot_446(v8994);
  return v8999;
}

struct StateG * slot_369(struct StateG * v7660) {
  int * v7661 = v7660->regs;
  int v7662 = v7661[16];
  int v7663 = v7661[17];
  bool v7683 = v7662 < v7663;
  struct StateG * v7678;
  if (v7683) {
    int * v7664 = v7660->pht;
    v7664[91] = 1;
    int v7666 = v7660->timer;
    int v7687 = v7666 + 15;
    v7660->timer = v7687;
    int * v7668 = v7660->saved_regs;
    int v7669 = v7668[18];
    int * v7670 = v7660->regs;
    v7670[18] = v7669;
    struct StateG * v7672 = slot_410(v7660);
    v7678 = v7672;
  } else {
    int * v7674 = v7660->pht;
    v7674[91] = 0;
    struct StateG * v7676 = slot_411(v7660);
    v7678 = v7676;
  }
  return v7678;
}

struct StateG * slot_461(struct StateG * v9544) {
  int * v9545 = v9544->saved_regs;
  int * v9546 = v9544->regs;
  int v9547 = v9546[18];
  v9545[18] = v9547;
  int v9549 = v9544->timer;
  int v9559 = v9549 + 1;
  v9544->timer = v9559;
  int * v9551 = v9544->regs;
  v9551[18] = 1;
  struct StateG * v9553 = slot_493(v9544);
  return v9553;
}

struct StateG * slot_631(struct StateG * v12944) {
  int * v12945 = v12944->saved_regs;
  int * v12946 = v12944->regs;
  int v12947 = v12946[18];
  v12945[18] = v12947;
  int v12949 = v12944->timer;
  int v12959 = v12949 + 1;
  v12944->timer = v12959;
  int * v12951 = v12944->regs;
  v12951[18] = 1;
  struct StateG * v12953 = slot_663(v12944);
  return v12953;
}

struct StateG * slot_164(struct StateG * v3306) {
  int v3307 = v3306->timer;
  int v3311 = v3307 + 1;
  v3306->timer = v3311;
  struct StateG * v3309 = slot_182(v3306);
  return v3309;
}

struct StateG * slot_847(struct StateG * v17624) {
  int * v17625 = v17624->regs;
  int v17626 = v17625[16];
  int v17627 = v17625[17];
  bool v17647 = v17626 >= v17627;
  struct StateG * v17642;
  if (v17647) {
    int * v17628 = v17624->pht;
    v17628[20] = 1;
    int v17630 = v17624->timer;
    int v17651 = v17630 + 15;
    v17624->timer = v17651;
    int * v17632 = v17624->saved_regs;
    int v17633 = v17632[19];
    int * v17634 = v17624->regs;
    v17634[19] = v17633;
    struct StateG * v17636 = slot_858(v17624);
    v17642 = v17636;
  } else {
    int * v17638 = v17624->pht;
    v17638[20] = 0;
    struct StateG * v17640 = slot_883(v17624);
    v17642 = v17640;
  }
  return v17642;
}

struct StateG * slot_133(struct StateG * v2892) {
  int * v2893 = v2892->regs;
  int v2894 = v2893[16];
  int v2895 = v2893[17];
  bool v2915 = v2894 < v2895;
  struct StateG * v2910;
  if (v2915) {
    int * v2896 = v2892->pht;
    v2896[49] = 1;
    int v2898 = v2892->timer;
    int v2919 = v2898 + 15;
    v2892->timer = v2919;
    int * v2900 = v2892->saved_regs;
    int v2901 = v2900[18];
    int * v2902 = v2892->regs;
    v2902[18] = v2901;
    struct StateG * v2904 = slot_162(v2892);
    v2910 = v2904;
  } else {
    int * v2906 = v2892->pht;
    v2906[49] = 0;
    struct StateG * v2908 = slot_163(v2892);
    v2910 = v2908;
  }
  return v2910;
}

struct StateG * slot_56(struct StateG * v1140) {
  int * v1141 = v1140->saved_regs;
  int * v1142 = v1140->regs;
  int v1143 = v1142[18];
  v1141[18] = v1143;
  int v1145 = v1140->timer;
  int v1155 = v1145 + 1;
  v1140->timer = v1155;
  int * v1147 = v1140->regs;
  v1147[18] = 2;
  struct StateG * v1149 = slot_64(v1140);
  return v1149;
}

struct StateG * slot_564(struct StateG * v11856) {
  int v11857 = v11856->timer;
  int v11863 = v11857 + 1;
  v11856->timer = v11863;
  int * v11859 = v11856->regs;
  v11859[1] = 148;
  struct StateG * v11861 = slot_580(v11856);
  return v11861;
}

struct StateG * slot_823(struct StateG * v16684) {
  int * v16685 = v16684->saved_regs;
  int * v16686 = v16684->regs;
  int v16687 = v16686[19];
  v16685[19] = v16687;
  int v16689 = v16684->timer;
  int v16699 = v16689 + 1;
  v16684->timer = v16699;
  int * v16691 = v16684->regs;
  v16691[19] = 1;
  struct StateG * v16693 = slot_855(v16684);
  return v16693;
}

struct StateG * slot_630(struct StateG * v12924) {
  int * v12925 = v12924->saved_regs;
  int * v12926 = v12924->regs;
  int v12927 = v12926[18];
  v12925[18] = v12927;
  int v12929 = v12924->timer;
  int v12939 = v12929 + 1;
  v12924->timer = v12939;
  int * v12931 = v12924->regs;
  v12931[18] = 2;
  struct StateG * v12933 = slot_662(v12924);
  return v12933;
}

struct StateG * slot_377(struct StateG * v7980) {
  int * v7981 = v7980->regs;
  int v7982 = v7981[16];
  int v7983 = v7981[17];
  bool v8003 = v7982 < v7983;
  struct StateG * v7998;
  if (v8003) {
    int * v7984 = v7980->pht;
    v7984[87] = 1;
    int v7986 = v7980->timer;
    int v8007 = v7986 + 15;
    v7980->timer = v8007;
    int * v7988 = v7980->saved_regs;
    int v7989 = v7988[18];
    int * v7990 = v7980->regs;
    v7990[18] = v7989;
    struct StateG * v7992 = slot_394(v7980);
    v7998 = v7992;
  } else {
    int * v7994 = v7980->pht;
    v7994[87] = 0;
    struct StateG * v7996 = slot_395(v7980);
    v7998 = v7996;
  }
  return v7998;
}

struct StateG * slot_768(struct StateG * v15640) {
  int v15641 = v15640->timer;
  int v15647 = v15641 + 1;
  v15640->timer = v15647;
  int * v15643 = v15640->regs;
  v15643[17] = 10;
  struct StateG * v15645 = slot_784(v15640);
  return v15645;
}

struct StateG * slot_427(struct StateG * v8955) {
  int v8956 = v8955->timer;
  int v8962 = v8956 + 1;
  v8955->timer = v8962;
  int * v8958 = v8955->regs;
  v8958[17] = 10;
  struct StateG * v8960 = slot_443(v8955);
  return v8960;
}

struct StateG * slot_464(struct StateG * v9604) {
  int * v9605 = v9604->saved_regs;
  int * v9606 = v9604->regs;
  int v9607 = v9606[18];
  v9605[18] = v9607;
  int v9609 = v9604->timer;
  int v9619 = v9609 + 1;
  v9604->timer = v9619;
  int * v9611 = v9604->regs;
  v9611[18] = 2;
  struct StateG * v9613 = slot_496(v9604);
  return v9613;
}

struct StateG * slot_433(struct StateG * v9033) {
  int v9034 = v9033->timer;
  int v9040 = v9034 + 1;
  v9033->timer = v9040;
  int * v9036 = v9033->regs;
  v9036[17] = 10;
  struct StateG * v9038 = slot_449(v9033);
  return v9038;
}

struct StateG * slot_121(struct StateG * v2412) {
  int * v2413 = v2412->regs;
  int v2414 = v2413[16];
  int v2415 = v2413[17];
  bool v2435 = v2414 < v2415;
  struct StateG * v2430;
  if (v2435) {
    int * v2416 = v2412->pht;
    v2416[55] = 1;
    int v2418 = v2412->timer;
    int v2439 = v2418 + 15;
    v2412->timer = v2439;
    int * v2420 = v2412->saved_regs;
    int v2421 = v2420[18];
    int * v2422 = v2412->regs;
    v2422[18] = v2421;
    struct StateG * v2424 = slot_138(v2412);
    v2430 = v2424;
  } else {
    int * v2426 = v2412->pht;
    v2426[55] = 0;
    struct StateG * v2428 = slot_139(v2412);
    v2430 = v2428;
  }
  return v2430;
}

struct StateG * slot_610(struct StateG * v12524) {
  int v12525 = v12524->timer;
  int v12535 = v12525 + 1;
  v12524->timer = v12535;
  int * v12527 = v12524->pht;
  int v12528 = v12527[5];
  bool v12538 = !(v12528 == 0);
  struct StateG * v12533;
  if (v12538) {
    struct StateG * v12529 = slot_636(v12524);
    v12533 = v12529;
  } else {
    struct StateG * v12531 = slot_637(v12524);
    v12533 = v12531;
  }
  return v12533;
}

struct StateG * slot_144(struct StateG * v3096) {
  int v3097 = v3096->timer;
  int v3101 = v3097 + 1;
  v3096->timer = v3101;
  struct StateG * v3099 = slot_172(v3096);
  return v3099;
}

struct StateG * slot_492(struct StateG * v10244) {
  int * v10245 = v10244->regs;
  int v10246 = v10245[16];
  int v10247 = v10245[17];
  bool v10267 = v10246 < v10247;
  struct StateG * v10262;
  if (v10267) {
    int * v10248 = v10244->pht;
    v10248[109] = 1;
    struct StateG * v10250 = slot_528(v10244);
    v10262 = v10250;
  } else {
    int * v10252 = v10244->pht;
    v10252[109] = 0;
    int v10254 = v10244->timer;
    int v10276 = v10254 + 15;
    v10244->timer = v10276;
    int * v10256 = v10244->saved_regs;
    int v10257 = v10256[18];
    int * v10258 = v10244->regs;
    v10258[18] = v10257;
    struct StateG * v10260 = slot_529(v10244);
    v10262 = v10260;
  }
  return v10262;
}

struct StateG * slot_201(struct StateG * v3896) {
  int * v3897 = v3896->saved_regs;
  int * v3898 = v3896->regs;
  int v3899 = v3898[18];
  v3897[18] = v3899;
  int v3901 = v3896->timer;
  int v3911 = v3901 + 1;
  v3896->timer = v3911;
  int * v3903 = v3896->regs;
  v3903[18] = 1;
  struct StateG * v3905 = slot_233(v3896);
  return v3905;
}

struct StateG * slot_600(struct StateG * v12324) {
  int v12325 = v12324->timer;
  int v12335 = v12325 + 1;
  v12324->timer = v12335;
  int * v12327 = v12324->pht;
  int v12328 = v12327[15];
  bool v12338 = !(v12328 == 0);
  struct StateG * v12333;
  if (v12338) {
    struct StateG * v12329 = slot_616(v12324);
    v12333 = v12329;
  } else {
    struct StateG * v12331 = slot_617(v12324);
    v12333 = v12331;
  }
  return v12333;
}

struct StateG * slot_63(struct StateG * v1280) {
  int * v1281 = v1280->saved_regs;
  int * v1282 = v1280->regs;
  int v1283 = v1282[18];
  v1281[18] = v1283;
  int v1285 = v1280->timer;
  int v1295 = v1285 + 1;
  v1280->timer = v1295;
  int * v1287 = v1280->regs;
  v1287[18] = 1;
  struct StateG * v1289 = slot_71(v1280);
  return v1289;
}

struct StateG * slot_195(struct StateG * v3776) {
  int v3777 = v3776->timer;
  int v3787 = v3777 + 1;
  v3776->timer = v3787;
  int * v3779 = v3776->pht;
  int v3780 = v3779[68];
  bool v3790 = !(v3780 == 0);
  struct StateG * v3785;
  if (v3790) {
    struct StateG * v3781 = slot_222(v3776);
    v3785 = v3781;
  } else {
    struct StateG * v3783 = slot_223(v3776);
    v3785 = v3783;
  }
  return v3785;
}

struct StateG * slot_326(struct StateG * v6620) {
  int v6621 = v6620->timer;
  int v6631 = v6621 + 1;
  v6620->timer = v6631;
  int * v6623 = v6620->pht;
  int v6624 = v6623[81];
  bool v6634 = !(v6624 == 0);
  struct StateG * v6629;
  if (v6634) {
    struct StateG * v6625 = slot_356(v6620);
    v6629 = v6625;
  } else {
    struct StateG * v6627 = slot_357(v6620);
    v6629 = v6627;
  }
  return v6629;
}

struct StateG * slot_303(struct StateG * v6223) {
  int v6224 = v6223->timer;
  int v6230 = v6224 + 1;
  v6223->timer = v6230;
  int * v6226 = v6223->regs;
  v6226[17] = 10;
  struct StateG * v6228 = slot_319(v6223);
  return v6228;
}

struct StateG * slot_335(struct StateG * v6800) {
  int * v6801 = v6800->saved_regs;
  int * v6802 = v6800->regs;
  int v6803 = v6802[18];
  v6801[18] = v6803;
  int v6805 = v6800->timer;
  int v6815 = v6805 + 1;
  v6800->timer = v6815;
  int * v6807 = v6800->regs;
  v6807[18] = 1;
  struct StateG * v6809 = slot_367(v6800);
  return v6809;
}

struct StateG * slot_223(struct StateG * v4336) {
  int * v4337 = v4336->saved_regs;
  int * v4338 = v4336->regs;
  int v4339 = v4338[18];
  v4337[18] = v4339;
  int v4341 = v4336->timer;
  int v4351 = v4341 + 1;
  v4336->timer = v4351;
  int * v4343 = v4336->regs;
  v4343[18] = 1;
  struct StateG * v4345 = slot_255(v4336);
  return v4345;
}

struct StateG * slot_773(struct StateG * v15705) {
  int v15706 = v15705->timer;
  int v15712 = v15706 + 1;
  v15705->timer = v15712;
  int * v15708 = v15705->regs;
  v15708[17] = 10;
  struct StateG * v15710 = slot_789(v15705);
  return v15710;
}

struct StateG * slot_237(struct StateG * v4716) {
  int * v4717 = v4716->regs;
  int v4718 = v4717[16];
  int v4719 = v4717[17];
  bool v4739 = v4718 < v4719;
  struct StateG * v4734;
  if (v4739) {
    int * v4720 = v4716->pht;
    v4720[77] = 1;
    int v4722 = v4716->timer;
    int v4743 = v4722 + 15;
    v4716->timer = v4743;
    int * v4724 = v4716->saved_regs;
    int v4725 = v4724[18];
    int * v4726 = v4716->regs;
    v4726[18] = v4725;
    struct StateG * v4728 = slot_274(v4716);
    v4734 = v4728;
  } else {
    int * v4730 = v4716->pht;
    v4730[77] = 0;
    struct StateG * v4732 = slot_275(v4716);
    v4734 = v4732;
  }
  return v4734;
}

struct StateG * slot_41(struct StateG * v914) {
  int v915 = v914->timer;
  int v922 = v915 + 1;
  v914->timer = v922;
  int * v917 = v914->regs;
  int v918 = v917[1];
  bool v925 = v918 == 24;
  ret_assert(v925);
  struct StateG * v920 = slot_45(v914);
  return v920;
}

struct StateG * slot_668(struct StateG * v14084) {
  int * v14085 = v14084->regs;
  int v14086 = v14085[16];
  int v14087 = v14085[17];
  bool v14107 = v14086 < v14087;
  struct StateG * v14102;
  if (v14107) {
    int * v14088 = v14084->pht;
    v14088[5] = 1;
    struct StateG * v14090 = slot_688(v14084);
    v14102 = v14090;
  } else {
    int * v14092 = v14084->pht;
    v14092[5] = 0;
    int v14094 = v14084->timer;
    int v14116 = v14094 + 15;
    v14084->timer = v14116;
    int * v14096 = v14084->saved_regs;
    int v14097 = v14096[18];
    int * v14098 = v14084->regs;
    v14098[18] = v14097;
    struct StateG * v14100 = slot_689(v14084);
    v14102 = v14100;
  }
  return v14102;
}

struct StateG * slot_537(struct StateG * v11540) {
  int v11541 = v11540->timer;
  int v11547 = v11541 + 1;
  v11540->timer = v11547;
  int * v11543 = v11540->regs;
  v11543[18] = 1;
  struct StateG * v11545 = slot_539(v11540);
  return v11545;
}

struct StateG * slot_737(struct StateG * v15237) {
  int v15238 = v15237->timer;
  int v15244 = v15238 + 1;
  v15237->timer = v15244;
  int * v15240 = v15237->regs;
  v15240[1] = 156;
  struct StateG * v15242 = slot_753(v15237);
  return v15242;
}

struct StateG * slot_289(struct StateG * v6056) {
  int v6057 = v6056->timer;
  int v6063 = v6057 + 1;
  v6056->timer = v6063;
  int * v6059 = v6056->regs;
  v6059[18] = 1;
  struct StateG * v6061 = slot_291(v6056);
  return v6061;
}

struct StateG * slot_238(struct StateG * v4756) {
  int * v4757 = v4756->regs;
  int v4758 = v4757[16];
  int v4759 = v4757[17];
  bool v4779 = v4758 < v4759;
  struct StateG * v4774;
  if (v4779) {
    int * v4760 = v4756->pht;
    v4760[76] = 1;
    struct StateG * v4762 = slot_276(v4756);
    v4774 = v4762;
  } else {
    int * v4764 = v4756->pht;
    v4764[76] = 0;
    int v4766 = v4756->timer;
    int v4788 = v4766 + 15;
    v4756->timer = v4788;
    int * v4768 = v4756->saved_regs;
    int v4769 = v4768[18];
    int * v4770 = v4756->regs;
    v4770[18] = v4769;
    struct StateG * v4772 = slot_277(v4756);
    v4774 = v4772;
  }
  return v4774;
}

struct StateG * slot_544(struct StateG * v11616) {
  int v11617 = v11616->timer;
  int v11621 = v11617 + 1;
  v11616->timer = v11621;
  struct StateG * v11619 = slot_564(v11616);
  return v11619;
}

struct StateG * slot_573(struct StateG * v11973) {
  int v11974 = v11973->timer;
  int v11980 = v11974 + 1;
  v11973->timer = v11980;
  int * v11976 = v11973->regs;
  v11976[1] = 156;
  struct StateG * v11978 = slot_589(v11973);
  return v11978;
}

struct StateG * slot_245(struct StateG * v5036) {
  int * v5037 = v5036->regs;
  int v5038 = v5037[16];
  int v5039 = v5037[17];
  bool v5059 = v5038 < v5039;
  struct StateG * v5054;
  if (v5059) {
    int * v5040 = v5036->pht;
    v5040[73] = 1;
    int v5042 = v5036->timer;
    int v5063 = v5042 + 15;
    v5036->timer = v5063;
    int * v5044 = v5036->saved_regs;
    int v5045 = v5044[18];
    int * v5046 = v5036->regs;
    v5046[18] = v5045;
    struct StateG * v5048 = slot_290(v5036);
    v5054 = v5048;
  } else {
    int * v5050 = v5036->pht;
    v5050[73] = 0;
    struct StateG * v5052 = slot_291(v5036);
    v5054 = v5052;
  }
  return v5054;
}

struct StateG * slot_388(struct StateG * v8420) {
  int * v8421 = v8420->regs;
  int v8422 = v8421[16];
  int v8423 = v8421[17];
  bool v8443 = v8422 < v8423;
  struct StateG * v8438;
  if (v8443) {
    int * v8424 = v8420->pht;
    v8424[81] = 1;
    struct StateG * v8426 = slot_416(v8420);
    v8438 = v8426;
  } else {
    int * v8428 = v8420->pht;
    v8428[81] = 0;
    int v8430 = v8420->timer;
    int v8452 = v8430 + 15;
    v8420->timer = v8452;
    int * v8432 = v8420->saved_regs;
    int v8433 = v8432[18];
    int * v8434 = v8420->regs;
    v8434[18] = v8433;
    struct StateG * v8436 = slot_417(v8420);
    v8438 = v8436;
  }
  return v8438;
}

struct StateG * slot_103(struct StateG * v2032) {
  int v2033 = v2032->timer;
  int v2043 = v2033 + 1;
  v2032->timer = v2043;
  int * v2035 = v2032->pht;
  int v2036 = v2035[48];
  bool v2046 = !(v2036 == 0);
  struct StateG * v2041;
  if (v2046) {
    struct StateG * v2037 = slot_118(v2032);
    v2041 = v2037;
  } else {
    struct StateG * v2039 = slot_119(v2032);
    v2041 = v2039;
  }
  return v2041;
}

struct StateG * slot_324(struct StateG * v6580) {
  int v6581 = v6580->timer;
  int v6591 = v6581 + 1;
  v6580->timer = v6591;
  int * v6583 = v6580->pht;
  int v6584 = v6583[83];
  bool v6594 = !(v6584 == 0);
  struct StateG * v6589;
  if (v6594) {
    struct StateG * v6585 = slot_352(v6580);
    v6589 = v6585;
  } else {
    struct StateG * v6587 = slot_353(v6580);
    v6589 = v6587;
  }
  return v6589;
}

struct StateG * slot_440(struct StateG * v9124) {
  int v9125 = v9124->timer;
  int v9135 = v9125 + 1;
  v9124->timer = v9135;
  int * v9127 = v9124->pht;
  int v9128 = v9127[111];
  bool v9138 = !(v9128 == 0);
  struct StateG * v9133;
  if (v9138) {
    struct StateG * v9129 = slot_456(v9124);
    v9133 = v9129;
  } else {
    struct StateG * v9131 = slot_457(v9124);
    v9133 = v9131;
  }
  return v9133;
}

struct StateG * slot_781(struct StateG * v15844) {
  int v15845 = v15844->timer;
  int v15855 = v15845 + 1;
  v15844->timer = v15855;
  int * v15847 = v15844->pht;
  int v15848 = v15847[26];
  bool v15858 = !(v15848 == 0);
  struct StateG * v15853;
  if (v15858) {
    struct StateG * v15849 = slot_802(v15844);
    v15853 = v15849;
  } else {
    struct StateG * v15851 = slot_803(v15844);
    v15853 = v15851;
  }
  return v15853;
}

struct StateG * slot_788(struct StateG * v15984) {
  int v15985 = v15984->timer;
  int v15995 = v15985 + 1;
  v15984->timer = v15995;
  int * v15987 = v15984->pht;
  int v15988 = v15987[19];
  bool v15998 = !(v15988 == 0);
  struct StateG * v15993;
  if (v15998) {
    struct StateG * v15989 = slot_816(v15984);
    v15993 = v15989;
  } else {
    struct StateG * v15991 = slot_817(v15984);
    v15993 = v15991;
  }
  return v15993;
}

struct StateG * slot_547(struct StateG * v11650) {
  int v11651 = v11650->timer;
  int v11655 = v11651 + 1;
  v11650->timer = v11655;
  struct StateG * v11653 = slot_565(v11650);
  return v11653;
}

struct StateG * slot_518(struct StateG * v11284) {
  int * v11285 = v11284->regs;
  int v11286 = v11285[16];
  int v11287 = v11285[17];
  bool v11307 = v11286 < v11287;
  struct StateG * v11302;
  if (v11307) {
    int * v11288 = v11284->pht;
    v11288[96] = 1;
    struct StateG * v11290 = slot_548(v11284);
    v11302 = v11290;
  } else {
    int * v11292 = v11284->pht;
    v11292[96] = 0;
    int v11294 = v11284->timer;
    int v11316 = v11294 + 15;
    v11284->timer = v11316;
    int * v11296 = v11284->saved_regs;
    int v11297 = v11296[18];
    int * v11298 = v11284->regs;
    v11298[18] = v11297;
    struct StateG * v11300 = slot_549(v11284);
    v11302 = v11300;
  }
  return v11302;
}

struct StateG * slot_451(struct StateG * v9344) {
  int v9345 = v9344->timer;
  int v9355 = v9345 + 1;
  v9344->timer = v9355;
  int * v9347 = v9344->pht;
  int v9348 = v9347[100];
  bool v9358 = !(v9348 == 0);
  struct StateG * v9353;
  if (v9358) {
    struct StateG * v9349 = slot_478(v9344);
    v9353 = v9349;
  } else {
    struct StateG * v9351 = slot_479(v9344);
    v9353 = v9351;
  }
  return v9353;
}

struct StateG * slot_458(struct StateG * v9484) {
  int * v9485 = v9484->saved_regs;
  int * v9486 = v9484->regs;
  int v9487 = v9486[18];
  v9485[18] = v9487;
  int v9489 = v9484->timer;
  int v9499 = v9489 + 1;
  v9484->timer = v9499;
  int * v9491 = v9484->regs;
  v9491[18] = 2;
  struct StateG * v9493 = slot_490(v9484);
  return v9493;
}

struct StateG * slot_415(struct StateG * v8824) {
  int v8825 = v8824->timer;
  int v8829 = v8825 + 1;
  v8824->timer = v8829;
  struct StateG * v8827 = slot_435(v8824);
  return v8827;
}

struct StateG * slot_613(struct StateG * v12584) {
  int v12585 = v12584->timer;
  int v12595 = v12585 + 1;
  v12584->timer = v12595;
  int * v12587 = v12584->pht;
  int v12588 = v12587[2];
  bool v12598 = !(v12588 == 0);
  struct StateG * v12593;
  if (v12598) {
    struct StateG * v12589 = slot_642(v12584);
    v12593 = v12589;
  } else {
    struct StateG * v12591 = slot_643(v12584);
    v12593 = v12591;
  }
  return v12593;
}

struct StateG * slot_832(struct StateG * v17024) {
  int * v17025 = v17024->regs;
  int v17026 = v17025[16];
  int v17027 = v17025[17];
  bool v17047 = v17026 >= v17027;
  struct StateG * v17042;
  if (v17047) {
    int * v17028 = v17024->pht;
    v17028[27] = 1;
    struct StateG * v17030 = slot_883(v17024);
    v17042 = v17030;
  } else {
    int * v17032 = v17024->pht;
    v17032[27] = 0;
    int v17034 = v17024->timer;
    int v17056 = v17034 + 15;
    v17024->timer = v17056;
    int * v17036 = v17024->saved_regs;
    int v17037 = v17036[19];
    int * v17038 = v17024->regs;
    v17038[19] = v17037;
    struct StateG * v17040 = slot_861(v17024);
    v17042 = v17040;
  }
  return v17042;
}

struct StateG * slot_531(struct StateG * v11482) {
  int v11483 = v11482->timer;
  int v11487 = v11483 + 1;
  v11482->timer = v11487;
  struct StateG * v11485 = slot_557(v11482);
  return v11485;
}

struct StateG * slot_321(struct StateG * v6520) {
  int v6521 = v6520->timer;
  int v6531 = v6521 + 1;
  v6520->timer = v6531;
  int * v6523 = v6520->pht;
  int v6524 = v6523[86];
  bool v6534 = !(v6524 == 0);
  struct StateG * v6529;
  if (v6534) {
    struct StateG * v6525 = slot_346(v6520);
    v6529 = v6525;
  } else {
    struct StateG * v6527 = slot_347(v6520);
    v6529 = v6527;
  }
  return v6529;
}

struct StateG * slot_317(struct StateG * v6440) {
  int v6441 = v6440->timer;
  int v6451 = v6441 + 1;
  v6440->timer = v6451;
  int * v6443 = v6440->pht;
  int v6444 = v6443[90];
  bool v6454 = !(v6444 == 0);
  struct StateG * v6449;
  if (v6454) {
    struct StateG * v6445 = slot_338(v6440);
    v6449 = v6445;
  } else {
    struct StateG * v6447 = slot_339(v6440);
    v6449 = v6447;
  }
  return v6449;
}

struct StateG * slot_558(struct StateG * v11778) {
  int v11779 = v11778->timer;
  int v11785 = v11779 + 1;
  v11778->timer = v11785;
  int * v11781 = v11778->regs;
  v11781[1] = 148;
  struct StateG * v11783 = slot_574(v11778);
  return v11783;
}

struct StateG * slot_205(struct StateG * v3976) {
  int * v3977 = v3976->saved_regs;
  int * v3978 = v3976->regs;
  int v3979 = v3978[18];
  v3977[18] = v3979;
  int v3981 = v3976->timer;
  int v3991 = v3981 + 1;
  v3976->timer = v3991;
  int * v3983 = v3976->regs;
  v3983[18] = 1;
  struct StateG * v3985 = slot_237(v3976);
  return v3985;
}

struct StateG * slot_193(struct StateG * v3736) {
  int v3737 = v3736->timer;
  int v3747 = v3737 + 1;
  v3736->timer = v3747;
  int * v3739 = v3736->pht;
  int v3740 = v3739[70];
  bool v3750 = !(v3740 == 0);
  struct StateG * v3745;
  if (v3750) {
    struct StateG * v3741 = slot_218(v3736);
    v3745 = v3741;
  } else {
    struct StateG * v3743 = slot_219(v3736);
    v3745 = v3743;
  }
  return v3745;
}

struct StateG * slot_375(struct StateG * v7900) {
  int * v7901 = v7900->regs;
  int v7902 = v7901[16];
  int v7903 = v7901[17];
  bool v7923 = v7902 < v7903;
  struct StateG * v7918;
  if (v7923) {
    int * v7904 = v7900->pht;
    v7904[88] = 1;
    int v7906 = v7900->timer;
    int v7927 = v7906 + 15;
    v7900->timer = v7927;
    int * v7908 = v7900->saved_regs;
    int v7909 = v7908[18];
    int * v7910 = v7900->regs;
    v7910[18] = v7909;
    struct StateG * v7912 = slot_422(v7900);
    v7918 = v7912;
  } else {
    int * v7914 = v7900->pht;
    v7914[88] = 0;
    struct StateG * v7916 = slot_423(v7900);
    v7918 = v7916;
  }
  return v7918;
}

struct StateG * slot_759(struct StateG * v15523) {
  int v15524 = v15523->timer;
  int v15530 = v15524 + 1;
  v15523->timer = v15530;
  int * v15526 = v15523->regs;
  v15526[1] = 164;
  struct StateG * v15528 = slot_775(v15523);
  return v15528;
}

struct StateG * slot_637(struct StateG * v13064) {
  int * v13065 = v13064->saved_regs;
  int * v13066 = v13064->regs;
  int v13067 = v13066[18];
  v13065[18] = v13067;
  int v13069 = v13064->timer;
  int v13079 = v13069 + 1;
  v13064->timer = v13079;
  int * v13071 = v13064->regs;
  v13071[18] = 1;
  struct StateG * v13073 = slot_669(v13064);
  return v13073;
}

struct StateG * slot_793(struct StateG * v16084) {
  int * v16085 = v16084->saved_regs;
  int * v16086 = v16084->regs;
  int v16087 = v16086[19];
  v16085[19] = v16087;
  int v16089 = v16084->timer;
  int v16099 = v16089 + 1;
  v16084->timer = v16099;
  int * v16091 = v16084->regs;
  v16091[19] = 1;
  struct StateG * v16093 = slot_825(v16084);
  return v16093;
}

struct StateG * slot_380(struct StateG * v8100) {
  int * v8101 = v8100->regs;
  int v8102 = v8101[16];
  int v8103 = v8101[17];
  bool v8123 = v8102 < v8103;
  struct StateG * v8118;
  if (v8123) {
    int * v8104 = v8100->pht;
    v8104[85] = 1;
    struct StateG * v8106 = slot_400(v8100);
    v8118 = v8106;
  } else {
    int * v8108 = v8100->pht;
    v8108[85] = 0;
    int v8110 = v8100->timer;
    int v8132 = v8110 + 15;
    v8100->timer = v8132;
    int * v8112 = v8100->saved_regs;
    int v8113 = v8112[18];
    int * v8114 = v8100->regs;
    v8114[18] = v8113;
    struct StateG * v8116 = slot_401(v8100);
    v8118 = v8116;
  }
  return v8118;
}

struct StateG * slot_636(struct StateG * v13044) {
  int * v13045 = v13044->saved_regs;
  int * v13046 = v13044->regs;
  int v13047 = v13046[18];
  v13045[18] = v13047;
  int v13049 = v13044->timer;
  int v13059 = v13049 + 1;
  v13044->timer = v13059;
  int * v13051 = v13044->regs;
  v13051[18] = 2;
  struct StateG * v13053 = slot_668(v13044);
  return v13053;
}

struct StateG * slot_478(struct StateG * v9884) {
  int * v9885 = v9884->saved_regs;
  int * v9886 = v9884->regs;
  int v9887 = v9886[18];
  v9885[18] = v9887;
  int v9889 = v9884->timer;
  int v9899 = v9889 + 1;
  v9884->timer = v9899;
  int * v9891 = v9884->regs;
  v9891[18] = 2;
  struct StateG * v9893 = slot_510(v9884);
  return v9893;
}

struct StateG * slot_775(struct StateG * v15731) {
  int v15732 = v15731->timer;
  int v15738 = v15732 + 1;
  v15731->timer = v15738;
  int * v15734 = v15731->regs;
  v15734[17] = 10;
  struct StateG * v15736 = slot_791(v15731);
  return v15736;
}

struct StateG * slot_695(struct StateG * v14720) {
  int v14721 = v14720->timer;
  int v14725 = v14721 + 1;
  v14720->timer = v14725;
  struct StateG * v14723 = slot_719(v14720);
  return v14723;
}

struct StateG * slot_246(struct StateG * v5076) {
  int * v5077 = v5076->regs;
  int v5078 = v5077[16];
  int v5079 = v5077[17];
  bool v5099 = v5078 < v5079;
  struct StateG * v5094;
  if (v5099) {
    int * v5080 = v5076->pht;
    v5080[72] = 1;
    struct StateG * v5082 = slot_292(v5076);
    v5094 = v5082;
  } else {
    int * v5084 = v5076->pht;
    v5084[72] = 0;
    int v5086 = v5076->timer;
    int v5108 = v5086 + 15;
    v5076->timer = v5108;
    int * v5088 = v5076->saved_regs;
    int v5089 = v5088[18];
    int * v5090 = v5076->regs;
    v5090[18] = v5089;
    struct StateG * v5092 = slot_293(v5076);
    v5094 = v5092;
  }
  return v5094;
}

struct StateG * slot_284(struct StateG * v6006) {
  int v6007 = v6006->timer;
  int v6011 = v6007 + 1;
  v6006->timer = v6011;
  struct StateG * v6009 = slot_306(v6006);
  return v6009;
}

struct StateG * slot_3(struct StateG * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[1] = 16;
  struct StateG * v237 = slot_4(v232);
  return v237;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[16] = v121;
  struct StateG * v124 = slot_2(v15);
  return v124;
}

struct StateG * slot_446(struct StateG * v9244) {
  int v9245 = v9244->timer;
  int v9255 = v9245 + 1;
  v9244->timer = v9255;
  int * v9247 = v9244->pht;
  int v9248 = v9247[105];
  bool v9258 = !(v9248 == 0);
  struct StateG * v9253;
  if (v9258) {
    struct StateG * v9249 = slot_468(v9244);
    v9253 = v9249;
  } else {
    struct StateG * v9251 = slot_469(v9244);
    v9253 = v9251;
  }
  return v9253;
}

struct StateG * slot_38(struct StateG * v879) {
  int v880 = v879->timer;
  int v886 = v880 + 1;
  v879->timer = v886;
  int * v882 = v879->regs;
  v882[19] = 2;
  struct StateG * v884 = slot_36(v879);
  return v884;
}

struct StateG * slot_159(struct StateG * v3256) {
  int v3257 = v3256->timer;
  int v3261 = v3257 + 1;
  v3256->timer = v3261;
  struct StateG * v3259 = slot_179(v3256);
  return v3259;
}

struct StateG * slot_684(struct StateG * v14602) {
  int v14603 = v14602->timer;
  int v14607 = v14603 + 1;
  v14602->timer = v14607;
  struct StateG * v14605 = slot_714(v14602);
  return v14605;
}

struct StateG * slot_459(struct StateG * v9504) {
  int * v9505 = v9504->saved_regs;
  int * v9506 = v9504->regs;
  int v9507 = v9506[18];
  v9505[18] = v9507;
  int v9509 = v9504->timer;
  int v9519 = v9509 + 1;
  v9504->timer = v9519;
  int * v9511 = v9504->regs;
  v9511[18] = 1;
  struct StateG * v9513 = slot_491(v9504);
  return v9513;
}

struct StateG * slot_812(struct StateG * v16464) {
  int * v16465 = v16464->saved_regs;
  int * v16466 = v16464->regs;
  int v16467 = v16466[19];
  v16465[19] = v16467;
  int v16469 = v16464->timer;
  int v16479 = v16469 + 1;
  v16464->timer = v16479;
  int * v16471 = v16464->regs;
  v16471[19] = 2;
  struct StateG * v16473 = slot_844(v16464);
  return v16473;
}

struct StateG * slot_132(struct StateG * v2852) {
  int * v2853 = v2852->regs;
  int v2854 = v2853[16];
  int v2855 = v2853[17];
  bool v2875 = v2854 < v2855;
  struct StateG * v2870;
  if (v2875) {
    int * v2856 = v2852->pht;
    v2856[49] = 1;
    struct StateG * v2858 = slot_160(v2852);
    v2870 = v2858;
  } else {
    int * v2860 = v2852->pht;
    v2860[49] = 0;
    int v2862 = v2852->timer;
    int v2884 = v2862 + 15;
    v2852->timer = v2884;
    int * v2864 = v2852->saved_regs;
    int v2865 = v2864[18];
    int * v2866 = v2852->regs;
    v2866[18] = v2865;
    struct StateG * v2868 = slot_161(v2852);
    v2870 = v2868;
  }
  return v2870;
}

struct StateG * slot_313(struct StateG * v6360) {
  int v6361 = v6360->timer;
  int v6371 = v6361 + 1;
  v6360->timer = v6371;
  int * v6363 = v6360->pht;
  int v6364 = v6363[94];
  bool v6374 = !(v6364 == 0);
  struct StateG * v6369;
  if (v6374) {
    struct StateG * v6365 = slot_330(v6360);
    v6369 = v6365;
  } else {
    struct StateG * v6367 = slot_331(v6360);
    v6369 = v6367;
  }
  return v6369;
}

struct StateG * slot_553(struct StateG * v11713) {
  int v11714 = v11713->timer;
  int v11720 = v11714 + 1;
  v11713->timer = v11720;
  int * v11716 = v11713->regs;
  v11716[1] = 148;
  struct StateG * v11718 = slot_569(v11713);
  return v11718;
}

struct StateG * slot_211(struct StateG * v4096) {
  int * v4097 = v4096->saved_regs;
  int * v4098 = v4096->regs;
  int v4099 = v4098[18];
  v4097[18] = v4099;
  int v4101 = v4096->timer;
  int v4111 = v4101 + 1;
  v4096->timer = v4111;
  int * v4103 = v4096->regs;
  v4103[18] = 1;
  struct StateG * v4105 = slot_243(v4096);
  return v4105;
}

struct StateG * slot_717(struct StateG * v14966) {
  int v14967 = v14966->timer;
  int v14974 = v14967 + 1;
  v14966->timer = v14974;
  int * v14969 = v14966->regs;
  int v14970 = v14969[1];
  bool v14977 = v14970 == 156;
  ret_assert(v14977);
  struct StateG * v14972 = slot_733(v14966);
  return v14972;
}

struct StateG * slot_436(struct StateG * v9072) {
  int v9073 = v9072->timer;
  int v9079 = v9073 + 1;
  v9072->timer = v9079;
  int * v9075 = v9072->regs;
  v9075[17] = 10;
  struct StateG * v9077 = slot_452(v9072);
  return v9077;
}

struct StateG * slot_704(struct StateG * v14812) {
  int v14813 = v14812->timer;
  int v14817 = v14813 + 1;
  v14812->timer = v14817;
  struct StateG * v14815 = slot_724(v14812);
  return v14815;
}

struct StateG * slot_708(struct StateG * v14854) {
  int v14855 = v14854->timer;
  int v14859 = v14855 + 1;
  v14854->timer = v14859;
  struct StateG * v14857 = slot_726(v14854);
  return v14857;
}

struct StateG * slot_296(struct StateG * v6132) {
  int v6133 = v6132->timer;
  int v6139 = v6133 + 1;
  v6132->timer = v6139;
  int * v6135 = v6132->regs;
  v6135[17] = 10;
  struct StateG * v6137 = slot_312(v6132);
  return v6137;
}

struct StateG * slot_18(struct StateG * v492) {
  int v493 = v492->timer;
  int v499 = v493 + 1;
  v492->timer = v499;
  int * v495 = v492->regs;
  v495[1] = 24;
  struct StateG * v497 = slot_20(v492);
  return v497;
}

struct StateG * slot_9(struct StateG * v357) {
  int * v358 = v357->regs;
  int v359 = v358[16];
  int v360 = v358[17];
  bool v380 = v359 < v360;
  struct StateG * v375;
  if (v380) {
    int * v361 = v357->pht;
    v361[0] = 1;
    int v363 = v357->timer;
    int v384 = v363 + 15;
    v357->timer = v384;
    int * v365 = v357->saved_regs;
    int v366 = v365[18];
    int * v367 = v357->regs;
    v367[18] = v366;
    struct StateG * v369 = slot_12(v357);
    v375 = v369;
  } else {
    int * v371 = v357->pht;
    v371[0] = 0;
    struct StateG * v373 = slot_13(v357);
    v375 = v373;
  }
  return v375;
}

struct StateG * slot_282(struct StateG * v5985) {
  int v5986 = v5985->timer;
  int v5992 = v5986 + 1;
  v5985->timer = v5992;
  int * v5988 = v5985->regs;
  v5988[18] = 2;
  struct StateG * v5990 = slot_280(v5985);
  return v5990;
}

struct StateG * slot_362(struct StateG * v7380) {
  int * v7381 = v7380->regs;
  int v7382 = v7381[16];
  int v7383 = v7381[17];
  bool v7403 = v7382 < v7383;
  struct StateG * v7398;
  if (v7403) {
    int * v7384 = v7380->pht;
    v7384[94] = 1;
    struct StateG * v7386 = slot_396(v7380);
    v7398 = v7386;
  } else {
    int * v7388 = v7380->pht;
    v7388[94] = 0;
    int v7390 = v7380->timer;
    int v7412 = v7390 + 15;
    v7380->timer = v7412;
    int * v7392 = v7380->saved_regs;
    int v7393 = v7392[18];
    int * v7394 = v7380->regs;
    v7394[18] = v7393;
    struct StateG * v7396 = slot_397(v7380);
    v7398 = v7396;
  }
  return v7398;
}

struct StateG * slot_43(struct StateG * v942) {
  int v943 = v942->timer;
  int v950 = v943 + 1;
  v942->timer = v950;
  int * v945 = v942->regs;
  int v946 = v945[1];
  bool v953 = v946 == 24;
  ret_assert(v953);
  struct StateG * v948 = slot_47(v942);
  return v948;
}

struct StateG * slot_76(struct StateG * v1662) {
  int v1663 = v1662->timer;
  int v1667 = v1663 + 1;
  v1662->timer = v1667;
  struct StateG * v1665 = slot_90(v1662);
  return v1665;
}

struct StateG * slot_55(struct StateG * v1120) {
  int v1121 = v1120->timer;
  int v1131 = v1121 + 1;
  v1120->timer = v1131;
  int * v1123 = v1120->pht;
  int v1124 = v1123[32];
  bool v1134 = !(v1124 == 0);
  struct StateG * v1129;
  if (v1134) {
    struct StateG * v1125 = slot_62(v1120);
    v1129 = v1125;
  } else {
    struct StateG * v1127 = slot_63(v1120);
    v1129 = v1127;
  }
  return v1129;
}

struct StateG * slot_346(struct StateG * v7020) {
  int * v7021 = v7020->saved_regs;
  int * v7022 = v7020->regs;
  int v7023 = v7022[18];
  v7021[18] = v7023;
  int v7025 = v7020->timer;
  int v7035 = v7025 + 1;
  v7020->timer = v7035;
  int * v7027 = v7020->regs;
  v7027[18] = 2;
  struct StateG * v7029 = slot_378(v7020);
  return v7029;
}

struct StateG * slot_647(struct StateG * v13264) {
  int * v13265 = v13264->saved_regs;
  int * v13266 = v13264->regs;
  int v13267 = v13266[18];
  v13265[18] = v13267;
  int v13269 = v13264->timer;
  int v13279 = v13269 + 1;
  v13264->timer = v13279;
  int * v13271 = v13264->regs;
  v13271[18] = 1;
  struct StateG * v13273 = slot_679(v13264);
  return v13273;
}

struct StateG * slot_274(struct StateG * v5901) {
  int v5902 = v5901->timer;
  int v5908 = v5902 + 1;
  v5901->timer = v5908;
  int * v5904 = v5901->regs;
  v5904[18] = 2;
  struct StateG * v5906 = slot_272(v5901);
  return v5906;
}

struct StateG * slot_535(struct StateG * v11524) {
  int v11525 = v11524->timer;
  int v11529 = v11525 + 1;
  v11524->timer = v11529;
  struct StateG * v11527 = slot_559(v11524);
  return v11527;
}

struct StateG * slot_318(struct StateG * v6460) {
  int v6461 = v6460->timer;
  int v6471 = v6461 + 1;
  v6460->timer = v6471;
  int * v6463 = v6460->pht;
  int v6464 = v6463[89];
  bool v6474 = !(v6464 == 0);
  struct StateG * v6469;
  if (v6474) {
    struct StateG * v6465 = slot_340(v6460);
    v6469 = v6465;
  } else {
    struct StateG * v6467 = slot_341(v6460);
    v6469 = v6467;
  }
  return v6469;
}

struct StateG * slot_91(struct StateG * v1827) {
  int v1828 = v1827->timer;
  int v1834 = v1828 + 1;
  v1827->timer = v1834;
  int * v1830 = v1827->regs;
  v1830[17] = 10;
  struct StateG * v1832 = slot_99(v1827);
  return v1832;
}

struct StateG * slot_700(struct StateG * v14770) {
  int v14771 = v14770->timer;
  int v14775 = v14771 + 1;
  v14770->timer = v14775;
  struct StateG * v14773 = slot_722(v14770);
  return v14773;
}

struct StateG * slot_58(struct StateG * v1180) {
  int * v1181 = v1180->saved_regs;
  int * v1182 = v1180->regs;
  int v1183 = v1182[18];
  v1181[18] = v1183;
  int v1185 = v1180->timer;
  int v1195 = v1185 + 1;
  v1180->timer = v1195;
  int * v1187 = v1180->regs;
  v1187[18] = 2;
  struct StateG * v1189 = slot_66(v1180);
  return v1189;
}

struct StateG * slot_255(struct StateG * v5436) {
  int * v5437 = v5436->regs;
  int v5438 = v5437[16];
  int v5439 = v5437[17];
  bool v5459 = v5438 < v5439;
  struct StateG * v5454;
  if (v5459) {
    int * v5440 = v5436->pht;
    v5440[68] = 1;
    int v5442 = v5436->timer;
    int v5463 = v5442 + 15;
    v5436->timer = v5463;
    int * v5444 = v5436->saved_regs;
    int v5445 = v5444[18];
    int * v5446 = v5436->regs;
    v5446[18] = v5445;
    struct StateG * v5448 = slot_278(v5436);
    v5454 = v5448;
  } else {
    int * v5450 = v5436->pht;
    v5450[68] = 0;
    struct StateG * v5452 = slot_279(v5436);
    v5454 = v5452;
  }
  return v5454;
}

struct StateG * slot_66(struct StateG * v1380) {
  int * v1381 = v1380->regs;
  int v1382 = v1381[16];
  int v1383 = v1381[17];
  bool v1403 = v1382 < v1383;
  struct StateG * v1398;
  if (v1403) {
    int * v1384 = v1380->pht;
    v1384[34] = 1;
    struct StateG * v1386 = slot_76(v1380);
    v1398 = v1386;
  } else {
    int * v1388 = v1380->pht;
    v1388[34] = 0;
    int v1390 = v1380->timer;
    int v1412 = v1390 + 15;
    v1380->timer = v1412;
    int * v1392 = v1380->saved_regs;
    int v1393 = v1392[18];
    int * v1394 = v1380->regs;
    v1394[18] = v1393;
    struct StateG * v1396 = slot_77(v1380);
    v1398 = v1396;
  }
  return v1398;
}

struct StateG * slot_643(struct StateG * v13184) {
  int * v13185 = v13184->saved_regs;
  int * v13186 = v13184->regs;
  int v13187 = v13186[18];
  v13185[18] = v13187;
  int v13189 = v13184->timer;
  int v13199 = v13189 + 1;
  v13184->timer = v13199;
  int * v13191 = v13184->regs;
  v13191[18] = 1;
  struct StateG * v13193 = slot_675(v13184);
  return v13193;
}

struct StateG * slot_550(struct StateG * v11679) {
  int v11680 = v11679->timer;
  int v11686 = v11680 + 1;
  v11679->timer = v11686;
  int * v11682 = v11679->regs;
  v11682[18] = 2;
  struct StateG * v11684 = slot_548(v11679);
  return v11684;
}

struct StateG * slot_592(struct StateG * v12220) {
  int v12221 = v12220->timer;
  int v12227 = v12221 + 1;
  v12220->timer = v12227;
  int * v12223 = v12220->regs;
  v12223[17] = 10;
  struct StateG * v12225 = slot_608(v12220);
  return v12225;
}

struct StateG * slot_368(struct StateG * v7620) {
  int * v7621 = v7620->regs;
  int v7622 = v7621[16];
  int v7623 = v7621[17];
  bool v7643 = v7622 < v7623;
  struct StateG * v7638;
  if (v7643) {
    int * v7624 = v7620->pht;
    v7624[91] = 1;
    struct StateG * v7626 = slot_408(v7620);
    v7638 = v7626;
  } else {
    int * v7628 = v7620->pht;
    v7628[91] = 0;
    int v7630 = v7620->timer;
    int v7652 = v7630 + 15;
    v7620->timer = v7652;
    int * v7632 = v7620->saved_regs;
    int v7633 = v7632[18];
    int * v7634 = v7620->regs;
    v7634[18] = v7633;
    struct StateG * v7636 = slot_409(v7620);
    v7638 = v7636;
  }
  return v7638;
}

struct StateG * slot_718(struct StateG * v14980) {
  int v14981 = v14980->timer;
  int v14988 = v14981 + 1;
  v14980->timer = v14988;
  int * v14983 = v14980->regs;
  int v14984 = v14983[1];
  bool v14991 = v14984 == 156;
  ret_assert(v14991);
  struct StateG * v14986 = slot_734(v14980);
  return v14986;
}

struct StateG * slot_265(struct StateG * v5804) {
  int v5805 = v5804->timer;
  int v5811 = v5805 + 1;
  v5804->timer = v5811;
  int * v5807 = v5804->regs;
  v5807[18] = 1;
  struct StateG * v5809 = slot_267(v5804);
  return v5809;
}

struct StateG * slot_192(struct StateG * v3716) {
  int v3717 = v3716->timer;
  int v3727 = v3717 + 1;
  v3716->timer = v3727;
  int * v3719 = v3716->pht;
  int v3720 = v3719[71];
  bool v3730 = !(v3720 == 0);
  struct StateG * v3725;
  if (v3730) {
    struct StateG * v3721 = slot_216(v3716);
    v3725 = v3721;
  } else {
    struct StateG * v3723 = slot_217(v3716);
    v3725 = v3723;
  }
  return v3725;
}

struct StateG * slot_48(struct StateG * v1008) {
  int v1009 = v1008->timer;
  int v1015 = v1009 + 1;
  v1008->timer = v1015;
  int * v1011 = v1008->regs;
  v1011[17] = 10;
  struct StateG * v1013 = slot_52(v1008);
  return v1013;
}

struct StateG * slot_770(struct StateG * v15666) {
  int v15667 = v15666->timer;
  int v15673 = v15667 + 1;
  v15666->timer = v15673;
  int * v15669 = v15666->regs;
  v15669[17] = 10;
  struct StateG * v15671 = slot_786(v15666);
  return v15671;
}

struct StateG * slot_119(struct StateG * v2352) {
  int * v2353 = v2352->saved_regs;
  int * v2354 = v2352->regs;
  int v2355 = v2354[18];
  v2353[18] = v2355;
  int v2357 = v2352->timer;
  int v2367 = v2357 + 1;
  v2352->timer = v2367;
  int * v2359 = v2352->regs;
  v2359[18] = 1;
  struct StateG * v2361 = slot_135(v2352);
  return v2361;
}

struct StateG * slot_276(struct StateG * v5922) {
  int v5923 = v5922->timer;
  int v5927 = v5923 + 1;
  v5922->timer = v5927;
  struct StateG * v5925 = slot_302(v5922);
  return v5925;
}

struct StateG * slot_763(struct StateG * v15575) {
  int v15576 = v15575->timer;
  int v15582 = v15576 + 1;
  v15575->timer = v15582;
  int * v15578 = v15575->regs;
  v15578[17] = 10;
  struct StateG * v15580 = slot_779(v15575);
  return v15580;
}

struct StateG * slot_290(struct StateG * v6069) {
  int v6070 = v6069->timer;
  int v6076 = v6070 + 1;
  v6069->timer = v6076;
  int * v6072 = v6069->regs;
  v6072[18] = 2;
  struct StateG * v6074 = slot_288(v6069);
  return v6074;
}

struct StateG * slot_234(struct StateG * v4596) {
  int * v4597 = v4596->regs;
  int v4598 = v4597[16];
  int v4599 = v4597[17];
  bool v4619 = v4598 < v4599;
  struct StateG * v4614;
  if (v4619) {
    int * v4600 = v4596->pht;
    v4600[78] = 1;
    struct StateG * v4602 = slot_268(v4596);
    v4614 = v4602;
  } else {
    int * v4604 = v4596->pht;
    v4604[78] = 0;
    int v4606 = v4596->timer;
    int v4628 = v4606 + 15;
    v4596->timer = v4628;
    int * v4608 = v4596->saved_regs;
    int v4609 = v4608[18];
    int * v4610 = v4596->regs;
    v4610[18] = v4609;
    struct StateG * v4612 = slot_269(v4596);
    v4614 = v4612;
  }
  return v4614;
}

struct StateG * slot_218(struct StateG * v4236) {
  int * v4237 = v4236->saved_regs;
  int * v4238 = v4236->regs;
  int v4239 = v4238[18];
  v4237[18] = v4239;
  int v4241 = v4236->timer;
  int v4251 = v4241 + 1;
  v4236->timer = v4251;
  int * v4243 = v4236->regs;
  v4243[18] = 2;
  struct StateG * v4245 = slot_250(v4236);
  return v4245;
}

struct StateG * slot_841(struct StateG * v17384) {
  int * v17385 = v17384->regs;
  int v17386 = v17385[16];
  int v17387 = v17385[17];
  bool v17407 = v17386 >= v17387;
  struct StateG * v17402;
  if (v17407) {
    int * v17388 = v17384->pht;
    v17388[23] = 1;
    int v17390 = v17384->timer;
    int v17411 = v17390 + 15;
    v17384->timer = v17411;
    int * v17392 = v17384->saved_regs;
    int v17393 = v17392[19];
    int * v17394 = v17384->regs;
    v17394[19] = v17393;
    struct StateG * v17396 = slot_858(v17384);
    v17402 = v17396;
  } else {
    int * v17398 = v17384->pht;
    v17398[23] = 0;
    struct StateG * v17400 = slot_883(v17384);
    v17402 = v17400;
  }
  return v17402;
}

struct StateG * slot_596(struct StateG * v12272) {
  int v12273 = v12272->timer;
  int v12279 = v12273 + 1;
  v12272->timer = v12279;
  int * v12275 = v12272->regs;
  v12275[17] = 10;
  struct StateG * v12277 = slot_612(v12272);
  return v12277;
}

struct StateG * slot_576(struct StateG * v12012) {
  int v12013 = v12012->timer;
  int v12019 = v12013 + 1;
  v12012->timer = v12019;
  int * v12015 = v12012->regs;
  v12015[1] = 156;
  struct StateG * v12017 = slot_592(v12012);
  return v12017;
}

struct StateG * slot_202(struct StateG * v3916) {
  int * v3917 = v3916->saved_regs;
  int * v3918 = v3916->regs;
  int v3919 = v3918[18];
  v3917[18] = v3919;
  int v3921 = v3916->timer;
  int v3931 = v3921 + 1;
  v3916->timer = v3931;
  int * v3923 = v3916->regs;
  v3923[18] = 2;
  struct StateG * v3925 = slot_234(v3916);
  return v3925;
}

struct StateG * slot_230(struct StateG * v4476) {
  int * v4477 = v4476->saved_regs;
  int * v4478 = v4476->regs;
  int v4479 = v4478[18];
  v4477[18] = v4479;
  int v4481 = v4476->timer;
  int v4491 = v4481 + 1;
  v4476->timer = v4491;
  int * v4483 = v4476->regs;
  v4483[18] = 2;
  struct StateG * v4485 = slot_262(v4476);
  return v4485;
}

struct StateG * slot_852(struct StateG * v17822) {
  int * v17823 = v17822->regs;
  int v17824 = v17823[16];
  int v17825 = v17823[17];
  bool v17845 = v17824 >= v17825;
  struct StateG * v17840;
  if (v17845) {
    int * v17826 = v17822->pht;
    v17826[17] = 1;
    struct StateG * v17828 = slot_883(v17822);
    v17840 = v17828;
  } else {
    int * v17830 = v17822->pht;
    v17830[17] = 0;
    int v17832 = v17822->timer;
    int v17852 = v17832 + 15;
    v17822->timer = v17852;
    int * v17834 = v17822->saved_regs;
    int v17835 = v17834[19];
    int * v17836 = v17822->regs;
    v17836[19] = v17835;
    struct StateG * v17838 = slot_861(v17822);
    v17840 = v17838;
  }
  return v17840;
}

struct StateG * slot_294(struct StateG * v6111) {
  int v6112 = v6111->timer;
  int v6118 = v6112 + 1;
  v6111->timer = v6118;
  int * v6114 = v6111->regs;
  v6114[18] = 2;
  struct StateG * v6116 = slot_292(v6111);
  return v6116;
}

struct StateG * slot_488(struct StateG * v10084) {
  int * v10085 = v10084->regs;
  int v10086 = v10085[16];
  int v10087 = v10085[17];
  bool v10107 = v10086 < v10087;
  struct StateG * v10102;
  if (v10107) {
    int * v10088 = v10084->pht;
    v10088[111] = 1;
    struct StateG * v10090 = slot_520(v10084);
    v10102 = v10090;
  } else {
    int * v10092 = v10084->pht;
    v10092[111] = 0;
    int v10094 = v10084->timer;
    int v10116 = v10094 + 15;
    v10084->timer = v10116;
    int * v10096 = v10084->saved_regs;
    int v10097 = v10096[18];
    int * v10098 = v10084->regs;
    v10098[18] = v10097;
    struct StateG * v10100 = slot_521(v10084);
    v10102 = v10100;
  }
  return v10102;
}

struct StateG * slot_439(struct StateG * v9111) {
  int v9112 = v9111->timer;
  int v9118 = v9112 + 1;
  v9111->timer = v9118;
  int * v9114 = v9111->regs;
  v9114[17] = 10;
  struct StateG * v9116 = slot_455(v9111);
  return v9116;
}

struct StateG * slot_479(struct StateG * v9904) {
  int * v9905 = v9904->saved_regs;
  int * v9906 = v9904->regs;
  int v9907 = v9906[18];
  v9905[18] = v9907;
  int v9909 = v9904->timer;
  int v9919 = v9909 + 1;
  v9904->timer = v9919;
  int * v9911 = v9904->regs;
  v9911[18] = 1;
  struct StateG * v9913 = slot_511(v9904);
  return v9913;
}

struct StateG * slot_196(struct StateG * v3796) {
  int v3797 = v3796->timer;
  int v3807 = v3797 + 1;
  v3796->timer = v3807;
  int * v3799 = v3796->pht;
  int v3800 = v3799[67];
  bool v3810 = !(v3800 == 0);
  struct StateG * v3805;
  if (v3810) {
    struct StateG * v3801 = slot_224(v3796);
    v3805 = v3801;
  } else {
    struct StateG * v3803 = slot_225(v3796);
    v3805 = v3803;
  }
  return v3805;
}

struct StateG * slot_172(struct StateG * v3400) {
  int v3401 = v3400->timer;
  int v3407 = v3401 + 1;
  v3400->timer = v3407;
  int * v3403 = v3400->regs;
  v3403[17] = 10;
  struct StateG * v3405 = slot_188(v3400);
  return v3405;
}

struct StateG * slot_443(struct StateG * v9184) {
  int v9185 = v9184->timer;
  int v9195 = v9185 + 1;
  v9184->timer = v9195;
  int * v9187 = v9184->pht;
  int v9188 = v9187[108];
  bool v9198 = !(v9188 == 0);
  struct StateG * v9193;
  if (v9198) {
    struct StateG * v9189 = slot_462(v9184);
    v9193 = v9189;
  } else {
    struct StateG * v9191 = slot_463(v9184);
    v9193 = v9191;
  }
  return v9193;
}

struct StateG * slot_8(struct StateG * v318) {
  int * v319 = v318->regs;
  int v320 = v319[16];
  int v321 = v319[17];
  bool v341 = v320 < v321;
  struct StateG * v336;
  if (v341) {
    int * v322 = v318->pht;
    v322[0] = 1;
    struct StateG * v324 = slot_10(v318);
    v336 = v324;
  } else {
    int * v326 = v318->pht;
    v326[0] = 0;
    int v328 = v318->timer;
    int v349 = v328 + 15;
    v318->timer = v349;
    int * v330 = v318->saved_regs;
    int v331 = v330[18];
    int * v332 = v318->regs;
    v332[18] = v331;
    struct StateG * v334 = slot_11(v318);
    v336 = v334;
  }
  return v336;
}

struct StateG * slot_534(struct StateG * v11511) {
  int v11512 = v11511->timer;
  int v11518 = v11512 + 1;
  v11511->timer = v11518;
  int * v11514 = v11511->regs;
  v11514[18] = 2;
  struct StateG * v11516 = slot_532(v11511);
  return v11516;
}

struct StateG * slot_597(struct StateG * v12285) {
  int v12286 = v12285->timer;
  int v12292 = v12286 + 1;
  v12285->timer = v12292;
  int * v12288 = v12285->regs;
  v12288[17] = 10;
  struct StateG * v12290 = slot_613(v12285);
  return v12290;
}

struct StateG * slot_180(struct StateG * v3504) {
  int v3505 = v3504->timer;
  int v3511 = v3505 + 1;
  v3504->timer = v3511;
  int * v3507 = v3504->regs;
  v3507[17] = 10;
  struct StateG * v3509 = slot_196(v3504);
  return v3509;
}

struct StateG * slot_512(struct StateG * v11044) {
  int * v11045 = v11044->regs;
  int v11046 = v11045[16];
  int v11047 = v11045[17];
  bool v11067 = v11046 < v11047;
  struct StateG * v11062;
  if (v11067) {
    int * v11048 = v11044->pht;
    v11048[99] = 1;
    struct StateG * v11050 = slot_536(v11044);
    v11062 = v11050;
  } else {
    int * v11052 = v11044->pht;
    v11052[99] = 0;
    int v11054 = v11044->timer;
    int v11076 = v11054 + 15;
    v11044->timer = v11076;
    int * v11056 = v11044->saved_regs;
    int v11057 = v11056[18];
    int * v11058 = v11044->regs;
    v11058[18] = v11057;
    struct StateG * v11060 = slot_537(v11044);
    v11062 = v11060;
  }
  return v11062;
}

struct StateG * slot_494(struct StateG * v10324) {
  int * v10325 = v10324->regs;
  int v10326 = v10325[16];
  int v10327 = v10325[17];
  bool v10347 = v10326 < v10327;
  struct StateG * v10342;
  if (v10347) {
    int * v10328 = v10324->pht;
    v10328[108] = 1;
    struct StateG * v10330 = slot_532(v10324);
    v10342 = v10330;
  } else {
    int * v10332 = v10324->pht;
    v10332[108] = 0;
    int v10334 = v10324->timer;
    int v10356 = v10334 + 15;
    v10324->timer = v10356;
    int * v10336 = v10324->saved_regs;
    int v10337 = v10336[18];
    int * v10338 = v10324->regs;
    v10338[18] = v10337;
    struct StateG * v10340 = slot_533(v10324);
    v10342 = v10340;
  }
  return v10342;
}

struct StateG * slot_607(struct StateG * v12464) {
  int v12465 = v12464->timer;
  int v12475 = v12465 + 1;
  v12464->timer = v12475;
  int * v12467 = v12464->pht;
  int v12468 = v12467[8];
  bool v12478 = !(v12468 == 0);
  struct StateG * v12473;
  if (v12478) {
    struct StateG * v12469 = slot_630(v12464);
    v12473 = v12469;
  } else {
    struct StateG * v12471 = slot_631(v12464);
    v12473 = v12471;
  }
  return v12473;
}

struct StateG * slot_789(struct StateG * v16004) {
  int v16005 = v16004->timer;
  int v16015 = v16005 + 1;
  v16004->timer = v16015;
  int * v16007 = v16004->pht;
  int v16008 = v16007[18];
  bool v16018 = !(v16008 == 0);
  struct StateG * v16013;
  if (v16018) {
    struct StateG * v16009 = slot_818(v16004);
    v16013 = v16009;
  } else {
    struct StateG * v16011 = slot_819(v16004);
    v16013 = v16011;
  }
  return v16013;
}

struct StateG * slot_328(struct StateG * v6660) {
  int * v6661 = v6660->saved_regs;
  int * v6662 = v6660->regs;
  int v6663 = v6662[18];
  v6661[18] = v6663;
  int v6665 = v6660->timer;
  int v6675 = v6665 + 1;
  v6660->timer = v6675;
  int * v6667 = v6660->regs;
  v6667[18] = 2;
  struct StateG * v6669 = slot_360(v6660);
  return v6669;
}

struct StateG * slot_402(struct StateG * v8685) {
  int v8686 = v8685->timer;
  int v8692 = v8686 + 1;
  v8685->timer = v8692;
  int * v8688 = v8685->regs;
  v8688[18] = 2;
  struct StateG * v8690 = slot_400(v8685);
  return v8690;
}

struct StateG * slot_149(struct StateG * v3146) {
  int v3147 = v3146->timer;
  int v3153 = v3147 + 1;
  v3146->timer = v3153;
  int * v3149 = v3146->regs;
  v3149[18] = 1;
  struct StateG * v3151 = slot_151(v3146);
  return v3151;
}

struct StateG * slot_527(struct StateG * v11440) {
  int v11441 = v11440->timer;
  int v11445 = v11441 + 1;
  v11440->timer = v11445;
  struct StateG * v11443 = slot_555(v11440);
  return v11443;
}

struct StateG * slot_5(struct StateG * v258) {
  int v259 = v258->timer;
  int v269 = v259 + 1;
  v258->timer = v269;
  int * v261 = v258->pht;
  int v262 = v261[0];
  bool v272 = !(v262 == 0);
  struct StateG * v267;
  if (v272) {
    struct StateG * v263 = slot_6(v258);
    v267 = v263;
  } else {
    struct StateG * v265 = slot_7(v258);
    v267 = v265;
  }
  return v267;
}

struct StateG * slot_235(struct StateG * v4636) {
  int * v4637 = v4636->regs;
  int v4638 = v4637[16];
  int v4639 = v4637[17];
  bool v4659 = v4638 < v4639;
  struct StateG * v4654;
  if (v4659) {
    int * v4640 = v4636->pht;
    v4640[78] = 1;
    int v4642 = v4636->timer;
    int v4663 = v4642 + 15;
    v4636->timer = v4663;
    int * v4644 = v4636->saved_regs;
    int v4645 = v4644[18];
    int * v4646 = v4636->regs;
    v4646[18] = v4645;
    struct StateG * v4648 = slot_270(v4636);
    v4654 = v4648;
  } else {
    int * v4650 = v4636->pht;
    v4650[78] = 0;
    struct StateG * v4652 = slot_271(v4636);
    v4654 = v4652;
  }
  return v4654;
}

struct StateG * slot_275(struct StateG * v5914) {
  int v5915 = v5914->timer;
  int v5919 = v5915 + 1;
  v5914->timer = v5919;
  struct StateG * v5917 = slot_301(v5914);
  return v5917;
}

struct StateG * slot_428(struct StateG * v8968) {
  int v8969 = v8968->timer;
  int v8975 = v8969 + 1;
  v8968->timer = v8975;
  int * v8971 = v8968->regs;
  v8971[17] = 10;
  struct StateG * v8973 = slot_444(v8968);
  return v8973;
}

struct StateG * slot_815(struct StateG * v16524) {
  int * v16525 = v16524->saved_regs;
  int * v16526 = v16524->regs;
  int v16527 = v16526[19];
  v16525[19] = v16527;
  int v16529 = v16524->timer;
  int v16539 = v16529 + 1;
  v16524->timer = v16539;
  int * v16531 = v16524->regs;
  v16531[19] = 1;
  struct StateG * v16533 = slot_847(v16524);
  return v16533;
}

struct StateG * slot_660(struct StateG * v13764) {
  int * v13765 = v13764->regs;
  int v13766 = v13765[16];
  int v13767 = v13765[17];
  bool v13787 = v13766 < v13767;
  struct StateG * v13782;
  if (v13787) {
    int * v13768 = v13764->pht;
    v13768[9] = 1;
    struct StateG * v13770 = slot_704(v13764);
    v13782 = v13770;
  } else {
    int * v13772 = v13764->pht;
    v13772[9] = 0;
    int v13774 = v13764->timer;
    int v13796 = v13774 + 15;
    v13764->timer = v13796;
    int * v13776 = v13764->saved_regs;
    int v13777 = v13776[18];
    int * v13778 = v13764->regs;
    v13778[18] = v13777;
    struct StateG * v13780 = slot_705(v13764);
    v13782 = v13780;
  }
  return v13782;
}

struct StateG * slot_614(struct StateG * v12604) {
  int v12605 = v12604->timer;
  int v12615 = v12605 + 1;
  v12604->timer = v12615;
  int * v12607 = v12604->pht;
  int v12608 = v12607[1];
  bool v12618 = !(v12608 == 0);
  struct StateG * v12613;
  if (v12618) {
    struct StateG * v12609 = slot_644(v12604);
    v12613 = v12609;
  } else {
    struct StateG * v12611 = slot_645(v12604);
    v12613 = v12611;
  }
  return v12613;
}

struct StateG * slot_345(struct StateG * v7000) {
  int * v7001 = v7000->saved_regs;
  int * v7002 = v7000->regs;
  int v7003 = v7002[18];
  v7001[18] = v7003;
  int v7005 = v7000->timer;
  int v7015 = v7005 + 1;
  v7000->timer = v7015;
  int * v7007 = v7000->regs;
  v7007[18] = 1;
  struct StateG * v7009 = slot_377(v7000);
  return v7009;
}

struct StateG * slot_753(struct StateG * v15445) {
  int v15446 = v15445->timer;
  int v15452 = v15446 + 1;
  v15445->timer = v15452;
  int * v15448 = v15445->regs;
  v15448[1] = 164;
  struct StateG * v15450 = slot_769(v15445);
  return v15450;
}

struct StateG * slot_414(struct StateG * v8811) {
  int v8812 = v8811->timer;
  int v8818 = v8812 + 1;
  v8811->timer = v8818;
  int * v8814 = v8811->regs;
  v8814[18] = 2;
  struct StateG * v8816 = slot_412(v8811);
  return v8816;
}

struct StateG * slot_364(struct StateG * v7460) {
  int * v7461 = v7460->regs;
  int v7462 = v7461[16];
  int v7463 = v7461[17];
  bool v7483 = v7462 < v7463;
  struct StateG * v7478;
  if (v7483) {
    int * v7464 = v7460->pht;
    v7464[93] = 1;
    struct StateG * v7466 = slot_400(v7460);
    v7478 = v7466;
  } else {
    int * v7468 = v7460->pht;
    v7468[93] = 0;
    int v7470 = v7460->timer;
    int v7492 = v7470 + 15;
    v7460->timer = v7492;
    int * v7472 = v7460->saved_regs;
    int v7473 = v7472[18];
    int * v7474 = v7460->regs;
    v7474[18] = v7473;
    struct StateG * v7476 = slot_401(v7460);
    v7478 = v7476;
  }
  return v7478;
}

struct StateG * slot_356(struct StateG * v7220) {
  int * v7221 = v7220->saved_regs;
  int * v7222 = v7220->regs;
  int v7223 = v7222[18];
  v7221[18] = v7223;
  int v7225 = v7220->timer;
  int v7235 = v7225 + 1;
  v7220->timer = v7235;
  int * v7227 = v7220->regs;
  v7227[18] = 2;
  struct StateG * v7229 = slot_388(v7220);
  return v7229;
}

struct StateG * slot_665(struct StateG * v13964) {
  int * v13965 = v13964->regs;
  int v13966 = v13965[16];
  int v13967 = v13965[17];
  bool v13987 = v13966 < v13967;
  struct StateG * v13982;
  if (v13987) {
    int * v13968 = v13964->pht;
    v13968[7] = 1;
    int v13970 = v13964->timer;
    int v13991 = v13970 + 15;
    v13964->timer = v13991;
    int * v13972 = v13964->saved_regs;
    int v13973 = v13972[18];
    int * v13974 = v13964->regs;
    v13974[18] = v13973;
    struct StateG * v13976 = slot_682(v13964);
    v13982 = v13976;
  } else {
    int * v13978 = v13964->pht;
    v13978[7] = 0;
    struct StateG * v13980 = slot_683(v13964);
    v13982 = v13980;
  }
  return v13982;
}

struct StateG * slot_434(struct StateG * v9046) {
  int v9047 = v9046->timer;
  int v9053 = v9047 + 1;
  v9046->timer = v9053;
  int * v9049 = v9046->regs;
  v9049[17] = 10;
  struct StateG * v9051 = slot_450(v9046);
  return v9051;
}

struct StateG * slot_760(struct StateG * v15536) {
  int v15537 = v15536->timer;
  int v15543 = v15537 + 1;
  v15536->timer = v15543;
  int * v15539 = v15536->regs;
  v15539[17] = 10;
  struct StateG * v15541 = slot_776(v15536);
  return v15541;
}

struct StateG * slot_522(struct StateG * v11385) {
  int v11386 = v11385->timer;
  int v11392 = v11386 + 1;
  v11385->timer = v11392;
  int * v11388 = v11385->regs;
  v11388[18] = 2;
  struct StateG * v11390 = slot_520(v11385);
  return v11390;
}

struct StateG * slot_80(struct StateG * v1704) {
  int v1705 = v1704->timer;
  int v1709 = v1705 + 1;
  v1704->timer = v1709;
  struct StateG * v1707 = slot_92(v1704);
  return v1707;
}

struct StateG * slot_390(struct StateG * v8500) {
  int * v8501 = v8500->regs;
  int v8502 = v8501[16];
  int v8503 = v8501[17];
  bool v8523 = v8502 < v8503;
  struct StateG * v8518;
  if (v8523) {
    int * v8504 = v8500->pht;
    v8504[80] = 1;
    struct StateG * v8506 = slot_420(v8500);
    v8518 = v8506;
  } else {
    int * v8508 = v8500->pht;
    v8508[80] = 0;
    int v8510 = v8500->timer;
    int v8532 = v8510 + 15;
    v8500->timer = v8532;
    int * v8512 = v8500->saved_regs;
    int v8513 = v8512[18];
    int * v8514 = v8500->regs;
    v8514[18] = v8513;
    struct StateG * v8516 = slot_421(v8500);
    v8518 = v8516;
  }
  return v8518;
}

struct StateG * slot_44(struct StateG * v956) {
  int v957 = v956->timer;
  int v963 = v957 + 1;
  v956->timer = v963;
  int * v959 = v956->regs;
  v959[16] = 20;
  struct StateG * v961 = slot_48(v956);
  return v961;
}

struct StateG * slot_137(struct StateG * v3020) {
  int v3021 = v3020->timer;
  int v3027 = v3021 + 1;
  v3020->timer = v3027;
  int * v3023 = v3020->regs;
  v3023[18] = 1;
  struct StateG * v3025 = slot_139(v3020);
  return v3025;
}

struct StateG * slot_122(struct StateG * v2452) {
  int * v2453 = v2452->regs;
  int v2454 = v2453[16];
  int v2455 = v2453[17];
  bool v2475 = v2454 < v2455;
  struct StateG * v2470;
  if (v2475) {
    int * v2456 = v2452->pht;
    v2456[54] = 1;
    struct StateG * v2458 = slot_140(v2452);
    v2470 = v2458;
  } else {
    int * v2460 = v2452->pht;
    v2460[54] = 0;
    int v2462 = v2452->timer;
    int v2484 = v2462 + 15;
    v2452->timer = v2484;
    int * v2464 = v2452->saved_regs;
    int v2465 = v2464[18];
    int * v2466 = v2452->regs;
    v2466[18] = v2465;
    struct StateG * v2468 = slot_141(v2452);
    v2470 = v2468;
  }
  return v2470;
}

struct StateG * slot_722(struct StateG * v15036) {
  int v15037 = v15036->timer;
  int v15044 = v15037 + 1;
  v15036->timer = v15044;
  int * v15039 = v15036->regs;
  int v15040 = v15039[1];
  bool v15047 = v15040 == 156;
  ret_assert(v15047);
  struct StateG * v15042 = slot_738(v15036);
  return v15042;
}

struct StateG * slot_179(struct StateG * v3491) {
  int v3492 = v3491->timer;
  int v3498 = v3492 + 1;
  v3491->timer = v3498;
  int * v3494 = v3491->regs;
  v3494[17] = 10;
  struct StateG * v3496 = slot_195(v3491);
  return v3496;
}

struct StateG * slot_338(struct StateG * v6860) {
  int * v6861 = v6860->saved_regs;
  int * v6862 = v6860->regs;
  int v6863 = v6862[18];
  v6861[18] = v6863;
  int v6865 = v6860->timer;
  int v6875 = v6865 + 1;
  v6860->timer = v6875;
  int * v6867 = v6860->regs;
  v6867[18] = 2;
  struct StateG * v6869 = slot_370(v6860);
  return v6869;
}

struct StateG * slot_563(struct StateG * v11843) {
  int v11844 = v11843->timer;
  int v11850 = v11844 + 1;
  v11843->timer = v11850;
  int * v11846 = v11843->regs;
  v11846[1] = 148;
  struct StateG * v11848 = slot_579(v11843);
  return v11848;
}

struct StateG * slot_366(struct StateG * v7540) {
  int * v7541 = v7540->regs;
  int v7542 = v7541[16];
  int v7543 = v7541[17];
  bool v7563 = v7542 < v7543;
  struct StateG * v7558;
  if (v7563) {
    int * v7544 = v7540->pht;
    v7544[92] = 1;
    struct StateG * v7546 = slot_404(v7540);
    v7558 = v7546;
  } else {
    int * v7548 = v7540->pht;
    v7548[92] = 0;
    int v7550 = v7540->timer;
    int v7572 = v7550 + 15;
    v7540->timer = v7572;
    int * v7552 = v7540->saved_regs;
    int v7553 = v7552[18];
    int * v7554 = v7540->regs;
    v7554[18] = v7553;
    struct StateG * v7556 = slot_405(v7540);
    v7558 = v7556;
  }
  return v7558;
}

struct StateG * slot_574(struct StateG * v11986) {
  int v11987 = v11986->timer;
  int v11993 = v11987 + 1;
  v11986->timer = v11993;
  int * v11989 = v11986->regs;
  v11989[1] = 156;
  struct StateG * v11991 = slot_590(v11986);
  return v11991;
}

struct StateG * slot_438(struct StateG * v9098) {
  int v9099 = v9098->timer;
  int v9105 = v9099 + 1;
  v9098->timer = v9105;
  int * v9101 = v9098->regs;
  v9101[17] = 10;
  struct StateG * v9103 = slot_454(v9098);
  return v9103;
}

struct StateG * slot_311(struct StateG * v6327) {
  int v6328 = v6327->timer;
  int v6334 = v6328 + 1;
  v6327->timer = v6334;
  int * v6330 = v6327->regs;
  v6330[17] = 10;
  struct StateG * v6332 = slot_327(v6327);
  return v6332;
}

struct StateG * slot_279(struct StateG * v5956) {
  int v5957 = v5956->timer;
  int v5961 = v5957 + 1;
  v5956->timer = v5961;
  struct StateG * v5959 = slot_303(v5956);
  return v5959;
}

struct StateG * slot_401(struct StateG * v8672) {
  int v8673 = v8672->timer;
  int v8679 = v8673 + 1;
  v8672->timer = v8679;
  int * v8675 = v8672->regs;
  v8675[18] = 1;
  struct StateG * v8677 = slot_403(v8672);
  return v8677;
}

struct StateG * slot_423(struct StateG * v8908) {
  int v8909 = v8908->timer;
  int v8913 = v8909 + 1;
  v8908->timer = v8913;
  struct StateG * v8911 = slot_439(v8908);
  return v8911;
}

struct StateG * slot_217(struct StateG * v4216) {
  int * v4217 = v4216->saved_regs;
  int * v4218 = v4216->regs;
  int v4219 = v4218[18];
  v4217[18] = v4219;
  int v4221 = v4216->timer;
  int v4231 = v4221 + 1;
  v4216->timer = v4231;
  int * v4223 = v4216->regs;
  v4223[18] = 1;
  struct StateG * v4225 = slot_249(v4216);
  return v4225;
}

struct StateG * slot_696(struct StateG * v14728) {
  int v14729 = v14728->timer;
  int v14733 = v14729 + 1;
  v14728->timer = v14733;
  struct StateG * v14731 = slot_720(v14728);
  return v14731;
}

struct StateG * slot_111(struct StateG * v2192) {
  int * v2193 = v2192->saved_regs;
  int * v2194 = v2192->regs;
  int v2195 = v2194[18];
  v2193[18] = v2195;
  int v2197 = v2192->timer;
  int v2207 = v2197 + 1;
  v2192->timer = v2207;
  int * v2199 = v2192->regs;
  v2199[18] = 1;
  struct StateG * v2201 = slot_127(v2192);
  return v2201;
}

struct StateG * slot_549(struct StateG * v11666) {
  int v11667 = v11666->timer;
  int v11673 = v11667 + 1;
  v11666->timer = v11673;
  int * v11669 = v11666->regs;
  v11669[18] = 1;
  struct StateG * v11671 = slot_551(v11666);
  return v11671;
}

struct StateG * slot_349(struct StateG * v7080) {
  int * v7081 = v7080->saved_regs;
  int * v7082 = v7080->regs;
  int v7083 = v7082[18];
  v7081[18] = v7083;
  int v7085 = v7080->timer;
  int v7095 = v7085 + 1;
  v7080->timer = v7095;
  int * v7087 = v7080->regs;
  v7087[18] = 1;
  struct StateG * v7089 = slot_381(v7080);
  return v7089;
}

struct StateG * slot_291(struct StateG * v6082) {
  int v6083 = v6082->timer;
  int v6087 = v6083 + 1;
  v6082->timer = v6087;
  struct StateG * v6085 = slot_309(v6082);
  return v6085;
}

struct StateG * slot_820(struct StateG * v16624) {
  int * v16625 = v16624->saved_regs;
  int * v16626 = v16624->regs;
  int v16627 = v16626[19];
  v16625[19] = v16627;
  int v16629 = v16624->timer;
  int v16639 = v16629 + 1;
  v16624->timer = v16639;
  int * v16631 = v16624->regs;
  v16631[19] = 2;
  struct StateG * v16633 = slot_852(v16624);
  return v16633;
}

struct StateG * slot_147(struct StateG * v3130) {
  int v3131 = v3130->timer;
  int v3135 = v3131 + 1;
  v3130->timer = v3135;
  struct StateG * v3133 = slot_173(v3130);
  return v3133;
}

struct StateG * slot_491(struct StateG * v10204) {
  int * v10205 = v10204->regs;
  int v10206 = v10205[16];
  int v10207 = v10205[17];
  bool v10227 = v10206 < v10207;
  struct StateG * v10222;
  if (v10227) {
    int * v10208 = v10204->pht;
    v10208[110] = 1;
    int v10210 = v10204->timer;
    int v10231 = v10210 + 15;
    v10204->timer = v10231;
    int * v10212 = v10204->saved_regs;
    int v10213 = v10212[18];
    int * v10214 = v10204->regs;
    v10214[18] = v10213;
    struct StateG * v10216 = slot_526(v10204);
    v10222 = v10216;
  } else {
    int * v10218 = v10204->pht;
    v10218[110] = 0;
    struct StateG * v10220 = slot_527(v10204);
    v10222 = v10220;
  }
  return v10222;
}

struct StateG * slot_163(struct StateG * v3298) {
  int v3299 = v3298->timer;
  int v3303 = v3299 + 1;
  v3298->timer = v3303;
  struct StateG * v3301 = slot_181(v3298);
  return v3301;
}

struct StateG * slot_422(struct StateG * v8895) {
  int v8896 = v8895->timer;
  int v8902 = v8896 + 1;
  v8895->timer = v8902;
  int * v8898 = v8895->regs;
  v8898[18] = 2;
  struct StateG * v8900 = slot_420(v8895);
  return v8900;
}

struct StateG * slot_448(struct StateG * v9284) {
  int v9285 = v9284->timer;
  int v9295 = v9285 + 1;
  v9284->timer = v9295;
  int * v9287 = v9284->pht;
  int v9288 = v9287[103];
  bool v9298 = !(v9288 == 0);
  struct StateG * v9293;
  if (v9298) {
    struct StateG * v9289 = slot_472(v9284);
    v9293 = v9289;
  } else {
    struct StateG * v9291 = slot_473(v9284);
    v9293 = v9291;
  }
  return v9293;
}

struct StateG * slot_792(struct StateG * v16064) {
  int * v16065 = v16064->saved_regs;
  int * v16066 = v16064->regs;
  int v16067 = v16066[19];
  v16065[19] = v16067;
  int v16069 = v16064->timer;
  int v16079 = v16069 + 1;
  v16064->timer = v16079;
  int * v16071 = v16064->regs;
  v16071[19] = 2;
  struct StateG * v16073 = slot_824(v16064);
  return v16073;
}

struct StateG * slot_698(struct StateG * v14749) {
  int v14750 = v14749->timer;
  int v14756 = v14750 + 1;
  v14749->timer = v14756;
  int * v14752 = v14749->regs;
  v14752[18] = 2;
  struct StateG * v14754 = slot_696(v14749);
  return v14754;
}

struct StateG * slot_407(struct StateG * v8740) {
  int v8741 = v8740->timer;
  int v8745 = v8741 + 1;
  v8740->timer = v8745;
  struct StateG * v8743 = slot_431(v8740);
  return v8743;
}

struct StateG * slot_250(struct StateG * v5236) {
  int * v5237 = v5236->regs;
  int v5238 = v5237[16];
  int v5239 = v5237[17];
  bool v5259 = v5238 < v5239;
  struct StateG * v5254;
  if (v5259) {
    int * v5240 = v5236->pht;
    v5240[70] = 1;
    struct StateG * v5242 = slot_268(v5236);
    v5254 = v5242;
  } else {
    int * v5244 = v5236->pht;
    v5244[70] = 0;
    int v5246 = v5236->timer;
    int v5268 = v5246 + 15;
    v5236->timer = v5268;
    int * v5248 = v5236->saved_regs;
    int v5249 = v5248[18];
    int * v5250 = v5236->regs;
    v5250[18] = v5249;
    struct StateG * v5252 = slot_269(v5236);
    v5254 = v5252;
  }
  return v5254;
}

struct StateG * slot_360(struct StateG * v7300) {
  int * v7301 = v7300->regs;
  int v7302 = v7301[16];
  int v7303 = v7301[17];
  bool v7323 = v7302 < v7303;
  struct StateG * v7318;
  if (v7323) {
    int * v7304 = v7300->pht;
    v7304[95] = 1;
    struct StateG * v7306 = slot_392(v7300);
    v7318 = v7306;
  } else {
    int * v7308 = v7300->pht;
    v7308[95] = 0;
    int v7310 = v7300->timer;
    int v7332 = v7310 + 15;
    v7300->timer = v7332;
    int * v7312 = v7300->saved_regs;
    int v7313 = v7312[18];
    int * v7314 = v7300->regs;
    v7314[18] = v7313;
    struct StateG * v7316 = slot_393(v7300);
    v7318 = v7316;
  }
  return v7318;
}

struct StateG * slot_259(struct StateG * v5596) {
  int * v5597 = v5596->regs;
  int v5598 = v5597[16];
  int v5599 = v5597[17];
  bool v5619 = v5598 < v5599;
  struct StateG * v5614;
  if (v5619) {
    int * v5600 = v5596->pht;
    v5600[66] = 1;
    int v5602 = v5596->timer;
    int v5623 = v5602 + 15;
    v5596->timer = v5623;
    int * v5604 = v5596->saved_regs;
    int v5605 = v5604[18];
    int * v5606 = v5596->regs;
    v5606[18] = v5605;
    struct StateG * v5608 = slot_286(v5596);
    v5614 = v5608;
  } else {
    int * v5610 = v5596->pht;
    v5610[66] = 0;
    struct StateG * v5612 = slot_287(v5596);
    v5614 = v5612;
  }
  return v5614;
}

struct StateG * slot_469(struct StateG * v9704) {
  int * v9705 = v9704->saved_regs;
  int * v9706 = v9704->regs;
  int v9707 = v9706[18];
  v9705[18] = v9707;
  int v9709 = v9704->timer;
  int v9719 = v9709 + 1;
  v9704->timer = v9719;
  int * v9711 = v9704->regs;
  v9711[18] = 1;
  struct StateG * v9713 = slot_501(v9704);
  return v9713;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

void ret_assert(bool c) { koika_assert(c, "return address"); }

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}