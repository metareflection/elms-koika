; @swap_conditional, by src/test/fact/extract. The body is verbatim apart from
; the `internal` that kept it inside its module.
;
; donna/ll/curve25519-c64.ll of PLSysSec/fact-eval@888bc6c6,
; rebuilt in place by `./factc --eval`, so with -no-inline-asm.
; ModuleID = './curve25519-c64.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @swap_conditional(i64* %__v100_a, i64* %__v101_b, i64 %__v102_swapi) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %__m1 = icmp eq i64 %__v102_swapi, 1
  br label %0

; <label>:0:                                      ; preds = %20, %entry
  %__v103_i = phi i32 [ 0, %entry ], [ %21, %20 ]
  %1 = icmp ult i32 %__v103_i, 5
  br i1 %1, label %2, label %22

; <label>:2:                                      ; preds = %0
  %__v119_lexpr = zext i32 %__v103_i to i64
  %3 = getelementptr i64, i64* %__v100_a, i64 %__v119_lexpr
  %__v104_x = load i64, i64* %3
  %__v120_lexpr = zext i32 %__v103_i to i64
  %__v121_lexpr = zext i32 %__v103_i to i64
  %4 = getelementptr i64, i64* %__v100_a, i64 %__v120_lexpr
  %5 = getelementptr i64, i64* %__v101_b, i64 %__v121_lexpr
  %6 = load i64, i64* %5
  %7 = and i1 true, %__m1
  %8 = load i64, i64* %4
  %9 = sext i1 %7 to i64
  %10 = xor i64 %6, %8
  %11 = and i64 %9, %10
  %12 = xor i64 %8, %11
  store i64 %12, i64* %4
  %__v122_lexpr = zext i32 %__v103_i to i64
  %13 = getelementptr i64, i64* %__v101_b, i64 %__v122_lexpr
  %14 = and i1 true, %__m1
  %15 = load i64, i64* %13
  %16 = sext i1 %14 to i64
  %17 = xor i64 %__v104_x, %15
  %18 = and i64 %16, %17
  %19 = xor i64 %15, %18
  store i64 %19, i64* %13
  br label %20

; <label>:20:                                     ; preds = %2
  %21 = add i32 %__v103_i, 1
  br label %0

; <label>:22:                                     ; preds = %0
  %__m2 = xor i1 %__m1, true
  ret void
}
attributes #0 = { argmemonly nounwind }
