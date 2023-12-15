/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:39:15 by tbae              #+#    #+#             */
/*   Updated: 2022/11/16 14:56:15 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)s1;
	i = 0;
	j = 0;
	if ((!s1 || !s2) && len == 0)
		return (NULL);
	if (*s2 == '\0')
		return (str);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			j++;
			if (s2[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
