/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:17:11 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 14:52:04 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_swap(t_lst *begin_list_a, t_lst *min, t_lst *max)
{
	if ((pos(begin_list_a, min->content) == 1 \
	&& pos(begin_list_a, max->content) == 2) \
	|| (pos(begin_list_a, min->content) == 0 \
	&& pos(begin_list_a, max->content) == 1) \
	|| (pos(begin_list_a, min->content) == 2 \
	&& pos(begin_list_a, max->content) == 0))
		return (1);
	return (0);
}

void	small(t_lst **begin_lst_a)
{
	t_lst	*min;
	t_lst	*max;

	while (is_sorted(*begin_lst_a) != 1)
	{
		min = search_min(*begin_lst_a);
		max = search_max(*begin_lst_a);
		if (is_swap(*begin_lst_a, min, max) == 1)
		{
			ft_printf("sa\n");
			sa(begin_lst_a);
		}
		else if (pos(*begin_lst_a, min->content) == 2 \
		&& pos(*begin_lst_a, max->content) == 1)
		{
			ft_printf("rra\n");
			rra(begin_lst_a);
		}
		else if (pos(*begin_lst_a, max->content) == 0 \
		&& pos(*begin_lst_a, min->content) == 1)
		{
			ft_printf("ra\n");
			ra(begin_lst_a);
		}
	}
}

void	medium(t_lst **begin_list_a, t_lst **begin_list_b)
{
	while (lstsize(*begin_list_a) > 3)
	{
		ft_printf("pb\n");
		pb(begin_list_a, begin_list_b);
	}
	end_sort(begin_list_a, begin_list_b);
	return ;
}

void	large(t_lst **begin_list_a, t_lst **begin_list_b, int *tab, int size)
{
	t_lst	*b_list;

	while (lstsize(*begin_list_a) > 3)
	{
		ft_printf("pb\n");
		pb(begin_list_a, begin_list_b);
		b_list = *begin_list_b;
		if (lstsize(*begin_list_b) >= 2 && b_list->content > tab[size / 2])
		{
			ft_printf("rb\n");
			rb(begin_list_b);
		}
	}
	free(tab);
	end_sort(begin_list_a, begin_list_b);
}

void	end_sort(t_lst **begin_list_a, t_lst **begin_list_b)
{
	t_lst	*min;
	t_lst	*max;

	small(begin_list_a);
	max = search_max(*begin_list_b);
	if (pos(*begin_list_b, max->content) != 0)
		put_num_first_b(begin_list_b, max);
	while (lstsize(*begin_list_b) > 0)
	{
		put_cost_b(*begin_list_a, begin_list_b);
		put_num_first(begin_list_a, begin_list_b,
			srch_closest_smaller(*begin_list_a,
				who_put(*begin_list_b)), who_put(*begin_list_b));
		ft_printf("pa\n");
		pa(begin_list_a, begin_list_b);
	}
	min = search_min(*begin_list_a);
	if (pos(*begin_list_a, min->content) != 0)
		put_num_first_a(begin_list_a, min);
	return ;
}
