/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/13 16:50:42 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int high_sqrt(int count)
{
	int size;

	size = 0;
	while (size * size < count * 4)
		size++;
	return (size);
}

void solve(char **list, int count)
{
	char **map;
	int y;
	int x;
	int max;

	max = high_sqrt(count);
	y = 0;
	x = 0;
	while (y < max && x < max)
	{

	}
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

int	valid(char *buf)
{
	int i;
	int block;
	int hash;
	int dots;

	i = 0;
	block = 0;
	hash = 0;
	dots = 0;
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
		if (buf[i] == '.')
			dots++;
		i++;
	}
	return (((block == 6 || block == 8) && hash == 4 && dots == 12) ? 1 : 0);
}

int	read_file(int fd, char *figure, char **list)
{
	unsigned char	cur;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int n;

	cur = 'A';
	n = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) >= 20))
	{
		if (valid(buf) == 0)
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

	if (argc != 2)
		ft_putendl("ebani odin argument plz");
	figure = ft_strnew(BUFF_SIZE);
	ft_bzero(figure, BUFF_SIZE + 1);
	if ((count = read_file(open(argv[1], O_RDONLY), figure, list)) == 0)
		ft_putendl("error");
	solve(list, count);
	return (0);
}
