/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:36 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:45:44 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size_s;
	size_t	i;

	size_s = ft_strlen(s);
	if (start > size_s)
		return (ft_calloc(1, sizeof(char)));
	substr = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (!substr)
		return (NULL);
	while ((i < len) && s[start])
	{
		substr[i++] = s[start++];
	}
	return (substr);
}
