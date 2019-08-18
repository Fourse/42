/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:01:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/18 14:25:36 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	detect_b(t_stack *s, t_stack *stack, int *count_next, int *count_prev)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->num != s->num - 1)
	{
		tmp = tmp->next;
		++(*count_next);
	}
	tmp = stack;
	while (tmp->num != s->num - 1)
	{
		tmp = tmp->prev;
		++(*count_prev);
	}
}
int		find_dir(t_stack *stack, int mid)
{
	t_stack	*tmp;
	int		direction;

	tmp = stack;
	direction = 0;
	while (tmp->num > mid)
	{
		tmp = tmp->next;
		--direction;
	}
	tmp = stack;
	while (tmp->num > mid)
	{
		tmp = tmp->prev;
		++direction;
	}
	return (direction);
}

void	find_min_maxi(t_stack *stack, int size, int *min, int *max)
{
	while (--size)
	{
		if (*max < stack->num)
			*max = stack->num;
		if (*min > stack->num)
			*min = stack->num;
		stack = stack->next;
	}
}

int		get_median(t_stack **a, t_stack **b, int size, long *comm)
{
	int max;
	int min;
	int mid;
	int tmp;
	int count;

	max = INT_MIN;
	min = INT_MAX;
	find_min_maxi(*a, size, &min, &max);
	mid = min + size / 2 + size % 2;
	count = 0;
	while (count * 2 < size + 4)
	{
		if ((*a)->num <= mid)
		{
			push(a, b, comm, 2);
			--tmp;
		}
		else
			rotate(a, comm, 1);
	}
	return (count);
}

void	sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int mid;
	int next;
	int prev;

	next = 0;
	prev = 0;
	if (size == 2 && (*a)->num > (*a)->next->num)
		swap(a, comm, 1);
	else if (size == 3)
		sort_3(a, size, comm);
	else
	{
		mid = get_median(a, b, size, comm);
		sort_100(a, b, size - mid, comm);
		detect_b(*a, *b, &next, &prev);
		while ((*b)->num != (*a)->num - 1)
		{
			prev > next ? rev_rotate(b, comm, 2) : rotate(b, comm, 2);
		}
		push(b, a, comm, 1);
	}
}
