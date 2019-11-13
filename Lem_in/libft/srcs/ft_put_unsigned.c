/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:24:46 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:24:50 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Processes unsigned number in decemal format. Does not show '+' and ' '.
*/

void	ft_unsigned(t_format *lst, uintmax_t arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-')
			&& lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width);
	else
		str_wid = ft_strnew_char(' ', lst->width);
	if (arg == 0 && lst->dot == 1 && !ft_chack_flag(lst, '+'))
		str = ft_strnew_char(' ', 0);
	else
		str = ft_un_itoa(arg);
	str_exa = ft_strnew_char('0', lst->exactness);
	str = ft_copy_string_right(str, str_exa);
	if (ft_chack_flag(lst, '-'))
		str = ft_copy_string_left(str, str_wid);
	else
		str = ft_copy_string_right(str, str_wid);
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

void	ft_put_unsigned(t_format *lst, va_list lst_arg)
{
	uintmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_unsigned(lst, arg);
}
