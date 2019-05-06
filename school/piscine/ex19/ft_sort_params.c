/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:58:57 by rloraine          #+#    #+#             */
/*   Updated: 2019/04/03 15:57:11 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **argv, int argc)
{
	char	*swap;
	int		i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			swap = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = swap;
			i = 0;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int n;

	if (argc > 1)
	{
		ft_sort_params(argv, argc);
		n = 1;
		while (n < argc)
		{
			i = 0;
			while (argv[n][i])
			{
				ft_putchar(argv[n][i]);
				i++;
			}
			ft_putchar('\n');
			n++;
		}
	}
	return (0);
}
