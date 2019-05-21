/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:30:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/21 17:35:12 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_map(char **map, t_etris *list, int y, int x)
{
	int size;

	size = ft_strlen(map[0]);
	if (list->next)
	{
		if (y  + list->heigth <= size)
		{
			
		}
		return (1);
	}
	return (0);
}

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

int	solve(char ***map, int count, t_etris *list)
{
	int n;
	int size;

	if (count > 26)
		return (0);
	size = 2;
	while (size * size < count * 4)
		size++;
	while ((empty_map(map, size)) && size < 17)
	{
		n = 0;
		if ((solve_map((*map), list, 0, 0)) == 0)
			break ;
		while ((*map[n]))
			free((*map)[n++]);
		free((*map));
		size++;
	}
	return ((size == 17) ? 0 : size);
}
