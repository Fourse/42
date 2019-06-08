/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/08 16:21:43 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			del_arr(char ***split)
{
	int n;

	n = 0;
	while ((*split)[n])
		free((*split)[n++]);
	free((*split));
}

static int		hook_keydown(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit(0);
	return (0);
}

void			error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				main(int argc, char **argv)
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
	solution(fdf, list);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
