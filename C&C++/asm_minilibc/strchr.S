SECTION .text

global strchr:function

strchr:
	mov r10, 0
iterator:
	mov bl, [rdi + r10]
	cmp bl, 0
	je false
	mov cl, sil
	cmp bl, cl
	je true
	inc r10
	jmp iterator
true:
	lea rax, [rdi + r10]
	ret
false:
	mov rax, 0
	ret
