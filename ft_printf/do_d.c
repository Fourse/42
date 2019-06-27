/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:34:57 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/27 16:51:07 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_d_itoa(char **tmp, intmax_t ret, t_format *params)
{
	if (ret < 0)
	{
		**tmp = ret % 10 * -1 + '0';
		ret = ~(ret / 10) + 1;
		--(*tmp);
		--params->acc;
	}
	while (ret)
	{
		**tmp = ret % 10 + '0';
		ret /= 10;
		--(*tmp);
		--params->acc;
	}
}

int		chk_fl_for(char *tmp, int sign, t_format *params)
{
	if (sign)
		*tmp = '-';
	else if (params->flag & PLUS)
		*tmp = '+';
	else if (params->flag & SPACE)
		*tmp = ' ';
	else
		return (-1);
	return (0);
}

int		do_d_wm(intmax_t ret, t_format *params)
{
	char	*tmp;
	char	*tmptmp;
	char	*width;

	if (!(tmp = (char*)malloc(sizeof(char) * 22)))
		return (g_print.error = 0);
	tmptmp = tmp;
	tmp += 21;
	*tmp-- = 0;
	if (ret)
		do_d_itoa(&tmp, ret, params);
	while (params->acc-- > 0)
		*tmp-- = '0';
	tmp -= chk_fl_for(tmp, (ret < 0), params);
	params->len = ft_strlen(tmp);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = 0);
	to_print(tmp, width, params);
	free(tmptmp);
	return (1);
}

int		do_d(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 1;
	if (params->mod == NO)
		return (do_d_wm(va_arg(*ap, int), params));
	else if (params->mod == HH)
		return (do_d_wm((char)va_arg(*ap, int), params));
	else if (params->mod == H)
		return (do_d_wm((short)va_arg(*ap, int), params));
	else if (params->mod == L)
		return (do_d_wm(va_arg(*ap, long), params));
	else if (params->mod == LL)
		return (do_d_wm(va_arg(*ap, long long), params));
	else if (params->mod == Z)
		return (do_d_wm(va_arg(*ap, ssize_t), params));
	else if (params->mod == J)
		return (do_d_wm(va_arg(*ap, intmax_t), params));
	return (g_print.print = 0);
}
