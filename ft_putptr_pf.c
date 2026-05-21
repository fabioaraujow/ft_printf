/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:00:39 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 11:00:48 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	*ft_processor(unsigned long n)
{
	char	*hex;
	char	mod;
	char	digit;
	int		size;
	int		i;

	size = ft_hexlen(n);
	hex = malloc((size + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	i = (size - 1);
	while (n > 0)
	{
		mod = n % 16;
		if (mod < 10)
			digit = '0' + mod;
		else
			digit = 'a' + (mod - 10);
		n = n / 16;
		hex[i--] = digit;
	}
	hex[size] = '\0';
	return (hex);
}

int	ft_putptr_pf(void *ptr)
{
	unsigned long	address;
	char			*hex;
	char			*str_hex;
	int				size;

	address = (unsigned long)ptr;
	if (address == 0)
		return (write(1, "(nil)", 5));
	hex = ft_processor(address);
	if (!hex)
		return (-1);
	str_hex = ft_strjoin("0x", hex);
	if (!str_hex)
	{
		free(hex);
		return (-1);
	}
	size = write(1, str_hex, ft_strlen(str_hex));
	free(str_hex);
	free(hex);
	return (size);
}
