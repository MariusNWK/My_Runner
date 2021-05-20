##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	=	-I include/ -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.Phony: all clean fclean re
