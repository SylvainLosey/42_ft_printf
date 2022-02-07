/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:44:02 by slosey            #+#    #+#             */
/*   Updated: 2021/12/14 16:57:25 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		s1_len;

	s1_len = ft_strlen(s1);
	copy = (char *) malloc(sizeof(*s1) * (s1_len + 1));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, s1_len + 1);
	return (copy);
}
