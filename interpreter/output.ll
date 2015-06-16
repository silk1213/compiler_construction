define i32 @test(i32 %a) #0 {
%1 = alloca i32 , align 4
store i32 %a, i32* %1 , align 4
%2 = load i32* %a
%3 = load i32* %a
%4 = mul nsw i32 %2, %3
%b = alloca i32, align 4
store i32 %4, i32* %b, align 4
%5 = load i32* %b
ret i32 %5 
}
define i32 @main() #0 {
%b = alloca i32, align 4
store i32 2, i32* %b, align 4
%6 = load i32* %b
%7 = load i32* %b
call i32 @test(i32%7)
%a = alloca i32, align 4
store i32 , i32* %a, align 4
%8 = load i32* %a
ret i32 %8 
}
