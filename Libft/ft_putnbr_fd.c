/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:20 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:27 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_processor(int n, char *dest, int fd)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		dest[i] = '0' + (n % 10);
		n = (n / 10);
		i++;
	}
	dest[i] = '\0';
	while (i > 0)
		ft_putchar_fd(dest[--i], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[11];

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_processor(n, nbr, fd);
}
