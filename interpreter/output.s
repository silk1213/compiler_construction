	.file	"output.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	movl	$1, -4(%rsp)
	movl	$0, -8(%rsp)
	cmpl	$0, -4(%rsp)
	jle	.LBB0_2
# BB#1:                                 # %label4
	cmpl	$0, -8(%rsp)
	je	.LBB0_2
# BB#3:                                 # %label2
	decl	-4(%rsp)
	movl	-4(%rsp), %eax
	ret
.LBB0_2:                                # %label1
	incl	-4(%rsp)
	movl	-4(%rsp), %eax
	ret
.Ltmp0:
	.size	main, .Ltmp0-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
