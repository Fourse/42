/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:15:25 by rloraine          #+#    #+#             */
/*   Updated: 2019/08/03 17:13:25 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_mid(int *start, int *end, int *mid)
{
	if (end - start < 1)
		return (0);
	if (end - start == 1)
	{
		if (*start > *end)
		{
			*mid = *start;
			*start = *end;
			*end = *mid;
		}
		return (0);
	}
	*mid = *(start + (end - start) / 2);
	if ((*mid > *end && *end > *start) || (*mid < *end && *end < *start))
		*mid = *end;
	else if ((*mid < *start && *start < *end) || (*mid < *start && *start < *end))
		*mid = *end;
	return (1);
}

void	sort_arr(int *start, int *end)
{
	int *left;
	int *right;
	int mid;
	int tmp;

	if (!get_mid(start, end, &mid))
		return ;
	left = start;
	right = end;
	while (left <= right)
	{
		if (*left < mid)
			++left;
		else if (*right > mid)
			--right;
		else
		{
			tmp = *left;
			*left++ = *right;
			*right-- = tmp;
		}
	}
	sort_arr(start, right);
	sort_arr(left - 1, end);
}
