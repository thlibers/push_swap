/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/21 17:36:44 by thlibers         ###   ########.fr       */
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
int parsing(char **tab);


#endif