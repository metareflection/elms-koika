; ModuleID = './fscalar_product.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @fscalar_product(i64* %__v1_output, i64* %__v2_input, i64 %__v3_scalar) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %__v4_a = alloca i128
  store i128 0, i128* %__v4_a
  %0 = getelementptr i64, i64* %__v2_input, i64 0
  %1 = load i64, i64* %0
  %2 = zext i64 %1 to i128
  %3 = zext i64 %__v3_scalar to i128
  %4 = mul i128 %2, %3
  store i128 %4, i128* %__v4_a
  %5 = getelementptr i64, i64* %__v1_output, i64 0
  %6 = load i128, i128* %__v4_a
  %7 = trunc i128 %6 to i64
  %8 = and i64 %7, 2251799813685247
  store i64 %8, i64* %5
  %9 = getelementptr i64, i64* %__v2_input, i64 1
  %10 = load i64, i64* %9
  %11 = zext i64 %10 to i128
  %12 = zext i64 %__v3_scalar to i128
  %13 = mul i128 %11, %12
  %14 = load i128, i128* %__v4_a
  %15 = lshr i128 %14, 51
  %16 = trunc i128 %15 to i64
  %17 = zext i64 %16 to i128
  %18 = add i128 %13, %17
  store i128 %18, i128* %__v4_a
  %19 = getelementptr i64, i64* %__v1_output, i64 1
  %20 = load i128, i128* %__v4_a
  %21 = trunc i128 %20 to i64
  %22 = and i64 %21, 2251799813685247
  store i64 %22, i64* %19
  %23 = getelementptr i64, i64* %__v2_input, i64 2
  %24 = load i64, i64* %23
  %25 = zext i64 %24 to i128
  %26 = zext i64 %__v3_scalar to i128
  %27 = mul i128 %25, %26
  %28 = load i128, i128* %__v4_a
  %29 = lshr i128 %28, 51
  %30 = trunc i128 %29 to i64
  %31 = zext i64 %30 to i128
  %32 = add i128 %27, %31
  store i128 %32, i128* %__v4_a
  %33 = getelementptr i64, i64* %__v1_output, i64 2
  %34 = load i128, i128* %__v4_a
  %35 = trunc i128 %34 to i64
  %36 = and i64 %35, 2251799813685247
  store i64 %36, i64* %33
  %37 = getelementptr i64, i64* %__v2_input, i64 3
  %38 = load i64, i64* %37
  %39 = zext i64 %38 to i128
  %40 = zext i64 %__v3_scalar to i128
  %41 = mul i128 %39, %40
  %42 = load i128, i128* %__v4_a
  %43 = lshr i128 %42, 51
  %44 = trunc i128 %43 to i64
  %45 = zext i64 %44 to i128
  %46 = add i128 %41, %45
  store i128 %46, i128* %__v4_a
  %47 = getelementptr i64, i64* %__v1_output, i64 3
  %48 = load i128, i128* %__v4_a
  %49 = trunc i128 %48 to i64
  %50 = and i64 %49, 2251799813685247
  store i64 %50, i64* %47
  %51 = getelementptr i64, i64* %__v2_input, i64 4
  %52 = load i64, i64* %51
  %53 = zext i64 %52 to i128
  %54 = zext i64 %__v3_scalar to i128
  %55 = mul i128 %53, %54
  %56 = load i128, i128* %__v4_a
  %57 = lshr i128 %56, 51
  %58 = trunc i128 %57 to i64
  %59 = zext i64 %58 to i128
  %60 = add i128 %55, %59
  store i128 %60, i128* %__v4_a
  %61 = getelementptr i64, i64* %__v1_output, i64 4
  %62 = load i128, i128* %__v4_a
  %63 = trunc i128 %62 to i64
  %64 = and i64 %63, 2251799813685247
  store i64 %64, i64* %61
  %65 = getelementptr i64, i64* %__v1_output, i64 0
  %66 = getelementptr i64, i64* %__v1_output, i64 0
  %67 = load i64, i64* %66
  %68 = load i128, i128* %__v4_a
  %69 = lshr i128 %68, 51
  %70 = mul i128 %69, 19
  %71 = trunc i128 %70 to i64
  %72 = add i64 %67, %71
  store i64 %72, i64* %65
  ret void
}
