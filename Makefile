##
## Makefile for Lecteur in /home/gomel_f/Documents/ConnecteMusiquePlayer
## 
## Made by Frédéric GOMEL
## Login   <gomel_f@epitech.net>
## 
## Started on  Sun Apr 17 02:47:00 2016 Frédéric GOMEL
## Last update Tue May 10 15:58:21 2016 guillaume
##

NAME1	=	cmp-server

NAME2	=	cmp

SRC1	=	src/server/main.c \
		src/server/get_next_line.c \
		src/server/my_realloc.c \
		src/server/config.c \
		src/server/display.c \
		src/server/tools.c \
		src/server/play.c \
		src/server/load_playlist.c \
		src/server/reseau.c \
		src/server/gest_client.c

SRC2	=	src/client/main.c \
		src/client/get_next_line.c \
		src/client/config.c \
		src/client/display.c \
		src/client/my_realloc.c \
		src/client/tools.c \
		src/client/reseau.c \
		src/client/props.c \
		src/client/init.c \

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

#CFLAGS	+=	-Wextra -Wall -Werror
#CFLAGS +=	-ansi	-pedantic
CFLAGS	+=	-Iinclude/
LFLAGS	=	-lpthread
LIB	=	./lib/libfmodex64.so
SDL	=	-lSDLmain -lSDL -lSDL_image -lSDL_ttf -lm -ldl

CC	=	gcc

RM	=	rm -f

all:		$(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1) $(LIB) $(LFLAGS)

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2) $(LFLAGS) $(SDL)

clean:
		$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
