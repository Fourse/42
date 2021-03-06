/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:57:00 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/21 16:48:44 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			nb;
	int				minus;

	i = 0;
	nb = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
	str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if ((nb >= 922337203685477581 && str[i] >= '0' && str[i] <= '9') ||
			(nb == 922337203685477580 && str[i] >= '8' && str[i] <= '9'))
		{
			nb = (minus == 1) ? 9223372036854775807 : -9223372036854775807 - 1;
			return (nb);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * minus);
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	printf("ft: %d\n", ft_atoi(argv[1]));
	printf("or: %d\n", atoi(argv[1]));
}
