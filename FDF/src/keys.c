/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:57:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/04 19:20:09 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	t_fdf *tmp;

	(void)fdf;
	tmp = fdf;
	if (key == 53)
		exit(0);
	return (0);
}

int	hook_mousedown(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	if (y < 0)
		return (0);
	fdf->mouse->isdown |= 1 << button;
	return (0);
}

int	hook_mouseup(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	fdf->mouse->isdown &= ~(1 << button);
	return (0);
}

int	hook_mousemove(int x, int y, t_fdf *fdf)
{
	fdf->mouse->lastx = fdf->mouse->x;
	fdf->mouse->lasty = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->isdown & (1 << 1) && fdf->mouse->isdown & (1 << 2))
	{
		fdf->cam->offsetx += (x - fdf->mouse->lastx);
		fdf->cam->offsety += (y - fdf->mouse->lasty);
	}
	else if (fdf->mouse->isdown & (1 << 1))
	{
		fdf->cam->x += (fdf->mouse->lasty - y) / 200.0f;
		fdf->cam->y -= (fdf->mouse->lastx - x) / 200.0f;
	}
	else if (fdf->mouse->isdown & (1 << 2))
	{
		fdf->cam->factor += (fdf->mouse->lasty - y) / 10.0f + 0.5f;
		if (fdf->cam->factor < 1)
			fdf->cam->factor = 1;
	}
	if (fdf->mouse->isdown)
		draw(fdf, fdf->map);
	return (0);
}
