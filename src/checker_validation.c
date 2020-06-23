/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:25:32 by mburnett          #+#    #+#             */
/*   Updated: 2020/06/19 16:08:51 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		checker_valid_duplicates(char **av)
{
	int i;
	int count;
	int j;
	int num;

	i = 0;
	while (av[++i])
	{
		num = ft_atoi(av[i]);
		j = 1;
		count = 0;
		while (av[j])
		{
			if (ft_atoi(av[j]) == num)
				count++;
			j++;
		}
		if (count > 1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int		checker_valid_overflow(char **av)
{
	int i;
	int num;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (((num == 0 || num == -1) && ft_strlen(av[i]) > 2)
			|| (ft_atoi(av[i]) != ft_longatoi(av[i])))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (checker_valid_duplicates(av));
}

int		checker_valid_isdigit(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (checker_valid_overflow(av));
}

int		checker_valid_command(char *str)
{
	if (ft_strcmp("sa", str) == 0 || ft_strcmp("sb", str) == 0 ||
		ft_strcmp("ss", str) == 0 || ft_strcmp("pa", str) == 0 ||
		ft_strcmp("pb", str) == 0 || ft_strcmp("ra", str) == 0 ||
		ft_strcmp("rb", str) == 0 || ft_strcmp("rr", str) == 0 ||
		ft_strcmp("rra", str) == 0 || ft_strcmp("rrb", str) == 0 ||
		ft_strcmp("rrr", str) == 0)
		return (1);
	return (0);
}
