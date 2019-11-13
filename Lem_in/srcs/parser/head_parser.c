/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:56:04 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:56:05 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Читает ожидаемое количество муравьев
*/

void	parse_ants(t_lem_in *lem_in, char **line)
{
	int i;

	i = 0;
	if ((i = gnl_no_comm(lem_in, 0, line)) != -1)
	{
		if (ft_strlen(*line) <= MAX_NB_SIZE
			&& (i = parse_string(*line)) > 0)
			lem_in->total_ants = i;
		else
		{
			ft_strdel(line);
			lem_out();
		}
		ft_strdel(line);
	}
	else
		lem_out();
}

/*
**	Читает и записывает комнаты
*/

int		count_lines_room(t_lem_in *lem_in, char **line, t_roomtype type)
{
	if (gnl_no_comm(lem_in, 0, line) == -1)
		lem_out();
	parse_room(lem_in, *line, type);
	return (1);
}

/*
**	Разбирает список комнат. Останавливается на первой линии связи.
*/

void	parse_rooms(t_lem_in *lem_in, char **line)
{
	int		state;

	while ((state = gnl_no_comm(lem_in, 0, line)) != -1)
	{
		if (parse_is_link(*line))
		{
			break ;
		}
		if (ft_strnequ("##", *line, 2))
		{
			if (ft_strequ("##start", *line))
				count_lines_room(lem_in, line, start);
			else if (ft_strequ("##end", *line))
				count_lines_room(lem_in, line, end);
		}
		else
		{
			parse_room(lem_in, *line, standard);
		}
	}
	if (state == -1 || lem_in->start == NULL || lem_in->end == NULL)
		lem_out();
}

/*
**	Разбивает список линков
*/

void	parser_links(t_lem_in *lem_in, char **line)
{
	while (1)
	{
		if (!parse_is_link(*line))
		{
			ft_strdel(line);
			break ;
		}
		parse_link(lem_in, line);
		if (gnl_no_comm(lem_in, 0, line) == -1)
		{
			lem_out();
		}
	}
	ft_strdel(line);
	if (lem_in->start->links == 0 || lem_in->end->links_count == 0)
		lem_out();
}
