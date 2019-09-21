/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:13:55 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/21 16:54:27 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

# define SHIT	0
# define COMM	1
# define ROOM	2
# define LINK	3
# define START	4
# define END	5

typedef struct	s_inp
{
	char			*line;
	int				type;
	struct s_inp	*next;
	struct s_inp	*prev;
}				t_inp;

typedef struct	s_coord
{
	int				x;
	int				y;
	int				number_of_room;
	int				start_end_dot;
}				t_coord;

typedef struct	s_links
{
	struct s_links	**links;
}				t_links;

typedef struct	s_lemin
{
	int				number_of_ants;
	char			**rooms;
	t_coord			*coords;
	t_links			**links;
}				t_lemin;

/*
**	----FUNCTS----
*/

/*
**	main.c
*/

t_inp			*read_file(t_inp *prev);
int				get_type(char *line);
void			error(void);

/*
**	read_input.c
*/

char			*read_input(void);
char			*find_newline(char *str);
char			*get_newline(char **tail, char *newline);
char			*read_more(char *tail);

#endif
