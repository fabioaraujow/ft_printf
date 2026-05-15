/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabde-ar <fabde-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:42:45 by fabde-ar          #+#    #+#             */
/*   Updated: 2026/04/21 17:47:19 by fabde-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	return (1);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	int	ret_ft_isascii;

	if (ac == 2)
	{
		ret_ft_isascii = ft_isascii(av[1][0]);
		if ((isascii(av[1][0]) != 0) == ret_ft_isascii)
		{
			printf("Return from std function: %d\n", (isascii(av[1][0]) != 0));
			printf("Return from my function: %d\n", ft_isascii(av[1][0]));
			printf("Rhe function is running like the original.\n");
		}
		if (ret_ft_isascii != 1)
			printf("The typed character isn't from ASCII.\n");
		else
			printf("The typed character is from ASCII.\n");
		}
	return (0);
}
*/
