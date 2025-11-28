/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:25:03 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/25 11:51:03 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack *stack)
{
	t_data	*tmp;

	if (!stack || !stack->b)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = stack->a;
	stack->a = tmp;
	stack->size_a++;
	stack->size_b--;
	ft_printf("pa\n");
}

void	pb(t_stack *stack)
{
	t_data	*tmp;

	if (!stack || !stack->a)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = stack->b;
	stack->b = tmp;
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}
