/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bfs_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:57:53 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:57:53 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*traverse(t_lem_in *lem_in, t_tree *node, t_room *dst)
{
	t_tree			*res;
	int				augmentation;
	t_room			*intersection;

	if (!do_traverse(node, dst))
		return (NULL);
	augmentation = node->augmentation;
	if (in_route(node->room, dst))
	{
		augmentation--;
		if (augmentation < 0)
			return (NULL);
		intersection = dst;
	}
	else if (out_route(node->room, dst))
		intersection = NULL;
	else
		intersection = node->intersection;
	res = tree_createchild(lem_in, node, dst);
	res->augmentation = augmentation;
	res->intersection = intersection;
	return (res);
}

t_tree	*stop_traverse(t_lem_in *lem_in, t_tree *node)
{
	t_tree	*res;

	if (node->parent->room->next != NULL)
	{
		res = go_begin(lem_in, node);
		return (res);
	}
	return (NULL);
}

t_route	*build_end_traverse(t_tree *node)
{
	if (node->augmentation > 0)
	{
		return (route_tree(node));
	}
	return (NULL);
}

/*
**	Перебирает соединения текущего уровня узла.
**	Хранит новый список соединений узла.
**	Возвращает найденный путь, если есть
*/

t_route	*sortout_node(t_lem_in *lem_in, t_tree *node,
	t_glist **next_nodes)
{
	t_glist			*curr;
	t_tree			*new_node;
	t_route			*res;

	new_node = NULL;
	mark_visited(node);
	if (node && node->room->type == end)
	{
		if ((res = build_end_traverse(node)) != NULL)
			return (res);
		new_node = stop_traverse(lem_in, node);
		if (new_node != NULL)
			ft_add_glist(next_nodes, ft_new_glist(new_node, sizeof(t_tree)));
		return (NULL);
	}
	curr = node->room->links;
	while (curr != NULL)
	{
		new_node = traverse(lem_in, node, curr->gen.room);
		if (new_node != NULL)
			ft_add_glist(next_nodes, ft_new_glist(new_node, sizeof(t_tree)));
		curr = curr->next;
	}
	return (NULL);
}

/*
**	Перебирает узлы текущего уровня.
**	Хранит список узлов следующего уровня.
**	Возвращает лист дерева с первым найденным путем, если есть.
*/

t_route	*sort_out_nodes(t_lem_in *lem_in, t_glist *nodes,
	t_glist **next_nodes)
{
	t_glist		*curr;
	t_route		*res;

	curr = nodes;
	while (curr != NULL)
	{
		if ((res = sortout_node(lem_in, curr->gen.tree, next_nodes)))
			return (res);
		curr = curr->next;
	}
	return (NULL);
}
