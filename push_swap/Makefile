NAME = a.out

SRC_PATH = srcs/
SRC = push_swap.c commands.c arr_functs.c error.c sorting_3_5.c sorting_100.c sorting_500.c stack_functs.c usefull_functs.c libft/ft_strsplit.c libft/ft_strnew.c libft/ft_isword.c libft/ft_wsize.c
SRC_PL_PATH = $(addprefix $(SRC_PATH), $(SRC))

INCLUDE_PATH = includes/
INCLUDE = push_swap.h
INCLUDE_PL_PATH = $(addprefix $(INCLUDE_PATH), $(INCLUDE))

LIB_PATH = ft_printf/
LIB = libftprintf.a
LIB_PL_PATH = $(addprefix $(LIB_PATH), $(LIB))

OBJ = $(SRC_PL_PATH:.c=.o)

FLAGS = -g

#	colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
RESET			=	\033[0m

all:$(NAME)

# $(NAME): $(OBJ)
# 	@gcc -I$(INCLUDE_PATH) $(LIB_PL_PATH) $(OBJ) -o $(NAME)
# 	@echo "$(GREEN)nu davay testiruy$(RESET)"

# $(SRC_PATH)%.o: $(SRC_PATH)%.c
# 	@gcc -c -I$(INCLUDE_PATH) $< -o $@

$(NAME):
	@gcc $(SRC_PL_PATH) $(LIB_PL_PATH) -I$(INCLUDE_PATH) -g
	@echo "$(GREEN)nu davay testiruy$(RESET)"

clean:
	@rm -rf $(OBJ)
	@rm -rf a.out.dSYM

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(RED)MUSORA NET. VOBWE NET.$(RESET)"

re: fclean all
