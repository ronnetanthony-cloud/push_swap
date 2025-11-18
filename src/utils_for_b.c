/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:01:20 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:33:48 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(int *b, int size)
{
	int	temp;

	if (size <= 1)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "sb\n", 3);
}

void	pb(int *a, int *b, int size_of_b, int size)
{
	int	temp;
	int	temp2;
	int	i;

	i = 1;
	temp = b[0];
	b[0] = a[0];
	if (size_of_b == 0)
		return ;
	while (i != size_of_b)
	{
		temp2 = b[i];
		b[i] = temp;
		temp = temp2;
		i++;
	}
	b[i] = temp;
	a[0] = 0;
	fake_ra(a, size - size_of_b);
	write(1, "pb\n", 3);
}

void	rb(int *b, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = b[0];
	i = 0;
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size - 1] = temp;
	write(1, "rb\n", 3);
}

void	rrb(int *b, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = b[size - 1];
	i = size - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrb\n", 4);
}
