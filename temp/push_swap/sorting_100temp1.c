#include "push_swap.h"

int		find_highest(t_stack *s, int size)
{
	int high;

	high = 0;
	if (s)
	{
		high = s->num;
		while (--size)
		{
			s = s->next;
			if (s->num > high)
				high = s->num;
		}
	}
	return (high);
}

int		find_lowest(t_stack *s, int size)
{
	int low;

	low = 0;
	if (s)
	{
		low = s->num;
		while (--size)
		{
			s = s->next;
			if (s->num < low)
				low = s->num;
		}
	}
	return (low);
}

static int	where_to(t_stack *s, int num)
{
	t_stack	*r;
	int		direction;

	direction = 0;
	r = s;
	while (r->num != num)
	{
		r = r->next;
		--direction;
	}
	r = s;
	while (r->num != num)
	{
		r = r->prev;
		++direction;
	}
	return (direction);
}

static void	bottom_up(t_stack **a, long *comm)
{
	while ((*a)->prev->num < (*a)->next->num)
	{
		rev_rotate(a, comm, 1);
		if ((*a)->num > (*a)->next->num)
			swap(a, comm, 1);
	}
}

static void	sort_back(t_stack **a, t_stack **b, int size, long *comm)
{
	int start;
	int end;

	start = find_highest(*b, size);
	end = find_lowest(*b, size);
	while (end <= start)
	{
		while ((*b)->num != start && (*b)->num != start - 1)
			if ((*b)->num == end || (*b)->num == end + 1)
			{
				if ((*b)->num == end)
					end += 1 + ((*a)->prev->num == end + 1);
				push(b, a, comm, 2);
				rotate(a, comm, 1);
			}
			else
				where_to(*b, start) >= 0 ? rotate(b, comm, 2) : rev_rotate(b, comm, 2);
		push(b, a, comm, 1);
		while ((*a)->num == start || (*a)->prev->num == start
			|| (*a)->next->num == start)
			--start;
		if ((*a)->num > (*a)->next->num)
			swap(a, comm, 1);
	}
}

static int	split(t_stack **a, t_stack **b, int size, long *comm)
{
	int pivot;
	int count;

	pivot = find_lowest(*a, size) + size / 2 + size % 2;
	count = 0;
	while (count * 2 < size + 4)
		if ((*a)->num <= pivot + 1)
		{
			push(a, b, comm, 2);
			++count;
			if ((*b)->num >= pivot)
				rotate(b, comm, 2);
		}
		else
			rotate(a, comm, 1);
	return (count);
}

void		sort_100(t_stack **a, t_stack **b, int size, long *comm)
{
	int count;

	if (size == 2 && (*a)->num > (*a)->next->num)
		swap(a, comm, 1);
	else if (size <= 3)
		sort_3(a, size, comm);
	else
	{
		count = split(a, b, size, comm);
		sort_100(a, b, size - count, comm);
		rev_rotate(b, comm, 2);
		rev_rotate(b, comm, 2);
		push(b, a, comm, 1);
		push(b, a, comm, 1);
		if ((*a)->num > (*a)->next->num)
			swap(a, comm, 1);
		sort_back(a, b, count - 2, comm);
		bottom_up(a, comm);
	}
}
