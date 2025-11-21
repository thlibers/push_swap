/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:47:10 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/21 12:38:56 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack, int print)
{
	t_data	*tmp;
	t_data	*last;

	if (!stack->a || !stack->a->next)
		return ;
	tmp = stack->a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->a;
	stack->a = last;
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, int print)
{
	t_data	*tmp;
	t_data	*last;

	if (!stack->b || !stack->b->next)
		return ;
	tmp = stack->b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->b;
	stack->b = last;
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack, 1);
	rrb(stack, 1);
	ft_printf("rrb\n");
}
