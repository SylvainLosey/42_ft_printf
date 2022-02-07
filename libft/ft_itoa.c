/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:26:56 by sylvain           #+#    #+#             */
/*   Updated: 2021/12/14 15:14:40 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	result = (char *) malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	*(result + digits) = 0;
	while (digits--)
	{
		*(result + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*result = '-';
	return (result);
}
