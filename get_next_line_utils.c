/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:34:06 by ralanes           #+#    #+#             */
/*   Updated: 2024/03/05 16:50:07 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
	{
		return (0);
	}
	chr = c;
	while (*s)
	{
		if (*s == chr)
		{
			return ((char *)s);
		}
		s++;
	}
	if (chr == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(count * size);
	if (!str)
		return (0);
	i = 0;
	while (i < count * size)
		str[i++] = '\0';
	return ((void *)str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (len == 0 || start >= ft_strlen(s))
		str = (char *)ft_calloc(1, sizeof(char));
	else if (len >= (ft_strlen(s) - start))
	{
		str = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
		if (!str)
			return (0);
		while (s[start] != '\0')
			str[i++] = s[start++];
	}
	else
	{
		str = (char *)ft_calloc(len + 1, sizeof(char));
		if (!str)
			return (0);
		while (len--)
			str[i++] = s[start++];
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (0);
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free((void *)s1);
	return (str);
}
