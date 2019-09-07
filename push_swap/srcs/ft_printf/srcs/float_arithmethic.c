/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_arithmethic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:03:30 by smorty            #+#    #+#             */
/*   Updated: 2019/07/13 14:14:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*multiply(int *a, int *b, int size_a, int size_b)
{
	int *result;
	int size;
	int i;
	int j;

	size = size_a + size_b + 1;
	result = (int *)malloc(sizeof(int) * (size + 1));
	ft_bzero(result, sizeof(int) * (size + 1));
	i = 0;
	while (i < size_a)
	{
		j = -1;
		while (++j < size_b)
			result[1 + i + j] += a[i] * b[j];
		++i;
	}
	while (--size)
		if (result[size] > 9)
		{
			result[size - 1] += result[size] / 10;
			result[size] %= 10;
		}
	free(a);
	return (result);
}

static int	new_size(int **result, int len)
{
	int *new;
	int i;
	int j;

	i = 0;
	while (!(*result)[i])
		++i;
	new = (int *)malloc(sizeof(int) * (len - i));
	j = 0;
	while (i < len)
	{
		*(new + j) = (*result)[i];
		++j;
		++i;
	}
	free(*result);
	*result = new;
	return (j);
}

static int	*power2pos(int power, int *len_r)
{
	int *result;
	int *pwr;
	int len_p;

	result = (int *)malloc(sizeof(int));
	*result = 1;
	*len_r = 1;
	pwr = (int *)malloc(sizeof(int));
	*pwr = 2;
	len_p = 1;
	while (power)
	{
		if (power & 1)
		{
			result = multiply(result, pwr, *len_r, len_p);
			*len_r = new_size(&result, *len_r + len_p);
		}
		pwr = multiply(pwr, pwr, len_p, len_p);
		len_p = new_size(&pwr, len_p * 2);
		power >>= 1;
	}
	free(pwr);
	return (result);
}

static int	*power2neg(int power, int *len_r)
{
	int *result;
	int *pwr;
	int len_p;

	result = (int *)malloc(sizeof(int));
	*result = 1;
	*len_r = 1;
	pwr = (int *)malloc(sizeof(int));
	*pwr = 5;
	len_p = 1;
	while (power)
	{
		if (power & 1)
		{
			result = multiply(result, pwr, *len_r, len_p);
			*len_r += len_p;
		}
		pwr = multiply(pwr, pwr, len_p, len_p);
		len_p *= 2;
		power >>= 1;
	}
	free(pwr);
	return (result);
}

void		power2(char *dot, int power)
{
	int *result;
	int len;

	result = power < 0 ? power2neg(-power, &len) : power2pos(power, &len);
	dot += (power < 0 ? len - 1 : -1);
	result += len - 1;
	while (len--)
	{
		*dot += *result;
		if (*dot > 9 && *dot != '.')
		{
			*dot -= 10;
			++*(dot - 1);
		}
		--dot;
		--result;
	}
	while (*dot > 9)
	{
		*dot -= 10;
		--dot;
		++*dot;
	}
	free(result + 1);
}
