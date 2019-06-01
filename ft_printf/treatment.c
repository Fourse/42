/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:44:42 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/01 20:29:20 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CONVE1 CHK_CONV(format) || CHK_CONV2(format)
#define CONVE2 CHK_CONV3(format) || CHK_CONV4(format)

void	solve(va_list atata, t_format *list)
{
	
}

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
				break ;
			}
			else if (CHK_FL(format))
				list->flag = (char)format++;
			else if (CHK_W(format))
			{
				list->width = ft_atoi(format);
				ROLL_NUMBS(format);
			}
			else if (CHK_A(format))
			{
				list->acc = ft_atoi(++format);
				ROLL_NUMBS(format);
			}
			else if (CHK_MODS(format))
			{
				if ((HH(format)) || (LL(format)))
				{
					list->mod = ft_strsub(list->mod, *format, 2);
					format++;
					format++;
				}
				else
					list->mod[0] = *format++;
			}
			else if (CONVE1 || CONVE2)
			{
				list->spec = *format++;
				break ;
			}
			list = list->next;
		}
		else
			result += write(1, &format, 1);
		format++;
	}
	list = NULL;
	solve(atata, list);
	return (result);
}
