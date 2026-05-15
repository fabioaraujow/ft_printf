/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:36 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:45:44 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*founded;
	char	chr;

	p = (char *) s;
	chr = (char) c;
	founded = NULL;
	if (chr == '\0')
	{
		while (*p)
		{
			p++;
		}
		return (p);
	}
	while (*p)
	{
		if (*p == chr)
			founded = p;
		p++;
	}
	if (!founded)
		return (NULL);
	return (founded);
}
