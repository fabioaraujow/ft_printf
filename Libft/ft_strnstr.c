/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:36 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:45:44 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ltt_len;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	ltt_len = ft_strlen(little);
	if (ltt_len > len)
		return (NULL);
	while ((i < len) && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((i + j < len) && (big[i + j])
				&& (little[j]) && (big[i + j] == little[j]))
				j++;
			if (j == ltt_len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
