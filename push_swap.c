/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:35:47 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 10:36:56 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_ps *ps);

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		verbose;

	verbose = 1;
	if (argc == 1)
		return (1);
	if (initialize(&ps, argc, argv, verbose) != 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	print_stacks(&ps);
	swap_a(&ps);
	swap_b(&ps);
	swap_ss(&ps);
	push_a(&ps);
	push_b(&ps);
	ft_lstclear(&ps.a, (void (*)(void *))del);
	ft_lstclear(&ps.b, (void (*)(void *))del);
}
