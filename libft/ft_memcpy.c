/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:55:09 by tbae              #+#    #+#             */
/*   Updated: 2022/11/15 17:40:16 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;
	char	*str;

	if (!destination && !source)
		return ("\0");
	str = (char *)destination;
	i = 0;
	while (i < size)
	{
		*((char *)destination) = *((char *)source);
		i++;
		destination++;
		source++;
	}
	return (str);
}
