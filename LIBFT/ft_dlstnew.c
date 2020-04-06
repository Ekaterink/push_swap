//
// Created by student on 05.04.20.
//

#include "libft.h"
#include "dlist.h"

t_dlist	*ft_dlstnew(int num)
{
	t_dlist		*list;

	if (!(list = (t_dlist *)malloc(sizeof(*list))))
		return (NULL);
	else
	{
		if (!(list->num = (int)malloc(sizeof(int))))
			return (NULL);
		list->num = num;
	}
	list->next = NULL;
	list->previous = NULL;
	return (list);
}