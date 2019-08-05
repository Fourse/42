/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:25:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/05 17:55:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int min;
	int max;

	min = INT_MAX;
	max = INT_MIN;
	while (stack_size(*a) > 3)
	{
		find_min_max(a, size, &min, &max);
	}
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
	else if (size <= 100)
		sort_100(a, &b, size, comm);
}
