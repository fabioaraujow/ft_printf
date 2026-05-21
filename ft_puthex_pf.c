/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:34:14 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:34:15 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
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

static char	*ft_zero(void)
{
	char	*hex_zero;

	hex_zero = malloc(2 * sizeof(char));
	if (!hex_zero)
		return (NULL);
	hex_zero[0] = '0';
	hex_zero[1] = '\0';
	return (hex_zero);
}

static char	*ft_processor(unsigned int n, char spfr)
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
		else if (spfr == 'x')
			digit = 'a' + (mod - 10);
		else if (spfr == 'X')
			digit = 'A' + (mod - 10);
		n = n / 16;
		hex[i--] = digit;
	}
	hex[size] = '\0';
	return (hex);
}

int	ft_puthex_pf(unsigned int n, char spfr)
{
	char	*puthex;
	int		size;

	if (n == 0)
		puthex = ft_zero();
	else
		puthex = ft_processor(n, spfr);
	if (!puthex)
		return (-1);
	size = write(1, puthex, ft_strlen(puthex));
	free(puthex);
	return (size);
}
