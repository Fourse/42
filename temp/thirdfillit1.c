/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdfillit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:26:05 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/07 16:35:52 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_simp_square(char **corr)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if (!corr)
		write(1, "oops", 4);
	/*while (corr[n])
	{
		if ()
	}*/
	write(1, "atata", 5);
}

void	ft_mass_join(char **corr, char **fig)
{
	int			n;
	int			i;
	static int	k;

	n = 0;
	corr = (char**)malloc(sizeof(char*) * 547);
	while (fig[n])
	{
		i = 0;
		corr[k] = (char*)malloc(sizeof(char) * 5);
		while (fig[n][i++])
			corr[k][i] = fig[n][i];
		corr[k++][i] = '\0';
		n++;
	}
	corr[k] = NULL;
}

int		ft_valid(char **figure, int y, int x)
{
	write(1, "1\n", 2);
	if (figure[y][x] != '#' && (y >= 4 || y < 0) && (x >= 4 || x < 0))
		return (0);
	figure[y][x] = '*';
	return ((ft_valid(figure, y + 1, x)) + (ft_valid(figure, y - 1, x))\
	+ (ft_valid(figure, y, x + 1)) + (ft_valid(figure, y, x - 1)) + 1);
}

int		ft_read_file(int fd, char **figure, char **corr_figure)
{
	int		n;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	while ((n = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		buf[n] = '\0';
		figure = ft_strsplit(buf, '\n');
		i++;
		if ((ft_valid(figure, 0, 0)) != 4)
			return (0);
		ft_mass_join(corr_figure, figure);
	}
	return (i);
}
