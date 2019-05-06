/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:04:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/03 16:22:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *str;
	int i;

	if (min >= max)
	{
		str = NULL;
		return (str);
	}
	else
		str = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min != max)
	{
		str[i++] = min;
		min += 1;
	}
	return (str);
}
