/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:34:06 by ralanes           #+#    #+#             */
/*   Updated: 2024/04/08 20:12:12 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_free_strs(char **str, char **str1, char **str2)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	if (!s1)
		return (ft_strdup(""));
	size = 0;
	while (s1[size])
		size++;
	s2 = ft_calloc(size + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	size = 0;
	while (s1[size])
	{
		s2[size] = s1[size];
		size++;
	}
	return (s2);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2 && s2[len_s2])
		len_s2++;
	s = ft_calloc(len_s1 + len_s2 + 1, sizeof * s);
	if (!s)
		return (NULL);
	len_s1 = -1;
	while (s1 && s1[++len_s1])
		s[len_s1] = s1[len_s1];
	len_s2 = -1;
	while (s2 && s2[++len_s2])
		s[len_s1 + len_s2] = s2[len_s2];
	return (s);
}
