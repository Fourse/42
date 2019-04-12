/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:34:44 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/12 15:16:45 by rloraine         ###   ########.fr       */
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
	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * ft_isword(s, c) + 1)))
		return (0);
	while (s[i] && n < ft_isword(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		split[n] = ft_strnew(ft_wsize(s, c, i));
		while (s[i] != c && s[i])
			split[n][k++] = s[i++];
		split[n++][k] = '\0';
	}
	split[n] = NULL;
	return (split);
}
