/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:52:44 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:53:09 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_route		*route_new(void)
{
	t_route		*res;
	static int	id;

	res = ft_memalloc(sizeof(t_route));
	res->len = -1;
	res->id_route = id;
	id++;
	return (res);
}

t_route		*route_build(t_room *start, t_room *second)
{
	t_route	*res;
	t_room	*curr;

	res = route_new();
	route_add_node(res, start);
	curr = second;
	while (curr != NULL)
	{
		route_add_node(res, curr);
		curr = curr->next;
	}
	return (res);
}

t_route		*route_copy(t_route *src)
{
	t_route	*res;

	res = route_new();
	res->len = src->len;
	res->rooms = ft_copy_glist(src->rooms);
	ft_reverse_glist(&res->rooms);
	return (res);
}

void		route_free(void *content, size_t size)
{
	t_route	*route;

	(void)size;
	route = (t_route*)content;
	ft_delete_glist(&route->rooms, NULL);
	free(route);
}

void		route_add_node(t_route *route, t_room *room)
{
	t_glist	*new;

	new = ft_new_glist(room, sizeof(t_room));
	ft_add_glist(&route->rooms, new);
	route->len++;
}
