/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick-eco.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:39:18 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/03 08:44:33 by abessa-m         ###   ########.fr       */
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
static t_eco	eco_cheapest_op(t_ps *ps);

t_eco	economic_operation(t_ps *ps)
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

static t_eco	eco_cheapest_op(t_ps *ps)
{
	int		a;
	int		b;
	t_eco	eco;

	a = 1;
	eco.cost = stack_len(ps, 'a') + stack_len(ps, 'b') + 2;
	eco.next_a = 1;
	eco.next_b = 1;
	eco.reverse_direction = 0;
	while (a <= stack_len(ps, 'a'))
	{
		//if (min(ps, 'a') != get_value_from_pos(ps, 'a', a))
		{
			b = 1;
			while (b <= stack_len(ps, 'b'))
			{
				if ((get_value_from_pos(ps, 'b', b)
						== maximum_bellow(ps, 'b', get_value_from_pos(ps, 'a', a)))
					&& ((get_value_from_pos(ps, 'a', a)
						== minimum_above(ps, 'a', get_value_from_pos(ps, 'b', b)))))
				{
					if (eco.cost > cost_from_b_to_a(ps, a, b))
						eco = get_eco_info(ps, a, b);
				}
				b++;
			}
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
	eco.next_b = pos_b;
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
	if (a_pos == 1)
		cost_reverse = (stack_len(ps, 'b') - b_pos) + 2;
	if (b_pos == 1)
		cost = a_pos;
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
	if (a_pos == 1)
		cost_reverse = (stack_len(ps, 'b') - b_pos) + 2;
	if (b_pos == 1)
		cost = a_pos;
	if (cost_reverse < cost)
		return (1);
	return (0);
}
