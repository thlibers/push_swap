/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:41:06 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/28 14:06:12 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_overflow(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atol(tab[i]) < -2147483648 || ft_atol(tab[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

static int	check_elements(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '+' || tab[i][j] == '-')
			j++;
		if (!tab[i][j])
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
			if (ft_atoi(tab[j]) - ft_atoi(tab[i]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	*convert(char **tab, int *size)
{
	int	*result;
	int	i;

	i = 0;
	while (tab[i])
		i++;
	*size = i;
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

int	*check_allnconvert(char **tab, char **tmp, int *size)
{
	int	*conversion;

	if (!check_overflow(tab) || !check_elements(tab) || !check_duplicate(tab))
	{
		if (tmp)
			free_tab(tmp);
		return (ft_putstr_fd("Error\n", 2), NULL);
	}
	conversion = convert(tab, size);
	if (!conversion)
		return (ft_putstr_fd("Error\n", 2), NULL);
	return (conversion);
}
