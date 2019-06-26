/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:34:57 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 15:21:19 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_d_wm(intmax_t ret, t_format *params)
{
	char	*tmp;
	int		size;

	if (params->width == 0)
		size = ft_count(ret);
	else
		size = params->width;
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (g_print.print = 0);
	return (1);
}

int	do_d(va_list *ap, t_format *params)
{
	if (params->mod == NO)
		return (do_d_wm(va_arg(*ap, int), params));
	else if (params->mod == HH)
		return (do_d_wm((char)va_arg(*ap, int), params));
	else if (params->mod == H)
		return (do_d_wm((short)va_arg(*ap, int), params));
	else if (params->mod == L)
		return (do_d_wm(va_arg(*ap, long), params));
	else if (params->mod == LL)
		return (do_d_wm(va_arg(*ap, long long), params));
	else if (params->mod == Z)
		return (do_d_wm(va_arg(*ap, ssize_t), params));
	else if (params->mod == J)
		return (do_d_wm(va_arg(*ap, intmax_t), params));
	return (0);
}
