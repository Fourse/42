/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:35:19 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/17 16:48:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(char *map, char **list)
{
	int y;
	int x;
	int num_fig;
	int x_fig;
	int hash;

	y = 0;
	x = 0;
	num_fig = 0;
	while (list[num_fig])
	{
		ft_putstr(list[num_fig]);
		x_fig = 0;
		hash = 0;
		while (hash < 4)
		{
			if (list[num_fig][x_fig] >= 'A' && list[num_fig][x_fig] <= 'Z')
			{
				map[x++] = list[num_fig][x_fig];
				hash++;
			}
			if (map[x] == '\n')
				x++;
			x_fig++;
		}
		num_fig++;
	}
	map[x] = '\0';
	ft_putstr(map);
}

char 	*empty_map(char *map, int count)
{
	int size;
	int y;
	int x;

	size = 0;
	y = 0;
	x = 0;
	while (size * size < count * 4)
		size++;
	map = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map[y * (size + 1) + x] = '.';
			x++;
		}
		map[y * (size + 1) + x] = '\n';
		y++;
	}
	map[y * (size + 1) + x] = '\0';
	return (map);
}
