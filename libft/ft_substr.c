/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:53 by tbae              #+#    #+#             */
/*   Updated: 2023/12/13 13:00:02 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

size_t	len_malloc(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		start++;
		i++;
	}
	return (i);
}

char	*ft_null(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*source;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_null());
	source = (char *)s;
	while (source[j])
		j++;
	if (start > j)
		start = j;
	str = malloc(sizeof(char) * (len_malloc(s, start, len) + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len && start + i < j)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
