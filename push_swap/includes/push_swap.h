/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:30 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:39:37 by rloraine         ###   ########.fr       */
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

typedef struct	s_share
{
	int				next;
	int				prev;
	int				mid;
	int				prev_mid;
	int				chech_mid;
	int				count;
}				t_share;

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

void			sort(t_stack **a, int size, long *comm);

/*
**	stack_functs.c
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

void			sort_3(t_stack **a, int size, long *comm);
void			sort_5(t_stack **a, t_stack **b, int size, long *comm);

/*
**	sorting_100.c
*/

void			sort_100(t_stack **a, t_stack **b, int size, long *comm);
void			bottom_up(t_stack **a, long *ops);
void			sort_back(t_stack **a, t_stack **b, int size, long *ops);
int				where_to(t_stack *s, int place);
int				share_stack(t_stack **a, t_stack **b, int size, long *comm);

/*
**	usefull_functs.c
*/

int				find_mid(t_stack *stack, int size);
void			find_dir(t_stack *stack, int mid, int *next, int *prev);
int				find_min(t_stack *s, int size);
int				find_max(t_stack *s, int size);

#endif
