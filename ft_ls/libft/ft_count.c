/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:24:53 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/13 18:22:30 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int				i;
	unsigned int	k;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		i++;
		n = n * -1;
	}
	k = n;
	while (k > 0)
	{
		k /= 10;
		i++;
	}
	return (i);
}