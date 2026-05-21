/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:32:46 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:32:51 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_dispatcher(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_putchar_pf(va_arg(ap, int)));
	if (spec == 's')
		return (ft_putstr_pf(va_arg(ap, char *)));
	if (spec == 'p')
		return (ft_putptr_pf(va_arg(ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_pf(va_arg(ap, int)));
	if (spec == 'u')
		return (ft_putunsigned_pf(va_arg(ap, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_puthex_pf(va_arg(ap, unsigned int), spec));
	return (ft_putchar_pf(spec));
}

static int	ft_process(const char *format, int *i, va_list ap)
{
	int	ret;

	if (format[*i] == '%')
	{
		ret = ft_check_dispatcher(format[*i + 1], ap);
		*i += 2;
	}
	else
	{
		ret = ft_putchar_pf(format[*i]);
		(*i)++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		ret;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		ret = ft_process(format, &i, ap);
		if (ret == -1)
			return (va_end(ap), -1);
		count += ret;
	}
	va_end(ap);
	return (count);
}
