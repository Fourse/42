/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:30 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 18:50:05 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../srcs/libft/libft.h"

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
**	error.c
*/

void			error(void);

/*
**	push_swap.c
*/

t_stack			*fill_stack(t_stack **stack, int **arr, int argc);
t_stack			*get_num_in_stack(t_stack **stack, int **arr, int size);
int				stack_is_sorted(t_stack *stack, int size);

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
**	sorting.c
*/

void			sort(t_stack **a, int size, long *comm);
void			sort_3(t_stack **a, int size, long *comm);

#endif
