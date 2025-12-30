/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:57:02 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 15:42:40 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			word++;
		else if (s[i] == c && s[i + 1] != c \
				&& s[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

int	finding_args(char **argv, char **args, int i, int l)
{
	int		k;
	int		j;

	while (argv[l])
	{
		k = 0;
		while (argv[l][k])
		{
			while (argv[l][k] && argv[l][k] == ' ')
				k++;
			j = k;
			while (argv[l][k] && argv[l][k] != ' ')
				k++;
			if (argv[l][j] != '\0')
			{
				args[i] = (char *)malloc(sizeof(char) * (k - j + 1));
				if (args[i] == NULL)
					return (1);
				ft_strlcpy(args[i], argv[l] + j, k - j + 1);
				i++;
			}
		}
		l++;
	}
	return (0);
}

char	**cleaning(char **argv)
{
	int		count;
	int		i;
	char	**args;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count = count + ft_count(argv[i], ' ');
		i++;
	}
	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
		return (NULL);
	finding_args(argv, args, 0, 1);
	args[count] = NULL;
	return (args);
}

void	ft_free(char **array)
{
	int	j;

	j = 0;
	while (array[j] != NULL)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return ;
}
