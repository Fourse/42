/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/08 19:02:13 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int iso_y(t_fdf *fdf, int y, int x)
{
	int previous_x;
	int previous_y;

	previous_x = fdf->map->pixel[y * fdf->map->weigth + x]->x;
	previous_y = fdf->map->pixel[y * fdf->map->weigth + x]->y;
	fdf->map->pixel[y * fdf->map->weigth + x]->x = (previous_x - previous_y) * cos(0.523599);
	fdf->map->pixel[y * fdf->map->weigth + x]->y = fdf->map->pixel[y * fdf->map->weigth + x]->z * -1 + (previous_x + previous_y) * sin(0.523599);
	return (fdf->map->pixel[y * fdf->map->weigth + x]->y);
}

int iso_x(t_fdf *fdf, int y, int x)
{
	int previous_x;
	int previous_y;

	previous_x = fdf->map->pixel[y * fdf->map->weigth + x]->x;
	previous_y = fdf->map->pixel[y * fdf->map->weigth + x]->y;
	fdf->map->pixel[y * fdf->map->weigth + x]->x = (previous_x - previous_y) * cos(0.523599);
	fdf->map->pixel[y * fdf->map->weigth + x]->y = fdf->map->pixel[y * fdf->map->weigth + x]->z * -1 + (previous_x + previous_y) * sin(0.523599);
	return (fdf->map->pixel[y * fdf->map->weigth + x]->x);
}

void		del_arr(char ***split)
{
	int n;

	n = 0;
	while ((*split)[n])
		free((*split)[n++]);
	free((*split));
}

static int	hook_keydown(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit(0);
	return (0);
}

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
	//solution(fdf, list);
	int y = 0;
	int x;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->weigth)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, iso_x(fdf, y, x) * 20, iso_y(fdf, y, x) * 20, 0xee82ee);
			//mlx_pixel_put(fdf->mlx, fdf->win, fdf->map->pixel[y * fdf->map->weigth + x]->x * 70, fdf->map->pixel[y * fdf->map->weigth + x]->y * 70, 0xee82ee);
			x++;
		}
		y++;
	}
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
