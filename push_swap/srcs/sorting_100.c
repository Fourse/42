/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:27:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/07 15:39:05 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define COUNT push(a, b, comm); ++prev_mid; ++count; --size;
#define IFBREAK if (size <= 3) break;
#define ELSEROT else rotate(a, comm);

int		share_stack(t_stack **a, t_stack **b, int size, int **comm)
{
	int mid;
	int prev_mid;
	int check_mid;
	int count;

	mid = find_mid(*a, size);
	prev_mid = find_min(*a, size);
	check_mid = mid;
	count = 0;
	while (1)
	{
		IFBREAK;
		if (prev_mid == check_mid)
		{
			mid = find_mid(*a, size);
			prev_mid = check_mid;
			check_mid = mid;
		}
		if ((*a)->num <= mid)
		{
			COUNT;
		}
		ELSEROT;
	}
	return (count);
}

void	sort_back(t_stack **a, t_stack **b, int size, int **ops)
{
	int start;
	int end;

	start = find_max(*b, size);
	end = find_min(*b, size);
	while (end <= start)
	{
		while ((*b)->num != start && (*b)->num != start - 1)
			if ((*b)->num == end || (*b)->num == end + 1)
			{
				if ((*b)->num == end)
					end += 1 + ((*a)->prev->num == end + 1);
				push(b, a, ops);
				rotate(a, ops);
			}
			else
				find_dir2(*b, start) >= 0 ? rotate(b, ops) : rev_rotate(b, ops);
		push(b, a, ops);
		while ((*a)->num == start || (*a)->prev->num == start
			|| (*a)->next->num == start)
			--start;
		if ((*a)->num > (*a)->next->num)
			swap(a, ops);
	}
}

void	get_up(t_stack **a, int **ops)
{
	while ((*a)->prev->num < (*a)->next->num)
	{
		rev_rotate(a, ops);
		if ((*a)->num > (*a)->next->num)
			swap(a, ops);
	}
}

void	sort_100(t_stack **a, t_stack **b, int size, int **comm)
{
	int count;

	if (size == 2 && (*a)->num > (*a)->next->num)
		swap(a, comm);
	else if (size == 3 && !stack_is_sorted(*a, size))
		sort_3(a, size, comm);
	else
	{
		count = share_stack(a, b, size, comm);
		sort_100(a, b, size - count, comm);
		sort_back(a, b, count, comm);
		get_up(a, comm);
	}
}
