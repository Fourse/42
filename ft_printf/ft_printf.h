/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:36:56 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/22 14:56:39 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "./libft/libft.h"

/*
**	flags
*/

# define IS_MI(s) *s == '-'
# define IS_PL(s) *s == '+'
# define IS_SP(s) *s == ' '
# define IS_HA(s) *s == '#'
# define IS_NU(s) *s == '0'

/*
**	modifier
*/

# define IS_H(s) *s == 'h'
# define IS_L(s) *s == 'l'
# define IS_Z(s) *s == 'z'
# define IS_J(s) *s == 'j'

/*
**	type of conversion
*/

# define I_I(s) *s == 'i'
# define I_D(s) *s == 'd'
# define I_BD(s) *s == 'D'
# define I_U(s) *s == 'u'
# define I_BU(s) *s == 'U'
# define I_O(s) *s == 'o'
# define I_BO(s) *s == 'O'
# define I_X(s) *s == 'x'
# define I_BX(s) *s == 'X'
# define I_F(s) *s == 'f'
# define I_BF(s) *s == 'F'
# define I_E(s) *s == 'e'
# define I_BE(s) *s == 'E'
# define I_G(s) *s == 'g'
# define I_BG(s) *s == 'G'
# define I_A(s) *s == 'a'
# define I_BA(s) *s == 'A'
# define I_C(s) *s == 'c'
# define I_BC(s) *s == 'C'
# define I_S(s) *s == 's'
# define I_BS(s) *s == 'S'
# define I_P(s) *s == 'p'
# define I_N(s) *s == 'n'

/*
**	very useful macro
*/

# define O ||

/*
**	used macro
*/

# define IS_INT(s) (I_I(s) O I_D(s) O I_BD(s) O I_U(s) O I_BU(s))
# define IS_816(s) (I_O(s) O I_BO(s) O I_X(s) O I_BX(s))
# define IS_FLO(s) (I_F(s) O I_BF(s) O I_E(s) O I_BE(s) O I_G(s) O I_BG(s))
# define IS_CHA(s) (I_C(s) O I_BC(s) O I_S(s) O I_BS(s))
# define IS_GAV(s) (I_A(s) O I_BA(s) O I_P(s) O I_N(s))

# define CHK_F(s) (IS_MI(s) O IS_PL(s) O IS_SP(s) O IS_HA(s) O IS_NU(s))
# define CHK_W(s) (ft_isdigit(*s))
# define CHK_A(s) *s == '.'
# define CHK_M(s) (IS_H(s) O IS_L(s) O IS_Z(s) O IS_J(s))
# define CHK_C(s) (IS_INT(s) O IS_816(s) O IS_FLO(s) O IS_CHA(s) O IS_GAV(s))

# define BUFF_SIZE 128

/*
**	structures
*/

typedef struct	s_out
{
	char		buf[BUFF_SIZE];
	int			len;
	int			print;
	int			fd;
	int			error;
}				t_out;

typedef enum	e_mod
{
	NO, HH, H, L, LL, Z, J
}				t_mod;

typedef struct	s_format
{
	int			flag;
	int			width;
	int			acc;
	t_mod		mod;
	int			spec;
}				t_format;

extern t_out	g_print;

/*
**	functions' prototypes
*/

/*
**	ft_printf.c
*/

int				ft_printf(const char *format, ...);
void			check_frmt(const char **format, va_list ap, t_format *params);
void			char_to_buf(char c, int i);
void			print_buf(void);

/*
**	parsing.c
*/

int				parse_prms(const char **format, va_list ap, t_format *params);
void			get_flag(const char **format, t_format *params);
void			get_width(const char **format, va_list ap, t_format *params);
void			get_acc(const char **format, va_list ap, t_format *params);
void			get_mod(const char **format, t_format *params);

/*
**	do_smth.c
*/

int				do_c(const char *format, t_format *params);

#endif
