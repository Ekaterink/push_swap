/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_first_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:27:36 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:28:12 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

char	*del_substr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i - 1] && str[i - 1] == ' ' && str[i] != ' ')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*exist_str(char *str, int count)
{
	if (ft_strchr(str, (int)' ') == 0 && count == 0)
		return (str);
	if (ft_strchr(str, (int)' ') == 0 && count == 1)
		return (NULL);
	else
	{
		if (count == 0)
			return (str);
		else
		{
			return (del_substr(str));
		}
	}
}
