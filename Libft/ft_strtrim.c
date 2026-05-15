/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:20 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:27 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	s1_len;
	size_t	i;
	size_t	j;

	s1_len = (ft_strlen(s1) - 1);
	i = 0;
	j = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > i && ft_strchr(set, s1[s1_len]))
		s1_len--;
	trim = calloc(((s1_len - i) + 2), sizeof(char));
	if (!trim)
		return (NULL);
	while (i <= s1_len)
	{
		trim[j++] = s1[i++];
	}
	return (trim);
}
