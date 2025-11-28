/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:47:13 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/24 18:56:06 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack, int print)
{
	t_data	*first;
	t_data	*last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	stack->a = first->next;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, int print)
{
	t_data	*first;
	t_data	*last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	stack->b = first->next;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	ft_printf("rr\n");
}
