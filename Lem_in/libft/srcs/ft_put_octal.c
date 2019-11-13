/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:23:53 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:23:55 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If there is a flag # insert 0.
*/

void	ft_octotorp_octal(char **str, uintmax_t arg, t_format *lst)
{
	char *s;

	if (arg == 0 && lst->dot == 0)
		s = ft_strnew_char('0', ft_strlen(*str) + 0);
	else
		s = ft_strnew_char('0', ft_strlen(*str) + 1);
	*str = ft_copy_string_right(*str, s);
}

/*
** Processes whith octal number. Ignore flags '+' and ' '.
*/

void	ft_octal(t_format *lst, uintmax_t arg)
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
		str = ft_strnew(23);
		ft_itoo(str, arg);
	}
	if (ft_chack_flag(lst, '#'))
		ft_octotorp_octal(&str, arg, lst);
	str_exa = ft_strnew_char('0', lst->exactness);
	str = ft_copy_string_right(str, str_exa);
	if (ft_chack_flag(lst, '-'))
		str = ft_copy_string_left(str, str_wid);
	else
		str = ft_copy_string_right(str, str_wid);
	ft_lenstr_putstr_delstr(lst, str);
}

void	ft_lenstr_putstr_delstr(t_format *lst, char *str)
{
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

void	ft_put_octal(t_format *lst, va_list lst_arg)
{
	uintmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_octal(lst, arg);
}
