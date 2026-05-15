/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:36 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:45:44 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_written;
	size_t	dst_size;
	size_t	i;

	src_size = ft_strlen(src);
	dst_written = ft_strlen(dst);
	dst_size = dst_written;
	i = 0;
	if (size == 0)
		return (src_size);
	if (size <= dst_written)
		return (size + src_size);
	while ((dst_written < size - 1) && (src[i]))
	{
		dst[dst_written] = src[i];
		dst_written++;
		i++;
	}
	dst[dst_written] = '\0';
	return ((src_size) + (dst_size));
}
