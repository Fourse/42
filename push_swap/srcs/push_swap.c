/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/05 14:23:36 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_size(t_stack *stack)
{
	t_stack	*head;
	int		size;

	size = 0;
	if (stack)
	{
		++size;
		head = stack;
		stack = stack->next;
		while (stack != head)
		{
			++size;
			stack = stack->next;
		}
	}
	return (size);
}

int		stack_is_sorted(t_stack *stack, int size)
{
	while (stack->num < stack->next->num)
	{
		stack = stack->next;
		--size;
	}
	if (size != 1)
		return (0);
	return (1);
}

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
		error();
	a = *stack;
	tmp = NULL;
	while (++i < size)
	{
		if (!((*stack)->next = (t_stack*)malloc(sizeof(t_stack))))
			error();
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
	return (0);
}
