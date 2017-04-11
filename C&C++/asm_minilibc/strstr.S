SECTION .text

global strstr:function

strstr:
	mov rax, 0
	mov r10, 0
	cmp byte [rsi], 0
	je true
prolog:
	mov r11, 0
	mov r12, 0
while:
	mov bl, byte [rdi + r10]
	cmp bl, 0
	je false
	cmp bl, byte [rsi]
	je compare
	inc r10
	jmp while
compare:
	mov r12, r10
	jmp second
second:	
	mov cl, byte [rsi + r11]
	mov bl, byte [rdi + r12]
	cmp cl, 0
	je true
	cmp bl, 0
	je choose
	cmp bl, cl
	jne prolog
	inc r11
	inc r12
	jmp second
choose:
	cmp cl, 0
	je true
	jne false
true:
	lea rax, [rdi + r10]
	ret
false:
	ret
