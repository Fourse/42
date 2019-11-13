/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:55:33 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:55:36 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Runs throught the double linked list and returns the first element.
*/

t_dlist			*ft_dlstfirst(t_dlist *lst)
{
	t_dlist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
