##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	src/main.c									\
		src/set_up_global.c							\
		src/3d_scene/3d_main.c						\
		src/3d_scene/event_3d.c						\
		src/3d_scene/calcul_3d.c					\
		src/3d_scene/print_3d.c					\
		src/3d_scene/set_up_3d.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch

NAME	=	my_rpg

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
