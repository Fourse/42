/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/01 17:39:17 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_i = 0;

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

int		main(int argc, char **argv)
{
	t_stack	*a;
	int		*arr;
	int		size;
	long	comm;

	fill_arr(&arr, argc, argv, &size);
	a = fill_stack(&a, &arr, size);
	sort_arr(arr, arr + size - 1);
	a = get_num_in_stack(&a, &arr, size);
	if (!stack_is_sorted(a, size))
	{
		sort(&a, size, &comm);
	}
	//printf("%d\n", g_i);
	return (0);
}
