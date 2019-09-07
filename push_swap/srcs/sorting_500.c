/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:35:35 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/07 15:24:38 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split(t_stack **a, t_stack **b, int size, int **ops)
{
	int pivot;
	int pushed;
	int rotated;

	pivot = (*a)->stack == 'a' ? find_min(*a, size) : find_max(*a, size);
	pivot += (*a)->stack == 'a' ? size / 2 : -(size / 2);
	pushed = 0;
	rotated = 0;
	while (size--)
		if (((*a)->stack == 'a' && (*a)->num <= pivot) ||
			((*a)->stack == 'b' && (*a)->num >= pivot))
		{
			push(a, b, ops);
			(*b)->num == pivot ? rotate(b, ops) : ++pushed;
		}
		else
		{
			rotate(a, ops);
			++rotated;
		}
	if (stack_size(*a) > rotated)
		while (rotated--)
			rev_rotate(a, ops);
	return (pushed);
}

void		sort_500(t_stack **a, t_stack **b, int size, int **ops)
{
	int pushed;

	if (size == 2 && (((*a)->stack == 'a' && (*a)->num > (*a)->next->num)
		|| ((*a)->stack == 'b' && (*a)->num < (*a)->next->num)))
		swap(a, ops);
	else if (size == 3)
		sort_3(a, size, ops);
	else if (size > 3)
	{
		pushed = split(a, b, size, ops);
		sort_500(a, b, size - pushed - 1, ops);
		rev_rotate(b, ops);
		push(b, a, ops);
		sort_500(b, a, pushed, ops);
		while (pushed--)
			push(b, a, ops);
	}
}
