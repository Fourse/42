/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:24:06 by rloraine          #+#    #+#             */
/*   Updated: 2019/05/30 11:41:29 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** flags
*/

# define IS_MINUS(s) if (*s == '-')
# define IS_PLUS(s) if (*s == '+')
# define IS_SPACE(s) if (*s == ' ')
# define IS_HASH(s) if (*s == '#')
# define IS_NULL(s) if (*s == '0')

/*
** type of conversion
*/

# define IS_NUMB(s) if (*s == 'd' || *s == 'i')
# define IS_U(s) if (*s == 'u')
# define IS_O(s) if (*s == 'o')
# define IS_X(s) if (*s == 'x')
# define IS_BX(s) if (*s == 'X')
# define IS_F(s) if (*s == 'f')
# define IS_BF(s) if (*s == 'F')
# define IS_E(s) if (*s == 'e')
# define IS_BE(s) if (*s == 'E')
# define IS_G(s) if (*s == 'g')
# define IS_BG(s) if (*s == 'G')
# define IS_A(s) if (*s == 'a')
# define IS_BA(s) if (*s == 'A')
# define IS_C(s) if (*s == 'c')
# define IS_S(s) if (*s == 's')
# define IS_BS(s) if (*s == 'S')
# define IS_p(s) if (*s == 'p')
# define IS_N(s) if (*s == 'n')

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "./libft/libft.h"

int	treatment(char *format, int result);

#endif
