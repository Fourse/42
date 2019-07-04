/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:04:00 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/04 16:37:32 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_out g_print;

void	init_params(t_format *params)
{
	params->flag = 0;
	params->width = 0;
	params->acc = 1;
	params->mod = 0;
	params->spec = 0;
}

int		do_format(va_list *ap, t_format *params)
{
	int sp;

	sp = params->spec;
	if (I_IN(sp) || I_GA(sp) || I_816(sp))
	{
		if ((params->flag & (ZERO | ACC)) == (ZERO | ACC))
			params->flag ^= ZERO;
		if (I_I(sp) || I_D(sp) || I_BD(sp))
			return (do_d(ap, params));
		else if (I_U(sp) || I_BU(sp))
			return (do_u(ap, params));
		else if (I_O(sp) || I_BO(sp))
			return (do_o(ap, params));
		else if (I_X(sp) || I_BX(sp) || I_P(sp))
			return (do_x(ap, params));
		else if (I_B(sp) || I_BB(sp))
			return (do_b(ap, params));
		else if (I_N(sp))
			return (do_n(va_arg(*ap, int*)));
	}
	// else if (I_FL(sp) || I_FL2(sp))
	// 	return (do_fl(ap, params));
	else if (I_CH(sp))
		return (do_c(ap, params));
	return (g_print.error = -1);
}

int		parse_prms(const char **format, va_list *ap, t_format *params)
{
	while (!CHK_C(**format))
	{
		if (CHK_F(**format))
			get_flag(format, params);
		else if (CHK_W(**format))
			get_width(format, ap, params);
		else if (CHK_A(**format))
			get_acc(format, ap, params);
		else if (CHK_M(**format))
			get_mod(format, params);
		else if (**format)
			return (do_c_wm(*(*format)++, params));
		else
			return (0);
	}
	params->spec = **format;
	if (I_BD(**format) || I_BU(**format) || I_BO(**format))
		params->mod = J;
	++(*format);
	return (do_format(ap, params));
}

void	check_frmt(const char **format, va_list *ap)
{
	t_format params;

	while (**format)
	{
		if (**format == '%')
		{
			init_params(&params);
			++(*format);
			if (**format == '%')
			{
				char_to_buf('%', 1);
				++(*format);
			}
			else if (**format)
				if (parse_prms(format, ap, &params) == -1)
					return ;
		}
		else
		{
			char_to_buf(**format, 1);
			++(*format);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	g_print.print = 0;
	g_print.error = 0;
	g_print.len = 0;
	g_print.fd = 1;
	va_start(ap, format);
	check_frmt(&format, &ap);
	print_buf();
	va_end(ap);
	return (g_print.error ? -1 : g_print.print);
}
