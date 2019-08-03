/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:09:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/27 13:52:30 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	if ((*stack) && (*stack)->prev != (*stack))
	{
		(*stack) = (*stack)->prev;
	}
}

void	rotate(t_stack **stack)
{
	if ((*stack) && (*stack)->next != (*stack))
	{
		(*stack) = (*stack)->next;
	}
}

void	swap(t_stack **stack)
{
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

void	push(t_stack **take, t_stack **put)
{
	t_stack *tmp;

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
