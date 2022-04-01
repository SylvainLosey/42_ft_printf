/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:01 by sylvain           #+#    #+#             */
/*   Updated: 2022/04/01 12:38:42 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		written_chars;

	va_start(ap, fmt);
	written_chars = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
		{
			fmt++;
			written_chars += print_flag(*fmt, &ap);
		}
		else
		{
			if (*fmt == '%' && *(fmt + 1) == '%')
				ft_putchar_fd(*fmt++, 1);
			else
				ft_putchar_fd(*fmt, 1);
			written_chars++;
		}
		fmt++;
	}
	va_end(ap);
	return (written_chars);
}

int	print_flag(char flag, va_list *ap)
{
	int	counter;

	counter = 0;
	if (flag == 'c')
		return (print_char(ap));
	else if (flag == 's')
		return (print_string(ap));
	else if (flag == 'p')
		return (print_pointer(ap, &counter));
	else if (flag == 'd' || flag == 'i')
		return (print_number(va_arg(*ap, int), &counter));
	else if (flag == 'u')
		return (print_unsigned_number(va_arg(*ap, unsigned int), &counter));
	else if (flag == 'x')
		return (print_hexadecimal(va_arg(*ap, unsigned int), &counter, 0));
	else if (flag == 'X')
		return (print_hexadecimal(va_arg(*ap, unsigned int), &counter, 1));
	else
		return (0);
}

int	print_pointer(va_list *ap, int *counter)
{
	ft_putstr_fd("0x", 1);
	return (print_hexadecimal((uintptr_t) va_arg(*ap, void *), counter, 0) + 2);
}
