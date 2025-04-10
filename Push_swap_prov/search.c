/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:38:23 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 12:05:04 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*search_min(t_lst *begin_list)
{
	t_lst	*min;

	min = begin_list;
	while (begin_list != NULL)
	{
		if (min->content > begin_list->content)
			min = begin_list;
		begin_list = begin_list->next;
	}
	return (min);
}

t_lst	*search_max(t_lst *begin_list)
{
	t_lst	*max;

	max = begin_list;
	while (begin_list != NULL)
	{
		if (max->content < begin_list->content)
			max = begin_list;
		begin_list = begin_list->next;
	}
	return (max);
}

t_lst	*srch_closest_bigger(t_lst *begin_list, t_lst *num)
{
	t_lst	*bigger;
	t_lst	*b_list;

	b_list = begin_list;
	while (b_list != NULL && b_list->content <= num->content)
		b_list = b_list->next;
	bigger = b_list;
	while (b_list != NULL)
	{
		if (b_list->content > num->content \
		&& bigger->content > b_list->content)
			bigger = b_list;
		b_list = b_list->next;
	}
	if (bigger == NULL)
		bigger = search_min(begin_list);
	if (bigger->next == NULL)
		return (begin_list);
	else
		bigger = bigger->next;
	return (bigger);
}

t_lst	*srch_closest_smaller(t_lst *begin_list, t_lst *num)
{
	t_lst	*smaller;
	t_lst	*b_list;

	b_list = begin_list;
	while (b_list != NULL && b_list->content >= num->content)
		b_list = b_list->next;
	smaller = b_list;
	while (b_list != NULL)
	{
		if (b_list->content < num->content \
		&& smaller->content < b_list->content)
			smaller = b_list;
		b_list = b_list->next;
	}
	if (smaller == NULL)
		smaller = search_max(begin_list);
	if (smaller->next == NULL)
		return (begin_list);
	else
		smaller = smaller->next;
	return (smaller);
}

t_lst	*who_put(t_lst *begin_list)
{
	t_lst	*result;

	result = begin_list;
	while (begin_list != NULL)
	{
		if (result->push_cost > begin_list->push_cost)
			result = begin_list;
		begin_list = begin_list->next;
	}
	return (result);
}
