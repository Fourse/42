/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:30:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/22 13:03:37 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define MAP map[y + y_fig][x + x_fig]

static void	del_from_map(char **map, t_etris *list, int y, int x)
{
	int y_fig;
	int x_fig;

	y_fig = 0;
	while (y_fig < list->heigth)
	{
		x_fig = -1;
		while (++x_fig < list->weigth)
			if (list->value[y_fig][x_fig] != '.')
				map[y + y_fig][x + x_fig] = '.';
		y_fig++;
	}
}

static void	fig_into_map(char **map, t_etris *list, int y, int x)
{
	int y_fig;
	int x_fig;

	y_fig = 0;
	while (y_fig < list->heigth)
	{
		x_fig = -1;
		while (++x_fig < list->weigth)
			if (list->value[y_fig][x_fig] != '.')
				MAP = list->value[y_fig][x_fig];
		y_fig++;
	}
}

static int	is_empty(char **map, t_etris *list, int y, int x)
{
	int y_fig;
	int x_fig;
	int size;

	y_fig = 0;
	size = ft_strlen(map[0]);
	if (x + list->weigth <= size)
	{
		while (y_fig < list->heigth)
		{
			x_fig = -1;
			while (++x_fig < list->weigth)
				if ((MAP != '.') && (list->value[y_fig][x_fig] != '.'))
					return (0);
			y_fig++;
		}
		return (1);
	}
	return (0);
}

int			solve_map(char **map, t_etris *list, int y, int x)
{
	int size;

	size = ft_strlen(map[0]);
	if (list->next)
	{
		if (y + list->heigth <= size)
		{
			while ((map[y][x]) && !(is_empty(map, list, y, x)))
				x++;
			if (is_empty(map, list, y, x))
			{
				fig_into_map(map, list, y, x);
				if (!(solve_map(map, list->next, 0, 0)))
					return (0);
				else
					del_from_map(map, list, y, x);
			}
			if (x + 1 + list->weigth <= size)
				return (solve_map(map, list, y, x + 1));
		}
		if (y + 1 + list->heigth <= size)
			return (solve_map(map, list, y + 1, x));
		return (1);
	}
	return (0);
}

int			solve(char ***map, int count, t_etris *list)
{
	int n;
	int size;

	if (count > 26)
		return (0);
	size = 2;
	while (size * size < count * 4)
		size++;
	/*while ((empty_map(map, size)) && size < 17)
	{
		n = 0;
		if ((solve_map((*map), list, 0, 0)) == 0)
			break ;
		while ((*map)[n])
			free((*map)[n++]);
		free((*map));
		size++;
	}*/
	empty_map(map, size);
	while (solve_map((*map), list, 0, 0))
	{
		n = 0;
		while ((*map)[n])
			free((*map)[n++]);
		free((*map));
		size++;
		empty_map(map, size);
	}
	return ((size == 17) ? 0 : size);
}
