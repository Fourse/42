/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/24 18:54:09 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(t_stack **stack, int **arr, int argc)
{
	t_stack	*tmp;
	t_stack	*a;
	int		i;

	i = -1;
	a = *stack;
	tmp = NULL;
	while(++i < argc)
	{
		if (!((*stack) = (t_stack*)malloc(sizeof(t_stack))))
			exit(0);
		(*stack)->prev = tmp;
		(*stack)->ret = (*arr)[i];
		tmp = (*stack);
		(*stack)->next = (*stack)->next;
		(*stack) = (*stack)->next;
	}
	(*stack) = NULL;
	return (a);
}

void	fill_arr(int **arr, int argc, char **argv)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (!((*arr) = (int*)malloc(sizeof(int) * --argc)))
		exit(0);
	ft_bzero((*arr), sizeof(int) * argc + 1);
	while (argv[++n])
		(*arr)[i++] = ft_atoi(argv[n]);
}

int		main(int argc, char **argv)
{
	t_stack *a;
	int		*arr;

	fill_arr(&arr, argc, argv);
	a = fill_stack(&a, &arr, argc);
	while (a)
	{
		ft_printf("%d\n", a->ret);
		a = a->next;
	}
	return (0);
}
