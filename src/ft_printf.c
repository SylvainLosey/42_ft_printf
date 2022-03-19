/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:01 by sylvain           #+#    #+#             */
/*   Updated: 2022/03/19 18:16:41 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list* ap)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	return (1);
}

int	print_string(va_list* ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	return (write(1, str, ft_strlen(str)));
}

int	print_hexadecimal(unsigned long n, int* counter, int maj)
{
	*counter = *counter + 1;
	if (n >= 16)
		print_hexadecimal(n / 16, counter, maj);
	if (maj == 0)
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	else 
		ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	return (*counter);
}

int	print_pointer(va_list* ap, int* counter)
{
	ft_putstr_fd("0x", 1);
	return (print_hexadecimal((uintptr_t) va_arg(*ap, void *), counter, 0) + 2);
}

int	print_number(int number, int* counter)
{
	*counter = *counter + 1;
	if (number == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	else if (number < 0)
	{
		ft_putchar_fd('-', 1);
		print_number(-number, counter);
	}
	else if (number >= 10)
	{
		print_number(number / 10, counter);
		ft_putchar_fd(number % 10 + '0', 1);
	}
	else
		ft_putchar_fd(number + '0', 1);
	return (*counter);
}

int	print_unsigned_number(unsigned int number, int* counter)
{
	*counter = *counter + 1;
	if (number >= 10)
	{
		print_unsigned_number(number / 10, counter);
		ft_putchar_fd(number % 10 + '0', 1);
	}
	else
		ft_putchar_fd(number + '0', 1);
	return (*counter);
}

int	print_flag(char flag, va_list* ap)
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
