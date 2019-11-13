/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:15:02 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:15:06 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strd;
	unsigned char	*strs;

	i = 0;
	strd = (unsigned char *)dst;
	strs = (unsigned char *)src;
	while (i < n)
	{
		((unsigned char *)strd)[i] = ((unsigned char *)strs)[i];
		if (((unsigned char *)strs)[i] == (unsigned char)c)
		{
			dst = strd;
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
