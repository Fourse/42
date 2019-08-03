/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:25:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 19:22:07 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, int size, long *comm)
{
	if ((*a)->num == 3 && (*a)->next->num == 2 && (*a)->prev->num == 1)
	{
		rotate(a, comm, 1);
		swap(a, comm, 1);
	}
	else if ((*a)->num == 2 && (*a)->next->num == 1 && (*a)->prev->num == 3)
		swap(a, comm, 1);
	else if ((*a)->num == 2 && (*a)->next->num == 3 && (*a)->prev->num == 1)
		rev_rotate(a, comm, 1);
	else if ((*a)->num == 3 && (*a)->next->num == 1 && (*a)->prev->num == 2)
		rotate(a, comm, 1);
	else if ((*a)->num == 1 && (*a)->next->num == 3 && (*a)->prev->num == 2)
	{
		swap(a, comm, 1);
		rotate(a, comm, 1);
	}
}

void	sort(t_stack **a, int size, long *comm)
{
	if (size == 2)
		swap(a, comm, 1);
	if (size <= 3)
		sort_3(a, size, comm);
}
