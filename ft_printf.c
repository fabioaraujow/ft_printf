/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:32:46 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:32:51 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_dispatcher(const char *str, int i, va_list ap)
{
	int	pos;

	pos = i;
	if (str[i + 1] == 'c')
		return (ft_putchar_pf(va_arg(ap, int)));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = count + ft_check_dispatcher(format, i, ap);
			i++;
		}
		else
			ft_putchar_pf(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
