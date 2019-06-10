/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:37:11 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/10 17:52:45 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_init(t_fdf **fdf)
{
	if (!((*fdf) = (t_fdf*)malloc(sizeof(t_fdf))))
		error("error");
	if (!((*fdf)->mlx = mlx_init()))
		error("error");
	if (!((*fdf)->win = mlx_new_window((*fdf)->mlx, WEIGHT, HEIGHT, "hello")))
		error("error");
	return (1);
}

static t_pixel	*pixel_init(int x, int y, char *split)
{
	t_pixel *pixel;

	if (!(pixel = (t_pixel*)malloc(sizeof(t_pixel))))
		error("error");
	pixel->x = (double)x + 40;
	pixel->y = (double)y + 10;
	pixel->z = (double)atoi(split);
	pixel->color = 0xee82ee;
	return (pixel);
}

void			get_pixel(t_list **list, t_map **map)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = (*list);
	y = 0;
	while (y < (*map)->heigth)
	{
		x = 0;
		if (!(split = ft_strsplit(lst->content, ' ')))
			error("error");
		while (x < (*map)->weigth)
		{
			(*map)->pixel[y * (*map)->weigth + x] = pixel_init(x, y, split[x]);
			x++;
		}
		del_arr(&split);
		lst = lst->next;
		y++;
	}
}

static t_map	*map_init(size_t x, size_t y)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		error("error");
	map->weigth = (int)x;
	map->heigth = (int)y;
	map->depthmax = INT_MAX;
	map->depthmin = INT_MIN;
	if (!(map->pixel = (t_pixel**)malloc(sizeof(t_pixel*) * (int)x * (int)y)))
		error("error");
	return (map);
}

int				read_file(int fd, t_map **map, t_list **list)
{
	t_list	*tmp;
	char	*line;
	int		count;
	int		ret;

	count = 0;
	while ((ret = (get_next_line(fd, &line))) == 1)
	{
		if (count == 0)
			count = ft_isword(line, ' ');
		if (!(tmp = ft_lstnew(line, ft_strlen(line) + 1)))
			error("error");
		ft_lstadd(list, tmp);
		if (count != ft_isword(line, ' '))
			return (0);
		free(line);
	}
	if (count == 0 || ret == -1)
		return (0);
	ft_lstrev(list);
	(*map) = map_init(count, ft_lstcount((*list)));
	get_pixel(list, map);
	return (1);
}
