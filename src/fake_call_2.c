/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_call_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:18:34 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/10 13:59:03 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_rrb(int *b, int size)
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
}

void	fake_rra(int *a, int size)
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
}
