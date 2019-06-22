/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:51:18 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/22 14:56:37 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_mod(const char **format, t_format *params)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		++(*format);
		if (params->mod < HH)
			params->mod = HH;
	}
	else if (**format == 'h' && params->mod < H)
		params->mod = H;
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		++(*format);
		if (params->mod < LL)
			params->mod = LL;
	}
	else if (**format == 'l' && params->mod < L)
		params->mod = L;
	else if (**format == 'z' && params->mod < Z)
		params->mod = Z;
	else if (**format == 'j')
		params->mod = J;
	++(*format);
}

void	get_acc(const char **format, va_list ap, t_format *params)
{
	++(*format);
	params->acc = ft_atoi(*format);
	while (ft_isdigit(**format))
		++(*format);
}

void	get_width(const char **format, va_list ap, t_format *params)
{
	params->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		++(*format);
}

void	get_flag(const char **format, t_format *params)
{
	if (**format == '-')
		params->flag = '-';
	else if (**format == '+')
		params->flag = '+';
	else if (**format == ' ')
		params->flag = ' ';
	else if (**format == '#')
		params->flag = '#';
	else if (**format == '0')
		params->flag = '0';
	++(*format);
}

int		parse_paramss(const char **format, va_list ap, t_format *params)
{
	while (!CHK_C(*format))
	{
		if (CHK_F(*format))
			get_flag(format, params);
		else if (CHK_W(*format))
			get_width(format, ap, params);
		else if (CHK_A(*format))
			get_acc(format, ap, params);
		else if (CHK_M(*format))
			get_mod(format, params);
		else if (**format)
			return (do_c(*(format)++, params));
		else
			return (0);
	}
	params->spec = **format;
	++(*format);
	return (do_format(ap, params));
}
