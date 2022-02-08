/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slosey <slosey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:44:09 by slosey            #+#    #+#             */
/*   Updated: 2021/10/27 15:44:10 by slosey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	if (*haystack == '\0' || len == 0)
		return (NULL);
	if (*haystack == *needle
		&& ft_strnstr(haystack + 1, needle + 1, len - 1) == haystack + 1)
		return ((char *) haystack);
	return (ft_strnstr(haystack + 1, needle, len - 1));
}
