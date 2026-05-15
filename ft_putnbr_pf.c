#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

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

int	main(void)
{
	int	size = ft_putnbr_pf(-42);
	printf("\n");
	printf("%d\n", size);
	return (0);
}
