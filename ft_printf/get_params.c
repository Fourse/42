/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:51:18 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 18:09:17 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_mod(const char **format, t_format *params)
{
	if (**format == 'L')
		params->flag |= LONGD;
	else if (**format == 'h' && *(*format + 1) == 'h')
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

void	get_acc(const char **format, va_list *ap, t_format *params)
{
	++(*format);
	params->acc = ft_atoi(*format);
	while (ft_isdigit(**format))
		++(*format);
	if (params->acc < 0)
		params->acc = 1;
	else
		params->flag |= ACC;
}

void	get_width(const char **format, va_list *ap, t_format *params)
{
	params->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		++(*format);
}

void	get_flag(const char **format, t_format *params)
{
	if (**format == '-')
	{
		params->flag |= MINUS;
		if (params->flag & ZERO)
			params->flag ^= ZERO;
	}
	else if (**format == '+')
		params->flag |= PLUS;
	else if (**format == ' ')
		params->flag |= SPACE;
	else if (**format == '#')
		params->flag |= HASH;
	else if (**format == '0' && !(params->flag & MINUS))
		params->flag |= ZERO;
	++(*format);
}
