/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:55:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:55:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next != NULL)
		(*alst)->next->prev = NULL;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
