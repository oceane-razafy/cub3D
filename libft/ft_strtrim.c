/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:31:39 by tbae              #+#    #+#             */
/*   Updated: 2023/12/13 12:59:40 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_verif(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_str(char *s1, size_t count_d, size_t count_f)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = (ft_strlen(s1) - (count_d + count_f));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[count_d];
		i++;
		count_d++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_str_null(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		count_d;
	int		count_f;

	count_d = 0;
	if (!s1)
		return (ft_str_null());
	while (s1[count_d] != '\0' && ft_verif(s1[count_d], set) == 1)
		count_d++;
	if (s1[count_d] == '\0')
		return (ft_str_null());
	i = ft_strlen((char *)s1);
	count_f = 0;
	i--;
	while (s1[i] != '\0' && ft_verif(s1[i], set) == 1)
	{
		i--;
		count_f++;
	}
	return (ft_str((char *)s1, count_d, count_f));
}
