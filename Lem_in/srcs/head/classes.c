/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:56:25 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:56:25 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Чистка всей группы
*/

void	class_free(void *content, size_t size)
{
	t_group	*group;
	int		i;

	(void)size;
	group = (t_group*)content;
	i = 0;
	while (i < group->route_count)
	{
		route_free(group->routes[i], sizeof(t_route));
		i++;
	}
	free(group->routes);
	free(group->ants_distribution);
	free(group);
}

/*
**	Возвращает количетсов раундов
*/

int		classes_count_route(t_group *group, int index)
{
	if (group->ants_distribution[index] <= 0)
		return (0);
	return (group->routes[index]->len + group->ants_distribution[index] - 1);
}

/*
**	Печать группы и всех раундов
*/

void	class_print(t_group *group)
{
	int	i;

	ft_printf("Group (routes=%d; total_rounds=%d):\n", group->route_count,
		group->total_rounds);
	i = 0;
	while (i < group->route_count)
	{
		ft_printf("(ants=%d) (rounds=%d) ",
			group->ants_distribution[i],
			classes_count_route(group, i));
		ft_print_ways(group->routes[i]);
		i++;
	}
}
