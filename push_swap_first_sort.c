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

void	first_sort3(t_dlist **stack_a, t_dlist **stack_b, int max, int min)
{
	int count;
	int all_num;

	count = 0;
	all_num = ft_dlistlen((*stack_a));
	while ((*stack_a) && count < all_num)
	{
		if (((*stack_a)->num < (max - min) / 1.5 + 1) &&
		(*stack_a)->num != max && (*stack_a)->num != min)
		{
			if ((*stack_a)->num < (max - min) / 3 + 1 &&
			(*stack_a)->num != max && (*stack_a)->num != min)
			{
				write_function(&(*stack_b), &(*stack_a), "pb");
				write_function2(&(*stack_b), "rb");
			}
			else
				write_function(&(*stack_b), &(*stack_a), "pb");
		}
		else
			write_function2(&(*stack_a), "ra");
		count++;
	}
}

void	first_sort2(t_dlist **stack_a, t_dlist **stack_b)
{
	int max;
	int min;

	max = find_max_int((*stack_a));
	min = find_min_int((*stack_a));
	first_sort3(stack_a, stack_b, max, min);
	while (ft_dlistlen(*stack_a) != 2)
	{
		if ((*stack_a)->num == max || (*stack_a)->num == min)
			write_function2(&(*stack_a), "ra");
		else
			write_function(&(*stack_b), &(*stack_a), "pb");
	}
}

int		find_order(t_dlist *list, int num)
{
	int i;

	i = 1;
	while (num != list->num)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char    *del_substr(char *str)
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

int     is_substr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}


char    *exist_str(char *str, int count)
{
    if (is_substr(str, ' ') == 0 && count == 0) // просто число
        return (str);
    else if (is_substr(str, ' ') == 0 && count == 1) // просто число
        return (NULL);
    else // там строка
    {
        if (count == 0) // первая цифра
            return (str);
        else // удаляем цифру и пробел, если есть
        {
            return (del_substr(str));
        }
    }
}

t_dlist	*get_stack_a(char **av)
{
	t_dlist	*new;
	t_dlist	*begin;
	int		i;
	char    *new_str;
	int     j;

	i = 1;
//	begin = ft_dlstnew(ft_atoi(av[1]));
    begin = NULL;
	while (av[i])
	{
        j = 0;
        new_str = av[i];
	    while ((new_str = exist_str(new_str, j)) != NULL)
        {
            new = ft_dlstnew(ft_atoi(new_str));
            ft_dlstadd_to_end(&begin, &new);
            j++;
        }
		i++;
	}
	return (begin);
}
