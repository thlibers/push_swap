/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:08:38 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/27 11:08:50 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_pos(t_data *stack, int index)
{
	t_data	*tmp;
	int		pos;

	tmp = stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

void	sort_two(t_stack *stack)
{
	if (stack->a->index > stack->a->next->index)
		sa(stack, 0);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a->index;
	second = stack->a->next->index;
	third = stack->a->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack, 0);
	else if (first > second && second > third)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 0);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 0);
		ra(stack, 0);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 0);
}

void	sort_four(t_stack *stack)
{
	while (stack->a->index != 0)
	{
		if (find_pos(stack->a, 0) <= 2)
			ra(stack, 0);
		else
			rra(stack, 0);
	}
	pb(stack);
	sort_three(stack);
	pa(stack);
}

void	sort_five(t_stack *stack)
{
	while (stack->size_b < 2)
	{
		if (stack->a->index == 0 || stack->a->index == 1)
			pb(stack);
		else
		{
			if (find_pos(stack->a, 0) <= 2 || find_pos(stack->a, 1) <= 2)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
	}
	sort_three(stack);
	if (stack->b->index == 0)
	{
		sb(stack, 0);
		pa(stack);
		pa(stack);
	}
	else
	{
		pa(stack);
		pa(stack);
	}
}
