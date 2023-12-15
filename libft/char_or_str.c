/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_or_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:14 by tbae              #+#    #+#             */
/*   Updated: 2023/02/02 14:27:13 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr_printf(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(1, str, i);
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

static int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	char_or_str(va_list arg, char c)
{
	char	*str;
	char	ch;

	if (c == 's')
	{
		str = va_arg (arg, char *);
		ch = '0';
		return (ft_putstr_printf(str));
	}
	if (c == 'c')
	{
		ch = va_arg(arg, int);
		str = "s";
		return (ft_putchar_printf(ch));
	}
	return (0);
}
