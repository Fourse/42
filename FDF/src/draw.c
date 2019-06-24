/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:15:40 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/24 15:30:04 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || x >= WEIGHT || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(fdf->adr + ((x + y * WEIGHT) * fdf->bpp)) = color;
}

t_pixel	projection(t_fdf *fdf, t_pixel pixel1)
{
	t_pixel	pixel2;
	double	x;
	double	y;
	double	z;

	x = pixel1.x;
	z = pixel1.z;
	pixel2.x = cos(fdf->cam->y) * x + sin(fdf->cam->y) * z;
	pixel2.z = -sin(fdf->cam->y) * x + cos(fdf->cam->y) * z;
	y = pixel1.y;
	z = pixel2.z;
	pixel2.y = cos(fdf->cam->x) * y - sin(fdf->cam->x) * z;
	pixel2.z = sin(fdf->cam->x) * y + cos(fdf->cam->x) * z;
	pixel2.color = pixel1.color;
	return (pixel2);
}

t_pixel	project(t_pixel pixel, t_fdf *fdf)
{
	pixel.x -= (double)(fdf->map->weigth - 1) / 2.0f;
	pixel.y -= (double)(fdf->map->heigth - 1) / 2.0f;
	pixel.z -= (double)(fdf->map->depthmin + fdf->map->depthmax) / 2.0f;
	pixel = projection(fdf, pixel);
	pixel.x *= fdf->cam->factor;
	pixel.y *= fdf->cam->factor;
	pixel.x += fdf->cam->offsetx;
	pixel.y += fdf->cam->offsety;
	return (pixel);
}

void	draw(t_fdf *fdf, t_map *map)
{
	int		y;
	int		x;

	ft_bzero(fdf->adr, WEIGHT * HEIGHT * fdf->bpp);
	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->weigth)
		{
			if (x + 1 < map->weigth)
				draw_line(fdf, project(*map->pixel[y * map->weigth + x], fdf),\
				project(*map->pixel[y * map->weigth + x + 1], fdf));
			if (y + 1 < map->heigth)
				draw_line(fdf, project(*map->pixel[y * map->weigth + x], fdf),\
				project(*map->pixel[(y + 1) * map->weigth + x], fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}
