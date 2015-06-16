define i32 @main() #0 {
%1 = alloca i32, align 4
store i32 1, i32* %1
%a = alloca i32, align 4
store i32 %1, i32* %a, align 4
label2:
br i1 %6 = load i32* %a
%7 = alloca i32, align 4
store i32 1, i32* %7
%8 = icmp slti32 %6, %7
, label %label3, label %label4
label3:
%9 = load i32* %a
%10 = add nsw i32%9, 1
%10 = add nsw i32%9, 1
br label %label5
label4:
%12 = load i32* %a
%13 = sub nsw i32%12, 1
%13 = sub nsw i32%12, 1
br label %label5
label5:
%15 = load i32* %a
ret i32 %15 
}
