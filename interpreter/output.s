	.text
	.file	"output.ll"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	movl	$1, -4(%rsp)
	cmpl	$0, -4(%rsp)
	jle	.LBB0_1
# BB#2:                                 # %label2
	decl	-4(%rsp)
	movl	-4(%rsp), %eax
	retq
.LBB0_1:                                # %label1
	incl	-4(%rsp)
	movl	-4(%rsp), %eax
	retq
.Ltmp0:
	.size	main, .Ltmp0-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
