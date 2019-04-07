/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:08:44 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/07 15:09:47 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str;
	unsigned char *src;

	str = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (n > 0 && *str == *src)
	{
		str++;
		src++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*str - *src);
}
