/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:01 by sylvain           #+#    #+#             */
/*   Updated: 2022/03/19 14:12:42 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list* ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	handle_string(va_list* ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	return (write(1, str, ft_strlen(str)));
}

int		count_hexadecimal(uintptr_t n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n /= 16;
		counter++;
	}
	return (counter + 2);
}

void	print_hexadecimal(uintptr_t n)
{
	if (n >= 16)
		print_hexadecimal(n / 16);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
}



int	handle_pointer(va_list* ap)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	ft_putstr_fd("0x", 1);
	print_hexadecimal((uintptr_t) ptr);
	return (count_hexadecimal((uintptr_t) ptr));
}

int	ft_putnbr(int number, int* counter)
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
		ft_putnbr(-number, counter);
	}
	else if (number >= 10)
	{
		ft_putnbr(number / 10, counter);
		ft_putchar_fd(number % 10 + '0', 1);
	}
	else
		ft_putchar_fd(number + '0', 1);
	return (*counter);
}

int	ft_putnbr_unsigned(unsigned int number, int* counter)
{
	*counter = *counter + 1;
	if (number >= 10)
	{
		ft_putnbr_unsigned(number / 10, counter);
		ft_putchar_fd(number % 10 + '0', 1);
	}
	else
		ft_putchar_fd(number + '0', 1);
	return (*counter);
}

int	handle_decimal(va_list* ap, int not_signed)
{
	int	counter;

	counter = 0;
	if (not_signed == 0)
		return (ft_putnbr(va_arg(*ap, int), &counter));
	else 
		return (ft_putnbr_unsigned(va_arg(*ap, unsigned int), &counter));
}

int	print_flag(char flag, va_list* ap)
{
	if (flag == 'c')
		return (handle_char(ap));
	else if (flag == 's')
		return (handle_string(ap));
	else if (flag == 'p')
		return (handle_pointer(ap));
	else if (flag == 'd' || flag == 'i')
		return (handle_decimal(ap, 0));
	else if (flag == 'u')
		return (handle_decimal(ap, 1));
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
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			written_chars++;
		}
		else
		{
			fmt++;
			written_chars += print_flag(*fmt, &ap);
		}
		fmt++;
	}
	va_end(ap);
	return (written_chars);
}
