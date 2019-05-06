/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:38:33 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 16:07:54 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 1)
    {
        write(1, "a\n", 2);
        return (0);
    }
    if (argc > 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (argv[1][i])
    {
        if (argv[1][i] == 'a')
        {
            write(1, "a", 1);
            break ;
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}