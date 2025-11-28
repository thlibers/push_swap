/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:12:53 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/27 11:08:40 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_sorted(t_stack *stack)
{
	t_data	*tmp;

	if (!stack->a)
		return (1);
	tmp = stack->a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	chunk_to_b(t_stack *stack)
{
	int	chunk;
	int	count;

	count = 0;
	if (stack->size_a <= 100)
		chunk = 20;
	else
		chunk = 30;
	while (stack->a)
	{
		if (stack->a->index <= count)
		{
			pb(stack);
			rb(stack, 0);
			count++;
		}
		else if (stack->a->index <= count + chunk)
		{
			pb(stack);
			count++;
		}
		else
			ra(stack, 0);
	}
}

static void	sort_to_a(t_stack *stack)
{
	int	maxindex;
	int	pos;

	while (stack->b)
	{
		maxindex = index_max_in_b(stack->b);
		pos = index_max_pos(stack->b, maxindex);
		if (pos <= get_stack_size(stack->b) / 2)
		{
			while (stack->b->index != maxindex)
				rb(stack, 0);
		}
		else
		{
			while (stack->b->index != maxindex)
				rrb(stack, 0);
		}
		pa(stack);
	}
}

void	chunk_sort(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (get_stack_size(stack->a) <= 2)
		return (sort_two(stack));
	else if (get_stack_size(stack->a) <= 3)
		return (sort_three(stack));
	else if (get_stack_size(stack->a) <= 4)
		return (sort_four(stack));
	else if (get_stack_size(stack->a) <= 5)
		return (sort_five(stack));
	else
	{
		chunk_to_b(stack);
		sort_to_a(stack);
		return ;
	}
}
