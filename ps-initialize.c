/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:44:16 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 08:08:17 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//void	ft_lstadd_back(t_list **lst, t_list *new)
//t_list	*ft_lstnew(void *content);
//void	ft_lstdelone(t_list *lst, void (*del)(void *));
//void	ft_lstclear(t_list **lst, void (*del)(void *));
//void	ft_lstadd_front(t_list **lst, t_list *new);
//void	ft_lstadd_back(t_list **lst, t_list *new);
//int		ft_lstsize(t_list *lst);
//t_list	*ft_lstlast(t_list *lst);
//void	ft_lstiter(t_list *lst, void (*f)(void *));
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

static int	is_valid_int(int argc, char **argv);

int	initialize(t_ps *ps, int argc, char **argv)
{
	int	i;

	ps->verbose = 0;
	ps->a = NULL;
	ps->b = NULL;
	if (is_valid_int(argc, argv) != 0)
		return (1);
	i = 1;
	if (ps->verbose)
		ft_printf("Adding to the bottom of stack a: ");
	while (i < argc)
	{
		if (ps->verbose)
			ft_printf("%i ", ft_atoi(argv[i]));
		ft_lstadd_back(&ps->a, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}
	if (ps->verbose)
		ft_printf("\n");
	return (0);
}

static int	is_valid_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		if (is_int(argv[i]) != 0)
			return (2);
		i++;
	}
	return (0);
}
