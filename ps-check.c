/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:13 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 17:32:11 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_ps *ps, char chr)
{
	t_list	*current;
	t_list	*previous;

	previous = (ps->a);
	if (chr == 'b')
		previous = (ps->b);
	else if ((chr != 'a') || (!(previous->next)))
		return (2);
	current = previous->next;
	while (previous->next)
	{
		if (ft_atoi(current->content) <= ft_atoi(previous->content))
		{
			if (ps->verbose)
				ft_printf("Stack %c is nor in order\n", chr);
			return (1);
		}
		previous = current;
		current = current->next;
	}
	if (ps->verbose)
		ft_printf("Stack %c looks to be in the correct order!\n", chr);
	return (0);
}
// Returns 1 if it's nor ordered
// Returns 0 if it is correclt ordered
