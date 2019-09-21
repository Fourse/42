/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:13:37 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/21 16:54:59 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_printf("Error");
	exit(0);
}

int		get_type(char *line)
{
	if (*line == '#')
	{
		if (ft_strequ(line, "##start"))
			return (START);
		if (ft_strequ(line, "##end"))
			return (END);
		return (COMM);
	}
	while (*line)
	{
		if (*line == ' ')
			return (ROOM);
		if (*line == '-')
			return (LINK);
		++line;
	}
	return (SHIT);
}

t_inp	*read_file(t_inp *prev)
{
	t_inp	*new;
	
	if (!(new = (t_inp*)malloc(sizeof(t_inp))))
		error();
	if (!(new->line = read_input()))
	{
		free(new);
		return (NULL);
	}
	new->type = get_type(new->line);
	new->prev = prev;
	new->next = read_file(new);
	return (new);
}

int		main(int argc, char **argv)
{
	t_lemin lem_in;
	t_inp	*map;

	if (!(map = read_file(NULL)))
		error();
		
}
