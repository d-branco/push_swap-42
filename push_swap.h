/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 08:12:16 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//ps-initialize
int		initialize(t_ps *ps, int argc, char **argv);
//ps-utils
void	print_stacks(t_ps *ps);
int		is_int(const char *nptr);
void	del(void *content);
//ps-operations
void	swap_a(t_ps *ps);

#endif
