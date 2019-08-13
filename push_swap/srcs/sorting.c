/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:25:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/13 19:45:56 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	direction(t_stack *stack, int *count_next, int *count_prev, int max)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->num > max - 3)
	{
		tmp = tmp->next;
		++(*count_next);
	}
	tmp = stack;
	while (tmp->num > max - 3)
	{
		tmp = tmp->prev;
		++(*count_prev);
	}
}

void	find_rot_or_revrot(t_stack **a, t_stack **b, long *comm, int max)
{
	t_stack	*tmp;
	int		count_next;
	int		count_prev;

	count_next = 0;
	count_prev = 0;
	if (stack_size(*a) == 3)
		return ;
	if ((*a)->num < max - 2)
	{
		push(a, b, comm, 2);
		return ;
	}
	direction(*a, &count_next, &count_prev, max);
	while ((*a)->num > max - 3)
	{
		count_prev > count_next ? rev_rotate(a, comm, 1) : rotate(a, comm, 1);
		if ((*a)->num < max - 2)
		{
			push(a, b, comm, 2);
			return ;
		}
	}
}

void	find_min_max(t_stack **a, int size, int *min, int *max)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (*max < (*a)->num)
			*max = (*a)->num;
		if (*min > (*a)->num)
			*min = (*a)->num;
		(*a) = (*a)->next;
	}
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
	int min;
	int max;
	int count_next = 0;
	int count_prev = 0;

	min = INT_MAX;
	max = INT_MIN;
	// if (size == 2 && (*a)->num > (*a)->next->num)
	// 	swap(a, comm, 1);
	if (size == 3)
		sort_3(a, size, comm);
	else
	{
		find_min_max(a, size, &min, &max);
		find_rot_or_revrot(a, b, comm, max);
		sort_100(a, b, size - 1, comm);
		detect_b(*a, *b, &count_next, &count_prev);
		while ((*b)->num != (*a)->num - 1)
			count_prev < count_next ? rev_rotate(b, comm, 2) : rotate(b, comm, 2);
		// while ((*b)->num != (*a)->num - 1)
		// 	rotate(b, comm, 2);
		push(b, a, comm, 1);
	}
}

void	sort_5(t_stack **a, t_stack **b, int size, long *comm)
{
	while (stack_size(*a) > 3)
	{
		if (stack_is_sorted(*a, size))
			return ;
		else if ((*a)->num < size - 2)
			push(a, b, comm, 2);
		else if ((*a)->prev->num < size - 2)
			rev_rotate(a, comm, 1);
		else
			rotate(a, comm, 1);
	}
	sort_3(a, size, comm);
	if (size == 5)
	{
		if ((*b)->num < (*b)->next->num)
			swap(b, comm, 2);
		push(b, a, comm, 1);
	}
	push(b, a, comm, 1);
}

void	sort_3(t_stack **a, int size, long *comm)
{
	if ((*a)->num > (*a)->next->num && (*a)->prev->num &&\
	(*a)->next->num > (*a)->prev->num)
	{
		rotate(a, comm, 1);
		swap(a, comm, 1);
	}
	else if ((*a)->num > (*a)->next->num && (*a)->num < (*a)->prev->num &&\
	(*a)->prev->num > (*a)->next->num)
		swap(a, comm, 1);
	else if ((*a)->num < (*a)->next->num && (*a)->num > (*a)->prev->num &&\
	(*a)->next->num > (*a)->prev->num)
		rev_rotate(a, comm, 1);
	else if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->prev->num &&\
	(*a)->prev->num > (*a)->next->num)
		rotate(a, comm, 1);
	else if ((*a)->num < (*a)->next->num && (*a)->num < (*a)->prev->num &&\
	(*a)->next->num > (*a)->prev->num)
	{
		swap(a, comm, 1);
		rotate(a, comm, 1);
	}
}

void	sort(t_stack **a, int size, long *comm)
{
	t_stack *b;

	b = NULL;
	if (size == 2)
		swap(a, comm, 1);
	else if (size == 3)
		sort_3(a, size, comm);
	else if (size <= 5)
		sort_5(a, &b, size, comm);
	else if (size <= 100)
		sort_100(a, &b, size, comm);
}
