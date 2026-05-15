#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int n);
int	ft_putunsigned_pf(unsigned int n);
int	ft_puthex_pf(unsigned int n, char spfr);
int	ft_putptr_pf(void *ptr);

#endif
