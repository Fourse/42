/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:25:33 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:41:46 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_width(char *c, t_format *lst, va_list lst_arg)
{
	int i;

	i = 0;
	if (*c == '*')
	{
		lst->width = va_arg(lst_arg, int);
		if (lst->width < 0)
		{
			lst->width = lst->width * -1;
			lst->flag[0] = '-';
		}
		i = 1;
	}
	else
	{
		lst->width = ft_atoi(c);
		while (ft_isdigit(*c++))
			i++;
	}
	return (i);
}

int	ft_read_exact(char *c, t_format *lst, va_list lst_arg)
{
	int	i;

	i = 0;
	if (*c == '*')
	{
		lst->exactness = va_arg(lst_arg, int);
		if (lst->exactness < 0)
			lst->exactness = 0;
		i++;
	}
	else
	{
		lst->exactness = ft_atoi(c);
		while (ft_isdigit(*c++))
			i++;
	}
	lst->dot = 1;
	return (i);
}

int	ft_read_flag(char *c, t_format *lst)
{
	int	i;

	i = 0;
	while (ft_isflag(*c))
	{
		lst->flag[i] = *c;
		i++;
		c++;
	}
	return (i);
}

int	ft_read_size(char *c, t_format *lst)
{
	if (ft_issize(*c) && ft_issize(*(c + 1)))
	{
		lst->size[0] = *c;
		lst->size[1] = *(c + 1);
		return (2);
	}
	if (ft_issize(*c))
	{
		lst->size[0] = *c;
		return (1);
	}
	return (0);
}

int	ft_read_format(char *iter, t_format *lst, va_list lst_arg)
{
	char	*c;

	c = iter;
	while (!ft_istype(*c) && *c != '\0')
	{
		if (ft_isflag(*c))
			c += ft_read_flag(c, lst);
		while (ft_isdigit(*c) || *c == '*')
			c += ft_read_width(c, lst, lst_arg);
		if (*c == '.')
			c += ft_read_exact((c + 1), lst, lst_arg);
		if (ft_issize(*c))
			c += ft_read_size(c, lst);
		if (!ft_istype(*c))
			c++;
	}
	return (c - iter);
}
