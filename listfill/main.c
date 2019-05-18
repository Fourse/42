/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:40:43 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/18 18:22:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **new_fig(char *buf, char cur, int y, int x)
{
	char **tmp;
	int 

	return (tmp);
}

int read_file(int fd, char **figure, t_etris **list)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		cur;

	cur = 'A';
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (valid(buf, ret) != 0)
			return (0);
		(*list)->value = new_fig(buf, cur++, 0, 0);
		(*list) = (*list)->next;
		(*list) = (t_etris*)malloc(sizeof(t_etris));
		(*list)->next = NULL;
	}
	if (ret != 0)
		return (0);
	return (cur - 'A');
}

int error(char *str)
{
	ft_putendl(str);
	return (0);
}

int main(int argc, char **argv)
{
	t_etris	*list;
	char	*figure[20];
	char	**map;
	int		count;
	int		size;

	if (argc != 2)
		return (error("ebani ka argiment, drujishe"));
	if (!(list = (t_etris*)malloc(sizeof(t_etris))))
		return (0);
	if ((count = read_file(open(argv[1], O_RDONLY), figure, &list)) == 0)
		return (error("error"));
	map = NULL;	
	return (0);
}