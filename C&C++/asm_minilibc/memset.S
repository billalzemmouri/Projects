SECTION .text

global memset:function

memset:
	mov rax, 0
	mov r10, 0
while:
	cmp byte [rdi + r10], 0
	je return
	cmp rdx, r10
	je return
	mov byte [rdi + r10], sil
	inc r10
	jmp while
return:
	mov rax, rdi
	ret
