#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	unsigned char chr;

	chr = (unsigned char) c;
	return (write(1, &chr, 1));
}

