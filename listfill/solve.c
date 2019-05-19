/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:30:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/19 18:08:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_map(char **map, t_etris *list, int y, int x)
{
	int y_fig;
	int x_fig;

	y_fig = 0;
	while (map[y])
	{
		while (y_fig < list->heigth)
		{
			x_fig = 0;
			while (list->value[y_fig][x_fig])
				map[y][x++] = list->value[y_fig][x_fig++];
			y_fig++;
		}
		ft_putendl(map[y]);
		y++;
	}
	//solve_map(map, list->next, y, x + x_fig);
}

int		solve(char ***map, int count, int size)
{
	int y;
	int x;

	while (size * size < count * 4)
		size++;
	if (!((*map) = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	y = 0;
	while (y < size)
	{
		x = 0;
		(*map)[y] = (char*)malloc(sizeof(char) * size + 1);
		while (x < size)
			(*map)[y][x++] = '.';
		(*map)[y++][x] = '\0';
	}
	map[y] = NULL;
	return ((size == 17) ? 0 : size);
}
