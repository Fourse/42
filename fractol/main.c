/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:31:46 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/18 18:31:26 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_keydown(int key, t_fractol *frac)
{
	(void)frac;
	if (key == 53)
		exit(0);
	return (0);
}

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_fractol *frac;

	read_file(open(argv[1], O_RDONLY));
	init(&frac);
	mlx_key_hook(frac->win, hook_keydown, frac);
	mlx_loop(frac->mlx);
	return (0);
}