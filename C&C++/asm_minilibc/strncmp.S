SECTION .text

global strncmp:function

strncmp:
	mov rax, 0
	mov r10, 0
while:
	cmp rdx, r10
	je return
	mov bl, [rdi + r10]
	mov cl, [rsi + r10]
	cmp bl, 0
	je right
	cmp cl, 0
	je left
	cmp bl, cl
	jne dif
	inc r10
	jmp while
dif:
	cmp bl, cl
	jl face
	sub bl, cl
	mov al, bl
	ret
face:
	sub cl, bl
	mov al, cl
	neg rax
	ret
right:
	cmp cl, 0
	je return
	mov al, cl
	ret
left:
	cmp bl, 0
	je return
	mov al, bl
	ret
return:
	mov rax, 0
	ret
