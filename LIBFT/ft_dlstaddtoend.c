//
// Created by student on 05.04.20.
//

#include "libft.h"
#include "dlist.h"

void	ft_dlstadd_to_end(t_dlist **alst, t_dlist **new)
{
	t_dlist *begin;

	begin = (*alst);
	if (begin)
	{
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = (*new);
		(*new)->previous = (*alst);
		(*new)->next = NULL;
		(*alst) = begin;
	}
}