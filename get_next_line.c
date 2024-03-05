/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:44 by ralanes           #+#    #+#             */
/*   Updated: 2024/03/05 17:35:58 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stash(char *stash, size_t stash_len, size_t break_pos)
{
	size_t	new_stash_size;
	char	*new_stash;

	new_stash_size = stash_len - break_pos;
	if (!new_stash_size || !stash[break_pos])
		return (ft_free(stash));
	new_stash = ft_substr(stash, break_pos, new_stash_size);
	ft_free(stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_next_line(char *stash, size_t break_pos)
{
	char	*next_line;

	next_line = ft_substr(stash, 0, break_pos);
	if (!next_line)
		return (NULL);
	return (next_line);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0 || (bytes_read == 0 && *buf))
		{
			buf[bytes_read] = '\0';
			stash = ft_strjoin(stash, buf);
		}
	}
	free (buf);
	if (bytes_read < 0)
		return (ft_free(stash));
	return (stash);
}

char	*ft_free(char *stash)
{
	free (stash);
	stash = NULL;
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*stash;
	size_t		stash_len;
	size_t		break_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	stash_len = ft_strlen(stash);
	if (ft_strchr(stash, '\n'))
		break_pos = ft_strchr(stash, '\n') - stash + 1;
	else
		break_pos = stash_len;
	next_line = ft_next_line(stash, break_pos);
	if (!next_line)
		return (ft_free(stash));
	stash = ft_stash(stash, stash_len, break_pos);
	return (next_line);
}


int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
		{
			break ;
		}
		printf("%s", next_line);
		free (next_line);
	}
	close (fd);
	return (0);
}
