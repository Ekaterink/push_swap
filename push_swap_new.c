/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:28:25 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:32:16 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

size_t	is_sorted(t_dlist **stack_a)
{
	t_dlist	*list;
	int		prev;

	list = (*stack_a);
	prev = list->num;
	while (list->next)
	{
		list = list->next;
		if (list->num < prev)
			return (0);
		prev = list->num;
	}
	return (1);
}

size_t	check_place_if_not_sorted(t_dlist **stack_a)
{
	int		num;
	int		prev;
	size_t	count;
	t_dlist	*a;

	a = (*stack_a);
	count = 1;
	prev = a->num;
	while (a->next)
	{
		a = a->next;
		count++;
		num = a->num;
		if (num < prev)
		{
			if (count > (ft_dlistlen((*stack_a)) / 2))
				do_func(stack_a, "ra");
			else
				do_func(stack_a, "rra");
		}
		else
			prev = a->num;
	}
	return (0);
}

void	sort_three(t_dlist **a)
{
	if ((*a)->num < (*a)->next->num)
	{
		if ((*a)->num < (*a)->next->next->num)
		{
			write_function2(a, "sa");
			write_function2(a, "ra");
		}
		else
			write_function3(a, "rra");
	}
	else
	{
		if ((*a)->num < (*a)->next->next->num)
			write_function2(a, "sa");
		else if ((*a)->next->num > (*a)->next->next->num)
		{
			write_function2(a, "sa");
			write_function3(a, "rra");
		}
		else
		{
			write_function2(a, "ra");
		}
	}
}

void	sort_five(t_dlist **a, t_dlist **b)
{
	int	min;

	while (ft_dlistlen((*a)) != 3)
	{
		min = find_min_int((*a));
		if (find_order((*a), min) < ft_dlistlen((*a)) / 2)
		{
			while ((*a)->num != min)
				write_function2(a, "ra");
		}
		else
		{
			while ((*a)->num != min)
				write_function2(a, "rra");
		}
		write_function(b, a, "pb");
	}
	sort_three(a);
	while ((*b))
	{
		while ((*b)->num > (*a)->num)
			write_function2(a, "ra");
		write_function(a, b, "pa");
	}
}

int		main(int ac, char **av)
{
	t_dlist *stack_a;
	t_dlist *stack_b;

	stack_b = NULL;
	if (ac == 1)
		return (0);
	else
	{
		if (checker_valid_isdigit(av) == 0)
			return (0);
		stack_a = get_stack_a(av);
		if (is_sorted(&stack_a) == 1)
			return (0);
		if (ac == 4)
			sort_three(&stack_a);
		if (ac == 6)
			sort_five(&stack_a, &stack_b);
		else
			sort_hundred(&stack_a, &stack_b);
		if (is_sorted(&stack_a) == 0)
			check_place_if_not_sorted(&stack_a);
	}
	return (0);
}
