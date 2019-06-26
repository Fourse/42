/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:32:59 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 18:31:33 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_u(va_list *ap, t_format *params)
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
