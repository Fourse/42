/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:11:43 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/06 21:19:08 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)d)[i] = ((unsigned char*)s)[i];
		if (((unsigned char*)d)[i] == (unsigned char)c)
			return ((void*)(d + i + 1));
		i++;
	}
	return (NULL);
}
