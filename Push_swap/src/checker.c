/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:00:05 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 15:39:53 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	main(int argc, char **argv)
{
	t_lst	**begin_list_a;
	t_lst	**begin_list_b;
	t_lst	*lst;
	char	**array;

	if (argc < 2)
		return (0);
	array = is_all_good(argv);
	begin_list_a = create_list(cleaning(argv));
	if (begin_list_a == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	lst = NULL;
	begin_list_b = &lst;
	sorting(begin_list_a, begin_list_b, array);
	lstclear(begin_list_a);
	free(begin_list_a);
	return (0);
}
