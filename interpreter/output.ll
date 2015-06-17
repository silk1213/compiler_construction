define i32 @test(i32 %a) #0 {
%1 = alloca i32 , align 4
store i32 %a, i32* %1 , align 4
%2 = load i32* %1
%3 = load i32* %1
%4 = mul nsw i32 %2, %3
%b = alloca i32, align 4
store i32 %4, i32* %b, align 4
%5 = load i32* %b
ret i32 %5 
}
define void @test2(i32 %a) #0 {
%1 = alloca i32 , align 4
store i32 %a, i32* %1 , align 4
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
%f = alloca double, align 4
store double 0.0, double* %f, align 4
%4 = load double* %f
store double 0.0, double* %f, align 4
br label %label0
label0:
%5 = load i32* %b
%6 = icmp sgt i32 %5, 0
br i1 %6, label %label1, label %label2
label1:
%7 = load i32* %b
%8 = call i32 @test(i32 %7)
%9 = load i32* %b
%10 = sub nsw i32%9, 1
store i32 %10, i32* %b, align 4
%c = alloca i32, align 4
store i32 %10, i32* %c, align 4
%11 = load i32* %b
%12 = load i32* %c
store i32 %12, i32* %c, align 4
br label %label0
 
label2:
%13 = load i32* %a
ret i32 %13 
}
