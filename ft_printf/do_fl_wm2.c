/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl_wm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:35:52 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/20 17:38:55 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int		chk_fl_for_fl(char *tmp, int sign, t_format *params)
{
	if (sign)
	{
		*tmp = '-';
		return (1);
	}
	else if (params->flag & PLUS)
	{
		*tmp = '+';
		return (1);
	}
	else if (params->flag & SPACE)
	{
		*tmp = ' ';
		return (1);
	}
	return (0);
}

int		do_fl_wm2(char *tmp, t_format *params, int sign)
{
	char *dot;
	char *width;

	dot = tmp;
	while (*dot == '0')
		++dot;
	if (*dot < '0' || *dot > '9')
		--dot;
	params->len = ft_strlen(dot);
	width = NULL;
	if (params->width > (int)params->len)
		if (!(width = make_width(params)))
			return (g_print.error = -1);
	if (width && params->flag & ZERO)
		chk_fl_for_fl(width, sign, params);
	else if (chk_fl_for_fl(dot - 1, sign, params))
	{
		--dot;
		++params->len;
		--params->width;
	}
	to_print(dot, width, params);
	free(tmp);
	return (0);
}
