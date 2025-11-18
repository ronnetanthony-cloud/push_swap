/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:19:41 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:35:07 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_worth(t_stack *stack)
{
	int	price;
	int	temp;
	int	res;
	int	i;

	i = the_worth(stack);
	temp = price_to_a(i, stack->size_of_b);
	price = price_sort(stack->stack_b[i], stack->stack_a, stack->size_of_a);
	res = same_op(stack, i);
	trie_both(stack);
	trie_b(stack->stack_b[i], stack->stack_b, stack->size_of_b, temp - res);
	trie_a(stack->stack_b[0], stack, price - res);
	pa(stack->stack_a, stack->stack_b, stack->size_of_a, stack->size_of_a
		+ stack->size_of_b);
}

int	price_sort(int num_b, int *stack_a, int size_of_a)
{
	int	i;
	int	temp;
	int	res;

	i = 0;
	temp = stack_a[price_max(stack_a, size_of_a)];
	if (num_b > temp)
		return (price_max(stack_a, size_of_a) + 1);
	res = i;
	while (i < size_of_a)
	{
		if (num_b < stack_a[i] && temp >= stack_a[i])
		{
			temp = stack_a[i];
			res = i;
		}
		i++;
	}
	if (size_of_a - res < size_of_a / 2)
		return (size_of_a - res);
	return (res);
}

int	price_to_a(int index_b, int size_of_b)
{
	int	count;

	count = 0;
	count = size_of_b - index_b;
	if (count < index_b)
		return (count);
	return (index_b);
}
