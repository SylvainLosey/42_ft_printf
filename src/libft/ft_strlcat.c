/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slosey <slosey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:44:05 by slosey            #+#    #+#             */
/*   Updated: 2021/10/27 15:44:06 by slosey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int			str_len_dst;
	int			n;
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	n = size;
	while (n-- && *destination)
		destination++;
	str_len_dst = destination - dst;
	n = size - str_len_dst;
	if (n == 0)
		return (str_len_dst + ft_strlen(source));
	while (*source)
	{
		if (n != 1)
		{
			*destination++ = *source;
			n--;
		}
		source++;
	}
	*destination = '\0';
	return (str_len_dst + (source - src));
}
