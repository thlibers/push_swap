/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:17:33 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/27 12:14:07 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	*parsing(char **tab, int *size)
{
	char	**newtab;
	char	**splitav;
	int		*conversion;

	if (!tab || !tab[1])
		return (ft_putstr_fd("Error\n", 2), NULL);
	splitav = NULL;
	if (!tab[2])
	{
		splitav = ft_split(tab[1], ' ');
		if (!splitav || !splitav[0])
		{
			free_tab(splitav);
			return (ft_putstr_fd("Error\n", 2), NULL);
		}
		newtab = splitav;
	}
	else
		newtab = &tab[1];
	conversion = check_allnconvert(newtab, splitav, size);
	return (conversion);
}

