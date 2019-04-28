/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:24:59 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/28 18:40:52 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUFF_SIZE 21

int ft_sqrt(int nb)
{
	int i;

	if (nb > 0)
	{
		i = 0;
		while (((i * i) <= nb) && (i < 46431))
		{
			i++;
			if ((i * i) == nb)
				return (i);
		}
	}
	return (0);
}

void printing(int n)
{

}

void print_map(int fd)
{
	int count;
	int i;
	int n;
	char buf[4097];

	i = 0;
	read(fd, buf, 4096);
	buf[4097] = '\0';
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	count /= 4 - 1;
	while (n = ft_sqrt(count) != 0 ? printing(n) : ft_sqrt(--count))
		;
}

int is_z(char **figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[y] && figure[y][x] && y <= 4)
	{
		if (((figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 1][x + 1] == '#' && figure[y + 2][x + 1] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 1][x - 1] == '#' && figure[y + 2][x - 1] == '#')\
			 || (figure[y][x] == '#' && figure[y][x + 1] == '#' && figure[y + 1][x] == '#' && figure[y + 1][x - 1] == '#')\
			 || (figure[y][x] == '#' && figure[y][x + 1] == '#' && figure[y + 1][x + 1] == '#' && figure[y + 1][x + 2] == '#')) && x <= 4)
			return (1);
		if (figure[y][x] == '\0')
        {
            x = 0;
            y++;
        }
        x++;
	}
	return (0);
}

int is_g(char **figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[y] && figure[y][x] && y <= 4)
	{
		if (((figure[y][x] == '#' && figure[y][x + 1] == '#' && figure[y][x + 2] == '#' && figure[y + 1][x + 2] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y][x + 1] == '#' && figure[y][x + 2] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 1][x + 1] == '#' && figure[y + 1][x + 2] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x - 2] == '#' && figure[y + 1][x - 1] == '#' && figure[y + 1][x] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#' && figure[y + 2][x - 1] == '#')\
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#' && figure[y + 2][x + 1] == '#')\
			 || (figure[y][x] == '#' && figure[y][x + 1] == '#' && figure[y + 1][x + 1] == '#' && figure[y + 2][x + 1] == '#')\
			 || (figure[y][x] == '#' figure[y][x + 1] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#')) && x <= 4)
			return (1);
		if (figure[y][x] == '\0')
        {
            x = 0;
            y++;
        }
        x++;
	}
	return (0);
}

int is_palka(char **figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[y] && figure[y][x] && y <= 4)
	{
		if (((figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#' && figure[y + 3][x] == '#')	\
			 || (figure[y][x] == '#' && figure[y][x + 1] == '#' figure[y][x + 2] == '#' && figure[y][x + 3] == '#')) && x <= 4)
			return (1);
		if (figure[y][x] == '\0')
        {
            x = 0;
            y++;
		}
        x++;
	}
	return (0);
}

int is_ti(char **figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[y] && figure[y][x] && y <= 4)
	{
		if (((figure[y][x] == '#' && figure[y][x + 1] == '#' && figure[y][x + 2] == '#' && figure[y + 1][x + 1] == '#') \
			|| (figure[y][x] == '#' && figure[y + 1][x - 1] == '#' && figure[y + 1][x] == '#' && figure[y + 1][x + 1] == '#') \
			|| (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#' && figure[y + 1][x + 1] == '#') \
			 || (figure[y][x] == '#' && figure[y + 1][x] == '#' && figure[y + 2][x] == '#' && figure[y + 1][x - 1] == '#')) && x <= 4)
			return (1);
		if (figure[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		x++;
	}
	return (0);
}

int is_square(char **figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[y] && figure[y][x] && y <= 4)
	{
		if ((figure[y][x] == '#' && figure[y][x + 1] == '#' &&		\
			 figure[y + 1][x] == '#' && figure[y + 1][x + 1] == '#') && x <= 4)
			return (1);
		if (figure[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		x++;
	}
	return (0);
}

int what_is(char **figure)
{
	int i;
	
	is_square(figure) == 1 || is_ti(figure) == 1 || is_palka(figure) == 1 ||
		is_g(figure) == 1 || is_z(figure) == 1 ? i = 1 : i = 0;
	return (i);
}

int get_figure(int fd)
{
	int ret;
	char buf[BUFF_SIZE + 1];
	char **figure;

	while ((ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		buf[ret] = '\0';
		figure = ft_strsplit(buf, '\n');
		what_is(figure) > 0 ? break : return (-1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}


int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (get_figure(fd) == 0)
		print_map(fd);
	else
		write(1, "error\n", 6);
	close(fd);
	return (0);
}
