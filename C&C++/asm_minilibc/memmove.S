SECTION .text

global memmove:function

memmove:
	mov rax, 0
	mov r10, 0
while:
	cmp byte [rsi + r10], 0
	je zero
	cmp r10, rdx
	je return
	mov cl, byte [rsi + r10]
	mov byte [rdi + r10], cl
	inc r10
	jmp while
return:
	mov rdi, rax
	ret
zero:
	mov byte [rdi + r10], 0
	jmp return
