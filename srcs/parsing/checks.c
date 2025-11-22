/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:41:06 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/22 15:35:05 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_duplicate(char **tab)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int check_elements(char **tab)
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
			return (0);
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int check_overflow(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int *convert(char **tab)
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

int *check_allnconvert(char **tab, char **tmp)
{
	int *conversion;
	
	if (!check_duplicate(tab) || !check_elements(tab) || !check_overflow(tab))
	{
		if (tmp)
			free_tab(tmp);
		return (ft_printf("Error\n"), NULL);
	}
	conversion = convert(tab);
	if (!conversion)
        return (ft_printf("Error\n"), NULL);
	return (conversion);
}
