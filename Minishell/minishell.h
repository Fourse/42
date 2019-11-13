/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:04:35 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/22 17:48:52 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

/*
**	ERROR DEFINES
*/

/*
**	----FUNCTS----
*/

void	get_comm(char *line);
void	error(char *str);

#endif
