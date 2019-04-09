/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:34:44 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/09 18:30:17 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	int i;
	int j;
	int n;
	int k;
	char **split;

	n = 0;
	j = 0;
	k = 0;
	split = NULL;
	while (s[n])
	{
		i = 0;
		while (s[n] != c)
			n++;
		if (s[n] == c)
		{
			*split[j] = *ft_strnew(n - k);
			while (s[n] != c)
			{
				split[j][i++] = s[n++];
				k++;
			}
			k++;
			split[j][i] = '\0';
		}
	}
	return (split);
}
