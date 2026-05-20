/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:34:27 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:34:28 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	char	*nbr;
	int		size;

	nbr = ft_itoa(n);
	if (!nbr)
		return (-1);
	size = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (size);
}
