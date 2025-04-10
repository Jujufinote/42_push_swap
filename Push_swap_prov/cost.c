/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:16:43 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/14 10:25:33 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_lst *begin_list, t_lst *post)
{
	int	cost;

	cost = 0;
	while (post != NULL && pos(begin_list, post->content) != 0)
	{
		if (pos(begin_list, post->content) >= (lstsize(begin_list) / 2))
		{
			cost++;
			post = post->next;
		}
		else
		{
			cost++;
			post = post->before;
		}
	}
	return (cost);
}

void	put_cost_b(t_lst *begin_lst_a, t_lst **begin_list_b)
{
	t_lst	*smaller;
	t_lst	*now;

	now = *begin_list_b;
	while (now != NULL)
	{
		smaller = srch_closest_smaller(begin_lst_a, now);
		now->push_cost = cost(begin_lst_a, smaller) + cost(*begin_list_b, now);
		now = now->next;
	}
	return ;
}

void	put_cost_a(t_lst **begin_list_a, t_lst *begin_list_b)
{
	t_lst	*bigger;
	t_lst	*now;

	now = *begin_list_a;
	while (now != NULL)
	{
		bigger = srch_closest_bigger(begin_list_b, now);
		now->push_cost = cost(*begin_list_a, now) + cost(begin_list_b, bigger);
		now = now->next;
	}
	return ;
}
