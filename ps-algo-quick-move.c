/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick-move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:49:20 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 15:24:47 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_ps *ps)
{
	int	median_value;

	median_value = median(ps, 'a');
	if (ps->verbose)
		ft_printf("\033[34mMoving to stack b\033[0m\n");
	while (stack_len(ps, 'a') > 3)
	{
		if (get_value_from_pos(ps, 'a', 1) != max(ps, 'a')
			&& get_value_from_pos(ps, 'a', 1) != min(ps, 'a'))
		{
			push_b(ps);
			if (get_value_from_pos(ps, 'b', 1) > median_value)
				rotate_b(ps);
		}
		else
			rotate_a(ps);
	}
}

void	quick_move(t_ps *ps)
{
	int	len;

//len
//24	5725
//23	5715
//22	5681
//21	5780

	len = 12;
	if (stack_len(ps, 'a') > 225)
		len = 22;
	if (ps->verbose)
		ft_printf("\033[34mMoving to stack b\033[0m\n");
	while (stack_len(ps, 'a') > 2)
	{
		if (get_value_from_pos(ps, 'a', 1) < find_nth_smallest(ps, 'a', len))
		{
			push_b(ps);
			if (get_value_from_pos(ps, 'b', 1) > find_nth_smallest(ps, 'a', len / 4))
			{
				if (get_value_from_pos(ps, 'a', 1) >= find_nth_smallest(ps, 'a', len))
					rotate_rr(ps);
				else
					rotate_b(ps);
			}
		}
		else
			rotate_a(ps);
	}
}

int	find_nth_smallest(t_ps *ps, char chr, int len)
{
	int	n;
	int	pos;

	n = min(ps, chr);
	pos = 0;
	while (pos < len)
	{
		n = minimum_above(ps, chr, n);
		pos++;
	}
	return (n);
}
