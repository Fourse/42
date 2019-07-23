/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:55:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/23 19:47:41 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rev(t_stack **stack)
{
	t_stack *prev;
	t_stack *cur;
	t_stack *next;

	prev = NULL;
	cur = *stack;
	while (cur->next)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;		
	}
	*stack = prev;
}

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	int n;

	n = 0;
	while (argv[++n])
	{
		stack_a = (t_stack*)malloc(sizeof(t_stack));
		stack_a->ret = ft_atoi(argv[n]);
		stack_a = stack_a->next;
		stack_a->next = NULL;
	}
	stack_rev(&stack_a);
	return (0);
}