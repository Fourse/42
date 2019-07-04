/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:26:03 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/04 16:37:53 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_c_wm(const wchar_t c, t_format *prms)
{
	prms->len = 1;
	if (!(prms->flag & MINUS) && prms->width > prms->len)
		char_to_buf((prms->flag & ZERO ? '0' : ' '), prms->width - prms->len);
	if (prms->spec == 'c' && prms->mod != L)
		char_to_buf(c, 1);
	if ((prms->flag & MINUS) && prms->width > prms->len)
		char_to_buf((prms->flag & ZERO ? '0' : ' '), prms->width - prms->len);
	return (0);
}

int		do_s_wm(const char *str, t_format *params)
{
	int width;

	if (!str)
		str = (params->acc ? "(null)" : "");
	params->len = ft_strlen(str);
	if (params->flag & ACC)
		params->len = params->acc < params->len ? params->acc : params->len;
	width = params->width - params->len;
	if (!(params->flag & MINUS) && width > 0)
		char_to_buf((params->flag & ZERO ? '0' : ' '), width);
	if (params->len > 0)
		string_to_buf(str, str + params->len);
	if ((params->flag & MINUS) && width > 0)
		char_to_buf((params->flag & ZERO ? '0' : ' '), width);
	return (0);
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
		return (do_s_wm(va_arg(*ap, const char *), params));
	return (g_print.print = -1);
}
