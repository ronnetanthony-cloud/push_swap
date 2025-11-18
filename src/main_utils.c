/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:48:06 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/13 00:37:28 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 10)
		error_exit();
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	verif(t_stack *stack, int argc)
{
	if (has_duplicates(stack->stack_a, argc - 1))
	{
		free(stack->stack_a);
		error_exit();
	}
	stack->stack_b = malloc(sizeof(int) * (argc - 1));
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		error_exit();
	}
}
