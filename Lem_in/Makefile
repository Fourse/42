# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnella <cnella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:51:06 by cnella            #+#    #+#              #
#    Updated: 2019/10/25 14:51:10 by cnella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: $(NAME)

NAME		= lem-in

SOURCES		+= main.c \
			lem_in.c \
			output.c
SOURCES		+= $(addprefix bfs/, \
			start_bfs.c \
			start_bfs_head.c \
			start_bfs_2.c tree_bfs.c)
SOURCES		+= $(addprefix parser/, \
			parser.c \
			head_parser.c \
			improver.c )
SOURCES		+= $(addprefix g_list/, \
			ft_add_glist.c\
			ft_length_glist.c \
			ft_sort_glist.c )
SOURCES		+= $(addprefix head/, \
			spread_of_ants.c \
			classes.c \
			class_construct.c)
SOURCES		+= $(addprefix room/, \
			rooms.c \
			room_addlinks.c )
SOURCES		+= $(addprefix ways/, \
			ft_ways.c \
			ft_print_ways.c)
SOURCES		+= $(addprefix resolve/, \
			resolves.c \
			printresolve.c \
			resolve_round.c )
SOURCES		+= $(addprefix resolveconstruct/, \
			resolve_construct.c )
SOURCES		+= $(addprefix decision/, \
			change_ways.c \
			decision.c)
SOURCES		+= $(addprefix process/, \
			processing.c \
			create_array.c)
SRCS_DR		= srcs
SRCS		= $(addprefix $(SRCS_DR)/, $(SOURCES))

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g -I libft/includes -O3 -I $(INC_DR)

OBJS_DR		= objs
OBJS		= $(SRCS:$(SRCS_DR)/%.c=$(OBJS_DR)/%.o)

INC_DR = includes

LIBFT_INC_DR = libft\includes
LIBFT_DR	= libft
LIBFT		= $(LIBFT_DR)/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS_DR) $(OBJS) 
	 $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT) :
	 make -sC $(LIBFT_DR)
$(OBJS_DR) :
	 mkdir -p $(OBJS_DR) $(OBJS_DR)/bfs $(OBJS_DR)/g_list $(OBJS_DR)/head $(OBJS_DR)/parser $(OBJS_DR)/room $(OBJS_DR)/ways $(OBJS_DR)/resolve $(OBJS_DR)/resolveconstruct $(OBJS_DR)/decision $(OBJS_DR)/process

$(OBJS_DR)/%.o : $(SRCS_DR)/%.c
	 $(CC) $(CFLAGS) -o $@ -c $<

clean :
	 make -sC $(LIBFT_DR) clean
	 rm -rf $(OBJS_DR)

fclean : clean
	 make -sC $(LIBFT_DR) fclean
	 rm -f $(NAME)

re : fclean all