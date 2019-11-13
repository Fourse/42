/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:08:11 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:08:13 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			l;
	unsigned char	*strh;
	unsigned char	*strn;

	strh = (unsigned char *)haystack;
	strn = (unsigned char *)needle;
	i = 0;
	if (*strn == '\0')
		return ((char *)haystack);
	while (strh[i] != '\0' && i < len)
	{
		l = 0;
		while (strn[l] == strh[i + l] && (i + l) < len)
		{
			if (strn[l + 1] == '\0')
				return ((char *)strh + i);
			l++;
		}
		i++;
	}
	return (NULL);
}
