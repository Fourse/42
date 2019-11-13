/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:41:28 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:41:34 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sotr_type(char *iter, t_format *lst, va_list lst_arg)
{
	ft_check_special_type(iter, lst);
	if (*iter == 'i' || *iter == 'd' || *iter == 'D')
		ft_put_decimal(lst, lst_arg);
	if (*iter == 'x' || *iter == 'X')
		ft_put_hexadecimal(lst, lst_arg, *iter);
	if (*iter == 'o' || *iter == 'O')
		ft_put_octal(lst, lst_arg);
	if (*iter == '%')
		ft_put_percent(lst);
	if (*iter == 'u' || *iter == 'U')
		ft_put_unsigned(lst, lst_arg);
	if (*iter == 'f' || *iter == 'F')
		ft_put_float(lst, lst_arg, *iter);
	if (*iter == 's')
		ft_put_string(lst, lst_arg);
	if (*iter == 'c')
		ft_put_char(lst, lst_arg);
	if (*iter == 'p')
		ft_put_pointer(lst, lst_arg);
	return (1);
}

int		ft_chack_valid_format(char *iter, char **iter_ptr, int *len)
{
	int	i;

	i = 0;
	if (*iter == '\0')
	{
		(*len)++;
		return (0);
	}
	while (!ft_istype(*iter))
	{
		if ((!ft_isflag(*iter) && !ft_issize(*iter) &&
				!ft_isdigit(*iter) && *iter != '.' && *iter != '*')
				|| *(iter + 0) == '\0')
		{
			*iter_ptr += i;
			*len = i + 1;
			return (0);
		}
		i++;
		iter++;
	}
	return (1);
}

int		ft_sort_arg(char *iter, va_list lst_arg, size_t *len_str,
		size_t *len_format)
{
	t_format	*lst;
	char		*ptr;

	ptr = iter;
	lst = ft_newstruct();
	ptr += ft_read_format(iter, lst, lst_arg);
	ptr += ft_sotr_type(ptr, lst, lst_arg);
	*len_str += lst->len_str;
	*len_format += (ptr - iter + 1);
	free(lst);
	return (ptr - iter);
}

int		ft_printf(const char *restrict format, ...)
{
	char		*iter;
	va_list		lst_arg;
	size_t		len_str;
	size_t		len_format;
	int			len;

	len = 0;
	len_str = 0;
	len_format = 0;
	va_start(lst_arg, format);
	iter = (char *)format;
	while (*iter != '\0')
	{
		if (*iter == '%')
		{
			if (ft_chack_valid_format((iter + 1), &iter, &len))
				iter += ft_sort_arg(iter + 1, lst_arg, &len_str, &len_format);
		}
		else
			ft_putchar(*iter);
		iter++;
	}
	va_end(lst_arg);
	return ((iter - format) - len + len_str - len_format);
}
