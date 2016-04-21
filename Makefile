##
## Makefile for Lecteur in /home/gomel_f/Documents/ConnecteMusiquePlayer
## 
## Made by Frédéric GOMEL
## Login   <gomel_f@epitech.net>
## 
## Started on  Sun Apr 17 02:47:00 2016 Frédéric GOMEL
## Last update Thu Apr 21 15:08:03 2016 guillaume
##

NAME1	=	cmp-server

NAME2	=	cmp

SRC1	=	server/main.c \
		server/get_next_line.c \
		server/my_realloc.c \
		server/config.c \
		server/display.c \
		server/tools.c \
		server/play.c

SRC2	=	client/main.c \
		client/config.c \
		client/display.c \
		client/my_realloc.c \
		client/get_next_line.c \
		client/tools.c

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

#CFLAGS	+=	-Wextra -Wall -Werror
#CFLAGS +=	-ansi	-pedantic
CFLAGS	+=	-Iinclude/
LFLAGS	=	-Llib/ -lfmodex64

CC	=	gcc

RM	=	rm -f

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1) $(LFLAGS)

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2)

clean:
		$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
