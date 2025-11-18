/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:00:19 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:35:20 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_op(t_stack *stack, int i)
{
	int	price;
	int	temp;

	temp = price_to_a(i, stack->size_of_b);
	price = price_sort(stack->stack_b[i], stack->stack_a, stack->size_of_a);
	if (up_down_b(stack->stack_b, stack->stack_b[i], stack->size_of_b)
		&& up_a(stack->stack_a, stack->stack_b[i], stack->size_of_a, stack))
	{
		if (temp < price)
			return (temp);
		else
			return (price);
	}
	else if ((!(up_down_b(stack->stack_b, stack->stack_b[i], stack->size_of_b)))
		&& (!(up_a(stack->stack_a, stack->stack_b[i], stack->size_of_a,
					stack))))
	{
		if (temp < price)
			return (temp);
		else
			return (price);
	}
	return (0);
}

int	same_opp(t_stack *stack, int bb)
{
	int	price;
	int	temp;
	int	i;

	i = bb;
	temp = price_to_a(i, stack->size_of_b);
	price = price_sort(stack->stack_b[i], stack->stack_a, stack->size_of_a);
	if (up_down_b(stack->stack_b, stack->stack_b[i], stack->size_of_b)
		&& up_a(stack->stack_a, stack->stack_b[i], stack->size_of_a, stack))
	{
		if (temp < price)
			return (temp);
		else
			return (price);
	}
	else if ((!(up_down_b(stack->stack_b, stack->stack_b[i], stack->size_of_b)))
		&& (!(up_a(stack->stack_a, stack->stack_b[i], stack->size_of_a,
					stack))))
	{
		if (temp < price)
			return (temp);
		else
			return (price);
	}
	return (0);
}

int	the_worth(t_stack *stack)
{
	int	price;
	int	sort;
	int	temp;
	int	tempo;
	int	i;

	i = 0;
	if (stack->size_of_b == 0)
		return (0);
	temp = price_to_a(i, stack->size_of_b) + price_sort(stack->stack_b[i],
			stack->stack_a, stack->size_of_a);
	sort = 0;
	while (stack->size_of_b - i != 0)
	{
		price = price_to_a(i, stack->size_of_b) + price_sort(stack->stack_b[i],
				stack->stack_a, stack->size_of_a);
		tempo = same_opp(stack, i);
		if (price - tempo < temp)
		{
			temp = price - tempo;
			sort = i;
		}
		i++;
	}
	return (sort);
}

int	find_median(int *arr, int size)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = arr[0];
	min = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return ((max + min) / 2);
}
