/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:33:41 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/05/20 09:33:43 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int n);
int	ft_putunsigned_pf(unsigned int n);
int	ft_puthex_pf(unsigned int n, char spfr);
int	ft_putptr_pf(void *ptr);

#endif
