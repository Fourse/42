/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:13:55 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/15 12:21:58 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_coord
{
	int			x;
	int			y;
	int			number_of_room;
}				t_coord;

typedef struct	s_links
{
	struct s_links	**links;
}				t_links;

typedef struct	s_lemin
{
	int				number_of_ants;
	char			**rooms;
	t_coord			**coords;
	t_links			**links;
}				t_lemin;

#endif