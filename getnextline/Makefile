SRC = get_next_line.c main.c 
HEADS = get_next_line.h ./libft/libft.a

FLAGS = -Wall -Wextra -Werror
all:
	gcc $(FLAGS) $(SRC) -I $(HEADS)
clean:
	rm -rf *.o
fclean:clean
	rm -rf a.out
re:fclean all
