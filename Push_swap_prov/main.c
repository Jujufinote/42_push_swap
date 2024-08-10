/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:21:38 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/09 13:19:18 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	**begin_list_a;
	t_lst	**begin_list_b;
	t_lst	*lst;
	
	if (argc < 2)
		return (0);
	if (verif_param(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	begin_list_a = create_list(argv);
	if (begin_list_a == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	lst = NULL;
	begin_list_b = &lst;
	if (is_sorted(*begin_list_a) != 1)
	{
		if (lstsize(*begin_list_a) <= 3)
			small(begin_list_a);
		else if (lstsize(*begin_list_a) < 6)
			medium(begin_list_a, begin_list_b);
		else
			large(begin_list_a, begin_list_b);
	}
	printlst(begin_list_a);
	lstclear(begin_list_a);
	free(begin_list_a);
	return (0);
}
