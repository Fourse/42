/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:39:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/12 15:23:47 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t j;

	if (s1 || s2)
	{
		i = ft_strlen(s1);
		j = 0;
		while (s2[j] && j < n)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (NULL);
}
