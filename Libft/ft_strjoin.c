/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:36 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:45:44 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*g_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	g_str = ft_calloc(((s1_len + s2_len) + 1), sizeof(char));
	i = 0;
	if (!g_str)
		return (NULL);
	while (*s1)
	{
		g_str[i] = *s1++;
		i++;
	}
	while (*s2)
		g_str[i++] = *s2++;
	g_str[i] = '\0';
	return (g_str);
}
