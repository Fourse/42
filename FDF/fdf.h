/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/04 20:15:53 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "./libft/libft.h"
# include <stdio.h>

# define WEIGHT 1920
# define HEIGHT 1080

typedef struct	s_image
{
	char		*addr;
	int			bpp;
	int			wide;
	int			bit_color;
	void *map;
}				t_image;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_image		*img;
}				t_fdf;

#endif
