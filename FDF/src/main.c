/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/16 10:13:10 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_map	*map;
	t_list	*list;

	if (argc != 2)
		error("ebani ti uje kartu");
	if (!(read_file(open(argv[1], O_RDONLY), &map, &list)))
		error("error");
	fdf_init(&fdf);
	fdf->map = map;
	draw(fdf, map);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_hook(fdf->win, 4, 0, hook_mousedown, fdf);
	mlx_hook(fdf->win, 5, 0, hook_mouseup, fdf);
	mlx_hook(fdf->win, 6, 0, hook_mousemove, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
