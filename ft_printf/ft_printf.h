/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:24:06 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/01 20:29:20 by rloraine         ###   ########.fr       */
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

# define H(s) *s == 'h'
# define HH(s) *s == 'h' && *++s == 'h'
# define L(s) *s == 'l'
# define LL(s) *s == 'l' && *++s == 'l'
# define BL(s) *s == 'L'

/*
** type of conversion
*/

# define IS_NUMB(s) *s == 'd' || *s == 'i'
# define IS_U(s) *s == 'u'
# define IS_O(s) *s == 'o'
# define IS_X(s) *s == 'x'
# define IS_BX(s) *s == 'X'
# define IS_F(s) *s == 'f'
# define IS_BF(s) *s == 'F'
# define IS_E(s) *s == 'e'
# define IS_BE(s) *s == 'E'
# define IS_G(s) *s == 'g'
# define IS_BG(s) *s == 'G'
# define IS_A(s) *s == 'a'
# define IS_BA(s) *s == 'A'
# define IS_C(s) *s == 'c'
# define IS_S(s) *s == 's'
# define IS_BS(s) *s == 'S'
# define IS_P(s) *s == 'p'
# define IS_N(s) *s == 'n'

/*
** used macro
*/

# define CHK_FL(s) (IS_MI(s) || IS_PL(s) || IS_SP(s) || IS_HA(s) || IS_NU(s))
# define CHK_W(s) (ft_isdigit(*s))
# define CHK_A(s) *s == '.'
# define CHK_MODS(s) ((H(s)) || (HH(s)) || (L(s)) || (LL(s)) || (BL(s)))
# define CHK_CONV(s) (IS_NUMB(s) || IS_U(s) || IS_O(s) || IS_X(s) || IS_BX(s))
# define CHK_CONV2(s) (IS_BE(s) || IS_G(s) || IS_BG(s) || IS_A(s) || IS_BA(s))
# define CHK_CONV3(s) (IS_BS(s) || IS_P(s)|| IS_N(s) || IS_E(s) || IS_S(s))
# define CHK_CONV4(s) (IS_F(s) || IS_C(s))
# define ROLL_NUMBS(s) while (ft_isdigit(*s++)) ;

/*
** structures
*/

typedef struct		s_format
{
	struct s_format	*next;
	char			flag;
	int				width;
	int				acc;
	char			*mod;
	char			spec;
}					t_format;

/*
** functions
*/

int					treatment(char *format, int result, va_list list);

#endif
