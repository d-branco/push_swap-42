/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:59:51 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 19:01:42 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_three(t_ps *ps);

int	algo_small(t_ps *ps)
{
	if (ft_lstsize(ps->a) == 1)
	{
		if (ps->verbose)
			ft_printf("There's only one. Must be ordered\n");
	}
	else if (ft_lstsize(ps->a) == 2)
	{
		if (check_order(ps, 'a') != 0)
			return (swap_a(ps), check_order(ps, 'a'), 0);
	}
	else if (ft_lstsize(ps->a) == 3)
		algo_three(ps);
	return (0);
}

static int	algo_three(t_ps *ps)
{
	if (check_order(ps, 'a') != 0)
	{
		if ((ft_atoi(ps->a->content) > ft_atoi(ps->a->next->content))
			&& (ft_atoi(ps->a->content) > ft_atoi(ps->a->next->next->content)))
		{
			rotate_a(ps);
			if (check_order(ps, 'a') != 0)
				return (swap_a(ps), check_order(ps, 'a'));
		}
		else if ((ft_atoi(ps->a->content) < ft_atoi(ps->a->next->content))
			&& (ft_atoi(ps->a->content) < ft_atoi(ps->a->next->next->content)))
			return (reverse_a(ps), swap_a(ps), check_order(ps, 'a'));
		else if (ft_atoi(ps->a->next->content)
			< ft_atoi(ps->a->next->next->content))
			return (swap_a(ps), check_order(ps, 'a'));
		else
			return (reverse_a(ps), check_order(ps, 'a'));
	}
	return (1);
}
