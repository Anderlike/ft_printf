/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:56:57 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/05/09 15:36:02 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_len;
	int		i;

	array = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !array)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			array[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	array[i] = NULL;
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**array;
	char	*s;
	char	c;
	int		i;

	s = "Boas meus tropas";
	c = ' ';
	array = ft_split(s, c);
	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}
 */