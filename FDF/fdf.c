/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/03 17:31:16 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "nnnu davay");
//	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xfffafa);
//	mlx_new_image(mlx_ptr, 10, 10);
	return (0);
}
