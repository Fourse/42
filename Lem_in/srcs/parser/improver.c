/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:55:51 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:55:52 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Удаляет комнату dead_end из всех ссылок списка всех комнат lem.
**	Удаляет комнату с тупиком и весь путь.
*/

void	delete_end(t_lem_in *lem_in, t_room *dead_end)
{
	t_room	*next;
	t_room	*curr;

	curr = dead_end;
	while (curr && curr->type == standard && curr->links_count <= 1)
	{
		next = NULL;
		if (curr->type == standard && curr->links_count == 1)
		{
			next = curr->links->gen.room;
			room_deletelink(next, curr);
		}
		lem_removeroom(lem_in, curr);
		curr = next;
	}
}

/*
**	Чистит комнаты с тупиками
*/

void	parse_optimizer(t_lem_in *lem_in)
{
	t_glist		*curr;
	t_room		*room;
	int			cpt;

	cpt = 0;
	room = NULL;
	curr = lem_in->rooms;
	while (curr && curr->gen.room)
	{
		room = curr->gen.room;
		if (room->links_count <= 1 && room->type == standard)
		{
			delete_end(lem_in, room);
			curr = lem_in->rooms;
			cpt++;
		}
		else
			curr = curr->next;
	}
}
