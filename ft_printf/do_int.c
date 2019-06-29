/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:52:28 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/29 12:57:16 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_n(int *tmp)
{
	print_buf();
	if (!tmp)
		return (g_print.error = 0);
	*tmp = g_print.print;
	return (1);
}

int		do_x(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 2;
	if (params->spec == 'p')
	{
		params->flag |= HASH;
		return (do_wm(va_arg(*ap, intptr_t), params, 16));
	}
	if (params->mod == NO)
		return (do_wm(va_arg(*ap, unsigned int), params, 16));
	else if (params->mod == HH)
		return (do_wm((unsigned char)va_arg(*ap, int), params, 16));
	else if (params->mod == H)
		return (do_wm((unsigned short)va_arg(*ap, int), params, 16));
	else if (params->mod == L)
		return (do_wm(va_arg(*ap, unsigned long), params, 16));
	else if (params->mod == LL)
		return (do_wm(va_arg(*ap, unsigned long long), params, 16));
	else if (params->mod == Z)
		return (do_wm(va_arg(*ap, size_t), params, 16));
	else if (params->mod == J)
		return (do_wm(va_arg(*ap, uintmax_t), params, 16));
	return (g_print.print = 0);
}

int		do_o(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 1;
	if (params->mod == NO)
		return (do_wm(va_arg(*ap, unsigned int), params, 8));
	else if (params->mod == HH)
		return (do_wm((unsigned char)va_arg(*ap, int), params, 8));
	else if (params->mod == H)
		return (do_wm((unsigned short)va_arg(*ap, int), params, 8));
	else if (params->mod == L)
		return (do_wm(va_arg(*ap, unsigned long), params, 8));
	else if (params->mod == LL)
		return (do_wm(va_arg(*ap, unsigned long long), params, 8));
	else if (params->mod == Z)
		return (do_wm(va_arg(*ap, size_t), params, 8));
	else if (params->mod == J)
		return (do_wm(va_arg(*ap, uintmax_t), params, 8));
	return (g_print.print = 0);
}

int		do_u(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 2;
	if (params->mod == NO)
		return (do_wm(va_arg(*ap, unsigned int), params, 10));
	else if (params->mod == HH)
		return (do_wm((unsigned char)va_arg(*ap, int), params, 10));
	else if (params->mod == H)
		return (do_wm((unsigned short)va_arg(*ap, int), params, 10));
	else if (params->mod == L)
		return (do_wm(va_arg(*ap, unsigned long), params, 10));
	else if (params->mod == LL)
		return (do_wm(va_arg(*ap, unsigned long long), params, 10));
	else if (params->mod == Z)
		return (do_wm(va_arg(*ap, size_t), params, 10));
	else if (params->mod == J)
		return (do_wm(va_arg(*ap, uintmax_t), params, 10));
	return (g_print.print = 0);
}

int		do_d(va_list *ap, t_format *params)
{
	if (params->flag & ZERO && params->width > params->acc)
		params->acc = params->width - 1;
	if (params->mod == NO)
		return (do_wm(va_arg(*ap, int), params, 10));
	else if (params->mod == HH)
		return (do_wm((char)va_arg(*ap, int), params, 10));
	else if (params->mod == H)
		return (do_wm((short)va_arg(*ap, int), params, 10));
	else if (params->mod == L)
		return (do_wm(va_arg(*ap, long), params, 10));
	else if (params->mod == LL)
		return (do_wm(va_arg(*ap, long long), params, 10));
	else if (params->mod == Z)
		return (do_wm(va_arg(*ap, ssize_t), params, 10));
	else if (params->mod == J)
		return (do_wm(va_arg(*ap, intmax_t), params, 10));
	return (g_print.print = 0);
}
