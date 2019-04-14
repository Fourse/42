/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:52:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/06 15:25:03 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if ((const char)s[i] == c)
			break ;
		i--;
	}
	if (i == 0 && s[i] != c)
		return (NULL);
	return ((char*)(s + i));
}
