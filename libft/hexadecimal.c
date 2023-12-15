/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:00 by tbae              #+#    #+#             */
/*   Updated: 2023/02/02 14:27:13 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex_printf(long nb, int count, char c)
{
	int		len;
	char	*str;

	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	len = count;
	str[count] = '\0';
	count--;
	while (nb != 0)
	{
		str[count] = (nb % 16) + 48;
		if (c == 'x' && str[count] > '9')
			str[count] = str[count] + 39;
		if (c == 'X' && str[count] > '9')
			str[count] = str[count] + 7;
		nb = nb / 16;
		count--;
	}
	write(1, str, len);
	return (free (str), len);
}

int	ft_itoh(va_list arg, char c)
{
	unsigned long	nb1;
	unsigned long	nb2;
	int				count;

	nb1 = va_arg(arg, unsigned int);
	nb2 = nb1;
	count = 0;
	if (nb1 == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (nb2 != 0)
	{
		nb2 = nb2 / 16;
		count ++;
	}
	return (ft_puthex_printf(nb1, count, c));
}
