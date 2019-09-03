/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/03 19:40:03 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, int size, int *comm)
{
	t_stack *b;
	int *p;

	p = comm;
	*p++ = 0;
	b = NULL;
	if (size == 2)
		swap(a, &p);
	else if (size == 3)
		sort_3(a, size, &p);
	else if (size <= 5)
		sort_5(a, &b, size, &p);
	else if (size <= 100)
		sort_100(a, &b, size, &p);
	else
		sort_500(a, &b, size, &p);
	*p = -1;
}

static void	print_comm(int *comm)
{
	while (*comm++ != -1)
	{
		if (*comm == SA)
			ft_printf("sa\n");
		else if (*comm == PA)
			ft_printf("pa\n");
		else if (*comm == RA)
			ft_printf("ra\n");
		else if (*comm == RRA)
			ft_printf("rra\n");
		else if (*comm == SB)
			ft_printf("sb\n");
		else if (*comm == PB)
			ft_printf("pb\n");
		else if (*comm == RB)
			ft_printf("rb\n");
		else if (*comm == RRB)
			ft_printf("rrb\n");
		else if (*comm == SS)
			ft_printf("ss\n");
		else if (*comm == RR)
			ft_printf("rr\n");
		else if (*comm == RRR)
			ft_printf("rrr\n");
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	int		*arr;
	int		size;
	int		*comm;

	fill_arr(&arr, argc, argv, &size);
	a = fill_stack(&a, &arr, size);
	sort_arr(arr, arr + size - 1);
	a = get_num_in_stack(&a, &arr, size);
	if (!stack_is_sorted(a, size))
	{
		if (!(comm = (int*)malloc(sizeof(int) * (size * size + 1))))
			error();
		sort(&a, size, comm);
		print_comm(comm);
	}
	return (0);
}
