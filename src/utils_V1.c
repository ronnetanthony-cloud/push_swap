/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_V1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:20:35 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/02 22:24:28 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_hexa(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_printf_hexa(nbr / 16, base);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}

int	ft_put_hexaa(unsigned long str)
{
	char	*base;
	int		count;

	if (str == 0)
	{
		count = ft_putstr("(nil)");
		return (count);
	}
	base = "0123456789abcdef";
	write(1, "0x", 2);
	count = ft_printf_hexa(str, base);
	return (count + 2);
}

int	ft_hexa_lower(unsigned int n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = ft_printf_hexa(n, base);
	return (count);
}

int	ft_hexa_upper(unsigned int nbr)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = ft_printf_hexa(nbr, base);
	return (count);
}
