/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:09:31 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 14:51:52 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	sa(t_lst **begin_list)
{
	t_lst	*b_lst;

	b_lst = *begin_list;
	swap(&b_lst->content, &b_lst->next->content);
	return ;
}

void	sb(t_lst **begin_list)
{
	t_lst	*b_lst;

	b_lst = *begin_list;
	swap(&b_lst->content, &b_lst->next->content);
	return ;
}

void	ss(t_lst **begin_list_a, t_lst **begin_list_b)
{
	sa(begin_list_a);
	sb(begin_list_b);
	ft_printf("ss\n");
	return ;
}
