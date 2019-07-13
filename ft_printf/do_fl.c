/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:01 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/13 16:13:56 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		do_fl_wm(char **tmp)
// {
// 	char *ttmp;

// 	ttmp = *tmp;
// 	string_to_buf(ttmp, ttmp + ft_strlen(ttmp));
// 	return (0);
// }
double	ft_calc_modulo(long double nb, int *size)
{
	double	modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	return (modulo);
}

void	ft_handle_integer(long double *nb, char **str, int *i, double modulo)
{
	char *s;

	s = *str;
	while ((int)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / modulo) + 48);
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
}

void	ft_handle_decimals(char **str, int *i, long double nb, int precision)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			continue ;
		}
		tmp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}
char	*load_tmp(t_floats *ret_union, t_format *params, char **tmp)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	modulo;

	size = 1;
	neg = 0;
	if (ret_union->ret < 0 && size++ && (neg = 1) == 1)
		ret_union->ret = -ret_union->ret;
	modulo = ft_calc_modulo(ret_union->ret, &size);
	size += params->acc;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&ret_union->ret, &str, &i, modulo);
	ft_handle_decimals(&str, &i, ret_union->ret, params->acc);
	str[--i] = '\0';
	*tmp = str;
	return (*tmp);
}

// int		inf_nan(t_floats *ret_union, t_format *params)
// {
// 	if (params->flag & ACC)
// 		params->flag ^= ACC;
// 	if (params->flag & ZERO)
// 		params->flag ^= ZERO;
// 	if (!(ret_union->bits.mantis << 1))
// 	{
// 		if (ret_union->bits.sign)
// 			return (do_s_wm((params->spec > 96 ? "-inf" : "-INF"), params));
// 		else if (params->flag & PLUS)
// 			return (do_s_wm((params->spec > 96 ? "+inf" : "+INF"), params));
// 		else if (params->flag & SPACE)
// 			return (do_s_wm((params->spec > 96 ? " inf" : " INF"), params));
// 	}
// 	return (do_s_wm((params->spec > 96 ? "nan" : "NAN"), params));
// }

int		do_fl(va_list *ap, t_format *params)
{
	t_floats	ret_union;
	t_bits bits;
	char		*tmp = NULL;

	if (!(params->acc & ACC))
		params->acc = 7;
	if (params->flag & LONGD)
		ret_union.ret = va_arg(*ap, long double);
	else
		ret_union.ret = va_arg(*ap, double);
	bits.exp = ret_union.l[4] - 16383;
	// if (bits.exp == 16384)
	// 	return (inf_nan(&ret_union, params));
	tmp = load_tmp(&ret_union, params, &tmp);
	string_to_buf(tmp, tmp + ft_strlen(tmp));
	return (0);
}
