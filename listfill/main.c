/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:40:43 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/21 16:26:15 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_listvalue(t_etris *list)
{
	int i;

	while (list->next)
	{
		i = 0;
		while (list->value[i])
			free(list->value[i++]);
		free(list->value);
		list = list->next;
	}
}

static void	list_del(t_etris *list)
{
	t_etris *elem;

	while (list)
	{
		elem = list;
		free(elem);
		list = list->next;
	}
}

static void	print_map(char **map)
{
	int n;

	n = 0;
	while (map[n])
	{
		ft_putendl(map[n]);
		free(map[n]);
		n++;
	}
	free(map);
}

int			read_file(int fd, t_etris *list)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		cur;

	cur = 'A';
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		list->next = (t_etris*)malloc(sizeof(t_etris));
		if (valid(buf, ret) != 0)
			return (0);
		buf[ret] = '\0';
		list->value = new_fig(buf, cur++, list);
		list = list->next;
		list->next = NULL;
	}
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int			main(int argc, char **argv)
{
	t_etris	*list;
	char	**map;
	int		count;
	int		size;
	int		i;

	if (argc != 2)
		return (error("ebani ka argiment, drujishe"));
	if (!(list = (t_etris*)malloc(sizeof(t_etris))))
		return (0);
	if ((count = read_file(open(argv[1], O_RDONLY), list)) == 0)
		return (error("error"));
	map = NULL;
	if ((size = solve(&map, count, list)) == 0)
		return (error("error"));
	print_map(map);
	del_listvalue(list);
	list_del(list);
	return (0);
}
