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
	movl	$1, -12(%rsp)
	jmp	.LBB0_1
	.align	16, 0x90
.LBB0_2:                                # %label1
                                        #   in Loop: Header=BB0_1 Depth=1
	incl	-4(%rsp)
.LBB0_1:                                # %label0
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$1, -12(%rsp)
	sete	%al
	cmpl	$0, -8(%rsp)
	sete	%cl
	xorb	%al, %cl
	je	.LBB0_2
# BB#3:                                 # %label2
	movl	-4(%rsp), %eax
	ret
.Ltmp0:
	.size	main, .Ltmp0-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
