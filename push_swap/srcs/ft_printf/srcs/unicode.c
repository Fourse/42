/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:34:30 by smorty            #+#    #+#             */
/*   Updated: 2019/05/31 20:21:09 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unicode_2(wchar_t c)
{
	CHECK_BUFF(2);
	*(g_ftprintf.buf + g_ftprintf.len + 1) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len) = 0xC0 | (c & 0x1F);
	g_ftprintf.len += 2;
	if (g_ftprintf.len == BUFF_SIZE)
		print_buf();
	return (2);
}

static int	unicode_3(wchar_t c)
{
	CHECK_BUFF(3);
	*(g_ftprintf.buf + g_ftprintf.len + 2) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len + 1) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len) = 0xE0 | (c & 0xF);
	g_ftprintf.len += 3;
	if (g_ftprintf.len == BUFF_SIZE)
		print_buf();
	return (3);
}

static int	unicode_4(wchar_t c)
{
	CHECK_BUFF(4);
	*(g_ftprintf.buf + g_ftprintf.len + 3) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len + 2) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len + 1) = 0x80 | (c & 0x3F);
	c = (c >> 6);
	*(g_ftprintf.buf + g_ftprintf.len) = 0xF0 | (c & 0x7);
	g_ftprintf.len += 4;
	if (g_ftprintf.len == BUFF_SIZE)
		print_buf();
	return (4);
}

int			unicode(wchar_t c)
{
	if (c <= 0x7F)
	{
		char_to_buf(c & 0x7F, 1);
		return (1);
	}
	else if (c <= 0x7FF && BUFF_SIZE >= 2)
		return (unicode_2(c));
	else if (c >= 0xD800 && c <= 0xDB7F)
		return (0);
	else if (c <= 0xFFFF && BUFF_SIZE >= 3)
		return (unicode_3(c));
	else if (BUFF_SIZE >= 4)
		return (unicode_4(c));
	return (0);
}
