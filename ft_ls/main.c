/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:25:58 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/25 14:01:54 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_out g_ls;

void	error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		find_flag(char **args, char *str)
{
	int		i;
	int		j;
	char	tmp[64];

	i = 0;
	j = 1;
	while (str[j])
	{
		if (str[j] == 'l')
			tmp[i++] = str[j++];
		if (str[j] == 'R')
			tmp[i++] = str[j++];
		if (str[j] == 'a')
			tmp[i++] = str[j++];
		if (str[j] == 'r')
			tmp[i++] = str[j++];
		if (str[j] == 't')
			tmp[i++] = str[j++];
		else if (str[j] && (str[j] != 'l' || str[j] != 'R' || str[j] != 'a' || str[j] != 'r' || str[j] != 't'))
			error("net takogo flaga");
	}
	tmp[i] = '\0';
	*args = ft_strjoin(*args, tmp);
	return (1);
}

void	check_args(char **args, char **av)
{
	int n;
	int i;

	n = 1;
	while (av[n])
	{
		i = 0;
		while (av[n][i])
		{
			if (av[n][i] == '-')
			{
				i++;
				if (!(find_flag(args, av[n])))
					error("ne tot flag");
			}
			else if (av[n][i] == '/')
				error("poka ne sdelal");
			i++;
			//else
			//	error("i eto ne sdelal");
		}
		n++;
	}
}

void	list_init(t_fl **list)
{
	if (!((*list) = (t_fl*)malloc(sizeof(t_fl))))
		error("MALLOC FAIL");
	(*list)->dir = 0;
	(*list)->root = NULL;
	(*list)->group = 0;
	(*list)->who = NULL;
	(*list)->year = 0;
	(*list)->weight = NULL;
	(*list)->month = NULL;
	(*list)->day = 0;
	(*list)->time = NULL;
	(*list)->name = NULL;
	(*list)->next = NULL;
}

int		main(int ac, char **av)
{
	t_fl	*list;
	char	*args;

	args = ft_strnew(0);
//	if (ac > 1)
//	{
		check_args(&args, av);
		list_init(&list);
		printf("%s\n", args);
//	}
//	else
//		cur_dir();
	return (g_ls.print);
}
