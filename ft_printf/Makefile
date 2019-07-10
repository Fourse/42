NAME = libftprintf.a
NAME	=	libftprintf.a

LIBDIR	=	libft

SRC		=	do_char.c do_fl.c do_int.c do_wm.c ft_printf.c get_params.c out.c

LIB		=	$(addprefix $(LIBDIR)/, ft_atoi.c ft_isdigit.c ft_bzero.c ft_memcpy.c ft_strcmp.c ft_strlen.c ft_memset.c)

OBJ		=	${SRC:.c=.o} ${LIB:.c=.o} 

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
$(LIBDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -I./includes -c -o $@ $<

clean:
	rm -rf ./libft/*.o
	rm -rf ./libft/libft.a
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
