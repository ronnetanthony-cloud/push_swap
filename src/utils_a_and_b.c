/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a_and_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:02:40 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 14:35:52 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *a, int *b, int size_a, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
	write(1, "ss\n", 3);
}

void	rr(int *a, int *b, int size_a, int size_b)
{
	fakee_ra(a, size_a);
	fakee_rb(b, size_b);
	write(1, "rr\n", 3);
}

void	rrr(int *a, int *b, int size_a, int size_b)
{
	fake_rra(a, size_a);
	fake_rrb(b, size_b);
	write(1, "rrr\n", 4);
}
