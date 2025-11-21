/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:46:54 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/21 17:54:29 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int ac, char **av)
{
	int i = 0;
	int j = 0;
	char **tab;
	
	if(ac == 2)
		tab = ft_split(av[1], ' ');
	if (ac > 2)
	{
		tab = malloc (sizeof(char *) * (ac + 1));
		while (av[i])
		{
			tab[j] = ft_strdup(av[i]);
			i++;
			j++;
		}
		tab[j] = NULL;
	}
	ft_printf("%d", parsing(tab));
}