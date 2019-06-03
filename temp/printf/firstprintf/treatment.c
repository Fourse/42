/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:44:42 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/03 15:25:39 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CONVE1 CHK_CONV(format) || CHK_CONV2(format)
#define CONVE2 CHK_CONV3(format) || CHK_CONV4(format)
/*
void	solve(va_list atata, t_format *list)
{
	
}
*/
int		treatment(char *format, int result, va_list atata)
{
	t_format *list;

	while (*format)
	{
		if (!(list = (t_format*)malloc(sizeof(t_format))))
			return (-1);
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				result += write(1, "%", 1);
				format++;
				continue;
			}
			if (CHK_FL(format))
				list->flag = (char)format++;
			if (CHK_W(format))
			{
				list->width = ft_atoi(format);
				ROLL_NUMBS(format);
			}
			if (CHK_A(format))
			{
				list->acc = ft_atoi(++format);
				ROLL_NUMBS(format);
			}
			if (CHK_MODS(format))
			{
				if ((HH(format)) || (LL(format)))
				{
					list->mod = ft_strsub(list->mod, *format, 2);
					format += 2;
				}
				else if ((H(format)) || (L(format)) || (BL(format)))
				{
					list->mod = ft_strnew(1);
					list->mod = format++;
				}
			}
			if (CONVE1 || CONVE2)
			{
				list->spec = *format++;
				list = list->next;
				continue ;
			}
		}
		else
			result += write(1, &format, 1);
		format++;
	}
	list = NULL;
	//solve(atata, list);
	return (result);
}
