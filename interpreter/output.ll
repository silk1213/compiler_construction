define i32 @main() #0 {
%a = alloca i32, align 4
store i32 1, i32* %a, align 4
%0= load i32* %a
ret %1 
}
