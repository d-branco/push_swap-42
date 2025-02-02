/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:57:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/02 14:54:40 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	economic_operation(t_ps *ps);
static void	move_to_b(t_ps *ps);

int	algo_quick(t_ps *ps)
{
	move_to_b(ps);
	algo_small(ps);
	economic_operation(ps);
	return (0);
}

//	int	maximum_bellow(t_ps *ps, char chr, int border);
//	int	minimum_above(t_ps *ps, char chr, int border);
static void	economic_operation(t_ps *ps)
{
	t_eco	eco;

	if (ps->verbose)
		ft_printf("\033[34mEconomic analysis\033[0m\n");
	eco = eco_cheapest_op(ps);
	if (ps->verbose)
	{
		ft_printf("Found %i to place above %i		",
			maximum_bellow(ps, 'b', get_value_from_pos(ps, 'a', eco.next_a)),
			get_value_from_pos(ps, 'a', eco.next_a));
		if (eco.reverse_direction)
			ft_printf("    cost: %i step. Reverse: yes\n", eco.cost);
		else
			ft_printf("    cost: %i step. Reverse: no\n", eco.cost);
	}
	return ;
}

static void	move_to_b(t_ps *ps)
{
	if (ps->verbose)
		ft_printf("\033[34mMoving to stack b\033[0m\n");
	while (stack_len(ps, 'a') > 3)
	{
		if (get_value_from_pos(ps, 'a', 1) != max(ps, 'a')
			&& get_value_from_pos(ps, 'a', 1) != min(ps, 'a'))
		{
			push_b(ps);
			if (get_value_from_pos(ps, 'b', 1) > median(ps, 'b'))
				rotate_b(ps);
		}
		else
			rotate_a(ps);
	}
}
