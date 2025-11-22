/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/22 14:49:01 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylibft/get_next_line.h"
# include "../mylibft/libft.h"
# include "../mylibft/printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	struct s_data	*next;
	int				data;
	int				index;
}					t_data;

typedef struct s_stack
{
	t_data			*a;
	t_data			*b;
	int				size_a;
	int				size_b;
}					t_stack;

/* === PARSING === */
// checks.c
int		*check_allnconvert(char **tab, char **tmp);

// parsing.c
int		*parsing(char **tab);
void	free_tab(char **tab);

/* === OPERATIONS === */
// push.c
void	pa(t_stack *stack);
void	pb(t_stack *stack);

// reverse.c
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack);

// rotate.c
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack);

// swap.c
void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack);

#endif