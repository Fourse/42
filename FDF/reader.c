/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:37:11 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/13 16:29:15 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_arr(char ***split)
{
	int n;

	n = 0;
	while ((*split)[n])
		free((*split)[n++]);
	free((*split));
}

void	get_pixel(t_list **list, t_map **map)
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

void	find_minmax(t_map *map)
{
	int min;
	int max;
	int y;
	int x;

	min = INT_MAX;
	max = INT_MIN;
	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->weigth)
		{
			if (map->pixel[y * map->weigth + x]->z < min)
				min = map->pixel[y * map->weigth + x]->z;
			if (map->pixel[y * map->weigth + x]->z > max)
				max = map->pixel[y * map->weigth + x]->z;
			x++;
		}
		y++;
	}
	map->depthmin = min;
	map->depthmax = max;
}

int		read_file(int fd, t_map **map, t_list **list)
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
	find_minmax(*map);
	find_color((*map));
	return (1);
}
