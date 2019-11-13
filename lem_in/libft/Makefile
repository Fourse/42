
CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

NAME = libft.a

SRC = ./srcs/*.c
DEPS = $(IDIR)/libft.h


IDIR = includes

OBJ = *.o

all: $(NAME)

$(NAME): 
	$(CC) -g $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
		
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
