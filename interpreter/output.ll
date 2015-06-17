define i32 @test(i32 %a) #0 {
%1 = alloca i32, align 4
store i32 %a, i32* %1, align 4
%2 = load i32* %1
%3 = load i32* %1
%4 = mul nsw i32 %2, %3
%b = alloca i32, align 4
store i32 %4, i32* %b, align 4
%5 = load i32* %b
ret i32 %5 
}
define void @test2(i32 %a) #0 {
%1 = alloca i32, align 4
store i32 %a, i32* %1, align 4
ret void
}
define i32 @main() #0 {
%b = alloca i32, align 4
store i32 2, i32* %b, align 4
%1 = load i32* %b
%2 = call i32 @test(i32 %1)
%a = alloca i32, align 4
store i32 %2, i32* %a, align 4
%3 = load i32* %b
call void @test2(i32 %3)
%f = alloca double, align 8
store double 0.0, double* %f, align 8
%4 = load double* %f
store double 0.0, double* %f, align 8
%5 = load double* %f
%6 = load i32* %b
%7 = sitofp i32 %6 to double
%8 = fadd double %5, %7
%k = alloca double, align 8
store double %8, double* %k, align 8
br label %label0
label0:
%9 = load i32* %b
%10 = icmp sgt i32 %9, 0
br i1 %10, label %label1, label %label2
label1:
%11 = load i32* %b
%12 = call i32 @test(i32 %11)
%13 = load i32* %b
%14 = sub nsw i32%13, 1
store i32 %14, i32* %b, align 4
%c = alloca i32, align 4
store i32 %14, i32* %c, align 4
%15 = load i32* %b
%16 = load i32* %c
store i32 %16, i32* %c, align 4
br label %label0
 
label2:
%17 = load i32* %a
ret i32 %17 
}
