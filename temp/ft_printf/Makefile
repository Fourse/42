NAME = libftprintf.a

#	sources
SRCDIR = srcs
SRC_DIR			=	srcs/
SRC_FILES		=	do_a_wm.c do_char.c do_fl_wm.c do_fl_wm2.c do_fl.c do_int.c do_wm.c\
					ft_printf.c get_params.c long_arithmetic.c out.c
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

#	lib_sources
LIB_DIR			=	$(addprefix $(SRC_DIR), libft/)
LIB_FILES		=	ft_abs.c ft_atoi.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_memset.c\
					ft_strcmp.c ft_strlen.c ft_strnequ.c
LIB_SRCS		=	$(addprefix $(LIB_DIR), $(LIB_FILES))

#	objects
OBJ				=	${SRCS:.c=.o} ${LIB_SRCS:.c=.o}

#	compilation
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

#	colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
RESET			=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "$(GREEN)$(NAME) was created$(RESET)"

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -I./includes $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FORCE CLEAN. AAAAAAAAAAAA$(RESET)"

re: fclean all
