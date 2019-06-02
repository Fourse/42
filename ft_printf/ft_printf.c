/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:36:54 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/02 21:59:11 by rloraine         ###   ########.fr       */
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
	list->next = NULL;
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
			if (*format == '%')
			{
				result += write(1, "%", 1);
				format++;
				continue;
			}
			if (CHK_F(format))
				list->flag = (unsigned char)format++;
			if (CHK_W(format))
			{
				list->width = (unsigned char)ft_atoi(format);
				ROLL_NUMBS(format);
			}
			if (CHK_A(format))
			{
				list->acc = (unsigned char)ft_atoi(++format);
				ROLL_NUMBS(format);
			}
			if (CHK_M(format))
			{

			}
			if (CHK_C(format))
			{
				list->spec = (unsigned char)format++;
				list = list->next;
				continue;
			}
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
