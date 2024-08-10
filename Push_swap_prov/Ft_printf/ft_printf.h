/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:01:09 by jverdier          #+#    #+#             */
/*   Updated: 2024/03/08 11:23:06 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_convert(const char string, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *arg);
int		ft_putnbr(long int arg);
int		iswhitespace(char c);
int		ft_puthexa(unsigned long int arg, unsigned char str);
int		ft_ptrhexa(unsigned long int arg);
char	ft_lowercase(char result);

#endif
