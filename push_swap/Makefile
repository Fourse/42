NAME1 = push_swap
NAME2 = checker

SRC_DIR = srcs/

OBJ_DIR = $(SRC_DIR)obj/

LIBFT_DIR = $(SRC_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

LIBFT_PRINTF_DIR = $(SRC_DIR)ft_printf/
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)libftprintf.a

SRCS1 = $(addprefix $(SRC_DIR), push_swap.c arr_functs.c commands.c stack_functs.c usefull_functs.c sorting_3_5.c sorting_100.c sorting_500.c error.c)
SRCS2 = $(addprefix $(SRC_DIR), checker.c arr_functs.c commands.c stack_functs.c usefull_functs.c visualization.c)

OBJ1 = $(SRCS1:%.c=$(OBJ_DIR)%.o)
OBJ2 = $(SRCS2:%.c=$(OBJ_DIR)%.o)

CC = gcc -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LIBFT) $(LIBFT_PRINTF)
	@$(CC) -L$(LIBFT_DIR) -lft -L$(LIBFT_PRINTF_DIR) -lftprintf $^ -o $@
	@echo "$(NAME1) done!"

$(NAME2): $(OBJ2) $(LIBFT) $(LIBFT_PRINTF)
	@$(CC) -L$(LIBFT_DIR) -lft -L$(LIBFT_PRINTF_DIR) -lftprintf $^ -o $@
	@echo "$(NAME2) done!"
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

$(LIBFT_PRINTF):
	@$(MAKE) -C $(LIBFT_PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) clean

$(OBJ_DIR)%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) -I./includes/ -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
