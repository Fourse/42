/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:09:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/05 13:44:28 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack, long *comm, int number)
{
	number == 1 ? ft_printf("rra\n") : ft_printf("rrb\n");
	if ((*stack) && (*stack)->prev != (*stack))
	{
		(*stack) = (*stack)->prev;
	}
}

void	rotate(t_stack **stack, long *comm, int number)
{
	number == 1 ? ft_printf("ra\n") : ft_printf("rb\n");
	if ((*stack) && (*stack)->next != (*stack))
	{
		(*stack) = (*stack)->next;
	}
}

void	swap(t_stack **stack, long *comm, int number)
{
	number == 1 ? ft_printf("sa\n") : ft_printf("sb\n");
	if ((*stack) && (*stack) != (*stack)->next)
	{
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

void	push(t_stack **take, t_stack **put, long *comm, int number)
{
	t_stack *tmp;

	number == 1 ? ft_printf("pa\n") : ft_printf("pb\n");
	if ((*take))
	{
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
