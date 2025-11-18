/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_V2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:59:55 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/02 22:24:30 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr(int n)
{
	char		nb;
	long int	nbr;
	int			count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	nb = (nbr % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}

int	ft_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_unsigned(nbr / 10);
	nbr = (nbr % 10) + '0';
	count += write(1, &nbr, 1);
	return (count);
}
