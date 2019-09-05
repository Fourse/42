/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:30:41 by smorty            #+#    #+#             */
/*   Updated: 2019/09/05 20:24:17 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_numbers(t_stack *a, t_stack *b)
{
	t_stack *ta;
	t_stack *tb;

	ta = a;
	tb = b;
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("|%11d  |", ta->ret);
			ta = (ta->next == a ? NULL : ta->next);
		}
		else
			ft_printf("|%14|");
		if (tb)
		{
			ft_printf("|%11d  |\n", tb->ret);
			tb = (tb->next == b ? NULL : tb->next);
		}
		else
			ft_printf("|%14|\n");
	}
}

static void	print_graphic(t_stack *a, t_stack *b, int width)
{
	t_stack	*ta;
	t_stack	*tb;
	int		len;

	ta = a;
	tb = b;
	while (ta || tb)
	{
		ft_printf("| \x1b[32m");
		len = ta ? 0 : 1;
		while (ta && len++ < ta->num)
			ft_printf("■");
		while (len++ <= width)
			ft_printf(" ");
		ft_printf("\x1b[0m|");
		ta = (ta && ta->next != a ? ta->next : NULL);
		ft_printf("| \x1b[33m");
		len = tb ? 0 : 1;
		while (tb && len++ < tb->num)
			ft_printf("■");
		while (len++ <= width)
			ft_printf(" ");
		ft_printf("\x1b[0m\n");
		tb = (tb && tb->next != b ? tb->next : NULL);
	}
}

static void	delay(int flag)
{
	char input;

	if (flag % 10)
		usleep(flag % 10 * 100000);
	else
	{
		input = 0;
		while (input != '\n')
		{
			ft_printf("\e[JPress enter to continue");
			read(1, &input, 1);
		}
		ft_printf("\e[F\e[J");
	}
}

void		print_stacks(t_stack *a, t_stack *b, char *com, int flag)
{
	static int	count = 0;
	static int	width = 0;
	int			i;

	ft_printf("\e[?25l\e[H");
	if (!width)
		if ((width = (flag / 10 == 1 ? 12 : stack_size(a) + 1)) < 7)
			width = 7;
	i = width - 5;
	while (i--)
		ft_printf("𝌃");
	ft_printf(" Operation: %3s ", com);
	while (i++ < width - 6)
		ft_printf("𝌃");
	ft_printf("\n");
	flag / 10 == 1 ? print_numbers(a, b) : print_graphic(a, b, width);
	i = width - 4;
	while (i--)
		ft_printf("𝌃");
	ft_printf(" Moves: %5d ", count++);
	while (i++ < width - 5)
		ft_printf("𝌃");
	ft_printf("\n\e[J\e[?25h");
	delay(flag);
}
