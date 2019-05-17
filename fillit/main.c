/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/17 18:10:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_fig(char *figure, char *buf, char cur)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			figure[i] = cur;
		else
			figure[i] = buf[i];
		i++;
	}
	figure[i] = '\0';
	return (figure);
}

int		connect(char *buf)
{
	int i;
	int block;
	int hash;

	i = 0;
	block = 0;
	hash = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				block++;
			hash++;
		}
		i++;
	}
	return (((block == 6 || block == 8) && hash == 4) ? 1 : 0);
}

int		valid(char *buf, int ret)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				error++;
		}
		else if (buf[i] != '\n')
			error++;
		i++;
	}
	if (ret == 21 && buf[20] != '\n')
		error++;
	if (connect(buf) == 0)
		error++;
	return (error);
}

int		read_file(int fd, char *figure, char **list)
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
		figure = new_fig(figure, buf, cur++);
		list[n++] = ft_strdup(figure);
	}
	list[n] = NULL;
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int		main(int argc, char **argv)
{
	char	figure[BUFF_SIZE + 1];
	char	*list[27];
	char	*map;
	int		count;

	map = NULL;
	if (argc != 2)
		return (error("ebani ka argument, drujishe"));
	ft_bzero(figure, BUFF_SIZE + 1);
	if ((count = read_file(open(argv[1], O_RDONLY), figure, list)) == 0)
		return (error("error"));
	map = empty_map(map, count);
	solve(map, list);
	return (0);
}
