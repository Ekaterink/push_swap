/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:26:48 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:27:23 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

int		find_min_int(t_dlist *begin)
{
	t_dlist *min;

	min = begin;
	while (begin)
	{
		if (begin->num < min->num)
			min = begin;
		begin = begin->next;
	}
	return (min->num);
}

int		find_max_int(t_dlist *begin)
{
	int max;

	max = begin->num;
	while (begin)
	{
		if (begin->num > max)
			max = begin->num;
		begin = begin->next;
	}
	return (max);
}

int		find_end_int(t_dlist **list)
{
	t_dlist *tmp;

	tmp = (*list);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->num);
}

int		ft_dlistlen(t_dlist *begin)
{
	int i;

	i = 0;
	if (begin)
	{
		i++;
		while (begin->next != NULL)
		{
			begin = begin->next;
			i++;
		}
	}
	return (i);
}
