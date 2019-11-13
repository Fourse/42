/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:26:58 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:27:02 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_symb(char *str, char ch)
{
	char *newstr;

	newstr = ft_strnew_char(ch, ft_strlen(str) + 1);
	newstr = ft_copy_string_right(str, newstr);
	return (newstr);
}

char	*ft_float_width_without_zero(t_format *lst, char *str)
{
	char	*str_res;
	char	*str_wid;

	str_wid = ft_strnew_char(' ', lst->width);
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left(str, str_wid);
	else
		str_res = ft_copy_string_right(str, str_wid);
	return (str_res);
}

char	*ft_float_width_with_zero(t_format *lst, char *str)
{
	char	*str_res;
	char	*str_wid;

	if (ft_chack_flag(lst, '-'))
	{
		str_wid = ft_strnew_char(' ', lst->width);
		str_res = ft_copy_string_left(str, str_wid);
	}
	else
	{
		str_wid = ft_strnew_char('0', lst->width);
		str_res = ft_copy_string_right(str, str_wid);
	}
	return (str_res);
}

char	*ft_float_width(t_format *lst, char *str, long double arg)
{
	char	*str_res;

	if (!ft_chack_flag(lst, '0'))
		str_res = ft_float_width_without_zero(lst, str);
	else
	{
		if (arg < 0 || ft_chack_flag(lst, '+') || ft_chack_flag(lst, ' '))
			str[0] = '0';
		str_res = ft_float_width_with_zero(lst, str);
		if (ft_chack_flag(lst, '+') || ft_chack_flag(lst, ' '))
		{
			if (ft_chack_flag(lst, ' '))
				str_res[0] = ' ';
			if (ft_chack_flag(lst, '+'))
				str_res[0] = '+';
		}
		if (arg < 0)
			str_res[0] = '-';
	}
	return (str_res);
}

void	ft_put_float(t_format *lst, va_list lst_arg, char type)
{
	char		*str;
	long double	arg;

	if (lst->size[0] == 'L')
		arg = va_arg(lst_arg, long double);
	else
		arg = va_arg(lst_arg, double);
	if (ft_float_inf(lst, arg, type))
		return ;
	if (!lst->dot)
		str = ft_float_str(arg, 6);
	else
		str = ft_float_str(arg, lst->exactness);
	str = ft_round(str);
	if (!ft_chack_flag(lst, '#'))
	{
		if (str[ft_strlen(str) - 1] == '.')
			str[ft_strlen(str) - 1] = '\0';
	}
	if (arg >= 0 && ft_chack_flag(lst, '+'))
		str = ft_add_symb(str, '+');
	else if (arg >= 0 && ft_chack_flag(lst, ' '))
		str = ft_add_symb(str, ' ');
	str = ft_float_width(lst, str, arg);
	ft_lenstr_putstr_delstr(lst, str);
}
