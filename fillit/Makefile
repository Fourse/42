NAME = fillit
SRC = main.c solve.c error.c ./libft/ft_strdup.c ./libft/ft_bzero.c \
./libft/ft_strnew.c ./libft/ft_putendl.c ./libft/ft_putendl_fd.c \
./libft/ft_putstr.c ./libft/ft_putstr_fd.c ./libft/ft_putchar.c \
./libft/ft_putchar_fd.c ./libft/ft_strlen.c
OBJ = *.o
INCLUDES = 
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
