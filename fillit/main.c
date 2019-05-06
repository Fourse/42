/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:59:02 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/06 19:30:22 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int read_file(int fd)
{
	int n;
	char buf[BUFF_SIZE + 1];
	static char **s;

	while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		buf[n] = '\0';
		s = ft_strsplit(buf, '\n');
		
	}
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((read_file(fd)) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}

	close(fd);
	return (0);
}