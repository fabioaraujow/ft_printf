#include "ft_printf.h"

static	unsigned int	ft_nlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_edgecase(int n)
{
	char	*nbrs;

	if (n == 0)
	{
		nbrs = malloc(2* sizeof(char));
		if (!nbrs)
			return (NULL);
		nbrs[0] = '0';
		nbrs[1] = '\0';
	}
	return (nbrs);
}

static char	*ft_unsigneditoa(unsigned int n)
{

}

int	ft_putunsigned_pf(unsigned int n)
{

}
