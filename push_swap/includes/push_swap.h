/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:30 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/13 19:55:32 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../srcs/libft/libft.h"
# include "limits.h"

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

extern int g_i;

/*
**	functions
*/

/*
**	error.c
*/

void			error(void);

/*
**	push_swap.c
*/

t_stack			*fill_stack(t_stack **stack, int **arr, int argc);
t_stack			*get_num_in_stack(t_stack **stack, int **arr, int size);
int				stack_is_sorted(t_stack *stack, int size);
int				stack_size(t_stack *stack);

/*
**	sort_arr.c
*/

void			fill_arr(int **arr, int argc, char **argv, int *size);
//void			get_size(int **arr, char **argv, int *size);
void			sort_arr(int *start, int *end);
int				get_mid(int *start, int *end, int *mid);

/*
**	commands.c
*/

void			push(t_stack **take, t_stack **put, long *comm, int number);
void			swap(t_stack **stack, long *comm, int number);
void			rotate(t_stack **stack, long *comm, int number);
void			rev_rotate(t_stack **stack, long *comm, int number);

/*
**	sorting_3_5.c
*/

void			sort(t_stack **a, int size, long *comm);
void			sort_3(t_stack **a, int size, long *comm);
void			sort_5(t_stack **a, t_stack **b, int size, long *comm);

/*
**	sorting_100.c
*/

void			sort_100(t_stack **a, t_stack **b, int size, long *comm);
void			detect_b(t_stack *s, t_stack *stack, int *next, int *prev);
void			find_min_max(t_stack **a, int size, int *min, int *max);
void			find_rot_or_revrot(t_stack **a, t_stack **b, long *com, int m);
void			direction(t_stack *stack, int *count_next, int *prev, int max);
#endif
