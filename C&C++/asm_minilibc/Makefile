##
## Makefile for  in /home/shark/rendu/tmp/asm_minilibc
## 
## Made by Shark
## Login   <zemmou_b@epitech.net>
## 
## Started on  Tue Mar 22 10:12:09 2016 Shark
## Last update Sun Mar 27 22:23:55 2016 Shark
##

NAME = libasm.so

RM = rm -rf

all:
	nasm -f elf64 strchr.S -o strchr.o
	nasm -f elf64 strlen.S -o strlen.o
	nasm -f elf64 strcmp.S -o strcmp.o
	nasm -f elf64 strncmp.S -o strncmp.o
	nasm -f elf64 memset.S -o memset.o
	nasm -f elf64 memcpy.S -o memcpy.o
	nasm -f elf64 memmove.S -o memmove.o
	nasm -f elf64 strstr.S -o strstr.o
	nasm -f elf64 strcasecmp.S -o strcasecmp.o
	nasm -f elf64 rindex.S -o rindex.o
	nasm -f elf64 strcspn.S -o strcspn.o
	nasm -f elf64 strpbrk.S -o strpbrk.o
	gcc -o $(NAME) -shared -fpic *.o
clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
