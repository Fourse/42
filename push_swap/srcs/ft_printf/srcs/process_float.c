/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:37:10 by smorty            #+#    #+#             */
/*   Updated: 2019/07/19 16:11:59 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "floats.h"

void		suffix_float(char *out, int e, int spec)
{
	int r;

	*out++ = spec + (spec == 'a' || spec == 'A') * 15;
	*out++ = (e < 0 ? '-' : '+');
	if (e < 0)
		e = ~e + 1;
	if (e < 10 && spec != 'a' && spec != 'A')
		*out++ = '0';
	if (!e)
		*out++ = '0';
	else
	{
		r = 1;
		while (e)
		{
			r = r * 10 + e % 10;
			e /= 10;
		}
		while (r != 1)
		{
			*out++ = r % 10 + '0';
			r /= 10;
		}
	}
	*out = 0;
}

static int	nan_or_inf(t_ld *nb, t_frmt *prm)
{
	if (prm->flags & F_PREC)
		(prm->flags ^= F_PREC);
	if (prm->flags & F_ZERO)
		(prm->flags ^= F_ZERO);
	if (!(nb->mantissa << 1))
	{
		if (nb->sign)
			return (process_s((prm->spec > 96 ? "-inf" : "-INF"), prm));
		else if (prm->flags & F_PLUS)
			return (process_s((prm->spec > 96 ? "+inf" : "+INF"), prm));
		else if (prm->flags & F_SPACE)
			return (process_s((prm->spec > 96 ? " inf" : " INF"), prm));
		return (process_s((prm->spec > 96 ? "inf" : "INF"), prm));
	}
	return (process_s((prm->spec > 96 ? "nan" : "NAN"), prm));
}

static char	*ftoa(t_ld *nb, t_frmt *prm)
{
	char	*dot;
	char	*out;
	char	*out_end;
	int		size;
	int		exponent;

	exponent = nb->exponent;
	size = MAX(65, ABS(exponent)) + prm->precision + 7;
	out = (char *)malloc(sizeof(int) * (size + 1));
	ft_bzero(out, sizeof(int) * (size + 1));
	out_end = out + size;
	dot = out + (exponent > 0 ? exponent : 2);
	*dot = '.';
	size = 63;
	while (size >= 0)
	{
		if (nb->mantissa & (1L << size))
			power2(dot, exponent);
		--exponent;
		--size;
	}
	while (out_end >= out)
		*out_end-- += '0';
	*dot = '.';
	return (out);
}

static int	get_exponent(char *out)
{
	int e;

	e = 0;
	while (*out == '0')
		++out;
	if (*out++ == '.')
	{
		--e;
		while (*out++ == '0')
			--e;
		if (!*out)
			return (0);
	}
	else
		while (*out++ != '.')
			++e;
	return (e);
}

int			process_float(va_list *argp, t_frmt *prm)
{
	t_bits	nb_union;
	t_ld	nb;
	char	*out;
	int		e;

	if (!(prm->flags & F_PREC))
		prm->precision = 6;
	if (prm->flags & F_LONGD)
		nb_union.l = va_arg(*argp, long double);
	else
		nb_union.l = va_arg(*argp, double);
	nb.exponent = nb_union.lsh[4] - 16383;
	nb.mantissa = *(uint64_t *)&nb_union.l;
	nb.sign = nb_union.lsh[4] >> 15;
	if (nb.exponent == -0x4000)
		return (nan_or_inf(&nb, prm));
	if (prm->spec == 'a' || prm->spec == 'A')
		return (process_a(nb_union.l, nb.sign, prm));
	out = ftoa(&nb, prm);
	e = get_exponent(out);
	return (process_efg(out, prm, e, nb.sign));
}
