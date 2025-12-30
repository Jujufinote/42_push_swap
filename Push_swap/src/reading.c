/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:51:54 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/14 10:19:16 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *savings, char *buffer)
{
	char	*savings_v2;
	int		total_length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_length = ft_len(savings) + ft_len(buffer) + 1;
	savings_v2 = malloc(sizeof(char) * total_length);
	if (savings_v2 == NULL)
		return (NULL);
	while (savings != NULL && savings[i])
		savings_v2[j++] = savings[i++];
	free(savings);
	i = 0;
	while (buffer[i])
		savings_v2[j++] = buffer[i++];
	savings_v2[j] = '\0';
	return (savings_v2);
}

char	*ft_reading(int fd, char *savings)
{
	int		result;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER + 1));
	if (buffer == NULL)
		return (NULL);
	result = read(fd, buffer, BUFFER);
	if (result == -1)
		return (ft_error(buffer, savings));
	buffer[result] = '\0';
	while (result > 0)
	{
		savings = ft_join(savings, buffer);
		if (savings == NULL)
			return (ft_error(buffer, savings));
		result = read(fd, buffer, BUFFER);
		if (result == -1)
			return (ft_error(buffer, savings));
		buffer[result] = '\0';
	}
	free(buffer);
	return (savings);
}
