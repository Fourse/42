/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bfs_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:57:46 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:57:46 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Возвращает фактический пункт назначения для указанного узла.
**	Возвращает NULL, когда пункт назначения невозможен.
*/

t_bool			do_traverse(t_tree *tree, t_room *dst)
{
	if (tree->augmentation > 0 && dst->visited)
		return (false);
	if (tree->augmentation == 0 && dst->visited2)
		return (false);
	if (tree->room->prev != NULL && tree->room->prev == dst)
		return (false);
	if (tree->intersection == dst)
		return (false);
	if (tree->intersection != NULL
		&& tree->room == tree->intersection
		&& dst != tree->room->next)
	{
		return (false);
	}
	if (tree->room->type == start && dst->prev == tree->room)
		return (false);
	if (dst->type == start)
		return (false);
	return (true);
}

/*
**	Возвращает true, если переход от src к dst означает
**	переход на существующий маршрут
*/

t_bool			in_route(t_room *src, t_room *dst)
{
	if (src->next != NULL && src->next == dst)
		return (false);
	if (dst->prev == NULL)
		return (false);
	if (dst->prev == src)
		return (false);
	return (true);
}

/*
**	Возвращает true, если переход от src к dst
**	означает выход из существующего маршрута.
*/

t_bool			out_route(t_room *src, t_room *dst)
{
	return (src->next != NULL && src->next != dst);
}

/*
**	Продолжает движение от первого узла существующего
**	маршрута, на котором мы находимся.
**	Возвращает ноль, если последнее пересечение является первым узлом маршрута.
*/

t_tree			*go_begin(t_lem_in *lem_in, t_tree *tree)
{
	t_room	*room;
	t_tree	*res;

	room = tree->parent->room;
	while (room->prev->type != start)
	{
		room = room->prev;
	}
	if (tree->intersection == room)
	{
		return (NULL);
	}
	res = tree_createchild(lem_in, tree, lem_in->start);
	res = tree_createchild(lem_in, res, room);
	res->augmentation++;
	return (res);
}

/*
**	Отмечает указанную комнату дерева перемещения, если необходимо.
*/

void			mark_visited(t_tree *tree)
{
	if (tree->room->type == standard && tree->room->next == NULL)
	{
		if (tree->augmentation > 0)
			tree->room->visited = true;
		else
			tree->room->visited2 = true;
	}
}
