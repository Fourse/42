/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:24:59 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/27 18:07:10 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_map(int fd, char **map)
{
	
}

int figure(int fd)
{
	int i;
	int n;
	int k;
	static char buf[22];

	i = 0;
	n = 1;
	read(fd, buf, 21);
	ft_strsplit(buf, '\n');
	while (buf[0][i] != '#')
		i++;
	k = i;
	while (buf[n])
	{
		i = 0;
		while (buf[n][i] != '#')
		{
			if (buf[n][i] == '#')
				i == k ? n++, continue : return (0);
			i++;
		}
		if (buf[n][i] == '#')
			i == k ? n++, continue : return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	char **map;

	if (argc == 2)
	{
		if (figure(open(argv[1], O_RDONLY)) == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else if (figure(open(argv[1], O_RDONLY)) == 1)
		{
			print_square(fd, map);
			return (0);
		}
	return (0);
}
