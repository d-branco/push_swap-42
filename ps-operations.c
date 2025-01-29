/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:30:22 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:34 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_ps *ps, char c)
{
	t_list	*first;
	t_list	*second;
	t_list	**lst;

	if (c == 'a')
		lst = &(ps->a);
	else if (c == 'b')
		lst = &(ps->b);
	if (*lst && ((*lst)->next))
	{
		if (ps->verbose)
			ft_printf("SA"
				"	swaping the first 2 elements at the top of stack a\n");
		else
			ft_printf("sa\n");
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		second->next = first;
		*lst = second;
		if (ps->verbose)
			print_stacks(ps);
	}
	else if (ps->verbose)
		ft_printf("swap_a requires two element at the top\n");
}

void	swap_a(t_ps *ps)
{
	swap_top(ps, 'a');
}

void	swap_b(t_ps *ps)
{
	swap_top(ps, 'b');
}

void	swap_s(t_ps *ps)
{
	swap_top(ps, 'a');
	swap_top(ps, 'a');
}

/*
sa (swap a):	Swap the first 2 elements at the top of stack a.
				Do nothing if there is only one or no elements.
sb (swap b):	Swap the first 2 elements at the top of stack b.
				Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

pa (push a):Take the first element at the top of b and put it at the top of a.
				Do nothing if b is empty.
pb (push b):Take the first element at the top of a and put it at the top of b.
				Do nothing if a is empty.

ra (rotate a):	Shift up all elements of stack a by 1.
				The first element becomes the last one.
rb (rotate b):	Shift up all elements of stack b by 1.
				The first element becomes the last one.
rr : ra and rb at the same time.

rra (reverse rotate a):	Shift down all elements of stack a by 1.
				The last element becomes the first one.
rrb (reverse rotate b):	Shift down all elements of stack b by 1.
				The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
