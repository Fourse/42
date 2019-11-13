/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:57:14 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:57:14 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Соединяет два узла. Не влияет на начало или конец комнаты
*/

static void		connect(t_room *prev, t_room *next)
{
	if (prev != NULL && prev->type != standard && next->type != standard)
	{
		return ;
	}
	if (prev != NULL && prev->type == standard)
	{
		prev->next = next;
	}
	if (next->type == standard)
	{
		next->prev = prev;
	}
}

static t_bool	has_route(t_room *room)
{
	return (room->next != NULL && room->prev != NULL);
}

/*
**	Возвращает первый узел маршрута комнаты после старта
*/

static t_room	*route_start(t_room *room)
{
	t_room	*res;

	res = room;
	while (res->prev && res->prev->type != start)
	{
		res = res->prev;
	}
	return (res);
}

/*
**	Разбивает обнаруженный существующий маршрут
*/

static void		break_route(t_room *room)
{
	t_room	*curr;
	t_room	*next;

	curr = route_start(room);
	while (curr && curr->type == standard)
	{
		next = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		curr = next;
	}
}

/*
**	Обновляет соединения узлов (prev, next), представляющие маршруты
**	на карте, используя ход, созданный алгоритмом Эдмондса-Карпа
*/

void			rebuild_ways(t_lem_in *lem_in, t_route *route)
{
	t_glist	*curr;
	t_room	*prev;

	(void)lem_in;
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (has_route(curr->gen.room))
		{
			break_route(curr->gen.room);
		}
		prev = curr->gen.room;
		curr = curr->next;
	}
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		connect(prev, curr->gen.room);
		prev = curr->gen.room;
		curr = curr->next;
	}
}
