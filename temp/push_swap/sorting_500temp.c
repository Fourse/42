/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:35:35 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/03 19:35:02 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		share_stack_500(t_stack **a, t_stack **b, int size, int **comm)
{
	int mid;
	int count;
	int rotated;

	
}

void	sort_500(t_stack **a, t_stack **b, int size, int **comm)
{
	int count;
	
	if (size == 2 && (((*a)->stack == 'a' && (*a)->num > (*a)->next->num) ||\
		((*a)->stack == 'b' && (*a)->num < (*a)->next->num)))
		swap(a, comm);
	else if (size == 3)
		sort_3(a, size, comm);
	else if (size > 3)
	{
		count = share_stack_500(a, b, size, comm);
	}
}

