/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:57:59 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:58:00 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Поиск в ширину
*/

/*
**	Сбрасывает посещенные флаги и маршруты
*/

static void			reset_visited(t_lem_in *lem_in)
{
	t_glist	*curr;

	curr = lem_in->rooms;
	while (curr != NULL)
	{
		curr->gen.room->visited = false;
		curr->gen.room->visited2 = false;
		curr = curr->next;
	}
}

/*
**	Создает начальный список из одного элемента с начальным узлом.
*/

static t_glist		*init_first_level(t_lem_in *lem_in)
{
	t_glist	*res;
	t_tree	*tree;

	res = NULL;
	tree = tree_new(lem_in);
	tree->room = lem_in->start;
	tree->augmentation = 1;
	ft_add_glist(&res, ft_new_glist(tree, sizeof(t_tree)));
	return (res);
}

/*
**	Запускает обход в ширину по графику и строит маршруты.
**	Возвращает виртуальный маршрут.
**	Возвращает ноль, если не найден соответствующий путь перемещения.
*/

t_route				*start_bfs(t_lem_in *lem_in)
{
	t_glist			*nodes;
	t_glist			*next_nodes;
	t_route			*res;

	reset_visited(lem_in);
	nodes = init_first_level(lem_in);
	next_nodes = NULL;
	while (1)
	{
		res = sort_out_nodes(lem_in, nodes, &next_nodes);
		tree_deletelist(lem_in, &nodes);
		if (res != NULL)
		{
			tree_deletelist(lem_in, &next_nodes);
			return (res);
		}
		if (next_nodes == NULL)
			return (NULL);
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
