/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:25:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/07 14:52:37 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_v0(t_stack **s, int **ops, int var)
{
	if ((var == 1 && (*s)->stack == 'a') || (var == 2 && (*s)->stack == 'b'))
		rotate(s, ops);
	else if ((var == 2 && (*s)->stack == 'a') || (var == 1 && (*s)->stack == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
	}
	else if ((var == 3 && (*s)->stack == 'a') || (var == 4 && (*s)->stack == 'b'))
		swap(s, ops);
	else if ((var == 4 && (*s)->stack == 'a') || (var == 3 && (*s)->stack == 'b'))
		rev_rotate(s, ops);
	if ((var == 6 && (*s)->stack == 'a') || (var == 5 && (*s)->stack == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
	}
}

static void	sort_3_v1(t_stack **s, int **ops, int var)
{
	if ((var == 1 && (*s)->stack == 'a') || (var == 2 && (*s)->stack == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
		swap(s, ops);
		rev_rotate(s, ops);
	}
	else if ((var == 2 && (*s)->stack == 'a') || (var == 1 && (*s)->stack == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
		rev_rotate(s, ops);
	}
}

static void	sort_3_v2(t_stack **s, int **ops, int var)
{
	if ((var == 6 && (*s)->stack == 'a') || (var == 5 && (*s)->stack == 'b'))
	{
		swap(s, ops);
		rotate(s, ops);
		swap(s, ops);
		rev_rotate(s, ops);
		swap(s, ops);
	}
	else if ((var == 4 && (*s)->stack == 'a') || (var == 3 && (*s)->stack == 'b'))
	{
		rotate(s, ops);
		swap(s, ops);
		rev_rotate(s, ops);
		swap(s, ops);
	}
	else if ((var == 3 && (*s)->stack == 'a') || (var == 4 && (*s)->stack == 'b'))
		swap(s, ops);
}

void		sort_3(t_stack **s, int size, int **ops)
{
	int var;
	int top;
	int middle;
	int bottom;

	size = 0;
	var = 0;
	top = (*s)->num;
	middle = (*s)->next->num;
	bottom = (*s)->next->next->num;
	if (top > bottom && bottom > middle)
		var = 1;
	else if (top < bottom && bottom < middle)
		var = 2;
	else if (top > middle && bottom > top)
		var = 3;
	else if (top > bottom && middle > top)
		var = 4;
	else if (top < middle && middle < bottom)
		var = 5;
	else if (top > middle && middle > bottom)
		var = 6;
	if (stack_size(*s) == 3)
		sort_3_v0(s, ops, var);
	else
		var <= 2 ? sort_3_v1(s, ops, var) : sort_3_v2(s, ops, var);
}

void		sort_5(t_stack **a, t_stack **b, int size, int **ops)
{
	while (stack_size(*a) > 3)
	{
		if (stack_is_sorted(*a, size))
			return ;
		else if ((*a)->num < size - 2)
			push(a, b, ops);
		else if ((*a)->prev->num < size - 2)
			rev_rotate(a, ops);
		else
			rotate(a, ops);
	}
	sort_3(a, size, ops);
	if (size == 5)
	{
		if ((*b)->num < (*b)->next->num)
			swap(b, ops);
		push(b, a, ops);
	}
	push(b, a, ops);
}

