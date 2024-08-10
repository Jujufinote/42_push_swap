/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:10:21 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/29 17:14:44 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_lst **begin_list_a, t_lst **begin_list_b)
{
	t_lst	*b_list_b;
	t_lst	*node;
	int		size;

	node = *begin_list_b;
	size = lstsize(*begin_list_b);
	if (size > 1)
	{
		b_list_b = *begin_list_b;
		b_list_b = b_list_b->next;
		*begin_list_b = b_list_b;
		b_list_b->before = NULL;
	}
	node->next = NULL;
	lstadd_front(begin_list_a, node);
	if (size == 1)
		*begin_list_b = NULL;
	ft_printf("pa\n");
	return ;
}

void	pb(t_lst **begin_list_a, t_lst **begin_list_b)
{
	t_lst	*b_list_a;
	t_lst	*node;

	b_list_a = *begin_list_a;
	node = b_list_a;
	b_list_a = b_list_a->next;
	*begin_list_a = b_list_a;
	b_list_a->before = NULL;
	node->next = NULL;
	lstadd_front(begin_list_b, node);
	ft_printf("pb\n");
	return ;
}
