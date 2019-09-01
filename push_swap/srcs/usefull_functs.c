/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:35:54 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:36:03 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_stack *s, int size)
{
	int high;

	high = 0;
	if (s)
	{
		high = s->num;
		while (--size)
		{
			s = s->next;
			if (s->num > high)
				high = s->num;
		}
	}
	return (high);
}

int		find_min(t_stack *s, int size)
{
	int low;

	low = 0;
	if (s)
	{
		low = s->num;
		while (--size)
		{
			s = s->next;
			if (s->num < low)
				low = s->num;
		}
	}
	return (low);
}

void	find_dir(t_stack *stack, int mid, int *next, int *prev)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->num > mid)
	{
		tmp = tmp->next;
		++next;
	}
	tmp = stack;
	while (tmp->num > mid)
	{
		tmp = tmp->prev;
		++prev;
	}
}

int		find_mid(t_stack *stack, int size)
{
	int sum;
	int i;
	int count;

	sum = 0;
	i = find_min(stack, size) - 1;
	count = 0;
	while (++i < find_max(stack, size))
	{
		sum += i;
		++count;
	}
	return ((sum / count));
}
