/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:30:07 by sylvain           #+#    #+#             */
/*   Updated: 2021/12/14 15:09:07 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	if (*s && *s != c)
	{
		words++;
		s++;
	}
	while (*s)
	{
		if (*s != c && s[-1] == c)
			words++;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		current_word;
	int		current_letter;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	current_word = 0;
	while (*s)
	{
		current_letter = 0;
		while (s[current_letter] && s[current_letter] != c)
			current_letter++;
		if (current_letter)
		{
			result[current_word++] = ft_substr(s, 0, current_letter);
			s = &s[current_letter];
		}
		else
			s++;
	}
	result[current_word] = NULL;
	return (result);
}
