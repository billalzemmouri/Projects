
CXX= 	g++

CXXFLAGS= -std=c++11 -W -Wall -Werror -Wextra -g3

RM= 	rm -rf

SRCS= 	src/parser/main.cpp \
		src/OperandClasses.cpp 	\
		src/Instruction.cpp \
		src/Factory.cpp	\
		src/Controller.cpp \
		src/Registre.cpp	\
		src/parser/ErrorHandler.cpp \
		src/parser/parser.cpp \
		src/parser/Regex.cpp	\
		src/BigDecimal_fonctions.cpp	\
		src/BigDecimal.cpp

LIBS= 	-I./include/

OBJS= 	$(SRCS:.cpp=.o)

NAME=	abstractVM

$(NAME): 	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS)

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
