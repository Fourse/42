/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:17:32 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/07 16:20:37 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>

void	ft_simp_square(char **figure);
int		ft_valid(char **figure, int y, int x);
int		ft_read_file(int fd, char **figure, char **corr_figure);
void	ft_mass_join(char **corr, char **fig);
void	ft_deleverytning(char **split, int n);

#endif
