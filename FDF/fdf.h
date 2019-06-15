/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/15 20:57:33 by rloraine         ###   ########.fr       */
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
	int			factor;
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

typedef struct	s_tmp
{
	t_pixel		start;
	t_pixel		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_tmp;


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

void			find_color(t_map *m);
int				clerp(int c1, int c2, double p);
int				ft_lerpi(int first, int second, double p);
double			ft_ilerp(double val, double first, double second);

/*
**	draw.c
*/

void			draw(t_fdf *fdf, t_map *map);
t_pixel			project(t_pixel pixel, t_fdf *fdf);
t_pixel			projection(t_fdf *fdf, t_pixel pixel1);
void			put_pixel(t_fdf *fdf, int x, int y, int color);

/*
**	draw_line.c
*/

void			draw_line(t_fdf *fdf, t_pixel pixel1, t_pixel pixel2);
int				line_twist(t_pixel *pixel1, t_pixel *pixel2);
void			change(t_pixel *tmp, t_pixel *pixel1, t_pixel *pixel2, int addiction);
int				line_cur(t_fdf *fdf, t_tmp *tmp, t_pixel *pixel1, t_pixel *pixel2);

/*
**	keys.c
*/

int				hook_keydown(int key, t_fdf *fdf);
int				hook_mousemove(int x, int y, t_fdf *mlx);
int				hook_mouseup(int button, int x, int y, t_fdf *mlx);
int				hook_mousedown(int button, int x, int y, t_fdf *mlx);

#endif
