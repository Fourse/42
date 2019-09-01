/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:25:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:34:09 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
