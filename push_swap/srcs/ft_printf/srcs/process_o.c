/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:58:45 by smorty            #+#    #+#             */
/*   Updated: 2019/05/31 23:25:45 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	otoa(char **out, uintmax_t n, int *precision)
{
	while (n)
	{
		**out = n % 8 + '0';
		n /= 8;
		--(*out);
		--(*precision);
	}
}

static int	process_o_mod(uintmax_t n, t_frmt *prm)
{
	char	*out;
	char	*out0;
	char	*width;
	int		size;

	size = MAX(prm->precision, 23) + 1;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (g_ftprintf.error = -1);
	out0 = out;
	out += size;
	*out-- = 0;
	if (n)
		otoa(&out, n, &prm->precision);
	while (prm->precision-- > 0)
		*out-- = '0';
	if (prm->flags & F_HASH && *(out + 1) != '0')
		*out-- = '0';
	prm->len = ft_strlen(out + 1);
	width = NULL;
	if (prm->width > prm->len)
		if (!(width = make_width(prm)))
			return (g_ftprintf.error = -1);
	to_print(out + 1, width, prm);
	free(out0);
	return (0);
}

int			process_o(va_list *argp, t_frmt *prm)
{
	if (prm->flags & F_ZERO && prm->width > prm->precision)
		prm->precision = prm->width - 1;
	if (prm->mod == HH)
		return (process_o_mod((unsigned char)va_arg(*argp, int), prm));
	else if (prm->mod == H)
		return (process_o_mod((unsigned short)va_arg(*argp, int), prm));
	else if (prm->mod == NO)
		return (process_o_mod(va_arg(*argp, unsigned int), prm));
	else if (prm->mod == L)
		return (process_o_mod(va_arg(*argp, unsigned long), prm));
	else if (prm->mod == LL)
		return (process_o_mod(va_arg(*argp, unsigned long long), prm));
	else if (prm->mod == Z)
		return (process_o_mod(va_arg(*argp, size_t), prm));
	else if (prm->mod == J)
		return (process_o_mod(va_arg(*argp, uintmax_t), prm));
	return (g_ftprintf.error = -1);
}
