/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:27:56 by smorty            #+#    #+#             */
/*   Updated: 2019/05/31 23:20:38 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	xtoa(char **s, uintmax_t n, t_frmt *prm)
{
	int spec;

	spec = (prm->spec > 'a' ? 87 : 55);
	while (n)
	{
		**s = n % 16;
		**s += (**s > 9 ? spec : '0');
		n /= 16;
		--(*s);
		--prm->precision;
	}
}

static int	prefix_x(char *s, int n_is_zero, t_frmt *prm)
{
	if (prm->spec == 'p')
	{
		*s-- = 'x';
		*s = '0';
	}
	else if (!n_is_zero && prm->flags & F_HASH)
	{
		*s-- = prm->spec;
		*s = '0';
	}
	else
		return (-1);
	return (1);
}

static int	process_x_mod(uintmax_t n, t_frmt *prm)
{
	char	*out;
	char	*out0;
	char	*width;
	int		size;

	size = MAX(prm->precision, 16) + 2;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (g_ftprintf.error = -1);
	out0 = out;
	out += size;
	*out-- = 0;
	if (n)
		xtoa(&out, n, prm);
	while (prm->precision-- > 0)
		*out-- = '0';
	out -= prefix_x(out, (!n), prm);
	prm->len = ft_strlen(out);
	width = NULL;
	if (prm->width > prm->len)
		if (!(width = make_width(prm)))
			return (g_ftprintf.error = -1);
	to_print(out, width, prm);
	free(out0);
	return (0);
}

int			process_x(va_list *argp, t_frmt *prm)
{
	if (prm->flags & F_ZERO && prm->width > prm->precision)
		prm->precision = prm->width - 2;
	if (prm->spec == 'p')
	{
		prm->flags |= F_HASH;
		return (process_x_mod(va_arg(*argp, intptr_t), prm));
	}
	else if (prm->mod == HH)
		return (process_x_mod((unsigned char)va_arg(*argp, int), prm));
	else if (prm->mod == H)
		return (process_x_mod((unsigned short)va_arg(*argp, int), prm));
	else if (prm->mod == NO)
		return (process_x_mod(va_arg(*argp, unsigned int), prm));
	else if (prm->mod == L)
		return (process_x_mod(va_arg(*argp, unsigned long), prm));
	else if (prm->mod == LL)
		return (process_x_mod(va_arg(*argp, unsigned long long), prm));
	else if (prm->mod == Z)
		return (process_x_mod(va_arg(*argp, size_t), prm));
	else if (prm->mod == J)
		return (process_x_mod(va_arg(*argp, uintmax_t), prm));
	return (g_ftprintf.error = -1);
}
