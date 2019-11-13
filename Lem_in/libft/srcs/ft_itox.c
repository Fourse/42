/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:21:10 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:21:13 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fill string for ft_itoo
*/

static void	ft_fullstr_x(char *str, uintmax_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = ft_itoa(n);
	while (str[i] != '\0')
		i++;
	if (n == 10)
		str[i] = 'a';
	else	if (n == 11)
		str[i] = 'b';
	else	if (n == 12)
		str[i] = 'c';
	else	if (n == 13)
		str[i] = 'd';
	else	if (n == 14)
		str[i] = 'e';
	else	if (n == 15)
		str[i] = 'f';
	else
		str[i] = *ptr;
	free(ptr);
}

/*
** Move decimal to hexadecimal
*/

void		ft_itox(char *str, uintmax_t n)
{
	if (n >= 16)
		ft_itox(str, n / 16);
	ft_fullstr_x(str, n % 16);
}
