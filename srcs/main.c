/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:46:54 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/26 16:08:17 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* === Parsing === */

// int	main(int ac, char **av)
// {
// 	int	*nums;

// 	if (ac < 2)
// 		return (0);
// 	nums = parsing(av + 1);
// 	if (!nums)
// 		return (1);
// 	free(nums);
// 	return (0);
// }

/* === Push_Swap === */

void	free_stack(t_stack *stack, int *numbers)
{
	t_data	*tmp;

	while (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while (stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	free(numbers);
	free(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		*numbers;
	int		size;

	size = 0;
	if (ac < 2)
		return (1);
	numbers = parsing(av, &size);
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free(numbers);
		return (1);
	}
	init_stack(stack, numbers, size);
	chunk_sort(stack);
	free_stack(stack, numbers);
	return (0);
}
