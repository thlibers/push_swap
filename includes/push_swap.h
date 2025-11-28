/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/26 15:39:57 by thlibers         ###   ########.fr       */
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
int		*check_allnconvert(char **tab, char **tmp, int *size);

// parsing.c
int		*parsing(char **tab, int *size);
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

/* === ALGORITHM === */
// init_stack.c
void	init_stack(t_stack *stack, int *numbers, int size);

// sort_stack.c
void	chunk_sort(t_stack *stack);

// mini_sort.c
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);

// utils.c
t_data	*ft_lstnew_mod(int data);
int		index_max_in_b(t_data *b);
int		index_max_pos(t_data *b, int index);
int		get_stack_size(t_data *stack);

#endif