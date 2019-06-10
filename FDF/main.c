/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:37:22 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/10 19:23:27 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void iso_x(t_fdf *fdf, int y, int x)
{
	int previous_x;
	int previous_y;

	previous_x = fdf->map->pixel[y * fdf->map->weigth + x]->x;
	previous_y = fdf->map->pixel[y * fdf->map->weigth + x]->y;
	fdf->map->pixel[y * fdf->map->weigth + x]->x = (previous_x - previous_y) * cos(0.523599);
	fdf->map->pixel[y * fdf->map->weigth + x]->y = fdf->map->pixel[y * fdf->map->weigth + x]->z * -1 + (previous_x + previous_y) * sin(0.523599);
}

void		del_arr(char ***split)
{
	int n;

	n = 0;
	while ((*split)[n])
		free((*split)[n++]);
	free((*split));
}

void iso_par(t_fdf *fdf, int key)
{
	int y = 0;
	int x;
	t_fdf *tmp;
	tmp = fdf;
	if (key == 34)
	{
		while (y < tmp->map->heigth)
		{
			x = 0;
			while (x < tmp->map->weigth)
			{
				iso_x(tmp, y, x);
				if (tmp->map->pixel[y * tmp->map->weigth + x]->z > 0)
					mlx_pixel_put(tmp->mlx, tmp->win, tmp->map->pixel[y * tmp->map->weigth + x]->x * 20, tmp->map->pixel[y * tmp->map->weigth + x]->y * 20, 0xeee8aa);
				else
					mlx_pixel_put(tmp->mlx, tmp->win, tmp->map->pixel[y * tmp->map->weigth + x]->x * 20, tmp->map->pixel[y * tmp->map->weigth + x]->y * 20, 0x8b0000);
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
				if (fdf->map->pixel[y * fdf->map->weigth + x]->z > 0)
					mlx_pixel_put(fdf->mlx, fdf->win, fdf->map->pixel[y * fdf->map->weigth + x]->x * 20, fdf->map->pixel[y * fdf->map->weigth + x]->y * 20, 0xeee8aa);
				else
					mlx_pixel_put(fdf->mlx, fdf->win, fdf->map->pixel[y * fdf->map->weigth + x]->x * 20, fdf->map->pixel[y * fdf->map->weigth + x]->y * 20, 0x8b0000);
				x++;
			}
			y++;
		}
	}
}

static int	hook_keydown(int key, t_fdf *fdf)
{
	(void)fdf;
	t_fdf *tmp;
	tmp = fdf;
	if (key == 53)
		exit(0);
	if (key == 34 || key == 35)
	{
		iso_par(tmp, key);
		tmp = fdf;
	}
	if (key == 8)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		tmp = fdf;
	}
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
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
