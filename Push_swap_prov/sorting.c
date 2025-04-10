/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:49:48 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/14 10:36:05 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(char	*array, t_lst **begin_list_a, t_lst **begin_list_b)
{
	if (ft_strncmp(array, RA, 4) == 0)
		ra(begin_list_a);
	else if (ft_strncmp(array, RB, 4) == 0)
		rb(begin_list_b);
	else if (ft_strncmp(array, RR, 4) == 0)
		rr(begin_list_a, begin_list_b);
	else if (ft_strncmp(array, RRA, 4) == 0)
		rra(begin_list_a);
	else if (ft_strncmp(array, RRB, 4) == 0)
		rrb(begin_list_b);
	else if (ft_strncmp(array, RRR, 4) == 0)
		rrr(begin_list_a, begin_list_b);
	return ;
}

void	sorting(t_lst **begin_list_a, t_lst **begin_list_b, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], SA, 4) == 0)
			sa(begin_list_a);
		else if (ft_strncmp(array[i], SB, 4) == 0)
			sb(begin_list_b);
		else if (ft_strncmp(array[i], SS, 4) == 0)
			ss(begin_list_a, begin_list_b);
		else if (ft_strncmp(array[i], PA, 4) == 0)
			pa(begin_list_a, begin_list_b);
		else if (ft_strncmp(array[i], PB, 4) == 0)
			pb(begin_list_a, begin_list_b);
		rotate(array[i], begin_list_a, begin_list_b);
		i++;
	}
	if (is_sorted(*begin_list_a) != 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free(array);
	return ;
}
