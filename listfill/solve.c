/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:30:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/19 15:24:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_map(char **map, t_etris *list, int y, int x)
{
	
}

int		solve(char **map, int count, int size)
{
	int y;
	int x;

	while (size * size < count * 4)
		size++;
	map = (char**)malloc(sizeof(char*) * size + 1);
	y = 0;
	while (y < size)
	{
		x = 0;
		map[y] = (char*)malloc(sizeof(char) * size + 1);
		while (x < size)
			map[y][x++] = '.';
		map[y++][x] = '\0';
	}
	map[y] = NULL;
	return ((size == 17) ? 0 : size);
}
