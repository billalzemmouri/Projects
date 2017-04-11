SECTION .text

global strcspn:function

strcspn:
	mov rax, 0
	mov r10, 0
while:
	mov r11, 0
	cmp byte [rdi + r10], 0
	je return
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
	mov rax, r10
	ret
