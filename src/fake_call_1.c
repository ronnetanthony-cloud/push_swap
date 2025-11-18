/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_call_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:32:27 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/04 20:07:24 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_ra(int *a, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = a[0];
	i = 0;
	while (i < size)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size] = temp;
}

void	fake_rb(int *b, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	temp = b[0];
	i = 0;
	while (i < size)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size] = temp;
}

void	fakee_ra(int *a, int size)
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
}

void	fakee_rb(int *b, int size)
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
}
