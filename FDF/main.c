/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/11 17:21:02 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define PIXEL fdf->map->pixel[y * fdf->map->weigth + x]

void		iso_x(t_fdf *fdf, int y, int x)
{
	int previous_x;
	int previous_y;

	previous_x = PIXEL->x;
	previous_y = PIXEL->y;
	PIXEL->x = (previous_x - previous_y) * cos(0.523599);
	PIXEL->y = PIXEL->z * -1 + (previous_x + previous_y) * sin(0.523599);
}

void		iso_par(t_fdf *fdf, int key)
{
	int		y;
	int		x;
	t_fdf	*tmp;

	y = 0;
	tmp = fdf;
	if (key == 34)
	{
		while (y < tmp->map->heigth)
		{
			x = 0;
			while (x < tmp->map->weigth)
			{
				iso_x(tmp, y, x);
				if (PIXEL->z > 0)
					mlx_pixel_put(tmp->mlx, tmp->win, PIXEL->x * 5, PIXEL->y * 5, 0xeee8aa);
				else
					mlx_pixel_put(tmp->mlx, tmp->win, PIXEL->x * 5, PIXEL->y * 5, 0x8b0000);
				x++;
			}
			y++;
		}
	}
	if (key == 35)
	{
		while (y < fdf->map->heigth)
		{
			x = 0;
			while (x < fdf->map->weigth)
			{
				if (PIXEL->z > 0)
					mlx_pixel_put(fdf->mlx, fdf->win, PIXEL->x * 5, PIXEL->y * 5, 0xeee8aa);
				else
					mlx_pixel_put(fdf->mlx, fdf->win, PIXEL->x * 5, PIXEL->y * 5, 0x8b0000);
				x++;
			}
			y++;
		}
	}
}

void		del_arr(char ***split)
{
	int n;

	n = 0;
	while ((*split)[n])
		free((*split)[n++]);
	free((*split));
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
//	solution(fdf, list);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
