/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:24 by cnella            #+#    #+#             */
/*   Updated: 2019/10/25 14:52:13 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_output(t_lem_in *lem_in, char *line)
{
	t_list *new;

	new = NULL;
	if (line)
	{
		new = ft_lstnew(ft_strdup(line), 1);
		ft_lstadd(&lem_in->display, new);
	}
}

void	print_line(t_list *display)
{
	while (display && display->content != NULL)
	{
		ft_printf("%s\n", display->content);
		display = display->next;
	}
}

void	print_output(t_lem_in *lem_in, t_solution *solution)
{
	ft_lstrev(&lem_in->display);
	print_line(lem_in->display);
	ft_printf("\n");
	print_solve((*lem_in), solution);
}

void	free_output(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->display);
}
