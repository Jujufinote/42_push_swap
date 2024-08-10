/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:10:50 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/05 10:23:32 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **begin_list)
{
	t_lst	*end_list;
	t_lst	*before;
	
	end_list = lstlast(*begin_list);
	before = end_list->before;
	before->next = NULL;
	end_list->before = NULL;
	lstadd_front(begin_list, end_list);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_lst **begin_list)
{
	t_lst	*end_list;
	t_lst	*before;
	
	end_list = lstlast(*begin_list);
	before = end_list->before;
	before->next = NULL;
	end_list->before = NULL;
	lstadd_front(begin_list, end_list);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_lst **begin_list_a, t_lst **begin_list_b)
{
	rra(begin_list_a);
	rrb(begin_list_b);
	return ;
}
