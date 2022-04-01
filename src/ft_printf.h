/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:04 by sylvain           #+#    #+#             */
/*   Updated: 2022/04/01 12:40:11 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int	ft_printf(const char *fmt, ...);
int	print_flag(char flag, va_list *ap);
int	print_pointer(va_list *ap, int *counter);

int	print_char(va_list *ap);
int	print_string(va_list *ap);
int	print_hexadecimal(unsigned long n, int *counter, int maj);
int	print_number(int number, int *counter);
int	print_unsigned_number(unsigned int number, int *counter);

#endif