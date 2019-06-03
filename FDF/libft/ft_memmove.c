/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:20:42 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/29 16:08:23 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*s;
	const unsigned char	*d;

	s = (unsigned char*)dst;
	d = (unsigned char*)src;
	i = 0;
	if (s == d)
		return (dst);
	if (d < s)
		while (++i <= len)
			s[len - i] = d[len - i];
	else
		while (len-- > 0)
			*(s++) = *(d++);
	return (dst);
}
