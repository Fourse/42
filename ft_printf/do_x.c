/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:43:04 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 18:32:53 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_x(va_list *ap, t_format *params)
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
