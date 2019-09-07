/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:09:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/07 15:24:24 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_command(int operation, int **comm)
{
	int check;

	check = operation + *(*comm - 1);
	if (check == PA + PB || check == SA + SA || check == SB + SB
		|| check == RA + RRA || check == RB + RRB)
		*(--*comm) = 0;
	else
		*((*comm)++) = operation;
}

void		rev_rotate(t_stack **stack, int **comm)
{
	if ((*stack) && (*stack)->prev != (*stack))
	{
		if (comm)
			write_command((*stack)->stack == 'a' ? RRA : RRB, comm);
		(*stack) = (*stack)->prev;
	}
}

void		rotate(t_stack **stack, int **comm)
{
	if ((*stack) && (*stack)->next != (*stack))
	{
		if (comm)
			write_command((*stack)->stack == 'a' ? RA : RB, comm);
		(*stack) = (*stack)->next;
	}
}

void		swap(t_stack **stack, int **comm)
{
	if ((*stack) && (*stack) != (*stack)->next)
	{
		if (comm)
			write_command((*stack)->stack == 'a' ? SA : SB, comm);
		if ((*stack)->next->next != (*stack))
		{
			(*stack)->next->next->prev = (*stack);
			(*stack)->prev->next = (*stack)->next;
			(*stack)->next->prev = (*stack)->prev;
			(*stack)->next = (*stack)->next->next;
			(*stack)->prev->next->next = (*stack);
			(*stack)->prev = (*stack)->prev->next;
		}
	}
	(*stack) = (*stack)->prev;
}

void		push(t_stack **take, t_stack **put, int **comm)
{
	t_stack *tmp;

	if ((*take))
	{
		if (comm)
			write_command((*take)->stack == 'a' ? PB : PA, comm);
		(*take)->stack = ((*take)->stack == 'a' ? 'b' : 'a');
		tmp = (*take) == (*take)->next ? NULL : (*take)->next;
		(*take)->next->prev = (*take)->prev;
		(*take)->prev->next = (*take)->next;
		if ((*put))
		{
			(*take)->prev = (*put)->prev;
			(*put)->prev->next = (*take);
			(*put)->prev = (*take);
			(*take)->next = (*put);
		}
		else
		{
			(*take)->prev = (*take);
			(*take)->next = (*take);
		}
		(*put) = (*take);
		(*take) = tmp;
	}
}
