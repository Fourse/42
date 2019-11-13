/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:44:45 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 18:44:48 by ptorchbu         ###   ########.fr       */
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
