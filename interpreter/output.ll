define i32 @main() #0 {
  %a = alloca i32, align 4
  store i32 1, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 1, i32* %b, align 4
  %1 = load i32* %a , align 4
  %2 = load i32* %b , align 4
  %3 = add nsw i32 %1, %2
  %c = alloca i32, align 4
  store i32 %3, i32* %c, align 4
  %4 = load i32* %c , align 4
  ret i32 %4 
}
