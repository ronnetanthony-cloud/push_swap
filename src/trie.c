/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:11:44 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:35:41 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trie_b(int i, int *stack_b, int size_of_b, int price)
{
	if (up_down_b(stack_b, i, size_of_b))
	{
		while (price != 0)
		{
			rb(stack_b, size_of_b);
			price--;
		}
	}
	else
	{
		while (price != 0)
		{
			rrb(stack_b, size_of_b);
			price--;
		}
	}
}

void	trie_both(t_stack *stack)
{
	int	nbr;
	int	price;

	price = same_op(stack, the_worth(stack));
	nbr = stack->stack_b[the_worth(stack)];
	if (up_down_b(stack->stack_b, nbr, stack->size_of_b))
	{
		while (price != 0)
		{
			rr(stack->stack_a, stack->stack_b, stack->size_of_a,
				stack->size_of_b);
			price--;
		}
	}
	else
	{
		while (price != 0)
		{
			rrr(stack->stack_a, stack->stack_b, stack->size_of_a,
				stack->size_of_b);
			price--;
		}
	}
}

void	trie_a(int nmb, t_stack *stack, int price)
{
	if (up_a(stack->stack_a, nmb, stack->size_of_a, stack))
	{
		while (price != 0)
		{
			ra(stack->stack_a, stack->size_of_a);
			price--;
		}
	}
	else
	{
		while (price != 0)
		{
			rra(stack->stack_a, stack->size_of_a);
			price--;
		}
	}
}

void	trie_after(int nmb, int *stack_a, int size_of_a, int price)
{
	if (up_down_a(stack_a, nmb, size_of_a))
	{
		while (price != 0)
		{
			ra(stack_a, size_of_a);
			price--;
		}
	}
	else
	{
		while (price != 0)
		{
			rra(stack_a, size_of_a);
			price--;
		}
	}
}

void	trie_again(int *stack_a, int size_of_a)
{
	int	i;
	int	price;

	i = price_min(stack_a, size_of_a);
	price = price_to_a(i, size_of_a);
	trie_after(i, stack_a, size_of_a, price);
}
