/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:19:44 by tbae              #+#    #+#             */
/*   Updated: 2022/11/16 15:01:25 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*t;
	char	*s;

	if (src == dest || !n)
		return (dest);
	if (dest < src)
	{
		t = (char *)dest;
		s = (char *)src;
		while (n--)
			*t++ = *s++;
	}
	else
	{
		t = (char *)dest + (n - 1);
		s = (char *)src + (n - 1);
		while (n--)
			*t-- = *s--;
	}
	return (dest);
}
