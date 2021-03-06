/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:59:13 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/12 14:59:16 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wsize(const char *s, char c, int i)
{
	int j;

	while (s[i] == c && s[i])
		i++;
	j = i;
	while (s[j] != c && s[j])
		j++;
	return (j - i);
}
