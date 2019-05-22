/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:28:41 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/22 18:32:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*trim_fig(char *s, char *buf)
{
	int i;

	i = 0;
	SQU(buf);
	VST(buf);
	GST(buf);
	T0(buf);
	T90(buf);
	T180(buf);
	T250(buf);
	Z0(buf);
	Z90(buf);
	Z180(buf);
	Z250(buf);
	L0G(buf);
	R0G(buf);
	RU90G(buf);
	LU90G(buf);
	L180G(buf);
	R180G(buf);
	LD90G(buf);
	RD90G(buf);
	return (s);
}

char		**new_fig(char *buf, char cur, t_etris *list)
{
	char	*s;
	int		j;
	int		y;
	int		x;

	s = NULL;
	j = -1;
	while (*buf != '#')
		buf++;
	s = trim_fig(s, buf);
	while (s[++j])
		if (s[j] == '#')
			s[j] = cur;
	list->value = ft_strsplit(s, '\n');
	free(s);
	y = -1;
	while (list->value[++y])
	{
		x = -1;
		while (list->value[y][++x])
			list->weigth = x + 1;
	}
	list->heigth = y;
	return (list->value);
}

static int	connect(char *buf)
{
	int i;
	int block;
	int hash;

	i = 0;
	block = 0;
	hash = 0;
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
		i++;
	}
	return (((block == 6 || block == 8) && hash == 4) ? 1 : 0);
}

int			valid(char *buf, int ret)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				error++;
		}
		else if (buf[i] != '\n')
			error++;
		i++;
	}
	if (ret == 21 && buf[20] != '\n')
		error++;
	if (connect(buf) == 0)
		error++;
	return (error);
}

int			error(char *str)
{
	ft_putendl(str);
	return (0);
}
