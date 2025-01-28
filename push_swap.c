/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:35:47 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 18:53:32 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_ps *ps);

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		return (1);
	if (initialize(&ps, argc, argv) != 0)
		ft_printf("Error parsisng the arguments.");
	print_stacks(&ps);
	ft_lstclear(&ps.a, (void (*)(void *))del);
	ft_lstclear(&ps.b, (void (*)(void *))del);
}

static void	print_stacks(t_ps *ps)
{
	t_list	*lst;

	if (ps->verbose)
	{
		ft_printf("a, size: %i    LIST: ", ft_lstsize(ps->a));
		lst = (ps->a);
		while (lst)
		{
			ft_printf("%s ", lst->content);
			lst = lst->next;
		}
		ft_printf("\nb, size: %i    LIST: ", ft_lstsize(ps->b));
		lst = (ps->b);
		while (lst)
		{
			ft_printf("%s ", lst->content);
			lst = lst->next;
		}
		ft_printf("\n");
	}
}
