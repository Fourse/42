/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:29:13 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 16:29:18 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
    write(1, "z", 1);
}