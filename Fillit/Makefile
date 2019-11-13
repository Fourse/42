NAME = fillit
SRC = empty_map.c main.c solve.c validation.c
LIB = ./libft/
OBJ = $(SRC:.c = .o)
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	make -C $(LIB)
	gcc $(FLAGS) $(SRC) -I $(HEADER) -L $(LIB) -lft -o $(NAME)
clean:
	make fclean -C $(LIB)
fclean:clean
	rm -rf $(NAME)
re:fclean all