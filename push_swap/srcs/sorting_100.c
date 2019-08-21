/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:41:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/21 18:16:24 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *stack, int size)
{
	int min;

	min = stack->num;
	while (--size)
	{
		stack = stack->next;
		if (stack->num < min)
			min = stack->num;
	}
	return (min);
}

void	find_dir(t_stack *stack, int mid, int *next, int *prev)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->num > mid)
	{
		//printf("here");
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

// int		get_count(t_stack **a, t_stack **b, int size, long *comm)
// {
// 	int mid;
// 	int count;
// 	int next;
// 	int prev;

// 	mid = find_min(*a, size) + size / 2 + size % 2;
// 	count = 0;
// 	while (count * 2 < size + 4)
// 	{
// 		if ((*a)->num <= mid + 1)
// 		{
// 			push(a, b, comm, 2);
// 			++count;
// 		}
// 		else
// 		{
// 			next = 0;
// 			prev = 0;
// 			find_dir(*a, mid, &next, &prev);
// 			next > prev ? rev_rotate(a, comm, 1) : rotate(a, comm, 1);
// 		}
// 	}
// 	return (count);
// }

static int	get_count(t_stack **a, t_stack **b, int size, long *ops)
{
	int pivot;
	int count;

	pivot = find_min(*a, size) + size / 2 + size % 2;
	count = 0;
	while (count * 2 < size + 4)
		if ((*a)->num <= pivot + 1)
		{
			push(a, b, ops, 1);
			++count;
			if ((*b)->num >= pivot)
				rotate(b, ops, 2);
		}
		else
			rotate(a, ops, 1);
	return (count);
}

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

void	sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int count;
	int next;
	int prev;

	if (stack_is_sorted(*a, size))
		return ;
	if (size == 2 && (*a)->num > (*a)->next->num)
		swap(a, comm, 1);
	else if (size <= 3)
		sort_3(a, size, comm);
	else
	{
		count = get_count(a, b, size, comm);
		sort_100(a, b, size - count, comm);
		while (--count)
		{
			next = 0;
			prev = 0;
			detect_b(*a, *b, &next, &prev);
			while ((*b)->num != (*a)->num - 1)
				prev < next ? rev_rotate(b, comm, 2) : rotate(b, comm, 2);
			push(b, a, comm, 1);
		}
		push(b, a, comm, 1);
	}
}
