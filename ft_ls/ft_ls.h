/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:26:12 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/24 16:57:40 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/time.h>
# include <glob.h>
# include <sys/ioctl.h>

# define CHK_FLAG "lRart"
# define BUF_SIZE 248

typedef struct	s_out
{
	char				buf[BUF_SIZE];
	int					len;
	int					print;
	int					fd;
}				t_out;

typedef struct	s_file_list
{
	struct s_file_list	*next;
	int					dir;
	char				*root;
	int					group;
	char				*who;
	int					year;
	char				*weight;
	char				*month;
	int					day;
	char				*time;
	char				*name;
}				t_fl;

extern t_out			g_ls;

#endif
