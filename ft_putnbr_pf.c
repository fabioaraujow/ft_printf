#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	char	*nbr;
	int	size;

	nbr = ft_itoa(n);
	if (!nbr)
		return (-1);
	size = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (size);
}
