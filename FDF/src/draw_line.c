/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:44:00 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/16 10:18:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_cur(t_fdf *fdf, t_tmp *tmp, t_pixel *pix1, t_pixel *pix2)
{
	double percent;

	if (pix1->x < 0 || pix1->x >= WEIGHT || pix1->y < 0 || pix1->y >= HEIGHT
	|| pix2->x < 0 || pix2->x >= WEIGHT || pix2->y < 0 || pix2->y >= HEIGHT)
		return (1);
	percent = (tmp->dx > tmp->dy ?\
			ft_ilerp((int)pix1->x, (int)tmp->start.x, (int)tmp->stop.x)\
			: ft_ilerp((int)pix1->y, (int)tmp->start.y, (int)tmp->stop.y));
	put_pixel(fdf, (int)pix1->x, (int)pix1->y, clerp(pix1->color,
			pix2->color, percent));
	tmp->err2 = tmp->err;
	if (tmp->err2 > -tmp->dx)
	{
		tmp->err -= tmp->dy;
		pix1->x += tmp->sx;
	}
	if (tmp->err2 < tmp->dy)
	{
		tmp->err += tmp->dx;
		pix1->y += tmp->sy;
	}
	return (0);
}

void	change(t_pixel *tmp, t_pixel *pix1, t_pixel *pix2, int addiction)
{
	if (addiction & 1)
	{
		tmp->x = pix1->x + \
				(pix2->x - pix1->x) * (HEIGHT - pix1->y) / (pix2->y - pix1->y);
		tmp->y = HEIGHT - 1;
	}
	else if (addiction & 2)
	{
		tmp->x = pix1->x + (pix2->x - pix1->x) * -pix1->y / (pix2->y - pix1->y);
		tmp->y = 0;
	}
	else if (addiction & 4)
	{
		tmp->x = WEIGHT - 1;
		tmp->y = pix1->y + \
				(pix2->y - pix1->y) * (WEIGHT - pix1->x) / (pix2->x - pix1->x);
	}
	else
	{
		tmp->x = 0;
		tmp->y = pix1->y + (pix2->y - pix1->y) * -pix1->x / (pix2->x - pix1->x);
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

int		line_twist(t_pixel *pix1, t_pixel *pix2)
{
	t_pixel	tmp;
	int		spot1;
	int		spot2;
	int		addiction;

	spot1 = spot(pix1->x, pix1->y);
	spot2 = spot(pix2->x, pix2->y);
	while (!(!(spot1 | spot2) || (spot1 & spot2)))
	{
		addiction = spot1 ? spot1 : spot2;
		change(&tmp, pix1, pix2, addiction);
		if (addiction == spot1)
		{
			pix1->x = tmp.x;
			pix1->y = tmp.y;
			spot1 = spot(pix1->x, pix1->y);
		}
		else
		{
			pix2->x = tmp.x;
			pix2->y = tmp.y;
			spot2 = spot(pix2->x, pix2->y);
		}
	}
	return (!(spot1 | spot2));
}

void	draw_line(t_fdf *fdf, t_pixel pix1, t_pixel pix2)
{
	t_tmp	tmp;

	pix1.x = (int)pix1.x;
	pix2.x = (int)pix2.x;
	pix1.y = (int)pix1.y;
	pix2.y = (int)pix2.y;
	tmp.start = pix1;
	tmp.stop = pix2;
	if (!line_twist(&pix1, &pix2))
		return ;
	tmp.dx = (int)ft_abs((int)pix2.x - (int)pix1.x);
	tmp.sx = (int)pix1.x < (int)pix2.x ? 1 : -1;
	tmp.dy = (int)ft_abs((int)pix2.y - (int)pix1.y);
	tmp.sy = (int)pix1.y < (int)pix2.y ? 1 : -1;
	tmp.err = (tmp.dx > tmp.dy ? tmp.dx : -tmp.dy) / 2;
	while (((int)pix1.x != (int)pix2.x || (int)pix1.y != (int)pix2.y))
		if (line_cur(fdf, &tmp, &pix1, &pix2))
			break ;
}
