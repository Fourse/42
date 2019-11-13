/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_inf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:16:56 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:17:04 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_float_plus_inf(t_format *lst, char type)
{
	if (type == 'f')
		ft_putstr("inf");
	else
		ft_putstr("INF");
	lst->len_str = 3;
}

void	ft_float_minus_inf(t_format *lst, char type)
{
	if (type == 'f')
		ft_putstr("-inf");
	else
		ft_putstr("-INF");
	lst->len_str = 4;
}

void	ft_float_nan(t_format *lst, char type)
{
	if (type == 'f')
		ft_putstr("nan");
	else
		ft_putstr("NAN");
	lst->len_str = 3;
}

int		ft_float_inf(t_format *lst, long double arg, char type)
{
	if (arg == 1.0 / 0.0)
	{
		ft_float_plus_inf(lst, type);
		return (1);
	}
	if (arg == -1.0 / 0.0)
	{
		ft_float_minus_inf(lst, type);
		return (1);
	}
	if (arg != arg)
	{
		ft_float_nan(lst, type);
		return (1);
	}
	return (0);
}
