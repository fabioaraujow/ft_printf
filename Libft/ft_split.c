/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:20 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:27 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

static size_t	ft_interlen(const char *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char	**ft_spcpy(const char *src, char **dest, char c, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[start])
	{
		dest[i] = ft_calloc((ft_interlen(src, c, start) + 1), sizeof(char));
		if (!dest[i])
		{
			while (i > 0)
				free(dest[--i]);
			return (NULL);
		}
		j = 0;
		while (src[start] && src[start] != c)
		{
			dest[i][j] = src[start];
			start++;
			j++;
		}
		while (src[start] == c)
			start++;
		i++;
	}
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**splited;
	size_t	start;

	splited = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!splited)
		return (NULL);
	start = 0;
	while (s[start] == c)
		start++;
	if (!ft_spcpy(s, splited, c, start))
	{
		free(splited);
		return (NULL);
	}
	return (splited);
}
