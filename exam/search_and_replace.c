/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:44:28 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 17:17:30 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i])
    {
        if (argv[1][i] == argv[2][0])
            argv[1][i] = argv[3][0];
        write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}