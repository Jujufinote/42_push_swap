/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:10:11 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 13:31:21 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_lst *begin_list, int content)
{
	int	pos;

	pos = 0;
	while (begin_list != NULL && begin_list->content != content)
	{
		pos++;
		begin_list = begin_list->next;
	}
	return (pos);
}

void	put_num_first_a(t_lst **begin_list, t_lst *num)
{
	while (pos(*begin_list, num->content) != 0)
	{
		if (pos(*begin_list, num->content) >= (lstsize(*begin_list) / 2))
		{
			ft_printf("rra\n");
			rra(begin_list);
		}
		else
		{
			ft_printf("ra\n");
			ra(begin_list);
		}
	}
	return ;
}

void	put_num_first_b(t_lst **begin_list, t_lst *num)
{
	while (pos(*begin_list, num->content) != 0)
	{
		if (pos(*begin_list, num->content) >= (lstsize(*begin_list) / 2))
		{
			ft_printf("rrb\n");
			rrb(begin_list);
		}
		else
		{
			ft_printf("rb\n");
			rb(begin_list);
		}
	}
	return ;
}

void	put_num_first(t_lst **b_a, t_lst **b_b, t_lst *numa, t_lst *numb)
{
	while (pos(*b_a, numa->content) != 0
		&& pos(*b_b, numb->content) != 0)
	{
		if (pos(*b_a, numa->content) >= (lstsize(*b_a) / 2) \
		&& pos(*b_b, numb->content) >= (lstsize(*b_b) / 2))
		{
			ft_printf("rrr\n");
			rrr(b_a, b_b);
		}
		else if (pos(*b_a, numa->content) <= (lstsize(*b_a) / 2) \
		&& pos(*b_b, numb->content) <= (lstsize(*b_b) / 2))
		{
			ft_printf("rr\n");
			rr(b_a, b_b);
		}
		else
		{
			put_num_first_a(b_a, numa);
			put_num_first_b(b_b, numb);
		}
	}
	put_num_first_a(b_a, numa);
	put_num_first_b(b_b, numb);
	return ;
}

void	bubble(int *tab, int size)
{
	int	i;
	int	j;
	int	*min;

	i = 0;
	while (i < size)
	{
		j = i;
		min = &tab[i];
		while (j < size)
		{
			if (*min > tab[j])
				min = &tab[j];
			j++;
		}
		if (min != &tab[i])
			swap(min, &tab[i]);
		i++;
	}
	return ;
}
