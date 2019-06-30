/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:26:03 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/30 18:29:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_c_wm(const wchar_t c, t_format *params)
{
	return (1);
}

int		do_s_wm(const char *str, t_format *params)
{
	return (1);
}

int		do_c(va_list *ap, t_format *params)
{
	if (params->spec == 'c' || params->spec == 'C')
	{
		if (params->mod == L || params->spec == 'C')
			return (do_c_wm((const wchar_t)va_arg(*ap, int), params));
		else
			return (do_c_wm((const char)va_arg(*ap, int), params));
	}
	else
	{
		if (params->mod == L || params->spec == 'S')
			return (do_ls_wm(va_arg(*ap, const wchar_t *), params));
		else
			return (do_s_wm(va_arg(*ap, const char *), params));
	}
	return (g_print.print = -1);
}
