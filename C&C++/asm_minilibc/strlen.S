SECTION .text

global strlen:function

strlen:
	mov rax, 0
iterator:
	cmp byte [rdi + rax], 0
	je return
	inc rax
	jmp iterator
return:
	ret
