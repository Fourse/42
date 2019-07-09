/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/09 18:02:53 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		do_fl_wm(t_floats ret_union, t_format *params)
{
	return (0);
}*/

int		infnan(t_floats *ret_union, t_format *params)
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

	if (!(params->acc & ACC))
		params->acc = 6;
	if (params->flag & LONGD)
		ret_union.ret = va_arg(*ap, long double);
	else
		ret_union.ret = va_arg(*ap, double);
	ret_union.bits.exp -= 16383;
	ret_union.bits.mantis = *(uint64_t*)&ret_union.ret;
	if (ret_union.bits.exp == 16384)
		return (infnan(&ret_union, params));	
	//return (do_fl_wm(ret_union, params));
	return (0);
}
