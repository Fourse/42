/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:30:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:30:46 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char_not_zero(t_format *lst, char *ch)
{
	char *str_wid;
	char *str_exac;
	char *str_res;

	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else
		str_wid = ft_strnew_char(' ', lst->width);
	str_exac = ft_strdup(ch);
	ft_strdel(&ch);
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left(str_exac, str_wid);
	else
		str_res = ft_copy_string_right(str_exac, str_wid);
	ft_putstr(str_res);
	lst->len_str = ft_strlen(str_res);
	ft_strdel(&str_res);
}

void	ft_source_char_zero(t_format *lst)
{
	char *str_wid;

	if (ft_chack_flag(lst, '-'))
	{
		ft_putchar('\0');
		str_wid = ft_strnew_char(' ', lst->width - 1);
		ft_putstr(str_wid);
	}
	else
	{
		if (ft_chack_flag(lst, '0'))
			str_wid = ft_strnew_char('0', lst->width - 1);
		else
			str_wid = ft_strnew_char(' ', lst->width - 1);
		ft_putstr(str_wid);
		ft_putchar('\0');
	}
	lst->len_str = lst->width;
}

void	ft_put_char_zero(t_format *lst)
{
	if (lst->width == 0)
	{
		ft_putchar('\0');
		lst->len_str = 1;
	}
	else
		ft_source_char_zero(lst);
}

void	ft_put_char(t_format *lst, va_list lst_arg)
{
	char	*ch;

	ch = ft_strnew_char((char)va_arg(lst_arg, int), 1);
	if (ch[0] != '\0')
		ft_put_char_not_zero(lst, ch);
	else
		ft_put_char_zero(lst);
}
