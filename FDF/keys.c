/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:57:15 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/11 17:00:46 by rloraine         ###   ########.fr       */
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
	if (key == 34 || key == 35)
	{
		iso_par(tmp, key);
		tmp = fdf;
	}
	if (key == 8)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		tmp = fdf;
	}
	return (0);
}
