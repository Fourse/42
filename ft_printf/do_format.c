/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:58:18 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/24 17:02:27 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_format(const char **format, va_list ap, t_format *params)
{
	while (CHK_C(*format))
	{
		if (IS_INT(*format))
			do_int(format, ap, params);
		if (IS_816(*format))
			
	}
	return (1);
}
