/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 17:42:09 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_num_in_stack(t_stack **stack, int **arr, int size)
{
	t_stack *a;
	int		i;
	int		count;

	a = *stack;
	count = 0;
	while (a)
	{
		i = 0;
		if (count == size)
			break ;
		while (i < size)
		{
			if ((*stack)->ret == (*arr)[i])
			{
				(*stack)->num = i + 1;
				(*stack) = (*stack)->next;
				++count;
				break ;
			}
			i++;
		}
	}
	return (a);
}

t_stack	*fill_stack(t_stack **stack, int **arr, int size)
{
	t_stack	*tmp;
	t_stack	*a;
	int		i;

	i = -1;
	if (!((*stack) = (t_stack*)malloc(sizeof(t_stack))))
		exit(0);
	a = *stack;
	tmp = NULL;
	while (++i < size)
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
	a = fill_stack(&a, &arr, size);
	sort_arr(arr, arr + size - 1);
	a = get_num_in_stack(&a, &arr, size);
	return (0);
}
