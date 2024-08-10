/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:01:18 by jverdier          #+#    #+#             */
/*   Updated: 2024/03/08 11:22:16 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}

int	ft_putnbr(long int num)
{
	int	length;

	length = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		num = -num;
		length += ft_putchar('-');
	}
	if (num < 10)
		length += ft_putchar(num + 48);
	if (num >= 10)
	{
		length += ft_putnbr(num / 10);
		length += ft_putchar((num % 10) + 48);
	}
	return (length);
}

int	ft_convert(const char string, va_list args)
{
	int	length;

	length = 0;
	if (string == 'c')
		length += ft_putchar(va_arg(args, int));
	if (string == 's')
		length += ft_putstr(va_arg(args, char *));
	if (string == 'p')
		length += ft_ptrhexa(va_arg(args, unsigned long int));
	if (string == 'd' || string == 'i')
		length += ft_putnbr(va_arg(args, int));
	if (string == 'u')
		length += ft_putnbr(va_arg(args, unsigned int));
	if (string == 'x' || string == 'X')
		length += ft_puthexa(va_arg(args, unsigned int), string);
	if (string == '%')
		length += ft_putchar(string);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				length;
	int				i;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (iswhitespace(str[i]) == 1)
				i++;
			length += ft_convert(str[i], args);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
