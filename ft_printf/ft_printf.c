/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:36:54 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/02 21:40:16 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	list_initialization(t_format *list)
{
	list = (t_format*)malloc(sizeof(t_format));
	list->flag = 0;
	list->width = 0;
	list->acc = 0;
	list->mod = 0;
	list->spec = 0;
}

int			treatment(char *format, int result, va_list args)
{
	t_format *list;

	while (*format)
	{
		list_initialization(list);
		if (*format == '%')
		{
			format++;
		}
		else
			result += write(1, format, 1);
		format++;
	}
	return (result);
}

int			ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, format);
	result = treatment((char*)format, result, args);
	va_end(args);
	return (result);
}
