/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:17:33 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/21 17:46:29 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_duplicate(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(tab[j], tab[i]) == 0)
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_elements(char **tab)
{
	int i;
	int j;

	i = 0;
	while(tab[i])
	{
		j = 0;
		if (tab[i][j] == '+' || tab[i][j] == '-')
			j++;
		if(!tab[i][j])
			return (ft_printf("Error\n"), 0);
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_overflow(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
			return (ft_printf("Error\n"), 0);
		i++;
	}
	return (1);
}

int *convert(char **tab)
{
	int *result;
	int i;

	i = 0;
	while(tab[i])
		i++;
	result = malloc(sizeof(int) * i);
	if (!result)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		result[i] = ft_atoi(tab[i]);
		i++;
	}
	return (result);
}

int parsing(char **tab)
{
	if (!tab)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_duplicate(tab) || !check_elements(tab) || !check_overflow(tab))
		return (0);
	return (1);
}
