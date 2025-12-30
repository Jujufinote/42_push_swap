/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:10:50 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 11:19:17 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra(t_lst **begin_list)
{
	t_lst	*end_list;
	t_lst	*before;

	end_list = lstlast(*begin_list);
	before = end_list->before;
	before->next = NULL;
	end_list->before = NULL;
	lstadd_front(begin_list, end_list);
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
	return ;
}

void	rrr(t_lst **begin_list_a, t_lst **begin_list_b)
{
	rra(begin_list_a);
	rrb(begin_list_b);
	return ;
}
