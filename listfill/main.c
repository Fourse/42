/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:40:43 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/19 15:23:27 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*trim_fig(char *buf)
{
	char	*s;
	int		i;

	i = 0;
	if (buf[i + 1] == '#' && buf[i + 5] == '#' && buf[i + 6] == '#') //square
		s = ft_strdup("##\n##\n");
	if (buf[i + 5] == '#' && buf[i + 10] == '#' && buf[i + 15] == '#') //stick
		s = ft_strdup("#\n#\n#\n#\n");
	if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 3] == '#') //stick
		s = ft_strdup("####\n");
	if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 6] == '#') //T
		s = ft_strdup(".#.\n###\n");
	if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 6] == '#') //T
		s = ft_strdup("###\n.#.\n");
	if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 10] == '#') //T
		s = ft_strdup("#.\n##\n#.\n");
	if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 10] == '#') //T
		s = ft_strdup(".#\n##\n.#\n");
	if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 9] == '#') //Z
		s = ft_strdup(".#\n##\n#.\n");
	if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 11] == '#') //Z
		s = ft_strdup("#.\n##\n.#\n");
	if (buf[i + 1] == '#' && buf[i + 4] == '#' && buf[i + 5] == '#') //Z
		s = ft_strdup(".##\n##.\n");
	if (buf[i + 1] == '#' && buf[i + 6] == '#' && buf[i + 7] == '#') //Z
		s = ft_strdup("##.\n.##\n");
	if (buf[i + 1] == '#' && buf[i + 6] == '#' && buf[i + 11] == '#') //G
		s = ft_strdup("##\n.#\n.#\n");
	if (buf[i + 1] == '#' && buf[i + 5] == '#' && buf[i + 10] == '#') //G
		s = ft_strdup("##\n#.\n#.\n");
	if (buf[i + 3] == '#' && buf[i + 4] == '#' && buf[i + 5] == '#') //G
		s = ft_strdup("..#\n###\n");
	if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 7] == '#') //G
		s = ft_strdup("#..\n###\n");
	if (buf[i + 5] == '#' && buf[i + 9] == '#' && buf[i + 10] == '#') //G
		s = ft_strdup(".#\n.#\n##\n");
	if (buf[i + 5] == '#' && buf[i + 10] == '#' && buf[i + 11] == '#') //G
		s = ft_strdup("#.\n#.\n##\n");
	if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 5] == '#') //G
		s = ft_strdup("###\n#..\n");
	if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 7] == '#') //G
		s = ft_strdup("###\n..#\n");
	return (s);
}

char	**new_fig(char *buf, char cur, t_etris ***list)
{
	char	**tmp;
	char	*s;
	int		j;
	int		y;
	int		x;

	j = -1;
	y = 0;
	while (*buf != '#')
		buf++;
	s = trim_fig(buf);
	while (s[++j])
		if (s[j] == '#')
			s[j] = cur;
	tmp = ft_strsplit(s, '\n');
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x++])
			(**list)->weigth = x;
		y++;
	}
	(**list)->heigth = y;
	return (tmp);
}

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

	if (argc != 2)
		return (error("ebani ka argiment, drujishe"));
	if (!(list = (t_etris*)malloc(sizeof(t_etris))))
		return (0);
	if ((count = read_file(open(argv[1], O_RDONLY), &list)) == 0)
		return (error("error"));
	map = NULL;
	size = 0;
	if ((size = solve(map, count, size)) == 0)
		return (error("error"));
	solve_map(map, list, 0, 0);
	return (0);
}
