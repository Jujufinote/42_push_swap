/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:18:12 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/16 14:07:40 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_error(char *buffer, char *savings)
{
	free(buffer);
	if (savings != NULL)
		free(savings);
	return (NULL);
}
