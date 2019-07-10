/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/10 18:38:16 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_fl_wm(t_floats ret_union, t_format *params)
{

	return (0);
}

char	*load_tmp(t_floats *ret_union, t_format *params)
{
	char	*tmp;
	char	*tmp_end;
	int		size;
	int		exp;
	int		i;

	exp = ret_union->bits.exp;
	size = 65 > ft_abs(exp) ? 72 + params->acc : ft_abs(exp) + params->acc + 7;
	tmp = (char*)malloc(sizeof(int) * (size + 1));
	ft_bzero(tmp, sizeof(int) * (size + 1));
	tmp_end = tmp + size;
	size = 63;
	i = 64;
	while (size-- >= 0)
	{
		tmp[size] = ret_union->bits.mantis >> i & 1;
	}
	return (tmp);
}

int		inf_nan(t_floats *ret_union, t_format *params)
{
	if (params->flag & ACC)
		params->flag ^= ACC;
	if (params->flag & ZERO)
		params->flag ^= ZERO;
	if (!(ret_union->bits.mantis << 1))
	{
		if (ret_union->bits.sign)
			return (do_s_wm((params->spec > 96 ? "-inf" : "-INF"), params));
		else if (params->flag & PLUS)
			return (do_s_wm((params->spec > 96 ? "-inf" : "+INF"), params));
		else if (params->flag & SPACE)
			return (do_s_wm((params->spec > 96 ? " inf" : " INF"), params));
	}
	return (do_s_wm((params->spec > 96 ? "nan" : "NAN"), params));
}

int		do_fl(va_list *ap, t_format *params)
{
	t_floats	ret_union;
	char		*tmp;

	if (!(params->acc & ACC))
		params->acc = 6;
	if (params->flag & LONGD)
		ret_union.ret = va_arg(*ap, long double);
	else
		ret_union.ret = va_arg(*ap, double);
	ret_union.bits.exp -= 16383;
	if (ret_union.bits.exp == 16384)
		return (inf_nan(&ret_union, params));
	tmp = load_tmp(&ret_union, params);
	return (do_fl_wm(ret_union, params));
}
