/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/20 16:14:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(int fd, char **list)
{
	unsigned char	cur;
	char			buf[BUFF_SIZE];
	int				ret;
	int				n;

	cur = 'A';
	n = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (valid(buf, ret) != 0)
			return (0);
		list[n++] = new_fig(buf, cur++);
	}
	list[n] = NULL;
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int		main(int argc, char **argv)
{
	char	*list[27];
	char	*map;
	int		count;

	map = NULL;
	if (argc != 2)
		return (error("ebani ka argument, drujishe"));
	if ((count = read_file(open(argv[1], O_RDONLY), list)) == 0)
		return (error("error"));
	map = empty_map(map, count);
	solve(map, list, 0, 0);
	return (0);
}
