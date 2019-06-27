/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:17:40 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/27 11:33:45 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_to_buf(const char *start, const char *end)
{
	while (start < end)
	{
		*(g_print.buf + g_print.len) = *start;
		++start;
		++g_print.len;
		if (g_print.len == BUFF_SIZE)
			print_buf();
	}
}

void	to_print(char *tmp, char *width, t_format *params)
{
	if (!(params->flag & MINUS) && width)
	{
		string_to_buf(width, width + params->width);
		free(width);
	}
	string_to_buf(tmp, tmp + params->len);
	if ((params->flag & MINUS) && width)
	{
		string_to_buf(width, width + params->width);
		free(width);
	}
}

char	*make_width(t_format *params)
{
	char *width;

	params->width -= params->len;
	if (!(width = (char*)malloc(sizeof(char) * params->width + 1)))
	{
		g_print.error = 0;
		return (NULL);
	}
	ft_memset(width, (params->flag & ZERO ? '0' : ' '), params->width);
	*(width + params->width) = 0;
	return (width);
}

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
