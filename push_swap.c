/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:35:47 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 17:43:33 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		verbose;
	t_ps	ps;

	verbose = 1;
	if (argc == 1)
		return (1);
	if (initialize(&ps, argc, argv, verbose) != 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	print_stacks(&ps);
	if (ft_lstsize(ps.a) <= 3)
		algo_small(&ps);
	else
		algo_buble(&ps, 'a');
	ft_lstclear(&ps.a, (void (*)(void *))del);
	ft_lstclear(&ps.b, (void (*)(void *))del);
}

/*
	swap_a(&ps);
	swap_b(&ps);
	swap_ss(&ps);
	push_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	rotate_b(&ps);
	rotate_rr(&ps);
	reverse_a(&ps);
	reverse_a(&ps);
	reverse_b(&ps);
	reverse_rr(&ps);
*/
