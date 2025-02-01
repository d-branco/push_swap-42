/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:57:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/01 17:22:30 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	economic_operation(t_ps *ps);
static int	cost_from_b_to_a(t_ps *ps, int a_pos, int b_pos);
static int	shorter_in_reverse(t_ps *ps, int a_pos, int b_pos);

int	algo_quick(t_ps *ps)
{
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
	algo_small(ps);
	economic_operation(ps);
	return (0);
}

//	int	maximum_bellow(t_ps *ps, char chr, int border);
//	int	minimum_above(t_ps *ps, char chr, int border);
static void	economic_operation(t_ps *ps)
{
	int	i;
	int	j;
	int	cost;
	int	next_a;
	int	reverse_direction;

	if (ps->verbose)
		ft_printf("Econmic analyses\n");
	i = 1;
	cost = stack_len(ps, 'a') + stack_len(ps, 'b') + 2;
	next_a = 1;
	reverse_direction = 0;
	while (i <= stack_len(ps, 'a'))
	{
		j = 1;
		while (j <= stack_len(ps, 'b'))
		{
			if (get_value_from_pos(ps, 'b', j)
				== maximum_bellow(ps, 'b', get_value_from_pos(ps, 'a', i)))
			{
				if (cost > cost_from_b_to_a(ps, i, j))
				{
					cost = cost_from_b_to_a(ps, i, j);
					next_a = i;
					reverse_direction = shorter_in_reverse(ps, i, j);
				}
			}
			j++;
		}
		i++;
	}
	if (ps->verbose)
	{
		ft_printf("At the end\nFound %i to place above %i\n",
			maximum_bellow(ps, 'b', get_value_from_pos(ps, 'a', next_a)),
			get_value_from_pos(ps, 'a', next_a));
		ft_printf("    cost: %i step. Reverse: %i\n", cost, reverse_direction);
	}
	return ;
}

static int	cost_from_b_to_a(t_ps *ps, int a_pos, int b_pos)
{
	int	cost;
	int	cost_reverse;

	cost = a_pos;
	if (a_pos < b_pos)
		cost = b_pos;
	cost_reverse = (stack_len(ps, 'a') - a_pos) + 2;
	if ((stack_len(ps, 'a') - a_pos) + 2 < (stack_len(ps, 'b') - b_pos) + 2)
		cost_reverse = (stack_len(ps, 'b') - b_pos) + 2;
	if (shorter_in_reverse(ps, a_pos, b_pos))
		cost = cost_reverse;
	else
		cost++;
	return (cost);
}

static int	shorter_in_reverse(t_ps *ps, int a_pos, int b_pos)
{
	int	cost;
	int	cost_reverse;

	cost = a_pos;
	if (a_pos < b_pos)
		cost = b_pos;
	cost_reverse = (stack_len(ps, 'a') - a_pos) + 2;
	if ((stack_len(ps, 'a') - a_pos) + 2 < (stack_len(ps, 'b') - b_pos) + 2)
		cost_reverse = (stack_len(ps, 'b') - b_pos) + 2;
	if (cost_reverse < cost)
		return (1);
	return (0);
}
