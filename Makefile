##
## Makefile for Lecteur in /home/gomel_f/Documents/ConnecteMusiquePlayer
## 
## Made by Frédéric GOMEL
## Login   <gomel_f@epitech.net>
## 
## Started on  Sun Apr 17 02:47:00 2016 Frédéric GOMEL
## Last update Mon May  2 14:53:15 2016 Frédéric GOMEL
##

NAME1	=	cmp-server

NAME2	=	cmp

SRC1	=	server/main.c \
		server/get_next_line.c \
		server/my_realloc.c \
		server/config.c \
		server/display.c \
		server/tools.c \
		server/play.c \
		server/load_playlist.c \
		server/reseau.c

SRC2	=	client/main.c \
		client/get_next_line.c \
		client/config.c \
		client/display.c \
		client/my_realloc.c \
		client/tools.c \
		client/reseau.c

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

#CFLAGS	+=	-Wextra -Wall -Werror
#CFLAGS +=	-ansi	-pedantic
CFLAGS	+=	-Iinclude/
LFLAGS	=	-lpthread

CC	=	gcc

RM	=	rm -f

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1) -L./lib -lfmodex64 $(LFLAGS)

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2)

clean:
		$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
