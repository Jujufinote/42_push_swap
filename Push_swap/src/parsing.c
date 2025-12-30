/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:26:22 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 16:10:39 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && arg[i] == ' ')
			i++;
		if (arg[i] == '\0')
			return (0);
		if (!(ft_isdigit(arg[i]) == 1 || arg[i] == '+' || arg[i] == '-'))
			return (1);
		if (ft_isdigit(arg[i]) == 1 && (ft_isdigit(arg[i + 1]) != 1 \
		&& arg[i + 1] != ' ' && arg[i + 1] != '\0'))
			return (1);
		if ((arg[i] == '+' || arg[i] == '-') && ft_isdigit(arg[i + 1]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	is_double(char **argv)
{
	char	**now;
	char	**next;

	now = argv;
	while (*now != NULL)
	{
		next = now + 1;
		while (*next != NULL)
		{
			if (ft_strlen(*now) == ft_strlen(*next) \
			&& ft_strncmp(*now, *next, ft_strlen(*now)) == 0)
				return (1);
			next++;
		}
		now++;
	}
	return (0);
}

int	is_intflow(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strlen(args[i]) >= 10 \
		&& ((args[i][0] != '-' && ft_strncmp(INT_MAX, args[i], 13) < 0) \
		|| (args[i][0] == '-' && ft_strncmp(INT_MIN, args[i], 13) < 0)))
			return (1);
		i++;
	}
	return (0);
}

int	verif_param(char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_valid(argv[i]) == 1)
			return (1);
		i++;
	}
	args = cleaning(argv);
	if (args == NULL)
		return (1);
	if (is_double(args) == 1 || is_intflow(args) == 1)
	{
		ft_free(args);
		return (1);
	}
	ft_free(args);
	return (0);
}

int	is_sorted(t_lst *begin_list)
{
	while (begin_list->next != NULL)
	{
		if (begin_list->content < begin_list->next->content)
			begin_list = begin_list->next;
		else
			return (0);
	}
	return (1);
}
