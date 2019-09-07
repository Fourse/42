# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:16:10 by smorty            #+#    #+#              #
#    Updated: 2019/07/21 18:25:45 by rloraine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = srcs

SRC = 	$(addprefix $(SRCDIR)/,ft_printf.c parse_params.c process_format.c\
		process_cs.c unicode.c process_d.c process_u.c process_o.c\
		process_x.c process_b.c process_float.c float_arithmethic.c process_a.c\
		process_efg.c process_efg_2.c output.c colors.c libft/ft_atoi.c\
		libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_strnequ.c)
		
OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	ranlib $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -I./includes $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
