/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:46:18 by student           #+#    #+#             */
/*   Updated: 2020/04/11 19:46:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

int		main(int ac, char **av)
{
	t_dlist *stack_a;
	t_dlist *stack_b;
	int		flag;

	stack_b = NULL;
	flag = 0;
	if (ac == 1)
		return (0);
	else
	{
		if (ft_strcmp("-v", av[1]) == 0)
		{
			set_flag(&ac, &flag);
			av++;
		}
		if (checker_valid_isdigit(av) == 0)
			return (0);
		stack_a = get_stack_a(av, flag);
		if (flag == 1)
			first_display(&stack_a);
		if (is_sorted(&stack_a) == 1)
			return (0);
		parse_stack(&stack_a, &stack_b, ac);
	}
	return (0);
}
