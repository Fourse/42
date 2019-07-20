/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_a_wm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:39:06 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/20 17:59:40 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_exponent(long double *n, int flag_ld)
{
	int p;
	int m;

	p = 0;
	if (*n < 0)
		*n *= -1;
	m = (flag_ld ? 16 : 2);
	while (*n >= m)
	{
		*n /= 2;
		++p;
	}
	m = (flag_ld ? 8 : 1);
	if (*n)
		while (*n < m)
		{
			*n *= 2;
			--p;
		}
	return (p);
}

static int	prefix_a(char *out, int sign, t_format *params)
{
	char *out0;

	out0 = out;
	if (sign)
		*out++ = '-';
	else if (params->flag & PLUS)
		*out++ = '+';
	else if (params->flag & SPACE)
		*out++ = ' ';
	*out++ = '0';
	*out++ = params->spec + 23;
	return (out - out0);
}

static int	round_a(char *s, int spec)
{
	int dif;

	dif = 1;
	while (*--s != '.' && dif)
	{
		*s += (*s == '9' ? spec - '9' : 1);
		if (*s == spec + 6)
			*s = '0';
		else
			dif = 0;
	}
	if (dif)
	{
		--s;
		*s += (*s == '9' ? spec - '9' : 1);
		if (*s == spec + 6)
		{
			*s = '1';
			return (4);
		}
	}
	return (0);
}

static void	floattohex(char *out, long double n, t_format *params)
{
	int p;

	p = get_exponent(&n, params->flag & LONGD);
	*out++ = (int)n + ((int)n > 9 ? params->spec - 10 : '0');
	n -= (int)n;
	*out++ = '.';
	while (n && (params->flag & ACC ? params->acc : 1))
	{
		n *= 16;
		*out++ = (int)n + ((int)n > 9 ? params->spec - 10 : '0');
		n -= (int)n;
		--params->acc;
	}
	if (params->flag & ACC)
	{
		n *= 16;
		while (params->acc--)
			*out++ = '0';
		if ((int)n > 8 || ((int)n == 8 && ((int)(n * 16) % 2)))
			p += round_a(out, params->spec);
	}
	if (*(out - 1) == '.' && !(params->flag & HASH))
		--out;
	chk_fl_for_fl(out, p, params);
}

int			do_a_wm(long double n, int sign, t_format *params)
{
	char *out;
	char *out0;
	char *width;

	if (!(out = (char *)malloc(sizeof(char) * (30 + params->acc))))
		return (g_print.error = -1);
	out0 = out;
	out += prefix_a(out, sign, params);
	floattohex(out, n, params);
	params->len = ft_strlen(out0);
	if (params->flag & ZERO && params->width > (int)params->len)
		params->len = ft_strlen(out);
	width = NULL;
	if (params->width > (int)params->len)
		if (!(width = make_width(params)))
			return (g_print.error = -1);
	if (width && params->flag & ZERO)
		prefix_a(width, sign, params);
	to_print((width && params->flag & ZERO ? out : out0), width, params);
	free(out0);
	return (0);
}
