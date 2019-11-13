/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:13:37 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/04 18:13:41 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_concat_str(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(result = (char*)malloc(sizeof(char) *
					(ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	while (str1[++i] != '\0')
	{
		result[j] = str1[i];
		j++;
	}
	free(str1);
	free(str2);
	i = 0;
	while (str2[i] != '\0')
	{
		result[j] = str2[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
