/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:09:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/25 17:35:20 by rloraine         ###   ########.fr       */
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
		
	}
}

void	push(t_stack **take, t_stack **put)
{
	if ((*take))
	{
		(*take)
	}
}
