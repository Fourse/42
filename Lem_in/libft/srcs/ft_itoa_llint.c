/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:20:24 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:20:29 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_recstr(char *str, int neg)
{
	long int	i;
	size_t		n;
	char		cop[23];
	char		*rtnstr;

	n = 0;
	i = ft_strlen(str) - 1;
	if (neg < 0)
		cop[n++] = '-';
	if (i == -1)
		cop[n++] = '0';
	while (i >= 0)
	{
		cop[n] = str[i];
		n++;
		i--;
	}
	cop[n] = '\0';
	if (!(rtnstr = ft_strdup(cop)))
		return (NULL);
	return (rtnstr);
}

char		*ft_itoa_llint(long long int n)
{
	size_t			i;
	long long int	num;
	int				neg;
	char			str[21];
	char			*rtnstr;

	i = 0;
	neg = 0;
	num = n;
	if (n < 0)
	{
		num = n * (-1);
		neg = -1;
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = '\0';
	if (!(rtnstr = ft_recstr(str, neg)))
		return (NULL);
	return (rtnstr);
}
