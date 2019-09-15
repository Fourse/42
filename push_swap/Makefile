NAME1 = push_swap

NAME2 = checker

SRCDIR = srcs/

OBJDIR = $(SRCDIR)obj/

LFTDIR = $(SRCDIR)libft/

LFT = $(LFTDIR)libft.a

LFTPRINTFDIR = $(SRCDIR)ft_printf/

LFTPRINTF = $(LFTPRINTFDIR)libftprintf.a

SRCS1 = $(addprefix $(SRCDIR),push_swap.c arr_functs.c arr_functs_ch.c commands.c stack_functs.c stack_functs_ch.c usefull_functs.c sorting_3_5.c sorting_100.c sorting_500.c error.c)

SRCS2 = $(addprefix $(SRCDIR),checker.c arr_functs.c arr_functs_ch.c commands.c stack_functs.c stack_functs_ch.c usefull_functs.c visualization.c error.c)

OBJ1 = $(SRCS1:%.c=$(OBJDIR)%.o)

OBJ2 = $(SRCS2:%.c=$(OBJDIR)%.o)

CC = gcc -Wall -Werror -Wextra

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME1) done!"

$(NAME2): $(OBJ2) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME2) done!"

$(LFT):
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(LFTDIR) clean

$(LFTPRINTF):
	@$(MAKE) -C $(LFTPRINTFDIR)
	@$(MAKE) -C $(LFTPRINTFDIR) clean

$(OBJDIR)%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) -I./includes -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LFTDIR) fclean
	@$(MAKE) -C $(LFTPRINTFDIR) fclean

fclean: clean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
