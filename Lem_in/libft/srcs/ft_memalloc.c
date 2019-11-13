/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:14:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:14:50 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	if ((ptr = (void*)malloc(size)) == NULL)
	{
		ft_printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = ft_safe_malloc(size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}
