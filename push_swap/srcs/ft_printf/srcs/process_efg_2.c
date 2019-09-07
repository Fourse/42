/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_efg_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:14:14 by smorty            #+#    #+#             */
/*   Updated: 2019/06/05 19:57:43 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "floats.h"

static int	prefix_efg(char *out, int sign, int flags)
{
	if (sign)
	{
		*out = '-';
		return (1);
	}
	else if (flags & F_PLUS)
	{
		*out = '+';
		return (1);
	}
	else if (flags & F_SPACE)
	{
		*out = ' ';
		return (1);
	}
	return (0);
}

int			process_efg_2(char *out, t_frmt *prm, int sign)
{
	char *dot;
	char *width;

	dot = out;
	while (*dot == '0')
		++dot;
	if (*dot < '0' || *dot > '9')
		--dot;
	prm->len = ft_strlen(dot);
	width = NULL;
	if (prm->width > prm->len)
		if (!(width = make_width(prm)))
			return (g_ftprintf.error = -1);
	if (width && prm->flags & F_ZERO)
		prefix_efg(width, sign, prm->flags);
	else if (prefix_efg(dot - 1, sign, prm->flags))
	{
		--dot;
		++prm->len;
		--prm->width;
	}
	to_print(dot, width, prm);
	free(out);
	return (0);
}
