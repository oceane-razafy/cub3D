/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:25:08 by tbae              #+#    #+#             */
/*   Updated: 2023/02/02 14:27:13 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv(char *base, va_list arg)
{
	if (base[0] != '%')
		return (0);
	if (base[1] == 's' || base[1] == 'c')
		return (char_or_str(arg, base[1]));
	if (base[1] == 'p')
		return (pointer(arg));
	if (base[1] == 'd' || base[1] == 'i' || base[1] == 'u')
		return (decimal(arg, base[1]));
	if (base[1] == 'x' || base[1] == 'X')
		return (ft_itoh(arg, base[1]));
	if (base[1] == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

static int	printstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	write (1, str, i);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	size_t		count;
	int			i;
	va_list		arg;

	va_start(arg, str);
	count = 0;
	while (*str)
	{
		i = printstr((char *)str);
		count = count + i;
		str = str + i;
		i = conv((char *)str, arg);
		if (i != 0 || (i == 0 && *str == '%'))
			str = str + 2;
		if (i == -1)
			i = 0;
		count = count + i;
	}
	va_end(arg);
	return (count);
}
