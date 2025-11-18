/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:15:18 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:34:59 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_max_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack->max = stack->stack_a[0];
	while (i < stack->size_of_a)
	{
		if (stack->stack_a[i] > stack->max)
			stack->max = stack->stack_a[i];
		i++;
	}
}

void	smart_push_to_b(t_stack *stack, int size)
{
	int	median;
	int	temp;

	median = find_median(stack->stack_a, size);
	temp = size;
	while (temp != 0 && stack->size_of_a > 3)
	{
		if (stack->stack_a[0] < median)
		{
			stack->size_of_b++;
			stack->size_of_a--;
			pb(stack->stack_a, stack->stack_b, stack->size_of_b, size);
		}
		else
			ra(stack->stack_a, stack->size_of_a);
		temp--;
	}
	while (stack->size_of_a != 3)
	{
		pb(stack->stack_a, stack->stack_b, stack->size_of_b, size);
		stack->size_of_b++;
		stack->size_of_a--;
	}
	update_max_a(stack);
}

void	optimize_b_during_push(t_stack *stack)
{
	if (stack->size_of_b >= 2)
	{
		if (stack->stack_b[0] < stack->stack_b[1])
			sb(stack->stack_b, stack->size_of_b);
	}
}

void	push_turk_algo(t_stack *stack, int size)
{
	stack->size_of_b = 0;
	stack->size_of_a = size;
	smart_push_to_b(stack, size);
	optimize_b_during_push(stack);
	stack->size_of_a = 3;
	sort_three(stack->stack_a);
	while (stack->size_of_b != 0)
	{
		price_worth(stack);
		stack->size_of_a++;
		stack->size_of_b--;
		update_max_a(stack);
	}
	if (is_sorted(stack->stack_a, stack->size_of_a))
		return ;
	trie_again(stack->stack_a, stack->size_of_a);
}

void	push_turk_algo_100(t_stack *stack, int size)
{
	int	i;

	i = 0;
	stack->size_of_b = 0;
	while (size - i > 3)
	{
		stack->size_of_b++;
		pb(stack->stack_a, stack->stack_b, stack->size_of_b, size);
		i++;
	}
	stack->size_of_a = 3;
	update_max_a(stack);
	sort_three(stack->stack_a);
	while (stack->size_of_b != 0)
	{
		price_worth(stack);
		stack->size_of_a++;
		stack->size_of_b--;
		update_max_a(stack);
	}
	if (is_sorted(stack->stack_a, stack->size_of_a))
		return ;
	trie_again(stack->stack_a, stack->size_of_a);
}
