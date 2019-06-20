/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:29:36 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/20 16:45:29 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int		clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void	find_color(t_map *map)
{
	t_pixel	v;
	t_pixel	*cur;

	v.y = 0;
	while (v.y < map->heigth)
	{
		v.x = 0;
		while (v.x < map->weigth)
		{
			cur = map->pixel[(int)v.y * map->weigth + (int)v.x];
			cur->color = clerp(0x8b0000, 0xee9a00, ft_ilerp(cur->z,
				map->depthmin, map->depthmax));
			v.x++;
		}
		v.y++;
	}
}
