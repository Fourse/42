/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:55:18 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:55:21 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*result;

	result = ft_memalloc(sizeof(t_dlist));
	if (result == NULL)
		return (NULL);
	result->content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
		result->content = NULL;
	}
	else
	{
		result->content_size = content_size;
	}
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
