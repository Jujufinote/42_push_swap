/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:15:38 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 13:28:55 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printlst(t_lst **begin_list_a)
{
	t_lst	*b_list;

	if (begin_list_a == NULL)
		return ;
	b_list = *begin_list_a;
	ft_printf("\n");
	while (b_list != NULL)
	{
		ft_printf("content : %d\n", b_list->content);
		b_list = b_list->next;
	}
	return ;
}

t_lst	**create_list(char **argv)
{
	int		i;
	t_lst	**begin_list_a;
	t_lst	*new;

	if (argv == NULL)
		return (NULL);
	i = 1;
	begin_list_a = (t_lst **)malloc(sizeof(t_lst *));
	if (begin_list_a == NULL)
		return (NULL);
	*begin_list_a = lstnew(ft_atoi(argv[0]));
	while (*begin_list_a != NULL && argv[i] != NULL)
	{
		new = lstnew(ft_atoi(argv[i]));
		if (new == NULL)
		{
			lstclear(begin_list_a);
			return (NULL);
		}
		lstadd_back(begin_list_a, new);
		i++;
	}
	ft_free(argv);
	return (begin_list_a);
}

void	lstclear(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*before;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		before = temp;
		temp = temp->next;
		before->next = NULL;
		before->before = NULL;
		free(before);
	}
	*lst = NULL;
	return ;
}
