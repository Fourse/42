/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:32:28 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 16:43:14 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int k;

    i = 0;
    k = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                k = argv[1][i] - 'a';
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                k = argv[1][i] - 'A';
            while (k--)
                write(1, &argv[1][i], 1);
            write(1, &argv[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}