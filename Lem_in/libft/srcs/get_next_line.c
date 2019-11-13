/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:29:27 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:52:53 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static unsigned int	linelen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char			*append(char *s1, char *s2)
{
	char		*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	if (str == NULL)
		return (NULL);
	return (str);
}

static int			shift_to_end(char *str)
{
	char	*lineend;

	lineend = ft_strchr(str, '\n');
	if (lineend)
	{
		ft_strcpy(str, lineend + 1);
		return (1);
	}
	if (linelen(str) > 0)
	{
		*str = '\0';
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	ssize_t		res;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (*line != NULL)
		ft_strdel(line);
	if (!(save[fd]) && (save[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) &&
			(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = append(save[fd], buff);
		if (save[fd] == NULL)
			return (-1);
	}
	*line = ft_strsub(save[fd], 0, linelen(save[fd]));
	if (!shift_to_end(save[fd]))
	{
		free(save[fd]);
		return (0);
	}
	return (1);
}
