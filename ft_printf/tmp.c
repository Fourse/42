/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:49:39 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/28 20:50:04 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SCROLL(n, base, tmp, prms) n /= base; --(*tmp); --prms->acc
#define CHK_FL_FOR(a) I_I(a) || I_D(a) || I_D(a) || I_X(a) || I_BX(a) || I_P(a)
#define ELSE_R else return(-1);
#define UI(a) (I_P(a) || I_U(a) || I_BU(a) || I_816(a))
#define EQU(a, b, size) a = b; b += size; *b-- = 0;
#define SMTH(a, b) *a-- = b; *a = '0';

void	do_itoa(char **tmp, intmax_t n, t_format *prms, int base)
{
	int sp;

	if (n < 0 && (prms->spec == 'd' || prms->spec == 'D' || prms->spec == 'i'))
	{
		**tmp = n % base * -1 + '0';
		n = ~(n / base) + 1;
		SCROLL(n, base, tmp, prms);
	}
	while (n)
	{
		sp = (prms->spec > 'a' ? 87 : 55);
		if (base == 16)
		{
			**tmp = n % base;
			**tmp += (**tmp > 9 ? sp : '0');
			SCROLL(n, base, tmp, prms);
		}
		else
		{
			**tmp = n % base + '0';
			SCROLL(n, base, tmp, prms);
		}
	}
}

int		chk_fl_for(char *tmp, int tof, t_format *params, int zero)
{
	if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
	{
		if (tof)
			*tmp = '-';
		else if (params->flag & PLUS)
			*tmp = '+';
		else if (params->flag & SPACE)
			*tmp = ' ';
		ELSE_R;
		return (0);
	}
	else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
	{
		if (I_P(params->spec))
		{
			SMTH(tmp, 'x');
		}
		else if (!zero && params->flag & HASH)
		{
			SMTH(tmp, params->spec);
		}
		ELSE_R;
		return (0);
	}
	return (0);
}

int		init_len(char *tmp, t_format *params)
{
	if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
		return (ft_strlen(tmp));
	else if (I_U(params->spec) || I_BU(params->spec))
		return (ft_strlen(tmp + 1));
	else if (I_O(params->spec) || I_BO(params->spec))
		return (ft_strlen(tmp + 1));
	else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
		return (ft_strlen(tmp));
	else
		return (0);
}

int		init_size(t_format *params)
{
	if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
		return (21);
	else if (I_U(params->spec) || I_BU(params->spec))
		return (20);
	else if (I_O(params->spec) || I_BO(params->spec))
		return (24);
	else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
		return (18);
	else
		return (0);
}

void	chk_to_print(char *tmp, char *width, t_format *params)
{
	if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
		to_print(tmp, width, params);
	else if (I_U(params->spec) || I_BU(params->spec))
		to_print(tmp + 1, width, params);
	else if (I_O(params->spec) || I_BO(params->spec))
		to_print(tmp + 1, width, params);
	else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
		to_print(tmp, width, params);
}

int		do_wm(intmax_t ret, t_format *params, int base)
{
	char	*tmp;
	char	*tmptmp;
	char	*width;
	int		size;

	if (UI(params->spec))
		ret = (uintmax_t)ret;
	size = init_size(params);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (g_print.error = 0);
	EQU(tmptmp, tmp, size);
	if (ret)
		do_itoa(&tmp, ret, params, base);
	while (params->acc-- > 0)
		*tmp-- = '0';
	if (CHK_FL_FOR(params->spec))
		tmp -= chk_fl_for(tmp, (ret < 0), params, (!ret));
	params->len = init_len(tmp, params);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = 0);
	chk_to_print(tmp, width, params);
	free(tmptmp);
	return (1);
}
