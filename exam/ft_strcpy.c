/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:24:24 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/01 16:27:55 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i++])
        s1[i] = s2[i];
    s1[i] = '\0';
    return (s1);
}