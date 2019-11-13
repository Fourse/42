/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:04:46 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:04:49 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (strh[i] != '\0')
	{
		l = 0;
		while (strn[l] == strh[i + l])
		{
			if (strn[l + 1] == '\0')
				return ((char *)strh + i);
			l++;
		}
		i++;
	}
	return (NULL);
}
