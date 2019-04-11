/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:34:44 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/11 20:58:39 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		k;
	char	**split;

	n = 0;
	i = 0;
	if (!(split = (char**)malloc(sizeof(char*) * ft_isword(s, c) + 1)))
		return (NULL);
	while (s[i] && n < ft_isword(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			split[n] = (char*)malloc(sizeof(char) * (ft_wordsize(s, c, i) + 1));
			while (s[i] != c && s[i])
				split[n][k++] = s[i++];
			split[n][k] = '\0';
			n++;
		}
	}
	split[n] = NULL;
	return (split);
}
