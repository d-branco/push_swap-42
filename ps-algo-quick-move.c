/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick-move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:49:20 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/03 09:59:50 by abessa-m         ###   ########.fr       */
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
	int	divisions;
	int	len;
	int	max;
	int	median_value;
	int	end;
	int	j;

	divisions = 4;
	if (stack_len(ps, 'a') > 225)
		divisions = 8;
	len = stack_len(ps, 'a') / divisions;



	j = 0;
	while ((j < divisions) && (stack_len(ps, 'a') > 3))
	{
		median_value = find_nth_smallest(ps, 'a', len/2);
		max = find_nth_smallest(ps, 'a', len);
		
		if (ps->verbose)
			ft_printf("\033[34mMoving to stack b\033[0m\n");
		end = stack_len(ps, 'a');
		while ((end > 0) && (stack_len(ps, 'a') > 3))
		{
			if (get_value_from_pos(ps, 'a', 1) < max)
			{
				push_b(ps);
				if (get_value_from_pos(ps, 'b', 1) > median_value)
					rotate_b(ps);
			}
			else
				rotate_a(ps);
			end--;
		}
		j++;
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

/*int	maximum_bellow(t_ps *ps, char chr, int border)
{
	t_list	*lst;
	int		max_bellow;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	max_bellow = min(ps, chr);
	while (lst != NULL)
	{
		if ((max_bellow < *(int *) lst->content)
			&& (*(int *) lst->content < border))
			max_bellow = *(int *) lst->content;
		lst = lst->next;
	}
	return (max_bellow);
}*/
