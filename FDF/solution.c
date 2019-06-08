/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:30:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/08 17:29:36 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	solution(t_fdf *fdf, t_list *list)
{
	int i;

	i = 0;
	fdf->image = mlx_new_image(fdf->mlx, WEIGHT, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->image, \
	&fdf->bpp, &fdf->wide, &fdf->endian);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, WEIGHT, HEIGHT);
}
