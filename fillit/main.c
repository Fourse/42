/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/14 18:27:29 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void solve(char **list, int count, int y, int x)
{
	char **map;
	int size;

	size = 0;
	while (size * size < count * 4)
		size++;
	
}

char *new_fig(char *figure, char *buf, char cur)
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
	return (figure);
}

int	connect(char *buf)
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

int valid(char *buf, int ret)
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

int	read_file(int fd, char *figure, char **list)
{
	unsigned char	cur;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int 			n;

	cur = 'A';
	n = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (valid(buf, ret) != 0)
			return (0);
		figure = new_fig(figure, buf, cur++);
		list[n++] = ft_strdup(figure);
	}
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int	main(int argc, char **argv)
{
	char	*figure;
	char	*list[27];
	int		count;

	figure = ft_strnew(BUFF_SIZE);
	ft_bzero(figure, BUFF_SIZE + 1);
	if ((count = read_file(open(argv[1], O_RDONLY), figure, list)) == 0)
		ft_putendl("error");
	solve(list, count, 0, 0);
	return (0);
}
