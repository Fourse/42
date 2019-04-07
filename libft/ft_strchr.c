/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:15:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/06 13:47:45 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((const char)*s == c)
			break ;
		s++;
	}
	if (!*s && *s != c)
		return (NULL);
	return ((char*)s);
}
