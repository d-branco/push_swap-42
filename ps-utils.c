/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:39:53 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 20:29:48 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Does not accep invalid int
int	is_int(const char *nptr)
{
	long	nbr;
	long	sign;
	size_t	j;

	j = 0;
	sign = 1;
	if (nptr[j] == '+' || nptr[j] == '-')
	{
		if (nptr[j] == '-')
			sign = -1;
		j++;
	}
	nbr = 0;
	while (ft_isdigit(nptr[j]))
	{
		nbr = (10 * nbr) + (nptr[j] - '0');
		j++;
	}
	nbr *= sign;
	if ((nbr > 2147483647) || (nbr < -2147483648) || (nptr[j]) != '\0')
		return (2);
	return (0);
}

void	del(void *content)
{
	if (content)
		free(content);
}
