/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:16:57 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 16:18:26 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i])
    {
        write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}