/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:09 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:27:12 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fraction_str(long double num)
{
	char		*str;
	long double	fract;
	int			i;

	if (num < 0)
		num = num * (-1);
	str = ft_strnew(100);
	str[0] = '.';
	i = 1;
	fract = num - (intmax_t)num;
	while (fract > 0.000000001 && i < 99)
	{
		fract *= 10;
		str[i] = (char)((int)fract + '0');
		fract = fract - (intmax_t)fract;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_change_symb(char *fract_str, int *i, int *end)
{
	if (*i != 0)
	{
		if (fract_str[*i - 1] == '9')
			fract_str[*i - 1] = '0';
		else if (fract_str[*i - 1] == '-')
		{
			fract_str[*i - 1] = '1';
			fract_str = ft_concat_str(ft_strnew_char('-', 1), fract_str);
			(*end)++;
		}
		else if (fract_str[*i - 1] != '.')
			fract_str[*i - 1] = (int)fract_str[*i - 1] + 1;
		else if (fract_str[*i - 1] == '.')
		{
			(*i)--;
			fract_str = ft_change_symb(fract_str, i, end);
		}
	}
	else
	{
		fract_str = ft_concat_str(ft_strnew_char('1', 1), fract_str);
		(*end)++;
	}
	return (fract_str);
}

char	*ft_round(char *fract_str)
{
	int i;
	int end;

	end = ft_strlen(fract_str) - 1;
	i = end;
	if (fract_str[i] >= '5')
	{
		fract_str = ft_change_symb(fract_str, &i, &end);
		i--;
		while (fract_str[i] == '0')
		{
			fract_str = ft_change_symb(fract_str, &i, &end);
			i--;
		}
	}
	fract_str[end] = '\0';
	return (fract_str);
}

char	*ft_fraction_exact(char *fract_str, int exact)
{
	int	i;

	i = 1;
	if (exact == 0)
		fract_str[0] = '\0';
	else
	{
		fract_str[exact + 1] = '\0';
		while (fract_str[i] != '\0')
			i++;
		while (i < exact + 1)
		{
			fract_str[i] = '0';
			i++;
		}
	}
	return (fract_str);
}

char	*ft_float_str(long double num, int exact)
{
	return (ft_concat_str(ft_itoa((intmax_t)num),
			ft_fraction_exact(ft_fraction_str(num), exact + 1)));
}
