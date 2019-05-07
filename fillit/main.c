/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/07 16:35:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int read_file(int fd, char *line)
{
	int n;
	char buf[BUFF_SIZE + 1];

	while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		ft_strjoin(line, buf);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char *line;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (read_file(open(argv[1], O_RDONLY), line) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}