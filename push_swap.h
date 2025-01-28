/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 18:52:43 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/

typedef struct s_ps
{
	int				verbose;
	t_list			*a;
	t_list			*b;
}					t_ps;

int		initialize(t_ps *ps, int argc, char **argv);
void	del(void *content);

#endif
