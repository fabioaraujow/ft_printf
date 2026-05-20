/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:34:00 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:34:02 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_nlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_nbr_zero(void)
{
	char	*nbrs;

	nbrs = malloc(2 * sizeof(char));
	if (!nbrs)
		return (NULL);
	nbrs[0] = '0';
	nbrs[1] = '\0';
	return (nbrs);
}

static char	*ft_nbr_processor(unsigned int n)
{
	char	*nbrs;
	int		i;
	int		size;

	size = ft_nlen(n);
	nbrs = malloc((size + 1) * sizeof(char));
	if (!nbrs)
		return (NULL);
	i = (size - 1);
	while (n > 0)
	{
		nbrs[i] = '0' + (n % 10);
		n = ((n) / 10);
		i--;
	}
	nbrs[size] = '\0';
	return (nbrs);
}

static char	*ft_unsigneditoa(unsigned int n)
{
	if (n == 0)
		return (ft_nbr_zero());
	return (ft_nbr_processor(n));
}

int	ft_putunsigned_pf(unsigned int n)
{
	char	*nbr;
	int		size;

	nbr = ft_unsigneditoa(n);
	if (!nbr)
		return (-1);
	size = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (size);
}
