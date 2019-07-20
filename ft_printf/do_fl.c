/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/20 18:26:14 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_fl_wm(char *tmp, t_format *params, int e, int sign)
{
	char	*dot;

	dot = tmp;
	while (*dot != '.')
		++dot;
	if (I_G(params->spec) || I_BG(params->spec))
		params->spec -= chk_g(e, params);
	if (I_E(params->spec) || I_BE(params->spec))
		dot = shift_dot(dot, &e, params);
	else
		round_efg(dot, dot + params->acc + 1);
	if ((I_G(params->spec) || I_BG(params->spec)) && !(params->flag & HASH))
		params->acc -= trim_zeros(dot + params->acc);
	dot += (params->acc ? params->acc + 1 : params->flag & HASH);
	if (I_E(params->spec) || I_BE(params->spec))
		suff_float(dot, e, params);
	else
		*dot = 0;
	return (do_fl_wm2(tmp, params, sign));
}

int		get_exp(char *tmp)
{
	int e;

	e = 0;
	while (*tmp == '0')
		++tmp;
	if (*tmp++ == '.')
	{
		--e;
		while (*tmp++ == '0')
			--e;
		if (!tmp)
			return (0);
	}
	else
		while (*tmp++ != '.')
			++e;
	return (e);
}

char	*load_tmp(t_floats *ret_union, t_format *params)
{
	char	*tmp;
	char	*tmp_end;
	char	*dot;
	int		size;
	int		exp;

	exp = ret_union->bits.exp;
	size = 65 > ft_abs(exp) ? 72 + params->acc : ft_abs(exp) + 7 + params->acc;
	tmp = (char*)malloc(sizeof(int) * (size + 1));
	ft_bzero(tmp, sizeof(int) * (size + 1));
	tmp_end = tmp + size;
	dot = tmp + (exp > 0 ? exp : 2);
	size = 64;
	while (--size >= 0)
	{
		if ((ret_union->bits.mantis >> size) & 1)
			power_of(dot, exp);
		--exp;
	}
	while (tmp_end >= tmp)
		*tmp_end-- += '0';
	*dot = '.';
	return (tmp);
}

int		innan(t_floats *ret_union, t_format *params)
{
	if (params->flag & ACC)
		params->flag ^= ACC;
	if (params->flag & ZERO)
		params->flag ^= ZERO;
	if (!(ret_union->bits.exp << 1))
	{
		if (ret_union->bits.sign)
			return (do_s_wm((params->spec > 96 ? "-inf" : "-INF"), params));
		else if (params->flag & PLUS)
			return (do_s_wm((params->spec > 96 ? "+inf" : "+INF"), params));
		else if (params->flag & SPACE)
			return (do_s_wm((params->spec > 96 ? " inf" : " INF"), params));
	}
	return (do_s_wm((params->spec > 96 ? "nan" : "NAN"), params));
}

int		do_fl(va_list *ap, t_format *params)
{
	t_floats	ret_union;
	char		*tmp;
	int			e;

	if (!(params->acc & ACC))
		params->acc = 6;
	if (params->flag & LONGD)
		ret_union.ret = va_arg(*ap, long double);
	else
		ret_union.ret = va_arg(*ap, double);
	ret_union.bits.exp -= 16383;
	if (ret_union.bits.exp == 16384)
		return (innan(&ret_union, params));
	if (I_A(params->spec) || I_BA(params->spec))
		return (do_a_wm(ret_union.ret, ret_union.bits.sign, params));
	tmp = load_tmp(&ret_union, params);
	e = get_exp(tmp);
	return (do_fl_wm(tmp, params, e, ret_union.bits.sign));
}
