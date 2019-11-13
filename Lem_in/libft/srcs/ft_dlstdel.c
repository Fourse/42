/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:55:59 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:56:02 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_dlstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
