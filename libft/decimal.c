/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:30:40 by tbae              #+#    #+#             */
/*   Updated: 2023/02/02 14:27:13 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnb_printf(long nb, int sign, int count)
{
	int		len;
	char	*str;

	if (sign == -1)
		count++;
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	if (sign == -1)
		str[0] = '-';
	len = count;
	str[count] = '\0';
	count--;
	while (nb > 9)
	{
		str[count] = (nb % 10) + 48;
		nb = nb / 10;
		count--;
	}
	str[count] = (nb % 10) + 48;
	write(1, str, len);
	free (str);
	return (len);
}

static int	ft_itoa_printf(long nb1)
{
	long	nb2;
	int		count;
	int		sign;

	nb2 = nb1;
	count = 0;
	sign = 0;
	if (nb2 < 0)
	{
		nb1 = nb1 * -1;
		sign = -1;
	}
	if (nb1 == 0)
		count = 1;
	else
	{
		while (nb2 != 0)
		{
			nb2 = nb2 / 10;
			count ++;
		}
	}
	return (ft_putnb_printf(nb1, sign, count));
}

int	decimal(va_list arg, char c)
{
	long			i;
	unsigned int	ui;

	i = 0;
	ui = 0;
	if (c == 'd' || c == 'i')
	{
		i = va_arg(arg, int);
		return (ft_itoa_printf(i));
	}
	if (c == 'u')
	{
		ui = va_arg(arg, unsigned int);
		return (ft_itoa_printf(ui));
	}
	return (0);
}
