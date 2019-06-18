/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:01:06 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/18 18:31:26 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	read_file(int fd)
{
	int		count;
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (count == 0)
			count = ft_isword(line, ' ');
		if (count != (int)ft_isword(line, ' '))
			return (0);
		free(line);
	}
	if (count == 0 || ret == -1)
		return (0);
	return (1);
}
