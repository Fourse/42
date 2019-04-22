/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:51:03 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/21 17:04:01 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t s;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		s = 0;
		while (haystack[i + s] == needle[s] && needle[s] && (i + s < len))
		{
			s++;
			if (!needle[s])
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
