NAME = libft.a
SRC = *.c
OBJ = *.o
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:fclean all
