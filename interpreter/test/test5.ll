; ModuleID = './test5.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
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
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 0, i32* %1
  store i32 2, i32* %b, align 4
  %2 = load i32* %b, align 4
  %3 = call i32 @test(i32 %2)
  store i32 %3, i32* %a, align 4
  %4 = load i32* %a, align 4
  ret i32 %4
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.6.1 (tags/RELEASE_361/final)"}
