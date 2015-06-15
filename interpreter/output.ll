define i32 @main() #0 {
i32 1%a = alloca i32, align 4
store i32 %0, i32* %a, align 4
%1 = load i32* %a
ret %1 
}
