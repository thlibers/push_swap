/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:43:55 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/21 12:37:53 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack, int print)
{
	t_data	*first;
	t_data	*second;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, int print)
{
	t_data	*first;
	t_data	*second;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	sa(stack, 1);
	sb(stack, 1);
	ft_printf("ss\n");
}
