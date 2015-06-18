; ModuleID = 'test4.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @plus(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = add nsw i32 %3, %4
  ret i32 %5
}

; Function Attrs: nounwind uwtable
define double @asd() #0 {
  ret double 1.000000e+00
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca double, align 8
  %d = alloca double, align 8
  store i32 0, i32* %1
  store i32 1, i32* %b, align 4
  store i32 1, i32* %a, align 4
  store double 1.000000e+00, double* %d, align 8
  store double 1.000000e+00, double* %c, align 8
  %2 = load i32* %a, align 4
  %3 = load i32* %b, align 4
  %4 = sdiv i32 %2, %3
  %5 = load i32* %a, align 4
  %6 = load i32* %b, align 4
  %7 = mul nsw i32 %5, %6
  %8 = load i32* %a, align 4
  %9 = load i32* %b, align 4
  %10 = add nsw i32 %8, %9
  %11 = load i32* %a, align 4
  %12 = load i32* %b, align 4
  %13 = sub nsw i32 %11, %12
  %14 = load double* %c, align 8
  %15 = load double* %d, align 8
  %16 = fdiv double %14, %15
  %17 = load double* %c, align 8
  %18 = load double* %d, align 8
  %19 = fadd double %17, %18
  %20 = load double* %c, align 8
  %21 = load double* %d, align 8
  %22 = fmul double %20, %21
  %23 = load double* %c, align 8
  %24 = load double* %d, align 8
  %25 = fsub double %23, %24
  %26 = load i32* %a, align 4
  %27 = load i32* %b, align 4
  %28 = icmp eq i32 %26, %27
  br i1 %28, label %29, label %30

; <label>:29                                      ; preds = %0
  br label %31

; <label>:30                                      ; preds = %0
  br label %31

; <label>:31                                      ; preds = %30, %29
  %32 = load i32* %a, align 4
  %33 = load i32* %b, align 4
  %34 = icmp ne i32 %32, %33
  br i1 %34, label %35, label %36

; <label>:35                                      ; preds = %31
  br label %37

; <label>:36                                      ; preds = %31
  br label %37

; <label>:37                                      ; preds = %36, %35
  %38 = load i32* %a, align 4
  %39 = load i32* %b, align 4
  %40 = icmp sge i32 %38, %39
  br i1 %40, label %41, label %42

; <label>:41                                      ; preds = %37
  br label %43

; <label>:42                                      ; preds = %37
  br label %43

; <label>:43                                      ; preds = %42, %41
  %44 = load i32* %a, align 4
  %45 = load i32* %b, align 4
  %46 = icmp sle i32 %44, %45
  br i1 %46, label %47, label %48

; <label>:47                                      ; preds = %43
  br label %49

; <label>:48                                      ; preds = %43
  br label %49

; <label>:49                                      ; preds = %48, %47
  %50 = load i32* %a, align 4
  %51 = load i32* %b, align 4
  %52 = icmp slt i32 %50, %51
  br i1 %52, label %53, label %54

; <label>:53                                      ; preds = %49
  br label %55

; <label>:54                                      ; preds = %49
  br label %55

; <label>:55                                      ; preds = %54, %53
  %56 = load i32* %a, align 4
  %57 = load i32* %b, align 4
  %58 = icmp sgt i32 %56, %57
  br i1 %58, label %59, label %60

; <label>:59                                      ; preds = %55
  br label %61

; <label>:60                                      ; preds = %55
  br label %61

; <label>:61                                      ; preds = %60, %59
  %62 = load double* %c, align 8
  %63 = load double* %d, align 8
  %64 = fcmp oeq double %62, %63
  br i1 %64, label %65, label %66

; <label>:65                                      ; preds = %61
  br label %67

; <label>:66                                      ; preds = %61
  br label %67

; <label>:67                                      ; preds = %66, %65
  %68 = load double* %c, align 8
  %69 = load double* %d, align 8
  %70 = fcmp une double %68, %69
  br i1 %70, label %71, label %72

; <label>:71                                      ; preds = %67
  br label %73

; <label>:72                                      ; preds = %67
  br label %73

; <label>:73                                      ; preds = %72, %71
  %74 = load double* %c, align 8
  %75 = load double* %d, align 8
  %76 = fcmp oge double %74, %75
  br i1 %76, label %77, label %78

; <label>:77                                      ; preds = %73
  br label %79

; <label>:78                                      ; preds = %73
  br label %79

; <label>:79                                      ; preds = %78, %77
  %80 = load double* %c, align 8
  %81 = load double* %d, align 8
  %82 = fcmp ole double %80, %81
  br i1 %82, label %83, label %84

; <label>:83                                      ; preds = %79
  br label %85

; <label>:84                                      ; preds = %79
  br label %85

; <label>:85                                      ; preds = %84, %83
  %86 = load double* %c, align 8
  %87 = load double* %d, align 8
  %88 = fcmp olt double %86, %87
  br i1 %88, label %89, label %90

; <label>:89                                      ; preds = %85
  br label %91

; <label>:90                                      ; preds = %85
  br label %91

; <label>:91                                      ; preds = %90, %89
  %92 = load double* %c, align 8
  %93 = load double* %d, align 8
  %94 = fcmp ogt double %92, %93
  br i1 %94, label %95, label %96

; <label>:95                                      ; preds = %91
  br label %97

; <label>:96                                      ; preds = %91
  br label %97

; <label>:97                                      ; preds = %96, %95
  ret i32 1
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
