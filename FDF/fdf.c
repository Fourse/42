/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/04 20:43:13 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(char *str)
{
	ft_putendl(str);
	return (0);
}

int	main(int argc, char **argv)
{
	//int fd;
	t_fdf *fdf;

	//if (argc != 2)
	//	return (error("ebani ti uje kartu"));
	//fd = open(argv[1], O_RDONLY);
	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (error("error"));
	if (!(fdf->mlx = mlx_init()))
		return (error("error"));
	if (!(fdf->win = mlx_new_window(fdf->mlx, WEIGHT, HEIGHT, "hello")))
		return (error("error"));
	mlx_string_put(fdf->mlx, fdf->win, 820, 510, 0xda70d6, "EBALA TO KAKAYA, EBALAAAAAAAA");
	mlx_loop(fdf->mlx);
	return (0);
}
