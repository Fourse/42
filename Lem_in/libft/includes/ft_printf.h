/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:41:13 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:41:17 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_format
{
	char		flag[5];
	int			width;
	int			dot;
	int			exactness;
	char		size[3];
	size_t		len_str;
}				t_format;

int				ft_printf(const char *restrict format, ...);
char			*ft_strnew_char(int c, size_t len);
void			ft_put_string(t_format *lst, va_list lst_arg);
int				ft_chack_flag(t_format *lst, char flag);
char			*ft_copy_string_left(char *str1, char *str2);
char			*ft_copy_string_right(char *str1, char *str2);
void			ft_put_char(t_format *lst, va_list lst_arg);
char			*ft_concat_str(char *str1, char *str2);
char			*ft_float_str(long double num, int exact);
char			*ft_fraction_exact(char *fract_str, int exact);
void			ft_put_float(t_format *lst, va_list lst_arg, char type);
char			*ft_round(char *fract_str);
int				ft_float_inf(t_format *lst, long double	arg, char type);
void			ft_put_pointer(t_format *lst, va_list lst_arg);
void			ft_octotorp_hex(char **str);
void			ft_put_percent(t_format *lst);
uintmax_t		ft_check_un_dimension(t_format *lst, va_list lst_arg);
void			ft_put_unsigned(t_format *lst, va_list lst_arg);
t_format		*ft_newstruct(void);
char			*ft_strnew_char(int c, size_t len);
void			ft_put_octal(t_format *lst, va_list lst_arg);
void			ft_lenstr_putstr_delstr(t_format *lst, char *str);
void			ft_put_hexadecimal(t_format *lst, va_list lst_arg, char char_x);
void			ft_sign_str(char *str1, char *str2);
char			*ft_cop_str_right(char *str1, char *str2);
char			*ft_cop_str_left(char *str1, char *str2);
void			ft_put_decimal(t_format *lst, va_list lst_arg);
intmax_t		ft_check_dimension(t_format *lst, va_list lst_arg);
int				ft_read_format(char *iter, t_format *lst, va_list lst_ard);
int				ft_isflag(char c);
int				ft_istype(char c);
int				ft_issize(char c);
void			ft_check_special_type(char *iter, t_format *lst);

#endif
