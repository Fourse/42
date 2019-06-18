/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:52:05 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/18 15:36:39 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define FDF (*fdf)

t_pixel	*pixel_init(int x, int y, char *split)
{
	t_pixel *pixel;

	if (!(pixel = (t_pixel*)malloc(sizeof(t_pixel))))
		error("error");
	pixel->x = (double)x;
	pixel->y = (double)y;
	pixel->z = (double)atoi(split);
	pixel->color = 0x8b0000;
	return (pixel);
}

t_cam	*cam_init(void)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		error("error");
	cam->x = 0;
	cam->y = 0;
	cam->factor = 30;
	cam->offsetx = WEIGHT / 2;
	cam->offsety = HEIGHT / 2;
	return (cam);
}

int		fdf_init(t_fdf **fdf)
{
	if (!(FDF = (t_fdf*)malloc(sizeof(t_fdf))))
		error("error");
	if (!(FDF->mlx = mlx_init()))
		error("error");
	if (!(FDF->win = mlx_new_window(FDF->mlx, WEIGHT, HEIGHT, "hello")))
		error("error");
	if (!(FDF->image = mlx_new_image(FDF->mlx, WEIGHT, HEIGHT)))
		error("error");
	FDF->adr = mlx_get_data_addr(FDF->image, &FDF->bpp, &FDF->wide, &FDF->end);
	FDF->bpp /= 8;
	if (!(FDF->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		error("error");
	FDF->cam = cam_init();
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
