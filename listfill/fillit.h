/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:40:55 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/19 15:25:13 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>

typedef struct		s_etris
{
	struct s_etris	*next;
	char			**value;
	int				weigth;
	int				heigth;
}					t_etris;

int					connect(char *buf);
int					valid(char *buf, int ret);
void				solve_map(char **map, t_etris *list, int y, int x);
int					solve(char **map, int count, int size);
char				*trim_fig(char *buf);
char				**new_fig(char *buf, char cur, t_etris ***list);
int					read_file(int fd, t_etris **list);
int					error(char *str);

#endif
