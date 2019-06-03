/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:34:44 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/21 15:38:58 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_deleverytning(char **split, int n)
{
	while (n >= 0)
	{
		free(split[n]);
		n--;
	}
	free(split);
	split = NULL;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
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
		if (!(split[n] = ft_strnew(ft_wsize(s, c, i))))
			split = ft_deleverytning(split, n);
		while (s[i] != c && s[i])
			split[n][k++] = s[i++];
		split[n++][k] = '\0';
	}
	split[n] = NULL;
	return (split);
}
