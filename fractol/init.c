/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:40:14 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/18 17:48:13 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol **frac)
{
	(*frac) = (t_fractol*)malloc(sizeof(t_fractol));
	if (!((*frac)->mlx = mlx_init()))
		error("error");
	if (!((*frac)->win = mlx_new_window((*frac)->mlx, WEIGHT, HEIGHT, "hello")))
		error("error");
	if (!((*frac)->image = mlx_new_image((*frac)->mlx, WEIGHT, HEIGHT)))
		error("error");
	if (!((*frac)->adr = mlx_get_data_addr((*frac)->image, &(*frac)->bpp,\
												&(*frac)->wide, &(*frac)->end)))
		error("error");
	(*frac)->bpp /= 4;
}
