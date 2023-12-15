/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:29:49 by tbae              #+#    #+#             */
/*   Updated: 2022/11/16 15:52:29 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	if (!dst && size == 0)
		return (0);
	len_dest = ft_strlen(dst);
	i = len_dest;
	j = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	if (size < len_dest)
		return (size + ft_strlen((char *)src));
	if (size > i)
	{
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (len_dest + j);
}
