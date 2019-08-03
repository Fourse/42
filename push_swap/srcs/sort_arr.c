/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:15:25 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 14:59:50 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arr_is_sorted(int **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if ((*arr)[i] < (*arr)[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	sort_arr(int *start, int *end)
{

}
