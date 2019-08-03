/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 17:11:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(t_stack **stack, int **arr, int argc)
{
	t_stack	*tmp;
	t_stack	*a;
	int		i;

	i = -1;
	if (!((*stack) = (t_stack*)malloc(sizeof(t_stack))))
		exit(0);
	a = *stack;
	tmp = NULL;
	while (++i < argc - 1)
	{
		if (!((*stack)->next = (t_stack*)malloc(sizeof(t_stack))))
			exit(0);
		(*stack)->prev = tmp;
		(*stack)->ret = (*arr)[i];
		tmp = (*stack);
		(*stack) = (*stack)->next;
	}
	(*stack) = a;
	(*stack)->prev = tmp;
	(*stack)->prev->next = a;
	return (a);
}

// void	get_size(int **arr, char **argv, int *size)
// {
// 	char	**tmp;
// 	int		n;
// 	int		i;

// 	tmp = ft_strsplit(argv[1], ' ');
// 	n = -1;
// 	i = 0;
// 	while (tmp[++n])
// 		(*arr)[i++] = ft_atoi(tmp[n]);
// 	*size = n - 1;
// }

int		fill_arr(int **arr, int argc, char **argv, int *size)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (!((*arr) = (int*)malloc(sizeof(int) * --argc)))
		exit(0);
	ft_bzero((*arr), sizeof(int) * argc);
	// if (argc == 2)
	// 	get_size(arr, argv, size);
	// else
	// {
		while (argv[++n])
		{
			(*arr)[i++] = ft_atoi(argv[n]);
		}
		*size = n - 1;
	// }
	return (*size);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	int		*arr;
	int		size;
	long	comm;

	fill_arr(&arr, argc, argv, &size);
	a = fill_stack(&a, &arr, argc);
	sort_arr(arr, arr + size - 1);
	int i = 0;
	while (i < size)
		ft_printf("%d\n", arr[i++]);
	return (0);
}
