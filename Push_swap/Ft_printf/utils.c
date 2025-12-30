/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:55:55 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/28 21:40:40 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_lowercase(char result)
{
	if (result >= 65 && result <= 90)
		result += 32;
	return (result);
}

int	ft_puthexa(unsigned long int nbr, unsigned char str)
{
	char	*base;
	int		length;

	base = "0123456789ABCDEF";
	length = 0;
	if (nbr < 16)
	{
		if (str == 'x')
			length += ft_putchar(ft_lowercase(base[nbr]));
		else
			length += ft_putchar(base[nbr]);
	}
	if (nbr >= 16)
	{
		length += ft_puthexa(nbr / 16, str);
		if (str == 'x')
			length += ft_putchar(ft_lowercase(base[nbr % 16]));
		else
			length += ft_putchar(base[nbr % 16]);
	}
	return (length);
}

int	ft_ptrhexa(unsigned long int adress)
{
	int	length;

	length = 0;
	if (adress == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	length += 2;
	length += ft_puthexa(adress, 'x');
	return (length);
}

int	iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
