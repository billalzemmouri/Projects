SECTION .text

global strpbrk:function

strpbrk:
	mov rax, 0
	mov r10, 0
while:
	mov r11, 0
	cmp byte [rdi + r10], 0
	je false
inception:
	mov bl, byte [rdi + r10]
	mov cl, byte [rsi + r11]
	cmp cl, 0
	je incre
	cmp bl, cl
	je return
	inc r11
	jmp inception
incre:
	inc r10
	jmp while
return:
	lea rax, [rdi + r10]
	ret
false:
	mov rax, 0
	ret
