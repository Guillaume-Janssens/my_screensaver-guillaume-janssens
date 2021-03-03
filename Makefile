##
## EPITECH PROJECT, 2020
## evalexper
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	screensaver.c	\
		shape.c		\
		init.c		\
		two.c		\
		tree.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -I./include

GFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

NAME	=	screensaver

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(GFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
