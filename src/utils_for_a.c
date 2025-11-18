/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:56:36 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:33:44 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int size)
{
	int	temp;

	if (size <= 1)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
}

void	pa(int *a, int *b, int size_of_a, int size)
{
	int	temp;
	int	temp2;
	int	i;

	i = 1;
	temp = a[0];
	a[0] = b[0];
	while (i != size_of_a)
	{
		temp2 = a[i];
		a[i] = temp;
		temp = temp2;
		i++;
	}
	a[i] = temp;
	b[0] = 0;
	fake_rb(b, size - size_of_a);
	write(1, "pa\n", 3);
}

void	ra(int *a, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	write(1, "ra\n", 3);
}

void	rra(int *a, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write(1, "rra\n", 4);
}
