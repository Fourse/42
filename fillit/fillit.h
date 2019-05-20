/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:17:32 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/20 16:14:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# define O == '#'
# define D s = ft_strdup
# define A &&

# define SQU(b) if (b[i + 1] O A b[i + 5] O A b[i + 6] O) D("##\n##\n");
# define VST(b) if (b[i + 5] O A b[i + 10] O A b[i + 15] O) D("#\n#\n#\n#\n");
# define GST(b) if (b[i + 1] O A b[i + 2] O A b[i + 3] O) D("####\n");
# define T0(b) if (b[i + 4] O A b[i + 5] O A b[i + 6] O) D(".#.\n###\n");
# define T90(b) if (b[i + 5] O A b[i + 6] O A b[i + 10] O) D("#.\n##\n#.\n");
# define T180(b) if (b[i + 1] O A b[i + 2] O A b[i + 6] O) D("###\n.#.\n");
# define T250(b) if (b[i + 4] O A b[i + 5] O A b[i + 10] O) D(".#\n##\n.#\n");
# define Z0(b) if (b[i + 4] O A b[i + 5] O A b[i + 9] O) D(".#\n##\n#.\n");
# define Z90(b) if (b[i + 1] O A b[i + 4] O A b[i + 5] O) D(".##\n##.\n");
# define Z180(b) if (b[i + 1] O A b[i + 6] O A b[i + 7] O) D("##.\n.##\n");
# define Z250(b) if (b[i + 5] O A b[i + 6] O A b[i + 11] O) D("#.\n##\n.#\n");
# define L0G(b) if (b[i + 1] O A b[i + 6] O A b[i + 11] O) D("##\n.#\n.#\n");
# define R0G(b) if (b[i + 1] O A b[i + 5] O A b[i + 10] O) D("##\n#.\n#.\n");
# define RU90G(b) if (b[i + 3] O A b[i + 4] O A b[i + 5] O) D("..#\n###\n");
# define LU90G(b) if (b[i + 5] O A b[i + 6] O A b[i + 7] O) D("#..\n###\n");
# define L180G(b) if (b[i + 5] O A b[i + 9] O A b[i + 10] O) D(".#\n.#\n##\n");
# define R180G(b) if (b[i + 5] O A b[i + 10] O A b[i + 11] O) D("#.\n#.\n##\n");
# define LD90G(b) if (b[i + 1] O A b[i + 2] O A b[i + 5] O) D("###\n#..\n");
# define RD90G(b) if (b[i + 1] O A b[i + 2] O A b[i + 7] O) D("###\n..#\n");

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>

void	solve(char *map, char **list, int num_fig, int x);
char	*empty_map(char *map, int count);
char	*trim_fig(char *s, char *buf);
char	*new_fig(char *buf, char cur);
int		connect(char *buf);
int		valid(char *buf, int ret);
int		read_file(int fd, char **list);
int		error(char *str);

#endif
