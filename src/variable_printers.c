/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_printers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:30:11 by sylvain           #+#    #+#             */
/*   Updated: 2022/04/01 12:41:17 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	return (1);
}

int	print_string(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, void *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_hexadecimal(unsigned long n, int *counter, int maj)
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

int	print_number(int number, int *counter)
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

int	print_unsigned_number(unsigned int number, int *counter)
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
