/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:05:56 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/03 16:14:53 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if ((nb < 0) || (nb > 12))
		return (0);
	else if (nb > 1)
	{
		nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else
		return (1);
}
