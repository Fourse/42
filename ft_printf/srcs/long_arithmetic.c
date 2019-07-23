/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:56:47 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/23 16:56:05 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*multiply(int *a, int *b, int size_a, int size_b)
{
	int *res;
	int size;
	int i;
	int j;

	size = size_a + size_b + 1;
	res = (int*)malloc(sizeof(int) * (size + 1));
	ft_bzero(res, sizeof(int) * (size + 1));
	i = 0;
	while (i < size_a)
	{
		j = -1;
		while (++j < size_b)
			res[1 + i + j] += a[i] * b[j];
		++i;
	}
	while (--size)
		if (res[size] > 9)
		{
			res[size - 1] += res[size] / 10;
			res[size] %= 10;
		}
	free(a);
	return (res);
}

static int	new_size(int **res, int len)
{
	int *new_res;
	int i;
	int j;

	i = 0;
	while (!(*res)[i])
		++i;
	new_res = (int*)malloc(sizeof(int) * (len - i));
	j = 0;
	while (i < len)
	{
		*(new_res + j) = (*res)[i];
		++j;
		++i;
	}
	free(*res);
	*res = new_res;
	return (j);
}

static int	*power_of_5(int exp, int *len_res)
{
	int *res;
	int *power;
	int len_power;

	res = (int*)malloc(sizeof(int));
	*res = 1;
	*len_res = 1;
	power = (int*)malloc(sizeof(int));
	*power = 5;
	len_power = 1;
	while (exp)
	{
		if (exp & 1)
		{
			res = multiply(res, power, *len_res, len_power);
			*len_res += len_power;
		}
		power = multiply(power, power, len_power, len_power);
		len_power *= 2;
		exp >>= 1;
	}
	free(power);
	return (res);
}

static int	*power_of_2(int exp, int *len_res)
{
	int *res;
	int *power;
	int len_power;

	res = (int*)malloc(sizeof(int));
	*res = 1;
	*len_res = 1;
	power = (int*)malloc(sizeof(int));
	*power = 2;
	len_power = 1;
	while (exp)
	{
		if (exp & 1)
		{
			res = multiply(res, power, *len_res, len_power);
			*len_res = new_size(&res, *len_res + len_power);
		}
		power = multiply(power, power, len_power, len_power);
		len_power = new_size(&power, len_power * 2);
		exp >>= 1;
	}
	free(power);
	return (res);
}

void		power_of(char *dot, int exp)
{
	int *res;
	int len;

	res = exp < 0 ? power_of_5(-exp, &len) : power_of_2(exp, &len);
	dot += (exp < 0 ? len - 1 : -1);
	res += len - 1;
	while (len--)
	{
		*dot += *res;
		if (*dot > 9 && *dot != '.')
		{
			*dot -= 10;
			++*(dot - 1);
		}
		--dot;
		--res;
	}
	while (*dot > 9)
	{
		*dot -= 10;
		--dot;
		++*dot;
	}
	free(res + 1);
}
