/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:17:40 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/26 15:21:21 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
