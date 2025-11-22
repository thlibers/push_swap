/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:46:54 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/22 15:52:42 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ===Parsing=== */

int main(int ac, char **av)
{
    int		*nums;

    if (ac < 2)
        return (0);
    nums = parsing(av + 1);
    if (!nums)
        return (1);
    free(nums);
    return (0);
}
