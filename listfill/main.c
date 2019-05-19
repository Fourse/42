/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:40:43 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/19 18:08:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(int fd, t_etris **list)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		cur;

	cur = 'A';
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (valid(buf, ret) != 0)
			return (0);
		(*list)->value = new_fig(buf, cur++, &list);
		(*list) = (*list)->next;
		(*list) = (t_etris*)malloc(sizeof(t_etris));
		(*list)->next = NULL;
	}
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int		error(char *str)
{
	ft_putendl(str);
	return (0);
}

int		main(int argc, char **argv)
{
	t_etris	*list;
	char	**map;
	int		count;
	int		size;

	int i;
	if (argc != 2)
		return (error("ebani ka argiment, drujishe"));
	if (!(list = (t_etris*)malloc(sizeof(t_etris))))
		return (0);
	if ((count = read_file(open(argv[1], O_RDONLY), &list)) == 0)
		return (error("error"));
	map = NULL;
	size = 0;
	if ((size = solve(&map, count, size)) == 0)
		return (error("error"));
	while (list)
	{
		i = 0;
		while (i < 4)
			ft_putendl(list->value[i]);
		list = list->next;
	}
	solve_map(map, list, 0, 0);
	return (0);
}
