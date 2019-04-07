/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:16:54 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/06 17:50:26 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int s;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		s = 0;
		while (haystack[i + s] == needle[s] && needle[s])
		{
			s++;
			if (!needle[s])
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
