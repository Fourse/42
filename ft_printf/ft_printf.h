/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:36:56 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/02 21:01:30 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "./libft/libft.h"

/*
** flags
*/

# define IS_MI(s) *s == '-'
# define IS_PL(s) *s == '+'
# define IS_SP(s) *s == ' '
# define IS_HA(s) *s == '#'
# define IS_NU(s) *s == '0'

/*
** modifier
*/

# define IS_H(s) *s == 'h'
# define IS_L(s) *s == 'l'
# define IS_Z(s) *s == 'z'
# define IS_J(s) *s == 'j'

/*
** type of conversion
*/

# define S_INT(s) 

/*
** structures
*/

enum			e_mods
{
	NO, HH, H, L, LL, Z, J
};

typedef struct		s_format
{
	struct s_format	*next;
	unsigned char	flag;
	unsigned char	width;
	unsigned char	acc;
	enum e_mods		mod;
	unsigned char	spec;
}					t_format;

/*
** functions' prototypes
*/

int	ft_printf(const char *format, ...);
int treatment(char *format, int result, va_list args);

#endif