/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:37:46 by smorty            #+#    #+#             */
/*   Updated: 2019/06/15 20:25:12 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_color(char *color, int color_len)
{
	if (BUFF_SIZE >= 5)
	{
		CHECK_BUFF(5);
		string_to_buf(color, color + 5);
		return (color_len);
	}
	char_to_buf('{', 1);
	return (1);
}

void		check_color_and_fd(const char **format, va_list *argp)
{
	if (ft_strnequ(*format, "{red}", 5))
		*format += set_color(COLOR_RED, 5);
	else if (ft_strnequ(*format, "{green}", 7))
		*format += set_color(COLOR_GREEN, 7);
	else if (ft_strnequ(*format, "{yellow}", 8))
		*format += set_color(COLOR_YELLOW, 8);
	else if (ft_strnequ(*format, "{blue}", 6))
		*format += set_color(COLOR_BLUE, 6);
	else if (ft_strnequ(*format, "{magenta}", 9))
		*format += set_color(COLOR_MAGENTA, 9);
	else if (ft_strnequ(*format, "{cyan}", 6))
		*format += set_color(COLOR_CYAN, 6);
	else if (ft_strnequ(*format, "{eoc}", 5))
		*format += set_color(COLOR_RESET, 5);
	else if (ft_strnequ(*format, "{*}", 3))
	{
		print_buf();
		g_ftprintf.fd = va_arg(*argp, int);
		*format += 3;
	}
	else
	{
		char_to_buf('{', 1);
		++(*format);
	}
}
