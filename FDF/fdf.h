/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/12 18:18:58 by rloraine         ###   ########.fr       */
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

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}				t_cam;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

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
	char		*adr;
	int			bpp;
	int			wide;
	int			end;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
}				t_fdf;

typedef struct	s_line
{
	t_pixel		start;
	t_pixel		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;


/*
**	main.c
*/

void			error(char *str);
void			del_arr(char ***split);
void			iso_par(t_fdf *fdf, int key);
void			iso_x(t_fdf *fdf, int y, int x);

/*
**	init.c
*/

int				fdf_init(t_fdf **fdf);
t_pixel			*pixel_init(int x, int y, char *split);
t_cam			*cam_init(t_fdf **fdf);
t_map			*map_init(size_t x, size_t y);

/*
**	reader.c
*/

int				read_file(int fd, t_map **map, t_list **list);
void			find_minmax(t_map *map);
void			get_pixel(t_list **list, t_map **map);
void			del_arr(char ***split);

/*
**	color.c
*/

void			find_colors(t_map *m);
int				clerp(int c1, int c2, double p);
int				ft_lerpi(int first, int second, double p);
double			ft_ilerp(double val, double first, double second);

/*
**	image.c
*/

/*
**	keys.c
*/

int				hook_keydown(int key, t_fdf *fdf);
int				hook_mousemove(int x, int y, t_fdf *mlx);
int				hook_mouseup(int button, int x, int y, t_fdf *mlx);
int				hook_mousedown(int button, int x, int y, t_fdf *mlx);

void		render(t_fdf *fdf, t_map *map);
#endif
