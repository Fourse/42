/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:35:19 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/17 18:10:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(char *map, char **list)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (list[n])
	{
		if ()
		j++;
	}
}

char	*empty_map(char *map, int count)
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
