; @_crypto_verify_16, by src/test/fact/extract. The body is verbatim apart from
; the `internal` that kept it inside its module.
;
; crypto_secretbox/ll/crypto_secretbox.asm.ll of PLSysSec/fact-eval@888bc6c6,
; rebuilt in place by `./factc --eval`, so with -no-inline-asm.
; ModuleID = './crypto_secretbox.asm.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%poly1305_state_internal_t = type { [3 x i64], [3 x i64], [2 x i64], i64, [16 x i8], i8 }

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i32, i1) #0

define i1 @_crypto_verify_16(i8* %__v179_x, i8* %__v180_y) {
entry:
  %__rval = alloca i1
  store i1 false, i1* %__rval
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  br label %0

; <label>:0:                                      ; preds = %17, %entry
  %__v181_i = phi i32 [ 0, %entry ], [ %18, %17 ]
  %1 = icmp ult i32 %__v181_i, 16
  br i1 %1, label %2, label %19

; <label>:2:                                      ; preds = %0
  %__m5 = load i1, i1* %__rctx
  %__v429_lexpr = zext i32 %__v181_i to i64
  %__v430_lexpr = zext i32 %__v181_i to i64
  %3 = getelementptr i8, i8* %__v179_x, i64 %__v429_lexpr
  %4 = load i8, i8* %3
  %5 = getelementptr i8, i8* %__v180_y, i64 %__v430_lexpr
  %6 = load i8, i8* %5
  %__m6 = icmp ne i8 %4, %6
  %7 = and i1 true, %__m6
  %8 = and i1 %7, %__m5
  %9 = load i1, i1* %__rval
  %10 = and i1 %8, %9
  %11 = xor i1 %9, %10
  store i1 %11, i1* %__rval
  %12 = and i1 true, %__m6
  %13 = and i1 %12, %__m5
  %14 = load i1, i1* %__rctx
  %15 = and i1 %13, %14
  %16 = xor i1 %14, %15
  store i1 %16, i1* %__rctx
  %__m7 = xor i1 %__m6, true
  %__m8 = xor i1 %__m5, true
  br label %17

; <label>:17:                                     ; preds = %2
  %18 = add i32 %__v181_i, 1
  br label %0

; <label>:19:                                     ; preds = %0
  %__m3 = load i1, i1* %__rctx
  %20 = and i1 true, %__m3
  %21 = load i1, i1* %__rval
  %22 = xor i1 true, %21
  %23 = and i1 %20, %22
  %24 = xor i1 %21, %23
  store i1 %24, i1* %__rval
  %25 = and i1 true, %__m3
  %26 = load i1, i1* %__rctx
  %27 = and i1 %25, %26
  %28 = xor i1 %26, %27
  store i1 %28, i1* %__rctx
  %__m4 = xor i1 %__m3, true
  %29 = load i1, i1* %__rval
  ret i1 %29
}
attributes #0 = { argmemonly nounwind }
attributes #1 = { nounwind }
