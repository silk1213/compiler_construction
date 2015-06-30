; ModuleID = 'test5.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @test(i32 %a) #0 {
  %1 = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = load i32* %1, align 4
  %4 = mul nsw i32 %2, %3
  store i32 %4, i32* %b, align 4
  %5 = load i32* %b, align 4
  ret i32 %5
}

; Function Attrs: nounwind uwtable
define void @test2(i32 %a) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  %f = alloca double, align 8
  %k = alloca double, align 8
  %c = alloca i32, align 4
  store i32 0, i32* %1
  store i32 2, i32* %b, align 4
  %2 = load i32* %b, align 4
  %3 = call i32 @test(i32 %2)
  store i32 %3, i32* %a, align 4
  %4 = load i32* %b, align 4
  call void @test2(i32 %4)
  store double 0.000000e+00, double* %f, align 8
  store double 0.000000e+00, double* %f, align 8
  %5 = load double* %f, align 8
  %6 = load i32* %b, align 4
  %7 = sitofp i32 %6 to double
  %8 = fadd double %5, %7
  store double %8, double* %k, align 8
  br label %9

; <label>:9                                       ; preds = %14, %0
  %10 = load i32* %b, align 4
  %11 = sitofp i32 %10 to double
  %12 = load double* %f, align 8
  %13 = fcmp ogt double %11, %12
  br i1 %13, label %14, label %20

; <label>:14                                      ; preds = %9
  %15 = load i32* %b, align 4
  %16 = call i32 @test(i32 %15)
  %17 = load i32* %b, align 4
  %18 = add nsw i32 %17, -1
  store i32 %18, i32* %b, align 4
  store i32 %17, i32* %c, align 4
  %19 = load i32* %c, align 4
  store i32 %19, i32* %b, align 4
  br label %9

; <label>:20                                      ; preds = %9
  %21 = load i32* %a, align 4
  ret i32 %21
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
