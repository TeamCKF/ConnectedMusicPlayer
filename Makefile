##
## Makefile for Lecteur in /home/gomel_f/Documents/ConnecteMusiquePlayer
## 
## Made by Frédéric GOMEL
## Login   <gomel_f@epitech.net>
## 
## Started on  Sun Apr 17 02:47:00 2016 Frédéric GOMEL
## Last update Tue Apr 19 16:22:34 2016 Frédéric GOMEL
##

NAME1	=	cmp-server

NAME2	=	cmp-client

SRC1	=	server/main.c

SRC2	=

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CFLAGS	+=	-Wextra -Wall -Werror
#CFLAGS +=	-ansi	-pedantic
CFLAGS	+=	-I
#LFLAGS	=	-L/api/lowlevel/lib/x86_64 -lfmod

CC	=	gcc

RM	=	rm -f

all:	$(NAME1)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1)

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2) $(LFLAGS)

clean:
		$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
