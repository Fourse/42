/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:30 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/07 17:01:42 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/includes/ft_printf.h"
# include "limits.h"

/*
**	macro
*/

# define SA 1
# define RA 10
# define RRA 100
# define PA 1000
# define SB 3
# define RB 30
# define RRB 300
# define PB 3000
# define SS 5
# define RR 50
# define RRR 500

/*
**	structures
*/

typedef struct	s_stack
{
	int				ret;
	int				num;
	int				stack;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
**	functions
*/

/*
**	error.c
*/

void			error(void);

/*
**	----PUSH_SWAP_FUNCTS----
*/

/*
**	push_swap.c
*/

void			sort(t_stack **a, int size, int *comm);

/*
**	stack_functs.c
*/

t_stack			*fill_stack(t_stack **stack, int **arr, int argc);
t_stack			*get_num_in_stack(t_stack **stack, int **arr, int size);
int				stack_is_sorted(t_stack *stack, int size);
int				stack_size(t_stack *stack);

/*
**	arr_functs.c
*/

void			fill_arr(int **arr, int argc, char **argv, int *size);
void			sort_arr(int *start, int *end);
int				get_mid(int *start, int *end, int *mid);

/*
**	commands.c
*/

void			push(t_stack **take, t_stack **put, int **comm);
void			swap(t_stack **stack, int **comm);
void			rotate(t_stack **stack, int **comm);
void			rev_rotate(t_stack **stack, int **comm);

/*
**	sorting_3_5.c
*/

void			sort_3(t_stack **a, int size, int **comm);
void			sort_5(t_stack **a, t_stack **b, int size, int **comm);

/*
**	sorting_100.c
*/

void			sort_100(t_stack **a, t_stack **b, int size, int **comm);
void			get_up(t_stack **a, int **comm);
void			sort_back(t_stack **a, t_stack **b, int size, int **comm);
int				share_stack(t_stack **a, t_stack **b, int size, int **comm);

/*
**	usefull_functs.c
*/

int				find_mid(t_stack *stack, int size);
void			find_dir(t_stack *stack, int mid, int *next, int *prev);
int				find_dir2(t_stack *s, int place);
int				find_min(t_stack *s, int size);
int				find_max(t_stack *s, int size);

/*
**	sorting_500.c
*/

void			sort_500(t_stack **a, t_stack **b, int size, int **comm);

/*
**	----CHECKER_FUNCTS----
*/

/*
**	arr_functs_ch.c
*/

int				*get_arr_ch(int argc, char **argv, int *size);
int				*get_array_single_arg(char **arg, int *size);
void			sort_arr_ch(int *begin, int *end);

/*
**	stack_functs_ch.c
*/

t_stack			*fill_stack_ch(int *arr, int size);
void			mark_stack(t_stack *a, int *arr, int size);

/*
**	vizualization.c
*/

void			print_stacks(t_stack *a, t_stack *b, char *com, int flag);

#endif
