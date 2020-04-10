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

#include "libft.h"
#include "dlist.h"

t_dlist	*ft_dlstnew(int num)
{
	t_dlist		*list;

	if (!(list = (t_dlist *)malloc(sizeof(*list))))
		return (NULL);
	else
	{
		list->num = num;
	}
	list->next = NULL;
	list->previous = NULL;
	return (list);
}
