SECTION .text

global strcasecmp:function

strcasecmp:
	mov rax, 0
	mov r10, 0
prolog:	
	mov r11, 0
	mov r12, 0
if:
	cmp byte [rdi + r10], 65
	jnge if2
	cmp byte [rdi + r10], 90
	jnle if2
	mov r11, 32
if2:
	cmp byte [rsi + r10], 65
	jnge while
	cmp byte [rsi + r10], 90
	jnle while
	mov r12, 32
while:
	mov bl, byte [rdi + r10]
	add bl, r11b
	mov cl, byte [rsi + r10]
	add cl, r12b
	cmp cl, bl
	jne dif
	cmp cl, 0
	je right
	cmp bl, 0
	je left
	inc r10
	jmp prolog
dif:
	cmp bl, cl
	jnge negat
	sub bl, cl
	mov al, bl
	ret
negat:
	sub cl, bl
	mov al, cl
	neg rax
	ret
right:
	mov al, bl
	ret
left:
	mov al, cl
	ret
