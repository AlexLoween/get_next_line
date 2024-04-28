/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:44 by ralanes           #+#    #+#             */
/*   Updated: 2024/04/28 00:38:13 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_before_jump(const char *str)
{
	char	*res_memory;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res_memory = ft_calloc(i + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	if (ft_strchr(str, '\n'))
	{
		res_memory[i] = str[i];
		i++;
	}
	return (res_memory);
}

static char	*get_after_jump(const char *str)
{
	char	*res_memory;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	j = 0;
	while (str && str[j])
		j++;
	res_memory = ft_calloc((j - i) + 1, sizeof(char));
	if (!res_memory)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res_memory[j] = str[i + j];
		j++;
	}
	return (res_memory);
}

static void	read_line(int fd, char **save, char **temporary)
{
	char	*reserva;
	long	leido;

	reserva = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reserva)
		return ;
	leido = 1;
	while (leido > 0)
	{
		leido = read(fd, reserva, BUFFER_SIZE);
		if (leido < 0)
		{
			ft_free_strs(&reserva, save, temporary);
			return ;
		}
		reserva[leido] = '\0';
		*temporary = ft_strdup(*save);
		ft_free_strs(save, 0, 0);
		*save = ft_strjoin(*temporary, reserva);
		ft_free_strs(temporary, 0, 0);
		if (ft_strchr(*save, '\n'))
			break ;
	}
	ft_free_strs(&reserva, 0, 0);
}

static char	*before_and_after(char **save, char **temporary)
{
	char	*line;

	*temporary = ft_strdup(*save);
	ft_free_strs(save, 0, 0);
	*save = get_after_jump(*temporary);
	line = get_before_jump(*temporary);
	ft_free_strs(temporary, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*temporary;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	temporary = NULL;
	read_line(fd, &save, &temporary);
	if (save != NULL && *save != '\0')
		line = before_and_after(&save, &temporary);
	if (!line || *line == '\0')
	{
		ft_free_strs(&temporary, &save, &line);
		return (NULL);
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("text.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}*/