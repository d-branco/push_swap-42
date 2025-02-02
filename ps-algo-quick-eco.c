/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick-eco.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:39:18 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/02 14:51:49 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//typedef struct s_eco
//{
//	int		cost;
//	int		next_a;
//	int		reverse_direction;
//}			t_eco;

static t_eco	get_eco_info(t_ps *ps, int pos_a, int pos_b);
static int		cost_from_b_to_a(t_ps *ps, int a_pos, int b_pos);
static int		shorter_in_reverse(t_ps *ps, int a_pos, int b_pos);

t_eco	eco_cheapest_op(t_ps *ps)
{
	int		a;
	int		b;
	t_eco	eco;

	a = 1;
	eco.cost = stack_len(ps, 'a') + stack_len(ps, 'b') + 2;
	eco.next_a = 1;
	eco.reverse_direction = 0;
	while (a <= stack_len(ps, 'a'))
	{
		b = 1;
		while (b <= stack_len(ps, 'b'))
		{
			if (get_value_from_pos(ps, 'b', b)
				== minimum_above(ps, 'b', get_value_from_pos(ps, 'a', a)))
			{
				if (eco.cost > cost_from_b_to_a(ps, a, b))
					eco = get_eco_info(ps, a, b);
			}
			b++;
		}
		a++;
	}
	return (eco);
}

static t_eco	get_eco_info(t_ps *ps, int pos_a, int pos_b)
{
	t_eco	eco;

	eco.cost = cost_from_b_to_a(ps, pos_a, pos_b);
	eco.next_a = pos_a;
	eco.reverse_direction = shorter_in_reverse(ps, pos_a, pos_b);
	return (eco);
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
