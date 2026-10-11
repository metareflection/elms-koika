; @_crypto_core_hsalsa20, by src/test/fact/extract. The body is verbatim apart from
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

define void @_crypto_core_hsalsa20(i8* %__v239_out, i8* %__v240_input, i8* %__v241_k) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %__v242_x0 = alloca i32
  store i32 1634760805, i32* %__v242_x0
  %__v243_x5 = alloca i32
  store i32 857760878, i32* %__v243_x5
  %__v244_x10 = alloca i32
  store i32 2036477234, i32* %__v244_x10
  %__v245_x15 = alloca i32
  store i32 1797285236, i32* %__v245_x15
  %0 = getelementptr i8, i8* %__v241_k, i64 0
  %1 = bitcast i8* %0 to i32*
  %2 = load i32, i32* %1
  %__v246_x1 = alloca i32
  store i32 %2, i32* %__v246_x1
  %3 = getelementptr i8, i8* %__v241_k, i64 4
  %4 = bitcast i8* %3 to i32*
  %5 = load i32, i32* %4
  %__v247_x2 = alloca i32
  store i32 %5, i32* %__v247_x2
  %6 = getelementptr i8, i8* %__v241_k, i64 8
  %7 = bitcast i8* %6 to i32*
  %8 = load i32, i32* %7
  %__v248_x3 = alloca i32
  store i32 %8, i32* %__v248_x3
  %9 = getelementptr i8, i8* %__v241_k, i64 12
  %10 = bitcast i8* %9 to i32*
  %11 = load i32, i32* %10
  %__v249_x4 = alloca i32
  store i32 %11, i32* %__v249_x4
  %12 = getelementptr i8, i8* %__v241_k, i64 16
  %13 = bitcast i8* %12 to i32*
  %14 = load i32, i32* %13
  %__v250_x11 = alloca i32
  store i32 %14, i32* %__v250_x11
  %15 = getelementptr i8, i8* %__v241_k, i64 20
  %16 = bitcast i8* %15 to i32*
  %17 = load i32, i32* %16
  %__v251_x12 = alloca i32
  store i32 %17, i32* %__v251_x12
  %18 = getelementptr i8, i8* %__v241_k, i64 24
  %19 = bitcast i8* %18 to i32*
  %20 = load i32, i32* %19
  %__v252_x13 = alloca i32
  store i32 %20, i32* %__v252_x13
  %21 = getelementptr i8, i8* %__v241_k, i64 28
  %22 = bitcast i8* %21 to i32*
  %23 = load i32, i32* %22
  %__v253_x14 = alloca i32
  store i32 %23, i32* %__v253_x14
  %24 = getelementptr i8, i8* %__v240_input, i64 0
  %25 = bitcast i8* %24 to i32*
  %26 = load i32, i32* %25
  %__v254_x6 = alloca i32
  store i32 %26, i32* %__v254_x6
  %27 = getelementptr i8, i8* %__v240_input, i64 4
  %28 = bitcast i8* %27 to i32*
  %29 = load i32, i32* %28
  %__v255_x7 = alloca i32
  store i32 %29, i32* %__v255_x7
  %30 = getelementptr i8, i8* %__v240_input, i64 8
  %31 = bitcast i8* %30 to i32*
  %32 = load i32, i32* %31
  %__v256_x8 = alloca i32
  store i32 %32, i32* %__v256_x8
  %33 = getelementptr i8, i8* %__v240_input, i64 12
  %34 = bitcast i8* %33 to i32*
  %35 = load i32, i32* %34
  %__v257_x9 = alloca i32
  store i32 %35, i32* %__v257_x9
  br label %36

; <label>:36:                                     ; preds = %295, %entry
  %__v258_i = phi i32 [ 0, %entry ], [ %296, %295 ]
  %37 = icmp ult i32 %__v258_i, 10
  br i1 %37, label %38, label %297

; <label>:38:                                     ; preds = %36
  %39 = load i32, i32* %__v249_x4
  %40 = load i32, i32* %__v242_x0
  %41 = load i32, i32* %__v251_x12
  %42 = add i32 %40, %41
  %43 = shl i32 %42, 7
  %44 = lshr i32 %42, 25
  %45 = or i32 %43, %44
  %46 = xor i32 %39, %45
  store i32 %46, i32* %__v249_x4
  %47 = load i32, i32* %__v256_x8
  %48 = load i32, i32* %__v249_x4
  %49 = load i32, i32* %__v242_x0
  %50 = add i32 %48, %49
  %51 = shl i32 %50, 9
  %52 = lshr i32 %50, 23
  %53 = or i32 %51, %52
  %54 = xor i32 %47, %53
  store i32 %54, i32* %__v256_x8
  %55 = load i32, i32* %__v251_x12
  %56 = load i32, i32* %__v256_x8
  %57 = load i32, i32* %__v249_x4
  %58 = add i32 %56, %57
  %59 = shl i32 %58, 13
  %60 = lshr i32 %58, 19
  %61 = or i32 %59, %60
  %62 = xor i32 %55, %61
  store i32 %62, i32* %__v251_x12
  %63 = load i32, i32* %__v242_x0
  %64 = load i32, i32* %__v251_x12
  %65 = load i32, i32* %__v256_x8
  %66 = add i32 %64, %65
  %67 = shl i32 %66, 18
  %68 = lshr i32 %66, 14
  %69 = or i32 %67, %68
  %70 = xor i32 %63, %69
  store i32 %70, i32* %__v242_x0
  %71 = load i32, i32* %__v257_x9
  %72 = load i32, i32* %__v243_x5
  %73 = load i32, i32* %__v246_x1
  %74 = add i32 %72, %73
  %75 = shl i32 %74, 7
  %76 = lshr i32 %74, 25
  %77 = or i32 %75, %76
  %78 = xor i32 %71, %77
  store i32 %78, i32* %__v257_x9
  %79 = load i32, i32* %__v252_x13
  %80 = load i32, i32* %__v257_x9
  %81 = load i32, i32* %__v243_x5
  %82 = add i32 %80, %81
  %83 = shl i32 %82, 9
  %84 = lshr i32 %82, 23
  %85 = or i32 %83, %84
  %86 = xor i32 %79, %85
  store i32 %86, i32* %__v252_x13
  %87 = load i32, i32* %__v246_x1
  %88 = load i32, i32* %__v252_x13
  %89 = load i32, i32* %__v257_x9
  %90 = add i32 %88, %89
  %91 = shl i32 %90, 13
  %92 = lshr i32 %90, 19
  %93 = or i32 %91, %92
  %94 = xor i32 %87, %93
  store i32 %94, i32* %__v246_x1
  %95 = load i32, i32* %__v243_x5
  %96 = load i32, i32* %__v246_x1
  %97 = load i32, i32* %__v252_x13
  %98 = add i32 %96, %97
  %99 = shl i32 %98, 18
  %100 = lshr i32 %98, 14
  %101 = or i32 %99, %100
  %102 = xor i32 %95, %101
  store i32 %102, i32* %__v243_x5
  %103 = load i32, i32* %__v253_x14
  %104 = load i32, i32* %__v244_x10
  %105 = load i32, i32* %__v254_x6
  %106 = add i32 %104, %105
  %107 = shl i32 %106, 7
  %108 = lshr i32 %106, 25
  %109 = or i32 %107, %108
  %110 = xor i32 %103, %109
  store i32 %110, i32* %__v253_x14
  %111 = load i32, i32* %__v247_x2
  %112 = load i32, i32* %__v253_x14
  %113 = load i32, i32* %__v244_x10
  %114 = add i32 %112, %113
  %115 = shl i32 %114, 9
  %116 = lshr i32 %114, 23
  %117 = or i32 %115, %116
  %118 = xor i32 %111, %117
  store i32 %118, i32* %__v247_x2
  %119 = load i32, i32* %__v254_x6
  %120 = load i32, i32* %__v247_x2
  %121 = load i32, i32* %__v253_x14
  %122 = add i32 %120, %121
  %123 = shl i32 %122, 13
  %124 = lshr i32 %122, 19
  %125 = or i32 %123, %124
  %126 = xor i32 %119, %125
  store i32 %126, i32* %__v254_x6
  %127 = load i32, i32* %__v244_x10
  %128 = load i32, i32* %__v254_x6
  %129 = load i32, i32* %__v247_x2
  %130 = add i32 %128, %129
  %131 = shl i32 %130, 18
  %132 = lshr i32 %130, 14
  %133 = or i32 %131, %132
  %134 = xor i32 %127, %133
  store i32 %134, i32* %__v244_x10
  %135 = load i32, i32* %__v248_x3
  %136 = load i32, i32* %__v245_x15
  %137 = load i32, i32* %__v250_x11
  %138 = add i32 %136, %137
  %139 = shl i32 %138, 7
  %140 = lshr i32 %138, 25
  %141 = or i32 %139, %140
  %142 = xor i32 %135, %141
  store i32 %142, i32* %__v248_x3
  %143 = load i32, i32* %__v255_x7
  %144 = load i32, i32* %__v248_x3
  %145 = load i32, i32* %__v245_x15
  %146 = add i32 %144, %145
  %147 = shl i32 %146, 9
  %148 = lshr i32 %146, 23
  %149 = or i32 %147, %148
  %150 = xor i32 %143, %149
  store i32 %150, i32* %__v255_x7
  %151 = load i32, i32* %__v250_x11
  %152 = load i32, i32* %__v255_x7
  %153 = load i32, i32* %__v248_x3
  %154 = add i32 %152, %153
  %155 = shl i32 %154, 13
  %156 = lshr i32 %154, 19
  %157 = or i32 %155, %156
  %158 = xor i32 %151, %157
  store i32 %158, i32* %__v250_x11
  %159 = load i32, i32* %__v245_x15
  %160 = load i32, i32* %__v250_x11
  %161 = load i32, i32* %__v255_x7
  %162 = add i32 %160, %161
  %163 = shl i32 %162, 18
  %164 = lshr i32 %162, 14
  %165 = or i32 %163, %164
  %166 = xor i32 %159, %165
  store i32 %166, i32* %__v245_x15
  %167 = load i32, i32* %__v246_x1
  %168 = load i32, i32* %__v242_x0
  %169 = load i32, i32* %__v248_x3
  %170 = add i32 %168, %169
  %171 = shl i32 %170, 7
  %172 = lshr i32 %170, 25
  %173 = or i32 %171, %172
  %174 = xor i32 %167, %173
  store i32 %174, i32* %__v246_x1
  %175 = load i32, i32* %__v247_x2
  %176 = load i32, i32* %__v246_x1
  %177 = load i32, i32* %__v242_x0
  %178 = add i32 %176, %177
  %179 = shl i32 %178, 9
  %180 = lshr i32 %178, 23
  %181 = or i32 %179, %180
  %182 = xor i32 %175, %181
  store i32 %182, i32* %__v247_x2
  %183 = load i32, i32* %__v248_x3
  %184 = load i32, i32* %__v247_x2
  %185 = load i32, i32* %__v246_x1
  %186 = add i32 %184, %185
  %187 = shl i32 %186, 13
  %188 = lshr i32 %186, 19
  %189 = or i32 %187, %188
  %190 = xor i32 %183, %189
  store i32 %190, i32* %__v248_x3
  %191 = load i32, i32* %__v242_x0
  %192 = load i32, i32* %__v248_x3
  %193 = load i32, i32* %__v247_x2
  %194 = add i32 %192, %193
  %195 = shl i32 %194, 18
  %196 = lshr i32 %194, 14
  %197 = or i32 %195, %196
  %198 = xor i32 %191, %197
  store i32 %198, i32* %__v242_x0
  %199 = load i32, i32* %__v254_x6
  %200 = load i32, i32* %__v243_x5
  %201 = load i32, i32* %__v249_x4
  %202 = add i32 %200, %201
  %203 = shl i32 %202, 7
  %204 = lshr i32 %202, 25
  %205 = or i32 %203, %204
  %206 = xor i32 %199, %205
  store i32 %206, i32* %__v254_x6
  %207 = load i32, i32* %__v255_x7
  %208 = load i32, i32* %__v254_x6
  %209 = load i32, i32* %__v243_x5
  %210 = add i32 %208, %209
  %211 = shl i32 %210, 9
  %212 = lshr i32 %210, 23
  %213 = or i32 %211, %212
  %214 = xor i32 %207, %213
  store i32 %214, i32* %__v255_x7
  %215 = load i32, i32* %__v249_x4
  %216 = load i32, i32* %__v255_x7
  %217 = load i32, i32* %__v254_x6
  %218 = add i32 %216, %217
  %219 = shl i32 %218, 13
  %220 = lshr i32 %218, 19
  %221 = or i32 %219, %220
  %222 = xor i32 %215, %221
  store i32 %222, i32* %__v249_x4
  %223 = load i32, i32* %__v243_x5
  %224 = load i32, i32* %__v249_x4
  %225 = load i32, i32* %__v255_x7
  %226 = add i32 %224, %225
  %227 = shl i32 %226, 18
  %228 = lshr i32 %226, 14
  %229 = or i32 %227, %228
  %230 = xor i32 %223, %229
  store i32 %230, i32* %__v243_x5
  %231 = load i32, i32* %__v250_x11
  %232 = load i32, i32* %__v244_x10
  %233 = load i32, i32* %__v257_x9
  %234 = add i32 %232, %233
  %235 = shl i32 %234, 7
  %236 = lshr i32 %234, 25
  %237 = or i32 %235, %236
  %238 = xor i32 %231, %237
  store i32 %238, i32* %__v250_x11
  %239 = load i32, i32* %__v256_x8
  %240 = load i32, i32* %__v250_x11
  %241 = load i32, i32* %__v244_x10
  %242 = add i32 %240, %241
  %243 = shl i32 %242, 9
  %244 = lshr i32 %242, 23
  %245 = or i32 %243, %244
  %246 = xor i32 %239, %245
  store i32 %246, i32* %__v256_x8
  %247 = load i32, i32* %__v257_x9
  %248 = load i32, i32* %__v256_x8
  %249 = load i32, i32* %__v250_x11
  %250 = add i32 %248, %249
  %251 = shl i32 %250, 13
  %252 = lshr i32 %250, 19
  %253 = or i32 %251, %252
  %254 = xor i32 %247, %253
  store i32 %254, i32* %__v257_x9
  %255 = load i32, i32* %__v244_x10
  %256 = load i32, i32* %__v257_x9
  %257 = load i32, i32* %__v256_x8
  %258 = add i32 %256, %257
  %259 = shl i32 %258, 18
  %260 = lshr i32 %258, 14
  %261 = or i32 %259, %260
  %262 = xor i32 %255, %261
  store i32 %262, i32* %__v244_x10
  %263 = load i32, i32* %__v251_x12
  %264 = load i32, i32* %__v245_x15
  %265 = load i32, i32* %__v253_x14
  %266 = add i32 %264, %265
  %267 = shl i32 %266, 7
  %268 = lshr i32 %266, 25
  %269 = or i32 %267, %268
  %270 = xor i32 %263, %269
  store i32 %270, i32* %__v251_x12
  %271 = load i32, i32* %__v252_x13
  %272 = load i32, i32* %__v251_x12
  %273 = load i32, i32* %__v245_x15
  %274 = add i32 %272, %273
  %275 = shl i32 %274, 9
  %276 = lshr i32 %274, 23
  %277 = or i32 %275, %276
  %278 = xor i32 %271, %277
  store i32 %278, i32* %__v252_x13
  %279 = load i32, i32* %__v253_x14
  %280 = load i32, i32* %__v252_x13
  %281 = load i32, i32* %__v251_x12
  %282 = add i32 %280, %281
  %283 = shl i32 %282, 13
  %284 = lshr i32 %282, 19
  %285 = or i32 %283, %284
  %286 = xor i32 %279, %285
  store i32 %286, i32* %__v253_x14
  %287 = load i32, i32* %__v245_x15
  %288 = load i32, i32* %__v253_x14
  %289 = load i32, i32* %__v252_x13
  %290 = add i32 %288, %289
  %291 = shl i32 %290, 18
  %292 = lshr i32 %290, 14
  %293 = or i32 %291, %292
  %294 = xor i32 %287, %293
  store i32 %294, i32* %__v245_x15
  br label %295

; <label>:295:                                    ; preds = %38
  %296 = add i32 %__v258_i, 1
  br label %36

; <label>:297:                                    ; preds = %36
  %298 = getelementptr i8, i8* %__v239_out, i64 0
  %299 = load i32, i32* %__v242_x0
  %300 = bitcast i8* %298 to i32*
  store i32 %299, i32* %300
  %301 = getelementptr i8, i8* %__v239_out, i64 4
  %302 = load i32, i32* %__v243_x5
  %303 = bitcast i8* %301 to i32*
  store i32 %302, i32* %303
  %304 = getelementptr i8, i8* %__v239_out, i64 8
  %305 = load i32, i32* %__v244_x10
  %306 = bitcast i8* %304 to i32*
  store i32 %305, i32* %306
  %307 = getelementptr i8, i8* %__v239_out, i64 12
  %308 = load i32, i32* %__v245_x15
  %309 = bitcast i8* %307 to i32*
  store i32 %308, i32* %309
  %310 = getelementptr i8, i8* %__v239_out, i64 16
  %311 = load i32, i32* %__v254_x6
  %312 = bitcast i8* %310 to i32*
  store i32 %311, i32* %312
  %313 = getelementptr i8, i8* %__v239_out, i64 20
  %314 = load i32, i32* %__v255_x7
  %315 = bitcast i8* %313 to i32*
  store i32 %314, i32* %315
  %316 = getelementptr i8, i8* %__v239_out, i64 24
  %317 = load i32, i32* %__v256_x8
  %318 = bitcast i8* %316 to i32*
  store i32 %317, i32* %318
  %319 = getelementptr i8, i8* %__v239_out, i64 28
  %320 = load i32, i32* %__v257_x9
  %321 = bitcast i8* %319 to i32*
  store i32 %320, i32* %321
  ret void
}
attributes #0 = { argmemonly nounwind }
attributes #1 = { nounwind }
