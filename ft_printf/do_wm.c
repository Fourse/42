/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:49:39 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/30 14:27:49 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SCROLL(tmp, prms) --(*tmp); --prms->acc
#define CHK_FL_FOR(a) I_I(a) || I_D(a) || I_D(a) || I_X(a) || I_BX(a) || I_P(a)
#define ELSE_R1 else return(-1);
#define EQU(a, b, size) a = b; b += size; *b-- = 0;
#define SMTH(a, b) *a-- = b; *a = '0';
#define NOTU(a) (I_D(a) || I_BD(a) || I_I(a))

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

void	do_itoa(char **tmp, uintmax_t n, t_format *prms, int base)
{
	int sp;

	if ((intmax_t)n < 0 && (NOTU(prms->spec)))
	{
		**tmp = (intmax_t)n % base * -1 + '0';
		n = ~((intmax_t)n / base) + 1;
		SCROLL(tmp, prms);
	}
	while (n)
	{
		if (base == 16)
		{
			sp = (prms->spec > 'a' ? 87 : 55);
			**tmp = n % base;
			**tmp += (**tmp > 9 ? sp : '0');
			n /= base;
			SCROLL(tmp, prms);
		}
		else
		{
			**tmp = n % base + '0';
			n /= base;
			SCROLL(tmp, prms);
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
		ELSE_R1;
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
		ELSE_R1;
		return (1);
	}
	return (g_print.print = -1);
}

int		init_size_len(t_format *params, char *tmp, int check)
{
	if (check == 1)
	{
		if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
			return (params->acc > 20 ? params->acc + 1 : 21);
		else if (I_U(params->spec) || I_BU(params->spec))
			return (params->acc > 20 ? params->acc : 20);
		else if (I_O(params->spec) || I_BO(params->spec))
			return (params->acc > 23 ? params->acc + 1 : 24);
		else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
			return (params->acc > 16 ? params->acc + 2 : 18);
	}
	else if (check == 2)
	{
		if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
			return (ft_strlen(tmp));
		else if (I_U(params->spec) || I_BU(params->spec))
			return (ft_strlen(tmp + 1));
		else if (I_O(params->spec) || I_BO(params->spec))
			return (ft_strlen(tmp + 1));
		else if (I_X(params->spec) || I_BX(params->spec) || I_P(params->spec))
			return (ft_strlen(tmp));
	}
	return (g_print.print = -1);
}

int		do_wm(uintmax_t ret, t_format *params, int base)
{
	char	*tmp;
	char	*tmptmp;
	char	*width;
	int		size;

	if (I_D(params->spec) || I_BD(params->spec) || I_I(params->spec))
		ret = (intmax_t)ret;
	size = init_size_len(params, tmp, 1);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (g_print.error = -1);
	EQU(tmptmp, tmp, size);
	if (ret)
		do_itoa(&tmp, ret, params, base);
	while (params->acc-- > 0)
		*tmp-- = '0';
	if (CHK_FL_FOR(params->spec))
		tmp -= chk_fl_for(tmp, ((intmax_t)ret < 0), params, (!ret));
	params->len = init_size_len(params, tmp, 2);
	width = NULL;
	if (params->width > params->len)
		if (!(width = make_width(params)))
			return (g_print.error = -1);
	chk_to_print(tmp, width, params);
	free(tmptmp);
	return (0);
}
