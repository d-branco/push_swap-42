/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 18:14:47 by abessa-m         ###   ########.fr       */
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
int		initialize(t_ps *ps, int argc, char **argv, int verbose);
//ps-utils
void	print_stacks(t_ps *ps);
int		is_int(const char *nptr);
void	del(void *content);
//ps-op-swap
void	swap_a(t_ps *ps);
void	swap_b(t_ps *ps);
void	swap_ss(t_ps *ps);
//ps-op-push
void	push_a(t_ps *ps);
void	push_b(t_ps *ps);
//ps-op-rotate
void	rotate_a(t_ps *ps);
void	rotate_b(t_ps *ps);
void	rotate_rr(t_ps *ps);
//ps-op-reverse
void	reverse_a(t_ps *ps);
void	reverse_b(t_ps *ps);
void	reverse_rr(t_ps *ps);
//ps-check
int		check_order(t_ps *ps, char chr);
//ps-algo-small
int		algo_small(t_ps *ps);

#endif
