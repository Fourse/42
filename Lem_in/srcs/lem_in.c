/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:06:04 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:51:49 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_initialization(t_lem_in *lem_in)
{
	ft_bzero(lem_in, sizeof(t_lem_in));
}

void	lem_addroom(t_lem_in *lem_in, t_room *room)
{
	t_glist	*new;

	new = ft_new_glist(room, sizeof(t_room));
	ft_add_glist(&lem_in->rooms, new);
	lem_in->room_count++;
	if (room->type == start)
	{
		if (lem_in->start != NULL)
			lem_out();
		lem_in->start = room;
	}
	else if (room->type == end)
	{
		if (lem_in->end != NULL)
			lem_out();
		lem_in->end = room;
	}
}

void	lem_free(t_lem_in *lem_in, t_solution *solution)
{
	resolve_free(&(*solution));
	ft_delete_glist(&lem_in->rooms, room_free);
	free(lem_in->array_room);
	free_output(lem_in);
}

void	lem_removeroom(t_lem_in *lem_in, t_room *room)
{
	t_glist	**curr;

	curr = &lem_in->rooms;
	while (*curr != NULL)
	{
		if ((*curr)->gen.room == room)
		{
			ft_delone_glist(curr, room_free);
			lem_in->room_count--;
			return ;
		}
		curr = &(*curr)->next;
	}
}

void	lem_out(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}
