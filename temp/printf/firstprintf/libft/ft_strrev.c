/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:38:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/09 15:21:42 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char *str;
	char c;

	str = s + ft_strlen(s) - 1;
	while (s < str)
	{
		c = *str;
		*str-- = *s;
		*s++ = c;
	}
}