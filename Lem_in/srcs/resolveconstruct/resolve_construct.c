/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_construct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:54:37 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:54:40 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Переместите муравьев для комнаты в другую и сохраните движение
*/

t_bool		move_ant(t_room *src, t_room *dest, t_solution *solution,
	int *ants_for_routes)
{
	int cpt;

	cpt = 0;
	while (src->ants > 0 && possible_move_ant(dest))
	{
		if (src->type == start)
		{
			if ((*ants_for_routes) <= 0)
				return (false);
			(*ants_for_routes)--;
			src->ant_id++;
		}
		src->ants--;
		dest->ants++;
		dest->ant_id = src->ant_id;
		resolve_addmove(solution, dest);
		cpt++;
	}
	return ((cpt != 0) ? true : false);
}

/*
**	Возвращает true, если муравей может переместиться в указанную комнату
*/

t_bool		possible_move_ant(t_room *room)
{
	if ((room->ants == 0 && room->type == standard) || (room->type == end))
		return (true);
	return (false);
}

/*
**	Переместить всех муравьев одного маршрута одной группы
*/

static void	run_route(t_lem_in *lem_in, t_route *route, int *ants_for_routes,
	t_solution *solution)
{
	t_glist	*curr;
	t_room	*room_a;
	t_room	*room_b;

	curr = route->rooms;
	while (curr->gen.room != lem_in->start)
	{
		room_a = curr->gen.room;
		room_b = curr->next->gen.room;
		move_ant(room_b, room_a, solution, ants_for_routes);
		curr = curr->next;
	}
}

/*
**	Выполняет один раунд решения. Печатает одну строку
*/

static void	run_round(t_group *group, t_lem_in *lem_in, t_solution *solution)
{
	int		i;

	resolve_new_round(solution);
	i = 0;
	while (i < group->route_count)
	{
		solution->route = i;
		run_route(lem_in, group->routes[i], &group->ants_distribution[i],
			solution);
		i++;
	}
}

/*
**	Двигает всех муравьев одного маршрута группы
*/

void		create_solve(t_lem_in *lem_in, t_group *group,
	t_solution *solution)
{
	while ((lem_in->start->ants) >= 0
		&& lem_in->end->ants != lem_in->total_ants)
	{
		run_round(group, lem_in, solution);
	}
}
