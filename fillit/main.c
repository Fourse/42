/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/12 14:57:29 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *new_fig(char *buf, char cur, int y, int x)
{
	char **tmp;
	char *str;
	int i;

	i = 0;
	str = ft_strnew(21);
	tmp = (char**)malloc(sizeof(char*) * 5);
	while (tmp[y])
	{
		x = 0;
		while (buf[i])
		{
			if (buf[i] == '#')
			{

			}
		}
		str = ft_strcat(str, tmp[y]);
	}
	return (str);
}

int	ft_valid(char *buf)
{
	int i;
	int block;

	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i <= 20 && buf[i + 1] == '#')
				block++;
			if (i <= 20 && buf[i - 1] == '#')
				block++;
			if (i <= 20 && buf[i + 5] == '#')
				block++;
			if (i <= 20 && buf[i - 5] == '#')
				block++;
		}
		i++;
	}
	return ((block == 6 || block == 8) ? 1 : 0);
}

int	read_file(int fd, char *figure, char **list, int count)
{
	unsigned char	cur;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int y;
	int x;

	cur = 'A';
	y = 0;
	x = 0;
	while (ret = read(fd, buf, BUFF_SIZE) >= 20)
	{
		if (ft_valid(buf) != 0)
			return (0);
		figure = new_fig(buf, cur++, y, x);
		list[count] = ft_strdup(figure);
	}
	return (cur - 'A');
}

int	main(int argc, char **argv)
{
	char *figure;
	char *list[27];
	int count;

	count = 0;
	ft_bzero(figure, BUFF_SIZE + 1);
	if (read_file(open(argv[1], O_RDONLY), figure, list, count) == 0)
		ft_putendl("error");
	return (0);
}
