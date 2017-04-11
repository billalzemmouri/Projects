##
## Makefile for  in /home/shark/rendu/piscine_de_synthese/autocompletion
## 
## Made by Shark
## Login   <zemmou_b@epitech.net>
## 
## Started on  Thu Jun 30 10:12:03 2016 Shark
## Last update Tue Jul  5 17:49:47 2016 Shark
##
CPP		=	g++

CXXFLAGS        =     	 -std=c++11 -I./include 

NAME		=	autoCompletion

SRC		=	src/main.cpp\
			src/Dict.cpp\
			src/Autocompletion.cpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CPP) $(OBJ) -o $(NAME)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
