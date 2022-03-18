/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:37:01 by sylvain           #+#    #+#             */
/*   Updated: 2022/03/18 11:48:54 by sylvain          ###   ########.fr       */
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

int	print_flag(char flag, va_list* ap)
{
	if (flag == 'c')
		return (handle_char(ap));
	else if (flag == 's')
		return (handle_string(ap));
	else if (flag == 'p')
		return (handle_pointer(ap));
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
