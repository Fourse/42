/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:33:34 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:33:37 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!*s1 && !*s2)
		return (1);
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2 || i == n)
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (1);
}
