/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/11 18:31:13 by rloraine         ###   ########.fr       */
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

typedef struct	s_pixel
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_pixel;

typedef struct	s_map
{
	int			weigth;
	int			heigth;
	int			depthmin;
	int			depthmax;
	t_pixel		**pixel;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*addr;
	int			bpp;
	int			wide;
	int			end;
	t_map		*map;
}				t_fdf;

/*
**	main.c
*/
void			error(char *str);
void			del_arr(char ***split);
void			iso_par(t_fdf *fdf, int key);
void			iso_x(t_fdf *fdf, int y, int x);

/*
**	reader.c
*/

int				read_file(int fd, t_map **map, t_list **list);
void			find_minmax(t_map *map);
void			get_pixel(t_list **list, t_map **map);

/*
**	init.c
*/

int				fdf_init(t_fdf **fdf);
t_pixel			*pixel_init(int x, int y, char *split);
t_map			*map_init(size_t x, size_t y);

/*
**	solution.c
*/

/*
**	keys.c
*/

int				hook_keydown(int key, t_fdf *fdf);

#endif
