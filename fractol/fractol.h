/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:55:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/18 18:01:45 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "mlx.h"
# include "math.h"

# define WEIGHT 1920
# define HEIGHT	1080

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*adr;
	int			bpp;
	int			wide;
	int			end;
}				t_fractol;

/*
**	main.c
*/

int				main(int argc, char **argv);
void			error(char *str);
int				hook_keydown(int key, t_fractol *frac);

/*
**	init.c
*/

void			init(t_fractol **frac);

/*
**	reader.c
*/

int				read_file(int fd);

#endif