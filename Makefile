##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compile 101 pong
##

SRC    =	101pong.c

OBJ    =    $(SRC:.c=.o)

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
