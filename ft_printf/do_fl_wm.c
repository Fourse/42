/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl_wm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:15:42 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/20 18:27:04 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	suff_float(char *tmp, int e, t_format *params)
{
	int r;

	*tmp++ = params->spec + (I_A(params->spec) || I_BA(params->spec)) * 15;
	*tmp++ = (e < 0 ? '-' : '+');
	if (e < 0)
		e = ~e + 1;
	if (e < 10 && !(I_A(params->spec)) && !(I_BA(params->spec)))
		*tmp++ = '0';
	if (!e)
		*tmp++ = '0';
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
			*tmp++ = r % 10 + '0';
			r /= 10;
		}
	}
	*tmp = 0;
}

int		trim_zeros(char *tmp)
{
	int cur;

	cur = 0;
	while (*tmp == '0')
	{
		*tmp-- = 0;
		++cur;
	}
	if (*tmp == '.')
	{
		*tmp = 0;
		++cur;
	}
	return (cur);
}

void	round_efg(char *dot, char *end)
{
	char	*p;
	int		diff;

	if (*end >= '5')
	{
		diff = 1;
		if (*end == '5' && !(*(end - (*(end - 1) == '.' ? 2 : 1)) % 2))
		{
			p = end + 1;
			while (*p == '0')
				++p;
			if (!*p)
				diff = 0;
		}
		while (diff && --end > dot)
			if (++(*end) > '9')
				*end = '0';
			else
				diff = 0;
		while (diff && --end)
			if (++(*end) > '9')
				*end = '0';
			else
				diff = 0;
	}
}

char	*shift_dot(char *dot, int *e, t_format *params)
{
	int i;

	i = *e;
	while (i > 0)
	{
		*dot = *(dot - 1);
		--dot;
		--i;
	}
	while (i < 0)
	{
		*dot = *(dot + 1);
		++dot;
		++i;
	}
	*dot = '.';
	i = (*dot - 1);
	round_efg(dot, dot + params->acc + 1);
	if (i == '9' && *(dot - 1) == '0')
	{
		*dot-- = '0';
		*dot = '.';
		++(*e);
	}
	return (dot);
}

int		chk_g(int e, t_format *params)
{
	int choice;

	choice = 0;
	if (!params->acc)
		++params->acc;
	if (e < params->acc && e >= -4)
		params->acc -= e;
	else
		++choice;
	++choice;
	--params->acc;
	return (choice);
}
