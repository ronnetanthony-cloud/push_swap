/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:34:49 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:34:20 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_down_b(int *stack_b, int num, int size_of_b)
{
	int	i;

	i = 0;
	while (stack_b[i] != num)
		i++;
	if (i > size_of_b / 2)
		return (0);
	return (1);
}

int	up_a(int *stack_a, int num, int size_of_a, t_stack *stack)
{
	int	i;
	int	temp;
	int	res;

	i = 0;
	temp = stack->max;
	if (num > temp)
		stack->max = num;
	res = 0;
	while (i < size_of_a)
	{
		if (num < stack_a[i] && temp >= stack_a[i])
		{
			temp = stack_a[i];
			res = i;
		}
		i++;
	}
	if (size_of_a - res < size_of_a / 2)
		return (0);
	return (1);
}

int	up_down_a(int *stack_a, int num, int size_of_a)
{
	int	i;

	i = 0;
	while (stack_a[i] != stack_a[num])
		i++;
	if (i > size_of_a / 2)
		return (0);
	return (1);
}
