/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:12:35 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/08 14:32:09 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *str;
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			i++;
			n++;
		}
	}
	str = ft_strnew(n);
	while (s[n] && (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t')))
	{
		str[n] = s[n];
		n--;
	}
	return (str);
}
