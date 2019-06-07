/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:37:11 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/07 15:18:22 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_init(t_fdf **fdf)
{
	if (!((*fdf) = (t_fdf*)malloc(sizeof(t_fdf))))
		return (error("error"));
	if (!((*fdf)->mlx = mlx_init()))
		return (error("error"));
	if (!((*fdf)->win = mlx_new_window((*fdf)->mlx, WEIGHT, HEIGHT, "hello")))
		return (error("error"));
	return (1);
}

static t_map	*map_init(size_t x, size_t y)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->weigth = (int)x;
	map->heigth = (int)y;
	map->depthmax = INT_MAX;
	map->depthmin = INT_MIN;
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
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(list, tmp);
		if (count != ft_isword(line, ' '))
			return (0);
		free(line);
	}
	if (count == 0 || ret == -1)
		return (0);
	(*map) = map_init(count, ft_lstcount((*list)));
	return (1);
}
