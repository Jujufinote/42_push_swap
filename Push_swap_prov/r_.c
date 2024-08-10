/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:10:35 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/29 13:48:34 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **begin_list)
{
	t_lst	*b_list;
	t_lst	*node;
	
	b_list = *begin_list;
	node = b_list;
	b_list = b_list->next;
	b_list->before = NULL;
	*begin_list = b_list;
	node->next = NULL;
	lstadd_back(begin_list, node);
	ft_printf("ra\n");
	return ;
}

void	rb(t_lst **begin_list)
{
	t_lst	*b_list;
	t_lst	*node;
	
	b_list = *begin_list;
	node = b_list;
	b_list = b_list->next;
	b_list->before = NULL;
	*begin_list = b_list;
	node->next = NULL;
	lstadd_back(begin_list, node);
	ft_printf("rb\n");
	return ;
}

void	rr(t_lst **begin_list_a, t_lst **begin_list_b)
{
	ra(begin_list_a);
	rb(begin_list_b);
	return ;
}
