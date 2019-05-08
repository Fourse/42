/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/08 15:08:22 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_valid(char  **figure, int n, int i)
{
	if (figure[n][i] != '#' && (n >= 4 || n < 0) && (i >= 4 || i < 0))
		return (0);
	figure[n][i] = '*';
	return (ft_valid(figure, n + 1, i) + ft_valid(figure, n - 1, i) + ft_valid(figure, n, i - 1) + ft_valid(figure, n, i + 1));
}

int read_file(int fd, char *line, char **figure)
{
	int n;
	char buf[BUFF_SIZE];

	while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		buf[n] = '\0';
		line = ft_strjoin(line, buf);
	}
	figure = ft_strsplit(line, '\n');
	return (ft_valid(figure, 0, 0) != 4 ? 0 : 1);
}

int main(int argc, char **argv)
{
	char *line;
	char **figure;

	line = ft_strnew(1);
	figure = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (read_file(open(argv[1], O_RDONLY), line, figure) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}