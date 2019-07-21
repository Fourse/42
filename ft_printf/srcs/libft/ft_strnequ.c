/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:40:34 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/21 18:27:42 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != s2)
	{
		if (!s1 || !s2)
			return (0);
		while ((*s1 || *s2) && n)
		{
			if (*s1 != *s2)
				return (0);
			++s1;
			++s2;
			--n;
		}
	}
	return (1);
}
