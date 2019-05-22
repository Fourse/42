/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:27:39 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/22 13:30:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	empty_map(char ***map, int size)
{
	int y;
	int x;

	if (!((*map) = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	y = 0;
	while (y < size)
	{
		x = 0;
		if (!((*map)[y] = (char*)malloc(sizeof(char) * size + 1)))
		{
			while (y >= 0)
				free((*map)[y--]);
			free((*map));
			return (0);
		}
		while (x < size)
			(*map)[y][x++] = '.';
		(*map)[y++][x] = '\0';
	}
	(*map)[y] = NULL;
	return (1);
}
