/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:15:27 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/13 11:15:32 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	lstadd_front(t_lst **lst, t_lst *new)
{
	t_lst	*next;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->before = NULL;
		new->next = NULL;
	}
	else
	{
		next = *lst;
		next->before = new;
		new->next = next;
	}
	*lst = new;
	return ;
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	last = lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
	{
		last->next = new;
		new->before = last;
	}
	return ;
}

t_lst	*lstnew(int content)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->push_cost = 0;
	node->next = NULL;
	node->before = NULL;
	return (node);
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
