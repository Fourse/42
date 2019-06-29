/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:43:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/28 18:07:20 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_x_itoa(char **tmp, uintmax_t ret, t_format *params)
{
	int spec;

	spec = (params->spec > 'a' ? 87 : 55);
	while (ret)
	{
		**tmp = ret % 16;
		**tmp += (**tmp > 9 ? spec : '0');
		ret /= 16;
		--(*tmp);
		--params->acc;
	}
}

int		chk_fl_forx(char *tmp, int zero, t_format *params)
{
	if (params->spec == 'p')
	{
		*tmp-- = 'x';
		*tmp = '0';
	}
	else if (!zero && params->flag & HASH)
	{
		*tmp-- = params->spec;
		*tmp = '0';
	}
	else
		return (-1);
	return (0);
}

int		do_x_wm(uintmax_t ret, t_format *params)
{
	char	*tmp;
	char	*tmptmp;
	char	*width;

	if (!(tmp = (char*)malloc(sizeof(char) * 19)))
		return (g_print.error = 0);
	tmptmp = tmp;
	tmp += 18;
	*tmp-- = 0;
	if (ret)
		do_x_itoa(&tmp, ret, params);
	while (params->acc-- > 0)
		*tmp-- = '0';
	tmp -= chk_fl_forx(tmp, (!ret), params);
	params->len = ft_strlen(tmp);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = 0);
	to_print(tmp, width, params);
	free(tmptmp);
	return (1);
}

int		do_x(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 2;
	if (params->spec == 'p')
	{
		params->flag |= HASH;
		return (do_x_wm(va_arg(*ap, intptr_t), params));
	}
	if (params->mod == NO)
		return (do_x_wm(va_arg(*ap, unsigned int), params));
	else if (params->mod == HH)
		return (do_x_wm((unsigned char)va_arg(*ap, int), params));
	else if (params->mod == H)
		return (do_x_wm((unsigned short)va_arg(*ap, int), params));
	else if (params->mod == L)
		return (do_x_wm(va_arg(*ap, unsigned long), params));
	else if (params->mod == LL)
		return (do_x_wm(va_arg(*ap, unsigned long long), params));
	else if (params->mod == Z)
		return (do_x_wm(va_arg(*ap, size_t), params));
	else if (params->mod == J)
		return (do_x_wm(va_arg(*ap, uintmax_t), params));
	return (g_print.print = 0);
}
