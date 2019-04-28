/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:58:07 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/28 16:02:29 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int valid(char **figure, int n, int i)
{
	if (figure[n][i] != '#' && (n >= 4 || n < 0) && (i >= 4 || i < 0))
		return (0);
	figure[n][i] = '*';
	return (valid(figure, n + 1, i) + valid(figure, n - 1, i) + valid(figure, n, i - 1) + valid(figure, n, i + 1))
}
