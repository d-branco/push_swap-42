/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:57:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/02 15:57:10 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_eco	economic_operation(t_ps *ps);
static void		move_to_b(t_ps *ps);
static void		align_stacks(t_ps *ps, t_eco eco);
static void		align_stacks_direction(t_ps *ps, t_eco eco);

int	algo_quick(t_ps *ps)
{
	t_eco	eco;

	move_to_b(ps);
	algo_small(ps);
	while (stack_len(ps, 'b') > 0)
	{
		eco = economic_operation(ps);
		align_stacks(ps, eco);
	}
	algo_buble(ps, 'a');
	return (0);
}

//	int	maximum_bellow(t_ps *ps, char chr, int border);
//	int	minimum_above(t_ps *ps, char chr, int border);
static t_eco	economic_operation(t_ps *ps)
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
	return (eco);
}

static void	align_stacks(t_ps *ps, t_eco eco)
{
	int	steps_a;
	int	steps_b;

	if (eco.reverse_direction)
	{
		steps_a = (stack_len(ps, 'a') - eco.next_a) + 1;
		steps_b = 1 + stack_len(ps, 'b') - get_pos_from_value(ps, 'b',
				minimum_above(ps, 'b', get_value_from_pos(ps, 'a',
						eco.next_a)));
		while ((steps_a > 0) || (steps_b > 0))
		{
			if ((steps_a > 0) && (steps_b > 0))
				reverse_rr(ps);
			else if (steps_a > 0)
				reverse_a(ps);
			else if (steps_b > 0)
				reverse_b(ps);
			steps_a--;
			steps_b--;
		}
	}
	else
		align_stacks_direction(ps, eco);
	push_a(ps);
}

static void	align_stacks_direction(t_ps *ps, t_eco eco)
{
	int	steps_a;
	int	steps_b;

	steps_a = 0 - 1 + eco.next_a;
	steps_b = 0 - 1 + get_pos_from_value(ps, 'b',
			minimum_above(ps, 'b', get_value_from_pos(ps, 'a', eco.next_a)));
	while ((steps_a > 0) || (steps_b > 0))
	{
		if (ps->verbose)
		{
			ft_printf("stack a needs to rotate %i times\n", steps_a);
			ft_printf("stack b needs to rotate %i times\n", steps_b);
		}
		if ((steps_a > 0) && (steps_b > 0))
			rotate_rr(ps);
		else if (steps_a > 0)
			rotate_a(ps);
		else if (steps_b > 0)
			rotate_b(ps);
		steps_a--;
		steps_b--;
	}
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
