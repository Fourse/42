/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:23:17 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/13 15:48:10 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;

	while (*alst)
	{
		elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = elem;
	}
}
