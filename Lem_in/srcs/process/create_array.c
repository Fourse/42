/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:55:18 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:55:22 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Преобразует указанный список в массив указателей
*/

void			*glist_inarray(t_glist *list)
{
	void	**res;
	size_t	pos;
	size_t	size;
	t_glist	*curr;

	size = ft_length_glist(list);
	res = ft_memalloc(((size) * sizeof(void*)));
	pos = 0;
	curr = list;
	while (curr != NULL)
	{
		res[pos] = curr->gen.content;
		pos++;
		curr = curr->next;
	}
	return (res);
}

static void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool	sort_pass(void **array, size_t size, int (cmp)(void*, void*))
{
	t_bool	res;
	size_t	pos;

	res = true;
	pos = 0;
	while (pos < size - 1)
	{
		if (cmp(array[pos], array[pos + 1]) > 0)
		{
			res = false;
			swap(&array[pos], &array[pos + 1]);
		}
		pos++;
	}
	return (res);
}

/*
**	Запускает пузырьковую сортировку по указанному массиву
*/

void			array_sort(void **array, size_t size, int (cmp)(void*, void*))
{
	size_t	pos;

	pos = 0;
	while (pos < size)
	{
		if (sort_pass(array, size - pos, cmp))
			return ;
		pos++;
	}
}
