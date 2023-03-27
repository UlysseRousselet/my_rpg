##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	src/main.c						\
		src/event.c						\
		src/set_up.c					\
		src/calcul_3d.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch

NAME	=	3D_test

LFLAGS	= 	-lcsfml-graphics -lcsfml-window 					\
			-lcsfml-system -lcsfml-audio -L lib/my/ -lmy -lm

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

unit_tests: fclean libmy.a
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out

clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	make fclean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
