/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:23:40 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:23:43 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_toupper(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str++;
	}
}

void	ft_sourse_hex(char *str, t_format *lst, char *str_wid, char char_x)
{
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
	if (char_x == 'X')
		ft_str_toupper(str);
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

/*
** Processes with hexadecimal number. Ignore flags '+' and ' '.
*/

void	ft_hexadecimal(t_format *lst, uintmax_t arg, char char_x)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && lst->exactness == 0 &&
			!ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else
		str_wid = ft_strnew_char(' ', lst->width);
	if (arg == 0 && lst->dot == 1)
		str = ft_strnew_char(' ', 0);
	else
	{
		str = ft_strnew(25);
		ft_itox(str, arg);
	}
	if (ft_chack_flag(lst, '#') && arg != 0)
	{
		ft_octotorp_hex(&str);
		str_exa = ft_strnew_char('0', lst->exactness + 2);
	}
	else
		str_exa = ft_strnew_char('0', lst->exactness);
	str = ft_cop_str_right(str, str_exa);
	ft_sourse_hex(str, lst, str_wid, char_x);
}

void	ft_put_hexadecimal(t_format *lst, va_list lst_arg, char char_x)
{
	intmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_hexadecimal(lst, arg, char_x);
}
