/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:34:57 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/27 11:33:46 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_itoa(char *tmp, size_t *size, intmax_t ret, t_format *params)
{
	if (ret < 0)
	{
		tmp[*size] = ret % 10 * -1 + '0';
		ret = ~(ret / 10) + 1;
		--*size;
		--params->acc;
	}
	while (ret)
	{
		tmp[*size] = ret % 10 + '0';
		ret /= 10;
		--*size;
		--params->acc;
	}
}

int		chk_fl_for(char *tmp, size_t *size, int sign, t_format *params)
{
	if (sign)
		tmp[*size] = '-';
	else if (params->flag & PLUS)
		tmp[*size] = '+';
	else if (params->flag & SPACE)
		tmp[*size] = ' ';
	else
		return (-1);
	return (0);
}

int		do_d_wm(intmax_t ret, t_format *params)
{
	char	tmp[64];
	size_t	size;
	char	*width;

	size = (20 & ((params->acc - 20) >> 31)) | (params->acc & (~(params->acc - 20) >> 31));
	tmp[--size] = 0;
	if (ret)
		do_itoa(tmp, &size, ret, params);
	while (params->acc-- > 0)
		tmp[size--] = '0';
	tmp[size] = chk_fl_for(tmp, &size, (ret < 0), params);
	params->len = ft_strlen(tmp);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = 0);
	to_print(tmp, width, params);
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
