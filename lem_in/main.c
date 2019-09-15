/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:13:37 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/15 13:15:04 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_printf("Error");
	exit(0);
}

void	get_coords(t_lemin *lem_in)
{
	char *line;

	while (get_next_line(0, &line) >= 0)
	{
		if (*line == '#')
		{
			if (*line + 1 == '#')
			{
				if (*line + 2 == 's')
				{
					
				}
				else if (*line + 2 == 'e')
				{
					
				}
			}
		}
		else
			continue ;
	}
}

int		main(int argc, char **argv)
{
	t_lemin lem_in;

	get_coords(&lem_in);
}
