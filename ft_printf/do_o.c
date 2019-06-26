/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:41:32 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 18:31:47 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_o(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 1;
	if (params->mod == NO)
		return (do_o_wm(va_arg(*ap, unsigned int), params));
	else if (params->mod == HH)
		return (do_o_wm((unsigned char)va_arg(*ap, int), params));
	else if (params->mod == H)
		return (do_o_wm((unsigned short)va_arg(*ap, int), params));
	else if (params->mod == L)
		return (do_o_wm(va_arg(*ap, unsigned long), params));
	else if (params->mod == LL)
		return (do_o_wm(va_arg(*ap, unsigned long long), params));
	else if (params->mod == Z)
		return (do_o_wm(va_arg(*ap, size_t), params));
	else if (params->mod == J)
		return (do_o_wm(va_arg(*ap, uintmax_t), params));
	return (g_print.print = 0);
}
