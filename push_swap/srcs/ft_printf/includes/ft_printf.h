/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:36:56 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/21 17:26:10 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"

/*
**	flags
*/

# define IS_MI(s) s == '-'
# define IS_PL(s) s == '+'
# define IS_SP(s) s == ' '
# define IS_HA(s) s == '#'
# define IS_NU(s) s == '0'

/*
**	modifier
*/

# define IS_H(s) s == 'h'
# define IS_L(s) s == 'l'
# define IS_Z(s) s == 'z'
# define IS_J(s) s == 'j'
# define IS_BL(s) s == 'L'

/*
**	type of conversion
*/

# define I_I(s) s == 'i'
# define I_D(s) s == 'd'
# define I_BD(s) s == 'D'
# define I_U(s) s == 'u'
# define I_BU(s) s == 'U'
# define I_O(s) s == 'o'
# define I_BO(s) s == 'O'
# define I_X(s) s == 'x'
# define I_BX(s) s == 'X'
# define I_B(s) s == 'b'
# define I_BB(s) s == 'B'
# define I_F(s) s == 'f'
# define I_BF(s) s == 'F'
# define I_E(s) s == 'e'
# define I_BE(s) s == 'E'
# define I_G(s) s == 'g'
# define I_BG(s) s == 'G'
# define I_A(s) s == 'a'
# define I_BA(s) s == 'A'
# define I_C(s) s == 'c'
# define I_BC(s) s == 'C'
# define I_S(s) s == 's'
# define I_BS(s) s == 'S'
# define I_P(s) s == 'p'
# define I_N(s) s == 'n'

/*
**	very useful macro
*/

# define O ||

/*
**	used macro
*/

# define I_IN(s) (I_I(s) O I_D(s) O I_BD(s) O I_U(s) O I_BU(s))
# define I_816(s) (I_O(s) O I_BO(s) O I_X(s) O I_BX(s) O I_B(s) O I_BB(s))
# define I_FL(s) (I_F(s) O I_BF(s) O I_E(s) O I_BE(s))
# define I_FL2(s) (I_G(s) O I_BG(s) O I_A(s) O I_BA(s))
# define I_CH(s) (I_C(s) O I_BC(s) O I_S(s) O I_BS(s))
# define I_GA(s) (I_P(s) O I_N(s))

# define CHK_F(s) (IS_MI(s) O IS_PL(s) O IS_SP(s) O IS_HA(s) O IS_NU(s))
# define CHK_W(s) (ft_isdigit(s))
# define CHK_A(s) s == '.'
# define CHK_M(s) (IS_H(s) O IS_L(s) O IS_Z(s) O IS_J(s) O IS_BL(s))
# define CHK_C(s) (I_IN(s) O I_816(s) O I_FL(s) O I_FL2(s) O I_CH(s) O I_GA(s))

# define BUFF_SIZE	128

# define HASH		1
# define MINUS		2
# define PLUS		4
# define SPACE		8
# define ZERO		16
# define ACC		32
# define LONGD		64

/*
**	structures/enum/union
*/

typedef enum	e_mod
{
	NO, HH, H, L, LL, Z, J
}				t_mod;

typedef struct	s_bits
{
	unsigned long long		mantis:64;
	int						exp:15;
	int						sign:1;
}				t_bits;

typedef union	u_floats
{
	long double				ret;
	t_bits					bits;
}				t_floats;

typedef struct	s_out
{
	char					buf[BUFF_SIZE];
	int						len;
	int						print;
	int						fd;
	int						error;
}				t_out;

typedef struct	s_format
{
	int						flag;
	int						width;
	int						acc;
	t_mod					mod;
	int						spec;
	size_t					len;
}				t_format;

extern t_out	g_print;

/*
**	functions' prototypes
*/

/*
**	ft_printf.c
*/

int				ft_printf(const char *format, ...);

/*
**		static functs
**	void		check_frmt(const char **format, va_list *ap);
**	int			parse_prms(const char **format, va_list *ap, t_format *params);
**	int			do_format(va_list *ap, t_format *params);
**	void		init_params(t_format *params);
*/

/*
**	out.c
*/

void			char_to_buf(char c, int i);
void			print_buf(void);
char			*make_width(t_format *params);
void			to_print(char *tmp, char *width, t_format *params);
void			string_to_buf(const char *start, const char *end);

/*
**	get_params.c
*/

void			get_flag(const char **format, t_format *params);
void			get_width(const char **format, va_list *ap, t_format *params);
void			get_acc(const char **format, va_list *ap, t_format *params);
void			get_mod(const char **format, t_format *params);
int				do_n(int *tmp);

/*
**	do_int.c
*/

int				do_d(va_list *ap, t_format *params);
int				do_u(va_list *ap, t_format *params);
int				do_o(va_list *ap, t_format *params);
int				do_x(va_list *ap, t_format *params);
int				do_b(va_list *ap, t_format *params);

/*
**	do_wm.c
*/

int				do_wm(uintmax_t ret, t_format *params, int base);

/*
**		static functs
**	int			init_size_len(t_format *params, char *tmp, int check);
**	int			chk_fl_for(char *tmp, int tof, t_format *params, int zero);
**	void		do_itoa(char **tmp, uintmax_t n, t_format *prms, int base);
**	void		chk_to_print(char *tmp, char *width, t_format *params);
*/

/*
**	do_char.c
*/

int				do_c(va_list *ap, t_format *params);
int				do_c_wm(const wchar_t c, t_format *params);
int				do_s_wm(const char *str, t_format *params);

/*
**	do_fl.c
*/

int				do_fl(va_list *ap, t_format *params);

/*
**		static functs
**	int			inf_nan(t_floats *ret_union, t_format *params);
**	char		*load_tmp(t_floats *ret_union, t_format *params);
**	int			get_exp(char *tmp);
**	int			do_fl_wm(char *tmp, t_format *params, int e, int sign);
*/

/*
**	long_arithmetic.c
*/

void			power_of(char *dot, int exp);

/*
**		static functs
**	int			*power_of_2(int exp, int *len_res);
**	int			*power_of_5(int exp, int *len_res);
**	int			new_size(int **res, int len);
**	int			*multiply(int *a, int *b, int size_a, int size_b);
*/

/*
**	do_fl_wm.c
*/

int				chk_g(int e, t_format *params);
char			*shift_dot(char *dot, int *e, t_format *params);
void			round_efg(char *dot, char *end);
int				trim_zeros(char *tmp);
void			suff_float(char *tmp, int e, t_format *params);

/*
**	do_fl_wm2.c
*/

int				do_fl_wm2(char *tmp, t_format *params, int sign);
int				chk_fl_for_fl(char *tmp, int sign, t_format *params);

/*
**	do_a_wm.c
*/

int				do_a_wm(long double n, int sign, t_format *params);

#endif
