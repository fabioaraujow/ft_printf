/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:20 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:27 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_edgecases(int n)
{
	char	*nbrs;

	if (n == 0)
	{
		nbrs = malloc(2 * sizeof(char));
		if (!nbrs)
			return (NULL);
		nbrs[0] = '0';
		nbrs[1] = '\0';
		return (nbrs);
	}
	nbrs = malloc(12 * sizeof(char));
	if (!nbrs)
		return (NULL);
	ft_strlcpy(nbrs, "-2147483648", 12);
	return (nbrs);
}

static char	*ft_negprocessor(int n)
{
	char	*nbrs;
	size_t	i;
	size_t	size;

	n = -n;
	size = ft_nlen(n);
	nbrs = malloc((size + 2) * sizeof(char));
	if (!nbrs)
		return (NULL);
	nbrs[0] = '-';
	i = size;
	while (n > 0)
	{
		nbrs[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	nbrs[size + 1] = '\0';
	return (nbrs);
}

static char	*ft_nbrprocessor(int n)
{
	char	*nbrs;
	size_t	i;
	size_t	size;

	size = ft_nlen(n);
	nbrs = malloc((size + 1) * sizeof(char));
	if (!nbrs)
		return (NULL);
	i = size - 1;
	while (n > 0)
	{
		nbrs[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	nbrs[size] = '\0';
	return (nbrs);
}

char	*ft_itoa(int n)
{
	if (n == 0 || n == -2147483648)
		return (ft_edgecases(n));
	else if (n < 0)
		return (ft_negprocessor(n));
	return (ft_nbrprocessor(n));
}
