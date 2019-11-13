/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_type_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:17:26 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:17:31 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == '%' ||
		c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'U' ||
		c == 'D' || c == 'O' || c == 'f' || c == 'F')
		return (1);
	else
		return (0);
}

int	ft_issize(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	else
		return (0);
}
