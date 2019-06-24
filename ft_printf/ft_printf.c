/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:04:00 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/24 17:02:13 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_out g_print;

void	print_buf(void)
{
	int print;

	print = write(g_print.fd, g_print.buf, g_print.len);
	if (print != g_print.len)
		g_print.error = -1;
	g_print.print += print;
	g_print.len = 0;
}

void	char_to_buf(char c, int i)
{
	while (i)
	{
		*(g_print.buf + g_print.len) = c;
		++g_print.len;
		if (g_print.len == BUFF_SIZE)
			print_buf();
		--i;
	}
}

void	check_frmt(const char **format, va_list ap, t_format *params)
{
	while (**format)
	{
		if (**format == '%')
		{
			++(*format);
			if (**format == '%')
			{
				char_to_buf('%', 1);
				++(*format);
			}
			else if (**format)
				if (!parse_prms(format, ap, params))
					return ;
		}
		else
		{
			char_to_buf(**format, 1);
			++(*format);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	params;

	params.flag = 0;
	params.width = 0;
	params.acc = 0;
	params.mod = 0;
	params.spec = 0;
	g_print.print = 0;
	g_print.error = 0;
	g_print.len = 0;
	g_print.fd = 1;
	va_start(ap, format);
	check_frmt(&format, ap, &params);
	print_buf();
	va_end(ap);
	return (g_print.error ? -1 : g_print.print);
}
