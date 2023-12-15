/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:36:47 by tbae              #+#    #+#             */
/*   Updated: 2023/02/02 14:27:13 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptoh(size_t pointer, size_t count)
{
	int		len;
	char	*str;

	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	len = count;
	str[count] = '\0';
	count--;
	while (pointer != 0)
	{
		str[count] = (pointer % 16) + 48;
		if (str[count] > '9')
			str[count] = str[count] + 39;
		pointer = pointer / 16;
		count--;
	}
	write(1, "0x", 2);
	write(1, str, len);
	free (str);
	return (len + 2);
}

int	pointer(va_list arg)
{
	size_t	pointer1;
	size_t	pointer2;
	size_t	count;

	pointer1 = va_arg(arg, size_t);
	pointer2 = pointer1;
	count = 0;
	if (pointer1 == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	while (pointer2 != 0)
	{
		pointer2 = pointer2 / 16;
		count ++;
	}
	return (ft_ptoh(pointer1, count));
}
