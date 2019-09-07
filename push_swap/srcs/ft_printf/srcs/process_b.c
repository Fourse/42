/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:24:09 by smorty            #+#    #+#             */
/*   Updated: 2019/06/05 16:33:37 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	btoa(char **out, uintmax_t n, int *precision)
{
	while (n)
	{
		**out = n % 2 + '0';
		n /= 2;
		--(*out);
		--(*precision);
	}
}

static int	prefix_b(char *out, int n_is_zero, t_frmt *prm)
{
	if (!n_is_zero && prm->flags & F_HASH)
	{
		*out-- = prm->spec;
		*out = '0';
		return (1);
	}
	return (-1);
}

static int	process_b_mod(uintmax_t n, t_frmt *prm)
{
	char	*out;
	char	*out0;
	char	*width;
	int		size;

	size = MAX(prm->precision, 64) + 2;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (g_ftprintf.error = -1);
	out0 = out;
	out += size;
	*out-- = 0;
	if (n)
		btoa(&out, n, &prm->precision);
	while (prm->precision-- > 0)
		*out-- = '0';
	out -= prefix_b(out, (!n), prm);
	prm->len = ft_strlen(out);
	width = NULL;
	if (prm->width > prm->len)
		if (!(width = make_width(prm)))
			return (g_ftprintf.error = -1);
	to_print(out, width, prm);
	free(out0);
	return (0);
}

int			process_b(va_list *argp, t_frmt *prm)
{
	if (prm->flags & F_ZERO && prm->width > prm->precision)
		prm->precision = prm->width - 2;
	if (prm->mod == HH)
		return (process_b_mod((unsigned char)va_arg(*argp, int), prm));
	else if (prm->mod == H)
		return (process_b_mod((unsigned short)va_arg(*argp, int), prm));
	else if (prm->mod == NO)
		return (process_b_mod(va_arg(*argp, unsigned int), prm));
	else if (prm->mod == L)
		return (process_b_mod(va_arg(*argp, unsigned long), prm));
	else if (prm->mod == LL)
		return (process_b_mod(va_arg(*argp, unsigned long long), prm));
	else if (prm->mod == Z)
		return (process_b_mod(va_arg(*argp, size_t), prm));
	else if (prm->mod == J)
		return (process_b_mod(va_arg(*argp, uintmax_t), prm));
	return (-1);
}
