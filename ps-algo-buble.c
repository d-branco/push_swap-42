/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-buble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:47:14 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 17:44:51 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_len:	ft_lstsize(ps->a)
int	nbr(t_ps *ps, char chr, int n);
int	stack_len(t_ps *ps, char chr);
int	max(t_ps *ps, char chr);

int	algo_buble(t_ps *ps, char chr)
{
	int	len;

	if (ps->verbose)
		ft_printf("Iniciating BUBLE SORT at %c\n", chr);
	len = stack_len(ps, chr);
	while (1)
	{
		if (ps->verbose)
		{
			ft_printf("Buble sort: comparing postions 1 (%i) and 2 (%i)"
				"\n", nbr(ps, chr, 1), nbr(ps, chr, 2));
		}
		if ((nbr(ps, chr, 1) > nbr(ps, chr, 2))
			&& (nbr(ps, chr, 1) != max(ps, chr)))
			swap_stack(ps, chr);
		else
			rotate_stack(ps, chr);
		if (check_order(ps, chr) == 0)
			break ;
	}
	ft_printf("Ending buble sort at %c\n", chr);
	return (check_order(ps, chr));
}

int	max(t_ps *ps, char chr)
{
	t_list	*lst;
	int		max;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	max = *(int *) lst->content;
	while (lst != NULL)
	{
		if (max < *(int *) lst->content)
			max = *(int *) lst->content;
		lst = lst->next;
	}
	return (max);
}

int	nbr(t_ps *ps, char chr, int n)
{
	t_list	*lst;
	int		pos;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	pos = 1;
	while (lst != NULL)
	{
		if (pos == n)
			break ;
		lst = lst->next;
		pos++;
	}
	return (*(int *) lst->content);
}

int	stack_len(t_ps *ps, char chr)
{
	t_list	**lst;
	int		len;

	if (chr == 'a')
		lst = &(ps->a);
	if (chr == 'b')
		lst = &(ps->b);
	len = ft_lstsize(*lst);
	return (len);
}
