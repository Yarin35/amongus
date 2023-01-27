##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC	=	lib/my/list_add.c	\
		lib/my/list_get.c	\
		lib/my/list_remove.c	\
		lib/my/list_create.c	\
		lib/my/list_reload.c

OBJ	=	$(SRC:.c=.o)

NAME	=	moguslib.a

CFLAGS  =       -Wall -Werror -Wextra -g
CFLAGS	+=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o runner $(CFLAGS) main.c moguslib.a

clean:
	rm -f $ $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f runner

re:	fclean all

.PHONY:	re clean fclean all
