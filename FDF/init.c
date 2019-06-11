/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:52:05 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/11 17:18:58 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_init(t_fdf *fdf)
{
	if (!(fdf->image = mlx_new_image(fdf->mlx, WEIGHT, HEIGHT)))
		error("error");
	fdf->addr = mlx_get_data_addr(fdf->image, &fdf->bpp, &fdf->wide, &fdf->end);
	fdf->bpp /= 8;
}

t_pixel	*pixel_init(int x, int y, char *split)
{
	t_pixel *pixel;

	if (!(pixel = (t_pixel*)malloc(sizeof(t_pixel))))
		error("error");
	pixel->x = (double)x + 40;
	pixel->y = (double)y + 10;
	pixel->z = (double)atoi(split);
	pixel->color = 0xee82ee;
	return (pixel);
}

int		fdf_init(t_fdf **fdf)
{
	if (!((*fdf) = (t_fdf*)malloc(sizeof(t_fdf))))
		error("error");
	if (!((*fdf)->mlx = mlx_init()))
		error("error");
	if (!((*fdf)->win = mlx_new_window((*fdf)->mlx, WEIGHT, HEIGHT, "hello")))
		error("error");
	return (1);
}

t_map	*map_init(size_t x, size_t y)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		error("error");
	map->weigth = (int)x;
	map->heigth = (int)y;
	map->depthmax = INT_MAX;
	map->depthmin = INT_MIN;
	if (!(map->pixel = (t_pixel**)malloc(sizeof(t_pixel*) * (int)x * (int)y)))
		error("error");
	return (map);
}
