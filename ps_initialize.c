/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:44:16 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 18:53:02 by abessa-m         ###   ########.fr       */
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

int	initialize(t_ps *ps, int argc, char **argv)
{
	int		i;

	ps->verbose = 1;
	ps->a = NULL;
	ps->b = NULL;
	i = 1;
	while (i < argc)
	{
		if (ps->verbose)
			ft_printf("Adding %i to the bottom of stack a\n", ft_atoi(argv[i]));
		ft_lstadd_back(&ps->a, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}
	return (0);
}

void	del(void *content)
{
	if (content)
		free(content);
}
