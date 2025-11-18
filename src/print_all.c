/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:09:15 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:34:29 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	price_max(int *stack_a, int size_of_a)
{
	int	i;
	int	num;
	int	temp;

	i = 0;
	num = stack_a[i];
	temp = i;
	while (i < size_of_a)
	{
		if (stack_a[i] > num)
		{
			num = stack_a[i];
			temp = i;
		}
		i++;
	}
	return (temp);
}

int	price_min(int *stack_a, int size_of_a)
{
	int	i;
	int	num;
	int	temp;

	i = 0;
	num = stack_a[i];
	temp = i;
	while (i < size_of_a)
	{
		if (stack_a[i] < num)
		{
			num = stack_a[i];
			temp = i;
		}
		i++;
	}
	return (temp);
}

void	print_stack(int *stack_a, int size_of_a)
{
	int	i;

	i = 0;
	while (i < size_of_a)
	{
		ft_printf("%d ", stack_a[i]);
		i++;
	}
	write(1, "\n", 1);
}
