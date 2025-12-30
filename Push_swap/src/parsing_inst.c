/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:00:29 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/17 11:33:00 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	is_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_good(char *inst)
{
	int	i;

	i = 0;
	while (inst[i] != '\0')
	{
		if (is_lowercase(inst[i]) != 1 && inst[i] != '\n')
			return (1);
		else if (inst[i] == '\n' && inst[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_real_inst(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], SA, 4) != 0 \
		&& ft_strncmp(array[i], SB, 4) != 0 \
		&& ft_strncmp(array[i], SS, 4) != 0 \
		&& ft_strncmp(array[i], PA, 4) != 0 \
		&& ft_strncmp(array[i], PB, 4) != 0 \
		&& ft_strncmp(array[i], RA, 4) != 0 \
		&& ft_strncmp(array[i], RB, 4) != 0 \
		&& ft_strncmp(array[i], RR, 4) != 0 \
		&& ft_strncmp(array[i], RRA, 4) != 0 \
		&& ft_strncmp(array[i], RRB, 4) != 0 \
		&& ft_strncmp(array[i], RRR, 4) != 0)
			return (1);
		i++;
	}
	return (0);
}

char	**inst_renderring(char *inst)
{
	char	**array;

	if (inst == NULL)
		return (NULL);
	if (is_good(inst) == 1)
	{
		free(inst);
		return (NULL);
	}
	array = ft_split(inst, '\n');
	if (array == NULL)
		return (NULL);
	free(inst);
	if (is_real_inst(array) == 1)
	{
		ft_free(array);
		return (NULL);
	}
	return (array);
}

char	**is_all_good(char **argv)
{
	char	**array;

	if (verif_param(argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	array = inst_renderring(ft_reading(0, NULL));
	if (array == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (array);
}
