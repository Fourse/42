/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:17:32 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/17 16:48:26 by rloraine         ###   ########.fr       */
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

int		connect(char *buf);
int		valid(char *buf, int ret);
int		read_file(int fd, char *figure, char **list);
char	*new_fig(char *figure, char *buf, char cur);
char	*empty_map(char *map, int count);
void	solve(char *map, char **list);
int		error(char *str);

#endif
