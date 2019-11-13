/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_glist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:57:03 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:57:03 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Меняем местами содержимое указанных элементов
*/

static void		swap(t_glist *a, t_glist *b)
{
	void	*content;
	size_t	content_size;

	content = a->gen.content;
	content_size = a->content_size;
	a->gen.content = b->gen.content;
	a->content_size = b->content_size;
	b->gen.content = content;
	b->content_size = content_size;
}

/*
**	Запускается один проход. Возвращает true, если все элементы упорядочены.
*/

static t_bool	pass(t_glist *list, int (*cmp)(void*, void*))
{
	t_bool	res;
	t_glist	*curr;

	res = true;
	curr = list;
	while (curr != NULL && curr->next != NULL)
	{
		if (cmp(curr->gen.content, curr->next->gen.content))
		{
			res = false;
			swap(curr, curr->next);
		}
		curr = curr->next;
	}
	return (res);
}

/*
**	Пузырьковая сортировка со связным списком.
**	Сортировка по содержанию. Не меняет указатели.
*/

void			ft_sort_glist(t_glist *list, int (*cmp)(void*, void*))
{
	t_glist	*curr;

	curr = list;
	while (curr != NULL)
	{
		if (pass(curr, cmp))
			return ;
		curr = curr->next;
	}
}
