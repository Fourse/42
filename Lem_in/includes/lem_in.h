/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:00:08 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 19:04:35 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define MAX_NB_SIZE 10

typedef struct s_glist		t_glist;

typedef	struct s_lem_in		t_lem_in;
typedef	struct s_room		t_room;
typedef	enum e_roomtype		t_roomtype;
typedef	struct s_move		t_move;
typedef struct s_round		t_round;
typedef struct s_solution	t_solution;
typedef struct s_route		t_route;
typedef struct s_group		t_group;
typedef struct s_opt		t_opt;
typedef struct s_tree		t_tree;

union		u_generic
{
	void	*content;
	t_room	*room;
	t_route	*route;
	t_group	*group;
	t_round	*round;
	t_move	*move;
	t_glist	*glist;
	t_tree	*tree;
};

struct		s_glist
{
	union u_generic	gen;
	size_t			content_size;
	struct s_glist	*next;
};

enum		e_roomtype
{
	standard,
	start,
	end,
};

struct		s_opt
{

	t_bool	print_room;
	t_bool	print_route;
	t_bool	print_groups;
	t_bool	print_nblines;
	t_bool	print_help;
};

struct		s_lem_in
{
	int		total_ants;
	int		max_routes;
	t_room	*start;
	t_room	*end;
	int		room_count;
	t_glist	*rooms;
	t_room	**array_room;
	t_list	*display;
	t_opt	opt;
};

/*
**	struct	s_room
**	Комната с муравьем или вершина
**
**	name:		Название комнаты. Вывод целей
**	id:			Room id. Айди комнаты
**	type:		Start / end / standard (intermediate node)
**	Начало/конец/ обычная (промежуточная)
**	ants:		Количество муравьев в текущей комнате. Максимум для одного
**	ant_id:		Найстощий айди муравья от 1 до отсчета
**				0, если нет муравьев
**	links:		Список связанных комнат
**	visited:	Истина, если был посещен поиском в ширину
**	visited2:	Как "посещенный", но пока не для увеличенного пути
*/

struct		s_room
{
	char		*name;
	int			id;
	t_roomtype	type;
	int			ants;
	int			ant_id;
	t_glist		*links;
	int			links_count;
	t_room		*prev;
	t_room		*next;
	t_bool		visited;
	t_bool		visited2;
};

/*
**	Итоговый результат
**	Содержит список раундов
*/

struct		s_solution
{
	int		round;
	int		route;
	t_dlist	*rounds;
};

/*
**	Раунд.
**	Содержит список движений
*/

struct		s_round
{
	t_dlist	*moves;
};

/*
**	Воображаемое корневое дерево. Используется
**	для разделения путей в поиске в ширину
**	room:			текущая комната узла
**	parent:			Родительская вершина
**	child_count:	потомок. Если 0 - тупик
**	intersection:	узел, где поиск начинает резать существующий маршрут.
*/

struct		s_tree
{
	t_room	*room;
	t_tree	*parent;
	int		child_count;
	int		augmentation;
	t_room	*intersection;
};

/*
**	Муравей идущий из начала к цели
*/

struct		s_move
{
	int		id_route;
	int		ant_id;
	t_room	*dst;
};

struct		s_route
{
	int		id_route;
	int		len;
	t_glist	*rooms;
};

/*
**	Комбинация не конфликтных путей
**	total_rounds:		необходимое количество раундов, чтобы
**	отправить муравьев через эту группу. Меньший лучшее
**	count:				количество путей
**	ants_distribution:	Оптимальный массив распределения муравьев по маршрутам
**	routes:				Массив групповых маршрутов
*/

struct		s_group
{
	int		route_count;
	int		total_rounds;
	int		*ants_distribution;
	t_route	**routes;
};

/*
**	Основа
*/

void		lem_initialization(t_lem_in *lem_in);
void		lem_addroom(t_lem_in *lem_in, t_room *room);
void		lem_free(t_lem_in *lem_in, t_solution *solution);
void		lem_out();
void		lem_removeroom(t_lem_in *lem_in, t_room *room);

/*
**	Функции листов
*/

t_glist		*ft_new_glist(void const *content, size_t content_size);
void		ft_delone_glist(t_glist **alst, void (*del)(void*, size_t));
void		ft_delete_glist(t_glist **alst, void (*del)(void*, size_t));
void		ft_add_glist(t_glist **alst, t_glist *new);
void		ft_glstiter(t_glist *lst, void (*f)(t_glist *elem));
t_glist		*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem));
void		ft_glstadd_last(t_glist **alst, t_glist *n);
t_glist		*ft_copy_glist(t_glist *src);
t_bool		ft_content_glist(t_glist *lst, void *content);
void		ft_sort_glist(t_glist *list, int (*cmp)(void*, void*));
int			ft_length_glist(t_glist *list);
void		ft_reverse_glist(t_glist **list);

/*
**	Поиск
*/

void		parser(t_lem_in *lem_in);
void		parse_ants(t_lem_in *lem_in, char **line);
void		parse_rooms(t_lem_in *lem_in, char **line);
void		parse_room(t_lem_in *lem_in, char *line, t_roomtype type);
int			count_lines_room(t_lem_in *lem_in, char **line, t_roomtype type);
t_bool		parse_is_link(char *line);
void		parser_links(t_lem_in *lem_in, char **line);
void		parse_link(t_lem_in *lem_in, char **line);
int			parse_string(char *s);
void		lem_in_print_all_rooms(t_lem_in *lem_in);

/*
**	Комната
*/

t_room		*create_newroom(char *name, t_roomtype type);
t_room		*search_room(t_lem_in *lem_in, char *name);
void		room_free(void *content, size_t size);
int			room_sort(void *a, void *b);

/*
** Связи комнат
*/

void		room_createlink(t_lem_in *lem_in, char *origin, char *target);
void		room_deletelink(t_room *room, t_room *link);

/*
**	Поиск в ширину
*/

t_route		*start_bfs(t_lem_in *lem_in);

/*
**	Основа поиска в ширину
*/

t_route		*sort_out_nodes(t_lem_in *lem_in, t_glist *nodes,
	t_glist **next_nodes);
t_route		*sortout_node(t_lem_in *lem_in,
	t_tree *node, t_glist **next_nodes);
t_route		*build_end_traverse(t_tree *node);
t_tree		*stop_traverse(t_lem_in *lem_in, t_tree *node);
t_tree		*traverse(t_lem_in *lem_in, t_tree *node, t_room *dst);

/*
**	Функции для поиска в ширину
*/

t_bool		do_traverse(t_tree *tree, t_room *dst);
t_bool		in_route(t_room *src, t_room *dst);
t_bool		out_route(t_room *src, t_room *dst);
t_tree		*go_begin(t_lem_in *lem_in, t_tree *tree);
void		mark_visited(t_tree *tree);

/*
**	Дерево для поиска в ширину
*/

t_tree		*tree_new(t_lem_in *lem_in);
void		tree_del(t_lem_in *lem_in, t_tree *tree);
void		tree_deletelist(t_lem_in *lem_in, t_glist **trees);
t_tree		*tree_createchild(t_lem_in *lem_in, t_tree *parent, t_room *room);
t_route		*route_tree(t_tree *tree);

/*
**	Маршрут
*/

t_route		*route_new();
t_route		*route_build(t_room *start, t_room *second);
void		route_free(void *content, size_t size);
t_route		*route_copy(t_route *src);
void		ft_print_ways(t_route *route);
void		route_add_node(t_route *route, t_room *room);

/*
**	Группа
*/

t_group		*class_create(t_lem_in *lem_in);
void		group_add_route(t_group *group, t_route *route);
void		class_free(void *content, size_t size);
void		class_print(t_group *group);
int			classes_count_route(t_group *group, int index);
void		spread_ants(t_group *group, int total_ants);

/*
**	Решение
*/

void		solve(t_lem_in *lem_in, t_solution *solution);
void		rebuild_ways(t_lem_in *lem_in, t_route *route);
void		create_solve(t_lem_in *lem_in, t_group *group,
	t_solution *solution);
int			max_routes(t_lem_in *lem_in);

/*
**	Вывод решения
*/

t_bool		move_ant(t_room *src, t_room *dest,
	t_solution *solution, int *ants_routes);
t_bool		possible_move_ant(t_room *room);

/*
**	Решение
*/

void		resolve_initialization(t_solution *solution);
void		print_solve(t_lem_in lem_in, t_solution *solution);
void		resolve_new_round(t_solution *solution);
void		resolve_addmove(t_solution *solution, t_room *dst);
void		resolve_free(t_solution *solution);
void		round_free(void *content, size_t size);
void		resolve_free_round(t_solution *solution);

/*
**	Применяемые функции
*/

void		ft_free_tab(char ***tab);
int			ft_strindex(const char *hay, char c);
int			gnl_no_comm(t_lem_in *lem_in, const int fd, char **line);
void		print_nodes(t_glist *nodes);
t_bool		is_number(char *s);

/*
**	Функции для массива
*/

void		*glist_inarray(t_glist *list);
void		array_sort(void **array, size_t size, int (cmp)(void*, void*));

/*
**	Поиск
*/

/*
**	Оптимизатор поиска
*/

void		delete_end(t_lem_in *lem_in, t_room *dead_end);
void		parse_optimizer(t_lem_in *lem_in);

/*
**	Сохранение и печать
*/

void		save_output(t_lem_in *lem_in, char *line);
void		print_output(t_lem_in *lem_in, t_solution *solution);
void		free_output(t_lem_in *lem_in);

/*
**	Функции для массива
*/

void		*glist_to_array(t_glist *list);
void		array_sort(void **array, size_t size, int (cmp)(void*, void*));

#endif
