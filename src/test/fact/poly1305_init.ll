; @_poly1305_init, by src/test/fact/extract. The body is verbatim apart from
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

define void @_poly1305_init(%poly1305_state_internal_t* %__v186_state, i8* %__v187_key) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %0 = getelementptr i8, i8* %__v187_key, i64 0
  %1 = bitcast i8* %0 to i64*
  %2 = load i64, i64* %1
  %3 = getelementptr i8, i8* %__v187_key, i64 8
  %4 = bitcast i8* %3 to i64*
  %5 = load i64, i64* %4
  %6 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 0
  %7 = bitcast [3 x i64]* %6 to i64*
  %8 = getelementptr i64, i64* %7, i64 0
  %9 = and i64 %2, 17575274610687
  store i64 %9, i64* %8
  %10 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 0
  %11 = bitcast [3 x i64]* %10 to i64*
  %12 = getelementptr i64, i64* %11, i64 1
  %13 = lshr i64 %2, 44
  %14 = shl i64 %5, 20
  %15 = or i64 %13, %14
  %16 = and i64 %15, 17592181915647
  store i64 %16, i64* %12
  %17 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 0
  %18 = bitcast [3 x i64]* %17 to i64*
  %19 = getelementptr i64, i64* %18, i64 2
  %20 = lshr i64 %5, 24
  %21 = and i64 %20, 68719475727
  store i64 %21, i64* %19
  %22 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 1
  %23 = bitcast [3 x i64]* %22 to i64*
  %24 = getelementptr i64, i64* %23, i64 0
  store i64 0, i64* %24
  %25 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 1
  %26 = bitcast [3 x i64]* %25 to i64*
  %27 = getelementptr i64, i64* %26, i64 1
  store i64 0, i64* %27
  %28 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 1
  %29 = bitcast [3 x i64]* %28 to i64*
  %30 = getelementptr i64, i64* %29, i64 2
  store i64 0, i64* %30
  %31 = getelementptr i8, i8* %__v187_key, i64 16
  %32 = bitcast i8* %31 to i64*
  %33 = load i64, i64* %32
  %34 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 2
  %35 = bitcast [2 x i64]* %34 to i64*
  %36 = getelementptr i64, i64* %35, i64 0
  store i64 %33, i64* %36
  %37 = getelementptr i8, i8* %__v187_key, i64 24
  %38 = bitcast i8* %37 to i64*
  %39 = load i64, i64* %38
  %40 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 2
  %41 = bitcast [2 x i64]* %40 to i64*
  %42 = getelementptr i64, i64* %41, i64 1
  store i64 %39, i64* %42
  %43 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 3
  store i64 0, i64* %43
  %44 = getelementptr inbounds %poly1305_state_internal_t, %poly1305_state_internal_t* %__v186_state, i32 0, i32 5
  store i8 0, i8* %44
  ret void
}
attributes #0 = { argmemonly nounwind }
attributes #1 = { nounwind }
