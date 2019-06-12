/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:15:40 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/12 18:18:56 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	project(t_pixel pixel, t_fdf *fdf)
{
	pixel.x -= (double)(fdf->map->weigth - 1)
	return (pixel);
}

void	draw_line(t_fdf *fdf, t_pixel p1, t_pixel p2)
{

}

void	draw(t_fdf *fdf, t_map *map)
{
	int y;
	int x;
	t_pixel pixel;

	ft_bzero(fdf->adr, WEIGHT * HEIGHT * fdf->bpp);
	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->weigth)
		{
			if (x + 1 < map->weigth)
				draw_line(fdf, project(*map->pixel[y * map->weigth + x], fdf), project(*map->pixel[y * map->weigth + x + 1], fdf));
			if (y + 1 < map->heigth)
				draw_line(fdf, project(*map->pixel[y * map->weigth + x], fdf), project(*map->pixel[y * map->weigth + y + 1], fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}