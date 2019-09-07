/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:27:53 by smorty            #+#    #+#             */
/*   Updated: 2019/06/30 13:46:08 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dtoa(char **s, intmax_t n, int *precision)
{
	if (n < 0)
	{
		**s = n % 10 * -1 + '0';
		n = ~(n / 10) + 1;
		--(*s);
		--(*precision);
	}
	while (n)
	{
		**s = n % 10 + '0';
		n /= 10;
		--(*s);
		--(*precision);
	}
}

static int	prefix_d(char *out, int sign, int flags)
{
	if (sign)
		*out = '-';
	else if (flags & F_PLUS)
		*out = '+';
	else if (flags & F_SPACE)
		*out = ' ';
	else
		return (-1);
	return (0);
}

static int	process_d_mod(intmax_t n, t_frmt *prm)
{
	char	*out;
	char	*out0;
	char	*width;
	int		size;

	size = MAX(prm->precision, 20) + 1;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (g_ftprintf.error = -1);
	out0 = out;
	out += size;
	*out-- = 0;
	if (n)
		dtoa(&out, n, &prm->precision);
	while (prm->precision-- > 0)
		*out-- = '0';
	out -= prefix_d(out, (n < 0), prm->flags);
	prm->len = ft_strlen(out);
	width = NULL;
	if (prm->width > prm->len)
		if (!(width = make_width(prm)))
			return (g_ftprintf.error = -1);
	to_print(out, width, prm);
	free(out0);
	return (0);
}

int			process_d(va_list *argp, t_frmt *prm)
{
	if (prm->flags & F_ZERO && prm->width > prm->precision)
		prm->precision = prm->width - 1;
	if (prm->mod == HH)
		return (process_d_mod((char)va_arg(*argp, int), prm));
	else if (prm->mod == H)
		return (process_d_mod((short)va_arg(*argp, int), prm));
	else if (prm->mod == NO)
		return (process_d_mod(va_arg(*argp, int), prm));
	else if (prm->mod == L)
		return (process_d_mod(va_arg(*argp, long), prm));
	else if (prm->mod == LL)
		return (process_d_mod(va_arg(*argp, long long), prm));
	else if (prm->mod == Z)
		return (process_d_mod(va_arg(*argp, ssize_t), prm));
	else if (prm->mod == J)
		return (process_d_mod(va_arg(*argp, intmax_t), prm));
	return (-1);
}
