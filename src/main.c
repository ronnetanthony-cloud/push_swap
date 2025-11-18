/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:52:42 by aronnet           #+#    #+#             */
/*   Updated: 2025/11/13 00:38:19 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	*parse_arguments(char **argv, int size)
{
	int				*numbers;
	long long int	i;
	long long int	tmp;

	numbers = malloc(sizeof(int) * (size));
	if (!numbers)
		error_exit();
	i = 0;
	while (i < size)
	{
		if (!is_valid_number(argv[i]))
		{
			free(numbers);
			error_exit();
		}
		tmp = ft_atoi(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			free(numbers);
			error_exit();
		}
		numbers[i] = (int)tmp;
		i++;
	}
	return (numbers);
}

void	init_stack_values(t_stack *stack, int size)
{
	int	i;

	i = 0;
	stack->max = stack->stack_a[0];
	stack->min = stack->stack_a[0];
	while (i < size)
	{
		if (stack->stack_a[i] > stack->max)
			stack->max = stack->stack_a[i];
		if (stack->stack_a[i] < stack->min)
			stack->min = stack->stack_a[i];
		i++;
	}
}

void	verify_sort(int size, t_stack *stack)
{
	if (size == 2)
		sort_two(stack->stack_a);
	else if (size == 3)
		sort_three(stack->stack_a);
	else if (size > 100)
		push_turk_algo(stack, size);
	else
		push_turk_algo_100(stack, size);
}

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i + 1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**str;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		argc = len_str(str);
		stack.stack_a = parse_arguments(str, argc - 1);
		free_all(str);
	}
	else
		stack.stack_a = parse_arguments(argv + 1, argc - 1);
	verif(&stack, argc);
	init_stack_values(&stack, argc - 1);
	if (!is_sorted(stack.stack_a, argc - 1))
		verify_sort(argc - 1, &stack);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
