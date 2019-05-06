/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:22:28 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/06 18:57:45 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_copyonly(char *s, char *d, char c)
{
	
}

void ft_printmap(char **s, int n)
{
    char **map;
	int i;

	i = 0;
	while (n <= 4)
	{
		ft_copyonly(map[n], s[n], '#');
		
}

int ft_valid(char **figure, int n, int i)
{
	if (figure[n][i] != '#' && (n >= 4 || n < 0) && (i >= 4 || i < 0))
		return (0);
	figure[n][i] = '*';
	return (ft_valid(figure, n + 1, i) + ft_valid(figure, n - 1, i) + ft_valid(figure, n, i - 1) + ft_valid(figure, n, i + 1) + 1);
}

void ft_massjoin(char **s, char **f)
{
	static int n;
	int i;

	while (f[n])
	{
		i = 0;
		while (f[n][i++])
			s[n][i] = f[n][i];
		n++;
	}
}

int main(int argc, char **argv)
{
	int fd;
	int n;
	char buf[BUFF_SIZE + 1];
	char **figure;
	static char **s;

	fd = open(argv[1], O_RDONLY);
	while ((n = read(fd, buf, BUFF_SIZE) > 20))
	{
		buf[n] = '\0';
		figure = ft_strsplit(buf, '\n');
		if (ft_valid(figure, 0, 0) == 4)
			ft_massjoin(s, figure);
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	ft_printmap(s, 0);
	free(s);
	return (0);
}