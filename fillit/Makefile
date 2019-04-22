NAME = fillit
SRC = *.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:fclean all
