/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:55:09 by tbae              #+#    #+#             */
/*   Updated: 2022/11/15 17:13:56 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size )
{
	while (size > 0)
	{
		if (*(char *)memoryBlock == (char)searchedChar)
			return ((void *)memoryBlock);
		memoryBlock ++;
		size--;
	}
	return (NULL);
}
