/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdfillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:59:02 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/07 16:35:54 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deleverytning(char **split, int n)
{
	while (n >= 0)
	{
		free(split[n]);
		n--;
	}
	free(split);
	split = NULL;
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**figure;
	char	**corr_fig;

	figure = NULL;
	corr_fig = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((ft_read_file(fd, figure, corr_fig)) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_simp_square(corr_fig);
	ft_deleverytning(figure, 5);
	ft_deleverytning(corr_fig, 547);
	close(fd);
	return (0);
}
