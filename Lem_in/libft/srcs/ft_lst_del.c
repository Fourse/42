/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:49:39 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:49:43 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_list **lst)
{
	if (*lst != NULL && (*lst)->content != NULL)
	{
		if ((*lst)->next != NULL && (*lst)->next->content != NULL)
			ft_lst_del(&((*lst)->next));
		ft_lst_del_one((*lst), (*lst)->content, (*lst)->content_size);
	}
}
