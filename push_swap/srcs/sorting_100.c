/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:27:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:21:40 by rloraine         ###   ########.fr       */
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
int		share_stack(t_stack **a, t_stack **b, int size, long *comm)
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
		if (size <= 3)
			break ;
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
	return (count);
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

	start = find_max(*b, size);
	end = find_min(*b, size);
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

void	bottom_up(t_stack **a, long *ops)
{
	while ((*a)->prev->num < (*a)->next->num)
	{
		rev_rotate(a, ops, 1);
		if ((*a)->num > (*a)->next->num)
			swap(a, ops, 1);
	}
}

void	sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int count;
	int next;
	int prev;

	if (size == 2 && (*a)->num > (*a)->next->num)
		swap(a, comm, 1);
	else if (size == 3 && !stack_is_sorted(*a, size))
		sort_3(a, size, comm);
	else
	{
		count = share_stack(a, b, size, comm);
		sort_100(a, b, size - count, comm);
		sort_back(a, b, count, comm);
		bottom_up(a, comm);
	}
}
