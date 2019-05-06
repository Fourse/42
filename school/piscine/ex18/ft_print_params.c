/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:50:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/02 19:58:12 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int n;

	if (argc > 1)
	{
		n = 1;
		while (n < argc)
		{
			i = 0;
			while (argv[n][i])
			{
				ft_putchar(argv[n][i]);
				i++;
			}
			n++;
			ft_putchar('\n');
		}
	}
	return (0);
}
