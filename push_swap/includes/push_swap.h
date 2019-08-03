/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:30 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 17:00:57 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../srcs/libft/libft.h"
# include <limits.h>

/*
**	macro
*/

# define SA 2
# define SB 4
# define SS 8
# define PA 16
# define PB 32
# define RA 64
# define RB 128
# define RR 256
# define RRA 512
# define RRB 1024
# define RRR 2048

/*
**	structures
*/

typedef struct	s_stack
{
	int				ret;
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
**	functions
*/

/*
**	push_swap.c
*/

int				fill_arr(int **arr, int argc, char **argv, int *size);
void			get_size(int **arr, char **argv, int *size);
t_stack			*fill_stack(t_stack **stack, int **arr, int argc);

/*
**	commands.c
*/

void			push(t_stack **take, t_stack **put);
void			swap(t_stack **stack);
void			rotate(t_stack **stack);
void			rev_rotate(t_stack **stack);

/*
**	sort_arr.c
*/

void			sort_arr(int *start, int *end);
int				get_mid(int *start, int *end, int *mid);

#endif
