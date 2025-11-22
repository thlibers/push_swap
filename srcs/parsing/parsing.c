/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:17:33 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/22 15:49:39 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void free_tab(char **tab)
{
	int i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int *parsing(char **tab)
{
	char **newtab;
	char **splitav;
	int *conversion;

	if (!tab || !tab[0])
		return (ft_printf("Error\n"), NULL);
	splitav = NULL;
	if (!tab[1])
	{
		splitav = ft_split(tab[0], ' ');
		if (!splitav || !splitav[0])
		{
			free_tab(splitav);
			return (ft_printf("Error\n"), NULL);
		}
		newtab = splitav;
	}
	else
		newtab = tab;
	conversion = check_allnconvert(newtab, splitav);
	return (conversion);
}
