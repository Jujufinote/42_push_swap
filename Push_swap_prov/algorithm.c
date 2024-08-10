/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:17:11 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/09 13:06:25 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small(t_lst **begin_list_a)
{
	t_lst	*min;
	t_lst	*max;

	if (lstsize(*begin_list_a) < 2)
		return ;
	min = search_min(*begin_list_a);
	max = search_max(*begin_list_a);
	if ((position(*begin_list_a, min->content) == 1 && lstsize(*begin_list_a) == 2) \
	|| (position(*begin_list_a, min->content) == 1 && position(*begin_list_a, max->content) == 2) \
	|| (position(*begin_list_a, min->content) == 0 && position(*begin_list_a, max->content) == 1) \
	|| (position(*begin_list_a, min->content) == 2 && position(*begin_list_a, max->content) == 0))
		sa(begin_list_a);
	min = search_min(*begin_list_a);
	max = search_max(*begin_list_a);
	if (position(*begin_list_a, min->content) == 2 && position(*begin_list_a, max->content) == 1)
		rra(begin_list_a);
	min = search_min(*begin_list_a);
	max = search_max(*begin_list_a);
	if (position(*begin_list_a, max->content) == 0 && position(*begin_list_a, min->content) == 1)
		ra(begin_list_a);
	return ;
}

void	medium(t_lst **begin_list_a, t_lst **begin_list_b)
{
	t_lst	*max;
	t_lst	*min;

	while (lstsize(*begin_list_a) > 3)
		pb(begin_list_a, begin_list_b);
	small(begin_list_a);
	max = search_max(*begin_list_b);
	if (position(*begin_list_b, max->content) != 0)
		put_num_first(begin_list_b, max);
	while (lstsize(*begin_list_b) > 0)
	{
		put_cost_b(*begin_list_a, begin_list_b);
		put_num_first(begin_list_b, who_put(*begin_list_b));
		min = srch_closest_smaller(*begin_list_a, who_put(*begin_list_b));
		if (min->next != NULL)
		{
			min = min->next;
			put_num_first(begin_list_a, min);
		}
		pa(begin_list_a, begin_list_b);
	}
	min = search_min(*begin_list_a);
	if (position(*begin_list_a, min->content) != 0)
		put_num_first(begin_list_a, min);
	return ;
}

void	large(t_lst **begin_list_a, t_lst **begin_list_b)
{
	t_lst	*max;
	t_lst	*min;
	
	while (lstsize(*begin_list_b) != 2)
		pb(begin_list_a, begin_list_b);
	while (lstsize(*begin_list_a) > 3)
	{
		put_cost_a(begin_list_a, *begin_list_b);
		put_num_first(begin_list_a, who_put(*begin_list_a));
		max = srch_closest_bigger(*begin_list_b, who_put(*begin_list_a));
		if (max->next != NULL)
		{
			max = max->next;
			put_num_first(begin_list_b, max);
		}
		pb(begin_list_a, begin_list_b);
	}
	small(begin_list_a);
	max = search_max(*begin_list_b);
	if (position(*begin_list_b, max->content) != 0)
		put_num_first(begin_list_b, max);
	while (lstsize(*begin_list_b) > 0)
	{
		put_cost_b(*begin_list_a, begin_list_b);
		put_num_first(begin_list_b, who_put(*begin_list_b));
		min = srch_closest_smaller(*begin_list_a, who_put(*begin_list_b));
		if (min->next != NULL)
		{
			min = min->next;
			put_num_first(begin_list_a, min);
		}
		pa(begin_list_a, begin_list_b);
	}
	min = search_min(*begin_list_a);
	if (position(*begin_list_a, min->content) != 0)
		put_num_first(begin_list_a, min);
	return ;
}
