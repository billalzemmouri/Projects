
CPP		=	g++

CXXFLAGS        =       -std=gnu++11 -I/usr/local/include/OGRE -I/usr/include/OIS -I/usr/local/include/OGRE/Overlay -I./include  -I/usr/local/include/cegui-0 -I/usr/local/include/cegui-0/CEGUI/RendererModules/Ogre -g3

LDFLAGS         =       -lboost_system -lOIS -L/usr/local/lib/OGRE  -L/usr/local/lib/cegui-0.8 -lOgreMain -lOgreOverlay -lCEGUIBase-0 -lCEGUIOgreRenderer-0  -lpthread

NAME		=	worm

SRC		=	src/Application.cpp		\
			src/main.cpp			\
			src/Light.cpp			\
			src/Worm.cpp			\
			src/Menu.cpp			\
			src/InputListener.cpp		\
			src/Menu/MenuParameter.cpp	\
			src/Menu/MenuInGame.cpp		\
			src/Menu/MenuArmes.cpp		\
			src/Menu/MenuESCAPE.cpp		

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CPP) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
