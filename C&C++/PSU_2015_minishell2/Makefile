##
## Makefile for  in /home/zemmou_b/rendu/PSU_2015_minishell1
## 
## Made by Billal Zemmouri
## Login   <zemmou_b@epitech.net>
## 
## Started on  Mon Nov 30 16:54:39 2015 Billal Zemmouri
## Last update Sun Dec 20 23:26:28 2015 Billal Zemmouri
##

CC=	gcc

RM=	rm -f

NAME=	mysh

SRCS=	functions_p.c \
	functions.c \
	minishell2.c \
	my_str_to_wordtab.c\
	get_next_line.c

LIB=./lib/my/libmy.a \

OBJS=$(SRCS:.c=.o)

CFLAGS= -g3

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
