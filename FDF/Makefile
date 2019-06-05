NAME = fdf
SRC = fdf.c
HEADER = fdf.h
LIB = ./libft/
OBJ = $(SRC:.c = .o)
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
all:$(NAME)
$(NAME):
	make -C $(LIB)
	gcc $(FLAGS) $(SRC) -I $(HEADER) -L $(LIB) -lft -o $(NAME)
clean:
	make fclean -C $(LIB)
fclean:clean
	rm-rf $(NAME)
re:fclean all
