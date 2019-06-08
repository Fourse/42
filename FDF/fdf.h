/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:20 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/08 15:40:36 by rloraine         ###   ########.fr       */
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
	int			endian;
	t_map		*map;
}				t_fdf;

/*
**	main.c
*/
void			error(char *str);
void			del_arr(char ***split);

/*
**	reader.c
*/

int				read_file(int fd, t_map **map, t_list **list);
int				fdf_init(t_fdf **fdf);

/*
**	solution.c
*/

void			solution(t_fdf *fdf, t_list *list);

#endif
