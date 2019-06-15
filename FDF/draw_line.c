/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:44:00 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/15 20:22:59 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_cur(t_fdf *fdf, t_tmp *tmp, t_pixel *pixel1, t_pixel *pixel2)
{
	double percent;

	if (pixel1->x < 0 || pixel1->x >= WEIGHT || pixel1->y < 0 || pixel1->y >= HEIGHT
	|| pixel2->x < 0 || pixel2->x >= WEIGHT || pixel2->y < 0 || pixel2->y >= HEIGHT)
		return (1);
	percent = (tmp->dx > tmp->dy ? 
				ft_ilerp((int)pixel1->x, (int)tmp->start.x, (int)tmp->stop.x)
				: ft_ilerp((int)pixel1->y, (int)tmp->start.y, (int)tmp->stop.y));
	put_pixel(fdf, (int)pixel1->x, (int)pixel1->y, clerp(pixel1->color,
				 pixel2->color, percent));
	tmp->err2 = tmp->err;
	if (tmp->err2 > -tmp->dx)
	{
		tmp->err -= tmp->dy;
		pixel1->x += tmp->sx;
	}
	if (tmp->err2 < tmp->dy)
	{
		tmp->err += tmp->dx;
		pixel1->y += tmp->sy;
	}
	return (0);
}

void	change(t_pixel *tmp, t_pixel *pixel1, t_pixel *pixel2, int addiction)
{
	if (addiction & 1)
	{
		tmp->x = pixel1->x + (pixel2->x - pixel1->x) * (HEIGHT - pixel1->y) / (pixel2->y - pixel1->y);
		tmp->y = HEIGHT - 1;
	}
	else if (addiction & 2)
	{
		tmp->x = pixel1->x + (pixel2->x - pixel1->x) * -pixel1->y / (pixel2->y - pixel1->y);
		tmp->y = 0;
	}
	else if (addiction & 4)
	{
		tmp->x = WEIGHT - 1;
		tmp->y = pixel1->y + (pixel2->y - pixel1->y) * (WEIGHT - pixel1->x) / (pixel2->x - pixel1->x);
	}
	else
	{
		tmp->x = 0;
		tmp->y = pixel1->y + (pixel2->y - pixel1->y) * -pixel1->x / (pixel2->x - pixel1->x);
	}
	
}

int		spot(int x, int y)
{
	int tmp;

	tmp = 0;
	if (y >= HEIGHT)
		tmp |= 1;
	else if (y < 0)
		tmp |= 2;
	if (x >= WEIGHT)
		tmp |= 4;
	else if (x < 0)
		tmp |= 8;
	return (tmp);
}

int		line_twist(t_pixel *pixel1, t_pixel *pixel2)
{
	t_pixel	tmp;
	int		spot1;
	int		spot2;
	int		addiction;

	spot1 = spot(pixel1->x, pixel1->y);
	spot2 = spot(pixel2->x, pixel2->y);
	while (!(!(spot1 | spot2) || (spot1 & spot2)))
	{
		addiction = spot1 ? spot1 : spot2;
		change(&tmp, pixel1, pixel2, addiction);
		if (addiction == spot1)
		{
			pixel1->x = tmp.x;
			pixel1->y = tmp.y;
			spot1 = spot(pixel1->x, pixel1->y);
		}
		else
		{
			pixel2->x = tmp.x;
			pixel2->y = tmp.y;
			spot2 = spot(pixel2->x, pixel2->y);
		}
	}
	return (!(spot1 | spot2));
}

void	draw_line(t_fdf *fdf, t_pixel pixel1, t_pixel pixel2)
{
	t_tmp	tmp;

	pixel1.x = (int)pixel1.x;
	pixel2.x = (int)pixel2.x;
	pixel1.y = (int)pixel1.y;
	pixel2.y = (int)pixel2.y;
	tmp.start = pixel1;
	tmp.stop = pixel2;
	if (!line_twist(&pixel1, &pixel2))
		return ;
	tmp.dx = (int)ft_abs((int)pixel2.x - (int)pixel1.x);
	tmp.sx = (int)pixel1.x < (int)pixel2.x ? 1 : -1;
	tmp.dy = (int)ft_abs((int)pixel2.y - (int)pixel1.y);
	tmp.sy = (int)pixel1.y < (int)pixel2.y ? 1 : -1;
	tmp.err = (tmp.dx > tmp.dy ? tmp.dx : -tmp.dy) / 2;
	while (((int)pixel1.x != (int)pixel2.x || (int)pixel1.y != (int)pixel2.y))
		if (line_cur(fdf, &tmp, &pixel1, &pixel2))
			break ;
}
