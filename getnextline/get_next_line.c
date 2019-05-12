/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:25:14 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/10 15:43:36 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **s, char **line, int fd, int n)
{
	char	*d;
	size_t	i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i])
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		d = ft_strdup(s[fd] + i + 1);
		FS(s[fd], d);
		if (!s[fd][0])
			ft_strdel(&s[fd]);
	}
	else if (!s[fd][i])
	{
		if (n == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			n;
	char		buf[BUFF_SIZE + 1];
	char		*d;
	static char	*s[12000];

	if ((fd < 0 || line == NULL || BUFF_SIZE == 0 || read(fd, buf, 0) < 0))
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(1);
		d = ft_strjoin(s[fd], buf);
		FS(s[fd], d);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (n < 0)
		return (-1);
	else if (!n && (!s[fd] || !s[fd][0]))
		return (0);
	return (get_line(s, line, fd, n));
}
