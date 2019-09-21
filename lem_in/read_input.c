/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:54:40 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/21 16:54:05 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*read_more(char *tail)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;
	if ((ret = read(0, buf, BUFF_SIZE)) < 0)
		error();
	buf[ret] = 0;
	if (tail)
	{
		tmp = tail;
		if (!(tail = ft_strjoin(tail, ret ? buf : "\n")))
			error();
		free(tmp);
	}
	else
	{
		if (!ret)
			return (NULL);
		if (!(tail = ft_strdup(buf)))
			error();
	}
	return (tail);
}

char	*get_newline(char **tail, char *newline)
{
	char *line;
	char *tmp;
	char *tmp_tail;
	char *new_tail;

	if (!(line = (char*)malloc(sizeof(char) * (newline - *tail + 1))))
		error();
	tmp = line;
	tmp_tail = *tail;
	while (tmp_tail != newline)
		*tmp++ = *tmp_tail++;
	*tmp = 0;
	if (!*++tmp_tail)
		new_tail = NULL;
	else if (!(new_tail = ft_strdup(tmp_tail)))
		error();
	free(*tail);
	*tail = new_tail;
	return (line);
}

char	*find_newline(char *str)
{
	if (str)
		while (*str)
			if (*str++ == '\n')
				return (str - 1);
	return (NULL);
}

char	*read_input(void)
{
	static char	*tail = NULL;
	char		*newline;
	
	while (1)
	{
		if ((newline = find_newline(tail)))
			return (get_newline(&tail, newline));
		else if (!(tail = read_more(tail)))
			return (NULL);
	}
}
