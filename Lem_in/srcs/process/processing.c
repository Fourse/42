/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:55:34 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:55:36 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция фришит массив чаров
*/

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

/*
**	Вернуть индекс позиции с начала символа
**	в строке или вернуть -1, если он
**	не может найти символы в строке
*/

int		ft_strindex(const char *hay, char c)
{
	int i;

	i = 0;
	while (hay && hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
**	Читает следующую строку без комментариев
**	Комментарии начинаются с "#"
**	«##» НЕ являются комментариями
*/

int		gnl_no_comm(t_lem_in *lem_in, const int fd, char **line)
{
	int	res;

	res = 0;
	ft_strdel(line);
	while (1)
	{
		res = get_next_line(fd, line);
		if (res <= 0)
		{
			return (res);
		}
		save_output(lem_in, *line);
		if (!ft_strnequ("#", *line, 1)
			|| (ft_strequ("##start", *line))
			|| (ft_strequ("##end", *line)))
			return (res);
		ft_strdel(line);
	}
}

/*
**	Печатает указанный маршрут.
**	Цели отладки.
*/

void	print_nodes(t_glist *nodes)
{
	t_glist	*curr;
	t_room	*room;
	char	*label;
	char	*padding;

	curr = nodes;
	while (curr != NULL)
	{
		room = curr->gen.room;
		if (room->type == start)
			label = "[S]";
		else if (room->type == end)
			label = "[E]";
		else
			label = "";
		if (curr->next != NULL)
			padding = "-";
		else
			padding = "";
		ft_printf("%s%s%s", room->name, label, padding);
		curr = curr->next;
	}
	ft_printf("\n");
}
