/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:43:11 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:15 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		if (str == NULL)
			return (NULL);
		i = 0;
		s = s + start;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
