/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:27:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:03:37 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_stack *stack, int size)
{
	int max;

	max = 0;
	if (stack)
	{
		max = stack->num;
		while (--size)
		{
			stack = stack->next;
			if (stack->num > max)
				max = stack->num;
		}
	}
	return (max);
}

int		find_min(t_stack *stack, int size)
{
	int min;

	min = 0;
	if (stack)
	{
		min = stack->num;
		while (--size)
		{
			stack = stack->next;
			if (stack->num < min)
				min = stack->num;
		}
	}
	return (min);
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

void	share_stack(t_stack **a, t_stack **b, int size, long *comm)
{
	int next;
	int prev;
	int mid;
	int prev_mid;
	int check_mid;
	int count;

	mid = find_mid(*a, size);
	prev_mid = 0;
	check_mid = mid;
	count = 0;
	while (1)
	{
		if (stack_is_sorted((*a), size))
			return ;
		if (prev_mid == check_mid)
		{
			mid = find_mid(*a, size);
			prev_mid = check_mid;
			check_mid = mid;
		}
		if ((*a)->num <= mid)
		{
			push(a, b, comm, 2);
			++prev_mid;
			++count;
			--size;
		}
		else
		{
			next = 0;
			prev = 0;
			find_dir(*a, mid, &next, &prev);
			next >= prev ? rev_rotate(a, comm, 1) : rotate(a, comm, 1);
		}
	}
}
int		where_to(t_stack *s, int place)
{
	t_stack	*r;
	int		direction;

	direction = 0;
	r = s;
	while (r->num != place)
	{
		r = r->next;
		--direction;
	}
	r = s;
	while (r->num != place)
	{
		r = r->prev;
		++direction;
	}
	return (direction);
}

void	sort_back(t_stack **a, t_stack **b, int size, long *ops)
{
	int start;
	int end;

	start = find_min(*b, size);
	end = find_max(*b, size);
	while (end <= start)
	{
		while ((*b)->num != start && (*b)->num != start - 1)
			if ((*b)->num == end || (*b)->num == end + 1)
			{
				if ((*b)->num == end)
					end += 1 + ((*a)->prev->num == end + 1);
				push(b, a, ops, 1);
				rotate(a, ops, 1);
			}
			else
				where_to(*b, start) >= 0 ? rotate(b, ops, 2) : rev_rotate(b, ops, 2);
		push(b, a, ops, 1);
		while ((*a)->num == start || (*a)->prev->num == start
			|| (*a)->next->num == start)
			--start;
		if ((*a)->num > (*a)->next->num)
			swap(a, ops, 1);
	}
}

void	detect_b(t_stack *a, t_stack *b, int *next, int *prev)
{
	t_stack *tmp;
	
	tmp = b;
	while (tmp->num != a->num - 1)
	{
		tmp = tmp->next;
		++(*next);
	}
	while (tmp->num != a->num - 1)
	{
		tmp = tmp->prev;
		++(*prev);
	}
}

void	sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int i = 97;
	int next;
	int prev;
	share_stack(a, b, size, comm);
	sort(a, 3, comm);
	sort_back(a, b, size, comm);
	while (i > 1)
	{
		if ((*b)->num == (*a)->num - 1)
		{
			push(b, a, comm, 1);
			--i;
			printf("%d\n", i);
		}
		else
		{
			next = 0;
			prev = 0;
			detect_b(*a, *b, &next, &prev);
			prev >= next ? rev_rotate(b, comm, 2) : rotate(b, comm, 2);
		}
	}
}