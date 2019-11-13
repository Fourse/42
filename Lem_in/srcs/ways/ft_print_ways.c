/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:52:33 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:52:35 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_ways(t_route *route)
{
	t_bool	rev;

	rev = route->rooms->gen.room->type == end;
	ft_printf("Route #%d (len=%d)\t", route->id_route, route->len);
	if (rev)
		ft_reverse_glist(&route->rooms);
	print_nodes(route->rooms);
	if (rev)
		ft_reverse_glist(&route->rooms);
}
