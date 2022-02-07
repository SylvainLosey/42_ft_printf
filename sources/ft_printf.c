/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:01 by sylvain           #+#    #+#             */
/*   Updated: 2022/02/07 20:20:24 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printf(const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    while(*fmt) {
        if (*fmt != '%') {
            ft_putchar_fd(*fmt, 1);
        }
        fmt++;
    }
    va_end(ap);
    return (0);
}

