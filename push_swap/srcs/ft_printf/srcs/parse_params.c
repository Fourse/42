/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:11:46 by smorty            #+#    #+#             */
/*   Updated: 2019/06/23 11:47:18 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_flag(const char **format, int *flags)
{
	if (**format == '-')
	{
		*flags |= F_MINUS;
		if (*flags & F_ZERO)
			*flags ^= F_ZERO;
	}
	else if (**format == '+')
		*flags |= F_PLUS;
	else if (**format == ' ')
		*flags |= F_SPACE;
	else if (**format == '#')
		*flags |= F_HASH;
	else if (**format == '0' && !(*flags & F_MINUS))
		*flags |= F_ZERO;
	++(*format);
}

static void		get_mod(const char **format, t_frmt *prm)
{
	if (**format == 'L')
		prm->flags |= F_LONGD;
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		++(*format);
		if (prm->mod < HH)
			prm->mod = HH;
	}
	else if (**format == 'h' && prm->mod < H)
		prm->mod = H;
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		++(*format);
		if (prm->mod < LL)
			prm->mod = LL;
	}
	else if (**format == 'l' && prm->mod < L)
		prm->mod = L;
	else if (**format == 'z' && prm->mod < Z)
		prm->mod = Z;
	else if (**format == 'j')
		prm->mod = J;
	++(*format);
}

static void		get_precision(const char **format, va_list *argp, t_frmt *prm)
{
	++(*format);
	if (**format == '*')
	{
		prm->precision = va_arg(*argp, int);
		++(*format);
	}
	else
	{
		prm->precision = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			++(*format);
	}
	if (prm->precision < 0)
		prm->precision = 1;
	else
		prm->flags |= F_PREC;
}

static void		get_width(const char **format, va_list *argp, t_frmt *prm)
{
	if (**format == '*')
	{
		prm->width = va_arg(*argp, int);
		if (prm->width < 0)
		{
			prm->width = ~prm->width + 1;
			prm->flags |= F_MINUS;
		}
		++(*format);
	}
	else
	{
		prm->width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			++(*format);
	}
}

int				parse_params(const char **format, va_list *argp, t_frmt prm)
{
	while (!SPEC(**format))
	{
		if (FLAG(**format))
			get_flag(format, &prm.flags);
		else if ((**format >= '1' && **format <= '9') || **format == '*')
			get_width(format, argp, &prm);
		else if (**format == '.')
			get_precision(format, argp, &prm);
		else if (MOD(**format))
			get_mod(format, &prm);
		else if (**format)
			return (process_c(*(*format)++, &prm));
		else
			return (0);
	}
	prm.spec = **format;
	if (**format == 'D' || **format == 'U' || **format == 'O')
		prm.mod = J;
	++(*format);
	return (process_format(argp, &prm));
}
