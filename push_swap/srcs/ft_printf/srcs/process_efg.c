/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_efg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:18:09 by smorty            #+#    #+#             */
/*   Updated: 2019/06/05 19:58:12 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "floats.h"

static int	check_g(int e, int *precision)
{
	int choice;

	choice = 0;
	if (!*precision)
		++(*precision);
	if (e < *precision && e >= -4)
		*precision -= e;
	else
		++choice;
	++choice;
	--(*precision);
	return (choice);
}

static void	round_efg(char *dot, char *end)
{
	char	*p;
	int		dif;

	if (*end >= '5')
	{
		dif = 1;
		if (*end == '5' && !(*(end - (*(end - 1) == '.' ? 2 : 1)) % 2))
		{
			p = end + 1;
			while (*p == '0')
				++p;
			if (!*p)
				dif = 0;
		}
		while (dif && --end > dot)
			if (++(*end) > '9')
				*end = '0';
			else
				dif = 0;
		while (dif && --end)
			if (++(*end) > '9')
				*end = '0';
			else
				dif = 0;
	}
}

static char	*shift_dot(char *dot, int *e, int precision)
{
	int	i;

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
	i = *(dot - 1);
	round_efg(dot, dot + precision + 1);
	if (i == '9' && *(dot - 1) == '0')
	{
		*dot-- = '0';
		*dot = '.';
		++(*e);
	}
	return (dot);
}

static int	trim_zeros(char *out)
{
	int cut;

	cut = 0;
	while (*out == '0')
	{
		*out-- = 0;
		++cut;
	}
	if (*out == '.')
	{
		*out = 0;
		++cut;
	}
	return (cut);
}

int			process_efg(char *out, t_frmt *prm, int e, int sign)
{
	char	*dot;
	int		spec;

	spec = prm->spec;
	dot = out;
	while (*dot != '.')
		++dot;
	if (spec == 'g' || spec == 'G')
		spec -= check_g(e, &prm->precision);
	if (spec == 'e' || spec == 'E')
		dot = shift_dot(dot, &e, prm->precision);
	else
		round_efg(dot, dot + prm->precision + 1);
	if ((prm->spec == 'g' || prm->spec == 'G') && !(prm->flags & F_HASH))
		prm->precision -= trim_zeros(dot + prm->precision);
	dot += (prm->precision ? prm->precision + 1 : prm->flags & F_HASH);
	if (spec == 'e' || spec == 'E')
		suffix_float(dot, e, spec);
	else
		*dot = 0;
	return (process_efg_2(out, prm, sign));
}
