/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_glist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:56:52 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 19:06:18 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delone_glist(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*next;

	if (del != NULL)
		del((*alst)->gen.content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	*alst = next;
}

void	ft_delete_glist(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*curr;
	t_glist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_delone_glist(&curr, del);
	}
	*alst = NULL;
}

/*
**	Возвращает копию всех элементов списка.
**	Копирует указатели контента.
**	Вывод в обратном порядке (как того требует route_creator).
*/

t_glist	*ft_copy_glist(t_glist *src)
{
	t_glist	*res;
	t_glist	*curr;
	t_glist	*new;

	res = NULL;
	curr = src;
	while (curr != NULL)
	{
		new = ft_new_glist(curr->gen.content, curr->content_size);
		ft_add_glist(&res, new);
		curr = curr->next;
	}
	return (res);
}

/*
**	Возвращает true, если указанный указатель
**	присутствует в одном из содержимого узла.
*/

t_bool	ft_content_glist(t_glist *lst, void *content)
{
	t_glist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->gen.content == content)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void	ft_add_glist(t_glist **alst, t_glist *new)
{
	new->next = *alst;
	*alst = new;
}
