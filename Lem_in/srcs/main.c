/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:03 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:05:06 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lem_in	lem_in;
	t_solution	solution;

	parser(&lem_in);
	solve(&lem_in, &solution);
	print_output(&lem_in, &solution);
	print_solve(lem_in, &solution);
	lem_free(&lem_in, &solution);
	return (0);
}
