/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:32:59 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/27 18:42:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_u_itoa(char **tmp, uintmax_t ret, t_format *params)
{
	while (ret)
	{
		**tmp = ret % 10 + '0';
		ret /= 10;
		--(*tmp);
		--params->acc;
	}
}

int		do_u_wm(uintmax_t ret, t_format *params)
{
	char	*tmp;
	char	*tmptmp;
	char	*width;

	if (!(tmp = (char*)malloc(sizeof(char) * 21)))
		return (g_print.error = 0);
	tmptmp = tmp;
	tmp += 20;
	*tmp-- = 0;
	if (ret)
		do_u_itoa(&tmp, ret, params);
	while (params->acc-- > 0)
		*tmp-- = '0';
	params->len = ft_strlen(tmp + 1);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = 0);
	to_print(tmp + 1, width, params);
	free(tmptmp);
	return (1);
}

int		do_u(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 2;
	if (params->mod == NO)
		return (do_u_wm(va_arg(*ap, unsigned int), params));
	else if (params->mod == HH)
		return (do_u_wm((unsigned char)va_arg(*ap, int), params));
	else if (params->mod == H)
		return (do_u_wm((unsigned short)va_arg(*ap, int), params));
	else if (params->mod == L)
		return (do_u_wm(va_arg(*ap, unsigned long), params));
	else if (params->mod == LL)
		return (do_u_wm(va_arg(*ap, unsigned long long), params));
	else if (params->mod == Z)
		return (do_u_wm(va_arg(*ap, size_t), params));
	else if (params->mod == J)
		return (do_u_wm(va_arg(*ap, uintmax_t), params));
	return (g_print.print = 0);
}
