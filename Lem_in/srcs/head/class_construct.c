/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:56:18 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:56:19 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		route_cmp_len(void *a, void *b)
{
	t_route	*route_a;
	t_route	*route_b;

	route_a = (t_route*)a;
	route_b = (t_route*)b;
	return (route_a->len - route_b->len);
}

static int		routes_count(t_room *start)
{
	int		res;
	t_glist	*curr;

	res = 0;
	curr = start->links;
	while (curr != NULL)
	{
		if (curr->gen.room->next != NULL || curr->gen.room->type == end)
		{
			res++;
		}
		curr = curr->next;
	}
	return (res);
}

static void		create_routes(t_lem_in *lem_in, t_group *group)
{
	t_glist	*curr;
	t_route	*route;
	int		i;

	i = 0;
	curr = lem_in->start->links;
	while (curr != NULL)
	{
		if (curr->gen.room->next != NULL || curr->gen.room->type == end)
		{
			route = route_build(lem_in->start, curr->gen.room);
			group->routes[i] = route;
			i++;
		}
		curr = curr->next;
	}
}

/*
**  Инициализация всей группы раундов
*/

static int		rounds_for_group(t_group *group)
{
	int res;
	int i;
	int tmp;

	res = 0;
	i = 0;
	tmp = 0;
	while (i < group->route_count)
	{
		if (group->ants_distribution[i] > 0)
		{
			tmp = group->ants_distribution[i] + group->routes[i]->len - 1;
			if (tmp > res)
				res = tmp;
		}
		i++;
	}
	return (res);
}

/*
**	Создает новую группу маршрутов,
**	используя исходящие соединения с начального узла.
*/

t_group			*class_create(t_lem_in *lem_in)
{
	t_group	*res;

	res = ft_memalloc(sizeof(t_group));
	res->route_count = routes_count(lem_in->start);
	res->routes = ft_safe_malloc(sizeof(t_route*) * res->route_count);
	res->ants_distribution = ft_memalloc(sizeof(int) * res->route_count);
	create_routes(lem_in, res);
	array_sort((void**)res->routes, res->route_count, route_cmp_len);
	spread_ants(res, lem_in->total_ants);
	res->total_rounds = rounds_for_group(res);
	return (res);
}
