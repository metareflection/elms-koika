; @_salsa_keysetup, by src/test/fact/extract. The body is verbatim apart from
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

define void @_salsa_keysetup(i32* %__v55_ctx, i8* %__v56_k) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %__v57_TR = alloca i32, i64 16
  %0 = getelementptr i32, i32* %__v57_TR, i64 0
  store i32 0, i32* %0
  %1 = getelementptr i32, i32* %__v57_TR, i64 1
  store i32 5, i32* %1
  %2 = getelementptr i32, i32* %__v57_TR, i64 2
  store i32 10, i32* %2
  %3 = getelementptr i32, i32* %__v57_TR, i64 3
  store i32 15, i32* %3
  %4 = getelementptr i32, i32* %__v57_TR, i64 4
  store i32 12, i32* %4
  %5 = getelementptr i32, i32* %__v57_TR, i64 5
  store i32 1, i32* %5
  %6 = getelementptr i32, i32* %__v57_TR, i64 6
  store i32 6, i32* %6
  %7 = getelementptr i32, i32* %__v57_TR, i64 7
  store i32 11, i32* %7
  %8 = getelementptr i32, i32* %__v57_TR, i64 8
  store i32 8, i32* %8
  %9 = getelementptr i32, i32* %__v57_TR, i64 9
  store i32 13, i32* %9
  %10 = getelementptr i32, i32* %__v57_TR, i64 10
  store i32 2, i32* %10
  %11 = getelementptr i32, i32* %__v57_TR, i64 11
  store i32 7, i32* %11
  %12 = getelementptr i32, i32* %__v57_TR, i64 12
  store i32 4, i32* %12
  %13 = getelementptr i32, i32* %__v57_TR, i64 13
  store i32 9, i32* %13
  %14 = getelementptr i32, i32* %__v57_TR, i64 14
  store i32 14, i32* %14
  %15 = getelementptr i32, i32* %__v57_TR, i64 15
  store i32 3, i32* %15
  %16 = getelementptr i8, i8* %__v56_k, i64 0
  %17 = bitcast i8* %16 to i32*
  %18 = load i32, i32* %17
  %19 = getelementptr i32, i32* %__v55_ctx, i64 5
  store i32 %18, i32* %19
  %20 = getelementptr i8, i8* %__v56_k, i64 4
  %21 = bitcast i8* %20 to i32*
  %22 = load i32, i32* %21
  %23 = getelementptr i32, i32* %__v55_ctx, i64 10
  store i32 %22, i32* %23
  %24 = getelementptr i8, i8* %__v56_k, i64 8
  %25 = bitcast i8* %24 to i32*
  %26 = load i32, i32* %25
  %27 = getelementptr i32, i32* %__v55_ctx, i64 15
  store i32 %26, i32* %27
  %28 = getelementptr i8, i8* %__v56_k, i64 12
  %29 = bitcast i8* %28 to i32*
  %30 = load i32, i32* %29
  %31 = getelementptr i32, i32* %__v55_ctx, i64 12
  store i32 %30, i32* %31
  %32 = getelementptr i8, i8* %__v56_k, i64 16
  %33 = bitcast i8* %32 to i32*
  %34 = load i32, i32* %33
  %35 = getelementptr i32, i32* %__v55_ctx, i64 7
  store i32 %34, i32* %35
  %36 = getelementptr i8, i8* %__v56_k, i64 20
  %37 = bitcast i8* %36 to i32*
  %38 = load i32, i32* %37
  %39 = getelementptr i32, i32* %__v55_ctx, i64 4
  store i32 %38, i32* %39
  %40 = getelementptr i8, i8* %__v56_k, i64 24
  %41 = bitcast i8* %40 to i32*
  %42 = load i32, i32* %41
  %43 = getelementptr i32, i32* %__v55_ctx, i64 9
  store i32 %42, i32* %43
  %44 = getelementptr i8, i8* %__v56_k, i64 28
  %45 = bitcast i8* %44 to i32*
  %46 = load i32, i32* %45
  %47 = getelementptr i32, i32* %__v55_ctx, i64 14
  store i32 %46, i32* %47
  %48 = getelementptr i32, i32* %__v55_ctx, i64 0
  store i32 1634760805, i32* %48
  %49 = getelementptr i32, i32* %__v55_ctx, i64 1
  store i32 857760878, i32* %49
  %50 = getelementptr i32, i32* %__v55_ctx, i64 2
  store i32 2036477234, i32* %50
  %51 = getelementptr i32, i32* %__v55_ctx, i64 3
  store i32 1797285236, i32* %51
  ret void
}
attributes #0 = { argmemonly nounwind }
attributes #1 = { nounwind }
