/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:30:40 by tbae              #+#    #+#             */
/*   Updated: 2022/11/17 10:01:10 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	*ft_0to9(long int n, int sign, int count)
{
	char	*str;

	if (sign == -1)
	{
		str = malloc(3);
		if (!str)
			return (NULL);
		str[count] = '-';
		count++;
	}
	else
	{
		str = malloc(2);
		if (!str)
			return (NULL);
	}
	str[count] = n + 48;
	count++;
	str[count] = '\0';
	return (str);
}

static char	*ft_supto9(long int n, int sign, int count)
{
	char	*str;

	if (sign == -1)
	{
		str = malloc(sizeof(char) * (count + 2));
		if (!str)
			return (NULL);
		str[0] = '-';
		count++;
	}
	else
	{
		str = malloc(sizeof(char) * count + 1);
		if (!str)
			return (NULL);
	}
	str[count--] = '\0';
	while (n > 9)
	{
		str[count--] = (n % 10) + 48;
		n = n / 10;
	}
	str[count] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nb1;
	long int	nb2;
	int			count;
	int			sign;

	nb1 = n;
	nb2 = n;
	count = 0;
	sign = 1;
	if (nb1 < 0)
	{
		nb2 = nb2 * -1;
		sign = -1;
	}
	if (nb2 >= 0 && nb2 <= 9)
		return (ft_0to9(nb2, sign, count));
	while (nb1 != 0)
	{
		nb1 = nb1 / 10;
		count ++;
	}
	return (ft_supto9(nb2, sign, count));
}
