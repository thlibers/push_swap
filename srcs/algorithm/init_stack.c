/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:21:46 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/26 16:06:14 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	stack_init(t_stack *stack, int *numbers, int size)
{
	t_data	*new;
	t_data	*last;
	int		i;

	i = 0;
	last = NULL;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = size;
	stack->size_b = 0;
	while (i < size)
	{
		new = ft_lstnew_mod(numbers[i]);
		if (stack->a == NULL)
			stack->a = new;
		else
			last->next = new;
		last = new;
		i++;
	}
}

static void	bubble_sort(int *numbers, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
			{
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assigned_index(t_data *stack, int *numbers, int size)
{
	t_data	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->data == numbers[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	init_stack(t_stack *stack, int *numbers, int size)
{
	stack_init(stack, numbers, size);
	bubble_sort(numbers, size);
	assigned_index(stack->a, numbers, size);
}
