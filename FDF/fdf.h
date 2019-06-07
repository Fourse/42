/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/07 15:15:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

# define WEIGHT 1920
# define HEIGHT 1080



typedef struct	s_map
{
	int			weigth;
	int			heigth;
	int			depthmin;
	int			depthmax;
	int			y;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*image;
	int			bpp;
	int			wide;
	int			endian;
	t_map		*map;
}				t_fdf;

int	error(char *str);
int read_file(int fd, t_map **map, t_list **list);
//t_map *map_init(size_t x, size_t y);
int fdf_init(t_fdf **fdf);

#endif
