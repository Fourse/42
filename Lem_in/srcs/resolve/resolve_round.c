/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:55:08 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:55:09 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Создает новый пустой раунд
*/

void		resolve_new_round(t_solution *solution)
{
	t_round	*round;
	t_dlist	*new;

	round = ft_memalloc(sizeof(t_round));
	new = ft_dlstnew(round, sizeof(t_round));
	ft_dlstadd(&solution->rounds, new);
	solution->round++;
}

/*
**	Сбрасывает последний раунд
**	Освобождаем раунд и двигает его память
*/

void		resolve_free_round(t_solution *solution)
{
	t_round	*round;
	t_dlist	*curr;

	curr = solution->rounds;
	if (curr == NULL)
		lem_out();
	round = (t_round*)curr->content;
	ft_dlstdel(&round->moves, NULL);
	ft_dlstdelone(&solution->rounds, NULL);
}

/*
**	Чистка раунда
*/

void		round_free(void *content, size_t size)
{
	t_round	*round;

	(void)size;
	round = (t_round*)content;
	ft_dlstdel(&round->moves, NULL);
}
