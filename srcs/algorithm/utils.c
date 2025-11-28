/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:05:49 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/26 15:22:35 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_data	*ft_lstnew_mod(int data)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	index_max_in_b(t_data *b)
{
	int	index_max;

	index_max = b->index;
	while (b)
	{
		if (b->index > index_max)
			index_max = b->index;
		b = b->next;
	}
	return (index_max);
}

int	index_max_pos(t_data *b, int index)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == index)
			return (i);
		b = b->next;
		i++;
	}
	return (-1);
}

int	get_stack_size(t_data *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
