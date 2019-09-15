/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functs_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:55:03 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/15 11:48:02 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_stack(t_stack *s, int size)
{
	while (--size)
	{
		s = s->next;
		free(s->prev);
	}
	free(s);
}

void			mark_stack(t_stack *a, int *arr, int size)
{
	int i;

	i = 1;
	while (size--)
	{
		while (a->ret != *arr)
			a = a->next;
		a->num = i++;
		++arr;
	}
}

static t_stack	*new_stack(int n)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->ret = n;
	s->num = 0;
	s->next = NULL;
	s->prev = NULL;
	return (s);
}

t_stack			*fill_stack_ch(int *arr, int size)
{
	t_stack *s;
	t_stack *head;

	s = new_stack(*arr++);
	s->stack = 'a';
	head = s;
	while (--size)
	{
		s->next = new_stack(*arr++);
		s->next->prev = s;
		s->next->stack = 'a';
		s = s->next;
	}
	s->next = head;
	head->prev = s;
	return (head);
}
