/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:44:42 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/30 11:41:31 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treatment(char *format, int result)
{
	while (*format)
	{
		if (*format == '%')
		{
			
		}
		format++;
	}
	return (result);
}
