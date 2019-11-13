/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:10:59 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:11:01 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*firptr;

	if (!lst)
		return (NULL);
	newlist = f(lst);
	firptr = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
			return (NULL);
		newlist = newlist->next;
	}
	return (firptr);
}
