/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:28:41 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/18 16:34:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connect(char *buf)
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

int		valid(char *buf, int ret)
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
